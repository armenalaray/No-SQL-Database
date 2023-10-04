//////////////////////////////////////////////////////
//
//Author: Alejandro Armenta 
//Date: 2019
//File: eflyfile_generator.h
//Company: 
//
//All rights reserved.
//
//////////////////////////////////////////////////////


#ifndef EFLYFILE_GENERATOR_H
#define EFLYFILE_GENERATOR_H


enum file_string_section_type
{
    StringSection_invalid = 0,
    
    StringSection_assembly_grammar,
    StringSection_conditional_codes,
    StringSection_modrm_rm101_grammars,
    StringSection_modrm_64_extended_grammars,
    StringSection_modrm_64_grammars,
    StringSection_modrm_32_extended_grammars,
    StringSection_modrm_32_grammars,
    StringSection_modrm_16_grammars,
    
    StringSection_base_base101_grammars,
    StringSection_base_64_extended_grammars,
    StringSection_base_64_grammars,
    StringSection_base_32_extended_grammars,
    StringSection_base_32_grammars,
    StringSection_ss_64_extended_grammars,
    StringSection_ss_64_grammars,
    StringSection_ss_32_extended_grammars,
    StringSection_ss_32_grammars,
    
    StringSection_reg_64_extended_grammars,
    StringSection_reg_64_grammars,
    StringSection_reg_32_extended_grammars,
    StringSection_reg_32_grammars,
    StringSection_reg_16_extended_grammars,
    StringSection_reg_16_grammars,
    StringSection_reg_8_extended_grammars,
    StringSection_reg_8_rex_present_grammars,
    StringSection_reg_8_grammars,
	
	StringSection_reg_fp_grammars,
	StringSection_reg_mmx_grammars,
	StringSection_reg_xmm_grammars,
    
	StringSection_reg_cr_grammars,
	StringSection_reg_dr_grammars,
	StringSection_reg_sreg_grammars,
	StringSection_reg_treg_grammars,
	
	StringSection_reg_cx_grammars,
	StringSection_reg_ax_grammars,
	StringSection_reg_dx_grammars,
	
	StringSection_mem_operand_size_kw_masm,
	
    StringSection_count,
    
};

enum file_section_type
{
    FileSection_Invalid = 0,
    
    FileSection_string,
    FileSection_instruction_info_16,
    FileSection_instruction_info_32,
    FileSection_instruction_info_64,
    
    FileSection_bits_16,
    FileSection_bits_32,
    FileSection_bits_64,
    
    FileSection_count,
};

struct operand_array
{
    u32 Count;
    operand_type TypesArray[MAX_OPERAND_COUNT];
    operand_size SizesArray[MAX_OPERAND_COUNT];
};

struct file_manager
{
    b32 IsInitialized;
    eflyfile_instruction_table_info * InstructionTableInfo;
    
    memory_arena FileArena;
    
    sub_arena BitsArraysArena_16_;
	sub_arena i_bits_header_arena_16;
	sub_arena i_bits_bits_arena_16;
    sub_arena InstructionInfosArena_16;
    
    sub_arena BitsArraysArena_32_;
	sub_arena i_bits_header_arena_32;
	sub_arena i_bits_bits_arena_32;
    sub_arena InstructionInfosArena_32;
    
    sub_arena BitsArraysArena_64_;
	sub_arena i_bits_header_arena_64;
	sub_arena i_bits_bits_arena_64;
    sub_arena InstructionInfosArena_64;
	
    sub_arena InstructionInfoEntriesArena;
    sub_arena StringOffsetsArena;
    sub_arena StringsArena;
	
	memory_index i_bits_h_count;
	memory_index i_bits_count;
	eff_instruction_bits_header * c_i_bits_h;    

    b32 SectionIsInitialized;
    file_section_type Type;
    eflyfile_instruction_info * ParentInfo;
};














#endif
