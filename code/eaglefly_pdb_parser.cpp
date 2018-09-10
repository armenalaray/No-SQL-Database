/*

Alejandro Armenta
eaglefly_pdb_parser.cpp
NOTE(Alex): This will parse pdbs and dump metafiles that eaglefly_debugger will use as debug_data 

*/

#include "Windows.h"
#include "eaglefly_platform.h"
#include "eaglefly_pdb_parser.h"

internal void * 
Win32AllocateMemory(memory_index Size)
{
    void * Result = 0;
    //TODO(Alex): Alignment?
    if(Size)
    {
        Result = VirtualAlloc(0, Size, MEM_RESERVE|MEM_COMMIT, PAGE_READWRITE); 
    }
    
    return Result;
}

internal void
Win32DeallocateMemory(void * Memory)
{
    if(Memory)
    {
        VirtualFree(Memory, 0, MEM_RELEASE);
    }
}


READ_ENTIRE_FILE(Win32ReadEntireFile)
{
    debug_file_content Result = {};
    HANDLE Handle = CreateFileA(FileName,
                                GENERIC_READ,
                                FILE_SHARE_READ,
                                0,
                                OPEN_EXISTING,
                                FILE_ATTRIBUTE_NORMAL,
                                0);
    if(Handle)
    {
        LARGE_INTEGER U64Size = {};
        if(GetFileSizeEx(Handle, &U64Size))
        {
            u32 U32Size = TruncateU64ToU32(U64Size.QuadPart);
            DWORD BytesRead = 0;
            
            void * Content = Win32AllocateMemory(U32Size);
            if(ReadFile(Handle, Content, U32Size, &BytesRead,0) && 
               (BytesRead == U32Size))
            {
                Result.Content = Content;
                Result.Size = U32Size;
            }
            else
            {
                Win32DeallocateMemory(Content);
            }
        }
        else
        {
            //TODO(Alex): logging
        }
        
        CloseHandle(Handle);
    }
    else
    {
        //TODO(Alex): Check if ERROR_FILE_NOT_FOUND 
    }
    
    return Result;
}

inline b32 
IsValidPDBMagic(char * Magic)
{
    b32 Result = 0;
    u32 Count = 0;
    char RealMagic[MAGIC_SIZE_PDB] = {'M','i','c','r','o','s','o','f','t',' ','C','/','C','+','+',' ','M','S','F',' ','7','.','0','0','\r','\n','1','D','S','\0','\0','\0'};
    RealMagic[26] = 26;
    char * RealMagicP = RealMagic;
    while((*Magic++ == *RealMagicP++))
    {
        
        ++Count;
    }
    
    Result = (Count == MAGIC_SIZE_PDB);
    return Result;
}

inline b32
IsValidPDB(epdb_super_block * SBlock, uint32_t FileSize)
{
    b32 Result = (IsValidPDBMagic(SBlock->Magic) && 
                  ((SBlock->BlockSize * SBlock->NumBlocks) == FileSize));
    
    return Result;
}

#if 0
internal void
GoToBlockWithIndex(pdb_manager * PManager, uint32_t Index)
{
    
}

internal void
GoToFreePageMap(pdb_manager * PDBmanager)
{
    uint32_t Index = PDBmanager->CurrentBlockIndex + PDBmanager->SBlock->FreePageMap;
    GoToBlockWithIndex(PDBmanager, Index);
}
#endif





inline void 
INIT_STREAM_BLOCK(epdb_block * Sentinel)
{
    INIT_DOUBLY_LLIST(Sentinel);
}

inline void
ADD_TAIL_STREAM_BLOCK(epdb_manager * PManager, memory_arena * Arena, epdb_block * Sentinel, uint32_t Index)
{
    epdb_block * Block = PushStruct(Arena, epdb_block); 
    Block->Base_ = PManager->BeginOfFile + (PManager->SBlock->BlockSize * Index);
    Block->Index = Index;
    ADD_TAIL_DOUBLY_LLIST(Sentinel, Block);
}




#define BLOCK_COUNT(PManager, Size) CeilR32Tou32((r32)(Size) / (r32)((PManager)->SBlock->BlockSize))  

