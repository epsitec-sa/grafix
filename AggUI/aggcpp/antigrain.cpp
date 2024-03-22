#include "antigrain.h"
#include <iostream>
#include "screeninfo/screeninfo.h"

namespace ScreenInfo {
    extern "C" DECLSPEC void GetScreenResolution(int &width, int &height){
        std::cout << "[C++] GetScreenResolution" << std::endl;
        getScreenResolution(width, height);
    }
}

namespace AntigrainCPP {

    // ************************************************************************ 
    //                               Application                                
    // ************************************************************************ 

    Application::Application(
        bool flip_y,
        void (*on_draw)(),
        void (*on_resize)(int sx, int sy),
        void (*on_mouse_move)(int x, int y, unsigned flags),
        void (*on_mouse_button_down)(int x, int y, unsigned flags),
        void (*on_mouse_button_up)(int x, int y, unsigned flags),
        void (*on_key)(int x, int y, unsigned key, unsigned flags)
    ) : agg::platform_support(pix_format, flip_y),
        on_draw_callback(on_draw),
        on_resize_callback(on_resize),
        on_mouse_move_callback(on_mouse_move),
        on_mouse_button_down_callback(on_mouse_button_down),
        on_mouse_button_up_callback(on_mouse_button_up),
        on_key_callback(on_key)
    {}

    // Exported methods -----------------------------

    void Application::set_color(int r, int g, int b){
        renderer_solid->color(agg::srgba8(r, g, b));
    }

    void Application::draw_ellipse(double x, double y, double rx, double ry){
        /* std::cout << "[C++] draw ellipse" << std::endl; */
        agg::rasterizer_scanline_aa<> ras;
        agg::scanline_p8 sl;
        agg::ellipse e;
        e.init(x, y, rx, ry);
        ras.add_path(e);
        agg::render_scanlines(ras, sl, *renderer_solid);
    }

    // Internal event handlers -----------------------------

    void Application::on_draw(){
        // initialise drawing functions
        pixfmt pixf(rbuf_window());
        renderer_base_t renderer_base(pixf);
        renderer_solid.reset(new renderer_solid_t(renderer_base));

        renderer_base.clear(agg::rgba(1,1,1));

        // call user-defined drawing
        if (on_draw_callback){
            on_draw_callback();
        }
    }

    void Application::on_resize(int sx, int sy){
        if (on_resize_callback){
            on_resize_callback(sx, sy);
        }
    }

    void Application::on_mouse_move(int x, int y, unsigned flags){
        if (on_mouse_move_callback){
            on_mouse_move_callback(x, y, flags);
        }
    }

    void Application::on_mouse_button_down(int x, int y, unsigned flags){
        if (on_mouse_button_down_callback){
            on_mouse_button_down_callback(x, y, flags);
        }
    }

    void Application::on_mouse_button_up(int x, int y, unsigned flags){
        if (on_mouse_button_up_callback){
            on_mouse_button_up_callback(x, y, flags);
        }
    }

    void Application::on_key(int x, int y, unsigned key, unsigned flags){
        if (on_key_callback){
            on_key_callback(x, y, key, flags);
        }
    }

    // ************************************************************************ 

    extern "C" Application* NewApplication(
        bool flip_y,
        void (*on_draw)(),
        void (*on_resize)(int sx, int sy),
        void (*on_mouse_move)(int x, int y, unsigned flags),
        void (*on_mouse_button_down)(int x, int y, unsigned flags),
        void (*on_mouse_button_up)(int x, int y, unsigned flags),
        void (*on_key)(int x, int y, unsigned key, unsigned flags)
    ){
        std::cout << "[C++] new platform_support(flip_y=" << flip_y << ")" << std::endl;
        return new Application(
            flip_y,
            on_draw,
            on_resize,
            on_mouse_move,
            on_mouse_button_down,
            on_mouse_button_up,
            on_key
        );
    }

    extern "C" void Application_Caption(Application* app, const char* text){
        std::cout << "[C++] Application Caption" << std::endl;
        app->caption(text);
    }

    extern "C" bool Application_Init(Application* app, 
                                         unsigned width, unsigned height,
                                         agg::window_flag_e flags){
        std::cout << "[C++] Application Init" << std::endl;
        return app->init(width, height, flags);
    }

    extern "C" int Application_Run(Application* app){
        std::cout << "[C++] Application Run" << std::endl;
        return app->run();
    }

    extern "C" void Application_ForceRedraw(Application* app){
        app->force_redraw();
    }

    extern "C" void Application_SetColor(Application* app, int r, int g, int b){
        app->set_color(r, g, b);
    }

    extern "C" void Application_DrawEllipse(Application* app,
                                            double x, double y,
                                            double rx, double ry){
        app->draw_ellipse(x, y, rx, ry);
    }
}

int agg_main(int argc, char* argv[]){
    return 1;
}
