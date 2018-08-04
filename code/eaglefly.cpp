
#include "eaglefly.h"


#define STB_TRUETYPE_IMPLEMENTATION 
#include "stb_truetype.h"


inline b32 
IsNormalized(r32 Value)
{
    b32 Result = ((Value >= 0) && (Value <= 1.0f));
    return Result;
}

inline r32
LinearBlend(r32 A, r32 t, r32 B)
{
    r32 Result = ((1 - t) * A) + (t * B);
    return Result;
}

//TODO(ALex): Optimize this!
internal void
DrawRectangleAt(efly_asset_bitmap * Buffer, 
                efly_asset_bitmap * Bitmap, 
                r32 AtX, 
                r32 AtY,
                r32 Red = 1.0f, 
                r32 Green = 1.0f, 
                r32 Blue = 1.0f, 
                r32 Alpha = 1.0f)
{
    //NOTE(Alex): AtX, AtY can be outside of the Buffer 
    //We need to map Screen Coordinates - to bitmap coordinates
    //TODO(Alex): Do we want to un-normalized Color values
    Assert(Buffer && 
           Bitmap && 
           Buffer->Data 
           && Bitmap->Data);
    
    Assert(IsNormalized(Red) &&
           IsNormalized(Green) &&
           IsNormalized(Blue) &&
           IsNormalized(Alpha));  
    
    
    Assert(Buffer->Data);
    s32 MinBufferX = RoundR32ToS32(AtX);
    s32 MinBufferY = RoundR32ToS32(AtY);
    s32 MaxBufferX = RoundR32ToS32(AtX + (r32)Bitmap->Width);
    s32 MaxBufferY = RoundR32ToS32(AtY + (r32)Bitmap->Height);
    
    s32 BufferMaxHeight =  (Buffer->Height - 1);
    s32 BufferMaxWidth =  (Buffer->Width - 1);
    
    u32 BlueMask = 0x000000FF;
    u32 GreenMask = 0x0000FF00;
    u32 RedMask = 0x00FF0000;
    
    if(MaxBufferY > BufferMaxHeight)
    {
        MaxBufferY = BufferMaxHeight;
    }
    if(MaxBufferX > BufferMaxWidth)
    {
        MaxBufferX = BufferMaxWidth;
    }
    
    s32 MinBitmapY = 0;
    if(MinBufferY < 0)
    {
        MinBitmapY = MinBitmapY - MinBufferY;
        MinBufferY = 0;
    }
    s32 MinBitmapX = 0;
    if(MinBufferX < 0)
    {
        MinBitmapX = MinBitmapX - MinBufferX;
        MinBufferX = 0;
    }
    
    r32 Inverse255 = 1 / 255.0f;
    
    u32 * Dest = (u32*)Buffer->Data + (MinBufferY * Buffer->Width + MinBufferX);
    u32 * Source = (u32*)Bitmap->Data + (MinBitmapY * Bitmap->Width + MinBitmapX);
    
    u32 * RowDest = Dest;
    u32 * RowSource = Source;
    
    for(s32 Y = MinBufferY; 
        Y < MaxBufferY;
        ++Y)
    {
        Dest = RowDest;
        Source = RowSource;
        
        for(s32 X = MinBufferX; 
            X < MaxBufferX;
            ++X)
        {
            //NOTE(Alex): AA RR GG BBB
            
            //TODO(Alex): Pre-multiplied alpha
            //TODO(Alex): Antialiasing
            
            //TODO(Alex) UnMap to 0-1  color space? 
            u32 SColor = *Source;
            u32 DColor = *Dest;
#if 1
            r32 SBlue = (r32)((SColor >> 0) & 0xFF);
            r32 SGreen = (r32)((SColor >> 8) & 0xFF); 
            r32 SRed = (r32)((SColor >> 16) & 0xFF);
            r32 SAlpha = (r32)((SColor >> 24) & 0xFF);
            
            r32 DBlue = (r32)((DColor >> 0) & 0xFF);
            r32 DGreen = (r32)((DColor >> 8) & 0xFF); 
            r32 DRed = (r32)((DColor >> 16) & 0xFF);
            r32 DAlpha = (r32)((DColor >> 24) & 0xFF);
            
            //r32 RAlpha = LinearBlend(DAlpha, 0.5f,  SAlpha) * Inverse255;
            r32 RAlpha = SAlpha * Inverse255;
            r32 RBlue = LinearBlend(DBlue, RAlpha, SBlue) * Blue;
            r32 RGreen = LinearBlend(DGreen,RAlpha, SGreen) * Green;
            r32 RRed = LinearBlend(DRed, RAlpha, SRed) * Red;
            
            u32 RColor = (((RoundR32ToU32(RBlue) & 0xFF) << 0) | 
                          ((RoundR32ToU32(RGreen)  & 0xFF) << 8) |
                          ((RoundR32ToU32(RRed) & 0xFF) << 16) |
                          ((RoundR32ToU32(RAlpha) & 0xFF) << 24));
#else
            u32 RColor = *Source;
#endif
            
            *Dest = RColor;
            ++Dest;
            ++Source;
        }
        
        RowDest += Buffer->Width;
        RowSource += Bitmap->Width;
    }
}

