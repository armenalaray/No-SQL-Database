//////////////////////////////////////////////////////
//
//Author: Alejandro Armenta 
//Date: 2019
//File: xml_tree.cpp
//Company: 
//
//All rights reserved.
//
//////////////////////////////////////////////////////

#if 0
inline memory_index GetTokenCount(xml_token * Token)
{
    memory_index Result = (memory_index)Token->Last - (memory_index)Token->Base + 1;
    return Result;
}
#endif


inline void
ClearXMLToken(xml_token * out_Token)
{
    out_Token->Base = 0;
    out_Token->Count = 0;
}


inline b32 
TokensAreEqual(xml_token * A_, xml_token * B_)
{
    Assert(A_ && B_);
    
    b32 Result = false;
    
    if(A_->Count == B_->Count)
    {
        char * A = A_->Base;
        char * B = B_->Base;
        
        memory_index Count = 0;
        while((Count < A_->Count) && (*A == *B))
        {
            ++A;
            ++B;
            ++Count;
        }
        
        Result = (Count >= A_->Count);
    }
    
    return Result;
    
}



inline void
InitXMLTokenizerLastPtr(xml_tokenizer * out_Tokenizer, char * Base, char * Last)
{
    out_Tokenizer->Base = Base;
    out_Tokenizer->At = out_Tokenizer->Base;
    out_Tokenizer->Last = Last;
}

inline void
InitXMLTokenizerCount(xml_tokenizer * out_Tokenizer, char * Base, memory_index Size)
{
    char * Last = Base + (Size - 1);
    InitXMLTokenizerLastPtr(out_Tokenizer, Base, Last);
}

internal b32 
IsXMLComment(xml_token * Token)
{
    Assert(Token);
    b32 Result = false;
    
    memory_index TokenCount = Token->Count;
    
    if(TokenCount >= 5)
    {
        
        char * CommentStart = Token->Base;
        char * CommentEnd = Token->Base + (Token->Count - 2);
        
        if((*(CommentStart + 0) == '!') &&
           (*(CommentStart + 1) == '-') &&
           (*(CommentStart + 2) == '-') &&
           
           (*(CommentEnd + 0) == '-') &&
           (*(CommentEnd + 1) == '-')
           
           )
        {
            Result = true;
        }
    }
    
    return Result;
}

internal b32 
IsXMLComment(xml_tokenizer * Tokenizer, char * At)
{
    Assert(At);
    b32 Result = false;
    
    if((At + 3) <= Tokenizer->Last)
    {
        if((*(At + 0) == '<') &&
           (*(At + 1) == '!') &&
           (*(At + 2) == '-') &&
           (*(At + 3) == '-')
           
           )
        {
            Result = true;
        }
    }
    
    return Result;
}



internal b32
IsValidXMLCharacter(xml_tokenizer * Tokenizer, char * At)
{
    Assert(At);
    b32 Result = false;
    
    if(IsAlphanumeric(At) ||
       (*At == '-') ||
       (*At == '_') ||
       (*At == '.')
       
       )
    {
        Result = true;
    }
    
    return Result;
    
}


#if 0
internal b32
IsValidXMLText(xml_tokenizer * Tokenizer, char * At)
{
    Assert(At);
    b32 Result = false;
    
    if(IsAlphanumeric(At) ||
       (*At == '-') ||
       (*At == '_') ||
       (*At == '.')
       
       )
    {
        Result = true;
    }
    
    return Result;
    
}
#endif



inline void
CleanWhiteSpace(xml_tokenizer * Tokenizer)
{
    char * At = Tokenizer->At;
    
    while(
        (*At == '\t') || 
        (*At == '\n') || 
        (*At == '\r') ||
        (*At == ' ')
        )
    {
        ++At;
    }
    
    Tokenizer->At = At;
    
}

