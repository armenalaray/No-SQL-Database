#include "Windows.h"
#include "stdio.h"
#define Buffer_Size 1024

int main(int argc, char ** Argv)
{
    int x = 1;
    int y = 0;
    int temp = 0;
    
    char Buffer[Buffer_Size] = {0};
    for(int Index = 0;
        Index < 20;
        ++Index)
    {
        printf("Test: %i\n", Index);
        printf("x:%i\n", x);
        printf("temp:%i\n", temp);
        printf("y:%i\n\n", y);
        
        temp = x;
        x = x + y;
        y = temp;
    }
}