internal void
ClearScreen(efly_asset_bitmap * Buffer, r32 Red, r32 Green, r32 Blue, r32 Alpha)
{
    //NOTE(Alex): AtX, AtY can be outside of the Buffer 
    //We need to map Screen Coordinates - to bitmap coordinates
    //TODO(Alex): Do we want to un-normalized Color values
    Assert(IsNormalized(Red) &&
           IsNormalized(Green) &&
           IsNormalized(Blue) &&
           IsNormalized(Alpha));  
    
    
    u32 Blue255  = RoundR32ToU32(255.0f * Blue) & 0xFF;
    u32 Green255 = RoundR32ToU32(255.0f * Green) & 0xFF;
    u32 Red255 = RoundR32ToU32(255.0f * Red) & 0xFF;
    u32 Alpha255 = RoundR32ToU32(255.0f * Alpha) & 0xFF;
    
    //NOTE(Alex): AA RR GG BBB
    u32 RColor = (u32)((Blue255 << 0) | (Green255 << 8) |(Red255 << 16) | (Alpha255 << 24));
    
    u32 * Dest = (u32*)Buffer->Data;
    u32 * RowDest = Dest;
    for(s32 Y = 0; 
        Y < (Buffer->Height - 1);
        ++Y)
    {
        Dest = RowDest;
        for(s32 X = 0; 
            X < (Buffer->Width - 1);
            ++X)
        {
            *Dest = RColor;
            ++Dest;
        }
        
        RowDest += Buffer->Width;
    }
}

inline b32 
IsValidCGlyph(codepoint_glyph CGlyph)
{
    b32 Result = (CGlyph.GlyphIndex); 
    return Result;
}

inline b32
IsValidFont(asset_font * Font)
{
    Assert(Font->MaxGlyphIndex >= Font->MinGlyphIndex);
    b32 Result = (Font->MinGlyphIndex && Font->MaxGlyphIndex);
    return Result;
}


internal asset_glyph *
GetGlyphMetrics(debug_state * DebugState, u32 CodePoint)
{
    codepoint_glyph CGlyph = DebugState->CGlyphTable[CodePoint];
    asset_glyph * Result = 0;
    if(IsValidCGlyph(CGlyph))
    {
        Result = DebugState->Glyphs + CGlyph.GlyphIndex;
    }
    
    return Result;
}


internal r32
GetHAdvance(debug_state * DebugState, u32 CodePoint)
{
    r32 Result = {};
    asset_glyph * Glyph = GetGlyphMetrics(DebugState, CodePoint);
    if(Glyph)
    {
        Result = Glyph->HAdvance;
    }
    
    return Result;
}

internal vector_2 
PositionGlyph(debug_state * DebugState, u32 CodePoint)
{
    vector_2 Result = {};
    asset_glyph * Glyph = GetGlyphMetrics(DebugState ,CodePoint);
    if(Glyph)
    {
        Result = Vector2(DebugState->AtX + Glyph->x0, DebugState->AtY - Glyph->y1); 
    }
    
    return Result;
}

