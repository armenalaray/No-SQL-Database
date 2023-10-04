//////////////////////////////////////////////////////
//
//Author: Alejandro Armenta 
//Date: 2019
//File: opcode_ids_filter_64.cpp
//Company: 
//
//2018 - 2019 All rights reserved.
//
//////////////////////////////////////////////////////



/*
NOTE(Alex): 

//TODO(Alex):IMPORTANT expand Temp buffer, its not sufficient!! 

//Important data:


 2532 - Table B-13.  General Purpose Instruction Formats and Encodings for Non-64-Bit Modes 
 2543 - Table B-15.  General Purpose Instruction Formats and Encodings for 64-Bit Mode
 2563 - Table B-16.  Pentium Processor Family Instruction Formats and Encodings, Non-64-Bit Modes Instruction and Format Encoding 
 2563 - Table B-17.  Pentium Processor Family Instruction Formats and Encodings, 64-Bit Mode Instruction and Format Encoding 
 
 XML syntax rules - 
 
 Markup 
 
 strings that constitute markup either begin with the character < and end with a >, 
or they begin with the character & and end with a ;.

Comments

<!--no need to escape <code> & such in comments-->

Content 


elements <a></a>
attributes a=""


There are 5 pre-defined entity references in XML:

&lt;	<	less than
&gt;	>	greater than
&amp;	&	ampersand 
&apos;	'	apostrophe
&quot;	"	quotation mark


all other text that is not markup or comments.



 1. The document contains only properly encoded legal Unicode characters.
 2. None of the special syntax characters such as < and & appear except when performing their markup-delineation roles.
 3. Tag names cannot contain any of the characters !"#$%&'()*+,/;<=>?@[\]^`{|}~, nor a space character, and cannot begin with "-", ".", or a numeric digit
 4. The start-tag, end-tag, and empty-element tag that delimit elements are correctly nested, with none missing and none overlapping.
5. A single root element contains all the other elements
6. Tag names are case-sensitive; the start-tag and end-tag must match exactly.


First i want to know the data structure of the xml file, so im going to write a program that just does that.

the thing a want from the data structure is to find all the names of it 
we dont care about the order in which they appear, nor their hierarchy 
we just want to knwo which elements we have first and then those elements what attributes they can have and which values they can have.


<x86reference>
           -  <one-byte>
-      <pri_opcd Attr0="00 01 03 03" Attr1="01 02 03 04 05 06 07 08 "
-      </pri_opcd>


-  </one-byte>
</x86reference>



peek tokens in spaces 

make count of each opening bracket and closing bracket

if in opening bracket it can be an element or a comment
if its not a comment then

the tag has to be inside the closing brackets and has to be the first element


///////////////////////////////////////////////////////////////////////////////


meta_tables.cpp

This will generate the code that generates the eaglefly_instruction_tables.eflyfile  and it also 
will generate the InstructionStream for the disassembler 

in_files:

x86_64_tables.xml - x86_64 specificcation xml file

out_files:

eflyfile_meta.cpp - is where all the code to generate the instruction_tables will be
instruction_stream.cpp - is where the instruction stream testing for disasssembler will be generated


xml_tree.info

using xml_tree.info lets start parsing the xml file and generating the eflyfile_meta.cpp


notes:

displayed attrname means that is an implicit operand in the instruction, so it it not used at all

<group1>prefix</group1>

nr attribute seems like a number, used only for indexing

<opcd_ext>1</opcd_ext> means the opcode extension field with reg field in modrm = 1

op_size attribute name is w bit field - this is nice since we need it that way!!

sign-ext 1 attribute name means if immediate data gets sign extended to effective operand size

tttn means tttn bitfield

direction 1/0 attribute name means d bitfield - this is not necessay since we will use the grammar only 

sr attribute name means segment register specifier sreg2
sre attribute name means segment register specifier sreg3

mf attribute name means mem_format (MF) bitfield used only on x87 FPU instructions


if the entry has 
 <grp1>prefix</grp1> - cancel meta parsing
 
 
 
 so all we need for now is to get all the <grp1>gen</grp1> instructions.
 
 we need to know the mandatory prefixes if any, wich we dont really care
 
 
 //NOTE(Alex): opcode encodings info 
 
 if it is on one byte we have pri_op
 if it is on two byte we have 0f pri_op
 r attribute name means full modrm byte
 
<sec_opcd>F0</sec_opcd>  OR <opcd_ext>7</opcd_ext> --- former means modrm byte is used fully , latter means opcode extension on reg field.
<pref>9B</pref> means mandatory prefix


//NOTE(Alex): assembly grammars info 
mnemonic	op1	op2	op3	op4	

dst displayed=no means immplicit operand donot use it to write grammar
so we can just print the text of mnem dst and src elements if not displayed=no

<mnem>LSS</mnem>
<dst nr="2" group="seg" type="w" address="S30" displayed="no">SS</dst>
<dst>
<a>G</a>
<t>vqp</t>
</dst>
<src>
<a>M</a>
<t>ptp</t>
</src>


//NOTE(Alex): flags info

lock yes attribute name means that the instruction is valid ith lock prefix
Invalid Instruction in 64-Bit Mode - translate this to i64 flag = true for entry


proc_start means introduced with processor 




*/

#include "Windows.h"
#include "stdio.h"
#include "eaglefly_platform.h"
#include "instruction_infos_filter.h"
#include "eaglefly_string.cpp"
#include "xml_tree.cpp"

#define INSTRUCTION_BUFFER_SIZE 8192 * 2

enum reg_in_opcode_type
{
    RegInOpcode_Invalid = 0,
    
    RegInOpcode_Z,
    RegInOpcode_S2,
    RegInOpcode_S30,
    RegInOpcode_S33,
    
    RegInOpcode_Count,
};

enum operating_mode
{
    OperatingMode_Invalid = 0,
    OperatingMode_64Bit, 
    
};

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

