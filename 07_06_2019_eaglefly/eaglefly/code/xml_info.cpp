//////////////////////////////////////////////////////
//
//Author: Alejandro Armenta 
//Date: 2019
//File: xml_info.cpp
//Company: 
//
//All rights reserved.
//
//////////////////////////////////////////////////////

/*
NOTE(Alex): 

meta_tables.cpp

This will generate the code that generates the eaglefly_instruction_tables.eflyfile  and it also 
will generate the InstructionStream for the disassembler 

in_files:

x86_64_tables.xml - x86_64 specificcation xml file

out_files:

eflyfile_meta.cpp - is where all the code to generate the instruction_tables will be
instruction_stream.cpp - is where the instruction stream testing for disasssembler will be generated


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




*/

#include "Windows.h"
#include "stdio.h"
#include "eaglefly_platform.h"
#include "instruction_infos_filter.h"
#include "eaglefly_string.cpp"
#include "xml_tree.cpp"

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



int main(int Argcount, char ** Arguments)
{
    
    HANDLE ScreenBuffer = {};
    
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
            SubArena(&MetaState->MetaArena, &MetaState->ListsArena, Megabytes(256));
            
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

TODO(Alex): do we want to have a categorization system? 
so that new virtual tags could be added to the xml_tree as pleased?

*/
            //<grp1>gen</grp1>
            
            
            char dstString[MAX_BUFFER_SIZE] = {"dst"};
            u32 dstStringLength = StringLength(dstString);
            
            char srcString[MAX_BUFFER_SIZE] = {"src"};
            u32 srcStringLength = StringLength(srcString);
            
            char aString[MAX_BUFFER_SIZE] = {"a"};
            u32 aStringLength = StringLength(aString);
            
            
            list Group1List = {};
            list dstList = {};
            list srcList = {};
            list aList = {};
            
            //BeginList(&Group1List);
            
            xml_token LastElement = {};
            
            b32 ElementFound = true;
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
                        PushTagToTree(MetaState, &XMLTree, &Token);
                    }break;
                    
                    case XMLType_SelfClosingTag:
                    {
                    }break;
                    
                    case XMLType_ClosingTag:
                    {
                    }break;
                    
                    case XMLType_Comment:
                    {
                        
                    }break;
                    
                    case XMLType_AttrName:
                    {
                        PushAttrNameOnCurrentElement(MetaState, &XMLTree, &Token);
                    }break;
                    
                    case XMLType_AttrValue:
                    {
                        PushAttrValueOnCurrentAttrName(MetaState, &XMLTree, &Token);
                    }break;
                    
                    case XMLType_Text:
                    {
                        if(StringsAreEqual(LastElement.Base, LastElement.Count, dstString, dstStringLength))
                        {
                            PushTextToList(MetaState, &dstList, Token.Base, Token.Count);
                        }
                        
                        if(StringsAreEqual(LastElement.Base, LastElement.Count, srcString, srcStringLength))
                        {
                            PushTextToList(MetaState, &srcList, Token.Base, Token.Count);
                        }
                        
                        if(StringsAreEqual(LastElement.Base, LastElement.Count, aString, aStringLength))
                        {
                            PushTextToList(MetaState, &aList, Token.Base, Token.Count);
                        }
                        
                    }break;
                    
                    InvalidDefaultCase;
                };
            }
            
            u32 TokenCharsWritten = 0;
            
            
            {
                WriteFile(STDOutHandle, (void*)dstString, dstStringLength, (LPDWORD)&TokenCharsWritten, 0);
                WriteFile(STDOutHandle, (void*)"\n", 1, (LPDWORD)&TokenCharsWritten, 0);
                
                list_element * ListElement = dstList.FirstElement;
                while(ListElement)
                {
                    WriteFile(STDOutHandle, (void*)"\t", 1, (LPDWORD)&TokenCharsWritten, 0);
                    WriteFile(STDOutHandle, (void*)ListElement->Token.Base, SafeTruncateU64ToU32(ListElement->Token.Count), (LPDWORD)&TokenCharsWritten, 0);
                    WriteFile(STDOutHandle, (void*)"\n", 1, (LPDWORD)&TokenCharsWritten, 0);
                    
                    ListElement = ListElement->Next;
                }
            }
            
            {
                WriteFile(STDOutHandle, (void*)srcString, srcStringLength, (LPDWORD)&TokenCharsWritten, 0);
                WriteFile(STDOutHandle, (void*)"\n", 1, (LPDWORD)&TokenCharsWritten, 0);
                
                list_element * ListElement = srcList.FirstElement;
                while(ListElement)
                {
                    WriteFile(STDOutHandle, (void*)"\t", 1, (LPDWORD)&TokenCharsWritten, 0);
                    WriteFile(STDOutHandle, (void*)ListElement->Token.Base, SafeTruncateU64ToU32(ListElement->Token.Count), (LPDWORD)&TokenCharsWritten, 0);
                    WriteFile(STDOutHandle, (void*)"\n", 1, (LPDWORD)&TokenCharsWritten, 0);
                    
                    ListElement = ListElement->Next;
                }
            }
            
            {
                WriteFile(STDOutHandle, (void*)aString, aStringLength, (LPDWORD)&TokenCharsWritten, 0);
                WriteFile(STDOutHandle, (void*)"\n", 1, (LPDWORD)&TokenCharsWritten, 0);
                
                list_element * ListElement = aList.FirstElement;
                while(ListElement)
                {
                    WriteFile(STDOutHandle, (void*)"\t", 1, (LPDWORD)&TokenCharsWritten, 0);
                    WriteFile(STDOutHandle, (void*)ListElement->Token.Base, SafeTruncateU64ToU32(ListElement->Token.Count), (LPDWORD)&TokenCharsWritten, 0);
                    WriteFile(STDOutHandle, (void*)"\n", 1, (LPDWORD)&TokenCharsWritten, 0);
                    
                    ListElement = ListElement->Next;
                }
            }
            
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
                        
                        AttrValue = AttrValue->Next;
                    }
                    
                    AttrName = AttrName->Next;
                }
                
                
            }
            
            
            free(XMLBase);
            
            //TODO(Alex): Use the xmltree to parse the xmlfile and select the attributes that you want from it 
            
        }
        
        
        fclose(XMLFile);
    }
    
    
    //SetConsoleActiveScreenBuffer(STDOutHandle);
    //CloseHandle(ScreenBuffer);
    
}


