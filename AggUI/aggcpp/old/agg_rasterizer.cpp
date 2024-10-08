//	AntiGrain.Win32/agg_rasterizer.cpp
//
//	Copyright � 2003-2007, Pierre ARNAUD, OPaC bright ideas, Ch. du Fontenay 6,
//	                       CH-1400 YVERDON, Switzerland. All rights reserved. 
//
//	Contact: pierre.arnaud@opac.ch, http://www.opac.ch
//	License: see license.txt

#include "antigrain.h"
#include "structures.h"

#include "agg_font_path_provider.h"
#include "agg_conv_curve.h"

/*****************************************************************************/

AggRasterizer*
AggRasterizerNew()
{
	AggRasterizer* rasterizer = new AggRasterizer ();
	rasterizer->has_transform = false;
	rasterizer->has_clip_box  = false;
	return rasterizer;
}

void
AggRasterizerDelete(AggRasterizer* rasterizer)
{
	delete rasterizer;
}

/*****************************************************************************/

void
AggRasterizerClear(AggRasterizer* rasterizer)
{
	if (rasterizer)
	{
		rasterizer->rasterizer.reset ();
	}
}

void
AggRasterizerFillingRule(AggRasterizer* rasterizer, int rule)
{
	if ( (rasterizer)
	  && (rule) )
	{
		switch (rule)
		{
			case 1:
				rasterizer->rasterizer.filling_rule (agg::fill_even_odd);
				break;
			case 2:
				rasterizer->rasterizer.filling_rule (agg::fill_non_zero);
				break;
		}
	}
}

bool
AggRasterizerHitTest(AggRasterizer* rasterizer, int x, int y)
{
	if (rasterizer)
	{
		return rasterizer->rasterizer.hit_test (x, y);
	}
	
	return false;
}

void
AggRasterizerGamma(AggRasterizer* rasterizer, double gamma)
{
	if (rasterizer)
	{
		if (gamma == 0.0)
		{
			rasterizer->rasterizer.gamma (agg::gamma_threshold ());
		}
		else
		{
			rasterizer->rasterizer.gamma (agg::gamma_power (gamma));
		}
	}
}

void
AggRasterizerSetTransform(AggRasterizer* rasterizer,
						  double xx, double xy, double yx, double yy, double tx, double ty)
{
	if (rasterizer)
	{
		if ( (xx == 1) && (xy == 0) && (tx == 0)
		  && (yx == 0) && (yy == 1) && (ty == 0) )
		{
			rasterizer->has_transform = false;
		}
		else
		{
			//	Caution: affine matrix sorts its elements in a different way than I do. AGG sorts
			//	them column by column, and I sort them as a 2x2 matrix, line by line, plus the
			//	separate translation vector.
			
			rasterizer->has_transform = true;
			rasterizer->transform_matrix = agg::trans_affine (xx, yx, xy, yy, tx, ty);
		}
	}
}

void
AggRasterizerSetClipBox(AggRasterizer* rasterizer, double x1, double y1, double x2, double y2)
{
	if (rasterizer)
	{
#if defined(USE_OLD_CLIPPING_CODE)
		rasterizer->has_clip_box = true;
#else
		rasterizer->rasterizer.clip_box (x1, y1, x2, y2);
#endif
		
		rasterizer->x1 = x1;
		rasterizer->y1 = y1;
		rasterizer->x2 = x2;
		rasterizer->y2 = y2;
	}
}

void
AggRasterizerResetClipBox(AggRasterizer* rasterizer)
{
	if (rasterizer)
	{
#if defined(USE_OLD_CLIPPING_CODE)
		rasterizer->has_clip_box = false;
#else
		rasterizer->rasterizer.reset_clipping ();
#endif
	}
}

/*****************************************************************************/

