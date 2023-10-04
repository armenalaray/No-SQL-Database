//////////////////////////////////////////////////////
//
//Author: Alejandro Armenta
//Date: 2019
//File: eaglefly_bits.cpp
//Company:
//
//(2018-2019) All rights reserved.
//
//////////////////////////////////////////////////////



//NOTE(Alex): bits functions

inline bits Bits(u32 bits_count, u64 Value)
{
    bits Result = {};
    
    Result.bits_count = bits_count;
    Result.value = Value;
    
    return Result;
}

inline bits Zeroes(u32 bits_count)
{
    bits Result = Bits(bits_count, 0);
    return Result;
}

inline bits BitsID(u32 bits_count, u64 Value)
{
    bits Result = Bits(bits_count, Value);
    Result.type = BitfieldType_id;
    return Result;
}


inline b32 
TestBit(bits Bits, u32 Index)
{
    Assert(Index < Bits.bits_count);
    b32 Result = ((Bits.value >> Index) & 1);
    return Result;
}

//NOTE(Alex): concat_bits will try to concatenate two bitfield values into one bitfield of bits_count equal to the sum of the two bitfields and the value a shifted left a.bits_count bits OR with b.value
internal bits
concat_bits(bits a , bits b, bitfield_type Type = BitfieldType_unasigned)
{
	u32 bits_count = a.bits_count + b.bits_count;

	Assert(bits_count < MAX_BITS_COUNT);

	bits Result = Zeroes(bits_count);
	Result.value = a.value << a.bits_count | b.value;
	Result.type = Type;
	
	return Result;
}

//NOTE(Alex): Buffered IO byte instruction stream

inline u8 
GetByte(disasm_state * State)
{
    u8 Result = *State->cursor++;
    return Result;
}

inline u32 BitSizeToHexSize(u32 BitSize)
{
    u32 Result = BitSize / 4;
    return Result;
}

internal bits SwapBitfieldBytes(bits Bitfield)
{
    bits Result = {};
    
    Result.bits_count = Bitfield.bits_count;
    
    switch(Bitfield.bits_count)
    {
        case 64:
        {
            Result.value = ByteSwapU64(Bitfield.value);
        }break;
        case 32:
        {
            u32 BEValue = SafeTruncateU64ToU32(Bitfield.value);
            Result.value = (u64)ByteSwapU32(BEValue);
        }break;
        case 16:
        {
            u16 BEValue = SafeTruncateU64ToU16(Bitfield.value);
            Result.value = (u64)ByteSwapU16(BEValue);
        }break;
        case 8:
        {
            Result.value = Bitfield.value;
        }break;
        InvalidDefaultCase;
    }
    
    return Result;
}


//NOTE(Alex): we can do this because we get per byte, and prefixes are byte aligned 
inline void BeginBaseFrame(disasm_state * State)
{
    State->baseframe = State->cursor;
};


inline void ResetToBaseFrame(disasm_state * State)
{
    State->cursor = State->baseframe;
    State->BitBuffer = 0;
};


internal u64 peekBits_noconsume_msb(disasm_state * State, u32 Count)
{
    Assert((Count >= 0) && (Count <= 57));
    
    while(State->BitCount < Count)
    {
        State->BitBuffer |= ((u64)GetByte(State) << (56 - State->BitCount));
        State->BitCount += 8;
    }
    
    u64 Result = State->BitBuffer >> (64 - Count);
    return Result;
}

internal void 
consumeBits_msb(disasm_state * State, u32 Count)
{
    Assert((Count >= 0) && (Count <= (64 - 7)));
    if(Count > 0)
    {
        State->BitBuffer <<= Count;
        State->BitCount -= Count;
    }
}


//NOTE(Alex): Have BitCount bits on BitBuffer starting from LSB first the other bits are 0 
internal u64 
GetBits_msb(disasm_state * State, u32 Count)
{
    Assert(Count >= 0 && Count <= 64);
    u64 Result_ = 0;
    u64 Result = 0;
    
    u32 BitsLeft = Count;
    u32 BitsCount = 56;
    
    while(BitsLeft > BitsCount)
    {
        Result_ = peekBits_noconsume_msb(State, BitsCount);
        consumeBits_msb(State, BitsCount);
        
        BitsLeft -= BitsCount;
        Result = (Result_ << BitsLeft);
    }
    
    Result_ = peekBits_noconsume_msb(State,BitsLeft);
    consumeBits_msb(State,BitsLeft);
    
    Result = Result | Result_;
    
    return Result;
}


