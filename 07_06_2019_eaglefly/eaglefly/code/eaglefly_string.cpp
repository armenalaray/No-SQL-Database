//////////////////////////////////////////////////////
//
//Author: Alejandro Armenta 
//Date: 2019
//File: eaglefly_string.cpp
//Company: 
//
//All rights reserved.
//
//////////////////////////////////////////////////////

//NOTE(Alex): String Functions

inline void 
make_string_size(memory_arena * Arena, string * out_string, u32 count, u32 mem_size)
{
	out_string->buffer = PushArray(Arena, mem_size, char);
	out_string->count = count;
	out_string->mem_size = mem_size;
}


inline u32 StringLength(char * String)
{
	u32 Result = 0;
	if(String)
	{
		while(*String++)
		{
			++Result;
		}
	}
	
	return Result;
}

internal void 
Append(char * Dest, u32 * out_CountDest, u32 DestSize, char * Source, u32 CountSource)
{
	Assert(Dest && out_CountDest && ((CountSource + *out_CountDest) < DestSize));
	
	char * At = Dest + *out_CountDest;
	for(u32 Index = 0; 
		Index < CountSource;
		++Index)
	{
		*At++ = *Source++;
		++(*out_CountDest);
	}
	
}

internal void 
Append(string * out_dest, char * s_, u32 s_count)
{
	Append(out_dest->buffer, &out_dest->count, out_dest->mem_size, s_, s_count);
}


internal void 
Append(string * out_dest, string * source)
{
	Append(out_dest->buffer, &out_dest->count, out_dest->mem_size, source->buffer, source->count);
}


//TODO(Alex): is this reliable?
internal void 
Append(string * out_string, char * s)
{
	u32 s_count = StringLength(s);
	Append(out_string, s, s_count);
}



internal uint32_t ConcatStrings(char * SourceA, u32 CountA, 
								char * SourceB, u32 CountB, 
								char * Dest, u32 CountDest)
{
	uint32_t DestCount = 0;
	Assert((CountA  + CountB) < CountDest);
	
	for(u32 Index = 0; 
		Index < CountA;
		++Index)
	{
		*Dest++ = *SourceA++;
		++DestCount;
	}
	
	for(u32 Index = CountA; 
		Index < CountA + CountB;
		++Index)
	{
		*Dest++ = *SourceB++;
		++DestCount;
	}
	
	//NOTE(Alex): Add Null terminator
	*Dest++ = 0;
	++DestCount;
	
	return DestCount;
}

inline b32 
StringsAreEqual(char * A_, memory_index ASize, char * B_, memory_index BSize)
{
	Assert(A_ && B_);
	
	b32 Result = false;
	
	if(ASize == BSize)
	{
		char * A = A_;
		char * B = B_;
		
		memory_index Count = 0;
		while((Count < ASize) && (*A == *B))
		{
			++A;
			++B;
			++Count;
		}
		
		Result = (Count >= ASize);
	}
	
	return Result;
}

inline b32 
StringsAreEqual(string * a, string * b)
{
	b32 Result = StringsAreEqual(a->buffer, a->count, b->buffer, b->count);
	return Result;
}

inline void CopyString(char * Dest, uint32_t DestCount, char * Source, uint32_t SourceCount, b32 NullTerminated = false)
{
	Assert(DestCount >= SourceCount);
	char * S, *D;
	S = Source;
	D = Dest;
	for(uint32_t Index = 0;
		Index < SourceCount;
		++Index)
	{
		*D++ = *S++;
	}
	
	if(NullTerminated)
	{
		*D++ = 0;
	}
}


inline void 
AddCharTimesAt(string * String, char * At, char Value, u32 Count)
{
	
    if(String && At >= String->buffer && At + Count < String->buffer + String->mem_size)
	{
		for(u32 Index = 0;
			Index < Count;
			++Index)
		{
			*At++ = Value;
		}
		
		String->count = SafeTruncateU64ToU32((memory_index)At - (memory_index)String->buffer);
	}
}


