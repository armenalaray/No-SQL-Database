/*
Alejandro Armenta 
eaglefly_tracer.cpp
*/



/*

typedef struct DECLSPEC_ALIGN(16) _CONTEXT {

    //
    // Register parameter home addresses.
    //
    // N.B. These fields are for convience - they could be used to extend the
    //      context record in the future.
    //
    
    DWORD64 P1Home;
    DWORD64 P2Home;
    DWORD64 P3Home;
    DWORD64 P4Home;
    DWORD64 P5Home;
    DWORD64 P6Home;
    
    //
    // Control flags.
    //
    
    DWORD ContextFlags;
    DWORD MxCsr;
    
    //
    // Segment Registers and processor flags.
    //
    
    WORD   SegCs;
    WORD   SegDs;
    WORD   SegEs;
    WORD   SegFs;
    WORD   SegGs;
    WORD   SegSs;
    DWORD EFlags;
    
    //
    // Debug registers
    //
    
    DWORD64 Dr0;
    DWORD64 Dr1;
    DWORD64 Dr2;
    DWORD64 Dr3;
    DWORD64 Dr6;
    DWORD64 Dr7;
    
    //
    // Integer registers.
    //
    
    DWORD64 Rax;
    DWORD64 Rcx;
    DWORD64 Rdx;
    DWORD64 Rbx;
    DWORD64 Rsp;
    DWORD64 Rbp;
    DWORD64 Rsi;
    DWORD64 Rdi;
    DWORD64 R8;
    DWORD64 R9;
    DWORD64 R10;
    DWORD64 R11;
    DWORD64 R12;
    DWORD64 R13;
    DWORD64 R14;
    DWORD64 R15;
    
    //
    // Program counter.
    //
    
    DWORD64 Rip;
    
    //
    // Floating point state.
    //
    
    union {
        XMM_SAVE_AREA32 FltSave;
        struct {
            M128A Header[2];
            M128A Legacy[8];
            M128A Xmm0;
            M128A Xmm1;
            M128A Xmm2;
            M128A Xmm3;
            M128A Xmm4;
            M128A Xmm5;
            M128A Xmm6;
            M128A Xmm7;
            M128A Xmm8;
            M128A Xmm9;
            M128A Xmm10;
            M128A Xmm11;
            M128A Xmm12;
            M128A Xmm13;
            M128A Xmm14;
            M128A Xmm15;
        } DUMMYSTRUCTNAME;
    } DUMMYUNIONNAME;
    
    //
    // Vector registers.
    //
    
    M128A VectorRegister[26];
    DWORD64 VectorControl;
    
    //
    // Special debug control registers.
    //
    
    DWORD64 DebugControl;
    DWORD64 LastBranchToRip;
    DWORD64 LastBranchFromRip;
    DWORD64 LastExceptionToRip;
    DWORD64 LastExceptionFromRip;
} CONTEXT, *PCONTEXT;

//NOTE(Alex): Exception Records for 32 bit and 64 bit
typedef struct _EXCEPTION_RECORD32 {
    DWORD    ExceptionCode;
    DWORD ExceptionFlags;
    DWORD ExceptionRecord;
    DWORD ExceptionAddress;
    DWORD NumberParameters;
    DWORD ExceptionInformation[EXCEPTION_MAXIMUM_PARAMETERS];
} EXCEPTION_RECORD32, *PEXCEPTION_RECORD32;

typedef struct _EXCEPTION_RECORD64 {
                            DWORD    ExceptionCode;
                            DWORD ExceptionFlags;
                            DWORD64 ExceptionRecord;
                            DWORD64 ExceptionAddress;
                            DWORD NumberParameters;
                            DWORD __unusedAlignment;
                            DWORD64 ExceptionInformation[EXCEPTION_MAXIMUM_PARAMETERS];
                        } EXCEPTION_RECORD64, *PEXCEPTION_RECORD64;
                        
*/

#if 0
inline b32
Win32IsValidIDMap(id_map * IDMap)
{
    b32 Result = (IDMap && IDMap->ID && IDMap->Handle);
    return Result;
}
#endif

//NOTE(Alex): Each key has to be unique! 
internal id_map *   
Win32GetHandleFromID(win32_dispatcher_state * DispState, memory_arena * Arena, memory_index ID, u32 Type = 0, void * Handle = 0)
{
    id_map * Result = 0;
    //TODO(Alex): BETTER HASH FUNCTION!
    u32 Bucket = (u32)(ID  & (ArrayCount(DispState->IDMapHash) - 1));
    id_map ** Base = DispState->IDMapHash + Bucket;
    
    for(id_map * Iter = *Base;
        Iter;
        Iter = Iter->Next)
    {
        if(Iter->ID == ID)
        {
            Result = Iter;
            break;
        }
    }
    
    if(Handle && !Result && Arena)
    {
        Result = DispState->IDMapFirstFree;
        
        if(Result)
        {
            DispState->IDMapFirstFree = Result->Next;
        }
        else
        {
            Result = PushStruct(Arena, id_map);
        }
        
        Result->ID = ID;
        Result->Type = (id_map_type)Type;
        Result->Handle = Handle;
        
        Result->Next = *Base;
        *Base = Result;
    }
    
    return Result;
}

