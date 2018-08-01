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

*/

inline bool Win32IsValidThreadIDMap(win32_thread_id_map * Map)
{
    bool Result = (Map->hThread && Map->ID);
    return Result;
}



inline bool Win32IsDuplicateThreadIDMap(win32_thread_id_map * Map, memory_index ID , void * Handle)
{
    bool Result = (Map->ID == ID);
    return Result;
}

//NOTE(Alex): Each key has to be unique! 
internal HANDLE  
Win32GetHandleFromID(win32_dispatcher_state * DispState, memory_index ID, void * hThread = 0)
{
    HANDLE Result = 0;
    unsigned int Bucket = ID & 0xFFF;
    unsigned int TableIndex = Bucket;
    
    do
    {
        win32_thread_id_map * Iter = DispState->ThreadIDMap + TableIndex;
        if(hThread && 
           !Win32IsValidThreadIDMap(Iter))
        {
            if(Win32IsDuplicateThreadIDMap(Iter, ID, hThread))
            {
                break;
            }
            
            Iter->ID = ID;
            Iter->hThread = hThread;
            Result = Iter->hThread;
            break;
        }
        
        if(Iter->ID == ID)
        {
            Result = Iter->hThread;
            break;
        }
        
        ++TableIndex;
        if(TableIndex >= ArrayCount(DispState->ThreadIDMap))
        {
            TableIndex = 0;
        }
        
    }while(TableIndex != Bucket);
    return Result;
}

internal void * 
win32GetProcessStartAddress(win32_dispatcher_state * DispState, DEBUG_EVENT * Out_DebugEvent)
{
    //TODO(Alex): lpStartAddress is busted we need to find a better way to get the REAL process start address
    Assert(Out_DebugEvent->dwDebugEventCode == CREATE_PROCESS_DEBUG_EVENT);
    void * Result = Out_DebugEvent->u.CreateProcessInfo.lpStartAddress; 
    DispState->CurrentAddressP = (char*)Result;
    return Result;
}

struct pdb_sym_iter
{
    char * At;
    u32 TableIndex;
    u32 ScopeIndex;
    
    
    
};


