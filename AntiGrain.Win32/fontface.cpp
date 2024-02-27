/*
 *	fontface.cpp
 *
 *	The FontFace class represents a font face.
 *
 *	(C) Copyright 2003-2004, Pierre ARNAUD, OPaC bright ideas, Ch. du Fontenay 6,
 *		CH-1400 YVERDON, Switzerland. All rights reserved.
 */

#define	_USE_MATH_DEFINES

#include "DLL.h"

#include "fontface.h"

#include "agg_opentype.h"
#include "agg_strsafe.h"

#include <assert.h>
#include <malloc.h>
#include <math.h>

using namespace agg;

/*****************************************************************************/

FontFace::FontFace (FontManager* font_manager_)
:
font_manager (font_manager),
face_data (0),
face_data_size (0),
face_cache (0),
prev (0),
next (0),
os_description (0),
lock_count (0),
is_memory_usage_reduction_pending (false),
is_font_unsupported (false)
{
	string_zero (this->os_name, sizeof (this->os_name));
	string_zero (this->family_name, sizeof (this->family_name));
	string_zero (this->style_name, sizeof (this->style_name));
	string_zero (this->style_name_loc, sizeof (this->style_name_loc));
	string_zero (this->optical_name, sizeof (this->optical_name));
}

FontFace::~FontFace ()
{
	assert (this->lock_count == 0);
}

/*****************************************************************************/

bool
FontFace::RealiseData ()
{
	if ( (this->face_data == 0)
	  && (this->is_font_unsupported == false) )
	{
		FontManager::FamilyRecord::LoadFontData (this->os_description, this->face_data, this->face_data_size);
		
		open_type::table_directory* dir = reinterpret_cast<open_type::table_directory*> (this->face_data);
		int32u end_of_tables = dir->FindMaxTableEnd ();
		
		if (end_of_tables > this->face_data_size)
		{
			this->is_font_unsupported = true;
			
			FontManager::FamilyRecord::FreeFontData (this->face_data);
			
			this->face_data = 0;
			this->face_data_size = 0;
		}
	}
	
	return this->face_data ? true : false;
}

void
FontFace::DisposeData ()
{
	if (this->face_data)
	{
		FontManager::FamilyRecord::FreeFontData (this->face_data);
		this->face_data = 0;
		this->face_data_size = 0;
	}
	
	if (this->os_handle)
	{
		FontManager::FamilyRecord::FreeOsHandle (this->os_handle);
		this->os_handle = 0;
	}
	
	this->ClearCache ();
}

void*
FontFace::RetOsHandle ()
{
	if (this->os_handle == 0)
	{
		FontManager::FamilyRecord::LoadFontAndReturnOsHandle (this->os_description, this->os_handle);
	}
	
	return this->os_handle;
}

void
FontFace::ClearCache ()
{
	if (this->face_cache)
	{
		delete this->face_cache;
		this->face_cache = 0;
	}
}

bool
FontFace::UpdateCache ()
{
	if ( (this->face_cache == 0)
	  && (this->RealiseData ()) )
	{
		this->face_cache = new FontFace::Cache (this);
	}
	
	return this->face_cache ? true : false;
}

const open_type::ligature_subst**
FontFace::NewOpenTypeLigatureSubstArray (const open_type::feature_table* features)
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
FontFace::FillOpenTypeLigatureSubstArray (const open_type::feature_table* features,
										  const open_type::ligature_subst** array)
{
	if (features == 0) {
		return 0;
	}
	
	int total_subst = 0;
	int max_feature = features->RetCount ();
	
	for (int i = 0; i < max_feature; i++)
	{
		const open_type::lookup_table* lookup_table;
		
		lookup_table  = this->RetOpenTypeGSUBLookupTable (features->RetIndex (i));
		int subst_num = lookup_table->RetSubTableCount ();
		
		assert (lookup_table->RetLookupType () == open_type::lookup_table::GSUB_TYPE_Ligature);
		
		if (array)
		{
			for (int j = 0; j < subst_num; j++)
			{
				array[total_subst+j] = reinterpret_cast<const open_type::ligature_subst*> (lookup_table->RetSubTable (j));
			}
		}
		
		total_subst += subst_num;
	}
	
	return total_subst;
}

