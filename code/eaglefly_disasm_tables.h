/*
//NOTE(Alex): eaglefly_disasm_tables.h

 IMPORTANT(Alex): opcode encoding are going to be little endian encoded. 
Find a way to decode big endian arquitectures!

*/


CENUM(eflyop_table_sreg3)
{
    SReg_ES = 0x0,
    SReg_CS,
    SReg_SS,
    SReg_DS,
    SReg_FS,
    SReg_GS,
    SReg_Reserved_00,
    SReg_Reserved_01,
    
    Sreg_Count,
}eflyop_table_sreg3;


CENUM(eflyop_table_eee)
{
    EEE_CR0 = 0x0,
    EEE_DR0 = EEE_CR0,
    
    EEE_CReserved_01,
    EEE_DR1 = EEE_CReserved_01,
    
    EEE_CR2,
    EEE_DR2 = EEE_CR2,
    
    EEE_CR3,
    EEE_DR3 = EEE_CR3,
    
    EEE_CR4,
    EEE_DReserved_04 = EEE_CR4,
    
    EEE_CReserved_05,
    EEE_DReserved_05 = EEE_CReserved_05,
    
    EEE_CReserved_06,
    EEE_DR6 = EEE_CReserved_06,
    
    EEE_CReserved_07,
    EEE_DR7 = EEE_CReserved_07,
    
    EEE_Count,
}eflyop_table_eee;


CENUM(eflyop_table_tttn)
{
    TTTN_Overflow = 0x0,
    TTTN_NOverflow,
    
    TTTN_Below,
    TTTN_NBelow,
    
    TTTN_Equal,
    TTTN_NEqual,
    
    TTTN_BelowOrEqual,
    TTTN_NBelowOrEqual,
    
    TTTN_Sign,
    TTTN_Nsign,
    
    TTTN_Parity,
    TTTN_NParity,
    
    TTTN_LessThan,
    TTTN_NLessThan,
    
    TTTN_LessThanOrEqual,
    TTTN_NLessThanOrEqual,
    
    TTTN_Count,
}eflyop_table_tttn;

CENUM(eflyop_prefixes)
{
    OpcodePrefix_None = 0,
    OpcodePrefix_LOCK,         //0xF0,
    OpcodePrefix_REPNE,        //0xF2, //NOTE(Alex): Used only for string instructions or mandatory prefixes
    OpcodePrefix_REPE,         //0xF3, //NOTE(Alex): Used only for string instructions
    OpcodePrefix_BND,          //0xF2, //NOTE(Alex): CPUID.(EAX=07H, ECX=0):EBX.MPX[bit 14] is set. BNDCFGU.EN and/or IA32_BNDCFGS.EN is set. When the F2 prefix precedes a near CALL, a near RET, a near JMP, a short Jcc, or a near Jcc instruction
    
    OpcodePrefix_AddressSizeOV,//0x67,
    
    OpcodePrefix_OperandSizeOV,//0x66,
    
    OpcodePrefix_CSOV,         //0x2E CS segment override (use with any branch instruction is reserved).
    OpcodePrefix_SSOV,         //0x36—SS segment override prefix (use with any branch instruction is reserved).
    OpcodePrefix_DSOV,         //0x3E—DS segment override prefix (use with any branch instruction is reserved).//0x2E CS segment override (use with any branch instruction is reserved).
    OpcodePrefix_ESOV,         //0x26—ES segment override prefix (use with any branch instruction is reserved).//0x2E CS segment override (use with any branch instruction is reserved).
    OpcodePrefix_FSOV,         //0x64—FS segment override prefix (use with any branch instruction is reserved).//0x2E CS segment override (use with any branch instruction is reserved).
    OpcodePrefix_GSOV,         //0x65—GS segment override prefix (use with any branch instruction is reserved).//0x2E CS segment override (use with any branch instruction is reserved).
    OpcodePrefix_BT,           //0x2EH—Branch not taken (used only with Jcc instructions).
    OpcodePrefix_BNT,          //0x3EH—Branch taken (used only with Jcc instructions).
    
    //------------------------------ANY ORDER-------------------//
    //OpcodePrefix_VEX,          //
    
    OpcodePrefix_EscapeMandatory,       //0x0F
    OpcodePrefix_SIMDMandatory,       //0xF2 | OxF3
    OpcodePrefix_REX,          //0x40 - 0x4F
    
    OpcodePrefix_Count,
}eflyop_prefixes;


CENUM(eflyop_addressing_modes)
{
    AddressingMode_Invalid,
    AddressingMode_DirectAddress,
    AddressingMode_VEX_GPR,
    AddressingMode_RegControl,
    AddressingMode_RegDebug,
    AddressingMode_MODRM_GPR_Mem,
    AddressingMode_rFLAGS,
    AddressingMode_RegGPR,
    AddressingMode_VEX_yMM,
    AddressingMode_Immediate,
    AddressingMode_RIP_offset,
    AddressingMode_8b_imm_yMM,//NOTE(Alex): The upper 4 bits of the 8 bit immediate selects a XMM or YMM register
    AddressingMode_MODRM_Mem_only,
    AddressingMode_RM_MMX,
    AddressingMode_NO_MODRM,
    AddressingMode_RegMMX,
    AddressingMode_MODRM_MMX_Mem,
    AddressingMode_RM_GPR_only,
    AddressingMode_Reg_Segment,
    AddressingMode_RM_yMM,
    AddressingMode_Reg_yMM,
    AddressingMode_MODRM_yMM_Mem,
    AddressingMode_DS_rSI_Mem,
    AddressingMode_ES_rDI_Mem,
    AddressingMode_Count,
}eflyop_addressing_modes;