//TODO(Alex): Make all offsets be char* 
#define GET_BLOCK_OFFSET(PManager, Value, type) *(type*)(GetBlockOffset(PManager, Value))
inline void * 
GetBlockOffset(epdb_manager * PManager, char * Value)
{
    void * Result = 0;
    epdb_stream * CurrentStream =  PManager->CurrentStream;
    memory_index Offset = (memory_index)Value - (memory_index)CurrentStream->FirstBlockBase;
    uint32_t StreamBlockIndex = FloorR32Tou32((r32)Offset / (r32)((PManager)->SBlock->BlockSize));
    uint32_t OffsetInsideBLock = (uint32_t)(Offset & (PManager->SBlock->BlockSize - 1));
    
    uint32_t Count = 0;
    for(epdb_block * Block = CurrentStream->BlockSentinel.Next;
        Block != &CurrentStream->BlockSentinel;
        Block = Block->Next, ++Count)
    {
        if(Count == StreamBlockIndex)
        {
            Result = Block->Base_ + OffsetInsideBLock;
            break;
        }
    }
    
    return Result;
}

//NOTE(Alex): We will create streams from streams!
internal void
BEGIN_STREAM_EXT(epdb_manager * PManager, epdb_stream * Source, epdb_stream_directory * out_Directory)
{
    if(Source->FirstBlockBase)
    {
        PManager->StreamExtraction = true;
        PManager->CurrentStream = Source;
        out_Directory->StreamCount = *(uint32_t*)Source->FirstBlockBase;
        PManager->ResultBlockIndex = (uint32_t*)Source->FirstBlockBase + (out_Directory->StreamCount + 1); 
    }
}

//TODO(Alex): Assert that we are not outside block boundary!
internal void
CREATE_STREAM(epdb_manager * PManager, epdb_stream_directory * out_Directory, uint32_t Index = 0)
{
    Assert((Index >= 0) && (Index < out_Directory->StreamCount));
    if(PManager->ResultBlockIndex && PManager->CurrentStream && PManager->StreamExtraction)
    {
        epdb_stream * Stream = PManager->CurrentStream;
        //NOTE(Alex):We will always be FirstBlockBase Relative! Absolute values
        char * Offset = (Stream->FirstBlockBase + ((Index + 1) * sizeof(uint32_t)));
        uint32_t Size = GET_BLOCK_OFFSET(PManager, Offset, uint32_t);
        
        //TODO(Alex): See why stream 5 is zero and what are the other streams >= 5 for?!
        if(Size)
        {
            epdb_stream * Result = PushStruct(&PManager->TempArena, epdb_stream);
            Result->Size = Size;
            Result->BlockCount = BLOCK_COUNT(PManager, Result->Size);
            
            Assert(Result->BlockCount);
            INIT_STREAM_BLOCK(&Result->BlockSentinel);
            for(uint32_t BlockIndex = 0;
                BlockIndex < Result->BlockCount;
                ++BlockIndex)
            {
                ADD_TAIL_STREAM_BLOCK(PManager, &PManager->TempArena, &Result->BlockSentinel, GET_BLOCK_OFFSET(PManager, (char*)PManager->ResultBlockIndex, uint32_t));
                ++PManager->ResultBlockIndex;
            }
            
            Result->FirstBlockBase = Result->BlockSentinel.Next->Base_;
            out_Directory->Streams[Index] = Result;
        }
    }
}

internal void
END_STREAM_EXT(epdb_manager * PManager)
{
    if(PManager)
    {
        //TODO(Alex): Shall we keep this on the place 
        PManager->StreamExtraction = false;
        PManager->CurrentStream = 0;
        PManager->ResultBlockIndex = 0;
    }
}

#define HAS_FLAG(BitField, Flag) ((BitField) & (Flag))

#define GET_STREAM_HEADER_(Stream, type) (type *)((Stream)->FirstBlockBase)
#define GET_STREAM_HEADER(Stream) GET_STREAM_HEADER_(Stream, epdb_##Stream##_header)


inline void BEGIN_SUBSTREAM_EXT(epdb_manager * PManager, epdb_stream * stream, uint32_t Offset)
{
    if(PManager)
    {
        PManager->SubstreamPtr = stream->FirstBlockBase + Offset;
    }
}

inline epdb_substream
CREATE_SUBSTREAM(epdb_manager * PManager, epdb_stream * Stream, memory_index Size)
{
    epdb_substream Result = {};
    if(PManager->SubstreamPtr)
    {
        Result.Stream = Stream;
        Result.Base = PManager->SubstreamPtr;
        Result.Size = Size;
        
        PManager->SubstreamPtr += Size;
    }
    
    return Result;
}

inline void
END_SUBSTREAM_EXT(epdb_manager * PManager) 
{
    PManager->SubstreamPtr = 0;
}

