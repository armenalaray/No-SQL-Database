/*
Alejandro Armenta

test_debug_target
*/

//#include "stdint.h"
#include "Windows.h"
#include "stdio.h"
#define BUFFER_SIZE 24

#if 0
static double CombineValuesA(unsigned int A, unsigned int B,  unsigned int C,  double D)
{
    double Result = (A + B + C) / D;
    return Result;
}


extern "C" double CombineValuesB(unsigned int A, unsigned int B,  unsigned int C,  double D);

int main(int ArgCount, char ** ArgValues)
{
    char BufferA[BUFFER_SIZE];
    char BufferB[BUFFER_SIZE];
    double V0 = CombineValuesA(1,2,3,4.0);
    _snprintf_s(BufferA, BUFFER_SIZE, "Result: %f\n", V0);  
    OutputDebugStringA(BufferA);
    
    double V1 = CombineValuesB(1,2,3,4.0);
    _snprintf_s(BufferB, BUFFER_SIZE, "Result: %f\n", V1);  
    OutputDebugStringA(BufferB);
}

#else

static void 
PrintNextFibonacciNumRec(unsigned int Index, unsigned int Max, unsigned int Num1, unsigned int Num0)
{
    unsigned int Temp = Num1;
    if(Index < Max)
    {
        Num1 = Num0 + Num1;
        Num0 = Temp;
        PrintNextFibonacciNumRec(++Index, Max, Num1, Num0);
    }
}

static void PrintFibonacciRangeA(char * Buffer, unsigned int Max, unsigned int Num0, unsigned int Num1, unsigned int Temp)
{
    
    for(unsigned int Index = 0;
        Index < Max;
        ++Index)
    {
        _snprintf_s(Buffer, BUFFER_SIZE, BUFFER_SIZE,  "%i\n", Num1); 
        OutputDebugStringA(Buffer);
        Temp = Num1;
        Num1 = Num0 + Num1;
        Num0 = Temp;
    }
}

extern "C" void PrintFibonacciRangeB(char * Buffer, unsigned int Max, unsigned int Num0, unsigned int Num1, unsigned int Temp);

int 
main(int ArgCount, char ** ArgValues)
{
    //Efly_InitDebugging();
    //OutputDebugStringA("Hello From Test");
    
    //EFLY_BEGIN_INSPECTION(tag: "Fibonacci Series iterative");
    unsigned int Min = 0;
    unsigned int Max = 30;
    unsigned int Num0 = 0;
    unsigned int Num1 = 1;
    unsigned int Temp = 0;
    
    char Buffer[BUFFER_SIZE];
    PrintFibonacciRangeA(Buffer, Max, Num0, Num1, Temp);
    PrintFibonacciRangeB(Buffer, Max, Num0, Num1, Temp);
    
    ///EFLY_END_INSPECTION();
    //EFLY_BREAKPOINT;
    
#if 0    
    Num0 = 0;
    Num1 = 1;
    Temp = 0;
    
    //EFLY_BEGIN_INSPECTION(Fibonacci Series recursive, d|r|);
    PrintNextFibonacciNumRec(0, Max, Num1, Num0);
#endif
    
    //EFLY_END_INSPECTION();
    return 0;
}
#endif



#if 0
#include <intrin.h>
#include <Windows.h>
#include <stdio.h>
#include "eaglefly_platform.h"
#define PRINT_BUFFER_SIZE 1024

#if PLATFORM_MSVC
#define EFLY_BREAKPOINT  __debugbreak() //NOTE(Alex): Look for compiler write the breakpoint instruction;

//TODO(Alex): Make our own text messagging control
internal void
Efly_InitDebugging(void)
{
    
}

#define EFLY_PRINT(Num)\
{\
    char Buffer[PRINT_BUFFER_SIZE] = {0};\
    _snprintf_s(Buffer, PRINT_BUFFER_SIZE, "%i\n", Num);\
    OutputDebugString(Buffer);\
}

#if 0
internal void 
EFLY_BEGIN_INSPECTION(char * Tag, Mode,  Flags)
{
    efly_inspection_block Block = {};
    Block.Tag = Tag;
    
    if(Mode & EflyMode_Dumping)
    {
        if(Flags & EFlySystem_Binary)
        {
            
        }
        if(Flags & EFlySystem_Dump)
        {
            
        }
        if(Flags & EFlySystem_Binary)
        {
            
        }
    }
    
}
#else
#define EFLY_BEGIN_INSPECTION(...)
#define EFLY_END_INSPECTION(...)
#define INSPECT

#endif
#endif
#endif