inline void 
FillBufferWithValue(char * out_Buffer, u32 BufferSize, u8 Value)
{
    if(out_Buffer && BufferSize)
    {
        char * At = out_Buffer;
        for(u32 Index = 0;
            Index < BufferSize;
            ++Index)
        {
            *At++ = Value;
        }
    }
}

inline void
ClearBuffer(char * out_Buffer, u32 BufferSize)
{
    FillBufferWithValue(out_Buffer, BufferSize, 0);
}


internal void 
ConvertASCHexStringToU64(char * Buffer, u32 BufferCount, u64 * out_Value)
{
    Assert((BufferCount > 0) && (BufferCount <= 4));
    
    u64 Value = 0;
    char * At = Buffer;
    
    for(u32 Index = 0;
        Index < BufferCount;
        ++Index)
    {
        u32 Addend = 0;
        switch(*At)
        {
            case '0':
            {
                Addend = 0;
            }break;
            case '1':
            {
                Addend = 1;
            }break;
            case '2':
            {
                Addend = 2;
            }break;
            case '3':
            {
                Addend = 3;
            }break;
            case '4':
            {
                Addend = 4;
            }break;
            case '5':
            {
                Addend = 5;
            }break;
            case '6':
            {
                Addend = 6;
            }break;
            case '7':
            {
                Addend = 7;
            }break;
            case '8':
            {
                Addend = 8;
            }break;
            case '9':
            {
                Addend = 9;
            }break;
            case 'A':
            {
                Addend = 0xA;
            }break;
            case 'B':
            {
                Addend = 0xB;
            }break;
            case 'C':
            {
                Addend = 0xC;
            }break;
            case 'D':
            {
                Addend = 0xD;
            }break;
            case 'E':
            {
                Addend = 0xE;
            }break;
            case 'F':
            {
                Addend = 0xF;
            }break;
            
            InvalidDefaultCase;
        }
        
        Value = (Value << BITS_PER_NIBBLE) + Addend;
        
        ++At;
    }
    
    *out_Value = Value;
}

internal void
ConvertU32ToASCHexString(char * out_Buffer, u32 * out_BufferCount, u32 BufferSize, u32 Bits, u32 BitsCount, b32 SignExtend = false)
{
    Assert((BitsCount > 0) && (BitsCount <= 32));
    Assert((BitsCount & 0x7) == 0);
    
    u32 NibblesCount = (BitsCount / BITS_PER_NIBBLE);
    Assert(NibblesCount > 0);

    char NibbleTable[HEX_DIGIT_COUNT] =
    {
        '0',
        '1',
        '2',
        '3',
        '4',
        '5',
        '6',
        '7',
        '8',
        '9',
        'A',
        'B',
        'C',
        'D',
        'E',
        'F',
        
    };
    
    char NegNibbles32[NIBBLE_COUNT_32] = {0};
    char PosNibbles32[NIBBLE_COUNT_32] = {0};
    
    FillBufferWithValue(NegNibbles32, NIBBLE_COUNT_32, (u8)'F');
    FillBufferWithValue(PosNibbles32, NIBBLE_COUNT_32, (u8)'0');
    
    char * Nibbles = PosNibbles32;
    
    if(SignExtend)
    {
        if(Bits >> (BitsCount - 1))
        {
            Nibbles = NegNibbles32; 
        }
    }
    
    
    //TODO(Alex): Add NibbleTable to disassembler file
    
    //NOTE(Alex):Since we have a zero extended buffer we start at NIBBLE_COUNT_64
    char * Base = Nibbles + (NIBBLE_COUNT_32 - 1);
    char * At = Base;

    u64 Temp = Bits;
    
    while(At >= Nibbles)
    {
        u32 Value = (Temp & 0xF);
        *At = NibbleTable[Value];
        Temp >>= BITS_PER_NIBBLE;
        --At;
    }
    
    Append(out_Buffer, out_BufferCount, BufferSize, Base - (NibblesCount - 1), NibblesCount);
}


