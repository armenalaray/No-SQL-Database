/*
Alejandro Armenta 
eaglefly_intrinsics.h
*/


#if COMPILER_MSVC

#include "math.h"
#include "intrin.h"

inline u32 CeilR32Tou32(r32 Value)
{
    u32 Result = (u32)ceilf(Value);  
    return Result;
}

inline u32 FloorR32Tou32(r32 Value)
{
    u32 Result = (u32)floorf(Value);  
    return Result;
}

#elif COMPILER_LLVM
//TODO(Alex): Add LLVM compiler specific intrinsics 
#endif

