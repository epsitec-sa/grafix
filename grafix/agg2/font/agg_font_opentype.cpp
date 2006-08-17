/*
 *	agg_font_opentype.cpp
 *
 *	OpenType support.
 *
 *	(C) Copyright 2002-2006, Pierre ARNAUD, OPaC bright ideas, Ch. du Fontenay 6,
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

#include "agg_font_opentype.h"

#include <string.h>

using namespace agg;

/*****************************************************************************/

/*
 *	compiler_pack_check_assertion
 *
 *	Make sure the following line compiles without trouble. If the compiler
 *	chokes on it, this means that the "#pragma pack" directive in agg_font_opentype.h
 *	was not properly handled by the compiler. Fix agg_font_opentype.h in order to make
 *	sure that all structs get packed as tightly as possible.
 */
typedef int compiler_pack_check_assertion[(sizeof(agg::open_type::compiler_pack_check)==4) ? 1 : -1];

/*****************************************************************************/

void*
open_type::table_directory::FindTable (const char* name)
{
	int8u* base = reinterpret_cast<int8u*> (this);
	int16u num  = read_big_endian (this->num_tables);
	
	for (int16u i = 0; i < num; i++)
	{
		if (strncmp (this->entries[i].tag, name, 4) == 0)
		{
			return base + read_big_endian (this->entries[i].offset);
		}
	}
	
	return 0;
}

int32u
open_type::table_directory::FindMaxTableEnd ()
{
	int32u max  = 0;
//	int8u* base = reinterpret_cast<int8u*> (this);
	int16u num  = read_big_endian (this->num_tables);
	
	for (int16u i = 0; i < num; i++)
	{
		int32u begin  = read_big_endian (this->entries[i].offset);
		int32u length = read_big_endian (this->entries[i].length);
		int32u end    = begin + length;
		
		if (end > max)
		{
			max = end;
		}
	}
	
	return max;
}

open_type::table_cmap::Encoding*
open_type::table_cmap::FindTable (int16u platform,
								 int16u encoding_id,
								 int16u format_id)
{
	int8u* base = reinterpret_cast<int8u*> (this);
	int16u num  = read_big_endian (this->num_sub_table);
	
	for (int16u i = 0; i < num; i++)
	{
		if ( (read_big_endian (this->table_head[i].platform) == platform)
		  && (read_big_endian (this->table_head[i].encoding_id) == encoding_id) )
		{
			Encoding* encoding = reinterpret_cast<Encoding*> (base + read_big_endian (this->table_head[i].table_offset));
			
			if (read_big_endian (encoding->format) == format_id)
			{
				return encoding;
			}
		}
	}
	
	return 0;
}

open_type::table_cmap::EncodingFmt4*
open_type::table_cmap::FindUnicodeTable ()
{
	open_type::table_cmap::EncodingFmt4* fmt4_1 = reinterpret_cast<EncodingFmt4*> (this->FindTable (3, 1, 4));	//	Unicode
	open_type::table_cmap::EncodingFmt4* fmt4_0 = reinterpret_cast<EncodingFmt4*> (this->FindTable (3, 0, 4));	//	Symbol
	
	if (fmt4_1) return fmt4_1;
	if (fmt4_0) return fmt4_0;
	
	return 0;
}

open_type::table_cmap::EncodingFmt12*
open_type::table_cmap::FindUCS4Table ()
{
	return reinterpret_cast<EncodingFmt12*> (this->FindTable (3, 1, 12));
}

const int16u*
open_type::table_cmap::EncodingFmt4::RetStartCode () const
{
	const int8u* record = reinterpret_cast<const int8u*> (& this->end_code[0]);
	record += read_big_endian (this->seg_count_x_2);	//	skip end_code
	record += 2;							//	skip reserved pad
	return reinterpret_cast<const int16u*> (record);
}

const int16*
open_type::table_cmap::EncodingFmt4::RetIDDelta () const
{
	const int8u* record = reinterpret_cast<const int8u*> (& this->end_code[0]);
	record += read_big_endian (this->seg_count_x_2);	//	skip end_code
	record += 2;							//	skip reserved pad
	record += read_big_endian (this->seg_count_x_2);	//	skip start_code
	return reinterpret_cast<const int16*> (record);
}

