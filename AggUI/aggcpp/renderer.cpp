//  AntiGrain.Win32/agg_renderer.cpp
//
//  Copyright � 2003-2007, Pierre ARNAUD, OPaC bright ideas, Ch. du Fontenay 6,
//                         CH-1400 YVERDON, Switzerland. All rights reserved. 
//
//  Contact: pierre.arnaud@opac.ch, http://www.opac.ch
//  License: see license.txt

#include <iostream>

#include "renderer.h"

/* #include "agg_conv_curve.h" */
/* #include "color_interpolator.h" */

/*****************************************************************************/

/* void */
/* RendererSolid_SetAlphaMask(RendererSolid* renderer, */
/*                              AggBuffer* buffer, int component) */
/* { */
/*     if (renderer) */
/*     { */
/*         renderer->renderer->active_mask_component = component; */
        
/*         if ( (component >= 0) */
/*           && (component <= 3) ) */
/*         { */
/*             renderer->renderer->am_a.attach (buffer->buffer); */
/*             renderer->renderer->am_r.attach (buffer->buffer); */
/*             renderer->renderer->am_g.attach (buffer->buffer); */
/*             renderer->renderer->am_b.attach (buffer->buffer); */
/*         } */
/*     } */
/* } */

/* void */
/* RendererSmooth_SetAlphaMask(RendererSmooth* renderer, */
/*                               AggBuffer* buffer, int component) */
/* { */
/*     if (renderer) */
/*     { */
/*         renderer->renderer->active_mask_component = component; */
        
/*         if ( (component >= 0) */
/*           && (component <= 3) ) */
/*         { */
/*             renderer->renderer->am_a.attach (buffer->buffer); */
/*             renderer->renderer->am_r.attach (buffer->buffer); */
/*             renderer->renderer->am_g.attach (buffer->buffer); */
/*             renderer->renderer->am_b.attach (buffer->buffer); */
/*         } */
/*     } */
/* } */

/* void */
/* RendererImage_SetAlphaMask(RendererImage* renderer, */
/*                              AggBuffer* buffer, int component) */
/* { */
/*     if (renderer) */
/*     { */
/*         renderer->renderer->active_mask_component = component; */
        
/*         if ( (component >= 0) */
/*           && (component <= 3) ) */
/*         { */
/*             renderer->renderer->am_a.attach (buffer->buffer); */
/*             renderer->renderer->am_r.attach (buffer->buffer); */
/*             renderer->renderer->am_g.attach (buffer->buffer); */
/*             renderer->renderer->am_b.attach (buffer->buffer); */
/*         } */
/*     } */
/* } */

/* void */
/* RendererGradient_SetAlphaMask(RendererGradient* renderer, */
/*                                 AggBuffer* buffer, int component) */
/* { */
/*     if (renderer) */
/*     { */
/*         renderer->renderer->active_mask_component = component; */
        
/*         if ( (component >= 0) */
/*           && (component <= 3) ) */
/*         { */
/*             renderer->renderer->am_a.attach (buffer->buffer); */
/*             renderer->renderer->am_r.attach (buffer->buffer); */
/*             renderer->renderer->am_g.attach (buffer->buffer); */
/*             renderer->renderer->am_b.attach (buffer->buffer); */
/*         } */
/*     } */
/* } */

/*****************************************************************************/

void
RendererSolid_Delete(RendererSolid* renderer)
{
    if (renderer->fence != 0x5AA55AA5)
    {
        /* ::DebugBreak (); */
        return;
    }
    
    delete renderer;
}

void
RendererSolid_Clear(RendererSolid* renderer, double r, double g, double b, double a)
{
    if (renderer)
    {
        renderer->ren_base.clear (agg::rgba (r, g, b, a));
    }
}

void
RendererSolid_Color(RendererSolid* renderer, double r, double g, double b, double a)
{
    if (renderer)
    {
        renderer->ren_solid.color (agg::rgba (r, g, b, a));
    }
}

/*****************************************************************************/

