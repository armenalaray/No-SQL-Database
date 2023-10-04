//////////////////////////////////////////////////////
//
//Author: Alejandro Armenta 
//Date: 2019
//File: meta_opcode_ids_table.h
//Company: 
//
//All rights reserved.
//
//////////////////////////////////////////////////////


#ifndef META_OPCODE_IDS_TABLE_H
#define META_OPCODE_IDS_TABLE_H

enum opcode_type
{
    OpcodeType_Invalid = 0,
    OpcodeType_Keyword,
    OpcodeType_Opcode,
    OpcodeType_OpcodeID,
    OpcodeType_Comment,
    OpcodeType_Numeric,
    
    OpcodeType_Count,
};


struct opcode_token
{
    char * Base;
    u32 Count;
};



struct opcode_tokenizer
{
    char * Base;
    char * At;
    char * Last;
    
    b32 IsOpcode;
};



#endif
