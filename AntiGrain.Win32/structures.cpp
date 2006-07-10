#include "structures.h"

bool
AggRendererImage::Validate ()
{
	if (this->is_ready == false)
	{
		if (this->is_source_ok)
		{
			this->interpolator.transformer (this->matrix);
			this->img_src.background_color (agg::rgba(1.0, 1.0, 1.0, 0.0));
			this->img_pixf.attach (this->source_buffer); //@
			this->span_gen.interpolator (this->interpolator);
			this->is_ready = true;
		}
	}
	
	return this->is_ready;
}

void
AggRendererGradient::Select (AggRendererGradient::GradientID id)
{
	switch (id)
	{
		case GRADIENT_X:		this->gradient_ptr = & this->gr_x;			break;
		case GRADIENT_Y:		this->gradient_ptr = & this->gr_y;			break;
		case GRADIENT_XY:		this->gradient_ptr = & this->gr_xy;			break;
		case GRADIENT_CIRCLE:	this->gradient_ptr = & this->gr_circle;		break;
		case GRADIENT_DIAMOND:	this->gradient_ptr = & this->gr_diamond;	break;
		case GRADIENT_SQRT_XY:	this->gradient_ptr = & this->gr_sqrt_xy;	break;
		case GRADIENT_CONIC:	this->gradient_ptr = & this->gr_conic;		break;
		default:				this->gradient_ptr = 0;						break;
	}
	
	this->is_ready = false;
}

bool
AggRendererGradient::Validate ()
{
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
