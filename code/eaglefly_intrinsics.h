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


struct bit_info
{
    u32 Index;
    b32 Set;
};


inline bit_info BitScanForwardU32(uint32_t Value)
{
    bit_info Result = {};
    Result.Set = _BitScanForward((DWORD *)&Result.Index, Value);  
    return Result;
}

inline bit_info BitScanReverseU32(uint32_t Value)
{
    bit_info Result = {};
    Result.Set = _BitScanReverse((DWORD *)&Result.Index, Value);  
    return Result;
}



//TODO(Alex): cpuid funtion 



#if 0
#if ARCH_AMD64
inline u32 CPUID(s32 )
{
    
}
#endif
#endif


#elif COMPILER_LLVM
//TODO(Alex): Add LLVM compiler specific intrinsics 
#endif

