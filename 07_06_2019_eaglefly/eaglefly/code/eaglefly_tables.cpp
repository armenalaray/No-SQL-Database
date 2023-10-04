//////////////////////////////////////////////////////
//
//Author: Alejandro Armenta 
//Date: 2019
//File: eaglefly_tables.cpp
//Company: 
//
//All rights reserved.
//
//////////////////////////////////////////////////////


//NOTE(Alex): bits_array functions

inline void * 
GetFilePointerFromBase(disasm_state * State, memory_index Offset)
{
    void * Result = (void*)((char*)State->FilePtrBase + Offset);
    return Result;
}

inline memory_index * 
GetAssemblyGrammarsOffsetsBase(disasm_state * State, instruction_table_info_ * InstructionTableInfo)
{
    memory_index Offset = InstructionTableInfo->AssemblyGrammarsOffsets;
    memory_index * Result = (memory_index *)GetFilePointerFromBase(State, Offset);
    return Result;
}


inline eflyfile_instruction_info * 
GetInstructionInfoBase(disasm_state * State, instruction_table_info_ * InstructionTableInfo)
{
    eflyfile_instruction_info * Result = (eflyfile_instruction_info *)GetFilePointerFromBase(State, State->InstructionInfosOffset);
    return Result;
}


inline eflyfile_instruction_info * 
GetInstructionEntryBase(disasm_state * State, instruction_info_ * InstructionInfo)
{
    eflyfile_instruction_info * Result = (eflyfile_instruction_info *)GetFilePointerFromBase(State, InstructionInfo->TableOffset);
    return Result;
}

internal void 
CopyEflyFileInstructionTableInfo(instruction_table_info_ * DestTableInfo, eflyfile_instruction_table_info * SourceTableInfo)
{
    //NOTE(Alex) We didnt copy Magic Number !!
    
    DestTableInfo->FileSize = SourceTableInfo->FileSize;
    
    DestTableInfo->BitsCount_16 = SourceTableInfo->BitsCount_16;
    DestTableInfo->i_bits_header_offset_16 = SourceTableInfo->i_bits_header_offset_16;
    DestTableInfo->i_bits_bits_offset_16 = SourceTableInfo->i_bits_bits_offset_16;
    DestTableInfo->InstructionCount_16 = SourceTableInfo->InstructionCount_16;
    DestTableInfo->InstructionInfosOffset_16 = SourceTableInfo->InstructionInfosOffset_16;
    
    DestTableInfo->BitsCount_32 = SourceTableInfo->BitsCount_32;
    DestTableInfo->i_bits_header_offset_32 = SourceTableInfo->i_bits_header_offset_32;
    DestTableInfo->i_bits_bits_offset_32 = SourceTableInfo->i_bits_bits_offset_32;
    DestTableInfo->InstructionCount_32 = SourceTableInfo->InstructionCount_32;
    DestTableInfo->InstructionInfosOffset_32 = SourceTableInfo->InstructionInfosOffset_32;
    
    DestTableInfo->BitsCount_64 = SourceTableInfo->BitsCount_64;
    DestTableInfo->i_bits_header_offset_64 = SourceTableInfo->i_bits_header_offset_64;
    DestTableInfo->i_bits_bits_offset_64 = SourceTableInfo->i_bits_bits_offset_64;
    DestTableInfo->InstructionCount_64 = SourceTableInfo->InstructionCount_64;
    DestTableInfo->InstructionInfosOffset_64 = SourceTableInfo->InstructionInfosOffset_64;
    
    //memory_index InstructionEntriesOffset = ;
    
    DestTableInfo->StringOffsetsCount = SourceTableInfo->StringOffsetsCount;
    DestTableInfo->AssemblyGrammarsOffsets = SourceTableInfo->AssemblyGrammarsOffsets;
    DestTableInfo->ConditionalCodesOffsets = SourceTableInfo->ConditionalCodesOffsets;
    DestTableInfo->MODRMrm101Offsets = SourceTableInfo->MODRMrm101Offsets;
    DestTableInfo->MODRM64ExtendedOffsets = SourceTableInfo->MODRM64ExtendedOffsets;
    
    DestTableInfo->MODRM64Offsets = SourceTableInfo->MODRM64Offsets;
    DestTableInfo->MODRM32ExtendedOffsets = SourceTableInfo->MODRM32ExtendedOffsets;
    DestTableInfo->MODRM32Offsets = SourceTableInfo->MODRM32Offsets;
    DestTableInfo->MODRM16Offsets = SourceTableInfo->MODRM16Offsets;
    
    DestTableInfo->Basebase101Offsets = SourceTableInfo->Basebase101Offsets;
    DestTableInfo->Base64ExtendedOffsets = SourceTableInfo->Base64ExtendedOffsets;
    DestTableInfo->Base64Offsets = SourceTableInfo->Base64Offsets;
    DestTableInfo->Base32ExtendedOffsets = SourceTableInfo->Base32ExtendedOffsets;
    DestTableInfo->Base32Offsets = SourceTableInfo->Base32Offsets;
    
    DestTableInfo->SS64ExtendedOffsets = SourceTableInfo->SS64ExtendedOffsets;
    DestTableInfo->SS64Offsets = SourceTableInfo->SS64Offsets;
    DestTableInfo->SS32ExtendedOffsets = SourceTableInfo->SS32ExtendedOffsets;
    DestTableInfo->SS32Offsets = SourceTableInfo->SS32Offsets;
    
    DestTableInfo->Reg64ExtendedOffsets = SourceTableInfo->Reg64ExtendedOffsets;
    DestTableInfo->Reg64Offsets = SourceTableInfo->Reg64Offsets;
    DestTableInfo->Reg32ExtendedOffsets = SourceTableInfo->Reg32ExtendedOffsets;
    DestTableInfo->Reg32Offsets = SourceTableInfo->Reg32Offsets;
    DestTableInfo->Reg16ExtendedOffsets = SourceTableInfo->Reg16ExtendedOffsets;
    DestTableInfo->Reg16Offsets = SourceTableInfo->Reg16Offsets;
    
    DestTableInfo->Reg8ExtendedOffsets = SourceTableInfo->Reg8ExtendedOffsets;
    DestTableInfo->Reg8REXPresentOffsets = SourceTableInfo->Reg8REXPresentOffsets;
    DestTableInfo->Reg8Offsets = SourceTableInfo->Reg8Offsets;
	
	
    DestTableInfo->Reg_FP_Offsets = SourceTableInfo->Reg_FP_Offsets;
    DestTableInfo->Reg_MMX_Offsets = SourceTableInfo->Reg_MMX_Offsets;
    DestTableInfo->Reg_XMM_Offsets = SourceTableInfo->Reg_XMM_Offsets;
    
	DestTableInfo->Reg_CR_Offsets = SourceTableInfo->Reg_CR_Offsets;
    DestTableInfo->Reg_DR_Offsets = SourceTableInfo->Reg_DR_Offsets;
    DestTableInfo->Reg_SREG_Offsets = SourceTableInfo->Reg_SREG_Offsets;
    DestTableInfo->Reg_TREG_Offsets = SourceTableInfo->Reg_TREG_Offsets;
	
    DestTableInfo->Reg_CX_Offsets = SourceTableInfo->Reg_CX_Offsets;
    DestTableInfo->Reg_AX_Offsets = SourceTableInfo->Reg_AX_Offsets;
    DestTableInfo->Reg_DX_Offsets = SourceTableInfo->Reg_DX_Offsets;
	
	DestTableInfo->Mem_Operand_Size_KW_MASM_Offset  = SourceTableInfo->Mem_Operand_Size_KW_MASM_Offset;
	
}

