//////////////////////////////////////////////////////
//
//Author: Alejandro Armenta 
//Date: 2019
//File: cheksum_entries.cpp
//Company: 
//
//All rights reserved.
//
//////////////////////////////////////////////////////


#include "Windows.h"
#include "stdio.h"


#include "eaglefly_platform.h"
#include "meta_opcode_ids_table.h"

#include "eaglefly_string.h"
#include "eaglefly_string.cpp"

#include "checksum_entries.h"


char OneByteString[MAX_BUFFER_SIZE] = {"one-byte"};
u32 OneByteStringLength = StringLength(OneByteString);

char TwoByteString[MAX_BUFFER_SIZE] = {"two-byte"};
u32 TwoByteStringLength = StringLength(TwoByteString);

char PriOpcdString[MAX_BUFFER_SIZE] = {"pri_opcd"};
u32 ProOpcdStringLength = StringLength(PriOpcdString);

char EntryString[MAX_BUFFER_SIZE] = {"entry"};
u32 EntryStringLength = StringLength(EntryString);

char ExtraEntryString[MAX_BUFFER_SIZE] = {"exta_entry"};
u32 ExtraEntryStringLength = StringLength(ExtraEntryString);

char GrammarString[MAX_BUFFER_SIZE] = {"grammar"};
u32 GrammarStringLength = StringLength(GrammarString);

char ExtraGrammarString[MAX_BUFFER_SIZE] = {"extra_grammar"};
u32 ExtraGrammarStringLength = StringLength(ExtraGrammarString);

char GrammarGroupString[MAX_BUFFER_SIZE] = {"grammar_group"};
u32 GrammarGroupStringLength = StringLength(GrammarGroupString);

char GrammarEntryString[MAX_BUFFER_SIZE] = {"grammar_entry"};
u32 GrammarEntryStringLength = StringLength(GrammarEntryString);

char EqualString[MAX_BUFFER_SIZE] = {"="};
u32 EqualStringLength = StringLength(EqualString);

char OpcodeIDString[MAX_BUFFER_SIZE] = {"opcode_id"};
u32 OpcodeIDStringLength = StringLength(OpcodeIDString);

char ExtraOpcodeIDString[MAX_BUFFER_SIZE] = {"extra_opcode_id"};
u32 ExtraOpcodeIDStringLength = StringLength(ExtraOpcodeIDString);

char RexString[MAX_BUFFER_SIZE] = {"rex"};
u32 RexStringLength = StringLength(RexString);

char RegString[MAX_BUFFER_SIZE] = {"reg"}; 
u32 RegStringLength = StringLength(RegString);

char RMString[MAX_BUFFER_SIZE] = {"rm"};
u32 RMStringLength = StringLength(RMString);

char ModString[MAX_BUFFER_SIZE] = {"mod"};
u32 ModStringLength = StringLength(ModString);

char sreg2String[MAX_BUFFER_SIZE] = {"sreg2"};
u32 sreg2StringLength = StringLength(sreg2String);

char sreg3String[MAX_BUFFER_SIZE] = {"sreg3"};
u32 sreg3StringLength = StringLength(sreg3String);


char SpaceString[MAX_BUFFER_SIZE] = {" "};
u32 SpaceStringLength = StringLength(SpaceString);

char EndOfLineString[MAX_BUFFER_SIZE] = {"\n"};
u32 EndOfLineStringLength = StringLength(EndOfLineString);

char count_asm_s[MAX_BUFFER_SIZE] = {"count_asm_entries: "};
u32 count_asm_s_length = StringLength(count_asm_s);

char count_opc_s[MAX_BUFFER_SIZE] = {"count_opc_entries: "};
u32 count_opc_s_length = StringLength(count_opc_s);




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
meta_WriteFile(state * MetaState, char * String, memory_index StringLength)
{
    win32_WriteFile(MetaState->STDOutHandle, String, SafeTruncateU64ToU32(StringLength));
}


inline void
CleanWhiteSpace(tokenizer * Tokenizer)
{
    while((IsWhiteSpace(Tokenizer->At)) && (Tokenizer->At <= Tokenizer->Last))
    {
        ++Tokenizer->At;
    }
}


