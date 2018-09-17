/*
NOTE(Alex): eaglefly_pe_parser.cpp

Parses COFF and PE Files and etracts symbol and type information out of   
*/

#include <Windows.h>
#include "eaglefly_platform.h"
#include "eaglefly_pe_parser.h"
#include "stdio.h"

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


READ_ENTIRE_FILE(Win32ReadEntireFile)
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

#define CheckAlignment(Alignment, Value) Assert(!((Value) & ((Alignment) - 1)));

internal eflype_section_id
GetSectionNameID(eflype_section_header * SectionHeader)
{
    eflype_section_id Result = SectionID_none;
    //NOTE(Alex): This has to mach eflype_section_id enumeration!
    //TODO(Alex): Find a way to match them easily
    char SectionNames[MAX_SECTION_COUNT][SECTION_NAME_COUNT + 1] = 
    {
        "",
        ".text",
        ".data",
        ".idata",
        ".rdata",
        ".reloc",
        ".drectve",
        ".edata",
        ".pdata",
        ".tls",
        ".rsrc",
    };
    
    b32 SectionFound = false; 
    uint32_t CharIndex = 0;
    for(uint32_t SectionNameIndex = 0;
        (SectionNameIndex < MAX_SECTION_COUNT) && !SectionFound;
        ++SectionNameIndex)
    {
        CharIndex = 0;
        char * A = SectionNames[SectionNameIndex];
        char * B = SectionHeader->Name + CharIndex;
        for(;
            (*A == *B) && (!SectionFound);
            ++A, ++B, ++CharIndex)
        {
            if(CharIndex >= (SECTION_NAME_COUNT - 1))
            {
                Result = (eflype_section_id)SectionNameIndex;
                SectionFound = true;
            }
        }
    }
    
    return Result;
}

