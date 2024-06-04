#include <iostream>
#include "graphic_context.h"

// ************************* drawing ********************************
#include "agg_rasterizer_scanline_aa.h"
#include "agg_scanline_p.h"
#include "agg_ellipse.h"

namespace AntigrainCPP {

    GraphicContext::GraphicContext(agg::rendering_buffer& buffer, FontManager& fm) :
        pixf(buffer),
        pixf_pre(buffer),
        renderer_solid(pixf),
        renderer_smooth(pixf),
        renderer_image(pixf_pre),
        renderer_gradient(pixf),
        renderer_bin(pixf),
        font_manager(fm)
    {
        //std::cout << "[C++] create GraphicContext" << std::endl;
    }

    void GraphicContext::clear(double r, double g, double b, double a){
        renderer_solid.ren_base.clear(agg::rgba(r, g, b, a));
    }

    void GraphicContext::set_color(double r, double g, double b, double a){
        renderer_solid.ren_solid.color(agg::rgba(r, g, b, a));
    }

    void GraphicContext::draw_ellipse(double x, double y, double rx, double ry){
        //std::cout << "[C++] draw ellipse" << std::endl;

        agg::rasterizer_scanline_aa<> ras;
        agg::scanline_p8 sl;
        agg::ellipse e;
        e.init(x, y, rx, ry);
        ras.add_path(e);
        agg::render_scanlines(ras, sl, renderer_solid.ren_solid);
    }

    double GraphicContext::draw_glyph(
        unsigned glyph,
        double x, double y
    ){
        if(!font_manager.m_feng.prepare_glyph_from_index(glyph))
        {
            return 0;
        }
        return internal_draw_glyph(x, y);
    }

    double GraphicContext::draw_char(
        char character,
        double x, double y
    ){
        if(!font_manager.m_feng.prepare_glyph(character))
        {
            return 0;
        }
        return internal_draw_glyph(x, y);
    }

    double GraphicContext::draw_text(
        const char* text,
        double x, double y
    ){
        double xp = x;
        double yp = y;
        const char* currChar = text;
        unsigned prevGlyph = 0;
        while (*currChar){
            if(!font_manager.m_feng.prepare_glyph(*currChar))
            {
                currChar++;
                continue;
            }
            unsigned currGlyph = font_manager.m_feng.glyph_index();
            font_manager.m_feng.add_kerning(prevGlyph, currGlyph, &xp, &yp);
            internal_draw_glyph(xp, yp);
            prevGlyph = currGlyph;
            xp += font_manager.m_feng.advance_x();
            yp += font_manager.m_feng.advance_y();
            currChar++;
        }
        return xp - x;
    }

