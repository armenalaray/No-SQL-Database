//////////////////////////////////////////////////////
//
//Author: Alejandro Armenta 
//Date: 2019
//File: meta_instruction_infos_table.cpp
//Company: 
//
//All rights reserved.
//
//////////////////////////////////////////////////////

/*


This takes up the eaglefly/misc/assembly_grammars.info
and outputs the file /eaglefly/code/eflyfile_meta.cpp 

            for assembly grammars we are going to be first make a pass for each entry, and see a
            We are going 
            
            we also need to print the addrees attribute in src and dst eleements when needed 
            following the next rule
            
            if displayed=no discard element, attributes and text
            
            else if(address attribute present)
            {
            
gather address value
            and gather type attribute value as well if any! 
            
            }
            
            
            {
            print text
            }
            
            so its not just to translate to one sring it can be any strings, so the idea here would be to have subgroups
            on the instructions and once i got to the opcode i want now i select it based on operand size attribute
            
            <ost> 
            
            I need a data structure for this i cannot meta parse it directly 
            
            opcodes can have many entries (opcode groups, escape opcodes) , and entries can have multiple syntaxes
            
            we print opcode 
            
            one-byte
            opcode = 80
            .   entry = 0
               .       grammar - ADD E v, G v
                    .   exta_entry = 1
            .       grammar - INS Yb (ES:)[rDI], DX 
            .       extra_grammar - INSB Yb (ES:)[rDI], DX 
            .   extra_entry = 2
            .       grammar - INS DX, ES : [Mem]
            .       extra_grammar - INSW
            .   extra_entry = 3
             .       grammar - PCMPESTRM XMM0 <dq V>, <dq W>, <b I>, <64 RAX>, <64 RDX> 
             
opcode = 81
            .   entry = 3
               .       grammar - ADD Ev, Gv
                    .   extra_entry = 4
            .       grammar - INS DX, ES : [Mem]
            .       extra_grammar - INSB
            .   extra_entry = 5
            .       grammar - INS DX, ES : [Mem]
            .       extra_grammar - INSW
            .   
            
            two-byte
            opcode = 80
            .   entry = 6
               .       ADD Ev, Gv
                    .   entry = 7
            .       INS DX, ES : [Mem]
            .       INSB
            .   entry = 8
            .       INS DX, ES : [Mem]
            .       INSW
            .   
            
opcode = 81
            .   entry = 9
               .       ADD Ev, Gv
                    .   entry = 10
            .       INS DX, ES : [Mem]
            .       INSB
            .   entry = 11
            .       INS DX, ES : [Mem]
            .       INSW
            .   
            
            entrycount = blah
            
            
            
            //NOTE(Alex): opcode tables 
            so now i dont need to have the tttn bitfield, i could just print the instruction based on 
            the only thing that matters now are mod and rm bitfields 
            
            
            for assembly grammar print all entries already as the grammar and say if theres multiple grammars fro entry, 
            then we manually check the double entries and decide which one we want!
            
            
            we want just one syntax, and for each entry we define the group extension value as it goes we dont care about that 
            
            
            
*/


#include "Windows.h"
#include "stdio.h"
#include "eaglefly_platform.h"

#include "instruction_infos_filter.h"
#include "meta_instruction_infos_table.h"
#include "eaglefly_string.cpp"

#define MAX_OPERAND_COUNT 16

internal void
Win32_OpenActiveScreenBuffer(HANDLE * out_Handle)
{
    *out_Handle = CreateFileA("CONOUT$",
                              GENERIC_READ | GENERIC_WRITE,
                              FILE_SHARE_WRITE,
                              0,
                              OPEN_EXISTING,
                              0,
                              0
                              );
}


internal void
Win32_CreateConsoleScreenBuffer(HANDLE * out_Handle)
{
    *out_Handle = CreateConsoleScreenBuffer(GENERIC_READ |           // read/write access 
                                            GENERIC_WRITE, 
                                            FILE_SHARE_READ | 
                                            FILE_SHARE_WRITE,        // shared 
                                            NULL,                    // default security attributes 
                                            CONSOLE_TEXTMODE_BUFFER, // must be TEXTMODE 
                                            NULL);                   // reserved; must be NULL 
    
}

internal memory_index
GetFileSize(FILE * File)
{
    memory_index Result = 0;
    
    fseek ( File, 0, SEEK_END);
    Result = ftell (File);
    fseek ( File, 0, SEEK_SET);
    
    return Result;
}

internal void
win32_WriteFile(HANDLE STDOutHandle, char * Buffer, u32 BufferLength)
{
    u32 TokenCharsWritten = 0;
    WriteFile(STDOutHandle, (void*)Buffer, BufferLength, (LPDWORD)&TokenCharsWritten,0);
}

internal void
meta_WriteFile(meta_state * MetaState, char * String, memory_index StringLength)
{
    win32_WriteFile(MetaState->STDOutHandle, String, SafeTruncateU64ToU32(StringLength));
}

inline void
CleanWhiteSpace(grammar_tokenizer * Tokenizer)
{
    while((IsWhiteSpace(Tokenizer->At)) && (Tokenizer->At <= Tokenizer->Last))
    {
        ++Tokenizer->At;
    }
}


