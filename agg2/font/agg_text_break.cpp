/*
 *	agg_text_break.cpp
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

#include "agg_text_break.h"
#include "agg_text_unicode_support.h"
#include "agg_strsafe.h"

/*****************************************************************************/

agg::text_break::text_break()
	:
	m_check_id (0xfaceb000),
	m_memory (0), m_memory_size (0),
	m_face_info (0), m_face_info_count (0),
	m_run_info (0), m_run_info_count (0),
	m_text (0), m_text_length (0), m_text_breaks (0), m_text_break_mode (agg::text_break::text_break_none),
	m_pos (0), m_run (0), m_run_n (0), m_run_offset (0),
	m_chunk (0), m_max_chunk_len (0)
{
}
		
agg::text_break::~text_break()
{
	this->free_buffers ();
	this->define_font_faces (0, 0);
	this->define_text_runs (0, 0, 0, 0);
	
	m_check_id  = 0;
}

bool agg::text_break::is_valid() const
{
	return (m_check_id == 0xfaceb000) && (m_face_info != 0) && (m_face_info_count > 0) && (m_text != 0);
}

/*****************************************************************************/

bool agg::text_break::allocate_buffers(size_t text_length)
{
	size_t text_size   = (text_length + 1) * sizeof (wchar_t);
	size_t break_size  = (text_length);
	
	size_t memory_size = text_size + break_size;
	
	if (memory_size > m_memory_size)
	{
		//	More memory needed than currently available. Allocate a new buffer.
		
		this->free_buffers ();
		
		int8u* memory_data = new int8u[memory_size];
		
		if (memory_data == 0)
		{
			return false;
		}
		
		m_memory      = memory_data;
		m_memory_size = memory_size;
	}
	
	int8u* memory = m_memory;
	
	m_text        = reinterpret_cast<wchar_t*> (memory);	memory += text_size;
	m_text_breaks = reinterpret_cast<int8u*> (memory);		memory += break_size;
	m_text_length = text_length;
	
	return true;
}

bool agg::text_break::allocate_chunk(size_t text_length)
{
	if (text_length > m_max_chunk_len)
	{
		if (m_chunk)
		{
			delete[] m_chunk;
		}
		
		m_chunk         = new wchar_t[text_length];
		m_max_chunk_len = m_chunk ? text_length : 0;
	}
	
	return m_chunk ? true : false;
}

void agg::text_break::free_buffers()
{
	if (m_memory)
	{
		delete[] m_memory;
		
		m_memory      = 0;
		m_text        = 0;
		m_text_breaks = 0;
		
		m_memory_size = 0;
		m_text_length = 0;
	}
	
	if (m_chunk)
	{
		delete[] m_chunk;
		
		m_chunk         = 0;
		m_max_chunk_len = 0;
	}
}

/*****************************************************************************/

bool agg::text_break::allocate_font_faces(int n)
{
	if (m_face_info)
	{
		delete[] m_face_info;
		
		m_face_info       = 0;
		m_face_info_count = 0;
	}
	
	if (n <= 0)
	{
		return false;
	}
	
	m_face_info       = new font_info_record[n];
	m_face_info_count = m_face_info ? n : 0;
	
	if (m_face_info == 0)
	{
		return false;
	}
	
	return true;
}

bool agg::text_break::allocate_text_runs(int n)
{
	if (m_run_info)
	{
		delete[] m_run_info;
		
		m_run_info       = 0;
		m_run_info_count = 0;
	}
	
	if ( (n <= 0)
	  || (m_face_info_count == 0) )
	{
		return false;
	}
	
	m_run_info       = new run_info_record[n];
	m_run_info_count = m_run_info ? n : 0;
	
	if (m_run_info == 0)
	{
		return false;
	}
	
	return true;
}

