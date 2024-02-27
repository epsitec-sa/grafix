/*
 *	agg_font_face.cpp
 *
 *	The font_face class represents a font face, that is all data related to a
 *	"physical" font (glyphs, geometry, etc.)
 *
 *	Note: part of the code in this file is no longer needed, as we rely on
 *	a C# implementation for most OpenType table parsing.
 *
 *	(C) Copyright 2003-2007, Pierre ARNAUD, OPaC bright ideas, Ch. du Fontenay 6,
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

#if defined(WIN32)
#include "win32tempdc.h"
#endif

#include "agg_font_face.h"
#include "agg_font_opentype.h"
#include "agg_strsafe.h"

#include <stdio.h>

#undef	ACTIVE_DEBUG_TRACE

#if defined(ACTIVE_DEBUG_TRACE)
extern void Trace (const char* fmt, ...);
#endif

/*****************************************************************************/

#if defined(_MSC_VER)
#include <malloc.h>
#else
#include <alloca.h>
#endif

#include <assert.h>
#include <math.h>

#if !defined(M_1_PI)
#define	M_1_PI     0.318309886183790671538		//	1/pi
#endif

/*****************************************************************************/

using namespace agg;

font_face::font_face ()
	:
	face_data (0),
	face_data_size (0),
	face_data_offset (0),
	os_handle (0),
	face_cache (0),
	lock_count (0)
{
}

font_face::~font_face ()
{
	if (this->face_data != 0)
	{
		delete this->face_data;
		
		this->face_data = 0;
	}
	
	assert (this->lock_count == 0);
}

/*****************************************************************************/

font_face*
font_face::CreateFontFaceFromData (const void* face_data, size_t face_data_size, size_t face_data_offset, void* os_handle)
{
	font_face* face = new font_face ();
	
	face->face_data        = new char[face_data_size];
	face->face_data_size   = face_data_size;
	face->face_data_offset = face_data_offset;
	
	face->os_handle = os_handle;
	
	memcpy (face->face_data, face_data, face_data_size);
	
	return face;
}

void
font_face::DisposeFontFace(font_face* face)
{
	if (face != 0)
	{
		delete face;
	}
}

/*****************************************************************************/

void
font_face::DisposeData ()
{
	if (this->face_data)
	{
		delete this->face_data;
		this->face_data = 0;
		this->face_data_size = 0;
	}
	
	this->ClearCache ();
}

void
font_face::ClearCache ()
{
	if (this->face_cache)
	{
		delete this->face_cache;
		this->face_cache = 0;
	}
}

bool
font_face::UpdateCache ()
{
	if (this->face_cache == 0)
	{
		this->face_cache = new font_face::cache_record (this);
	}
	
	return this->face_cache ? true : false;
}

const open_type::ligature_subst**
font_face::NewOpenTypeLigatureSubstArray (const open_type::feature_table* features)
{
	const open_type::ligature_subst** subst_array = 0;
	int num_subst = this->FillOpenTypeLigatureSubstArray (features, subst_array);
	
	if (num_subst)
	{
		subst_array = new const open_type::ligature_subst*[num_subst+1];
		this->FillOpenTypeLigatureSubstArray (features, subst_array);
		subst_array[num_subst] = 0;
	}
	
	return subst_array;
}

int
font_face::FillOpenTypeLigatureSubstArray (const open_type::feature_table* features,
										  const open_type::ligature_subst** array)
{
	if (features == 0)
	{
		return 0;
	}
	
	int total_subst = 0;
	int max_feature = features->RetCount ();
	
	for (int i = 0; i < max_feature; i++)
	{
		const open_type::lookup_table* lookup_table;
		
		lookup_table  = this->RetOpenTypeGSUBLookupTable (features->RetIndex (i));
		int subst_num = lookup_table->RetSubTableCount ();
		open_type::lookup_table::GSUB_Type gsub_type = lookup_table->RetLookupType ();

		if (gsub_type == open_type::lookup_table::GSUB_TYPE_ChainingContext)
		{
			continue;
		}
		
		if (gsub_type == open_type::lookup_table::GSUB_TYPE_Single)
		{
			//	...
		}
		
		if (gsub_type == open_type::lookup_table::GSUB_TYPE_Ligature)
		{
			if (array)
			{
				for (int j = 0; j < subst_num; j++)
				{
					array[total_subst+j] = reinterpret_cast<const open_type::ligature_subst*> (lookup_table->RetSubTable (j));
				}
			}
			
			total_subst += subst_num;
		}
		else
		{
			char message[100];
			sprintf (message, "Unsupported GSUB_TYPE=%d found", (int)gsub_type);
			OS::OutputDebugStringA (message);
		}
	}
	
	return total_subst;
}

open_type::table_directory*
font_face::FindOpenTypeTableDirectory (void* base_ptr, size_t offset)
{
	if (base_ptr == 0)
	{
		return 0;
	}
	
	if (offset == 0)
	{
		open_type::table_ttc_header* ttc = reinterpret_cast<open_type::table_ttc_header*> (base_ptr);
		
		if ((ttc->tag[0] == 't') &&
			(ttc->tag[1] == 't') &&
			(ttc->tag[2] == 'c') &&
			(ttc->tag[3] == 'f'))
		{
			offset = read_big_endian (ttc->offset_table[0]);
		}
	}
	
	return reinterpret_cast<open_type::table_directory*> (reinterpret_cast<char*> (base_ptr) + offset);
}

open_type::table_directory*
font_face::RetOpenTypeTableDirectory ()
{
	return this->FindOpenTypeTableDirectory (this->face_data, this->face_data_offset);
}

