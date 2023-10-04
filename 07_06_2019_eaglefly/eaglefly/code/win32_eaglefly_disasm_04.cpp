//////////////////////////////////////////////////////
//
//Author: Alejandro Armenta 
//Date: 2019
//File: win32_eaglefly_disasm_04.cpp
//Company: 
//
//All rights reserved.
//
//////////////////////////////////////////////////////

#include "Windows.h"
#include "stdio.h"
#include "eaglefly_platform.h"

DWORD WINAPI ProcedureManager(LPVOID lpParameter)
{
    HANDLE * EventHandle = (HANDLE *)lpParameter;
    DWORD Result = WaitForSingleObject(*EventHandle,INFINITE);
    
    switch(Result)
    {
        case WAIT_OBJECT_0:
        {
            printf_s("Thread %d Started\n", GetCurrentThreadId());
        }break;
        
        default: 
        {
            
        }break;
    }
    
    
#if 0    
    BOOL ResetEvent(
        HANDLE hEvent
        );
#endif
    
    
    return 0;
}

int main(int ArgCount, char ** Args)
{
    /*
What do i need for this to be my platform layer? 

There has to be 3 files like this, that the disassembler itself could choose to use whichever is neccesary, 
so i need some kind of macroing thing 

It can be 3 DLLs that the program can choose at startup you know, like some library to the services that the project will use!

In that way you will always have the same 


- The PE32, PE32+, COFF, file

- The encodings file - 
- The InstructionInfo File
- The AssemblyGrammar File

- Write to File .asm

These files are my intermediarys to reaad/write from file, 
now the disassembler shouldnt care which platform it is! we need to have an abstraction layer that just chooses the correct platform every time!

win32_eaglefly_disasm_04.cpp file - Operating system services
mac_eaglefly_disasm_04.cpp file - Operating system services
linux_eaglefly_disasm_04.cpp file - Operating system services


*/
    /*NOTE(Alex): Main process thread creates other worker threads to process information.
    we will use the object event to handle synchronization between threads, ok.
    
    we will create just one worker thread to serve as our filler and the main thread will serve as our reader
    
*/
    
    HANDLE EventHandle = CreateEventA(0,//LPSECURITY_ATTRIBUTES lpEventAttributes,
                                      TRUE, //BOOL                  bManualReset,
                                      FALSE, //BOOL                  bInitialState,
                                      NULL //LPCSTR                lpName
                                      );
    
    
    HANDLE ThreadHandle = CreateThread(0, //LPSECURITY_ATTRIBUTES   lpThreadAttributes,
                                       0, //SIZE_T                  dwStackSize,
                                       ProcedureManager, //LPTHREAD_START_ROUTINE  lpStartAddress,
                                       (LPVOID)&EventHandle, // __drv_aliasesMem LPVOID lpParameter,
                                       0, //DWORD                   dwCreationFlags,
                                       0 //LPDWORD                 lpThreadId
                                       );
    
    
    EagleflyDisasm(void);
    
    printf_s("Allowing thread to start\n");
    
    SetEvent(EventHandle);
    
    printf_s("Waiting for thread to finish\n");
    
    DWORD ThreadEnded = WaitForSingleObject(ThreadHandle,INFINITE);
    
    switch(ThreadEnded)
    {
        case WAIT_OBJECT_0:
        {
            printf_s("End waiting\n");
        }break;
        
        default: 
        {
            
        }break;
    }
    
    
    CloseHandle(EventHandle);
    
    int x = 4;
}