internal void
Win32RemoveHandleFromID(win32_dispatcher_state * DispState, memory_index ID)
{
    id_map * Result = 0;
    //TODO(Alex): BETTER HASH FUNCTION!
    u32 Bucket = (u32)(ID  & (ArrayCount(DispState->IDMapHash) - 1));
    id_map ** Base = DispState->IDMapHash + Bucket;
    id_map * Iter = *Base;
    id_map * Prev = 0;
    for(;
        Iter;
        Prev = Iter, Iter = Iter->Next)
    {
        if(Iter->ID == ID)
        {
            if(Prev)
            {
                Prev->Next = Iter->Next;
            }
            else
            {
                *Base = Iter->Next;
            }
            
            Iter->Next = DispState->IDMapFirstFree;
            DispState->IDMapFirstFree = Iter;
            break;
        }
    }
}

#if 0
internal u32
GetProcessHandle(win32_dispatcher_state * DispState, memory_index ProcessIndex)
{
    u32 Result = 0;
    for(u32 Index = 1;
        Index < DispState->TargetPCount;
        ++Index)
    {
        process_info * PInfo = DispState->PInfos + Index;
        if(PInfo->ProcessInfo.dwProcessId == ProcessIndex)
        {
            Result = Index;
            break;
        }
    }
    
    return Result;
}
#endif

#if 0

struct pdb_sym_iter
{
    char * At;
    u32 TableIndex;
    u32 ScopeIndex;
};

internal win32_sym_contents * 
Win32LoadSymbolsFromSource(win32_dispatcher_state * DispState, char * TargetPDBFullPath)
{
    win32_sym_contents * Result = 0;
    //TODO(Alex): Make User choose pdb TargetFullPath! 
    debug_file_content * PDBContent = Win32ReadEntireFile(TargetPDBFullPath);
    
    super_block * SBlock = (super_block *)PDBContent;
    
    pdb_sym_iter Iter = {};
    Iter.At = PDBContent->Content;
    Iter.TableIndex = 0;
    Iter.ScopeIndex = 0;
    
    for()
    {
        
    }
    
    return Result;
}

#endif

internal memory_index
win32GetProcessStartAddress(win32_dispatcher_state * DispState, DEBUG_EVENT * DebugEvent)
{
    //TODO(Alex): lpStartAddress is busted we need to find a better way to get the REAL process start address
    Assert(DebugEvent);
    memory_index Result = (memory_index)DebugEvent->u.CreateProcessInfo.lpStartAddress; 
    return Result;
}


#define NUM_BETWEEN(Num, Max, Min) ((Num < Max) && (Num > Min))

#if 0
internal efly_disasm_code_block *  
GetLineMapFromAddress(win32_dispatcher_state * DispState, efly_debug_info * DebugInfo, 
                      memory_index Address)
{
    efly_disasm_code_block * Result = 0;
    efly_disasm_code_block * LineMap = DebugInfo->Moudle.FirstLineMap;
    u32 Index = LineMap->LineNum;
    
    for(; 
        LineMap;
        LineMap = LineMap->Next)
    {
        if(NUM_BETWEEN(Address, LineMap->EndOffset, LineMap->BeginOffset))
        {
            Result = LineMap;//BREAKPOINT
        }
    }
    
    return Result;
}

internal void
DisplayLineSymbols(win32_dispatcher_state * DispState, address_line_map * LineMap)
{
    char Buffer[4096] = {0};
    for(symbol_entry * Entry = LineMap->SymbolEntryBlock; 
        Entry;
        Entry = Entry->Next)
    {
        char * Symbol = 0;
        switch(Entry->SymType)
        {
            case SymType_Function:
            {
                Symbol = Entry->FuncSymbol;
            }break;
            case SymType_Global:
            {
                Symbol = Entry->GlobalSymbol;
            }break;
            case SymType_Local:
            {
                Symbol = Entry->LocalSymbol;
            }break;
            case SymType_StructClass:
            {
                Symbol = Entry->StructClassSymbol;
            }break;
            default:
            {
                InvalidCodePath;
            }
        }
        
        if(Symbol)
        {
            sprintf_s(Buffer, ArrayCount(Buffer), "0x%p SymType: %i,  %s TargetType: %s", 
                      (void*)Entry->MemoryAddress, Entry->SymType, Symbol, Entry->TargetType->Name);
            OutputDebugStringA(Buffer);
        }
    }
    
}
#endif

