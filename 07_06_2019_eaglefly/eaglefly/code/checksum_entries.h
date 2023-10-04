//////////////////////////////////////////////////////
//
//Author: Alejandro Armenta
//Date: 2019
//File: checksum_entries.h
//Company:
//
//(2018-2019) All rights reserved.
//
//////////////////////////////////////////////////////


#ifndef CHECKSUM_ENTRIES_H

enum file_id
{
	FileID_asm,
	FileID_opc,
	FileID_count,
	
};

enum token_type
{
	TokenType_Invalid = 0,
    TokenType_Keyword,
    TokenType_Comment,
    TokenType_Numeric,    
    TokenType_Count,
};

struct entry_entry 
{
	string e_s;
	string entry_id_s;
	entry_entry * next;
};

struct entry_group
{
	memory_index count;
	entry_entry * first_entry;
};


struct state
{
    HANDLE STDOutHandle;
    memory_arena Arena;
    sub_arena AssemblyGrammarsArena;
    sub_arena OpcodeIDSArena;
	sub_arena * c_arena;
	entry_group * c_g;
};






#define CHECKSUM_ENTRIES_H
#endif