inline void
CleanWhiteSpace(xml_tokenizer * Tokenizer, char ** At)
{
    while(
        (**At == '\t') || 
        (**At == '\n') || 
        (**At == '\r') ||
        (**At == ' ')
        )
    {
        ++*At;
    }
}


inline b32 
IsOpeningGuillemet(char * At)
{
    b32 Result = (*At == '<');
    return Result;
}

inline b32
IsClosingGuillemet(char * At)
{
    b32 Result = (*At == '>');
    return Result;
}

inline b32 
IsQuotationMark(char * At)
{
    b32 Result = (*At == '"');
    return Result;
}

inline xml_token_type
GetNextXMLToken(xml_tokenizer * Tokenizer, xml_token * out_Token)
{
    
    CleanWhiteSpace(Tokenizer);
    
    char * At = Tokenizer->At;
    b32 Result = false;
    
    xml_token_type Type = XMLType_Invalid;
    
    char * Base = 0;
    u32 Count = 0;
    
    if((At <= Tokenizer->Last) && !Base)
    {
        if(IsOpeningGuillemet(At))
        {
            if(IsXMLComment(Tokenizer, At))
            {
                //NOTE(Alex): Comment
                
                At += 4;
                Base = At;
                Type = XMLType_Comment;
                
                while(true)
                {
                    if((*(At + 0) == '-') &&
                       (*(At + 1) == '-') &&
                       (*(At + 2) == '>'))
                    {
                        At += 3;
                        break;
                    }
                    else
                    {
                        ++At;
                        ++Count;
                    }
                }
            }
            else
            {
                ++At;
                
                if(*At == '/')
                {
                    //NOTE(Alex): Closing Tag
                    Type = XMLType_ClosingTag;
                    ++At;
                }
                else
                {
                    //NOTE(Alex): Opening Tag
                    Type = XMLType_OpeningTag;
                    Tokenizer->OpeningTag = true;
                }
                
                Base = At;
                
                while(IsValidXMLCharacter(Tokenizer, At))
                {
                    ++At;
                    ++Count;
                }
                
                CleanWhiteSpace(Tokenizer, &At);
                
                char * Ptr = At;
                
                if(*Ptr == '/')
                {
                    Type = XMLType_SelfClosingTag;
                    ++Ptr;
                    Assert(*Ptr == '>');
                    
                    At = Ptr;
                }
                else
                {
                    while(*Ptr != '>')
                    {
                        ++Ptr;
                    }
                    
                    if(*(Ptr - 1) == '/')
                    {
                        Type = XMLType_SelfClosingTag;
                    }
                }
                
            }
        }
        
        else if(Tokenizer->OpeningTag)
        {
            
            if(IsQuotationMark(At))
            {
                //NOTE(Alex): AttrValue
                ++At;
                
                Type = XMLType_AttrValue;
                Base = At;
                
                while(!IsQuotationMark(At))
                {
                    ++At;
                    ++Count;
                }
                
                ++At;
                
                CleanWhiteSpace(Tokenizer, &At);
                
                if(*At == '/')
                {
                    ++At;
                    Assert(*At == '>');
                }
            }
            else
            {
                //NOTE(Alex): AttrName
                Type = XMLType_AttrName;
                Base = At;
                
                while(IsValidXMLCharacter(Tokenizer, At))
                {
                    ++At;
                    ++Count;
                }
                
                CleanWhiteSpace(Tokenizer, &At);
                Assert(*At == '=');
                ++At;
            }
            
        }
        
        else 
        {
            //NOTE(Alex): Text
            Type = XMLType_Text;
            Base = At;
            while(*At != '<')
            {
                ++At;
                ++Count;
            }
        }
        
        
        if(IsClosingGuillemet(At))
        {
            Tokenizer->OpeningTag = false;
            ++At;
        }
        
        
        
        if(Type != XMLType_Invalid)
        {
            Result = true;
            out_Token->Base = Base;
            out_Token->Count = Count;
        }
        
    }
    
    
    Tokenizer->At = At;
    
    return Type;
}