//TODO(Alex): Signal Register display to UI Element
internal void
Win32Displayx64Registers(win32_dispatcher_state * DispState, CONTEXT * TContext)
{
    char Buffer[4096] = {0};
    sprintf_s(Buffer, ArrayCount(Buffer), "----------\nRegisters at 0x%p:\nRax: 0x%p\nRcx: 0x%p\nRdx: 0x%p\nRbx: 0x%p\nRsp: 0x%p\nRbp: 0x%p\nRsi: 0x%p\nRdi: 0x%p\nR8: 0x%p\nR9: 0x%p\n", 
              (void*)TContext->Rip,
              (void*)TContext->Rax,
              (void*)TContext->Rcx,
              (void*)TContext->Rdx,
              (void*)TContext->Rbx,
              (void*)TContext->Rsp,
              (void*)TContext->Rbp,
              (void*)TContext->Rsi,
              (void*)TContext->Rdi,
              (void*)TContext->R8,
              (void*)TContext->R9);
    OutputDebugStringA(Buffer);
}

internal void
Win32UnloadIMAGE(win32_dispatcher_state * DispState)
{
    EndTempMemory(&DispState->AssetTempMem);
    //TODO(Alex): Unload Process And PDB out of memory!
}

internal void
Win32LoadIMAGE(win32_dispatcher_state * DispState, efly_process * Process)
{
    process_state * PState = &Process->State;
    process_info * PInfo = &Process->Info;
    if(!PState->ProcessIsRunning)
    {
        //TODO(Alex): Do we want to have a custom setup for the window?
        STARTUPINFO StartupInfo = {};
        StartupInfo.cb = sizeof(STARTUPINFO);
        
        load_process_data * ProcessData = &PInfo->LoadProcessData;
        char Command[1024] = {0};
        char * TargetName = 0;
        if(ProcessData->RunFromCmdLine)
        {
            char * CommandToken = "/c ";
            ConcatStrings(CommandToken, StringLength(CommandToken), 
                          ProcessData->TargetImageFullPath, StringLength(ProcessData->TargetImageFullPath), 
                          Command, ArrayCount(Command));
            
            TargetName = ProcessData->CmdEXEFullPath;
        }
        else
        {
            TargetName = ProcessData->TargetImageFullPath;
        }
        
        DispState->AssetTempMem = BeginTempMemory(&DispState->AssetArena);
        //TODO(Alex): Make this a working thread
        //DispState->PDBExistsForThisImage = Win32LoadEDebugInfoFromPDB(DispState, DispState->EDebugInfoArena, ProcessData->TargetPDBFullPath);
        //if(DispState->PDBExistsForThisImage)
        {
            //NOTE(Alex): Right now we are only debugging main process, no child processes! 
            PState->ProcessIsRunning = (CreateProcessA(TargetName, 
                                                       Command, //NOTE(Alex): Command line for cmd.exe  
                                                       0,
                                                       0,
                                                       false,
                                                       DEBUG_ONLY_THIS_PROCESS, //TODO(Alex): Debug child processes? DEBUG_PROCESS
                                                       0, //TODO(Alex): Set environment block? CREATE_UNICODE_ENVIRONMENT for user processes that setup a unicode environment 
                                                       0,
                                                       &StartupInfo,
                                                       &PInfo->ProcessInfo));
        }
        
#if 0        
        else
        {
            OutputDebugStringA("Not Valid PDB");
        }
#endif
        //LoadSymbolsForImage(DispState);
        //TODO(Alex): The dispatcher doesn thave to know about symbols, we could have a second call inside here
        //HERE is where the debug manager is going to be
        
    }
}

//TODO(Alex): Make a Handle system for IDMaps
internal efly_process * 
Win32GetProcessFromID(win32_dispatcher_state * DispState,  memory_index ProcessIndex)
{
    efly_process * Result = 0;
    id_map * Map = Win32GetHandleFromID(DispState, 0, ProcessIndex);
    if(Map && (Map->Type == IDMap_Process))
    {
        Result = (efly_process*)Map->Handle;
    }
    
    return Result;
}


internal void
BEGIN_PROCESS(win32_dispatcher_state * DispState, load_process_data * PData)
{
    if(PData)
    {
        Assert(DispState->StorageCount <  ArrayCount(DispState->DebugStorage));
        id_map * Map = DispState->IDMapFirstFree;
        efly_debug_storage * Storage = 0;
        if(Map)
        {
            Storage = (efly_debug_storage*)Map->Handle;
        }
        else
        {
            Storage = DispState->DebugStorage + DispState->StorageCount++;
        }
        
        Storage->P.Info.LoadProcessData = *PData;
        Storage->P.State.ContinueTracing = true;
        Storage->P.State.IsInitialized = true;
        Win32LoadIMAGE(DispState, &Storage->P);
        if(Storage->P.State.ProcessIsRunning)
        {
            Win32GetHandleFromID(DispState, &DispState->TranState->Out_TracerSubArena.Arena, Storage->P.Info.ProcessInfo.dwProcessId, IDMap_Process, Storage);
        }
    }
}