#if 0        
((*At >= 65) && (*At <= 90)) || 
((*At >= 97) && (*At <= 122)) ||
((*At >= 48) && (*At <= 57)) ||
(*At == '-') ||
(*At == '_') ||
(*At == '=') ||
(*At == '<') ||
(*At == '>') ||
(*At == '[') ||
(*At == '/') ||
(*At == ':') ||
(*At == '(') ||
(*At == '#') ||
(*At == ',') 
);
#endif


b32
IsGrammarCharacter(char * At)
{
    b32 Result = (!IsWhiteSpace(At));
    return Result;
}

internal void
InitializeTokenizer(tokenizer * out_Tokenizer, char * Base, u32 Count)
{
    Assert(Count > 0);
    
    out_Tokenizer->Base = Base;
    out_Tokenizer->At = out_Tokenizer->Base;
    out_Tokenizer->Last = out_Tokenizer->Base + (Count - 1);
}

internal token_type 
GetNextToken(tokenizer * Tokenizer, char ** out_Ptr, u32 * out_Count)
{
    token_type Result = TokenType_Invalid;
    
    CleanWhiteSpace(Tokenizer);
    

    
    char * Ptr = 0;
    u32 Count = 0;
    
    char * At = Tokenizer->At;
    
    if(At <= Tokenizer->Last)
    {
        if(IsNumeric(At))
        {
            Result = TokenType_Numeric;
            Ptr = At;
            
            while(IsNumeric(At))
            {
                ++At;
                ++Count;
            }
        }

        else if(*At == '/')
		{
			++At;		
			Assert(*At == '/');
			++At;

			Ptr = At;			
			
			Result = TokenType_Comment;
			while(*At != '\n')
			{
				++Count;
				++At;
			}
			
			++At;
		}
		
        else if(IsGrammarCharacter(At))
        {
            Result = TokenType_Keyword;
            Ptr = At;
            
            while(IsGrammarCharacter(At))
            {
                ++At;
                ++Count;
            }
        }
    }
    
    if(out_Ptr && out_Count)
    {
        *out_Ptr = Ptr;
        *out_Count = Count;
    }
    
    Tokenizer->At = At;
    
    return Result;
}

inline b32 
IsUpperCase(char * At)
{
    b32 Result = ((*At >= 0x41) && (*At <= 0x5A));
    return Result;
}

inline b32 
IsLowerCase(char * At)
{
    b32 Result = ((*At >= 0x61) && (*At <= 0x7A));
    return Result;
}