const int16u*
open_type::table_cmap::EncodingFmt4::RetIDRangeOffset () const
{
	const int8u* record = reinterpret_cast<const int8u*> (& this->end_code[0]);
	record += read_big_endian (this->seg_count_x_2);	//	skip end_code
	record += 2;							//	skip reserved pad
	record += read_big_endian (this->seg_count_x_2);	//	skip start_code
	record += read_big_endian (this->seg_count_x_2);	//	skip id_delta
	return reinterpret_cast<const int16u*> (record);
}

const int16u*
open_type::table_cmap::EncodingFmt4::RetGlyphIDArray () const
{
	const int8u* record = reinterpret_cast<const int8u*> (& this->end_code[0]);
	record += read_big_endian (this->seg_count_x_2);	//	skip end_code
	record += 2;							//	skip reserved pad
	record += read_big_endian (this->seg_count_x_2);	//	skip start_code
	record += read_big_endian (this->seg_count_x_2);	//	skip id_delta
	record += read_big_endian (this->seg_count_x_2);	//	skip id_range_offset
	return reinterpret_cast<const int16u*> (record);
}


int16u
open_type::table_cmap::EncodingFmt4::FindGlyphIndex (int16u code) const
{
	int16u max = read_big_endian (this->seg_count_x_2) / 2;
	
	const int16u* end_code   = this->end_code;
	const int16u* start_code = this->RetStartCode ();
	
	for (int16u i = 0; i < max; i++)
	{
		if (read_big_endian (end_code[i]) >= code)
		{
			if (read_big_endian (start_code[i]) <= code)
			{
				const int16*  id_delta        = this->RetIDDelta ();
				const int16u* id_range_offset = this->RetIDRangeOffset ();
//				const int16u* id_glyph_array  = this->RetGlyphIDArray ();
				
				int16u swapped_id_range_offset = read_big_endian (id_range_offset[i]);
				int16u index = 0;
				
				if (swapped_id_range_offset != 0)
				{
					index = read_big_endian (*(&id_range_offset[i] + swapped_id_range_offset/2 + code - read_big_endian (start_code[i])));
					if (index)
					{
						index += read_big_endian (id_delta[i]);
					}
				}
				else
				{
					index = read_big_endian (id_delta[i]) + code;
				}
				index &= 0xffff;
				return index;
			}
			else
			{
				return 0;
			}
		}
	}
	
	throw "FindGlyphIndex failure";
}

int32u
open_type::table_cmap::EncodingFmt12::FindGlyphIndex (int32u code) const
{
	int32u max = read_big_endian (this->n_groups);
	for (int32u i = 0; i < max; i++)
	{
		if (code <= read_big_endian (this->groups[i].end_char_code))
		{
			if (code >= read_big_endian (this->groups[i].start_char_code))
			{
				return code - read_big_endian (this->groups[i].start_char_code)
							+ read_big_endian (this->groups[i].start_glyph_id);
			}
			
			return 0;
		}
	}
	
	throw "FindFlyphIndex failure";
}

/*****************************************************************************/

size_t
open_type::table_name::RetUnicodeLength (int16u language_id,
										 NameID name_id,
										 PlatformID platform_id) const
{
	int16u num = read_big_endian (this->num_name_records);
	
	const int16u swp_encoding = read_big_endian (static_cast<int16u> (1));
	const int16u swp_platform = read_big_endian (static_cast<int16u> (platform_id));
	const int16u swp_lang_id  = read_big_endian (language_id);
	const int16u swp_name_id  = read_big_endian (static_cast<int16u> (name_id));

	for (int16u i = 0; i < num; i++)
	{
		if ( (this->record_head[i].platform_id == swp_platform)
		  && (this->record_head[i].encoding_id == swp_encoding)
		  && (this->record_head[i].language_id == swp_lang_id)
		  && (this->record_head[i].name_id == swp_name_id) )
		{
			return read_big_endian (this->record_head[i].string_length) / 2 + 1;
		}
	}
	
	return language_id ? this->RetUnicodeLength (0, name_id, platform_id) : 0;
}

