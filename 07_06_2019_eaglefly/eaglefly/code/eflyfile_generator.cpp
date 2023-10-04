//////////////////////////////////////////////////////
//
//Author: Alejandro Armenta 
//Date: 2019
//File: eflyfile_generator.cpp
//Company: 
//
//All rights reserved.
//
//////////////////////////////////////////////////////

//NOTE(Alex): Operand Array helper function

inline void
InitOperandArray(operand_array * OperandArray)
{
    OperandArray->Count = 0;
}

inline void
PushOperand(operand_array * OperandArray, u32 Type, u32 Size)
{
    Assert(OperandArray->Count < MAX_OPERAND_COUNT);
    
    u32 Index = OperandArray->Count++;
    
    operand_size * DestSize = OperandArray->SizesArray + Index;
    operand_type * DestType = OperandArray->TypesArray + Index;
    
    *DestSize = (operand_size)Size;
    *DestType = (operand_type)Type;
}


#if 0
internal memory_index
GetInstructionEntryOffset(file_manager * FileManager)
{
    memory_index Result = FileManager->InstructionTableInfo->InstructionEntriesOffset + FileManager->InstructionEntriesByteCount;
    return Result;
}


inline void * 
GetFilePtrAt_(file_manager * FileManager, memory_index Offset)
{
    void * Result = (u8 *)FileManager->FilePtrBase + Offset;
    return Result;
}

inline void * 
GetFileWriteCursor(file_manager * FileManager)
{
    void * Result = (u8 *)GetFilePtrAt_(FileManager, FileManager->FileByteCount);
    return Result;
}

inline void * 
GetInstructionEntryWriteCursor(file_manager * FileManager)
{
    memory_index Offset = GetInstructionEntryOffset(FileManager);
    void * Result = (u8 *)GetFilePtrAt_(FileManager, Offset);
    return Result;
}
#endif

inline memory_index
GetOffsetFromBase(file_manager * FileManager, void * Adress)
{
    memory_index Offset = (memory_index)(Adress) - (memory_index)FileManager->InstructionTableInfo;
    return Offset;
}

inline eff_bits BitsFile(u32 bits_count, u64 value, bitfield_type Type)
{
    eff_bits Result = {};
    
    Result.bits_count = bits_count;
    Result.value = value;
    Result.Type = Type;
    
    return Result;
}

inline eff_bits ZeroesFile(u32 N, bitfield_type Type)
{
    eff_bits Result = BitsFile(N, 0, Type);
    return Result;
}

inline eff_bits BitsIDFile(u32 N, u64 Value)
{
    eff_bits Result = BitsFile(N, Value, BitfieldType_id);
    return Result;
}