#if 0        
((*At >= 65) && (*At <= 90)) || 
((*At >= 97) && (*At <= 122)) ||
((*At >= 48) && (*At <= 57)) ||
(*At == '-') ||
(*At == '_') ||
(*At == '=') ||
(*At == '<') ||
(*At == '>') ||
(*At == '[') ||
(*At == '/') ||
(*At == ':') ||
(*At == '(') ||
(*At == '#') ||
(*At == ',') 
);
#endif


b32
IsGrammarCharacter(char * At)
{
    b32 Result = (!IsWhiteSpace(At));
    return Result;
    
}

internal void
InitializeGrammarTokenizer(grammar_tokenizer * out_Tokenizer, char * Base, u32 Count)
{
    Assert(Count);
    
    out_Tokenizer->Base = Base;
    out_Tokenizer->At = out_Tokenizer->Base;
    out_Tokenizer->Last = out_Tokenizer->Base + (Count - 1);
}

internal grammar_token_type 
GetNextGrammarToken(grammar_tokenizer * Tokenizer, char ** out_Ptr, u32 * out_Count)
{
    grammar_token_type Result = GrammarTokenType_Invalid;
    
    CleanWhiteSpace(Tokenizer);
    
    
    memory_index TotalEntryCount = 0;
    char TotalEntryCountString[MAX_BUFFER_SIZE] = {"0"};
    u32 TotalEntryCountStringLength = StringLength(TotalEntryCountString);
    
    
    char OneByteString[MAX_BUFFER_SIZE] = {"one-byte"};
    u32 OneByteStringLength = StringLength(OneByteString);
    
    char TwoByteString[MAX_BUFFER_SIZE] = {"two-byte"};
    u32 TwoByteStringLength = StringLength(TwoByteString);
    
    char OpcodeString[MAX_BUFFER_SIZE] = {"pri_opcd"};
    u32 OpcodeStringLength = StringLength(OpcodeString);
    
    memory_index EntryCount = 0;
    
    char EntryString[MAX_BUFFER_SIZE] = {"entry"};
    u32 EntryStringLength = StringLength(EntryString);
    
    char ExtraEntryString[MAX_BUFFER_SIZE] = {"exta_entry"};
    u32 ExtraEntryStringLength = StringLength(ExtraEntryString);
    
    memory_index GrammarCount = 0;
    
    char GrammarString[MAX_BUFFER_SIZE] = {"grammar"};
    u32 GrammarStringLength = StringLength(GrammarString);
    
    char ExtraGrammarString[MAX_BUFFER_SIZE] = {"extra_grammar"};
    u32 ExtraGrammarStringLength = StringLength(ExtraGrammarString);
    
    char GrammarGroupString[MAX_BUFFER_SIZE] = {"grammar_group"};
    u32 GrammarGroupStringLength = StringLength(GrammarGroupString);
    
    char GrammarEntryString[MAX_BUFFER_SIZE] = {"grammar_entry"};
    u32 GrammarEntryStringLength = StringLength(GrammarEntryString);
    
    char EqualString[MAX_BUFFER_SIZE] = {"="};
    u32 EqualStringLength = StringLength(EqualString);
    
    
    char * Ptr = 0;
    u32 Count = 0;
    
    char * At = Tokenizer->At;
    
    if(At <= Tokenizer->Last)
    {
        if(Tokenizer->IsGrammar)
        {
            Result = GrammarTokenType_Text;
            Ptr = At;
            
            while(*At != '\n')
            {
                ++At;
                ++Count;
            }
            
            Tokenizer->IsGrammar = false;
        }
        
        else if(IsNumeric(At))
        {
            Result = GrammarTokenType_Numeric;
            Ptr = At;
            
            while(IsNumeric(At))
            {
                ++At;
                ++Count;
            }
        }
        
        else if(
            (*At == '/') &&
            (*(At + 1) == '/')
            )
        {
            Result = GrammarTokenType_Comment;
            At += 2;
            
            Ptr = At;
            while(*At != '\n')
            {
                ++At;
                ++Count;
            }
        }
        
        else if(IsGrammarCharacter(At))
        {
            Result = GrammarTokenType_Keyword;
            Ptr = At;
            
            while(IsGrammarCharacter(At))
            {
                ++At;
                ++Count;
            }
            
            if(StringsAreEqual(Ptr, Count, GrammarEntryString, GrammarEntryStringLength))
            {
                Result = GrammarTokenType_Entry;
                Tokenizer->IsGrammar = true;
            }
            
            else if(StringsAreEqual(Ptr, Count, GrammarGroupString, GrammarGroupStringLength))
            {
                Result = GrammarTokenType_Group;
                Tokenizer->IsGrammar = true;
            }
            
            else if(StringsAreEqual(Ptr, Count, ExtraGrammarString, ExtraGrammarStringLength))
            {
                Result = GrammarTokenType_Normal;
                Tokenizer->IsGrammar = true;
            }
            
            else if(StringsAreEqual(Ptr, Count, GrammarString, GrammarStringLength))
            {
                Result = GrammarTokenType_Normal;
                Tokenizer->IsGrammar = true;
            }
            
        }
    }
    
    
#if 0    
    if(Ptr && Count)
    {
        if(
            StringsAreEqual(Ptr, Count, GrammarEntryString, GrammarEntryStringLength) ||
            StringsAreEqual(Ptr, Count, GrammarGroupString, GrammarGroupStringLength) ||
            StringsAreEqual(Ptr, Count, ExtraGrammarString, ExtraGrammarStringLength) ||
            StringsAreEqual(Ptr, Count, GrammarString, GrammarStringLength) ||
            
            StringsAreEqual(Ptr, Count, ExtraEntryString, ExtraEntryStringLength) ||
            StringsAreEqual(Ptr, Count, EntryString, EntryStringLength) ||
            StringsAreEqual(Ptr, Count, OpcodeString, OpcodeStringLength) ||
            StringsAreEqual(Ptr, Count, TwoByteString, TwoByteStringLength) ||
            StringsAreEqual(Ptr, Count, OneByteString, OneByteStringLength) ||
            
            StringsAreEqual(Ptr, Count, EqualString, EqualStringLength) 
            
            )
        {
            Result = GrammarTokenType_Keyword;
        }
        
        
    }
#endif
    
    
    if(out_Ptr && out_Count)
    {
        *out_Ptr = Ptr;
        *out_Count = Count;
    }
    
    
    
    Tokenizer->At = At;
    
    return Result;
}