open_type::table_GSUB*
font_face::RetOpenTypeGSUB ()
{
	open_type::table_directory* ot_dir = this->RetOpenTypeTableDirectory ();
	return ot_dir ? reinterpret_cast<open_type::table_GSUB*> (ot_dir->FindTable (this->face_data, "GSUB")) : 0;
}

open_type::table_head*
font_face::RetOpenTypeHead ()
{
	open_type::table_directory* ot_dir = this->RetOpenTypeTableDirectory ();
	return ot_dir ? reinterpret_cast<open_type::table_head*> (ot_dir->FindTable (this->face_data, "head")) : 0;
}

open_type::table_hhea*
font_face::RetOpenTypeHorizHead ()
{
	open_type::table_directory* ot_dir = this->RetOpenTypeTableDirectory ();
	return ot_dir ? reinterpret_cast<open_type::table_hhea*> (ot_dir->FindTable (this->face_data, "hhea")) : 0;
}

open_type::table_cmap*
font_face::RetOpenTypeCMap ()
{
	open_type::table_directory* ot_dir = this->RetOpenTypeTableDirectory ();
	return ot_dir ? reinterpret_cast<open_type::table_cmap*> (ot_dir->FindTable (this->face_data, "cmap")) : 0;
}

open_type::table_loca*
font_face::RetOpenTypeLoca ()
{
	open_type::table_directory* ot_dir = this->RetOpenTypeTableDirectory ();
	return ot_dir ? reinterpret_cast<open_type::table_loca*> (ot_dir->FindTable (this->face_data, "loca")) : 0;
}

open_type::table_glyf*
font_face::RetOpenTypeGlyf (int32u offset)
{
	open_type::table_directory* ot_dir = this->RetOpenTypeTableDirectory ();
	int8u* table_glyf = ot_dir ? reinterpret_cast<int8u*> (ot_dir->FindTable (this->face_data, "glyf")) : 0;
	return table_glyf ? reinterpret_cast<open_type::table_glyf*> (table_glyf + offset) : 0;
}



const open_type::feature_list*
font_face::RetOpenTypeGSUBFeatureList ()
{
	open_type::table_GSUB* ot_gsub = this->RetOpenTypeGSUB ();
	return ot_gsub ? ot_gsub->RetFeatureList () : 0;
}

const open_type::feature_table*
font_face::RetOpenTypeGSUBFeatureTable (const char* feature)
{
	const open_type::feature_list* ot_feature_list = this->RetOpenTypeGSUBFeatureList ();
	return ot_feature_list ? ot_feature_list->RetTable (feature) : 0;
}

const open_type::lookup_list*
font_face::RetOpenTypeGSUBLookupList ()
{
	open_type::table_GSUB* ot_gsub = this->RetOpenTypeGSUB ();
	return ot_gsub ? ot_gsub->RetLookupList () : 0;
}

const open_type::lookup_table*
font_face::RetOpenTypeGSUBLookupTable (int16u index)
{
	const open_type::lookup_list* ot_lookup_list = this->RetOpenTypeGSUBLookupList ();
	return ot_lookup_list ? ot_lookup_list->RetTable (index) : 0;
}

/*****************************************************************************/

int16u
font_face::RetGlyphIndex (int32u unicode)
{
	open_type::table_cmap* ot_cmap = this->RetOpenTypeCMap ();
	open_type::table_cmap::EncodingFmt4* unicode_map = ot_cmap ? ot_cmap->FindUnicodeTable () : 0;
	
	if ( (unicode_map)
	  && (unicode < 0x0000ffff) )
	{
		int16u glyph = unicode_map->FindGlyphIndex (static_cast<int16u> (unicode));
		
		if (glyph == 0)
		{
			switch (unicode)
			{
				case 0x2000: glyph = 0xff01; break;			//	1/2 em
				case 0x2001: glyph = 0xff00; break;			//	1 em
				case 0x2002: glyph = 0xff01; break;			//	1/2 em
				case 0x2003: glyph = 0xff00; break;			//	1 em
				case 0x2004: glyph = 0xff02; break;			//	1/3 em
				case 0x2005: glyph = 0xff03; break;			//	1/4 em
				case 0x2006: glyph = 0xff06; break;			//	1/6 em
				case 0x2007: glyph = 0xff0a; break;			//	'0' (digit)
				case 0x2008: glyph = 0xff09; break;			//	'.' (narrow punctuation)
				case 0x2009: glyph = 0xff05; break;			//	1/5 em
				case 0x200A: glyph = 0xff07; break;			//	1/16 em
				case 0x200B: glyph = 0xff08; break;			//	zero width
				case 0x200C: glyph = 0xff08; break;			//	zero width
				case 0x200D: glyph = 0xff08; break;			//	zero width
				
				case 0x202F: glyph = 0xff0b; break;			//	narrow space
				case 0x205F: glyph = 0xff04; break;			//	4/18 em
				case 0x2060: glyph = 0xff08; break;			//	zero width
				
				case 0x00A0:
					glyph = unicode_map->FindGlyphIndex (static_cast<int16u> (' '));
					break;
				
				case 0x2010:		//	Hyphen
				case 0x2011:		//	Non Breaking Hyphen
				case 0x00AD:		//	Soft Hyphen
				case 0x1806:		//	Mongolian Todo Hyphen
					glyph = unicode_map->FindGlyphIndex (static_cast<int16u> ('-'));
					break;
			}
		}
		
		return glyph;
	}
	
	return 0;
}


double
font_face::RetGlyphAdvance (int16u glyph)
{
	double x = 0;
	double y = 0;
	this->GetGlyphAdvance (glyph, x, y);
	return x;
}

