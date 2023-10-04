//////////////////////////////////////////////////////
//
//Author: Alejandro Armenta 
//Date: 2019
//File: meta_opcodes_ids_table.cpp
//Company: 
//
//All rights reserved.
//
//////////////////////////////////////////////////////

/*
//INFO FILES CLEANUP PROCESS:

Do these steps for each operating mode 16, 32, 64:

1. choose in assembly_grammar.info the grammar you want on <>/<> operands
2. look for opcodes collision in opcode_ids.info and select the aprropiate one in opcode_ids.info. and 
select the appropriate or make a group on assembly_grammars.info

For 64 bit only 

3. add rex prefix to instructions that have mandatory prefixes on 64 bit mode and the corresponding assembly grammar

.   opcode id                            assembly_grammar

ex. opcode_id (8,0xF3) (8,0x90)          grammar PAUSE 
ex. opcode_id (8,0xF3) rex (8,0x90)      grammar PAUSE 

*/


#ifndef INSTRUCTION_INFOS_FILTER_H


#include "eaglefly_string.h"
#include "xml_tree.h"


enum processor_mode 
{
    ProcessorMode_Invalid,
    ProcessorMode_64bit,
    ProcessorMode_32bit,
    ProcessorMode_16bit,
};


struct meta_state
{
    HANDLE STDOutHandle;
    
    memory_arena MetaArena;
    
    sub_arena AttrValuesArena;
    sub_arena AttrNamesArena;
    sub_arena ElementArena;
    
    sub_arena ListsArena;
    
    xml_tree Tree;
};


#define INSTRUCTION_INFOS_FILTER_H
#endif