void
AggRasterizerAddPath(AggRasterizer* rasterizer, AggPath* path, bool curved)
{
	if ( (rasterizer)
	  && (path) )
	{
		if (curved)
		{
			if (rasterizer->has_transform)
			{
				if (rasterizer->has_clip_box)
				{
					agg::conv_transform<agg::path_storage, agg::trans_affine> conv (path->path, rasterizer->transform_matrix);
					agg::conv_curve<agg::conv_transform<agg::path_storage, agg::trans_affine> > curve (conv);
					agg::conv_clip_polygon<agg::conv_curve<agg::conv_transform<agg::path_storage, agg::trans_affine> > > clip (curve);
					
					curve.approximation_scale (2);
					
					double x1 = rasterizer->x1; double y1 = rasterizer->y1;
					double x2 = rasterizer->x2; double y2 = rasterizer->y2;
					
					clip.clip_box (x1, y1, x2, y2);
					
					rasterizer->rasterizer.add_path (clip);
				}
				else
				{
					agg::conv_transform<agg::path_storage, agg::trans_affine> conv (path->path, rasterizer->transform_matrix);
					agg::conv_curve<agg::conv_transform<agg::path_storage, agg::trans_affine> > curve (conv);
					
					curve.approximation_scale (2);
					
					rasterizer->rasterizer.add_path (curve);
				}
			}
			else
			{
				if (rasterizer->has_clip_box)
				{
					agg::conv_curve<agg::path_storage> curve (path->path);
					agg::conv_clip_polygon<agg::conv_curve<agg::path_storage> > clip (curve);
					
					curve.approximation_scale (2);
					
					double x1 = rasterizer->x1; double y1 = rasterizer->y1;
					double x2 = rasterizer->x2; double y2 = rasterizer->y2;
					
					clip.clip_box (x1, y1, x2, y2);
					
					rasterizer->rasterizer.add_path (clip);
				}
				else
				{
					agg::conv_curve<agg::path_storage> curve (path->path);
					
					curve.approximation_scale (2);
					
					rasterizer->rasterizer.add_path (curve);
				}
			}
		}
		else
		{
			if (rasterizer->has_transform)
			{
				if (rasterizer->has_clip_box)
				{
					agg::conv_transform<agg::path_storage, agg::trans_affine> conv (path->path, rasterizer->transform_matrix);
					agg::conv_clip_polygon<agg::conv_transform<agg::path_storage, agg::trans_affine> > clip (conv);
					
					double x1 = rasterizer->x1; double y1 = rasterizer->y1;
					double x2 = rasterizer->x2; double y2 = rasterizer->y2;
					
					clip.clip_box (x1, y1, x2, y2);
					
					rasterizer->rasterizer.add_path (clip);
				}
				else
				{
					agg::conv_transform<agg::path_storage, agg::trans_affine> conv (path->path, rasterizer->transform_matrix);
					rasterizer->rasterizer.add_path (conv);
				}
			}
			else
			{
				if (rasterizer->has_clip_box)
				{
					agg::conv_clip_polygon<agg::path_storage> clip (path->path);
					
					double x1 = rasterizer->x1; double y1 = rasterizer->y1;
					double x2 = rasterizer->x2; double y2 = rasterizer->y2;
					
					clip.clip_box (x1, y1, x2, y2);
					
					rasterizer->rasterizer.add_path (clip);
				}
				else
				{
					rasterizer->rasterizer.add_path (path->path);
				}
			}
		}
	}
}

/*****************************************************************************/