bool
open_type::table_name::GetUnicodeName (int16u language_id,
									   NameID name_id,
									   PlatformID platform_id,
									   wchar_t* buffer,
									   size_t max) const
{
	int16u num = read_big_endian (this->num_name_records);
	
	const int16u swp_encoding = read_big_endian (static_cast<int16u> (1));
	const int16u swp_platform = read_big_endian (static_cast<int16u> (platform_id));
	const int16u swp_lang_id  = read_big_endian (language_id);
	const int16u swp_name_id  = read_big_endian (static_cast<int16u> (name_id));
	
	for (int16u i = 0; i < num; i++)
	{
		if ( (this->record_head[i].platform_id == swp_platform)
		  && (this->record_head[i].encoding_id == swp_encoding)
		  && (this->record_head[i].language_id == swp_lang_id)
		  && (this->record_head[i].name_id == swp_name_id) )
		{
			const int8u* raw = reinterpret_cast<const int8u*> (this);
			
			raw += read_big_endian (this->storage_area_offset);
			raw += read_big_endian (this->record_head[i].string_offset);
			
			int16u        num_char = read_big_endian (this->record_head[i].string_length) / 2;
			const int16u* name     = reinterpret_cast<const int16u*> (raw);
			
			if (num_char >= max)
			{
				num_char = static_cast<int16u> (max-1);
			}
			
			for (int16u j = 0; j < num_char; j++)
			{
				buffer[j] = read_big_endian (name[j]);
			}
			
			buffer[num_char] = 0;
			
			return true;
		}
	}
	
	return language_id ? this->GetUnicodeName (0, name_id, platform_id, buffer, max) : false;
}

size_t
open_type::table_name::RetLatinLength (int16u language_id,
									   NameID name_id,
									   PlatformID platform_id) const
{
	int16u num = read_big_endian (this->num_name_records);
	
	const int16u swp_encoding = read_big_endian (static_cast<int16u> (0));
	const int16u swp_platform = read_big_endian (static_cast<int16u> (platform_id));
	const int16u swp_lang_id  = read_big_endian (language_id);
	const int16u swp_name_id  = read_big_endian (static_cast<int16u> (name_id));

	for (int16u i = 0; i < num; i++)
	{
		if ( (this->record_head[i].platform_id == swp_platform)
		  && (this->record_head[i].encoding_id == swp_encoding)
		  && (this->record_head[i].language_id == swp_lang_id)
		  && (this->record_head[i].name_id == swp_name_id) )
		{
			return read_big_endian (this->record_head[i].string_length) + 1;
		}
	}
	
	return language_id ? this->RetLatinLength (0, name_id, platform_id) : 0;
}

bool
open_type::table_name::GetLatinName (int16u language_id,
									 NameID name_id,
									 PlatformID platform_id,
									 wchar_t* buffer,
									 size_t max) const
{
	int16u num = read_big_endian (this->num_name_records);
	
	const int16u swp_encoding = read_big_endian (static_cast<int16u> (0));
	const int16u swp_platform = read_big_endian (static_cast<int16u> (platform_id));
	const int16u swp_lang_id  = read_big_endian (language_id);
	const int16u swp_name_id  = read_big_endian (static_cast<int16u> (name_id));
	
	for (int16u i = 0; i < num; i++)
	{
		if ( (this->record_head[i].platform_id == swp_platform)
		  && (this->record_head[i].encoding_id == swp_encoding)
		  && (this->record_head[i].language_id == swp_lang_id)
		  && (this->record_head[i].name_id == swp_name_id) )
		{
			const int8u* raw = reinterpret_cast<const int8u*> (this);
			
			raw += read_big_endian (this->storage_area_offset);
			raw += read_big_endian (this->record_head[i].string_offset);
			
			int16u       num_char = read_big_endian (this->record_head[i].string_length);
			const int8u* name     = reinterpret_cast<const int8u*> (raw);
			
			if (num_char >= max)
			{
				num_char = static_cast<int16u> (max-1);
			}
			
			for (int16u j = 0; j < num_char; j++)
			{
				buffer[j] = name[j];
			}
			
			buffer[num_char] = 0;
			
			return true;
		}
	}
	
	return language_id ? this->GetLatinName (0, name_id, platform_id, buffer, max) : false;
}

const int16*
open_type::table_hmtx::RetLeftSideBearing (int16u number_of_H_metrics) const
{
	return reinterpret_cast<const int16*> (& this->hor_metrics[number_of_H_metrics]);
}

