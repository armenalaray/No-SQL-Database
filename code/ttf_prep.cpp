/*

Alejandro Armenta

TTF_Parser

- I'll rasterize and cache font glyphs into a bitmap pack, that the debugger will use, 
- We will use a common range of glyph sizes 6 - 30 codepoints? 

*/


#include "Windows.h"
#include "eaglefly_platform.h"
#include "ttf_prep.h"

#define STB_TRUETYPE_IMPLEMENTATION 
#include "stb_truetype.h"


#if PLATFORM_MSVC

internal void * 
Win32AllocateMemory(memory_index Size)
{
    void * Result = 0;
    //TODO(Alex): Alignment?
    //Assert(IsPower2(Alignment));
    if(Size)
    {
        Result = VirtualAlloc(0, Size, MEM_RESERVE|MEM_COMMIT, PAGE_READWRITE); 
    }
    
    return Result;
}

internal void
Win32DeallocateMemory(void * Memory)
{
    if(Memory)
    {
        VirtualFree(Memory, 0, MEM_RELEASE);
    }
}


WRITE_ENTIRE_FILE(Win32WriteEntireFile)
{
    b32 Result = false;
    HANDLE Handle = CreateFileA(FileName,
                                GENERIC_WRITE,
                                FILE_SHARE_WRITE,
                                0,
                                OPEN_EXISTING,
                                FILE_ATTRIBUTE_NORMAL,
                                0);
    if(Handle)
    {
        DWORD BytesWritten = 0;
        if(WriteFile(Handle, Data, BytesToWrite, &BytesWritten, 0))
        {
            Result = true;
        }
        else
        {
            //TODO(Alex): Logging
        }
        
        CloseHandle(Handle);
    }
    else
    {
        //TODO(Alex): Check if ERROR_FILE_NOT_FOUND 
    }
    
    return Result;
}

READ_ENTIRE_FILE(Win32ReadEntireFile)
{
    debug_file_content Result = {};
    HANDLE Handle = CreateFileA(FileName,
                                GENERIC_READ,
                                FILE_SHARE_READ,
                                0,
                                OPEN_EXISTING,
                                FILE_ATTRIBUTE_NORMAL,
                                0);
    if(Handle)
    {
        LARGE_INTEGER U64Size = {};
        if(GetFileSizeEx(Handle, &U64Size))
        {
            u32 U32Size = TruncateU64ToU32(U64Size.QuadPart);
            DWORD BytesRead = 0;
            
            void * Content = Win32AllocateMemory(U32Size);
            if(ReadFile(Handle, Content, U32Size, &BytesRead,0) && 
               (BytesRead == U32Size))
            {
                Result.Content = Content;
                Result.Size = U32Size;
            }
            else
            {
                Win32DeallocateMemory(Content);
            }
        }
        else
        {
            //TODO(Alex): logging
        }
        
        CloseHandle(Handle);
    }
    else
    {
        //TODO(Alex): Check if ERROR_FILE_NOT_FOUND 
    }
    
    return Result;
}
#endif


#define TTF_U32(a,b,c,d) (u32)(((a) << 24) | ((b) << 16) | ((c) << 8) | ((d) << 0))
#define TTF_U16(a,b) (u16)(((a) << 8) | ((b) << 0))

#define CAST_U32(Ptr)  (u32*)Ptr
#define CAST_U16(Ptr)  (u16*)Ptr

#define MoveByTypeSize(Ptr, Count, type) Ptr = (type*)Ptr + Count

inline u16
GetNextWORD(ttf_state * TTFState)
{
    u16 Result = TTF_U16(*(TTFState->At + 0), *(TTFState->At + 1));
    TTFState->At += 2;
    return Result;
}


inline u32
GetNextDWORD(ttf_state * TTFState)
{
    u32 Result = TTF_U32(*(TTFState->At + 0),
                         *(TTFState->At + 1),
                         *(TTFState->At + 2),
                         *(TTFState->At + 3));
    
    TTFState->At += 4;
    return Result;
}