internal efly_asset_bitmap *
GetGlyphFromCodePoint(debug_state * DebugState, u32 CodePoint)
{
    efly_asset_bitmap * Result = 0;
    asset_glyph * Glyph = GetGlyphMetrics(DebugState ,CodePoint);
    if(Glyph)
    {
        Result = &Glyph->Bitmap;
    }
    
    return Result;
}

internal r32  
GetKerningForPair(debug_state * DebugState, 
                  u32 CodePoint, 
                  u32 NextCodePoint, 
                  r32 KerningValue = 0.0f)
{
    kerning_pair * PairFound = 0;
    kerning_pair ** FirstPair = (DebugState->KerningTable + CodePoint);
    kerning_pair * Iter = *FirstPair;
    while(Iter) 
    {
        if(Iter->NextCode == NextCodePoint)
        {
            PairFound = Iter;
            break;
        }
        
        Iter = Iter->Next;
    }
    
    if(!PairFound)
    {
        PairFound = PushStruct(&DebugState->DebugArena, kerning_pair); 
        PairFound->Next = *FirstPair;
        PairFound->KerningValue = KerningValue;
        PairFound->NextCode = NextCodePoint;
        *FirstPair = PairFound;
    }
    
    Assert(PairFound);
    return (PairFound->KerningValue);
}


//TODO(Alex): Batch system for rendering glyphs! 
//use codepoint list to modify a specific glyph to be rendered into the batch!   
internal void 
RenderText(debug_state * DebugState, efly_asset_bitmap * Dest, char * Text)
{
    if(IsValidFont(&DebugState->Fonts[0]))
    {
        asset_font * Font = &DebugState->Fonts[0];
        r32 * AtX = &DebugState->AtX;  
        r32 * AtY = &DebugState->AtY;  
        
        char * At = Text;
        while(*At)
        {
            u32 C0 = (u32)*At;
            u32 C1 = (*(At+1)) ? *(At+1) : 0;
            
            r32 KerningAdvance = DebugState->CurrentFontScale * GetKerningForPair(DebugState, C0, C1);
            r32 HAdvance = DebugState->CurrentFontScale * GetHAdvance(DebugState, C0);
            vector_2 P = PositionGlyph(DebugState, C0);
            efly_asset_bitmap * Glyph = GetGlyphFromCodePoint(DebugState, C0);
            
            if(Glyph)
            {
                DrawRectangleAt(Dest, Glyph,  P.x, P.y);
            }
            
            *AtX += HAdvance + KerningAdvance; 
            ++At;
        }
        
        *AtX = 0;
        *AtY -= Font->YAdvance;
    }
}

#define MapMonoTo4Channel(Value) (((Value) << 24) | ((Value) << 16) | ((Value) << 8) | ((Value) << 0))


//TODO(Alex) Suport unicode
internal asset_glyph *
AddNextGlyphIndex(debug_state * DebugState, 
                  asset_font * Font,  
                  u32 CodePoint,
                  s32 HAdvance,
                  s32 LeftSideBearing,
                  s32 x0, s32 y0, s32 x1, s32 y1)
{
    codepoint_glyph * CGlyph = DebugState->CGlyphTable + CodePoint;
    CGlyph->CodePoint = CodePoint;
    CGlyph->GlyphIndex = DebugState->GlyphCount++;
    Font->MaxGlyphIndex = CGlyph->GlyphIndex;
    
    asset_glyph * Result = DebugState->Glyphs + CGlyph->GlyphIndex;
    Result->x0 = x0;
    Result->y0 = y0;
    Result->x1 = x1;
    Result->y1 = y1;
    Result->LeftSideBearing = (r32)LeftSideBearing;
    Result->HAdvance = (r32)HAdvance;
    
    return (Result);
}

internal asset_font *
InitAssetFont(debug_state * DebugState)
{
    asset_font * Result = DebugState->Fonts + DebugState->FontCount++;
    Result->MinGlyphIndex = DebugState->GlyphCount;
    Result->MaxGlyphIndex = Result->MinGlyphIndex;
    
    return Result;
}

