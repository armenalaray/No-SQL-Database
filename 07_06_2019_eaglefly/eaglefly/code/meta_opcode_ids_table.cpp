//////////////////////////////////////////////////////
//
//Author: Alejandro Armenta 
//Date: 2019
//File: meta_opcodes_ids_table.cpp
//Company: 
//
//All rights reserved.
//
//////////////////////////////////////////////////////


#include "Windows.h"
#include "stdio.h"


#include "eaglefly_platform.h"
#include "meta_opcode_ids_table.h"
#include "eaglefly_string.h"
#include "eaglefly_string.cpp"


struct meta_state
{
    HANDLE STDOutHandle;
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


inline void
CleanWhiteSpace(opcode_tokenizer * Tokenizer)
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
InitializeOpcodeIDTokenizer(opcode_tokenizer * out_Tokenizer, char * Base, u32 Count)
{
    Assert(Count > 0);
    
    out_Tokenizer->Base = Base;
    out_Tokenizer->At = out_Tokenizer->Base;
    out_Tokenizer->Last = out_Tokenizer->Base + (Count - 1);
}

internal opcode_type 
GetNextOpcodeIDToken(opcode_tokenizer * Tokenizer, char ** out_Ptr, u32 * out_Count)
{
    opcode_type Result = OpcodeType_Invalid;
    
    CleanWhiteSpace(Tokenizer);
    
    char OneByteString[MAX_BUFFER_SIZE] = {"one-byte"};
    u32 OneByteStringLength = StringLength(OneByteString);
    
    char TwoByteString[MAX_BUFFER_SIZE] = {"two-byte"};
    u32 TwoByteStringLength = StringLength(TwoByteString);
    
    char PriOpcdString[MAX_BUFFER_SIZE] = {"pri_opcd"};
    u32 ProOpcdStringLength = StringLength(PriOpcdString);
    
    char EntryString[MAX_BUFFER_SIZE] = {"entry"};
    u32 EntryStringLength = StringLength(EntryString);
    
    char ExtraEntryString[MAX_BUFFER_SIZE] = {"exta_entry"};
    u32 ExtraEntryStringLength = StringLength(ExtraEntryString);
    
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
    
    char OpcodeIDString[MAX_BUFFER_SIZE] = {"opcode_id"};
    u32 OpcodeIDStringLength = StringLength(OpcodeIDString);
    
    
    char RexString[MAX_BUFFER_SIZE] = {"low_rex"};
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
    
    
    char * Ptr = 0;
    u32 Count = 0;
    
    char * At = Tokenizer->At;
    
    if(At <= Tokenizer->Last)
    {
        if(*At == '(')
        {
            Result = OpcodeType_OpcodeID;
            
            Ptr = At;
            
            while(*At != ')')
            {
                ++At;
                ++Count;
            }
            
            ++At;
            ++Count;
        }
        
        else if((*At == '/') && (*(At + 1) == '/'))
        {
            Result = OpcodeType_Comment;
            
            At += 2;
            Ptr = At;
            
            b32 EndOfComment = false;
            while(!EndOfComment)
            {
                if((*At != '\\') && (*(At + 1) == '\n'))
                {
                    EndOfComment = true;
                }
                
                ++At;
                ++Count;
            }
            
            Assert(*At == '\n');
            
            ++At;
            ++Count;
        }
        
        else if(IsGrammarCharacter(At))
        {
            Result = OpcodeType_Keyword;
            Ptr = At;
            
            while(IsGrammarCharacter(At))
            {
                ++At;
                ++Count;
            }
            
            
            if(
                StringsAreEqual(Ptr, Count, RexString, RexStringLength) ||
                StringsAreEqual(Ptr, Count, RegString, RegStringLength) ||
                StringsAreEqual(Ptr, Count, RMString, RMStringLength) ||
                StringsAreEqual(Ptr, Count, ModString, ModStringLength) ||
                StringsAreEqual(Ptr, Count, sreg2String, sreg2StringLength) ||
                StringsAreEqual(Ptr, Count, sreg3String, sreg3StringLength)
                )
            {
                Result = OpcodeType_Opcode;
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
            Result = OpcodeType_Keyword;
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
    FILE * OpcodeFile = fopen(Arguments[1], "rb");
    
    if(OpcodeFile)
    {
        memory_index FileSize = GetFileSize(OpcodeFile);
        
        char * FileBase = 0;
        FileBase = (char *)malloc(FileSize);
        
        memory_index FileBytesRead = fread (FileBase, 1, FileSize, OpcodeFile);
        Assert(FileBytesRead  == FileSize);
        
        if(FileBase)
        {
            
            meta_state MetaState = {};
            MetaState.STDOutHandle = STDOutHandle;
            
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

*/
            
            opcode_token LastElement = {};
            
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
            
            char ClosingParenString[MAX_BUFFER_SIZE] = {")"};
            u32 ClosingParenStringLength = StringLength(ClosingParenString);
            
            char ComaString[MAX_BUFFER_SIZE] = {","};
            u32 ComaStringLength = StringLength(ComaString);
            
            char ColonString[MAX_BUFFER_SIZE] = {";"};
            u32 ColonStringLength = StringLength(ColonString);
            
            char SpaceString[MAX_BUFFER_SIZE] = {" "};
            u32 SpaceStringLength = StringLength(SpaceString);
            
            char EndOfLineString[MAX_BUFFER_SIZE] = {"\n"};
            u32 EndOfLineStringLength = StringLength(EndOfLineString);
            
            char ZeroXString[MAX_BUFFER_SIZE] = {"0x"};
            u32 ZeroXStringLength = StringLength(ZeroXString);
            
            char ZeroFString[MAX_BUFFER_SIZE] = {"0F"};
            u32 ZeroFStringLength = StringLength(ZeroFString);
            
            char RexString[MAX_BUFFER_SIZE] = {"rex"};
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
            
            char PrefixString[MAX_BUFFER_SIZE] = {"pref"};
            u32 PrefixStringLength = StringLength(PrefixString);
            
            char SecOpcString[MAX_BUFFER_SIZE] = {"sec_opcd"};
            u32 SecOpcStringLength = StringLength(SecOpcString);
            
            char ExtOpcString[MAX_BUFFER_SIZE] = {"opcd_ext"};
            u32 ExtOpcStringLength = StringLength(ExtOpcString);
            
            char EndFileSectionOpcodeString[MAX_BUFFER_SIZE] = {"\tEndFileSection(FileManager);\n}"};
            u32 EndFileSectionOpcodeStringLength = StringLength(EndFileSectionOpcodeString);
            
            char BeginInstructionBitsString[MAX_BUFFER_SIZE] = {"\tBeginInstructionBits(FileManager);\n"}; 
            u32 BeginInstructionBitsStringLength = StringLength(BeginInstructionBitsString);
            
            char EndInstructionBitsString[MAX_BUFFER_SIZE] = {"\tEndInstructionBits(FileManager);\n"};
            u32 EndInstructionBitsStringLength = StringLength(EndInstructionBitsString);
            
            char CopyBitsString[MAX_BUFFER_SIZE] = {"\tCopyBitsToFile(FileManager, "};
            u32 CopyBitsStringLength = StringLength(CopyBitsString);
            
            char BitsIDFileString[MAX_BUFFER_SIZE] = {"BitsIDFile"};
            u32 BitsIDFileStringLength = StringLength(BitsIDFileString);
            
            opcode_tokenizer Tokenizer = {};
            InitializeOpcodeIDTokenizer(&Tokenizer, FileBase, SafeTruncateU64ToU32(FileSize));
            
            
            b32 ElementFound = true;
            
            /*
            
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0b11111111));
        CopyBitsToFile(&FileManager, mod);
        CopyBitsToFile(&FileManager, BitsIDFile(3, 0b101));
        CopyBitsToFile(&FileManager, rm);
        EndInstructionBits(&FileManager);
        
                        */
			
			
            char BeginFuncString[MAX_BUFFER_SIZE] = "internal void "; 
            u32 BeginFuncStringLength = StringLength(BeginFuncString);
			
			char CreateOpcodeIDS[MAX_BUFFER_SIZE] = "CreateOpcodeIDS_";
            u32 CreateOpcodeIDSLength = StringLength(CreateOpcodeIDS);
			
			char MiddleFuncString[MAX_BUFFER_SIZE] = "(file_manager * FileManager)\n{\n\n\tconst eff_bits mod = ZeroesFile(2, BitfieldType_mod);\n\tconst eff_bits reg = ZeroesFile(3, BitfieldType_reg);\n\tconst eff_bits rm = ZeroesFile(3, BitfieldType_rm);\n\tconst eff_bits tttn = ZeroesFile(4, BitfieldType_tttn);\n\tconst eff_bits eee = ZeroesFile(3, BitfieldType_eee);\n\tconst eff_bits sreg2 = ZeroesFile(2, BitfieldType_sreg2);\n\tconst eff_bits sreg3 = ZeroesFile(2, BitfieldType_sreg3);\n\tconst eff_bits s = ZeroesFile(1, BitfieldType_s);\n\tconst eff_bits low_rex = ZeroesFile(4, BitfieldType_low_rex);\n\n\tBeginFileSection(FileManager, ";
            u32 MiddleFuncStringLength = StringLength(MiddleFuncString);
			
			char FileSectionBits[MAX_BUFFER_SIZE] = "FileSection_bits_";
            u32 FileSectionBitsLength = StringLength(FileSectionBits);
			
			char EndFuncString[MAX_BUFFER_SIZE] = ");\n\n";
            u32 EndFuncStringLength = StringLength(EndFuncString);
            
            
            meta_WriteFile(&MetaState, BeginFuncString, BeginFuncStringLength);
            meta_WriteFile(&MetaState, CreateOpcodeIDS, CreateOpcodeIDSLength);
            meta_WriteFile(&MetaState, Arguments[2], StringLength(Arguments[2]));
            meta_WriteFile(&MetaState, MiddleFuncString, MiddleFuncStringLength);
            meta_WriteFile(&MetaState, FileSectionBits, FileSectionBitsLength);
            meta_WriteFile(&MetaState, Arguments[2], StringLength(Arguments[2]));
            meta_WriteFile(&MetaState, EndFuncString, EndFuncStringLength);
            
            opcode_type LastOpcodeType = OpcodeType_Invalid;
            
            while(ElementFound)
            {
                opcode_token Token = {};
                opcode_type Type = GetNextOpcodeIDToken(&Tokenizer, &Token.Base, &Token.Count);
                
                switch(Type)
                {
                    case OpcodeType_Invalid:
                    {
                        //NOTE(Alex): Invalid Token
                        ElementFound = false;
                    }break;
                    
                    case OpcodeType_Keyword:
                    {
                        if((LastOpcodeType == OpcodeType_Opcode) || (LastOpcodeType == OpcodeType_OpcodeID))
                        {
                            meta_WriteFile(&MetaState, EndInstructionBitsString, EndInstructionBitsStringLength);
                            meta_WriteFile(&MetaState, EndOfLineString, EndOfLineStringLength);
                        }
                        
                        if(
                            StringsAreEqual(Token.Base, Token.Count, OpcodeIDString, OpcodeIDStringLength) ||
                            StringsAreEqual(Token.Base, Token.Count, ExtraOpcodeIDString, ExtraOpcodeIDStringLength)
                            
                            )
                        {
                            meta_WriteFile(&MetaState, BeginInstructionBitsString, BeginInstructionBitsStringLength);
                        }
                        
                    }break;
                    
                    case OpcodeType_Comment:
                    {
                        if((LastOpcodeType == OpcodeType_Opcode) || (LastOpcodeType == OpcodeType_OpcodeID))
                        {
                            meta_WriteFile(&MetaState, EndInstructionBitsString, EndInstructionBitsStringLength);
                            meta_WriteFile(&MetaState, EndOfLineString, EndOfLineStringLength);
                        }
                        
                    }break;
                    
                    case OpcodeType_Opcode:
                    {
                        meta_WriteFile(&MetaState, CopyBitsString, CopyBitsStringLength);
                        meta_WriteFile(&MetaState, Token.Base, Token.Count);
                        meta_WriteFile(&MetaState, ClosingParenString, ClosingParenStringLength);
                        meta_WriteFile(&MetaState, ColonString, ColonStringLength);
                        meta_WriteFile(&MetaState, EndOfLineString, EndOfLineStringLength);
                    }break;
                    
                    case OpcodeType_OpcodeID:
                    {
                        meta_WriteFile(&MetaState, CopyBitsString, CopyBitsStringLength);
                        meta_WriteFile(&MetaState, BitsIDFileString, BitsIDFileStringLength);
                        meta_WriteFile(&MetaState, Token.Base, Token.Count);
                        meta_WriteFile(&MetaState, ClosingParenString, ClosingParenStringLength);
                        meta_WriteFile(&MetaState, ColonString, ColonStringLength);
                        meta_WriteFile(&MetaState, EndOfLineString, EndOfLineStringLength);
                        
                    }break;
                    
                    InvalidDefaultCase;
                };
                
                LastOpcodeType = Type;
            }
            
            meta_WriteFile(&MetaState, EndFileSectionOpcodeString, EndFileSectionOpcodeStringLength);
            
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
            
            
            
            free(FileBase);
            
            //TODO(Alex): Use the xmltree to parse the xmlfile and select the attributes that you want from it 
            
        }
        
        
        fclose(OpcodeFile);
    }
    
}