void
AggRasterizerAddGlyph(AggRasterizer* rasterizer, agg::font_face* face,
					  int glyph, double x, double y, double scale)
{
	if ( (rasterizer)
	  && (face) && (face->UpdateCache ())
	  && (scale)
	  && (glyph < 0xffff) && (glyph >= 0) )
	{
		face->RetGlyphAdvance (glyph);
		
		agg::font_face::cache_record::size_info_record* info = face->FindSizeInfo (glyph);
		
		if ( (info)
		  && (info->num_coord) )
		{
			if (rasterizer->has_transform)
			{
				if (rasterizer->has_clip_box)
				{
					agg::font_path_provider font_path = agg::font_path_provider (face, glyph, info, x, y, scale, scale);
					agg::conv_transform<agg::font_path_provider, agg::trans_affine> conv (font_path, rasterizer->transform_matrix);
					agg::conv_curve<agg::conv_transform<agg::font_path_provider, agg::trans_affine> > curve (conv);
					agg::conv_clip_polygon<agg::conv_curve<agg::conv_transform<agg::font_path_provider, agg::trans_affine> > > clip (curve);
					
					curve.approximation_scale (2);
					
					double x1 = rasterizer->x1; double y1 = rasterizer->y1;
					double x2 = rasterizer->x2; double y2 = rasterizer->y2;
					
					clip.clip_box (x1, y1, x2, y2);
					
					rasterizer->rasterizer.add_path (clip);
				}
				else
				{
					agg::font_path_provider font_path = agg::font_path_provider (face, glyph, info, x, y, scale, scale);
					agg::conv_transform<agg::font_path_provider, agg::trans_affine> conv (font_path, rasterizer->transform_matrix);
					agg::conv_curve<agg::conv_transform<agg::font_path_provider, agg::trans_affine> > curve (conv);
					
					curve.approximation_scale (2);
					
					rasterizer->rasterizer.add_path (curve);
				}
			}
			else
			{
				if (rasterizer->has_clip_box)
				{
					agg::font_path_provider font_path = agg::font_path_provider (face, glyph, info, x, y, scale, scale);
					agg::conv_curve<agg::font_path_provider> curve (font_path);
					agg::conv_clip_polygon<agg::conv_curve<agg::font_path_provider> > clip (curve);
					
					curve.approximation_scale (2);
					
					double x1 = rasterizer->x1; double y1 = rasterizer->y1;
					double x2 = rasterizer->x2; double y2 = rasterizer->y2;
					
					clip.clip_box (x1, y1, x2, y2);
					
					rasterizer->rasterizer.add_path (clip);
				}
				else
				{
					agg::font_path_provider font_path = agg::font_path_provider (face, glyph, info, x, y, scale, scale);
					agg::conv_curve<agg::font_path_provider> curve (font_path);
					
					curve.approximation_scale (2);
					
					rasterizer->rasterizer.add_path (curve);
				}
			}
		}
	}
}

/*****************************************************************************/

void
AggRasterizerAddGlyphXY(AggRasterizer* rasterizer, agg::font_face* face,
						int glyph,
						double x, double y, double scale_x, double scale_y)
{
	if ( (rasterizer)
	  && (face) && (face->UpdateCache ())
	  && (scale_x) && (scale_y)
	  && (glyph < 0xffff) && (glyph >= 0) )
	{
		face->RetGlyphAdvance (glyph);
		
		agg::font_face::cache_record::size_info_record* info = face->FindSizeInfo (glyph);
		
		if ( (info)
		  && (info->num_coord) )
		{
			if (rasterizer->has_transform)
			{
				if (rasterizer->has_clip_box)
				{
					agg::font_path_provider font_path = agg::font_path_provider (face, glyph, info, x, y, scale_x, scale_y);
					agg::conv_transform<agg::font_path_provider, agg::trans_affine> conv (font_path, rasterizer->transform_matrix);
					agg::conv_curve<agg::conv_transform<agg::font_path_provider, agg::trans_affine> > curve (conv);
					agg::conv_clip_polygon<agg::conv_curve<agg::conv_transform<agg::font_path_provider, agg::trans_affine> > > clip (curve);
					
					curve.approximation_scale (2);
					
					double x1 = rasterizer->x1; double y1 = rasterizer->y1;
					double x2 = rasterizer->x2; double y2 = rasterizer->y2;
					
					clip.clip_box (x1, y1, x2, y2);
					
					rasterizer->rasterizer.add_path (clip);
				}
				else
				{
					agg::font_path_provider font_path = agg::font_path_provider (face, glyph, info, x, y, scale_x, scale_y);
					agg::conv_transform<agg::font_path_provider, agg::trans_affine> conv (font_path, rasterizer->transform_matrix);
					agg::conv_curve<agg::conv_transform<agg::font_path_provider, agg::trans_affine> > curve (conv);
					
					curve.approximation_scale (2);
					
					rasterizer->rasterizer.add_path (curve);
				}
			}
			else
			{
				if (rasterizer->has_clip_box)
				{
					agg::font_path_provider font_path = agg::font_path_provider (face, glyph, info, x, y, scale_x, scale_y);
					agg::conv_curve<agg::font_path_provider> curve (font_path);
					agg::conv_clip_polygon<agg::conv_curve<agg::font_path_provider> > clip (curve);
					
					curve.approximation_scale (2);
					
					double x1 = rasterizer->x1; double y1 = rasterizer->y1;
					double x2 = rasterizer->x2; double y2 = rasterizer->y2;
					
					clip.clip_box (x1, y1, x2, y2);
					
					rasterizer->rasterizer.add_path (clip);
				}
				else
				{
					agg::font_path_provider font_path = agg::font_path_provider (face, glyph, info, x, y, scale_x, scale_y);
					agg::conv_curve<agg::font_path_provider> curve (font_path);
					
					curve.approximation_scale (2);
					
					rasterizer->rasterizer.add_path (curve);
				}
			}
		}
	}
}

