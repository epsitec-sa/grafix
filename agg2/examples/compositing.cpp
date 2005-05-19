#include <stdio.h>
#include "agg_rendering_buffer.h"
#include "agg_rasterizer_scanline_aa.h"
#include "agg_scanline_u.h"
#include "agg_renderer_scanline.h"
#include "agg_rounded_rect.h"
#include "agg_pixfmt_rgba.h"
#include "agg_span_gradient.h"
#include "agg_gsv_text.h"
#include "agg_span_interpolator_linear.h"
#include "platform/agg_platform_support.h"
#include "ctrl/agg_slider_ctrl.h"
#include "ctrl/agg_rbox_ctrl.h"


enum { flip_y = true };

typedef agg::rgba8 color;
typedef agg::pixel32_type pixel_type;
#define pix_format agg::pix_format_bgra32



typedef agg::blender_rgba<color, agg::order_bgra> prim_blender_type; 
typedef agg::pixel_formats_rgba<prim_blender_type, pixel_type> prim_pixfmt_type;
typedef agg::renderer_base<prim_pixfmt_type> prim_ren_base_type;

namespace agg
{

    //========================================================================
    template<> struct gradient_linear_color<color>
    {
        typedef color color_type;
        enum { base_shift = color_type::base_shift };

        gradient_linear_color() {}
        gradient_linear_color(const color_type& c1, const color_type& c2) :
            m_c1(c1), m_c2(c2) {}

        static unsigned size() { return 256; }
        color_type operator [] (unsigned v) const 
        {
            color_type c;
            typedef color_type::value_type value_type;
            v <<= base_shift - 8;
            c.r = (value_type)((((m_c2.r - m_c1.r) * v) + (m_c1.r << base_shift)) >> base_shift);
            c.g = (value_type)((((m_c2.g - m_c1.g) * v) + (m_c1.g << base_shift)) >> base_shift);
            c.b = (value_type)((((m_c2.b - m_c1.b) * v) + (m_c1.b << base_shift)) >> base_shift);
            c.a = (value_type)((((m_c2.a - m_c1.a) * v) + (m_c1.a << base_shift)) >> base_shift);
            return c;
        }

        void colors(const color_type& c1, const color_type& c2)
        {
            m_c1 = c1;
            m_c2 = c2;
        }

        color_type m_c1;
        color_type m_c2;
    };

}




agg::trans_affine gradient_affine(double x1, double y1, double x2, double y2, 
                                  double gradient_d2 = 100.0)
{
    agg::trans_affine mtx;
    double dx = x2 - x1;
    double dy = y2 - y1;
    mtx.reset();
    mtx *= agg::trans_affine_scaling(sqrt(dx * dx + dy * dy) / gradient_d2);
    mtx *= agg::trans_affine_rotation(atan2(dy, dx));
    mtx *= agg::trans_affine_translation(x1, y1);
    mtx.invert();
    return mtx;
}



template<class RenBase> 
void circle(RenBase& rbase, color c1, color c2, 
            double x1, double y1, double x2, double y2,
            double shadow_alpha)
{
    typedef RenBase renderer_base_type;
    typedef agg::gradient_x gradient_func_type;
    typedef agg::gradient_linear_color<color> color_func_type;
    typedef agg::span_interpolator_linear<> interpolator_type;
    typedef agg::span_allocator<color> span_allocator_type;
    typedef agg::span_gradient<color, 
                               interpolator_type, 
                               gradient_func_type, 
                               color_func_type,
                               span_allocator_type> span_gradient_type;
    typedef agg::renderer_scanline_aa<renderer_base_type, 
                                      span_gradient_type> renderer_gradient_type;

    gradient_func_type  gradient_func;                   // The gradient function
    agg::trans_affine   gradient_mtx = gradient_affine(x1, y1, x2, y2, 100);
    interpolator_type   span_interpolator(gradient_mtx); // Span interpolator
    span_allocator_type span_allocator;                  // Span Allocator
    color_func_type     color_func(c1, c2);
    span_gradient_type span_gradient(span_allocator, 
                                     span_interpolator, 
                                     gradient_func, 
                                     color_func, 
                                     0, 100);
    renderer_gradient_type ren_gradient(rbase, span_gradient);
    agg::rasterizer_scanline_aa<> ras;
    agg::scanline_u8 sl;

    double r = agg::calc_distance(x1, y1, x2, y2) / 2;
    agg::ellipse ell((x1+x2)/2+5, (y1+y2)/2-3, r, r, 100);
    agg::renderer_scanline_aa_solid<renderer_base_type> ren_solid(rbase);
    ren_solid.color(agg::rgba(0.6, 0.6, 0.6, 0.7*shadow_alpha));
    ras.add_path(ell);
    agg::render_scanlines(ras, sl, ren_solid);

    ell.init((x1+x2)/2, (y1+y2)/2, r, r, 100);
    ras.add_path(ell);
    agg::render_scanlines(ras, sl, ren_gradient);
}