bool
open_type::GetGlyphWidths (const open_type::table_maxp* maxp,
						  const open_type::table_hhea* hhea,
						  const open_type::table_hmtx* hmtx,
						  int32u glyph,
						  int16 & lsb, int16 & advance)
{
	int16u number_of_glyphs    = read_big_endian (maxp->num_glyphs);
	int16u number_of_H_metrics = read_big_endian (hhea->number_of_H_metrics);
	
	if (glyph < number_of_glyphs)
	{
		if (glyph < number_of_H_metrics)
		{
			advance = hmtx->hor_metrics[glyph].advance_width;
			lsb     = hmtx->hor_metrics[glyph].left_side_bearing;
		}
		else
		{
			advance = hmtx->hor_metrics[number_of_H_metrics-1].advance_width;
			lsb     = hmtx->RetLeftSideBearing (number_of_H_metrics) [glyph - number_of_H_metrics];
		}
		
		advance = read_big_endian (advance);
		lsb     = read_big_endian (lsb);
//		rsb     = advance - (lsb + xmax - xmin);
		
		return true;
	}
	
	return false;
}

const open_type::script_table*
open_type::script_list::RetTable (int16u nth) const
{
	int16u number_of_recs = read_big_endian (this->script_count);
	
	if (nth < number_of_recs)
	{
		const int8u* base  = reinterpret_cast<const int8u*> (this);
		const int8u* table = base + read_big_endian (this->script_records[nth].script_table);
		
		return reinterpret_cast<const open_type::script_table*> (table);
	}
	
	return 0;
}

const open_type::script_table*
open_type::script_list::RetTable (const char* tag) const
{
	int16u number_of_recs = read_big_endian (this->script_count);
	
	for (int16u nth = 0; nth < number_of_recs; nth++)
	{
		const char* ref = this->script_records[nth].script_tag;
		
		if ( (ref[0] == tag[0])
		  && (ref[1] == tag[1])
		  && (ref[2] == tag[2])
		  && (ref[3] == tag[3]) )
		{
			const int8u* base  = reinterpret_cast<const int8u*> (this);
			const int8u* table = base + read_big_endian (this->script_records[nth].script_table);
			
			return reinterpret_cast<const open_type::script_table*> (table);
		}
	}
	
	return 0;
}


const open_type::lang_sys_table*
open_type::script_table::RetTable () const
{
	if (this->default_lang_sys)
	{
		const int8u* base  = reinterpret_cast<const int8u*> (this);
		const int8u* table = base + read_big_endian (this->default_lang_sys);
		
		return reinterpret_cast<const open_type::lang_sys_table*> (table);
	}
	
	return 0;
}

const open_type::lang_sys_table*
open_type::script_table::RetTable (int16u nth) const
{
	int16u number_of_recs = read_big_endian (this->lang_sys_count);
	
	if (nth < number_of_recs)
	{
		const int8u* base  = reinterpret_cast<const int8u*> (this);
		const int8u* table = base + read_big_endian (this->lang_sys_records[nth].lang_sys_table);
		
		return reinterpret_cast<const open_type::lang_sys_table*> (table);
	}
	
	return 0;
}

const open_type::lang_sys_table*
open_type::script_table::RetTable (const char* tag) const
{
	int16u number_of_recs = read_big_endian (this->lang_sys_count);
	
	for (int16u nth = 0; nth < number_of_recs; nth++)
	{
		const char* ref = this->lang_sys_records[nth].lang_sys_tag;
		
		if ( (ref[0] == tag[0])
		  && (ref[1] == tag[1])
		  && (ref[2] == tag[2])
		  && (ref[3] == tag[3]) )
		{
			const int8u* base  = reinterpret_cast<const int8u*> (this);
			const int8u* table = base + read_big_endian (this->lang_sys_records[nth].lang_sys_table);
			
			return reinterpret_cast<const open_type::lang_sys_table*> (table);
		}
	}
	
	return 0;
}


int16u
open_type::feature_table::RetCount () const
{
	return read_big_endian (this->lookup_count);
}

int16u
open_type::feature_table::RetIndex (int16u i) const
{
	return read_big_endian (this->lookup_index[i]);
}


