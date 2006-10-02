//	structures.h
//
//	Copyright © 2003-2006, Pierre ARNAUD, OPaC bright ideas, Ch. du Fontenay 6,
//	                       CH-1400 YVERDON, Switzerland. All rights reserved. 
//
//	Contact: pierre.arnaud@opac.ch, http://www.opac.ch
//	License: see license.txt

#pragma once

#include "settings.h"

#include "agg_alpha_mask_u8.h"
#include "agg_bounding_rect.h"
#include "agg_image_accessors.h"
#include "agg_path_storage.h"
#include "agg_rasterizer_scanline_aa.h"
#include "agg_rasterizer_outline_aa.h"
#include "agg_rendering_buffer.h"
#include "agg_renderer_scanline.h"
#include "agg_renderer_mclip.h"
#include "agg_renderer_outline_aa.h"
#include "agg_span_allocator.h"
#include "agg_span_image_filter_rgb.h"
#include "agg_span_image_filter_rgba.h"
#include "agg_span_interpolator_linear.h"
#include "agg_scanline_u.h"
#include "agg_scanline_p.h"
#include "agg_trans_affine.h"

#include "agg_conv_clip_polygon.h"
#include "agg_conv_curve.h"
#include "agg_conv_dash.h"
#include "agg_conv_stroke.h"
#include "agg_conv_transform.h"

#include "agg_span_solid.h"
#include "agg_span_gradient.h"

#include "agg_ellipse.h"

#include "agg_pixfmt_rgba.h"

#include "ctrl/agg_gamma_spline.h"

#include "platform/win32/agg_win32_bmp.h"

/*****************************************************************************/

/*
 *	We work internally with a B-G-R-A 32-bit pixel format (this is what is
 *	expected on Windows machines: blue/green/red + alpha, little endian).
 */

typedef agg::pixfmt_bgra32				pixfmt;
typedef agg::pixfmt_bgra32_pre			pixfmt_pre;
typedef agg::rgba8						color_type;
typedef agg::order_bgra					component_order;
typedef agg::renderer_mclip<pixfmt>		renderer_base;
typedef agg::renderer_mclip<pixfmt_pre>	renderer_base_pre;
typedef agg::span_allocator<color_type>	span_alloc_type;

/*****************************************************************************/

namespace agg
{
	class font_face;
}

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

/*****************************************************************************/

struct AggRasterizer
{
	agg::rasterizer_scanline_aa<>	rasterizer;
	bool							has_transform;
	bool							has_clip_box;
	agg::trans_affine				transform_matrix;
	double							x1, y1, x2, y2;
};

/*****************************************************************************/

struct AggRendererCommon;
struct AggRendererCommonPre;

/*****************************************************************************/

struct AggBuffer
{
	agg::pixel_map			pixmap;
	agg::rendering_buffer	buffer;
	AggRendererCommon*		renderer;
	AggRendererCommonPre*	renderer_pre;
    
#if defined(USE_WIN32_API)
	HDC						bitmap_dc;
	HBITMAP                 bitmap;
	HGDIOBJ					bitmap_old;
#endif
};

/*****************************************************************************/

struct AggRendererCommon
{
	agg::scanline_u8		scanline;
	pixfmt					pixf;
	renderer_base			ren_base;
	
	int						active_mask_component;
	
	typedef agg::scanline_u8_am<agg::alpha_mask_bgra32r> sl_alpha_mask_r;
	typedef agg::scanline_u8_am<agg::alpha_mask_bgra32g> sl_alpha_mask_g;
	typedef agg::scanline_u8_am<agg::alpha_mask_bgra32b> sl_alpha_mask_b;
	typedef agg::scanline_u8_am<agg::alpha_mask_bgra32a> sl_alpha_mask_a;
	
	agg::alpha_mask_bgra32r	am_r;
	agg::alpha_mask_bgra32g	am_g;
	agg::alpha_mask_bgra32b	am_b;
	agg::alpha_mask_bgra32a	am_a;
	
	sl_alpha_mask_r			sl_r;
	sl_alpha_mask_g			sl_g;
	sl_alpha_mask_b			sl_b;
	sl_alpha_mask_a			sl_a;
	
	AggRendererCommon(agg::rendering_buffer& buffer)
	  : scanline(), pixf(buffer), ren_base(pixf),
		active_mask_component (-1),
		sl_r (am_r), sl_g (am_g), sl_b (am_b), sl_a (am_a)
	{
	}
};

/*****************************************************************************/

