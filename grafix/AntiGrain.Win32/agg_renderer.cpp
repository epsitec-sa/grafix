//	AntiGrain.Win32/agg_renderer.cpp
//
//	Copyright © 2003-2006, Pierre ARNAUD, OPaC bright ideas, Ch. du Fontenay 6,
//	                       CH-1400 YVERDON, Switzerland. All rights reserved. 
//
//	Contact: pierre.arnaud@opac.ch, http://www.opac.ch
//	License: see license.txt

#include "interface.h"
#include "structures.h"

#include "agg_conv_curve.h"
#include "agg_color_interpolator.h"

/*****************************************************************************/

void
AggRendererSolidSetAlphaMask(AggRendererSolid* renderer,
							 AggBuffer* buffer, int component)
{
	if (renderer)
	{
		renderer->renderer->active_mask_component = component;
		
		if ( (component >= 0)
		  && (component <= 3) )
		{
			renderer->renderer->am_a.attach (buffer->buffer);
			renderer->renderer->am_r.attach (buffer->buffer);
			renderer->renderer->am_g.attach (buffer->buffer);
			renderer->renderer->am_b.attach (buffer->buffer);
		}
	}
}

void
AggRendererSmoothSetAlphaMask(AggRendererSmooth* renderer,
							  AggBuffer* buffer, int component)
{
	if (renderer)
	{
		renderer->renderer->active_mask_component = component;
		
		if ( (component >= 0)
		  && (component <= 3) )
		{
			renderer->renderer->am_a.attach (buffer->buffer);
			renderer->renderer->am_r.attach (buffer->buffer);
			renderer->renderer->am_g.attach (buffer->buffer);
			renderer->renderer->am_b.attach (buffer->buffer);
		}
	}
}

void
AggRendererImageSetAlphaMask(AggRendererImage* renderer,
							 AggBuffer* buffer, int component)
{
	if (renderer)
	{
		renderer->renderer->active_mask_component = component;
		
		if ( (component >= 0)
		  && (component <= 3) )
		{
			renderer->renderer->am_a.attach (buffer->buffer);
			renderer->renderer->am_r.attach (buffer->buffer);
			renderer->renderer->am_g.attach (buffer->buffer);
			renderer->renderer->am_b.attach (buffer->buffer);
		}
	}
}

void
AggRendererGradientSetAlphaMask(AggRendererGradient* renderer,
								AggBuffer* buffer, int component)
{
	if (renderer)
	{
		renderer->renderer->active_mask_component = component;
		
		if ( (component >= 0)
		  && (component <= 3) )
		{
			renderer->renderer->am_a.attach (buffer->buffer);
			renderer->renderer->am_r.attach (buffer->buffer);
			renderer->renderer->am_g.attach (buffer->buffer);
			renderer->renderer->am_b.attach (buffer->buffer);
		}
	}
}

/*****************************************************************************/

AggRendererSolid*
AggRendererSolidNew(AggBuffer* buffer)
{
	AggRendererSolid* renderer = new AggRendererSolid (buffer);
	return renderer;
}

void
AggRendererSolidDelete(AggRendererSolid* renderer)
{
	if (renderer->fence != 0x5AA55AA5)
	{
		::DebugBreak ();
	}
	
	delete renderer;
}

void
AggRendererSolidClear(AggRendererSolid* renderer, double r, double g, double b, double a)
{
	if (renderer)
	{
		renderer->renderer->ren_base.clear (agg::rgba (r, g, b, a));
	}
}

void
AggRendererSolidColor(AggRendererSolid* renderer, double r, double g, double b, double a)
{
	if (renderer)
	{
		renderer->ren_solid.color (agg::rgba (r, g, b, a));
	}
}

/*****************************************************************************/

AggRendererSmooth*
AggRendererSmoothNew(AggBuffer* buffer)
{
	AggRendererSmooth* renderer = new AggRendererSmooth (buffer);
	return renderer;
}

void
AggRendererSmoothDelete(AggRendererSmooth* renderer)
{
	delete renderer;
}

void
AggRendererSmoothColor(AggRendererSmooth* renderer, double r, double g, double b, double a)
{
	if (renderer)
	{
		renderer->ren_smooth.color (agg::rgba (r, g, b, a));
	}
}

