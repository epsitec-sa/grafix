#include <stdio.h>
#include "agg_basics.h"
#include "agg_rendering_buffer.h"
#include "agg_rasterizer_scanline_aa.h"
#include "agg_scanline_u.h"
#include "agg_renderer_scanline.h"
#include "agg_span_gradient.h"
#include "agg_span_gradient_alpha.h"
#include "agg_span_interpolator_linear.h"
#include "agg_span_converter.h"
#include "agg_ellipse.h"
#include "agg_vcgen_stroke.h"
#include "agg_pixfmt_rgb24.h"
#include "platform/agg_platform_support.h"

#include "ctrl/agg_spline_ctrl.h"

enum { flip_y = true };


#include "agg_math.h"
#include "agg_dda_line.h"


class the_application : public agg::platform_support
{
    double m_x[3];
    double m_y[3];
    double m_dx;
    double m_dy;
    int    m_idx;
    agg::spline_ctrl<agg::rgba8> m_alpha;


public:
    the_application(agg::pix_format_e format, bool flip_y) :
        agg::platform_support(format, flip_y),
        m_idx(-1),
        m_alpha(2,  2,  200, 30,  6, !flip_y)
    {
        m_x[0] = 257;    m_y[0] = 60;
        m_x[1] = 369;   m_y[1] = 170;
        m_x[2] = 143;   m_y[2] = 310;

        m_alpha.point(0, 0.0,     0.0);
        m_alpha.point(1, 1.0/5.0, 1.0 - 4.0/5.0);
        m_alpha.point(2, 2.0/5.0, 1.0 - 3.0/5.0);
        m_alpha.point(3, 3.0/5.0, 1.0 - 2.0/5.0);
        m_alpha.point(4, 4.0/5.0, 1.0 - 1.0/5.0);
        m_alpha.point(5, 1.0,     1.0);
        m_alpha.update_spline();
        add_ctrl(m_alpha);
    }



    // A simple function to form the gradient color array 
    // consisting of 3 colors, "begin", "middle", "end"
    //---------------------------------------------------
    static void fill_color_array(agg::rgba8* array, 
                                 agg::rgba8 begin, 
                                 agg::rgba8 middle, 
                                 agg::rgba8 end)
    {
        unsigned i;
        for(i = 0; i < 128; ++i)
        {
            array[i] = begin.gradient(middle, i / 128.0);
        }
        for(; i < 256; ++i)
        {
            array[i] = middle.gradient(end, (i - 128) / 128.0);
        }
    }