extern "C" DEBUG_UPDATE_AND_RENDER(DebugUpdateAndRender) 
{
    debug_state * DebugState = (debug_state*)Memory->DebugStorage;
    if(!DebugState->IsInitialized)
    {
        InitializeArena(&DebugState->DebugArena, (char*)Memory->DebugStorage + sizeof(debug_state), Memory->DebugStorageSize - sizeof(debug_state));
        //NOTE(Alex): We keep zero Index for null or invalid glyph indices
        DebugState->GlyphCount = 1;
        
        //TODO(Alex): Start at the top of the frameBuffer 
        DebugState->AtX = 0;
        DebugState->AtY = 0;
        
        stbtt_fontinfo FontInfo = {};
        //debug_file_content TTFContent = Memory->DebugReadEntireFile("C:/Windows/Fonts/liberation-mono.ttf");
        debug_file_content TTFContent = Memory->DebugReadEntireFile("C:/Windows/Fonts/arial.ttf");
        b32 FontInit = stbtt_InitFont(&FontInfo, (const unsigned char *)TTFContent.Content, 0);//stbtt_GetFontOffsetForIndex((const unsiged char*)TTFContent.Content, 1));
        if(FontInit)
        {
            asset_font * Font = InitAssetFont(DebugState);
            
            s32 Ascent = 0;
            s32 Descent = 0;
            s32 LineGap = 0;
            r32 PixelHeight = 30.0f;
            r32 Scale = stbtt_ScaleForPixelHeight(&FontInfo, PixelHeight);
            
            //u32 CodePointSize = Scale
            
            DebugState->CurrentFontScale = Scale;
            stbtt_GetFontVMetrics(&FontInfo, &Ascent, &Descent, &LineGap); 
            
            //TODO(Alex): Subpixel alignment
            Font->YAdvance = Scale * (Ascent - Descent + LineGap);
            r32 Baseline = Scale * Ascent;
            for(u32 CodePoint = Min_Codepoint_Extract;
                CodePoint <= Max_Codepoint_Extract;
                ++CodePoint)
            {
                
#if 1
                s32 Width;
                s32 Height;
                s32 XOffset;
                s32 YOffset;
                
                unsigned char * MonoBitmap = stbtt_GetCodepointBitmap(&FontInfo, 0, Scale, CodePoint, &Width, &Height, &XOffset, &YOffset);
                
                s32 HAdvance;
                s32 LeftSideBearing;
                stbtt_GetCodepointHMetrics(&FontInfo, 
                                           CodePoint, 
                                           &HAdvance, 
                                           &LeftSideBearing);
                
                s32 x0, y0, x1, y1;
                stbtt_GetCodepointBitmapBoxSubpixel(&FontInfo, CodePoint, 
                                                    Scale, Scale, 
                                                    0, 0, 
                                                    &x0, &y0, &x1, &y1);
                
#else
                s32 Width = x1 - x0;
                s32 Height = y1 - y0;
                
                unsigned char * MonoBitmap = (unsigned char*)PushSize(&DebugState->TranArena, Height * Width);
                stbtt_MakeCodepointBitmapSubpixel(&FontInfo, MonoBitmap, 
                                                  Width, Height,
                                                  0, 
                                                  0, Scale,
                                                  0,0,
                                                  CodePoint);
#endif
                asset_glyph * Glyph = AddNextGlyphIndex(DebugState, Font, CodePoint, 
                                                        HAdvance, LeftSideBearing, 
                                                        x0, y0, x1, y1);
                Glyph->Bitmap.Data = PushSize(&DebugState->DebugArena, Width * Height * BITMAP_BYTES_PER_PIXEL); 
                Glyph->Bitmap.Width = Width;
                Glyph->Bitmap.Height = Height;
                Glyph->Bitmap.BytesPerPixel = BITMAP_BYTES_PER_PIXEL;
                
                if(MonoBitmap)
                {
                    u32 * Dest = (u32*)Glyph->Bitmap.Data;
                    unsigned char * Source = MonoBitmap + (Height - 1) * Width;
                    u32 * DestRow = Dest; 
                    unsigned char * SourceRow = Source; 
                    
                    for(s32 Y = 0;
                        Y < Height;
                        ++Y)
                    {
                        Source = SourceRow;
                        Dest= DestRow;
                        for(s32 X = 0;
                            X < Width;
                            ++X)
                        {
                            u32 Pixel = MapMonoTo4Channel(*Source);
                            *Dest = Pixel;
                            ++Source;
                            ++Dest;
                        }
                        
                        DestRow += Width;
                        SourceRow -= Width;
                    }
                }
                
                for(u32 NextCodePoint = Min_Codepoint_Extract;
                    NextCodePoint < Max_Codepoint_Extract;
                    ++NextCodePoint)
                {
                    s32 KerningValue = stbtt_GetCodepointKernAdvance(&FontInfo, CodePoint, NextCodePoint);
                    if(KerningValue != 0) 
                    {
                        int x = 5;
                    }
                    GetKerningForPair(DebugState, CodePoint, NextCodePoint, (r32)KerningValue);
                }
            }
        }
        
        
        DebugState->IsInitialized = true;
    }
    
    transient_state * TranState = (transient_state *)Memory->TransientStorage; 
    if(!TranState->IsInitialized)
    {
        InitializeArena(&TranState->TranArena, (char*)Memory->TransientStorage + sizeof(transient_state), Memory->TransientStorageSize - sizeof(transient_state));
        SubArena(&TranState->TranArena, &TranState->Out_TracerSubArena, Megabytes(200));
        SubArena(&TranState->TranArena, &TranState->In_TracerSubArena, Megabytes(200));
        
        TranState->IsInitialized = true;
    }
    
    for(u32 VKeyIndex = VKey_F1;
        VKeyIndex < VKey_FCount;
        ++VKeyIndex)
    {
        efly_input_command * NewCommand = 0;
        if(FUNKEY_PRESSED(Input, VKeyIndex))
        {
            NewCommand = TranState->TracerInput.CommandFirstFree;
            if(NewCommand)
            {
                TranState->TracerInput.CommandFirstFree = NewCommand->Next; 
            }
            else
            {
                NewCommand = PushStruct(&TranState->Out_TracerSubArena.Arena, efly_input_command);
            }
        }
        
        if(NewCommand)
        {
            switch(VKeyIndex)
            {
                case VKey_F1:
                {
                    NewCommand->Type = InputCommand_LOAD_PROCESS;
                    NewCommand->LoadProcessData.RunFromCmdLine = true;
                    NewCommand->LoadProcessData.TargetImageFullPath = TargetImageFullPath;
                    NewCommand->LoadProcessData.TargetPDBFullPath = TargetPDBFullPath;
                    NewCommand->LoadProcessData.CmdEXEFullPath = CmdEXEFullPath;
                }break;
                case VKey_F2:
                {
                    //TODO(Alex): Findout data composition for this command!
                    NewCommand->Type = InputCommand_CONTINUE;
                }break;
                default:
                {
                    InvalidCodePath;
                }break;
            }
            
            efly_input_command * Command = TranState->TracerInput.FirstCommand;
            if(Command)
            {
                while(Command->Next)
                {
                    Command = Command->Next;
                }
                Command->Next = NewCommand;
            }
            else
            {
                TranState->TracerInput.FirstCommand = NewCommand;
            }
        }
    }
    
    ClearScreen(FrameBuffer, 0.2f, 0.2f, 0.6f, 1.0f);
    
    //TODO(Alex): Control writing positioning
    DebugState->AtX = 0;
    DebugState->AtY = (r32)FrameBuffer->Height - DebugState->Fonts[0].YAdvance;
    
    RenderText(DebugState, FrameBuffer,  "El veloz murcielago hindu comia feliz cardillo y kiwi.");
    RenderText(DebugState, FrameBuffer,  "Today I drank some milk with my friends.");
    RenderText(DebugState, FrameBuffer,  "Today I drank some milk with my friends.");
    RenderText(DebugState, FrameBuffer,  "Today I drank some milk with my friends.");
    RenderText(DebugState, FrameBuffer,  "Today I drank some milk with my friends.");
}























