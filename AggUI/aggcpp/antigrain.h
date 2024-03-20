#pragma once

#include <memory> // unique_ptr


#if defined(_WIN32)
#  if defined(EXPORTING_ANTIGRAIN_CPP)
#    define DECLSPEC __declspec(dllexport)
#  else
#    define DECLSPEC __declspec(dllimport)
#  endif
#else // non windows
#  define DECLSPEC
#endif

#include "platform/agg_platform_support.h"

// ************************* drawing ********************************
#include "agg_rasterizer_scanline_aa.h"
#include "agg_scanline_p.h"
#include "agg_ellipse.h"

#include "agg_pixfmt_rgb.h"
const agg::pix_format_e pix_format = agg::pix_format_bgr24;
typedef agg::pixfmt_bgr24 pixfmt;
typedef agg::pixfmt_bgr24_pre pixfmt_pre;
#define pixfmt_gamma agg::pixfmt_bgr24_gamma
typedef agg::rgba8 color_type;
typedef agg::order_bgr component_order;
typedef agg::gray8 gray_type;

typedef agg::renderer_base<pixfmt> renderer_base_t;
typedef agg::renderer_scanline_aa_solid<renderer_base_t> renderer_solid_t;
// ******************************************************************

namespace ScreenInfo {
	extern "C" DECLSPEC void GetScreenResolution(int &width, int &height);
}

namespace AntigrainCPP {
    class Application : public agg::platform_support {
        public:
            Application(
                bool flip_y,
                void (*on_draw)(),
                void (*on_resize)(int sx, int sy),
                void (*on_mouse_move)(int x, int y, unsigned flags),
                void (*on_mouse_button_down)(int x, int y, unsigned flags),
                void (*on_mouse_button_up)(int x, int y, unsigned flags),
                void (*on_key)(int x, int y, unsigned key, unsigned flags)
            );
            void set_color(int r, int g, int b);
            void draw_ellipse(double x, double y, double rx, double ry);
        private:
            // user callbacks
            void (*on_resize_callback)(int sx, int sy);
            void (*on_mouse_move_callback)(int x, int y, unsigned flags);
            void (*on_mouse_button_down_callback)(int x, int y, unsigned flags);
            void (*on_mouse_button_up_callback)(int x, int y, unsigned flags);
            void (*on_key_callback)(int x, int y, unsigned key, unsigned flags);
            void (*on_draw_callback)();

            // event handlers
            void on_resize(int sx, int sy);
            void on_mouse_move(int x, int y, unsigned flags);
            void on_mouse_button_down(int x, int y, unsigned flags);
            void on_mouse_button_up(int x, int y, unsigned flags);
            void on_key(int x, int y, unsigned key, unsigned flags);
            void on_draw();

            // renderers
            std::unique_ptr<renderer_solid_t> renderer_solid;
    };

    extern "C" DECLSPEC Application* NewApplication(
        bool flip_y,
        void (*on_draw)(),
        void (*on_resize)(int sx, int sy),
        void (*on_mouse_move)(int x, int y, unsigned flags),
        void (*on_mouse_button_down)(int x, int y, unsigned flags),
        void (*on_mouse_button_up)(int x, int y, unsigned flags),
        void (*on_key)(int x, int y, unsigned key, unsigned flags)
    );

    extern "C" DECLSPEC void Application_Caption(Application* ps, 
        const char* text
    );

    extern "C" DECLSPEC bool Application_Init(Application* ps,
        unsigned width, unsigned height,
        agg::window_flag_e flags
    );

    extern "C" DECLSPEC int Application_Run(Application* ps);

    extern "C" DECLSPEC void Application_ForceRedraw(Application* ps);

    extern "C" DECLSPEC void Application_SetColor(Application* ps,
        int r, int g, int b
    );

    extern "C" DECLSPEC void Application_DrawEllipse(Application* ps,
        double x, double y,
        double rx, double ry
    );
}

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
/*	from agg_buffer.cpp														 */