inline void 
CopyBitsFromFile(bits * Dest, eff_bits * Source)
{
    Dest->type = Source->Type;
    Dest->bits_count = Source->bits_count;
    Dest->value = Source->value;
}

inline void 
CopyEflyFileInstructionInfo(instruction_info_ * DestInfo , eflyfile_instruction_info * SourceInfo)
{
    Assert(SourceInfo->MnemonicCount < MAX_BUFFER_SIZE);
    Assert(SourceInfo->OperandCount < MAX_OPERAND_COUNT);
    
    DestInfo->OperandCount = SourceInfo->OperandCount;
    for(u32 Index = 0;
        Index < MAX_OPERAND_COUNT;
        ++Index)
    {
        operand_size * SourceSize = SourceInfo->OperandSizes + Index;
        operand_type * SourceType = SourceInfo->OperandTypes + Index;
        operand_size * DestSize = DestInfo->OperandSizes + Index;
        operand_type * DestType = DestInfo->OperandTypes + Index;
        
        *DestSize = *SourceSize;
        *DestType = *SourceType;
    }
    
    DestInfo->MnemonicCount = SourceInfo->MnemonicCount;
    for(u32 Index = 0;
        Index < MAX_BUFFER_SIZE;
        ++Index)
    {
        char * Source = SourceInfo->MnemonicBuffer + Index;
        char * Dest = DestInfo->MnemonicBuffer + Index;
        *Dest = *Source;
    }
    
    DestInfo->Type = SourceInfo->Type;
    
    switch(DestInfo->Type)
    {
        case InstructionType_Group:
        {
            DestInfo->TableOffset = SourceInfo->TableOffset;
            DestInfo->TableEntryCount = SourceInfo->TableEntryCount;
        }break;
        case InstructionType_Normal:
        case InstructionType_Entry:
        {
			DestInfo->REP_Valid = SourceInfo->REP_Valid;
			DestInfo->LOCK_Valid = SourceInfo->LOCK_Valid;
			DestInfo->BranchHint_Valid = SourceInfo->BranchHint_Valid;
			DestInfo->InstructionOperandSize = SourceInfo->InstructionOperandSize;
        }break;
		InvalidDefaultCase;
    }
    
}


internal void
ReadInstructionTableInfo(disasm_state * State, instruction_table_info_ * out_InstructionTableInfo)
{
	processor_mode ProcessorMode = State->ProcessorMode;
    eflyfile_instruction_table_info* FileTableInfo = (eflyfile_instruction_table_info *)State->FilePtrBase;
    CopyEflyFileInstructionTableInfo(out_InstructionTableInfo, FileTableInfo);
}


internal void
ReadInstructionInfo(disasm_state * State, instruction_info_ * out_info, memory_index index)
{
	instruction_table_info_ result = {};
    eflyfile_instruction_info * base = (eflyfile_instruction_info*)GetInstructionInfoBase(State, &State->InstructionTableInfo);
    eflyfile_instruction_info * s_info = base + index;
    CopyEflyFileInstructionInfo(out_info , s_info);
}



//NOTE(Alex): Reader
/*
NOTE(Alex): The tables are ordered such that register opcodes are read first and memory opcodes are read later.
In that way we can always check for valid ID's
*/


inline void 
init_i_search(disasm_state * State)
{
    State->instruction_bits_index_reader = 0;
}


internal eff_instruction_bits_header * 
get_file_instruction_bits_header(disasm_state * State, memory_index index)
{
	eff_instruction_bits_header * base = (eff_instruction_bits_header*)GetFilePointerFromBase(State, State->i_bits_header_offset);
	eff_instruction_bits_header * result =  base + index;
	return (result);
}

internal eff_bits * 
get_file_instruction_bits_bits(disasm_state * State, memory_index index)
{
	
	eff_bits * base = (eff_bits *)GetFilePointerFromBase(State, State->i_bits_bits_offset);
	eff_bits * result =  base + index;
	return (result);	
}