inline b32 
IsUpperCase(char * At)
{
    b32 Result = ((*At >= 0x41) && (*At <= 0x5A));
    return Result;
}

inline b32 
IsLowerCase(char * At)
{
    b32 Result = ((*At >= 0x61) && (*At <= 0x7A));
    return Result;
}


int main(int Argcount, char ** Arguments)
{
    
    HANDLE STDOutHandle = GetStdHandle(STD_OUTPUT_HANDLE); 
    FILE * AssemblyGrammarsFile = fopen(Arguments[1], "rb");
    
    if(AssemblyGrammarsFile)
    {
        u32 AssemblyGrammarsSize = SafeTruncateU64ToU32(GetFileSize(AssemblyGrammarsFile));
        
        char * AssemblyGrammarsBase = 0;
        AssemblyGrammarsBase = (char *)malloc(AssemblyGrammarsSize);
        
        memory_index AssemblyGrammarsBytesRead = fread (AssemblyGrammarsBase, 1, AssemblyGrammarsSize, AssemblyGrammarsFile);
        Assert(AssemblyGrammarsBytesRead  == AssemblyGrammarsSize);
        
        if(AssemblyGrammarsBase)
        {
            
            meta_state MetaState = {};
            MetaState.STDOutHandle = STDOutHandle;
            
            
            b32 Mnemonic = false;
            b32 OperandDisplayed = true;
            b32 ElementFound = true;
            b32 InsideSyntax = false;
            
            char * OperandTypesStrings[] =
            {
                "A",
                "BA",
                "BB",
                "BD",
                "C",
                "D",
                "E",
                "ES",
                "EST",
                "F",
                "G",
                "H",
                "I",
                "J",
                "M",
                "N",
                "O",
                "P",
                "Q",
                "R",
                "S",
                "SC",
                "T",
                "U",
                "V",
                "W",
                "X",
                "Y",
                "Z",
                
                "S2",
                "S30",
                "S33",
                
                
            };
            
            u32 OperandTypesTableCount = 0;
            xml_token OperandTypesTable[MAX_BUFFER_SIZE] = {0};
            
            for(u32 Index = 0; 
                Index <  ArrayCount(OperandTypesStrings);
                ++Index)
            {
                xml_token * Token = OperandTypesTable + OperandTypesTableCount++;
                char * Type = OperandTypesStrings[Index];
                
                Token->Base = Type;
                Token->Count = StringLength(Type);
            }
            
            char * OperandSizesStrings[]=
            {
                
                "a",
                "b",
                "bcd",
                "bs",
                "bsq",
                "bss",
                "c",
                "d",
                "di",
                "dq",
                "dqp",
                "dr",
                "ds",
                "e",
                "er",
                "p",
                "pi",
                "pd",
                "ps",
                "psq",
                "pt",
                "ptp",
                "q",
                "qi",
                "qp",
                "s",
                "sd",
                "si",
                "sr",
                "ss",
                "st",
                "stx",
                "t",
                "v",
                "vds",
                "vq",
                "vqp",
                "vs",
                "w",
                "wi",
                "va",
                "dqa",
                "wa",
                "wo",
                "ws",
                "da",
                "do",
                "qa",
                "qs",
                
            };
            
            u32 OperandSizesTableCount = 0;
            xml_token OperandSizesTable[MAX_BUFFER_SIZE] = {0};
            
            for(u32 Index = 0; 
                Index <  ArrayCount(OperandSizesStrings);
                ++Index)
            {
                xml_token * Token = OperandSizesTable + OperandSizesTableCount++;
                char * Size = OperandSizesStrings[Index];
                
                Token->Base = Size;
                Token->Count = StringLength(Size);
            }
            
            
            char SyntaxString[MAX_BUFFER_SIZE] = {"syntax"};
            u32 SyntaxStringLength = StringLength(SyntaxString);
            
            char AddressString[MAX_BUFFER_SIZE] = {"address"};
            u32 AddressStringLength = StringLength(AddressString);
            
            char TypeString[MAX_BUFFER_SIZE] = {"type"};
            u32 TypeStringLength = StringLength(TypeString);
            
            char DisplayedString[MAX_BUFFER_SIZE] = {"displayed"};
            u32 DisplayedStringLength = StringLength(DisplayedString);
            
            
            char DestString[MAX_BUFFER_SIZE] = {"dst"};
            u32 DestStringLength = StringLength(DestString);
            
            char SourceString[MAX_BUFFER_SIZE] = {"src"};
            u32 SourceStringLength = StringLength(SourceString);
            
            char MnemString[MAX_BUFFER_SIZE] = {"mnem"};
            u32 MnemStringLength = StringLength(MnemString);
            
            char AString[MAX_BUFFER_SIZE] = {"a"};
            u32 AStringLength = StringLength(AString);
            
            char TString[MAX_BUFFER_SIZE] = {"t"};
            u32 TStringLength = StringLength(TString);
            
            
            memory_index TotalEntryCount = 0;
            char TotalEntryCountString[MAX_BUFFER_SIZE] = {"0"};
            u32 TotalEntryCountStringLength = StringLength(TotalEntryCountString);
            
            
            char OneByteString[MAX_BUFFER_SIZE] = {"one-byte"};
            u32 OneByteStringLength = StringLength(OneByteString);
            
            char TwoByteString[MAX_BUFFER_SIZE] = {"two-byte"};
            u32 TwoByteStringLength = StringLength(TwoByteString);
            
            char OpcodeString[MAX_BUFFER_SIZE] = {"pri_opcd"};
            u32 OpcodeStringLength = StringLength(OpcodeString);
            
            memory_index EntryCount = 0;
            
            char EntryString[MAX_BUFFER_SIZE] = {"entry"};
            u32 EntryStringLength = StringLength(EntryString);
            
            char ExtraEntryString[MAX_BUFFER_SIZE] = {"exta_entry"};
            u32 ExtraEntryStringLength = StringLength(ExtraEntryString);
            
            
            memory_index GrammarCount = 0;
            
            char GrammarString[MAX_BUFFER_SIZE] = {"grammar"};
            u32 GrammarStringLength = StringLength(GrammarString);
            
            char ExtraGrammarString[MAX_BUFFER_SIZE] = {"extra_grammar"};
            u32 ExtraGrammarStringLength = StringLength(ExtraGrammarString);
            
            char GrammarGroupString[MAX_BUFFER_SIZE] = {"grammar_group"};
            u32 GrammarGroupStringLength = StringLength(GrammarGroupString);
            
            char GrammarEntryString[MAX_BUFFER_SIZE] = {"grammar_entry"};
            u32 GrammarEntryStringLength = StringLength(GrammarEntryString);
            
            char EqualString[MAX_BUFFER_SIZE] = {"="};
            u32 EqualStringLength = StringLength(EqualString);
            
			
            
            char rAXString[MAX_BUFFER_SIZE] = {"rAX"};
            u32 rAXStringLength = StringLength(rAXString);
            
            char eAXString[MAX_BUFFER_SIZE] = {"eAX"};
            u32 eAXStringLength = StringLength(eAXString);
            
            char AXString[MAX_BUFFER_SIZE] = {"AX"}; 
            u32 AXStringLength = StringLength(AXString);
            
            char ALString[MAX_BUFFER_SIZE] = {"AL"}; 
            u32 ALStringLength = StringLength(ALString);
            
            char VQPString[MAX_BUFFER_SIZE] = {"vqp"};
            u32 VQPStringLength = StringLength(VQPString);
            
            char VString[MAX_BUFFER_SIZE] = {"v"};
            u32 VStringLength = StringLength(VString);
            
            char WString[MAX_BUFFER_SIZE] = {"w"};
            u32 WStringLength = StringLength(WString);
            
            char BString[MAX_BUFFER_SIZE] = {"b"};
            u32 BStringLength = StringLength(BString);
            
            char CXString[MAX_BUFFER_SIZE] = {"CX"};
            u32 CXStringLength = StringLength(CXString);
            
            char CLString[MAX_BUFFER_SIZE] = {"CL"};
            u32 CLStringLength = StringLength(CLString);
            
            char DXString[MAX_BUFFER_SIZE] = {"DX"};
            u32 DXStringLength = StringLength(DXString);
            
            char STString[MAX_BUFFER_SIZE] = {"ST"};
            u32 STStringLength = StringLength(STString);
            
            char ESTString[MAX_BUFFER_SIZE] = {"EST"};
            u32 ESTStringLength = StringLength(ESTString);
			
            

            char ERString[MAX_BUFFER_SIZE] = {"er"};
            u32 ERStringLength = StringLength(ERString);
            
            
            
            char InitOperandArrayString[MAX_BUFFER_SIZE] = {"\r\n\tInitOperandArray(&OperandArray);\r\n"};
            u32 InitOperandArrayStringLength = StringLength(InitOperandArrayString);
            
            char BeginPushOperandString[MAX_BUFFER_SIZE] = {"\tPushOperand(&OperandArray, "};
            u32 BeginPushOperandStringLength = StringLength(BeginPushOperandString);
            
            char OperandTypeString[MAX_BUFFER_SIZE] = {"OperandType_"};
            u32 OperandTypeStringLength = StringLength(OperandTypeString);
            
            char InvalidString[MAX_BUFFER_SIZE] = {"Invalid"};
            u32 InvalidStringLength = StringLength(InvalidString);
            
            char ComaString[MAX_BUFFER_SIZE] = {","};
            u32 ComaStringLength = StringLength(ComaString);
            
            char OperandSizeString[MAX_BUFFER_SIZE] = {"OperandSize_"};
            u32 OperandSizeStringLength = StringLength(OperandSizeString);
            
            char EndPushOperandString[MAX_BUFFER_SIZE] = {");\r\n"};
            u32 EndPushOperandStringLength = StringLength(EndPushOperandString);
            
            char BeginPushInstructionInfoString[MAX_BUFFER_SIZE] = {"\tPushInstructionInfo(FileManager, "};
            u32 BeginPushInstructionInfoStringLength = StringLength(BeginPushInstructionInfoString);
            
            char QuoteString[MAX_BUFFER_SIZE] = {"\""};
            u32 QuoteStringLength = StringLength(QuoteString);
            
            char EndPushInstructionInfoString[MAX_BUFFER_SIZE] = {" OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !REP_VALID, !LOCK_VALID, !BRANCHHINT_VALID);\r\n"};
            u32 EndPushInstructionInfoStringLength = StringLength(EndPushInstructionInfoString);
            
            char BeginInstructionInfoGroupString[MAX_BUFFER_SIZE] = {"\tBeginInstructionInfoGroup(FileManager, "};
            u32 BeginInstructionInfoGroupStringLength = StringLength(BeginInstructionInfoGroupString);
            
            char EndInstructionInfoGroupString[MAX_BUFFER_SIZE] = {"\tEndInstructionInfoGroup(FileManager);\r\n"};
            u32 EndInstructionInfoGroupStringLength = StringLength(EndInstructionInfoGroupString);
            
            char BeginPushInstructionInfoEntryString[MAX_BUFFER_SIZE] = {"\tPushInstructionInfoEntry(FileManager, "};
            u32 BeginPushInstructionInfoEntryStringLength = StringLength(BeginPushInstructionInfoEntryString);
            
            char EndFileSectionString[MAX_BUFFER_SIZE] = {"\tEndFileSection(FileManager);\n}"};
            u32 EndFileSectionStringLength = StringLength(EndFileSectionString);
            
            
			char CreateInstructionInfosString[MAX_BUFFER_SIZE] = "CreateInstructionInfos_";
			u32 CreateInstructionInfosStringLength = StringLength(CreateInstructionInfosString);
			//PushStringToBuffer(CreateInstructionInfosString, &CreateInstructionInfosStringLength, MAX_BUFFER_SIZE, Arguments[2], StringLength(Arguments[2]));
			
			char FileSectionInstructionInfoString[MAX_BUFFER_SIZE] = "FileSection_instruction_info_";
			u32 FileSectionInstructionInfoStringLength = StringLength(FileSectionInstructionInfoString);
			//PushStringToBuffer(FileSectionInstructionInfoString, &FileSectionInstructionInfoStringLength, MAX_BUFFER_SIZE, Arguments[2], StringLength(Arguments[2]));
			
            char BeginFuncOpeningString[MAX_BUFFER_SIZE] = "internal void ";
			u32 BeginFuncOpeningStringLength = StringLength(BeginFuncOpeningString);
			
			char BeginFuncMiddleString[MAX_BUFFER_SIZE] = "(file_manager * FileManager)\n{\r\n\n\toperand_array OperandArray = {};\r\n\tBeginFileSection(FileManager, ";
			u32 BeginFuncMiddleStringLength = StringLength(BeginFuncMiddleString);
			
			
			char BeginFuncTerminatorString[MAX_BUFFER_SIZE] = {");\r\n"};
			u32 BeginFuncTerminatorStringLength = StringLength(BeginFuncTerminatorString);
			
			//PushStringToBuffer(BeginFuncOpeningString, &BeginFuncOpeningStringLength, MAX_BUFFER_SIZE, CreateInstructionInfosString, CreateInstructionInfosStringLength);
			
#if 0				
			
			//PushStringToBuffer(BeginFuncOpeningString, &BeginFuncOpeningStringLength, MAX_BUFFER_SIZE, Arguments[2], StringLength(Arguments[2]));
			//			"FileSection_instruction_info_";
			
			u32 BeginFuncStringLength = StringLength(BeginFuncString);
			
			PushStringToBuffer(BeginFuncString, &BeginFuncStringLength, MAX_BUFFER_SIZE, Arguments[2], StringLength(Arguments[2]));
			PushStringToBuffer(BeginFuncString, &BeginFuncStringLength, MAX_BUFFER_SIZE, BeginFuncTerminatorString, BeginFuncTerminatorStringLength);
#endif
			
			
		    meta_WriteFile(&MetaState, BeginFuncOpeningString, BeginFuncOpeningStringLength);
		    meta_WriteFile(&MetaState, CreateInstructionInfosString, CreateInstructionInfosStringLength);
		    meta_WriteFile(&MetaState, Arguments[2], StringLength(Arguments[2]));
		    meta_WriteFile(&MetaState, BeginFuncMiddleString, BeginFuncMiddleStringLength);
		    meta_WriteFile(&MetaState, FileSectionInstructionInfoString, FileSectionInstructionInfoStringLength);
		    meta_WriteFile(&MetaState, Arguments[2], StringLength(Arguments[2]));
		    meta_WriteFile(&MetaState, BeginFuncTerminatorString, BeginFuncTerminatorStringLength);


		    //meta_WriteFile(&MetaState, BeginFuncOpeningString, BeginFuncOpeningStringLength);

         
            
            grammar_tokenizer Tokenizer = {};
            InitializeGrammarTokenizer(&Tokenizer, AssemblyGrammarsBase, AssemblyGrammarsSize);
            
            grammar_token_type LastType = GrammarTokenType_Invalid;
            
            b32 IsGroup = false;
            
            while(ElementFound)
            {
                grammar_token Token = {};
                grammar_token_type Type = GetNextGrammarToken(&Tokenizer, &Token.Base, &Token.Count);
                
                switch(Type)
                {
                    case GrammarTokenType_Invalid:
                    {
                        ElementFound = false;
                    }break;
                    
                    case GrammarTokenType_Keyword:
                    {
                        if(StringsAreEqual(Token.Base, Token.Count, TwoByteString, TwoByteStringLength) )
                        {
                            //ElementFound = false;
                        }
                    }break;
                    
                    case GrammarTokenType_Normal:
                    {
                        LastType = Type;
                        if(IsGroup)
                        {
                            //NOTE(Alex): Here we write the end of a group context
                            
                            meta_WriteFile(&MetaState, EndInstructionInfoGroupString, EndInstructionInfoGroupStringLength);
                            IsGroup = false;
                        }
                    }break;
                    
                    case GrammarTokenType_Group:
                    {
                        LastType = Type;
                        
                        if(IsGroup)
                        {
                            //NOTE(Alex): Here we write the end of a group context
                            
                            meta_WriteFile(&MetaState, EndInstructionInfoGroupString, EndInstructionInfoGroupStringLength);
                            IsGroup = false;
                        }
                        
                        IsGroup = true;
                    }break;
                    
                    case GrammarTokenType_Entry:
                    {
                        LastType = Type;
                    }break;
                    
                    case GrammarTokenType_Text:
                    {
                        //TODO(Alex): we are missing 
                        /*
                        
                        rAX , 
                        eAX, 
                        
                        AX,
                        AL, 
                        CL,
                        DX,
                        
                        
                        SS, 
                        DS, 
                        FS, 
                        GS,
                        
                        
                        ST,  
                        
                        operands and other registers!
                        
                        */
                        
                        
                     
                        grammar_token MnemonicToken = {};
                        grammar_token EntryID = {};
                        
                        char * At = Token.Base;
                        char * Last = Token.Base + (Token.Count - 1);
                        
                        if(LastType == GrammarTokenType_Entry)
                        {
                            Assert(*At == '#');
                            ++At;
                            
                            EntryID.Base = At;
                            
                            while(IsNumeric(At))
                            {
                                ++EntryID.Count;
                                ++At;
                            }
                            
                            
                            ++At;
                            Assert(IsAlphanumeric(At));
                        }
                        
                        MnemonicToken.Base = At;
                        
                        while((At <= Last) && (*At != ' '))
                        {
                            ++MnemonicToken.Count;
                            ++At;
                        }
                        
                        u32 OperandCount = 0;
                        grammar_token SizeTokens[MAX_OPERAND_COUNT] = {0};
                        grammar_token TypeTokens[MAX_OPERAND_COUNT] = {0};
                        
                        for(u32 Index = 0;
                            Index < MAX_OPERAND_COUNT;
                            ++Index)
                        {
                            grammar_token * TypeToken = TypeTokens + Index;
                            grammar_token * SizeToken = SizeTokens + Index;
                            
                            SizeToken->Count = 0;
                            TypeToken->Count = 0;
                            
                            SizeToken->Base = 0;
                            TypeToken->Base = 0;
                        }
                        
                        while(At <= Last)
                        {
                            if(*At == '<')
                            {
                                char * NewBase = 0;
                                
                                ++At;
                                
                                u32 OperandIndex = OperandCount++;
                                grammar_token * TypeToken = TypeTokens + OperandIndex;
                                grammar_token * SizeToken = SizeTokens + OperandIndex;
                                
                                if(IsLowerCase(At))
                                {
                                    TypeToken->Base = At;
                                    while(*At != '>')
                                    {
                                        ++TypeToken->Count;
                                        ++At;
                                    }
                                }
                                
                                if(IsUpperCase(At) || IsNumeric(At))
                                {
                                    TypeToken->Base = At;
                                    while(IsUpperCase(At) || IsNumeric(At))
                                    {
                                        ++TypeToken->Count;
                                        ++At;
                                    }
                                }
                                
                                if(IsLowerCase(At) && !SizeToken->Base)
                                {
                                    SizeToken->Base = At;
                                    while(IsLowerCase(At))
                                    {
                                        ++SizeToken->Count;
                                        ++At;
                                    }
                                }
                                
                                Assert(*At == '>');
                            }
                            
                            ++At;
                        }
                        
                        
                        meta_WriteFile(&MetaState, InitOperandArrayString, InitOperandArrayStringLength);
                        
                        for(u32 Index = 0;
                            Index < OperandCount;
                            ++Index)
                        {
                            grammar_token * TypeToken = TypeTokens + Index;
                            grammar_token * SizeToken = SizeTokens + Index;
                            
                            meta_WriteFile(&MetaState, BeginPushOperandString, BeginPushOperandStringLength);
                            
                            //NOTE(Alex): we are going to grab the whole token instead!
                            
                            if(StringsAreEqual(TypeToken->Base, TypeToken->Count, rAXString, rAXStringLength))
                            {
                                meta_WriteFile(&MetaState, OperandTypeString, OperandTypeStringLength);
                                meta_WriteFile(&MetaState, AXString, AXStringLength);
                                
                                meta_WriteFile(&MetaState, ComaString, ComaStringLength);
                                
                                meta_WriteFile(&MetaState, OperandSizeString, OperandSizeStringLength);
                                meta_WriteFile(&MetaState, VQPString, VQPStringLength);
                                
                            }
                            else if(StringsAreEqual(TypeToken->Base, TypeToken->Count, eAXString, eAXStringLength))
                            {
                                meta_WriteFile(&MetaState, OperandTypeString, OperandTypeStringLength);
                                meta_WriteFile(&MetaState, AXString, AXStringLength);
                                
                                meta_WriteFile(&MetaState, ComaString, ComaStringLength);
                                
                                meta_WriteFile(&MetaState, OperandSizeString, OperandSizeStringLength);
                                meta_WriteFile(&MetaState, VString, VStringLength);
                                
                            }
                            
                            else if(StringsAreEqual(TypeToken->Base, TypeToken->Count, AXString, AXStringLength))
                            {
                                meta_WriteFile(&MetaState, OperandTypeString, OperandTypeStringLength);
                                meta_WriteFile(&MetaState, AXString, AXStringLength);
                                
                                meta_WriteFile(&MetaState, ComaString, ComaStringLength);
                                
                                meta_WriteFile(&MetaState, OperandSizeString, OperandSizeStringLength);
                                meta_WriteFile(&MetaState, WString, WStringLength);
                            }
                            
                            else if(StringsAreEqual(TypeToken->Base, TypeToken->Count, ALString, ALStringLength))
                            {
                                meta_WriteFile(&MetaState, OperandTypeString, OperandTypeStringLength);
                                meta_WriteFile(&MetaState, AXString, AXStringLength);
                                
                                meta_WriteFile(&MetaState, ComaString, ComaStringLength);
                                
                                meta_WriteFile(&MetaState, OperandSizeString, OperandSizeStringLength);
                                meta_WriteFile(&MetaState, BString, BStringLength);
                                
                            }
                            
                            else if(StringsAreEqual(TypeToken->Base, TypeToken->Count, CLString, CLStringLength))
                            {
                                meta_WriteFile(&MetaState, OperandTypeString, OperandTypeStringLength);
                                meta_WriteFile(&MetaState, CXString, CXStringLength);
                                
                                meta_WriteFile(&MetaState, ComaString, ComaStringLength);
                                
                                meta_WriteFile(&MetaState, OperandSizeString, OperandSizeStringLength);
                                meta_WriteFile(&MetaState, BString, BStringLength);
                            }
                            
                            else if(StringsAreEqual(TypeToken->Base, TypeToken->Count, DXString, DXStringLength))
                            {
                                meta_WriteFile(&MetaState, OperandTypeString, OperandTypeStringLength);
                                meta_WriteFile(&MetaState, DXString, DXStringLength);
                                
                                meta_WriteFile(&MetaState, ComaString, ComaStringLength);
                                
                                meta_WriteFile(&MetaState, OperandSizeString, OperandSizeStringLength);
                                meta_WriteFile(&MetaState, WString, WStringLength);
                                
                            }

                            //NOTE(Alex): 
							//M no operand size - Invalid operand size keyword
							//3 no operand size - Invalid operand size keyword
							//1 no operand size - Invalid operand size keyword
							//EST needs and operand size - OperandSize_er
							
                            else if(StringsAreEqual(TypeToken->Base, TypeToken->Count, STString, STStringLength))
                            {
                                meta_WriteFile(&MetaState, OperandTypeString, OperandTypeStringLength);
                                meta_WriteFile(&MetaState, STString, STStringLength);
                                
                                meta_WriteFile(&MetaState, ComaString, ComaStringLength);
                                
                                meta_WriteFile(&MetaState, OperandSizeString, OperandSizeStringLength);
                                meta_WriteFile(&MetaState, ERString, ERStringLength);
                            }

							
                            else if(StringsAreEqual(TypeToken->Base, TypeToken->Count, ESTString, ESTStringLength))
                            {
                                meta_WriteFile(&MetaState, OperandTypeString, OperandTypeStringLength);
                                meta_WriteFile(&MetaState, ESTString, ESTStringLength);
                                
                                meta_WriteFile(&MetaState, ComaString, ComaStringLength);
                                
                                meta_WriteFile(&MetaState, OperandSizeString, OperandSizeStringLength);
                                meta_WriteFile(&MetaState, ERString, ERStringLength);
                            }
							
							

                            else 
                            {
                                meta_WriteFile(&MetaState, OperandTypeString, OperandTypeStringLength);
                                
                                if(TypeToken->Count)
                                {
                                    Assert(TypeToken->Base);
                                    meta_WriteFile(&MetaState, TypeToken->Base, TypeToken->Count);
                                }
                                else
                                {
                                    meta_WriteFile(&MetaState, InvalidString, InvalidStringLength);
                                }
                                
                                meta_WriteFile(&MetaState, ComaString, ComaStringLength);
                                
                                meta_WriteFile(&MetaState, OperandSizeString, OperandSizeStringLength);
                                
                                if(SizeToken->Count)
                                {
                                    Assert(SizeToken->Base);
                                    meta_WriteFile(&MetaState, SizeToken->Base, SizeToken->Count);
                                }
                                else
                                {
                                    meta_WriteFile(&MetaState, InvalidString, InvalidStringLength);
                                }
                                
                            }
                            
                            meta_WriteFile(&MetaState, EndPushOperandString, EndPushOperandStringLength);
                        }
                        
                        if(LastType == GrammarTokenType_Normal)
                        {
                            meta_WriteFile(&MetaState, BeginPushInstructionInfoString, BeginPushInstructionInfoStringLength);
                        }
                        else if(LastType == GrammarTokenType_Group)
                        {
                            meta_WriteFile(&MetaState, BeginInstructionInfoGroupString, BeginInstructionInfoGroupStringLength);
                        }
                        else if(LastType == GrammarTokenType_Entry)
                        {
                            meta_WriteFile(&MetaState, BeginPushInstructionInfoEntryString, BeginPushInstructionInfoEntryStringLength);
                        }
                        
                        meta_WriteFile(&MetaState, QuoteString, QuoteStringLength);
                        meta_WriteFile(&MetaState, MnemonicToken.Base, MnemonicToken.Count);
                        meta_WriteFile(&MetaState, QuoteString, QuoteStringLength);
                        
                        meta_WriteFile(&MetaState, ComaString, ComaStringLength);
                        
                        if(LastType == GrammarTokenType_Entry)
                        {
                            meta_WriteFile(&MetaState, EntryID.Base, EntryID.Count);
                            meta_WriteFile(&MetaState, ComaString, ComaStringLength);
                        }
                        
                        
                        meta_WriteFile(&MetaState, EndPushInstructionInfoString, EndPushInstructionInfoStringLength);
                        
                        LastType = GrammarTokenType_Invalid;
                        
                    }break;
                    
                    case GrammarTokenType_Numeric:
                    {
                        int x = 5;
                    }break;
                    
                    case GrammarTokenType_Comment:
                    {
                        int x = 5;
                    }break;
                    
                    InvalidDefaultCase;
                };
            }
            
            meta_WriteFile(&MetaState, EndFileSectionString, EndFileSectionStringLength);
            
#if 0            
            TotalEntryCountStringLength = sprintf_s(TotalEntryCountString, MAX_BUFFER_SIZE, "%zi", TotalEntryCount);
            meta_WriteFile(MetaState, TotalEntryCountString, TotalEntryCountStringLength);
            meta_WriteFile(MetaState, "\n", 1);
#endif
            
            free(AssemblyGrammarsBase);
            
            //TODO(Alex): Use the xmltree to parse the xmlfile and select the attributes that you want from it 
            
        }
        
        
        fclose(AssemblyGrammarsFile);
    }
    
}



