/*

Alejandro Armenta 
eaglefly_tracer.h

*/

#include "eaglefly_debug_info.h"

//NOTE(Alex): Win32 Dispatcher structures
struct win32_thread_id_map
{
    memory_index ID;
    HANDLE hThread;
};

//NOTE(Alex): We probably want to see processor specific memory segmentations changes accross process state_
struct memory_segment
{
    u32 SegmentIndex; //Up to 65536 segments
    u64 Offset;
};

struct win32_dispatcher_state
{
    b32 IsInitialized;
    b32 PDBExistsForThisImage;
    b32 InitProcess;
    b32 ProcessIsRunning;
    //TODO(Alex): Do Debug state machine 
    b32 ContinueTracing;
    
    HANDLE HProcess;
    DWORD ProcessExitCode;
    PROCESS_INFORMATION ProcessInfo;
    load_process_data CurrentProcessData;
    
    uint8_t OriginalCodeByte;
    
    memory_segment Segments[65536];
    
    u32 BPCount;
    u32 CurrentBPIndex;
    memory_index BPAddresses[4096];
    
    unsigned int  win32_thread_id_map_count;
    win32_thread_id_map ThreadIDMap[4096];
    
    FILETIME IMAGELastWriteTime;
    
    efly_tracer_input TracerInput_; 
    
    memory_arena EDebugInfoArena;
    temp_memory EDebugInfoMem;
    
    //NOTE(Alex): LEXER DATA CONSTRUCTS
    efly_lexical_scope * CurrentLexicalScope;
    
    //NOTE(Alex): Output  Data
    
};