    double GraphicContext::internal_draw_glyph(double x, double y) {

        typedef agg::serialized_scanlines_adaptor_aa<agg::int8u> adaptor_type;

        agg::int8u* glyph_data = (agg::int8u*)std::malloc(font_manager.m_feng.data_size());
        font_manager.m_feng.write_glyph_to(glyph_data);

        adaptor_type adaptor;
        adaptor_type::embedded_scanline sl;
        adaptor.init(glyph_data, font_manager.m_feng.data_size(), x, y);

        agg::render_scanlines(adaptor, sl, renderer_solid.ren_solid);
        std::free(glyph_data);
        return font_manager.m_feng.advance_x();
    }

/* #include <stdlib.h> */
/* #include <ctype.h> */
/* #include <stdio.h> */
/* #include "agg_rendering_buffer.h" */
/* #include "agg_rasterizer_scanline_aa.h" */
/* #include "agg_scanline_p.h" */
/* #include "agg_renderer_scanline.h" */
/* #include "agg_conv_bspline.h" */
/* #include "agg_conv_segmentator.h" */
/* #include "agg_font_freetype.h" */
/* #include "agg_trans_single_path.h" */
/* #include "ctrl/agg_cbox_ctrl.h" */
/* #include "ctrl/agg_slider_ctrl.h" */
/* #include "platform/agg_platform_support.h" */
/* #include "interactive_polygon.h" */

/* #define AGG_BGR24 */ 
/* #include "pixel_formats.h" */

/* class the_application : public agg::platform_support */
/* { */
/* public: */
/*     typedef agg::renderer_base<pixfmt> renderer_base; */
/*     typedef agg::renderer_scanline_aa_solid<renderer_base> renderer_solid; */
/*     typedef agg::scanline_p8 scanline_type; */
/*     typedef agg::font_engine_freetype_int16 font_engine_type; */
/*     typedef agg::font_cache_manager<font_engine_type> font_manager_type; */

/*     font_engine_type             m_feng; */
/*     font_manager_type            m_fman; */

/*     the_application(agg::pix_format_e format, bool flip_y) : */
/*         agg::platform_support(format, flip_y), */
/*         m_feng(), */
/*         m_fman(m_feng) */
/*     { */
/*     } */


/*     virtual void on_draw() */
/*     { */
/*         pixfmt pixf(rbuf_window()); */
/*         renderer_base rb(pixf); */
/*         renderer_solid r(rb); */
/*         rb.clear(agg::rgba(1, 1, 1)); */

/*         scanline_type sl; */
/*         agg::rasterizer_scanline_aa<> ras; */

/*         typedef agg::conv_curve<font_manager_type::path_adaptor_type>            conv_font_curve_type; */
/*         typedef agg::conv_segmentator<conv_font_curve_type>                      conv_font_segm_type; */
/*         conv_font_curve_type fcurves(m_fman.path_adaptor()); */

/*         conv_font_segm_type  fsegm(fcurves); */
/*         fsegm.approximation_scale(3.0); */
/*         fcurves.approximation_scale(2.0); */

/*         ras.reset(); */

/*         if(m_feng.load_font(full_file_name("timesi.ttf"), 0, agg::glyph_ren_outline)) */
/*         { */
/*             double x = 1.0; */
/*             double y = 4.0; */
/*             const char* p = text; */
/*             p += 11; */

/*             m_feng.hinting(false); */
/*             m_feng.height(40); */

/*             while(*p) */
/*             { */
/*                 const agg::glyph_cache* glyph = m_fman.glyph(*p); */
/*                 if(glyph) */
/*                 { */
/*                     m_fman.add_kerning(&x, &y); */
/*                     m_fman.init_embedded_adaptors(glyph, x, y); */

/*                     if(glyph->data_type == agg::glyph_data_outline) */
/*                     { */
/*                         ras.add_path(fsegm); */
/*                     } */

/*                     // increment pen position */
/*                     x += glyph->advance_x; */
/*                     y += glyph->advance_y; */
/*                 } */
/*                 ++p; */
/*             } */
/*         } */
/*         else */
/*         { */
/*             message("Please copy file timesi.ttf to the current directory\n" */
/*                     "or download it from http://www.antigrain.com/timesi.zip"); */
/*         } */
/*         r.color(agg::srgba8(0, 0, 0)); */
/*         agg::render_scanlines(ras, sl, r); */
/*     } */
/* }; */


    void GraphicContext_SetColor(GraphicContext* gctx,
        double r, double g, double b, double a
    ){
        gctx->set_color(r, g, b, a);
    }

    void GraphicContext_DrawEllipse(GraphicContext* gctx,
        double x, double y,
        double rx, double ry
    ){
        gctx->draw_ellipse(x, y, rx, ry);
    }

    double GraphicContext_DrawChar(GraphicContext* gctx,
        char character,
        double x, double y
    ){
        return gctx->draw_char(character, x, y);
    }

    double GraphicContext_DrawText(GraphicContext* gctx,
        const char* text,
        double x, double y
    ){
        return gctx->draw_text(text, x, y);
    }

    double GraphicContext_DrawGlyph(GraphicContext* gctx,
        unsigned glyph,
        double x, double y
    ){
        return gctx->draw_glyph(glyph, x, y);
    }

    RendererSolid* GraphicContext_GetSolidRenderer(GraphicContext* gctx){
        return &(gctx->renderer_solid);
    }

    RendererSmooth* GraphicContext_GetSmoothRenderer(GraphicContext* gctx){
        return &(gctx->renderer_smooth);
    }

    RendererImage* GraphicContext_GetImageRenderer(GraphicContext* gctx){
        return &(gctx->renderer_image);
    }

    RendererGradient* GraphicContext_GetGradientRenderer(GraphicContext* gctx){
        return &(gctx->renderer_gradient);
    }
}