template<class RenBase> 
void dst_shape(RenBase& rbase, color c1, color c2, 
               double x1, double y1, double x2, double y2)
{
    typedef RenBase renderer_base_type;
    typedef agg::gradient_x gradient_func_type;
    typedef agg::gradient_linear_color<color> color_func_type;
    typedef agg::span_interpolator_linear<> interpolator_type;
    typedef agg::span_allocator<color> span_allocator_type;
    typedef agg::span_gradient<color, 
                               interpolator_type, 
                               gradient_func_type, 
                               color_func_type,
                               span_allocator_type> span_gradient_type;
    typedef agg::renderer_scanline_aa<renderer_base_type, 
                                      span_gradient_type> renderer_gradient_type;

    gradient_func_type  gradient_func;                   // The gradient function
    agg::trans_affine   gradient_mtx = gradient_affine(x1, y1, x2, y2, 100);
    interpolator_type   span_interpolator(gradient_mtx); // Span interpolator
    span_allocator_type span_allocator;                  // Span Allocator
    color_func_type     color_func(c1, c2);
    span_gradient_type  span_gradient(span_allocator, 
                                      span_interpolator, 
                                      gradient_func, 
                                      color_func, 
                                      0, 100);
    renderer_gradient_type ren_gradient(rbase, span_gradient);
    agg::rasterizer_scanline_aa<> ras;
    agg::scanline_u8 sl;

    agg::rounded_rect shape(x1, y1, x2, y2, 40);
//    agg::ellipse shape((x1+x2)/2, (y1+y2)/2, fabs(x2-x1)/2, fabs(y2-y1)/2, 100);

    ras.add_path(shape);
    agg::render_scanlines(ras, sl, ren_gradient);
}







class the_application : public agg::platform_support
{
    agg::slider_ctrl<color>    m_alpha_src;
    agg::slider_ctrl<color>    m_alpha_dst;
    agg::rbox_ctrl<agg::rgba8> m_comp_op;

public:
    the_application(agg::pix_format_e format, bool flip_y) :
        agg::platform_support(format, flip_y),
        m_alpha_src(5, 5,    400, 11,    !flip_y),
        m_alpha_dst(5, 5+15, 400, 11+15, !flip_y),
        m_comp_op(420, 5.0, 420+170.0, 395.0, !flip_y)
    {
        m_alpha_src.label("Src Alpha=%.2f");
        m_alpha_src.value(1.0);
        add_ctrl(m_alpha_src);

        m_alpha_dst.label("Dst Alpha=%.2f");
        m_alpha_dst.value(0.75);
        add_ctrl(m_alpha_dst);

        m_comp_op.text_size(7);
        m_comp_op.add_item("clear");
        m_comp_op.add_item("src");
        m_comp_op.add_item("dst");
        m_comp_op.add_item("src-over");
        m_comp_op.add_item("dst-over");
        m_comp_op.add_item("src-in");
        m_comp_op.add_item("dst-in");
        m_comp_op.add_item("src-out");
        m_comp_op.add_item("dst-out");
        m_comp_op.add_item("src-atop");
        m_comp_op.add_item("dst-atop");
        m_comp_op.add_item("xor");
        m_comp_op.add_item("plus");
        m_comp_op.add_item("minus");
        m_comp_op.add_item("multiply");
        m_comp_op.add_item("screen");
        m_comp_op.add_item("overlay");
        m_comp_op.add_item("darken");
        m_comp_op.add_item("lighten");
        m_comp_op.add_item("color-dodge");
        m_comp_op.add_item("color-burn");
        m_comp_op.add_item("hard-light");
        m_comp_op.add_item("soft-light");
        m_comp_op.add_item("difference");
        m_comp_op.add_item("exclusion");
        m_comp_op.add_item("contrast");
        m_comp_op.cur_item(3);
        add_ctrl(m_comp_op);
    }

    virtual ~the_application()
    {
    }

    virtual void on_init()
    {
    }


