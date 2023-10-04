//////////////////////////////////////////////////////
//
//Author: Alejandro Armenta 
//Date: 2019
//File: meta_instruction_infos_table.h
//Company: 
//
//All rights reserved.
//
//////////////////////////////////////////////////////


#ifndef META_INSTRUCTION_INFOS_TABLE_H
#define META_INSTRUCTION_INFOS_TABLE_H

enum grammar_token_type
{
    GrammarTokenType_Invalid = 0,
    GrammarTokenType_Keyword,
    GrammarTokenType_AlphaNumeric,
    
    GrammarTokenType_Normal,
    GrammarTokenType_Group,
    GrammarTokenType_Entry,
    
    GrammarTokenType_Text,
    
    GrammarTokenType_Numeric,
    GrammarTokenType_Comment,
    GrammarTokenType_Count,
};


struct grammar_token
{
    char * Base;
    u32 Count;
};

struct grammar_tokenizer
{
    char * Base;
    char * At;
    char * Last;
    
    b32 IsGrammar;
};




#endif

