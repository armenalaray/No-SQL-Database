//////////////////////////////////////////////////////
//
//Author: Alejandro Armenta 
//File: instruction_infos_filter_64.cpp
//Company: 
//
//2018 - 2019 All rights reserved.
//
//////////////////////////////////////////////////////



#include "Windows.h"
#include "stdio.h"
#include "eaglefly_platform.h"

#include "instruction_infos_filter.h"

#include "eaglefly_string.cpp"
#include "xml_tree.cpp"

#define INSTRUCTION_BUFFER_SIZE 8192

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

int main(int Argcount, char ** Arguments)
{
    
    HANDLE STDOutHandle = GetStdHandle(STD_OUTPUT_HANDLE); 
    FILE * XMLFile = fopen(Arguments[1], "rb");
    
    
    if(XMLFile)
    {
        memory_index XMLSize = GetFileSize(XMLFile);
        
        char * XMLBase = 0;
        XMLBase = (char *)malloc(XMLSize);
        
        memory_index XMLBytesRead = fread (XMLBase, 1, XMLSize, XMLFile);
        Assert(XMLBytesRead  == XMLSize);
        
        if(XMLBase)
        {
            
            /*
NOTE(ALex): we just want to see the tree structure,  so for that we say if we find new elements we add them 

if we already have a tag we dont add it
 we have to add it to the right place in the tree
 
 if its a new attribute name its a new name for that element 
 
 we add elements to elements - these are added between opening and closing elements
 so we add attrnames to elements - this are added inside the opening element
 we add attrvalues to attrnames - this are added inside the attr values 
 
*/
            
            
            memory_index MetaMemorySize = Gigabytes(4);
            meta_state * MetaState = (meta_state *)malloc(MetaMemorySize);
            InitializeArena(&MetaState->MetaArena, MetaState + 1, MetaMemorySize - sizeof(meta_state));
            SubArena(&MetaState->MetaArena, &MetaState->ElementArena, Megabytes(256));
            SubArena(&MetaState->MetaArena, &MetaState->AttrValuesArena, Megabytes(256));
            SubArena(&MetaState->MetaArena, &MetaState->AttrNamesArena, Megabytes(256));
            
            MetaState->STDOutHandle = STDOutHandle;
            
            xml_tokenizer Tokenizer = {};
            InitXMLTokenizerCount(&Tokenizer, XMLBase, XMLSize);
            
            xml_tree XMLTree = {};
            InitXMLTree(MetaState, &XMLTree);
            
            /*
            
            //NOTE(Alex): Element tags have to start with a letter or an undescore , valid characters: "[a-z][A-Z][0-9]-_."
            //NOTE(Alex): Attribute names have to start with a letter or an undescore , valid characters: "[a-z][A-Z][0-9]-_."
            // attribute names have to be followed by a quoted value. 
            //there can be a space between attributesname = and atribute value
            
            Attribute Values and text can have any unicode character, Entity characters have to be represented as :
            
There are 5 pre-defined entity references in XML:

&lt;	<	less than
&gt;	>	greater than
&amp;	&	ampersand 
&apos;	'	apostrophe
&quot;	"	quotation mark


Only < and & are strictly illegal in XML, but it is a good habit to replace > with &gt; as well.

Take < > = as especial characters not tokens 


Namespaces:   

Default namespaces are added to current and children elements , but no attributes.
*/
            
            /*
            
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
            
            
total 1125



            //NOTE(Alex): opcode tables 
            so now i dont need to have the tttn bitfield, i could just print the instruction based on 
            the only thing that matters now are mod and rm bitfields 
            
            
            for assembly grammar print all entries already as the grammar and say if theres multiple grammars fro entry, 
            then we manually check the double entries and decide which one we want!
            
            
            we want just one syntax, and for each entry we define the group extension value as it goes we dont care about that 
            
            
            opcode IDs file layout:
            
            
            
            one-byte
            
 pref element (tex)
            pri_opcd element (value attr-value)
            sec_opcd element (text)
            r attr / opcd_ext element (text) / no modrm byte
            mod attr -> attr-value mem (mod < 0b11) , attr-value nomem (mod == 0b11)
            NOTE(Alex): we re  going to treat mod = 11 as opcodeID's and (mod < 0b11) as mod bitfield
            and we are going to order them first the opcodeID and then the memory access so that there's not an invalid hit on the decoder.
            
            
            
            mem_format (floating point) MF - is a bitfield on the primary opcode - 2 bitfield (00 01 10 11)
            sign-ext is s bitfield on the primary opcode - 1 bitfield (0 1);
            op_size is w bitfield on the primary opcode - 1 bitfield (0 1);
            direction is d bitfield on the primary opcode - 1 bitfield(0 1);
            
            
            two-byte
            
pf
0x0F
            pri_opcd
            sec_opcd
            
r attr - means mod reg rm

immediate bitfields are not necessary to be encoded inside the opcode ID's they are accessed via the instruction info


attr="invd" means invalid instruction (on 64 bit mode?)


            one-byte
            opcode = 80
            .   entry = 0
               .       opcode_id (8 0b00000000) mod reg rm //ADD E v, G v
                    .   exta_entry = 1
            .       opcode_id (8, 0b11111111) mod (3, 0b101) rm
            .   extra_entry = 2
             .       //NOTE(Alex): The opcode id with reg access goes first and the opcode id with mem access goes last!
            .       opcode_id (8, 0b10001100) (2, 0b11) sreg3 reg       
.       extra_opcode_id (8, 0b10001100) mod sreg3 rm

opcode = 81
            .   entry = 3
               .       opcode_id (8 0b00000000) mod reg rm //ADD E v, G v
                    .   exta_entry = 4
            .       opcode_id (8, 0b11111111) mod (3, 0b101) rm
            .   extra_entry = 5
             .       //NOTE(Alex): The opcode id with reg access goes first and the opcode id with mem access goes last!
            .       opcode_id (8, 0b10001100) (2, 0b11) sreg3 reg       
.       extra_opcode_id (8, 0b10001100) mod sreg3 rm

            two-byte
            opcode = 80
            .   entry = 6
               .       opcode_id (8 0b00000000) mod reg rm //ADD E v, G v
                    .   exta_entry = 7
            .       opcode_id (8, 0b11111111) mod (3, 0b101) rm
            .   extra_entry = 8
             .       //NOTE(Alex): The opcode id with reg access goes first and the opcode id with mem access goes last!
            .       opcode_id (8, 0b10001100) (2, 0b11) sreg3 reg       
.       extra_opcode_id (8, 0b10001100) mod sreg3 rm

opcode = 81
.   entry = 9
               .       opcode_id (8 0b00000000) mod reg rm //ADD E v, G v
                    .   exta_entry = 10
            .       opcode_id (8, 0b11111111) mod (3, 0b101) rm
            .   extra_entry = 11
             .       //NOTE(Alex): The opcode id with reg access goes first and the opcode id with mem access goes last!
            .       opcode_id (8, 0b10001100) (2, 0b11) sreg3 reg       
.       extra_opcode_id (8, 0b10001100) mod sreg3 rm

total 1125

            follow the syntax field to the opcode id granularities 
            
            instruction flags

I64 sandppile, the instruction is not valid on 64 bit modde, this is already cleaned because we have 3 streams!!
DF64 says defaults to O64 in PM64; 66H results in O16, we have it already on push instructions such that they are made with specific operand types
N.S. is already mapped in in 64 bit mode with instructions that are invalid on 64 bit mode!

     
            REP_VALID, REPNE_VALID, LOCK_VALID
            
            Invalid_64 <brief>Invalid Instruction in 64-Bit Mode</brief>
            
REP_VALID :

<grp1>gen</grp1>
<grp2>inout</grp2>
<grp2>string</grp2>

REPNE_VALID :

<grp1>gen</grp1>
<grp2>inout</grp2>
<grp2>string</grp2>

LOCK_VALID :

<entry direction="0" op_size="0" r="yes" lock="yes"> NOTE(Alex): Lock attribute is only on entry y


we are going to make 3 streams 

1. real address mode

.   if mode=p or mode=e dont put those entries in real address mode

2. protected mode

.   if mode=e dont put those entries in protected mode

3. 64 bit mode

.   if attr=invd and mode=e then dont print that opcode on 64 bit mode
.   note tha this comes after all other entries have been written so we need to rewrite that diferently


i could write inside  a temp buffer the whole thing and thats simpler because if i find that it is invalid
opcode on 64 bit mode then i could just not write it at all

its a priopcd based write system!

so if one entry has attr=invd and mode=e then invalidate opcode

boolean 


*/
            
            
#if 0            
            char StartAssemblyGrammar[MAX_BUFFER_SIZE] = {"StartFileStringSection(&FileManager, StringSection_assembly_grammar);\t\n\n\0"};
            u32 StartAssemblyGrammarLength =  StringLength(StartAssemblyGrammar);
            meta_WriteFile(MetaState, StartAssemblyGrammar, StartAssemblyGrammarLength);
#endif
            
            xml_token LastElement = {};
            
            u32 OperandCount = 0;
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
                "128",
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
            
            
            memory_index TotalEntryCount = 0;
            char TotalEntryCountString[MAX_BUFFER_SIZE] = {"0"};
            u32 TotalEntryCountStringLength = StringLength(TotalEntryCountString);
            
            
            char OneByteString[MAX_BUFFER_SIZE] = {"one-byte"};
            u32 OneByteStringLength = StringLength(OneByteString);
            
            char TwoByteString[MAX_BUFFER_SIZE] = {"two-byte"};
            u32 TwoByteStringLength = StringLength(TwoByteString);
            
            char OpcodeString[MAX_BUFFER_SIZE] = {"pri_opcd"};
            u32 OpcodeStringLength = StringLength(OpcodeString);
            
            char SyntaxString[MAX_BUFFER_SIZE] = {"syntax"};
            u32 SyntaxStringLength = StringLength(SyntaxString);
            
            char AddressString[MAX_BUFFER_SIZE] = {"address"};
            u32 AddressStringLength = StringLength(AddressString);
            
            char TypeString[MAX_BUFFER_SIZE] = {"type"};
            u32 TypeStringLength = StringLength(TypeString);
            
            char DisplayedString[MAX_BUFFER_SIZE] = {"displayed"};
            u32 DisplayedStringLength = StringLength(DisplayedString);
            
            char ModeString[MAX_BUFFER_SIZE] = {"mode"};
            u32 ModeStringLength = StringLength(ModeString);
            
            char pString[MAX_BUFFER_SIZE] = {"p"};
            u32 pStringLength = StringLength(pString);
            
            char eString[MAX_BUFFER_SIZE] = {"e"};
            u32 eStringLength = StringLength(eString);
            
            char DestString[MAX_BUFFER_SIZE] = {"dst"};
            u32 DestStringLength = StringLength(DestString);
            
            char SourceString[MAX_BUFFER_SIZE] = {"src"};
            u32 SourceStringLength = StringLength(SourceString);
            
            char MnemString[MAX_BUFFER_SIZE] = {"mnem"};
            u32 MnemStringLength = StringLength(MnemString);
            
            char AttrString[MAX_BUFFER_SIZE] = {"attr"};
            u32 AttrStringLength = StringLength(AttrString);
            
            char invdString[MAX_BUFFER_SIZE] = {"invd"};
            u32 invdStringLength = StringLength(invdString);
            
            char AString[MAX_BUFFER_SIZE] = {"a"};
            u32 AStringLength = StringLength(AString);
            
            char TString[MAX_BUFFER_SIZE] = {"t"};
            u32 TStringLength = StringLength(TString);
            
            char ComaString[MAX_BUFFER_SIZE] = {","};
            u32 ComaStringLength = StringLength(ComaString);
            
            char OpeningGuillemetString[MAX_BUFFER_SIZE] = {"<"};
            u32 OpeningGuillemetStringLength = StringLength(OpeningGuillemetString);
            
            char ClosingGuillemetString[MAX_BUFFER_SIZE] = {">"};
            u32 ClosingGuillemetStringLength = StringLength(ClosingGuillemetString);
            
            char FSlashString[MAX_BUFFER_SIZE] = {"/"};
            u32 FSlashStringLength = StringLength(FSlashString);
            
            char SpaceString[MAX_BUFFER_SIZE] = {" "};
            u32 SpaceStringLength = StringLength(SpaceString);
            
            char EqualString[MAX_BUFFER_SIZE] = {"="};
            u32 EqualStringLength = StringLength(EqualString);
            
            char TabString[MAX_BUFFER_SIZE] = {"\t"};
            u32 TabStringLength = StringLength(TabString);
            
            char EndOfLineString[MAX_BUFFER_SIZE] = {"\n"};
            u32 EndOfLineStringLength = StringLength(EndOfLineString);
            
            char PrefixString[MAX_BUFFER_SIZE] = {"pref"};
            u32 PrefixStringLength = StringLength(PrefixString);
            
            
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
            
            
            b32 LastAddress = false;
            b32 LastType = false;
            
            b32 ModeE = false;
            b32 ModeP = false;
            b32 ModeAttr = false;
            
            b32 AttrInvdAndModeE = false;
            b32 AttrInvd = false;
            b32 AttrAttr = false;
            
            xml_token Prefix = {};
            
            xml_token * LastAddressPtr = 0;
            xml_token * LastTypePtr = 0;
            
            xml_token LastAddressValue = {};
            xml_token LastTypeValue = {};
            
            xml_token * TypeText = 0;
            xml_token * SizeText = 0;
            xml_token * AddressText = 0;
            xml_token * AddressSizeText = 0;
            
            xml_token OperandText = {};
            
            char TempSyntaxBuffer[INSTRUCTION_BUFFER_SIZE];
            u32 TempSyntaxBufferCount = 0;
            
            char InstructionsBuffer[INSTRUCTION_BUFFER_SIZE];
            u32 InstructionsBufferCount = 0;
            
            while(ElementFound)
            {
                xml_token Token = {};
                xml_token_type Type = GetNextXMLToken(&Tokenizer, &Token);
                
                switch(Type)
                {
                    case XMLType_Invalid:
                    {
                        //NOTE(Alex): Invalid Token
                        ElementFound = false;
                    }break;
                    
                    case XMLType_OpeningTag:
                    {
                        
                        LastElement = Token;
                        
                        
                        if(
                            StringsAreEqual(Token.Base, Token.Count, OneByteString, OneByteStringLength) || 
                            StringsAreEqual(Token.Base, Token.Count, TwoByteString, TwoByteStringLength)
                            )
                        {
                            meta_WriteFile(MetaState, Token.Base, Token.Count);
                            meta_WriteFile(MetaState, "\n", 1);
                        }
                        
                        else if(
                            StringsAreEqual(Token.Base, Token.Count, OpcodeString, OpcodeStringLength)
                            )
                        {
                            meta_WriteFile(MetaState, Token.Base, Token.Count);
                            meta_WriteFile(MetaState, " = ", 3);
                            
                            EntryCount = 0;
                        }
                        
                        else if(
                            StringsAreEqual(Token.Base, Token.Count, EntryString, EntryStringLength)
                            )
                        {
                            TotalEntryCountStringLength = sprintf_s(TotalEntryCountString, MAX_BUFFER_SIZE, "%zi", TotalEntryCount);
                            
                            if(EntryCount == 0)
                            {
                                //First opcode  Entry
                                
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, TabString, TabStringLength);
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, Token.Base, Token.Count);
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, SpaceString, SpaceStringLength);
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, EqualString, EqualStringLength);
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, SpaceString, SpaceStringLength);
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, TotalEntryCountString, TotalEntryCountStringLength);
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, EndOfLineString, EndOfLineStringLength);
                                
#if 0                                
                                meta_WriteFile(MetaState, "\t", 1);
                                meta_WriteFile(MetaState, Token.Base, Token.Count);
                                meta_WriteFile(MetaState, " = ", 3);
                                meta_WriteFile(MetaState, TotalEntryCountString, TotalEntryCountStringLength);
                                meta_WriteFile(MetaState, "\n", 1);
#endif
                                
                            }
                            else
                            {
                                
                                //Extra Entries for opcode
                                
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, TabString, TabStringLength);
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, ExtraEntryString, ExtraEntryStringLength);
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, SpaceString, SpaceStringLength);
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, EqualString, EqualStringLength);
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, SpaceString, SpaceStringLength);
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, TotalEntryCountString, TotalEntryCountStringLength);
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, EndOfLineString, EndOfLineStringLength);
                                
