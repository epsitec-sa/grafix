#include "antigrain.h"
#include <iostream>
#include "screeninfo/screeninfo.h"

namespace ScreenInfo {
    void GetScreenResolution(int &width, int &height){
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
        void (*on_draw)(GraphicContext* gctx),
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
        on_key_callback(on_key),
        font_manager()
    {
    }

    // Internal event handlers -----------------------------

    void Application::on_draw(){
        std::cout << "[C++] Application on_draw" << std::endl;
        // initialise drawing context
        GraphicContext context(rbuf_window(), font_manager);

        // call user-defined drawing
        if (on_draw_callback){
            std::cout << "[C++] Call user on_draw" << std::endl;
            on_draw_callback(&context);
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

    Application* NewApplication(
        bool flip_y,
        void (*on_draw)(GraphicContext* gctx),
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

    void Application_Caption(Application* app, const char* text){
        std::cout << "[C++] Application Caption" << std::endl;
        app->caption(text);
    }

    bool Application_Init(Application* app, 
                                         unsigned width, unsigned height,
                                         agg::window_flag_e flags){
        std::cout << "[C++] Application Init" << std::endl;
        return app->init(width, height, flags);
    }

    int Application_Run(Application* app){
        std::cout << "[C++] Application Run" << std::endl;
        return app->run();
    }

    void Application_ForceRedraw(Application* app){
        app->force_redraw();
    }

    FontManager* Application_GetFontManager(Application* app){
        return &(app->font_manager);
    }
}

int agg_main(int argc, char* argv[]){
    return 1;
}