internal void
ConvertU64ToStringSize(char * out_Buffer, u32 * out_BufferCount, u32 BufferSize, u32 EffOperandSize, u64 BitfieldValue, u32 BitfieldSize, b32 SignExtend)
{
    Assert((BitfieldSize & 0x7) == 0);
    
    u32 TempBufferCount = 0;
    char TempBuffer[MAX_BUFFER_SIZE] = {0};
    
    ConvertU64ToASCHexString(TempBuffer, &TempBufferCount, MAX_BUFFER_SIZE, BitfieldValue, BitfieldSize, false);
    
    u32 NibbleCount = EffOperandSize / 4;
    char * At = TempBuffer + (TempBufferCount - NibbleCount);
    
    Append(out_Buffer, out_BufferCount, BufferSize, At, NibbleCount);
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
               .       opcode_id (8, 0b00000000) mod reg rm //ADD E v, G v
                    .   exta_entry = 1
            .       opcode_id (8, 0b11111111) mod (3, 0b101) rm
            .   extra_entry = 2
             .       //NOTE(Alex): The opcode id with reg access goes first and the opcode id with mem access goes last!
            .       opcode_id (8, 0b10001100) (2, 0b11) sreg3 reg       
.       extra_opcode_id (8, 0b10001100) mod sreg3 rm

opcode = 81
            .   entry = 3
               .       opcode_id (8, 0b00000000) mod reg rm //ADD E v, G v
                    .   exta_entry = 4
            .       opcode_id (8, 0b11111111) mod (3, 0b101) rm
            .   extra_entry = 5
             .       //NOTE(Alex): The opcode id with reg access goes first and the opcode id with mem access goes last!
            .       opcode_id (8, 0b10001100) (2, 0b11) sreg3 reg       
.       extra_opcode_id (8, 0b10001100) mod sreg3 rm

            two-byte
            opcode = 80
            .   entry = 6
               .       opcode_id (8, 0b00000000) mod reg rm //ADD E v, G v
                    .   exta_entry = 7
            .       opcode_id (8, 0b11111111) mod (3, 0b101) rm
            .   extra_entry = 8
             .       //NOTE(Alex): The opcode id with reg access goes first and the opcode id with mem access goes last!
            .       opcode_id (8, 0b10001100) (2, 0b11) sreg3 reg       
.       extra_opcode_id (8, 0b10001100) mod sreg3 rm

opcode = 81
.   entry = 9
               .       opcode_id (8, 0b00000000) mod reg rm //ADD E v, G v
                    .   exta_entry = 10
            .       opcode_id (8, 0b11111111) mod (3, 0b101) rm
            .   extra_entry = 11
             .       //NOTE(Alex): The opcode id with reg access goes first and the opcode id with mem access goes last!
            .       opcode_id (8, 0b10001100) (2, 0b11) sreg3 reg       
.       extra_opcode_id (8, 0b10001100) mod sreg3 rm

total 1125

prefix opcode is enclosed in entry elements (means each new entry has a new prefix if any)
sec opcode is enclosed in entry elements (means each new entry has a new sec opcode if any)
 opcd_ext is enclosed in entry elements (means each new entry has a new  opcd_ext if any)
 
            follow the syntax field to the opcode id granularities 
            
            NOTE(Alex): CHECKED - reg instructions go first than mem instructions
            
            modrm addressing modes
            
                C means xx control xxx // the reg field of the modrmbyte selects a control register
                D means xx debug xxx //the reg field of the modrmbyte selects a debug register
E  means mod xxx (GRP / mem)  // A ModR/M byte follows the opcode and specifies the operand. The operand is either a general-purpose register or a memory address. 
                ES means mod xxx (ST(i) / mem)
  CHECKED -- EST means 11 xxx ST(i) 
  
G means xx GPR xxx // The reg field of the ModR/M byte selects a general register (for example, AX (000)).
                CHECKED -- H means mod xxx GPR // The r/m field of the ModR/M byte always selects a general register, regardless of the mod field (for example, MOV (0F20)). 
                
                M means mod xxx mem // The ModR/M byte may refer only to memory: mod != 11bin (BOUND, LEA, CALLF, JMPF, LES, LDS, LSS, LFS, LGS, CMPXCHG8B, CMPXCHG16B, F20FF0 LDDQU).
                CHECKED -- N meams 11 xxx MMX // The R/M field of the ModR/M byte selects a packed quadword MMX technology register.
                
                P means xx MMX xxx // The reg field of the ModR/M byte selects a packed quadword MMX technology register.
                Q means mod xxx (MMX / mem) // A ModR/M byte follows the opcode and specifies the operand. The operand is either an MMX technology register or a memory address.
                CHECKED -- R means 11 xxx GPR // The mod field of the ModR/M byte may refer only to a general register (only MOV (0F20-0F24, 0F26)).
                S means xx segreg xxxx // The reg field of the ModR/M byte selects a segment register (only MOV (8C, 8E)).
                
                U means 11 xxx XMM // The R/M field of the ModR/M byte selects a 128-bit XMM register.
                V means xx XMM xxx // The reg field of the ModR/M byte selects a 128-bit XMM register.
                W means mod xxx (XMM / mem) // A ModR/M byte follows the opcode and specifies the operand. The operand is either a 128-bit XMM register or a memory address.
                
                so the register type is not necessary to diferentiate, rm is ok. 
                what does it access, if its an opcode extension then it is an id other is reg
                
                mod field is ok, but since we have two different grammars for memory and for registers we need an idea to wrap them up
                so the simplest way is to move register fetches at first so the opcodeid can be compared other could be to put a especific type so that it is checked on the decoder,
                simply putting mod is not going to work, since the register
                
                mod reg rm
                
                
            "A", 
                "BA",
                "BB",
                "BD",
                
                F 
                
I 
                J
                O 
                
X 
                Y
                
                register inside opcode  addressing modes
                
                Z means (opcode) GPR // The instruction has no ModR/M byte; the three least-significant bits of the opcode byte selects a general-purpose register
                S2 means xxx sreg2 xxx // The two bits at bit index three of the opcode byte selects one of original four segment registers (for example, PUSH ES).
                S30 means opcode sreg3 (SS/FS/GS)  // The three least-significant bits of the opcode byte selects segment register SS, FS, or GS (for example, LSS).
                S33 means xx sreg3 (FS/GS) xxx // The three bits at bit index three of the opcode byte selects segment register FS or GS (for example, PUSH FS).
                
                
                
SC  references the stack
                T test register 80386 / 80486 replaced by MSR's
                
                
                //NOTE(Alex): 
                
                All Zv operands are either alone or they are followwed by immediate data
                
XCHG <Zvqp>,<rAX>
MOV <Zb>,<Ib>
MOV <Zvqp>,<Ivqp>

All instructions with S2 & S33 operands only have one operand.
Seemns no instruction with S30 explicit operands 

It is not necessary to put the eee field since we now when C or D grammars are found we fetch reg field in modrm

TODO(Alex): It is missing to put rex prefixes between legacy prefixes and  main opcodes.
tecnically you could have it or you could not! 


so first iterate through the whole instruction set for 

rex opcode
rex opcode

exta_entry = 716
  (8,0x0F) (8,0x38) (8,0x0A) mod reg rm 
exta_entry = 717
  (16,0x660F) (8,0x38) (8,0x0A) mod reg rm 
  
  REX opcode solution - 
  put rex to all insructions that are on 64 bit mode, and manually erase the ones that shouldnt need rex to operate on 64 bit mode,
  later on we will put flags data for i64 , LOCK, REPE, REPNE;
  
  rex opcode
66 rex OF opcode
66 opcode
F3 rex opcode
F3 opcode
F2 rex opcode
F2 opcode

This solves 66 F3 F2 mandatory prefixes and legacy prefixes,  
so we check all opcode ids to see a match on the prefixes; if there's no match, then we know that those are legacy prefixes
we consume the prefixes and reiterate on the opcode matcher, for a new instruction, 

So for REX prefixes we can add them to each assembly grammar who has at least one operand that is a qword pointer 'q';
because we know that 64 bit operands are only valid on 64 bit mode!

We dont need to check for the NP (not valid prefix), what that means is that if you use the prefix then the encoding would be for other instruction.


mode="e" 
Invalid Instruction on 64 bit mode
ES segment override prefix - null prefix on 64 bit mode
CS segment override prefix - null prefix on 64 bit mode
SS segment override prefix - null prefix on 64 bit mode
DS segment override prefix - null prefix on 64 bit mode
priopcd 40 - Access to new 8-bit registers
priopcd 41 - Extension of r/m field, base field, or opcode reg field
priopcd 42 - Extension of SIB index field
priopcd 43 - REX.X and REX.B combination
priopcd 44 - Extension of ModR/M reg field
priopcd 45 - REX.R and REX.B combination
priopcd 46 - REX.R and REX.X combination
priopcd 47 - REX.R, REX.X and REX.B combination
priopcd 48 - 64 Bit Operand Size
priopcd 49 - REX.W and REX.B combination
priopcd 4A - REX.W and REX.X combination
priopcd 4B - REX.W, REX.X and REX.B combination
priopcd 4C - REX.W and REX.R combination
priopcd 4D - REX.W, REX.R and REX.B combination
priopcd 4E - REX.W, REX.R and REX.X combination
priopcd 4F - REX.W, REX.R, REX.X and REX.B combination

Instruction with REX prefix

Instrucion Flags - 

I dont need Df64 since i have vq data size which means Quadword (default) or word if operand-size prefix is used (for example, PUSH (50)).


we are going to make 3 streams 

1. real address mode

.   if mode=p or mode=e dont put those entries in real address mode

2. protected mode

.   if mode=e dont put those entries in protected mode

3. 64 bit mode

.   if attr=invd and mode=e then dont print that opcode on 64 bit mode
.   note tha this comes after all other entries have been written so we need to rewrite that diferently



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
            
            char * Mod11TypesStrings[]=
            {
                "EST", //NOTE(Alex): address attr in syntax/dst | syntax/src all are implicit
                "H",
                "N",
                "R",
                "U",
            };
            
            
            u32 Mod11TypesTableCount = 0;
            xml_token Mod11TypesTable[MAX_BUFFER_SIZE] = {0};
            
            for(u32 Index = 0; 
                Index <  ArrayCount(Mod11TypesStrings);
                ++Index)
            {
                xml_token * Token = Mod11TypesTable + Mod11TypesTableCount++;
                char * Type = Mod11TypesStrings[Index];
                
                Token->Base = Type;
                Token->Count = StringLength(Type);
            }
            
            
            char * ModrmTypesStrings[]=
            {
                
#if 0                
                "A", 
                "BA",
                "BB",
                "BD",
#endif
                
                "C",
                "D",
                "E",
                "ES",
                "EST", //NOTE(Alex): address attr in syntax/dst | syntax/src all are implicit
                
#if 0                
                "F",
#endif
                
                "G",
                "H",
                
#if 0                
                "I",
                "J",
#endif
                
                "M",
                "N",
                
#if 0                
                "O",
#endif
                
                "P",
                "Q",
                "R",
                "S",
                
                
#if 0                
                "SC",
                "T",
#endif
                
                "U",
                "V",
                "W",
                
#if 0                
                "X",
                "Y",
                "Z",
                "S2",
                "S30",
                "S33",
#endif
            };
            
            
            u32 ModrmTypesTableCount = 0;
            xml_token ModrmTypesTable[MAX_BUFFER_SIZE] = {0};
            
            for(u32 Index = 0; 
                Index <  ArrayCount(ModrmTypesStrings);
                ++Index)
            {
                xml_token * Token = ModrmTypesTable + ModrmTypesTableCount++;
                char * Type = ModrmTypesStrings[Index];
                
                Token->Base = Type;
                Token->Count = StringLength(Type);
            }
            
            
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
                "EST", //NOTE(Alex): address attr in syntax/dst | syntax/src all are implicit
                
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
            
            char ModeString[MAX_BUFFER_SIZE] = {"mode"};
            u32 ModeStringLength = StringLength(ModeString);
            
            char pString[MAX_BUFFER_SIZE] = {"p"};
            u32 pStringLength = StringLength(pString);
            
            char eString[MAX_BUFFER_SIZE] = {"e"};
            u32 eStringLength = StringLength(eString);
            
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
            
            char ZString[MAX_BUFFER_SIZE] = {"Z"};
            u32 ZStringLength = StringLength(ZString);
            
            char S2String[MAX_BUFFER_SIZE] = {"S2"};
            u32 S2StringLength = StringLength(S2String);
            
            char S33String[MAX_BUFFER_SIZE] = {"S33"};
            u32 S33StringLength = StringLength(S33String);
            
            
            memory_index EntryCount = 0;
            
            char EntryString[MAX_BUFFER_SIZE] = {"entry"};
            u32 EntryStringLength = StringLength(EntryString);
            
            char ExtraEntryString[MAX_BUFFER_SIZE] = {"exta_entry"};
            u32 ExtraEntryStringLength = StringLength(ExtraEntryString);
            
            
            memory_index GrammarCount = 0;
            
            char OpcodeIDString[MAX_BUFFER_SIZE] = {"opcode_id"};
            u32 OpcodeIDStringLength = StringLength(OpcodeIDString);
            
            char ExtraOpcodeIDString[MAX_BUFFER_SIZE] = {"extra_opcode_id"};
            u32 ExtraOpcodeIDStringLength = StringLength(ExtraOpcodeIDString);
            
            
            char OpeningParenString[MAX_BUFFER_SIZE] = {"("};
            u32 OpeningParenStringLength = StringLength(OpeningParenString);
            
            char ComaString[MAX_BUFFER_SIZE] = {","};
            u32 ComaStringLength = StringLength(ComaString);
            
            char SpaceString[MAX_BUFFER_SIZE] = {" "};
            u32 SpaceStringLength = StringLength(SpaceString);
            
            char ZeroXString[MAX_BUFFER_SIZE] = {"0x"};
            u32 ZeroXStringLength = StringLength(ZeroXString);
            
            char ZeroFString[MAX_BUFFER_SIZE] = {"0F"};
            u32 ZeroFStringLength = StringLength(ZeroFString);
            
            char RexString[MAX_BUFFER_SIZE] = {"(4,0x4) low_rex"};
            u32 RexStringLength = StringLength(RexString);
            
            char RegString[MAX_BUFFER_SIZE] = {"reg"}; 
            u32 RegStringLength = StringLength(RegString);
            
            char RMString[MAX_BUFFER_SIZE] = {"rm"};
            u32 RMStringLength = StringLength(RMString);
            
            char ModString[MAX_BUFFER_SIZE] = {"mod"};
            u32 ModStringLength = StringLength(ModString);
            
            char sreg2String[MAX_BUFFER_SIZE] = {"sreg2"};
            u32 sreg2StringLength = StringLength(sreg2String);
            
            char sreg3String[MAX_BUFFER_SIZE] = {"sreg3"};
            u32 sreg3StringLength = StringLength(sreg3String);
            
            char TwoString[MAX_BUFFER_SIZE] = {"2"};
            u32 TwoStringLength = StringLength(TwoString);
            
            char ThreeString[MAX_BUFFER_SIZE] = {"3"};
            u32 ThreeStringLength = StringLength(ThreeString);
            
            char FiveString[MAX_BUFFER_SIZE] = {"5"};
            u32 FiveStringLength = StringLength(FiveString);
            
            char EightString[MAX_BUFFER_SIZE] = {"8"};
            u32 EightStringLength = StringLength(EightString);
            
            char ModNoMemString[MAX_BUFFER_SIZE] = {"(2,3)"};
            u32 ModNoMemStringLength = StringLength(ModNoMemString);
            
            char EndOfLineString[MAX_BUFFER_SIZE] = {"\n"};
            u32 EndOfLineStringLength = StringLength(EndOfLineString);
            
            char PrefixString[MAX_BUFFER_SIZE] = {"pref"};
            u32 PrefixStringLength = StringLength(PrefixString);
            
            char SecOpcString[MAX_BUFFER_SIZE] = {"sec_opcd"};
            u32 SecOpcStringLength = StringLength(SecOpcString);
            
            char ExtOpcString[MAX_BUFFER_SIZE] = {"opcd_ext"};
            u32 ExtOpcStringLength = StringLength(ExtOpcString);
            
            char ClosingParenString[MAX_BUFFER_SIZE] = {")"};
            u32 ClosingParenStringLength = StringLength(ClosingParenString);
            
            char TabString[MAX_BUFFER_SIZE] = {"\t"};
            u32 TabStringLength = StringLength(TabString);
            
            char EqualString[MAX_BUFFER_SIZE] = {"="};
            u32 EqualStringLength = StringLength(EqualString);
            
            char AttrString[MAX_BUFFER_SIZE] = {"attr"};
            u32 AttrStringLength = StringLength(AttrString);
            
            char invdString[MAX_BUFFER_SIZE] = {"invd"};
            u32 invdStringLength = StringLength(invdString);
            
            
            xml_token PriOpc = {};
            xml_token Prefix = {};
            xml_token SecOpc = {};
            xml_token ExtOpc = {};
            
            b32 modrmbyte = false;
            b32 Mod11 = false;
            b32 LastAddress = false;
            
            b32 ExtendedOpcode = false;
            b32 TwoByteOpcodes = false;
            
            u32 OneByteOpcodesBase = 0;
            u32 TwoByteOpcodeBase = 8;
            
            u32 PrefixBitfieldCount = OneByteOpcodesBase;
            u32 BitfieldCount = 8;
            
            reg_in_opcode_type RegInOpcodeType = RegInOpcode_Invalid;
            
            
            b32 AttrInvdAndModeE = false;
            b32 AttrInvd = false;
            b32 AttrAttr = false;
            
            b32 ModeAttr = false;
            b32 ModeE = false;
            b32 ModeP = false;
            u32 OperatingMode = OperatingMode_Invalid;
            
            b32 LastType = false;
            
            xml_token * LastAddressPtr = 0;
            xml_token * LastTypePtr = 0;
            
            xml_token LastAddressValue = {};
            xml_token LastTypeValue = {};
            
            xml_token * TypeText = 0;
            xml_token * SizeText = 0;
            xml_token * AddressText = 0;
            xml_token * AddressSizeText = 0;
            
            xml_token OperandText = {};
            
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
                        
                        
                        if(StringsAreEqual(Token.Base, Token.Count, OneByteString, OneByteStringLength))
                        {
                            meta_WriteFile(MetaState, Token.Base, Token.Count);
                            meta_WriteFile(MetaState, "\n", 1);
                        }
                        
                        if(StringsAreEqual(Token.Base, Token.Count, TwoByteString, TwoByteStringLength))
                        {
                            meta_WriteFile(MetaState, Token.Base, Token.Count);
                            meta_WriteFile(MetaState, "\n", 1);
                            
                            TwoByteOpcodes = true;
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
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, OpcodeIDString, OpcodeIDStringLength);
                                //meta_WriteFile(MetaState, OpcodeIDString, OpcodeIDStringLength);
                            }
                            else
                            {
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, ExtraOpcodeIDString, ExtraOpcodeIDStringLength);
                                //meta_WriteFile(MetaState, ExtraOpcodeIDString, ExtraOpcodeIDStringLength);
                            }
                            
                            //meta_WriteFile(MetaState, " - ", 3);
                            
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
                        
                        if(StringsAreEqual(Token.Base, Token.Count, EntryString, EntryStringLength))
                        {
                            PrefixBitfieldCount = ((TwoByteOpcodes) ? TwoByteOpcodeBase : OneByteOpcodesBase);
                            OperatingMode = OperatingMode_Invalid;
                            
                            ClearXMLToken(&Prefix);
                            ClearXMLToken(&SecOpc);
                            ClearXMLToken(&ExtOpc);
                            
                            if(AttrInvd && ModeE)
                            {
                                AttrInvdAndModeE = true;
                            }
                            
                            AttrInvd = false;
                            ModeE = false;
                            ModeP = false;
                            
                        }
                        
                        if(StringsAreEqual(Token.Base, Token.Count, SyntaxString, SyntaxStringLength))
                        {
                            InsideSyntax = false;
                            OperandCount = 0;
                            
#ifdef EAGLEFLY_INTERNAL
                            if(ModeE || ModeP)
                            {
                                int x = 5;
                            }
#endif
                            
                            
                            
                            b32 DoubleEntry = 0;
                            DOUBLE_ENTRY:
                            
                            u32 PrefixBitfieldStringLength = 0;
                            char PrefixBitfieldString[MAX_BUFFER_SIZE] = {0};
                            
                            if(DoubleEntry)
                            {
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, TabString, TabStringLength);
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, TabString, TabStringLength);
                                //meta_WriteFile(MetaState, "\t", 1);
                                //meta_WriteFile(MetaState, "\t", 1);
                                
                                if(GrammarCount == 0)
                                {
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, OpcodeIDString, OpcodeIDStringLength);
                                    //meta_WriteFile(MetaState, OpcodeIDString, OpcodeIDStringLength);
                                }
                                else
                                {
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, ExtraOpcodeIDString, ExtraOpcodeIDStringLength);
                                    //meta_WriteFile(MetaState, ExtraOpcodeIDString, ExtraOpcodeIDStringLength);
                                }
                            }
                            
                            Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, SpaceString, SpaceStringLength);
                            //meta_WriteFile(MetaState, SpaceString, SpaceStringLength);
                            
                            PrefixBitfieldStringLength = sprintf_s(PrefixBitfieldString, MAX_BUFFER_SIZE, "%i", PrefixBitfieldCount);
                            
                            if(Prefix.Base)
                            {
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, OpeningParenString, OpeningParenStringLength);
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, EightString, EightStringLength);
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, ComaString, ComaStringLength);
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, ZeroXString, ZeroXStringLength);
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, Prefix.Base, Prefix.Count);
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, ClosingParenString, ClosingParenStringLength);
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, SpaceString, SpaceStringLength);
                                
