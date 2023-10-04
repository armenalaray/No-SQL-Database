//////////////////////////////////////////////////////
//
//Author: Alejandro Armenta 
//Date: 2019
//File: eaglefly_decoder.h
//Company: 
//
//All rights reserved.
//
//////////////////////////////////////////////////////

/*
NOTE(Alex): eaglefly_disasm_04.h 

normally disassemblers are used to see the asssmlby code that the compiler emits, so it's closely related to the compiler, that's its main functionality!
So what i need to know is the relationship betweeen the compiler and the user! to see what's the best idea!

Ideally what you would like to have is something as a list of compiler options for the 

I want to choose which insructions to put on the assembly, i want that possibility! Nowadays tere's options for doing that but it is still very precariate, normally you would use inline assembly, but what if you 
could have a tool as a compiler where you write in a language and you could see the assembly instructions for a particular block, or a paticular statement, or a particular 


Nowadays what you do to debug something is to compile and disassemble! which is straightforwad, 
but what if we dont compile and we disassemble, 

The disassembler is like opening the black box for what a compiler does in a sense.
You see the trace of what's left y compiler, the thing is that you dont see the process but you see the end result, nowadays when everything is done using compilers, low or less importance is given to assembly, 
but is equally important - because is the end result! and ideally as well i mean is really thinking on the processor itself, what is the arquitecture, because at the end of the day that's the real problem!,  
the problem is the hardware! So if the problem is the hardware you have to understand how to deal with it in the most efficient way to get your problem done!

Per example, one thing I saw was arquitecturally speaking you cannot expand the processor stack without having relevant performance issues
So one thing is missig is that approach to programming, not focusing on the code but on the hardware!
If you focus on hardware, then everything constructs itself up from there, and even now that i have a poor kowledge of processor, im starting to see the consecuences of the actions,
so the disassembler should let you know about the arquitecture itself so that its not just mnemonics but particular bottlenecks on the pipeline, so you mean like performance issues on them, or something 
Like ooh using this combination of instructions is not good because they go through the same port, try this instructions instead, so it is an optimizattion guideline to the user!

So ideally what you would have is something like an assembly listing, with the instructions and annotations about them! - trying to find bottlenecks on the instructions!

references - 
Ask mr Agner Fog if I can use his tables to try to make the performance heuristics for instruction combinations

*/

#ifndef EAGLEFLY_DECODER_H

#define MAX_OPERAND_COUNT 16

//TODO(Alex): change this to EFLY_STRING_BUFFER_SIZE
#define MAX_BUFFER_SIZE 1024

#include "instruction_table_info.h"
#include "eaglefly_string.h"
#include "eaglefly_bits.h"

//Group 1 prefixes
#define LockPrefix 0xF0
#define REPNE_REPNZ 0xF2 //only used for string instructions and input/output instructions 
#define REP_REPE 0xF3 //only used for string instructions and input/output instructions 
#define BND 0xF2 

//Group 2 prefixes
#define CSOverride 0x2E 
#define SSOverride 0x36
#define DSOverride 0x3E
#define ESOverride 0x26
#define FSOverride 0x64
#define GSOverride 0x65

#define BranchNotTaken 0x2E
#define Branchtaken 0x3E


//Group 3 prefixes
#define OperandSizeOverridePrefix 0x66 //is also used as a mandatory prefix for some instructions

//Group 4 prefixes
#define AddressSizeOverridePrefix 0x67

enum string_types
{
str_comma,
str_endofline,
str_space,
};

enum eff_operand_size
{
	operandsize_Invalid,
	
	operandsize_8,
	operandsize_16,
	operandsize_32,
	operandsize_64,
	operandsize_128,
	operandsize_256,
	operandsize_512,
	
	operandsize_48,
	operandsize_80,
	
	operandsize_MemoryRange,
	
	operandsize_Count,
	
};


enum eff_address_size
{
	addresssize_Invalid,
	addresssize_16,
	addresssize_32,
	addresssize_64,
	addresssize_Count,	
};