double
font_face::RetGlyphKerning (int16u glyph_1, int16u glyph_2)
{
	return 0.0;
}

double
font_face::RetCaretSlope ()
{
	if (this->UpdateCache () == false) {
		return 90;
	}
	
	open_type::table_hhea* hhea = this->face_cache->ot_hhea;
	
	double rise = read_big_endian (hhea->caret_slope_rise);
	double run  = read_big_endian (hhea->caret_slope_run);
	
	return atan2 (rise, run) * 180.0 * M_1_PI;
}

bool
font_face::GetGlyphAdvance (int16u glyph, double& x, double& y)
{
	if (this->UpdateCache () == false) {
		return false;
	}
	
	font_face::cache_record::size_info_record* info = this->face_cache->FindSizeInfo (glyph);
	
	if (info)
	{
		x = info->width_advance * this->face_cache->scale_to_em;
		y = 0.0;
	}
	else
	{
		x = 0.0;
		y = 0.0;
	}
	
	return (x != 0.0) ? true : false;
}

bool
font_face::GetGlyphAdvance (int16u glyph, double& x, double& y, font_face::cache_record::size_info_record*& info)
{
	if (this->UpdateCache () == false)
	{
		info = 0;
		return false;
	}
	
	info = this->face_cache->FindSizeInfo (glyph);
	
	if (info)
	{
		x = info->width_advance * this->face_cache->scale_to_em;
		y = 0.0;
	}
	else
	{
		x = 0.0;
		y = 0.0;
	}
	
	return (x != 0.0) ? true : false;
}

void
font_face::GetGlyphBounds (int16u glyph, double& x_min, double& y_min, double& x_max, double& y_max)
{
	font_face::cache_record::size_info_record* info = this->UpdateCache () ? this->face_cache->FindSizeInfo (glyph) : 0;
	
	if (info)
	{
		double s = this->face_cache->scale_to_em;
		
		x_min = info->x_min * s;
		y_min = info->y_min * s;
		x_max = info->x_max * s;
		y_max = info->y_max * s;
	}
	else
	{
		x_min = 0;	y_min = 0;
		x_max = 0;	y_max = 0;
	}
}


bool
font_face::GetVerticalMetrics (double & ascender, double & descender, double & line_height)
{
	if (this->UpdateCache ())
	{
		double scale = this->face_cache->scale_to_em;
		
		ascender    = scale * this->face_cache->mac_ascender;
		descender   = scale * this->face_cache->mac_descender;
		line_height = scale * (this->face_cache->mac_ascender - this->face_cache->mac_descender + this->face_cache->mac_line_gap);
		
		return true;
	}
	
	return false;
}


double
font_face::MeasureWidth (const int16u* glyphs, int num_glyphs,
							 bool use_kerning,
							 int16u pre_kern_glyph, int16u post_kern_glyph)
{
	double width = 0;
	
	if (num_glyphs)
	{
		for (int i = 0; i < num_glyphs; i++)
		{
			width += this->RetGlyphAdvance (glyphs[i]);
		}
		
		if (use_kerning)
		{
			width += this->RetGlyphKerning (pre_kern_glyph, glyphs[0]);
			
			for (int i = 0; i < num_glyphs-1; i++)
			{
				width += this->RetGlyphKerning (glyphs[i], glyphs[i+1]);
			}
			
			width += this->RetGlyphKerning (glyphs[num_glyphs-1], post_kern_glyph);
		}
	}
	
	return width;
}

void
font_face::MeasureWidthByClass (const int16u* glyphs, const int8u* glyphs_class, float* glyph_dx, int num_glyphs,
									double* width_by_class, int num_classes,
									bool use_kerning,
									int16u pre_kern_glyph, int16u post_kern_glyph)
{
	for (int i = 0; i < num_classes; i++)
	{
		width_by_class[i] = 0;
	}
	
	if (num_glyphs)
	{
		double dx;
		
		if (glyph_dx == 0)
		{
			for (int i = 0; i < num_glyphs; i++)
			{
				assert (glyphs_class[i] < num_classes);
				dx = this->RetGlyphAdvance (glyphs[i]);
				width_by_class[glyphs_class[i]] += dx;
			}
			
			if (use_kerning)
			{
				dx = this->RetGlyphKerning (pre_kern_glyph, glyphs[0]);
				width_by_class[glyphs_class[0]] += dx;
				
				for (int i = 0; i < num_glyphs-1; i++)
				{
					dx = this->RetGlyphKerning (glyphs[i], glyphs[i+1]);
					width_by_class[glyphs_class[i]] += dx;
				}
				
				dx = this->RetGlyphKerning (glyphs[num_glyphs-1], post_kern_glyph);
				width_by_class[glyphs_class[num_glyphs-1]] += dx;
			}
		}
		else
		{
			for (int i = 0; i < num_glyphs; i++)
			{
				assert (glyphs_class[i] < num_classes);
				dx = this->RetGlyphAdvance (glyphs[i]);
				width_by_class[glyphs_class[i]] += dx;
				glyph_dx[i] = static_cast<float> (dx);
			}
			
			if (use_kerning)
			{
				dx = this->RetGlyphKerning (pre_kern_glyph, glyphs[0]);
				width_by_class[glyphs_class[0]] += dx;
				glyph_dx[0] += static_cast<float> (dx);
				
				for (int i = 0; i < num_glyphs-1; i++)
				{
					dx = this->RetGlyphKerning (glyphs[i], glyphs[i+1]);
					width_by_class[glyphs_class[i]] += dx;
					glyph_dx[i] += static_cast<float> (dx);
				}
				
				dx = this->RetGlyphKerning (glyphs[num_glyphs-1], post_kern_glyph);
				width_by_class[glyphs_class[num_glyphs-1]] += dx;
				glyph_dx[num_glyphs-1] += static_cast<float> (dx);
			}
		}
	}
}

