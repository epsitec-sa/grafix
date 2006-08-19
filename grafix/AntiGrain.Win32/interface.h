//	interface.h
//
//	Copyright © 2003-2006, Pierre ARNAUD, OPaC bright ideas, Ch. du Fontenay 6,
//	                       CH-1400 YVERDON, Switzerland. All rights reserved. 
//
//	Contact: pierre.arnaud@opac.ch, http://www.opac.ch
//	License: see license.txt

#pragma once

#include "DLL.h"

/*
 *	The "interface" gives access to all public API entry points.
 */

/*****************************************************************************/

#if	defined(AGG_DUMMY_TYPES)

/*
 *	If we just want to expose the raw API entry points (which are plain "C"
 *	functions) we don't need to know precisely about all the internal types
 *	which are required.
 *
 *	We map structures to void and enums to int.
 */

typedef void AggBuffer;
typedef void AggPath;
typedef void AggRasterizer;
typedef void AggRendererGradient;
typedef void AggRendererImage;
typedef void AggRendererSolid;
typedef void AggRendererSmooth;
typedef void AggRendererBase;

namespace agg
{
	typedef void font_face;
	typedef void text_break;
}

#else

struct AggBuffer;
struct AggPath;
struct AggRasterizer;
struct AggRendererGradient;
struct AggRendererImage;
struct AggRendererSolid;
struct AggRendererSmooth;
struct AggRendererBase;

namespace agg
{
	class font_face;
	class text_break;
}
#endif

/*****************************************************************************/
/*	from interface.cpp														 */

extern "C" AGGDLL bool				AggInitialise();
extern "C" AGGDLL void				AggShutDown();
extern "C" AGGDLL void				AggNoOp();
extern "C" AGGDLL void				AggNoOpString(const wchar_t* text);
extern "C" AGGDLL const wchar_t*	AggGetVersion();
extern "C" AGGDLL const wchar_t*	AggGetProductName();

/*****************************************************************************/
/*	from agg_buffer.cpp														 */

extern "C" AGGDLL AggBuffer*		AggBufferNew(unsigned dx, unsigned dy, unsigned bpp);
extern "C" AGGDLL void				AggBufferResize(AggBuffer* buffer, unsigned dx, unsigned dy, unsigned bpp);
extern "C" AGGDLL void				AggBufferDrawGlyphs(AggBuffer* buffer, void* hfont, int x, int y, unsigned short* glyphs, int* dx_array, unsigned int count, unsigned int color);
extern "C" AGGDLL void				AggBufferPaint(AggBuffer* buffer, void* hdc, int x1, int y1, int x2, int y2);
extern "C" AGGDLL void				AggBufferPaintOffset(AggBuffer* buffer, void* hdc, int ox, int oy, int x1, int y1, int x2, int y2);
extern "C" AGGDLL void				AggBufferBlendOffset(AggBuffer* buffer, void* hdc, int ox, int oy, int x1, int y1, int x2, int y2);
extern "C" AGGDLL void				AggBufferClear(AggBuffer* buffer);
extern "C" AGGDLL void				AggBufferClearRect(AggBuffer* buffer, int x1, int y1, int x2, int y2);
extern "C" AGGDLL void				AggBufferGetMemoryLayout(AggBuffer* buffer, int & dx, int & dy, int & stride, void*& memory);
extern "C" AGGDLL void*             AggBufferGetMemoryBitmapHandle(AggBuffer* buffer);
extern "C" AGGDLL void				AggBufferDelete(AggBuffer* buffer);
extern "C" AGGDLL void				AggBufferInfiniteClipping(AggBuffer* buffer);
extern "C" AGGDLL void				AggBufferEmptyClipping(AggBuffer* buffer);
extern "C" AGGDLL void				AggBufferAddClipBox(AggBuffer* buffer, int x1, int y1, int x2, int y2);
extern "C" AGGDLL void				AggBufferBltBuffer(AggBuffer* buffer, int xd, int yd, AggBuffer* source, int xs, int ys, int dx, int dy);
extern "C" AGGDLL void				AggBufferComposeBuffer(AggBuffer* buffer, int xd, int yd, AggBuffer* source, int xs, int ys, int dx, int dy);

/*****************************************************************************/
/*	from agg_rasterizer.cpp													 */