internal void 
refillBits_lsb(disasm_state * State, u32 Count)
{
    Assert(Count >= 0 && Count <= (64 - 7));
    while(State->BitCount < Count)
    {
        State->BitBuffer = State->BitBuffer  | (u64)GetByte(State) << (State->BitCount);
        State->BitCount += 8;
    }
}

internal u64 
peekBits_noconsume_lsb(disasm_state * State, u32 Count)
{
    Assert(Count >= 0 && Count <= (64 - 7));
    if(State->BitCount < Count)
    {
        refillBits_lsb(State, Count);
    }
    
    u64 Result = Result = State->BitBuffer & ((1ull << Count) - 1);
    return Result;
}

internal void consumeBits_lsb(disasm_state * State, u32 Count)
{
    Assert(Count >= 0 && Count <= (64 - 7));
    State->BitBuffer >>= Count;
    State->BitCount -= Count;
}


//NOTE(Alex): Have BitCount bits on BitBuffer starting from LSB first the other bits are 0 
internal u64 
GetBits_lsb(disasm_state * State, u32 Count)
{
    u64 Result = 0;
    refillBits_lsb(State,Count);
    Result = peekBits_noconsume_lsb(State,Count);
    consumeBits_lsb(State,Count);
    return Result;
}

//TODO(Alex): Implement this with the new system!
internal b32 BitsAreEqual(char * CBase, bits InstructionBits)
{
    b32 Result = true;
    
#if 0    
    char * CByte = CBase;
    u32 ByteCount = (InstructionBits.bits_count / 8);
    u32 BitStraddle = (InstructionBits.bits_count % 8);
    
    char * TestByte = 0;
    char * RealByte = 0;
    
    for(u32 Index = 0; 
        (Index < ByteCount) && Result; 
        ++Index)
    {
        TestByte = Instruction.Buffer + Index;
        RealByte = CByte++;
        
        Result = (*TestByte == *CByte);
    }
    
    if(BitStraddle)
    {
        Assert(TestByte && RealByte);
        u32 ShiftCount = (8 - BitStraddle);
        Result = ((*TestByte >> ShiftCount) == (*RealByte >> ShiftCount));
    }
#endif
    
    return Result;
}


internal void
ConvertBitfieldToStringSize(char * out_Buffer, u32 * out_BufferCount, u32 BufferSize, u32 EffOperandSize, u64 BitfieldValue, u32 BitfieldSize)
{
    Assert((BitfieldSize & 0x7) == 0);
    
    u32 TempBufferCount = 0;
    char TempBuffer[MAX_BUFFER_SIZE] = {0};
    
    ConvertU64ToASCHexString(TempBuffer, &TempBufferCount, MAX_BUFFER_SIZE, BitfieldValue, BitfieldSize, true);
    
    u32 NibbleCount = EffOperandSize / 4;
    char * At = TempBuffer + (TempBufferCount - NibbleCount);
    
    Append(out_Buffer, out_BufferCount, BufferSize, "0x", StringLength("0x"));
    Append(out_Buffer, out_BufferCount, BufferSize, At, NibbleCount);
}

internal void 
ConvertBitfieldToStringSize(string * out_string, u32 EffOperandSize, u64 BitfieldValue, u32 BitfieldSize)
{
	ConvertBitfieldToStringSize(out_string->buffer, &out_string->count, out_string->mem_size, EffOperandSize, BitfieldValue, BitfieldSize);
}


internal void
ConvertBitsToString(char * out_Buffer, u32 * out_BufferCount,u32 BufferSize, bits * Bits)
{
    ConvertBitfieldToStringSize(out_Buffer, out_BufferCount, BufferSize, Bits->bits_count, Bits->value, Bits->bits_count);
}

internal void
ConvertBitsToString(string * out_string, bits * Bits)
{
    ConvertBitfieldToStringSize(out_string, Bits->bits_count, Bits->value, Bits->bits_count);
}