//TODO(Alex): Name this append
internal void
ConvertU64ToASCHexString(char * out_Buffer, u32 * out_BufferCount, u32 BufferSize, u64 Bits, u32 BitsCount, b32 SignExtend = false)
{
    Assert((BitsCount > 0) && (BitsCount <= 64));
    Assert((BitsCount & 0x7) == 0);
    
    u32 NibblesCount = (BitsCount / BITS_PER_NIBBLE);
    
    char NibbleTable[HEX_DIGIT_COUNT] =
    {
        '0',
        '1',
        '2',
        '3',
        '4',
        '5',
        '6',
        '7',
        '8',
        '9',
        'A',
        'B',
        'C',
        'D',
        'E',
        'F',
        
    };
    
    char NegNibbles64[NIBBLE_COUNT_64] = {0};
    char PosNibbles64[NIBBLE_COUNT_64] = {0};
    
    FillBufferWithValue(NegNibbles64, NIBBLE_COUNT_64, (u8)'F');
    FillBufferWithValue(PosNibbles64, NIBBLE_COUNT_64, (u8)'0');
    
    char * Nibbles = PosNibbles64;
    
    if(SignExtend)
    {
        if(Bits >> (BitsCount - 1))
        {
            Nibbles = NegNibbles64; 
        }
    }
    
    
    //TODO(Alex): Add NibbleTable to disassembler file
    
    //NOTE(Alex):Since we have a zero extended buffer we start at NIBBLE_COUNT_64
    char * At = Nibbles + (NIBBLE_COUNT_64 - 1);
    
    u64 Temp = Bits;
    
    while(At >= Nibbles)
    {
        u64 Value = (Temp & 0xF);
        *At = NibbleTable[Value];
        Temp >>= BITS_PER_NIBBLE;
        --At;
    }
    
    Append(out_Buffer, out_BufferCount, BufferSize, Nibbles, NIBBLE_COUNT_64);
}



//NOTE(Alex): regexp functions

internal b32
RegExpMatch(regexp_token * Token, char * RegExp)
{
    b32 Result = false;
    return Result;
}

inline b32
IsBrackets(char * At)
{
    b32 Result = ((*At == '<') || (*At == '>'));
    return Result;
}

inline b32 
IsWhiteSpace(char * At)
{
    b32 Result = ((*At == ' ') ||
                  (*At == '\n') ||
                  (*At == '\t') || 
                  (*At == '\r')
                  );
    return Result;
}


inline b32
IsNumeric(char * At)
{
    b32 Result = ((*At >= 48) && (*At <= 57));
    return Result;
}


inline b32
IsAlphanumeric(char * At)
{
    b32 Result = (((*At >= 65) && (*At <= 90)) || 
                  ((*At >= 97) && (*At <= 122)) ||
                  ((*At >= 48) && (*At <= 57))
                  );
    return Result;
}


#if 0
inline void
CleanWhiteSpace(tokenizer * Tokenizer)
{
    while((*Tokenizer->At == ' ') ||
          (*Tokenizer->At == '\n') ||
          (*Tokenizer->At == '\t') || 
          (*Tokenizer->At == '\r')
          )
    {
        ++Tokenizer->At;
    }
}
#endif


//NOTE(Alex): I'll only get the alphanumeric tokens without special symbols

//NOTE(Alex): when we say any number, we limit output to buffer size.

// "cc"  - this means two lower case letters c
//"[A-Z]z" - this means a capital letter from A - Z following a lower case z
//"[A-Z]*" - this means any number of capital letters from A-Z
//"E[a-z]" - this means capital Letter E followed by a lower case letter from a-z
//"<...>"); - this means opening guillemet then any number of elements and then a closing guillemet

//[A-Z]z* - this means any number of the pair,  capital letter from A - Z following a lower case z

//x...z - this means any number of indefinite elements then a lower case z - is that until we reach the z we don't know 
// I have to invalidate ... without symbols before and after!

//E[] - invalid range, not a dash between brackets, valid expression string 
//E-] - invalid range, not opening bracket, valid expression string
//E]  - * * *

//E[* - this is valid, and means a capital letter E followed by any number of opening brackets 

