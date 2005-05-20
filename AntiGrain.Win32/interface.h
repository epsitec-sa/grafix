#pragma once

#include "DLL.h"

extern "C" AGGDLL bool AggInitialise();
extern "C" AGGDLL void AggShutDown();
extern "C" AGGDLL const wchar_t* AggGetVersion();
extern "C" AGGDLL const wchar_t* AggGetProductName();

#if	defined(AGG_DUMMY_TYPES)
typedef void AggBuffer;
typedef void AggPath;
typedef void AggRasterizer;
typedef void AggRendererGradient;
typedef void AggRendererImage;
typedef void AggRendererSolid;
typedef void AggRendererSmooth;
typedef void AggRendererBase;
typedef void BreakContext;
typedef int  TextBreakMode;
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
struct BreakContext;
enum TextBreakMode;

namespace agg
{
	class font_face;
	class text_break;
}
#endif

extern "C" AGGDLL void				AggNoOp();
extern "C" AGGDLL void				AggNoOpString(const wchar_t* text);

extern "C" AGGDLL AggBuffer*		AggBufferNew(unsigned dx, unsigned dy, unsigned bpp);
extern "C" AGGDLL AggBuffer*		AggBufferNewUsingOS(void* hdc, unsigned dx, unsigned dy, unsigned bpp);
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

extern "C" AGGDLL AggRasterizer*	AggRasterizerNew();
extern "C" AGGDLL void				AggRasterizerClear(AggRasterizer* rasterizer);
extern "C" AGGDLL void				AggRasterizerFillingRule(AggRasterizer* rasterizer, int rule);
extern "C" AGGDLL void				AggRasterizerGamma(AggRasterizer* rasterizer, double gamma);
extern "C" AGGDLL void				AggRasterizerSetTransform(AggRasterizer* rasterizer, double xx, double xy, double yx, double yy, double tx, double ty);
extern "C" AGGDLL void				AggRasterizerSetClipBox(AggRasterizer* rasterizer, double x1, double y1, double x2, double y2);
extern "C" AGGDLL void				AggRasterizerResetClipBox(AggRasterizer* rasterizer);
extern "C" AGGDLL void				AggRasterizerAddPath(AggRasterizer* rasterizer, AggPath* path, bool curved);
extern "C" AGGDLL void				AggRasterizerAddGlyph(AggRasterizer* rasterizer, agg::font_face* face, int glyph, double x, double y, double scale);
extern "C" AGGDLL double			AggRasterizerAddText(AggRasterizer* rasterizer, agg::font_face* face, const wchar_t* text, int mode, double xx, double xy, double yx, double yy, double tx, double ty);
extern "C" AGGDLL void				AggRasterizerAddPathStroke1(AggRasterizer* rasterizer, AggPath* path, double width, bool curved);
extern "C" AGGDLL void				AggRasterizerAddPathStroke2(AggRasterizer* rasterizer, AggPath* path, double width, int cap, int join, double miter_limit, bool curved);
extern "C" AGGDLL void				AggRasterizerRenderSolid(AggRasterizer* rasterizer, AggRendererSolid* renderer);
extern "C" AGGDLL void				AggRasterizerRenderImage(AggRasterizer* rasterizer, AggRendererImage* renderer);
extern "C" AGGDLL void				AggRasterizerRenderGradient(AggRasterizer* rasterizer, AggRendererGradient* renderer);
extern "C" AGGDLL void				AggRasterizerDelete(AggRasterizer* rasterizer);

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
extern "C" AGGDLL void				AggRendererImageDelete(AggRendererImage* renderer);

extern "C" AGGDLL AggRendererGradient* AggRendererGradientNew(AggBuffer* buffer);
extern "C" AGGDLL void				AggRendererGradientDelete(AggRendererGradient* renderer);
extern "C" AGGDLL void				AggRendererGradientSelect(AggRendererGradient* renderer, int id);
extern "C" AGGDLL void				AggRendererGradientRange(AggRendererGradient* renderer, double r1, double r2);
extern "C" AGGDLL void				AggRendererGradientMatrix(AggRendererGradient* renderer, double xx, double xy, double yx, double yy, double tx, double ty);
extern "C" AGGDLL void				AggRendererGradientColor1(AggRendererGradient* renderer, const double r[256], const double g[256], const double b[256], const double a[256]);
extern "C" AGGDLL void				AggRendererFill4Colors(AggRendererBase* renderer, int x, int y, int dx, int dy, double r1, double g1, double b1, double r2, double g2, double b2, double r3, double g3, double b3, double r4, double g4, double b4);

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