#define STATIC_MODULE_INFO_SIZE 64


internal void
GetAllModulesFromPDB(epdb_manager * PManager, epdb_substream ModSubstream)
{
    char * ModuleName, * ObjFileName;
    epdb_module_info * Source = (epdb_module_info*)ModSubstream.Base;
    epdb_module * Dest = 0;
    epdb_module * PrevModule = 0;
    if(Source)
    {
        uint32_t ModByteCount = 0;
        for(uint32_t ByteIndex = 0;
            ByteIndex < ModSubstream.Size;)
        {
            if(Source->Unused0 == 0)
            {
                Dest = PushStruct(&PManager->TempArena, epdb_module);
                Dest->Info = Source;
                
                ModuleName = (char*)Source + sizeof(epdb_module_info);
                Dest->ModuleNameSize = StringLength(ModuleName) + 1;
                ObjFileName = ModuleName + (Dest->ModuleNameSize);
                Dest->ObjFileNameSize = StringLength(ObjFileName) + 1;
                
                Dest->ModuleName = PushString(&PManager->TempArena, Dest->ModuleNameSize, char);
                Dest->ObjFileName = PushString(&PManager->TempArena, Dest->ObjFileNameSize, char);
                
                CopyString(Dest->ModuleName, ModuleName, Dest->ModuleNameSize);
                CopyString(Dest->ObjFileName, ObjFileName, Dest->ObjFileNameSize);
                
                if(!PManager->FirstModule)
                {
                    PManager->FirstModule = Dest;
                }
                
                if(PrevModule)
                {
                    PrevModule->Next = Dest;
                }
                PrevModule = Dest;
                
                CREATE_STREAM(PManager, &PManager->Directory, Source->ModuleSymStream);
                
                ModByteCount = sizeof(epdb_module_info) + Dest->ModuleNameSize + Dest->ObjFileNameSize;
                //TODO(Alex): handle different architectures
                uint32_t Offset = (ModByteCount & (sizeof(uint32_t) - 1));
                uint32_t PaddingBytes = (Offset) ? sizeof(uint32_t) - Offset : 0;
                
                ModByteCount += PaddingBytes;
                
                ByteIndex += ModByteCount;
                Source = (epdb_module_info*)((char*)Source + ModByteCount);
            }
            else
            {
                //TODO(Alex): Transform MBCS formatted strings to utf8 as needed! 
                break;
            }
        }
        
    }
}

inline b32 
IsValidModule(epdb_module * Module)
{
    b32 Result = (Module->ModuleNameSize &&
                  Module->ModuleName &&
                  Module->ObjFileNameSize &&
                  Module->ObjFileName &&
                  Module->Info);
    
    return Result;
}

//TODO(Alex): Write this onto a file
internal void
CreateTracerSymbolsForModule(epdb_manager * PManager, epdb_module * Module, memory_arena * DestArena)
{
    if(IsValidModule(Module))// && DestArena)
    {
        epdb_module_info * ModInfo = Module->Info;
        epdb_stream * ModStream = PManager->Directory.Streams[ModInfo->ModuleSymStream]; 
        
        uint32_t Signature = *(uint32_t *)ModStream->FirstBlockBase;
        
        BEGIN_SUBSTREAM_EXT(PManager, ModStream, sizeof(Signature));
        epdb_substream SymbolSS = CREATE_SUBSTREAM(PManager, ModStream, ModInfo->SymByteSize - 4);
        epdb_substream LineInfo11SS = CREATE_SUBSTREAM(PManager, ModStream,  ModInfo->C11ByteSize);
        epdb_substream LineInfo13SS = CREATE_SUBSTREAM(PManager, ModStream,  ModInfo->C13ByteSize);
        END_SUBSTREAM_EXT(PManager);
        
        epdb_symbol_iterator SymIter = {};
        SymIter.ModuleSymBase = SymbolSS.Base;
        Assert((*(uint32_t*)SymIter.ModuleSymBase) == 0x00000001); 
        
        SymIter.At = SymIter.ModuleSymBase + 4;
        uint16_t SymLength = *(uint16_t*)SymIter.At;
        SymIter.At += SymLength + 2;
        
        
        
        //SymIter.ModuleSymBase = SymIter.At;
        //SymIter.CurrentScope = (uint16_t*)SymbolSS.Base;
        
        //efly_debug_info  * DebugInfo = PushStruct(DestArena, efly_debug_info);
        //INIT_DOUBLY_LLIST(&DebugInfo->LexicalScopeSentinel);
        
        for(;SymIter.At < (SymbolSS.Base + SymbolSS.Size);)
        {
            //efly_lexical_scope * Scope = PushStruct(DestArena, efly_lexical_scope);
            //ADD_TAIL_DOUBLY_LLIST(&DebugInfo->LexicalScopeSentinel, Scope);
        }
        
    }
}

