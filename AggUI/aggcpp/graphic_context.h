#pragma once

#include "agg_renderer_base.h"
#include "declspec.h"
#include "pixelfmt.h"

#include "renderer.h"
#include "freetype_font.h"

namespace AntigrainCPP {
    class GraphicContext {
        public:
            GraphicContext(agg::rendering_buffer& buffer, FontEngine& font_engine);

            void set_color(int r, int g, int b);
            void draw_ellipse(double x, double y, double rx, double ry);
            void draw_char(char character, double x, double y);

        private:
            pixfmt pixf;
        public:
            RendererSolid renderer_solid;
            RendererSmooth renderer_smooth;
            RendererBin renderer_bin;
            FontEngine& font_engine;
    };

    extern "C" DECLSPEC void GraphicContext_SetColor(GraphicContext* gctx, int r, int g, int b);

    extern "C" DECLSPEC void GraphicContext_DrawEllipse(GraphicContext* gctx,
                                            double x, double y,
                                            double rx, double ry);

    extern "C" DECLSPEC RendererSolid* GraphicContext_GetSolidRenderer(GraphicContext* gctx);

    extern "C" DECLSPEC RendererSmooth* GraphicContext_GetSmoothRenderer(GraphicContext* gctx);
}