//** - this is invalid, and means the first one is ignored, and the second is any number of asterisks

//...[0-1] - this is invalid 
//[0-1]*... - this is invalid .
//[0-1]*...* - this is invalid .
//...* - this is invalid - the values around ellipsis have to be symbols or ranges

//a...a - this is valid
//[A-Z]...[0-1] - this is valid
//E[*]...[0-1] - this is valid

//E-]...[0-1] - this is valid
//E-]...*[0-1] - this is invalid
//*E-]...[0-1] - this is invalid

//E** - this is invalid
//E_** - this is invalid

//E*_* - this is valid
//[1-0]E*_* this is invalid range - first value has to be lower than upper value
//[E-H]E*_* this is valid and means a nested string

//[]...[] - this is valid, is not a valid range though

//[]...[]

//...[0-1]

//


//*[0-1] - * is ignored , a digit in the range 0 - 1
//*E - * is ignored, letter E present;
//[A-Z]*z - this means any number of capital letters followed by z, note that if the capital letters is not followed by z the string is invalidated!

// "cc"  - this means two lower case letters c

inline b32 cc (char * Stream)
{
    char FirstLetter = 'c';
    char SecondLetter = 'c';
    
    char * At = Stream;
    if((*At == FirstLetter) && (*(At + 1) == SecondLetter))
    {
        //we have a match
    }
}

//TODO(Alex): Change the return values to s32 values so we can say 
// -1 : Invalid regular expression syntax 
// 0  : normal string
// 1  : Valid regular expression syntax

//"[A-Z]z" - this means a capital letter from A - Z following a lower case z

inline b32 
PtrIsInsideString(void * At, char * String)
{
    b32 Result = ((At >= String) && (At < (String + StringLength(String))));
    return Result;
};

inline void
TestValidRange(regexp_support * RegExpSupport, regexp_result * Result, char * At)
{
    Assert(Result);
    
    if(PtrIsInsideString(At, RegExpSupport->RegExpBase))
    {
        if((At + 4) <= RegExpSupport->RegExpLast && (*Result == RegExp_normalstring))
        {
            char OpeningBracket = '[';
            char Dash = '-';
            char ClosingBracket = ']';
            
            char * MinValue = (At + 1);
            char * MaxValue = (At + 3);
            
            if((*At == OpeningBracket) && 
               (IsAlphanumeric(MinValue)) &&
               (*(At + 2) == Dash) && 
               (IsAlphanumeric(MaxValue)) &&
               (*(At + 4) == ClosingBracket)
               )
            {
                //We have a match
                if(*MinValue <= *MaxValue)
                {
                    *Result = RegExp_range;
                }
                else
                {
                    *Result = RegExp_invalidexpression;
                }
            }
        }
    }
}

inline void
TestValidAsterisk(regexp_support * RegExpSupport, regexp_result * Result, char * At)
{
    Assert(Result);
    if(PtrIsInsideString(At, RegExpSupport->RegExpBase) && (*Result == RegExp_normalstring))
    {
        char Asterisk = '*';
        if(*(At) == Asterisk)
        {
            if((At > RegExpSupport->RegExpBase))
            {
                //We have a match
                char * TestString = (At - 5);
                regexp_result RangeResult = RegExp_normalstring;
                TestValidRange(RegExpSupport, &RangeResult, TestString);
                
                if((RangeResult == RegExp_range) || (*(At - 1) != Asterisk))
                {
                    *Result = RegExp_asterisk;
                }
                else if((*(At - 1) == Asterisk))
                {
                    *Result = RegExp_invalidexpression;
                }
            }
            else if((At == RegExpSupport->RegExpBase))
            {
                *Result = RegExp_invalidexpression;
            }
        }
    }
}

//"<...>"); - this means opening guillemet then any number of elements and then a closing guillemet

