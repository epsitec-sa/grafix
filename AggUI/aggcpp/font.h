/*
This file is part of AggUI.

Copyright © 2003-2024, EPSITEC SA, 1400 Yverdon-les-Bains, Switzerland

AggUI is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
any later version.

AggUI is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

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

    extern "C" DECLSPEC void FreetypeInfo_DoneFace(FT_Face face);

    extern "C" DECLSPEC bool FreetypeInfo_IsFaceBold(FT_Face face);

    extern "C" DECLSPEC bool FreetypeInfo_IsFaceItalic(FT_Face face);

    extern "C" DECLSPEC unsigned FreetypeInfo_GetUnitsPerEm(FT_Face face);

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

    extern "C" DECLSPEC double FreetypeInfo_GetAscender(FT_Face face, double size);

    extern "C" DECLSPEC double FreetypeInfo_GetDescender(FT_Face face, double size);

    extern "C" DECLSPEC double FreetypeInfo_GetHeight(FT_Face face, double size);

    // INTERNAL FUNCTIONS

    void LoadGlyph(FT_Face face, unsigned glyph_index, double size);

    void SetFaceSize(FT_Face face, double size);
}
