/*
 *	agg_font_path_provider.h
 *
 *	Font Path Provider definition. The font_path_provider class generates a path
 *	from a glyph description stored in an Open Type font face.
 *
 *	(C) Copyright 2002-2004, Pierre ARNAUD, OPaC bright ideas, Ch. du Fontenay 6,
 *		CH-1400 YVERDON, Switzerland. All rights reserved. 
 *		Contact: pierre.arnaud@opac.ch, http://www.opac.ch
 *
 *	This file may be distributed and used under the same terms and conditions as
 *	the Anti-Grain Geometry software (http://www.antigrain.com).
 *
 *	Permission to copy, use, modify, sell and distribute this software 
 *	is granted provided this copyright notice appears in all copies. 
 *	This software is provided "as is" without express or implied
 *	warranty, and with no claim as to its suitability for any purpose.
 */

#ifndef AGG_FONT_PATH_PROVIDER_INCLUDED
#define AGG_FONT_PATH_PROVIDER_INCLUDED

#include "agg_basics.h"
#include "agg_font_face.h"

/*****************************************************************************/

namespace agg
{
	class font_face;
	
	class font_path_provider
	{
		enum State
		{
			STATE_BEGIN,
			STATE_ON_CURVE,
			STATE_OFF_CURVE,
			STATE_INTERPOLATED,
			STATE_END_CURVE,
			STATE_CLOSE_CURVE
		};
		
		unsigned int					index;					
		unsigned int					num_coord;
		int8u*							glyph_flags;
		int16*							glyph_x;
		int16*							glyph_y;
		State							state;
		bool							generate_close;
		double							ox, oy;
		double							contour_ox, contour_oy;
		double							matrix_xx;
		double							matrix_xy;
		double							matrix_yx;
		double							matrix_yy;
		
		font_path_provider*				composite_next;

	protected:
		void Setup (font_face* face,
					int16u glyph,
					font_face::cache_record::size_info_record*& info,
					double x, double y,
					double matrix_xx, double matrix_yy, double matrix_xy, double matrix_yx)
		{
			double scale = face->RetScaleToEM ();
			
			double xx = matrix_xx * scale;
			double xy = matrix_xy * scale;
			double yx = matrix_yx * scale;
			double yy = matrix_yy * scale;
			
			this->matrix_xx = xx * info->mxx + xy * info->myx;
			this->matrix_xy = xx * info->mxy + xy * info->myy;
			this->matrix_yx = yx * info->mxx + yy * info->myx;
			this->matrix_yy = yx * info->mxy + yy * info->myy;
			
			this->index       = 0;
			this->num_coord   = info->num_coord;
			this->glyph_flags = info->glyph_flags;
			this->glyph_x     = info->glyph_x;
			this->glyph_y     = info->glyph_y;
			this->state       = STATE_BEGIN;
			
			this->generate_close = false;
			this->composite_next = 0;
			
			double tx = xx * info->mtx + yx * info->mty;
			double ty = xy * info->mtx + yy * info->mty;
			
			this->ox = x + tx;
			this->oy = y + ty;
			
			if (info->composites)
			{
				font_path_provider** next_ptr = & this->composite_next;
				int n = info->composite_count;
				
				for (int i = 0; i < n; i++)
				{
					double xx = info->composites[i].xx * this->matrix_xx + info->composites[i].xy * this->matrix_yx;
					double xy = info->composites[i].xx * this->matrix_xy + info->composites[i].xy * this->matrix_yy;
					double yx = info->composites[i].yx * this->matrix_xx + info->composites[i].yy * this->matrix_yx;
					double yy = info->composites[i].yx * this->matrix_xy + info->composites[i].yy * this->matrix_yy;
					
					int16u                                     other_glyph = info->composites[i].glyph;
					font_face::cache_record::size_info_record* other_info  = face->FindSizeInfo (other_glyph);
					
					//	We must make sure that 'info' still points at a valid record, since FindSizeInfo
					//	could move the records from under our feet :
					
					info = face->FindSizeInfo (glyph);
					
					next_ptr[0] = new font_path_provider (face, other_glyph, other_info,
												x + info->composites[i].ox * this->matrix_xx + info->composites[i].oy * this->matrix_xy,
												y + info->composites[i].oy * this->matrix_yy + info->composites[i].ox * this->matrix_yx,
												matrix_xx, matrix_yy, matrix_xy, matrix_yx);
					
					next_ptr[0]->matrix_xx = xx;
					next_ptr[0]->matrix_xy = xy;
					next_ptr[0]->matrix_yx = yx;
					next_ptr[0]->matrix_yy = yy;
					
					next_ptr = & next_ptr[0]->composite_next;
				}
			}
		}
		
	public:
		/*
		 *	Arguments:
		 *
		 *	- font_face, font to be used.
		 *	- glyph, index of the glyph in the font; (use font_face::RetGlyphIndex or
		 *	  font_face::MapToGlyphs to find the glyph index based on the Unicode
		 *	  character code).
		 *	- x & y, position of the glyph (base-line relative).
		 *	- scale, font size.
		 */
		
		font_path_provider (font_face* face, int16u glyph, double x, double y, double matrix_xx, double matrix_yy)
		{
			font_face::cache_record::size_info_record* info = face->FindSizeInfo (glyph);
			
			this->Setup (face, glyph, info, x, y, matrix_xx, matrix_yy, 0, 0);
		}
		
		font_path_provider (font_face* face, int16u glyph, font_face::cache_record::size_info_record*& info, double x, double y, double matrix_xx, double matrix_yy)
		{
			this->Setup (face, glyph, info, x, y, matrix_xx, matrix_yy, 0, 0);
		}
		