#if 0            
for(memory_index Index = 0;
    Index < XMLTree.ElementCount;
    ++Index)
{
    xml_element * Element = XMLTree.FirstElement + Index;
    
    WriteFile(STDOutHandle, (void*)Element->Tag.Base, SafeTruncateU64ToU32(Element->Tag.Count), (LPDWORD)&TokenCharsWritten,0);
    WriteFile(STDOutHandle, (void*)"\n", 1, (LPDWORD)&TokenCharsWritten, 0);
    
    xml_attr_name * AttrName = Element->FirstAttrName;
    while(AttrName)
    {
        
        WriteFile(STDOutHandle, (void*)"\t", 1, (LPDWORD)&TokenCharsWritten, 0);
        WriteFile(STDOutHandle, (void*)AttrName->AttrName.Base, SafeTruncateU64ToU32(AttrName->AttrName.Count), (LPDWORD)&TokenCharsWritten, 0);
        WriteFile(STDOutHandle, (void*)"\n", 1, (LPDWORD)&TokenCharsWritten, 0);
        
        xml_attr_value * AttrValue = AttrName->FirstAttrValue;
        while(AttrValue)
        {
            
            
            WriteFile(STDOutHandle, (void*)"\t", 1, (LPDWORD)&TokenCharsWritten, 0);
            WriteFile(STDOutHandle, (void*)"\t", 1, (LPDWORD)&TokenCharsWritten, 0);
            WriteFile(STDOutHandle, (void*)AttrValue->AttrValue.Base, SafeTruncateU64ToU32(AttrValue->AttrValue.Count), (LPDWORD)&TokenCharsWritten, 0);
            WriteFile(STDOutHandle, (void*)"\n", 1, (LPDWORD)&TokenCharsWritten, 0);
            
            //printf_s("\t\t%*s\n",(u32)AttrValue->AttrValue.Count, AttrValue->AttrValue.Base);
            AttrValue = AttrValue->Next;
        }
        
        AttrName = AttrName->Next;
    }
    
    
}
#endif