enum group1_prefix
{
    group1_Invalid,
    group1_LockPrefix,
    group1_REPNE_REPNZ, //only used for string instructions and input/output instructions 
    group1_REP_REPE, //only used for string instructions and input/output instructions 
    group1_BND, 
};

enum group2_prefix
{
    group2_Invalid ,
    group2_CSOverride ,
    group2_SSOverride ,
    group2_DSOverride ,
    group2_ESOverride ,
    group2_FSOverride ,
    group2_GSOverride ,
    
    group2_BranchNotTaken ,
    group2_Branchtaken ,
};

enum processor_mode 
{
    ProcessorMode_Invalid,
    ProcessorMode_64bit,
    ProcessorMode_32bit,
    ProcessorMode_16bit,
};


enum error_code
{
    errorcode_noerror            = 0,
    errorcode_endoffile          = 1,
    errorcode_invalidinstruction = 2,
    errorcode_invalidcase        = 3,
    errorcode_count
};

struct bits_array_
{
    u32 Count;
    bits Base[32];
};

struct instruction_info_;

struct source_instruction_bits
{
	u32 count;
	bits buffer[32];
	memory_index i_info_index;
};

struct instruction_bits
{
	u32 count;	
	memory_index i_info_index;
	bits * base;
};

#define MAX_I_BITS_BUFFER 512
struct instruction_bits_buffer
{
	u32 count;
    instruction_bits * buffer;
	instruction_bits * first_free;
};



struct instruction_info_
{

    u32 OperandCount;
    operand_size OperandSizes[MAX_OPERAND_COUNT];
    operand_type OperandTypes[MAX_OPERAND_COUNT];
    
    u32 MnemonicCount;
    char MnemonicBuffer[MAX_BUFFER_SIZE];
    
    instruction_type Type;
    union
    {
        struct
        {
            memory_index TableOffset;
            memory_index TableEntryCount;
        };
        
        struct
        {
			b32 REP_Valid;
			b32 LOCK_Valid;
			b32 BranchHint_Valid;
            u32 InstructionOperandSize;
        };
    };
};


struct instruction_table_info_
{
    char MagicNum[MAGIC_SIZE];
    memory_index FileSize;
    
    
    memory_index BitsArraysOffset_16_;
	
	memory_index BitsCount_16;
	memory_index i_bits_header_offset_16;
	memory_index i_bits_bits_offset_16;
	
    memory_index BitsArraysOffset_32_;
    memory_index BitsCount_32;
	memory_index i_bits_header_offset_32;
	memory_index i_bits_bits_offset_32;
	
    memory_index BitsArraysOffset_64_;
    memory_index BitsCount_64;
	memory_index i_bits_header_offset_64;
	memory_index i_bits_bits_offset_64;
	
    memory_index InstructionCount_16;
    memory_index InstructionInfosOffset_16;
    memory_index InstructionCount_32;
    memory_index InstructionInfosOffset_32;
    memory_index InstructionCount_64;
    memory_index InstructionInfosOffset_64;
    
    //memory_index InstructionEntriesOffset;
    
    memory_index StringOffsetsCount;
    memory_index AssemblyGrammarsOffsets;
    memory_index ConditionalCodesOffsets;
    memory_index MODRMrm101Offsets;
    memory_index MODRM64ExtendedOffsets;
    memory_index MODRM64Offsets;
    memory_index MODRM32ExtendedOffsets;
    memory_index MODRM32Offsets;
    memory_index MODRM16Offsets;
    
    memory_index Basebase101Offsets;
    memory_index Base64ExtendedOffsets;
    memory_index Base64Offsets;
    memory_index Base32ExtendedOffsets;
    memory_index Base32Offsets;
    
    memory_index SS64ExtendedOffsets;
    memory_index SS64Offsets;
    memory_index SS32ExtendedOffsets;
    memory_index SS32Offsets;
    
