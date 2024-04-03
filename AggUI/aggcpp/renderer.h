#pragma once

#include "declspec.h"


#include "path.h"
#include "pixelfmt.h"
#include "agg_scanline_p.h"
#include "agg_scanline_u.h"
#include "agg_renderer_base.h"
#include "agg_renderer_scanline.h"
#include "agg_renderer_outline_aa.h"
#include "agg_rasterizer_outline_aa.h"
#include "agg_span_interpolator_linear.h"
#include "agg_span_image_filter_rgba.h"
#include "agg_span_gradient.h"
#include "ctrl/agg_gamma_spline.h"

#include "agg_alpha_mask_u8.h"

/*****************************************************************************/
/*  from agg_renderer.cpp                                                    */

//struct RendererCommon
struct RendererBase
{
    agg::scanline_u8        scanline;
    //pixfmt                  pixf;
    renderer_base_t           ren_base;
    
    int                     active_mask_component;
    
    typedef agg::scanline_u8_am<agg::alpha_mask_bgra32r> sl_alpha_mask_r;
    typedef agg::scanline_u8_am<agg::alpha_mask_bgra32g> sl_alpha_mask_g;
    typedef agg::scanline_u8_am<agg::alpha_mask_bgra32b> sl_alpha_mask_b;
    typedef agg::scanline_u8_am<agg::alpha_mask_bgra32a> sl_alpha_mask_a;
    
    agg::alpha_mask_bgra32r am_r;
    agg::alpha_mask_bgra32g am_g;
    agg::alpha_mask_bgra32b am_b;
    agg::alpha_mask_bgra32a am_a;
    
    sl_alpha_mask_r         sl_r;
    sl_alpha_mask_g         sl_g;
    sl_alpha_mask_b         sl_b;
    sl_alpha_mask_a         sl_a;
    
    RendererBase(pixfmt& pixf)
      : scanline(), ren_base(pixf),
        active_mask_component (-1),
        sl_r (am_r), sl_g (am_g), sl_b (am_b), sl_a (am_a)
    {
    }
};

/*****************************************************************************/

/* struct RendererCommonPre */
struct RendererBasePre
{
    agg::scanline_u8        scanline;
    //pixfmt_pre              pixf;
    renderer_base_pre_t    ren_base;
    
    int                     active_mask_component;
    
    typedef agg::scanline_u8_am<agg::alpha_mask_bgra32r> sl_alpha_mask_r;
    typedef agg::scanline_u8_am<agg::alpha_mask_bgra32g> sl_alpha_mask_g;
    typedef agg::scanline_u8_am<agg::alpha_mask_bgra32b> sl_alpha_mask_b;
    typedef agg::scanline_u8_am<agg::alpha_mask_bgra32a> sl_alpha_mask_a;
    
    agg::alpha_mask_bgra32r am_r;
    agg::alpha_mask_bgra32g am_g;
    agg::alpha_mask_bgra32b am_b;
    agg::alpha_mask_bgra32a am_a;
    
    sl_alpha_mask_r         sl_r;
    sl_alpha_mask_g         sl_g;
    sl_alpha_mask_b         sl_b;
    sl_alpha_mask_a         sl_a;
    
    RendererBasePre(pixfmt_pre& pixf)
      : scanline(), ren_base(pixf),
        active_mask_component (-1),
        sl_r (am_r), sl_g (am_g), sl_b (am_b), sl_a (am_a)
    {
    }
};

/*****************************************************************************/

/* struct RendererBase */
/* { */
/*     RendererCommon*      renderer; */
    
/*     RendererBase(AggBuffer* buffer) : renderer(buffer->renderer) */
/*     { */
/*     } */
/* }; */

/*****************************************************************************/

struct RendererSolid : RendererBase
{
    typedef agg::renderer_scanline_aa_solid<renderer_base_t> renderer_solid;
    
    renderer_solid          ren_solid;
    unsigned int            fence;
    
    RendererSolid (pixfmt& pixf) : RendererBase(pixf), ren_solid(ren_base)
    {
        this->fence = 0x5AA55AA5;
    }
};

/*****************************************************************************/

struct RendererSmooth : RendererBase
{
    typedef agg::renderer_outline_aa<renderer_base_t> renderer_smooth;
    typedef agg::rasterizer_outline_aa<renderer_smooth> rasterizer_smooth;

    agg::line_profile_aa    profile;
    
    renderer_smooth         ren_smooth;
    rasterizer_smooth       ras_smooth;
    agg::trans_affine       transform_matrix;
    