internal void
get_next_instruction_bits_from_file(disasm_state * State, source_instruction_bits * out_s_bits)
{
	memory_index index = State->instruction_bits_index_reader;
	
	eff_instruction_bits_header * s_h = get_file_instruction_bits_header(State, index);	
	out_s_bits->count = s_h->count;
	out_s_bits->i_info_index = s_h->i_info_index;
	
	eff_bits * s_bits = get_file_instruction_bits_bits(State, s_h->first_bits_index);
	
	bits * d_bits = out_s_bits->buffer;
	for(u32 s_index = 0;
		s_index < out_s_bits->count;
		++s_index)
	{
		CopyBitsFromFile(d_bits++, s_bits++);
	}
	
	++index;
	
	if(index < State->InstructionCount)
	{
		State->instruction_bits_index_reader = index;
	}
	else
	{
		State->instruction_bits_index_reader = 0;
	}
	
	
}


internal b32
ReadWorkingBuffer(disasm_state * State, instruction_context * out_ctx)
{
	
	State->work_temp_mem = BeginTempMemory(&State->i_match_arena.Arena);	
	
	instruction_bits_buffer * i_buffer = &State->i_buffer;    
	b32 InstructionFound = false;
    
	u32 i_count = 0;
    u32 i_index = 0;//State->LastBitsBufferIndex;
    b32 BitsMatch = true;

	init_i_search(State);    
	
	instruction_bits * i_bits = 0;    
	
    do
    {
        //BitsBufferIndex %= ArrayCount(BitsBuffer->Base);
		//NOTE(Alex): Filler - This writes data from file to buffer - It always starts from Index  = 0; until theres no more space to add instructions
        if(i_index == 0)
        {
            //FillWorkingBuffer(State, i_buffer);
			
			instruction_bits * d_i_bits = 0;
			d_i_bits = State->i_buffer.buffer;
			if(d_i_bits)
			{
				EndTempMemory(&State->work_temp_mem);
				State->work_temp_mem = BeginTempMemory(&State->i_match_arena.Arena);
				
				for(u32 index = 0; 
					index < i_buffer->count;
					++index)
				{
					
					bits * d_1 = 0, * d_0 = 0;
					source_instruction_bits s_i_bits = {};
					get_next_instruction_bits_from_file(State, &s_i_bits);					
					d_i_bits->i_info_index = s_i_bits.i_info_index;
					
					bits * s_first_bits = s_i_bits.buffer;
					bits * s = s_first_bits;
					
					d_i_bits->count = s_i_bits.count;
					d_i_bits->base = PushArray(&State->i_match_arena.Arena, s_i_bits.count, bits);
					d_1 = d_i_bits->base;
					
					for(u32 s_index = 0;
						s_index < s_i_bits.count;
						++s_index)
					{					
						*d_1++ = *s++;
					}
					
					
					++d_i_bits;
				}
				
			}
			
        }
        
        i_bits = i_buffer->buffer + i_index;
		Assert(i_bits->count);
		
		bits * comp_bits = i_bits->base;
		for(u32 index = 0;
			index < i_bits->count;
			++index)
		{
			u64 SourceBits = GetBits_msb(State, comp_bits->bits_count);
			
			if(comp_bits->type == BitfieldType_id)
			{
				BitsMatch = BitsMatch & (SourceBits == comp_bits->value);
			}
			
			++comp_bits;
		}
		
		if(BitsMatch)
		{ 
			InstructionFound = true;
		}
		else
		{
			BitsMatch = true;
		}
		
		//TODO(Alex): Fid a way to erase this!
		//NOTE(Alex): Reset BitBuffer so we can start again!
		State->cursor = State->baseframe + State->SecureByteCount;
		State->BitBuffer = 0;
		State->BitCount = 0;
		
		++i_index;
		if(i_index >= i_buffer->count)
		{
			i_index = 0;
		}
		
		++i_count;
    }
    while((i_count < State->InstructionCount) && !InstructionFound);
	
#if EAGLEFLY_INTERNAL
	if(i_count == State->InstructionCount)
	{
		int x = 5;
	}
#endif
	
	if(InstructionFound)
	{
		//NOTE(Alex): Fill encoding buffer we will use
		instruction_info_ * d_info = out_ctx->i_info;		
		ReadInstructionInfo(State, d_info, i_bits->i_info_index);
		
		bits_array_ * bits_array = out_ctx->BitsArrayPtr;
		
		bits * t = i_bits->base;
		for(u32 index = 0;
			index < i_bits->count;
			++index)
		{
			bits * d = bits_array->Base + bits_array->Count++;
			u64 s_value = GetBits_msb(State, t->bits_count);
			
			*d = *t;
			d->value = s_value;
			
			++t;
		}
		
		out_ctx->InstructionFound = true;
	}
	
	EndTempMemory(&State->work_temp_mem);
    return InstructionFound;
}


#if 0
internal void
ReadAssemblyGrammar(disasm_state * State, char * out_AssemblyGrammar, u32 BufferSize)
{
    memory_index * AssemblyGrammarsOffsetsBase = GetAssemblyGrammarsOffsetsBase(State, State->InstructionTableInfo);
    memory_index Index = GetInstructionIndex_(State);
    //NOTE(Alex), we can do this because there's a rule in the tables that each instruction entry has its own grammar respectively!
    memory_index StringOffset = AssemblyGrammarsOffsetsBase[Index];
    
    char * AssemblyGrammar = (char*)GetFilePointerFromBase(State, StringOffset);
    _snprintf_s(out_AssemblyGrammar, BufferSize, BufferSize, "%s", AssemblyGrammar);
}
#endif


internal void
GetGrammarEntryInGroup(disasm_state * State,  instruction_info_ * out_InstructionInfo, instruction_info_ * InstructionInfoGroup, u32 ID)
{
    Assert(out_InstructionInfo && InstructionInfoGroup);
    eflyfile_instruction_info * Entry = GetInstructionEntryBase(State, InstructionInfoGroup);
    
    b32 InstructionEntryFound = false;
    for(u32 Index = 0;
        (Index < InstructionInfoGroup->TableEntryCount) && !InstructionEntryFound;
        ++Index)
    {
        Assert(Entry->Type == InstructionType_Entry);
        if(Entry->InstructionOperandSize == ID)
        {
            CopyEflyFileInstructionInfo(out_InstructionInfo, Entry);
            InstructionEntryFound = true;
        }
        
        ++Entry;
    }
}