/*

Element names are case-sensitive
Element names must start with a letter or underscore
Element names cannot start with the letters xml (or XML, or Xml, etc)
Element names can contain letters, digits, hyphens, underscores, and periods
Element names cannot contain spaces

*/

#if 0
internal void
GetXMLTag(xml_token * Element, xml_token * out_Tag)
{
    out_Tag->Base = Element->Base;
    
    char * At = out_Tag->Base;
    while(*At != ' ')
    {
        ++At;
    }
    
    out_Tag->Last = (At - 1);
}
#endif

//NOTE(Alex):Initialze the XML tree

internal void 
InitXMLTree(meta_state * MetaState, xml_tree * out_XMLTree)
{
    out_XMLTree->ElementCount = 0;
    out_XMLTree->FirstElement = 0;
    out_XMLTree->CurrentElementIndex = 0;
    out_XMLTree->CurrentAttrName = 0;
}


internal b32
FindElement(meta_state * State, xml_tree * XMLTree, xml_token * Tag)
{
    b32 Result = false;
    
    for(u32 Index = 0;
        Index < XMLTree->ElementCount;
        ++Index)
    {
        xml_element * Element = XMLTree->FirstElement + Index;
        if(TokensAreEqual(&Element->Tag , Tag))
        {
            XMLTree->CurrentElementIndex = Index;
            Result = true;
        }
    }
    
    if(!Result)
    {
        XMLTree->CurrentElementIndex = XMLTree->ElementCount;
    }
    
    return Result;
}


internal b32
IsNotClosingElement(xml_tree * XMLTree, xml_token * Tag)
{
    b32 Result = false;
    Result = (*Tag->Base != '\\');
    return Result;
}

internal void
PushTagToTree(meta_state * MetaState, xml_tree * XMLTree, xml_token * Tag)
{
    Assert(Tag);
    
    if(!FindElement(MetaState, XMLTree, Tag))
    {
        xml_element * Element = PushStruct(&MetaState->ElementArena.Arena, xml_element);
        Element->Tag = *Tag;
        Element->FirstAttrName = 0;
        
        if(!XMLTree->FirstElement)
        {
            XMLTree->FirstElement = Element;
        }
        
        ++XMLTree->ElementCount;
    }
}

internal void
PopXMLTree(meta_state * MetaState, xml_tree * XMLTree)
{
}


internal b32
FindAttrNameOnCurrentElement(meta_state * MetaState, xml_tree * XMLTree, xml_token * AttrName)
{
    b32 Result = false;
    xml_element * Element = XMLTree->FirstElement + XMLTree->CurrentElementIndex;
    
    xml_attr_name * Comparand = Element->FirstAttrName;
    while(Comparand && !Result)
    {
        if(TokensAreEqual(&Comparand->AttrName, AttrName))
        {
            XMLTree->CurrentAttrName = Comparand;
            Result = true;
        }
        
        Comparand = Comparand->Next;
    }
    
    return Result;
}


internal void
PushAttrNameOnCurrentElement(meta_state * MetaState, xml_tree * XMLTree, xml_token * AttrName)
{
    Assert(AttrName);
    Assert(XMLTree->CurrentElementIndex < XMLTree->ElementCount);
    
    if(!FindAttrNameOnCurrentElement(MetaState, XMLTree, AttrName))
    {
        xml_element * Element = XMLTree->FirstElement + XMLTree->CurrentElementIndex;
        xml_attr_name * New = PushStruct(&MetaState->AttrNamesArena.Arena, xml_attr_name);
        
        if(!Element->FirstAttrName)
        {
            New->Next = 0;
            Element->FirstAttrName = New;
        }
        else
        {
            New->Next = Element->FirstAttrName;
            Element->FirstAttrName = New;
        }
        
        New->AttrName = *AttrName;
        New->FirstAttrValue = 0;
        
        XMLTree->CurrentAttrName = New;
    }
}

