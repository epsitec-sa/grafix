//	AntiGrain.Win32/agg_font.cpp
//
//	Copyright © 2003-2006, Pierre ARNAUD, OPaC bright ideas, Ch. du Fontenay 6,
//	                       CH-1400 YVERDON, Switzerland. All rights reserved. 
//
//	Contact: pierre.arnaud@opac.ch, http://www.opac.ch
//	License: see license.txt

#include "interface.h"
#include "structures.h"

#include "agg_font_face.h"

#include "agg_bounding_rect.h"
#include "agg_font_path_provider.h"
#include "agg_conv_contour.h"
#include "agg_conv_curve.h"

#include "agg_pixfmt_gray.h"
#include "agg_renderer_base.h"
#include "agg_renderer_primitives.h"
#include "agg_renderer_scanline.h"
#include "agg_renderer_mclip.h"

/*****************************************************************************/

void*
AggFontCreateFaceFromFontData(const void* data, size_t size, size_t offset, void* os_handle)
{
	return agg::font_face::CreateFontFaceFromData (data, size, offset, os_handle);
}

void
AggFontDisposeFace(agg::font_face* face)
{
	agg::font_face::DisposeFontFace (face);
}

/*****************************************************************************/

static inline int round_up(double x)
{
	return static_cast<int> (x + 0.999999);
}

static inline int round_down(double x)
{
	if (x < 0)
	{
		return static_cast<int> (x - 0.999999);
	}
	else
	{
		return static_cast<int> (x);
	}
}

/*****************************************************************************/