void
font_face::LayoutGlyphs (double & x,
							 const int16u* glyphs, double* x_array, int num_glyphs,
							 bool use_kerning,
							 int16u pre_kern_glyph, int16u post_kern_glyph)
{
	if (num_glyphs < 1) {
		return;
	}
	
	if (use_kerning)
	{
		x += this->RetGlyphKerning (pre_kern_glyph, glyphs[0]);
	}
	
	for (int i = 0; i < num_glyphs-1; i++)
	{
		x_array[i] = x;
		x += this->RetGlyphAdvance (glyphs[i]) + (use_kerning ? this->RetGlyphKerning (glyphs[i], glyphs[i+1]) : 0);
	}
	
	x_array[num_glyphs-1] = x;
	x += this->RetGlyphAdvance (glyphs[num_glyphs-1]) + (use_kerning ? this->RetGlyphKerning (glyphs[num_glyphs-1], post_kern_glyph) : 0);
}


int
font_face::MapToGlyphs (const wchar_t* text16, size_t text_len,
							int16u* glyphs, int8u* charpg, int max_glyphs,
							font_face::GlyphSubst substitution)
{
	int32u* text32 = reinterpret_cast<int32u*> (alloca (text_len * 4));
	
	for (size_t i = 0; i < text_len; i++) {
		text32[i] = text16[i];
	}
	
	return this->MapToGlyphs (text32, text_len, glyphs, charpg, max_glyphs, substitution);
}

int
font_face::MapToGlyphs (const int32u* text, size_t text_len,
							int16u* glyphs, int8u* charpg, int max_glyphs,
							font_face::GlyphSubst substitution)
{
	int num_glyphs = 0;
	
	for (size_t i = 0; i < text_len; i++) {
		if (num_glyphs < max_glyphs) {
			glyphs[i] = this->RetGlyphIndex (text[i]);
			charpg[i] = 1;
		}
		num_glyphs++;
	}
	
	if (num_glyphs > max_glyphs) {
		return num_glyphs;
	}
	
	this->SubstituteGlyphs (glyphs, charpg, num_glyphs, substitution);
	
	return num_glyphs;
}


int
font_face::SubstituteGlyphs (int16u* glyphs, int8u* charpg, int & num_glyphs,
								 font_face::GlyphSubst substitution)
{
	if (this->UpdateCache () == false) {
		return 0;
	}
	
	int num_subst = 0;
	int sel_mask  = font_face::SUBST_LIG_LAST;
	
	if (charpg == 0)
	{
		//	Rather than testing further in the loops if the character to glyph count mapping
		//	array was specified, allocate a local one which will get thrown away when we leave
		//	the function.
		
		charpg = reinterpret_cast<int8u*> (alloca (num_glyphs));
	}
	
	while (sel_mask)
	{
		const open_type::ligature_subst** subst = 0;
		
		if (sel_mask & substitution)
		{
			switch (sel_mask)
			{
				case font_face::SUBST_LIG_STANDARD:
					subst = this->face_cache->lig_standard;
					break;
				case font_face::SUBST_LIG_REQUIRED:
					subst = this->face_cache->lig_required;
					break;
				case font_face::SUBST_LIG_DISCRETIONARY:
					subst = this->face_cache->lig_discretionary;
					break;
			}
		}
		
		sel_mask >>= 1;
		
		if (subst == 0) {
			continue;
		}
		
		for (int i = 0; subst[i]; i++)
		{
			for (int glyph_offset = 0; glyph_offset < num_glyphs; glyph_offset++)
			{
				int    max   = num_glyphs - glyph_offset;
				int16u glyph = 0;
				int16u skip  = 0;
				
				if (subst[i]->PerformSubstitution (glyphs + glyph_offset, glyph, skip))
				{
					glyphs[glyph_offset]  = glyph;
					charpg[glyph_offset] += skip-1;
		            
					int remaining = max - skip;
					
					if (remaining > 0)
					{
						memmove (glyphs+glyph_offset+1, glyphs+glyph_offset+skip, sizeof (*glyphs) * remaining);
						memmove (charpg+glyph_offset+1, charpg+glyph_offset+skip, sizeof (*charpg) * remaining);
					}
					
					num_glyphs -= skip-1;
					num_subst++;
				}
			}
		}
	}
	
	return num_subst;
}

/*****************************************************************************/

void
font_face::Unlock ()
{
	assert (this->lock_count);
	
	this->lock_count--;
	
	if (this->lock_count == 0)
	{
		//	...
	}
}

/*****************************************************************************/

