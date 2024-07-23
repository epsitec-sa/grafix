/*
This file is part of AggUI.

Copyright © 2003-2024, EPSITEC SA, 1400 Yverdon-les-Bains, Switzerland

AggUI is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
any later version.

AggUI is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

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

            void clear(double r, double g, double b, double a);
            void set_color(double r, double g, double b, double a);
            void draw_ellipse(double x, double y, double rx, double ry);
            double draw_char(char character, double x, double y);
            double draw_text(const char* text, double x, double y);
            double draw_glyph(unsigned glyph, double x, double y);

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

        private:
            double internal_draw_glyph(double x, double y);
    };

    extern "C" DECLSPEC void GraphicContext_SetColor(GraphicContext* gctx, double r, double g, double b, double a);

    extern "C" DECLSPEC void GraphicContext_DrawEllipse(GraphicContext* gctx,
                                            double x, double y,
                                            double rx, double ry);

    extern "C" DECLSPEC double GraphicContext_DrawChar(GraphicContext* gctx,
        char character,
        double x, double y
    );

    extern "C" DECLSPEC double GraphicContext_DrawGlyph(GraphicContext* gctx,
        unsigned glyph,
        double x, double y
    );

    extern "C" DECLSPEC double GraphicContext_DrawText(GraphicContext* gctx,
        const char* text,
        double x, double y
    );

    extern "C" DECLSPEC RendererSolid* GraphicContext_GetSolidRenderer(GraphicContext* gctx);

    extern "C" DECLSPEC RendererSmooth* GraphicContext_GetSmoothRenderer(GraphicContext* gctx);

    extern "C" DECLSPEC RendererImage* GraphicContext_GetImageRenderer(GraphicContext* gctx);

    extern "C" DECLSPEC RendererGradient* GraphicContext_GetGradientRenderer(GraphicContext* gctx);
}