double
AggFontPixelCacheFill(AggBuffer* buffer, agg::font_face* face,
					  const unsigned short* glyphs, int length,
					  double scale,
					  double ox, double oy,
					  double r, double g, double b, double a)
{
	if ( (face == 0)
	  || (glyphs == 0)
	  || (length == 0) )
	{
		return 0.0;
	}
	
	if (face->UpdateCache () == false)
	{
		return 0.0;
	}
	
	ox = static_cast<int> (ox * 4) / 4.0;
	oy = static_cast<int> (oy * 4) / 4.0;
	
	agg::rgba fill_color = agg::rgba (r, g, b, a);
	double total_advance = 0;
	
	agg::int32u i_size = static_cast<agg::int32u> (scale * 256);
	
	while (length-- > 0)
	{
		agg::int16u glyph = *glyphs++;

		if (glyph >= 0xff00)
		{
			continue;
		}
		
		agg::int8u  i_xs = static_cast<agg::int8u> ((ox - (int)(ox)) * 256);
		agg::int8u  i_ys = static_cast<agg::int8u> ((oy - (int)(oy)) * 256);
		
		agg::font_face::cache_record::size_info_record* info = face->FindSizeInfo (glyph);
		agg::font_face::cache_record::pix_data_record*  data = info ? face->FindPixData (info, i_size, i_xs, i_ys) : 0;
		
		double advance = info ? face->RetGlyphAdvance (glyph, info) * scale : 0;
		total_advance += advance;
		
		if ( (glyph < 0xff00)
		  && (info) && (data)
		  && (data->pixels == 0) )
		{
			//	The glyph is not yet known, so we will have to fill the cache with its
			//	image. Instanciate a rasterizer and do everything in here. This is not
			//	optimal yet.
			
			double x1 = 0, y1 = 0, x2 = 0, y2 = 0;
			unsigned path_i [1] = { 0 };
			
			agg::font_path_provider font_path = agg::font_path_provider (face, glyph, info, ox, oy, scale, scale);
			agg::conv_curve<agg::font_path_provider> curve (font_path);
			agg::bounding_rect (curve, path_i, 0, 1, &x1, &y1, &x2, &y2);
			
			//	Round bounding box to nearest pixel size, shrinking the left border
			//	and growing the right border...
			
			int i_x1 = round_down (x1);
			int i_x2 = round_up (x2);
			int i_y1 = round_down (y1);
			int i_y2 = round_up (y2);
			
			if (((i_x1 - i_x2) == 1) ||
				((i_y1 - i_y2) == 1))
			{
				data->dx = 0;
				data->dy = 0;
			}
			else
			{
				data->dx = i_x2 - i_x1;
				data->dy = i_y2 - i_y1;
			}
			
			if (data->dx)
			{
				//	[data->ox] is the offset from the left of the bitmap to the glyph's origin
				//	[data->oy] is the offset from the bottom of the bitmap to the glyph's origin
				
				data->ox = static_cast<agg::int16> ((ox - i_x1) * 256);
				data->oy = static_cast<agg::int16> ((oy - i_y1) * 256);
			}
			
			agg::int32u pixel_size = data->dx * data->dy;
			
#if defined(EMULATE_CLEARTYPE_X3)
			data->pixels = face->TurboAlloc (pixel_size*3);
#elsif defined(EMULATE_CLEARTYPE_INTERPOLATE)
			data->pixels = face->TurboAlloc (pixel_size+1);
			data->pixels[pixel_size] = 0;
#else
			data->pixels = face->TurboAlloc (pixel_size);
#endif
			
			if (data->dx)
			{
				//	Render the glyph into the pixel coverage buffer...
				
#if defined(EMULATE_CLEARTYPE_X3)
				agg::font_path_provider font_path = agg::font_path_provider (face, glyph, info, data->ox / 256.0, data->oy / 256.0, i_size * 3 / 256.0, i_size / 256.0);
				agg::conv_curve<agg::font_path_provider> curve (font_path);
				agg::rasterizer_scanline_aa<> rasterizer;
				agg::rendering_buffer buffer;
				buffer.attach (data->pixels, data->dx*3, data->dy, data->dx*3);
				agg::pixfmt_gray8 pixf (buffer);
				agg::renderer_base<agg::pixfmt_gray8> ren_base(pixf);
				agg::renderer_scanline_aa_solid<agg::renderer_base<agg::pixfmt_gray8> > renderer(ren_base);
				agg::scanline_p8 scanline;
				ren_base.clear (agg::gray8 (0x00));
				renderer.color (agg::gray8 (0xff));
				rasterizer.add_path (curve);
				agg::render_scanlines (rasterizer, scanline, renderer);
#else
				agg::font_path_provider font_path = agg::font_path_provider (face, glyph, info, data->ox / 256.0, data->oy / 256.0, i_size / 256.0, i_size / 256.0);
				agg::conv_curve<agg::font_path_provider> curve (font_path);
				agg::rasterizer_scanline_aa<> rasterizer;
				agg::rendering_buffer buffer;
				buffer.attach (data->pixels, data->dx, data->dy, data->dx);
				agg::pixfmt_gray8 pixf (buffer);
				agg::renderer_base<agg::pixfmt_gray8> ren_base(pixf);
				agg::renderer_scanline_aa_solid<agg::renderer_base<agg::pixfmt_gray8> > renderer(ren_base);
				agg::scanline_p8 scanline;
				ren_base.clear (agg::gray8 (0x00));
				renderer.color (agg::gray8 (0xff));
				rasterizer.add_path (curve);
				agg::render_scanlines (rasterizer, scanline, renderer);
#endif
			}
		}
		
		if (data && buffer && data->dx && data->pixels)
		{
			//	The glyph data exists in the cache and the caller specified a destination buffer, so
			//	paint whatever is in the cache.
			
			double x_offset = ox - data->ox / 256.0;
			double y_offset = oy - data->oy / 256.0;
			
			int dst_x = static_cast<int> ((x_offset > 0) ? x_offset + 0.5 : x_offset - 0.5);
			int dst_y = static_cast<int> ((y_offset > 0) ? y_offset + 0.5 : y_offset - 0.5);
			
			agg::int8u* covers = data->pixels;
			
			for (int y = dst_y, dy = 0; dy < data->dy; y++, dy++)
			{
#if defined(EMULATE_CLEARTYPE_X3)
				buffer->renderer->ren_base.blend_solid_hspan_cleartype (dst_x, y, data->dx, fill_color, covers);
				covers += data->dx*3;
#elsif defined(EMULATE_CLEARTYPE_INTERPOLATE)
				buffer->renderer->ren_base.blend_solid_hspan_cleartype (dst_x, y, data->dx, fill_color, covers);
				covers += data->dx;
#else
				buffer->renderer->ren_base.blend_solid_hspan (dst_x, y, data->dx, fill_color, covers);
				covers += data->dx;
#endif
			}
		}
		
		ox += advance;
	}
	
	return total_advance;
}

/*****************************************************************************/

typedef __declspec(dllimport) int (FAR WINAPI *GETUNAME_FUNC)(DWORD,LPVOID); 

static HMODULE			hUNameDll;
static GETUNAME_FUNC	pGetUNameFunc;

/*
 *	Find the name of the specified character code. This uses the getuname.dll
 *	from Windows to retrieve the Unicode database information.
 *
 *	See http://blogs.gotdotnet.com/michkap/archive/2006/01/12/511920.aspx
 */

bool
AggFontGetUnicodeName(int code, wchar_t* max_path_buffer)
{
	if (hUNameDll == 0)
	{
		hUNameDll = ::LoadLibrary ("GETUNAME.DLL");
	}
	if (hUNameDll == 0)
	{
		return false;
	}
    
	if (pGetUNameFunc == 0)
	{
		pGetUNameFunc = (GETUNAME_FUNC)GetProcAddress(hUNameDll, "GetUName"); 
	}
	if (pGetUNameFunc == 0)
	{
		return false;
	}
    
	pGetUNameFunc (code, max_path_buffer);
	
	return true;
}

/*****************************************************************************/