#if 0                                
                                meta_WriteFile(MetaState, "\t", 1);
                                meta_WriteFile(MetaState, ExtraEntryString, ExtraEntryStringLength);
                                meta_WriteFile(MetaState, " = ", 3);
                                meta_WriteFile(MetaState, TotalEntryCountString, TotalEntryCountStringLength);
                                meta_WriteFile(MetaState, "\n", 1);
#endif
                                
                            }
                            
                            ++EntryCount;
                            ++TotalEntryCount;
                            
                            GrammarCount = 0;
                        }
                        
                        else if(StringsAreEqual(Token.Base, Token.Count, SyntaxString, SyntaxStringLength))
                        {
#ifdef EAGLEFLY_INTERNAL
                            if(ModeE || ModeP)
                            {
                                int x = 5;
                            }
#endif
                            Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, TabString, TabStringLength);
                            Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, TabString, TabStringLength);
                            //meta_WriteFile(MetaState, "\t", 1);
                            //meta_WriteFile(MetaState, "\t", 1);
                            
                            if(GrammarCount == 0)
                            {
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, GrammarString, GrammarStringLength);
                                //meta_WriteFile(MetaState, GrammarString, GrammarStringLength);
                            }
                            else
                            {
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, ExtraGrammarString, ExtraGrammarStringLength);
                                //meta_WriteFile(MetaState, ExtraGrammarString, ExtraGrammarStringLength);
                            }
                            
                            Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, SpaceString, SpaceStringLength);
                            
                            //meta_WriteFile(MetaState, " ", 1);
                            
                            InsideSyntax = true;
                            ++GrammarCount;
                        }
                        
                        else if(StringsAreEqual(Token.Base, Token.Count, MnemString, MnemStringLength))
                        {
                            Mnemonic = true;
                        }
                        
                    }break;
                    
                    case XMLType_SelfClosingTag:
                    {
                        int x = 5;
                    }break;
                    
                    case XMLType_ClosingTag:
                    {
                        if(StringsAreEqual(Token.Base, Token.Count, OpcodeString, OpcodeStringLength))
                        {
                            if(!(AttrInvdAndModeE))
                            {
                                meta_WriteFile(MetaState, InstructionsBuffer, InstructionsBufferCount);
                            }
                            
                            InstructionsBufferCount = 0;
                            AttrInvdAndModeE = false;
                        }
                        
                        if(StringsAreEqual(Token.Base, Token.Count, SyntaxString, SyntaxStringLength))
                        {
                            Append(TempSyntaxBuffer, &TempSyntaxBufferCount, INSTRUCTION_BUFFER_SIZE, EndOfLineString, EndOfLineStringLength);
                            
                            //NOTE(Alex): We push twice when we have a mandatory prefix
                            
                            Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, TempSyntaxBuffer, TempSyntaxBufferCount);
                            
                            if(Prefix.Base)
                            {
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, TabString, TabStringLength);
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, TabString, TabStringLength);
                                //meta_WriteFile(MetaState, "\t", 1);
                                //meta_WriteFile(MetaState, "\t", 1);
                                
                                if(GrammarCount == 0)
                                {
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, GrammarString, GrammarStringLength);
                                    //meta_WriteFile(MetaState, GrammarString, GrammarStringLength);
                                }
                                else
                                {
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, ExtraGrammarString, ExtraGrammarStringLength);
                                    //meta_WriteFile(MetaState, ExtraGrammarString, ExtraGrammarStringLength);
                                }
                                
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, SpaceString, SpaceStringLength);
                                
                                
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, TempSyntaxBuffer, TempSyntaxBufferCount);
                            }
                            
                            TempSyntaxBufferCount = 0;
                            //meta_WriteFile(MetaState, "\n", 1);
                            
                            InsideSyntax = false;
                            OperandCount = 0;
                        }
                        
                        if(StringsAreEqual(Token.Base, Token.Count, MnemString, MnemStringLength))
                        {
                            Mnemonic = false;
                        }
                        
                        if(StringsAreEqual(Token.Base, Token.Count, EntryString, EntryStringLength))
                        {
                            if(AttrInvd && ModeE)
                            {
                                AttrInvdAndModeE = true;
                            }
                            
                            AttrInvd = false;
                            ModeE = false;
                            
                            ClearXMLToken(&Prefix);
                        }
                        
                        if(StringsAreEqual(Token.Base, Token.Count, DestString, DestStringLength) ||
                           StringsAreEqual(Token.Base, Token.Count, SourceString, SourceStringLength))
                        {
                            
                            if(InsideSyntax && OperandDisplayed)
                            {
                                
                                if(OperandCount > 0)
                                {
                                    Append(TempSyntaxBuffer, &TempSyntaxBufferCount, INSTRUCTION_BUFFER_SIZE, ComaString, ComaStringLength);
                                    //meta_WriteFile(MetaState, ",", 1);
                                }
                                
                                if(AddressText)
                                {
                                    Append(TempSyntaxBuffer, &TempSyntaxBufferCount, INSTRUCTION_BUFFER_SIZE, OpeningGuillemetString, OpeningGuillemetStringLength);
                                    //meta_WriteFile(MetaState, "<", 1);
                                    
                                    if(AddressText)
                                    {
                                        Append(TempSyntaxBuffer, &TempSyntaxBufferCount, INSTRUCTION_BUFFER_SIZE, AddressText->Base, AddressText->Count);
                                        //meta_WriteFile(MetaState, AddressText->Base, AddressText->Count);
                                    }
                                    
                                    //meta_WriteFile(MetaState, " ", 1);
                                    
                                    if(AddressSizeText)
                                    {
                                        Append(TempSyntaxBuffer, &TempSyntaxBufferCount, INSTRUCTION_BUFFER_SIZE, AddressSizeText->Base, AddressSizeText->Count);
                                        //meta_WriteFile(MetaState, AddressSizeText->Base, AddressSizeText->Count);
                                    }
                                    
                                    Append(TempSyntaxBuffer, &TempSyntaxBufferCount, INSTRUCTION_BUFFER_SIZE, ClosingGuillemetString, ClosingGuillemetStringLength);
                                    Append(TempSyntaxBuffer, &TempSyntaxBufferCount, INSTRUCTION_BUFFER_SIZE, FSlashString, FSlashStringLength);
                                    //meta_WriteFile(MetaState, ">/", 2);
                                }
                                
                                if(SizeText || TypeText)
                                {
                                    Append(TempSyntaxBuffer, &TempSyntaxBufferCount, INSTRUCTION_BUFFER_SIZE, OpeningGuillemetString, OpeningGuillemetStringLength);
                                    //meta_WriteFile(MetaState, "<", 1);
                                    
                                    if(TypeText)
                                    {
                                        Append(TempSyntaxBuffer, &TempSyntaxBufferCount, INSTRUCTION_BUFFER_SIZE, TypeText->Base, TypeText->Count);
                                        //meta_WriteFile(MetaState, TypeText->Base, TypeText->Count);
                                    }
                                    
                                    //meta_WriteFile(MetaState, " ", 1);
                                    
                                    if(SizeText)
                                    {
                                        Append(TempSyntaxBuffer, &TempSyntaxBufferCount, INSTRUCTION_BUFFER_SIZE, SizeText->Base, SizeText->Count);
                                        //eta_WriteFile(MetaState, SizeText->Base, SizeText->Count);
                                    }
                                    
                                    Append(TempSyntaxBuffer, &TempSyntaxBufferCount, INSTRUCTION_BUFFER_SIZE, ClosingGuillemetString, ClosingGuillemetStringLength);
                                    //meta_WriteFile(MetaState, ">", 1);
                                }
                                
                                ++OperandCount;
                            }
                            
                            AddressText = 0;
                            AddressSizeText = 0;
                            TypeText = 0;
                            SizeText = 0;
                            
                        }
                        
                        
                        OperandDisplayed = true;
                        
                    }break;
                    
                    case XMLType_Comment:
                    {
                        
                    }break;
                    
                    case XMLType_AttrName:
                    {
                        if(StringsAreEqual(Token.Base, Token.Count, DisplayedString, DisplayedStringLength))
                        {
                            OperandDisplayed = false;
                        }
                        
                        if(StringsAreEqual(Token.Base, Token.Count, AddressString, AddressStringLength))
                        {
                            LastAddress = true;
                        }
                        
                        if(StringsAreEqual(Token.Base, Token.Count, TypeString, TypeStringLength))
                        {
                            LastType = true;
                        }
                        
                        if(StringsAreEqual(Token.Base, Token.Count, ModeString, ModeStringLength))
                        {
                            ModeAttr = true;
                        }
                        
                        if(StringsAreEqual(Token.Base, Token.Count, AttrString, AttrStringLength))
                        {
                            AttrAttr = true;
                        }
                        
                    }break;
                    
                    case XMLType_AttrValue:
                    {
                        //NOTE(Alex): print pri_opcode value
                        if(StringsAreEqual(LastElement.Base, LastElement.Count, OpcodeString, OpcodeStringLength))
                        {
                            meta_WriteFile(MetaState, Token.Base, Token.Count);
                            meta_WriteFile(MetaState, "\n", 1);
                        }
                        
                        if(InsideSyntax)
                        {
                            for(u32 Index = 0;
                                (Index < OperandTypesTableCount) && (AddressText == 0);
                                ++Index)
                            {
                                xml_token * TypeString_ = OperandTypesTable + Index;
                                if(StringsAreEqual(Token.Base, Token.Count, TypeString_->Base, TypeString_->Count))
                                {
                                    AddressText = TypeString_;
                                }
                            }
                            
                            
                            for(u32 Index = 0;
                                (Index < OperandSizesTableCount) && (AddressSizeText == 0);
                                ++Index)
                            {
                                xml_token * SizeString = OperandSizesTable + Index;
                                if(StringsAreEqual(Token.Base, Token.Count, SizeString->Base, SizeString->Count))
                                {
                                    AddressSizeText = SizeString;
                                }
                            }
                            
                        }
                        
                        if(AttrAttr)
                        {
                            if(StringsAreEqual(Token.Base, Token.Count, invdString, invdStringLength))
                            {
                                AttrInvd = true;
                            }
                            
                            AttrAttr = false;
                        }
                        
                        if(ModeAttr)
                        {
                            if(StringsAreEqual(Token.Base, Token.Count, pString, pStringLength))
                            {
                                ModeP = true;
                            }
                            else if(StringsAreEqual(Token.Base, Token.Count, eString, eStringLength))
                            {
                                ModeE = true;
                            }
                            
                            ModeAttr = false;
                        }
                        
                        
#if 0                        
                        else if(LastAddress)
                        {
                            Assert(LastAddressPtr == 0);
                            
                            LastAddressValue = Token;
                            LastAddressPtr = &LastAddressValue;
                            
                            LastAddress = false;
                        }
                        
                        else if(LastType)
                        {
                            Assert(LastTypePtr  == 0);
                            LastTypeValue = Token;
                            LastTypePtr = &LastTypeValue;
                            
                            LastType = false;
                        }
#endif
                        
                    }break;
                    
                    case XMLType_Text:
                    {
                        ////NOTE(Alex): assembly grammars info : mnem dst and src elements
                        //it could be with a counter if counter OperandLetterCount
                        
                        if(StringsAreEqual(LastElement.Base, LastElement.Count, PrefixString, PrefixStringLength))
                        {
                            Prefix = Token;
                        }
                        
                        if(InsideSyntax)
                        {
                            for(u32 Index = 0;
                                (Index < OperandTypesTableCount) && (TypeText == 0);
                                ++Index)
                            {
                                xml_token * TypeString_ = OperandTypesTable + Index;
                                if(StringsAreEqual(Token.Base, Token.Count, TypeString_->Base, TypeString_->Count))
                                {
                                    TypeText = TypeString_;
                                }
                            }
                            
                            for(u32 Index = 0;
                                (Index < OperandSizesTableCount) && (SizeText == 0);
                                ++Index)
                            {
                                xml_token * SizeString = OperandSizesTable + Index;
                                if(StringsAreEqual(Token.Base, Token.Count, SizeString->Base, SizeString->Count))
                                {
                                    SizeText = SizeString;
                                }
                            }
                            
                            
                            if(Mnemonic)
                            {
                                
                                Append(TempSyntaxBuffer, &TempSyntaxBufferCount, INSTRUCTION_BUFFER_SIZE, Token.Base, Token.Count);
                                Append(TempSyntaxBuffer, &TempSyntaxBufferCount, INSTRUCTION_BUFFER_SIZE, SpaceString, SpaceStringLength);
                                
                                //meta_WriteFile(MetaState, Token.Base, Token.Count);
                                //meta_WriteFile(MetaState, " ", 1);
                            }
                            else if(!SizeText && !TypeText)
                            {
                                //TODO(Alex): Add Size Text to this entries
                                OperandText = Token;
                                TypeText = &OperandText;
                            }
                            
                        }
                        
                        LastAddressPtr = 0;
                        LastTypePtr = 0;
                        
                    }break;
                    
                    InvalidDefaultCase;
                };
            }
            
            TotalEntryCountStringLength = sprintf_s(TotalEntryCountString, MAX_BUFFER_SIZE, "%zi", TotalEntryCount);
            meta_WriteFile(MetaState, TotalEntryCountString, TotalEntryCountStringLength);
            meta_WriteFile(MetaState, "\n", 1);
            
            
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
            
            
            
            free(XMLBase);
            
            //TODO(Alex): Use the xmltree to parse the xmlfile and select the attributes that you want from it 
            
        }
        
        
        fclose(XMLFile);
    }
    
}