#if 0                                
                                meta_WriteFile(MetaState, OpeningParenString, OpeningParenStringLength);
                                meta_WriteFile(MetaState, EightString, EightStringLength);
                                meta_WriteFile(MetaState, ComaString, ComaStringLength);
                                meta_WriteFile(MetaState, ZeroXString, ZeroXStringLength);
                                meta_WriteFile(MetaState, Prefix.Base, Prefix.Count);
                                meta_WriteFile(MetaState, ClosingParenString, ClosingParenStringLength);
                                meta_WriteFile(MetaState, SpaceString, SpaceStringLength);
#endif
                                
                            }
                            
                            if((OperatingMode == OperatingMode_64Bit) || DoubleEntry)
                            {
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, RexString, RexStringLength);
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, SpaceString, SpaceStringLength);
                                
#if 0                                    
                                meta_WriteFile(MetaState, RexString, RexStringLength);
                                meta_WriteFile(MetaState, SpaceString, SpaceStringLength);
#endif
                                
                            }
                            
                            if(TwoByteOpcodes)
                            {
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, OpeningParenString, OpeningParenStringLength);
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, EightString, EightStringLength);
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, ComaString, ComaStringLength);
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, ZeroXString, ZeroXStringLength);
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, ZeroFString, ZeroFStringLength);
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, ClosingParenString, ClosingParenStringLength);
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, SpaceString, SpaceStringLength);
                                
