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
        std::cout << "[C++] create GraphicContext" << std::endl;

        renderer_solid.ren_base.clear(agg::rgba(1,1,1));
    }

    void GraphicContext::set_color(int r, int g, int b){
        renderer_solid.ren_solid.color(agg::rgba(r, g, b));
    }

    void GraphicContext::draw_ellipse(double x, double y, double rx, double ry){
        std::cout << "[C++] draw ellipse" << std::endl;

        agg::rasterizer_scanline_aa<> ras;
        agg::scanline_p8 sl;
        agg::ellipse e;
        e.init(x, y, rx, ry);
        ras.add_path(e);
        agg::render_scanlines(ras, sl, renderer_solid.ren_solid);
    }

    void GraphicContext::draw_char(
        char character,
        double x, double y
    ){
        typedef agg::serialized_scanlines_adaptor_aa<agg::int8u> adaptor_type;

        if(!font_manager.m_feng.prepare_glyph(character))
        {
            return;
        }

        agg::int8u* glyph_data = (agg::int8u*)std::malloc(font_manager.m_feng.data_size());
        font_manager.m_feng.write_glyph_to(glyph_data);

        adaptor_type adaptor;
        adaptor_type::embedded_scanline sl;
        adaptor.init(glyph_data, font_manager.m_feng.data_size(), x, y);

        renderer_solid.ren_solid.color(agg::srgba8(0, 0, 0));
        agg::render_scanlines(adaptor, sl, renderer_solid.ren_solid);
        std::free(glyph_data);
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

    void GraphicContext_DrawChar(GraphicContext* gctx,
        char character,
        double x, double y
    ){
        gctx->draw_char(character, x, y);
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