    RendererSmooth (pixfmt& pixf) : RendererBase(pixf), ren_smooth(ren_base, profile), ras_smooth(ren_smooth)
    {
//@     this->ras_smooth.accurate_join (true);
        this->ras_smooth.line_join (agg::outline_miter_accurate_join);  //@
        this->ras_smooth.round_cap (true);
        this->profile.gamma (agg::gamma_power(1.2));
        this->profile.min_width (0.75);
    }
};

/*****************************************************************************/

namespace agg
{
    //----------------------------------------------------image_accessor_clone_convert_pre
    template<class PixFmt> class image_accessor_clone_convert_pre
    {
    public:
        typedef PixFmt   pixfmt_type;
        typedef typename pixfmt_type::color_type color_type;
        typedef typename pixfmt_type::order_type order_type;
        typedef typename pixfmt_type::value_type value_type;
        enum pix_width_e { pix_width = pixfmt_type::pix_width };

        image_accessor_clone_convert_pre() {}
        explicit image_accessor_clone_convert_pre(const pixfmt_type& pixf) : 
            m_pixf(&pixf) 
        {
            m_zero_buf[0] = 0;
            m_zero_buf[1] = 0;
            m_zero_buf[2] = 0;
            m_zero_buf[3] = 0;
        }

        void attach(const pixfmt_type& pixf)
        {
            m_pixf = &pixf;
        }

    private:
        AGG_INLINE const int8u* pixel() const
        {
            int x = m_x;
            int y = m_y;
            if(x < 0) x = 0;
            if(y < 0) y = 0;
            if(x >= (int)m_pixf->width())  x = m_pixf->width() - 1;
            if(y >= (int)m_pixf->height()) y = m_pixf->height() - 1;
            const int8u* ptr = m_pixf->pix_ptr(x, y);

            int8u a = ptr[order_type::A];

            if (a == pixfmt_type::color_type::base_mask)
            {
              return ptr;
            }
            if (a == 0)
            {
              return m_zero_buf;
            }

            int8u r = ptr[order_type::R];
            int8u g = ptr[order_type::G];
            int8u b = ptr[order_type::B];
            
            r = int8u((r * a) >> 8);
            g = int8u((g * a) >> 8);
            b = int8u((b * a) >> 8);
            
            m_tmp_buf[order_type::R] = r;
            m_tmp_buf[order_type::G] = g;
            m_tmp_buf[order_type::B] = b;
            m_tmp_buf[order_type::A] = a;
            
            return m_tmp_buf;
        }

    public:
        AGG_INLINE const int8u* span(int x, int y, unsigned len)
        {
            m_x = m_x0 = x;
            m_y = y;
            return pixel();
        }

        AGG_INLINE const int8u* next_x()
        {
            ++m_x;
            return pixel();
        }

        AGG_INLINE const int8u* next_y()
        {
            ++m_y;
            m_x = m_x0;
            return pixel();
        }

    private:
        const pixfmt_type* m_pixf;
        int                m_x, m_x0, m_y;
        mutable int8u      m_tmp_buf[4];
        int8u              m_zero_buf[4];
    };
}

/*
 *  The image renderer manipulates pixels stored in a source buffer. This
 *  source buffer may not move once it has been attached to the renderer.
 */

struct RendererImage : RendererBasePre
{
    /* AggRendererCommonPre*       renderer; */

    /* typedef pixfmt                                                                          img_pixfmt; */
    typedef agg::span_interpolator_linear<>                                                 interpolator_type;
    typedef agg::image_accessor_clone_convert_pre<pixfmt_pre>                               img_source_type;
    typedef agg::span_image_filter_rgba_bilinear<img_source_type, interpolator_type>        span_gen_type;
    typedef agg::span_image_filter_rgba_nn<img_source_type, interpolator_type>              span_gen_type_nn;
    typedef agg::span_image_filter_rgba<img_source_type, interpolator_type>                 span_gen_type_general;
    typedef agg::span_image_resample_rgba_affine<img_source_type>                           span_gen_type_resample;
    
    agg::trans_affine           matrix;
    interpolator_type           interpolator;
    agg::rendering_buffer       source_buffer;
    //img_pixfmt                  img_pixf;
    img_source_type             img_src;
    agg::image_filter_lut       filter;
    span_alloc_type_t           span_alloc;
    span_gen_type               span_gen;
    span_gen_type_nn            span_gen_nn;
    span_gen_type_general       span_gen_general;
    span_gen_type_resample      span_gen_resample;
    