#if 0                                
                                meta_WriteFile(MetaState, OpeningParenString, OpeningParenStringLength);
                                meta_WriteFile(MetaState, EightString, EightStringLength);
                                meta_WriteFile(MetaState, ComaString, ComaStringLength);
                                meta_WriteFile(MetaState, ZeroXString, ZeroXStringLength);
                                meta_WriteFile(MetaState, ZeroFString, ZeroFStringLength);
                                meta_WriteFile(MetaState, ClosingParenString, ClosingParenStringLength);
                                meta_WriteFile(MetaState, SpaceString, SpaceStringLength);
#endif
                                
                            }
                            
                            switch(RegInOpcodeType)
                            {
                                case RegInOpcode_Z:
                                {
                                    Assert(!modrmbyte);
                                    
                                    u32 BufferCount = 0;
                                    char Buffer[MAX_BUFFER_SIZE] = {0};
                                    u64 ValueU64;
                                    
                                    ConvertASCHexStringToU64(PriOpc.Base, SafeTruncateU64ToU32(PriOpc.Count), &ValueU64);
                                    ValueU64 >>= 3;
                                    ConvertU64ToStringSize(Buffer, &BufferCount, MAX_BUFFER_SIZE, 8, ValueU64, 8, false);
                                    
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, OpeningParenString, OpeningParenStringLength);
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, FiveString, FiveStringLength);
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, ComaString, ComaStringLength);
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, ZeroXString, ZeroXStringLength);
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, Buffer, BufferCount);
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, ClosingParenString, ClosingParenStringLength);
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, SpaceString, SpaceStringLength);
                                    
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, RegString, RegStringLength);
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, SpaceString, SpaceStringLength);
                                    
                                    
#if 0                                    
                                    meta_WriteFile(MetaState, OpeningParenString, OpeningParenStringLength);
                                    meta_WriteFile(MetaState, FiveString, FiveStringLength);
                                    meta_WriteFile(MetaState, ComaString, ComaStringLength);
                                    meta_WriteFile(MetaState, ZeroXString, ZeroXStringLength);
                                    meta_WriteFile(MetaState, Buffer, BufferCount);
                                    meta_WriteFile(MetaState, ClosingParenString, ClosingParenStringLength);
                                    meta_WriteFile(MetaState, SpaceString, SpaceStringLength);
                                    
                                    meta_WriteFile(MetaState, RegString, RegStringLength);
                                    meta_WriteFile(MetaState, SpaceString, SpaceStringLength);