/*****************************************************************************/

#if 0
double
AggRasterizerAddText(AggRasterizer* rasterizer, agg::font_face* face,
					 const wchar_t* text, int mode,
					 double xx, double xy, double yx, double yy, double tx, double ty)
{
	double width = 0;
	
	if ( (rasterizer)
	  && (face) && (face->UpdateCache ())
	  && (text) )
	{
		double scale = 1.0;
		
		while (*text)
		{
			agg::trans_affine matrix = agg::trans_affine (xx, yx, xy, yy, tx, ty);
			
			if (rasterizer->has_transform)
			{
				matrix *= rasterizer->transform_matrix;
			}
			
			agg::int32u unicode = *text++;
			agg::int16u glyph   = face->RetGlyphIndex (unicode);
			double advance = face->RetGlyphAdvance (glyph) * xx;
			
			width += advance;
			tx += advance;
			
			agg::font_face::cache_record::size_info_record* info = face->FindSizeInfo (glyph);
			
			if ( (info)
			  && (info->num_coord) )
			{
				if (rasterizer->has_clip_box)
				{
					agg::font_path_provider font_path = agg::font_path_provider (face, glyph, info, 0, 0, scale, scale);
					agg::conv_transform<agg::font_path_provider, agg::trans_affine> conv (font_path, matrix);
					agg::conv_curve<agg::conv_transform<agg::font_path_provider, agg::trans_affine> > curve (conv);
					agg::conv_clip_polygon<agg::conv_curve<agg::conv_transform<agg::font_path_provider, agg::trans_affine> > > clip (curve);
					
					curve.approximation_scale (2);
					
					double x1 = rasterizer->x1; double y1 = rasterizer->y1;
					double x2 = rasterizer->x2; double y2 = rasterizer->y2;
					
					clip.clip_box (x1, y1, x2, y2);
					
					rasterizer->rasterizer.add_path (clip);
				}
				else
				{
					agg::font_path_provider font_path = agg::font_path_provider (face, glyph, info, 0, 0, scale, scale);
					agg::conv_transform<agg::font_path_provider, agg::trans_affine> conv (font_path, matrix);
					agg::conv_curve<agg::conv_transform<agg::font_path_provider, agg::trans_affine> > curve (conv);
					
					curve.approximation_scale (2);
					
					rasterizer->rasterizer.add_path (curve);
				}
			}
		}
	}
	
	return width;
}
#endif

/*****************************************************************************/