    bool                        is_source_ok;
    bool                        is_ready;
    bool                        use_nn;
    int                         mode;
    
    unsigned int                fence;
    
    RendererImage (pixfmt_pre& pixf)
        : RendererBasePre(pixf),
          matrix (),
          interpolator (matrix),
          source_buffer (),
          //img_pixf (source_buffer),
          img_src (pixf /*, agg::rgba (0, 0, 0, 0)*/),
          span_alloc (),
          span_gen (img_src, interpolator),
          span_gen_nn (img_src, interpolator),
          span_gen_general (img_src, interpolator, filter),
          span_gen_resample (img_src, interpolator, filter),
          is_source_ok (false),
          is_ready (false),
          use_nn (false),
          mode (0)
    {
        this->span_gen.filter_offset (0);
        this->fence = 0x5AA55AA5;
    }
    
    bool Validate ();
};

/*****************************************************************************/

class gradient_polymorphic_wrapper_base
{
public:
    virtual int calculate(int x, int y, int) const = 0;
};

/*****************************************************************************/

class gradient_full_conic
{
public:
	static int calculate(int x, int y, int d)
	{
		return int((atan2(double(y), double(x))+agg::pi) * double(d) / (agg::pi*2));
	}
};

/*****************************************************************************/

template<class GradientF> 
class gradient_polymorphic_wrapper : public gradient_polymorphic_wrapper_base
{
public:
    virtual int calculate(int x, int y, int d) const
    {
        return m_gradient.calculate(x, y, d);
    }
private:
    GradientF m_gradient;
};

struct RendererGradient : RendererBase
{
    enum GradientID
    {
        GRADIENT_NONE       = 0,
        GRADIENT_X,
        GRADIENT_Y,
        GRADIENT_XY,
        GRADIENT_CIRCLE,
        GRADIENT_DIAMOND,
        GRADIENT_SQRT_XY,
        GRADIENT_CONIC
    };
    
    struct color_function_profile
    {
        color_function_profile() {}
        color_function_profile(const color_type* colors, const agg::int8u* profile) :  m_colors(colors), m_profile(profile) {}
        static unsigned size() { return 256; }
        const color_type& operator [] (unsigned v) const
        { 
            return m_colors[m_profile[v]]; 
        }
        const color_type* m_colors;
        const agg::int8u* m_profile;
    };
    
    typedef agg::span_interpolator_linear<>                                     interpolator_type;
    /* typedef agg::renderer_scanline_aa_solid<renderer_base>                      renderer_solid; */
    typedef agg::span_gradient<color_type, interpolator_type,
                               gradient_polymorphic_wrapper_base,
                               color_function_profile>                          gradient_span_gen;
    typedef agg::span_allocator<gradient_span_gen::color_type>                  gradient_span_alloc;
    typedef agg::renderer_scanline_aa<renderer_base_t, gradient_span_alloc, gradient_span_gen>    renderer_gradient;
    
    agg::trans_affine                                       matrix;
    interpolator_type                                       interpolator;
    
    gradient_span_alloc                                     span_alloc;
    gradient_span_gen                                       span_gen;
    
    renderer_gradient                                       ren_gradient;
    
    color_type                                              color_profile[256];
    agg::gamma_spline                                       gamma_profile;
    color_function_profile                                  colors;
    
    gradient_polymorphic_wrapper_base*                      gradient_ptr;
    double                                                  r1, r2;
    bool                                                    is_ready;
    
    gradient_polymorphic_wrapper<agg::gradient_x>           gr_x;
    gradient_polymorphic_wrapper<agg::gradient_y>           gr_y;
    gradient_polymorphic_wrapper<agg::gradient_xy>          gr_xy;
    gradient_polymorphic_wrapper<agg::gradient_radial_d>    gr_circle;
    gradient_polymorphic_wrapper<agg::gradient_diamond>     gr_diamond;
    gradient_polymorphic_wrapper<agg::gradient_sqrt_xy>     gr_sqrt_xy;
    gradient_polymorphic_wrapper<gradient_full_conic>       gr_conic;
    
    RendererGradient (pixfmt& pixf)
        : RendererBase(pixf),
          matrix (),
          interpolator (matrix),
          span_alloc (),
          span_gen (interpolator, gr_x, colors, 0, 0),
          ren_gradient (ren_base, span_alloc, span_gen),
          gamma_profile (),
          colors (color_profile, gamma_profile.gamma()),
          gradient_ptr (0), r1 (0), r2 (0), is_ready (false)
    {
        for (int i = 0; i < 256; i++)
        {
            this->color_profile[i] = color_type (i, i, i);
        }
    }
    