bool agg::text_break::define_nth_font_face(int i, agg::font_face* face)
{
	if ( (i < 0)
	  || (i >= m_face_info_count) )
	{
		return false;
	}
	
	font_info_record& rec = m_face_info[i];
	
	rec.face = face;
	
	rec.hyphen_char  = agg::unicode_helper::Hyphen;
	rec.hyphen_glyph = face->RetGlyphIndex (rec.hyphen_char);
	
	if (rec.hyphen_glyph == 0)
	{
		rec.hyphen_char  = agg::unicode_helper::HyphenMinus;
		rec.hyphen_glyph = face->RetGlyphIndex (rec.hyphen_char);
	}
	
	rec.hyphen_width   = face->RetGlyphAdvance (rec.hyphen_glyph);
	
	rec.ellipsis_char  = agg::unicode_helper::Ellipsis;
	rec.ellipsis_glyph = face->RetGlyphIndex (rec.ellipsis_char);
	rec.ellipsis_width = face->RetGlyphAdvance (rec.ellipsis_glyph);
	
	return true;
}

bool agg::text_break::define_nth_run(int i, int16u run_length, int16u font_id, double scale)
{
	if ( (i < 0)
	  || (i >= m_run_info_count) )
	{
		return false;
	}
	
	run_info_record& run = m_run_info[i];
	
	run.font   = (font_id == 0xffff) ? 0 : & m_face_info[font_id];
	run.length = run_length;
	run.scale  = scale;
	
	return true;
}

bool agg::text_break::define_font_faces(int n, agg::font_face** font_faces)
{
	if (font_faces == 0)
	{
		return false;
	}
	
	if (this->allocate_font_faces (n))
	{
		for (int i = 0; i < n; i++)
		{
			this->define_nth_font_face (i, font_faces[i]);
		}
		
		return true;
	}
	
	return false;
}

bool agg::text_break::define_text_runs(int n, const int16u* run_lengths, const int16u* font_ids, const double* scales)
{
	if ( (run_lengths == 0)
	  || (font_ids == 0)
	  || (scales == 0) )
	{
		return false;
	}
	
	for (int i = 0; i < n; i++)
	{
		if ((font_ids[i] >= m_face_info_count) ||
			(font_ids[i] == 0xffff))
		{
			return false;
		}
	}
	
	if (this->allocate_text_runs (n))
	{
		for (int i = 0; i < n; i++)
		{
			this->define_nth_run (i, run_lengths[i], font_ids[i], scales[i]);
		}
		
		return true;
	}
	
	return false;
}

bool agg::text_break::define_text(const wchar_t* text)
{
	if (text == 0)
	{
		text = L"";
	}
	
	size_t length = wcslen (text) + 1;
	
	if (this->allocate_buffers (length))
	{
		//	The memory has been successfully allocated for the text; keep a copy of the
		//	original text.
		
		agg::string_copy (m_text, length*sizeof (wchar_t), text);
		
		return true;
	}
	
	m_text        = 0;
	m_text_breaks = 0;
	m_text_length = 0;
	
	return false;
}

bool agg::text_break::define_text_break_mode(agg::text_break::text_break_mode_enum mode)
{
	if (m_text_length == 0)
	{
		return true;
	}
	
	m_text_break_mode = mode;
	
	//	Analyse the text and produce the text breaks based on the Unicode algorithm.
	
	agg::unicode_helper::analyse_breaks (m_text, m_text_length, m_text_breaks);
	
	if (mode & text_break_single_line)
	{
		//	When in single-line mode, only break at forced line breaks, but nowhere else.
		
		for (size_t i = 0; i < m_text_length; i++)
		{
			if (m_text_breaks[i] != agg::unicode_helper::break_yes_always)
			{
				m_text_breaks[i] = agg::unicode_helper::break_no;
			}
		}
	}
	
	return true;
}

/*****************************************************************************/

void agg::text_break::rewind()
{
	m_pos        = 0;
	m_run        = m_run_info;
	m_run_n      = 0;
	m_run_offset = 0;
}

