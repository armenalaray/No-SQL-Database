//////////////////////////////////////////////////////
//
//Author: Alejandro Armenta 
//Date: 2019
//File: instruction_table_info.h
//Company: 
//
//All rights reserved.
//
//////////////////////////////////////////////////////

#ifndef INSTRUCTION_TABLE_INFO_H
#define INSTRUCTION_TABLE_INFO_H

#define MAGIC_SIZE 32

#pragma pack(push,1)

enum bitfield_type
{
    BitfieldType_null = 0,
    BitfieldType_ss,
    BitfieldType_index,
    BitfieldType_base,
    BitfieldType_mod,
    BitfieldType_reg,
    BitfieldType_rm,
    BitfieldType_tttn,
    BitfieldType_eee,
    BitfieldType_sreg2,
    BitfieldType_sreg3,
    BitfieldType_s,
    BitfieldType_w,
    
    BitfieldType_low_rex,
    BitfieldType_disp8,
    BitfieldType_full_displacement,
    
    BitfieldType_imm8,
    BitfieldType_imm16,
    BitfieldType_imm32,
    BitfieldType_imm64,
    
    BitfieldType_immediate_data,
    
    BitfieldType_id,
    BitfieldType_unasigned,
    BitfieldType_count,
};

enum operand_type
{
    OperandType_Invalid,
    OperandType_A,
    OperandType_BA,
    OperandType_BB,
    OperandType_BD,
    OperandType_C,
    OperandType_D,
    OperandType_E,
    OperandType_ES,
    OperandType_EST,
    OperandType_F,
    OperandType_G,
    OperandType_H,
    OperandType_I,
    OperandType_J,
    OperandType_M,
    OperandType_N,
    OperandType_O,
    OperandType_P,
    OperandType_Q,
    OperandType_R,
    OperandType_S,
    OperandType_SC,
    OperandType_T,
    OperandType_U,
    OperandType_V,
    OperandType_W,
    OperandType_X,
    OperandType_Y,
    OperandType_Z,
    
    OperandType_S2_,
    OperandType_S30_,
    OperandType_S33_,
	
	//NOTE(Alex): This are used as immediate data types
	OperandType_3,    
	OperandType_1,    
	

	OperandType_GSEG,
	OperandType_FSEG,
	OperandType_ESEG,
	OperandType_DSEG,
	OperandType_SSEG,
	OperandType_CSEG,

    //NOTE(Alex): This are explicit registers
    
    //NOTE(Alex): this is for Operand type rAX
    OperandType_AX,
    OperandType_CX,
    OperandType_DX,
    OperandType_ST,  
    
    //NOTE(Alex): Special for opcode groups that don't have any operand type
    OperandType_GR,
    
    
    
    OperandType_Count,
    
};

enum operand_size
{
    OperandSize_Invalid = 0,
    
    //NOTE(Alex): Operand size attribute dependent
    OperandSize_a,
    OperandSize_b,
    OperandSize_bcd,
    OperandSize_bs,
    OperandSize_bsq,
    OperandSize_bss,
    OperandSize_c,
    OperandSize_d,
    OperandSize_di,
    OperandSize_dq,
    OperandSize_dqp,
    OperandSize_dr,
    OperandSize_ds,
    OperandSize_e,
    OperandSize_er,
    OperandSize_p,
    OperandSize_pi,
    OperandSize_pd,
    OperandSize_ps,
    OperandSize_psq,
    OperandSize_pt,
    OperandSize_ptp,
    OperandSize_q,
    OperandSize_qi,
    OperandSize_qp,
    OperandSize_s,
    OperandSize_sd,
    OperandSize_si,
    OperandSize_sr,
    OperandSize_ss,
    OperandSize_st,
    OperandSize_stx,
    OperandSize_t,
    OperandSize_v,
    OperandSize_vds,
    OperandSize_vq,
    OperandSize_vqp,
    OperandSize_vs,
    OperandSize_w,
    OperandSize_wi,
    
    //NOTE(Alex): Address size attribute dependent
    OperandSize_va,
    OperandSize_dqa,
    OperandSize_wa,
    OperandSize_wo,
    OperandSize_ws,
    OperandSize_da,
    OperandSize_do,
    OperandSize_qa,
    OperandSize_qs,
    
    //NOTE(Alex): OperandSize_f Special one for PUSHF & POPF opcode groups 
    //if on 64 bit mode defaults to 64 bit operand size attr. 
    //if on 64 bit mode operand size prefix - 16 bit operand size attr.
    //if on 32 bit mode or 16 bit mode depends on operand size attr.
    
    OperandSize_f,
    
    //NOTE(Alex): OperandSize_cxz Special one for JCXZ instrucitions opcode group
    //64/32/16 depends on address size attr.
    
    OperandSize_cxz,
    
    OperandSize_Count,
    
};


struct eff_bits
{
    //NOTE(Alex): We treat each Value as a huge Little endian - LSB 64-bit unsigned integer
    bitfield_type Type;
    u32 bits_count;
    u64 value;
};

struct eff_instruction_bits_header
{
	
	u32 count;
	memory_index i_info_index;
	memory_index first_bits_index;
	
};

enum instruction_type
{
    InstructionType_Invalid,
    InstructionType_Normal,
    InstructionType_Group,
    InstructionType_Entry,
    InstructionType_Count,
};


struct grammar_entry 
{
    u32 OperandSize;
    memory_index GrammarOffset;
};

//TODO(Alex): Do we want a general instruction operand size ? moffsets
struct eflyfile_instruction_info
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

struct eflyfile_instruction_bits
{
	//TODO(Alex): Fill this structure!
};

struct eflyfile_instruction_table_info
{
    char MagicNum[MAGIC_SIZE];
    memory_index FileSize;
    
    memory_index BitsArraysOffset_16_;
    memory_index BitsCount_16;
	memory_index i_bits_bits_offset_16;
	memory_index i_bits_header_offset_16;
	
    memory_index BitsArraysOffset_32_;
    memory_index BitsCount_32;
	memory_index i_bits_bits_offset_32;
	memory_index i_bits_header_offset_32;
	
    memory_index BitsArraysOffset_64_;
    memory_index BitsCount_64;
	memory_index i_bits_bits_offset_64;
	memory_index i_bits_header_offset_64;
	
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

#pragma pack(pop)





#endif



