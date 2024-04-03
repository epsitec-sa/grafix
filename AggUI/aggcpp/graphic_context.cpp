#include <iostream>
#include "graphic_context.h"

namespace AntigrainCPP {
    GraphicContext::GraphicContext(agg::rendering_buffer& buffer) :
        pixf(buffer),
        /* renderer_base(pixf), */
        /* renderer_solid(renderer_base) */
        renderer_solid(pixf)
    {
        std::cout << "[C++] create GraphicContext" << std::endl;
        //AggRendererBase renderer_base(pixf);
        /* renderer_solid.reset(new AggRendererSolid(pixf)); */

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
}