const open_type::feature_table*
open_type::feature_list::RetTable (int16u nth) const
{
	int16u number_of_recs = read_big_endian (this->feature_count);
	
	if (nth < number_of_recs)
	{
		const int8u* base  = reinterpret_cast<const int8u*> (this);
		const int8u* table = base + read_big_endian (this->feature_records[nth].feature_table);
		
		return reinterpret_cast<const open_type::feature_table*> (table);
	}
	
	return 0;
}

const open_type::feature_table*
open_type::feature_list::RetTable (const char* tag) const
{
	int16u number_of_recs = read_big_endian (this->feature_count);
	
	for (int16u nth = 0; nth < number_of_recs; nth++)
	{
		const char* ref = this->feature_records[nth].feature_tag;
		
		if ( (ref[0] == tag[0])
		  && (ref[1] == tag[1])
		  && (ref[2] == tag[2])
		  && (ref[3] == tag[3]) )
		{
			const int8u* base  = reinterpret_cast<const int8u*> (this);
			const int8u* table = base + read_big_endian (this->feature_records[nth].feature_table);
			
			return reinterpret_cast<const open_type::feature_table*> (table);
		}
	}
	
	return 0;
}


const open_type::lookup_table*
open_type::lookup_list::RetTable (int16u nth) const
{
	int16u number_of_tables = read_big_endian (this->lookup_count);
	
	if (nth < number_of_tables)
	{
		const int8u* base  = reinterpret_cast<const int8u*> (this);
		const int8u* table = base + read_big_endian (this->lookup_offsets[nth]);
		
		return reinterpret_cast<const open_type::lookup_table*> (table);
	}
	
	return 0;
}

open_type::lookup_table::GSUB_Type
open_type::lookup_table::RetLookupType () const
{
	return static_cast<open_type::lookup_table::GSUB_Type> (read_big_endian (this->lookup_type));
}

bool
open_type::lookup_table::TestLookupFlag (open_type::lookup_table::Flags flag) const
{
	return (read_big_endian (this->lookup_flags) & flag) ? true : false;
}

int16u
open_type::lookup_table::RetSubTableCount () const
{
	return read_big_endian (this->sub_table_count);
}

const int8u*
open_type::lookup_table::RetSubTable (int16u nth) const
{
	int16u number_of_tables = read_big_endian (this->sub_table_count);
	
	if (nth < number_of_tables)
	{
		const int8u* base  = reinterpret_cast<const int8u*> (this);
		const int8u* table = base + read_big_endian (this->sub_table_offsets[nth]);
		
		return table;
	}
	
	return 0;
}

bool
open_type::coverage_table::IsGlyphInCoverageTable (int16u glyph) const
{
	int16u coverage_index;
	return this->IsGlyphInCoverageTable (glyph, coverage_index);
}

bool
open_type::coverage_table::IsGlyphInCoverageTable (int16u glyph, int16u & coverage_index) const
{
	int16u format = read_big_endian (this->coverage_format);
	int16u count  = read_big_endian (this->coverage_count);
	
	switch (format)
	{
		case FORMAT_GlyphIndices:
			for (int16u i = 0; i < count; i++)
			{
				if (read_big_endian (this->u.glyph_array[i]) == glyph)
				{
					coverage_index = i;
					return true;
				}
			}
			break;
		case FORMAT_GlyphRanges:
			for (int16u i = 0; i < count; i++) {
				
				int16u start = read_big_endian (this->u.glyph_range[i].start);
				int16u end   = read_big_endian (this->u.glyph_range[i].end);
				
				if ( (glyph >= start)
				  && (glyph <= end) )
				{
					coverage_index = read_big_endian (this->u.glyph_range[i].start_coverage_index) + glyph - start;
					return true;
				}
			}
			break;
	}
	
	return false;
}

const open_type::script_list*
open_type::table_GSUB::RetScriptList () const
{
	const int8u* base  = reinterpret_cast<const int8u*> (this);
	const int8u* table = base + read_big_endian (this->script_list_offset);
	return reinterpret_cast<const open_type::script_list*> (table);
}

