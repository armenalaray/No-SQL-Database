//////////////////////////////////////////////////////
//
//Author: Alejandro Armenta
//Date: 2019
//File: meta_instruction_flags.cpp
//Company:
//
//(2018-2019) All rights reserved.
//
//////////////////////////////////////////////////////

/*
this file will pick the  meta generated .cpp files and modify its flags 

*/

#include "windows.h"
#include "stdio.h"
#include "eaglefly_platform.h"
#include "eaglefly_string.h"

#include "meta_instruction_flags.h"

#include "eaglefly_string.cpp"

internal void
Win32_OpenActiveScreenBuffer(HANDLE * out_Handle)
{
    *out_Handle = CreateFileA("CONOUT$",
                              GENERIC_READ | GENERIC_WRITE,
                              FILE_SHARE_WRITE,
                              0,
                              OPEN_EXISTING,
                              0,
                              0
                              );
}


internal void
Win32_CreateConsoleScreenBuffer(HANDLE * out_Handle)
{
    *out_Handle = CreateConsoleScreenBuffer(GENERIC_READ |           // read/write access 
                                            GENERIC_WRITE, 
                                            FILE_SHARE_READ | 
                                            FILE_SHARE_WRITE,        // shared 
                                            NULL,                    // default security attributes 
                                            CONSOLE_TEXTMODE_BUFFER, // must be TEXTMODE 
                                            NULL);                   // reserved; must be NULL 
    
}

internal memory_index
GetFileSize(FILE * File)
{
    memory_index Result = 0;
    
    fseek ( File, 0, SEEK_END);
    Result = ftell (File);
    fseek ( File, 0, SEEK_SET);
    
    return Result;
}

internal void
win32_WriteFile(HANDLE STDOutHandle, char * Buffer, u32 BufferLength)
{
    u32 TokenCharsWritten = 0;
    WriteFile(STDOutHandle, (void*)Buffer, BufferLength, (LPDWORD)&TokenCharsWritten,0);
}

internal void
meta_WriteFile(meta_state * MetaState, char * String, memory_index StringLength)
{
    win32_WriteFile(MetaState->STDOutHandle, String, SafeTruncateU64ToU32(StringLength));
}