    void Select(GradientID id);
    bool Validate();
};

/*****************************************************************************/

/* exported functions */

/* extern "C" DECLSPEC void RendererSolid_SetAlphaMask( */
/*     RendererSolid* renderer, */
/*     AggBuffer* buffer, */
/*     int component */
/* ); */

/* extern "C" DECLSPEC void RendererSmooth_SetAlphaMask( */
/*     RendererSmooth* renderer, */
/*     AggBuffer* buffer, */
/*     int component */
/* ); */

/* extern "C" DECLSPEC void RendererImage_SetAlphaMask( */
/*     RendererImage* renderer, */
/*     AggBuffer* buffer, */
/*     int component */
/* ); */

/* extern "C" DECLSPEC void RendererGradient_SetAlphaMask( */
/*     RendererGradient* renderer, */
/*     AggBuffer* buffer, */
/*     int component */
/* ); */

/* extern "C" DECLSPEC RendererSolid* RendererSolid_New( */
/*     AggBuffer* buffer */
/* ); */

extern "C" DECLSPEC void RendererSolid_Clear(
    RendererSolid* renderer,
    double r, double g, double b, double a
);

extern "C" DECLSPEC void RendererSolid_Color(
    RendererSolid* renderer,
    double r, double g, double b, double a
);

/* extern "C" DECLSPEC void RendererSolid_Delete( */
/*     RendererSolid* renderer */
/* ); */

/* extern "C" DECLSPEC RendererSmooth* RendererSmooth_New( */
/*     AggBuffer* buffer */
/* ); */

extern "C" DECLSPEC void RendererSmooth_Color(
    RendererSmooth* renderer,
    double r, double g, double b, double a
);

extern "C" DECLSPEC void RendererSmooth_Setup(
    RendererSmooth* renderer,
    double r1, double r2,
    double xx, double xy,
    double yx, double yy,
    double tx, double ty
);

extern "C" DECLSPEC void RendererSmooth_AddPath(
    RendererSmooth* renderer,
    Path* path
);

/* extern "C" DECLSPEC void RendererSmooth_Delete( */
/*     RendererSmooth* renderer */
/* ); */

/* extern "C" DECLSPEC RendererImage* RendererImage_New( */
/*     AggBuffer* buffer */
/* ); */

extern "C" DECLSPEC void RendererImage_Matrix(
    RendererImage* renderer,
    double xx, double xy,
    double yx, double yy,
    double tx, double ty
);

/* extern "C" DECLSPEC void RendererImage_Source1( */
/*     RendererImage* renderer, */
/*     AggBuffer* buffer */
/* ); */

/* extern "C" DECLSPEC void RendererImage_Source2( */
/*     RendererImage* renderer, */
/*     void* buffer, */
/*     int dx, int dy, */
/*     int stride */
/* ); */

extern "C" DECLSPEC void RendererImage_SetStretchMode(
    RendererImage* renderer,
    int mode,
    double radius
);

/* extern "C" DECLSPEC void RendererImage_Delete( */
/*     RendererImage* renderer */
/* ); */

/* extern "C" DECLSPEC RendererGradient* RendererGradient_New( */
/*     AggBuffer* buffer */
/* ); */

/* extern "C" DECLSPEC void RendererGradient_Delete( */
/*     RendererGradient* renderer */
/* ); */

extern "C" DECLSPEC void RendererGradient_Select(
    RendererGradient* renderer,
    int id
);

extern "C" DECLSPEC void RendererGradient_Range(
    RendererGradient* renderer,
    double r1, double r2
);

extern "C" DECLSPEC void RendererGradient_Matrix(
    RendererGradient* renderer,
    double xx, double xy,
    double yx, double yy,
    double tx, double ty
);

extern "C" DECLSPEC void RendererGradient_Color1(
    RendererGradient* renderer,
    const double r[256],
    const double g[256],
    const double b[256],
    const double a[256]
);

extern "C" DECLSPEC void RendererFill4Colors(
    RendererBase* renderer,
    int x, int y,
    int dx, int dy,
    double r1, double g1, double b1,
    double r2, double g2, double b2,
    double r3, double g3, double b3,
    double r4, double g4, double b4
);