#endif
                                    
                                }break;
                                
                                case RegInOpcode_S2:
                                {
                                    Assert(!modrmbyte);
                                    
                                    u32 UpValueBufferCount = 0;
                                    char UpValueBuffer[MAX_BUFFER_SIZE] = {0};
                                    
                                    u32 BotValueBufferCount = 0;
                                    char BotValueBuffer[MAX_BUFFER_SIZE] = {0};
                                    
                                    u64 ValueU64;
                                    u64 UpValueU64;
                                    u64 BotValueU64;
                                    
                                    ConvertASCHexStringToU64(PriOpc.Base, SafeTruncateU64ToU32(PriOpc.Count), &ValueU64);
                                    
                                    UpValueU64 = (ValueU64 >> 5);
                                    BotValueU64 = ValueU64 & 0x7;
                                    
                                    ConvertU64ToStringSize(UpValueBuffer, &UpValueBufferCount, MAX_BUFFER_SIZE, 8, UpValueU64, 8, false);
                                    ConvertU64ToStringSize(BotValueBuffer, &BotValueBufferCount, MAX_BUFFER_SIZE, 8, BotValueU64, 8, false);
                                    
                                    //NOTE(Alex): S2 means xxx sreg2 xxx
                                    
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, OpeningParenString, OpeningParenStringLength);
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, ThreeString, ThreeStringLength);
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, ComaString, ComaStringLength);
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, ZeroXString, ZeroXStringLength);
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, UpValueBuffer, UpValueBufferCount);
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, ClosingParenString, ClosingParenStringLength);
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, SpaceString, SpaceStringLength);
                                    
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, sreg2String, sreg2StringLength);
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, SpaceString, SpaceStringLength);
                                    
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, OpeningParenString, OpeningParenStringLength);
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, ThreeString, ThreeStringLength);
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, ComaString, ComaStringLength);
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, ZeroXString, ZeroXStringLength);
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, BotValueBuffer, BotValueBufferCount);
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, ClosingParenString, ClosingParenStringLength);
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, SpaceString, SpaceStringLength);
                                    
                                    
                                    
