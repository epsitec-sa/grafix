#pragma once

#include "agg_rendering_buffer.h"

#include "graphic_context.h"
#include "font_manager.h"
#include "declspec.h"

namespace AntigrainCPP {

    class GraphicBuffer {

        public:
            GraphicBuffer(FontManager& font_manager);

            GraphicContext gctx;

        private:
            agg::rendering_buffer buffer;
    };

    extern "C" DECLSPEC GraphicBuffer* GraphicBuffer_NewGraphicBuffer(FontManager& font_manager);

    extern "C" DECLSPEC GraphicContext* GraphicBuffer_GetGraphicContext(GraphicBuffer* gbuff);
}