inline void
InitFileManager(file_manager * FileManager, void * Memory, memory_index BufferSize)
{
    Assert(!FileManager->IsInitialized);
    
    eflyfile_instruction_table_info * InstructionTableInfo = (eflyfile_instruction_table_info*)Memory;
    InitializeArena(&FileManager->FileArena, InstructionTableInfo + 1, BufferSize - sizeof(eflyfile_instruction_table_info));  
    
    SubArena(&FileManager->FileArena, &FileManager->i_bits_header_arena_16, Kilobytes(128));
    SubArena(&FileManager->FileArena, &FileManager->i_bits_bits_arena_16, Kilobytes(128));
    SubArena(&FileManager->FileArena, &FileManager->InstructionInfosArena_16, Megabytes(2));
    
    SubArena(&FileManager->FileArena, &FileManager->i_bits_header_arena_32, Kilobytes(128));
    SubArena(&FileManager->FileArena, &FileManager->i_bits_bits_arena_32, Kilobytes(128));
    SubArena(&FileManager->FileArena, &FileManager->InstructionInfosArena_32, Megabytes(2));
    
    SubArena(&FileManager->FileArena, &FileManager->i_bits_header_arena_64, Kilobytes(128));
    SubArena(&FileManager->FileArena, &FileManager->i_bits_bits_arena_64, Kilobytes(128));
    SubArena(&FileManager->FileArena, &FileManager->InstructionInfosArena_64, Megabytes(2));
    
    SubArena(&FileManager->FileArena, &FileManager->InstructionInfoEntriesArena, Megabytes(1));
    SubArena(&FileManager->FileArena, &FileManager->StringOffsetsArena, Kilobytes(16));
    SubArena(&FileManager->FileArena, &FileManager->StringsArena, Megabytes(1));
    
    FileManager->InstructionTableInfo = InstructionTableInfo;
    InstructionTableInfo->FileSize = FileManager->FileArena.Used + sizeof(eflyfile_instruction_table_info);
    
    char SourceMagic[MAGIC_SIZE] = {"Eaglefly_File_01"};
    u32 SourceMagicLength = StringLength(SourceMagic);
    u32 MagicNumCount = 0;
    Append(InstructionTableInfo->MagicNum, &MagicNumCount, MAGIC_SIZE, SourceMagic, SourceMagicLength);
    
    InstructionTableInfo->i_bits_header_offset_16 = GetOffsetFromBase(FileManager, FileManager->i_bits_header_arena_16.Arena.Base);
    InstructionTableInfo->i_bits_bits_offset_16 = GetOffsetFromBase(FileManager, FileManager->i_bits_bits_arena_16.Arena.Base);
    InstructionTableInfo->InstructionInfosOffset_16 = GetOffsetFromBase(FileManager, FileManager->InstructionInfosArena_16.Arena.Base);
	
	InstructionTableInfo->i_bits_header_offset_32 = GetOffsetFromBase(FileManager, FileManager->i_bits_header_arena_32.Arena.Base);
    InstructionTableInfo->i_bits_bits_offset_32 = GetOffsetFromBase(FileManager, FileManager->i_bits_bits_arena_32.Arena.Base);	
    InstructionTableInfo->InstructionInfosOffset_32 = GetOffsetFromBase(FileManager, FileManager->InstructionInfosArena_32.Arena.Base);
	
    InstructionTableInfo->i_bits_header_offset_64 = GetOffsetFromBase(FileManager, FileManager->i_bits_header_arena_64.Arena.Base);
    InstructionTableInfo->i_bits_bits_offset_64 = GetOffsetFromBase(FileManager, FileManager->i_bits_bits_arena_64.Arena.Base);
    InstructionTableInfo->InstructionInfosOffset_64 = GetOffsetFromBase(FileManager, FileManager->InstructionInfosArena_64.Arena.Base);
	
    FileManager->i_bits_h_count = 0;
	FileManager->i_bits_count = 0;
    FileManager->IsInitialized = true;
}


inline void
BeginFileSection(file_manager * FileManager, file_section_type FileSectionType)
{
    Assert(FileManager->IsInitialized);
    Assert(!FileManager->SectionIsInitialized);
    FileManager->SectionIsInitialized = true;
    FileManager->Type = FileSectionType;
}

internal void 
EndFileSection(file_manager * FileManager)
{
    Assert(FileManager->SectionIsInitialized);
    switch(FileManager->Type)
    {
        case FileSection_string:
        {
            FileManager->InstructionTableInfo->StringOffsetsCount = (FileManager->StringOffsetsArena.Arena.Used / sizeof(memory_index));
        }break;
        
        case FileSection_instruction_info_16:
        {
            FileManager->InstructionTableInfo->InstructionCount_16 = (FileManager->InstructionInfosArena_16.Arena.Used / sizeof(eflyfile_instruction_info));
        }break;
        
        case FileSection_instruction_info_32:
        {
            FileManager->InstructionTableInfo->InstructionCount_32 = (FileManager->InstructionInfosArena_32.Arena.Used / sizeof(eflyfile_instruction_info));
        }break;
        
        case FileSection_instruction_info_64:
        {
            FileManager->InstructionTableInfo->InstructionCount_64 = (FileManager->InstructionInfosArena_64.Arena.Used / sizeof(eflyfile_instruction_info));
        }break;
        
        case FileSection_bits_16:
        {
            FileManager->InstructionTableInfo->BitsCount_16 = FileManager->i_bits_count;//(FileManager->BitsArraysArena_16.Arena.Used / sizeof(eff_bits));
        }break;
        
        case FileSection_bits_32:
        {
            FileManager->InstructionTableInfo->BitsCount_32 = FileManager->i_bits_count;//(FileManager->BitsArraysArena_32.Arena.Used / sizeof(eff_bits));
        }break;
        
        case FileSection_bits_64:
        {
            FileManager->InstructionTableInfo->BitsCount_64 = FileManager->i_bits_count;//(FileManager->BitsArraysArena_64.Arena.Used / sizeof(eff_bits));
        }break;
        
        InvalidDefaultCase;
    }
	
    FileManager->i_bits_h_count = 0; 
	FileManager->i_bits_count = 0;
    FileManager->SectionIsInitialized = false;
}