//NOTE(Alex): Addressing Tables

struct string_result_file_
{
	u32 mem_size;
    u32  count;
    char * base;
};

internal string
ReadConditionalCodesTable(disasm_state * State, u64 MemoryIndex, string * out_string)
{    
    memory_index * ConditonalCodesOffset = (memory_index * )GetFilePointerFromBase(State, State->InstructionTableInfo.ConditionalCodesOffsets);
    memory_index StringOffset = ConditonalCodesOffset[MemoryIndex];
    char * String = (char*)GetFilePointerFromBase(State, StringOffset);
    
	Append(out_string, String, StringLength(String));
}


inline void
GetAdressingModemod00_rm101(disasm_state * State, processor_mode ProcessorMode, eff_address_size EffAdressSize, string * out_string)
{
	memory_index Index = SIZE_MAX;
    if (EffAdressSize == addresssize_64)
    {
        if (ProcessorMode == ProcessorMode_64bit)
        {
            //bits(N) instruction = baseInstruction : disp32;
            Index = 0;
            //_snprintf_s(out_Buffer, BufferSize, BufferSize, "CS : [ RIP + %s ]", ImmBuffer);
        }
        else
        {
            Index = 1;
            //PrintImmediateToBuffer(out_Buffer, BufferSize, EffAdressSize, disp32);
        }
    }
    else if (EffAdressSize == addresssize_32)
    {
        if (ProcessorMode == ProcessorMode_64bit)
        {
            Index = 2;
            //_snprintf_s(out_Buffer, BufferSize, BufferSize, "CS : [ EIP + %s ]", ImmBuffer);
        }
        else
        {
            Index = 3;
            //PrintImmediateToBuffer(out_Buffer, BufferSize, EffAdressSize, disp32);
        }
    }
    
    Assert(Index != SIZE_MAX);
    
    memory_index * MODRMrm101Offset = (memory_index * )GetFilePointerFromBase(State, State->InstructionTableInfo.MODRMrm101Offsets);
    memory_index StringOffset = MODRMrm101Offset[Index];
    char * String = (char*)GetFilePointerFromBase(State, StringOffset);
    
	Append(out_string, String, StringLength(String));    
}


internal void 
ReadModrm64TableExtended(disasm_state * State, u64 MODValue, u64 RMValue, string * out_string)
{
    Assert(MODValue != 0b11);
    Assert(!((MODValue == 0b00) && (RMValue == 0b101)));
    
    memory_index * MODRM64ExtendedOffset = (memory_index * )GetFilePointerFromBase(State, State->InstructionTableInfo.MODRM64ExtendedOffsets);
    memory_index StringOffset = MODRM64ExtendedOffset[MODValue * 8 + RMValue];
    char * String = (char*)GetFilePointerFromBase(State, StringOffset);
    
	Append(out_string, String, StringLength(String));
}

internal void 
ReadModrm64Table(disasm_state * State, u64 MODValue, u64 RMValue , string * out_string)
{
    Assert(MODValue != 0b11);
    Assert(!((MODValue == 0b00) && (RMValue == 0b101)));
    
    memory_index * MODRM64Offset = (memory_index * )GetFilePointerFromBase(State, State->InstructionTableInfo.MODRM64Offsets);
    memory_index StringOffset = MODRM64Offset[MODValue * 8 + RMValue];
    char * String = (char*)GetFilePointerFromBase(State, StringOffset);
    Append(out_string, String, StringLength(String));    
}

internal void
ReadModrm32TableExtended(disasm_state * State, u64 MODValue, u64 RMValue, string * out_string)
{
    Assert(MODValue != 0b11);
    Assert(!((MODValue == 0b00) && (RMValue == 0b101)));
    
    memory_index * MODRM32ExtendedOffset = (memory_index * )GetFilePointerFromBase(State, State->InstructionTableInfo.MODRM32ExtendedOffsets);
    memory_index StringOffset = MODRM32ExtendedOffset[MODValue * 8 + RMValue];
    char * String = (char*)GetFilePointerFromBase(State, StringOffset);
    
	Append(out_string, String, StringLength(String));    
}

internal void
ReadModrm32Table(disasm_state * State, u64 MODValue, u64 RMValue, string * out_string)
{
    Assert(MODValue != 0b11);
    Assert(!((MODValue == 0b00) && (RMValue == 0b101)));
	
    memory_index * MODRM32Offset = (memory_index * )GetFilePointerFromBase(State, State->InstructionTableInfo.MODRM32Offsets);
    memory_index StringOffset = MODRM32Offset[MODValue * 8 + RMValue];
    char * String = (char*)GetFilePointerFromBase(State, StringOffset);
	
	Append(out_string, String, StringLength(String));
}

internal void
ReadModrm16Table(disasm_state * State, u64 MODValue, u64 RMValue, string * out_string)
{
    Assert(MODValue != 0b11);
    Assert(!((MODValue == 0b00) && (RMValue == 0b101)));
    
    memory_index * MODRM16Offset = (memory_index * )GetFilePointerFromBase(State, State->InstructionTableInfo.MODRM16Offsets);
    memory_index StringOffset = MODRM16Offset[MODValue * 8 + RMValue];
    char * String = (char*)GetFilePointerFromBase(State, StringOffset);
	Append(out_string, String, StringLength(String));    
}

internal void
ReadSS64ExtendedTable(disasm_state * State, u64 SSValue, u64 INDEXValue, string * out_string)
{    
    memory_index * SS64ExtendedOffset = (memory_index * )GetFilePointerFromBase(State, State->InstructionTableInfo.SS64ExtendedOffsets);
    memory_index StringOffset = SS64ExtendedOffset[SSValue * 8 + INDEXValue];
    char * String = (char*)GetFilePointerFromBase(State, StringOffset);
	Append(out_string, String, StringLength(String));
}

