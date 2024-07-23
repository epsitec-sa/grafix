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

/*****************************************************************************/
#include "agg_rasterizer_scanline_aa.h"

#include "path.h"
#include "renderer.h"
#include "font_manager.h"

namespace AntigrainCPP {

    struct Rasterizer
    {
     agg::rasterizer_scanline_aa<> rasterizer;
     bool has_transform;
     bool has_clip_box;
     agg::trans_affine transform_matrix;
     double x1, y1, x2, y2;
    };

    extern "C" DECLSPEC Rasterizer* Rasterizer_New();

    extern "C" DECLSPEC void Rasterizer_Clear(
        Rasterizer* rasterizer
    );

    extern "C" DECLSPEC void Rasterizer_FillingRule(
        Rasterizer* rasterizer, 
        int rule
    );

    extern "C" DECLSPEC bool Rasterizer_HitTest(
        Rasterizer* rasterizer, 
        int x, int y
    );

    extern "C" DECLSPEC void Rasterizer_Gamma(
        Rasterizer* rasterizer, 
        double gamma
    );

    extern "C" DECLSPEC void Rasterizer_SetTransform(
        Rasterizer* rasterizer, 
        double xx, double xy, 
        double yx, double yy, 
        double tx, double ty
    );

    extern "C" DECLSPEC void Rasterizer_SetClipBox(
        Rasterizer* rasterizer, 
        double x1, double y1, 
        double x2, double y2
    );

    extern "C" DECLSPEC void Rasterizer_ResetClipBox(
        Rasterizer* rasterizer
    );

    extern "C" DECLSPEC void Rasterizer_AddPath(
        Rasterizer* rasterizer, 
        Path* path, 
        bool curved
    );

    extern "C" DECLSPEC void Rasterizer_AddGlyph(Rasterizer* rasterizer, int glyph, double x, double y, double scale, FontManager* font_manager);

    extern "C" DECLSPEC void Rasterizer_AddChar(Rasterizer* rasterizer, char c, double x, double y, double scale, FontManager* font_manager);

    void Rasterizer_InternalAddChar(Rasterizer* rasterizer, double x, double y, double scale, FontManager* font_manager);

    /* extern "C" DECLSPEC void Rasterizer_AddGlyph( */
    /*     Rasterizer* rasterizer, */ 
    /*     agg::font_face* face, */ 
    /*     int glyph, */ 
    /*     double x, double y, */ 
    /*     double scale */
    /* ); */

    /* extern "C" DECLSPEC void Rasterizer_AddGlyphXY( */
    /*     Rasterizer* rasterizer, */ 
    /*     agg::font_face* face, */ 
    /*     int glyph, */ 
    /*     double x, double y, */ 
    /*     double scale_x, double scale_y */
    /* ); */

    /* extern "C" DECLSPEC double Rasterizer_AddText( */
    /*     Rasterizer* rasterizer, */ 
    /*     agg::font_face* face, */ 
    /*     const wchar_t* text, */ 
    /*     int mode, */ 
    /*     double xx, double xy, */ 
    /*     double yx, double yy, */ 
    /*     double tx, double ty */
    /* ); */

    extern "C" DECLSPEC void Rasterizer_AddPathStroke1(
        Rasterizer* rasterizer, 
        Path* path, 
        double width, 
        bool curved
    );

    extern "C" DECLSPEC void Rasterizer_AddPathStroke2(
        Rasterizer* rasterizer, 
        Path* path, 
        double width, 
        int cap, 
        int join, 
        double miter_limit, 
        bool curved
    );

    extern "C" DECLSPEC void Rasterizer_RenderSolid(
        Rasterizer* rasterizer, 
        RendererSolid* renderer
    );

    extern "C" DECLSPEC void Rasterizer_RenderImage(
        Rasterizer* rasterizer, 
        RendererImage* renderer
    );

    extern "C" DECLSPEC void Rasterizer_RenderGradient(
        Rasterizer* rasterizer, 
        RendererGradient* renderer
    );

    extern "C" DECLSPEC void Rasterizer_Delete(
        Rasterizer* rasterizer
    );
}