struct AggRendererCommonPre
{
	agg::scanline_u8		scanline;
	pixfmt_pre				pixf;
	renderer_base_pre		ren_base_pre;
	
	int						active_mask_component;
	
	typedef agg::scanline_u8_am<agg::alpha_mask_bgra32r> sl_alpha_mask_r;
	typedef agg::scanline_u8_am<agg::alpha_mask_bgra32g> sl_alpha_mask_g;
	typedef agg::scanline_u8_am<agg::alpha_mask_bgra32b> sl_alpha_mask_b;
	typedef agg::scanline_u8_am<agg::alpha_mask_bgra32a> sl_alpha_mask_a;
	
	agg::alpha_mask_bgra32r	am_r;
	agg::alpha_mask_bgra32g	am_g;
	agg::alpha_mask_bgra32b	am_b;
	agg::alpha_mask_bgra32a	am_a;
	
	sl_alpha_mask_r			sl_r;
	sl_alpha_mask_g			sl_g;
	sl_alpha_mask_b			sl_b;
	sl_alpha_mask_a			sl_a;
	
	AggRendererCommonPre(agg::rendering_buffer& buffer)
	  : scanline(), pixf(buffer), ren_base_pre(pixf),
		active_mask_component (-1),
		sl_r (am_r), sl_g (am_g), sl_b (am_b), sl_a (am_a)
	{
	}
};

/*****************************************************************************/

struct AggRendererBase
{
	AggRendererCommon*		renderer;
	
	AggRendererBase(AggBuffer* buffer) : renderer(buffer->renderer)
	{
	}
};

/*****************************************************************************/

struct AggRendererSolid : AggRendererBase
{
	typedef agg::renderer_scanline_aa_solid<renderer_base> renderer_solid;
	
	renderer_solid			ren_solid;
	unsigned int			fence;
	
	AggRendererSolid (AggBuffer* buffer) : AggRendererBase(buffer), ren_solid(renderer->ren_base)
	{
		this->fence = 0x5AA55AA5;
	}
};

/*****************************************************************************/

struct AggRendererSmooth : AggRendererBase
{
	typedef agg::renderer_outline_aa<renderer_base> renderer_smooth;
	typedef agg::rasterizer_outline_aa<renderer_smooth> rasterizer_smooth;

	agg::line_profile_aa	profile;
	
	renderer_smooth			ren_smooth;
	rasterizer_smooth		ras_smooth;
	agg::trans_affine		transform_matrix;
	
	AggRendererSmooth (AggBuffer* buffer) : AggRendererBase(buffer), ren_smooth(renderer->ren_base, profile), ras_smooth(ren_smooth)
	{
//@		this->ras_smooth.accurate_join (true);
		this->ras_smooth.line_join (agg::outline_miter_accurate_join);	//@
		this->ras_smooth.round_cap (true);
		this->profile.gamma (agg::gamma_power(1.2));
		this->profile.min_width (0.75);
	}
};

/*****************************************************************************/

/*
 *	The image renderer manipulates pixels stored in a source buffer. This
 *	source buffer may not move once it has been attached to the renderer.
 */

struct AggRendererImage
{
	AggRendererCommon*			renderer;
	
	typedef agg::span_interpolator_linear<>													interpolator_type;
	typedef agg::image_accessor_clip<pixfmt>												img_source_type;
	typedef agg::span_image_filter_rgba_bilinear<img_source_type, interpolator_type>		span_gen_type;		//@
	typedef agg::span_image_filter_rgba_nn<img_source_type, interpolator_type>				span_gen_type_nn;	//@
	typedef agg::span_image_filter_rgba<img_source_type, interpolator_type>					span_gen_type_general;
	
	agg::trans_affine			matrix;
	interpolator_type			interpolator;
	agg::rendering_buffer		source_buffer;
	pixfmt						img_pixf;		//@
	img_source_type				img_src;
	agg::image_filter_lut		filter;
	span_alloc_type				span_alloc;
	span_gen_type				span_gen;
	span_gen_type_nn			span_gen_nn;
	span_gen_type_general		span_gen_general;
    
	bool						is_source_ok;
	bool						is_ready;
	bool						use_nn;
	int							mode;
	
	unsigned int				fence;
	
