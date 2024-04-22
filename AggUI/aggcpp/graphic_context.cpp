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

    void GraphicContext::set_color(int r, int g, int b, int a){
        renderer_solid.ren_solid.color(agg::rgba(r, g, b, a));
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

    void GraphicContext::draw_glyph(
        unsigned glyph,
        double x, double y
    ){
        if(!font_manager.m_feng.prepare_glyph_from_index(glyph))
        {
            return;
        }
        internal_draw_glyph(x, y);
    }

    void GraphicContext::draw_char(
        char character,
        double x, double y
    ){
        if(!font_manager.m_feng.prepare_glyph(character))
        {
            return;
        }
        internal_draw_glyph(x, y);
    }

    void GraphicContext::draw_text(
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
    }

    void GraphicContext::internal_draw_glyph(double x, double y) {

        typedef agg::serialized_scanlines_adaptor_aa<agg::int8u> adaptor_type;

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
        int r, int g, int b, int a
    ){
        gctx->set_color(r, g, b, a);
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

    void GraphicContext_DrawText(GraphicContext* gctx,
        const char* text,
        double x, double y
    ){
        gctx->draw_text(text, x, y);
    }

    void GraphicContext_DrawGlyph(GraphicContext* gctx,
        unsigned glyph,
        double x, double y
    ){
        gctx->draw_glyph(glyph, x, y);
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
