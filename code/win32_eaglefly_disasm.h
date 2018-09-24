/*
NOTE(Alex): win32_eaglefly_disasm.h

IMPORTANT(Alex): Intel Instruction Format Manual Pages

- Appendix B Instruction formats en encodings                                2527
- Appendix A Opcode Map                                                      2497
- Instruction Format (General) 16/32-bit MODRM and 32-bit SIB tables          505
- Programming with General purpose Innstructions                              169


*/

#define MAX_INSTRUCTION_OPCOUNT 15
#define MAX_MAIN_OPCODE_COUNT 3
#define MAX_OPERAND_COUNT 3

#define MAX_PREFIX_COUNT_64 5
#define MAX_PREFIX_COUNT_32 4
#define MONO_OPCODE_TABLE_SIZE 256
#define MAX_INSTRUCTION_OPERAND_COUNT 24

enum efly_bin_options
{
    PEOption_None,
    PEOption_Disasm,
    PEOption_Headers,
    PEOption_ModuleInfo,
    PEOption_Count,
};

struct efly_command 
{
    efly_bin_options OptionFlags;
    char * EXEFullPath;
};


//NOTE(Alex): EFLY_DISASM 
//-------------------------------------------------------------------------

typedef enum efly_opcode_prefixes
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
    
    OpcodePrefix_REX,          //0x40 - 0x4F
    OpcodePrefix_VEX,          //
    OpcodePrefix_Count,
    
}efly_opcode_prefixes;

typedef enum efly_opcode_table_type
{
    OpTable_None = 0,
    OpTable_Mono = 1,
}efly_primary_opcode_size;

CENUM(efly_addressing_modes)
{
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
}efly_addressing_modes;

CENUM(efly_operand_types)
{
    OperandType_a,
    OperandType_b,
    OperandType_c,
    OperandType_d,
    OperandType_dq,
    OperandType_p,
    OperandType_pd,
    OperandType_pi,
    OperandType_ps,
    OperandType_q,
    OperandType_qq,
    OperandType_s,
    OperandType_sd,
    OperandType_ss,
    OperandType_si,
    OperandType_v,
    OperandType_w,
    OperandType_x,
    OperandType_y,
    OperandType_z,
}efly_operand_types;


CENUM(efly_data_type)
{
    DataType_None = 0,
    DataType_BYTE = 1,
    DataType_WORD = 2,
    DataType_DWORD = 4,
    DataType_QWORD = 8,
    DataType_XMM = 16,
    DataType_YMM = 32,
    DataType_ZMM = 64,
}efly_data_type;

//IMPORTANT(Alex): This has to match the columns of RegNamesTable!
CENUM(efly_reg_types)
{
    RegType_8bit,
    RegType_16bit,
    RegType_32bit,
    RegType_MMX,
    RegType_XMM,
    RegType_64bit,
    RegType_Ctrl,
    //RegType_ExtCtrl,
    RegType_Dbg,
    //RegType_ExtDbg,
}efly_reg_types;


CSTRUCT(efly_operand)
{
    efly_data_type Type;
    efly_addressing_modes AddrMode;
}efly_operand;


CENUM(eflyop_bgroup_type)
{
    OPField_Prefixes,
    OPField_MainOpcode,
    OPField_ModRM,
    OPField_SIB,
    OPField_Displacement,
    OPField_Immediate,
}eflyop_bgroup_type;

CSTRUCT(eflyop_bgroup)
{
    char * MinFilePtr;
    uint32_t ByteCount;
    uint32_t MaxByteCount;
    
    eflyop_bgroup * Next;
}eflyop_bgroup;

CSTRUCT(eflyop_modrm)
{
    char * Symbol;
    b32 SIBPresent;
    efly_data_type DispType;
    
    uint32_t Mod;
    uint32_t Reg;
    uint32_t RM;
    
}eflyop_modrm;


CSTRUCT(eflyop_prototype)
{
    b32 Direction;
    b32 ModRMPresent;
    
    uint32_t BufferCount;
    char Buffer[4096];
    
    uint16_t OperandCount;
    efly_operand Operands[MAX_OPERAND_COUNT];
    
    eflyop_bgroup IBGroup;
    
}eflyop_prototype;


CSTRUCT(efly_disasm_state)
{
    memory_arena DisasmArena;
    
    void * MonoOpcodeTable;
    
    char * CFilePtrByte;
    char * CFilePtrBase;
    size_t CodeSectionSize;
    
    size_t IP;
    size_t InstructionCount;
    
    eflyop_bgroup * FirstBGroup;
    eflyop_bgroup * FirstFreeBGroup;
    
}efly_opcode_table;

