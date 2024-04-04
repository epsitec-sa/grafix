#pragma once

/*****************************************************************************/
/* from agg_rasterizer.cpp */
#include "path.h"
#include "renderer.h"

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