internal void
lex_file_and_create_entries(state * State, entry_group * out_group, void * file_base, memory_index file_size, file_id file_id_)
{
	
	tokenizer Tokenizer = {};
	InitializeTokenizer(&Tokenizer, (char*)file_base, SafeTruncateU64ToU32(file_size));
	
	entry_group * c_g = out_group;
	
	
	
	b32 is_entry = false;
	token l_entry_id_t = {};
	b32 ElementFound = true;
	
	b32 valid_entry = false;
	
	while(ElementFound)
	{
		token Token = {};
		token_type Type = GetNextToken(&Tokenizer, &Token.Base, &Token.Count);
		
		switch(Type)
		{
			case OpcodeType_Invalid:
			{
				//NOTE(Alex): Invalid Token
				ElementFound = false;
			}break;
			
			case TokenType_Numeric:
			{
				if(is_entry)
				{
					l_entry_id_t = Token;
					is_entry = false;
				}
				
			}break;
			
			case TokenType_Comment:
			{
				
			}break;
			
			case TokenType_Keyword:
			{
				if(
					StringsAreEqual(Token.Base, Token.Count, EntryString, EntryStringLength) || 
					StringsAreEqual(Token.Base, Token.Count, ExtraEntryString, ExtraEntryStringLength)
					
					)
				{
					is_entry = true;
				}
				
				if(file_id_ == FileID_asm)
				{
					if(
						StringsAreEqual(Token.Base, Token.Count, GrammarString, GrammarStringLength) || 
						StringsAreEqual(Token.Base, Token.Count, ExtraGrammarString, ExtraGrammarStringLength)||
						StringsAreEqual(Token.Base, Token.Count, GrammarGroupString, GrammarGroupStringLength) 
						)
					{
						valid_entry = true;
					}
				}
				else if (file_id_ == FileID_opc)
				{
					if(
						StringsAreEqual(Token.Base, Token.Count, OpcodeIDString, OpcodeIDStringLength) || 
						StringsAreEqual(Token.Base, Token.Count, ExtraOpcodeIDString, ExtraOpcodeIDStringLength)
						)
					{
						valid_entry = true;
					}
				}
				
				if(valid_entry)
				{
					entry_entry * e_e = PushStruct(&State->c_arena->Arena, entry_entry);
					
					if(c_g->first_entry == 0)
					{
						c_g->first_entry = e_e;
					}
					
					string * entry_id_s = &e_e->entry_id_s;
					entry_id_s->buffer = l_entry_id_t.Base;
					entry_id_s->count = l_entry_id_t.Count;
					entry_id_s->mem_size = entry_id_s->count;
					
					
					string * e_s = &e_e->e_s;
					e_s->buffer = Token.Base;
					e_s->count = Token.Count;
					e_s->mem_size = e_s->count;
					
					++c_g->count;
					valid_entry = false;
				}
				
				
			}break;
			
			InvalidDefaultCase;
		}
	}
}



