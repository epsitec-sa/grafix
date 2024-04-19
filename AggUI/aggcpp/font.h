#pragma once

#include "agg_conv_contour.h"
#include "agg_font_freetype.h"


#include "declspec.h"
#include "pixelfmt.h"


namespace AntigrainCPP {

    extern "C" DECLSPEC FT_Library FreetypeInfo_CreateLibrary();

    extern "C" DECLSPEC FT_Face FreetypeInfo_LoadFromFile(FT_Library library,
        const char* font_name
    );

    extern "C" DECLSPEC bool FreetypeInfo_IsFaceBold(FT_Face face);

    extern "C" DECLSPEC bool FreetypeInfo_IsFaceItalic(FT_Face face);

    extern "C" DECLSPEC unsigned FreetypeInfo_GetCharIndex(FT_Face face,
        unsigned long charcode
    );

    extern "C" DECLSPEC double FreetypeInfo_GetGlyphAdvance(FT_Face face, 
        unsigned glyph_index,
        double size
    );

    extern "C" DECLSPEC void FreetypeInfo_GetGlyphBBox(FT_Face face,
        unsigned glyph_index,
        double size,
        double &xMin,
        double &xMax,
        double &yMin,
        double &yMax
    );

    extern "C" DECLSPEC double FreetypeInfo_GetKerning(FT_Face face, 
        unsigned left_glyph,
        unsigned right_glyph,
        double size
    );

    // INTERNAL FUNCTIONS

    void LoadGlyph(FT_Face face, unsigned glyph_index, double size);

    void SetFaceSize(FT_Face face, double size);
}