void
RendererSmooth_Delete(RendererSmooth* renderer)
{
    delete renderer;
}

void
RendererSmooth_Color(RendererSmooth* renderer, double r, double g, double b, double a)
{
    if (renderer)
    {
        renderer->ren_smooth.color (agg::rgba (r, g, b, a));
    }
}

void
RendererSmooth_Setup(RendererSmooth* renderer, double r1, double r2,
                       double xx, double xy, double yx, double yy, double tx, double ty)
{
    if (renderer)
    {
        renderer->transform_matrix = agg::trans_affine (xx, yx, xy, yy, tx, ty);
        double s = renderer->transform_matrix.scale ();
        
        r1 *= s;
        r2 *= s;
        
        //  Internally, line_interpolator_aa_base does not allow widths larger than 64; this
        //  constant is defined as max_half_width.
        
        if (r1 > 64) r1 = 64;
        if (r2 > 64) r2 = 64;
        
        renderer->profile.smoother_width (r2);
        renderer->profile.width (r1);
    }
}

void
RendererSmooth_AddPath(RendererSmooth* renderer, Path* path)
{
    if ( (renderer)
      && (path) )
    {
        agg::conv_transform<agg::path_storage, agg::trans_affine> conv (path->path, renderer->transform_matrix);
        agg::conv_curve<agg::conv_transform<agg::path_storage, agg::trans_affine> > curve (conv);
        renderer->ras_smooth.add_path (curve);
    }
}

/*****************************************************************************/

bool RendererGradient::Validate(){
    if (this->is_ready == false)
    {
        if ( (this->gradient_ptr)
          && (this->r1 != this->r2)
          && (this->matrix.determinant () != 0) )
        {
            this->interpolator.transformer (this->matrix);
            this->span_gen.interpolator (this->interpolator);
            this->span_gen.gradient_function (*this->gradient_ptr);
            this->span_gen.color_function (this->colors);
            this->span_gen.d1 (this->r1);
            this->span_gen.d2 (this->r2);
            
            this->is_ready = true;
        }
    }
    
    return this->is_ready;
}

void RendererGradient::Select(RendererGradient::GradientID id){
    switch (id)
    {
        case GRADIENT_X:        this->gradient_ptr = & this->gr_x;          break;
        case GRADIENT_Y:        this->gradient_ptr = & this->gr_y;          break;
        case GRADIENT_XY:       this->gradient_ptr = & this->gr_xy;         break;
        case GRADIENT_CIRCLE:   this->gradient_ptr = & this->gr_circle;     break;
        case GRADIENT_DIAMOND:  this->gradient_ptr = & this->gr_diamond;    break;
        case GRADIENT_SQRT_XY:  this->gradient_ptr = & this->gr_sqrt_xy;    break;
        case GRADIENT_CONIC:    this->gradient_ptr = & this->gr_conic;      break;
        default:                this->gradient_ptr = 0;                     break;
    }
    
    this->is_ready = false;
}

void
RendererGradient_Delete(RendererGradient* renderer)
{
    delete renderer;
}

void
RendererGradient_Select(RendererGradient* renderer, int id)
{
    if (renderer)
    {
        renderer->Select (static_cast<RendererGradient::GradientID> (id));
    }
}

void
RendererGradient_Range(RendererGradient* renderer, double r1, double r2)
{
    if (renderer)
    {
        renderer->r1 = r1;
        renderer->r2 = r2;
        renderer->is_ready = false;
    }
}

void
RendererGradient_Color1(RendererGradient* renderer,
                          const double r[256], const double g[256], const double b[256], const double a[256])
{
    if (renderer)
    {
        for (int i = 0; i < 256; i++)
        {
            renderer->color_profile[i] = agg::rgba8 (agg::rgba (r[i], g[i], b[i], a[i]));
        }
        
        renderer->is_ready = false;
    }
}

