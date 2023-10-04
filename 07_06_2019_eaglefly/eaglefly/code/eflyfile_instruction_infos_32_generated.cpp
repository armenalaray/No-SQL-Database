internal void CreateInstructionInfos_32(file_manager * FileManager)
{

	operand_array OperandArray = {};
	BeginFileSection(FileManager, FileSection_instruction_info_32);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_G,OperandSize_b);
	PushInstructionInfo(FileManager, "ADD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushInstructionInfo(FileManager, "ADD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_b);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushInstructionInfo(FileManager, "ADD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushInstructionInfo(FileManager, "ADD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_AX,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "ADD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_AX,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_vds);
	PushInstructionInfo(FileManager, "ADD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_ESEG,OperandSize_Invalid);
	PushInstructionInfo(FileManager, "PUSH", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_ESEG,OperandSize_Invalid);
	PushInstructionInfo(FileManager, "POP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_G,OperandSize_b);
	PushInstructionInfo(FileManager, "OR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushInstructionInfo(FileManager, "OR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_b);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushInstructionInfo(FileManager, "OR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushInstructionInfo(FileManager, "OR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_AX,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "OR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_AX,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_vds);
	PushInstructionInfo(FileManager, "OR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_CSEG,OperandSize_Invalid);
	PushInstructionInfo(FileManager, "PUSH", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_G,OperandSize_b);
	PushInstructionInfo(FileManager, "ADC", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushInstructionInfo(FileManager, "ADC", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_b);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushInstructionInfo(FileManager, "ADC", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushInstructionInfo(FileManager, "ADC", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_AX,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "ADC", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_AX,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_vds);
	PushInstructionInfo(FileManager, "ADC", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_SSEG,OperandSize_Invalid);
	PushInstructionInfo(FileManager, "PUSH", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_SSEG,OperandSize_Invalid);
	PushInstructionInfo(FileManager, "POP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_G,OperandSize_b);
	PushInstructionInfo(FileManager, "SBB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushInstructionInfo(FileManager, "SBB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_b);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushInstructionInfo(FileManager, "SBB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushInstructionInfo(FileManager, "SBB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_AX,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "SBB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_AX,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_vds);
	PushInstructionInfo(FileManager, "SBB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_DSEG,OperandSize_Invalid);
	PushInstructionInfo(FileManager, "PUSH", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_DSEG,OperandSize_Invalid);
	PushInstructionInfo(FileManager, "POP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_G,OperandSize_b);
	PushInstructionInfo(FileManager, "AND", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushInstructionInfo(FileManager, "AND", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_b);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushInstructionInfo(FileManager, "AND", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushInstructionInfo(FileManager, "AND", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_AX,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "AND", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_AX,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_vds);
	PushInstructionInfo(FileManager, "AND", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "DAA", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_G,OperandSize_b);
	PushInstructionInfo(FileManager, "SUB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushInstructionInfo(FileManager, "SUB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_b);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushInstructionInfo(FileManager, "SUB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushInstructionInfo(FileManager, "SUB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_AX,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "SUB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_AX,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_vds);
	PushInstructionInfo(FileManager, "SUB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "NTAKEN", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "DAS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_G,OperandSize_b);
	PushInstructionInfo(FileManager, "XOR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushInstructionInfo(FileManager, "XOR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_b);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushInstructionInfo(FileManager, "XOR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushInstructionInfo(FileManager, "XOR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_AX,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "XOR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_AX,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_vds);
	PushInstructionInfo(FileManager, "XOR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "AAA", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_G,OperandSize_b);
	PushInstructionInfo(FileManager, "CMP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushInstructionInfo(FileManager, "CMP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_b);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushInstructionInfo(FileManager, "CMP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushInstructionInfo(FileManager, "CMP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_AX,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "CMP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_AX,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_vds);
	PushInstructionInfo(FileManager, "CMP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "TAKEN", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "AAS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_Z,OperandSize_v);
	PushInstructionInfo(FileManager, "INC", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_Z,OperandSize_v);
	PushInstructionInfo(FileManager, "DEC", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_Z,OperandSize_v);
	PushInstructionInfo(FileManager, "PUSH", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_Z,OperandSize_v);
	PushInstructionInfo(FileManager, "POP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_Y,OperandSize_v);
	BeginInstructionInfoGroup(FileManager, "PUSHA", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "PUSHA",16, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "PUSHAD",32, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);
	EndInstructionInfoGroup(FileManager);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_Y,OperandSize_v);
	BeginInstructionInfoGroup(FileManager, "POPA", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "POPA",16, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "POPAD",32, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);
	EndInstructionInfoGroup(FileManager);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_v);
	PushOperand(&OperandArray, OperandType_M,OperandSize_a);
	PushInstructionInfo(FileManager, "BOUND", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_w);
	PushOperand(&OperandArray, OperandType_G,OperandSize_w);
	PushInstructionInfo(FileManager, "ARPL", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "ALTER", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_I,OperandSize_vs);
	PushInstructionInfo(FileManager, "PUSH", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_vds);
	PushInstructionInfo(FileManager, "IMUL", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_I,OperandSize_bss);
	PushInstructionInfo(FileManager, "PUSH", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_bs);
	PushInstructionInfo(FileManager, "IMUL", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "INSB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray,  REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_Y,OperandSize_v);
	BeginInstructionInfoGroup(FileManager, "INSGR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "INSW",16, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray,  REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "INSD",32, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray,  REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);
	EndInstructionInfoGroup(FileManager);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "OUTSB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray,  REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_X,OperandSize_v);
	BeginInstructionInfoGroup(FileManager, "OUTSGR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "OUTSW",16, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray,  REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "OUTSD",32, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray,  REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);
	EndInstructionInfoGroup(FileManager);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_bs);
	PushInstructionInfo(FileManager, "JO", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID,  BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_bs);
	PushInstructionInfo(FileManager, "JNO", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID,  BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_bs);
	PushInstructionInfo(FileManager, "JB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID,  BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_bs);
	PushInstructionInfo(FileManager, "JAE", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID,  BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_bs);
	PushInstructionInfo(FileManager, "JZ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID,  BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_bs);
	PushInstructionInfo(FileManager, "JNZ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID,  BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_bs);
	PushInstructionInfo(FileManager, "JBE", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID,  BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_bs);
	PushInstructionInfo(FileManager, "JA", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID,  BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_bs);
	PushInstructionInfo(FileManager, "JS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID,  BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_bs);
	PushInstructionInfo(FileManager, "JNS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID,  BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_bs);
	PushInstructionInfo(FileManager, "JPE", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID,  BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_bs);
	PushInstructionInfo(FileManager, "JPO", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID,  BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_bs);
	PushInstructionInfo(FileManager, "JL", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID,  BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_bs);
	PushInstructionInfo(FileManager, "JGE", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID,  BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_bs);
	PushInstructionInfo(FileManager, "JLE", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID,  BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_bs);
	PushInstructionInfo(FileManager, "JG", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID,  BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "ADD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "OR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "ADC", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "SBB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "AND", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "SUB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "XOR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "CMP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_vds);
	PushInstructionInfo(FileManager, "ADD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_vds);
	PushInstructionInfo(FileManager, "OR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_vds);
	PushInstructionInfo(FileManager, "ADC", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_vds);
	PushInstructionInfo(FileManager, "SBB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_vds);
	PushInstructionInfo(FileManager, "AND", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_vds);
	PushInstructionInfo(FileManager, "SUB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_vds);
	PushInstructionInfo(FileManager, "XOR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_vds);
	PushInstructionInfo(FileManager, "CMP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "ADD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "OR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "ADC", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "SBB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "AND", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "SUB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "XOR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "CMP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_bs);
	PushInstructionInfo(FileManager, "ADD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_bs);
	PushInstructionInfo(FileManager, "OR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_bs);
	PushInstructionInfo(FileManager, "ADC", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_bs);
	PushInstructionInfo(FileManager, "SBB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_bs);
	PushInstructionInfo(FileManager, "AND", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_bs);
	PushInstructionInfo(FileManager, "SUB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_bs);
	PushInstructionInfo(FileManager, "XOR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_bs);
	PushInstructionInfo(FileManager, "CMP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_G,OperandSize_b);
	PushInstructionInfo(FileManager, "TEST", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushInstructionInfo(FileManager, "TEST", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_b);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushInstructionInfo(FileManager, "XCHG", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushInstructionInfo(FileManager, "XCHG", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_G,OperandSize_b);
	PushInstructionInfo(FileManager, "MOV", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushInstructionInfo(FileManager, "MOV", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_b);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushInstructionInfo(FileManager, "MOV", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushInstructionInfo(FileManager, "MOV", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_R,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_S,OperandSize_w);
	PushInstructionInfo(FileManager, "MOV", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_w);
	PushOperand(&OperandArray, OperandType_S,OperandSize_w);
	PushInstructionInfo(FileManager, "MOV", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_M,OperandSize_Invalid);
	PushInstructionInfo(FileManager, "LEA", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_S,OperandSize_w);
	PushOperand(&OperandArray, OperandType_E,OperandSize_w);
	PushInstructionInfo(FileManager, "MOV", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_v);
	PushInstructionInfo(FileManager, "POP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "NOP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_Z,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_AX,OperandSize_vqp);
	PushInstructionInfo(FileManager, "XCHG", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID,  LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "PAUSE", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_GR,OperandSize_vqp);
	BeginInstructionInfoGroup(FileManager, "CBWGGR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "CBW",16, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "CWDE",32, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "CDQE",64, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);
	EndInstructionInfoGroup(FileManager);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_GR,OperandSize_vqp);
	BeginInstructionInfoGroup(FileManager, "CWDGR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "CWD",16, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "CDQ",32, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "CQO",64, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);
	EndInstructionInfoGroup(FileManager);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_A,OperandSize_p);
	PushInstructionInfo(FileManager, "CALLF", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FWAIT", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_GR,OperandSize_f);
	BeginInstructionInfoGroup(FileManager, "PUSHFGR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "PUSHF",16, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "PUSHFD",32, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "PUSHFQ",64, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);
	EndInstructionInfoGroup(FileManager);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_GR,OperandSize_f);
	BeginInstructionInfoGroup(FileManager, "POPFGR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "POPF",16, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "POPFD",32, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "POPFQ",64, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);
	EndInstructionInfoGroup(FileManager);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "SAHF", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "LAHF", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_AX,OperandSize_b);
	PushOperand(&OperandArray, OperandType_O,OperandSize_b);
	PushInstructionInfo(FileManager, "MOV", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_AX,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_O,OperandSize_vqp);
	PushInstructionInfo(FileManager, "MOV", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_O,OperandSize_b);
	PushOperand(&OperandArray, OperandType_AX,OperandSize_b);
	PushInstructionInfo(FileManager, "MOV", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_O,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_AX,OperandSize_vqp);
	PushInstructionInfo(FileManager, "MOV", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "MOVSB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray,  REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_Y,OperandSize_vqp);
	BeginInstructionInfoGroup(FileManager, "MOVSGR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "MOVSW",16, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray,  REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "MOVSD",32, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray,  REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "MOVSQ",64, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray,  REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);
	EndInstructionInfoGroup(FileManager);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "CMPSB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray,  REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_Y,OperandSize_vqp);
	BeginInstructionInfoGroup(FileManager, "CMPSGR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "CMPSW",16, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray,  REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "CMPSD",32, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray,  REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "CMPSQ",64, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray,  REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);
	EndInstructionInfoGroup(FileManager);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_AX,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "TEST", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_AX,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_vds);
	PushInstructionInfo(FileManager, "TEST", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "STOSB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray,  REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_Y,OperandSize_vqp);
	BeginInstructionInfoGroup(FileManager, "STOSGR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "STOSW",16, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray,  REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "STOSD",32, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray,  REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "STOSQ",64, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray,  REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);
	EndInstructionInfoGroup(FileManager);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "LODSB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray,  REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_X,OperandSize_vqp);
	BeginInstructionInfoGroup(FileManager, "LODSGR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "LODSW",16, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray,  REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "LODSD",32, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray,  REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "LODSQ",64, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray,  REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);
	EndInstructionInfoGroup(FileManager);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "SCASB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray,  REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_Y,OperandSize_vqp);
	BeginInstructionInfoGroup(FileManager, "SCASGR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "SCASW",16, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray,  REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "SCASD",32, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray,  REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "SCASQ",64, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray,  REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);
	EndInstructionInfoGroup(FileManager);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_Z,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "MOV", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_Z,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_vqp);
	PushInstructionInfo(FileManager, "MOV", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "ROL", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "ROR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "RCL", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "RCR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "SAL", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "SHR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "SAL", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "SAR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "ROL", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "ROR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "RCL", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "RCR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "SAL", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "SHR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "SAL", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "SAR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_I,OperandSize_w);
	PushInstructionInfo(FileManager, "RETN", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "RETN", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_v);
	PushOperand(&OperandArray, OperandType_M,OperandSize_p);
	PushInstructionInfo(FileManager, "LES", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_v);
	PushOperand(&OperandArray, OperandType_M,OperandSize_p);
	PushInstructionInfo(FileManager, "LDS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "MOV", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_vds);
	PushInstructionInfo(FileManager, "MOV", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_I,OperandSize_w);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "ENTER", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "LEAVE", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_I,OperandSize_w);
	PushInstructionInfo(FileManager, "RETF", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "RETF", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_3,OperandSize_Invalid);
	PushInstructionInfo(FileManager, "INT", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "INT", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "INTO", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_GR,OperandSize_vqp);
	BeginInstructionInfoGroup(FileManager, "IRETGR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "IRET",16, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "IRETD",32, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "IRETQ",64, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);
	EndInstructionInfoGroup(FileManager);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_1,OperandSize_Invalid);
	PushInstructionInfo(FileManager, "ROL", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_1,OperandSize_Invalid);
	PushInstructionInfo(FileManager, "ROR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_1,OperandSize_Invalid);
	PushInstructionInfo(FileManager, "RCL", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_1,OperandSize_Invalid);
	PushInstructionInfo(FileManager, "RCR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_1,OperandSize_Invalid);
	PushInstructionInfo(FileManager, "SAL", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_1,OperandSize_Invalid);
	PushInstructionInfo(FileManager, "SHR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_1,OperandSize_Invalid);
	PushInstructionInfo(FileManager, "SAL", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_1,OperandSize_Invalid);
	PushInstructionInfo(FileManager, "SAR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_1,OperandSize_Invalid);
	PushInstructionInfo(FileManager, "ROL", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_1,OperandSize_Invalid);
	PushInstructionInfo(FileManager, "ROR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_1,OperandSize_Invalid);
	PushInstructionInfo(FileManager, "RCL", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_1,OperandSize_Invalid);
	PushInstructionInfo(FileManager, "RCR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_1,OperandSize_Invalid);
	PushInstructionInfo(FileManager, "SAL", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_1,OperandSize_Invalid);
	PushInstructionInfo(FileManager, "SHR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_1,OperandSize_Invalid);
	PushInstructionInfo(FileManager, "SAL", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_1,OperandSize_Invalid);
	PushInstructionInfo(FileManager, "SAR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_CX,OperandSize_b);
	PushInstructionInfo(FileManager, "ROL", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_CX,OperandSize_b);
	PushInstructionInfo(FileManager, "ROR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_CX,OperandSize_b);
	PushInstructionInfo(FileManager, "RCL", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_CX,OperandSize_b);
	PushInstructionInfo(FileManager, "RCR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_CX,OperandSize_b);
	PushInstructionInfo(FileManager, "SAL", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_CX,OperandSize_b);
	PushInstructionInfo(FileManager, "SHR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_CX,OperandSize_b);
	PushInstructionInfo(FileManager, "SAL", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_CX,OperandSize_b);
	PushInstructionInfo(FileManager, "SAR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_CX,OperandSize_b);
	PushInstructionInfo(FileManager, "ROL", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_CX,OperandSize_b);
	PushInstructionInfo(FileManager, "ROR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_CX,OperandSize_b);
	PushInstructionInfo(FileManager, "RCL", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_CX,OperandSize_b);
	PushInstructionInfo(FileManager, "RCR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_CX,OperandSize_b);
	PushInstructionInfo(FileManager, "SAL", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_CX,OperandSize_b);
	PushInstructionInfo(FileManager, "SHR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_CX,OperandSize_b);
	PushInstructionInfo(FileManager, "SAL", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_CX,OperandSize_b);
	PushInstructionInfo(FileManager, "SAR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "AAM", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "AMX", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "AAD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "ADX", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "SETALC", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "XLATB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_ST,OperandSize_er);
	PushOperand(&OperandArray, OperandType_EST,OperandSize_er);
	PushInstructionInfo(FileManager, "FADD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_sr);
	PushInstructionInfo(FileManager, "FADD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_ST,OperandSize_er);
	PushOperand(&OperandArray, OperandType_EST,OperandSize_er);
	PushInstructionInfo(FileManager, "FMUL", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_sr);
	PushInstructionInfo(FileManager, "FMUL", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FCOM", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_ES,OperandSize_sr);
	PushInstructionInfo(FileManager, "FCOM", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FCOMP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&O