const open_type::feature_list*
open_type::table_GSUB::RetFeatureList () const
{
	const int8u* base  = reinterpret_cast<const int8u*> (this);
	const int8u* table = base + read_big_endian (this->feature_list_offset);
	return reinterpret_cast<const open_type::feature_list*> (table);
}

const open_type::lookup_list*
open_type::table_GSUB::RetLookupList () const
{
	const int8u* base  = reinterpret_cast<const int8u*> (this);
	const int8u* table = base + read_big_endian (this->lookup_list_offset);
	return reinterpret_cast<const open_type::lookup_list*> (table);
}


const open_type::coverage_table*
open_type::lookup_table::SingleSubst::RetTable () const
{
	const int8u* base  = reinterpret_cast<const int8u*> (this);
	const int8u* table = base + read_big_endian (this->coverage);
	return reinterpret_cast<const open_type::coverage_table*> (table);
}

bool
open_type::lookup_table::SingleSubst::PerformSubstitution (int16u & glyph) const
{
	int16u coverage_index;
	
	switch (read_big_endian (this->subst_format))
	{
		case 1:
			if (this->RetTable ()->IsGlyphInCoverageTable (glyph))
			{
				glyph += read_big_endian (this->delta_glyph_id);
				return true;
			}
			break;
		
		case 2:
			if ( (this->RetTable ()->IsGlyphInCoverageTable (glyph, coverage_index))
			  && (coverage_index < read_big_endian (this->glyph_count)) )
			{
				glyph = read_big_endian (this->substitutes[coverage_index]);
				return true;
			}
			break;
	}
	
	return false;
}

const open_type::ligature_table*
open_type::ligature_set_table::RetTable (int16u nth) const
{
	int16u number_of_tables = read_big_endian (this->ligature_count);
	
	if (nth < number_of_tables)
	{
		const int8u* base  = reinterpret_cast<const int8u*> (this);
		const int8u* table = base + read_big_endian (this->ligatures[nth]);
		
		return reinterpret_cast<const open_type::ligature_table*> (table);
	}
	
	return 0;
}

const open_type::ligature_set_table*
open_type::ligature_subst::RetLigatureSetTable (int16u nth) const
{
	int16u number_of_tables = read_big_endian (this->ligature_set_count);
	
	if (nth < number_of_tables)
	{
		const int8u* base  = reinterpret_cast<const int8u*> (this);
		const int8u* table = base + read_big_endian (this->ligature_sets[nth]);
		
		return reinterpret_cast<const open_type::ligature_set_table*> (table);
	}
	
	return 0;
}

const open_type::coverage_table*
open_type::ligature_subst::RetCoverageTable () const
{
	const int8u* base  = reinterpret_cast<const int8u*> (this);
	const int8u* table = base + read_big_endian (this->coverage);
	return reinterpret_cast<const open_type::coverage_table*> (table);
}

bool
open_type::ligature_subst::PerformSubstitution (const int16u* glyphs, int16u& glyph, int16u& skip) const
{
	int16u coverage_index;
	
	glyph = glyphs[0];
	skip  = 1;
	
	if ( (this->RetCoverageTable ()->IsGlyphInCoverageTable (glyphs[0], coverage_index))
	  && (coverage_index < read_big_endian (this->ligature_set_count)) )
	{
		const ligature_set_table* set = this->RetLigatureSetTable (coverage_index);
		int16u set_count = read_big_endian (set->ligature_count);
		
		for (int16u i = 0; i < set_count; i++)
		{
			const ligature_table* ligature = set->RetTable (i);
			
			int16u comp_count = read_big_endian (ligature->comp_count) - 1;
			int16u j = 0;
			
			while (j < comp_count)
			{
				if (read_big_endian (ligature->components[j]) != glyphs[j+1])
				{
					break;
				}
				j++;
			}
			
			if (j == comp_count)
			{
				glyph = read_big_endian (ligature->lig_glyph);
				skip  = comp_count + 1;
				return true;
			}
		}
	}
	
	return false;
}

/*****************************************************************************/

int32u
open_type::table_loca::FindOffsetShort (int16u glyph) const
{
	return read_big_endian (this->u.offsets_short[glyph]) * 2;
}

int32u
open_type::table_loca::FindOffsetLong (int16u glyph) const
{
	return read_big_endian (this->u.offsets_long[glyph]);
}

/*****************************************************************************/