inline void
TestValidEllipsis(regexp_support * RegExpSupport, regexp_result * Result, char * At)
{
    Assert(Result);
    if(PtrIsInsideString(At, RegExpSupport->RegExpBase) && (*Result == RegExp_normalstring))
    {
        if(((At + 4) <= RegExpSupport->RegExpLast))
        {
            char Period = '.';
            char Asterisk = '*';
            
            if((*(At + 0) != Asterisk) && 
               (*(At + 1) == Period) && 
               (*(At + 2) == Period) && 
               (*(At + 3) == Period) &&
               (*(At + 4) != Asterisk)
               )
            {
                // we have a match
                *Result = RegExp_ellipsis;
            }
            else if((*(At) == Asterisk) || (*(At + 4) == Asterisk))
            {
                *Result = RegExp_invalidexpression;
                //Assert(!"Invalid asterisk around ellipsis");
            }
        }
    }
}

//TODO(Alex): Here we use LastPointerAddresses so we don't dereference an invalid pointer!

inline void
EndRegExpSource(regexp_support * RegExpSupport)
{
    RegExpSupport->RegExpAt = RegExpSupport->RegExpBase;
    RegExpSupport->SourceAt = RegExpSupport->SourceBase;
    RegExpSupport->RegExpDataArrayCount = 0;
    RegExpSupport->IsInitialized = false;
}


internal b32
InitRegExpSource(regexp_support * RegExpSupport, char * SourceStream, memory_index StreamCount, char ** out_Ptr = 0)
{
    EndRegExpSource(RegExpSupport);
    
    if(StreamCount && SourceStream)
    {
        RegExpSupport->SourceBase = SourceStream;
        RegExpSupport->SourceAt = RegExpSupport->SourceBase;
        RegExpSupport->SourceLast = RegExpSupport->SourceBase + (StreamCount - 1);
        RegExpSupport->IsInitialized = true;
        
        if(out_Ptr)
        {
            *out_Ptr = RegExpSupport->SourceBase;
        }
    }
    
    return RegExpSupport->IsInitialized;
}


inline b32 
PtrInsideString(regexp_support * RegExpSupport, char * At)
{
    b32 Result = (At <= RegExpSupport->SourceLast);
    return Result;
}

inline void 
AdvanceSourcePtr(regexp_support * RegExpSupport, char ** out_At)
{
    Assert(out_At);
    *out_At = RegExpSupport->SourceAt;
}


inline void
EndRegExp(regexp_support * RegExpSupport)
{
    RegExpSupport->RegExpDataArrayCount = 0;
}



internal b32
BeginRegExp(regexp_support * RegExpSupport, char * RegExp, memory_index RegExpCount)
{
    b32 Result = false;
    
    if(RegExpSupport->IsInitialized)
    {
        RegExpSupport->RegExpBase = RegExp;
        RegExpSupport->RegExpAt = RegExpSupport->RegExpBase;
        RegExpSupport->RegExpLast = RegExp + (RegExpCount - 1);
        
        Result = true;
        char * At = RegExpSupport->RegExpBase;
        
        b32 InvalidRegExp = false;
        while((At <= RegExpSupport->RegExpLast) && !InvalidRegExp)
        {
            regexp_result RegExpResult = RegExp_normalstring;
            
            TestValidRange(RegExpSupport, &RegExpResult, At);
            TestValidAsterisk(RegExpSupport, &RegExpResult, At);
            TestValidEllipsis(RegExpSupport, &RegExpResult, At);
            
            switch(RegExpResult)
            {
                case RegExp_invalidexpression:
                {
                    InvalidRegExp = true;
                }break;
                
                case RegExp_range:
                {
                    regexp_data * Data = RegExpSupport->RegExpDataArray + RegExpSupport->RegExpDataArrayCount++;
                    Data->Type = regexp_data_range;
                    Data->MinValue = *(At + 1);
                    Data->MaxValue = *(At + 3);
                    Data->SymbolCount = 1;
                    
                    At += 5;
                }break;
                
                case RegExp_asterisk:
                {
                    u32 Index = RegExpSupport->RegExpDataArrayCount - 1;
                    
                    Assert((Index >= 0) && (Index < ArrayCount(RegExpSupport->RegExpDataArray)));
                    
                    regexp_data * Data = RegExpSupport->RegExpDataArray + Index;
                    Data->SymbolCount = -1; //NOTE(Alex): Indefinifte value is -1!
                    
                    At += 1;
                }break;
                
                case RegExp_ellipsis:
                {
                    regexp_data * Data = RegExpSupport->RegExpDataArray + RegExpSupport->RegExpDataArrayCount++;
                    Data->Type = regexp_data_indefinite;
                    Data->OpeningSymbol = *At;
                    Data->ClosingSymbol = *(At + 4);
                    Data->SymbolCount = -1;
                    
                    At += 5;
                }break;
                
                case RegExp_normalstring:
                {
                    regexp_data * Data = RegExpSupport->RegExpDataArray + RegExpSupport->RegExpDataArrayCount++;
                    Data->SymbolCount = 1;
                    Data->Type = regexp_data_value;
                    Data->Value = *At;
                    
                    At += 1;
                }break;
                
                InvalidDefaultCase;
            }
            
        }
        
        if(InvalidRegExp)
        {
            Result = false;
        }
    }
    
    return Result;
}