//
//NOTE(Alex): EagleFly Data constructs needed
//

#if 0
//TODO(Alex): Create lexical scopes based on this idea
internal void 
PUSH_STACK(win32_dispatcher_state * DispState, memory_arena *  Arena, memory_index Address, opcode_block * Sentinel, opcode_block * OBlock)
{
    efly_lexical_scope * Result = 0;
    if(NUM_BETWEEN(Address, OBlock->EndOffset, OBlock->BeginOffset))
    {
        DispState->DispState->LexicalScopeFound = true;
    }
    else if(Oblock->Next != Sentinel)
    {
        PUSH_STACK(win32_dispatcher_state * DispState, memory_index Address, Sentinel, Oblock->Next);
    }
    
    if(DispState->LexicalScopeFound)
    {
        Result = PushStruct(&DispState->EDebugInfoArena, efly_lexical_scope);
        ADD_TAIL_DOUBLY_LLIST(Sentinel, Result);
    }
}

//NOTE(Alex): This will create the call stack from PDB symbol information
internal efly_lexical_scope * 
CONSTRUCT_LEXICAL_SCOPE(win32_dispatcher_state * DispState, memory_index Address)
{
    efly_lexical_scope * Result = 0;
    if(DispState->EDebugInfoMem)
    {
        edebug_info * DebugInfo = (edebug_info*)DispState->EDebugInfoMem; 
        PUSH_STACK(win32_dispatcher_state * DispState, memory_index Address, &DebugInfo->OpcodeSentinel, DebugInfo->OpcodeSentinel->Next);
    }
    
    return Result;
}
#endif