    template<class PixFmt> void render_scene(agg::rendering_buffer& rbuf, PixFmt& pixf)
    {
        typedef agg::comp_op_adaptor_rgba<color, agg::order_bgra> blender_type;
        typedef agg::pixfmt_custom_blend_rgba<blender_type> pixfmt_type;
        typedef agg::renderer_base<pixfmt_type> renderer_type;

        pixfmt_type ren_pixf(rbuf);
        renderer_type renderer(ren_pixf);

        agg::renderer_base<PixFmt> rb(pixf);

        rb.blend_from(prim_pixfmt_type(rbuf_img(1)), 
                      0, 250, 180, 
                      unsigned(m_alpha_src.value() * 255));
        circle(rb, 
               agg::rgba8(0xFD, 0xF0, 0x6F, unsigned(m_alpha_src.value() * 255)), 
               agg::rgba8(0xFE, 0x9F, 0x34, unsigned(m_alpha_src.value() * 255)),
               70*3, 100+24*3, 37*3, 100+79*3,
               m_alpha_src.value());

        ren_pixf.comp_op(m_comp_op.cur_item());

        if(m_comp_op.cur_item() == 25) // Contrast
        {
            double v = m_alpha_dst.value();
            dst_shape(renderer, 
                      agg::rgba(v, v, v), 
                      agg::rgba(v, v, v),
                      300+50, 100+24*3, 107+50, 100+79*3);
        }
        else
        {
            dst_shape(renderer, 
                      agg::rgba8(0x7F, 0xC1, 0xFF, unsigned(m_alpha_dst.value() * 255)), 
                      agg::rgba8(0x05, 0x00, 0x5F, unsigned(m_alpha_dst.value() * 255)),
                      300+50, 100+24*3, 107+50, 100+79*3);
        }
    }


    virtual void on_draw()
    {
        prim_pixfmt_type pixf(rbuf_window());
        prim_ren_base_type rb(pixf);
        rb.clear(agg::rgba8(255, 255, 255));

        unsigned y;
        for(y = 0; y < rb.height(); y += 8)
        {
            unsigned x;
            for(x = ((y >> 3) & 1) << 3; x < rb.width(); x += 16)
            {
                rb.copy_bar(x, y, x+7, y+7, agg::rgba8(0xdf, 0xdf, 0xdf));
            }
        }

        create_img(0, rbuf_window().width(), rbuf_window().height()); // agg_platform_support functionality

        prim_pixfmt_type pixf2(rbuf_img(0));
        prim_ren_base_type rb2(pixf2);
        rb2.clear(agg::rgba8(0,0,0,0));

        typedef agg::blender_rgba_pre<color, agg::order_bgra> blender_type_pre; 
        typedef agg::pixel_formats_rgba<blender_type_pre, pixel_type> pixfmt_pre;
        typedef agg::renderer_base<pixfmt_pre> ren_base_pre;

        pixfmt_pre pixf_pre(rbuf_window());
        ren_base_pre rb_pre(pixf_pre);


        start_timer();
        render_scene(rbuf_img(0), pixf2);
        double tm = elapsed_time();

        rb_pre.blend_from(pixf2);

        agg::rasterizer_scanline_aa<> ras;
        agg::scanline_u8 sl;
        agg::renderer_scanline_aa_solid<prim_ren_base_type> ren(rb);

        char buf[64]; 
        agg::gsv_text t;
        t.size(10.0);

        agg::conv_stroke<agg::gsv_text> pt(t);
        pt.width(1.5);

        sprintf(buf, "%3.2f ms", tm);
        t.start_point(10.0, 35.0);
        t.text(buf);

        ras.add_path(pt);
        ren.color(agg::rgba(0,0,0));
        agg::render_scanlines(ras, sl, ren);

        agg::render_ctrl(ras, sl, ren, m_alpha_src);
        agg::render_ctrl(ras, sl, ren, m_alpha_dst);
        agg::render_ctrl(ras, sl, ren, m_comp_op);
    }


    virtual void on_mouse_button_down(int x, int y, unsigned flags)
    {
    }

    virtual void on_mouse_move(int x, int y, unsigned flags)
    {
    }

    virtual void on_mouse_button_up(int x, int y, unsigned flags)
    {
    }
};


int agg_main(int argc, char* argv[])
{
    the_application app(pix_format, flip_y);
    app.caption("AGG Example. Compositing Modes");

    const char* img_name = "compositing";
    if(argc >= 2) img_name = argv[1];
    if(!app.load_img(1, img_name)) 
    {
        char buf[256];
        if(strcmp(img_name, "compositing") == 0)
        {
            sprintf(buf, "File not found: %s%s. Download http://www.antigrain.com/%s%s\n"
                         "or copy it from another directory if available.",
                    img_name, app.img_ext(), img_name, app.img_ext());
        }
        else
        {
            sprintf(buf, "File not found: %s%s", img_name, app.img_ext());
        }
        app.message(buf);
        return 1;
    }


    if(app.init(600, 400, agg::window_resize))
    {
        return app.run();
    }
    return 1;
}