font_face::cache_record::cache_record (font_face* font_face)
:
face (font_face),
heap (),
lig_standard (0), lig_required (0), lig_discretionary (0),
ot_glyf (0), ot_head (0), ot_hhea (0), ot_hmtx (0), ot_loca (0), ot_maxp (0),
glyph_count (0), glyph_sizes (0),
units_per_em (0), scale_to_em (1),
mac_ascender (0), mac_descender (0), mac_line_gap (0)
{
	const open_type::feature_table* features;
	
	features = face->RetOpenTypeGSUBFeatureTable ("liga");
	this->lig_standard      = face->NewOpenTypeLigatureSubstArray (features);
	
	features = face->RetOpenTypeGSUBFeatureTable ("rlig");
	this->lig_required      = face->NewOpenTypeLigatureSubstArray (features);
	
	features = face->RetOpenTypeGSUBFeatureTable ("dlig");
	this->lig_discretionary = face->NewOpenTypeLigatureSubstArray (features);
	
	open_type::table_directory* ot_dir = face->RetOpenTypeTableDirectory ();
	
	this->ot_glyf = reinterpret_cast<open_type::table_glyf*> (ot_dir->FindTable (font_face->face_data, "glyf"));
	this->ot_head = reinterpret_cast<open_type::table_head*> (ot_dir->FindTable (font_face->face_data, "head"));
	this->ot_hhea = reinterpret_cast<open_type::table_hhea*> (ot_dir->FindTable (font_face->face_data, "hhea"));
	this->ot_hmtx = reinterpret_cast<open_type::table_hmtx*> (ot_dir->FindTable (font_face->face_data, "hmtx"));
	this->ot_loca = reinterpret_cast<open_type::table_loca*> (ot_dir->FindTable (font_face->face_data, "loca"));
	this->ot_maxp = reinterpret_cast<open_type::table_maxp*> (ot_dir->FindTable (font_face->face_data, "maxp"));
	
	this->units_per_em = read_big_endian (this->ot_head->units_per_em);
	this->scale_to_em  = 1.0 / this->units_per_em;
	
	this->mac_ascender  = read_big_endian (this->ot_hhea->mac_ascender);
	this->mac_descender = read_big_endian (this->ot_hhea->mac_descender);
	this->mac_line_gap  = read_big_endian (this->ot_hhea->mac_line_gap);
	
	this->TurboAlloc (0);
}

font_face::cache_record::~cache_record ()
{
	if (this->glyph_sizes)
	{
		delete [] this->glyph_sizes;
		this->glyph_sizes = 0;
		this->glyph_count = 0;
	}
	if (this->lig_standard)
	{
		delete [] this->lig_standard;
		this->lig_standard = 0;
	}
	if (this->lig_required)
	{
		delete [] this->lig_required;
		this->lig_required = 0;
	}
	if (this->lig_discretionary)
	{
		delete [] this->lig_discretionary;
		this->lig_discretionary = 0;
	}
}


bool
font_face::cache_record::CheckAndResize (int16u n)
{
	if (n < this->glyph_count)
	{
		return true;
	}
	if (n >= 0xff00)
	{
		return false;
	}
	
	n += 1;
	
	//	TODO: vérifier pourquoi on utilise n*2 ici !
	
	size_info_record* array = new size_info_record [n*2];
	
	if (array)
	{
		memory_zero (array, sizeof (size_info_record) * n * 2);
		
		if (this->glyph_sizes)
		{
			for (int i = 0; i < this->glyph_count; i++)
			{
				array[i] = this->glyph_sizes[i];
			}
			
			delete [] this->glyph_sizes;
		}
		
		this->glyph_sizes = array;
		this->glyph_count = n;
		
		return true;
	}
	
	return false;
}