CENUM(eflyop_operand_type_info)
{
    OperandTypeInfo_Invalid,
    OperandTypeInfo_a,
    OperandTypeInfo_b,//NOTE(Alex): Byte regardless of Operand Attribute
    OperandTypeInfo_c,
    OperandTypeInfo_d,
    OperandTypeInfo_dq,
    OperandTypeInfo_p,
    OperandTypeInfo_pd,
    OperandTypeInfo_pi,
    OperandTypeInfo_ps,
    OperandTypeInfo_q,
    OperandTypeInfo_qq,
    OperandTypeInfo_s,
    OperandTypeInfo_sd,
    OperandTypeInfo_ss,
    OperandTypeInfo_si,
    OperandTypeInfo_v,
    OperandTypeInfo_w,
    OperandTypeInfo_x,
    OperandTypeInfo_y,
    OperandTypeInfo_z,
}eflyop_operand_type_info;


CENUM(eflyop_data_size)
{
    DataSize_None = 0,
    
    DataSize_BYTE = 1,
    DataSize_8Bit = DataSize_BYTE,
    
    DataSize_WORD = 2,
    DataSize_16Bit = DataSize_WORD,
    
    DataSize_DWORD = 4,
    DataSize_32Bit = DataSize_DWORD,
    
    DataSize_QWORD = 8,
    DataSize_MMX = DataSize_QWORD,
    DataSize_64Bit = DataSize_QWORD,
    
    DataSize_XMM = 16,
    DataSize_128Bit = DataSize_XMM,
    
    DataSize_YMM = 32,
    DataSize_256Bit = DataSize_YMM,
    
    DataSize_ZMM = 64,
    DataSize_512Bit = DataSize_ZMM,
    
}eflyop_data_size;

//IMPORTANT(Alex): This has to match the columns of RegNamesTable!
CENUM(eflyop_operand_type)
{
    OperandType_None, 
    OperandType_GPR, 
    OperandType_x87,
    OperandType_MMX,
    OperandType_XMM,
    OperandType_YMM,
    OperandType_VEX,
    OperandType_Ctrl,
    //OperandType_ExtCtrl,
    OperandType_Dbg,
    //OperandType_ExtDbg,
    OperandType_Mem,
}eflyop_operand_type;

#if 0
CENUM(eflyop_encoding_byte_fields)
{
    ByteField_None = 0,
    ByteField_Main,
    ByteField_MODRM,
    ByteField_SIB,
    ,
    ByteField_Imm,
    ByteField_Count,
}eflyop_encoding_byte_fields;
#endif

CENUM(eflyop_bfield_type)
{
    BitField_None = 0,
    BitField_s,
    BitField_w,
    
    BitField_reg,
    
    BitField_reg1,
    BitField_reg2,
    BitField_reg3,
    BitField_reg4,
    
    BitField_sreg2,
    BitField_sreg3,
    BitField_eee,
    
    BitField_tttn,
    BitField_d,
    
    BitField_mod,
    BitField_rm,
    BitField_imm,
    BitField_disp,
    
    BitField_modrmbyte,
    BitField_sibbyte,
    BitField_mainopbyte,
    
    BitField_Count,
}eflyop_bfield_type;


#if 0
typedef enum efly_opcode_table_type
{
    OpTable_None = 0,
    OpTable_Mono = 1,
}efly_primary_opcode_size;



CSTRUCT(eflyop_modrm)
{
    eflyop_encoding_bit_fields BitFlags;
    
    uint32_t Offset;
    uint32_t Count;
    
    b32 SIBPresent;
}eflyop_modrm;

#endif


CSTRUCT(eflyop_bfield)
{
    eflyop_bfield_type Type;
    uint8_t BitOffset;
    uint8_t BitCount;
}eflyop_bfield;

CSTRUCT(eflyop_encoding)
{
    uint8_t TotalBFieldCount;
    eflyop_bfield BFields[BitField_Count];
    uint8_t * Base;
}eflyop_encoding;

CSTRUCT(eflyop_operand)
{
    eflyop_data_size DataSize;
    uint32_t LetterCount;
    char * Data;
}eflyop_operand;

CSTRUCT(eflyop_operand_info)
{
    eflyop_addressing_modes AddrMode;
    eflyop_operand_type_info Type;
}eflyop_operand_info;

//TODO(Alex): Make table spec
CSTRUCT(eflyop_table_entry)
{
    char * Mnemonic;
    uint32_t EncodingIndex;
    uint32_t  OperandCount;
    eflyop_operand_info OperandInfos[8];
}eflyop_table_entry;

CSTRUCT(eflyop_table)
{
    uint16_t Count;
    eflyop_table_entry * Data;
}eflyop_table;


//NOTE(Alex): Compile time assertions! -----------------------------------------------------------

CTAssert(Sreg_Count == 8);
CTAssert(EEE_Count == 8);
CTAssert(TTTN_Count == 16);