int main(int ArgCount, char ** Arguments)
{
	HANDLE STDOutHandle = GetStdHandle(STD_OUTPUT_HANDLE); 
	FILE * MetaFile = fopen(Arguments[1], "rb");
	
	if(MetaFile)
	{
		u32 MetaFileSize = SafeTruncateU64ToU32(GetFileSize(MetaFile));
		
        char * MetaFileBase = 0;
        MetaFileBase = (char *)malloc(MetaFileSize);
        
        memory_index MetaFileBytesRead = fread (MetaFileBase, 1, MetaFileSize, MetaFile);
        Assert(MetaFileBytesRead  == MetaFileSize);
        
        if(MetaFileBase)
        {
			meta_state MetaState = {};
            MetaState.STDOutHandle = STDOutHandle;
			
#define TOKEN_ARRAYS_COUNT 3
			
			char * REPStrings[] = 
			{
				"MOVSB", 
				"MOVSW", 
				//NOTE(Alex): There's an instruction called MOVSD that works with scalar double precision floating point values that shouldnt be allowed to have a REP prefix!!!			
				"MOVSD", 
				"MOVSQ", 
				
				"SCASB", 
				"SCASW", 
				"SCASD", 
				"SCASQ", 
				
				"LODSB", 
				"LODSW", 
				"LODSD", 
				"LODSQ",
				
				"STOSB", 
				"STOSW", 
				"STOSD", 
				"STOSQ",
				
				"CMPSB", 
				"CMPSW", 
				//NOTE(Alex): There's an instruction called COMPSD that works with scalar double precision floating point values that shouldnt be allowed to have a REP prefix!!!			
				"CMPSD", 
				"CMPSQ", 
				
				"INSB",
				"INSW",
				"INSD",
				
				"OUTSB",
				"OUTSW",
				"OUTSD",
			};
			
			char * LOCKStrings[] =
			{
				"ADD", 
				"ADC",
				"AND",
				"BTC",  
				"BTR",
				"BTS", 
				"CMPXCHG", 
				"CMPXCHG8B",
				"CMPXCHG16B", 
				"DEC", 
				"INC", 
				"NEG", 
				"NOT", 
				"OR", 
				"SBB", 
				"SUB", 
				"XOR", 
				"XADD", 
				"XCHG",
			};
			
			char * BRANCHHINTStrings[] = 
			{
				"JO",
				"JNO",
				"JB",
				"JNAE",
				"JC2",
				"JNB",
				"JAE",
				"JNC",
				"JZ",
				"JE",
				"JNZ",
				"JNE",
				"JBE",
				"JNA",
				"JNBE",
				"JA",
				"JS",
				"JNS",
				"JP",
				"JPE",
				"JNP",
				"JPO",
				"JL",
				"JNGE",
				"JNL",
				"JGE",
				"JLE",
				"JNG",
				"JNLE",
				"JG",
				"JCXZ",
				"JECXZ",
				"JRCXZ",
			};			
			
			
			char ** StringPtrs[TOKEN_ARRAYS_COUNT] = 
			{
				REPStrings, 
				LOCKStrings, 
				BRANCHHINTStrings, 
			};
			
			token_array TokenArrays[TOKEN_ARRAYS_COUNT] = {};
			
			TokenArrays[0].Count = ArrayCount(REPStrings);
			TokenArrays[1].Count = ArrayCount(LOCKStrings);
			TokenArrays[2].Count = ArrayCount(BRANCHHINTStrings);
			
			for(u32 Index = 0;
				Index < ArrayCount(StringPtrs);
				++Index)
			{
				if(Index == 2)
				{
					int x=5;
				}
				token_array * TA = TokenArrays + Index; 
				token * T = TA->FirstToken;
				char ** Ptr = StringPtrs[Index];
				
				for(u32 TokenIndex =0;
					TokenIndex < TA->Count;
					++TokenIndex)
				{
					
					T->Base = *Ptr;
					T->Count = StringLength(*Ptr);
					++T;
					++Ptr;
				}                
			}
			
			token FlagStrings[TOKEN_ARRAYS_COUNT];
			
			FlagStrings[0].Base = "REP_VALID";
			FlagStrings[0].Count = StringLength(FlagStrings[0].Base);
			
			FlagStrings[1].Base = "LOCK_VALID";
			FlagStrings[1].Count = StringLength(FlagStrings[1].Base);
			
			FlagStrings[2].Base = "BRANCHHINT_VALID";
			FlagStrings[2].Count = StringLength(FlagStrings[2].Base);
			
			char * Ptr = MetaFileBase;	
			
			mnemonic_result MC = {};
			
			while((unsigned char*)Ptr < (unsigned char*)MetaFileBase + MetaFileSize)
			{
				
				if(MC.Valid && *Ptr == '!')
				{
					char * Temp = Ptr + 1;
					token TestFlag = FlagStrings[MC.Index];
					if(StringsAreEqual(Temp, TestFlag.Count, TestFlag.Base, TestFlag.Count))
					{
						*Ptr = ' ';
					}
					
				}
				
				if(*Ptr == ';')
				{
					MC.Valid = false;
				}
				
				if(*Ptr == '"')
				{
					meta_WriteFile(&MetaState, Ptr, 1);
					++Ptr;
					token CM = {};
					CM.Base = Ptr;
					
					while(*Ptr != '"')
					{
						++CM.Count;
						++Ptr;
					}
					
					for(u32 index = 0;
						(index < TOKEN_ARRAYS_COUNT) && !MC.Valid;
						++index)
					{
						
						token_array * TA = TokenArrays + index;
						token * Token = TA->FirstToken;
						for(u32 TokenIndex = 0;
							(TokenIndex < TA->Count) && !MC.Valid;
							++TokenIndex)
						{
							if(StringsAreEqual(CM.Base, CM.Count, Token->Base, Token->Count))
							{
								MC.Valid = true;
								MC.Index = index;
							}
							
							++Token;
						}
					}
					
					meta_WriteFile(&MetaState, CM.Base, CM.Count);
				}
				
				meta_WriteFile(&MetaState, Ptr, 1);
				
				++Ptr;
			}
			
			
		}
		
		
		free(MetaFileBase);
		fclose(MetaFile);
	}


}