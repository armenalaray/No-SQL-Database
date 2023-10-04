//////////////////////////////////////////////////////
//
//Author: Alejandro Armenta 
//Date: 2019
//File: eaglefly_intrinsics.h
//Company: 
//
//All rights reserved.
//
//////////////////////////////////////////////////////

#ifndef EAGLEFLY_INTRINSICS_H
#define EAGLEFLY_INTRINSICS_H

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
    u32 Offset;
    b32 Set;
};


inline bit_info BitScanForwardU32(uint32_t Value)
{
    bit_info Result = {};
    Result.Set = _BitScanForward((unsigned long *)&Result.Offset, Value);  
    return Result;
}

inline bit_info BitScanReverseU32(uint32_t Value)
{
    bit_info Result = {};
    Result.Set = _BitScanReverse((unsigned long *)&Result.Offset, Value);  
    return Result;
}



inline u64 ByteSwapU64(u64 Value)
{
    u64 Result = _byteswap_uint64 (Value);
    return Result;
}


inline u32 ByteSwapU32(u32 Value)
{
    u32 Result = _byteswap_ulong (Value);
    return Result;
}


inline u16 ByteSwapU16(u16 Value)
{
    u16 Result = _byteswap_ushort (Value);
    return Result;
}


inline void InterlockedCompareExchangePtr(volatile void * Destination, void * Exchange, void * Comparand)
{
    void * InitialValue = _InterlockedCompareExchangePointer ((void * volatile *)Destination, Exchange, Comparand);
}

////////////////////////////////////////////////////////////
//TODO(Alex): Intrinsic form?
inline u32 
MakeMask(u32 BitCount)
{
    u32 Result = 0;
    
    for(u32 BitIndex = 0;
        BitIndex < BitCount;
        ++BitIndex)
    {
        Result |= (1 << BitIndex);
    }
    
    return Result;
}


inline u32 PowerOfTwoInt(s32 Value)
{
    u32 Result = (MakeMask(Value) + 1);
    return Result;
}

////////////////////////////////////////////////////////////


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

#endif