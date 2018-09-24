/*
NOTE(Alex): This is gonna be our win32 platform layer!
Work from here, write the usage code first and see the API!

*/

#include <Windows.h>
#include "stdio.h"
#include "eaglefly_platform.h"
#include "win32_eaglefly_disasm.h"

#include "eaglefly_pe_parser.cpp"

internal void * 
Win32AllocateMemory(memory_index Size)
{
    void * Result = 0;
    //TODO(Alex): Alignment?
    if(Size)
    {
        Result = VirtualAlloc(0, Size, MEM_RESERVE|MEM_COMMIT, PAGE_READWRITE); 
    }
    
    return Result;
}

internal void
Win32DeallocateMemory(void * Memory)
{
    if(Memory)
    {
        VirtualFree(Memory, 0, MEM_RELEASE);
    }
}


DEBUG_READ_ENTIRE_FILE(Debug_Win32ReadEntireFile)
{
    debug_file_content Result = {};
    HANDLE Handle = CreateFileA(FileName,
                                GENERIC_READ,
                                FILE_SHARE_READ,
                                0,
                                OPEN_EXISTING,
                                FILE_ATTRIBUTE_NORMAL,
                                0);
    if(Handle)
    {
        LARGE_INTEGER U64Size = {};
        if(GetFileSizeEx(Handle, &U64Size))
        {
            u32 U32Size = TruncateU64ToU32(U64Size.QuadPart);
            DWORD BytesRead = 0;
            
            void * Content = Win32AllocateMemory(U32Size);
            if(ReadFile(Handle, Content, U32Size, &BytesRead,0) && 
               (BytesRead == U32Size))
            {
                Result.Content = Content;
                Result.Size = U32Size;
            }
            else
            {
                Win32DeallocateMemory(Content);
            }
        }
        else
        {
            //TODO(Alex): logging
        }
        
        CloseHandle(Handle);
    }
    else
    {
        //TODO(Alex): Check if ERROR_FILE_NOT_FOUND 
    }
    
    return Result;
}



//TODO(Alex): Find a way to find out whether opcode is x64 or x86
//TODO(Alex): Support Big Endianness?
//NOTE(Alex): Now we are assuming is x64 opcode

/*
NOTE(Alex): For starters ... 
One opcode byte encoding without MOD R/M Opcode extensions
Memory constraint not necessary

//TODO(Alex): Make an independent pass for the disassembler so it 
is totally isolated from the PE parser 
*/

internal b32
EFlyLexOpcode(eflype_manager * PEManager, char * Base, char * Max)
{
    b32 Result = false;
    
    char * ByteIter = Base;
    
    for(;
        ByteIter !=  Max;
        ++ByteIter)
    {
        
    }
    return Result;
}

internal uint32_t
GetByteSizeForOperandType(uint32_t OperandType)
{
    uint32_t Result = 0;
    return Result;
}

internal uint32_t 
GetRegFieldFromModRM(uint8_t ModRMByte)
{
    uint32_t Result = 0;
    return Result;
}

inline b32
ByteIsPrefix(char Byte)
{
    b32 Result = ((Byte == 0xF0) ||
                  (Byte == 0xF2) ||
                  (Byte == 0xF3) ||
                  (Byte == 0x67) ||
                  (Byte == 0x66) ||
                  (Byte == 0x2E) ||
                  (Byte == 0x36) ||
                  (Byte == 0x3E) ||
                  (Byte == 0x26) ||
                  (Byte == 0x64) ||
                  (Byte == 0x65) ||
                  (Byte == 0x40) ||
                  (Byte == 0x41) ||
                  (Byte == 0x42) ||
                  (Byte == 0x43) ||
                  (Byte == 0x44) ||
                  (Byte == 0x45) ||
                  (Byte == 0x46) ||
                  (Byte == 0x47) ||
                  (Byte == 0x48) ||
                  (Byte == 0x49) ||
                  (Byte == 0x4A) ||
                  (Byte == 0x4B) ||
                  (Byte == 0x4C) ||
                  (Byte == 0x4D) ||
                  (Byte == 0x4E) ||
                  (Byte == 0x4F));
    
    return Result;
}


internal eflyop_bgroup * 
CreateBGroup(efly_disasm_state * DisasmState)
{
    eflyop_bgroup * Result = DisasmState->FirstFreeBGroup;
    if(Result)
    {
        DisasmState->FirstFreeBGroup = Result->Next;
    }
    else
    {
        Result = PushStruct(&DisasmState->DisasmArena, eflyop_bgroup);
    }
    
    if(!DisasmState->FirstBGroup)
    {
        DisasmState->FirstBGroup = Result;
    }
    
    return Result;
}


