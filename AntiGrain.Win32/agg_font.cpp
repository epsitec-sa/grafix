#include "interface.h"
#include "structures.h"
#include "agg_font_manager.h"
#include "agg_font_face.h"

#include "wordbreak.h"

#include "agg_bounding_rect.h"
#include "agg_font_path_provider.h"
#include "agg_conv_contour.h"
#include "agg_conv_curve.h"

#include "agg_pixfmt_gray8.h"
#include "agg_renderer_base.h"
#include "agg_renderer_primitives.h"
#include "agg_renderer_scanline.h"
#include "agg_renderer_mclip.h"

extern void Trace (const char* fmt, ...);

using namespace agg;

static agg::font_manager global_font_manager;

#define	EMULATE_CLEARTYPE_INTERPOLATE	0
#define	EMULATE_CLEARTYPE_X3			0

class DebugTraceMessage
{
	const char*			message;
public:
	DebugTraceMessage(const char* text) : message(text)
	{
		Trace("%s - enter", this->message);
	}
	~DebugTraceMessage()
	{
		Trace("%s - exit", this->message);
	}
};

void AggFontInitialise()
{
//	DebugTraceMessage trace ("AggFontInitialise");
	global_font_manager.Initialise ();
}

int AggFontGetFaceCount()
{
//	DebugTraceMessage trace ("AggFontGetFaceCount");
	return global_font_manager.CountFontFaces ();
}

agg::font_face* AggFontGetFaceByRank(int n)
{
//	DebugTraceMessage trace ("AggGetFaceByRank");
	return global_font_manager.RetNthFace (n);
}

agg::font_face* AggFontGetFaceByName(const wchar_t* family, const wchar_t* style, const wchar_t* optical)
{
//	DebugTraceMessage trace ("AggFontGetFaceByName");
	return global_font_manager.FindFontFace (family, style, optical);
}

const wchar_t* AggFontFaceGetName(agg::font_face* face, int id)
{
	if (face)
	{
		switch (id)
		{
			case 1:	return face->RetFamilyName ();
			case 2:	return face->RetStyleName ();
			case 3:	return face->RetStyleNameUserLocale ();
			case 4: return face->RetOpticalName ();
			case 5: return face->RetUniqueName ();
		}
	}
	
	return 0;
}

void* AggFontFaceGetOsHandle(agg::font_face* face)
{
	if (face)
	{
		return face->RetOsHandle ();
	}
	
	return 0;
}

double AggFontFaceGetCaretSlope(agg::font_face* face)
{
	if (face)
	{
		return face->RetCaretSlope ();
	}
	
	return 90;
}

int AggFontFaceGetGlyphIndex(agg::font_face* face, int unicode)
{
	if (face)
	{
		return face->RetGlyphIndex (unicode);
	}
	
	return 0;
}

double AggFontFaceGetGlyphAdvance(agg::font_face* face, int glyph)
{
	if (face)
	{
		return face->RetGlyphAdvance (static_cast<int16u> (glyph));
	}
	
	return 0;
}

double AggFontFaceGetCharAdvance(agg::font_face* face, int unicode)
{
	if (face)
	{
		int16u glyph = face->RetGlyphIndex (unicode);
		return face->RetGlyphAdvance (glyph);
	}
	
	return 0;
}

double AggFontFaceGetTextAdvance(agg::font_face* face, const wchar_t* text, int mode)
{
	if ( (face)
	  && (text) )
	{
		double advance = 0;
		
		while (*text)
		{
			int unicode = *text++;
			advance += face->RetGlyphAdvance (face->RetGlyphIndex (unicode));
		}
		
		return advance;
	}
	
	return 0;
}

void AggFontFaceGetGlyphBounds(agg::font_face* face, int glyph, double& x_min, double& y_min, double& x_max, double& y_max)
{
	if (face)
	{
		face->GetGlyphBounds (static_cast<int16u> (glyph), x_min, y_min, x_max, y_max);
	}
	else
	{
		x_min = 0;	y_min = 0;
		x_max = 0;	y_max = 0;
	}
}

void AggFontFaceGetCharBounds(agg::font_face* face, int unicode, double& x_min, double& y_min, double& x_max, double& y_max)
{
	if (face)
	{
		int16u glyph = face->RetGlyphIndex (unicode);
		face->GetGlyphBounds (glyph, x_min, y_min, x_max, y_max);
	}
	else
	{
		x_min = 0;	y_min = 0;
		x_max = 0;	y_max = 0;
	}
}