#if 0                                    
                                    meta_WriteFile(MetaState, OpeningParenString, OpeningParenStringLength);
                                    meta_WriteFile(MetaState, ThreeString, ThreeStringLength);
                                    meta_WriteFile(MetaState, ComaString, ComaStringLength);
                                    meta_WriteFile(MetaState, ZeroXString, ZeroXStringLength);
                                    meta_WriteFile(MetaState, UpValueBuffer, UpValueBufferCount);
                                    meta_WriteFile(MetaState, ClosingParenString, ClosingParenStringLength);
                                    meta_WriteFile(MetaState, SpaceString, SpaceStringLength);
                                    
                                    meta_WriteFile(MetaState, sreg2String, sreg2StringLength);
                                    meta_WriteFile(MetaState, SpaceString, SpaceStringLength);
                                    
                                    meta_WriteFile(MetaState, OpeningParenString, OpeningParenStringLength);
                                    meta_WriteFile(MetaState, ThreeString, ThreeStringLength);
                                    meta_WriteFile(MetaState, ComaString, ComaStringLength);
                                    meta_WriteFile(MetaState, ZeroXString, ZeroXStringLength);
                                    meta_WriteFile(MetaState, BotValueBuffer, BotValueBufferCount);
                                    meta_WriteFile(MetaState, ClosingParenString, ClosingParenStringLength);
                                    meta_WriteFile(MetaState, SpaceString, SpaceStringLength);