inline void
FillInstructionInfo(file_manager * FileManager, eflyfile_instruction_info * InstructionInfo, instruction_type Type, char * Mnemonic, u32 MnemonicSize, u32 OperandCount,  u32 * OperandTypesArray, u32 * OperandSizesArray, b32 REP_Valid,  b32 LOCK_Valid, b32 BranchHint_Valid)
{
    Assert((OperandCount >= 0) && (OperandCount <= MAX_OPERAND_COUNT) && InstructionInfo);
    
    InstructionInfo->Type = Type;
    InstructionInfo->OperandCount = OperandCount;
    
    Append(InstructionInfo->MnemonicBuffer, &InstructionInfo->MnemonicCount, MAX_BUFFER_SIZE, Mnemonic, MnemonicSize);
    
    for(u32 Index = 0;
        Index < OperandCount;
        ++Index)
    {
        operand_size * DestSize = InstructionInfo->OperandSizes + Index;
        operand_type * DestType = InstructionInfo->OperandTypes + Index;
        operand_size * SourceSize = (operand_size *)OperandSizesArray + Index;
        operand_type * SourceType = (operand_type *)OperandTypesArray + Index;
        
        *DestSize = *SourceSize;
        *DestType = *SourceType;
    }
    
	
	if(Type != InstructionType_Group)
	{
		InstructionInfo->REP_Valid = REP_Valid;
		InstructionInfo->LOCK_Valid = LOCK_Valid;
		InstructionInfo->BranchHint_Valid = BranchHint_Valid;
	}
    
}

inline eflyfile_instruction_info * 
PushInstructionInfo_(file_manager * FileManager)
{
    eflyfile_instruction_info * InstructionInfo = 0;
    switch(FileManager->Type)
    {
        case FileSection_instruction_info_16:
        {
            InstructionInfo = (eflyfile_instruction_info *)PushStruct(&FileManager->InstructionInfosArena_16.Arena, eflyfile_instruction_info);
        }break;
        
        case FileSection_instruction_info_32:
        {
            InstructionInfo = (eflyfile_instruction_info *)PushStruct(&FileManager->InstructionInfosArena_32.Arena, eflyfile_instruction_info);
        }break;
        
        case FileSection_instruction_info_64:
        {
            InstructionInfo = (eflyfile_instruction_info *)PushStruct(&FileManager->InstructionInfosArena_64.Arena, eflyfile_instruction_info);
        }break;
        
        InvalidDefaultCase;
    }
    
    return InstructionInfo;
}

internal eflyfile_instruction_info *
PushInstructionEntry_(file_manager * FileManager)
{
    eflyfile_instruction_info * InstructionInfo = (eflyfile_instruction_info*)PushStruct(&FileManager->InstructionInfoEntriesArena.Arena, eflyfile_instruction_info);
    return InstructionInfo;
}


internal void 
PushInstructionInfo(file_manager * FileManager, char * Mnemonic, u32 OperandCount,  u32 * OperandTypesArray, u32 * OperandSizesArray, b32 REP_Valid, b32 LOCK_Valid, b32 BranchHint_Valid)
{
    Assert(!FileManager->ParentInfo && Mnemonic);
    u32 MnemonicSize = StringLength(Mnemonic);
    eflyfile_instruction_info * InstructionInfo = PushInstructionInfo_(FileManager);
    FillInstructionInfo(FileManager, InstructionInfo, InstructionType_Normal, Mnemonic, MnemonicSize, OperandCount,  OperandTypesArray, OperandSizesArray, REP_Valid, LOCK_Valid, BranchHint_Valid);
}