font_face::cache_record::size_info_record*
font_face::cache_record::FindSizeInfo (int16u glyph)
{
	if (this->CheckAndResize (glyph) == false)
	{
		return 0;
	}
	
	if (glyph >= read_big_endian (this->ot_maxp->num_glyphs))
	{
		return 0;
	}
	
	size_info_record* info = this->glyph_sizes + glyph;
	
	if (info->width_advance)
	{
		return info;
	}
	
	if ( (info->x_min != 0)
	  || (info->x_max != 0)
	  || (info->y_min != 0)
	  || (info->y_max != 0) )
	{
		return info;
	}
	
	int32u                 glyph_offset = this->ot_loca ? this->ot_loca->FindOffset (glyph, this->ot_head) : 0;
	int32u				   glyph_o_next = this->ot_loca ? this->ot_loca->FindOffset (glyph+1, this->ot_head) : 0;
	open_type::table_glyf* glyph_table  = this->ot_glyf ? this->ot_glyf->FindSubTable (glyph_offset) : 0;
	
	int16u left_side_bearing  = 0;
	int16u width_advance      = 0;
	int16u right_side_bearing = 0;
	
	int16u x_min = 0;
	int16u x_max = 0;
	
	open_type::GetGlyphWidths (ot_maxp, ot_hhea, ot_hmtx, glyph,
							   info->left_side_bearing, info->width_advance);
	
	if (glyph_table)
	{
		info->x_min = read_big_endian (glyph_table->header.x_min);
		info->x_max = read_big_endian (glyph_table->header.x_max);
		info->y_min = read_big_endian (glyph_table->header.y_min);
		info->y_max = read_big_endian (glyph_table->header.y_max);
	}
	else
	{
		//	We don't know how to parse fonts which don't have a glyph table, like
		//	PostScript fonts (such as Adobe's "Warnock Pro" font family). Under Win32,
		//	we rely on GDI to convert the glyph into its outline and then we tranform
		//	the path to a TrueType compatible representation.
		
#if defined(WIN32)
		Win32::TempDC dc;
		
		HFONT   os_font  = (HFONT) this->face->os_handle;
		HGDIOBJ old_font = SelectObject (dc, os_font);
		
		GLYPHMETRICS metrics = { 0 };
		
		MAT2 mat2;
		mat2.eM11.value = 1; mat2.eM11.fract = 0;
		mat2.eM12.value = 0; mat2.eM12.fract = 0;
		mat2.eM21.value = 0; mat2.eM21.fract = 0;
		mat2.eM22.value = 1; mat2.eM22.fract = 0;
		
		GetGlyphOutline (dc, glyph, GGO_GLYPH_INDEX | GGO_METRICS, & metrics, 0, 0, & mat2);
		
		int    inc_x = metrics.gmCellIncX;
		double scale = 1.0;
		
		if (inc_x && info->width_advance)
		{
			scale = 1.0 * info->width_advance / inc_x;
		}
		
		info->x_min = static_cast<agg::int16> (scale * (metrics.gmptGlyphOrigin.x));
		info->x_max = static_cast<agg::int16> (scale * (metrics.gmptGlyphOrigin.x + static_cast<int> (metrics.gmBlackBoxX)));
		info->y_max = static_cast<agg::int16> (scale * (metrics.gmptGlyphOrigin.y));
		info->y_min = static_cast<agg::int16> (scale * (metrics.gmptGlyphOrigin.y - static_cast<int> (metrics.gmBlackBoxY)));
		
		info->mtx = 0;
		info->mty = 0;
		info->mxx = scale;
		info->myy = scale;
		info->mxy = 0.0;
		info->myx = 0.0;
		
#if !defined(GGO_UNHINTED)
#define  GGO_UNHINTED       0x0100
#endif
		
		int mode = GGO_GLYPH_INDEX | GGO_NATIVE | GGO_UNHINTED;
		int size = GetGlyphOutline (dc, glyph, mode, & metrics, 0, 0, & mat2);
		
		if (size > 0)
		{
			agg::int8u* buffer = reinterpret_cast<agg::int8u*> (_alloca (size));
			const int buf_size = size;
			
			GetGlyphOutline (dc, glyph, mode, & metrics, size, buffer, & mat2);
			
			TTPOLYGONHEADER* header = reinterpret_cast<TTPOLYGONHEADER*> (buffer);
			
			if (header->dwType == TT_POLYGON_TYPE)
			{
				int         total_size = buf_size;
				agg::int8u* ptr        = buffer;
				agg::int8u* ptr_path   = buffer;
				
				int num_coord = 0;
				
				while (total_size > 0)
				{
					total_size -= header->cb;
					ptr_path   += header->cb;
					num_coord  += 1;
					
					size  = header->cb;
					size -= sizeof (TTPOLYGONHEADER);
					ptr  += sizeof (TTPOLYGONHEADER);
					
					while (size > 0)
					{
						TTPOLYCURVE* curve = reinterpret_cast<TTPOLYCURVE*> (ptr);
						
						num_coord += curve->cpfx;
						
						size -= sizeof (TTPOLYCURVE) + sizeof (POINTFX) * (curve->cpfx-1);
						ptr  += sizeof (TTPOLYCURVE) + sizeof (POINTFX) * (curve->cpfx-1);
					}
					
					header = reinterpret_cast<TTPOLYGONHEADER*> (ptr_path);
				}
				
				int8u* copy_flags = reinterpret_cast<int8u*> (this->TurboAlloc (num_coord * sizeof(int8u)));
				int16* copy_x     = reinterpret_cast<int16*> (this->TurboAlloc (num_coord * sizeof(int16)));
				int16* copy_y     = reinterpret_cast<int16*> (this->TurboAlloc (num_coord * sizeof(int16)));
				
				info->num_coord   = num_coord;
				info->glyph_flags = copy_flags;
				info->glyph_x     = copy_x;
				info->glyph_y     = copy_y;
				
				total_size = buf_size;
				ptr        = buffer;
				ptr_path   = buffer;
				
				header = reinterpret_cast<TTPOLYGONHEADER*> (ptr_path);
				
				int c = 0;
				
				while (total_size > 0)
				{
					int sx = header->pfxStart.x.value;
					int sy = header->pfxStart.y.value;
					
					total_size -= header->cb;
					ptr_path   += header->cb;
					
					copy_flags[c] = font_face::cache_record::FLAG_ON_CURVE;
					copy_x[c] = sx;
					copy_y[c] = sy;
					
					c++;
					
					size  = header->cb;
					size -= sizeof (TTPOLYGONHEADER);
					ptr  += sizeof (TTPOLYGONHEADER);
					
					while (size > 0)
					{
						TTPOLYCURVE* curve = reinterpret_cast<TTPOLYCURVE*> (ptr);
						int curve_elements = curve->cpfx;
						
						switch (curve->wType)
						{
							case TT_PRIM_LINE:
								for (int i = 0; i < curve_elements; i++)
								{
									POINTFX pfx = curve->apfx[i];
									
									sx = pfx.x.value;
									sy = pfx.y.value;
									
									copy_flags[c] = font_face::cache_record::FLAG_ON_CURVE;
									copy_x[c] = sx;
									copy_y[c] = sy;
									
									c++;
								}
								break;
							
							case TT_PRIM_QSPLINE:
								for (int i = 0; i < curve_elements; i++)
								{
									POINTFX pfx = curve->apfx[i];
									
									sx = pfx.x.value;
									sy = pfx.y.value;
									
									copy_flags[c] = (i == curve_elements-1) ? font_face::cache_record::FLAG_ON_CURVE : 0;
									copy_x[c] = sx;
									copy_y[c] = sy;
									
									c++;
								}
								break;
							
							case TT_PRIM_CSPLINE:
								for (int i = 0; i < curve_elements; i++)
								{
									POINTFX pfx = curve->apfx[i];
									
									//	...pas supporté...
									
									__asm int 3;
									
									sx = pfx.x.value;
									sy = pfx.y.value;
								}
								break;
						}
						
						size -= sizeof (TTPOLYCURVE) + sizeof (POINTFX) * (curve_elements-1);
						ptr  += sizeof (TTPOLYCURVE) + sizeof (POINTFX) * (curve_elements-1);
					}
					
					copy_flags[c-1] |= font_face::cache_record::FLAG_CONTOUR_END;
					
					header = reinterpret_cast<TTPOLYGONHEADER*> (ptr_path);
				}
			}
		}
		
		SelectObject (dc, old_font);
		
		return info;
#endif
	}
	
	info->mtx = 0;
	info->mty = 0;
	info->mxx = 1.0;
	info->myy = 1.0;
	info->mxy = 0.0;
	info->myx = 0.0;
	
#if defined(ACTIVE_DEBUG_TRACE)
	Trace ("%S %S, Glyph %d has contents at offset %d [%d %d %d %d] %d %d [%d:%d]\n",
			face->RetFamilyName (),
			face->RetStyleNameUserLocale (),
			glyph, glyph_offset,
			info->x_min, info->y_min, info->x_max, info->y_max,
			info->left_side_bearing, info->width_advance,
			read_big_endian (glyph_table->header.num_contours),
			glyph_table->u.simple.NumCoordinates ());
#endif
	
	if (glyph_offset < glyph_o_next)
	{
		int16 num_contours = read_big_endian (glyph_table->header.num_contours);
		
		if (num_contours > 0)
		{
			this->DecompileSimpleCoordinates (info, num_contours, glyph_table);
		}
		else if (num_contours == -1)
		{
			this->DecompileComposite (glyph, info, glyph_table);
		}
	}
	
	return info;
}


