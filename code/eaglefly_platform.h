#ifndef EAGLEFLY_PLATFORM_H

#include "stdint.h"

//TODO(Alex): Start filling this platform layer
#ifdef COMPILER_MSVC
#undef COMPILER_MSVC
#endif

#ifdef COMPILER_LLVM
#undef COMPILER_LLVM
#endif


#if _MSC_VER 
#define COMPILER_MSVC 1
#else
#define COMPILER_LLVM
#endif


#if defined(__cplusplus)
extern "C"{
#endif
    typedef uint64_t u64;
    typedef int64_t s64;
    
    typedef uint32_t u32;
    typedef int32_t s32;
    typedef s32 b32;
    
    typedef uint16_t u16;
    typedef int16_t s16;
    
    typedef uint8_t u8;
    typedef int8_t s8;
    
    typedef float r32;
    typedef double r64;
    typedef size_t memory_index;
    
    typedef uintptr_t uptr;
    typedef intptr_t sptr;
    
#include "eaglefly_intrinsics.h"
    
#define internal static 
#define global_variable static 
#define local_persist static 
    
#define BITMAP_BYTES_PER_PIXEL 4
#define Assert(Expression) if(!(Expression)){*(int*)(0) = 6;}
#define ArrayCount(Array) sizeof((Array)) / sizeof(Array[0]) 
#define InvalidCodePath Assert(!"Not Expected case")
    
    
#define Kilobytes(Size) ((Size) * 1024LL)
#define Megabytes(Size) (Kilobytes(Size) * 1024LL)
#define Gigabytes(Size) (Megabytes(Size) * 1024LL)
    
#define NUM_BUTTONS_PROCESSED  
#define MAX_NUM_FUNC_KEYS 12
    
    //TODO(Alex): intrinsics.h
    
    inline u32 TruncateR32ToU32(r32 Value)
    {
        u32 Result = (u32)Value;  
        return Result;
    }
    
    inline u32 RoundR32ToU32(r32 Value)
    {
        Assert(Value >= 0);
        u32 Result = (u32)(Value + 0.5f);  
        return Result;
    }
    
    inline s32 RoundR32ToS32(r32 Value)
    {
        s32 Result = (s32)(Value + 0.5f);  
        return Result;
    }
    
    inline u32 TruncateU64ToU32(u64 Value)
    {
        Assert(Value & 0xFFFFFFFF);
        u32 Result = (u32)Value;
        return Result;
    }
    
    
    internal void ConcatStrings(char * SourceA, u32 CountA, 
                                char * SourceB, u32 CountB, 
                                char * Dest, u32 CountDest)
    {
        Assert(CountA  + CountB < CountDest);
        
        for(u32 Index = 0; 
            Index < CountA;
            ++Index)
        {
            *Dest++ = *SourceA++;
        }
        
        for(u32 Index = CountA; 
            Index < CountA + CountB;
            ++Index)
        {
            *Dest++ = *SourceB++;
        }
        
        //NOTE(Alex): Add Null terminator
        *Dest++ = 0;
    }
    
    inline u32 
        StringLength(char * String)
    {
        u32 Result = 0;
        while(*String++)
        {
            ++Result;
        }
        
        return Result;
    }
    
    inline void CopyString(char * Dest_, char * Source_, uint32_t Size)
    {
        char * Dest = Dest_;
        char * Source = Source_;
        uint32_t BytesCopied = 0;
        while(BytesCopied < Size)
        {
            *Dest++ = *Source++;
            ++BytesCopied;
        }
    }
    
    
    enum efly_vkey
    {
        VKey_0 = 0,
        VKey_1,
        VKey_2,
        VKey_3,
        VKey_4,
        VKey_5,
        VKey_6,
        VKey_7,
        VKey_8,
        VKey_9,
        VKey_A,
        VKey_B,
        VKey_C,
        VKey_D,
        VKey_E,
        VKey_F,
        VKey_G,
        VKey_H,
        VKey_I,
        VKey_J,
        VKey_K,
        VKey_L,
        VKey_M,
        VKey_N,
        VKey_O,
        VKey_P,
        VKey_Q,
        VKey_R,
        VKey_S,
        VKey_T,
        VKey_U,
        VKey_V,
        VKey_W,
        VKey_X,
        VKey_Y,
        VKey_Z,
        Vkey_AlphaNumCount,
        
        VKey_F1,
        VKey_F2,
        VKey_F3,
        VKey_F4,
        VKey_F5,
        VKey_F6,
        VKey_F7,
        VKey_F8,
        VKey_F9,
        VKey_F10,
        VKey_F11,
        VKey_F12,
        VKey_FCount,
        
        VKey_OEM_1 = VKey_FCount + 1,
        VKey_OEM_2,
        VKey_OEM_3,
        VKey_OEM_4,
        VKey_OEM_5,
        VKey_OEM_6,
        VKey_OEM_7,
        VKey_OEM_8,
        VKey_OEM_102,
        
        VKey_OEM_PLUS,
        VKey_OEM_MINUS,
        VKey_OEM_COMMA,
        VKey_OEM_PERIOD,
        VKey_OEM_CLEAR,
        
        VKey_TAB,
        VKey_CAPITAL,
        VKey_SPACE,
        
        VKey_LEFT,
        VKey_UP,
        VKey_RIGHT,
        VKey_DOWN,
        
        VKey_PRIOR,
        VKey_NEXT,
        VKey_END,
        VKey_HOME,
        
        VKey_DELETE,
        VKey_BACK,
        VKey_Count,
    };
    
    enum efly_mouse_key
    {
        MouseKey_Left,
        MouseKey_Right,
        MouseKey_Middle,
        MouseKey_X1,
        MouseKey_X2,
        MouseKey_Count,
    };
    
    enum efly_control_key_flags
    {
        ControlKey_Shift = (1<<0),
        ControlKey_Alt = (1<<1),
        ControlKey_Ctrl = (1<<2),
    };
    
    struct efly_button_state
    {
        b32 ButtonEndedDown;
        u32 TransitionCount;
    };
    
    struct efly_keyboard_controller
    {
        efly_button_state Buttons[VKey_Count];
        //efly_button_state FunctionKeys[MAX_NUM_FUNC_KEYS];
    };
    
    struct efly_input
    {
        efly_keyboard_controller Keyboard;
        efly_button_state MouseButtons[MouseKey_Count]; 
        r32 MouseX, MouseY, MouseZ;
        r32 WheelDelta;
        
        u8 ControlKeyFlags;
    };
    
    inline b32 ControlKeyIsToggled(efly_input * Input, efly_control_key_flags Flags)
    {
        b32 Result = (Input->ControlKeyFlags & Flags);
        return Result;
    }
    
#define FUNKEY_PRESSED(Input, VKeyIndex) WasPressed(Input, (efly_vkey)VKeyIndex)
    
    inline b32 WasPressed(efly_input *  Input, efly_vkey VKey)
    {
        b32 Result = false;
        
        efly_button_state BState = Input->Keyboard.Buttons[VKey];
        
        if((BState.TransitionCount > 1) || 
           ((BState.TransitionCount == 1)
            && BState.ButtonEndedDown))
        {
            Result = true;
        }
        
        return Result;
    }
    
    struct efly_asset_bitmap
    {
        u32 BytesPerPixel;
        s32 Width;
        s32 Height;
        void * Data;
    };
    
    struct efly_memory;
    
#define DEBUG_UPDATE_AND_RENDER(Name) void (Name)(efly_asset_bitmap * FrameBuffer, efly_memory * Memory, efly_input * Input, char * TargetImageFullPath, char * TargetPDBFullPath, char * CmdEXEFullPath)
    typedef DEBUG_UPDATE_AND_RENDER(debug_update_and_render);
    DEBUG_UPDATE_AND_RENDER(DebugUpdateAndRenderStub)
    {
        //NOTE(Alex): DebugUpdateAndRender not grabbed from DLL
    }
    
#if 0    
#define WIN32_LOAD_EDEBUG_INFO(Name) void (Name)(win32_dispatcher_state * DispState, memory_arena * out_Arena, char * TargetPDBFullPath)
    typedef WIN32_LOAD_EDEBUG_INFO(win32_load_debug_info);
    WIN32_LOAD_EDEBUG_INFO(Win32LoadEDebugInfoStub)
    {
        //NOTE(Alex): Win32LoadEDebugInfo not grabbed from DLL
    }
#endif
    
    
    //
    //NOTE(Alex): File I/O Tools
    //
    
    struct debug_file_content
    {
        void * Content;
        u32 Size;
    };
    
    
#define READ_ENTIRE_FILE(Name) debug_file_content Name(char * FileName)
    typedef READ_ENTIRE_FILE(debug_read_entire_file);
    
#define WRITE_ENTIRE_FILE(Name) b32 Name(char * FileName, void * Data, u32 BytesToWrite)
    typedef WRITE_ENTIRE_FILE(debug_write_entire_file);
    
    //
    //NOTE(Alex): Memory Arena's and resources
    //
    
    struct efly_memory
    {
        memory_index DebugStorageSize;
        void * DebugStorage;
        
        memory_index TransientStorageSize;
        void * TransientStorage;
        
        memory_index TracerStorageSize;
        void * TracerStorage;
        
#if EAGLEFLY_INTERNAL
        debug_read_entire_file * DebugReadEntireFile;
        debug_write_entire_file * DebugWriteEntireFile;
#endif
    };
    
    
    struct memory_arena
    {
        void * Base;
        memory_index Size;
        memory_index Used;
    };
    
    struct sub_arena
    {
        memory_arena * ParentArena;
        memory_arena Arena;
    };
    
    internal void InitializeArena(memory_arena * Arena, void * Base, memory_index Size)
    {
        Arena->Base = Base;
        Arena->Size = Size;
        Arena->Used = 0;
    }
    
    
#define PushArray(Arena, Count, type) (type *)PushSize(Arena, Count * sizeof(type))
#define PushString(Arena, Count, type) (type *)PushArray(Arena, Count, type)
#define PushStruct(Arena, type) (type *)PushSize(Arena, sizeof(type))
    
    //TODO(Alex): Add Alignment
    internal void * PushSize(memory_arena * Arena, memory_index Size)
    {
        Assert(Arena && Arena->Base);
        Assert((Arena->Used + Size)  < Arena->Size);
        
        void * Result = (char *)Arena->Base + Arena->Used;
        Arena->Used += Size;
        return Result;
    }
    
    inline void SubArena(memory_arena * Arena, sub_arena * out_SubArena, memory_index Size)
    {
        out_SubArena->ParentArena = Arena;
        Assert(Size <= (Arena->Size - Arena->Used));
        InitializeArena(&out_SubArena->Arena, (char*)Arena->Base + Arena->Used, Size);
        PushSize(Arena, Size);
    }
    
    struct temp_memory
    {
        memory_arena * Arena;
        char * Base;
        u32 TempCount;
    };
    
    inline temp_memory BeginTempMemory(memory_arena * Arena)
    {
        temp_memory Result = {};
        char * Base = (char*)Arena->Base + Arena->Used;
        Assert(Arena->Used < Arena->Size);
        
        Result.Arena = Arena;
        Result.Base = Base; 
        ++Result.TempCount;
        return Result;
    }
    
    inline void EndTempMemory(temp_memory * TempMem)
    {
        memory_arena * Arena = TempMem->Arena;
        Assert(Arena);
        Arena->Used = (memory_index)TempMem->Base - (memory_index)Arena->Base;
        TempMem->Arena = 0;
        --TempMem->TempCount; 
        Assert(TempMem->TempCount == 0);
    }
    
    //
    //NOTE(Alex): Usaful tools constructs
    //
    
#define INIT_DOUBLY_LLIST(Sentinel)\
    (Sentinel)->Next = (Sentinel);\
    (Sentinel)->Prev = (Sentinel);\
    
#define ADD_TAIL_DOUBLY_LLIST(Sentinel, Instance)\
    (Instance)->Next = (Sentinel);\
    (Instance)->Prev = (Sentinel)->Prev;\
    (Sentinel)->Prev->Next = (Instance);\
    (Sentinel)->Prev = (Instance);
    
    //
    //NOTE(Alex): Tracer Input Data
    //
    
    typedef enum efly_input_command_type
    {
        InputCommand_NONE = 0,
        InputCommand_STEP_NEXT = (1 << 0),
        InputCommand_STEP_INTO = (1 << 1),
        InputCommand_STEP_OUT = (1 << 2),
        InputCommand_CONTINUE = (1 << 3),
        InputCommand_BREAK_ALL = (1 << 4),
        InputCommand_WALK_STACK = (1 << 5),
        InputCommand_UNLOAD_PROCESS = (1 << 6),
        InputCommand_LOAD_PROCESS = (1 << 7),
    }efly_input_command_type;
    
    typedef struct load_process_data
    {
        b32 RunFromCmdLine;
        char * TargetImageFullPath;
        char * TargetPDBFullPath;
        char * CmdEXEFullPath;
    }load_process_data;
    
    typedef struct efly_input_command
    {
        efly_input_command_type Type;
        union
        {
            load_process_data LoadProcessData;
        };
        
        efly_input_command * Next;
    }efly_input_command;
    
    //NOTE(Alex): Are we gonna just allow to debug windows specific applications?
    typedef struct efly_tracer_input
    {
        efly_input_command * FirstCommand;
        efly_input_command * CommandFirstFree;
    }efly_tracer_input;
    
    typedef struct transient_state
    {
        b32 IsInitialized;
        memory_arena TranArena;
        sub_arena Out_TracerSubArena;
        sub_arena In_TracerSubArena;
        
        efly_tracer_input TracerInput;
    }transient_state;
    
#if defined(__cplusplus)
}
#endif


#define EAGLEFLY_PLATFORM_H
#endif

