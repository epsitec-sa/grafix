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

#include "agg_rendering_buffer.h"

#include "graphic_context.h"
#include "font_manager.h"
#include "declspec.h"

namespace AntigrainCPP {
    
    class GraphicBufferBase {
        public:
            virtual GraphicContext* GetGraphicContext() = 0;
            virtual unsigned GetWidth() = 0;
            virtual unsigned GetHeight() = 0;
            virtual int GetStride() = 0;
            virtual unsigned GetBufferLength() = 0;
            virtual void GetBufferData(unsigned char* output_buffer) = 0;
            virtual agg::rendering_buffer& GetRenderingBuffer() = 0;

            virtual ~GraphicBufferBase() = default;
    };

    class GraphicBufferExternalData : public GraphicBufferBase {
        public:
            agg::rendering_buffer rendering_buffer;
            GraphicContext gctx;

        public:
            GraphicBufferExternalData (
                unsigned char* data_buffer,
                unsigned width, unsigned height, int stride,
                FontManager& font_manager
            );

            GraphicContext* GetGraphicContext() override;
            unsigned GetWidth() override;
            unsigned GetHeight() override;
            int GetStride() override;
            unsigned GetBufferLength() override;
            void GetBufferData(unsigned char* output_buffer) override;
            agg::rendering_buffer& GetRenderingBuffer() override;

            ~GraphicBufferExternalData ();
    };

    class GraphicBuffer : public GraphicBufferBase  {
        public:
            unsigned char* data_buffer;
            GraphicBufferExternalData gbuff;

        public:
            GraphicBuffer(
                unsigned width, unsigned height, int stride,
                FontManager& font_manager
            );

            GraphicContext* GetGraphicContext() override;
            unsigned GetWidth() override;
            unsigned GetHeight() override;
            int GetStride() override;
            unsigned GetBufferLength() override;
            void GetBufferData(unsigned char* output_buffer) override;
            agg::rendering_buffer& GetRenderingBuffer() override;

            ~GraphicBuffer();
    };

    extern "C" DECLSPEC GraphicBuffer* GraphicBuffer_NewGraphicBuffer(
        unsigned width, unsigned height, int stride,
        FontManager& font_manager
    );

    extern "C" DECLSPEC void GraphicBuffer_DeleteGraphicBuffer(GraphicBuffer* gbuff);

    extern "C" DECLSPEC GraphicBufferExternalData* GraphicBuffer_NewGraphicBufferExternalData(
        unsigned char* data_buffer,
        unsigned width, unsigned height, int stride,
        FontManager& font_manager
    );

    extern "C" DECLSPEC void GraphicBuffer_DeleteGraphicBufferExternalData(GraphicBufferExternalData* gbuff);

    extern "C" DECLSPEC GraphicContext* GraphicBuffer_GetGraphicContext(GraphicBufferBase* gbuff);

    extern "C" DECLSPEC unsigned GraphicBuffer_GetWidth(GraphicBufferBase* gbuff);

    extern "C" DECLSPEC unsigned GraphicBuffer_GetHeight(GraphicBufferBase* gbuff);

    extern "C" DECLSPEC int GraphicBuffer_GetStride(GraphicBufferBase* gbuff);

    extern "C" DECLSPEC unsigned GraphicBuffer_GetBufferLength(GraphicBufferBase* gbuff);

    extern "C" DECLSPEC void GraphicBuffer_GetBufferData(GraphicBufferBase* gbuff, unsigned char* output_buffer);
}
