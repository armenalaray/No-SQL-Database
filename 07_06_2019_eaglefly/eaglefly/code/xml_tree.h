//////////////////////////////////////////////////////
//
//Author: Alejandro Armenta 
//Date: 2019
//File: xml_tree.h
//Company: 
//
//All rights reserved.
//
//////////////////////////////////////////////////////

#ifndef XML_TREE_H
#define XML_TREE_H


#define MAX_ELEMENT_COUNT 1024
#define MAX_ATTR_COUNT 1024


//NOTE(Alex): xml info  data structures


enum xml_token_type
{
    XMLType_Invalid,
    XMLType_Comment,
    XMLType_OpeningTag,
    XMLType_ClosingTag,
    XMLType_AttrName,
    XMLType_AttrValue,
    XMLType_Text,
    XMLType_SelfClosingTag,
    
    XMLType_Count,
};



struct xml_token
{
    u32 Count;
    char * Base;
};


struct xml_tokenizer
{
    b32 OpeningTag;
    char * Base;
    char * At;
    char * Last;
};



//NOTE(Alex): xml tree data structure

struct xml_attr_value
{
    xml_token AttrValue;
    xml_attr_value * Next;
};

struct xml_attr_name
{
    xml_token AttrName;
    xml_attr_value * FirstAttrValue;
    xml_attr_name * Next;
};

struct xml_element
{
    xml_token Tag;
    xml_attr_name * FirstAttrName;
};

struct xml_tree
{
    memory_index ElementCount;
    xml_element * FirstElement;
    
    memory_index CurrentElementIndex;
    xml_attr_name * CurrentAttrName;
    
};

//NOTE(Alex): lists

struct list_element
{
    xml_token Token;
    list_element * Next;
};

struct list
{
    list_element * FirstElement;
};






#endif

