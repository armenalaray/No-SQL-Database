/*

Alejandro Armenta 
eaglefly_tracer.h

*/

#include "eaglefly_debug_info.h"

//NOTE(Alex): We probably want to see processor specific memory segmentations changes accross process state_
struct memory_segment
{
    u32 SegmentIndex; //Up to 65536 segments
    u64 Offset;
};

struct id_map
{
    memory_index ID;
    ptrv Handle;
    id_map * Next;
};

struct process_info
{
    PROCESS_INFORMATION ProcessInfo;
    FILETIME IMAGELastWriteTime;
    DWORD ProcessExitCode;
    
    //TODO(Alex) : Make ID process system  
    load_process_data LoadProcessData;
    
    ptrv BaseOfImage;
    ptrv StartAddress;
};

struct process_state
{
    b32 IsInitialized;
    b32 PDBExistsForThisImage;
    b32 InitProcess;
    b32 ProcessIsRunning;
    //TODO(Alex): Do Debug state machine 
    b32 ContinueTracing;
};

struct win32_dispatcher_state
{
    b32 IsInitialized;
    u32 TargetPCount;
    process_info PInfos[1024];
    process_state PStates[1024];
    
    id_map * IDHash[4096];
    memory_segment Segments[65536];
    
    u32 BPCount;
    u32 CurrentBPIndex;
    memory_index BPAddresses[4096];
    
    efly_tracer_input TracerInput_; 
    
    //TODO(Alex): Make Process subarena
    memory_arena EDebugInfoArena;
    temp_memory EDebugInfoMem;
    
    uint8_t OriginalCodeByte;
    //NOTE(Alex): LEXER DATA CONSTRUCTS
    efly_lexical_scope * CurrentLexicalScope;
    
    //NOTE(Alex): Output  Data
    
};