internal eflype_section_header * 
GetSectionHeader(eflype_manager * PEManager, eflype_section_id ID)
{
    eflype_section_header * Result = 0;
    if((ID > SectionID_none) && (ID < SectionID_count))
    {
        for(uint32_t Index = 0;
            Index < SectionID_count;
            ++Index)
        {
            eflype_section_entry * Entry = PEManager->SectionTable + Index;
            if(Entry->ID == ID)
            {
                Result = PEManager->SHeaderTable[Entry->Index]; 
                break;
            }
        }
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

internal void
DecodeOpcode(efly_disasm_state * DisasmState, char * MonoOpcode, efly_mnemonic * CMnemonic, efly_opcode_table_type OpTableType)
{
    
}

int main(int Argcount, char ** Arguments)
{
    b32 IsPEFile = false;
    b32 Isx86Arch = false;
    char * FileName = Arguments[1];
    uint32_t Temp = IMAGE_FILE_DEBUG_STRIPPED;
    
    if(FileName)
    {
        char * BeginOfFile = 0;
        debug_file_content PDBContent = Win32ReadEntireFile(FileName);
        eflype_manager PEManager = {};
        PEManager.FileSize = PDBContent.Size;
        PEManager.Base = (char*)PDBContent.Content;
        PEManager.At = PEManager.Base;
        if(PEManager.Base && PEManager.FileSize)
        {
            uint32_t * FileOffset = DWORD_PTR(BYTE_PTR(PEManager.Base) + 0x3c);
            char * PESignature = CHAR_PTR(PEManager.Base)  + *FileOffset;
            IsPEFile  = (CheckFilePESignature(PESignature) ? true : false); 
            eflype_coff_header * COFFHeader = (!IsPEFile) ? (eflype_coff_header*)PEManager.Base : (eflype_coff_header*)(PESignature + 4);
            
            if(COFFHeader->MachineType == MACHINE_TYPE_AMD64)
            {
                Assert((COFFHeader->Characteristics & IMAGE_FILE_EXECUTABLE_IMAGE));
                Isx86Arch = (b32)(COFFHeader->Characteristics &IMAGE_FILE_32BIT_MACHINE);
                uint16_t * MagicNum = (uint16_t*)(COFFHeader + 1);
                
                if(*MagicNum == PE32_IMAGE)
                {
                    eflype_standard_opt_header * StandardOptHeader = (eflype_standard_opt_header*)MagicNum;
                    eflype_windows_opt_header * WindowsOptHeader = (eflype_windows_opt_header*)(StandardOptHeader + 1);
                    
                    PEManager.OptHeader.Magic = StandardOptHeader->Magic;
                    PEManager.OptHeader.MajorLinkerVersion = StandardOptHeader->MajorLinkerVersion;
                    PEManager.OptHeader.MinorLinkerVersion = StandardOptHeader->MinorLinkerVersion;
                    PEManager.OptHeader.SizeOfCode = StandardOptHeader->SizeOfCode;
                    PEManager.OptHeader.SizeOfInitializedData = StandardOptHeader->SizeOfInitializedData;
                    PEManager.OptHeader.SizeOfUninitializedData = StandardOptHeader->SizeOfUninitializedData;
                    PEManager.OptHeader.AddressOfEntryPoint = StandardOptHeader->AddressOfEntryPoint;
                    PEManager.OptHeader.BaseOfCode = StandardOptHeader->BaseOfCode;
                    PEManager.OptHeader.BaseOfData = StandardOptHeader->BaseOfData;
                    
                    PEManager.OptHeader.ImageBase = (uint64_t)WindowsOptHeader->ImageBase;
                    PEManager.OptHeader.SectionAlignment = WindowsOptHeader->SectionAlignment;
                    PEManager.OptHeader.FileAlignment = WindowsOptHeader->FileAlignment;
                    PEManager.OptHeader.MajorOperatingSystemVersion = WindowsOptHeader->MajorOperatingSystemVersion;
                    PEManager.OptHeader.MinorOperatingSystemVersion = WindowsOptHeader->MinorOperatingSystemVersion;
                    PEManager.OptHeader.MajorImageVersion = WindowsOptHeader->MajorImageVersion;
                    PEManager.OptHeader.MinorImageVersion = WindowsOptHeader->MinorImageVersion;
                    PEManager.OptHeader.MajorSubsystemVersion = WindowsOptHeader->MajorSubsystemVersion;
                    PEManager.OptHeader.MinorSubsystemVersion = WindowsOptHeader->MinorSubsystemVersion;
                    PEManager.OptHeader.Win32VersionValue = WindowsOptHeader->Win32VersionValue;
                    PEManager.OptHeader.SizeOfImage = WindowsOptHeader->SizeOfImage;
                    PEManager.OptHeader.SizeOfHeaders = WindowsOptHeader->SizeOfHeaders;
                    PEManager.OptHeader.CheckSum = WindowsOptHeader->CheckSum;
                    PEManager.OptHeader.Subsystem = WindowsOptHeader->Subsystem;
                    PEManager.OptHeader.DllCharacteristics = WindowsOptHeader->DllCharacteristics;
                    PEManager.OptHeader.SizeOfStackReserve = (uint64_t)WindowsOptHeader->SizeOfStackReserve;
                    PEManager.OptHeader.SizeOfStackCommit = (uint64_t)WindowsOptHeader->SizeOfStackCommit;
                    PEManager.OptHeader.SizeOfHeapReserve = (uint64_t)WindowsOptHeader->SizeOfHeapReserve;
                    PEManager.OptHeader.SizeOfHeapCommit = (uint64_t)WindowsOptHeader->SizeOfHeapCommit;
                    PEManager.OptHeader.LoaderFlags = WindowsOptHeader->LoaderFlags;
                    PEManager.OptHeader.NumberOfRvaAndSizes = WindowsOptHeader->NumberOfRvaAndSizes;
                    PEManager.OptHeader.PE32Type = false; 
                }
                else
                {
                    eflype_plus_standard_opt_header * StandardOptHeader = (eflype_plus_standard_opt_header*)MagicNum;;
                    eflype_plus_windows_opt_header * WindowsOptHeader = (eflype_plus_windows_opt_header*)(StandardOptHeader + 1);
                    
                    PEManager.OptHeader.Magic = StandardOptHeader->Magic;
                    PEManager.OptHeader.MajorLinkerVersion = StandardOptHeader->MajorLinkerVersion;
                    PEManager.OptHeader.MinorLinkerVersion = StandardOptHeader->MinorLinkerVersion;
                    PEManager.OptHeader.SizeOfCode = StandardOptHeader->SizeOfCode;
                    PEManager.OptHeader.SizeOfInitializedData = StandardOptHeader->SizeOfInitializedData;
                    PEManager.OptHeader.SizeOfUninitializedData = StandardOptHeader->SizeOfUninitializedData;
                    PEManager.OptHeader.AddressOfEntryPoint = StandardOptHeader->AddressOfEntryPoint;
                    PEManager.OptHeader.BaseOfCode = StandardOptHeader->BaseOfCode;
                    
                    PEManager.OptHeader.ImageBase = (uint64_t)WindowsOptHeader->ImageBase;
                    PEManager.OptHeader.SectionAlignment = WindowsOptHeader->SectionAlignment;
                    PEManager.OptHeader.FileAlignment = WindowsOptHeader->FileAlignment;
                    PEManager.OptHeader.MajorOperatingSystemVersion = WindowsOptHeader->MajorOperatingSystemVersion;
                    PEManager.OptHeader.MinorOperatingSystemVersion = WindowsOptHeader->MinorOperatingSystemVersion;
                    PEManager.OptHeader.MajorImageVersion = WindowsOptHeader->MajorImageVersion;
                    PEManager.OptHeader.MinorImageVersion = WindowsOptHeader->MinorImageVersion;
                    PEManager.OptHeader.MajorSubsystemVersion = WindowsOptHeader->MajorSubsystemVersion;
                    PEManager.OptHeader.MinorSubsystemVersion = WindowsOptHeader->MinorSubsystemVersion;
                    PEManager.OptHeader.Win32VersionValue = WindowsOptHeader->Win32VersionValue;
                    PEManager.OptHeader.SizeOfImage = WindowsOptHeader->SizeOfImage;
                    PEManager.OptHeader.SizeOfHeaders = WindowsOptHeader->SizeOfHeaders;
                    PEManager.OptHeader.CheckSum = WindowsOptHeader->CheckSum;
                    PEManager.OptHeader.Subsystem = WindowsOptHeader->Subsystem;
                    PEManager.OptHeader.DllCharacteristics = WindowsOptHeader->DllCharacteristics;
                    PEManager.OptHeader.SizeOfStackReserve = (uint64_t)WindowsOptHeader->SizeOfStackReserve;
                    PEManager.OptHeader.SizeOfStackCommit = (uint64_t)WindowsOptHeader->SizeOfStackCommit;
                    PEManager.OptHeader.SizeOfHeapReserve = (uint64_t)WindowsOptHeader->SizeOfHeapReserve;
                    PEManager.OptHeader.SizeOfHeapCommit = (uint64_t)WindowsOptHeader->SizeOfHeapCommit;
                    PEManager.OptHeader.LoaderFlags = WindowsOptHeader->LoaderFlags;
                    PEManager.OptHeader.NumberOfRvaAndSizes = WindowsOptHeader->NumberOfRvaAndSizes;
                    PEManager.OptHeader.PE32Type = true; 
                }
                
                if(PEManager.OptHeader.SectionAlignment < ARCH_PAGE_SIZE)
                {
                    Assert(PEManager.OptHeader.SectionAlignment == PEManager.OptHeader.FileAlignment);
                }
                
                Assert(!(PEManager.OptHeader.ImageBase & (0xFFFF - 1)));
                CheckAlignment(PEManager.OptHeader.SectionAlignment, PEManager.OptHeader.SizeOfImage);
                
                //TODO(Alex):Extract Data Directories
                eflype_section_header * HeaderSource = (eflype_section_header*)((char*)MagicNum + COFFHeader->SizeOptHeader);
                for(uint32_t SHeaderIndex = 0;
                    SHeaderIndex < COFFHeader->SectionCount;
                    ++SHeaderIndex)
                {
                    if(HeaderSource->VirtualSize)
                    {
                        CheckAlignment(PEManager.OptHeader.FileAlignment, HeaderSource->PointerToRawData); 
                        CheckAlignment(PEManager.OptHeader.FileAlignment, HeaderSource->SizeOfRawData); 
                        Assert(PEManager.SectionCount < MAX_SECTION_COUNT);
                        uint32_t SectionIndex = PEManager.SectionCount++;
                        
                        eflype_section_header ** HeaderDest = PEManager.SHeaderTable + SectionIndex;
                        *HeaderDest = HeaderSource;
                        
                        eflype_section_entry * SectionEntry = PEManager.SectionTable + SectionIndex;
                        SectionEntry->ID = GetSectionNameID(HeaderSource);
                        SectionEntry->Index = SectionIndex;
                    }
                    
                    ++HeaderSource;
                }
                
                //TODO(Alex): Find a way to find out whether opcode is x64 or x86
                //NOTE(Alex): Now we are assuming is x64 opcode
                
                /*
NOTE(Alex): For starters ... 
                One opcode byte encoding without MOD R/M Opcode extensions
                Memory constraint not necessary
                
                //TODO(Alex): Make an independent pass for the disassembler so it 
is totally isolated from the PE parser 
                */
                
                
                eflype_section_header * SHeader = GetSectionHeader(&PEManager, SectionID_text); 
                
                efly_disasm_state DisasmState = {};
                DisasmState.CodeSegmentBase = CHAR_PTR(PEManager.Base) + SHeader->PointerToRawData; 
                DisasmState.COpcodeByte = DisasmState.CodeSegmentBase; 
                DisasmState.COpcodeBase = DisasmState.COpcodeByte;
                DisasmState.CodeSegmentSize = SHeader->SizeOfRawData;
                //TODO(Alex): Load this from file?
                //InitializeOpcodeTable(DisasmState, DisasmState.MonoOpcodeTable, MONO_OPCODE_TABLE_SIZE);
                
#if 0                
                char * PrefixMinBound = DisasmState.COpcodeByte;
                char * PrefixMaxBound = PrefixMinBound + MAX_PREFIX_COUNT_64;
                for(uint32_t ByteIndex = 0;
                    ByteIndex < DisasmState.CodeSegmentSize;
                    ++ByteIndex)
                {
                    for(uint32_t PrefixIndex = 0; 
                        PrefixIndex < MAX_PREFIX_COUNT_64; 
                        ++PrefixIndex)
                    {
                        AddPrefixCheckFlag(PrefixByte);
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
                        
                        ++DisasmState.COpcodeByte;
                    }
                }
#endif
                
                //TODO(Alex): Add Prefix identification
                //TODO(Alex): Shall we make the user choose which size attrivutes  
                //the instruction arquitecture should target? Or we use the current arquitecture?
                char * MonoOpcode = DisasmState.COpcodeByte;
                efly_mnemonic * CMnemonic = PushStruct(&DisasmState.DisasmArena, efly_mnemonic);
                DecodeOpcode(&DisasmState, MonoOpcode, CMnemonic, OpTable_Mono);
                //printf_s("%s", CMnemonic->Size, CMnemonic->Text);
                
#define GET_H4BIT_WORD(...) 0
#define GET_L4BIT_WORD(...) 0
                
                for(uint32_t  OperandIndex = 0;
                    OperandIndex < CMnemonic->OperandCount;
                    ++OperandIndex)
                {
                    char * Operand = CMnemonic->AddressingTypeFlags + OperandIndex;
                    uint8_t AddressingMode = GET_H4BIT_WORD(Operand);
                    uint8_t Type = GET_L4BIT_WORD(Operand);
                    
                    switch(AddressingMode)
                    {
                        case AddressingMode_DirectAddress:
                        {
                            
                        }break;
                        case AddressingMode_VEX_GPR:
                        {
                            
                        }break;
                        case AddressingMode_RegControl:
                        {
                            
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
                    
                }
                
                
#if 0                
                //Hints = PushArray(Arena, Count,eflype_opcode_size_hints);
                eflype_opcode_bloc * Block = LexOpcodeBlock(PEManager);
                ListInstructionrefixes(PEManager, Block);
                FindInstructionMnemonic(PEManager, Block);
                FindOperands(Block);
                
                if(InstructionFound)
                {
                    DisasmState.OpcodeBase = DisasmState.COpcodeByte;
                }
#endif
                
                ++DisasmState.OpByteCount;
            }
            else
            {
                //TODO(Alex): Transform data to other architectures
                //ex. change endianness if necessary, 
                Assert(!"Other Architecure");
            }
        }
    }
}