void
AggRasterizerAddPathStroke1(AggRasterizer* rasterizer,
							AggPath* path, double width, bool curved)
{
	if ( (rasterizer)
	  && (path) )
	{
		if (curved)
		{
			if (rasterizer->has_transform)
			{
				if (rasterizer->has_clip_box)
				{
					agg::conv_curve<agg::path_storage> curve (path->path);
					agg::conv_stroke<agg::conv_curve<agg::path_storage> > stroke (curve);
					
					double s = rasterizer->transform_matrix.scale () * 2;
					curve.approximation_scale (s);
					stroke.approximation_scale (s);
					stroke.width (width);
					
					agg::conv_transform<agg::conv_stroke<agg::conv_curve<agg::path_storage> >, agg::trans_affine> conv (stroke, rasterizer->transform_matrix);
					agg::conv_clip_polygon<agg::conv_transform<agg::conv_stroke<agg::conv_curve<agg::path_storage> >, agg::trans_affine> > clip (conv);
					
					double x1 = rasterizer->x1; double y1 = rasterizer->y1;
					double x2 = rasterizer->x2; double y2 = rasterizer->y2;
					
					clip.clip_box (x1, y1, x2, y2);
					
					rasterizer->rasterizer.add_path (clip);
				}
				else
				{
					agg::conv_curve<agg::path_storage> curve (path->path);
					agg::conv_stroke<agg::conv_curve<agg::path_storage> > stroke (curve);
					
					double s = rasterizer->transform_matrix.scale () * 2;
					curve.approximation_scale (s);
					stroke.approximation_scale (s);
					stroke.width (width);
					
					agg::conv_transform<agg::conv_stroke<agg::conv_curve<agg::path_storage> >, agg::trans_affine> conv (stroke, rasterizer->transform_matrix);
					
					rasterizer->rasterizer.add_path (conv);
				}
			}
			else
			{
				if (rasterizer->has_clip_box)
				{
					agg::conv_curve<agg::path_storage> curve (path->path);
					agg::conv_stroke<agg::conv_curve<agg::path_storage> > stroke (curve);
					
					curve.approximation_scale (2);
					
					stroke.width (width);
					
					agg::conv_clip_polygon<agg::conv_stroke<agg::conv_curve<agg::path_storage> > > clip (stroke);
					
					double x1 = rasterizer->x1; double y1 = rasterizer->y1;
					double x2 = rasterizer->x2; double y2 = rasterizer->y2;
					
					clip.clip_box (x1, y1, x2, y2);
					
					rasterizer->rasterizer.add_path (clip);
				}
				else
				{
					agg::conv_curve<agg::path_storage> curve (path->path);
					agg::conv_stroke<agg::conv_curve<agg::path_storage> > stroke (curve);
					
					curve.approximation_scale (2);
					
					stroke.width (width);
					
					rasterizer->rasterizer.add_path (stroke);
				}
			}
		}
		else
		{
			if (rasterizer->has_transform)
			{
				if (rasterizer->has_clip_box)
				{
					agg::conv_stroke<agg::path_storage> stroke (path->path);
					
					double s = rasterizer->transform_matrix.scale ();
					stroke.approximation_scale (s);
					stroke.width (width);
					
					agg::conv_transform<agg::conv_stroke<agg::path_storage>, agg::trans_affine> conv (stroke, rasterizer->transform_matrix);
					agg::conv_clip_polygon<agg::conv_transform<agg::conv_stroke<agg::path_storage>, agg::trans_affine> > clip (conv);
					
					double x1 = rasterizer->x1; double y1 = rasterizer->y1;
					double x2 = rasterizer->x2; double y2 = rasterizer->y2;
					
					clip.clip_box (x1, y1, x2, y2);
					
					rasterizer->rasterizer.add_path (clip);
				}
				else
				{
					agg::conv_stroke<agg::path_storage> stroke (path->path);
					
					double s = rasterizer->transform_matrix.scale ();
					stroke.approximation_scale (s);
					stroke.width (width);
					
					agg::conv_transform<agg::conv_stroke<agg::path_storage>, agg::trans_affine> conv (stroke, rasterizer->transform_matrix);
					rasterizer->rasterizer.add_path (conv);
				}
			}
			else
			{
				if (rasterizer->has_clip_box)
				{
					agg::conv_stroke<agg::path_storage> stroke (path->path);
					
					stroke.width (width);
					
					agg::conv_clip_polygon<agg::conv_stroke<agg::path_storage> > clip (stroke);
					
					double x1 = rasterizer->x1; double y1 = rasterizer->y1;
					double x2 = rasterizer->x2; double y2 = rasterizer->y2;
					
					clip.clip_box (x1, y1, x2, y2);
					
					rasterizer->rasterizer.add_path (clip);
				}
				else
				{
					agg::conv_stroke<agg::path_storage> stroke (path->path);
					
					stroke.width (width);
					
					rasterizer->rasterizer.add_path (stroke);
				}
			}
		}
	}
}

/*****************************************************************************/