open_type::table_directory*
FontFace::RetOpenTypeTableDirectory ()
{
	this->RealiseData ();
	return reinterpret_cast<open_type::table_directory*> (this->face_data);
}

open_type::table_GSUB*
FontFace::RetOpenTypeGSUB ()
{
	open_type::table_directory* ot_dir = this->RetOpenTypeTableDirectory ();
	return ot_dir ? reinterpret_cast<open_type::table_GSUB*> (ot_dir->FindTable ("GSUB")) : 0;
}

open_type::table_head*
FontFace::RetOpenTypeHead ()
{
	open_type::table_directory* ot_dir = this->RetOpenTypeTableDirectory ();
	return ot_dir ? reinterpret_cast<open_type::table_head*> (ot_dir->FindTable ("head")) : 0;
}

open_type::table_hhea*
FontFace::RetOpenTypeHorizHead ()
{
	open_type::table_directory* ot_dir = this->RetOpenTypeTableDirectory ();
	return ot_dir ? reinterpret_cast<open_type::table_hhea*> (ot_dir->FindTable ("hhea")) : 0;
}

open_type::table_cmap*
FontFace::RetOpenTypeCMap ()
{
	open_type::table_directory* ot_dir = this->RetOpenTypeTableDirectory ();
	return ot_dir ? reinterpret_cast<open_type::table_cmap*> (ot_dir->FindTable ("cmap")) : 0;
}

open_type::table_loca*
FontFace::RetOpenTypeLoca ()
{
	open_type::table_directory* ot_dir = this->RetOpenTypeTableDirectory ();
	return ot_dir ? reinterpret_cast<open_type::table_loca*> (ot_dir->FindTable ("loca")) : 0;
}

open_type::table_glyf*
FontFace::RetOpenTypeGlyf (int32u offset)
{
	open_type::table_directory* ot_dir = this->RetOpenTypeTableDirectory ();
	int8u* table_glyf = ot_dir ? reinterpret_cast<int8u*> (ot_dir->FindTable ("glyf")) : 0;
	return table_glyf ? reinterpret_cast<open_type::table_glyf*> (table_glyf + offset) : 0;
}



const open_type::feature_list*
FontFace::RetOpenTypeGSUBFeatureList ()
{
	open_type::table_GSUB* ot_gsub = this->RetOpenTypeGSUB ();
	return ot_gsub ? ot_gsub->RetFeatureList () : 0;
}

const open_type::feature_table*
FontFace::RetOpenTypeGSUBFeatureTable (const char* feature)
{
	const open_type::feature_list* ot_feature_list = this->RetOpenTypeGSUBFeatureList ();
	return ot_feature_list ? ot_feature_list->RetTable (feature) : 0;
}

const open_type::lookup_list*
FontFace::RetOpenTypeGSUBLookupList ()
{
	open_type::table_GSUB* ot_gsub = this->RetOpenTypeGSUB ();
	return ot_gsub ? ot_gsub->RetLookupList () : 0;
}

const open_type::lookup_table*
FontFace::RetOpenTypeGSUBLookupTable (int16u index)
{
	const open_type::lookup_list* ot_lookup_list = this->RetOpenTypeGSUBLookupList ();
	return ot_lookup_list ? ot_lookup_list->RetTable (index) : 0;
}

/*****************************************************************************/

int16u
FontFace::RetGlyphIndex (int32u unicode)
{
	this->RealiseData ();
	
	open_type::table_cmap* ot_cmap = this->RetOpenTypeCMap ();
	open_type::table_cmap::EncodingFmt4* unicode_map = ot_cmap ? ot_cmap->FindUnicodeTable () : 0;
	
	if ( (unicode_map)
	  && (unicode < 0x0000ffff) )
	{
		int16u glyph = unicode_map->FindGlyphIndex (static_cast<int16u> (unicode));
		return glyph;
	}
	
	return 0;
}


double
FontFace::RetGlyphAdvance (int16u glyph)
{
	double x = 0;
	double y = 0;
	this->GetGlyphAdvance (glyph, x, y);
	return x;
}

