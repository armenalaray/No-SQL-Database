//////////////////////////////////////////////////////
//
//Author: Alejandro Armenta 
//Date: 2019
//File: eaglefly_string.h
//Company: 
//
//All rights reserved.
//
//////////////////////////////////////////////////////


#ifndef EAGLEFLY_STRING_H
#define EGALEFLY_STRING_H

#define NIBBLE_COUNT_32 8
#define NIBBLE_COUNT_64 16
#define NIBBLE_COUNT_64_PLUS1 17

#define BITS_PER_NIBBLE 4
#define HEX_DIGIT_COUNT 16

//TODO(Alex): Remove this!
#define MAX_BUFFER_SIZE 1024


//NOTE(Alex): text processing data structures

enum regexp_result
{
    RegExp_normalstring = 0,
    RegExp_invalidexpression,
    RegExp_range,
    RegExp_asterisk,
    RegExp_ellipsis,
    
    Regexp_count,
};

enum regexp_data_type
{
    regexp_data_indefinite,
    regexp_data_range,
    regexp_data_value,
    
    regexp_data_count,
};

struct regexp_data
{
    //NOTE(Alex): SymbolCount = -1 means any number of them!
    s32 SymbolCount;
    regexp_data_type Type;
    
    union
    {
        struct
        {
            char OpeningSymbol;
            char ClosingSymbol;
        };
        
        struct
        {
            char MinValue;
            char MaxValue;
        };
        
        struct
        {
            char Unused0;
            char Value;
        };
    };
};

struct regexp_support
{
    b32 IsInitialized;
    //NOTE(Alex): Source Parameters
    char * SourceBase;
    char * SourceAt;
    char * SourceLast;
    
    //NOTE(Alex): RegExp data structure
    u32 RegExpDataArrayCount;
    regexp_data RegExpDataArray[64];
    
    //NOTE(Alex): RegExp Parameters
    char * RegExpBase;
    char * RegExpAt;
    char * RegExpLast;
    
};

struct regexp_token
{
    u32 Count;
    char * Base;
};

struct string
{
    u32 mem_size;
    u32 count;
    char * buffer;
};


struct token
{
    char * Base;
    u32 Count;
};

struct tokenizer
{
    char * Base;
    char * At;
    char * Last;
};





#endif