#if 0    
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
Win32Displayx64RegistersFromContext(win32_dispatcher_state * DispState, CONTEXT * TContext)
{
    char Buffer[4096] = {0};
    sprintf_s(Buffer, ArrayCount(Buffer), "----------\nRegisters at 0x%p:\nRax: 0x%p\nRcx: 0x%p\nRdx: 0x%p\nRbx: 0x%p\nRsp: 0x%p\nRbp: 0x%p\nRsi: 0x%p\nRdi: 0x%p\nR8: 0x%p\nR9: 0x%p\n", 
              (void*)(TContext->Rip + 1),
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
    EndTempMemory(&DispState->EDebugInfoMem);
    //TODO(Alex): Unload Process And PDB out of memory!
}

internal void
Win32LoadIMAGE(win32_dispatcher_state * DispState, tracer_input_data * InputData)
{
    //TODO(Alex): Shall we reload the target process on recompilation?
    if(DispState->InitProcess && !DispState->ProcessIsRunning)
    {
        STARTUPINFO StartupInfo = {};
        StartupInfo.cb = sizeof(STARTUPINFO);
        PROCESS_INFORMATION ProcessInfo = {};
        
        char Command[1024] = {0};
        char * TargetName = 0;
        if(InputData->RunFromCmdLine)
        {
            char * CommandToken = "/c ";
            ConcatStrings(CommandToken, StringLength(CommandToken), 
                          InputData->TargetImageFullPath, StringLength(InputData->TargetImageFullPath), 
                          Command, ArrayCount(Command));
            
            TargetName = InputData->CmdEXEFullPath;
        }
        else
        {
            TargetName = InputData->TargetImageFullPath;
        }
        
        DispState->EDebugInfoMem = BeginTempMemory(&DispState->EDebugInfoArena);
        //TODO(Alex): Make this a working thread
        //DispState->PDBExistsForThisImage = Win32LoadEDebugInfoFromPDB(DispState, DispState->EDebugInfoArena, InputData->TargetPDBFullPath);
        if(DispState->PDBExistsForThisImage)
        {
            //NOTE(Alex): Right now we are only debugging main process, no child processes! 
            DispState->ProcessIsRunning = (CreateProcessA(TargetName, 
                                                          Command, //NOTE(Alex): Command line for cmd.exe  
                                                          0,
                                                          0,
                                                          false,
                                                          DEBUG_ONLY_THIS_PROCESS, //TODO(Alex): Debug child processes? DEBUG_PROCESS
                                                          0, //TODO(Alex): Set environment block? CREATE_UNICODE_ENVIRONMENT for user processes that setup a unicode environment 
                                                          0,
                                                          &StartupInfo,
                                                          &DispState->ProcessInfo));
        }
        else
        {
            OutputDebugStringA("Not Valid PDB");
        }
        
        //LoadSymbolsForImage(DispState);
        //TODO(Ale): We want only the path here!
        //TODO(Alex): The dispatcher doesn thave to know about symbols, we could have a second call inside here
        //HERE is where the debug manager is going to be
        
    }
}

internal efly_lexical_scope * 
CONSTRUCT_LEXICAL_SCOPE(win32_dispatcher_state * DispState, memory_index Address)
{
    efly_lexical_scope * Result = 0;
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


#define GET_EDEBUG_INFO(Info) (edebug_info *)((Info).Base)

//TODO(Alex): Implement print_f function ourselves!
internal void
Win32DebugUpdateTracer(debug_memory * Memory, debug_input * Input, char * TargetImageFullPath, char * TargetPDBFullPath,  char * CmdEXEFullPath)
{
    win32_dispatcher_state * DispState = (win32_dispatcher_state *)Memory->TracerStorage; 
    tracer_input_data * InputData = (tracer_input_data *)&DispState->InputData;
    
    if(!DispState->IsInitialized)
    {
        InitializeArena(&DispState->EDebugInfoArena, (char*)Memory->TracerStorage + sizeof(win32_dispatcher_state), Megabytes(500)); 
        
        DispState->ProcessExitCode = {};
        DispState->InitProcess = true;
        DispState->ContinueTracing = true;
        
        //TODO(Alex): Set BreakPointCount in Debug Manager
        DispState->BreakPointCount = 2;//NOTE(Alex): Initial system breakpoint
        
        InputData->RunFromCmdLine = false;
        InputData->TargetImageFullPath = TargetImageFullPath;
        InputData->CmdEXEFullPath = CmdEXEFullPath;
        DispState->IsInitialized = true;
    }
    
    //TODO(Alex): Make Input Command Queue!
#if 0    
    if(InputData->Commands[LOAD_TARGET_PROCESS])
    {
        LoadIMAGE(DispState, TargetImageFullPath, TargetPDBFullPath);
    }
#endif
    
    //IMPORTANT(Alex): We have to make sure the user always creates a valid PDB file 
    //so that we can parse it an reload the image as well!
    FILETIME IMAGELastWriteTime = Win32GetFileLastWriteTime(InputData->TargetPDBFullPath);
    if(DispState->PDBExistsForThisImage)
    {
        if(CompareFileTime(&IMAGELastWriteTime, &DispState->IMAGELastWriteTime) != 0)
        {
            Win32UnloadIMAGE(DispState);
            Win32LoadIMAGE(DispState, InputData);
        }
    }
    
    if(DispState->ProcessIsRunning)
    {
        DEBUG_EVENT Out_DebugEvent;
        DWORD ContinueStatus = DBG_CONTINUE;
        if(WaitForDebugEvent(&Out_DebugEvent, 0))
        {
            switch(Out_DebugEvent.dwDebugEventCode)
            {
                case EXCEPTION_DEBUG_EVENT:
                {
                    b32 EFirstChance = (Out_DebugEvent.u.Exception.dwFirstChance) ? true : false;
                    EXCEPTION_RECORD ERecord = Out_DebugEvent.u.Exception.ExceptionRecord;
                    
                    switch(ERecord.ExceptionCode)
                    {
                        case EXCEPTION_BREAKPOINT:
                        {
                            //NOTE(Alex): We dont handle the first breakpoint made by the system! 
                            if(DispState->BreakPointIndex)
                            {
                                /*
                                Display Data(registers, call stack, source code, etc), 
                                Dont continuedebugevent
                                */
                                DispState->ContinueTracing = false;
                                //TODO(Alex): These is platform specific, handle each platform as well!
                                CONTEXT TContext = {};
                                TContext.ContextFlags = CONTEXT_ALL;
                                GetThreadContext(DispState->ProcessInfo.hThread, &TContext);
                                --TContext.Rip;  
                                Win32Displayx64RegistersFromContext(DispState, &TContext);
                                SetThreadContext(DispState->ProcessInfo.hThread, &TContext);
                                
                                SIZE_T BytesWritten = {};
                                if(WriteProcessMemory(DispState->ProcessInfo.hProcess,
                                                      (void*)TContext.Rip,
                                                      &DispState->OriginalCodeByte,
                                                      1,
                                                      &BytesWritten) && (BytesWritten == 1))
                                {
                                    FlushInstructionCache(DispState->ProcessInfo.hProcess,
                                                          (void*)TContext.Rip,
                                                          1);
                                }
                                
                                //TODO(Alex): This has to go on the collation step, put it here temporarilly 
                                //TODO(Alex): Add Memory Layout, 
                                //DisplayDisAtIntructionP(DispState, SymTable);
                                //TODO(Alex): Define a debugger platform identifier for x64 x86 modes
                                
                                DispState->CurrentLexicalScope = CONSTRUCT_LEXICAL_SCOPE(DispState, (memory_index)TContext.Rip);
                                
                                DisplaySourceFileAtLine(DispState, DispState->CurrentLexicalScope);
                                DisplayLocalSymmbols(DispState, DispState->CurrentLexicalScope);
                                DisplayWatchSymbols(DispState, DispState->CurrentLexicalScope);
                                DisplayCallStack(DispState, DispState->CurrentLexicalScope);
                                
                                //address_line_map * LineMap = GetLineMapFromAddress(DispState, );
                            }
                            ++DispState->BreakPointIndex;
                            if(DispState->BreakPointIndex >= DispState->BreakPointCount)
                            {
                                DispState->BreakPointIndex = 1;
                            }
                        }break;
                        case EXCEPTION_SINGLE_STEP:
                        {
                            
                        }
                        default:
                        {
                            ContinueStatus = DBG_EXCEPTION_NOT_HANDLED;
                        }break;
                    }
                    
                }break;
                
                case OUTPUT_DEBUG_STRING_EVENT:
                {
                    OUTPUT_DEBUG_STRING_INFO  DebugString = Out_DebugEvent.u.DebugString;
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
                    if(ReadProcessMemory(DispState->ProcessInfo.hProcess, 
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
                    
                    SIZE_T BytesRead = {};
                    uint8_t InterruptCodeByte = 0xCC;//NOTE(Alex): 204
                    DispState->OriginalCodeByte = 0;
                    //NOTE(Alex): We will stop at extern "C" int mainCRTStartup() : 00007FF6A6D21000
                    win32GetProcessStartAddress(DispState, &Out_DebugEvent);
                    if(ReadProcessMemory(DispState->ProcessInfo.hProcess, 
                                         DispState->CurrentAddressP,
                                         &DispState->OriginalCodeByte,
                                         1,
                                         &BytesRead) && (BytesRead == 1))
                    {
                        SIZE_T BytesWritten = {};
                        if(WriteProcessMemory(DispState->ProcessInfo.hProcess,
                                              DispState->CurrentAddressP,
                                              &InterruptCodeByte,
                                              1,
                                              &BytesWritten) && (BytesWritten == 1))
                        {
                            FlushInstructionCache(DispState->ProcessInfo.hProcess,
                                                  DispState->CurrentAddressP,
                                                  1);
                        }
                    }
                }break;
                
                case EXIT_PROCESS_DEBUG_EVENT:
                {
                    DispState->ProcessExitCode = Out_DebugEvent.u.ExitProcess.dwExitCode;
                    char Buffer[4096] = {0};
                    sprintf_s(Buffer, ArrayCount(Buffer), "The process exited with code: %x\n", DispState->ProcessExitCode);
                    OutputDebugStringA(Buffer);
                    
                    DispState->ProcessIsRunning = false;
                    DispState->InitProcess = false;
                }break;
                
                case CREATE_THREAD_DEBUG_EVENT:
                {
                    Win32GetHandleFromID(DispState, 
                                         (memory_index)Out_DebugEvent.dwThreadId, 
                                         Out_DebugEvent.u.CreateThread.hThread);
                    char Buffer[4096] = {0};
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
                              Win32GetHandleFromID(DispState, 
                                                   (memory_index)Out_DebugEvent.dwThreadId),
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
                }break;
                
                case UNLOAD_DLL_DEBUG_EVENT:
                {
                    char Buffer[4096] = {0};
                    sprintf_s(Buffer, ArrayCount(Buffer), "DLL 0x%p loaded at address 0x%p\n", 
                              Win32GetHandleFromID(DispState, (memory_index)Out_DebugEvent.u.UnloadDll.lpBaseOfDll), 
                              Out_DebugEvent.u.UnloadDll.lpBaseOfDll);
                    OutputDebugStringA(Buffer);
                    //UNLOAD_DLL_DEBUG_INFO     UnloadDll;
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
                    InvalidCodePath;
                }break;
            }
            
            //NOTE(Alex): We should not close any Handles being returned from the debugee application
            //ContinueDebugEvent will close them for us
            if(DispState->ContinueTracing)
            {
                //SAVE_WATCH_SYMBOLS(DispState);
                DESTRUCT_LEXICAL_SCOPE(DispState->CurrentLexicalScope);
                ContinueDebugEvent(DispState->ProcessInfo.dwProcessId,
                                   DispState->ProcessInfo.dwThreadId,
                                   ContinueStatus);
            }
        }
    }
    
#if 0    
    if(TerminateProcess)
    {
        CloseHandle(ProcessInfo.hProcess);
        CloseHandle(ProcessInfo.hThread);
    }
#endif
}











