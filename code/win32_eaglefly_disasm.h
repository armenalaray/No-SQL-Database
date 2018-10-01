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
#define MONO_OPCODE_TABLE_SIZE 256
#define MONO_OPCODE_TABLE_SIZE 256


#include "eaglefly_disasm_tables.h"

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

CENUM(eflyop_bgroup_type)
{
    OPField_Prefixes,
    OPField_MainOpcode,
    OPField_ModRM,
    OPField_SIB,
    OPField_Displacement,
    OPField_Immediate,
}eflyop_bgroup_type;


CSTRUCT(eflyop_flags)
{
    b32 MODRMNext; 
    b32 ControlRegister;
    b32 DebugRegister;
    b32 SIBNext;
    b32 RegToMODRM;
    
    uint32_t OperandType, DataSize;
}eflyop_flags;


CSTRUCT(eflyop_bgroup)
{
    char * MinFilePtr;
    uint32_t ByteCount;
    uint32_t MaxByteCount;
}eflyop_bgroup;

CSTRUCT(eflyop_prototype)
{
    b32 Direction;
    b32 ModRMPresent;
    
    uint16_t OperandCount;
    //efly_operand Operands[MAX_OPERAND_COUNT];
    eflyop_bgroup IBGroup;
}eflyop_prototype;


CSTRUCT(efly_disasm_state)
{
    memory_arena DisasmArena;
    
    b32 TablesPresent;
    eflyop_table_entry OneByteTablex64[4096];
    eflyop_encoding EncodingsTable[4096];
    //eflyop_encoding OneByteOpTablex86[24];
    //eflyop_table * ConditionTable;
    
    char * CFilePtrByte;
    char * CFilePtrBase;
    size_t CodeSectionSize;
    
    size_t IP;
    size_t InstructionCount;
}efly_disasm_state;



