/*
 *	agg_font_opentype.h
 *
 *	OpenType definitions.
 *
 *	Note: not all tables defined here are still used by the project.
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

#ifndef AGG_OPENTYPE_INCLUDED
#define AGG_OPENTYPE_INCLUDED

#include "agg_read_big_endian.h"
#include <memory.h>

/*****************************************************************************/

#pragma pack(push, 1)

namespace agg
{
	namespace open_type
	{
		typedef int16u		FWord;			//	16-bit signed integer in FUnits
		typedef int32u		Fixed;			//	16.16-bit signed fixed-point number
		typedef int16u		Offset;
		
		
		struct table_entry
		{
			char			tag[4];
			int32u			checksum;
			int32u			offset;
			int32u			length;
		};
		
		struct table_ttc_header
		{
			char			tag[4];
			int32u			version;
			int32u			num_fonts;
			int32u			offset_table[1];
		};
		
		struct table_directory
		{
			Fixed			sfnt_version;
			int16u			num_tables;
			int16u			search_range;
			int16u			entry_selector;
			int16u			range_shift;
			table_entry		entries[1];
			
			void* FindTable (void* base, const char* name);
			int32u FindMaxTableEnd ();
		};

		
		struct table_head
		{
			Fixed			table_version;
			Fixed			font_revision;
			int32u			checksum_adjustment;
			int32u			magic_number;
			int16u			flags;
			int16u			units_per_em;
			int32u			created_h;
			int32u			created_l;
			int32u			modified_h;
			int32u			modified_l;
			FWord			x_min;
			FWord			y_min;
			FWord			x_max;
			FWord			y_max;
			int16u			mac_style;
			int16u			lowest_rec_ppem;
			int16			font_direction_hint;
			int16			index_to_loc_format;		//	0 => table_loca_short, 1 => table_loca_long
			int16			glyph_data_format;			//	0
		};
		
		struct table_glyf		//	for TrueType glyph definitions
		{
			struct GlyfHeader
			{
				int16			num_contours;			//	-1 => composite
				int16			x_min;
				int16			y_min;
				int16			x_max;
				int16			y_max;
			};	
			
			struct Simple
			{
				int16u			end_pts_of_contour[1];
				
				const GlyfHeader* Header () const				{ return reinterpret_cast<const table_glyf::GlyfHeader*> (this) - 1; }
				int16u			InstructionLength () const		{ return read_big_endian (this->end_pts_of_contour[read_big_endian (this->Header ()->num_contours) + 0]); }
				const int8u*	Instructions () const			{ return reinterpret_cast<const int8u*> (this->end_pts_of_contour + read_big_endian (this->Header ()->num_contours) + 1); }
				const int8u*	Flags () const					{ return this->Instructions () + this->InstructionLength (); }
				int16u			NumCoordinates () const			{ return read_big_endian (this->end_pts_of_contour[read_big_endian (this->Header ()->num_contours) - 1]) + 1; }
				int16u			NumContours () const			{ return static_cast<int16u> (read_big_endian (this->Header ()->num_contours)); }
			};
			
			enum SimpleFlags
			{
				FLAG_OnCurve	= 0x01,
				FLAG_xShort		= 0x02,
				FLAG_yShort		= 0x04,
				FLAG_Repeat		= 0x08,
				FLAG_xSame		= 0x10,			//	xShort=1, xSame=1 => (+)			/ xSame=0 => (-)
				FLAG_ySame		= 0x20,			//	xShort=0, xSame=1 => repeat last x	/ xSame=0 => signed
			};
			
			struct Composite
			{
				int16u			flags;
				int16u			glyph_index;

				union
				{
					struct
					{
						int8	arg1_byte;
						int8	arg2_byte;
					} s1;
					struct
					{
						int16	arg1_word;
						int16	arg2_word;
					} s2;
				} u;
				
				int16u				Flags () const
				{
					return read_big_endian (this->flags);
				}
				
				int16u				GlyphIndex () const
				{
					return read_big_endian (this->glyph_index);
				}
				
