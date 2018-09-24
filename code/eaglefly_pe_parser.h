/*
NOTE(Alex): eaglefly_pe_parser.h

Parses PE Files, finds Opcode data and starts disassemble process to x64 - x86 architectures, in intel style.
96 Maximum num of PE sections allowes in Windows


*/

#if defined(__cplusplus)
extern "C" {
#endif
    
#define IS_COFF_FILE(HCoff) (!(HCoff)->SizeOptHeader)
#define CheckFilePESignature(Signature) ((CHAR_PTR(Signature)[0] == 'P') && (CHAR_PTR(Signature)[1] == 'E') && (CHAR_PTR(Signature)[2] == 0) && (CHAR_PTR(Signature)[3] == 0))
    
#define PE32_IMAGE 0x10B
#define PE32P_IMAGE 0x20B
#define ROM_IMAGE 0x107
    
    //TODO(Alex): Look for actual architecture page size if needed!
    // NOTE(Alex): Intel Itanium 8k 
    // NOTE(Alex): Intel x86 and MIPS  4k 
#define ARCH_PAGE_SIZE 4096
#define SECTION_NAME_COUNT 8
#define MAX_SECTION_COUNT 4096
    
#pragma pack(push,1)
    // NOTE(Alex): Symbol extraction data structures
    //-----------------------------------------------------------------------------
    /*
//NOTE(Alex): COFF record entries values 
#define IMAGE_SYM_UNDEFINED 0
#define IMAGE_SYM_ABSOLUTE -1
#define IMAGE_SYM_DEBUG -2
#define COFF_DTYPE_FUNC 0x20
#define COFF_DTYPE_NULL 0x00
*/
    
    CSTRUCT(debug_symbol_info)
    {
        uint32_t Signature : 1;
        uint32_t A : 2;
        uint32_t B : 3;
        uint32_t C = 4;
    }debug_symbol_info;
    
    CSTRUCT(coff_sym_table_record)
    {
        char Name[8];
        uint32_t Value;
        int16_t SectionIndex;
        uint16_t Type;
        uint8_t StorageClass;
        uint8_t AuxSymbolsCount;
    }coff_sym_table_record;
    
    // NOTE(Alex): -----------------------------------------------------------------------------
    
    typedef enum machine_type
    {
        MACHINE_TYPE_UNKNOWN = 0x0, //NOTE(Alex): The contents of this field are assumed to be applicable to any machine type 
        MACHINE_TYPE_AM33 = 0x1d3 , //NOTE(Alex): Matsushita AM33 
        MACHINE_TYPE_AMD64 = 0x8664 , //NOTE(Alex): x64 
        MACHINE_TYPE_ARM = 0x1c0 , //NOTE(Alex): ARM little endian 
        MACHINE_TYPE_ARM64 = 0xaa64 , //NOTE(Alex): ARM64 little endian 
        MACHINE_TYPE_ARMNT = 0x1c4 , //NOTE(Alex): ARM Thumb-2 little endian 
        MACHINE_TYPE_EBC = 0xebc , //NOTE(Alex): EFI byte code 
        MACHINE_TYPE_I386 = 0x14c , //NOTE(Alex): Intel 386 or later processors and compatible processors 
        MACHINE_TYPE_IA64 = 0x200 , //NOTE(Alex): Intel Itanium processor family 
        MACHINE_TYPE_M32R = 0x9041 , //NOTE(Alex): Mitsubishi M32R little endian 
        MACHINE_TYPE_MIPS16 = 0x266 , //NOTE(Alex): MIPS16 
        MACHINE_TYPE_MIPSFPU = 0x366 , //NOTE(Alex): MIPS with FPU 
        MACHINE_TYPE_MIPSFPU16 = 0x466 , //NOTE(Alex): MIPS16 with FPU 
        MACHINE_TYPE_POWERPC = 0x1f0 , //NOTE(Alex): Power PC little endian 
        MACHINE_TYPE_POWERPCFP = 0x1f1 , //NOTE(Alex): Power PC with floating point support 
        MACHINE_TYPE_R4000 = 0x166 , //NOTE(Alex): MIPS little endian 
        MACHINE_TYPE_RISCV32 = 0x5032 , //NOTE(Alex): RISC-V 32-bit address space 
        MACHINE_TYPE_RISCV64 = 0x5064 , //NOTE(Alex): RISC-V 64-bit address space 
        MACHINE_TYPE_RISCV128 = 0x5128 , //NOTE(Alex):RISC-V 128-bit address space 
        MACHINE_TYPE_SH3 = 0x1a2 , //NOTE(Alex):Hitachi SH3 
        MACHINE_TYPE_SH3DSP = 0x1a3 , //NOTE(Alex):Hitachi SH3 DSP 
        MACHINE_TYPE_SH4 = 0x1a6 , //NOTE(Alex):Hitachi SH4 
        MACHINE_TYPE_SH5 = 0x1a8 , //NOTE(Alex):Hitachi SH5 
        MACHINE_TYPE_THUMB = 0x1c2 , //NOTE(Alex):Thumb 
        MACHINE_TYPE_WCEMIPSV2 = 0x169 //NOTE(Alex):MIPS little-endian WCE v2 
    }machine_type;
    
    CSTRUCT(eflype_coff_header)
    {
        //NOTE(Alex):The number that identifies the type of target machine. For more information, see Machine Types. 
        uint16_t MachineType;
        //NOTE(Alex):The number of sections. This indicates the size of the section table, which immediately follows the headers. 
        uint16_t SectionCount;
        //NOTE(Alex):The low 32 bits of the number of seconds since 00:00 January 1, 1970 (a C run-time time_t value), that indicates when the file was created. 
        uint32_t TimeDateStamp;
        //NOTE(Alex):The file offset of the COFF symbol table, or zero if no COFF symbol table is present. This value should be zero for an image because COFF debugging information is deprecated. 
        uint32_t PCOFFSymTable;
        //NOTE(Alex):The number of entries in the symbol table. This data can be used to locate the string table, which immediately follows the symbol table. This value should be zero for an image because COFF debugging information is deprecated. 
        uint32_t COFFSymCount;
        //NOTE(Alex):The size of the optional header, which is required for executable files but not for object files. This value should be zero for an object file. For a description of the header format, see Optional Header (Image Only). 
        uint16_t SizeOptHeader;
        //NOTE(Alex):The flags that indicate the attributes of the file. For specific flag values, see Characteristics. 
        uint16_t Characteristics;
    }eflype_coff_header;
    
    CSTRUCT(eflype_standard_opt_header)
    {
        // NOTE(Alex): The unsigned integer that identifies the state of the image file. The most common number is 0x10B, which identifies it as a normal executable file. 0x107 identifies it as a ROM image, and 0x20B identifies it as a PE32+ executable. 
        uint16_t Magic;
        // NOTE(Alex): The linker major version number. 
        uint8_t MajorLinkerVersion; 
        // NOTE(Alex): The linker minor version number. 
        uint8_t MinorLinkerVersion;
        // NOTE(Alex): The size of the code (text) section, or the sum of all code sections if there are multiple sections. 
        uint32_t SizeOfCode;
        // NOTE(Alex): The size of the initialized data section, or the sum of all such sections if there are multiple data sections. 
        uint32_t SizeOfInitializedData;
        // NOTE(Alex): The size of the uninitialized data section (BSS), or the sum of all such sections if there are multiple BSS sections. 
        uint32_t SizeOfUninitializedData;
        // NOTE(Alex): The address of the entry point relative to the image base when the executable file is loaded into memory. For program images, this is the starting address. For device drivers, this is the address of the initialization function. An entry point is optional for DLLs. When no entry point is present, this field must be zero. 
        uint32_t AddressOfEntryPoint;
        // NOTE(Alex): The address that is relative to the image base of the beginning-of-code section when it is loaded into memory. 
        uint32_t BaseOfCode;
        // NOTE(Alex): The address that is relative to the image base of the beginning-of-data section when it is loaded into memory. 
        uint32_t BaseOfData;
    }eflype_standard_opt_header;
    
    CSTRUCT(elfype_plus_standard_opt_header)
    {
        // NOTE(Alex): The unsigned integer that identifies the state of the image file. The most common number is 0x10B, which identifies it as a normal executable file. 0x107 identifies it as a ROM image, and 0x20B identifies it as a PE32+ executable. 
        uint16_t Magic;
        // NOTE(Alex): The linker major version number. 
        uint8_t MajorLinkerVersion; 
        // NOTE(Alex): The linker minor version number. 
        uint8_t MinorLinkerVersion;
        // NOTE(Alex): The size of the code (text) section, or the sum of all code sections if there are multiple sections. 
        uint32_t SizeOfCode;
        // NOTE(Alex): The size of the initialized data section, or the sum of all such sections if there are multiple data sections. 
        uint32_t SizeOfInitializedData;
        // NOTE(Alex): The size of the uninitialized data section (BSS), or the sum of all such sections if there are multiple BSS sections. 
        uint32_t SizeOfUninitializedData;
        // NOTE(Alex): The address of the entry point relative to the image base when the executable file is loaded into memory. For program images, this is the starting address. For device drivers, this is the address of the initialization function. An entry point is optional for DLLs. When no entry point is present, this field must be zero. 
        uint32_t AddressOfEntryPoint;
        // NOTE(Alex): The address that is relative to the image base of the beginning-of-code section when it is loaded into memory. 
        uint32_t BaseOfCode;
    }eflype_plus_standard_opt_header;
    
    CSTRUCT(eflype_plus_windows_opt_header)
    {
        // NOTE(Alex): The preferred address of the first byte of image when loaded into memory; must be a multiple of 64 K. The default for DLLs is 0x10000000. The default for Windows CE EXEs is 0x00010000. The default for Windows NT, Windows 2000, Windows XP, Windows 95, Windows 98, and Windows Me is 0x00400000. 
        uint64_t ImageBase;
        // NOTE(Alex): The alignment (in bytes) of sections when they are loaded into memory. It must be greater than or equal to FileAlignment. The default is the page size for the architecture. 
        uint32_t SectionAlignment;
        // NOTE(Alex): The alignment factor (in bytes) that is used to align the raw data of sections in the image file. The value should be a power of 2 between 512 and 64 K, inclusive. The default is 512. If the SectionAlignment is less than the architecture's page size, then FileAlignment must match SectionAlignment. 
        uint32_t FileAlignment;
        // NOTE(Alex): The major version number of the required operating system. 
        uint16_t MajorOperatingSystemVersion;
        // NOTE(Alex): The minor version number of the required operating system. 
        uint16_t MinorOperatingSystemVersion;
        // NOTE(Alex): The major version number of the image. 
        uint16_t MajorImageVersion;
        // NOTE(Alex): The minor version number of the image. 
        uint16_t MinorImageVersion;
        // NOTE(Alex): The major version number of the subsystem. 
        uint16_t MajorSubsystemVersion;
        // NOTE(Alex): The minor version number of the subsystem. 
        uint16_t MinorSubsystemVersion;
        // NOTE(Alex): Reserved, must be zero. 
        uint32_t Win32VersionValue;
        // NOTE(Alex): The size (in bytes) of the image, including all headers, as the image is loaded in memory. It must be a multiple of SectionAlignment. 
        uint32_t SizeOfImage;
        // NOTE(Alex): The combined size of an MS-DOS stub, PE header, and section headers rounded up to a multiple of FileAlignment. 
        uint32_t SizeOfHeaders;
        // NOTE(Alex): The image file checksum. The algorithm for computing the checksum is incorporated into IMAGHELP.DLL. The following are checked for validation at load time: all drivers, any DLL loaded at boot time, and any DLL that is loaded into a critical Windows process. 
        uint32_t CheckSum;
        
        // NOTE(Alex): The subsystem that is required to run this image. For more information, see Windows Subsystem. 
        uint16_t Subsystem;
        
        // NOTE(Alex): For more information, see DLL Characteristics later in this specification. 
        uint16_t DllCharacteristics;
        // NOTE(Alex): The size of the stack to reserve. Only SizeOfStackCommit is committed; the rest is made available one page at a time until the reserve size is reached. 
        uint64_t SizeOfStackReserve;
        // NOTE(Alex): The size of the stack to commit. 
        uint64_t SizeOfStackCommit;
        // NOTE(Alex): The size of the local heap space to reserve. Only SizeOfHeapCommit is committed; the rest is made available one page at a time until the reserve size is reached. 
        uint64_t SizeOfHeapReserve;
        // NOTE(Alex): The size of the local heap space to commit. 
        uint64_t SizeOfHeapCommit;
        // NOTE(Alex): Reserved, must be zero. 
        uint32_t LoaderFlags;
        // NOTE(Alex): The number of data-directory entries in the remainder of the optional header. Each describes a location and size. 
        uint32_t NumberOfRvaAndSizes;
    }eflype_plus_windows_opt_header;
    
    CSTRUCT(eflype_windows_opt_header)
    {
        // NOTE(Alex): The preferred address of the first byte of image when loaded into memory; must be a multiple of 64 K. The default for DLLs is 0x10000000. The default for Windows CE EXEs is 0x00010000. The default for Windows NT, Windows 2000, Windows XP, Windows 95, Windows 98, and Windows Me is 0x00400000. 
        uint32_t ImageBase;
        // NOTE(Alex): The alignment (in bytes) of sections when they are loaded into memory. It must be greater than or equal to FileAlignment. The default is the page size for the architecture. 
        uint32_t SectionAlignment;
        // NOTE(Alex): The alignment factor (in bytes) that is used to align the raw data of sections in the image file. The value should be a power of 2 between 512 and 64 K, inclusive. The default is 512. If the SectionAlignment is less than the architecture's page size, then FileAlignment must match SectionAlignment. 
        uint32_t FileAlignment;
        // NOTE(Alex): The major version number of the required operating system. 
        uint16_t MajorOperatingSystemVersion;
        // NOTE(Alex): The minor version number of the required operating system. 
        uint16_t MinorOperatingSystemVersion;
        // NOTE(Alex): The major version number of the image. 
        uint16_t MajorImageVersion;
        // NOTE(Alex): The minor version number of the image. 
        uint16_t MinorImageVersion;
        // NOTE(Alex): The major version number of the subsystem. 
        uint16_t MajorSubsystemVersion;
        // NOTE(Alex): The minor version number of the subsystem. 
        uint16_t MinorSubsystemVersion;
        // NOTE(Alex): Reserved, must be zero. 
        uint32_t Win32VersionValue;
        // NOTE(Alex): The size (in bytes) of the image, including all headers, as the image is loaded in memory. It must be a multiple of SectionAlignment. 
        uint32_t SizeOfImage;
        // NOTE(Alex): The combined size of an MS-DOS stub, PE header, and section headers rounded up to a multiple of FileAlignment. 
        uint32_t SizeOfHeaders;
        // NOTE(Alex): The image file checksum. The algorithm for computing the checksum is incorporated into IMAGHELP.DLL. The following are checked for validation at load time: all drivers, any DLL loaded at boot time, and any DLL that is loaded into a critical Windows process. 
        uint32_t CheckSum;
        
        // NOTE(Alex): The subsystem that is required to run this image. For more information, see Windows Subsystem. 
        uint16_t Subsystem;
        
        // NOTE(Alex): For more information, see DLL Characteristics later in this specification. 
        uint16_t DllCharacteristics;
        // NOTE(Alex): The size of the stack to reserve. Only SizeOfStackCommit is committed; the rest is made available one page at a time until the reserve size is reached. 
        uint32_t SizeOfStackReserve;
        // NOTE(Alex): The size of the stack to commit. 
        uint32_t SizeOfStackCommit;
        // NOTE(Alex): The size of the local heap space to reserve. Only SizeOfHeapCommit is committed; the rest is made available one page at a time until the reserve size is reached. 
        uint32_t SizeOfHeapReserve;
        // NOTE(Alex): The size of the local heap space to commit. 
        uint32_t SizeOfHeapCommit;
        // NOTE(Alex): Reserved, must be zero. 
        uint32_t LoaderFlags;
        // NOTE(Alex): The number of data-directory entries in the remainder of the optional header. Each describes a location and size. 
        uint32_t NumberOfRvaAndSizes;
    }eflype_windows_opt_header;
    
    CSTRUCT(eflype_section_header)
    {
        //NOTE(Alex): An 8-byte, null-padded UTF-8 encoded string. If the string is exactly 8 characters long, there is no terminating null. For longer names, this field contains a slash (/) that is followed by an ASCII representation of a decimal number that is an offset into the string table. Executable images do not use a string table and do not support section names longer than 8 characters. Long names in object files are truncated if they are emitted to an executable file. 
        char Name[8];
        //NOTE(Alex): The total size of the section when loaded into memory. If this value is greater than SizeOfRawData, the section is zero-padded. This field is valid only for executable images and should be set to zero for object files. 
        uint32_t VirtualSize; 
        //NOTE(Alex): For executable images, the address of the first byte of the section 
        //relative to the image base when the section is loaded into memory. 
        //For object files, this field is the address of the first byte before relocation is applied; for simplicity, compilers should set this to zero. 
        //Otherwise, it is an arbitrary value that is subtracted from offsets during relocation. 
        uint32_t VirtualAddress; 
        //NOTE(Alex): The size of the section (for object files) or the size of the initialized data on disk (for image files). For executable images, this must be a multiple of FileAlignment from the optional header. If this is less than VirtualSize, the remainder of the section is zero-filled. Because the SizeOfRawData field is rounded but the VirtualSize field is not, it is possible for SizeOfRawData to be greater than VirtualSize as well. When a section contains only uninitialized data, this field should be zero. 
        uint32_t SizeOfRawData; 
        //NOTE(Alex): The file pointer to the first page of the section within the COFF file. 
        //For executable images, this must be a multiple of FileAlignment from the optional header. 
        //For object files, the value should be aligned on a 4-byte boundary for best performance. 
        //When a section contains only uninitialized data, this field should be zero. 
        uint32_t PointerToRawData; 
        //NOTE(Alex): The file pointer to the beginning of relocation entries for the section. This is set to zero for executable images or if there are no relocations. 
        uint32_t PointerToRelocations;
        //NOTE(Alex): The file pointer to the beginning of line-number entries for the section. This is set to zero if there are no COFF line numbers. This value should be zero for an image because COFF debugging information is deprecated. 
        uint32_t PointerToLinenumbers;
        //NOTE(Alex): The number of relocation entries for the section. This is set to zero for executable images. 
        uint16_t RelocCount;
        //NOTE(Alex): The number of line-number entries for the section. This value should be zero for an image because COFF debugging information is deprecated. 
        uint16_t LineNumberCount;
        //NOTE(Alex): The flags that describe the characteristics of the section. For more information, see Section Flags.
        uint32_t Characteristics;
    }eflype_section_header;
    
    CSTRUCT(eflype_data_directory)
    {
        uint32_t VA;
        uint32_t Size;
    }eflype_data_directory;
    
#pragma pack(pop)
    
    CSTRUCT(eflype_opt_header)
    {
        b32 PE32Type;//NOTE(Alex): 0 - PE32 , 1 - PE32Plus
        struct
        {
            // NOTE(Alex): The unsigned integer that identifies the state of the image file. The most common number is 0x10B, which identifies it as a normal executable file. 0x107 identifies it as a ROM image, and 0x20B identifies it as a PE32+ executable. 
            uint16_t Magic;
            // NOTE(Alex): The linker major version number. 
            uint8_t MajorLinkerVersion; 
            // NOTE(Alex): The linker minor version number. 
            uint8_t MinorLinkerVersion;
            // NOTE(Alex): The size of the code (text) section, or the sum of all code sections if there are multiple sections. 
            uint32_t SizeOfCode;
            // NOTE(Alex): The size of the initialized data section, or the sum of all such sections if there are multiple data sections. 
            uint32_t SizeOfInitializedData;
            // NOTE(Alex): The size of the uninitialized data section (BSS), or the sum of all such sections if there are multiple BSS sections. 
            uint32_t SizeOfUninitializedData;
            // NOTE(Alex): The address of the entry point relative to the image base when the executable file is loaded into memory. For program images, this is the starting address. For device drivers, this is the address of the initialization function. An entry point is optional for DLLs. When no entry point is present, this field must be zero. 
            uint32_t AddressOfEntryPoint;
            // NOTE(Alex): The address that is relative to the image base of the beginning-of-code section when it is loaded into memory. 
            uint32_t BaseOfCode;
            // NOTE(Alex): The address that is relative to the image base of the beginning-of-data section when it is loaded into memory. 
            uint32_t BaseOfData;
        };
        
        struct
        {
            // NOTE(Alex): The preferred address of the first byte of image when loaded into memory; must be a multiple of 64 K. The default for DLLs is 0x10000000. The default for Windows CE EXEs is 0x00010000. The default for Windows NT, Windows 2000, Windows XP, Windows 95, Windows 98, and Windows Me is 0x00400000. 
            uint64_t ImageBase;
            // NOTE(Alex): The alignment (in bytes) of sections when they are loaded into memory. It must be greater than or equal to FileAlignment. The default is the page size for the architecture. 
            uint32_t SectionAlignment;
            // NOTE(Alex): The alignment factor (in bytes) that is used to align the raw data of sections in the image file. The value should be a power of 2 between 512 and 64 K, inclusive. The default is 512. If the SectionAlignment is less than the architecture's page size, then FileAlignment must match SectionAlignment. 
            uint32_t FileAlignment;
            // NOTE(Alex): The major version number of the required operating system. 
            uint16_t MajorOperatingSystemVersion;
            // NOTE(Alex): The minor version number of the required operating system. 
            uint16_t MinorOperatingSystemVersion;
            // NOTE(Alex): The major version number of the image. 
            uint16_t MajorImageVersion;
            // NOTE(Alex): The minor version number of the image. 
            uint16_t MinorImageVersion;
            // NOTE(Alex): The major version number of the subsystem. 
            uint16_t MajorSubsystemVersion;
            // NOTE(Alex): The minor version number of the subsystem. 
            uint16_t MinorSubsystemVersion;
            // NOTE(Alex): Reserved, must be zero. 
            uint32_t Win32VersionValue;
            // NOTE(Alex): The size (in bytes) of the image, including all headers, as the image is loaded in memory. It must be a multiple of SectionAlignment. 
            uint32_t SizeOfImage;
            // NOTE(Alex): The combined size of an MS-DOS stub, PE header, and section headers rounded up to a multiple of FileAlignment. 
            uint32_t SizeOfHeaders;
            // NOTE(Alex): The image file checksum. The algorithm for computing the checksum is incorporated into IMAGHELP.DLL. The following are checked for validation at load time: all drivers, any DLL loaded at boot time, and any DLL that is loaded into a critical Windows process. 
            uint32_t CheckSum;
            
            // NOTE(Alex): The subsystem that is required to run this image. For more information, see Windows Subsystem. 
            uint16_t Subsystem;
            
            // NOTE(Alex): For more information, see DLL Characteristics later in this specification. 
            uint16_t DllCharacteristics;
            // NOTE(Alex): The size of the stack to reserve. Only SizeOfStackCommit is committed; the rest is made available one page at a time until the reserve size is reached. 
            uint64_t SizeOfStackReserve;
            // NOTE(Alex): The size of the stack to commit. 
            uint64_t SizeOfStackCommit;
            // NOTE(Alex): The size of the local heap space to reserve. Only SizeOfHeapCommit is committed; the rest is made available one page at a time until the reserve size is reached. 
            uint64_t SizeOfHeapReserve;
            // NOTE(Alex): The size of the local heap space to commit. 
            uint64_t SizeOfHeapCommit;
            // NOTE(Alex): Reserved, must be zero. 
            uint32_t LoaderFlags;
            // NOTE(Alex): The number of data-directory entries in the remainder of the optional header. Each describes a location and size. 
            uint32_t NumberOfRvaAndSizes;
        };
    }eflype_opt_header;
    
    typedef enum eflype_section_id
    {
        SectionID_none = 0,
        SectionID_text,
        SectionID_data,
        SectionID_idata,
        SectionID_rdata,
        SectionID_reloc,
        SectionID_ldrectve,
        SectionID_edata,
        SectionID_pdata,
        SectionID_tls,
        SectionID_rsrc,
        //TODO(alex): Add more Section IDs
        SectionID_count
    }eflype_section_id;
    
    CSTRUCT(eflype_section_entry)
    {
        eflype_section_id ID;
        uint32_t Index;
    }eflype_section_entry;
    
    CSTRUCT(eflype_manager)
    {
        void * Base;
        void * At;
        memory_index FileSize;
        eflype_opt_header OptHeader; 
        
        uint32_t SectionCount;
        eflype_section_header * SHeaderTable[MAX_SECTION_COUNT];
        eflype_section_entry SectionTable[MAX_SECTION_COUNT];
    }eflype_manager;
    
#if defined(__cplusplus)
}
#endif