internal void
END_PROCESS(win32_dispatcher_state * DispState, memory_index ProcessIndex)
{
    Win32RemoveHandleFromID(DispState, ProcessIndex);
}

inline memory_index
GET_NATURAL_BOUNDARY(memory_index Size)
{
    memory_index Result = 1;
    while(Result < Size)
    {
        Result <<= 1;
    }
    
    return Result;
}

//NOTE(Alex): This will create the call stack from PDB symbol information
internal efly_lexical_scope * 
GET_LEXICAL_SCOPE(win32_dispatcher_state * DispState, process_state * PState,  memory_index Address)
{
    efly_lexical_scope * Result = 0;
    if(PState->PDBExistsForThisImage)
    {
        efly_debug_info * DebugInfo = (efly_debug_info*)DispState->AssetArena.Base; 
        for(efly_opcode_block * OBlock = DebugInfo->OpcodeSentinel.Next;
            OBlock != &DebugInfo->OpcodeSentinel;
            OBlock = OBlock->Next)
        {
            if(NUM_BETWEEN(Address, OBlock->EndOffset, OBlock->BeginOffset))
            {
                Result = (efly_lexical_scope*)((char*)&DebugInfo->LexicalScopeSentinel + (OBlock->ScopeIndex * GET_NATURAL_BOUNDARY(sizeof(efly_lexical_scope))));
            }
        }
    }
    
    return Result;
}


internal void 
DisplaySourceFileAtLine(win32_dispatcher_state * DispState, efly_lexical_scope * LexicalScope)
{
    
}

internal void
DisplayLocalSymmbols(win32_dispatcher_state * DispState, efly_lexical_scope * LexicalScope)
{
    
}

internal void 
DisplayWatchSymbols(win32_dispatcher_state * DispState, efly_lexical_scope * LexicalScope)
{
    
}

internal void
DisplayCallStack(win32_dispatcher_state * DispState, efly_lexical_scope * LexicalScope)
{
    
}

internal void
DESTRUCT_LEXICAL_SCOPE(efly_lexical_scope * LexicalScope)
{
    
}

internal void
SET_BREAKPOINT_AT(win32_dispatcher_state * DispState, process_info * PInfo, void * IP)
{
    SIZE_T BytesRead = {};
    uint8_t InterruptCodeByte = 0xCC;//NOTE(Alex): 204
    DispState->OriginalCodeByte = 0;
    if(ReadProcessMemory(PInfo->ProcessInfo.hProcess, 
                         IP,
                         &DispState->OriginalCodeByte,
                         1,
                         &BytesRead) && (BytesRead == 1))
    {
        SIZE_T BytesWritten = {};
        if(WriteProcessMemory(PInfo->ProcessInfo.hProcess,
                              IP,
                              &InterruptCodeByte,
                              1,
                              &BytesWritten) && (BytesWritten == 1))
        {
            FlushInstructionCache(PInfo->ProcessInfo.hProcess,
                                  IP,
                                  1);
        }
    }
}

#define GET_EDEBUG_INFO(Info) (edebug_info *)((Info).Base)

inline void
POP_INPUT_COMMAND(efly_tracer_input * TracerInput, efly_input_command * out_Command)
{
    if(TracerInput && out_Command)
    {
        efly_input_command * Temp = TracerInput->FirstCommand;
        if(Temp)
        {
            *out_Command = *Temp;
            TracerInput->FirstCommand = TracerInput->FirstCommand->Next;
            Temp->Next = TracerInput->CommandFirstFree; 
            TracerInput->CommandFirstFree = Temp; 
        }
    }
}

internal b32 
PROCESS_INPUT_COMMAND(efly_input_command * Command, efly_input_command_type Type)
{
    b32 Result = (Command && (Command->Type == Type));
    return Result;
}



