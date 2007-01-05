/*
 *	agg_font_face.h
 *
 *	The font_face class represents a font face, that is all data related to a
 *	"physical" font (glyphs, geometry, etc.)
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

#ifndef AGG_FONT_FACE_INCLUDED
#define AGG_FONT_FACE_INCLUDED

/*****************************************************************************/

#include "agg_turboheap.h"

/*****************************************************************************/

namespace agg
{
	namespace open_type
	{
		struct table_directory;
		
		struct table_GSUB;
		struct table_head;
		struct table_hhea;
		struct table_cmap;
		struct table_loca;
		struct table_glyf;
		struct table_maxp;
		struct table_hmtx;
		
		struct feature_list;
		struct feature_table;
		
		struct lookup_list;
		struct lookup_table;
		
		struct ligature_subst;
	}
	
/*****************************************************************************/
	
	class font_face
	{
		
	public:
		enum GlyphSubst
		{
			SUBST_NONE				= 0,
			SUBST_LIG_STANDARD		= 0x0001,
			SUBST_LIG_REQUIRED		= 0x0002,
			SUBST_LIG_DISCRETIONARY	= 0x0004,
			
			SUBST_LIG_LAST			= 0x0004,
			
			SUBST_LIG_ALL			= SUBST_LIG_STANDARD | SUBST_LIG_REQUIRED | SUBST_LIG_DISCRETIONARY,
		};
		
	public:
		struct cache_record
		{
			/*
			 *	The pix_data_record stores the coverage for a given glyph (this is the
			 *	"bitmap" cache).
			 */
			
			struct pix_data_record
			{
				pix_data_record*				next;
				int8u							x_shift;	//	horizontal sub-pixel offset
				int8u							y_shift;	//	vertical sub-pixel offset
				int16u							dx;
				int16u							dy;
				int16							ox;
				int16							oy;
				int8u*							pixels;
			};
			
			
			/*
			 *	The pix_per_size_record represents the head of a list of pix_data_record
			 *	instances for a given glyph at a given size.
			 */
			
			struct pix_per_size_record
			{
				pix_per_size_record*			next;
				int32u							size;
				pix_data_record*				data_head;
			};
			
			/*
			 *	The pix_data_record defines how and where to insert a glyph to build a
			 *	composite glyph (a composite usually merges several glyphs by offseting
			 *	and scaling them).
			 */
			
			struct composite_info_record
			{
				int16u							glyph;
				int16							ox, oy;
				double							xx, xy, yx, yy;
			};
			
			
			/*
			 *	The size_info_record gives access to the Open Type font data for a given
			 *	glyph. All sizes are expressed in internal font units.
			 */
			
			struct size_info_record
			{
				int16							x_min, x_max, y_min, y_max;
				int16							width_advance;
				int16							left_side_bearing;
				int16							mtx, mty;
				double							mxx, mxy, myx, myy;
				
				int16u							num_coord;
				int8u*							glyph_flags;			//	decompiled glyph path flags, from Open Type glyf table
				int16*							glyph_x;				//	decompiled [x] coordinates, from Open Type glyf table
				int16*							glyph_y;				//	decompiled [y] coordinates, from Open Type glyf table
				
				pix_per_size_record*			pixel_head;				//	list of cached pixels, per size/sub-pixel offset
				composite_info_record*			composites;				//	only for composite glyphs
				int16u							composite_count;
			};
			
			
			enum GlyphFlags
			{
				FLAG_NONE						= 0x00,
				FLAG_ON_CURVE					= 0x01,
				FLAG_CONTOUR_END				= 0x02,
			};
			
			font_face*							face;
			turbo_heap<32*1024, 4>				heap;
			
			const open_type::ligature_subst**	lig_standard;
			const open_type::ligature_subst**	lig_required;
			const open_type::ligature_subst**	lig_discretionary;
			
			open_type::table_glyf*				ot_glyf;
			open_type::table_head*				ot_head;
			open_type::table_hhea*				ot_hhea;
			open_type::table_hmtx*				ot_hmtx;
			open_type::table_loca*				ot_loca;
			open_type::table_maxp*				ot_maxp;
			
			int16u								glyph_count;			//	total number of glyphs in the font
			size_info_record*					glyph_sizes;			//	table with one entry per glyph
			
			int16u								units_per_em;
			double								scale_to_em;
			
			int16								mac_ascender;
			int16								mac_descender;
			int16								mac_line_gap;
			
			cache_record (font_face* face);
			~cache_record ();
			
			bool CheckAndResize (int16u n);
			
			size_info_record*    FindSizeInfo (int16u glyph);
			pix_per_size_record* FindPixPerSize (size_info_record* info, int32u size);
			pix_data_record*     FindPixData (size_info_record* info, int32u size, int8u xs, int8u ys);
			
			int8u* TurboAlloc (int32u size);
			