inline b32 
ValueIsInRange(char Value, char MinValue, char MaxValue)
{
    b32 Result = ((Value >= MinValue) && (Value <= MaxValue));
    return Result;
}

inline b32 
ValueIsEqual(char Value, char Comparand)
{
    b32 Result = (Value == Comparand);
    return Result;
}


internal b32
MatchStringToRegExp(regexp_support * RegExpSupport, char * At, regexp_token * out_Token)
{
    //If we find a match then we advance the RegExpSupport->SourceAt, if we don´t find a match 
    //RegExpSupport->SourceAt has to be equal to the end of string so there's no need to continue!
    
    //NOTE(Alex): We are going to do it simpler but slower to start with!
    
    b32 TraceFound = false;
    
    char * Tracer = At;
    b32 ValidTrace = true;
    
    for(u32 RegExpDataIndex = 0;
        (RegExpDataIndex < RegExpSupport->RegExpDataArrayCount) && ValidTrace;
        ++RegExpDataIndex)
    {
        regexp_data * Data = RegExpSupport->RegExpDataArray + RegExpDataIndex;
        
        switch(Data->Type)
        {
            case regexp_data_indefinite:
            {
                if(*Tracer == Data->OpeningSymbol)
                {
                    ++Tracer;
                    
                    while((Tracer <= RegExpSupport->SourceLast) && (*Tracer != Data->ClosingSymbol))
                    {
                        ++Tracer;
                    }
                    
                    if(*Tracer != Data->ClosingSymbol)
                    {
                        ValidTrace = false;
                    }
                    else
                    {
                        ++Tracer;
                    }
                }
                else
                {
                    ValidTrace = false;
                }
                
            }break;
            
            case regexp_data_range:
            {
                s32 SymbolCount = 0;
                //NOTE(Alex): if it is indefinite or count == 1 and enters the loop is valid
                //if count >= 1 it has to complete the loop completely 
                //it has to complete the loop completely to be validated
                
                if(ValueIsInRange(*Tracer, Data->MinValue, Data->MaxValue))
                {
                    while((Tracer <= RegExpSupport->SourceLast) && ValueIsInRange(*Tracer, Data->MinValue, Data->MaxValue) && (SymbolCount != Data->SymbolCount))
                    {
                        ++Tracer;
                        ++SymbolCount;
                    }
                    
                    if((Data->SymbolCount != -1) && (SymbolCount != Data->SymbolCount))
                    {
                        ValidTrace = false;
                    }
                    
                }
                else
                {
                    ValidTrace = false;
                }
                
                
            }break;
            
            case regexp_data_value:
            {
                s32 SymbolCount = 0;
                if(ValueIsEqual(*Tracer, Data->Value))
                {
                    while((Tracer <= RegExpSupport->SourceLast) && ValueIsEqual(*Tracer, Data->Value) && (SymbolCount != Data->SymbolCount))
                    {
                        ++Tracer;
                        ++SymbolCount;
                    }
                    
                    if((Data->SymbolCount != -1) && (SymbolCount != Data->SymbolCount))
                    {
                        ValidTrace = false;
                    }
                }
                else
                {
                    ValidTrace = false;
                }
                
            }break;
            
            InvalidDefaultCase;
        }
    }
    
    if(ValidTrace)
    {
        if(out_Token)
        {
            out_Token->Base = At;
            out_Token->Count = (u32)((memory_index)Tracer - (memory_index)At);
        }
        
        RegExpSupport->SourceAt = Tracer;
        TraceFound = true;
    }
    
    return TraceFound;
}