extern "C" AGGDLL void				AggFontInitialise();
extern "C" AGGDLL int				AggFontGetFaceCount();
extern "C" AGGDLL agg::font_face*	AggFontGetFaceByRank(int n);
extern "C" AGGDLL agg::font_face*	AggFontGetFaceByName(const wchar_t* family, const wchar_t* style, const wchar_t* optical);
extern "C" AGGDLL const wchar_t*	AggFontFaceGetName(agg::font_face* face, int id);
extern "C" AGGDLL void*				AggFontFaceGetOsHandle(agg::font_face* face);
extern "C" AGGDLL double			AggFontFaceGetCaretSlope(agg::font_face* face);
extern "C" AGGDLL int				AggFontFaceGetGlyphIndex(agg::font_face* face, int unicode);
extern "C" AGGDLL double			AggFontFaceGetGlyphAdvance(agg::font_face* face, int glyph);
extern "C" AGGDLL double			AggFontFaceGetCharAdvance(agg::font_face* face, int unicode);
extern "C" AGGDLL double			AggFontFaceGetTextAdvance(agg::font_face* face, const wchar_t* text, int mode);
extern "C" AGGDLL void				AggFontFaceGetGlyphBounds(agg::font_face* face, int glyph, double& x_min, double& y_min, double& x_max, double& y_max);
extern "C" AGGDLL void				AggFontFaceGetCharBounds(agg::font_face* face, int unicode, double& x_min, double& y_min, double& x_max, double& y_max);
extern "C" AGGDLL void				AggFontFaceGetTextBounds(agg::font_face* face, const wchar_t* text, int mode, double& x_min, double& y_min, double& x_max, double& y_max);
extern "C" AGGDLL double			AggFontFaceGetMetrics(agg::font_face* face, int id);
extern "C" AGGDLL int				AggFontFaceGetTextCharEndXArray(agg::font_face* face, const wchar_t* text, int mode, double* x_array);

extern "C" AGGDLL double			AggFontPixelCacheFill(AggBuffer* buffer, agg::font_face* face, const wchar_t* text, double scale, double ox, double oy, double r, double g, double b, double a);

extern "C" AGGDLL BreakContext*		AggFontFaceBreakNew(agg::font_face* face, const wchar_t* text, TextBreakMode mode);
extern "C" AGGDLL const wchar_t*	AggFontFaceBreakIter(BreakContext* context, double& width, int& n_char);
extern "C" AGGDLL bool				AggFontFaceBreakHasMore(BreakContext* context);
extern "C" AGGDLL void				AggFontFaceBreakDelete(BreakContext* context);

extern "C" AGGDLL void				AggDebugGetCycles(unsigned int& h, unsigned int& l);
extern "C" AGGDLL int				AggDebugGetCycleDelta();
extern "C" AGGDLL void				AggDebugTrapZeroPointer();


extern "C" AGGDLL void				AggTextBreakInitialiseLineBreak(const void* data, size_t length);
extern "C" AGGDLL agg::text_break*	AggTextBreakNew();
extern "C" AGGDLL void				AggTextBreakDelete(agg::text_break* tb);
extern "C" AGGDLL bool				AggTextBreakIsValid(agg::text_break* tb);
extern "C" AGGDLL bool				AggTextBreakSetFontFaces(agg::text_break* tb, int n, agg::font_face** faces);
extern "C" AGGDLL bool				AggTextBreakSetTextRuns(agg::text_break* tb, int n, const unsigned short* run_lengths, const unsigned short* font_ids, const double* scales);
extern "C" AGGDLL bool				AggTextBreakSetText(agg::text_break* tb, const wchar_t* text, int mode);
extern "C" AGGDLL const	wchar_t*	AggTextBreakGetText(agg::text_break* tb);
extern "C" AGGDLL int				AggTextBreakGetTextLength(agg::text_break* tb);
extern "C" AGGDLL const unsigned char* AggTextBreakGetTextBreaks(agg::text_break* tb);
extern "C" AGGDLL void				AggTextBreakRewind(agg::text_break* tb);
extern "C" AGGDLL const wchar_t*	AggTextBreakFindNextBreak(agg::text_break* tb, double& width, int& n_chars);

extern "C" AGGDLL void				AggTextBreakSetFontFaceCount(agg::text_break* tb, int n);
extern "C" AGGDLL void				AggTextBreakSetNthFontFace(agg::text_break* tb, int nth, agg::font_face* face);
extern "C" AGGDLL void				AggTextBreakSetRunCount(agg::text_break* tb, int n);
extern "C" AGGDLL void				AggTextBreakSetNthRun(agg::text_break* tb, int nth, int run_length, int face_index, double scale);
extern "C" AGGDLL void				AggTextBreakHyphenate(agg::text_break* tb);
