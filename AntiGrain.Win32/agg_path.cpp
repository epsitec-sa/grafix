#include "interface.h"
#include "structures.h"

#include "agg_arc.h"
#include "agg_bounding_rect.h"
#include "agg_font_path_provider.h"
#include "agg_conv_contour.h"
#include "agg_conv_curve.h"

using namespace agg;

AggPath* AggPathNew()
{
	AggPath* path = new AggPath ();
	return path;
}

void AggPathDelete(AggPath* path)
{
	delete path;
}

void AggPathMoveTo(AggPath* path, double x, double y)
{
	if (path)
	{
		path->path.move_to (x, y);
	}
}

void AggPathLineTo(AggPath* path, double x, double y)
{
	if (path)
	{
		path->path.line_to (x, y);
	}
}

void AggPathCurve3(AggPath* path, double x_c, double y_c, double x, double y)
{
	if (path)
	{
		path->path.curve3 (x_c, y_c, x, y);
	}
}

void AggPathCurve4(AggPath* path, double x_c1, double y_c1, double x_c2, double y_c2, double x, double y)
{
	if (path)
	{
		path->path.curve4 (x_c1, y_c1, x_c2, y_c2, x, y);
	}
}

void AggPathClose(AggPath* path)
{
	if (path)
	{
		path->path.end_poly (agg::path_flags_close);
	}
}

void AggPathAddNewPath(AggPath* path)
{
	if (path)
	{
		path->path.start_new_path ();
	}
}

void AggPathRemoveAll(AggPath* path)
{
	if (path)
	{
		path->path.remove_all ();
	}
}

int AggPathElemCount(AggPath* path)
{
	if (path)
	{
		path->path.rewind (0);
		
		int n = 0;
		unsigned cmd;
		double x, y;
		
		cmd = path->path.vertex(&x, &y);
		
		while(!agg::is_stop (cmd))
		{
			n++;
			cmd = path->path.vertex(&x, &y);
		}
		
		return n+1;
	}
	
	return 0;
}

void AggPathElemGet(AggPath* path, int max, int* types, double* x, double* y)
{
	if ( (path)
	  && (max > 0) )
	{
		path->path.rewind (0);
		
		int n = 0;
		unsigned cmd;
		
		cmd = path->path.vertex(x, y);
		
		while (--max && !agg::is_stop (cmd))
		{
			*types++ = cmd; x++; y++;
			n++;
			cmd = path->path.vertex(x, y);
		}
		
		*types = cmd;
	}
}



void AggPathAppendGlyph(AggPath* path, agg::font_face* face, int glyph, double xx, double xy, double yx, double yy, double tx, double ty, double bold)
{
	if (path && path && face->UpdateCache ())
	{
		agg::font_face::cache_record::size_info_record* info = face->FindSizeInfo (glyph);
		
		if ( (info)
		  && (info->num_coord) )
		{
			agg::trans_affine matrix = agg::trans_affine (xx, yx, xy, yy, tx, ty);
			
			if (bold)
			{
				agg::font_path_provider font_path = agg::font_path_provider (face, glyph, info, 0, 0, 1, 1);
				agg::conv_transform<agg::font_path_provider, agg::trans_affine> conv (font_path, matrix);
				agg::conv_curve<agg::conv_transform<agg::font_path_provider, agg::trans_affine> > curve (conv);
				agg::conv_contour<agg::conv_curve<agg::conv_transform<agg::font_path_provider, agg::trans_affine> > > contour (curve);
				
				curve.approximation_scale (2);
				
				contour.auto_detect_orientation (false);
				contour.width (- bold);
				
				path->path.add_path (contour, 0, false);
			}
			else
			{
				agg::font_path_provider font_path = agg::font_path_provider (face, glyph, info, 0, 0, 1, 1);
				agg::conv_transform<agg::font_path_provider, agg::trans_affine> conv (font_path, matrix);
				
				path->path.add_path (conv, 0, false);
			}
		}
	}
}

void AggPathAppendPath(AggPath* path, AggPath* path2, double xx, double xy, double yx, double yy, double tx, double ty, double scale, double bold)
{
	if (path && path2)
	{
		agg::trans_affine matrix = agg::trans_affine (xx, yx, xy, yy, tx, ty);
		
		if (bold)
		{
			agg::conv_transform<agg::path_storage, agg::trans_affine> conv (path2->path, matrix);
			agg::conv_curve<agg::conv_transform<agg::path_storage, agg::trans_affine> > curve (conv);
			agg::conv_contour<agg::conv_curve<agg::conv_transform<agg::path_storage, agg::trans_affine> > > contour (curve);
			
			curve.approximation_scale (scale * 2);
			
			contour.auto_detect_orientation (true);
			contour.width (bold);
			
			path->path.add_path (contour, 0, false);
		}
		else
		{
			if (scale)
			{
				agg::conv_transform<agg::path_storage, agg::trans_affine> conv (path2->path, matrix);
				agg::conv_curve<agg::conv_transform<agg::path_storage, agg::trans_affine> > curve (conv);
				
				curve.approximation_scale (scale * 2);
				
				path->path.add_path (curve, 0, false);
			}
			else
			{
				path->path.add_path (path2->path, 0, false);
			}
		}
	}
}

void AggPathComputeBounds(AggPath* path, double& x1, double& y1, double& x2, double& y2)
{
	if (path)
	{
		unsigned path_i [1] = { 0 };
		
		agg::bounding_rect (path->path, path_i, 0, 1, &x1, &y1, &x2, &y2);
	}
}

void AggPathAppendArc(AggPath* path, double x, double y, double rx, double ry, double a1, double a2, bool ccw, double scale, bool continue_path)
{
	if (path)
	{
		agg::arc arc (x, y, rx, ry, a1, a2, ccw);
		
		arc.approximation_scale (scale * 2);
		path->path.add_path (arc, 0, continue_path);
	}
}


void AggPathDashReset(AggPath* path)
{
	if (path)
	{
		path->dash.remove_all_dashes ();
		path->has_dashes = false;
	}
}

void AggPathDashAdd(AggPath* path, double dash_len, double gap_len)
{
	if (path)
	{
		path->dash.add_dash (dash_len, gap_len);
		path->has_dashes = true;
	}
}

void AggPathDashSetStart(AggPath* path, double dash_start)
{
	if (path)
	{
		path->dash.dash_start (dash_start);
	}
}

void AggPathAppendDashedPath(AggPath* path, AggPath* dash, double scale)
{
	if (path && dash && (scale > 0))
	{
		dash->curve.approximation_scale (scale * 2);
		path->path.add_path (dash->dash, 0, false);
	}
}