internal void
ReadSS64Table(disasm_state * State, u64 SSValue, u64 INDEXValue, string * out_string)
{
    memory_index * SS64Offset = (memory_index * )GetFilePointerFromBase(State, State->InstructionTableInfo.SS64Offsets);
    memory_index StringOffset = SS64Offset[SSValue * 8 + INDEXValue];
    char * String = (char*)GetFilePointerFromBase(State, StringOffset);
	Append(out_string, String, StringLength(String));    
}

internal void
ReadSS32ExtendedTable(disasm_state * State, u64 SSValue, u64 INDEXValue, string * out_string)
{
    memory_index * SS32ExtendedOffset = (memory_index * )GetFilePointerFromBase(State, State->InstructionTableInfo.SS32ExtendedOffsets);
    memory_index StringOffset = SS32ExtendedOffset[SSValue * 8 + INDEXValue];
    char * String = (char*)GetFilePointerFromBase(State, StringOffset);
	Append(out_string, String, StringLength(String));    
}

internal void
ReadSS32Table(disasm_state * State, u64 SSValue, u64 INDEXValue, string * out_string)
{
    
    memory_index * SS32Offset = (memory_index * )GetFilePointerFromBase(State, State->InstructionTableInfo.SS32Offsets);
    memory_index StringOffset = SS32Offset[SSValue * 8 + INDEXValue];
    char * String = (char*)GetFilePointerFromBase(State, StringOffset);
	Append(out_string, String, StringLength(String));    
}

internal void
ReadBasebase101ExtendedTable(disasm_state * State, eff_address_size EffAdressSize, b32 REX_b_Set, u32 MODValue, string * out_string)
{
    Assert(!(MODValue & ~0b11));
    
    memory_index Base = SIZE_MAX;
    
    
    if(EffAdressSize == addresssize_64)
    {
        if(REX_b_Set)
        {
            Base = 0;
        }
        else
        {
            Base = 1;
        }
    }
    else if(EffAdressSize == addresssize_32)
    {
        if(REX_b_Set)
        {
            Base = 2;
        }
        else
        {
            Base = 3;
        }
    }
    
    
    Assert(Base != SIZE_MAX);
    
    memory_index * Basebase101Offset = (memory_index * )GetFilePointerFromBase(State, State->InstructionTableInfo.Basebase101Offsets);
    memory_index StringOffset = Basebase101Offset[Base * 3 + MODValue];
    char * String = (char*)GetFilePointerFromBase(State, StringOffset);
    
	Append(out_string, String, StringLength(String));    
}

internal void
ReadBase64ExtendedTable(disasm_state * State, u64 BASEValue, string * out_string)
{
    memory_index * Base64ExtendedOffset = (memory_index * )GetFilePointerFromBase(State, State->InstructionTableInfo.Base64ExtendedOffsets);
    memory_index StringOffset = Base64ExtendedOffset[BASEValue];
    char * String = (char*)GetFilePointerFromBase(State, StringOffset);
	Append(out_string, String, StringLength(String));    
}

internal void
ReadBase64Table(disasm_state * State, u64 BASEValue, string * out_string)
{
    memory_index * Base64Offset = (memory_index * )GetFilePointerFromBase(State, State->InstructionTableInfo.Base64Offsets);
    memory_index StringOffset = Base64Offset[BASEValue];
    char * String = (char*)GetFilePointerFromBase(State, StringOffset);
	Append(out_string, String, StringLength(String));    
}

internal void
ReadBase32ExtendedTable(disasm_state * State, u64 BASEValue, string * out_string)
{
    memory_index * Base32ExtendedOffset = (memory_index * )GetFilePointerFromBase(State, State->InstructionTableInfo.Base32ExtendedOffsets);
    memory_index StringOffset = Base32ExtendedOffset[BASEValue];
    char * String = (char*)GetFilePointerFromBase(State, StringOffset);
	Append(out_string, String, StringLength(String));    
}

internal void
ReadBase32Table(disasm_state *  State, u64 BASEValue, string * out_string)
{
    memory_index * Base32Offset = (memory_index * )GetFilePointerFromBase(State, State->InstructionTableInfo.Base32Offsets);
    memory_index StringOffset = Base32Offset[BASEValue];
    char * String = (char*)GetFilePointerFromBase(State, StringOffset);
	Append(out_string, String, StringLength(String));    
}

internal void
ReadReg8ExtendedTable(disasm_state * State, u64 RegValue, string * out_string)
{
    memory_index * Reg8ExtendedOffset = (memory_index * )GetFilePointerFromBase(State, State->InstructionTableInfo.Reg8ExtendedOffsets);
    memory_index StringOffset = Reg8ExtendedOffset[RegValue];
    char * String = (char*)GetFilePointerFromBase(State, StringOffset);
	Append(out_string, String, StringLength(String));    
}

internal void
ReadReg8REXPresentTable(disasm_state * State, u64 RegValue, string * out_string)
{
    memory_index * Reg8REXPresentOffset = (memory_index * )GetFilePointerFromBase(State, State->InstructionTableInfo.Reg8REXPresentOffsets);
    memory_index StringOffset = Reg8REXPresentOffset[RegValue];
    char * String = (char*)GetFilePointerFromBase(State, StringOffset);
	Append(out_string, String, StringLength(String));    
}

internal void
ReadReg8Table(disasm_state * State, u64 RegValue, string * out_string)
{
    memory_index * RegReg8Offset = (memory_index * )GetFilePointerFromBase(State, State->InstructionTableInfo.Reg8Offsets);
    memory_index StringOffset = RegReg8Offset[RegValue];
    char * String = (char*)GetFilePointerFromBase(State, StringOffset);
	Append(out_string, String, StringLength(String));    
}