void AggFontFaceGetTextBounds(agg::font_face* face, const wchar_t* text, int mode, double& x_min, double& y_min, double& x_max, double& y_max)
{
	if ( (face)
	  && (text) )
	{
		x_min = 1000;	y_min = 1000;
		x_max = 0;		y_max = 0;
		
		double x = 0;
		double y = 0;
		
		while (*text)
		{
			int  unicode = *text++;
			int16u glyph = face->RetGlyphIndex (unicode);
			
			double x_min_loc, y_min_loc, x_max_loc, y_max_loc;
			
			face->GetGlyphBounds (glyph, x_min_loc, y_min_loc, x_max_loc, y_max_loc);
			
			x_min_loc += x;
			x_max_loc += x;
			y_min_loc += y;
			y_max_loc += y;
			
			if (x_min_loc < x_min) x_min = x_min_loc;
			if (x_max_loc > x_max) x_max = x_max_loc;
			if (y_min_loc < y_min) y_min = y_min_loc;
			if (y_max_loc > y_max) y_max = y_max_loc;
			
			x += face->RetGlyphAdvance (glyph);
		}
	}
	else
	{
		x_min = 0;	y_min = 0;
		x_max = 0;	y_max = 0;
	}
}



double AggFontFaceGetMetrics(agg::font_face* face, int id)
{
	double ascender    = 0;
	double descender   = 0;
	double line_height = 0;
	
	if ( (face)
	  && (face->GetVerticalMetrics (ascender, descender, line_height)) )
	{
		switch (id)
		{
			case 1: return ascender;
			case 2: return descender;
			case 3: return line_height;
		}
	}
	
	return 0;
}

int AggFontFaceGetTextCharEndXArray(agg::font_face* face, const wchar_t* text, int mode, double* x_array)
{
	if ( (face)
	  && (text)
	  && (x_array) )
	{
		double x = 0;
		int n = 0;
		
		while (*text)
		{
			int    unicode = *text++;
			int16u glyph   = face->RetGlyphIndex (unicode);
			
			x += face->RetGlyphAdvance (glyph);
			x_array[n++] = x;
		}
		
		return n;
	}
	
	return 0;
}


static char ReduceToASCIIAndConvertToUpper (int utf)
{
	if ( (utf >= 'A')
	  && (utf <= 'Z') )
	{
		return static_cast<char> (utf);
	}
	
	if ( (utf >= 'a')
	  && (utf <= 'z') )
	{
		return static_cast<char> (utf+'A'-'a');
	}
	
	if (utf < 256)
	{
		switch (static_cast<char> (utf))
		{
			case 'á': case 'à': case 'â': case 'ä': case 'ã':	return 'A';
			case 'Á': case 'À': case 'Â': case 'Ä': case 'Ã':	return 'A';
			
			case 'ç':											return 'C';
			case 'Ç':											return 'C';
			
			case 'é': case 'è': case 'ê': case 'ë':				return 'E';
			case 'É': case 'È': case 'Ê': case 'Ë':				return 'E';
			case 'í': case 'ì': case 'î': case 'ï':				return 'I';
			case 'Í': case 'Ì': case 'Î': case 'Ï':				return 'I';
			case 'ó': case 'ò': case 'ô': case 'ö': case 'õ':	return 'O';
			case 'Ó': case 'Ò': case 'Ô': case 'Ö': case 'Õ':	return 'O';
			case 'ú': case 'ù': case 'û': case 'ü':				return 'U';
			case 'Ú': case 'Ù': case 'Û': case 'Ü':				return 'U';
			case 'ñ':											return 'N';
			case 'Ñ':											return 'N';
			case 'ÿ': case 'ý':									return 'Y';
			case 'Ÿ': case 'Ý':									return 'Y';
			
			case 'Å': case 'Æ': case 'å': case 'æ':				return 'A';
		}
	}
	
	return '#';
}


enum BreakClass
{
	BREAK_NO			= 0,
	BREAK_NATURAL		= 1,
	BREAK_HYPHENATE		= 2,
};


static void BreakText(const wchar_t* text, size_t text_length, TextBreakMode mode, int8u* breaks)
{
	int len   = static_cast<int> (text_length);
	int start = 0;
	
	for (int i = 0; i < len; i++)
	{
		int unicode = text[i];
		
		if (unicode == ' ')
		{
			breaks[i] = BREAK_NATURAL;
			
			if (mode & TEXT_BREAK_HYPHENATE)
			{
				int n = i - start;
				
				if ((n > 3) &&
					(n < 100))
				{
					char word[100];
					int  list[100];
					
					for (int j = 0; j < n; j++)
					{
						word[j] = ReduceToASCIIAndConvertToUpper (text[start+j]);
					}
					
					Break (word, n, list);
					
					int* pos = list;
					
					while (*pos)
					{
						int p = *pos++;
						breaks[start + p] = BREAK_HYPHENATE;
					}
				}
				
				start = i+1;
			}
		}
		else
		{
			breaks[i] = BREAK_NO;
		}
	}
}