				Composite*			NextComposite()
				{
					int16u fl = read_big_endian (this->flags);
					
					if (fl & FLAG_MoreComponents)
					{
						int len = 2 + 2;
						len += (fl & FLAG_ArgsAreWords) ?     4 : 2;
						len += (fl & FLAG_SimpleScale) ?      2 : 0;
						len += (fl & FLAG_ScaleXyDifferent) ? 4 : 0;
						len += (fl & FLAG_Scale2x2) ?         8 : 0;
						
						int8u* ptr = reinterpret_cast<int8u*> (this);
						
						return reinterpret_cast<Composite*> (ptr + len);
					}
					
					return 0;
				}
				
				int					CountElements()
				{
					int n = 0;
					Composite* next = this;
					
					while (next)
					{
						next = next->NextComposite ();
						n++;
					}
					
					return n;
				}
				
				void				GetOffsetXandY(int16& ox, int16& oy) const
				{
					int16u fl = read_big_endian (this->flags);
					
					if (fl & FLAG_ArgsAreWords)
					{
						ox = read_big_endian (this->u.s2.arg1_word);
						oy = read_big_endian (this->u.s2.arg2_word);
					}
					else
					{
						ox = this->u.s1.arg1_byte;
						oy = this->u.s1.arg2_byte;
					}
				}
				
				void				GetPointNumbers(FWord& a1, FWord& a2) const
				{
					int16u fl = read_big_endian (this->flags);
					
					if (fl & FLAG_ArgsAreWords)
					{
						a1 = read_big_endian (this->u.s2.arg1_word);
						a2 = read_big_endian (this->u.s2.arg2_word);
					}
					else
					{
						a1 = this->u.s1.arg1_byte & 0x00ff;
						a2 = this->u.s1.arg2_byte & 0x00ff;
					}
				}
				
				void				GetMatrix(double& xx, double& xy, double& yx, double& yy) const
				{
					xx = 1; xy = 0; yx = 0; yy = 1;
					
					int16u fl = read_big_endian (this->flags);
					const int16* ptr;
					
					if (fl & FLAG_ArgsAreWords)
					{
						ptr = & this->u.s2.arg1_word + 2;
					}
					else
					{
						ptr = & this->u.s2.arg2_word;
					}
					
					if (fl & FLAG_SimpleScale)
					{
						xx = yy = (1.0 * read_big_endian (ptr[0])) / (1 << 14);
					}
					else if (fl & FLAG_ScaleXyDifferent)
					{
						xx = (1.0 * read_big_endian (ptr[0])) / (1 << 14);
						yy = (1.0 * read_big_endian (ptr[1])) / (1 << 14);
					}
					else if (fl & FLAG_Scale2x2)
					{
						xx = (1.0 * read_big_endian (ptr[0])) / (1 << 14);
						xy = (1.0 * read_big_endian (ptr[1])) / (1 << 14);
						yx = (1.0 * read_big_endian (ptr[2])) / (1 << 14);
						yy = (1.0 * read_big_endian (ptr[3])) / (1 << 14);
					}
				}

			};
			
			enum CompositeFlags
			{
				FLAG_ArgsAreWords		= 0x0001,
				FLAG_ArgsAreXyValues	= 0x0002,
				FLAG_RoundXyToGrid		= 0x0004,
				FLAG_SimpleScale		= 0x0008,
				FLAG_MoreComponents		= 0x0020,
				FLAG_ScaleXyDifferent	= 0x0040,
				FLAG_Scale2x2			= 0x0080,
				FLAG_Instructions		= 0x0100,
				FLAG_UseMyMetrics		= 0x0200,
				FLAG_OverlapCompound	= 0x0400,
				FLAG_ScaledOffset		= 0x0800,
				FLAG_UnscaledOffset		= 0x1000,
			};
			
			GlyfHeader			header;
			
			union
			{
				Simple			simple;
				Composite		composite;
			} u;

			table_glyf* FindSubTable (int32u offset)	{ return reinterpret_cast<table_glyf*> (reinterpret_cast<int8u*> (this) + offset); }
		};
		
