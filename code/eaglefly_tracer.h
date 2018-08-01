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

//NOTE(Alex): Are we gonna just allow to debug windows specific applications?
struct tracer_input_data
{
    b32 RunFromCmdLine;
    char * TargetImageFullPath;
    char * TargetPDBFullPath;
    char * CmdEXEFullPath;
};

struct win32_dispatcher_state
{
    b32 IsInitialized;
    b32 PDBExistsForThisImage;
    uint8_t OriginalCodeByte;
    
    b32 ContinueTracing;
    b32 InitProcess;
    HANDLE HProcess;
    b32 ProcessIsRunning;
    
    DWORD ProcessExitCode;
    PROCESS_INFORMATION ProcessInfo;
    char * CurrentAddressP;
    
    u32 BreakPointCount;
    u32 BreakPointIndex;
    
    unsigned int  win32_thread_id_map_count;
    win32_thread_id_map ThreadIDMap[4096];
    
    FILETIME IMAGELastWriteTime;
    //NOTE(Alex): Input Data
    //TODO(Alex): Provide a user input data queue?
    tracer_input_data InputData; 
    
    memory_arena EDebugInfoArena;
    temp_memory EDebugInfoMem;
    
    //NOTE(Alex): LEXER DATA CONSTRUCTS
    efly_lexical_scope * CurrentLexicalScope;
    
    
    
    
    //NOTE(Alex): Output  Data
    
};


