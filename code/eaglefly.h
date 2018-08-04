#ifndef EAGLEFLY_H

#include "eaglefly_platform.h"
#include "eaglefly_math.h"

#define Min_Codepoint_Extract 32
#define Max_Codepoint_Extract 126

struct ttf_font
{
    r32 KerningTable;
    u32 CodePointToGlyphTable;
};


struct asset_font
{
    r32 YAdvance;
    u32 MinGlyphIndex;
    u32 MaxGlyphIndex;
};

//TODO(Alex): Allow Sparse codepoint_glyph table for unicode 
struct codepoint_glyph
{
    u32 CodePoint;
    u32 GlyphIndex;
    
#if 0    
    u32 SizeIndex;
    asset_bitmap Bitmap;
    codepoint_glyph * Next;
#endif
    
};

//NOTE(Alex): Glyph metrics are unscaled
struct kerning_pair
{
    u32 NextCode;
    r32 KerningValue; 
    kerning_pair * Next;
};

struct asset_glyph
{
    efly_asset_bitmap Bitmap;
    r32 HAdvance;
    r32 LeftSideBearing;
    
#if 0    
    r32 YAdvance;
    r32 Ascent;
    r32 Descent;
    r32 LineGap;
#endif
    
    s32 x0, y0, x1, y1;
};

#if 0
struct efly_debug_manager
{
    memory_arena DebugArena;
    memory_arena TranArena;
    
    efly_tracer_input * TracerInput;
    sub_arena Out_TracerSubArena;
    sub_arena In_TracerSubArena;
};
#endif

//TODO(Alex): How do we wanna choose font glyphs?
struct debug_state
{
    b32 IsInitialized;
    memory_arena DebugArena;
    
    //NOTE(Alex): FONT_GLYPH DATA
    
    ttf_font DefaultTTF;
    u32 FontCount;
    asset_font Fonts[8];
    
    //TODO(Alex): Do ScaleTable
#if 0    
    u32 GlyphSizeCount;
    u32 CurrentGlyphSize;
#endif
    
    r32 CurrentFontScale;
    codepoint_glyph CGlyphTable[4096]; 
    
    u32 GlyphCount;
    asset_glyph Glyphs[4096];
    kerning_pair * KerningTable[4096];
    
    
    r32 AtY;
    r32 AtX;
};


#define EAGLEFLY_H
#endif