internal void
TranslateMainOpcode(efly_disasm_state * DisasmState, eflyop_bgroup * PrefixGroup, char * MainOpByte, eflyop_prototype * out_OpProt)
{
#if 0    
    switch(*PrefixByte)
    {
        case OpcodePrefix_REX:
        {
            
        }break;
        case OpcodePrefix_AddressSizeOV:
        {
            
        }break;
        case OpcodePrefix_OperandSizeOV:
        {
            
        }break;
        case OpcodePrefix_SegmentOV:
        {
            
        }break;
        case OpcodePrefix_LOCKAndRepeat:
        {
            
        }break;
        default:
        {
            InvalidCodePath;
        }break;
    }
#endif
}

internal void
DecodeExtraBytes(efly_disasm_state * DisasmState, char * MODRMByte, eflyop_prototype * OpProt)
{
    
}

internal void
PrintOpcodeBytes(efly_disasm_state * DisasmState, eflyop_bgroup * BGroup)
{
    for(uint32_t BIndex = 0;
        BIndex < BGroup->ByteCount;
        ++BIndex)
    {
        char * Ptr = BGroup->MinFilePtr + BIndex;
        if(Ptr)
        {
            printf_s("%x ", *Ptr);
        }
    }
}

internal void
PrintInstructionSymbols(efly_disasm_state * DisasmState, uint32_t Count, char * Text)
{
    //TODO(Alex):  Find a way to encode symbolic info!
}


#define REG_TABLE_DIM_X 7
#define REG_TABLE_DIM_Y 8