void
RendererGradient_Matrix(RendererGradient* renderer,
                          double xx, double xy, double yx, double yy, double tx, double ty)
{
    if (renderer)
    {
        //  Caution: affine matrix sorts its elements in a different way than I do. AGG sorts
        //  them column by column, and I sort them as a 2x2 matrix, line by line, plus the
        //  separate translation vector.
        
        renderer->matrix = agg::trans_affine (xx, yx, xy, yy, tx, ty);
        renderer->is_ready = false;
    }
}

/*****************************************************************************/

bool RendererImage::Validate(){
    if (this->is_ready == false)
    {
        if (this->is_source_ok)
        {
            //std::cout << "RendererImage Validate" << std::endl;
            this->interpolator.transformer (this->matrix);
//-         this->img_src.background_color (agg::rgba(0.0, 0.0, 0.0, 0.0));
            this->img_pixf.attach (this->source_buffer); //@
            this->span_gen.interpolator (this->interpolator);
            this->is_ready = true;
        }
    }
    
    return this->is_ready;
}

void
RendererImage_Delete(RendererImage* renderer)
{
    delete renderer;
}

void
RendererImage_SetStretchMode(RendererImage* renderer, int mode, double radius)
{
    renderer->use_nn = (mode == 0);
    renderer->mode = mode;

    if (mode > 1)
    {
        switch (mode)
        {
            case 2:  renderer->filter.calculate (agg::image_filter_bicubic ()); break;
            case 3:  renderer->filter.calculate (agg::image_filter_spline16 ()); break;
            case 4:  renderer->filter.calculate (agg::image_filter_spline36 ()); break;
            case 5:  renderer->filter.calculate (agg::image_filter_kaiser ()); break;
            case 6:  renderer->filter.calculate (agg::image_filter_quadric ()); break;
            case 7:  renderer->filter.calculate (agg::image_filter_catrom ()); break;
            case 8:  renderer->filter.calculate (agg::image_filter_gaussian ()); break;
            case 9:  renderer->filter.calculate (agg::image_filter_bessel ()); break;
            case 10: renderer->filter.calculate (agg::image_filter_mitchell ()); break;
            case 11: renderer->filter.calculate (agg::image_filter_sinc (radius)); break; 
            case 12: renderer->filter.calculate (agg::image_filter_lanczos (radius)); break; 
            case 13: renderer->filter.calculate (agg::image_filter_blackman (radius)); break; 
        }

        renderer->span_gen_general.filter (renderer->filter);
    }
    else if (mode < 0)
    {
        switch (-mode)
        {
            case 1:  renderer->filter.calculate (agg::image_filter_bilinear ()); break;
            case 2:  renderer->filter.calculate (agg::image_filter_bicubic ()); break;
            case 3:  renderer->filter.calculate (agg::image_filter_spline16 ()); break;
            case 4:  renderer->filter.calculate (agg::image_filter_spline36 ()); break;
            case 5:  renderer->filter.calculate (agg::image_filter_kaiser ()); break;
            case 6:  renderer->filter.calculate (agg::image_filter_quadric ()); break;
            case 7:  renderer->filter.calculate (agg::image_filter_catrom ()); break;
            case 8:  renderer->filter.calculate (agg::image_filter_gaussian ()); break;
            case 9:  renderer->filter.calculate (agg::image_filter_bessel ()); break;
            case 10: renderer->filter.calculate (agg::image_filter_mitchell ()); break;
            case 11: renderer->filter.calculate (agg::image_filter_sinc (radius)); break; 
            case 12: renderer->filter.calculate (agg::image_filter_lanczos (radius)); break; 
            case 13: renderer->filter.calculate (agg::image_filter_blackman (radius)); break; 
        }

        renderer->span_gen_resample.filter (renderer->filter);
    }
}


void
RendererImage_Matrix(RendererImage* renderer,
                       double xx, double xy, double yx, double yy, double tx, double ty)
{
    if (renderer)
    {
        //  Caution: affine matrix sorts its elements in a different way than I do. AGG sorts
        //  them column by column, and I sort them as a 2x2 matrix, line by line, plus the
        //  separate translation vector.
        
        renderer->matrix = agg::trans_affine (xx, yx, xy, yy, tx, ty);
        renderer->is_ready = false;
    }
}