void
AggRendererSmoothSetup(AggRendererSmooth* renderer, double r1, double r2,
					   double xx, double xy, double yx, double yy, double tx, double ty)
{
	if (renderer)
	{
		renderer->transform_matrix = agg::trans_affine (xx, yx, xy, yy, tx, ty);
		double s = renderer->transform_matrix.scale ();
		
		r1 *= s;
		r2 *= s;
		
		//	Internally, line_interpolator_aa_base does not allow widths larger than 64; this
		//	constant is defined as max_half_width.
		
		if (r1 > 64) r1 = 64;
		if (r2 > 64) r2 = 64;
		
		renderer->profile.smoother_width (r2);
		renderer->profile.width (r1);
	}
}

void
AggRendererSmoothAddPath(AggRendererSmooth* renderer, AggPath* path)
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

AggRendererGradient*
AggRendererGradientNew(AggBuffer* buffer)
{
	AggRendererGradient* renderer = new AggRendererGradient (buffer);
	return renderer;
}

void
AggRendererGradientDelete(AggRendererGradient* renderer)
{
	delete renderer;
}

void
AggRendererGradientSelect(AggRendererGradient* renderer, int id)
{
	if (renderer)
	{
		renderer->Select (static_cast<AggRendererGradient::GradientID> (id));
	}
}

void
AggRendererGradientRange(AggRendererGradient* renderer, double r1, double r2)
{
	if (renderer)
	{
		renderer->r1 = r1;
		renderer->r2 = r2;
		renderer->is_ready = false;
	}
}

void
AggRendererGradientColor1(AggRendererGradient* renderer,
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
AggRendererGradientMatrix(AggRendererGradient* renderer,
						  double xx, double xy, double yx, double yy, double tx, double ty)
{
	if (renderer)
	{
		//	Caution: affine matrix sorts its elements in a different way than I do. AGG sorts
		//	them column by column, and I sort them as a 2x2 matrix, line by line, plus the
		//	separate translation vector.
		
		renderer->matrix = agg::trans_affine (xx, yx, xy, yy, tx, ty);
		renderer->is_ready = false;
	}
}

/*****************************************************************************/

AggRendererImage*
AggRendererImageNew(AggBuffer* buffer)
{
	AggRendererImage* renderer = new AggRendererImage (buffer);
	return renderer;
}

void
AggRendererImageDelete(AggRendererImage* renderer)
{
	delete renderer;
}

void
AggRendererImageSetStretchMode(AggRendererImage* renderer, int mode, double radius)
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
AggRendererImageMatrix(AggRendererImage* renderer,
					   double xx, double xy, double yx, double yy, double tx, double ty)
{
	if (renderer)
	{
		//	Caution: affine matrix sorts its elements in a different way than I do. AGG sorts
		//	them column by column, and I sort them as a 2x2 matrix, line by line, plus the
		//	separate translation vector.
		
		renderer->matrix = agg::trans_affine (xx, yx, xy, yy, tx, ty);
		renderer->is_ready = false;
	}
}

void
AggRendererImageSource1(AggRendererImage* renderer, AggBuffer* buffer)
{
	if (renderer)
	{
		if (buffer)
		{
			renderer->source_buffer.attach (buffer->pixmap.buf (), buffer->pixmap.width (), buffer->pixmap.height (), buffer->pixmap.stride ());
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

void
AggRendererImageSource2(AggRendererImage* renderer, void* buffer, int dx, int dy, int stride)
{
	if (renderer)
	{
		if (buffer)
		{
			renderer->source_buffer.attach (reinterpret_cast<unsigned char*> (buffer), dx, dy, stride);
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

void AggRendererFill4Colors(AggRendererBase* renderer,
							int x, int y, int dx, int dy,
							double r1, double g1, double b1,
							double r2, double g2, double b2,
							double r3, double g3, double b3,
							double r4, double g4, double b4)
{
	if (renderer)
	{
		agg::color_rect_rgba8 (renderer->renderer->ren_base, x, y, dx, dy,
							   agg::rgba8 (agg::rgba (r1, g1, b1)),
							   agg::rgba8 (agg::rgba (r2, g2, b2)),
							   agg::rgba8 (agg::rgba (r3, g3, b3)),
							   agg::rgba8 (agg::rgba (r4, g4, b4)));
	}
}

/*****************************************************************************/