BreakContext* AggFontFaceBreakNew(agg::font_face* face, const wchar_t* text, TextBreakMode mode)
{
	size_t text_length = text ? wcslen (text) : 0;
	
	if ( (text_length < 100000)
	  && (text_length > 0)
	  && (face) )
	{
		BreakContext* context = new BreakContext (face);
		
		context->text = new wchar_t[text_length+1];
		context->mode = mode;
		
		context->ellipsis_glyph = face->RetGlyphIndex (0x2026);
		context->dash_length = face->RetGlyphAdvance (face->RetGlyphIndex ('-'));
		
		context->breaks = new int8u[text_length];
		BreakText (text, text_length, mode, context->breaks);
		
		wcscpy (context->text, text);
		return context;
	}
	
	return 0;
}

const wchar_t* AggFontFaceBreakIter(BreakContext* context, double& width, int& n_char)
{
	n_char = 0;
	
	if ( (context)
	  && (context->Check ()) )
	{
		double advance = 0;
		int    offset  = 0;
		
		const wchar_t* text = context->text + context->pos;
		const int8u* breaks = context->breaks + context->pos;
		
		int    space_offset   = 0;
		double space_advance  = 0;
		double space_width    = 0;
		bool   space_match    = false;
		bool   add_ellipsis   = false;
		bool   is_single_line = (context->mode & TEXT_BREAK_SINGLE_LINE) ? true : false;
		double ellipsis_width = 0;
		
		if (text[offset] == 0)
		{
			width = 0.0;
			return 0;
		}
		
		
		//-----------------------------------------------------------------------------------
		//
		//	TODO: faire la césure si besoin, l'ellipse, tronquer ou laisser déborder...
		//
		//-----------------------------------------------------------------------------------
		
		while (text[offset])
		{
			int    unicode    = text[offset];
			double char_width = context->face->RetGlyphAdvance (context->face->RetGlyphIndex (unicode));
			
			if ((breaks[offset] != BREAK_NO) && (!is_single_line))
			{
				if (breaks[offset] == BREAK_HYPHENATE)
				{
					space_width = context->dash_length;
					
					if (advance+space_width > width)
					{
						goto try_fit;
					}
				}
				else
				{
					space_width = 0;
				}
				
//				if (space_match == false)
				{
					space_offset  = offset;
					space_advance = advance;
					space_match   = true;
				}
			}
			else
			{
				space_match = false;
			}
			
try_fit:
			if ( (space_offset == 0)
			  && (offset > 0) )
			{
				if ((advance + char_width) > width)
				{
					//	Oups... Le mot est trop long pour tenir dans l'espace alloué, mais on ne peut
					//	pas le couper avant. Que faire ?
					
					if ( (context->mode & TEXT_BREAK_ELLIPSIS)
					  && (context->ellipsis_glyph > 0)
					  && (add_ellipsis == false) )
					{
						double x = 0, y = 0;
						context->face->GetGlyphAdvance (context->ellipsis_glyph, x, y);
						ellipsis_width = x;
						
						if (width > ellipsis_width)
						{
							//	On va placer une ellipse (...) en fin de texte. On réduit d'autant la
							//	largeur disponible, et on recommence au début !
							
							width -= ellipsis_width;
							
							space_offset   = 0;
							space_advance  = 0;
							space_match    = false;
							add_ellipsis   = true;
							
							advance = 0;
							offset  = 0;
							
							continue;
						}
					}
					
					if ( (context->mode & TEXT_BREAK_SPLIT)
					  || (add_ellipsis) )
					{
						//	On s'arrête ici.
						
						space_offset  = offset;
						space_advance = advance;
						
						goto break_text;
					}
				}
			}
			
			advance += char_width;
			offset  += 1;
			
			if (advance > width)
			{
				break;
			}
		}
		
		if (advance <= width)
		{
			//	Tout le texte tient dans l'espace alloué... Simple et efficace !
			
			width = advance;
			context->pos += offset;
			n_char = offset;
			return text;
		}
		
		if (space_offset == 0)
		{
			//	Ne tient pas dans l'espace alloué, et ne contient aucun caractère
			//	où l'on peut couper.
			
			width = 0.0;
			return L"";
		}
		
		//	Copie le texte dans le buffer temporaire.
		
break_text:
		if (space_offset+1 >= context->max_chunk_len)
		{
			delete[] context->chunk;
			context->chunk = new wchar_t[space_offset+2];
			context->max_chunk_len = space_offset+2;
		}
		
		wcsncpy (context->chunk, text, space_offset);
		
		if (breaks[space_offset] == BREAK_HYPHENATE)
		{
			context->chunk[space_offset+0] = '-';
			context->chunk[space_offset+1] = 0;
		}
		else
		{
			context->chunk[space_offset] = 0;
		}
		
		width = space_advance + space_width;
		
		if (add_ellipsis)
		{
			//	On s'est interrompu en ajoutant une ellipse. N'oublions pas de mettre
			//	celle-ci dans le buffer en sortie, et de compter sa longueur.
			
			context->chunk[space_offset+0] = 0x2026;
			context->chunk[space_offset+1] = 0;
			
			width += ellipsis_width;
			
			while (text[space_offset])
			{
				if (text[space_offset] == ' ') {
					break;
				}
				
				space_offset++;
			}
		}
		
		if (text[space_offset] == ' ')
		{
			space_offset++;
		}
		
		context->pos += space_offset;
		n_char = space_offset;
		return context->chunk;
	}
	
	width = 0.0;
	return 0;
}