extern "C" AGGDLL AggRasterizer*	AggRasterizerNew();
extern "C" AGGDLL void				AggRasterizerClear(AggRasterizer* rasterizer);
extern "C" AGGDLL void				AggRasterizerFillingRule(AggRasterizer* rasterizer, int rule);
extern "C" AGGDLL bool				AggRasterizerHitTest(AggRasterizer* rasterizer, int x, int y);
extern "C" AGGDLL void				AggRasterizerGamma(AggRasterizer* rasterizer, double gamma);
extern "C" AGGDLL void				AggRasterizerSetTransform(AggRasterizer* rasterizer, double xx, double xy, double yx, double yy, double tx, double ty);
extern "C" AGGDLL void				AggRasterizerSetClipBox(AggRasterizer* rasterizer, double x1, double y1, double x2, double y2);
extern "C" AGGDLL void				AggRasterizerResetClipBox(AggRasterizer* rasterizer);
extern "C" AGGDLL void				AggRasterizerAddPath(AggRasterizer* rasterizer, AggPath* path, bool curved);
extern "C" AGGDLL void				AggRasterizerAddGlyph(AggRasterizer* rasterizer, agg::font_face* face, int glyph, double x, double y, double scale);
extern "C" AGGDLL void				AggRasterizerAddGlyphXY(AggRasterizer* rasterizer, agg::font_face* face, int glyph, double x, double y, double scale_x, double scale_y);
extern "C" AGGDLL double			AggRasterizerAddText(AggRasterizer* rasterizer, agg::font_face* face, const wchar_t* text, int mode, double xx, double xy, double yx, double yy, double tx, double ty);
extern "C" AGGDLL void				AggRasterizerAddPathStroke1(AggRasterizer* rasterizer, AggPath* path, double width, bool curved);
extern "C" AGGDLL void				AggRasterizerAddPathStroke2(AggRasterizer* rasterizer, AggPath* path, double width, int cap, int join, double miter_limit, bool curved);
extern "C" AGGDLL void				AggRasterizerRenderSolid(AggRasterizer* rasterizer, AggRendererSolid* renderer);
extern "C" AGGDLL void				AggRasterizerRenderImage(AggRasterizer* rasterizer, AggRendererImage* renderer);
extern "C" AGGDLL void				AggRasterizerRenderGradient(AggRasterizer* rasterizer, AggRendererGradient* renderer);
extern "C" AGGDLL void				AggRasterizerDelete(AggRasterizer* rasterizer);

/*****************************************************************************/
/*	from agg_renderer.cpp													 */

extern "C" AGGDLL void				AggRendererSolidSetAlphaMask(AggRendererSolid* renderer, AggBuffer* buffer, int component);
extern "C" AGGDLL void				AggRendererSmoothSetAlphaMask(AggRendererSmooth* renderer, AggBuffer* buffer, int component);
extern "C" AGGDLL void				AggRendererImageSetAlphaMask(AggRendererImage* renderer, AggBuffer* buffer, int component);
extern "C" AGGDLL void				AggRendererGradientSetAlphaMask(AggRendererGradient* renderer, AggBuffer* buffer, int component);

extern "C" AGGDLL AggRendererSolid*	AggRendererSolidNew(AggBuffer* buffer);
extern "C" AGGDLL void				AggRendererSolidClear(AggRendererSolid* renderer, double r, double g, double b, double a);
extern "C" AGGDLL void				AggRendererSolidColor(AggRendererSolid* renderer, double r, double g, double b, double a);
extern "C" AGGDLL void				AggRendererSolidDelete(AggRendererSolid* renderer);

extern "C" AGGDLL AggRendererSmooth* AggRendererSmoothNew(AggBuffer* buffer);
extern "C" AGGDLL void				AggRendererSmoothColor(AggRendererSmooth* renderer, double r, double g, double b, double a);
extern "C" AGGDLL void				AggRendererSmoothSetup(AggRendererSmooth* renderer, double r1, double r2, double xx, double xy, double yx, double yy, double tx, double ty);
extern "C" AGGDLL void				AggRendererSmoothAddPath(AggRendererSmooth* renderer, AggPath* path);
extern "C" AGGDLL void				AggRendererSmoothDelete(AggRendererSmooth* renderer);

extern "C" AGGDLL AggRendererImage*	AggRendererImageNew(AggBuffer* buffer);
extern "C" AGGDLL void				AggRendererImageMatrix(AggRendererImage* renderer, double xx, double xy, double yx, double yy, double tx, double ty);
extern "C" AGGDLL void				AggRendererImageSource1(AggRendererImage* renderer, AggBuffer* buffer);
extern "C" AGGDLL void				AggRendererImageSource2(AggRendererImage* renderer, void* buffer, int dx, int dy, int stride);
extern "C" AGGDLL void				AggRendererImageSetStretchMode(AggRendererImage* renderer, int mode);
extern "C" AGGDLL void				AggRendererImageDelete(AggRendererImage* renderer);