    virtual void on_draw()
    {
        typedef agg::pixfmt_bgr24 pixfmt;
        typedef agg::renderer_base<pixfmt> base_ren_type;
        typedef agg::renderer_scanline_aa_solid<base_ren_type> renderer_solid;

        pixfmt pf(rbuf_window());
        base_ren_type ren_base(pf);
        renderer_solid ren_solid(ren_base);
        ren_base.clear(agg::rgba(1,1,1));

        agg::scanline_u8 sl;
        agg::rasterizer_scanline_aa<> ras;


        // Draw some background
        agg::ellipse ell;
        srand(1234);
        unsigned i;
        unsigned w = unsigned(width());
        unsigned h = unsigned(height());
        for(i = 0; i < 100; i++)
        {
            ell.init(rand() % w, rand() % h, rand() % 60 + 5, rand() % 60 + 5, 50);
            ren_solid.color(agg::rgba8(rand() & 0xFF, rand() & 0xFF, rand() & 0xFF, rand() & 0x7F));
            ras.add_path(ell);
            agg::render_scanlines(ras, sl, ren_solid);
        }



        double parallelogram[6];
        parallelogram[0] = m_x[0];
        parallelogram[1] = m_y[0];
        parallelogram[2] = m_x[1];
        parallelogram[3] = m_y[1];
        parallelogram[4] = m_x[2];
        parallelogram[5] = m_y[2];


        // Gradient shape function (linear, radial, custom, etc)
        //-----------------
        typedef agg::gradient_circle gradient_func_type;   

        // Alpha gradient shape function (linear, radial, custom, etc)
        //-----------------
        typedef agg::gradient_xy gradient_alpha_func_type;

        // Span interpolator. This object is used in all span generators 
        // that operate with transformations during iterating of the spans,
        // for example, image transformers use the interpolator too.
        //-----------------
        typedef agg::span_interpolator_linear<> interpolator_type;


        // Span allocator is an object that allocates memory for 
        // the array of colors that will be used to render the 
        // color spans. One object can be shared between different 
        // span generators.
        //-----------------
        typedef agg::span_allocator<agg::rgba8> span_allocator_type;


        // Finally, the gradient span generator working with the agg::rgba8 
        // color type. 
        // The 4-th argument is the color function that should have 
        // the [] operator returning the color in range of [0...255].
        // In our case it will be a simple look-up table of 256 colors.
        //-----------------
        typedef agg::span_gradient<agg::rgba8, 
                                   interpolator_type, 
                                   gradient_func_type, 
                                   const agg::rgba8*,
                                   span_allocator_type> span_gradient_type;


        // The alpha gradient span converter working with the agg::rgba8 
        // color type. 
        // The 4-th argument is the alpha function that should have 
        // the [] operator returning the alpha in range of [0...255].
        // In our case it will be a simple look-up table of 256 unsigned chars.
        //-----------------
        typedef agg::span_gradient_alpha<agg::rgba8, 
                                         interpolator_type, 
                                         gradient_alpha_func_type, 
                                         const agg::int8u*> span_gradient_alpha_type;


        // Span converter type
        //-----------------
        typedef agg::span_converter<span_gradient_type,
                                    span_gradient_alpha_type> span_conv_type;



        // The gradient (plus span converter) renderer type
        //-----------------
        typedef agg::renderer_scanline_aa<base_ren_type, 
                                          span_conv_type> renderer_gradient_type;


        // The gradient objects declarations
        //----------------
        gradient_func_type       gradient_func;                      // The gradient function
        gradient_alpha_func_type alpha_func;                         // The gradient function
        agg::trans_affine        gradient_mtx;                       // Gradient affine transformer
        agg::trans_affine        alpha_mtx;                          // Alpha affine transformer
        interpolator_type        span_interpolator(gradient_mtx);    // Span gradient interpolator
        interpolator_type        span_interpolator_alpha(alpha_mtx); // Span alpha interpolator
        span_allocator_type      span_allocator;                     // Span Allocator
        agg::rgba8               color_array[256];                   // The gradient colors

        // Declare the gradient span itself. 
        // The last two arguments are so called "d1" and "d2" 
        // defining two distances in pixels, where the gradient starts
        // and where it ends. The actual meaning of "d1" and "d2" depands
        // on the gradient function.
        //----------------
        span_gradient_type span_gradient(span_allocator, 
                                         span_interpolator, 
                                         gradient_func, 
                                         color_array, 
                                         0, 150);

        // Declare the gradient span itself. 
        // The last two arguments are so called "d1" and "d2" 
        // defining two distances in pixels, where the gradient starts
        // and where it ends. The actual meaning of "d1" and "d2" depands
        // on the gradient function.
        //----------------
        span_gradient_alpha_type span_gradient_alpha(span_interpolator_alpha, 
                                                     alpha_func, 
                                                     m_alpha.spline8(), 
                                                     0, 100);

        // Span converter declaration
        span_conv_type span_conv(span_gradient, span_gradient_alpha);

        // The gradient renderer
        //----------------
        renderer_gradient_type ren_gradient(ren_base, span_conv);


        // Finally we can draw a circle.
        //----------------
        gradient_mtx *= agg::trans_affine_scaling(0.75, 1.2);
        gradient_mtx *= agg::trans_affine_rotation(-agg::pi/3.0);
        gradient_mtx *= agg::trans_affine_translation(width()/2, height()/2);
        gradient_mtx.invert();
        alpha_mtx.parl_to_rect(parallelogram, -100, -100, 100, 100);
        fill_color_array(color_array, 
                         agg::rgba8(0,50,50), 
                         agg::rgba8(180, 180, 50),
                         agg::rgba8(80, 0, 0));

        ell.init(width()/2, height()/2, 150, 150, 100);
        ras.add_path(ell);

        agg::render_scanlines(ras, sl, ren_gradient);




        // Draw the control points and the parallelogram
        //-----------------
        ren_solid.color(agg::rgba8(0, 100, 100, 80));
        ell.init(m_x[0], m_y[0], 5, 5, 20);
        ras.add_path(ell);
        agg::render_scanlines(ras, sl, ren_solid);
        ell.init(m_x[1], m_y[1], 5, 5, 20);
        ras.add_path(ell);
        agg::render_scanlines(ras, sl, ren_solid);
        ell.init(m_x[2], m_y[2], 5, 5, 20);
        ras.add_path(ell);
        agg::render_scanlines(ras, sl, ren_solid);

        agg::vcgen_stroke stroke;
        stroke.add_vertex(m_x[0], m_y[0], agg::path_cmd_move_to);
        stroke.add_vertex(m_x[1], m_y[1], agg::path_cmd_line_to);
        stroke.add_vertex(m_x[2], m_y[2], agg::path_cmd_line_to);
        stroke.add_vertex(m_x[0]+m_x[2]-m_x[1], m_y[0]+m_y[2]-m_y[1], agg::path_cmd_line_to);
        stroke.add_vertex(0, 0, agg::path_cmd_end_poly | agg::path_flags_close);
        ren_solid.color(agg::rgba8(0, 0, 0));
        ras.add_path(stroke);
        agg::render_scanlines(ras, sl, ren_solid);

        agg::render_ctrl(ras, sl, ren_solid, m_alpha);
    }





