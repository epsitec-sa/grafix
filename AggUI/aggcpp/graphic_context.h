#pragma once

#include "agg_renderer_base.h"
#include "declspec.h"
#include "pixelfmt.h"

#include "renderer.h"
// ************************* drawing ********************************
#include "agg_rasterizer_scanline_aa.h"
#include "agg_scanline_p.h"
#include "agg_ellipse.h"

namespace AntigrainCPP {
    class GraphicContext {
        public:
            GraphicContext(agg::rendering_buffer& buffer);

            void set_color(int r, int g, int b);
            void draw_ellipse(double x, double y, double rx, double ry);

        private:
            pixfmt pixf;
        public:
            RendererSolid renderer_solid;
            /* renderer_base_t renderer_base; */
            /* agg::renderer_scanline_aa_solid<renderer_base_t> renderer_solid; */
    };

    extern "C" DECLSPEC void GraphicContext_SetColor(GraphicContext* gctx, int r, int g, int b);

    extern "C" DECLSPEC void GraphicContext_DrawEllipse(GraphicContext* gctx,
                                            double x, double y,
                                            double rx, double ry);

    extern "C" DECLSPEC RendererSolid* GraphicContext_GetSolidRenderer(GraphicContext* gctx);
}
