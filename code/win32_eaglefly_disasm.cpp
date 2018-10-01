/*
NOTE(Alex): This is gonna be our win32 platform layer!
Work from here, write the usage code first and see the API!


//TODO(Alex): Find a way to find out whether opcode is x64 or x86
//TODO(Alex): Support Big Endianness?
//NOTE(Alex): Now we are assuming is x64 opcode

NOTE(Alex): For starters ... 
One opcode byte encoding without MOD R/M Opcode extensions
Memory constraint not necessary
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
            u32 U32Size = SafeTruncateU64ToU32(U64Size.QuadPart);
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

inline uint32_t 
MakeMask(uint32_t BitCount)
{
    uint32_t Result = 0;
    
    for(uint32_t BitIndex = 0;
        BitIndex < BitCount;
        ++BitIndex)
    {
        Result |= (1 << BitIndex);
    }
    
    return Result;
}

inline uint32_t
GetBits(efly_disasm_state * DisasmState, eflyop_encoding * Encoding, eflyop_bfield_type BFieldFlag)
{
    uint32_t Result = 0;
    
    //TODO(Alex): Make special case MainOpcode extension!
    for(uint32_t BFieldIndex = 0;
        BFieldIndex < Encoding->TotalBFieldCount;
        ++BFieldIndex)
    {
        eflyop_bfield * BField = Encoding->BFields + BFieldIndex;
        if(BField->Type == BFieldFlag)
        {
            uint32_t ByteOffset = BField->BitOffset / 8; 
            uint32_t BitOffset = BField->BitOffset % 8; 
            uint8_t Temp = Encoding->Base[ByteOffset];
            uint32_t Mask = MakeMask(BField->BitCount);
            Result = (Temp >> BitOffset) & Mask;
            break;
        }
    }
    
    return Result;
}

internal void 
BeginAddressExtraction(efly_disasm_state * DisasmState)
{
    
}

internal void
GetEffectiveAddressMnemonic(efly_disasm_state * DisasmState, uint32_t BitField, char * Out_Buffer, uint32_t BufferCount, 
                            eflyop_flags * Flags)
{
    
}

internal void 
EndAddressExtraction(efly_disasm_state * DisasmState)
{
    
}

#define SignExtend16(value) SignExtend_(value, sizeof(uint16_t))
#define SignExtend32(value) SignExtend_(value, sizeof(uint32_t))

inline uint32_t
SignExtend_(uint32_t Value, uint32_t  ByteSize)
{
    uint32_t Result = 0;
    bit_info BitInfo = BitScanReverseU32(Value);
    
    if(BitInfo.Set)
    {
        uint32_t Mask = 0;
        uint32_t MaskCount = ((ByteSize * 8) - BitInfo.Index);
        Mask = MakeMask(MaskCount);
        Result = (Value | (Mask << BitInfo.Index));
        
        if(ByteSize == 2)
        {
            Result = SafeTruncateU32ToU16(Result);
        }
    }
    
    return Result;
}

#define GET_H4BIT_BYTE(Byte) (Byte) >> 4
#define GET_L4BIT_BYTE(Byte) (Byte) & 0x0F

internal b32
TranslateOpcodeAt(efly_disasm_state * DisasmState, 
                  char * CFilePtr, 
                  eflyop_bgroup * PrefixGroup, 
                  eflyop_prototype * Out_OpProt, 
                  b32 Is64BitMode)
{
    b32 Result = false;
    if(!DisasmState->TablesPresent)
    {
        //TODO(Alex): Load them Lazily
        OutputDebugStringA("Opcode Table not found");
        Result = DisasmState->TablesPresent = true;
        
        uint8_t FakeEncoding[2] = 
        {
            0x00, 0xC0, //NOTE(Alex): 0000 000w : 11 reg1 reg2;;
        };
        
#if 1   
        //NOTE(Alex): Test Table Entry!
        eflyop_table_entry * TestEntry = DisasmState->OneByteTablex64; //NOTE(Alex): 0000 000w : 11 reg1 reg2;
        eflyop_encoding * TestEncoding = DisasmState->EncodingsTable; //NOTE(Alex): 0000 000w : 11 reg1 reg2;
        
        TestEntry->Mnemonic = "ADD";
        TestEntry->EncodingIndex = 0;
        TestEntry->OperandCount = 2;
        
        TestEntry->OperandInfos[0].AddrMode = AddressingMode_MODRM_GPR_Mem;
        TestEntry->OperandInfos[0].Type = OperandTypeInfo_b;
        TestEntry->OperandInfos[1].AddrMode = AddressingMode_RegGPR;
        TestEntry->OperandInfos[1].Type = OperandTypeInfo_b;
        
        
        TestEncoding->TotalBFieldCount = 7;
        TestEncoding->BFields[0].Type = BitField_mainopbyte;
        TestEncoding->BFields[0].BitCount = 8;
        TestEncoding->BFields[0].BitOffset = 0;
        
        TestEncoding->BFields[1].Type = BitField_d;
        TestEncoding->BFields[1].BitCount = 1;
        TestEncoding->BFields[1].BitOffset = 1;
        
        TestEncoding->BFields[2].Type = BitField_w;
        TestEncoding->BFields[2].BitCount = 1;
        TestEncoding->BFields[2].BitOffset = 0;
        
        TestEncoding->BFields[3].Type = BitField_mod;
        TestEncoding->BFields[3].BitCount = 2;
        TestEncoding->BFields[3].BitOffset = 8 + 6;
        
        TestEncoding->BFields[4].Type = BitField_reg1;
        TestEncoding->BFields[4].BitCount = 3;
        TestEncoding->BFields[4].BitOffset = 8 + 3;
        
        TestEncoding->BFields[5].Type = BitField_reg2;
        TestEncoding->BFields[5].BitCount = 3;
        TestEncoding->BFields[5].BitOffset = 8 + 0;
        
        TestEncoding->BFields[6].Type = BitField_modrmbyte;
        TestEncoding->BFields[6].BitCount = 8;
        TestEncoding->BFields[6].BitOffset = 8 + 0;
        
        TestEncoding->Base = FakeEncoding;
        
#endif
        
        //Result = LoadTable(Blah);
        //if(Result)
        {
#if 0    
            uint8_t MainOpByte = *CFilePtr;
            //if(PrefixGroup->ByteCount)
            {
                char * MandatoryPrefix, * PrevByte;
                PrevByte = *(MainOpByte - 1);
                if(*PrevByte == OpcodePrefix_REX)
                {
                    MandatoryPrefix = MandatoryPrefix
                }
                else
                {
                    MandatoryPrefix = PrevByte;
                }
            }
#else
            uint8_t MainOpByte = 0x00; 
#endif
            
            //TODO(Alex): Make OneByteOpcodeTable Fit into memory!
            uint32_t XOffset = GET_H4BIT_BYTE(MainOpByte);
            uint32_t YOffset = GET_L4BIT_BYTE(MainOpByte);
            
            //TODO(Alex): Make a caching system for fast lookup
            eflyop_table_entry * Table = DisasmState->OneByteTablex64; //(Is64BitMode) ? DisasmState->OneBytex64Table : DisasmState->OneByteOpTablex86;
            Assert((XOffset >= 0) && (XOffset <= 0xF) && 
                   (YOffset >= 0) && (YOffset <= 0xF));
            
            eflyop_table_entry * Entry = Table + (YOffset * 0x10 + XOffset);
            eflyop_encoding * Encoding = DisasmState->EncodingsTable + Entry->EncodingIndex;
            
            //(char)GetNextBits(Encoding->Buffer, Offset, Count)
            
            eflyop_flags OpFlagsArray[8] = {};
#if 1                
            for(uint32_t OperandIndex = 0;
                OperandIndex < Entry->OperandCount;
                ++OperandIndex)
            {
                eflyop_operand_info * OperandInfo = Entry->OperandInfos + OperandIndex;
                eflyop_flags * OpFlags = OpFlagsArray + OperandIndex;
                
                switch(OperandInfo->AddrMode)
                {
                    case AddressingMode_DirectAddress:
                    {
                        
                    }break;
                    case AddressingMode_VEX_GPR:
                    {
                        //TODO(Alex): VEX Encoding
                    }break;
                    case AddressingMode_RegControl:
                    {
                        
                    }break;
                    
                    case AddressingMode_RegDebug:
                    {
                    }break;
                    case AddressingMode_MODRM_GPR_Mem:
                    {
                        OpFlags->MODRMNext = true;
                        OpFlags->OperandType = OperandType_GPR | OperandType_Mem;
                    }break;
                    case AddressingMode_rFLAGS:
                    {
                    }break;
                    case AddressingMode_RegGPR:
                    {
                        OpFlags->OperandType = OperandType_GPR;
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
                        OpFlags->MODRMNext = true;
                        OpFlags->OperandType = OperandType_Mem;
                    }break;
                    case AddressingMode_RM_MMX:
                    {
                        
                    }break;
                    case AddressingMode_NO_MODRM:
                    {
                        OpFlags->MODRMNext = false;
                    }break;
                    
                    case AddressingMode_RegMMX:
                    {
                        OpFlags->OperandType = OperandType_MMX;
                        OpFlags->DataSize = DataSize_MMX;
                    }break;
                    
                    case AddressingMode_MODRM_MMX_Mem:
                    {
                        OpFlags->MODRMNext = true;
                        OpFlags->OperandType = OperandType_MMX; 
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
                        OpFlags->MODRMNext = true;
                        OpFlags->OperandType = OperandType_YMM; 
                        OpFlags->DataSize = DataSize_YMM; 
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
                
            }
#endif
            
            
            uint32_t reg, mod, rm, sreg2, sreg3, reg1, reg2, reg3, imm, eee, s, w, d, tttn, ModRMByte, SIBByte;
            b32 RegToMODRM = false;
            
            //NOTE(Alex): So since we dont know the order od regs sregs, the encoding already knows that, we just have to have a call for all the special bits
            sreg2 = GetBits(DisasmState, Encoding, BitField_sreg2);
            sreg3 = GetBits(DisasmState, Encoding, BitField_sreg3);
            reg1 = GetBits(DisasmState, Encoding, BitField_reg1);
            reg2 = GetBits(DisasmState, Encoding, BitField_reg2);
            reg3 = GetBits(DisasmState, Encoding, BitField_reg3);
            reg = GetBits(DisasmState, Encoding, BitField_reg);
            eee = GetBits(DisasmState, Encoding, BitField_eee);
            mod = GetBits(DisasmState, Encoding, BitField_mod);
            rm = GetBits(DisasmState, Encoding, BitField_rm);
            w = GetBits(DisasmState, Encoding, BitField_w);
            imm = GetBits(DisasmState,Encoding, BitField_imm);
            s = GetBits(DisasmState,Encoding, BitField_s);
            d = GetBits(DisasmState,Encoding, BitField_d);
            tttn = GetBits(DisasmState,Encoding, BitField_tttn);
            ModRMByte = GetBits(DisasmState,Encoding, BitField_modrmbyte);
            SIBByte = GetBits(DisasmState,Encoding, BitField_sibbyte);
            
            Assert(MainOpByte == (uint8_t)GetBits(DisasmState, Encoding, BitField_mainopbyte));
            //Assert((MainOpByte + 1)  == (uint8_t)GetBits(DisasmState, Encoding, BitField_modrmbyte));
            
            RegToMODRM = (d) ? false : true; 
            
#define BUFFER_COUNT 128
            char BufferA[BUFFER_COUNT] = {0};
            char BufferB[BUFFER_COUNT] = {0};
            char BufferC[BUFFER_COUNT] = {0};
            
            eflyop_operand Source = {};
            eflyop_operand Dest = {};
            
            if(tttn)
            {
                //NOTE(Alex): Only for conditional jumps and set on condition
#if 0                
                char * ConMnemonic = DisasmState->ConditionTable + tttn;
                fprintf("%s%s", Entry->Mnemonic, ConMnemonic);
#endif
                
            }
            
            if(ModRMByte)
            {
                BeginAddressExtraction(DisasmState);
                GetEffectiveAddressMnemonic(DisasmState, ModRMByte, BufferA, BUFFER_COUNT, OpFlagsArray);
                GetEffectiveAddressMnemonic(DisasmState, ModRMByte, BufferB, BUFFER_COUNT, OpFlagsArray);
                GetEffectiveAddressMnemonic(DisasmState, SIBByte, BufferC, BUFFER_COUNT, OpFlagsArray);
                EndAddressExtraction(DisasmState);
                
                Source.Data = (RegToMODRM)  ? BufferA : BufferB;
                Dest.Data = (RegToMODRM)  ? BufferB : BufferA;
                printf_s(" %*s %*s ", Dest.LetterCount, Dest.Data, Source.LetterCount, Source.Data);
            }
            else
            {
                //NOTE(Alex): Has to be encoded inside main opcode
                BeginAddressExtraction(DisasmState);
                GetEffectiveAddressMnemonic(DisasmState, reg, BufferA, BUFFER_COUNT, OpFlagsArray);
                EndAddressExtraction(DisasmState);
                printf_s(" %s ", BufferA);
            }
            
            // NOTE(Alex): The sign-extend (s) bit occurs in instructions with immediate data fields that are being extended from 8 bits to 16 or 32 bits.
            if(s)
            {
                if(!(imm >> 8))
                {
                    if(Dest.DataSize == DataSize_16Bit)
                    {
                        imm = SignExtend16(imm);
                    }
                    else if(Dest.DataSize == DataSize_32Bit)
                    {
                        imm = SignExtend32(imm);
                    }
                }
                
                printf_s("%x", imm);
            }
            
#if 0    
            //NOTE(Alex): Prefix decoding
            uint32_t PrefixFlags = 0;
            for(uint32_t PrefixIndex = 0;
                PrefixIndex < PrefixGroup->ByteCount;
                ++PrefixIndex)
            {
                char * CPrefix = PrefixGroup->MinFilePtr + PrefixIndex;
                
                switch(*CPrefix)
                {
                    case 0xF0:
                    {
                        PrefixFlags |= OpcodePrefix_LOCK;
                    }break;
                    case 0xF2:
                    {
                        PrefixFlags |= OpcodePrefix_REPNE;
                        PrefixFlags |= OpcodePrefix_BND;
                    }break;
                    case OpcodePrefix_OperandSizeOV:
                    {
                        PrefixFlags |= OpcodePrefix_LOCK;
                    }break;
                    case OpcodePrefix_SegmentOV:
                    {
                        PrefixFlags |= OpcodePrefix_LOCK;
                    }break;
                    case OpcodePrefix_LOCKAndRepeat:
                    {
                        PrefixFlags |= OpcodePrefix_LOCK;
                    }break;
                    default:
                    {
                        InvalidCodePath;
                    }break;
                }
            }
#endif
        }
    }
    
    
    return Result;
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


//TODO(Alex): Load this from file?
//TODO(Alex): Add Prefix identification
//TODO(Alex): Shall we make the user choose which size attrivutes  
//the instruction arquitecture should target? Or we use the current arquitecture?


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
    
    //TODO(Alex): shall we let the user define this?
    b32 Is64BitMode = true;
    
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
        
        
        
        eflyop_bgroup PrefixBGroup = {};
        eflyop_prototype OpProt_ = {};
        eflyop_prototype * out_OpProt = &OpProt_;
        
        u32 FirstPassByteCount =  MAX_PREFIX_COUNT_64 + MAX_MAIN_OPCODE_COUNT;
        
        uint32_t BufferCount = 0;
        char Buffer[4096];
        //TODO(Alex): Assert not going out of bounds
        for(;
            DisasmState->CFilePtrByte < (DisasmState->CFilePtrBase + DisasmState->CodeSectionSize);)
        {
            if(ByteIsPrefix(*DisasmState->CFilePtrByte))
            {
                if(!PrefixBGroup.MinFilePtr)
                {
                    PrefixBGroup.MinFilePtr = DisasmState->CFilePtrByte;
                }
                
                Assert(PrefixBGroup.ByteCount < MAX_PREFIX_COUNT_64);
                ++PrefixBGroup.ByteCount;
                
                ++DisasmState->CFilePtrByte;
            }
            else
            {
                //NOTE(Alex): This will move the CFilePtr
                //eflyop_bitfield BField= GetNextBits(Buffer, 8);
                if(TranslateOpcodeAt(DisasmState, DisasmState->CFilePtrByte, &PrefixBGroup, out_OpProt, Is64BitMode))
                {
                    if(DisasmState->CFilePtrByte && out_OpProt->ModRMPresent)
                    {
                        DecodeExtraBytes(DisasmState, DisasmState->CFilePtrByte, out_OpProt);
                    }
                    
                    printf_s("0x%I64x\n", DisasmState->IP);
                    PrintOpcodeBytes(DisasmState, &out_OpProt->IBGroup);
                    PrintInstructionSymbols(DisasmState, BufferCount, Buffer);
                    DisasmState->IP += out_OpProt->IBGroup.ByteCount;
                    PrefixBGroup.MinFilePtr = 0;
                }
                else
                {
                    //NOTE(Alex): Error loading tables
                    break;
                }
            }
        }
    }
    else
    {
        printf_s("Invalid File");
    }
    
    return 0;
}















