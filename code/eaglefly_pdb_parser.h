/*

eaglefly_pdb_parser.h
NOTE(Alex): PDB Access
egf

*/

#include "eaglefly_debug_info.h"

#define MAGIC_SIZE_PDB 32
#define MAX_STREAM_COUNT 128



#if defined(__cplusplus)
extern "C" {
#endif
    
#pragma pack(push, 1)
    typedef struct epdb_super_block
    {
        char Magic[MAGIC_SIZE_PDB];
        uint32_t BlockSize; //NOTE(Alex): 512, 1024, 2048, 4096 bytes
        uint32_t FreePageMap; //NOTE(Alex): This can be 1 or 2
        uint32_t NumBlocks;
        uint32_t DirectorySize;
        uint32_t Unkwown;
        uint32_t BlockMapAddress;
    }epdb_super_block;
    
    
    typedef struct epdb_GUID 
    {
        DWORD Data1;
        WORD  Data2;
        WORD  Data3;
        BYTE  Data4[8];
    } epdb_GUID;
    
#if 0    
    typedef enum epdb_pdb_stream_version 
    {
        pdbps_VC2 = 19941610,
        pdbps_VC4 = 19950623,
        pdbps_VC41 = 19950814,
        pdbps_VC50 = 19960307,
        pdbps_VC98 = 19970604,
        pdbps_VC70Dep = 19990604,
        pdbps_VC70 = 20000404,
        pdbps_VC80 = 20030901,
        pdbps_VC110 = 20091201,
        pdbps_VC140 = 20140508,
    }epdb_pdb_stream_version;
    
    typedef enum epdb_dbi_stream_version 
    {
        VC41 = 930803,
        V50 = 19960307,
        V60 = 19970606,
        V70 = 19990903,
        V110 = 20091201
    };
#endif
    
    typedef enum epdb_build_flags
    {
        BuildFlag_IncrementallyLinked = (1 << 0),
        BuildFlag_PrivateSymStripped = (1 << 1),
        BuildFlag_HasConflictingTypes = (1 << 2),
    }epdb_pdb_build_flags;
    
    
    typedef enum epdb_target_architectures
    {
        CPU_x86,
        CPU_x64,
    }epdb_target_architectures;
    
    
    typedef struct epdb_pdb_stream_header 
    {
        uint32_t Version;
        uint32_t Signature;
        uint32_t Age;
        //TODO(Alex): Make a unique cross-platform GUID? 
        epdb_GUID ID;
    }epdb_pdb_stream_header;
    
    
    typedef struct epdb_dbi_stream_header 
    {
        int32_t VersionSignature;
        uint32_t VersionHeader;
        uint32_t Age;
        uint16_t GlobalStreamIndex;
        uint16_t BuildNumber;
        uint16_t PublicStreamIndex;
        uint16_t PdbDllVersion;//NOTE(Alex):  The version number of mspdbXXXX.dll used to produce this PDB
        uint16_t SymRecordStream;
        uint16_t PdbDllRbld;
        int32_t ModInfoSize;
        int32_t SectionContributionSize;
        int32_t SectionMapSize;
        int32_t SourceInfoSize;
        int32_t TypeServerSize;
        uint32_t MFCTypeServerIndex;
        int32_t OptionalDbgHeaderSize;
        int32_t ECSubstreamSize;
        uint16_t Flags;
        uint16_t Machine;
        uint32_t Padding;
    }epdb_dbi_stream_header;
    
    typedef struct epdb_section_contrib_entry 
    {
        uint16_t Section;
        char Padding1[2];
        int32_t Offset;
        int32_t Size;
        uint32_t Characteristics;
        uint16_t ModuleIndex;
        char Padding2[2];
        uint32_t DataCrc;
        uint32_t RelocCrc;
    }epdb_section_contrib_entry;
    
    typedef struct epdb_module_info 
    {
        uint32_t Unused1;
        epdb_section_contrib_entry SectionContr;
        uint16_t Flags;
        uint16_t ModuleSymStream;
        uint32_t SymByteSize;
        uint32_t C11ByteSize;
        uint32_t C13ByteSize;
        uint16_t SourceFileCount;
        char Padding[2];
        uint32_t Unused2;
        uint32_t SourceFileNameIndex;
        uint32_t PdbFilePathNameIndex;//38 + 26
        //64 bytes till here
        char * ModuleName;
        char * ObjFileName;
    }epdb_module_info;
    
    
#pragma pack(pop)
    
    typedef enum epdb_stream_indices
    {
        StreamIndex_Old,
        StreamIndex_PDB,
        StreamIndex_TPI,
        StreamIndex_DBI,
        StreamIndex_IPI,
        
        /*
NOTE(Alex) : This are not know until Prev Streams being parsed!
        StreamType_ModInfo,
        StreamType_Public,
        StreamType_Global,
        StreamType_TPIHash,
        StreamType_IPIHash,
        */
    }epdb_stream_indices;
    
    typedef enum epdb_substream_indices
    {
        SubstreamIndex_ModInfoSize, // - The length of the Module Info Substream.
        SubstreamIndex_SectionContributionSize, // - The length of the Section Contribution Substream.
        SubstreamIndex_SectionMapSize, // - The length of the Section Map Substream.
        SubstreamIndex_SourceInfoSize, // - The length of the File Info Substream.
        SubstreamIndex_TypeServerSize, // - The length of the Type Server Substream.
        SubstreamIndex_OptionalDbgHeaderSize, // - The length of the Optional Debug Header Stream.
        SubstreamIndex_ECSubstreamSize, // - The length of the EC Substream.
    }epdb_substream_indices;
    
    typedef struct epdb_block
    {
        uint32_t Index;
        char * Base_;
        epdb_block * Next;
        epdb_block * Prev;
    }epdb_block;
    
    typedef struct epdb_stream
    {
        uint32_t Size;
        uint32_t BlockCount;
        char * FirstBlockBase;
        epdb_block BlockSentinel;
    }epdb_stream;
    
    typedef struct epdb_substream
    {
        epdb_stream * Stream;
        char * Base;
        memory_index Size;
    }epdb_substream;
    
    typedef struct epdb_module
    {
        epdb_module_info * Info;
        epdb_module * Next;
    }epdb_module;
    
    //NOTE(Alex): On recompilation we will need to reload the whole file.
    typedef struct epdb_stream_directory
    {
        uint32_t StreamCount;
        epdb_stream * Streams[MAX_STREAM_COUNT];
    }epdb_stream_directory;
    
    typedef struct epdb_manager
    {
        b32 IsInitialized;
        b32 StreamExtraction;
        char * BeginOfFile;
        epdb_super_block * SBlock;
        
        epdb_module * FirstModule; 
        epdb_substream ModSubstream;
        epdb_stream_directory Directory;
        
        uint32_t IntervalBlockCount;//TODO(Alex): Test this!
        uint32_t DirectoryBlockCount;
        
        uint32_t TempPDBStorageSize;
        memory_arena TempArena;
        
        //NOTE(Alex): Temporal stream read back storage!
        epdb_stream * CurrentStream;
        uint32_t * ResultBlockIndex;
        
        char * SubstreamPtr;
        
    }epdb_manager;
    
    
    /*
    typedef enum CV_CPU_TYPE_e {   
        CV_CFL_8080         = 0x00,  
        CV_CFL_8086         = 0x01,  
        CV_CFL_80286        = 0x02,  
        CV_CFL_80386        = 0x03,  
        CV_CFL_80486        = 0x04,  
        CV_CFL_PENTIUM      = 0x05,  
        CV_CFL_PENTIUMII    = 0x06,  
        CV_CFL_PENTIUMPRO   = CV_CFL_PENTIUMII,  
        CV_CFL_PENTIUMIII   = 0x07,  
        CV_CFL_MIPS         = 0x10,  
        CV_CFL_MIPSR4000    = CV_CFL_MIPS,  
        CV_CFL_MIPS16       = 0x11,  
        CV_CFL_MIPS32       = 0x12,  
        CV_CFL_MIPS64       = 0x13,  
        CV_CFL_MIPSI        = 0x14,  
        CV_CFL_MIPSII       = 0x15,  
        CV_CFL_MIPSIII      = 0x16,  
        CV_CFL_MIPSIV       = 0x17,  
        CV_CFL_MIPSV        = 0x18,  
        CV_CFL_M68000       = 0x20,  
        CV_CFL_M68010       = 0x21,  
        CV_CFL_M68020       = 0x22,  
        CV_CFL_M68030       = 0x23,  
        CV_CFL_M68040       = 0x24,  
        CV_CFL_ALPHA        = 0x30,  
        CV_CFL_ALPHA_21064  = 0x30,  
        CV_CFL_ALPHA_21164  = 0x31,  
        CV_CFL_ALPHA_21164A = 0x32,  
        CV_CFL_ALPHA_21264  = 0x33,  
        CV_CFL_ALPHA_21364  = 0x34,  
        CV_CFL_PPC601       = 0x40,  
        CV_CFL_PPC603       = 0x41,  
        CV_CFL_PPC604       = 0x42,  
        CV_CFL_PPC620       = 0x43,  
        CV_CFL_PPCFP        = 0x44,  
        CV_CFL_SH3          = 0x50,  
        CV_CFL_SH3E         = 0x51,  
        CV_CFL_SH3DSP       = 0x52,  
        CV_CFL_SH4          = 0x53,  
        CV_CFL_SHMEDIA      = 0x54,  
        CV_CFL_ARM3         = 0x60,  
        CV_CFL_ARM4         = 0x61,  
        CV_CFL_ARM4T        = 0x62,  
        CV_CFL_ARM5         = 0x63,  
        CV_CFL_ARM5T        = 0x64,  
        CV_CFL_ARM6         = 0x65,  
        CV_CFL_ARM_XMAC     = 0x66,  
        CV_CFL_ARM_WMMX     = 0x67,  
        CV_CFL_OMNI         = 0x70,  
        CV_CFL_IA64         = 0x80,  
        CV_CFL_IA64_1       = 0x80,  
        CV_CFL_IA64_2       = 0x81,  
        CV_CFL_CEE          = 0x90,  
        CV_CFL_AM33         = 0xA0,  
        CV_CFL_M32R         = 0xB0,  
        CV_CFL_TRICORE      = 0xC0,  
        CV_CFL_X64          = 0xD0,  
        CV_CFL_AMD64        = CV_CFL_X64,  
        CV_CFL_EBC          = 0xE0,  
        CV_CFL_THUMB        = 0xF0, 
        CV_CFL_ARMNT        = 0xF4,  
        CV_CFL_D3D11_SHADER = 0x100,  
    } CV_CPU_TYPE_e;  
    */
#if defined(__cplusplus)
}
#endif