extern "C" DECLSPEC AggBuffer*		AggBufferNew(unsigned dx, unsigned dy, unsigned bpp);
extern "C" DECLSPEC AggBuffer*		AggBufferNewFrom(unsigned dx, unsigned dy, unsigned bpp, int stride, void* bits, bool copy_bits);
extern "C" DECLSPEC bool				AggBufferResize(AggBuffer* buffer, unsigned dx, unsigned dy, unsigned bpp);
extern "C" DECLSPEC void				AggBufferDrawGlyphs(AggBuffer* buffer, void* hfont, int x, int y, unsigned short* glyphs, int* dx_array, unsigned int count, unsigned int color);
extern "C" DECLSPEC void				AggBufferPaint(AggBuffer* buffer, void* hdc, int x1, int y1, int x2, int y2);
extern "C" DECLSPEC void				AggBufferPaintOffset(AggBuffer* buffer, void* hdc, int ox, int oy, int x1, int y1, int x2, int y2);
extern "C" DECLSPEC void				AggBufferBlendOffset(AggBuffer* buffer, void* hdc, int ox, int oy, int x1, int y1, int x2, int y2);
extern "C" DECLSPEC void				AggBufferClear(AggBuffer* buffer);
extern "C" DECLSPEC void				AggBufferClearRect(AggBuffer* buffer, int x1, int y1, int x2, int y2);
extern "C" DECLSPEC void				AggBufferGetMemoryLayout(AggBuffer* buffer, int & dx, int & dy, int & stride, void*& memory);
extern "C" DECLSPEC void*             AggBufferGetMemoryBitmapHandle(AggBuffer* buffer);
extern "C" DECLSPEC void				AggBufferDelete(AggBuffer* buffer);
extern "C" DECLSPEC void				AggBufferInfiniteClipping(AggBuffer* buffer);
extern "C" DECLSPEC void				AggBufferEmptyClipping(AggBuffer* buffer);
extern "C" DECLSPEC void				AggBufferAddClipBox(AggBuffer* buffer, int x1, int y1, int x2, int y2);
extern "C" DECLSPEC void				AggBufferBltBuffer(AggBuffer* buffer, int xd, int yd, AggBuffer* source, int xs, int ys, int dx, int dy);
extern "C" DECLSPEC void				AggBufferComposeBuffer(AggBuffer* buffer, int xd, int yd, AggBuffer* source, int xs, int ys, int dx, int dy);

/*****************************************************************************/
/*	from agg_rasterizer.cpp													 */

extern "C" DECLSPEC AggRasterizer*	AggRasterizerNew();
extern "C" DECLSPEC void				AggRasterizerClear(AggRasterizer* rasterizer);
extern "C" DECLSPEC void				AggRasterizerFillingRule(AggRasterizer* rasterizer, int rule);
extern "C" DECLSPEC bool				AggRasterizerHitTest(AggRasterizer* rasterizer, int x, int y);
extern "C" DECLSPEC void				AggRasterizerGamma(AggRasterizer* rasterizer, double gamma);
extern "C" DECLSPEC void				AggRasterizerSetTransform(AggRasterizer* rasterizer, double xx, double xy, double yx, double yy, double tx, double ty);
extern "C" DECLSPEC void				AggRasterizerSetClipBox(AggRasterizer* rasterizer, double x1, double y1, double x2, double y2);
extern "C" DECLSPEC void				AggRasterizerResetClipBox(AggRasterizer* rasterizer);
extern "C" DECLSPEC void				AggRasterizerAddPath(AggRasterizer* rasterizer, AggPath* path, bool curved);
extern "C" DECLSPEC void				AggRasterizerAddGlyph(AggRasterizer* rasterizer, agg::font_face* face, int glyph, double x, double y, double scale);
extern "C" DECLSPEC void				AggRasterizerAddGlyphXY(AggRasterizer* rasterizer, agg::font_face* face, int glyph, double x, double y, double scale_x, double scale_y);
extern "C" DECLSPEC double			AggRasterizerAddText(AggRasterizer* rasterizer, agg::font_face* face, const wchar_t* text, int mode, double xx, double xy, double yx, double yy, double tx, double ty);
extern "C" DECLSPEC void				AggRasterizerAddPathStroke1(AggRasterizer* rasterizer, AggPath* path, double width, bool curved);
extern "C" DECLSPEC void				AggRasterizerAddPathStroke2(AggRasterizer* rasterizer, AggPath* path, double width, int cap, int join, double miter_limit, bool curved);
extern "C" DECLSPEC void				AggRasterizerRenderSolid(AggRasterizer* rasterizer, AggRendererSolid* renderer);
extern "C" DECLSPEC void				AggRasterizerRenderImage(AggRasterizer* rasterizer, AggRendererImage* renderer);
extern "C" DECLSPEC void				AggRasterizerRenderGradient(AggRasterizer* rasterizer, AggRendererGradient* renderer);
extern "C" DECLSPEC void				AggRasterizerDelete(AggRasterizer* rasterizer);