		struct table_loca	//	for TrueType index to location mapping
		{
			union
			{
				int16u		offsets_short[1];
				int32u		offsets_long[1];
			} u;
			
			int32u FindOffsetShort (int16u glyph) const;
			int32u FindOffsetLong (int16u glyph) const;
			
			int32u FindOffset (int16u glyph, const table_head* head) const	{ return (head->index_to_loc_format == 0) ? this->FindOffsetShort (glyph) : this->FindOffsetLong (glyph); }
		};
		
		struct table_maxp
		{
			Fixed			table_version;
			int16u			num_glyphs;
			int16u			max_points;
			int16u			max_contours;
			int16u			max_composite_points;
			int16u			max_composite_contours;
			int16u			max_zones;
			int16u			max_twilight_points;
			int16u			max_storage;
			int16u			max_function_defs;
			int16u			max_instruction_defs;
			int16u			max_stack_elements;
			int16u			max_size_of_instructions;
			int16u			max_component_elements;
			int16u			max_component_depth;
		};

		
		struct table_cmap
		{
			struct Submap
			{
				int16u		platform;
				int16u		encoding_id;
				int32u		table_offset;
			};
			
			struct Encoding
			{
				int16u		format;
				int16u		length;
			};
			
			struct EncodingFmt0 : Encoding
			{
				int16u		language;			//	Mac specific
				int8u		map[1];
			};
			
			struct EncodingFmt4 : Encoding
			{
				int16u		language;			//	always zero
				int16u		seg_count_x_2;
				int16u		search_range;
				int16u		entry_selector;
				int16u		range_shift;
				int16u		end_code[1];
				
				const int16u* RetStartCode () const;
				const int16* RetIDDelta () const;
				const int16u* RetIDRangeOffset () const;
				const int16u* RetGlyphIDArray () const;
				
				int16u FindGlyphIndex (int16u code) const;
			};
			
			struct EncodingFmt12 : Encoding
			{
				struct Group
				{
					int32u	start_char_code;
					int32u	end_char_code;
					int32u	start_glyph_id;
				};
				
				int32u		length;
				int32u		language;			//	Mac specific
				int32u		n_groups;
				
				Group		groups[1];
				
				int32u FindGlyphIndex (int32u code) const;
			};
			
			int16u			table_version;
			int16u			num_sub_table;
			Submap			table_head[1];
			
			open_type::table_cmap::Encoding* FindTable (int16u platform, int16u encoding_id, int16u format_id);
			open_type::table_cmap::EncodingFmt4* FindUnicodeTable ();
			open_type::table_cmap::EncodingFmt12* FindUCS4Table ();
			
			static const int16u UNKNOWN_GLYPH = 0x0000;
			static const int16u NO_GLYPH      = 0xffff;
		};

		
		enum PlatformID
		{
			PLATFORM_Unicode = 0,
			PLATFORM_Macintosh = 1,
			PLATFORM_Microsoft = 3,
			PLATFORM_Custom = 4,
		};
		
		struct table_name
		{
			enum NameID
			{
				NAME_CopyrightNotice,
				NAME_FontFamily,				//	"Futura Lt BT"
				NAME_FontSubfamily,				//	"Light Italic"
				NAME_UniqueFontIdentifier,		//	"Futura Light Italic, Geometric 211"
				NAME_FullFontName,				//	"Futura Lt BT Light Italic"
				NAME_Version,					//	"Version 2.001 mfgpctt 4.4"
				NAME_PostScriptName,			//	"FuturaBT-LightItalic"
				NAME_Trademark,
				NAME_Manufacturer,
				NAME_Designer,
				NAME_Description,
				NAME_VendorURL,
				NAME_DesignerURL,
				NAME_License,
				NAME_LicenseURL,
				NAME_Reserved_0,
				NAME_PreferredFamily,
				NAME_PreferredSubfamily,
				NAME_Mac_CompatibleFull,
				NAME_SampleText,
				NAME_PostScriptCID,
			};
			
			struct NameRecord
			{
				int16u		platform_id;
				int16u		encoding_id;
				int16u		language_id;
				int16u		name_id;
				int16u		string_length;
				int16u		string_offset;
			};
			
