
#include "graphic_buffer.h"

namespace AntigrainCPP {

    GraphicBuffer::GraphicBuffer(FontManager& font_manager) :
        buffer(),
        gctx(buffer, font_manager) {}

    GraphicBuffer* GraphicBuffer_NewGraphicBuffer(FontManager& font_manager){
        return new GraphicBuffer(font_manager);
    }

    GraphicContext* GraphicBuffer_GetGraphicContext(GraphicBuffer* gbuff){
        return &(gbuff->gctx);
    }
}