		font_path_provider (font_face* face, int16u glyph, font_face::cache_record::size_info_record*& info, double x, double y, double matrix_xx, double matrix_yy, double matrix_xy, double matrix_yx)
		{
			this->Setup (face, glyph, info, x, y, matrix_xx, matrix_yy, matrix_xy, matrix_yx);
		}
		
		~font_path_provider ()
		{
			if (this->composite_next)
			{
				delete this->composite_next;
			}
		}
		
		void rewind (unsigned)
		{
			this->index = 0;
			this->state = STATE_BEGIN;
			this->generate_close = false;
			
			if (this->composite_next != 0)
			{
				this->composite_next->rewind (0);
			}
		}
		
		unsigned vertex (double* x, double* y)
		{
			for (;;)
			{
				int8u flag;
				int32 x16;
				int32 y16;
				
				if (this->generate_close)
				{
					this->generate_close = false;
					return agg::path_flags_close;
				}
				
				if (this->index >= this->num_coord)
				{
					if (this->state == STATE_END_CURVE)
					{
						flag = 0;
						x16  = 0;
						y16  = 0;
					}
					else
					{
						if (this->composite_next != 0)
						{
							return this->composite_next->vertex (x, y);
						}
						
						return agg::path_cmd_stop;
					}
				}
				else
				{
					flag = this->glyph_flags[this->index];
					x16  = this->glyph_x[this->index];
					y16  = this->glyph_y[this->index];
				}
				
				this->index++;
				
				switch (this->state)
				{
					case STATE_BEGIN:
						if (flag & font_face::cache_record::FLAG_CONTOUR_END)
						{
							//	Special case : there is only one point in this contour -- this happens, but
							//	is really useless, so simply discard it !
							
							continue;
						}
						
						*x = this->contour_ox = this->matrix_xx * x16 + this->matrix_yx * y16 + this->ox;
						*y = this->contour_oy = this->matrix_xy * x16 + this->matrix_yy * y16 + this->oy;
						
						this->state = STATE_ON_CURVE;
						return agg::path_cmd_move_to;
					
					
					
					case STATE_ON_CURVE:
						*x = this->matrix_xx * x16 + this->matrix_yx * y16 + this->ox;
						*y = this->matrix_xy * x16 + this->matrix_yy * y16 + this->oy;
						
						if (flag & font_face::cache_record::FLAG_ON_CURVE)
						{
							//	The last point was on the curve, and this point is on the curve too. This
							//	means that we can output a segment.
							
							if (flag & font_face::cache_record::FLAG_CONTOUR_END)
							{
								this->state = STATE_BEGIN;
								this->generate_close = true;
								return agg::path_cmd_line_to;
							}
							
							this->state = STATE_ON_CURVE;
							return agg::path_cmd_line_to;
						}
						
						//	The last point was on the curve, and this point is off the curve. This means
						//	that we are starting a curve here.
						
						if (flag & font_face::cache_record::FLAG_CONTOUR_END)
						{
							this->state = STATE_CLOSE_CURVE;
							this->index--;
							return agg::path_cmd_curve3;
						}
						
						this->state = STATE_OFF_CURVE;
						return agg::path_cmd_curve3;
					
					
					
					case STATE_OFF_CURVE:
						if (flag & font_face::cache_record::FLAG_ON_CURVE)
						{
							*x = this->matrix_xx * x16 + this->matrix_yx * y16 + this->ox;
							*y = this->matrix_xy * x16 + this->matrix_yy * y16 + this->oy;
							
							//	The last point was off the curve, and this point is on the curve again. This
							//	means that we are finishing a curve here.
							
							if (flag & font_face::cache_record::FLAG_CONTOUR_END)
							{
								this->state = STATE_BEGIN;
								this->generate_close = true;
								return agg::path_cmd_curve3;
							}
							
							this->state = STATE_ON_CURVE;
							return agg::path_cmd_curve3;
						}
						
						//	The last point was off the curve, and this point is off the curve too. This means
						//	that we must interpolate the medium point, rewind the iteration index and return
						//	the virtual medium point as 'on the curve'.
						
						this->index--;
						
						{
							double temp_x = (this->glyph_x[this->index - 1] + this->glyph_x[this->index]) / 2.0;
							double temp_y = (this->glyph_y[this->index - 1] + this->glyph_y[this->index]) / 2.0;
							
							*x = this->matrix_xx * temp_x + this->matrix_yx * temp_y + this->ox;
							*y = this->matrix_xy * temp_x + this->matrix_yy * temp_y + this->oy;
						}
						
						this->state = STATE_INTERPOLATED;
						return agg::path_cmd_curve3;
						
					case STATE_INTERPOLATED:
						*x = this->matrix_xx * x16 + this->matrix_yx * y16 + this->ox;
						*y = this->matrix_xy * x16 + this->matrix_yy * y16 + this->oy;
						
						if (flag & font_face::cache_record::FLAG_CONTOUR_END)
						{
							this->state = STATE_END_CURVE;
						}
						else
						{
							this->state = STATE_OFF_CURVE;
						}
						
						return agg::path_cmd_curve3;
					
					case STATE_END_CURVE:
						*x = this->contour_ox;
						*y = this->contour_oy;
						
						this->index--;
						this->state = STATE_BEGIN;
						this->generate_close = true;
						
						return agg::path_cmd_curve3;
					
					case STATE_CLOSE_CURVE:
						*x = this->contour_ox;
						*y = this->contour_oy;
						
						this->state = STATE_BEGIN;
						this->generate_close = true;
						
						return agg::path_cmd_curve3;
				}
			}
		}
	};
}

#endif /* AGG_FONT_PATH_PROVIDER_INCLUDED */