#endif
                                    
                                }break;
                                
                                case RegInOpcode_S33:
                                {
                                    
                                    Assert(!modrmbyte);
                                    
                                    u32 UpValueBufferCount = 0;
                                    char UpValueBuffer[MAX_BUFFER_SIZE] = {0};
                                    
                                    u32 BotValueBufferCount = 0;
                                    char BotValueBuffer[MAX_BUFFER_SIZE] = {0};
                                    
                                    u64 ValueU64;
                                    u64 UpValueU64;
                                    u64 BotValueU64;
                                    
                                    ConvertASCHexStringToU64(PriOpc.Base, SafeTruncateU64ToU32(PriOpc.Count), &ValueU64);
                                    
                                    UpValueU64 = (ValueU64 >> 6);
                                    BotValueU64 = ValueU64 & 0x7;
                                    
                                    ConvertU64ToStringSize(UpValueBuffer, &UpValueBufferCount, MAX_BUFFER_SIZE, 8, UpValueU64, 8, false);
                                    ConvertU64ToStringSize(BotValueBuffer, &BotValueBufferCount, MAX_BUFFER_SIZE, 8, BotValueU64, 8, false);
                                    
                                    //NOTE(Alex): S2 means xxx sreg2 xxx
                                    
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, OpeningParenString, OpeningParenStringLength);
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, TwoString, TwoStringLength);
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, ComaString, ComaStringLength);
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, ZeroXString, ZeroXStringLength);
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, UpValueBuffer, UpValueBufferCount);
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, ClosingParenString, ClosingParenStringLength);
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, SpaceString, SpaceStringLength);
                                    
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, sreg3String, sreg3StringLength);
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, SpaceString, SpaceStringLength);
                                    
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, OpeningParenString, OpeningParenStringLength);
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, ThreeString, ThreeStringLength);
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, ComaString, ComaStringLength);
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, ZeroXString, ZeroXStringLength);
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, BotValueBuffer, BotValueBufferCount);
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, ClosingParenString, ClosingParenStringLength);
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, SpaceString, SpaceStringLength);
                                    
                                    
#if 0                                    
                                    meta_WriteFile(MetaState, OpeningParenString, OpeningParenStringLength);
                                    meta_WriteFile(MetaState, TwoString, TwoStringLength);
                                    meta_WriteFile(MetaState, ComaString, ComaStringLength);
                                    meta_WriteFile(MetaState, ZeroXString, ZeroXStringLength);
                                    meta_WriteFile(MetaState, UpValueBuffer, UpValueBufferCount);
                                    meta_WriteFile(MetaState, ClosingParenString, ClosingParenStringLength);
                                    meta_WriteFile(MetaState, SpaceString, SpaceStringLength);
                                    
                                    meta_WriteFile(MetaState, sreg3String, sreg3StringLength);
                                    meta_WriteFile(MetaState, SpaceString, SpaceStringLength);
                                    
                                    meta_WriteFile(MetaState, OpeningParenString, OpeningParenStringLength);
                                    meta_WriteFile(MetaState, ThreeString, ThreeStringLength);
                                    meta_WriteFile(MetaState, ComaString, ComaStringLength);
                                    meta_WriteFile(MetaState, ZeroXString, ZeroXStringLength);
                                    meta_WriteFile(MetaState, BotValueBuffer, BotValueBufferCount);
                                    meta_WriteFile(MetaState, ClosingParenString, ClosingParenStringLength);
                                    meta_WriteFile(MetaState, SpaceString, SpaceStringLength);
#endif
                                    
                                }break;
                                
                                case RegInOpcode_Invalid:
                                {
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, OpeningParenString, OpeningParenStringLength);
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, EightString, EightStringLength);
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, ComaString, ComaStringLength);
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, ZeroXString, ZeroXStringLength);
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, PriOpc.Base, PriOpc.Count);
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, ClosingParenString, ClosingParenStringLength);
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, SpaceString, SpaceStringLength);
                                    
                                    
#if 0                                    
                                    meta_WriteFile(MetaState, OpeningParenString, OpeningParenStringLength);
                                    meta_WriteFile(MetaState, EightString, EightStringLength);
                                    meta_WriteFile(MetaState, ComaString, ComaStringLength);
                                    meta_WriteFile(MetaState, ZeroXString, ZeroXStringLength);
                                    meta_WriteFile(MetaState, PriOpc.Base, PriOpc.Count);
                                    meta_WriteFile(MetaState, ClosingParenString, ClosingParenStringLength);
                                    meta_WriteFile(MetaState, SpaceString, SpaceStringLength);
#endif
                                    
                                }break;
                                
                                InvalidDefaultCase;
                            }
                            
                            
                            //NOTE(Alex): Until now there's no instruction that has a register inside main opcode and a secondary opcode afterwards!
                            if(SecOpc.Base)
                            {
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, OpeningParenString, OpeningParenStringLength);
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, EightString, EightStringLength);
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, ComaString, ComaStringLength);
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, ZeroXString, ZeroXStringLength);
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, SecOpc.Base, SecOpc.Count);
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, ClosingParenString, ClosingParenStringLength);
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, SpaceString, SpaceStringLength);
                                
                                
#if 0                                
                                meta_WriteFile(MetaState, OpeningParenString, OpeningParenStringLength);
                                meta_WriteFile(MetaState, EightString, EightStringLength);
                                meta_WriteFile(MetaState, ComaString, ComaStringLength);
                                meta_WriteFile(MetaState, ZeroXString, ZeroXStringLength);
                                meta_WriteFile(MetaState, SecOpc.Base, SecOpc.Count);
                                meta_WriteFile(MetaState, ClosingParenString, ClosingParenStringLength);
                                meta_WriteFile(MetaState, SpaceString, SpaceStringLength);
