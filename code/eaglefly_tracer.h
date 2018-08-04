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
    
    void * IP;
    uint8_t OriginalCodeByte;
    u32 BreakPointCount;
    u32 BreakPointIndex;
    
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