#if 0    
Win32_OpenActiveScreenBuffer(&ScreenBuffer);
Win32_CreateConsoleScreenBuffer(&ScreenBuffer);
SetConsoleActiveScreenBuffer(ScreenBuffer);

b32 OutputToConsole = true;
DWORD OutputMode = {}; 
if(GetConsoleMode(STDOutHandle, &OutputMode))
{
    //NOTE(alex): ScreenBuffer;
}
else
{
    
    
    OutputToConsole = false;
    //char * Message = "Not a console";
    //u32 MessageLength = StringLength(Message);
    //u32 TokenCharsWritten;
    //WriteFile(STDOutHandle, (void*)Message, MessageLength, (LPDWORD)&TokenCharsWritten,0);
    //printf("Not a console");
}
#endif


#if 0                
xml_token Tag = {};
GetXMLTag(&Element, &Tag);
PushTagToTree(MetaState, &XMLTree, &Tag);

xml_tokenizer AttrTokenizer = {};
InitXMLTokenizerLastPtr(&AttrTokenizer, Element.Base, Element.Last);


b32 AttrFound = true;
while(AttrFound)
{
    xml_token Attr;
    AttrFound = GetNextXMLElementAttribute(&AttrTokenizer, &Attr);
    
    if(AttrFound)
    {
        xml_token AttrName = {};
        GetXMLAttrName(&Attr, &AttrName);
        PushAttrNameOnTag(&XMLTree, &Tag, &AttrName);
        
        xml_token AttrValue = {};
        GetXMLAttrValue(&Attr, &AttrValue);
        PushAttrValueOnAttrName(&XMLTree, &Tag, &AttrName, &AttrValue);
    }
}
#endif


