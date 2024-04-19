#pragma once

#include "agg_renderer_base.h"
#include "declspec.h"
#include "pixelfmt.h"

#include "renderer.h"
#include "font_manager.h"

namespace AntigrainCPP {
    class GraphicContext {
        public:
            GraphicContext(agg::rendering_buffer& buffer, FontManager& font_manager);

            void set_color(int r, int g, int b);
            void draw_ellipse(double x, double y, double rx, double ry);
            void draw_char(char character, double x, double y);

        private:
            pixfmt pixf;
            pixfmt_pre pixf_pre;
        public:
            RendererSolid renderer_solid;
            RendererSmooth renderer_smooth;
            RendererImage renderer_image;
            RendererGradient renderer_gradient;
            RendererBin renderer_bin;
            FontManager& font_manager;
    };

    extern "C" DECLSPEC void GraphicContext_SetColor(GraphicContext* gctx, int r, int g, int b);

    extern "C" DECLSPEC void GraphicContext_DrawEllipse(GraphicContext* gctx,
                                            double x, double y,
                                            double rx, double ry);

    extern "C" DECLSPEC RendererSolid* GraphicContext_GetSolidRenderer(GraphicContext* gctx);

    extern "C" DECLSPEC RendererSmooth* GraphicContext_GetSmoothRenderer(GraphicContext* gctx);

    extern "C" DECLSPEC RendererImage* GraphicContext_GetImageRenderer(GraphicContext* gctx);

    extern "C" DECLSPEC RendererGradient* GraphicContext_GetGradientRenderer(GraphicContext* gctx);
}