#endif
                                
                            }
                            
                            if(modrmbyte)
                            {
                                if(Mod11)
                                {
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, ModNoMemString, ModNoMemStringLength);
                                    //meta_WriteFile(MetaState, ModNoMemString, ModNoMemStringLength);
                                }
                                else
                                {
                                    
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, ModString, ModStringLength);
                                    //meta_WriteFile(MetaState, ModString, ModStringLength);
                                }
                                
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, SpaceString, SpaceStringLength);
                                //meta_WriteFile(MetaState, SpaceString, SpaceStringLength);
                                
                                if(ExtOpc.Base)
                                {
                                    
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, OpeningParenString, OpeningParenStringLength);
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, ThreeString, ThreeStringLength);
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, ComaString, ComaStringLength);
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, ZeroXString, ZeroXStringLength);
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, ExtOpc.Base, ExtOpc.Count);
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, ClosingParenString, ClosingParenStringLength);
                                    
#if 0                                    
                                    meta_WriteFile(MetaState, OpeningParenString, OpeningParenStringLength);
                                    meta_WriteFile(MetaState, ThreeString, ThreeStringLength);
                                    meta_WriteFile(MetaState, ComaString, ComaStringLength);
                                    meta_WriteFile(MetaState, ZeroXString, ZeroXStringLength);
                                    meta_WriteFile(MetaState, ExtOpc.Base, ExtOpc.Count);
                                    meta_WriteFile(MetaState, ClosingParenString, ClosingParenStringLength);
#endif
                                    
                                }
                                else
                                {
                                    Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, RegString, RegStringLength);
                                    //meta_WriteFile(MetaState, RegString, RegStringLength);
                                }
                                
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, SpaceString, SpaceStringLength);
                                //meta_WriteFile(MetaState, SpaceString, SpaceStringLength);
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, RMString, RMStringLength);
                                //meta_WriteFile(MetaState, RMString, RMStringLength);
                                Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, SpaceString, SpaceStringLength);
                                //meta_WriteFile(MetaState, SpaceString, SpaceStringLength);
                                
                            }
                            
                            Append(InstructionsBuffer, &InstructionsBufferCount, INSTRUCTION_BUFFER_SIZE, EndOfLineString, EndOfLineStringLength);
                            
                            if(Prefix.Base && !DoubleEntry)
                            {
                                DoubleEntry = true;
                                goto DOUBLE_ENTRY;
                            }
                            
                            //meta_WriteFile(MetaState, EndOfLineString, EndOfLineStringLength);
                            
                            
                            modrmbyte = false;
                            Mod11 = false;
                            RegInOpcodeType = RegInOpcode_Invalid;
                            LastAddress = false;
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
                            PriOpc = Token;
                            meta_WriteFile(MetaState, PriOpc.Base, PriOpc.Count);
                            meta_WriteFile(MetaState, "\n", 1);
                        }
                        
                        if(LastAddress)
                        {
                            //NOTE(Alex): S2 addressing mode
                            if(StringsAreEqual(Token.Base, Token.Count, S2String, S2StringLength))
                            {
                                Assert(RegInOpcodeType == RegInOpcode_Invalid);
                                RegInOpcodeType = RegInOpcode_S2;
                            }
                            
                            //NOTE(Alex): S33 addressing mode
                            if(StringsAreEqual(Token.Base, Token.Count, S33String, S33StringLength))
                            {
                                Assert(RegInOpcodeType == RegInOpcode_Invalid);
                                RegInOpcodeType = RegInOpcode_S33;
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
                            
                            if(StringsAreEqual(Token.Base, Token.Count, eString, eStringLength))
                            {
                                ModeE = true;
                                
                                Assert(RegInOpcodeType == RegInOpcode_Invalid);
                                OperatingMode = OperatingMode_64Bit;
                            }
                            
                            ModeAttr = false;
                        }
                        
                    }break;
                    
                    case XMLType_Text:
                    {
                        
                        //NOTE(Alex): Here we assume that this elements are not nested
                        if(StringsAreEqual(LastElement.Base, LastElement.Count, PrefixString, PrefixStringLength))
                        {
                            PrefixBitfieldCount += 8;
                            Prefix = Token;
                        }
                        
                        else if(StringsAreEqual(LastElement.Base, LastElement.Count, SecOpcString, SecOpcStringLength))
                        {
                            //PrefixBitfieldCount += 8;
                            SecOpc = Token;
                        }
                        
                        else if(StringsAreEqual(LastElement.Base, LastElement.Count, ExtOpcString, ExtOpcStringLength))
                        {
                            modrmbyte = true;
                            ExtOpc = Token;
                        }
                        
                        else if(StringsAreEqual(LastElement.Base, LastElement.Count, AString, AStringLength))
                        {
                            for(u32 Index = 0;
                                (Index < ModrmTypesTableCount) && (modrmbyte == false);
                                ++Index)
                            {
                                xml_token * TypeString_ = ModrmTypesTable + Index;
                                if(StringsAreEqual(Token.Base, Token.Count, TypeString_->Base, TypeString_->Count))
                                {
                                    modrmbyte = true;
                                }
                            }
                            
                            for(u32 Index = 0;
                                (Index < Mod11TypesTableCount) && (Mod11 == false);
                                ++Index)
                            {
                                xml_token * TypeString_ = Mod11TypesTable + Index;
                                if(StringsAreEqual(Token.Base, Token.Count, TypeString_->Base, TypeString_->Count))
                                {
                                    Mod11 = true;
                                }
                            }
                            
                            //NOTE(Alex): Z addressing mode
                            
                            if(StringsAreEqual(Token.Base, Token.Count, ZString, ZStringLength))
                            {
                                Assert(RegInOpcodeType == RegInOpcode_Invalid);
                                Assert(modrmbyte == false);
                                RegInOpcodeType = RegInOpcode_Z;
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