			bool DecompileSimpleCoordinates (size_info_record* info, int16u num_contours, open_type::table_glyf* glyf);
			bool DecompileComposite (int16u glyph, size_info_record*& info, open_type::table_glyf* glyf);
		};
		
		
	protected:
		void*				face_data;				//	associated face (font) data (or 0)
		size_t				face_data_size;			//	size of face data
		size_t				face_data_offset;		//	offset to start of directory entry
		void*				os_handle;
		
		cache_record*		face_cache;				//	OpenType face information cache
		
		int					lock_count;				//	# of uses of this face object
		
	protected:
		font_face ();
		virtual ~ font_face ();
		
		void DisposeData ();
		
	public:
		static font_face* CreateFontFaceFromData (const void* face_data, size_t face_data_size, size_t face_data_offset, void* os_handle);
		static void DisposeFontFace(font_face* face);
		
		void ClearCache ();
		bool UpdateCache ();
		
		//	OpenType table access :
		
	public:
		open_type::table_directory*     RetOpenTypeTableDirectory ();
		open_type::table_directory*		FindOpenTypeTableDirectory (void* base_ptr, size_t offset);
		open_type::table_GSUB*          RetOpenTypeGSUB ();
		open_type::table_head*          RetOpenTypeHead ();
		open_type::table_hhea*          RetOpenTypeHorizHead ();
		open_type::table_cmap*          RetOpenTypeCMap ();
		open_type::table_loca*          RetOpenTypeLoca ();
		open_type::table_glyf*          RetOpenTypeGlyf (int32u offset);
		
		const open_type::feature_list*  RetOpenTypeGSUBFeatureList ();
		const open_type::feature_table* RetOpenTypeGSUBFeatureTable (const char* feature);
		const open_type::lookup_list*   RetOpenTypeGSUBLookupList ();
		const open_type::lookup_table*  RetOpenTypeGSUBLookupTable (int16u index);
		
		const open_type::ligature_subst** NewOpenTypeLigatureSubstArray (const open_type::feature_table* features);
		int FillOpenTypeLigatureSubstArray (const open_type::feature_table* features, const open_type::ligature_subst** array);
		
	private:
		font_face (const font_face & );
		font_face & operator = (const font_face & );
		
	public:
		void Lock ()												{ this->lock_count++; }
		void Unlock ();
		
		int16u RetGlyphIndex (int32u unicode);
		
		font_face::cache_record::size_info_record* FindSizeInfo (int16u glyph)
		/**/														{ this->UpdateCache (); return this->face_cache->FindSizeInfo (glyph); }
		font_face::cache_record::pix_data_record*  FindPixData (font_face::cache_record::size_info_record* info, int32u size, int8u xs, int8u ys)
		/**/														{ this->UpdateCache (); return this->face_cache->FindPixData (info, size, xs, ys); }
		int8u* TurboAlloc (int32u size)								{ this->UpdateCache (); return this->face_cache->TurboAlloc (size); }
		double RetScaleToEM ()										{ this->UpdateCache (); return this->face_cache->scale_to_em; }
		int RetUnitsPerEM ()										{ this->UpdateCache (); return this->face_cache->units_per_em; }
		
		double RetGlyphAdvance (int16u glyph);
		double RetGlyphKerning (int16u glyph_1, int16u glyph_2);
		double RetCaretSlope ();
		
		double RetGlyphAdvance (int16u glyph, const font_face::cache_record::size_info_record* info)
		/**/														{ this->UpdateCache (); return info->width_advance * this->face_cache->scale_to_em; }
		
		
		double MeasureWidth (const int16u* glyphs, int num_glyphs, bool use_kerning, int16u pre_kern_glyph = 0, int16u post_kern_glyph = 0);
		void MeasureWidthByClass (const int16u* glyphs, const int8u* glyphs_class, float* glyph_dx, int num_glyphs, double* width_by_class, int num_classes, bool use_kerning, int16u pre_kern_glyph = 0, int16u post_kern_glyph = 0);
		void LayoutGlyphs (double & x, const int16u* glyphs, double* x_array, int num_glyphs, bool use_kerning, int16u pre_kern_glyph = 0, int16u post_kern_glyph = 0);
		
		bool GetGlyphAdvance (int16u glyph, double& x, double& y);
		bool GetGlyphAdvance (int16u glyph, double& x, double& y, font_face::cache_record::size_info_record*& info);
		bool GetVerticalMetrics (double & ascender, double & descender, double & line_height);
		
		void GetGlyphBounds (int16u glyph, double& x_min, double& y_min, double& x_max, double& y_max);
		
		int MapToGlyphs (const wchar_t* text, size_t text_len, int16u* glyphs, int8u* char_per_glyph, int max_glyphs, font_face::GlyphSubst substitution);
		int MapToGlyphs (const int32u* text, size_t text_len, int16u* glyphs, int8u* char_per_glyph, int max_glyphs, font_face::GlyphSubst substitution);
		
		int SubstituteGlyphs (int16u* glyphs, int8u* char_per_glyph, int & num_glyphs, font_face::GlyphSubst substitution);
	};
}

/*****************************************************************************/

#endif /* AGG_FONT_FACE_INCLUDED */