const wchar_t* agg::text_break::find_next_break(double& width, int& n_chars)
{
	const wchar_t* text = m_text + m_pos;
	const int8u* breaks = m_text_breaks + m_pos;
	
	bool   add_ellipsis  = false;
//	bool   is_multi_line = (m_text_break_mode & text_break_single_line) ? false : true;
	
restart:
	if (text[0] == 0)
	{
		width   = 0.0;
		n_chars = 0;
		return 0;
	}
	
	run_info_record*  run   = m_run;
	int               run_n = m_run_n;
	font_info_record* font  = run->font;
	agg::font_face*   face  = font ? font->face : 0;
	
	double  advance       = 0;
	int     offset        = 0;
	int     run_offset    = m_run_offset;
	double  scale         = run->scale;
	bool    hyphenate     = false;
	
	int               break_offset     = 0;
	run_info_record*  break_run        = 0;
	int               break_run_n      = 0;
	int               break_run_offset = 0;
	double            break_advance    = 0;
	double            break_width      = 0;
	wchar_t           break_char       = 0;
	
		
	//	When we reach the end of the current run, we must move to the next run, which
	//	might have a different font face and a different font scale.
	
	while (run_offset >= run->length)
	{
		run++;
		run_n++;
		
		if (run_n >= m_run_info_count)
		{
			__asm int 3;
		}
		
		run_offset = 0;
		font       = run->font;
		scale      = run->scale;
		face       = font ? font->face : 0;
	}
	
	for (;;)
	{
		int16u unicode    = text[offset];
		int16u glyph      = face ? face->RetGlyphIndex (unicode) : 0;
		double char_width = face ? face->RetGlyphAdvance (glyph) * scale : scale;
		int8u  break_mode = breaks[offset] & agg::unicode_helper::break_mask;
		
		if (glyph == 0)
		{
			switch (unicode)
			{
				case agg::unicode_helper::PageSeparator:
				case agg::unicode_helper::LineSeparator:
				case agg::unicode_helper::ParagraphSeparator:
				case agg::unicode_helper::ZeroWidthSpace:
				case agg::unicode_helper::ZeroWidthNonJoiner:
				case agg::unicode_helper::ZeroWidthJoiner:
					char_width = 0;
					break;
				default:
					break;
			}
		}
		
		if (agg::unicode_helper::break_no != break_mode)
		{
			if ( (font) &&
				 (agg::unicode_helper::break_hyphenate == break_mode) )
			{
				//	Check to see if the current text, including the hyphen, fits in the given space.
				//	If not, give up and use the previous best fit.
				
				if (width < advance+font->hyphen_width*scale)
				{
					goto try_fit;
				}
				
				break_width = font->hyphen_width * scale;
				break_char  = font->hyphen_char;
				hyphenate   = true;
			}
			else
			{
				double temp_width = char_width;
				
				//	Spaces at the end of a line are not counted for the line length computation :
				
				switch (unicode)
				{
					case agg::unicode_helper::Space:
						temp_width = 0;
						break;
				}
				
				//	Can we fit the glyph on the line and possibly break after it, or do we have
				//	to break immediately, relying on the previous possible break ?
				
				if (width < advance+temp_width)
				{
					goto try_fit;
				}
				
				break_width = temp_width;
				break_char  = unicode;
				hyphenate   = false;
			}
			
			//	We have found a position where it is possible to break the text. Remember it; it
			//	might be used as the best fit.
			
			break_offset     = offset;
			break_run        = run;
			break_run_n      = run_n;
			break_run_offset = run_offset;
			break_advance    = advance;
		}
		
try_fit:
		if ( (break_offset == 0)
		  && (offset > 0)
		  && (width < (advance + char_width)) )
		{
			//	Oops... The word is too long to fit in the given space, and there is no position
			//	where a break would be possible before. What can we do?
			
			if ( (m_text_break_mode & text_break_ellipsis)
			  && (font)
			  && (font->ellipsis_glyph > 0)
			  && (add_ellipsis == false) )
			{
				//	The caller specified that an ellipsis should be added if a word gets
				//	truncated.
				
				if (width > font->ellipsis_width)
				{
					//	Pretend that there is an ellipsis (...) at the end of the text, reduce the
					//	available width and start all the process over again.
					
					width -= font->ellipsis_width * scale;
					add_ellipsis = true;
					goto restart;
				}
			}
			
			if ( (m_text_break_mode & text_break_truncate)
			  || (add_ellipsis) )
			{
				//	Truncation required, just stop here.
				
				break_offset     = offset;
				break_advance    = advance;
				break_run        = run;
				break_run_n      = run_n;
				break_run_offset = run_offset;
				break_char       = add_ellipsis ? font->ellipsis_char : 0;
				
				goto break_text;
			}
		}
		
		//	TODO: handle surrogate pairs...
		
		advance    += char_width;
		offset     += 1;
		run_offset += 1;
		
		if ( (advance > width)
		  || (agg::unicode_helper::break_yes_always == breaks[offset-1])
		  || (text[offset] == 0) )
		{
			break;
		}
		
		//	When we reach the end of the current run, we must move to the next run, which
		//	might have a different font face and a different font scale.
		
		if (run_offset >= run->length)
		{
			run++;
			run_n++;
			
			if (run_n >= m_run_info_count)
			{
				__asm int 3;
			}
			
			run_offset = 0;
			font       = run->font;
			scale      = run->scale;
			face       = font ? font->face : 0;
		}
	}
	
	if (advance <= width)
	{
		//	Everything just fits into the specified width. That's nice and easy to handle.
		
		m_pos       += offset;
		m_run        = run;
		m_run_n      = run_n;
		m_run_offset = run_offset;
		
		width   = advance;
		n_chars = offset;
		
		if (this->allocate_chunk (offset+1))
		{
			wcsncpy (m_chunk, text, offset);
			m_chunk[offset] = 0;
			text = m_chunk;
		}
		
		return text;
	}
	
	if (break_offset == 0)
	{
		//	There was no break position before the current point; we must give up here,
		//	and hope that the caller will be able to handle the condition.
		
		width   = 0.0;
		n_chars = 0;
		
		return L"";
	}
	
	//	Make a copy of the text, either in order to add an ellipsis or a hyphen.
	
break_text:
	if (this->allocate_chunk (break_offset+2) == false)
	{
		m_pos       += offset;
		m_run        = run;
		m_run_n      = run_n;
		m_run_offset = run_offset;
		
		width   = advance;
		n_chars = offset;
		return 0;
	}
	
	wcsncpy (m_chunk, text, break_offset);
	
	m_chunk[break_offset+0] = break_char;
	m_chunk[break_offset+1] = 0;
	
	width = break_advance + break_width;
	
//	TODO: skip end of word if ellipsis inserted
	
	if (text[break_offset] == ' ')
	{
		//	If the line ends with a space, strip the space and skip it, to be sure we don't
		//	reconsider it on the next iteration.
		
		m_chunk[break_offset] = 0;
		
		break_offset++;
		break_run_offset++;
		
		if (break_run_offset >= break_run->length)
		{
			break_run++;
			break_run_n++;
			
			if (break_run_n >= m_run_info_count)
			{
//-				__asm int 3;
				break_run = 0;	//	nobody will be able to read from here !
			}
			
			break_run_offset = 0;
		}
	}
	else if (!hyphenate && !add_ellipsis)
	{
		//	The line breaks with a breaking character. Since it has been placed on the
		//	current line, we must skip it in order not to reconsider it on the next
		//	iteration.
		
		break_offset++;
	}
	
	m_pos       += break_offset;
	m_run        = break_run;
	m_run_n      = break_run_n;
	m_run_offset = break_run_offset;
	
	width   = break_advance;
	n_chars = break_offset;
	
	return m_chunk;
}