extern "C" AGGDLL AggRendererGradient* AggRendererGradientNew(AggBuffer* buffer);
extern "C" AGGDLL void				AggRendererGradientDelete(AggRendererGradient* renderer);
extern "C" AGGDLL void				AggRendererGradientSelect(AggRendererGradient* renderer, int id);
extern "C" AGGDLL void				AggRendererGradientRange(AggRendererGradient* renderer, double r1, double r2);
extern "C" AGGDLL void				AggRendererGradientMatrix(AggRendererGradient* renderer, double xx, double xy, double yx, double yy, double tx, double ty);
extern "C" AGGDLL void				AggRendererGradientColor1(AggRendererGradient* renderer, const double r[256], const double g[256], const double b[256], const double a[256]);
extern "C" AGGDLL void				AggRendererFill4Colors(AggRendererBase* renderer, int x, int y, int dx, int dy, double r1, double g1, double b1, double r2, double g2, double b2, double r3, double g3, double b3, double r4, double g4, double b4);

/*****************************************************************************/
/*	from agg_path.cpp														 */

extern "C" AGGDLL AggPath*			AggPathNew();
extern "C" AGGDLL void				AggPathDelete(AggPath* path);
extern "C" AGGDLL void				AggPathMoveTo(AggPath* path, double x, double y);
extern "C" AGGDLL void				AggPathLineTo(AggPath* path, double x, double y);
extern "C" AGGDLL void				AggPathCurve3(AggPath* path, double x_c, double y_c, double x, double y);
extern "C" AGGDLL void				AggPathCurve4(AggPath* path, double x_c1, double y_c1, double x_c2, double y_c2, double x, double y);
extern "C" AGGDLL void				AggPathClose(AggPath* path);
extern "C" AGGDLL void				AggPathAddNewPath(AggPath* path);
extern "C" AGGDLL void				AggPathAppendGlyph(AggPath* path, agg::font_face* face, int glyph, double xx, double xy, double yx, double yy, double tx, double ty, double bold);
extern "C" AGGDLL void				AggPathAppendPath(AggPath* path, AggPath* path2, double xx, double xy, double yx, double yy, double tx, double ty, double scale, double bold);
extern "C" AGGDLL void				AggPathAppendPathStroke(AggPath* path, AggPath* path2, double width, int cap, int join, double miter_limit, double scale, bool curved);
extern "C" AGGDLL void				AggPathAppendArc(AggPath* path, double x, double y, double rx, double ry, double a1, double a2, bool ccw, double scale, bool continue_path);
extern "C" AGGDLL void				AggPathAppendDashedPath(AggPath* path, AggPath* dash, double scale);
extern "C" AGGDLL void				AggPathCombinePathsUsingGpc(AggPath* path1, AggPath* path2, AggPath* result, int op);
extern "C" AGGDLL void				AggPathComputeBounds(AggPath* path, double& x1, double& y1, double& x2, double& y2);
extern "C" AGGDLL void				AggPathRemoveAll(AggPath* path);
extern "C" AGGDLL int				AggPathElemCount(AggPath* path);
extern "C" AGGDLL void				AggPathElemGet(AggPath* path, int n, int* types, double* x, double* y);
extern "C" AGGDLL void				AggPathDashReset(AggPath* path);
extern "C" AGGDLL void				AggPathDashAdd(AggPath* path, double dash_len, double gap_len);
extern "C" AGGDLL void				AggPathDashSetStart(AggPath* path, double dash_start);

/*****************************************************************************/
/*	from agg_font.cpp														 */

extern "C" AGGDLL void*				AggFontCreateFaceFromFontData(const void* data, size_t size, void* os_handle);
extern "C" AGGDLL void				AggFontDisposeFace(agg::font_face* face);

extern "C" AGGDLL double			AggFontPixelCacheFill(AggBuffer* buffer, agg::font_face* face, const unsigned short* glyphs, int length, double scale, double ox, double oy, double r, double g, double b, double a);
extern "C" AGGDLL bool				AggFontGetUnicodeName(int code, wchar_t* max_path_buffer);

/*****************************************************************************/
