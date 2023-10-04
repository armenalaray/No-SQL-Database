internal void CreateInstructionInfos_16(file_manager * FileManager)
{

	operand_array OperandArray = {};
	BeginFileSection(FileManager, FileSection_instruction_info_16);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_G,OperandSize_b);
	PushInstructionInfo(FileManager, "ADD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushInstructionInfo(FileManager, "ADD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_b);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushInstructionInfo(FileManager, "ADD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushInstructionInfo(FileManager, "ADD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_AX,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "ADD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_AX,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_vds);
	PushInstructionInfo(FileManager, "ADD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_ESEG,OperandSize_Invalid);
	PushInstructionInfo(FileManager, "PUSH", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_ESEG,OperandSize_Invalid);
	PushInstructionInfo(FileManager, "POP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_G,OperandSize_b);
	PushInstructionInfo(FileManager, "OR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushInstructionInfo(FileManager, "OR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_b);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushInstructionInfo(FileManager, "OR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushInstructionInfo(FileManager, "OR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_AX,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "OR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_AX,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_vds);
	PushInstructionInfo(FileManager, "OR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_CSEG,OperandSize_Invalid);
	PushInstructionInfo(FileManager, "PUSH", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_G,OperandSize_b);
	PushInstructionInfo(FileManager, "ADC", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushInstructionInfo(FileManager, "ADC", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_b);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushInstructionInfo(FileManager, "ADC", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushInstructionInfo(FileManager, "ADC", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_AX,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "ADC", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_AX,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_vds);
	PushInstructionInfo(FileManager, "ADC", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_SSEG,OperandSize_Invalid);
	PushInstructionInfo(FileManager, "PUSH", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_SSEG,OperandSize_Invalid);
	PushInstructionInfo(FileManager, "POP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_G,OperandSize_b);
	PushInstructionInfo(FileManager, "SBB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushInstructionInfo(FileManager, "SBB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_b);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushInstructionInfo(FileManager, "SBB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushInstructionInfo(FileManager, "SBB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_AX,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "SBB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_AX,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_vds);
	PushInstructionInfo(FileManager, "SBB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_DSEG,OperandSize_Invalid);
	PushInstructionInfo(FileManager, "PUSH", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_DSEG,OperandSize_Invalid);
	PushInstructionInfo(FileManager, "POP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_G,OperandSize_b);
	PushInstructionInfo(FileManager, "AND", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushInstructionInfo(FileManager, "AND", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_b);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushInstructionInfo(FileManager, "AND", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushInstructionInfo(FileManager, "AND", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_AX,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "AND", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_AX,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_vds);
	PushInstructionInfo(FileManager, "AND", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "DAA", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_G,OperandSize_b);
	PushInstructionInfo(FileManager, "SUB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushInstructionInfo(FileManager, "SUB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_b);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushInstructionInfo(FileManager, "SUB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushInstructionInfo(FileManager, "SUB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_AX,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "SUB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_AX,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_vds);
	PushInstructionInfo(FileManager, "SUB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "NTAKEN", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "DAS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_G,OperandSize_b);
	PushInstructionInfo(FileManager, "XOR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushInstructionInfo(FileManager, "XOR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_b);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushInstructionInfo(FileManager, "XOR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushInstructionInfo(FileManager, "XOR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_AX,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "XOR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_AX,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_vds);
	PushInstructionInfo(FileManager, "XOR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

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
	PushInstructionInfo(FileManager, "INC", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_Z,OperandSize_v);
	PushInstructionInfo(FileManager, "DEC", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

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
	PushInstructionInfo(FileManager, "INSB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_Y,OperandSize_v);
	BeginInstructionInfoGroup(FileManager, "INSGR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "INSW",16, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "INSD",32, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);
	EndInstructionInfoGroup(FileManager);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "OUTSB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_X,OperandSize_v);
	BeginInstructionInfoGroup(FileManager, "OUTSGR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "OUTSW",16, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "OUTSD",32, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);
	EndInstructionInfoGroup(FileManager);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_bs);
	PushInstructionInfo(FileManager, "JO", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_bs);
	PushInstructionInfo(FileManager, "JNO", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_bs);
	PushInstructionInfo(FileManager, "JB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_bs);
	PushInstructionInfo(FileManager, "JAE", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_bs);
	PushInstructionInfo(FileManager, "JE", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_bs);
	PushInstructionInfo(FileManager, "JNE", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_bs);
	PushInstructionInfo(FileManager, "JBE", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_bs);
	PushInstructionInfo(FileManager, "JA", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_bs);
	PushInstructionInfo(FileManager, "JS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_bs);
	PushInstructionInfo(FileManager, "JNS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_bs);
	PushInstructionInfo(FileManager, "JPE", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_bs);
	PushInstructionInfo(FileManager, "JPO", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_bs);
	PushInstructionInfo(FileManager, "JL", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_bs);
	PushInstructionInfo(FileManager, "JGE", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_bs);
	PushInstructionInfo(FileManager, "JLE", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_bs);
	PushInstructionInfo(FileManager, "JG", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "ADD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "OR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "ADC", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "SBB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "AND", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "SUB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "XOR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "CMP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_vds);
	PushInstructionInfo(FileManager, "ADD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_vds);
	PushInstructionInfo(FileManager, "OR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_vds);
	PushInstructionInfo(FileManager, "ADC", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_vds);
	PushInstructionInfo(FileManager, "SBB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_vds);
	PushInstructionInfo(FileManager, "AND", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_vds);
	PushInstructionInfo(FileManager, "SUB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_vds);
	PushInstructionInfo(FileManager, "XOR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_vds);
	PushInstructionInfo(FileManager, "CMP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "ADD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "OR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "ADC", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "SBB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "AND", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "SUB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "XOR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "CMP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_bs);
	PushInstructionInfo(FileManager, "ADD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_bs);
	PushInstructionInfo(FileManager, "OR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_bs);
	PushInstructionInfo(FileManager, "ADC", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_bs);
	PushInstructionInfo(FileManager, "SBB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_bs);
	PushInstructionInfo(FileManager, "AND", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_bs);
	PushInstructionInfo(FileManager, "SUB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_bs);
	PushInstructionInfo(FileManager, "XOR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

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
	PushInstructionInfo(FileManager, "XCHG", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushInstructionInfo(FileManager, "XCHG", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

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
	PushInstructionInfo(FileManager, "XCHG", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

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
	PushInstructionInfo(FileManager, "MOVSB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_Y,OperandSize_vqp);
	BeginInstructionInfoGroup(FileManager, "MOVSGR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "MOVSW",16, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "MOVSD",32, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "MOVSQ",64, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);
	EndInstructionInfoGroup(FileManager);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "CMPSB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_Y,OperandSize_vqp);
	BeginInstructionInfoGroup(FileManager, "CMPSGR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "CMPSW",16, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "CMPSD",32, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "CMPSQ",64, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);
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
	PushInstructionInfo(FileManager, "STOSB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_Y,OperandSize_vqp);
	BeginInstructionInfoGroup(FileManager, "STOSGR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "STOSW",16, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "STOSD",32, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "STOSQ",64, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);
	EndInstructionInfoGroup(FileManager);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "LODSB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_X,OperandSize_vqp);
	BeginInstructionInfoGroup(FileManager, "LODSGR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "LODSW",16, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "LODSD",32, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "LODSQ",64, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);
	EndInstructionInfoGroup(FileManager);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "SCASB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_Y,OperandSize_vqp);
	BeginInstructionInfoGroup(FileManager, "SCASGR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "SCASW",16, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "SCASD",32, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfoEntry(FileManager, "SCASQ",64, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);
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
	PushOperand(&OperandArray, OperandType_ES,OperandSize_sr);
	PushInstructionInfo(FileManager, "FCOMP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_ST,OperandSize_er);
	PushOperand(&OperandArray, OperandType_EST,OperandSize_er);
	PushInstructionInfo(FileManager, "FSUB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_sr);
	PushInstructionInfo(FileManager, "FSUB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_ST,OperandSize_er);
	PushOperand(&OperandArray, OperandType_EST,OperandSize_er);
	PushInstructionInfo(FileManager, "FSUBR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_sr);
	PushInstructionInfo(FileManager, "FSUBR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_ST,OperandSize_er);
	PushOperand(&OperandArray, OperandType_EST,OperandSize_er);
	PushInstructionInfo(FileManager, "FDIV", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_sr);
	PushInstructionInfo(FileManager, "FDIV", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_ST,OperandSize_er);
	PushOperand(&OperandArray, OperandType_EST,OperandSize_er);
	PushInstructionInfo(FileManager, "FDIVR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_sr);
	PushInstructionInfo(FileManager, "FDIVR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_ES,OperandSize_sr);
	PushInstructionInfo(FileManager, "FLD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FXCH", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_EST,OperandSize_er);
	PushInstructionInfo(FileManager, "FXCH", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FNOP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_sr);
	PushInstructionInfo(FileManager, "FST", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_EST,OperandSize_er);
	PushInstructionInfo(FileManager, "FSTP1", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_sr);
	PushInstructionInfo(FileManager, "FSTP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FCHS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FABS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FTST", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FXAM", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_e);
	PushInstructionInfo(FileManager, "FLDENV", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FLD1", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FLDL2T", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FLDL2E", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FLDPI", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FLDLG2", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FLDLN2", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FLDZ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_w);
	PushInstructionInfo(FileManager, "FLDCW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "F2XM1", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FYL2X", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FPTAN", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FPATAN", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FXTRACT", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FPREM1", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FDECSTP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FINCSTP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_e);
	PushInstructionInfo(FileManager, "FNSTENV", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_e);
	PushInstructionInfo(FileManager, "FSTENV", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FPREM", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FYL2XP1", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FSQRT", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FSINCOS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FRNDINT", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FSCALE", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FSIN", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FCOS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_w);
	PushInstructionInfo(FileManager, "FNSTCW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_w);
	PushInstructionInfo(FileManager, "FSTCW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_ST,OperandSize_er);
	PushOperand(&OperandArray, OperandType_EST,OperandSize_er);
	PushInstructionInfo(FileManager, "FCMOVB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_di);
	PushInstructionInfo(FileManager, "FIADD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_ST,OperandSize_er);
	PushOperand(&OperandArray, OperandType_EST,OperandSize_er);
	PushInstructionInfo(FileManager, "FCMOVE", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_di);
	PushInstructionInfo(FileManager, "FIMUL", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_ST,OperandSize_er);
	PushOperand(&OperandArray, OperandType_EST,OperandSize_er);
	PushInstructionInfo(FileManager, "FCMOVBE", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_di);
	PushInstructionInfo(FileManager, "FICOM", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_ST,OperandSize_er);
	PushOperand(&OperandArray, OperandType_EST,OperandSize_er);
	PushInstructionInfo(FileManager, "FCMOVU", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_di);
	PushInstructionInfo(FileManager, "FICOMP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_di);
	PushInstructionInfo(FileManager, "FISUB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FUCOMPP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_di);
	PushInstructionInfo(FileManager, "FISUBR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_di);
	PushInstructionInfo(FileManager, "FIDIV", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_di);
	PushInstructionInfo(FileManager, "FIDIVR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_ST,OperandSize_er);
	PushOperand(&OperandArray, OperandType_EST,OperandSize_er);
	PushInstructionInfo(FileManager, "FCMOVNB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_di);
	PushInstructionInfo(FileManager, "FILD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_ST,OperandSize_er);
	PushOperand(&OperandArray, OperandType_EST,OperandSize_er);
	PushInstructionInfo(FileManager, "FCMOVNE", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_di);
	PushInstructionInfo(FileManager, "FISTTP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_ST,OperandSize_er);
	PushOperand(&OperandArray, OperandType_EST,OperandSize_er);
	PushInstructionInfo(FileManager, "FCMOVNBE", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_di);
	PushInstructionInfo(FileManager, "FIST", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_ST,OperandSize_er);
	PushOperand(&OperandArray, OperandType_EST,OperandSize_er);
	PushInstructionInfo(FileManager, "FCMOVNU", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_di);
	PushInstructionInfo(FileManager, "FISTP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FNENI", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FENI", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FNENI", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FNDISI", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FDISI", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FNDISI", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FNCLEX", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FCLEX", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FNINIT", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FINIT", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FNSETPM", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FSETPM", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FNSETPM", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_ST,OperandSize_er);
	PushOperand(&OperandArray, OperandType_EST,OperandSize_er);
	PushInstructionInfo(FileManager, "FUCOMI", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_er);
	PushInstructionInfo(FileManager, "FLD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_ST,OperandSize_er);
	PushOperand(&OperandArray, OperandType_EST,OperandSize_er);
	PushInstructionInfo(FileManager, "FCOMI", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_er);
	PushInstructionInfo(FileManager, "FSTP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_EST,OperandSize_er);
	PushOperand(&OperandArray, OperandType_ST,OperandSize_er);
	PushInstructionInfo(FileManager, "FADD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_dr);
	PushInstructionInfo(FileManager, "FADD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_EST,OperandSize_er);
	PushOperand(&OperandArray, OperandType_ST,OperandSize_er);
	PushInstructionInfo(FileManager, "FMUL", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_dr);
	PushInstructionInfo(FileManager, "FMUL", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_EST,OperandSize_er);
	PushInstructionInfo(FileManager, "FCOM2", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_dr);
	PushInstructionInfo(FileManager, "FCOM", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_EST,OperandSize_er);
	PushInstructionInfo(FileManager, "FCOMP3", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_dr);
	PushInstructionInfo(FileManager, "FCOMP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_EST,OperandSize_er);
	PushOperand(&OperandArray, OperandType_ST,OperandSize_er);
	PushInstructionInfo(FileManager, "FSUBR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_dr);
	PushInstructionInfo(FileManager, "FSUB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_EST,OperandSize_er);
	PushOperand(&OperandArray, OperandType_ST,OperandSize_er);
	PushInstructionInfo(FileManager, "FSUB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_dr);
	PushInstructionInfo(FileManager, "FSUBR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_EST,OperandSize_er);
	PushOperand(&OperandArray, OperandType_ST,OperandSize_er);
	PushInstructionInfo(FileManager, "FDIVR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_dr);
	PushInstructionInfo(FileManager, "FDIV", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_EST,OperandSize_er);
	PushOperand(&OperandArray, OperandType_ST,OperandSize_er);
	PushInstructionInfo(FileManager, "FDIV", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_dr);
	PushInstructionInfo(FileManager, "FDIVR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_EST,OperandSize_er);
	PushInstructionInfo(FileManager, "FFREE", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_dr);
	PushInstructionInfo(FileManager, "FLD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_EST,OperandSize_er);
	PushInstructionInfo(FileManager, "FXCH4", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_qi);
	PushInstructionInfo(FileManager, "FISTTP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_EST,OperandSize_er);
	PushInstructionInfo(FileManager, "FST", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_dr);
	PushInstructionInfo(FileManager, "FST", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_EST,OperandSize_er);
	PushInstructionInfo(FileManager, "FSTP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_dr);
	PushInstructionInfo(FileManager, "FSTP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_EST,OperandSize_er);
	PushInstructionInfo(FileManager, "FUCOM", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_st);
	PushInstructionInfo(FileManager, "FRSTOR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FUCOM", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FUCOMP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_EST,OperandSize_er);
	PushInstructionInfo(FileManager, "FUCOMP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_st);
	PushInstructionInfo(FileManager, "FNSAVE", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_st);
	PushInstructionInfo(FileManager, "FSAVE", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_w);
	PushInstructionInfo(FileManager, "FNSTSW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_w);
	PushInstructionInfo(FileManager, "FSTSW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FADDP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_EST,OperandSize_er);
	PushOperand(&OperandArray, OperandType_ST,OperandSize_er);
	PushInstructionInfo(FileManager, "FADDP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_wi);
	PushInstructionInfo(FileManager, "FIADD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FMULP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_EST,OperandSize_er);
	PushOperand(&OperandArray, OperandType_ST,OperandSize_er);
	PushInstructionInfo(FileManager, "FMULP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_wi);
	PushInstructionInfo(FileManager, "FIMUL", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_EST,OperandSize_er);
	PushInstructionInfo(FileManager, "FCOMP5", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_wi);
	PushInstructionInfo(FileManager, "FICOM", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FCOMPP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_wi);
	PushInstructionInfo(FileManager, "FICOMP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FSUBRP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_EST,OperandSize_er);
	PushOperand(&OperandArray, OperandType_ST,OperandSize_er);
	PushInstructionInfo(FileManager, "FSUBRP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_wi);
	PushInstructionInfo(FileManager, "FISUB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FSUBP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_EST,OperandSize_er);
	PushOperand(&OperandArray, OperandType_ST,OperandSize_er);
	PushInstructionInfo(FileManager, "FSUBP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_wi);
	PushInstructionInfo(FileManager, "FISUBR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FDIVRP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_EST,OperandSize_er);
	PushOperand(&OperandArray, OperandType_ST,OperandSize_er);
	PushInstructionInfo(FileManager, "FDIVRP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_wi);
	PushInstructionInfo(FileManager, "FIDIV", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "FDIVP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_EST,OperandSize_er);
	PushOperand(&OperandArray, OperandType_ST,OperandSize_er);
	PushInstructionInfo(FileManager, "FDIVP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_wi);
	PushInstructionInfo(FileManager, "FIDIVR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_EST,OperandSize_er);
	PushInstructionInfo(FileManager, "FFREEP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_wi);
	PushInstructionInfo(FileManager, "FILD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_EST,OperandSize_er);
	PushInstructionInfo(FileManager, "FXCH7", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_wi);
	PushInstructionInfo(FileManager, "FISTTP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_EST,OperandSize_er);
	PushInstructionInfo(FileManager, "FSTP8", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_wi);
	PushInstructionInfo(FileManager, "FIST", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_EST,OperandSize_er);
	PushInstructionInfo(FileManager, "FSTP9", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_wi);
	PushInstructionInfo(FileManager, "FISTP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_AX,OperandSize_w);
	PushInstructionInfo(FileManager, "FNSTSW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_bcd);
	PushInstructionInfo(FileManager, "FBLD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_AX,OperandSize_w);
	PushInstructionInfo(FileManager, "FSTSW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_ST,OperandSize_er);
	PushOperand(&OperandArray, OperandType_EST,OperandSize_er);
	PushInstructionInfo(FileManager, "FUCOMIP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_qi);
	PushInstructionInfo(FileManager, "FILD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_ST,OperandSize_er);
	PushOperand(&OperandArray, OperandType_EST,OperandSize_er);
	PushInstructionInfo(FileManager, "FCOMIP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_bcd);
	PushInstructionInfo(FileManager, "FBSTP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_qi);
	PushInstructionInfo(FileManager, "FISTP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_bs);
	PushInstructionInfo(FileManager, "LOOPNZ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_bs);
	PushInstructionInfo(FileManager, "LOOPZ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_bs);
	PushInstructionInfo(FileManager, "LOOP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_GR,OperandSize_cxz);
	BeginInstructionInfoGroup(FileManager, "JCXZGR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_bs);
	PushInstructionInfoEntry(FileManager, "JCXZ",16, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_bs);
	PushInstructionInfoEntry(FileManager, "JECXZ",32, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_bs);
	PushInstructionInfoEntry(FileManager, "JRCXZ",64, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);
	EndInstructionInfoGroup(FileManager);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_AX,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "IN", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_AX,OperandSize_v);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "IN", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushOperand(&OperandArray, OperandType_AX,OperandSize_b);
	PushInstructionInfo(FileManager, "OUT", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushOperand(&OperandArray, OperandType_AX,OperandSize_v);
	PushInstructionInfo(FileManager, "OUT", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_vds);
	PushInstructionInfo(FileManager, "CALL", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_vds);
	PushInstructionInfo(FileManager, "JMP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_A,OperandSize_p);
	PushInstructionInfo(FileManager, "JMPF", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_bs);
	PushInstructionInfo(FileManager, "JMP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_AX,OperandSize_b);
	PushOperand(&OperandArray, OperandType_DX,OperandSize_w);
	PushInstructionInfo(FileManager, "IN", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_AX,OperandSize_v);
	PushOperand(&OperandArray, OperandType_DX,OperandSize_w);
	PushInstructionInfo(FileManager, "IN", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_DX,OperandSize_w);
	PushOperand(&OperandArray, OperandType_AX,OperandSize_b);
	PushInstructionInfo(FileManager, "OUT", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_DX,OperandSize_w);
	PushOperand(&OperandArray, OperandType_AX,OperandSize_v);
	PushInstructionInfo(FileManager, "OUT", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "ICEBP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "HLT", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "CMC", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "TEST", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "TEST", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushInstructionInfo(FileManager, "NOT", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushInstructionInfo(FileManager, "NEG", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushInstructionInfo(FileManager, "MUL", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushInstructionInfo(FileManager, "IMUL", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushInstructionInfo(FileManager, "DIV", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushInstructionInfo(FileManager, "IDIV", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_vqp);
	PushInstructionInfo(FileManager, "TEST", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_vqp);
	PushInstructionInfo(FileManager, "TEST", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushInstructionInfo(FileManager, "NOT", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushInstructionInfo(FileManager, "NEG", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushInstructionInfo(FileManager, "MUL", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushInstructionInfo(FileManager, "IMUL", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushInstructionInfo(FileManager, "DIV", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushInstructionInfo(FileManager, "IDIV", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "CLC", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "STC", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "CLI", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "STI", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "CLD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "STD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushInstructionInfo(FileManager, "INC", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushInstructionInfo(FileManager, "DEC", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushInstructionInfo(FileManager, "INC", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushInstructionInfo(FileManager, "DEC", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_v);
	PushInstructionInfo(FileManager, "CALL", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_ptp);
	PushInstructionInfo(FileManager, "CALLF", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_v);
	PushInstructionInfo(FileManager, "JMP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_ptp);
	PushInstructionInfo(FileManager, "JMPF", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_v);
	PushInstructionInfo(FileManager, "PUSH", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "JMPE", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_s);
	PushInstructionInfo(FileManager, "SGDT", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "MONITOR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "MWAIT", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_s);
	PushInstructionInfo(FileManager, "SIDT", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "XGETBV", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "XSETBV", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_s);
	PushInstructionInfo(FileManager, "LGDT", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_s);
	PushInstructionInfo(FileManager, "LIDT", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_R,OperandSize_vqp);
	PushInstructionInfo(FileManager, "SMSW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_w);
	PushInstructionInfo(FileManager, "SMSW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_w);
	PushInstructionInfo(FileManager, "LMSW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "RDTSCP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_Invalid);
	PushInstructionInfo(FileManager, "INVLPG", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "CLTS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "INVD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "WBINVD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "UD2", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_v);
	PushInstructionInfo(FileManager, "NOP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ps);
	PushOperand(&OperandArray, OperandType_W,OperandSize_ps);
	PushInstructionInfo(FileManager, "MOVUPS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ss);
	PushOperand(&OperandArray, OperandType_W,OperandSize_ss);
	PushInstructionInfo(FileManager, "MOVSS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_pd);
	PushOperand(&OperandArray, OperandType_W,OperandSize_pd);
	PushInstructionInfo(FileManager, "MOVUPD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_sd);
	PushOperand(&OperandArray, OperandType_W,OperandSize_sd);
	PushInstructionInfo(FileManager, "MOVSD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_W,OperandSize_ps);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ps);
	PushInstructionInfo(FileManager, "MOVUPS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_W,OperandSize_ss);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ss);
	PushInstructionInfo(FileManager, "MOVSS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_W,OperandSize_pd);
	PushOperand(&OperandArray, OperandType_V,OperandSize_pd);
	PushInstructionInfo(FileManager, "MOVUPD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_W,OperandSize_sd);
	PushOperand(&OperandArray, OperandType_V,OperandSize_sd);
	PushInstructionInfo(FileManager, "MOVSD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_q);
	PushOperand(&OperandArray, OperandType_U,OperandSize_q);
	PushInstructionInfo(FileManager, "MOVHLPS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_q);
	PushOperand(&OperandArray, OperandType_M,OperandSize_q);
	PushInstructionInfo(FileManager, "MOVLPS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_q);
	PushOperand(&OperandArray, OperandType_M,OperandSize_q);
	PushInstructionInfo(FileManager, "MOVLPD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_q);
	PushOperand(&OperandArray, OperandType_W,OperandSize_q);
	PushInstructionInfo(FileManager, "MOVDDUP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_q);
	PushOperand(&OperandArray, OperandType_W,OperandSize_q);
	PushInstructionInfo(FileManager, "MOVSLDUP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_q);
	PushOperand(&OperandArray, OperandType_V,OperandSize_q);
	PushInstructionInfo(FileManager, "MOVLPS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_q);
	PushOperand(&OperandArray, OperandType_V,OperandSize_q);
	PushInstructionInfo(FileManager, "MOVLPD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ps);
	PushOperand(&OperandArray, OperandType_W,OperandSize_q);
	PushInstructionInfo(FileManager, "UNPCKLPS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_pd);
	PushOperand(&OperandArray, OperandType_W,OperandSize_pd);
	PushInstructionInfo(FileManager, "UNPCKLPD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ps);
	PushOperand(&OperandArray, OperandType_W,OperandSize_q);
	PushInstructionInfo(FileManager, "UNPCKHPS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_pd);
	PushOperand(&OperandArray, OperandType_W,OperandSize_pd);
	PushInstructionInfo(FileManager, "UNPCKHPD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_q);
	PushOperand(&OperandArray, OperandType_U,OperandSize_q);
	PushInstructionInfo(FileManager, "MOVLHPS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_q);
	PushOperand(&OperandArray, OperandType_M,OperandSize_q);
	PushInstructionInfo(FileManager, "MOVHPS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_q);
	PushOperand(&OperandArray, OperandType_M,OperandSize_q);
	PushInstructionInfo(FileManager, "MOVHPD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_q);
	PushOperand(&OperandArray, OperandType_W,OperandSize_q);
	PushInstructionInfo(FileManager, "MOVSHDUP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_q);
	PushOperand(&OperandArray, OperandType_V,OperandSize_q);
	PushInstructionInfo(FileManager, "MOVHPS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_q);
	PushOperand(&OperandArray, OperandType_V,OperandSize_q);
	PushInstructionInfo(FileManager, "MOVHPD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_b);
	PushInstructionInfo(FileManager, "PREFETCHNTA", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_b);
	PushInstructionInfo(FileManager, "PREFETCHT0", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_b);
	PushInstructionInfo(FileManager, "PREFETCHT1", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_b);
	PushInstructionInfo(FileManager, "PREFETCHT2", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_v);
	PushInstructionInfo(FileManager, "HINT_NOP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_v);
	PushInstructionInfo(FileManager, "HINT_NOP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_v);
	PushInstructionInfo(FileManager, "HINT_NOP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_v);
	PushInstructionInfo(FileManager, "HINT_NOP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_v);
	PushInstructionInfo(FileManager, "HINT_NOP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_v);
	PushInstructionInfo(FileManager, "HINT_NOP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_v);
	PushInstructionInfo(FileManager, "HINT_NOP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_v);
	PushInstructionInfo(FileManager, "HINT_NOP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_v);
	PushInstructionInfo(FileManager, "HINT_NOP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_v);
	PushInstructionInfo(FileManager, "HINT_NOP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_v);
	PushInstructionInfo(FileManager, "HINT_NOP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_v);
	PushInstructionInfo(FileManager, "NOP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_v);
	PushInstructionInfo(FileManager, "HINT_NOP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_v);
	PushInstructionInfo(FileManager, "HINT_NOP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_v);
	PushInstructionInfo(FileManager, "HINT_NOP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_v);
	PushInstructionInfo(FileManager, "HINT_NOP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_v);
	PushInstructionInfo(FileManager, "HINT_NOP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_v);
	PushInstructionInfo(FileManager, "HINT_NOP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_v);
	PushInstructionInfo(FileManager, "HINT_NOP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_v);
	PushInstructionInfo(FileManager, "HINT_NOP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_H,OperandSize_d);
	PushOperand(&OperandArray, OperandType_C,OperandSize_d);
	PushInstructionInfo(FileManager, "MOV", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_H,OperandSize_d);
	PushOperand(&OperandArray, OperandType_D,OperandSize_d);
	PushInstructionInfo(FileManager, "MOV", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_C,OperandSize_d);
	PushOperand(&OperandArray, OperandType_H,OperandSize_d);
	PushInstructionInfo(FileManager, "MOV", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_D,OperandSize_d);
	PushOperand(&OperandArray, OperandType_H,OperandSize_d);
	PushInstructionInfo(FileManager, "MOV", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_H,OperandSize_d);
	PushOperand(&OperandArray, OperandType_T,OperandSize_d);
	PushInstructionInfo(FileManager, "MOV", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_T,OperandSize_d);
	PushOperand(&OperandArray, OperandType_H,OperandSize_d);
	PushInstructionInfo(FileManager, "MOV", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ps);
	PushOperand(&OperandArray, OperandType_W,OperandSize_ps);
	PushInstructionInfo(FileManager, "MOVAPS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_pd);
	PushOperand(&OperandArray, OperandType_W,OperandSize_pd);
	PushInstructionInfo(FileManager, "MOVAPD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_W,OperandSize_ps);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ps);
	PushInstructionInfo(FileManager, "MOVAPS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_W,OperandSize_pd);
	PushOperand(&OperandArray, OperandType_V,OperandSize_pd);
	PushInstructionInfo(FileManager, "MOVAPD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ps);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_pi);
	PushInstructionInfo(FileManager, "CVTPI2PS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ss);
	PushOperand(&OperandArray, OperandType_E,OperandSize_dqp);
	PushInstructionInfo(FileManager, "CVTSI2SS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_pd);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_pi);
	PushInstructionInfo(FileManager, "CVTPI2PD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_sd);
	PushOperand(&OperandArray, OperandType_E,OperandSize_dqp);
	PushInstructionInfo(FileManager, "CVTSI2SD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_ps);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ps);
	PushInstructionInfo(FileManager, "MOVNTPS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_pd);
	PushOperand(&OperandArray, OperandType_V,OperandSize_pd);
	PushInstructionInfo(FileManager, "MOVNTPD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_pi);
	PushOperand(&OperandArray, OperandType_W,OperandSize_psq);
	PushInstructionInfo(FileManager, "CVTTPS2PI", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_dqp);
	PushOperand(&OperandArray, OperandType_W,OperandSize_ss);
	PushInstructionInfo(FileManager, "CVTTSS2SI", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_pi);
	PushOperand(&OperandArray, OperandType_W,OperandSize_pd);
	PushInstructionInfo(FileManager, "CVTTPD2PI", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_dqp);
	PushOperand(&OperandArray, OperandType_W,OperandSize_sd);
	PushInstructionInfo(FileManager, "CVTTSD2SI", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_pi);
	PushOperand(&OperandArray, OperandType_W,OperandSize_psq);
	PushInstructionInfo(FileManager, "CVTPS2PI", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_dqp);
	PushOperand(&OperandArray, OperandType_W,OperandSize_ss);
	PushInstructionInfo(FileManager, "CVTSS2SI", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_pi);
	PushOperand(&OperandArray, OperandType_W,OperandSize_pd);
	PushInstructionInfo(FileManager, "CVTPD2PI", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_dqp);
	PushOperand(&OperandArray, OperandType_W,OperandSize_sd);
	PushInstructionInfo(FileManager, "CVTSD2SI", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ss);
	PushOperand(&OperandArray, OperandType_W,OperandSize_ss);
	PushInstructionInfo(FileManager, "UCOMISS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_sd);
	PushOperand(&OperandArray, OperandType_W,OperandSize_sd);
	PushInstructionInfo(FileManager, "UCOMISD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ss);
	PushOperand(&OperandArray, OperandType_W,OperandSize_ss);
	PushInstructionInfo(FileManager, "COMISS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_sd);
	PushOperand(&OperandArray, OperandType_W,OperandSize_sd);
	PushInstructionInfo(FileManager, "COMISD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "WRMSR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "RDTSC", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "RDMSR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "RDPMC", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "GETSEC", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PSHUFB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PSHUFB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PHADDW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PHADDW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PHADDD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PHADDD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PHADDSW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PHADDSW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PMADDUBSW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PMADDUBSW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PHSUBW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PHSUBW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PHSUBD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PHSUBD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PHSUBSW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PHSUBSW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PSIGNB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PSIGNB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PSIGNW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PSIGNW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PSIGND", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PSIGND", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PMULHRSW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PMULHRSW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PBLENDVB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ps);
	PushOperand(&OperandArray, OperandType_W,OperandSize_ps);
	PushInstructionInfo(FileManager, "BLENDVPS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_pd);
	PushOperand(&OperandArray, OperandType_W,OperandSize_pd);
	PushInstructionInfo(FileManager, "BLENDVPD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PTEST", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PABSB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PABSB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PABSW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PABSW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PABSD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PABSD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_U,OperandSize_dq);
	PushInstructionInfo(FileManager, "PMOVSXBW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_M,OperandSize_q);
	PushInstructionInfo(FileManager, "PMOVSXBW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_U,OperandSize_dq);
	PushInstructionInfo(FileManager, "PMOVSXBD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_M,OperandSize_d);
	PushInstructionInfo(FileManager, "PMOVSXBD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_U,OperandSize_dq);
	PushInstructionInfo(FileManager, "PMOVSXBQ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_M,OperandSize_w);
	PushInstructionInfo(FileManager, "PMOVSXBQ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_U,OperandSize_dq);
	PushInstructionInfo(FileManager, "PMOVSXWD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_M,OperandSize_q);
	PushInstructionInfo(FileManager, "PMOVSXWD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_U,OperandSize_dq);
	PushInstructionInfo(FileManager, "PMOVSXWQ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_M,OperandSize_d);
	PushInstructionInfo(FileManager, "PMOVSXWQ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_U,OperandSize_dq);
	PushInstructionInfo(FileManager, "PMOVSXDQ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_M,OperandSize_q);
	PushInstructionInfo(FileManager, "PMOVSXDQ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PMULDQ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PCMPEQQ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_M,OperandSize_dq);
	PushInstructionInfo(FileManager, "MOVNTDQA", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PACKUSDW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_U,OperandSize_dq);
	PushInstructionInfo(FileManager, "PMOVZXBW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_M,OperandSize_q);
	PushInstructionInfo(FileManager, "PMOVZXBW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_U,OperandSize_dq);
	PushInstructionInfo(FileManager, "PMOVZXBD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_M,OperandSize_d);
	PushInstructionInfo(FileManager, "PMOVZXBD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_U,OperandSize_dq);
	PushInstructionInfo(FileManager, "PMOVZXBQ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_M,OperandSize_w);
	PushInstructionInfo(FileManager, "PMOVZXBQ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_U,OperandSize_dq);
	PushInstructionInfo(FileManager, "PMOVZXWD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_M,OperandSize_q);
	PushInstructionInfo(FileManager, "PMOVZXWD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_U,OperandSize_dq);
	PushInstructionInfo(FileManager, "PMOVZXWQ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_M,OperandSize_d);
	PushInstructionInfo(FileManager, "PMOVZXWQ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_U,OperandSize_dq);
	PushInstructionInfo(FileManager, "PMOVZXDQ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_M,OperandSize_q);
	PushInstructionInfo(FileManager, "PMOVZXDQ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PCMPGTQ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PMINSB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PMINSD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PMINUW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PMINUD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PMAXSB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PMAXSD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PMAXUW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PMAXUD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PMULLD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PHMINPOSUW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_M,OperandSize_vqp);
	PushInstructionInfo(FileManager, "MOVBE", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_dqp);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushInstructionInfo(FileManager, "CRC32", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushInstructionInfo(FileManager, "MOVBE", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_dqp);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushInstructionInfo(FileManager, "CRC32", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ps);
	PushOperand(&OperandArray, OperandType_W,OperandSize_ps);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "ROUNDPS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ps);
	PushOperand(&OperandArray, OperandType_W,OperandSize_pd);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "ROUNDPD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ss);
	PushOperand(&OperandArray, OperandType_W,OperandSize_ss);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "ROUNDSS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_sd);
	PushOperand(&OperandArray, OperandType_W,OperandSize_sd);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "ROUNDSD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ps);
	PushOperand(&OperandArray, OperandType_W,OperandSize_ps);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "BLENDPS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_pd);
	PushOperand(&OperandArray, OperandType_W,OperandSize_pd);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "BLENDPD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "PBLENDW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PALIGNR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PALIGNR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_R,OperandSize_dqp);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "PEXTRB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_b);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "PEXTRB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_R,OperandSize_dqp);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "PEXTRW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_w);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "PEXTRW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_d);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "PEXTRD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_d);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "EXTRACTPS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_R,OperandSize_dqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "PINSRB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_M,OperandSize_b);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "PINSRB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ps);
	PushOperand(&OperandArray, OperandType_U,OperandSize_ps);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "INSERTPS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ps);
	PushOperand(&OperandArray, OperandType_M,OperandSize_d);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "INSERTPS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_E,OperandSize_d);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "PINSRD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ps);
	PushOperand(&OperandArray, OperandType_W,OperandSize_ps);
	PushInstructionInfo(FileManager, "DPPS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_pd);
	PushOperand(&OperandArray, OperandType_W,OperandSize_pd);
	PushInstructionInfo(FileManager, "DPPD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "MPSADBW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "PCMPESTRM", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "PCMPESTRI", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "PCMPISTRM", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "PCMPISTRI", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushInstructionInfo(FileManager, "CMOVO", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushInstructionInfo(FileManager, "CMOVNO", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushInstructionInfo(FileManager, "CMOVB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushInstructionInfo(FileManager, "CMOVAE", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushInstructionInfo(FileManager, "CMOVZ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushInstructionInfo(FileManager, "CMOVNZ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushInstructionInfo(FileManager, "CMOVNA", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushInstructionInfo(FileManager, "CMOVA", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushInstructionInfo(FileManager, "CMOVS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushInstructionInfo(FileManager, "CMOVNS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushInstructionInfo(FileManager, "CMOVPE", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushInstructionInfo(FileManager, "CMOVPO", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushInstructionInfo(FileManager, "CMOVL", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushInstructionInfo(FileManager, "CMOVGE", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushInstructionInfo(FileManager, "CMOVLE", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushInstructionInfo(FileManager, "CMOVG", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_dqp);
	PushOperand(&OperandArray, OperandType_U,OperandSize_ps);
	PushInstructionInfo(FileManager, "MOVMSKPS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_dqp);
	PushOperand(&OperandArray, OperandType_U,OperandSize_pd);
	PushInstructionInfo(FileManager, "MOVMSKPD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ps);
	PushOperand(&OperandArray, OperandType_W,OperandSize_ps);
	PushInstructionInfo(FileManager, "SQRTPS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ss);
	PushOperand(&OperandArray, OperandType_W,OperandSize_ss);
	PushInstructionInfo(FileManager, "SQRTSS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_pd);
	PushOperand(&OperandArray, OperandType_W,OperandSize_pd);
	PushInstructionInfo(FileManager, "SQRTPD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_sd);
	PushOperand(&OperandArray, OperandType_W,OperandSize_sd);
	PushInstructionInfo(FileManager, "SQRTSD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ps);
	PushOperand(&OperandArray, OperandType_W,OperandSize_ps);
	PushInstructionInfo(FileManager, "RSQRTPS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ss);
	PushOperand(&OperandArray, OperandType_W,OperandSize_ss);
	PushInstructionInfo(FileManager, "RSQRTSS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ps);
	PushOperand(&OperandArray, OperandType_W,OperandSize_ps);
	PushInstructionInfo(FileManager, "RCPPS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ss);
	PushOperand(&OperandArray, OperandType_W,OperandSize_ss);
	PushInstructionInfo(FileManager, "RCPSS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ps);
	PushOperand(&OperandArray, OperandType_W,OperandSize_ps);
	PushInstructionInfo(FileManager, "ANDPS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_pd);
	PushOperand(&OperandArray, OperandType_W,OperandSize_pd);
	PushInstructionInfo(FileManager, "ANDPD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ps);
	PushOperand(&OperandArray, OperandType_W,OperandSize_ps);
	PushInstructionInfo(FileManager, "ANDNPS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_pd);
	PushOperand(&OperandArray, OperandType_W,OperandSize_pd);
	PushInstructionInfo(FileManager, "ANDNPD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ps);
	PushOperand(&OperandArray, OperandType_W,OperandSize_ps);
	PushInstructionInfo(FileManager, "ORPS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_pd);
	PushOperand(&OperandArray, OperandType_W,OperandSize_pd);
	PushInstructionInfo(FileManager, "ORPD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ps);
	PushOperand(&OperandArray, OperandType_W,OperandSize_ps);
	PushInstructionInfo(FileManager, "XORPS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_pd);
	PushOperand(&OperandArray, OperandType_W,OperandSize_pd);
	PushInstructionInfo(FileManager, "XORPD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ps);
	PushOperand(&OperandArray, OperandType_W,OperandSize_ps);
	PushInstructionInfo(FileManager, "ADDPS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ss);
	PushOperand(&OperandArray, OperandType_W,OperandSize_ss);
	PushInstructionInfo(FileManager, "ADDSS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_pd);
	PushOperand(&OperandArray, OperandType_W,OperandSize_pd);
	PushInstructionInfo(FileManager, "ADDPD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_sd);
	PushOperand(&OperandArray, OperandType_W,OperandSize_sd);
	PushInstructionInfo(FileManager, "ADDSD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ps);
	PushOperand(&OperandArray, OperandType_W,OperandSize_ps);
	PushInstructionInfo(FileManager, "MULPS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ss);
	PushOperand(&OperandArray, OperandType_W,OperandSize_ss);
	PushInstructionInfo(FileManager, "MULSS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_pd);
	PushOperand(&OperandArray, OperandType_W,OperandSize_pd);
	PushInstructionInfo(FileManager, "MULPD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_sd);
	PushOperand(&OperandArray, OperandType_W,OperandSize_sd);
	PushInstructionInfo(FileManager, "MULSD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_pd);
	PushOperand(&OperandArray, OperandType_W,OperandSize_ps);
	PushInstructionInfo(FileManager, "CVTPS2PD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ps);
	PushOperand(&OperandArray, OperandType_W,OperandSize_pd);
	PushInstructionInfo(FileManager, "CVTPD2PS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_sd);
	PushOperand(&OperandArray, OperandType_W,OperandSize_ss);
	PushInstructionInfo(FileManager, "CVTSS2SD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ss);
	PushOperand(&OperandArray, OperandType_W,OperandSize_sd);
	PushInstructionInfo(FileManager, "CVTSD2SS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ps);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "CVTDQ2PS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_ps);
	PushInstructionInfo(FileManager, "CVTPS2DQ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_ps);
	PushInstructionInfo(FileManager, "CVTTPS2DQ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ps);
	PushOperand(&OperandArray, OperandType_W,OperandSize_ps);
	PushInstructionInfo(FileManager, "SUBPS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ss);
	PushOperand(&OperandArray, OperandType_W,OperandSize_ss);
	PushInstructionInfo(FileManager, "SUBSS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_pd);
	PushOperand(&OperandArray, OperandType_W,OperandSize_pd);
	PushInstructionInfo(FileManager, "SUBPD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_sd);
	PushOperand(&OperandArray, OperandType_W,OperandSize_sd);
	PushInstructionInfo(FileManager, "SUBSD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ps);
	PushOperand(&OperandArray, OperandType_W,OperandSize_ps);
	PushInstructionInfo(FileManager, "MINPS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ss);
	PushOperand(&OperandArray, OperandType_W,OperandSize_ss);
	PushInstructionInfo(FileManager, "MINSS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_pd);
	PushOperand(&OperandArray, OperandType_W,OperandSize_pd);
	PushInstructionInfo(FileManager, "MINPD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_sd);
	PushOperand(&OperandArray, OperandType_W,OperandSize_sd);
	PushInstructionInfo(FileManager, "MINSD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ps);
	PushOperand(&OperandArray, OperandType_W,OperandSize_ps);
	PushInstructionInfo(FileManager, "DIVPS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ss);
	PushOperand(&OperandArray, OperandType_W,OperandSize_ss);
	PushInstructionInfo(FileManager, "DIVSS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_pd);
	PushOperand(&OperandArray, OperandType_W,OperandSize_pd);
	PushInstructionInfo(FileManager, "DIVPD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_sd);
	PushOperand(&OperandArray, OperandType_W,OperandSize_sd);
	PushInstructionInfo(FileManager, "DIVSD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ps);
	PushOperand(&OperandArray, OperandType_W,OperandSize_ps);
	PushInstructionInfo(FileManager, "MAXPS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ss);
	PushOperand(&OperandArray, OperandType_W,OperandSize_ss);
	PushInstructionInfo(FileManager, "MAXSS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_pd);
	PushOperand(&OperandArray, OperandType_W,OperandSize_pd);
	PushInstructionInfo(FileManager, "MAXPD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_sd);
	PushOperand(&OperandArray, OperandType_W,OperandSize_sd);
	PushInstructionInfo(FileManager, "MAXSD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_d);
	PushInstructionInfo(FileManager, "PUNPCKLBW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PUNPCKLBW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_d);
	PushInstructionInfo(FileManager, "PUNPCKLWD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PUNPCKLWD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_d);
	PushInstructionInfo(FileManager, "PUNPCKLDQ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PUNPCKLDQ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_d);
	PushInstructionInfo(FileManager, "PACKSSWB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PACKSSWB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_d);
	PushInstructionInfo(FileManager, "PCMPGTB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PCMPGTB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_d);
	PushInstructionInfo(FileManager, "PCMPGTW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PCMPGTW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_d);
	PushInstructionInfo(FileManager, "PCMPGTD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PCMPGTD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PACKUSWB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PACKUSWB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PUNPCKHBW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PUNPCKHBW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PUNPCKHWD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PUNPCKHWD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PUNPCKHDQ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PUNPCKHDQ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PACKSSDW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PACKSSDW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PUNPCKLQDQ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PUNPCKHQDQ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_E,OperandSize_d);
	PushInstructionInfo(FileManager, "MOVD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_E,OperandSize_d);
	PushInstructionInfo(FileManager, "MOVD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "MOVQ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "MOVDQA", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "MOVDQU", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "PSHUFW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "PSHUFLW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "PSHUFHW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "PSHUFD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_N,OperandSize_q);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "PSRLW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_U,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "PSRLW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_N,OperandSize_q);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "PSRAW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_U,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "PSRAW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_N,OperandSize_q);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "PSLLW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_U,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "PSLLW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_N,OperandSize_q);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "PSRLD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_U,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "PSRLD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_N,OperandSize_q);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "PSRAD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_U,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "PSRAD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_N,OperandSize_q);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "PSLLD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_U,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "PSLLD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_N,OperandSize_q);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "PSRLQ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_U,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "PSRLQ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_U,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "PSRLDQ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_N,OperandSize_q);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "PSLLQ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_U,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "PSLLQ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_U,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "PSLLDQ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PCMPEQB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PCMPEQB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PCMPEQW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PCMPEQW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PCMPEQD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PCMPEQD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "EMMS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_pd);
	PushOperand(&OperandArray, OperandType_W,OperandSize_pd);
	PushInstructionInfo(FileManager, "HADDPD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ps);
	PushOperand(&OperandArray, OperandType_W,OperandSize_ps);
	PushInstructionInfo(FileManager, "HADDPS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_pd);
	PushOperand(&OperandArray, OperandType_W,OperandSize_pd);
	PushInstructionInfo(FileManager, "HSUBPD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ps);
	PushOperand(&OperandArray, OperandType_W,OperandSize_ps);
	PushInstructionInfo(FileManager, "HSUBPS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_d);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushInstructionInfo(FileManager, "MOVD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_d);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushInstructionInfo(FileManager, "MOVD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_q);
	PushOperand(&OperandArray, OperandType_W,OperandSize_q);
	PushInstructionInfo(FileManager, "MOVQ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushInstructionInfo(FileManager, "MOVQ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushInstructionInfo(FileManager, "MOVDQA", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushInstructionInfo(FileManager, "MOVDQU", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_vds);
	PushInstructionInfo(FileManager, "JO", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_vds);
	PushInstructionInfo(FileManager, "JNO", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_vds);
	PushInstructionInfo(FileManager, "JB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_vds);
	PushInstructionInfo(FileManager, "JAE", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_vds);
	PushInstructionInfo(FileManager, "JZ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_vds);
	PushInstructionInfo(FileManager, "JNZ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_vds);
	PushInstructionInfo(FileManager, "JBE", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_vds);
	PushInstructionInfo(FileManager, "JA", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_vds);
	PushInstructionInfo(FileManager, "JS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_vds);
	PushInstructionInfo(FileManager, "JNS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_vds);
	PushInstructionInfo(FileManager, "JPE", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_vds);
	PushInstructionInfo(FileManager, "JPO", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_vds);
	PushInstructionInfo(FileManager, "JL", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_vds);
	PushInstructionInfo(FileManager, "JGE", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_vds);
	PushInstructionInfo(FileManager, "JLE", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_J,OperandSize_vds);
	PushInstructionInfo(FileManager, "JG", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushInstructionInfo(FileManager, "SETO", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushInstructionInfo(FileManager, "SETNO", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushInstructionInfo(FileManager, "SETB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushInstructionInfo(FileManager, "SETAE", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushInstructionInfo(FileManager, "SETZ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushInstructionInfo(FileManager, "SETNZ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushInstructionInfo(FileManager, "SETBE", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushInstructionInfo(FileManager, "SETA", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushInstructionInfo(FileManager, "SETS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushInstructionInfo(FileManager, "SETNS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushInstructionInfo(FileManager, "SETPE", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushInstructionInfo(FileManager, "SETPO", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushInstructionInfo(FileManager, "SETL", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushInstructionInfo(FileManager, "SETGE", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushInstructionInfo(FileManager, "SETLE", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushInstructionInfo(FileManager, "SETG", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_FSEG,OperandSize_Invalid);
	PushInstructionInfo(FileManager, "PUSH", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_FSEG,OperandSize_Invalid);
	PushInstructionInfo(FileManager, "POP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "CPUID", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushInstructionInfo(FileManager, "BT", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "SHLD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_CX,OperandSize_b);
	PushInstructionInfo(FileManager, "SHLD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_GSEG,OperandSize_Invalid);
	PushInstructionInfo(FileManager, "PUSH", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_GSEG,OperandSize_Invalid);
	PushInstructionInfo(FileManager, "POP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "RSM", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushInstructionInfo(FileManager, "BTS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "SHRD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_CX,OperandSize_b);
	PushInstructionInfo(FileManager, "SHRD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_stx);
	PushInstructionInfo(FileManager, "FXSAVE", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_stx);
	PushInstructionInfo(FileManager, "FXRSTOR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_d);
	PushInstructionInfo(FileManager, "LDMXCSR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_d);
	PushInstructionInfo(FileManager, "STMXCSR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_Invalid);
	PushInstructionInfo(FileManager, "XSAVE", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "LFENCE", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_Invalid);
	PushInstructionInfo(FileManager, "XRSTOR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "MFENCE", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "SFENCE", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_b);
	PushInstructionInfo(FileManager, "CLFLUSH", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushInstructionInfo(FileManager, "IMUL", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_G,OperandSize_b);
	PushInstructionInfo(FileManager, "CMPXCHG", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushInstructionInfo(FileManager, "CMPXCHG", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_M,OperandSize_ptp);
	PushInstructionInfo(FileManager, "LSS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushInstructionInfo(FileManager, "BTR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_M,OperandSize_ptp);
	PushInstructionInfo(FileManager, "LFS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_M,OperandSize_ptp);
	PushInstructionInfo(FileManager, "LGS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushInstructionInfo(FileManager, "MOVZX", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_E,OperandSize_w);
	PushInstructionInfo(FileManager, "MOVZX", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushInstructionInfo(FileManager, "JMPE", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushInstructionInfo(FileManager, "POPCNT", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_d);
	PushOperand(&OperandArray, OperandType_E,OperandSize_d);
	PushInstructionInfo(FileManager, "UD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "BT", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "BTS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "BTR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "BTC", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushInstructionInfo(FileManager, "BTC", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushInstructionInfo(FileManager, "BSF", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushInstructionInfo(FileManager, "BSR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushInstructionInfo(FileManager, "MOVSX", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_E,OperandSize_w);
	PushInstructionInfo(FileManager, "MOVSX", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_b);
	PushOperand(&OperandArray, OperandType_G,OperandSize_b);
	PushInstructionInfo(FileManager, "XADD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_E,OperandSize_vqp);
	PushOperand(&OperandArray, OperandType_G,OperandSize_vqp);
	PushInstructionInfo(FileManager, "XADD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ps);
	PushOperand(&OperandArray, OperandType_W,OperandSize_ps);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "CMPPS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ss);
	PushOperand(&OperandArray, OperandType_W,OperandSize_ss);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "CMPSS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_pd);
	PushOperand(&OperandArray, OperandType_W,OperandSize_pd);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "CMPPD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_sd);
	PushOperand(&OperandArray, OperandType_W,OperandSize_sd);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "CMPSD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_dqp);
	PushOperand(&OperandArray, OperandType_G,OperandSize_dqp);
	PushInstructionInfo(FileManager, "MOVNTI", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_R,OperandSize_dqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "PINSRW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_M,OperandSize_w);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "PINSRW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_R,OperandSize_dqp);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "PINSRW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_M,OperandSize_w);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "PINSRW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_dqp);
	PushOperand(&OperandArray, OperandType_N,OperandSize_q);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "PEXTRW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_dqp);
	PushOperand(&OperandArray, OperandType_U,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "PEXTRW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ps);
	PushOperand(&OperandArray, OperandType_W,OperandSize_ps);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "SHUFPS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_pd);
	PushOperand(&OperandArray, OperandType_W,OperandSize_pd);
	PushOperand(&OperandArray, OperandType_I,OperandSize_b);
	PushInstructionInfo(FileManager, "SHUFPD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_q);
	PushInstructionInfo(FileManager, "CMPXCHG8B", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_Z,OperandSize_vqp);
	PushInstructionInfo(FileManager, "BSWAP", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_pd);
	PushOperand(&OperandArray, OperandType_W,OperandSize_pd);
	PushInstructionInfo(FileManager, "ADDSUBPD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_ps);
	PushOperand(&OperandArray, OperandType_W,OperandSize_ps);
	PushInstructionInfo(FileManager, "ADDSUBPS", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PSRLW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PSRLW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PSRLD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PSRLD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PSRLQ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PSRLQ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PADDQ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PADDQ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PMULLW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PMULLW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_W,OperandSize_q);
	PushOperand(&OperandArray, OperandType_V,OperandSize_q);
	PushInstructionInfo(FileManager, "MOVQ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_N,OperandSize_q);
	PushInstructionInfo(FileManager, "MOVQ2DQ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_U,OperandSize_q);
	PushInstructionInfo(FileManager, "MOVDQ2Q", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_dqp);
	PushOperand(&OperandArray, OperandType_N,OperandSize_q);
	PushInstructionInfo(FileManager, "PMOVMSKB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_G,OperandSize_dqp);
	PushOperand(&OperandArray, OperandType_U,OperandSize_dq);
	PushInstructionInfo(FileManager, "PMOVMSKB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PSUBUSB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PSUBUSB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PSUBUSW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PSUBUSW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PMINUB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PMINUB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_d);
	PushInstructionInfo(FileManager, "PAND", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PAND", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PADDUSB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PADDUSB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PADDUSW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PADDUSW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PMAXUB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PMAXUB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PANDN", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PANDN", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PAVGB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PAVGB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PSRAW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PSRAW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PSRAD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PSRAD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PAVGW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PAVGW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PMULHUW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PMULHUW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PMULHW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PMULHW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_pd);
	PushInstructionInfo(FileManager, "CVTPD2DQ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_pd);
	PushInstructionInfo(FileManager, "CVTTPD2DQ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_pd);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "CVTDQ2PD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_q);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushInstructionInfo(FileManager, "MOVNTQ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_M,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushInstructionInfo(FileManager, "MOVNTDQ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PSUBSB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PSUBSB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PSUBSW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PSUBSW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PMINSW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PMINSW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "POR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "POR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PADDSB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PADDSB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PADDSW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PADDSW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PMAXSW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PMAXSW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PXOR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PXOR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_M,OperandSize_dq);
	PushInstructionInfo(FileManager, "LDDQU", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PSLLW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PSLLW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PSLLD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PSLLD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PSLLQ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PSLLQ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PMULUDQ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PMULUDQ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_d);
	PushInstructionInfo(FileManager, "PMADDWD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PMADDWD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PSADBW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PSADBW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_N,OperandSize_q);
	PushInstructionInfo(FileManager, "MASKMOVQ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_U,OperandSize_dq);
	PushInstructionInfo(FileManager, "MASKMOVDQU", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PSUBB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PSUBB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PSUBW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PSUBW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PSUBD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PSUBD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PSUBQ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PSUBQ", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PADDB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PADDB", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PADDW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PADDW", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_P,OperandSize_q);
	PushOperand(&OperandArray, OperandType_Q,OperandSize_q);
	PushInstructionInfo(FileManager, "PADDD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);

	InitOperandArray(&OperandArray);
	PushOperand(&OperandArray, OperandType_V,OperandSize_dq);
	PushOperand(&OperandArray, OperandType_W,OperandSize_dq);
	PushInstructionInfo(FileManager, "PADDD", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);
	EndFileSection(FileManager);
}