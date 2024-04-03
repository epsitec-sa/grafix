#pragma once

/*****************************************************************************/
/* from agg_rasterizer.cpp */
#include "path.h"

struct Rasterizer
{
 agg::rasterizer_scanline_aa<> rasterizer;
 bool has_transform;
 bool has_clip_box;
 agg::trans_affine transform_matrix;
 double x1, y1, x2, y2;
};

extern "C" DECLSPEC Rasterizer* RasterizerNew();

extern "C" DECLSPEC void RasterizerClear(
    Rasterizer* rasterizer
);

extern "C" DECLSPEC void RasterizerFillingRule(
    Rasterizer* rasterizer, 
    int rule
);

extern "C" DECLSPEC bool RasterizerHitTest(
    Rasterizer* rasterizer, 
    int x, int y
);

extern "C" DECLSPEC void RasterizerGamma(
    Rasterizer* rasterizer, 
    double gamma
);

extern "C" DECLSPEC void RasterizerSetTransform(
    Rasterizer* rasterizer, 
    double xx, double xy, 
    double yx, double yy, 
    double tx, double ty
);

extern "C" DECLSPEC void RasterizerSetClipBox(
    Rasterizer* rasterizer, 
    double x1, double y1, 
    double x2, double y2
);

extern "C" DECLSPEC void RasterizerResetClipBox(
    Rasterizer* rasterizer
);

extern "C" DECLSPEC void RasterizerAddPath(
    Rasterizer* rasterizer, 
    Path* path, 
    bool curved
);

/* extern "C" DECLSPEC void RasterizerAddGlyph( */
/*     Rasterizer* rasterizer, */ 
/*     agg::font_face* face, */ 
/*     int glyph, */ 
/*     double x, double y, */ 
/*     double scale */
/* ); */

/* extern "C" DECLSPEC void RasterizerAddGlyphXY( */
/*     Rasterizer* rasterizer, */ 
/*     agg::font_face* face, */ 
/*     int glyph, */ 
/*     double x, double y, */ 
/*     double scale_x, double scale_y */
/* ); */

/* extern "C" DECLSPEC double RasterizerAddText( */
/*     Rasterizer* rasterizer, */ 
/*     agg::font_face* face, */ 
/*     const wchar_t* text, */ 
/*     int mode, */ 
/*     double xx, double xy, */ 
/*     double yx, double yy, */ 
/*     double tx, double ty */
/* ); */

extern "C" DECLSPEC void RasterizerAddPathStroke1(
    Rasterizer* rasterizer, 
    Path* path, 
    double width, 
    bool curved
);

extern "C" DECLSPEC void RasterizerAddPathStroke2(
    Rasterizer* rasterizer, 
    Path* path, 
    double width, 
    int cap, 
    int join, 
    double miter_limit, 
    bool curved
);

/* extern "C" DECLSPEC void RasterizerRenderSolid( */
/*     Rasterizer* rasterizer, */ 
/*     AggRendererSolid* renderer */
/* ); */

/* extern "C" DECLSPEC void RasterizerRenderImage( */
/*     Rasterizer* rasterizer, */ 
/*     AggRendererImage* renderer */
/* ); */

/* extern "C" DECLSPEC void RasterizerRenderGradient( */
/*     Rasterizer* rasterizer, */ 
/*     AggRendererGradient* renderer */
/* ); */

extern "C" DECLSPEC void RasterizerDelete(
    Rasterizer* rasterizer
);