/*****************************************************************************/
/*	from agg_renderer.cpp													 */

extern "C" DECLSPEC void				AggRendererSolidSetAlphaMask(AggRendererSolid* renderer, AggBuffer* buffer, int component);
extern "C" DECLSPEC void				AggRendererSmoothSetAlphaMask(AggRendererSmooth* renderer, AggBuffer* buffer, int component);
extern "C" DECLSPEC void				AggRendererImageSetAlphaMask(AggRendererImage* renderer, AggBuffer* buffer, int component);
extern "C" DECLSPEC void				AggRendererGradientSetAlphaMask(AggRendererGradient* renderer, AggBuffer* buffer, int component);

extern "C" DECLSPEC AggRendererSolid*	AggRendererSolidNew(AggBuffer* buffer);
extern "C" DECLSPEC void				AggRendererSolidClear(AggRendererSolid* renderer, double r, double g, double b, double a);
extern "C" DECLSPEC void				AggRendererSolidColor(AggRendererSolid* renderer, double r, double g, double b, double a);
extern "C" DECLSPEC void				AggRendererSolidDelete(AggRendererSolid* renderer);

extern "C" DECLSPEC AggRendererSmooth* AggRendererSmoothNew(AggBuffer* buffer);
extern "C" DECLSPEC void				AggRendererSmoothColor(AggRendererSmooth* renderer, double r, double g, double b, double a);
extern "C" DECLSPEC void				AggRendererSmoothSetup(AggRendererSmooth* renderer, double r1, double r2, double xx, double xy, double yx, double yy, double tx, double ty);
extern "C" DECLSPEC void				AggRendererSmoothAddPath(AggRendererSmooth* renderer, AggPath* path);
extern "C" DECLSPEC void				AggRendererSmoothDelete(AggRendererSmooth* renderer);

extern "C" DECLSPEC AggRendererImage*	AggRendererImageNew(AggBuffer* buffer);
extern "C" DECLSPEC void				AggRendererImageMatrix(AggRendererImage* renderer, double xx, double xy, double yx, double yy, double tx, double ty);
extern "C" DECLSPEC void				AggRendererImageSource1(AggRendererImage* renderer, AggBuffer* buffer);
extern "C" DECLSPEC void				AggRendererImageSource2(AggRendererImage* renderer, void* buffer, int dx, int dy, int stride);
extern "C" DECLSPEC void				AggRendererImageSetStretchMode(AggRendererImage* renderer, int mode, double radius);
extern "C" DECLSPEC void				AggRendererImageDelete(AggRendererImage* renderer);