bool AggFontFaceBreakHasMore(BreakContext* context)
{
	if ( (context)
	  && (context->Check ()) )
	{
		return context->text[context->pos] ? true : false;
	}
	
	return false;
}

void AggFontFaceBreakDelete(BreakContext* context)
{
	if ( (context)
	  && (context->Check ()) )
	{
		delete context;
	}
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

double
AggFontPixelCacheFill(AggBuffer* buffer, agg::font_face* face, const wchar_t* text, double scale,
					  double ox, double oy,
					  double r, double g, double b, double a)
{
	if ( (face == 0)
	  || (text == 0)
	  || (text == L"") )
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
	
	int32u i_size = static_cast<int32u> (scale * 256);
	
	while (*text)
	{
		int32u unicode = *text++;
		int16u glyph   = face->RetGlyphIndex (unicode);
		int8u  i_xs    = static_cast<int8u> ((ox - (int)(ox)) * 256);
		int8u  i_ys    = static_cast<int8u> ((oy - (int)(oy)) * 256);
		
		agg::font_face::cache_record::size_info_record* info = face->FindSizeInfo (glyph);
		agg::font_face::cache_record::pix_data_record*  data = face->FindPixData (info, i_size, i_xs, i_ys);
		
		double advance = face->RetGlyphAdvance (glyph, info) * scale;
		total_advance += advance;
		
		if (data->pixels == 0)
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
				
				data->ox = static_cast<int16> ((ox - i_x1) * 256);
				data->oy = static_cast<int16> ((oy - i_y1) * 256);
			}
			
			int32u pixel_size = data->dx * data->dy;
			
#if EMULATE_CLEARTYPE_X3
			data->pixels = face->TurboAlloc (pixel_size*3);
#elsif EMULATE_CLEARTYPE_INTERPOLATE
			data->pixels = face->TurboAlloc (pixel_size+1);
			data->pixels[pixel_size] = 0;
#else
			data->pixels = face->TurboAlloc (pixel_size);
#endif
			
			if (data->dx)
			{
				//	Render the glyph into the pixel coverage buffer...
				
#if EMULATE_CLEARTYPE_X3
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
#if EMULATE_CLEARTYPE_X3
				buffer->renderer->ren_base.blend_solid_hspan_cleartype (dst_x, y, data->dx, fill_color, covers);
				covers += data->dx*3;
#elsif EMULATE_CLEARTYPE_INTERPOLATE
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

#if 0
static int exception_filter(EXCEPTION_POINTERS * pex)
{
	char text[10000];
	sprintf (text, "AggFontPixelCacheFill: Ex.code = %08x at %08p - start at %08p\n"
		/**/	   "EAX=%08X EBX=%08X ECX=%08X EDX=%08X\n"
		/**/	   "EIP=%08X EBP=%08X ESP=%08X\n",
		/**/	   pex->ExceptionRecord->ExceptionCode,
		/**/	   pex->ExceptionRecord->ExceptionAddress,
		/**/       & AggFontPixelCacheFill,
		/**/	   pex->ContextRecord->Eax,
		/**/	   pex->ContextRecord->Ebx,
		/**/	   pex->ContextRecord->Ecx,
		/**/	   pex->ContextRecord->Edx,
		/**/	   pex->ContextRecord->Eip,
		/**/	   pex->ContextRecord->Ebp,
		/**/	   pex->ContextRecord->Esp);
	OutputDebugString (text);
	
	return EXCEPTION_CONTINUE_SEARCH;
}

double
_AggFontPixelCacheFill(AggBuffer* buffer,
					  agg::font_face* face, const wchar_t* text, double scale,
					  double ox, double oy,
					  double r, double g, double b, double a)
{
	double w = 0.0;
	__try
	{
		w = AggFontPixelCacheFill (buffer, face, text, scale, ox, oy, r, g, b, a);
	}
	__except(exception_filter(GetExceptionInformation()))
	{
	}
	return w;
}
#endif

/*****************************************************************************/