internal void 
PushInstructionInfoEntry(file_manager * FileManager, char * Mnemonic, u32 InstructionOperandSize, u32 OperandCount,  u32 * OperandTypesArray, u32 * OperandSizesArray, b32 REP_Valid, b32 LOCK_Valid, b32 BranchHint_Valid)
{
    Assert(FileManager->ParentInfo && Mnemonic);
    u32 MnemonicSize = StringLength(Mnemonic);
    ++FileManager->ParentInfo->TableEntryCount;
   
    eflyfile_instruction_info * InstructionInfo = PushInstructionEntry_(FileManager);
    FillInstructionInfo(FileManager, InstructionInfo, InstructionType_Entry, Mnemonic, MnemonicSize, OperandCount,  OperandTypesArray, OperandSizesArray, REP_Valid, LOCK_Valid, BranchHint_Valid);
    
    InstructionInfo->InstructionOperandSize = InstructionOperandSize; 
}

internal void
BeginInstructionInfoGroup(file_manager * FileManager,  char * Mnemonic, u32 OperandCount,  u32 * OperandTypesArray, u32 * OperandSizesArray, b32 REP_Valid, b32 LOCK_Valid, b32 BranchHint_Valid)
{
    Assert(!FileManager->ParentInfo && Mnemonic);
    u32 MnemonicSize = StringLength(Mnemonic);
    
    eflyfile_instruction_info * InstructionInfo = PushInstructionInfo_(FileManager);
    FillInstructionInfo(FileManager, InstructionInfo, InstructionType_Group, Mnemonic, MnemonicSize, OperandCount,  OperandTypesArray, OperandSizesArray, REP_Valid, LOCK_Valid, BranchHint_Valid);
    
    InstructionInfo->TableEntryCount = 0;
    InstructionInfo->TableOffset = GetOffsetFromBase(FileManager, (u8*)FileManager->InstructionInfoEntriesArena.Arena.Base + FileManager->InstructionInfoEntriesArena.Arena.Used);
    
    FileManager->ParentInfo = InstructionInfo;
}

internal void
EndInstructionInfoGroup(file_manager * FileManager)
{
	Assert(FileManager->ParentInfo);
    FileManager->ParentInfo = 0;
}

//NOTE(Alex): instruction_bits functions

inline void
BeginInstructionBits(file_manager * FileManager)
{
	Assert(FileManager->c_i_bits_h == 0);
	
	sub_arena * SubArena = 0;
	switch(FileManager->Type)
	{
		case FileSection_bits_16:
        {
            SubArena = &FileManager->i_bits_header_arena_16;
        }break;
        
        case FileSection_bits_32:
        {
            SubArena = &FileManager->i_bits_header_arena_32;
        }break;
        
        case FileSection_bits_64:
        {
            SubArena = &FileManager->i_bits_header_arena_64;
        }break;
        
        InvalidDefaultCase;		
	}
	
	
	eff_instruction_bits_header * n_h = PushStruct(&SubArena->Arena, eff_instruction_bits_header);
	n_h->i_info_index = FileManager->i_bits_h_count++;
	n_h->first_bits_index = FileManager->i_bits_count;
	
	FileManager->c_i_bits_h = n_h;

}

inline void 
CopyBitsToFile(file_manager * FileManager, eff_bits Source)
{
	Assert(FileManager->c_i_bits_h);
	
    sub_arena * SubArena = 0;
    switch(FileManager->Type)
    {
        case FileSection_bits_16:
        {
            SubArena = &FileManager->i_bits_bits_arena_16;
        }break;
        
        case FileSection_bits_32:
        {
            SubArena = &FileManager->i_bits_bits_arena_32;
        }break;
        
        case FileSection_bits_64:
        {
            SubArena = &FileManager->i_bits_bits_arena_64;
        }break;
        
        InvalidDefaultCase;
    }
	
	eff_instruction_bits_header * n_h = FileManager->c_i_bits_h;
	n_h->count++;
    
    eff_bits * Dest = (eff_bits*)PushStruct(&SubArena->Arena, eff_bits);
    Dest->Type = Source.Type;
    Dest->bits_count = Source.bits_count;
    Dest->value = Source.value;
	
	FileManager->i_bits_count++;
}