internal void
ReadReg64ExtendedTable(disasm_state * State, u64 RegValue, string * out_string)
{
    memory_index * Reg64ExtendedOffset = (memory_index * )GetFilePointerFromBase(State, State->InstructionTableInfo.Reg64ExtendedOffsets);
    memory_index StringOffset = Reg64ExtendedOffset[RegValue];
    char * String = (char*)GetFilePointerFromBase(State, StringOffset);
	Append(out_string, String, StringLength(String));    
}

internal void
ReadReg64Table(disasm_state * State, u64 RegValue, string * out_string)
{
    memory_index * Reg64Offset = (memory_index * )GetFilePointerFromBase(State, State->InstructionTableInfo.Reg64Offsets);
    memory_index StringOffset = Reg64Offset[RegValue];
    char * String = (char*)GetFilePointerFromBase(State, StringOffset);
	Append(out_string, String, StringLength(String));    
}

internal void
ReadReg32ExtendedTable(disasm_state * State, u64 RegValue, string * out_string)
{
    memory_index * Reg32ExtendedOffset = (memory_index * )GetFilePointerFromBase(State, State->InstructionTableInfo.Reg32ExtendedOffsets);
    memory_index StringOffset = Reg32ExtendedOffset[RegValue];
    char * String = (char*)GetFilePointerFromBase(State, StringOffset);
	Append(out_string, String, StringLength(String));    
}

internal void
ReadReg32Table(disasm_state * State, u64 RegValue, string * out_string)
{
    memory_index * Reg32Offset = (memory_index * )GetFilePointerFromBase(State, State->InstructionTableInfo.Reg32Offsets);
    memory_index StringOffset = Reg32Offset[RegValue];
    char * String = (char*)GetFilePointerFromBase(State, StringOffset);
	Append(out_string, String, StringLength(String));    
}

internal void
ReadReg16ExtendedTable(disasm_state * State, u64 RegValue, string * out_string)
{
    memory_index * Reg16ExtendedOffset = (memory_index * )GetFilePointerFromBase(State, State->InstructionTableInfo.Reg16ExtendedOffsets);
    memory_index StringOffset = Reg16ExtendedOffset[RegValue];
    char * String = (char*)GetFilePointerFromBase(State, StringOffset);
	Append(out_string, String, StringLength(String));    
}

internal void
ReadReg16Table(disasm_state * State, u64 RegValue, string * out_string)
{
    memory_index * Reg16Offset = (memory_index * )GetFilePointerFromBase(State, State->InstructionTableInfo.Reg16Offsets);
    memory_index StringOffset = Reg16Offset[RegValue];
    char * String = (char*)GetFilePointerFromBase(State, StringOffset);
	Append(out_string, String, StringLength(String));    
}

internal void
read_reg_xmm_8_15_table(disasm_state * State, u32 RegIndex, string * out_string)
{
	memory_index * Reg_XMM_Offsets = (memory_index * )GetFilePointerFromBase(State, State->InstructionTableInfo.Reg_XMM_Offsets);
	RegIndex += 8;
    memory_index StringOffset = Reg_XMM_Offsets[RegIndex];
    char * String = (char*)GetFilePointerFromBase(State, StringOffset);
	Append(out_string, String, StringLength(String));    
}

internal void 
read_reg_xmm_0_7_table(disasm_state * State, u32 RegIndex, string * out_string)
{
	memory_index * Reg_XMM_Offsets = (memory_index * )GetFilePointerFromBase(State, State->InstructionTableInfo.Reg_XMM_Offsets);
    memory_index StringOffset = Reg_XMM_Offsets[RegIndex];
    char * String = (char*)GetFilePointerFromBase(State, StringOffset);
	Append(out_string, String, StringLength(String));    
}

internal void 
read_reg_mmx_table(disasm_state * State, u64 RegIndex, string * out_string)
{
	memory_index * Reg_MMX_Offsets = (memory_index * )GetFilePointerFromBase(State, State->InstructionTableInfo.Reg_MMX_Offsets);
    memory_index StringOffset = Reg_MMX_Offsets[RegIndex];
    char * String = (char*)GetFilePointerFromBase(State, StringOffset);
	Append(out_string, String, StringLength(String));    
}

internal void 
read_reg_fp_table(disasm_state * State, u64 RegIndex, string * out_string)
{
	memory_index * Reg_FP_Offsets = (memory_index * )GetFilePointerFromBase(State, State->InstructionTableInfo.Reg_FP_Offsets);
    memory_index StringOffset = Reg_FP_Offsets[RegIndex];
    char * String = (char*)GetFilePointerFromBase(State, StringOffset);
	Append(out_string, String, StringLength(String));    
}

internal void 
read_reg_sreg_table(disasm_state * State, u64 RegIndex, string * out_string)
{
	memory_index * Reg_SREG_Offsets = (memory_index * )GetFilePointerFromBase(State, State->InstructionTableInfo.Reg_SREG_Offsets);
    memory_index StringOffset = Reg_SREG_Offsets[RegIndex];
    char * String = (char*)GetFilePointerFromBase(State, StringOffset);
	Append(out_string, String, StringLength(String));    
}

internal void 
read_reg_treg_table(disasm_state * State, u32 RegIndex, string *out_string)
{
	memory_index * Reg_TREG_Offsets = (memory_index * )GetFilePointerFromBase(State, State->InstructionTableInfo.Reg_TREG_Offsets);
    memory_index StringOffset = Reg_TREG_Offsets[RegIndex];
    char * String = (char*)GetFilePointerFromBase(State, StringOffset);
	Append(out_string, String, StringLength(String));
}

internal void 
read_cx_reg_table(disasm_state * State, u32 RegIndex, string * out_string)
{
	memory_index * Reg_CX_Offsets = (memory_index * )GetFilePointerFromBase(State, State->InstructionTableInfo.Reg_CX_Offsets);
    memory_index StringOffset = Reg_CX_Offsets[RegIndex];
    char * String = (char*)GetFilePointerFromBase(State, StringOffset);
	Append(out_string, String, StringLength(String));    
}