int main(u32 ArgCount, char ** Arguments)
{
    
    char * RegNamesTable[256] = 
    {
        "AL", "AX", "EAX", "MM0", "XMM0", "RAX", "R8", "CR0", "DR0",  
        "CL", "CX", "ECX", "MM1", "XMM1", "RCX", "R9", "CR1", "DR1",
        "DL", "DX", "EDX", "MM2", "XMM2", "RDX", "R10", "CR2", "DR2",
        "BL", "BX", "EBX", "MM3", "XMM3", "RBX", "R11", "CR3", "DR3",
        "AH", "SP", "ESP", "MM4", "XMM4", "RSP", "R12", "CR4", "DR4",
        "CH", "BP", "EBP", "MM5", "XMM5", "RBP", "R13", "CR5", "DR5",
        "DH", "SI", "ESI", "MM6", "XMM6", "RSI", "R14", "CR6", "DR6",
        "BH", "DI", "EDI", "MM7", "XMM7", "RDI", "R15", "CR7", "DR7",
    };
    
    char * FileName = Arguments[1];
    printf_s("Arg1: %s", Arguments[1]);
    debug_file_content PEContent = Debug_Win32ReadEntireFile(FileName);
    
    eflype_manager PEManager = {};
    if(eflype_InitParser(&PEManager, &PEContent))
    {
        eflype_section_header * TextHeader = GetSectionHeader(&PEManager, SectionID_text); 
        eflype_section_header * DataHeader = GetSectionHeader(&PEManager, SectionID_data); 
        //char * DataPtr = GetFilePtrFromImageBase(PEManager, DataHeader->PointerToRawData); 
        
        memory_index TotalDisasMem =  Megabytes(500);
        efly_disasm_state * DisasmState = (efly_disasm_state*)VirtualAlloc(0, TotalDisasMem, MEM_RESERVE|MEM_COMMIT, PAGE_READWRITE);
        InitializeArena(&DisasmState->DisasmArena, DisasmState + 1, TotalDisasMem - sizeof(efly_disasm_state));
        DisasmState->CFilePtrBase = (char*)GetFilePtrFromImageBase(&PEManager, TextHeader->PointerToRawData);
        DisasmState->CFilePtrByte = DisasmState->CFilePtrBase;
        DisasmState->CodeSectionSize = TextHeader->SizeOfRawData;
        DisasmState->IP = TextHeader->VirtualAddress;
        
        //InitializeOpcodeTable(DisasmState, DisasmState.MonoOpcodeTable, MONO_OPCODE_TABLE_SIZE);
        
        
        //TODO(Alex): Load this from file?
        //TODO(Alex): Add Prefix identification
        //TODO(Alex): Shall we make the user choose which size attrivutes  
        //the instruction arquitecture should target? Or we use the current arquitecture?
        
        eflyop_bgroup * PrefixBGroup = 0;
        eflyop_prototype OpProt_ = {};
        eflyop_prototype * out_OpProt = &OpProt_;
        
        u32 FirstPassByteCount =  MAX_PREFIX_COUNT_64 + MAX_MAIN_OPCODE_COUNT;
        
        for(;
            DisasmState->CFilePtrByte < (DisasmState->CFilePtrBase + DisasmState->CodeSectionSize);)
        {
            char * MainOpByte = 0;
            char * Byte = DisasmState->CFilePtrByte;
            for(u32 Index = 0;
                Index < FirstPassByteCount;
                ++Index)
            {
                
                if(ByteIsPrefix(*Byte))
                {
                    if(!PrefixBGroup)
                    {
                        PrefixBGroup = CreateBGroup(DisasmState);
                        PrefixBGroup->MinFilePtr = Byte;
                    }
                    
                    Assert(PrefixBGroup->ByteCount < MAX_PREFIX_COUNT_64);
                    ++PrefixBGroup->ByteCount;
                }
                else
                {
                    MainOpByte = PrefixBGroup->MinFilePtr + PrefixBGroup->ByteCount;
                    break;
                }
            }
            
            Assert(MainOpByte);
            TranslateMainOpcode(DisasmState, PrefixBGroup, MainOpByte, out_OpProt);
            
            if(out_OpProt->ModRMPresent)
            {
                DecodeExtraBytes(DisasmState, MainOpByte + 1, out_OpProt);
            }
            
            printf_s("0x%I64x\n", DisasmState->IP);
            
            PrintOpcodeBytes(DisasmState, &out_OpProt->IBGroup);
            PrintInstructionSymbols(DisasmState, out_OpProt->BufferCount, out_OpProt->Buffer);
            
            DisasmState->IP += out_OpProt->IBGroup.ByteCount;
            DisasmState->CFilePtrByte = (out_OpProt->IBGroup.MinFilePtr + out_OpProt->IBGroup.ByteCount);
        }
        
        
#define GET_H4BIT_WORD(...) 0
#define GET_L4BIT_WORD(...) 0
        
#if 0                
        for(uint32_t OperandIndex = 0;
            OperandIndex < CMnemonic.OperandCount;
            ++OperandIndex)
        {
            Assert(FilePtrIsInSegment(TextHeader, DisasmState.CFilePtrByte));
            Assert(OperandIndex < ArrayCount(CMnemonic.Operands));
            
            efly_operand * Operand = CMnemonic.Operands + OperandIndex;
            switch(Operand->AddrMode)
            {
                case AddressingMode_DirectAddress:
                {
                    Instruction.Size += Operand->Type;
                }break;
                case AddressingMode_VEX_GPR:
                {
                    //TODO(Alex): VEX Encoding
                }break;
                case AddressingMode_RegControl:
                {
                    uint32_t RegField = GetRegFieldFromModRM(*DisasmState.CFilePtrByte);
                    char * RegName = RegNamesTable[RegField * REG_TABLE_DIM_X + RegType_Ctrl];
                    //PushNameToBuffer(Instruction, RegName);
                }break;
                
                case AddressingMode_RegDebug:
                {
                }break;
                case AddressingMode_MODRM_GPR_Mem:
                {
                }break;
                case AddressingMode_rFLAGS:
                {
                }break;
                case AddressingMode_RegGPR:
                {
                }break;
                case AddressingMode_VEX_yMM:
                {
                }break;
                case AddressingMode_Immediate:
                {
                }break;
                case AddressingMode_RIP_offset:
                {
                }break;
                case AddressingMode_8b_imm_yMM:
                {
                }break;//NOTE(Alex): The upper 4 bits of the 8 bit immediate selects a XMM or YMM register
                case AddressingMode_MODRM_Mem_only:
                {
                }break;
                case AddressingMode_RM_MMX:
                {
                }break;
                case AddressingMode_NO_MODRM:
                {
                }break;
                case AddressingMode_RegMMX:
                {
                }break;
                case AddressingMode_MODRM_MMX_Mem:
                {
                }break;
                
                case AddressingMode_RM_GPR_only:
                {
                }break;
                case AddressingMode_Reg_Segment:
                {
                }break;
                case AddressingMode_RM_yMM:
                {
                }break;
                case AddressingMode_Reg_yMM:
                {
                }break;
                case AddressingMode_MODRM_yMM_Mem:
                {
                }break;
                case AddressingMode_DS_rSI_Mem:
                {
                }break;
                case AddressingMode_ES_rDI_Mem:
                {
                }break;
                case AddressingMode_Count:
                {
                }break;
                default:
                {
                    InvalidCodePath;
                }
            }
            
            for(uint32_t ByteIndex = 0;
                ByteIndex < Operand->Type;
                ++ByteIndex)
            {
                Assert(IsValidFilePtr(ImmFilePtr));
                printf_s("%x", *ImmFilePtr);
            }
            
            
            //Hints = PushArray(Arena, Count,eflype_opcode_size_hints);
            eflype_opcode_bloc * Block = LexOpcodeBlock(PEManager);
            ListInstructionrefixes(PEManager, Block);
            FindInstructionMnemonic(PEManager, Block);
            FindOperands(Block);
            
            if(InstructionFound)
            {
                DisasmState.OpcodeBase = DisasmState.CFilePtrByte;
            }
            
        }
#endif
    }
    else
    {
        printf_s("Invalid File");
    }
    
    return 0;
}