void
AggRasterizerAddPathStroke2(AggRasterizer* rasterizer,
							AggPath* path, double width, int cap, int join,
							double miter_limit, bool curved)
{
	if (miter_limit < 0)
	{
		miter_limit = - miter_limit;
	}
	
	if ( (rasterizer)
	  && (path) )
	{
		if (curved)
		{
			if (rasterizer->has_transform)
			{
				if (rasterizer->has_clip_box)
				{
					agg::conv_curve<agg::path_storage> curve (path->path);
					agg::conv_stroke<agg::conv_curve<agg::path_storage> > stroke (curve);
					
					double s = 2 * rasterizer->transform_matrix.scale ();
					curve.approximation_scale (s);
					stroke.approximation_scale (s);
					stroke.width (width);
					stroke.line_cap ((agg::line_cap_e) cap);
					stroke.line_join ((agg::line_join_e) join);
					stroke.miter_limit (miter_limit);
					
					agg::conv_transform<agg::conv_stroke<agg::conv_curve<agg::path_storage> >, agg::trans_affine> conv (stroke, rasterizer->transform_matrix);
					agg::conv_clip_polygon<agg::conv_transform<agg::conv_stroke<agg::conv_curve<agg::path_storage> >, agg::trans_affine> > clip (conv);
					
					double x1 = rasterizer->x1; double y1 = rasterizer->y1;
					double x2 = rasterizer->x2; double y2 = rasterizer->y2;
					
					clip.clip_box (x1, y1, x2, y2);
					
					rasterizer->rasterizer.add_path (clip);
				}
				else
				{
					agg::conv_curve<agg::path_storage> curve (path->path);
					agg::conv_stroke<agg::conv_curve<agg::path_storage> > stroke (curve);
					
					double s = 2 * rasterizer->transform_matrix.scale ();
					curve.approximation_scale (s);
					stroke.approximation_scale (s);
					stroke.width (width);
					stroke.line_cap ((agg::line_cap_e) cap);
					stroke.line_join ((agg::line_join_e) join);
					stroke.miter_limit (miter_limit);
					
					agg::conv_transform<agg::conv_stroke<agg::conv_curve<agg::path_storage> >, agg::trans_affine> conv (stroke, rasterizer->transform_matrix);
					
					rasterizer->rasterizer.add_path (conv);
				}
			}
			else
			{
				if (rasterizer->has_clip_box)
				{
					agg::conv_curve<agg::path_storage> curve (path->path);
					agg::conv_stroke<agg::conv_curve<agg::path_storage> > stroke (curve);
					
					curve.approximation_scale (2);
					
					stroke.approximation_scale (2);
					stroke.width (width);
					stroke.line_cap ((agg::line_cap_e) cap);
					stroke.line_join ((agg::line_join_e) join);
					stroke.miter_limit (miter_limit);
					
					agg::conv_clip_polygon<agg::conv_stroke<agg::conv_curve<agg::path_storage> > > clip (stroke);
					
					double x1 = rasterizer->x1; double y1 = rasterizer->y1;
					double x2 = rasterizer->x2; double y2 = rasterizer->y2;
					
					clip.clip_box (x1, y1, x2, y2);
					
					rasterizer->rasterizer.add_path (clip);
				}
				else
				{
					agg::conv_curve<agg::path_storage> curve (path->path);
					agg::conv_stroke<agg::conv_curve<agg::path_storage> > stroke (curve);
					
					curve.approximation_scale (2);
					
					stroke.approximation_scale (2);
					stroke.width (width);
					stroke.line_cap ((agg::line_cap_e) cap);
					stroke.line_join ((agg::line_join_e) join);
					stroke.miter_limit (miter_limit);
					
					rasterizer->rasterizer.add_path (stroke);
				}
			}
		}
		else
		{
			if (rasterizer->has_transform)
			{
				if (rasterizer->has_clip_box)
				{
					agg::conv_stroke<agg::path_storage> stroke (path->path);
					
					double s = 2 * rasterizer->transform_matrix.scale ();
					stroke.approximation_scale (s);
					stroke.width (width);
					stroke.line_cap ((agg::line_cap_e) cap);
					stroke.line_join ((agg::line_join_e) join);
					stroke.miter_limit (miter_limit);
					
					agg::conv_transform<agg::conv_stroke<agg::path_storage>, agg::trans_affine> conv (stroke, rasterizer->transform_matrix);
					agg::conv_clip_polygon<agg::conv_transform<agg::conv_stroke<agg::path_storage>, agg::trans_affine> > clip (conv);
					
					double x1 = rasterizer->x1; double y1 = rasterizer->y1;
					double x2 = rasterizer->x2; double y2 = rasterizer->y2;
					
					clip.clip_box (x1, y1, x2, y2);
					
					rasterizer->rasterizer.add_path (clip);
				}
				else
				{
					agg::conv_stroke<agg::path_storage> stroke (path->path);
					
					double s = 2 * rasterizer->transform_matrix.scale ();
					stroke.approximation_scale (s);
					stroke.width (width);
					stroke.line_cap ((agg::line_cap_e) cap);
					stroke.line_join ((agg::line_join_e) join);
					stroke.miter_limit (miter_limit);
					
					agg::conv_transform<agg::conv_stroke<agg::path_storage>, agg::trans_affine> conv (stroke, rasterizer->transform_matrix);
					
					rasterizer->rasterizer.add_path (conv);
				}
			}
			else
			{
				if (rasterizer->has_clip_box)
				{
					agg::conv_stroke<agg::path_storage> stroke (path->path);
					
					stroke.approximation_scale (2);
					stroke.width (width);
					stroke.line_cap ((agg::line_cap_e) cap);
					stroke.line_join ((agg::line_join_e) join);
					stroke.miter_limit (miter_limit);
					
					agg::conv_clip_polygon<agg::conv_stroke<agg::path_storage> > clip (stroke);
					
					double x1 = rasterizer->x1; double y1 = rasterizer->y1;
					double x2 = rasterizer->x2; double y2 = rasterizer->y2;
					
					clip.clip_box (x1, y1, x2, y2);
					
					rasterizer->rasterizer.add_path (clip);
				}
				else
				{
					agg::conv_stroke<agg::path_storage> stroke (path->path);
					
					stroke.approximation_scale (2);
					stroke.width (width);
					stroke.line_cap ((agg::line_cap_e) cap);
					stroke.line_join ((agg::line_join_e) join);
					stroke.miter_limit (miter_limit);
					
					rasterizer->rasterizer.add_path (stroke);
				}
			}
		}
	}
}