internal table_head 
ParseTTFTableHeader(ttf_state * TTFState, u32 Tag)
{
    table_head Result = 
    {
        TTF_U32(*(TTFState->At + 0),
                *(TTFState->At + 1),
                *(TTFState->At + 2),
                *(TTFState->At + 3)),
        TTF_U32(*(TTFState->At + 4),
                *(TTFState->At + 5),
                *(TTFState->At + 6),
                *(TTFState->At + 7)),
        TTF_U32(*(TTFState->At + 8),
                *(TTFState->At + 9),
                *(TTFState->At + 10),
                *(TTFState->At + 11)),
        TTF_U32(*(TTFState->At + 12),
                *(TTFState->At + 13),
                *(TTFState->At + 14),
                *(TTFState->At + 15))
    };
    
    
    return Result;
}

internal u32 
CalcTableChecksum(u32 * Entry, u32 TableSize)
{
    u32 Result = 0;
    u32 LongCount = (TableSize + 3) / 4;
    while (LongCount-- > 0)
    {
        Result += *Entry++;
    }
    return Result;
}

/*
Font tables can appear in any order 
We should check ALWAYS if a table exists

Required Tables
'cmap'	character to glyph mapping
'glyf'	glyph data
'head'	font header
'hhea'	horizontal header
'hmtx'	horizontal metrics
'loca'	index to location
'maxp'	maximum profile
'name'	naming
'post'	PostScript

First table Font Table 
*/


#if 1
int
main(int ArgCount, char ** Args)
{
    
    
}

#else
int 
main(int ArgCount, char ** Args)
{
#if PLATFORM_MSVC
    debug_file_content TTFContent = Win32ReadEntireFile("C:/Windows/Fonts/liberation-mono.ttf");
#endif
    
    u32 TableTags[] = 
    {
        TTF_U32('c','m','a','p'),//character to glyph mapping
        TTF_U32('g','l','y','f'),//glyph data
        TTF_U32('h','e','a','d'),//font header
        TTF_U32('h','h','e','a'),//horizontal header
        TTF_U32('h','m','t','x'),//horizontal metrics
        TTF_U32('l','o','c','a'),//index to location
        TTF_U32('m','a','x','p'),// maximum profile
        TTF_U32('n','a','m','e'),//naming
        TTF_U32('p','o','s','t'),//PostScript
    };
    
    ttf_state TTFState = {};
    TTFState.At = (char*)TTFContent.Content; 
    
    if(TTFState.At)
    {
        //NOTE(Alex): 0x00010000  Windows only, 'true' ios and osx only  
        if(GetNextDWORD(&TTFState) == 0x00010000)
        {
            TTFState.TableCount = (u32)GetNextWORD(&TTFState);
            //TODO(Alex): binary search?
            TTFState.At += sizeof(u16) * 3;
            
            for(u32 TableIndex = 0;  
                TableIndex < TTFState.TableCount;
                ++TableIndex)
            {
                u32 Tag = TTF_U32(*(TTFState.At + 0),
                                  *(TTFState.At + 1),
                                  *(TTFState.At + 2),
                                  *(TTFState.At + 3));
                for(u32 TagIndex = 0;
                    TagIndex < ArrayCount(TableTags);
                    ++TagIndex)
                {
                    //NOTE(Alex): Could tables be repeated in a file?
                    if(Tag == TableTags[TagIndex])
                    {
                        table_head Head = ParseTTFTableHeader(&TTFState,Tag);
                        //NOTE(Alex): The checksum has to be done to the TABLE itself!
                        //u32 CheckSum = CalcTableChecksum((u32*)TTFState.At, 16);
                        int x = 5;
                    }
                }
                
                TTFState.At += (sizeof(u32) *4);
            }
        }
    }
}
#endif