	AggRendererImage (AggBuffer* buffer)
		: renderer(buffer->renderer),
		  matrix (),
		  interpolator (matrix),
		  source_buffer (),
		  img_pixf (source_buffer),		//@
		  img_src (img_pixf, agg::rgba (1, 0, 0, 1)),			//@
		  span_alloc (),
		  span_gen (img_src, interpolator),	//@ supprimé agg::rgba (1, 0, 0, 1), 
		  span_gen_nn (img_src, interpolator),
		  span_gen_general (img_src, interpolator, filter),
//@		  ren_image(renderer->ren_base, span_gen),
//@		  ren_image_nn(renderer->ren_base, span_gen_nn),
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

struct AggRendererGradient : AggRendererBase
{
	enum GradientID
	{
		GRADIENT_NONE		= 0,
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
	
	typedef agg::span_interpolator_linear<>										interpolator_type;
	typedef agg::renderer_scanline_aa_solid<renderer_base>						renderer_solid;
    typedef agg::span_gradient<color_type, interpolator_type,
							   gradient_polymorphic_wrapper_base,
							   color_function_profile>							gradient_span_gen;
	typedef agg::span_allocator<gradient_span_gen::color_type>					gradient_span_alloc;
	typedef agg::renderer_scanline_aa<renderer_base, gradient_span_alloc, gradient_span_gen>	renderer_gradient;
	
	agg::trans_affine										matrix;
	interpolator_type										interpolator;
	
	gradient_span_alloc										span_alloc;
	gradient_span_gen										span_gen;
	
	renderer_gradient										ren_gradient;
	
	color_type												color_profile[256];
	agg::gamma_spline										gamma_profile;
	color_function_profile									colors;
	
	gradient_polymorphic_wrapper_base*						gradient_ptr;
	double													r1, r2;
	bool													is_ready;
    
    gradient_polymorphic_wrapper<agg::gradient_x>			gr_x;
    gradient_polymorphic_wrapper<agg::gradient_y>			gr_y;
    gradient_polymorphic_wrapper<agg::gradient_xy>			gr_xy;
	gradient_polymorphic_wrapper<agg::gradient_radial_d>	gr_circle;
    gradient_polymorphic_wrapper<agg::gradient_diamond>		gr_diamond;
    gradient_polymorphic_wrapper<agg::gradient_sqrt_xy>		gr_sqrt_xy;
    gradient_polymorphic_wrapper<gradient_full_conic>		gr_conic;
	
	AggRendererGradient (AggBuffer* buffer)
		: AggRendererBase(buffer),
		  matrix (),
		  interpolator (matrix),
		  span_alloc (),
		  span_gen (interpolator, gr_x, colors, 0, 0),
		  ren_gradient (renderer->ren_base, span_alloc, span_gen),
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

struct AggPath
{
	agg::path_storage									path;
	agg::conv_curve<agg::path_storage>					curve;
	agg::conv_dash<agg::conv_curve<agg::path_storage> >	dash;
	
	bool				has_dashes;
	
	AggPath ()
		: path (), curve (path), dash (curve), has_dashes (false)
	{
	}
};

/*****************************************************************************/

enum TextBreakMode
{
	TEXT_BREAK_NONE					= 0x0000,
	TEXT_BREAK_HYPHENATE			= 0x0001,		//	césure des mots
	TEXT_BREAK_ELLIPSIS				= 0x0002,		//	tronque et ajoute ...
	TEXT_BREAK_OVERHANG				= 0x0004,		//	autorise le dépassement
	TEXT_BREAK_SPLIT				= 0x0008,		//	coupe brutalement si besoin
	
	TEXT_BREAK_SINGLE_LINE			= 0x0100,		//	force tout sur une ligne (utile avec ELLIPSIS, OVERHANG et SPLIT)
};

/*****************************************************************************/

struct BreakContext
{
	int				check_id;
	TextBreakMode	mode;
	
	agg::font_face*	face;
	wchar_t*		text;
	wchar_t*		chunk;
	unsigned char*	breaks;
	
	double			dash_length;
	
	int				pos;
	int				max_chunk_len;
	int				ellipsis_glyph;
	
	BreakContext (agg::font_face* font_face) : check_id (0xfaceb000), mode (TEXT_BREAK_NONE), face (font_face), text (0), chunk (0), breaks (0), dash_length (0), pos (0), max_chunk_len (0), ellipsis_glyph (0)
	{
	}
	
	~BreakContext ()
	{
		if (this->text)
		{
			delete[] this->text;
			this->text = 0;
		}
		if (this->chunk)
		{
			delete[] this->chunk;
			this->chunk = 0;
		}
		if (this->breaks)
		{
			delete[] this->breaks;
			this->breaks = 0;
		}
		
		this->face = 0;
		this->check_id = 0;
	}
	
	bool Check () const
	{
		return this->check_id == 0xfaceb000;
	}
};

/*****************************************************************************/