int main(u32 ArgCount, char ** Arguments)
{
    
    HANDLE STDOutHandle = GetStdHandle(STD_OUTPUT_HANDLE); 
    FILE * AssemblyGrammarsFile = fopen(Arguments[1], "rb");
    FILE * OpcodeIDSFile = fopen(Arguments[2], "rb");
    
    if(AssemblyGrammarsFile && OpcodeIDSFile)
    {
        memory_index AssemblyGrammarsFileSize = GetFileSize(AssemblyGrammarsFile);
        memory_index OpcodeIDSFileSize = GetFileSize(OpcodeIDSFile);
        
        char * AssemblyGrammarsFileBase = 0;
        char * OpcodeIDSFileBase = 0;
        AssemblyGrammarsFileBase = (char *)malloc(AssemblyGrammarsFileSize);
        OpcodeIDSFileBase = (char *)malloc(OpcodeIDSFileSize);
        
        
        memory_index AssemblyGrammarsFileBytesRead = fread (AssemblyGrammarsFileBase, 1, AssemblyGrammarsFileSize, AssemblyGrammarsFile);
        memory_index OpcodeIDSFileBytesRead = fread (OpcodeIDSFileBase, 1, OpcodeIDSFileSize, OpcodeIDSFile);
        
        Assert(AssemblyGrammarsFileBytesRead == AssemblyGrammarsFileSize);
        Assert(OpcodeIDSFileBytesRead == OpcodeIDSFileSize);
        
        if(AssemblyGrammarsFileBase && OpcodeIDSFileBase)
        {
			
			
			entry_group asm_g_group = {};
			entry_group opc_i_group = {};
			
			
            memory_index MetaMemorySize = Gigabytes(4);
            state * State = (state *)malloc(MetaMemorySize);
            
            InitializeArena(&State->Arena, State + 1, MetaMemorySize - sizeof(state));
            SubArena(&State->Arena, &State->AssemblyGrammarsArena, Megabytes(16));
            SubArena(&State->Arena, &State->OpcodeIDSArena, Megabytes(16));
            State->STDOutHandle = STDOutHandle;
            State->c_arena = &State->AssemblyGrammarsArena;
            State->c_g = &asm_g_group;
			
			lex_file_and_create_entries(State, &asm_g_group, AssemblyGrammarsFileBase, AssemblyGrammarsFileSize, FileID_asm);
			lex_file_and_create_entries(State, &opc_i_group, OpcodeIDSFileBase, OpcodeIDSFileSize, FileID_opc);

			u32 mem_size = (1 << 8);
			
			string count_asm_group_s = {};
			make_string_size(&State->Arena, &count_asm_group_s, 0, mem_size);
			count_asm_group_s.count = _snprintf_s(count_asm_group_s.buffer, count_asm_group_s.mem_size, count_asm_group_s.mem_size, "%zi", asm_g_group.count); 
			
			string count_opc_group_s = {};
			make_string_size(&State->Arena, &count_opc_group_s, 0, mem_size);
			count_opc_group_s.count = _snprintf_s(count_opc_group_s.buffer, count_opc_group_s.mem_size, count_opc_group_s.mem_size, "%zi", opc_i_group.count); 
			
			
			meta_WriteFile(State, count_asm_s, count_asm_s_length);
			meta_WriteFile(State, count_asm_group_s.buffer, count_asm_group_s.count);
			meta_WriteFile(State, count_opc_s, count_opc_s_length);
			meta_WriteFile(State, count_opc_group_s.buffer, count_opc_group_s.count);
			
			
			entry_entry * a = asm_g_group.first_entry;
			entry_entry * o = opc_i_group.first_entry;
			
			//NOTE(Alex): there could be multiple comments for the same entry.			
			b32  invalid_match = false;
			for(u32 index  = 0; 
				index <  asm_g_group.count && !invalid_match; 
				++index)
			{
				if(!StringsAreEqual(&o->entry_id_s , &a->entry_id_s))
				{
					string * o_id_s = &o->entry_id_s;
					string * a_id_s = &a->entry_id_s;
					
					meta_WriteFile(State, o_id_s->buffer, o_id_s->count);
					//meta_WriteFile(State, SpaceString, SpaceStringLength);
					//meta_WriteFile(State, o->e_s->buffer, o->e_s->count);
					meta_WriteFile(State, SpaceString, SpaceStringLength);
					
					meta_WriteFile(State, a_id_s->buffer, a_id_s->count);
					//meta_WriteFile(State, SpaceString, SpaceStringLength);
					//meta_WriteFile(State, a->e_s->buffer, a->e_s->count);
					
					meta_WriteFile(State, EndOfLineString, EndOfLineStringLength);
					
					invalid_match = true;
				}
				
				++a;
				++o;			
			}
			
			
			
			free(State);
			free(AssemblyGrammarsFileBase);
			free(OpcodeIDSFileBase);
		}
		
		fclose(AssemblyGrammarsFile);
		fclose(OpcodeIDSFile);
	}
	
	
	
}

				   
#if 0
{
	opcode_tokenizer Tokenizer = {};
	InitializeOpcodeIDTokenizer(&Tokenizer, OpcodeIDSFileBase, SafeTruncateU64ToU32(OpcodeIDSFileSize));
	
	opcode_token LastNumberToken = {};
	b32 LastIsNumber = false;
	
	b32 ElementFound = true;
	while(ElementFound)
	{
		opcode_token Token = {};
		opcode_type Type = GetNextOpcodeIDToken(&Tokenizer, &Token.Base, &Token.Count);
		
		switch(Type)
		{
			case OpcodeType_Invalid:
			{
				//NOTE(Alex): Invalid Token
				ElementFound = false;
			}break;
			
			case OpcodeType_Numeric:
			{
				LastNumberToken = Token;
				LastIsNumber = true;
			}break;
			
			case OpcodeType_Keyword:
			{
				if(LastIsNumber)
				{
					if(StringsAreEqual(Token.Base, Token.Count, OpcodeIDString, OpcodeIDStringLength) ||
					   StringsAreEqual(Token.Base, Token.Count, ExtraOpcodeIDString, ExtraOpcodeIDStringLength)
					   )
					{
						u64 Value = 0;
						ConvertASCHexStringToU64(LastNumberToken.Base, LastNumberToken.Count, &Value);
						u64 * Ptr = PushStruct(&State->OpcodeIDSArena.Arena, u64);
						*Ptr = Value;
					}
				}
				
				LastIsNumber = false;
			}break;
			
			InvalidDefaultCase;
		}
	}
}
#endif
            
            