int8u*
font_face::cache_record::TurboAlloc (int32u size)
{
	return this->heap.alloc (size);
}



bool
font_face::cache_record::DecompileComposite (int16u glyph, size_info_record*& info, open_type::table_glyf* glyf)
{
	assert (info->glyph_flags == 0);
	assert (info->glyph_x == 0);
	assert (info->glyph_y == 0);
	assert (info->composites == 0);
	assert (info->composite_count == 0);
	
	open_type::table_glyf::Composite* compo = & glyf->u.composite;
	
	int num_elements = compo->CountElements ();
	
	font_face::cache_record::size_info_record* elem = this->FindSizeInfo (compo->GlyphIndex ());
	
	info = this->glyph_sizes + glyph;
	
	assert (num_elements > 0);
	assert (elem != 0);
	
	int16u num_coord  = elem->num_coord;
	int8u* copy_flags = reinterpret_cast<int8u*> (this->TurboAlloc (num_coord * sizeof(int8u)));
	int16* copy_x     = reinterpret_cast<int16*> (this->TurboAlloc (num_coord * sizeof(int16)));
	int16* copy_y     = reinterpret_cast<int16*> (this->TurboAlloc (num_coord * sizeof(int16)));
	
	composite_info_record* composites = (num_elements < 2) ? 0 : reinterpret_cast<composite_info_record*> (this->TurboAlloc ((num_elements - 1) * sizeof(composite_info_record)));
	
	info->num_coord   = num_coord;
	info->glyph_flags = copy_flags;	memcpy (info->glyph_flags, elem->glyph_flags, num_coord * sizeof(int8u));
	info->glyph_x     = copy_x;		memcpy (info->glyph_x,     elem->glyph_x,     num_coord * sizeof(int16));
	info->glyph_y     = copy_y;		memcpy (info->glyph_y,     elem->glyph_y,     num_coord * sizeof(int16));
	
	num_elements--;
	
	info->composites      = composites;
	info->composite_count = num_elements;
	
	compo->GetMatrix (info->mxx, info->mxy, info->myx, info->myy);
	compo->GetOffsetXandY (info->mtx, info->mty);
	
	compo = compo->NextComposite ();
	
	for (int i = 0; i < num_elements; i++)
	{
		assert (compo != 0);
		
		int16u flags = compo->Flags ();
		
#if defined(ACTIVE_DEBUG_TRACE)
		if ((flags & open_type::table_glyf::FLAG_ArgsAreXyValues) == 0)
		{
			Trace ("Glyph %d in %S %S does not specify [x] [y] offset, but points !\n", glyph, face->RetFamilyName (), face->RetStyleNameUserLocale ());
		}
		if (flags & open_type::table_glyf::FLAG_Scale2x2)
		{
			Trace ("Glyph %d in %S %S specifies 2 x 2 scale matrix.\n", glyph, face->RetFamilyName (), face->RetStyleNameUserLocale ());
		}
		if (flags & open_type::table_glyf::FLAG_SimpleScale)
		{
			Trace ("Glyph %d in %S %S specifies simple scale.\n", glyph, face->RetFamilyName (), face->RetStyleNameUserLocale ());
		}
		if (flags & open_type::table_glyf::FLAG_ScaleXyDifferent)
		{
			Trace ("Glyph %d in %S %S specifies [x] and [y] scales.\n", glyph, face->RetFamilyName (), face->RetStyleNameUserLocale ());
		}
#endif
		
		composites[i].glyph = compo->GlyphIndex ();
		compo->GetOffsetXandY (composites[i].ox, composites[i].oy);
		compo->GetMatrix (composites[i].xx, composites[i].xy, composites[i].yx, composites[i].yy);
		compo = compo->NextComposite ();
	}
	
	return true;
}


/*
 *	Decompile the coordinates from the OpenType 'glyf' table. Process the description
 *	in its 'simple' form. We don't evaluate the program, but only the coordinates.
 *	
 *	The OpenType specification is clear, once you understand how it works ;-)
 */