/*****************************************************************************/

void
AggRasterizerRenderSolid(AggRasterizer* rasterizer, AggRendererSolid* renderer)
{
	if ( (rasterizer)
	  && (renderer) )
	{
		switch (renderer->renderer->active_mask_component)
		{
			case 0:
				agg::render_scanlines (rasterizer->rasterizer, renderer->renderer->sl_a, renderer->ren_solid);
				break;
				
			case 1:
				agg::render_scanlines (rasterizer->rasterizer, renderer->renderer->sl_r, renderer->ren_solid);
				break;
			
			case 2:
				agg::render_scanlines (rasterizer->rasterizer, renderer->renderer->sl_g, renderer->ren_solid);
				break;
			
			case 3:
				agg::render_scanlines (rasterizer->rasterizer, renderer->renderer->sl_b, renderer->ren_solid);
				break;
			
			default:
				agg::render_scanlines (rasterizer->rasterizer, renderer->renderer->scanline, renderer->ren_solid);
				break;
		}
	}
}

void
AggRasterizerRenderImage(AggRasterizer* rasterizer, AggRendererImage* renderer)
{
	if ( (rasterizer)
	  && (renderer)
	  && (renderer->Validate ()) )
	{
		switch (renderer->renderer->active_mask_component)
		{
			case 0:
				if (renderer->use_nn)
				{
					agg::render_scanlines_aa (rasterizer->rasterizer, renderer->renderer->sl_a, renderer->renderer->ren_base, renderer->span_alloc, renderer->span_gen_nn);
				}
				else if (renderer->mode == 1)
				{
					agg::render_scanlines_aa (rasterizer->rasterizer, renderer->renderer->sl_a, renderer->renderer->ren_base, renderer->span_alloc, renderer->span_gen);
				}
				else if (renderer->mode > 1)
				{
					agg::render_scanlines_aa (rasterizer->rasterizer, renderer->renderer->sl_a, renderer->renderer->ren_base, renderer->span_alloc, renderer->span_gen_general);
				}
				else
				{
					agg::render_scanlines_aa (rasterizer->rasterizer, renderer->renderer->sl_a, renderer->renderer->ren_base, renderer->span_alloc, renderer->span_gen_resample);
				}
				break;
			
			case 1:
				if (renderer->use_nn)
				{
					agg::render_scanlines_aa (rasterizer->rasterizer, renderer->renderer->sl_r, renderer->renderer->ren_base, renderer->span_alloc, renderer->span_gen_nn);
				}
				else if (renderer->mode == 1)
				{
					agg::render_scanlines_aa (rasterizer->rasterizer, renderer->renderer->sl_r, renderer->renderer->ren_base, renderer->span_alloc, renderer->span_gen);
				}
				else if (renderer->mode > 1)
				{
					agg::render_scanlines_aa (rasterizer->rasterizer, renderer->renderer->sl_r, renderer->renderer->ren_base, renderer->span_alloc, renderer->span_gen_general);
				}
				else
				{
					agg::render_scanlines_aa (rasterizer->rasterizer, renderer->renderer->sl_r, renderer->renderer->ren_base, renderer->span_alloc, renderer->span_gen_resample);
				}
				break;
			
			case 2:
				if (renderer->use_nn)
				{
					agg::render_scanlines_aa (rasterizer->rasterizer, renderer->renderer->sl_g, renderer->renderer->ren_base, renderer->span_alloc, renderer->span_gen_nn);
				}
				else if (renderer->mode == 1)
				{
					agg::render_scanlines_aa (rasterizer->rasterizer, renderer->renderer->sl_g, renderer->renderer->ren_base, renderer->span_alloc, renderer->span_gen);
				}
				else if (renderer->mode > 1)
				{
					agg::render_scanlines_aa (rasterizer->rasterizer, renderer->renderer->sl_g, renderer->renderer->ren_base, renderer->span_alloc, renderer->span_gen_resample);
				}
				else
				{
					agg::render_scanlines_aa (rasterizer->rasterizer, renderer->renderer->sl_g, renderer->renderer->ren_base, renderer->span_alloc, renderer->span_gen_general);
				}
				break;
			
			case 3:
				if (renderer->use_nn)
				{
					agg::render_scanlines_aa (rasterizer->rasterizer, renderer->renderer->sl_b, renderer->renderer->ren_base, renderer->span_alloc, renderer->span_gen_nn);
				}
				else if (renderer->mode == 1)
				{
					agg::render_scanlines_aa (rasterizer->rasterizer, renderer->renderer->sl_b, renderer->renderer->ren_base, renderer->span_alloc, renderer->span_gen);
				}
				else if (renderer->mode > 1)
				{
					agg::render_scanlines_aa (rasterizer->rasterizer, renderer->renderer->sl_b, renderer->renderer->ren_base, renderer->span_alloc, renderer->span_gen_general);
				}
				else
				{
					agg::render_scanlines_aa (rasterizer->rasterizer, renderer->renderer->sl_b, renderer->renderer->ren_base, renderer->span_alloc, renderer->span_gen_resample);
				}
				break;
			
			default:
				if (renderer->use_nn)
				{
					agg::render_scanlines_aa (rasterizer->rasterizer, renderer->renderer->scanline, renderer->renderer->ren_base, renderer->span_alloc, renderer->span_gen_nn);
				}
				else if (renderer->mode == 1)
				{
					agg::render_scanlines_aa (rasterizer->rasterizer, renderer->renderer->scanline, renderer->renderer->ren_base, renderer->span_alloc, renderer->span_gen);
				}
				else if (renderer->mode > 1)
				{
					agg::render_scanlines_aa (rasterizer->rasterizer, renderer->renderer->scanline, renderer->renderer->ren_base, renderer->span_alloc, renderer->span_gen_general);
				}
				else
				{
					agg::render_scanlines_aa (rasterizer->rasterizer, renderer->renderer->scanline, renderer->renderer->ren_base, renderer->span_alloc, renderer->span_gen_resample);
				}
				break;
			
		}
	}
}

void
AggRasterizerRenderGradient(AggRasterizer* rasterizer, AggRendererGradient* renderer)
{
	if ( (rasterizer)
	  && (renderer)
	  && (renderer->Validate ()) )
	{
		switch (renderer->renderer->active_mask_component)
		{
			case 0:  agg::render_scanlines (rasterizer->rasterizer, renderer->renderer->sl_a, renderer->ren_gradient); break;
			case 1:  agg::render_scanlines (rasterizer->rasterizer, renderer->renderer->sl_r, renderer->ren_gradient); break;
			case 2:  agg::render_scanlines (rasterizer->rasterizer, renderer->renderer->sl_g, renderer->ren_gradient); break;
			case 3:  agg::render_scanlines (rasterizer->rasterizer, renderer->renderer->sl_b, renderer->ren_gradient); break;
			default: agg::render_scanlines (rasterizer->rasterizer, renderer->renderer->scanline, renderer->ren_gradient); break;
		}
	}
}

/*****************************************************************************/