internal void 
read_ax_reg_table(disasm_state * State, u32 RegIndex, string * out_string)
{
	memory_index * Reg_AX_Offsets = (memory_index * )GetFilePointerFromBase(State, State->InstructionTableInfo.Reg_AX_Offsets);
    memory_index StringOffset = Reg_AX_Offsets[RegIndex];
    char * String = (char*)GetFilePointerFromBase(State, StringOffset);
	Append(out_string, String, StringLength(String));    
}

internal void 
read_dx_reg_table(disasm_state * State, u32 RegIndex, string * out_string)
{
	memory_index * Reg_DX_Offsets = (memory_index * )GetFilePointerFromBase(State, State->InstructionTableInfo.Reg_DX_Offsets);
    memory_index StringOffset = Reg_DX_Offsets[RegIndex];
    char * String = (char*)GetFilePointerFromBase(State, StringOffset);
	Append(out_string, String, StringLength(String));    
}

internal void 
read_mem_operand_size_kw_masm_table(disasm_state * State, u32 Index, string * out_string)
{
	memory_index * Ptr = (memory_index * )GetFilePointerFromBase(State, State->InstructionTableInfo.Mem_Operand_Size_KW_MASM_Offset);
    memory_index StringOffset = Ptr[Index];
    char * String = (char*)GetFilePointerFromBase(State, StringOffset);
	Append(out_string, String, StringLength(String));    
}

internal void
read_xmm_table(disasm_state * State, bits rex, u32 RegValue, b32 look_rex_r, string * out_string)
{
	if ((look_rex_r) ? TestBit(rex, 2) : TestBit(rex,0))
	{
		read_reg_xmm_8_15_table(State, RegValue, out_string);
	}
	else
	{
		read_reg_xmm_0_7_table(State, RegValue, out_string);
	}
	
}

internal void
ReadRegTable(disasm_state * State, eff_operand_size EffOperandSize, bits rex, u64 RegValue, b32 look_rex_r, string * out_string)
{    
	u32 s_c = out_string->count;
    //reg8(rex, RegValue, look_rex_r);
    if (EffOperandSize == operandsize_8)
    {
        if(rex.value)
        {
            if((look_rex_r) ? TestBit(rex, 2) : TestBit(rex,0))
            {
                ReadReg8ExtendedTable(State, RegValue, out_string);
            }
            else
            {
                ReadReg8REXPresentTable(State, RegValue, out_string);
            }
            
        }
        else
        {
            ReadReg8Table(State, RegValue, out_string);
        }
    }
    else if(EffOperandSize == operandsize_64)
    {
        if ((look_rex_r) ? TestBit(rex, 2) : TestBit(rex,0))
        {
            ReadReg64ExtendedTable(State, RegValue, out_string);
        }
        else
        {
            ReadReg64Table(State, RegValue, out_string);
        }
    }
    else if(EffOperandSize == operandsize_32)
    {
        if((look_rex_r) ? TestBit(rex, 2) : TestBit(rex,0))
        {
            ReadReg32ExtendedTable(State, RegValue, out_string);
        }
        else
        {
            ReadReg32Table(State, RegValue, out_string);
        }
        
    }
    else if(EffOperandSize == operandsize_16)
    {
        if((look_rex_r) ? TestBit(rex, 2) : TestBit(rex,0))
        {
            ReadReg16ExtendedTable(State, RegValue, out_string);
        }
        else
        {
            ReadReg16Table(State, RegValue, out_string);
        }
    }
	
    Assert(out_string->count > s_c);
}


internal void
read_mem_table(disasm_state * State, u32 ProcessorMode, eff_address_size EffAdressSize, bits rex, u64 MODValue, u64 RMValue, string * out_string)
{
	u32 s_c = out_string->count;
	
	//TODO(Alex): Add operand size attr masm syntax as separate data to be chosen!
	//Make string_result_file a buffer instead of just a pointer.
#if 0	
	if(EffOperandSize != operandsize_Invalid)
	{
		read_operand_size_attr_masm(State);
	}    
#endif
	
	b32 REXBSet = TestBit(rex, 0);
	
	if((MODValue == 0b00) && (RMValue == 0b101) && (EffAdressSize != addresssize_16))
	{
		GetAdressingModemod00_rm101(State, (processor_mode)ProcessorMode, EffAdressSize, out_string);
	}
	else if(EffAdressSize == addresssize_64)
	{
		if(REXBSet)
		{
			ReadModrm64TableExtended(State, MODValue, RMValue, out_string);
		}
		else
		{
			ReadModrm64Table(State, MODValue, RMValue, out_string);
		}
	}
	else if (EffAdressSize == addresssize_32)
	{
		if(REXBSet)
		{
			ReadModrm32TableExtended(State, MODValue, RMValue, out_string);
		}
		else
		{
			ReadModrm32Table(State, MODValue, RMValue, out_string);
		}
	}
	else if (EffAdressSize == addresssize_16)
	{
		ReadModrm16Table(State, MODValue, RMValue, out_string);
	}
	
    Assert(out_string->count > s_c);
	
}

internal void
get_gp_addressing_mode(disasm_state * State, u32 ProcessorMode, eff_operand_size EffOperandSize, eff_address_size EffAdressSize,  u64 MODValue, u64 RMValue, bits rex, b32 look_rex_r, string * out_string)
{
	u32 s_c = out_string->count;
	
    if(MODValue >= 0b11)
    {
        ReadRegTable(State, EffOperandSize, rex, RMValue, look_rex_r, out_string); 
    }
    
    else
	{	
		read_mem_table(State, ProcessorMode, EffAdressSize, rex, MODValue, RMValue, out_string);		
	}   
	
    Assert(out_string->count > s_c);	
}