//extern "C" WIN32_LOAD_EDEBUG_INFO(Win32LoadEDebugInfo)
int main(uint32_t ArgCount, char ** Arguments)
{
    //NOTE(Alex): Arguments[0] is EXE FullPath!
    //TODO(Alex): Make User choose pdb TargetFullPath! 
    char * FileName = Arguments[1];
    if(FileName)
    {
        char * BeginOfFile = 0;
        debug_file_content PDBContent = Win32ReadEntireFile(FileName);
        epdb_super_block * SBlock = (epdb_super_block *)PDBContent.Content;
        BeginOfFile = (char*)PDBContent.Content;
        if(IsValidPDB(SBlock, PDBContent.Size))
        {
            uint32_t TempPDBStorageSize = Gigabytes(1);
            epdb_manager * PManager = (epdb_manager *)Win32AllocateMemory(TempPDBStorageSize);
            if(PManager)
            {
                PManager->SBlock = SBlock;
                PManager->IntervalBlockCount = 4096;//TODO(Alex): Test this!
                PManager->TempPDBStorageSize = TempPDBStorageSize;
                PManager->BeginOfFile = BeginOfFile;
                
                uint32_t ArenaSize = Megabytes(500);
                InitializeArena(&PManager->TempArena, (PManager + 1), ArenaSize);
                
                uint32_t DirectoryBlockCount = CeilR32Tou32((r32)SBlock->DirectorySize / (r32)SBlock->BlockSize); 
                uint32_t DirectoryIndex = SBlock->BlockMapAddress;
                uint32_t * DirectoryIndices = (uint32_t *)(BeginOfFile + (DirectoryIndex * SBlock->BlockSize));
                
                PManager->DirectoryBlockCount = DirectoryBlockCount;
                
                epdb_stream StreamDirectory = {};
                StreamDirectory.Size = SBlock->DirectorySize;
                StreamDirectory.BlockCount = DirectoryBlockCount;
                
                Assert(StreamDirectory.BlockCount);
                INIT_STREAM_BLOCK(&StreamDirectory.BlockSentinel);
                for(uint32_t Index = 0;
                    Index < StreamDirectory.BlockCount;
                    ++Index)
                {
                    ADD_TAIL_STREAM_BLOCK(PManager, &PManager->TempArena, &StreamDirectory.BlockSentinel, *DirectoryIndices++);
                }
                StreamDirectory.FirstBlockBase = StreamDirectory.BlockSentinel.Next->Base_;
                
                BEGIN_STREAM_EXT(PManager, &StreamDirectory, &PManager->Directory);
                CREATE_STREAM(PManager, &PManager->Directory, StreamIndex_Old);
                CREATE_STREAM(PManager, &PManager->Directory, StreamIndex_PDB);
                CREATE_STREAM(PManager, &PManager->Directory, StreamIndex_TPI);
                CREATE_STREAM(PManager, &PManager->Directory, StreamIndex_DBI);
                CREATE_STREAM(PManager, &PManager->Directory, StreamIndex_IPI);
                
                epdb_stream * pdb_stream = PManager->Directory.Streams[StreamIndex_PDB];
                epdb_stream * dbi_stream = PManager->Directory.Streams[StreamIndex_DBI];
                epdb_pdb_stream_header * PDBStreamHeader = GET_STREAM_HEADER(pdb_stream); 
                epdb_dbi_stream_header * DBIStreamHeader = GET_STREAM_HEADER(dbi_stream); 
                Assert(DBIStreamHeader->Age == PDBStreamHeader->Age);
                
                //TODO(Alex): Image/PDB Matching
                //TODO(Alex): Prinnt out Version Toolchain!
                
#if 0
                char BuildNText[128] = {0};
                snprintf_s(BuildNText, ArrayCount(BuildNText), "Build No.: %i");
                OutputDebugStringA(DBIStreamHeader->BuildNumber);
#endif
                
                b32 WasIncrementallyLinked = HAS_FLAG(DBIStreamHeader->Flags, BuildFlag_IncrementallyLinked);
                //if(IS_DEBUG_TARGET_ARCHITECTURES(DBIStreamHeader))
                {
                    efly_debug_info out_DebugInfo = {}; 
                    uint32_t TotalDBISubstreamSize = (DBIStreamHeader->ModInfoSize + 
                                                      DBIStreamHeader->SectionContributionSize + 
                                                      DBIStreamHeader->SectionMapSize + 
                                                      DBIStreamHeader->SourceInfoSize + 
                                                      DBIStreamHeader->TypeServerSize + 
                                                      DBIStreamHeader->OptionalDbgHeaderSize + 
                                                      DBIStreamHeader->ECSubstreamSize);
                    
                    Assert((sizeof(epdb_dbi_stream_header) + TotalDBISubstreamSize) == dbi_stream->Size);  
                    
                    //epdb_GetDBISubstreams();
                    BEGIN_SUBSTREAM_EXT(PManager, dbi_stream, sizeof(epdb_dbi_stream_header));
                    epdb_substream ModSubstream = CREATE_SUBSTREAM(PManager, dbi_stream, DBIStreamHeader->ModInfoSize);
                    
#if 0                    
                    //TODO Alex: Parse other substreams 
                    epdb_substream ModSubstream = CREATE_SUBSTREAM(dbi_stream, DBIStreamHeader->SectionContributionSize);
                    epdb_substream ModSubstream = CREATE_SUBSTREAM(dbi_stream, DBIStreamHeader->SectionMapSize); 
                    epdb_substream ModSubstream = CREATE_SUBSTREAM(dbi_stream, DBIStreamHeader->SourceInfoSize);
                    epdb_substream ModSubstream = CREATE_SUBSTREAM(dbi_stream, DBIStreamHeader->TypeServerSize); 
                    epdb_substream ModSubstream = CREATE_SUBSTREAM(dbi_stream, DBIStreamHeader->OptionalDbgHeaderSize);
                    epdb_substream ModSubstream = CREATE_SUBSTREAM(dbi_stream, DBIStreamHeader->ECSubstreamSize);
#endif
                    END_SUBSTREAM_EXT(PManager);
                    
                    GetAllModulesFromPDB(PManager, ModSubstream);
                    
                    CREATE_STREAM(PManager, &PManager->Directory, DBIStreamHeader->SymRecordStream);
                    CREATE_STREAM(PManager, &PManager->Directory, DBIStreamHeader->GlobalStreamIndex);
                    CREATE_STREAM(PManager, &PManager->Directory, DBIStreamHeader->PublicStreamIndex);
                    
                    CreateTracerSymbolsForModule(PManager, PManager->FirstModule, 0);
                    
                    //TODO(Alex): This could not be compact inside a block, use get offset block to find the proper data
                    //NOTE(Alex): This is an array of epdb_mod_info's
                    //epdb_mod_info * ModInfo =    
                    
                }
                
                END_STREAM_EXT(PManager);
            }
            
        }
    }
}