extern "C" DECLSPEC AggRendererGradient* AggRendererGradientNew(AggBuffer* buffer);
extern "C" DECLSPEC void				AggRendererGradientDelete(AggRendererGradient* renderer);
extern "C" DECLSPEC void				AggRendererGradientSelect(AggRendererGradient* renderer, int id);
extern "C" DECLSPEC void				AggRendererGradientRange(AggRendererGradient* renderer, double r1, double r2);
extern "C" DECLSPEC void				AggRendererGradientMatrix(AggRendererGradient* renderer, double xx, double xy, double yx, double yy, double tx, double ty);
extern "C" DECLSPEC void				AggRendererGradientColor1(AggRendererGradient* renderer, const double r[256], const double g[256], const double b[256], const double a[256]);
extern "C" DECLSPEC void				AggRendererFill4Colors(AggRendererBase* renderer, int x, int y, int dx, int dy, double r1, double g1, double b1, double r2, double g2, double b2, double r3, double g3, double b3, double r4, double g4, double b4);

/*****************************************************************************/
/*	from agg_path.cpp														 */

extern "C" DECLSPEC AggPath*			AggPathNew();
extern "C" DECLSPEC void				AggPathDelete(AggPath* path);
extern "C" DECLSPEC void				AggPathMoveTo(AggPath* path, double x, double y);
extern "C" DECLSPEC void				AggPathLineTo(AggPath* path, double x, double y);
extern "C" DECLSPEC void				AggPathCurve3(AggPath* path, double x_c, double y_c, double x, double y);
extern "C" DECLSPEC void				AggPathCurve4(AggPath* path, double x_c1, double y_c1, double x_c2, double y_c2, double x, double y);
extern "C" DECLSPEC void				AggPathClose(AggPath* path);
extern "C" DECLSPEC void				AggPathAddNewPath(AggPath* path);
extern "C" DECLSPEC void				AggPathAppendGlyph(AggPath* path, agg::font_face* face, int glyph, double xx, double xy, double yx, double yy, double tx, double ty, double bold);
extern "C" DECLSPEC void				AggPathAppendPath(AggPath* path, AggPath* path2, double xx, double xy, double yx, double yy, double tx, double ty, double scale, double bold);
extern "C" DECLSPEC void				AggPathAppendPathStroke(AggPath* path, AggPath* path2, double width, int cap, int join, double miter_limit, double scale, bool curved);
extern "C" DECLSPEC void				AggPathAppendArc(AggPath* path, double x, double y, double rx, double ry, double a1, double a2, bool ccw, double scale, bool continue_path);
extern "C" DECLSPEC void				AggPathAppendDashedPath(AggPath* path, AggPath* dash, double scale);
extern "C" DECLSPEC void				AggPathCombinePathsUsingGpc(AggPath* path1, AggPath* path2, AggPath* result, int op);
extern "C" DECLSPEC void				AggPathComputeBounds(AggPath* path, double& x1, double& y1, double& x2, double& y2);
extern "C" DECLSPEC void				AggPathRemoveAll(AggPath* path);
extern "C" DECLSPEC int				AggPathElemCount(AggPath* path);
extern "C" DECLSPEC void				AggPathElemGet(AggPath* path, int n, int* types, double* x, double* y);
extern "C" DECLSPEC void				AggPathDashReset(AggPath* path);
extern "C" DECLSPEC void				AggPathDashAdd(AggPath* path, double dash_len, double gap_len);
extern "C" DECLSPEC void				AggPathDashSetStart(AggPath* path, double dash_start);

/*****************************************************************************/
/*	from agg_font.cpp														 */

extern "C" DECLSPEC void*				AggFontCreateFaceFromFontData(const void* data, size_t size, size_t offset, void* os_handle);
extern "C" DECLSPEC void				AggFontDisposeFace(agg::font_face* face);

extern "C" DECLSPEC double			AggFontPixelCacheFill(AggBuffer* buffer, agg::font_face* face, const unsigned short* glyphs, int length, double scale, double ox, double oy, double r, double g, double b, double a);
extern "C" DECLSPEC void				AggFontPixelCacheGlyphXY(AggBuffer* buffer, agg::font_face* face, unsigned short glyph, double ox, double oy, double scale_x, double scale_y, double r, double g, double b, double a);
extern "C" DECLSPEC bool				AggFontGetUnicodeName(int code, wchar_t* max_path_buffer);

/*****************************************************************************/