//TODO(Alex): Implement print_f function ourselves!
internal void
Win32DebugUpdateTracer(efly_memory * Memory)
{
    transient_state * TranState = (transient_state *)Memory->TransientStorage; 
    if(TranState->IsInitialized)
    {
        win32_dispatcher_state * DispState = (win32_dispatcher_state *)Memory->TracerStorage; 
        if(!DispState->IsInitialized)
        {
            InitializeArena(&DispState->AssetArena, (char*)Memory->TracerStorage + sizeof(win32_dispatcher_state), Memory->TracerStorageSize - sizeof(win32_dispatcher_state)); 
            //NOTE(Alex): We will always start with process index = 1
            DispState->StorageCount = 1;
            DispState->TranState = TranState;
            DispState->IsDummyBP = true;
            DispState->IsInitialized = true;
        }
        
        efly_input_command out_Command = {};
        POP_INPUT_COMMAND(&TranState->TracerInput, &out_Command);
        if(PROCESS_INPUT_COMMAND(&out_Command, InputCommand_LOAD_PROCESS))
        {
            BEGIN_PROCESS(DispState, &out_Command.LoadProcessData);
        }
        
#if 0
        //IMPORTANT(Alex): We have to make sure the user always creates a valid PDB file 
        //so that we can parse it an reload the image as well!
        FILETIME IMAGELastWriteTime = Win32GetFileLastWriteTime(InputData->TargetImageFullPath);
        if(CompareFileTime(&IMAGELastWriteTime, &DispState->IMAGELastWriteTime) != 0)
        {
            Win32UnloadIMAGE(DispState);
            Win32LoadIMAGE(DispState, InputData);
        }
#endif
        
        DEBUG_EVENT Out_DebugEvent;
        DWORD ContinueStatus = DBG_CONTINUE;
        //TODO(Alex): Do we want to handle multiple Processes at the same time, 
        //if we do we will need to change the Winapi for our own debug message tracing stuff
        b32 ResultGathered = WaitForDebugEvent(&Out_DebugEvent, 0);
        efly_process * Process = Win32GetProcessFromID(DispState, Out_DebugEvent.dwProcessId);
        if(Process)
        {
            process_state * PState = &Process->State;
            process_info * PInfo = &Process->Info;
            
            CONTEXT TContext = {};
            TContext.ContextFlags = CONTEXT_ALL;
            GetThreadContext(PInfo->ProcessInfo.hThread, &TContext);
            if(ResultGathered)
            {
                if(PState->ProcessIsRunning)
                {
                    switch(Out_DebugEvent.dwDebugEventCode)
                    {
                        case EXCEPTION_DEBUG_EVENT:
                        {
#if defined(_M_IX86)
                            EXCEPTION_RECORD32 ERecord = Out_DebugEvent.u.Exception.ExceptionRecord;
#elif defined(_M_X64)
                            EXCEPTION_RECORD TempRecord = Out_DebugEvent.u.Exception.ExceptionRecord;
                            EXCEPTION_RECORD64 ERecord = {};
                            ERecord.ExceptionCode = TempRecord.ExceptionCode;
                            ERecord.ExceptionFlags = TempRecord.ExceptionFlags;
                            ERecord.ExceptionRecord = (DWORD64)TempRecord.ExceptionRecord;
                            ERecord.ExceptionAddress = (DWORD64)TempRecord.ExceptionAddress;
                            ERecord.NumberParameters = TempRecord.NumberParameters;
                            ERecord.__unusedAlignment = 0;
                            for(uint32_t Index = 0;
                                Index < EXCEPTION_MAXIMUM_PARAMETERS;
                                ++Index)
                            {
                                ERecord.ExceptionInformation[Index] = TempRecord.ExceptionInformation[Index];
                            }
#endif
                            //NOTE(Alex): Set resume bit after breakpoint processing
                            TContext.EFlags |= 0x10000; 
                            
                            b32 EFirstChance = (Out_DebugEvent.u.Exception.dwFirstChance) ? true : false;
                            if(EFirstChance)
                            {
                                switch(ERecord.ExceptionCode)
                                {
                                    case EXCEPTION_BREAKPOINT:
                                    {
                                        //NOTE(Alex): We dont handle the first breakpoint made by the system! 
                                        
                                        if(((memory_index)ERecord.ExceptionAddress == DispState->BPAddresses[DispState->CurrentBPIndex]) && PState->ContinueTracing)
                                        {
                                            //TODO(Alex): These is platform specific, handle each platform as well!
#if defined(_M_IX86)
                                            void * IP = (void*)(--TContext.Eip);  
#elif defined(_M_X64)
                                            void * IP = (void*)(--TContext.Rip);  
#endif
                                            
                                            //TODO(Alex):Win32DisplayRegistersFromContext(DispState, &TContext, ArchMode);
                                            SIZE_T BytesWritten = {};
                                            if(WriteProcessMemory(PInfo->ProcessInfo.hProcess,
                                                                  IP,
                                                                  &DispState->OriginalCodeByte,
                                                                  1,
                                                                  &BytesWritten) && (BytesWritten == 1))
                                            {
                                                FlushInstructionCache(PInfo->ProcessInfo.hProcess, IP, 1);
                                            }
                                        }
                                        
                                        
                                        //TODO(Alex): This has to go on the collation step, put it here temporarilly 
                                        //DisplayDisAtIntructionP(PInfo, SymTable);
                                        //TODO(Alex): Define a debugger platform identifier for x64 x86 modes
                                        Win32Displayx64Registers(DispState, &TContext);
                                        
#if 0                                
                                        PInfo->CurrentLexicalScope = GET_LEXICAL_SCOPE(PInfo, (memory_index)TContext.Rip);
                                        DisplaySourceFileAtLine(DispState, PInfo->CurrentLexicalScope);
                                        DisplayLocalSymmbols(DispState, DispState->CurrentLexicalScope);
                                        DisplayWatchSymbols(DispState, DispState->CurrentLexicalScope);
                                        DisplayCallStack(DispState, DispState->CurrentLexicalScope);
#endif
                                        //address_line_map * LineMap = GetLineMapFromAddress(DispState, );
                                        
                                        if(DispState->IsDummyBP)
                                        {
                                            DispState->IsDummyBP = false;
                                        }
                                        else
                                        {
                                            PState->ContinueTracing = false;
                                        }
                                        
                                    }break;
                                    //NOTE(Alex): A trace trap or other single-instruction mechanism signaled that one instruction has been executed.
                                    case EXCEPTION_SINGLE_STEP:
                                    {
                                        PState->ContinueTracing = false;
                                        Win32Displayx64Registers(DispState, &TContext);
                                    }break;
                                    //NOTE(Alex): The thread tried to read from or write to a virtual address for which it does not have the appropriate access.
                                    case EXCEPTION_ACCESS_VIOLATION:
                                    {
                                        int x = 5;
                                    }break;
                                    //NOTE(Alex): The thread tried to access an array element that is out of bounds and the underlying hardware supports bounds checking. 
                                    case EXCEPTION_ARRAY_BOUNDS_EXCEEDED:
                                    {
                                        int x = 5;
                                    }break;
                                    //NOTE(Alex): The thread tried to read or write data that is misaligned on hardware that does not provide alignment. 
                                    //For example, 16-bit values must be aligned on 2-byte boundaries; 32-bit values on 4-byte boundaries, and so on.
                                    case EXCEPTION_DATATYPE_MISALIGNMENT:
                                    {
                                        int x = 5;
                                    }break;
                                    //NOTE(Alex): One of the operands in a floating-point operation is denormal. A denormal value is one that is too small to represent as a standard floating-point value.
                                    case EXCEPTION_FLT_DENORMAL_OPERAND:
                                    {
                                        int x = 5;
                                    }break;
                                    //NOTE(Alex): The thread tried to divide a floating-point value by a floating-point divisor of zero.
                                    case EXCEPTION_FLT_DIVIDE_BY_ZERO:
                                    {
                                        int x = 5;
                                    }break;
                                    //NOTE(Alex): The result of a floating-point operation cannot be represented exactly as a decimal fraction.
                                    case EXCEPTION_FLT_INEXACT_RESULT:
                                    {
                                        int x = 5;
                                    }break;
                                    //NOTE(Alex): This exception represents any floating-point exception not included in this list.
                                    case EXCEPTION_FLT_INVALID_OPERATION:
                                    {
                                        int x = 5;
                                    }break;
                                    //NOTE(Alex): The exponent of a floating-point operation is greater than the magnitude allowed by the corresponding type.
                                    case EXCEPTION_FLT_OVERFLOW:
                                    {
                                        int x = 5;
                                    }break;
                                    //NOTE(Alex): The stack overflowed or underflowed as the result of a floating-point operation.
                                    case EXCEPTION_FLT_STACK_CHECK:
                                    {
                                        int x = 5;
                                    }break;
                                    
                                    //NOTE(Alex): The exponent of a floating-point operation is less than the magnitude allowed by the corresponding type.
                                    case EXCEPTION_FLT_UNDERFLOW:
                                    {
                                        int x = 5;
                                    }break;
                                    //NOTE(Alex): The thread tried to execute an invalid instruction.
                                    case EXCEPTION_ILLEGAL_INSTRUCTION:
                                    {
                                        int x = 5;
                                    }break;
                                    //NOTE(Alex): The thread tried to access a page that was not present, and the system was unable to load the page. For example, this exception might occur if a network connection is lost while running a program over the network.
                                    case EXCEPTION_IN_PAGE_ERROR:
                                    {
                                        int x = 5;
                                    }break;
                                    //NOTE(Alex): The thread tried to divide an integer value by an integer divisor of zero.
                                    case EXCEPTION_INT_DIVIDE_BY_ZERO:
                                    {
                                        int x = 5;
                                    }break;
                                    //NOTE(Alex): The result of an integer operation caused a carry out of the most significant bit of the result.
                                    case EXCEPTION_INT_OVERFLOW:
                                    {
                                        int x = 5;
                                    }break;
                                    //NOTE(Alex): An exception handler returned an invalid disposition to the exception dispatcher. Programmers using a high-level language such as C should never encounter this exception.
                                    case EXCEPTION_INVALID_DISPOSITION:
                                    {
                                        int x = 5;
                                    }break;
                                    //NOTE(Alex): The thread tried to continue execution after a noncontinuable exception occurred.
                                    case EXCEPTION_NONCONTINUABLE_EXCEPTION:
                                    {
                                        int x = 5;
                                    }break;
                                    
                                    //NOTE(Alex): The thread tried to execute an instruction whose operation is not allowed in the current machine mode.
                                    case EXCEPTION_PRIV_INSTRUCTION:
                                    {
                                        int x = 5;
                                    }break;
                                    
                                    //NOTE(Alex): The thread used up its stack.
                                    case EXCEPTION_STACK_OVERFLOW:
                                    {
                                        int x = 5;
                                    }break;
                                    default:
                                    {
                                        //ContinueStatus = DBG_EXCEPTION_NOT_HANDLED;
                                    }break;
                                }
                            }
                            
                        }break;
                        case OUTPUT_DEBUG_STRING_EVENT:
                        {
                            OUTPUT_DEBUG_STRING_INFO DebugString = Out_DebugEvent.u.DebugString;
                            SIZE_T BytesRead;
                            
                            //TODO(Alex): process unicode strings
                            //NOTE(Alex): UTF-16 is Windows default unicode support
                            unsigned int StringSize = 0;
                            if(!DebugString.fUnicode)
                            {
                                StringSize = DebugString.nDebugStringLength;
                            }
                            //TODO(Alex): Do we want to set a limit size for OutputDebugStringA?
                            unsigned int ExtraBytes = 20;
                            char * Buffer = (StringSize) ? (char*)malloc(StringSize + ExtraBytes) : 0;
                            if(ReadProcessMemory(PInfo->ProcessInfo.hProcess, 
                                                 DebugString.lpDebugStringData,
                                                 Buffer,
                                                 StringSize,
                                                 &BytesRead) && (BytesRead == StringSize))
                            {
                                char * Char = Buffer + StringSize - 1;
                                *Char++ = '\n'; 
                                *Char = '\0'; 
                                OutputDebugStringA(Buffer);
                            }
                            free(Buffer);
                        }break;
                        case CREATE_PROCESS_DEBUG_EVENT:
                        {
                            char Buffer[4096] = {0};
                            sprintf_s(Buffer, ArrayCount(Buffer), 
                                      "Process 0x%p ID(0x%x) created. File: 0x%p Thread: 0x%p ImageBase: 0x%p Starting address: 0x%p,\n", 
                                      Out_DebugEvent.u.CreateProcessInfo.hProcess,
                                      Out_DebugEvent.dwProcessId, 
                                      Out_DebugEvent.u.CreateProcessInfo.hFile,
                                      Out_DebugEvent.u.CreateProcessInfo.hThread,
                                      Out_DebugEvent.u.CreateProcessInfo.lpBaseOfImage,
                                      Out_DebugEvent.u.CreateProcessInfo.lpStartAddress);
                            OutputDebugStringA(Buffer);
                            //NOTE(Alex): We will stop at extern "C" int mainCRTStartup() : 00007FF6A6D21000
                            DispState->BPAddresses[0] = win32GetProcessStartAddress(DispState, &Out_DebugEvent);
                            DispState->CurrentBPIndex = 0;
                            SET_BREAKPOINT_AT(DispState, PInfo, (void*)DispState->BPAddresses[0]);
                            PInfo->BaseOfImage = Out_DebugEvent.u.CreateProcessInfo.lpBaseOfImage;
                            PInfo->StartAddress = Out_DebugEvent.u.CreateProcessInfo.lpStartAddress;
                            PInfo->HFile = Out_DebugEvent.u.CreateProcessInfo.hFile;
                        }break;
                        case EXIT_PROCESS_DEBUG_EVENT:
                        {
                            PInfo->ProcessExitCode = Out_DebugEvent.u.ExitProcess.dwExitCode;
                            char Buffer[4096] = {0};
                            sprintf_s(Buffer, ArrayCount(Buffer), "The process exited with code: %x\n", PInfo->ProcessExitCode);
                            OutputDebugStringA(Buffer);
                            
                            PState->ProcessIsRunning = false;
                            PState->InitProcess = false;
                            END_PROCESS(DispState, Out_DebugEvent.dwProcessId);
                            CloseHandle(PInfo->HFile);
                        }break;
                        
                        case CREATE_THREAD_DEBUG_EVENT:
                        {
                            char Buffer[4096] = {0};
                            //TODO(Alex): Create Arena TracerArena!
                            //Win32GetHandleFromID(DispState, , (memory_index)Out_DebugEvent.dwThreadId, Out_DebugEvent.u.CreateThread.hThread);
                            sprintf_s(Buffer, ArrayCount(Buffer), 
                                      "Thread 0x%p  ID(0x%x) created. Starting address: 0x%p\n", 
                                      Out_DebugEvent.u.CreateThread.hThread,
                                      Out_DebugEvent.dwThreadId, 
                                      Out_DebugEvent.u.CreateThread.lpStartAddress);
                            OutputDebugStringA(Buffer);
                        }break;
                        case EXIT_THREAD_DEBUG_EVENT:
                        {
                            //EXIT_THREAD_DEBUG_INFO;
                            char Buffer[4096] = {0};
                            sprintf_s(Buffer, ArrayCount(Buffer), 
                                      "Thread 0x%p  ID(0x%x) exited with code %x\n", 
                                      (void*)0,//Win32GetHandleFromID(DispState, (memory_index)Out_DebugEvent.dwThreadId),
                                      Out_DebugEvent.dwThreadId, 
                                      Out_DebugEvent.u.ExitThread.dwExitCode);
                            OutputDebugStringA(Buffer);
                        }break;
                        
                        case LOAD_DLL_DEBUG_EVENT:
                        {
                            //GetHandleFromTable(Out_DebugEvent.u.LoadDll.lpImageName, Out_DebugEvent.u.LoadDll.hFile);
                            char Buffer[4096] = {0};
                            sprintf_s(Buffer, ArrayCount(Buffer), "DLL 0x%p loaded at address 0x%p\n", 
                                      Out_DebugEvent.u.LoadDll.hFile, 
                                      Out_DebugEvent.u.LoadDll.lpBaseOfDll);
                            OutputDebugStringA(Buffer);
                            //TODO(Alex): Load DLL Symbols if any?
                            Win32GetHandleFromID(DispState, &TranState->Out_TracerSubArena.Arena, (memory_index)Out_DebugEvent.u.LoadDll.lpBaseOfDll, IDMap_DLL, Out_DebugEvent.u.LoadDll.hFile);
                        }break;
                        case UNLOAD_DLL_DEBUG_EVENT:
                        {
                            char Buffer[4096] = {0};
                            sprintf_s(Buffer, ArrayCount(Buffer), "DLL 0x%p loaded at address 0x%p\n", 
                                      (void*)0,//Win32GetHandleFromID(DispState, (memory_index)Out_DebugEvent.u.UnloadDll.lpBaseOfDll), 
                                      Out_DebugEvent.u.UnloadDll.lpBaseOfDll);
                            OutputDebugStringA(Buffer);
                            id_map * Map =  Win32GetHandleFromID(DispState, 0, (memory_index)Out_DebugEvent.u.UnloadDll.lpBaseOfDll);
                            CloseHandle(Map->Handle);
                        }break;
                        
                        case RIP_EVENT:
                        {
                            //TODO(Alex): Error Handling?
                            char Buffer[4096] = {0};
                            sprintf_s(Buffer, ArrayCount(Buffer), "Error 0x%x of type 0x%x\n", 
                                      Out_DebugEvent.u.RipInfo.dwError,
                                      Out_DebugEvent.u.RipInfo.dwType);
                            OutputDebugStringA(Buffer);
                        }break;
                        default:
                        {
                            //InvalidCodePath;
                        }break;
                    }
                }//NOTE(Alex): 
            }
            
            
            if(!PState->ContinueTracing && PROCESS_INPUT_COMMAND(&out_Command, InputCommand_CONTINUE))
            {
                PState->ContinueTracing = true;
            }
            
            if(!PState->ContinueTracing && PROCESS_INPUT_COMMAND(&out_Command, InputCommand_STEP_NEXT))
            {
                TContext.EFlags |= 0x100; 
                PState->ContinueTracing = true;
            }
            
            SetThreadContext(PInfo->ProcessInfo.hThread, &TContext);
            //NOTE(Alex): We should not close any Handles being returned from the debugee application
            //ContinueDebugEvent will close them for us
            if(PState->ContinueTracing)
            {
                //SAVE_WATCH_SYMBOLS(DispState);
                //TODO(Alex): Use permanent arenas and make a list of breakpointlexical scope storage so that we don't need to create them every time!
                DESTRUCT_LEXICAL_SCOPE(DispState->CurrentLexicalScope);
                ContinueDebugEvent(Out_DebugEvent.dwProcessId,
                                   Out_DebugEvent.dwThreadId,
                                   ContinueStatus);
            }
        }
    }
}
















