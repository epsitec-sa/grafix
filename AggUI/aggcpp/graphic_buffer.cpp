
#include <iostream>
#include <cmath>

#include "graphic_buffer.h"

namespace AntigrainCPP {

    GraphicBuffer::GraphicBuffer(
        unsigned width, unsigned height, int stride, FontManager& font_manager
    ) :
        data_buffer { new unsigned char[height*abs(stride)]{0} } ,
        rendering_buffer(data_buffer, width, height, stride),
        gctx(rendering_buffer, font_manager) {
            std::cout << "[C++] GraphicBuffer set to zero " << std::endl;
            gctx.clear(0, 0, 0, 0);
            /* std::cout << "[C++] sizeof unsigned char " << sizeof(unsigned char) << std::endl; */
            /* rendering_buffer.clear(0); */
            /* memset(data_buffer, 0, height*abs(stride)); */
        }

    GraphicBuffer::~GraphicBuffer(){
        delete [] this->data_buffer;
    }

    GraphicBuffer* GraphicBuffer_NewGraphicBuffer(
        unsigned width, unsigned height, int stride, FontManager& font_manager
    ){
        return new GraphicBuffer(width, height, stride, font_manager);
    }

    void GraphicBuffer_DeleteGraphicBuffer(GraphicBuffer* gbuff){
        delete gbuff;
    }

    GraphicContext* GraphicBuffer_GetGraphicContext(GraphicBuffer* gbuff){
        return &(gbuff->gctx);
    }

    unsigned GraphicBuffer_GetWidth(GraphicBuffer* gbuff){
        return gbuff->rendering_buffer.width();
    }

    unsigned GraphicBuffer_GetHeight(GraphicBuffer* gbuff){
        return gbuff->rendering_buffer.height();
    }

    unsigned GraphicBuffer_GetStride(GraphicBuffer* gbuff){
        return gbuff->rendering_buffer.stride();
    }

    unsigned GraphicBuffer_GetBufferLength(GraphicBuffer* gbuff){
        return gbuff->rendering_buffer.height() * gbuff->rendering_buffer.stride_abs();
    }

    void GraphicBuffer_GetBufferData(GraphicBuffer* gbuff, unsigned char* output_buffer){
        unsigned length = GraphicBuffer_GetBufferLength(gbuff);
        std::cout << "[C++] GetBufferData " << length << std::endl;
        unsigned char* buf = gbuff->rendering_buffer.buf();
        std::cout << "[C++] data buffer 0 is " << ((int)(gbuff->data_buffer[0])) << std::endl;
        std::cout << "[C++] data buffer 1 is " << ((int)(gbuff->data_buffer[1])) << std::endl;
        std::cout << "[C++] data buffer 2 is " << ((int)(gbuff->data_buffer[2])) << std::endl;
        std::cout << "[C++] data buffer 3 is " << ((int)(gbuff->data_buffer[3])) << std::endl;

        std::cout << "[C++] buffer 0 is " << ((int)buf[0]) << std::endl;
        std::cout << "[C++] buffer 1 is " << ((int)buf[1]) << std::endl;
        std::cout << "[C++] buffer 2 is " << ((int)buf[2]) << std::endl;
        std::cout << "[C++] buffer 3 is " << ((int)buf[3]) << std::endl;
        std::memcpy(output_buffer, buf, length);
        std::cout << "[C++] GetBufferData done" << std::endl;
    }
}
