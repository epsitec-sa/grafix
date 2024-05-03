#pragma once

#include "agg_rendering_buffer.h"

#include "graphic_context.h"
#include "font_manager.h"
#include "declspec.h"

namespace AntigrainCPP {

    class GraphicBuffer {
        public:
            unsigned char* data_buffer;
            agg::rendering_buffer rendering_buffer;
            GraphicContext gctx;

        public:
            GraphicBuffer(
                unsigned width, unsigned height, int stride,
                FontManager& font_manager
            );

            ~GraphicBuffer();


    };

    extern "C" DECLSPEC GraphicBuffer* GraphicBuffer_NewGraphicBuffer(
        unsigned width, unsigned height, int stride,
        FontManager& font_manager
    );

    extern "C" DECLSPEC void GraphicBuffer_DeleteGraphicBuffer(GraphicBuffer* gbuff);

    extern "C" DECLSPEC GraphicContext* GraphicBuffer_GetGraphicContext(GraphicBuffer* gbuff);

    extern "C" DECLSPEC unsigned GraphicBuffer_GetWidth(GraphicBuffer* gbuff);

    extern "C" DECLSPEC unsigned GraphicBuffer_GetHeight(GraphicBuffer* gbuff);

    extern "C" DECLSPEC unsigned GraphicBuffer_GetBufferLength(GraphicBuffer* gbuff);

    extern "C" DECLSPEC void GraphicBuffer_GetBufferData(GraphicBuffer* gbuff, unsigned char* output_buffer);
}