internal void
get_xmm_addressing_mode(disasm_state * State, processor_mode ProcessorMode, eff_address_size EffAdressSize, u32 MODValue, u32 RMValue, bits rex, b32 look_rex_r, string * out_string)
{
	u32 s_c = out_string->count;
    
    if(MODValue >= 0b11)
    {
        read_xmm_table(State, rex, RMValue, look_rex_r, out_string); 
    }
    
    else
	{
		read_mem_table(State, ProcessorMode, EffAdressSize, rex, MODValue, RMValue, out_string);		
	}   
	
    Assert(out_string->count > s_c);	
	
}

internal void
get_mmx_addressing_mode(disasm_state * State, eff_address_size EffAdressSize, bits rex, b32 look_rex_r, u64 MODValue, u64 RMValue, string * out_string)
{
	u32 s_c = out_string->count;
	
	processor_mode ProcessorMode = State->ProcessorMode;
	
    if(MODValue >= 0b11)
    {
        read_reg_mmx_table(State, RMValue, out_string); 
    }
    
    else
	{
		read_mem_table(State, ProcessorMode, EffAdressSize, rex, MODValue, RMValue, out_string);		
	}   
	
    Assert(out_string->count > s_c);	
	
}


internal void
get_fp_addressing_mode(disasm_state * State, eff_address_size EffAdressSize, bits rex, b32 look_rex_r, u64 MODValue, u64 RMValue, string * out_string)
{
	
	u32 s_c = out_string->count;
	processor_mode ProcessorMode = State->ProcessorMode;
	
    if(MODValue >= 0b11)
    {
        read_reg_fp_table(State, RMValue, out_string); 
    }
    
    else
	{
		read_mem_table(State, ProcessorMode, EffAdressSize, rex, MODValue, RMValue, out_string);		
	}   
	
    Assert(out_string->count > s_c);	
	
}

internal void
get_sreg_reg(disasm_state * State, u32 RegValue, string * out_string)
{
	if(RegValue <= 5)
	{
		read_reg_sreg_table(State, RegValue, out_string);
	}
	else
	{
		//TODO(Alex): Error logging invalide Opcode excpetion?? Treat as data?
	}
	
}

internal void
get_treg_reg(disasm_state * State, u32 RegValue ,string * out_string)
{
	
	if(RegValue >= 3)
	{
		read_reg_treg_table(State, RegValue, out_string);
	}
	else
	{
		//TODO(Alex): Error logging invalide Opcode excpetion?? Treat as data?
	}
	
}

//TODO(Alex): Change operand_size to be an enum!
internal void
get_cx_reg_size(disasm_state * State, u32 OperandSize, string * out_string)
{
	u32 s_c = out_string->count;
	Assert(OperandSize > operandsize_Invalid && OperandSize <= operandsize_64);
	u32 Index = OperandSize - 1;
	read_cx_reg_table(State, Index, out_string);
	
	Assert(out_string->count > s_c);	
}

internal void
get_ax_reg_size(disasm_state * State, eff_operand_size OperandSize, string * out_string)
{
	u32 s_c = out_string->count; 
	Assert(OperandSize > operandsize_Invalid && OperandSize <= operandsize_64);
	u32 Index = OperandSize - 1;
	read_ax_reg_table(State, Index, out_string);
	Assert(out_string->count > s_c);	
}

internal void
get_dx_reg_size(disasm_state * State, eff_operand_size OperandSize, string * out_string)
{
	u32 s_c = out_string->count;
	Assert(OperandSize > operandsize_Invalid && OperandSize <= operandsize_64);
	u32 Index = OperandSize - 1;
	read_dx_reg_table(State, Index, out_string);	
	Assert(out_string->count > s_c);	
	
}

internal void 
get_mem_operand_size_kw_masm(disasm_state * State, eff_operand_size OperandSize, string * out_string)
{
	u32 s_c = out_string->count;
	Assert(OperandSize < OperandSize_Count);
	read_mem_operand_size_kw_masm_table(State, OperandSize, out_string);	
	Assert(out_string->count > s_c);	

}

internal void
ReadSIBTable(disasm_state * State, eff_address_size EffAdressSize, b32 REX_s_Set, u64 SSValue, u64 INDEXValue, string * out_string)
{
    if(EffAdressSize == addresssize_64)
    {
        if(REX_s_Set)
        {
            ReadSS64ExtendedTable(State, SSValue, INDEXValue, out_string);
        }
        else
        {
            ReadSS64Table(State, SSValue, INDEXValue, out_string);
        }
    }
    else if(EffAdressSize == addresssize_32)
    {
        if(REX_s_Set)
        {
            ReadSS32ExtendedTable(State, SSValue, INDEXValue, out_string);
        }
        else
        {
            ReadSS32Table(State, SSValue, INDEXValue, out_string);
        }
        
    }    
}


internal void
ReadBaseTable(disasm_state * State, eff_address_size EffAdressSize, b32 REX_b_Set, u32 BASEValue, u32 MODValue, string * out_string)
{
    u32 s_c = out_string->count;
    
	if(BASEValue == 0b101)
    {
        ReadBasebase101ExtendedTable(State, EffAdressSize, REX_b_Set, MODValue, out_string);
    }
    
    else if(EffAdressSize == addresssize_64)
    {
        if(REX_b_Set)
        {
            ReadBase64ExtendedTable(State, BASEValue, out_string);
        }
        else
        {
            ReadBase64Table(State, BASEValue, out_string);
        }
    }
    else if(EffAdressSize == addresssize_32)
    {
        if(REX_b_Set)
        {
            ReadBase32ExtendedTable(State, BASEValue, out_string);
        }
        else
        {
            ReadBase32Table(State, BASEValue, out_string);
        }
        
    }
    
	Assert(out_string->count > s_c);	
}



internal bits
get_bitfield_from_bitsarray_bytype(bits_array_ * BitsArray, bitfield_type BFieldType)
{
    bits Result = {};
    
    for(u32 Index = 0;
        (Index < BitsArray->Count);
        ++Index)
    {
        bits a = BitsArray->Base[Index];
        if(a.type == BFieldType)
        {
            Result = a;
            break;
        }
    }
    
    return Result;
}
