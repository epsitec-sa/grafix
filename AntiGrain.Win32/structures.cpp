#include "structures.h"

#include "agg_font_manager.h"
#include "agg_font_face.h"
#include "agg_font_path_provider.h"

bool
AggRendererImage::Validate ()
{
	if (this->is_ready == false)
	{
		if (this->is_source_ok)
		{
			this->interpolator.transformer (this->matrix);
			this->span_gen.source_image (this->source_buffer);
			this->span_gen.interpolator (this->interpolator);
			this->span_gen.background_color (agg::rgba(1.0, 1.0, 1.0, 0.0));
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



extern void DiagnosticDump(int x)
{
	static char buffer[100];
	sprintf(buffer, "%x", x);
	::OutputDebugString (buffer);
}

extern bool AnalysePath(agg::conv_curve<agg::font_path_provider>& vs, unsigned start, unsigned num, double* x1, double* y1, double* x2, double* y2)
{
    unsigned i;
    double x;
    double y;
    bool first = true;

    for(i = 0; i < num; i++)
    {
        vs.rewind(0);
        unsigned cmd;
		while(!agg::is_stop(cmd = vs.vertex(&x, &y)))
        {
			if(agg::is_vertex(cmd))
            {
                if(first)
                {
                    *x1 = (x);
                    *y1 = (y);
                    *x2 = (x);
                    *y2 = (y);
					::DiagnosticDump ((int)(*x1));
					::DiagnosticDump ((int)(*y1));
					::DiagnosticDump ((int)(*x2));
					::DiagnosticDump ((int)(*y2));
                    first = false;
                }
                else
                {
                    if((x) < *x1) *x1 = (x);
                    if((y) < *y1) *y1 = (y);
                    if((x) > *x2) *x2 = (x);
                    if((y) > *y2) *y2 = (y);
					::OutputDebugString ("--");
					::DiagnosticDump ((int)(*x1));
					::DiagnosticDump ((int)(*y1));
					::DiagnosticDump ((int)(*x2));
					::DiagnosticDump ((int)(*y2));
                }
            }
        }
    }
    return *x1 <= *x2 && *y1 <= *y2;
}
