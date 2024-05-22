
#include <iostream>
#include <cmath>

#include "graphic_buffer.h"

namespace AntigrainCPP {

    GraphicBufferExternalData::GraphicBufferExternalData(
        unsigned char* data_buffer,
        unsigned width, unsigned height, int stride, FontManager& font_manager
    ) :
        GraphicBufferBase(),
        rendering_buffer(data_buffer, width, height, stride),
        gctx(rendering_buffer, font_manager) {
            //std::cout << "[C++] GraphicBuffer set to zero " << std::endl;
            gctx.clear(0, 0, 0, 0);
            /* std::cout << "[C++] sizeof unsigned char " << sizeof(unsigned char) << std::endl; */
            /* rendering_buffer.clear(0); */
            /* memset(data_buffer, 0, height*abs(stride)); */
        }

    GraphicBufferExternalData::~GraphicBufferExternalData(){
    }

    agg::rendering_buffer& GraphicBufferExternalData::GetRenderingBuffer(){
        return this->rendering_buffer;
    }

    GraphicBufferExternalData* GraphicBuffer_NewGraphicBufferExternalData(
        unsigned char* data_buffer,
        unsigned width, unsigned height, int stride, FontManager& font_manager
    ){
        return new GraphicBufferExternalData(data_buffer, width, height, stride, font_manager);
    }

    void GraphicBuffer_DeleteGraphicBufferExternalData(GraphicBufferExternalData* gbuff){
        delete gbuff;
    }

    GraphicContext* GraphicBufferExternalData::GetGraphicContext() {
        return &(this->gctx);
    }

    unsigned GraphicBufferExternalData::GetWidth() {
        return this->rendering_buffer.width();
    }

    unsigned GraphicBufferExternalData::GetHeight() {
        return this->rendering_buffer.height();
    }

    int GraphicBufferExternalData::GetStride() {
        return this->rendering_buffer.stride();
    }

    unsigned GraphicBufferExternalData::GetBufferLength() {
        return this->rendering_buffer.height() * this->rendering_buffer.stride_abs();
    }

    void GraphicBufferExternalData::GetBufferData(unsigned char* output_buffer) {
        unsigned length = this->GetBufferLength();
        unsigned char* buf = this->rendering_buffer.buf();
        std::memcpy(output_buffer, buf, length);
    }

    // ---------------------------------------------------------------------------

    GraphicBuffer::GraphicBuffer(
        unsigned width, unsigned height, int stride, FontManager& font_manager
    ) :
        GraphicBufferBase(),
        data_buffer { new unsigned char[height*abs(stride)]{0} },
        gbuff(data_buffer, width, height, stride, font_manager)
        {
        }

    GraphicBuffer::~GraphicBuffer(){
        delete [] this->data_buffer;
    }

    agg::rendering_buffer& GraphicBuffer::GetRenderingBuffer(){
        return this->gbuff.GetRenderingBuffer();
    }

    GraphicBuffer* GraphicBuffer_NewGraphicBuffer(
        unsigned width, unsigned height, int stride, FontManager& font_manager
    ){
        return new GraphicBuffer(width, height, stride, font_manager);
    }

    void GraphicBuffer_DeleteGraphicBuffer(GraphicBuffer* gbuff){
        delete gbuff;
    }

    GraphicContext* GraphicBuffer::GetGraphicContext() {
        return this->gbuff.GetGraphicContext();
    }

    unsigned GraphicBuffer::GetWidth() {
        return this->gbuff.GetWidth();
    }

    unsigned GraphicBuffer::GetHeight() {
        return this->gbuff.GetHeight();
    }

    int GraphicBuffer::GetStride() {
        return this->gbuff.GetStride();
    }

    unsigned GraphicBuffer::GetBufferLength() {
        return this->gbuff.GetBufferLength();
    }

    void GraphicBuffer::GetBufferData(unsigned char* output_buffer) {
        this->gbuff.GetBufferData(output_buffer);
    }

    // ---------------------------------------------------------------------------

    GraphicContext* GraphicBuffer_GetGraphicContext(GraphicBufferBase* gbuff){
        return gbuff->GetGraphicContext();
    }

    unsigned GraphicBuffer_GetWidth(GraphicBufferBase* gbuff){
        return gbuff->GetWidth();
    }

    unsigned GraphicBuffer_GetHeight(GraphicBufferBase* gbuff){
        return gbuff->GetHeight();
    }

    int GraphicBuffer_GetStride(GraphicBufferBase* gbuff){
        return gbuff->GetStride();
    }

    unsigned GraphicBuffer_GetBufferLength(GraphicBufferBase* gbuff){
        return gbuff->GetBufferLength();
    }

    void GraphicBuffer_GetBufferData(GraphicBufferBase* gbuff, unsigned char* output_buffer){
        gbuff->GetBufferData(output_buffer);
    }
}