    memory_index Reg64ExtendedOffsets;
    memory_index Reg64Offsets;
    memory_index Reg32ExtendedOffsets;
    memory_index Reg32Offsets;
    memory_index Reg16ExtendedOffsets;
    memory_index Reg16Offsets;
    
    memory_index Reg8ExtendedOffsets;
    memory_index Reg8REXPresentOffsets;
    memory_index Reg8Offsets;
    
    memory_index Reg_FP_Offsets;
    memory_index Reg_MMX_Offsets;
    memory_index Reg_XMM_Offsets;
    
	
	memory_index Reg_CR_Offsets;
    memory_index Reg_DR_Offsets;
    memory_index Reg_SREG_Offsets;
    memory_index Reg_TREG_Offsets;
	
    memory_index Reg_CX_Offsets;
    memory_index Reg_AX_Offsets;
    memory_index Reg_DX_Offsets;
    
	memory_index Mem_Operand_Size_KW_MASM_Offset;
	
    //TODO(Alex): These shouldnt be here!
    memory_index AbsoluteRelInstructionIndex;
    memory_index AbsoluteWriteByteIndexFile;
    memory_index AbsoluteReadByteIndexFile;
    memory_index AbsoluteReadBaseIndexFile;
    memory_index SentinelEncodingIndex;
    
};

struct lower_case_info
{
    char Name;
    
    union
    {
        struct
        {
            bits Bits;
        };
        struct
        {
            bits segment_selector;
            bits unsigned_offset;
        };
    };
};

enum token_type
{
    TokenType_Invalid,
    TokenType_Text,
    TokenType_ID,
};

struct instruction_context
{
	//TODO(Alex): Do we want an processor mode per instruction context?
	//u32 ProcessorMode;
	b32 OperandSizeOverridePrefixPresent;
	b32 AddressSizeOverridePrefixPresent;
	
	group2_prefix Group2Prefix; 
	group1_prefix Group1Prefix; 
	
	bits rex;
	
    //bits_array_ * BitsArrayPtr;
	bits_array_ * BitsArrayPtr;
    instruction_info_ * i_info;
	
	b32 InstructionFound;
};

struct addr_mode_info
{

};

struct string_ref 
{

};

struct disasm_state
{
    //TODO(Alex): Remove this!
    HANDLE STDOutHandle;
    
	
	b32 IsInitialized;
	memory_arena arena;     
	sub_arena i_match_arena;
	sub_arena i_write_arena;

	temp_memory work_temp_mem;
    //NOTE(Alex): instruction Bits Buffer 
    instruction_bits_buffer i_buffer;
	
    processor_mode ProcessorMode;
    
    u8 * start;
    u8 * end;
    u8 * cursor;
    u8 * baseframe;
    
    //NOTE(Alex): EXE Source BitBuffer
    u64 BitBuffer;
    u32 BitCount;
    
    
    u32 SecureByteCount;
    error_code errorcode;
    
	b32 TablesInitialized;
    void * FilePtrBase;
	memory_index instruction_bits_index_reader;
    memory_index BitsCount;
    memory_index InstructionCount;

    memory_index BitsArraysOffset_;
	memory_index i_bits_bits_offset;
	memory_index i_bits_header_offset;
	
    memory_index InstructionInfosOffset;
  
	instruction_table_info_ InstructionTableInfo;
    
};


internal u64 peekBits_noconsume_msb(disasm_state * State, u32 Count);

internal void consumeBits_msb(disasm_state * State, u32 Count);

//NOTE(Alex): Have BitCount bits on BitBuffer starting from LSB first the other bits are 0 
internal u64 GetBits_msb(disasm_state * State, u32 Count);

internal u64 peekBits_noconsume_lsb(disasm_state * State, u32 Count);

internal void consumeBits_lsb(disasm_state * State, u32 Count);

//NOTE(Alex): Have BitCount bits on BitBuffer starting from LSB first the other bits are 0 
internal u64 GetBits_lsb(disasm_state * State, u32 Count);

inline b32 TestBit(bits Bits, u32 Index);

#define EAGLEFLY_DECODER_H
#endif
