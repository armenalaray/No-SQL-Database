/*
Alejandro Armenta

test_debug_target
*/

#include <Windows.h>

int 
main(int ArgCount, char ** ArgValues)
{
    OutputDebugStringA("Hello From Test");
    return 0;
}