/* void */
/* RendererImage_Source1(RendererImage* renderer, AggBuffer* buffer) */
/* { */
/*     if (renderer) */
/*     { */
/*         if (buffer) */
/*         { */
/*             renderer->source_buffer.attach (buffer->pixmap.buf (), buffer->pixmap.width (), buffer->pixmap.height (), buffer->pixmap.stride ()); */
/*             renderer->is_source_ok = true; */
/*             renderer->is_ready = false; */
/*         } */
/*         else */
/*         { */
/*             renderer->is_source_ok = false; */
/*             renderer->is_ready = false; */
/*         } */
/*     } */
/* } */

void
RendererImage_AttachSource(RendererImage* renderer, unsigned char* buffer, int width, int height, int stride)
{
    if (renderer)
    {
        delete [] renderer->source_buffer_data;
        renderer->source_buffer_data = nullptr;
        if (buffer)
        {
            size_t data_size = height*std::abs(stride);
            /*
            std::cout << "AttachSource "
                      << width << "x" << height << " stride " << stride 
                      << " data size " << data_size << std::endl;
                      */
            renderer->source_buffer_data = new unsigned char[data_size]{0};
            memcpy(renderer->source_buffer_data, buffer, data_size);
            renderer->source_buffer.attach (renderer->source_buffer_data, width, height, stride);
            renderer->is_source_ok = true;
            renderer->is_ready = false;
        }
        else
        {
            renderer->is_source_ok = false;
            renderer->is_ready = false;
        }
    }
}

/*****************************************************************************/

namespace agg
{
    class color_interpolator_rgba8
    {
    public:
        color_interpolator_rgba8(agg::rgba8 c1, agg::rgba8 c2, unsigned len) :
            m_r(c1.r, c2.r, len),
            m_g(c1.g, c2.g, len),
            m_b(c1.b, c2.b, len),
            m_a(c1.a, c2.a, len)
        {
        }

        void operator ++ ()
        {
            ++m_r; ++m_g; ++m_b; ++m_a;
        }

        rgba8 color() const
        {
            return rgba8(m_r.y(), m_g.y(), m_b.y(), m_a.y());
        }

    private:
        dda_line_interpolator<16> m_r;
        dda_line_interpolator<16> m_g;
        dda_line_interpolator<16> m_b;
        dda_line_interpolator<16> m_a;
    };
    
    
    // Rendering a square with color interpolation between its corners
    // The colors of the corners are ordered CCW started from bottom-left,
    // assuming that the Y axis goes up.
    //------------------------------------------------------------------
    template<class Renderer>
    void color_rect_rgba8(Renderer& r, int x, int y, int dx, int dy,
                          rgba8 c1, rgba8 c2, rgba8 c3, rgba8 c4)
    {
        int i, j;
        color_interpolator_rgba8 cy1(c1, c4, dy);
        color_interpolator_rgba8 cy2(c2, c3, dy);
        for(i = 0; i < dy; ++i)
        {
            color_interpolator_rgba8 cx(cy1.color(), cy2.color(), dx);
            for(j = 0; j < dx; ++j)
            {
                r.copy_pixel(x + j, y + i, cx.color());
                ++cx;
            }
            ++cy1;
            ++cy2;
        }
    }
}

/*****************************************************************************/
void RendererFill4Colors(RendererBase* renderer,
                            int x, int y, int dx, int dy,
                            double r1, double g1, double b1,
                            double r2, double g2, double b2,
                            double r3, double g3, double b3,
                            double r4, double g4, double b4)
{
    if (renderer)
    {
        agg::color_rect_rgba8 (renderer->ren_base, x, y, dx, dy,
                               agg::rgba8 (agg::rgba (r1, g1, b1)),
                               agg::rgba8 (agg::rgba (r2, g2, b2)),
                               agg::rgba8 (agg::rgba (r3, g3, b3)),
                               agg::rgba8 (agg::rgba (r4, g4, b4)));
    }
}

/*****************************************************************************/