			int16u			format_selector;
			int16u			num_name_records;
			int16u			storage_area_offset;
			NameRecord		record_head[1];
			
			size_t RetLatinLength (int16u language_id, NameID name_id, PlatformID platform_id) const;	//	length in characters, including terminal zero
			size_t RetUnicodeLength (int16u language_id, NameID name_id, PlatformID platform_id) const;	//	length in characters, including terminal zero
			
			bool GetLatinName (int16u language_id, NameID name_id, PlatformID platform_id, wchar_t* buffer, size_t max) const;
			bool GetUnicodeName (int16u language_id, NameID name_id, PlatformID platform_id, wchar_t* buffer, size_t max) const;
		};

		
		struct table_hhea
		{
			Fixed			table_version;
			int16			mac_ascender;
			int16			mac_descender;
			int16			mac_line_gap;
			int16u			advance_width_max;
			int16			min_left_side_bearing;
			int16			min_right_side_bearing;
			int16			x_max_extent;
			int16u			caret_slope_rise;
			int16u			caret_slope_run;
			int16u			caret_offset;
			int16u			reserved_0;
			int16u			reserved_1;
			int16u			reserved_2;
			int16u			reserved_3;
			int16u			metric_data_format;
			int16u			number_of_H_metrics;
		};
		
		struct table_hmtx
		{
			struct HorMetric
			{
				int16u		advance_width;
				int16		left_side_bearing;
			};
			
			HorMetric		hor_metrics[1];
			
			const int16* RetLeftSideBearing (int16u number_of_H_metrics) const;
		};
		
		struct table_GDEF
		{
			Fixed			version;
			Offset			glyph_class_def;
			Offset			attach_list;
			Offset			lig_caret_list;
			Offset			mark_attach_class_def;
			
			struct LigCaretList
			{
				Offset		coverage;
				int16u		lig_glyph_count;
				Offset		lig_glyph[1];
			};
			struct LigGlyph
			{
				int16u		caret_count;
				Offset		caret_value[1];
			};
			
			struct CaretValue
			{
				int16u		format;
			};
			
			struct CaretValueFmt1 : CaretValue
			{
				int16		coord;
			};
			struct CaretValueFmt2 : CaretValue
			{
				int16u		contour_point;
			};
			struct CaretValueFmt3 : CaretValue
			{
				int16		coord;
				Offset		device_table;
			};
		};
		
		
		struct coverage_table
		{
			enum Format
			{
				FORMAT_GlyphIndices			= 1,
				FORMAT_GlyphRanges			= 2
			};
			
			struct Range
			{
				int16u		start;
				int16u		end;
				int16u		start_coverage_index;
			};
			
			int16u			coverage_format;
			int16u			coverage_count;
			
			union
			{
				int16u		glyph_array[1];
				Range		glyph_range[1];
			} u;
			
			bool IsGlyphInCoverageTable (int16u glyph) const;
			bool IsGlyphInCoverageTable (int16u glyph, int16u & coverage_index) const;
		};
		
		
		struct ligature_table
		{
			int16u		lig_glyph;
			int16u		comp_count;
			int16u		components[1];
		};
		
		struct ligature_set_table
		{
			int16u		ligature_count;
			Offset		ligatures[1];
			
			const ligature_table* RetTable (int16u nth) const;
		};
		
		struct ligature_subst
		{
			int16u		subst_format;				//	1
			Offset		coverage;
			int16u		ligature_set_count;
			Offset		ligature_sets[1];
			
			const coverage_table* RetCoverageTable () const;
			const ligature_set_table* RetLigatureSetTable (int16u nth) const;
			bool PerformSubstitution (const int16u* glyphs, int16u& glyph, int16u& skip) const;
		};
		
		//	See http://www.microsoft.com/typography/otspec/GSUB.htm for GSUB table
		//	See http://www.microsoft.com/typography/otspec/chapter2.htm for the common table format
		//	See http://www.microsoft.com/typography/otspec/featurelist.htm for 'liga' and others.
		
