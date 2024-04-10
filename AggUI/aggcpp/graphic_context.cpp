#include <iostream>
#include "graphic_context.h"

// ************************* drawing ********************************
#include "agg_rasterizer_scanline_aa.h"
#include "agg_scanline_p.h"
#include "agg_ellipse.h"

namespace AntigrainCPP {
    GraphicContext::GraphicContext(agg::rendering_buffer& buffer, FontEngine& fe) :
        pixf(buffer),
        renderer_solid(pixf),
        renderer_smooth(pixf),
        renderer_bin(pixf),
        font_engine(fe)
    {
        std::cout << "[C++] create GraphicContext" << std::endl;
        /* renderer_solid.reset(new AggRendererSolid(pixf)); */

        renderer_solid.ren_base.clear(agg::rgba(1,1,1));
    }

    void GraphicContext::set_color(int r, int g, int b){
        renderer_solid.ren_solid.color(agg::rgba(r, g, b));
    }

    void GraphicContext::draw_ellipse(double x, double y, double rx, double ry){
        std::cout << "[C++] draw ellipse" << std::endl;
        draw_char('e', x, y);

        /* agg::rasterizer_scanline_aa<> ras; */
        /* agg::scanline_p8 sl; */
        /* agg::ellipse e; */
        /* e.init(x, y, rx, ry); */
        /* ras.add_path(e); */
        /* agg::render_scanlines(ras, sl, renderer_solid.ren_solid); */
    }

    void GraphicContext::draw_char(
        char character,
        double x, double y
    ){
        const agg::glyph_cache* glyph = font_engine.m_fman.glyph(character);
        if(glyph)
        {
            /* if(m_kerning.status()) */
            /* { */
            /*     m_fman.add_kerning(&x, &y); */
            /* } */

            /* if(x >= width() - m_height.value()) */
            /* { */
            /*     x = 10.0; */
            /*     y0 -= m_height.value(); */
            /*     if(y0 <= 120) break; */
            /*     y = y0; */
            /* } */

            font_engine.m_fman.init_embedded_adaptors(glyph, x, y);

            switch(glyph->data_type)
            {
            default: break;
            case agg::glyph_data_mono:
                renderer_bin.ren_bin.color(agg::srgba8(0, 0, 0));
                agg::render_scanlines(font_engine.m_fman.mono_adaptor(), 
                                      font_engine.m_fman.mono_scanline(), 
                                      renderer_bin.ren_bin);
                break;

            case agg::glyph_data_gray8:
                renderer_solid.ren_solid.color(agg::srgba8(0, 0, 0));
                agg::render_scanlines(font_engine.m_fman.gray8_adaptor(), 
                                      font_engine.m_fman.gray8_scanline(), 
                                      renderer_solid.ren_solid);
                break;

            case agg::glyph_data_outline:
                agg::rasterizer_scanline_aa<> ras;
                agg::scanline_u8 sl;
                /* ras.reset(); */
                /* if(fabs(m_weight.value()) <= 0.01) */
                /* { */
                /*     // For the sake of efficiency skip the */
                /*     // contour converter if the weight is about zero. */
                /*     //----------------------- */
                /*     ras.add_path(m_curves); */
                /* } */
                /* else */
                /* { */
                    ras.add_path(font_engine.m_contour);
                /* } */
                renderer_solid.ren_solid.color(agg::srgba8(0, 0, 0));
                agg::render_scanlines(ras, sl, renderer_solid.ren_solid);
                break;
            }

            // increment pen position
            /* x += glyph->advance_x; */
            /* y += glyph->advance_y; */
            /* ++num_glyphs; */
        }
    }

    void GraphicContext_SetColor(GraphicContext* gctx,
        int r, int g, int b
    ){
        gctx->set_color(r, g, b);
    }

    void GraphicContext_DrawEllipse(GraphicContext* gctx,
        double x, double y,
        double rx, double ry
    ){
        gctx->draw_ellipse(x, y, rx, ry);
    }

    RendererSolid* GraphicContext_GetSolidRenderer(GraphicContext* gctx){
        std::cout << "[C++] get solid renderer" << std::endl;
        return &(gctx->renderer_solid);
    }

    RendererSmooth* GraphicContext_GetSmoothRenderer(GraphicContext* gctx){
        std::cout << "[C++] get smooth renderer" << std::endl;
        return &(gctx->renderer_smooth);
    }
}