double
FontFace::RetGlyphKerning (int16u glyph_1, int16u glyph_2)
{
	double x = 0;
	double y = 0;
	this->GetGlyphKerning (glyph_1, glyph_2, x, y);
	return x;
}

double
FontFace::RetCaretSlope ()
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
FontFace::GetGlyphAdvance (int16u glyph, double& x, double& y)
{
	if (this->UpdateCache () == false) {
		return false;
	}
	
	FontFace::Cache::SizeInfo* info = this->face_cache->FindSizeInfo (glyph);
	
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
FontFace::GetGlyphAdvance (int16u glyph, double& x, double& y, FontFace::Cache::SizeInfo*& info)
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
FontFace::GetGlyphBounds (int16u glyph, double& x_min, double& y_min, double& x_max, double& y_max)
{
	FontFace::Cache::SizeInfo* info = this->UpdateCache () ? this->face_cache->FindSizeInfo (glyph) : 0;
	
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
FontFace::GetGlyphKerning (int16u glyph_1, int16u glyph_2, double& x, double& y)
{
	this->RealiseData ();
	
	//	TODO: get kerning
	
	return false;
}

bool
FontFace::GetVerticalMetrics (double & ascender, double & descender, double & line_height)
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
FontFace::MeasureWidth (const int16u* glyphs, int num_glyphs,
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
FontFace::MeasureWidthByClass (const int16u* glyphs, const int8u* glyphs_class, float* glyph_dx, int num_glyphs,
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
FontFace::LayoutGlyphs (double & x,
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
FontFace::MapToGlyphs (const wchar_t* text16, size_t text_len,
							int16u* glyphs, int8u* charpg, int max_glyphs,
							FontFace::GlyphSubst substitution)
{
	int32u* text32 = reinterpret_cast<int32u*> (_alloca (text_len * 4));
	
	for (size_t i = 0; i < text_len; i++) {
		text32[i] = text16[i];
	}
	
	return this->MapToGlyphs (text32, text_len, glyphs, charpg, max_glyphs, substitution);
}

int
FontFace::MapToGlyphs (const int32u* text, size_t text_len,
							int16u* glyphs, int8u* charpg, int max_glyphs,
							FontFace::GlyphSubst substitution)
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
FontFace::SubstituteGlyphs (int16u* glyphs, int8u* charpg, int & num_glyphs,
								 FontFace::GlyphSubst substitution)
{
	if (this->UpdateCache () == false) {
		return 0;
	}
	
	int num_subst = 0;
	int sel_mask  = FontFace::SUBST_LIG_LAST;
	
	if (charpg == 0)
	{
		//	Rather than testing further in the loops if the character to glyph count mapping
		//	array was specified, allocate a local one which will get thrown away when we leave
		//	the function.
		
		charpg = reinterpret_cast<int8u*> (_alloca (num_glyphs));
	}
	
	while (sel_mask)
	{
		const open_type::ligature_subst** subst = 0;
		
		if (sel_mask & substitution)
		{
			switch (sel_mask)
			{
				case FontFace::SUBST_LIG_STANDARD:
					subst = this->face_cache->lig_standard;
					break;
				case FontFace::SUBST_LIG_REQUIRED:
					subst = this->face_cache->lig_required;
					break;
				case FontFace::SUBST_LIG_DISCRETIONARY:
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
FontFace::ReduceMemoryUsage ()
{
	if (this->lock_count == 0)
	{
		assert (this->is_memory_usage_reduction_pending == false);
		this->DisposeData ();
	}
	else
	{
		this->is_memory_usage_reduction_pending = true;
	}
}

void
FontFace::Unlock ()
{
	assert (this->lock_count);
	
	this->lock_count--;
	
	if ( (this->lock_count == 0)
	  && (this->is_memory_usage_reduction_pending) )
	{
		this->is_memory_usage_reduction_pending = false;
		this->DisposeData ();
	}
}

/*****************************************************************************/

const wchar_t* FontFace::RetFamilyName () const				{ return this->family_name; }
const wchar_t* FontFace::RetStyleName () const				{ return this->style_name; }
const wchar_t* FontFace::RetStyleNameUserLocale () const	{ return this->style_name_loc; }
const wchar_t* FontFace::RetOpticalName () const			{ return this->optical_name; }

/*****************************************************************************/

FontFace::Cache::Cache (FontFace* font_face)
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
	
	this->ot_glyf = reinterpret_cast<open_type::table_glyf*> (ot_dir->FindTable ("glyf"));
	this->ot_head = reinterpret_cast<open_type::table_head*> (ot_dir->FindTable ("head"));
	this->ot_hhea = reinterpret_cast<open_type::table_hhea*> (ot_dir->FindTable ("hhea"));
	this->ot_hmtx = reinterpret_cast<open_type::table_hmtx*> (ot_dir->FindTable ("hmtx"));
	this->ot_loca = reinterpret_cast<open_type::table_loca*> (ot_dir->FindTable ("loca"));
	this->ot_maxp = reinterpret_cast<open_type::table_maxp*> (ot_dir->FindTable ("maxp"));
	
	this->units_per_em = read_big_endian (this->ot_head->units_per_em);
	this->scale_to_em  = 1.0 / this->units_per_em;
	
	this->mac_ascender  = read_big_endian (this->ot_hhea->mac_ascender);
	this->mac_descender = read_big_endian (this->ot_hhea->mac_descender);
	this->mac_line_gap  = read_big_endian (this->ot_hhea->mac_line_gap);
	
	this->TurboAlloc (0);
}

FontFace::Cache::~Cache ()
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
FontFace::Cache::CheckAndResize (int16u n)
{
	if (n < this->glyph_count)
	{
		return true;
	}
	
	n += 1;
	
	//	TODO: vérifier pourquoi on utilise n*2 ici !
	
	SizeInfo* array = new SizeInfo [n*2];
	
	if (array)
	{
		memory_zero (array, sizeof (SizeInfo) * n * 2);
		
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

FontFace::Cache::SizeInfo*
FontFace::Cache::FindSizeInfo (int16u glyph)
{
	if ( (this->ot_glyf == 0)
	  || (this->ot_loca == 0)
	  || (this->CheckAndResize (glyph) == false) )
	{
		return 0;
	}
	
	SizeInfo* info = this->glyph_sizes + glyph;
	
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
	
	int32u                glyph_offset = this->ot_loca->FindOffset (glyph, this->ot_head);
	int32u				  glyph_o_next = this->ot_loca->FindOffset (glyph+1, this->ot_head);
	open_type::table_glyf* glyph_table  = this->ot_glyf->FindSubTable (glyph_offset);
	
	int16u left_side_bearing  = 0;
	int16u width_advance      = 0;
	int16u right_side_bearing = 0;
	
	int16u x_min = 0;
	int16u x_max = 0;
	
	open_type::GetGlyphWidths (ot_maxp, ot_hhea, ot_hmtx, glyph,
							  info->left_side_bearing, info->width_advance);
	
	info->x_min = read_big_endian (glyph_table->header.x_min);
	info->x_max = read_big_endian (glyph_table->header.x_max);
	info->y_min = read_big_endian (glyph_table->header.y_min);
	info->y_max = read_big_endian (glyph_table->header.y_max);
	
#if 0	
	Trace ("%S %S, Glyph %d has contents at offset %d [%d %d %d %d] %d %d [%d:%d]\n",
			face->RetFamilyName (),
			face->RetStyleNameUserLocale (),
			glyph, glyph_offset,
			info->x_min, info->y_min, info->x_max, info->y_max,
			info->left_side_bearing, info->width_advance,
			read_big_endian (glyph_table->header.num_contours),
			glyph_table->simple.NumCoordinates ());
#endif
	
	if (glyph_offset < glyph_o_next)
	{
		int16 num_contours = read_big_endian (glyph_table->header.num_contours);
		
		if (num_contours > 0)
		{
//-			__int64 cycle_t0 = GetCycleCount ();
			this->DecompileSimpleCoordinates (info, num_contours, glyph_table);
//-			__int64 cycle_t1 = GetCycleCount ();
//-			Trace ("Time to decompile: %d cycles\n", (int) (cycle_t1 - cycle_t0));
		}
		else if (num_contours == -1)
		{
			this->DecompileComposite (glyph, info, glyph_table);
		}
	}
	
	return info;
}


int8u*
FontFace::Cache::TurboAlloc (int32u size)
{
	return this->heap.alloc (size);
}


bool
FontFace::Cache::DecompileComposite (int16u glyph, SizeInfo*& info, open_type::table_glyf* glyf)
{
	assert (info->glyph_flags == 0);
	assert (info->glyph_x == 0);
	assert (info->glyph_y == 0);
	assert (info->composites == 0);
	assert (info->composite_count == 0);
	
	open_type::table_glyf::Composite* compo = & glyf->u.composite;
	
	int num_elements = compo->CountElements ();
	
	FontFace::Cache::SizeInfo* elem = this->FindSizeInfo (compo->GlyphIndex ());
	
	info = this->glyph_sizes + glyph;
	
	assert (num_elements > 0);
	assert (elem != 0);
	
	int16u num_coord  = elem->num_coord;
	int8u* copy_flags = reinterpret_cast<int8u*> (this->TurboAlloc (num_coord * sizeof(int8u)));
	int16* copy_x     = reinterpret_cast<int16*> (this->TurboAlloc (num_coord * sizeof(int16)));
	int16* copy_y     = reinterpret_cast<int16*> (this->TurboAlloc (num_coord * sizeof(int16)));
	
	CompositeInfo* composites = (num_elements < 2) ? 0 : reinterpret_cast<CompositeInfo*> (this->TurboAlloc ((num_elements - 1) * sizeof(CompositeInfo)));
	
	info->num_coord   = num_coord;
	info->glyph_flags = copy_flags;	memcpy (info->glyph_flags, elem->glyph_flags, num_coord * sizeof(int8u));
	info->glyph_x     = copy_x;		memcpy (info->glyph_x,     elem->glyph_x,     num_coord * sizeof(int16));
	info->glyph_y     = copy_y;		memcpy (info->glyph_y,     elem->glyph_y,     num_coord * sizeof(int16));
	
	num_elements--;
	
	info->composites      = composites;
	info->composite_count = num_elements;
	
	compo = compo->NextComposite ();
	
	for (int i = 0; i < num_elements; i++)
	{
		assert (compo != 0);
		
		int16u flags = compo->Flags ();
		
		if ((flags & open_type::table_glyf::FLAG_ArgsAreXyValues) == 0)
		{
			Trace ("Glyph %d in %S %S does not specify [x] [y] offset, but points !\n", glyph, face->RetFamilyName (), face->RetStyleNameUserLocale ());
		}
#if _DEBUG
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
FontFace::Cache::DecompileSimpleCoordinates (SizeInfo* info, int16u num_contours, open_type::table_glyf* glyf)
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

FontFace::Cache::PixPerSize*
FontFace::Cache::FindPixPerSize (FontFace::Cache::SizeInfo* info, int32u size)
{
	if (info)
	{
		FontFace::Cache::PixPerSize** ptr = & info->pixel_head;
		FontFace::Cache::PixPerSize*  pps = *ptr;
		
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
		
		pps = reinterpret_cast<FontFace::Cache::PixPerSize*> (this->TurboAlloc (sizeof (FontFace::Cache::PixPerSize)));
		
		pps->data_head = 0;
		pps->next      = 0;
		pps->size      = size;
		
		*ptr = pps;
		
		return pps;
	}
	
	return 0;
}

FontFace::Cache::PixData*
FontFace::Cache::FindPixData (FontFace::Cache::SizeInfo* info, int32u size, int8u xs, int8u ys)
{
	FontFace::Cache::PixPerSize* pps = this->FindPixPerSize (info, size);
	
	if (pps)
	{
		FontFace::Cache::PixData** ptr = & pps->data_head;
		FontFace::Cache::PixData*  ppd = *ptr;
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
		
		ppd = reinterpret_cast<FontFace::Cache::PixData*> (this->TurboAlloc (sizeof (FontFace::Cache::PixData)));
		
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