		struct lookup_table
		{
			struct SingleSubst
			{
				int16u		subst_format;				//	1 or 2
				Offset		coverage;
				union
				{
				int16		delta_glyph_id;
				struct
				{
					int16u	glyph_count;
					int16u	substitutes[1];
				};
				};
				
				const coverage_table* RetTable () const;
				bool PerformSubstitution (int16u & glyph) const;
			};
			
			struct MultipleSubst
			{
			};
			struct AlternateSubst
			{
			};
			
			enum Flags
			{
				LOOKUP_RightToLeft			= 0x0001,
				LOOKUP_IgnoreBaseGlyphs		= 0x0002,
				LOOKUP_IgnoreLigatures		= 0x0004,
				LOOKUP_IgnoreMarks			= 0x0008,
				LOOKUP_MarkAttachmentType	= 0xFF00
			};
			
			enum GSUB_Type
			{
				GSUB_TYPE_Single			= 1,
				GSUB_TYPE_Multiple			= 2,
				GSUB_TYPE_Alternate			= 3,
				GSUB_TYPE_Ligature			= 4,
				GSUB_TYPE_Context			= 5,
				GSUB_TYPE_ChainingContext	= 6,
				GSUB_TYPE_ExtSubstitution	= 7,
				GSUB_TYPE_RevChCtxSingle	= 8,
			};
			
			int16u			lookup_type;
			int16u			lookup_flags;
			int16u			sub_table_count;
			Offset			sub_table_offsets[1];
			
			GSUB_Type RetLookupType () const;
			bool TestLookupFlag (Flags flag) const;
			int16u RetSubTableCount () const;
			const int8u* RetSubTable (int16u nth) const;
		};
		
		struct lookup_list
		{
			int16u			lookup_count;
			Offset			lookup_offsets[1];
			
			const lookup_table* RetTable (int16u nth) const;
		};
		
		struct feature_table
		{
			Offset			feature_params;				//	reserved
			int16u			lookup_count;
			int16u			lookup_index[1];
			
			int16u RetCount () const;
			int16u RetIndex (int16u i) const;
		};
		
		struct feature_list
		{
			struct Record
			{
				char		feature_tag[4];
				Offset		feature_table;
			};
			
			int16u			feature_count;
			Record			feature_records[1];
			
			const feature_table* RetTable (int16u nth) const;
			const feature_table* RetTable (const char* tag) const;
		};
		
		struct lang_sys_table
		{
			Offset			lookup_order;				//	reserved
			int16u			req_feature_index;
			int16u			feature_count;
			int16u			feature_index[1];
		};
		
		struct script_table
		{
			struct LangSysRecord
			{
				char		lang_sys_tag[4];
				Offset		lang_sys_table;
			};
			
			Offset			default_lang_sys;
			int16u			lang_sys_count;
			LangSysRecord	lang_sys_records[1];
			
			const lang_sys_table* RetTable () const;
			const lang_sys_table* RetTable (int16u nth) const;
			const lang_sys_table* RetTable (const char* tag) const;
		};
		
		struct script_list
		{
			struct Record
			{
				char		script_tag[4];
				Offset		script_table;
			};
			
			int16u			script_count;
			Record			script_records[1];
			
			const script_table* RetTable (int16u nth) const;
			const script_table* RetTable (const char* tag) const;
		};
		
		struct table_GSUB
		{
			Fixed			version;
			
			Offset			script_list_offset;
			Offset			feature_list_offset;
			Offset			lookup_list_offset;
			
			const script_list*  RetScriptList () const;
			const feature_list* RetFeatureList () const;
			const lookup_list*  RetLookupList () const;
		};
		
		
		extern bool GetGlyphWidths (const table_maxp* maxp, const table_hhea* hhea, const table_hmtx* hmtx, int32u glyph, int16 & lsb, int16 & advance);
		
		
		struct compiler_pack_check
		{
			int8u		a;
			int16u		b;
			int8u		c;
		};
	}
}

#pragma pack(pop)

/*****************************************************************************/

#endif /* AGG_OPENTYPE_INCLUDED */
