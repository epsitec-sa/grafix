/*
 *	agg_text_break.h
 *
 *	Text Break support code.
 *
 *	(C) Copyright 2003-2004, Pierre ARNAUD, OPaC bright ideas, Ch. du Fontenay 6,
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

/*****************************************************************************/

#ifndef AGG_TEXT_BREAK_INCLUDED
#define	AGG_TEXT_BREAK_INCLUDED

#include "agg_font_face.h"

/*****************************************************************************/

namespace agg
{
	class text_break
	{
	public:
		enum text_break_mode_enum
		{
			text_break_none			= 0x0000,
			text_break_hyphenate	= 0x0001,		//	hyphenate words, if needed
			text_break_ellipsis		= 0x0002,		//	truncate text and add "..."
			text_break_overhang		= 0x0004,		//	allow text to hang over the margins
			text_break_truncate		= 0x0008,		//	truncate anywhere, if needed
			
			text_break_single_line	= 0x0100,		//	force everything on a single line (used with ellipsis, overhang and truncate)
		};
		
	private:
		struct font_info_record
		{
			agg::font_face*		face;
			
			agg::int16u			hyphen_char;
			agg::int16u			hyphen_glyph;
			double				hyphen_width;
			
			agg::int16u			ellipsis_char;
			agg::int16u			ellipsis_glyph;
			double				ellipsis_width;
		};
		
		struct run_info_record
		{
			font_info_record*	font;
			int					length;
			double				scale;
		};
		
	private:
		agg::int32u				m_check_id;
		
		agg::int8u*				m_memory;
		size_t					m_memory_size;
		
		font_info_record*		m_face_info;
		int						m_face_info_count;
		
		run_info_record*		m_run_info;
		int						m_run_info_count;
		
		wchar_t*				m_text;
		size_t					m_text_length;
		agg::int8u*				m_text_breaks;
		text_break_mode_enum	m_text_break_mode;
		
		
		int						m_pos;
		run_info_record*		m_run;
		int						m_run_n;
		int						m_run_offset;
		
		wchar_t*				m_chunk;
		size_t					m_max_chunk_len;

	private:
		bool allocate_buffers(size_t text_length);
		bool allocate_chunk(size_t text_length);
		void free_buffers();
		
	public:
		text_break();
		~text_break();
		
		bool is_valid() const;
		
		bool define_font_faces(int n, agg::font_face** font_faces);
		bool define_text_runs(int n, const agg::int16u* run_lengths, const agg::int16u* font_ids, const double* scales);
		bool define_text(const wchar_t* text);
		bool define_text_break_mode(text_break_mode_enum mode);
		
		bool allocate_font_faces(int n);
		bool allocate_text_runs(int n);
		bool define_nth_font_face(int n, agg::font_face* font_face);
		bool define_nth_run(int n, agg::int16u run_length, agg::int16u font_id, double scale);
		
		wchar_t*             text() const				{ return m_text; }
		size_t               text_length() const		{ return m_text_length; }
		const agg::int8u*    text_breaks() const		{ return m_text_breaks; }
		agg::int8u*          text_breaks()				{ return m_text_breaks; }
		text_break_mode_enum text_break_mode() const	{ return m_text_break_mode; }
		
		void rewind();
		const wchar_t* find_next_break(double& width, int& n_chars);
	};
}

/*****************************************************************************/

#endif /* AGG_TEXT_BREAK_INCLUDED */
