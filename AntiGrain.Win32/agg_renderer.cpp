#include "interface.h"
#include "structures.h"

#include "agg_conv_curve.h"


void AggRendererSolidSetAlphaMask(AggRendererSolid* renderer, AggBuffer* buffer, int component)
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

void AggRendererSmoothSetAlphaMask(AggRendererSmooth* renderer, AggBuffer* buffer, int component)
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

void AggRendererImageSetAlphaMask(AggRendererImage* renderer, AggBuffer* buffer, int component)
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

void AggRendererGradientSetAlphaMask(AggRendererGradient* renderer, AggBuffer* buffer, int component)
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




AggRendererSolid* AggRendererSolidNew(AggBuffer* buffer)
{
	AggRendererSolid* renderer = new AggRendererSolid (buffer);
	return renderer;
}

void AggRendererSolidClear(AggRendererSolid* renderer, double r, double g, double b, double a)
{
	if (renderer)
	{
		renderer->renderer->ren_base.clear (agg::rgba (r, g, b, a));
	}
}

void AggRendererSolidColor(AggRendererSolid* renderer, double r, double g, double b, double a)
{
	if (renderer)
	{
		renderer->ren_solid.color (agg::rgba (r, g, b, a));
	}
}

void AggRendererSolidDelete(AggRendererSolid* renderer)
{
	delete renderer;
}



AggRendererSmooth* AggRendererSmoothNew(AggBuffer* buffer)
{
	AggRendererSmooth* renderer = new AggRendererSmooth (buffer);
	return renderer;
}

void AggRendererSmoothColor(AggRendererSmooth* renderer, double r, double g, double b, double a)
{
	if (renderer)
	{
		renderer->ren_smooth.color (agg::rgba (r, g, b, a));
	}
}

void AggRendererSmoothSetup(AggRendererSmooth* renderer, double r1, double r2, double xx, double xy, double yx, double yy, double tx, double ty)
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

void AggRendererSmoothAddPath(AggRendererSmooth* renderer, AggPath* path)
{
	if ( (renderer)
	  && (path) )
	{
		{
			{
				{
					agg::conv_transform<agg::path_storage, agg::trans_affine> conv (path->path, renderer->transform_matrix);
					agg::conv_curve<agg::conv_transform<agg::path_storage, agg::trans_affine> > curve (conv);
					renderer->ras_smooth.add_path (curve);
				}
			}
		}
	}
}

void AggRendererSmoothDelete(AggRendererSmooth* renderer)
{
	delete renderer;
}


AggRendererGradient* AggRendererGradientNew(AggBuffer* buffer)
{
	AggRendererGradient* renderer = new AggRendererGradient (buffer);
	return renderer;
}

void AggRendererGradientDelete(AggRendererGradient* renderer)
{
	delete renderer;
}

void AggRendererGradientSelect(AggRendererGradient* renderer, int id)
{
	if (renderer)
	{
		renderer->Select (static_cast<AggRendererGradient::GradientID> (id));
	}
}

void AggRendererGradientRange(AggRendererGradient* renderer, double r1, double r2)
{
	if (renderer)
	{
		renderer->r1 = r1;
		renderer->r2 = r2;
		renderer->is_ready = false;
	}
}

void AggRendererGradientColor1(AggRendererGradient* renderer,
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

void AggRendererGradientMatrix(AggRendererGradient* renderer,
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


AggRendererImage* AggRendererImageNew(AggBuffer* buffer)
{
	AggRendererImage* renderer = new AggRendererImage (buffer);
	return renderer;
}

void AggRendererImageDelete(AggRendererImage* renderer)
{
	delete renderer;
}


void AggRendererImageMatrix(AggRendererImage* renderer,
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

void AggRendererImageSource1(AggRendererImage* renderer, AggBuffer* buffer)
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

void AggRendererImageSource2(AggRendererImage* renderer, void* buffer, int dx, int dy, int stride)
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
