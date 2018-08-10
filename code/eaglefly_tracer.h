/*

Alejandro Armenta 
eaglefly_tracer.h


NOTE(Alex): Things to do:
- Threading support -> Task switches
- QueryPerformanceCounters - Timers, etc.
- Stack Memory layout (Heap memory layout, Process Memory layouts) 
- Exception Notifications.

- More input commands Close process, set breakpoint at, step into.
- * PDB symbol extraction 
- Disassembly Symbol information,
- Module Management -> File organization, etc.
- Exception Handling?
- UI - System
*/

#include "eaglefly_debug_info.h"

//NOTE(Alex): We probably want to see processor specific memory segmentations changes accross process state_
struct memory_segment
{
    u32 SegmentIndex; //Up to 65536 segments
    u64 Offset;
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

struct efly_process
{
    process_info Info;
    process_state State;
};

enum id_map_type
{
    IDMap_Process = 1,
    IDMap_Thread,
};

//NOTE(Alex): We dont' care how did we get to the process, we just want the signal to start fetching data out of the process!
struct id_map
{
    memory_index ID;
    id_map_type Type;
    ptrv Handle;
    id_map * Next;
};

union efly_debug_storage
{
    efly_process P;
    //efly_thread T;
};

struct win32_dispatcher_state
{
    b32 IsInitialized;
    transient_state * TranState;
    
    id_map * IDMapFirstFree;
    id_map * IDMapHash[4096];
    
    //u32 ProcessCount;
    //u32 ThreadCount;
    u32 StorageCount; //NOTE(Alex): StorageCount = ProcessCount + ThreadCount;
    efly_debug_storage DebugStorage[4096];
    
    memory_segment Segments[65536];
    
    u32 BPCount;
    u32 CurrentBPIndex;
    memory_index BPAddresses[4096];
    
    efly_tracer_input TracerInput_; 
    
    memory_arena AssetArena;
    temp_memory AssetTempMem;
    
    uint8_t OriginalCodeByte;
    //NOTE(Alex): LEXER DATA CONSTRUCTS
    efly_lexical_scope * CurrentLexicalScope;
    
    //NOTE(Alex): Output  Data
};