bool
font_face::cache_record::DecompileSimpleCoordinates (size_info_record* info, int16u num_contours, open_type::table_glyf* glyf)
{
	assert (num_contours != 0);
	assert (info->glyph_flags == 0);
	assert (info->glyph_x == 0);
	assert (info->glyph_y == 0);
	
	open_type::table_glyf::Simple* simple = & glyf->u.simple;
	
	int16u num_instr    = read_big_endian (simple->end_pts_of_contour[num_contours]);
	int16u num_coord    = read_big_endian (simple->end_pts_of_contour[num_contours - 1]) + 1;
	
	const int8u* data = reinterpret_cast<const int8u*> (simple->end_pts_of_contour + num_contours + 1) + num_instr;
	
	assert (data == simple->Flags ());
	
	int8u* copy_flags = reinterpret_cast<int8u*> (this->TurboAlloc (num_coord * sizeof(int8u)));
	int16* copy_x     = reinterpret_cast<int16*> (this->TurboAlloc (num_coord * sizeof(int16)));
	int16* copy_y     = reinterpret_cast<int16*> (this->TurboAlloc (num_coord * sizeof(int16)));
	
	info->num_coord   = num_coord;
	info->glyph_flags = copy_flags;
	info->glyph_x     = copy_x;
	info->glyph_y     = copy_y;
	
	int16u i = 0;
	int16u j = 0;
	
	while (j < num_coord)
	{
		int8u flag = data[i++];
		
		if (flag & open_type::table_glyf::FLAG_Repeat)
		{
			int8u repeat = data[i++] + 1;
			
			while (repeat--)
			{
				copy_flags[j++] = flag;
			}
		}
		else
		{
			copy_flags[j++] = flag;
		}
	}
	
	int16u x_org = 0;
	
	for (j = 0; j < num_coord; j++)
	{
		int8u flag = copy_flags[j];
		
		if (flag & open_type::table_glyf::FLAG_xShort)
		{
			//	[x] is a int8u
			copy_x[j] = x_org += (flag & open_type::table_glyf::FLAG_xSame) ? data[i] : -data[i];
			i += 1;
		}
		else if (flag & open_type::table_glyf::FLAG_xSame)
		{
			//	[x] is simply the same as the last one
			copy_x[j] = x_org;
		}
		else
		{
			//	[x] is a int16u
			copy_x[j] = x_org += (data[i+0] << 8) | (data[i+1]);
			i += 2;
		}
	}
	
	int16u y_org = 0;
	
	for (j = 0; j < num_coord; j++)
	{
		int8u flag = copy_flags[j];
		
		if (flag & open_type::table_glyf::FLAG_yShort)
		{
			//	[y] is a int8u
			copy_y[j] = y_org += (flag & open_type::table_glyf::FLAG_ySame) ? data[i] : -data[i];
			i += 1;
		}
		else if (flag & open_type::table_glyf::FLAG_ySame)
		{
			//	[y] is simply the same as the last one
			copy_y[j] = y_org;
		}
		else
		{
			//	[y] is a int16u
			copy_y[j] = y_org += (data[i+0] << 8) | (data[i+1]);
			i += 2;
		}
	}
	
	int16u contour_i   = 0;
	int16u contour_end = read_big_endian (simple->end_pts_of_contour[contour_i]);
	
	for (j = 0; j < num_coord; j++)
	{
		if (j == contour_end)
		{
			contour_i++;
			contour_end = read_big_endian (simple->end_pts_of_contour[contour_i]);
			
			copy_flags[j] &= FLAG_ON_CURVE;
			copy_flags[j] |= FLAG_CONTOUR_END;
		}
		else
		{
			copy_flags[j] &= FLAG_ON_CURVE;
		}
	}
	
	return true;
}

/*****************************************************************************/

font_face::cache_record::pix_per_size_record*
font_face::cache_record::FindPixPerSize (font_face::cache_record::size_info_record* info, int32u size)
{
	if (info)
	{
		font_face::cache_record::pix_per_size_record** ptr = & info->pixel_head;
		font_face::cache_record::pix_per_size_record*  pps = *ptr;
		
		while (pps)
		{
			if (pps->size == size)
			{
				return pps;
			}
			ptr = & pps->next;
			pps = *ptr;
		}
		
		//	No record found for this size, so allocate an empty one.
		
		pps = reinterpret_cast<font_face::cache_record::pix_per_size_record*> (this->TurboAlloc (sizeof (font_face::cache_record::pix_per_size_record)));
		
		pps->data_head = 0;
		pps->next      = 0;
		pps->size      = size;
		
		*ptr = pps;
		
		return pps;
	}
	
	return 0;
}

font_face::cache_record::pix_data_record*
font_face::cache_record::FindPixData (font_face::cache_record::size_info_record* info, int32u size, int8u xs, int8u ys)
{
	font_face::cache_record::pix_per_size_record* pps = this->FindPixPerSize (info, size);
	
	if (pps)
	{
		font_face::cache_record::pix_data_record** ptr = & pps->data_head;
		font_face::cache_record::pix_data_record*  ppd = *ptr;
		while (ppd)
		{
			if ( (ppd->x_shift == xs)
			  && (ppd->y_shift == ys) )
			{
				//	Always put the last hit into the head of the list. This will speed up subsequent searches
				//	of this glyph.
				
				if (ppd != pps->data_head)
				{
					*ptr = ppd->next;
					ppd->next = pps->data_head;
					pps->data_head = ppd;
				}
				
				return ppd;
			}
			ptr = & ppd->next;
			ppd = *ptr;
		}
		
		//	No record found for this shift, so allocate an empty one.
		
		ppd = reinterpret_cast<font_face::cache_record::pix_data_record*> (this->TurboAlloc (sizeof (font_face::cache_record::pix_data_record)));
		
		ppd->next = 0;
		ppd->dx = 0;
		ppd->dy = 0;
		ppd->ox = 0;
		ppd->oy = 0;
		ppd->x_shift = xs;
		ppd->y_shift = ys;
		ppd->pixels = 0;
		
		*ptr = ppd;
		
		return ppd;
	}
	
	return 0;
}


/*****************************************************************************/