    virtual void on_mouse_button_down(int x, int y, unsigned flags)
    {
        unsigned i;
        if(flags & agg::mouse_left)
        {
            for (i = 0; i < 3; i++)
            {
                if(sqrt( (x-m_x[i]) * (x-m_x[i]) + (y-m_y[i]) * (y-m_y[i]) ) < 10.0)
                {
                    m_dx = x - m_x[i];
                    m_dy = y - m_y[i];
                    m_idx = i;
                    break;
                }
            }
            if(i == 3)
            {
                if(agg::point_in_triangle(m_x[0], m_y[0], 
                                          m_x[1], m_y[1],
                                          m_x[2], m_y[2],
                                          x, y))
                {
                    m_dx = x - m_x[0];
                    m_dy = y - m_y[0];
                    m_idx = 3;
                }

            }
        }
    }


    virtual void on_mouse_move(int x, int y, unsigned flags)
    {
        if(flags & agg::mouse_left)
        {
            if(m_idx == 3)
            {
                double dx = x - m_dx;
                double dy = y - m_dy;
                m_x[1] -= m_x[0] - dx;
                m_y[1] -= m_y[0] - dy;
                m_x[2] -= m_x[0] - dx;
                m_y[2] -= m_y[0] - dy;
                m_x[0] = dx;
                m_y[0] = dy;
                force_redraw();
                return;
            }

            if(m_idx >= 0)
            {
                m_x[m_idx] = x - m_dx;
                m_y[m_idx] = y - m_dy;
                force_redraw();
            }
        }
        else
        {
            on_mouse_button_up(x, y, flags);
        }
    }

    virtual void on_mouse_button_up(int x, int y, unsigned flags)
    {
        m_idx = -1;
    }

    
    virtual void on_key(int x, int y, unsigned key, unsigned flags)
    {
        double dx = 0;
        double dy = 0;
        switch(key)
        {
        case agg::key_left:  dx = -0.1; break;
        case agg::key_right: dx =  0.1; break;
        case agg::key_up:    dy =  0.1; break;
        case agg::key_down:  dy = -0.1; break;
        }
        m_x[0] += dx;
        m_y[0] += dy;
        m_x[1] += dx;
        m_y[1] += dy;
        force_redraw();
    }


};


int agg_main(int argc, char* argv[])
{
    the_application app(agg::pix_format_bgr24, flip_y);
    app.caption("AGG Example. Alpha channel gradient");

    if(app.init(400, 320, agg::window_resize))
    {
        return app.run();
    }
    return 1;
}