inline void 
EndInstructionBits(file_manager * FileManager)
{
	Assert(FileManager->c_i_bits_h);
	FileManager->c_i_bits_h = 0;
}


inline void
StartFileStringSection(file_manager * FileManager , file_string_section_type StringType)
{
    switch(StringType)
    {
        case StringSection_assembly_grammar:
        {
            FileManager->InstructionTableInfo->AssemblyGrammarsOffsets = GetOffsetFromBase(FileManager, (u8*)FileManager->StringOffsetsArena.Arena.Base + FileManager->StringOffsetsArena.Arena.Used);
        }break;
        case StringSection_conditional_codes:
        {
            FileManager->InstructionTableInfo->ConditionalCodesOffsets = GetOffsetFromBase(FileManager, (u8*)FileManager->StringOffsetsArena.Arena.Base + FileManager->StringOffsetsArena.Arena.Used);
        }break;
        case StringSection_modrm_rm101_grammars:
        {
            FileManager->InstructionTableInfo->MODRMrm101Offsets = GetOffsetFromBase(FileManager, (u8*)FileManager->StringOffsetsArena.Arena.Base + FileManager->StringOffsetsArena.Arena.Used);
        }break;
        
        case StringSection_modrm_64_extended_grammars:
        {
            FileManager->InstructionTableInfo->MODRM64ExtendedOffsets = GetOffsetFromBase(FileManager, (u8*)FileManager->StringOffsetsArena.Arena.Base + FileManager->StringOffsetsArena.Arena.Used);
        }break;
        
        case StringSection_modrm_64_grammars:
        {
            FileManager->InstructionTableInfo->MODRM64Offsets = GetOffsetFromBase(FileManager, (u8*)FileManager->StringOffsetsArena.Arena.Base + FileManager->StringOffsetsArena.Arena.Used);
        }break;
        
        case StringSection_modrm_32_extended_grammars:
        {
            FileManager->InstructionTableInfo->MODRM32ExtendedOffsets = GetOffsetFromBase(FileManager, (u8*)FileManager->StringOffsetsArena.Arena.Base + FileManager->StringOffsetsArena.Arena.Used);
        }break;
        
        case StringSection_modrm_32_grammars:
        {
            FileManager->InstructionTableInfo->MODRM32Offsets = GetOffsetFromBase(FileManager, (u8*)FileManager->StringOffsetsArena.Arena.Base + FileManager->StringOffsetsArena.Arena.Used);
        }break;
        
        case StringSection_modrm_16_grammars:
        {
            FileManager->InstructionTableInfo->MODRM16Offsets = GetOffsetFromBase(FileManager, (u8*)FileManager->StringOffsetsArena.Arena.Base + FileManager->StringOffsetsArena.Arena.Used);
        }break;
        
        
        case StringSection_base_base101_grammars:
        {
            FileManager->InstructionTableInfo->Basebase101Offsets = GetOffsetFromBase(FileManager, (u8*)FileManager->StringOffsetsArena.Arena.Base + FileManager->StringOffsetsArena.Arena.Used);
        }break;
        
        case StringSection_base_64_extended_grammars:
        {
            FileManager->InstructionTableInfo->Base64ExtendedOffsets = GetOffsetFromBase(FileManager, (u8*)FileManager->StringOffsetsArena.Arena.Base + FileManager->StringOffsetsArena.Arena.Used);
        }break;
        
        case StringSection_base_64_grammars:
        {
            FileManager->InstructionTableInfo->Base64Offsets = GetOffsetFromBase(FileManager, (u8*)FileManager->StringOffsetsArena.Arena.Base + FileManager->StringOffsetsArena.Arena.Used);
        }break;
        
        case StringSection_base_32_extended_grammars:
        {
            FileManager->InstructionTableInfo->Base32ExtendedOffsets = GetOffsetFromBase(FileManager, (u8*)FileManager->StringOffsetsArena.Arena.Base + FileManager->StringOffsetsArena.Arena.Used);
        }break;
        
        case StringSection_base_32_grammars:
        {
            FileManager->InstructionTableInfo->Base32Offsets = GetOffsetFromBase(FileManager, (u8*)FileManager->StringOffsetsArena.Arena.Base + FileManager->StringOffsetsArena.Arena.Used);
        }break;
        
        case StringSection_ss_64_extended_grammars:
        {
            FileManager->InstructionTableInfo->SS64ExtendedOffsets = GetOffsetFromBase(FileManager, (u8*)FileManager->StringOffsetsArena.Arena.Base + FileManager->StringOffsetsArena.Arena.Used);
        }break;
        
        case StringSection_ss_64_grammars:
        {
            FileManager->InstructionTableInfo->SS64Offsets = GetOffsetFromBase(FileManager, (u8*)FileManager->StringOffsetsArena.Arena.Base + FileManager->StringOffsetsArena.Arena.Used);
        }break;
        
        case StringSection_ss_32_extended_grammars:
        {
            FileManager->InstructionTableInfo->SS32ExtendedOffsets = GetOffsetFromBase(FileManager, (u8*)FileManager->StringOffsetsArena.Arena.Base + FileManager->StringOffsetsArena.Arena.Used);
        }break;
        
        case StringSection_ss_32_grammars:
        {
            FileManager->InstructionTableInfo->SS32Offsets = GetOffsetFromBase(FileManager, (u8*)FileManager->StringOffsetsArena.Arena.Base + FileManager->StringOffsetsArena.Arena.Used);
            
        }break;
        
        
        case StringSection_reg_64_extended_grammars:
        {
            FileManager->InstructionTableInfo->Reg64ExtendedOffsets = GetOffsetFromBase(FileManager, (u8*)FileManager->StringOffsetsArena.Arena.Base + FileManager->StringOffsetsArena.Arena.Used);
        }break;
        
        case StringSection_reg_64_grammars:
        {
            FileManager->InstructionTableInfo->Reg64Offsets = GetOffsetFromBase(FileManager, (u8*)FileManager->StringOffsetsArena.Arena.Base + FileManager->StringOffsetsArena.Arena.Used);
        }break;
        
        case StringSection_reg_32_extended_grammars:
        {
            FileManager->InstructionTableInfo->Reg32ExtendedOffsets = GetOffsetFromBase(FileManager, (u8*)FileManager->StringOffsetsArena.Arena.Base + FileManager->StringOffsetsArena.Arena.Used);
        }break;
        
        case StringSection_reg_32_grammars:
        {
            FileManager->InstructionTableInfo->Reg32Offsets = GetOffsetFromBase(FileManager, (u8*)FileManager->StringOffsetsArena.Arena.Base + FileManager->StringOffsetsArena.Arena.Used);
        }break;
        
        case StringSection_reg_16_extended_grammars:
        {
            FileManager->InstructionTableInfo->Reg16ExtendedOffsets = GetOffsetFromBase(FileManager, (u8*)FileManager->StringOffsetsArena.Arena.Base + FileManager->StringOffsetsArena.Arena.Used);
        }break;
        
        case StringSection_reg_16_grammars:
        {
            FileManager->InstructionTableInfo->Reg16Offsets = GetOffsetFromBase(FileManager, (u8*)FileManager->StringOffsetsArena.Arena.Base + FileManager->StringOffsetsArena.Arena.Used);
        }break;
        
        case StringSection_reg_8_extended_grammars:
        {
            FileManager->InstructionTableInfo->Reg8ExtendedOffsets = GetOffsetFromBase(FileManager, (u8*)FileManager->StringOffsetsArena.Arena.Base + FileManager->StringOffsetsArena.Arena.Used);
        }break;
        
        case StringSection_reg_8_rex_present_grammars:
        {
            FileManager->InstructionTableInfo->Reg8REXPresentOffsets = GetOffsetFromBase(FileManager, (u8*)FileManager->StringOffsetsArena.Arena.Base + FileManager->StringOffsetsArena.Arena.Used);
        }break;
        
        case StringSection_reg_8_grammars:
        {
            FileManager->InstructionTableInfo->Reg8Offsets = GetOffsetFromBase(FileManager, (u8*)FileManager->StringOffsetsArena.Arena.Base + FileManager->StringOffsetsArena.Arena.Used);
        }break;
		
        case StringSection_reg_fp_grammars:
        {
            FileManager->InstructionTableInfo->Reg_FP_Offsets = GetOffsetFromBase(FileManager, (u8*)FileManager->StringOffsetsArena.Arena.Base + FileManager->StringOffsetsArena.Arena.Used);
        }break;
		
        case StringSection_reg_mmx_grammars:
        {
            FileManager->InstructionTableInfo->Reg_MMX_Offsets = GetOffsetFromBase(FileManager, (u8*)FileManager->StringOffsetsArena.Arena.Base + FileManager->StringOffsetsArena.Arena.Used);
        }break;
		
        case StringSection_reg_xmm_grammars:
        {
            FileManager->InstructionTableInfo->Reg_XMM_Offsets = GetOffsetFromBase(FileManager, (u8*)FileManager->StringOffsetsArena.Arena.Base + FileManager->StringOffsetsArena.Arena.Used);
        }break;

        case StringSection_reg_cr_grammars:
        {
            FileManager->InstructionTableInfo->Reg_CR_Offsets = GetOffsetFromBase(FileManager, (u8*)FileManager->StringOffsetsArena.Arena.Base + FileManager->StringOffsetsArena.Arena.Used);
        }break;

        case StringSection_reg_dr_grammars:
        {
            FileManager->InstructionTableInfo->Reg_DR_Offsets = GetOffsetFromBase(FileManager, (u8*)FileManager->StringOffsetsArena.Arena.Base + FileManager->StringOffsetsArena.Arena.Used);
        }break;
        
		case StringSection_reg_sreg_grammars:
        {
            FileManager->InstructionTableInfo->Reg_SREG_Offsets = GetOffsetFromBase(FileManager, (u8*)FileManager->StringOffsetsArena.Arena.Base + FileManager->StringOffsetsArena.Arena.Used);
        }break;
        
		case StringSection_reg_treg_grammars:
        {
            FileManager->InstructionTableInfo->Reg_TREG_Offsets = GetOffsetFromBase(FileManager, (u8*)FileManager->StringOffsetsArena.Arena.Base + FileManager->StringOffsetsArena.Arena.Used);
        }break;
        
		case StringSection_reg_cx_grammars:
        {
            FileManager->InstructionTableInfo->Reg_CX_Offsets = GetOffsetFromBase(FileManager, (u8*)FileManager->StringOffsetsArena.Arena.Base + FileManager->StringOffsetsArena.Arena.Used);
        }break;
        
		case StringSection_reg_ax_grammars:
        {
            FileManager->InstructionTableInfo->Reg_AX_Offsets = GetOffsetFromBase(FileManager, (u8*)FileManager->StringOffsetsArena.Arena.Base + FileManager->StringOffsetsArena.Arena.Used);
        }break;
        
		case StringSection_reg_dx_grammars:
        {
            FileManager->InstructionTableInfo->Reg_DX_Offsets = GetOffsetFromBase(FileManager, (u8*)FileManager->StringOffsetsArena.Arena.Base + FileManager->StringOffsetsArena.Arena.Used);
        }break;
        
		case StringSection_mem_operand_size_kw_masm:
        {
            FileManager->InstructionTableInfo->Mem_Operand_Size_KW_MASM_Offset = GetOffsetFromBase(FileManager, (u8*)FileManager->StringOffsetsArena.Arena.Base + FileManager->StringOffsetsArena.Arena.Used);
        }break;
        
        InvalidDefaultCase;
    }
}


inline void 
PushStringToFile(file_manager * FileManager, char * StringSource)
{
    memory_index * StringOffset = PushStruct(&FileManager->StringOffsetsArena.Arena, memory_index);
    u32 StringSourceSize = StringLength(StringSource);
    u32 StringDestSize = StringSourceSize + 1;
    
    char * StringDest = PushString(&FileManager->StringsArena.Arena, StringDestSize, char);
    u32 StringDestCount = 0;
    Append(StringDest, &StringDestCount, StringDestSize, StringSource, StringSourceSize);
    
    *StringOffset = GetOffsetFromBase(FileManager, StringDest);
}












