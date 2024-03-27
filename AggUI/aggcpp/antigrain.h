#pragma once

//#include <memory> // unique_ptr

#include "declspec.h"
#include "pixelfmt.h"
#include "graphic_context.h"

#include "platform/agg_platform_support.h"


// ******************************************************************

namespace ScreenInfo {
    extern "C" DECLSPEC void GetScreenResolution(int &width, int &height);
}

namespace AntigrainCPP {

    class Application : public agg::platform_support {
        public:
            Application(
                bool flip_y,
                void (*on_draw)(GraphicContext* gctx),
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
            void (*on_draw_callback)(GraphicContext* gctx);

            // event handlers
            void on_resize(int sx, int sy);
            void on_mouse_move(int x, int y, unsigned flags);
            void on_mouse_button_down(int x, int y, unsigned flags);
            void on_mouse_button_up(int x, int y, unsigned flags);
            void on_key(int x, int y, unsigned key, unsigned flags);
            void on_draw();
    };

    extern "C" DECLSPEC Application* NewApplication(
        bool flip_y,
        void (*on_draw)(GraphicContext* gctx),
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

}

/*****************************************************************************/

//#if defined(AGG_DUMMY_TYPES)

/*
 *  If we just want to expose the raw API entry points (which are plain "C"
 *  functions) we don't need to know precisely about all the internal types
 *  which are required.
 *
 *  We map structures to void and enums to int.
 */

/*
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
*/


