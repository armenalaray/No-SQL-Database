//////////////////////////////////////////////////////
//
//Author: Alejandro Armenta 
//Date: 2019
//File: eaglefly_pe_parser.cpp
//Company: 
//
//All rights reserved.
//
//////////////////////////////////////////////////////

/*
Parses COFF and PE Files and etracts symbol and type information out of it
*/

#include "eaglefly_pe_parser.h"
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


inline b32 
FilePtrIsInSegment(eflype_section_header * SHeader, void * FilePtr)
{
    b32 Result = (((memory_index)FilePtr > (memory_index)SHeader->PointerToRawData) && 
                  ((memory_index)FilePtr < (memory_index)(SHeader->PointerToRawData + SHeader->SizeOfRawData)));
    return Result;
}


inline void * 
GetFilePtrFromImageBase(eflype_manager * PEManager, memory_index RelP)
{
    void * Result = CHAR_PTR(PEManager->Base) + RelP;
    return Result;
}

//TODO(Alex): Work the debug_file_content so it can work on other platforms!
internal b32 
eflype_InitParser(eflype_manager * PEManager , debug_file_content * PEContent)
{
    b32 Result = false;
    b32 Isx86Arch = false;
    uint32_t Temp = IMAGE_FILE_DEBUG_STRIPPED;
    
    if(PEContent->Content && PEContent->Size)
    {
        PEManager->FileSize = PEContent->Size;
        PEManager->Base = (char*)PEContent->Content;
        PEManager->At = PEManager->Base;
        
        uint32_t * FileOffset = DWORD_PTR(BYTE_PTR(PEManager->Base) + 0x3c);
        char * PESignature = CHAR_PTR(PEManager->Base)  + *FileOffset;
        Result = (CheckFilePESignature(PESignature) ? true : false); 
        if(Result)
        {
            eflype_coff_header * COFFHeader = (!Result) ? (eflype_coff_header*)PEManager->Base : (eflype_coff_header*)(PESignature + 4);
            if(COFFHeader->MachineType == MACHINE_TYPE_AMD64)
            {
                Assert((COFFHeader->Characteristics & IMAGE_FILE_EXECUTABLE_IMAGE));
                Isx86Arch = (b32)(COFFHeader->Characteristics &IMAGE_FILE_32BIT_MACHINE);
                uint16_t * MagicNum = (uint16_t*)(COFFHeader + 1);
                
                if(*MagicNum == PE32_IMAGE)
                {
                    eflype_standard_opt_header * StandardOptHeader = (eflype_standard_opt_header*)MagicNum;
                    eflype_windows_opt_header * WindowsOptHeader = (eflype_windows_opt_header*)(StandardOptHeader + 1);
                    
                    PEManager->OptHeader.Magic = StandardOptHeader->Magic;
                    PEManager->OptHeader.MajorLinkerVersion = StandardOptHeader->MajorLinkerVersion;
                    PEManager->OptHeader.MinorLinkerVersion = StandardOptHeader->MinorLinkerVersion;
                    PEManager->OptHeader.SizeOfCode = StandardOptHeader->SizeOfCode;
                    PEManager->OptHeader.SizeOfInitializedData = StandardOptHeader->SizeOfInitializedData;
                    PEManager->OptHeader.SizeOfUninitializedData = StandardOptHeader->SizeOfUninitializedData;
                    PEManager->OptHeader.AddressOfEntryPoint = StandardOptHeader->AddressOfEntryPoint;
                    PEManager->OptHeader.BaseOfCode = StandardOptHeader->BaseOfCode;
                    PEManager->OptHeader.BaseOfData = StandardOptHeader->BaseOfData;
                    
                    PEManager->OptHeader.ImageBase = (uint64_t)WindowsOptHeader->ImageBase;
                    PEManager->OptHeader.SectionAlignment = WindowsOptHeader->SectionAlignment;
                    PEManager->OptHeader.FileAlignment = WindowsOptHeader->FileAlignment;
                    PEManager->OptHeader.MajorOperatingSystemVersion = WindowsOptHeader->MajorOperatingSystemVersion;
                    PEManager->OptHeader.MinorOperatingSystemVersion = WindowsOptHeader->MinorOperatingSystemVersion;
                    PEManager->OptHeader.MajorImageVersion = WindowsOptHeader->MajorImageVersion;
                    PEManager->OptHeader.MinorImageVersion = WindowsOptHeader->MinorImageVersion;
                    PEManager->OptHeader.MajorSubsystemVersion = WindowsOptHeader->MajorSubsystemVersion;
                    PEManager->OptHeader.MinorSubsystemVersion = WindowsOptHeader->MinorSubsystemVersion;
                    PEManager->OptHeader.Win32VersionValue = WindowsOptHeader->Win32VersionValue;
                    PEManager->OptHeader.SizeOfImage = WindowsOptHeader->SizeOfImage;
                    PEManager->OptHeader.SizeOfHeaders = WindowsOptHeader->SizeOfHeaders;
                    PEManager->OptHeader.CheckSum = WindowsOptHeader->CheckSum;
                    PEManager->OptHeader.Subsystem = WindowsOptHeader->Subsystem;
                    PEManager->OptHeader.DllCharacteristics = WindowsOptHeader->DllCharacteristics;
                    PEManager->OptHeader.SizeOfStackReserve = (uint64_t)WindowsOptHeader->SizeOfStackReserve;
                    PEManager->OptHeader.SizeOfStackCommit = (uint64_t)WindowsOptHeader->SizeOfStackCommit;
                    PEManager->OptHeader.SizeOfHeapReserve = (uint64_t)WindowsOptHeader->SizeOfHeapReserve;
                    PEManager->OptHeader.SizeOfHeapCommit = (uint64_t)WindowsOptHeader->SizeOfHeapCommit;
                    PEManager->OptHeader.LoaderFlags = WindowsOptHeader->LoaderFlags;
                    PEManager->OptHeader.NumberOfRvaAndSizes = WindowsOptHeader->NumberOfRvaAndSizes;
                    PEManager->OptHeader.PE32Type = false; 
                }
                else
                {
                    eflype_plus_standard_opt_header * StandardOptHeader = (eflype_plus_standard_opt_header*)MagicNum;;
                    eflype_plus_windows_opt_header * WindowsOptHeader = (eflype_plus_windows_opt_header*)(StandardOptHeader + 1);
                    
                    PEManager->OptHeader.Magic = StandardOptHeader->Magic;
                    PEManager->OptHeader.MajorLinkerVersion = StandardOptHeader->MajorLinkerVersion;
                    PEManager->OptHeader.MinorLinkerVersion = StandardOptHeader->MinorLinkerVersion;
                    PEManager->OptHeader.SizeOfCode = StandardOptHeader->SizeOfCode;
                    PEManager->OptHeader.SizeOfInitializedData = StandardOptHeader->SizeOfInitializedData;
                    PEManager->OptHeader.SizeOfUninitializedData = StandardOptHeader->SizeOfUninitializedData;
                    PEManager->OptHeader.AddressOfEntryPoint = StandardOptHeader->AddressOfEntryPoint;
                    PEManager->OptHeader.BaseOfCode = StandardOptHeader->BaseOfCode;
                    
                    PEManager->OptHeader.ImageBase = (uint64_t)WindowsOptHeader->ImageBase;
                    PEManager->OptHeader.SectionAlignment = WindowsOptHeader->SectionAlignment;
                    PEManager->OptHeader.FileAlignment = WindowsOptHeader->FileAlignment;
                    PEManager->OptHeader.MajorOperatingSystemVersion = WindowsOptHeader->MajorOperatingSystemVersion;
                    PEManager->OptHeader.MinorOperatingSystemVersion = WindowsOptHeader->MinorOperatingSystemVersion;
                    PEManager->OptHeader.MajorImageVersion = WindowsOptHeader->MajorImageVersion;
                    PEManager->OptHeader.MinorImageVersion = WindowsOptHeader->MinorImageVersion;
                    PEManager->OptHeader.MajorSubsystemVersion = WindowsOptHeader->MajorSubsystemVersion;
                    PEManager->OptHeader.MinorSubsystemVersion = WindowsOptHeader->MinorSubsystemVersion;
                    PEManager->OptHeader.Win32VersionValue = WindowsOptHeader->Win32VersionValue;
                    PEManager->OptHeader.SizeOfImage = WindowsOptHeader->SizeOfImage;
                    PEManager->OptHeader.SizeOfHeaders = WindowsOptHeader->SizeOfHeaders;
                    PEManager->OptHeader.CheckSum = WindowsOptHeader->CheckSum;
                    PEManager->OptHeader.Subsystem = WindowsOptHeader->Subsystem;
                    PEManager->OptHeader.DllCharacteristics = WindowsOptHeader->DllCharacteristics;
                    PEManager->OptHeader.SizeOfStackReserve = (uint64_t)WindowsOptHeader->SizeOfStackReserve;
                    PEManager->OptHeader.SizeOfStackCommit = (uint64_t)WindowsOptHeader->SizeOfStackCommit;
                    PEManager->OptHeader.SizeOfHeapReserve = (uint64_t)WindowsOptHeader->SizeOfHeapReserve;
                    PEManager->OptHeader.SizeOfHeapCommit = (uint64_t)WindowsOptHeader->SizeOfHeapCommit;
                    PEManager->OptHeader.LoaderFlags = WindowsOptHeader->LoaderFlags;
                    PEManager->OptHeader.NumberOfRvaAndSizes = WindowsOptHeader->NumberOfRvaAndSizes;
                    PEManager->OptHeader.PE32Type = true; 
                }
                
                if(PEManager->OptHeader.SectionAlignment < ARCH_PAGE_SIZE)
                {
                    Assert(PEManager->OptHeader.SectionAlignment == PEManager->OptHeader.FileAlignment);
                }
                
                Assert(!(PEManager->OptHeader.ImageBase & (0xFFFF - 1)));
                CheckAlignment(PEManager->OptHeader.SectionAlignment, PEManager->OptHeader.SizeOfImage);
                
                //TODO(Alex):Extract Data Directories
                eflype_section_header * HeaderSource = (eflype_section_header*)((char*)MagicNum + COFFHeader->SizeOptHeader);
                for(uint32_t SHeaderIndex = 0;
                    SHeaderIndex < COFFHeader->SectionCount;
                    ++SHeaderIndex)
                {
                    if(HeaderSource->VirtualSize)
                    {
                        CheckAlignment(PEManager->OptHeader.FileAlignment, HeaderSource->PointerToRawData); 
                        CheckAlignment(PEManager->OptHeader.FileAlignment, HeaderSource->SizeOfRawData); 
                        Assert(PEManager->SectionCount < MAX_SECTION_COUNT);
                        uint32_t SectionIndex = PEManager->SectionCount++;
                        
                        eflype_section_header ** HeaderDest = PEManager->SHeaderTable + SectionIndex;
                        *HeaderDest = HeaderSource;
                        
                        eflype_section_entry * SectionEntry = PEManager->SectionTable + SectionIndex;
                        SectionEntry->ID = GetSectionNameID(HeaderSource);
                        SectionEntry->Index = SectionIndex;
                    }
                    
                    ++HeaderSource;
                }
            }
            else
            {
                //TODO(Alex): Transform data to other architectures
                //ex. change endianness if necessary, 
                Assert(!"Other Architecure");
            }
        }
        else
        {
            Assert(!"Is not PE File!");
        }
    }
    
    return Result;
}