internal b32
GetNextTokenWithRegExp_(regexp_support * RegExpSupport, regexp_token * out_Token)
{
    //If we find a match then we advance the RegExpSupport->SourceAt, if we don´t find a match 
    //RegExpSupport->SourceAt has to be equal to the end of string so there's no need to continue!
    
    //NOTE(Alex): We are going to do it simpler but slower to start with!
    
    b32 TraceFound = false;
    for(char * Base = RegExpSupport->SourceAt;
        (Base <= RegExpSupport->SourceLast) && !TraceFound; 
        ++Base)
    {
        char * Tracer = Base;
        TraceFound = MatchStringToRegExp(RegExpSupport, Tracer, out_Token);
    }
    
    return TraceFound;
}

internal b32
GetNextTokenWithRegExp(regexp_support * RegExpSupport, char * RegExp, memory_index RegExpSize, regexp_token * out_Token)
{
    b32 Result = false;
    
    if(BeginRegExp(RegExpSupport, RegExp, RegExpSize))
    {
        Result = GetNextTokenWithRegExp_(RegExpSupport, out_Token);
    }
    
    EndRegExp(RegExpSupport);
    
    return Result;
}

internal void
FindTokensWithRegExp(regexp_support * RegExpSupport, char * SourceStream, memory_index StreamCount, regexp_token * out_TokenArray, memory_index ArraySize, u32 * out_TokenCount,  char * RegExp, memory_index RegExpCount) 
{
    if(SourceStream && out_TokenArray && out_TokenCount)
    {
        InitRegExpSource(RegExpSupport, SourceStream, StreamCount);
        
        if(BeginRegExp(RegExpSupport, RegExp, RegExpCount))
        {
            u32 Count = 0;
            while(Count < ArraySize)
            {
                if(GetNextTokenWithRegExp_(RegExpSupport, &out_TokenArray[Count]))
                {
                    ++Count;
                }
                else
                {
                    break;
                }
            }
            
            *out_TokenCount = Count;
        }
        
        EndRegExp(RegExpSupport);
        
        EndRegExpSource(RegExpSupport);
    }
    
}


//NOTE(Alex): This finds the first regexp_token with these regexp in the string. 

inline void 
FindToken(regexp_support * RegExpSupport, char * SourceStream, memory_index StreamCount, regexp_token * out_Token, char * RegExp, memory_index RegExpCount)
{
    u32 TokenCount;
    FindTokensWithRegExp(RegExpSupport, SourceStream, StreamCount, out_Token, 1, &TokenCount, RegExp, RegExpCount);
}


internal b32
StringIsEqualRegExp(regexp_support * RegExpSupport, char * At, char * RegExp, memory_index RegExpCount, regexp_token * out_Token = 0)
{
    b32 Result = false;
    
    if(BeginRegExp(RegExpSupport, RegExp, RegExpCount))
    {
        Result = MatchStringToRegExp(RegExpSupport, At, out_Token);
    }
    
    //NOTE(Alex): We want to reset the RegExpDataArray each time so we can test new regexps!
    EndRegExp(RegExpSupport);
    
    return Result;
}

internal b32
StringIsEqualRegExp(regexp_support * RegExpSupport, char * At, char * RegExp, regexp_token * out_Token = 0)
{
    memory_index RegExpCount = StringLength(RegExp);
    b32 Result = StringIsEqualRegExp(RegExpSupport, At, RegExp, RegExpCount, out_Token);
    return Result;
}