internal b32
FindAttrValueOnCurrentAttrName(meta_state * MetaState, xml_tree * XMLTree, xml_token * AttrValue)
{
    b32 Result = false;
    xml_attr_name * AttrName = XMLTree->CurrentAttrName;
    
    xml_attr_value * Comparand = AttrName->FirstAttrValue;
    while(Comparand && !Result)
    {
        if(TokensAreEqual(&Comparand->AttrValue, AttrValue))
        {
            Result = true;
        }
        
        Comparand = Comparand->Next;
    }
    
    return Result;
}

internal void
PushAttrValueOnCurrentAttrName(meta_state * MetaState, xml_tree * XMLTree, xml_token * AttrValue)
{
    
    Assert(AttrValue);
    Assert(XMLTree->CurrentElementIndex < XMLTree->ElementCount);
    
    if(!FindAttrValueOnCurrentAttrName(MetaState, XMLTree, AttrValue))
    {
        xml_attr_name * AttrName = XMLTree->CurrentAttrName;
        xml_attr_value * New = PushStruct(&MetaState->AttrValuesArena.Arena, xml_attr_value);
        
        if(!AttrName->FirstAttrValue)
        {
            New->Next = 0;
            AttrName->FirstAttrValue = New;
        }
        else
        {
            New->Next = AttrName->FirstAttrValue;
            AttrName->FirstAttrValue= New;
        }
        
        New->AttrValue = *AttrValue;
    }
    
}


internal void
BeginAttrFetch(xml_tokenizer * Tokenizer, xml_token * Element)
{
    
}

internal b32
GetNextXMLElementAttribute(xml_tokenizer * Tokenizer, xml_token * out_Attr)
{
    b32 Result = false;
    
    Assert(out_Attr);
    
    char * At = Tokenizer->At;
    
    while(At <= Tokenizer->Last)
    {
        if(*At != ' ')
        {
            ;
        }
        
        ++At;
    }
    
    ++At;
    
    while(At <= Tokenizer->Last)
    {
        
        
        //PushAttrNameOnTag();
    }
    
    Tokenizer->At = At;
    return Result;
    
}




internal b32
GetNextTreeElementAttribute(xml_token * out_Attr)
{
    b32 Result = false;
    return Result;
}

internal void
GetXMLAttrName(xml_token * Attr, xml_token * out_AttrName)
{
    
}


internal b32
FindAttrNameOnTag(xml_tree * XMLTree, xml_token * Tag, xml_token * AttrName)
{
    b32 Result = false;
    return Result;
}

internal void 
GetXMLAttrValue(xml_token * Attr, xml_token * out_AttrValue)
{
    
}

internal b32
FindAttrValueOnAttrName(xml_tree * XMLTree, xml_token * Tag, xml_token * AttrName, xml_token * AttrValue)
{
    b32 Result = false;
    return Result;
}


//NOTE(Alex): InitList functions 

internal void
InitList(list * out_List)
{
    //out_List->FirstElement
}

internal b32
FindStringOnList(meta_state * MetaState, list * List, char * Text, memory_index Size)
{
    b32 Result = false;
    list_element * Element = List->FirstElement;
    
    while(Element && !Result)
    {
        if(StringsAreEqual(Element->Token.Base, Element->Token.Count, Text, Size))
        {
            Result = true;
        }
        
        Element = Element->Next;
    }
    
    return Result;
}

internal void
PushTextToList(meta_state * MetaState, list * List, char * Text, u32 Size)
{
    if(!FindStringOnList(MetaState, List, Text, Size))
    {
        list_element * Element = PushStruct(&MetaState->ListsArena.Arena, list_element);
        if(!List->FirstElement)
        {
            Element->Next = 0;
            List->FirstElement = Element;
        }
        else
        {
            Element->Next = List->FirstElement;
            List->FirstElement = Element;
        }
        
        Element->Token.Base = Text;
        Element->Token.Count = Size;
    }
}


