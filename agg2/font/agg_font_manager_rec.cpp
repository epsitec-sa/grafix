/*
 *	agg_font_manager_rec.cpp
 *
 *	Font Manager Family Record implementation.
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

#include "agg_font_manager.h"
#include "agg_font_face.h"

#include "agg_font_opentype.h"
#include "agg_strsafe.h"

#include <string.h>
#include <stdio.h>

using namespace agg;

/*****************************************************************************/

font_manager::family_record::family_record ()
	:
	prev (0),
	next (0),
	face_head (0),
	face_tail (0)
{
	string_zero (this->name, sizeof (this->name));
}

font_manager::family_record::~family_record ()
{
	font_face* iter = this->face_head;
	
	while (iter)
	{
		font_face* next = iter->next;
		
		if (iter->os_description)
		{
			int8u* bytes = reinterpret_cast<int8u*> (iter->os_description);
			delete[] bytes;
			iter->os_description = 0;
		}
		
		delete iter;
		iter = next;
	}
	
	this->face_head = 0;
	this->face_tail = 0;
}

/*
 *	Record a font face for a given font family. Store everything we know about
 *	the font: its OS description, its name, style, etc.
 */

void
font_manager::family_record::InsertFace (font_manager* type,
										 const void* os_description, size_t os_description_size,
										 const wchar_t* os_name,
										 const wchar_t* style_name,
										 const wchar_t* script_name,
										 const wchar_t* family_name,
										 const open_type::table_name* ot_name)
{
	size_t ot_font_family_len = ot_name->RetUnicodeLength (1033, open_type::table_name::NAME_FontFamily);
	size_t ot_font_style_len  = ot_name->RetUnicodeLength (1033, open_type::table_name::NAME_FontSubfamily);
	size_t ot_pref_family_len = ot_name->RetUnicodeLength (1033, open_type::table_name::NAME_PreferredFamily);
	size_t ot_pref_style_len  = ot_name->RetUnicodeLength (1033, open_type::table_name::NAME_PreferredSubfamily);
	
	wchar_t ot_family[100] = { 0 };
	wchar_t ot_style[100]  = { 0 };
	wchar_t ot_optical[64] = { 0 };
	
	if (ot_font_family_len || ot_pref_family_len)
	{
		ot_name->GetUnicodeName (1033, ot_pref_family_len ? open_type::table_name::NAME_PreferredFamily
			/**/										  : open_type::table_name::NAME_FontFamily,
			/**/				 ot_family, 100);
	}
	
	if (ot_font_style_len || ot_pref_style_len)
	{
		ot_name->GetUnicodeName (1033, ot_pref_style_len  ? open_type::table_name::NAME_PreferredSubfamily
			/**/										  : open_type::table_name::NAME_FontSubfamily,
			/**/				 ot_style, 100);
	}
	
	if (ot_family[0] == 0)
	{
		string_copy (ot_family, sizeof (ot_family), family_name);
	}
	
	if (ot_style[0] == 0)
	{
		string_copy (ot_style, sizeof (ot_style), style_name);
	}
	
	
	//	Some fonts, such as Adobe's "Warnock Pro" have an additional denomination for designating
	//	optical size... We need to identify it, remove it from the style name and store it as the
	//	"optical name".
	
	wchar_t*       style_suffix = ot_style;
	const wchar_t* fname_suffix = family_name;
	wchar_t*       optical_name = 0;
	
	int style_i = static_cast<int> (wcslen (style_suffix));
	int fname_i = static_cast<int> (wcslen (fname_suffix));
	
	for (;;)
	{
		style_i--;
		fname_i--;
		
		if ((style_i < 0) || (fname_i < 0))
		{
			optical_name = style_suffix;
			break;
		}
		if (style_suffix[style_i] != fname_suffix[fname_i])
		{
			break;
		}
		if (style_suffix[style_i] == ' ')
		{
			optical_name = style_suffix + style_i;
		}
	}
	
	if (optical_name)
	{
again:
		while (*optical_name == ' ')
		{
			optical_name++;
		}
		
		static const wchar_t* reserved_names[] = { L"Light", L"Demibold", L"Semibold", L"Demi", L"Semi", 0 };
		
		int i = 0;
		
		while (reserved_names[i])
		{
			const wchar_t* name = reserved_names[i++];
			size_t         len  = wcslen (name);
			
			if (wcsncmp (name, optical_name, len) == 0)
			{
				optical_name += len;
				goto again;
			}
		}
		
		string_copy (ot_optical, sizeof (ot_optical), optical_name);
		
		while ( (optical_name > style_suffix)
			 && (optical_name[-1] == ' ') )
		{
			optical_name--;
		}
		
		optical_name[0] = 0;
	}
	
	
	
	font_face* face = new font_face (type);
	
	face->next = 0;
	face->prev = this->face_tail;
	
	face->os_description = new int8u[os_description_size];
	
	memcpy (face->os_description, os_description, os_description_size);
	
	(face->next ? face->next->prev : this->face_tail) = face;
	(face->prev ? face->prev->next : this->face_head) = face;
	
	string_copy (face->os_name,        sizeof (face->os_name),        os_name);
	string_copy (face->family_name,    sizeof (face->family_name),    ot_family);
	string_copy (face->style_name,     sizeof (face->style_name),     ot_style);
	string_copy (face->optical_name,   sizeof (face->optical_name),   ot_optical);
	string_copy (face->style_name_loc, sizeof (face->style_name_loc), style_name);
}

/*
 *	In a given font family, find the specified font (using the OS name).
 *	Prefer using the other version of FindFace, which uses the family,
 *	style and optical names for the search.
 */

font_face*
font_manager::family_record::FindFace (const wchar_t* os_name) const
{
	font_face* iter = this->face_head;
	
	while (iter)
	{
		if (string_equal (iter->os_name, os_name))
		{
			break;
		}
		
		iter = iter->next;
	}
	
	return iter;
}

font_face*
font_manager::family_record::FindFace (const wchar_t* family_name, const wchar_t* style_name, const wchar_t* optical_name)
{
	font_face* iter = this->face_head;
	
	while (iter)
	{
		if ( (string_equal (iter->style_name, style_name))
		  && (string_equal (iter->optical_name, optical_name))
		  && (string_equal (iter->family_name, family_name)) )
		{
			break;
		}
		
		iter = iter->next;
	}
	
	return iter;
}

/*****************************************************************************/

/*
 *	Return number of font faces in the given font family.
 */

int
font_manager::family_record::CountFaces () const
{
	font_face* iter = this->face_head;
	int num = 0;
	
	while (iter)
	{
		num += 1;
		iter = iter->next;
	}
	
	return num;
}

/*
 *	Return the nth font face in the given font family.
 */

font_face*
font_manager::family_record::RetNthFace (int & nth) const
{
	font_face* iter = this->face_head;
	
	while (iter)
	{
		if (nth == 0)
		{
			return iter;
		}
		
		nth--;
		iter = iter->next;
	}
	
	return 0;
}

/*****************************************************************************/
/* This platform specific code is only available for Win32, for now...       */
/* Other platforms welcome...                                                */

#if defined(WIN32)
#include "win32tempdc.h"

/*
 *	Load the font data for the specified font, using the OS description
 *	(under Win32, this is a LOGFONT structure; under other platforms,
 *	this could simply be the OpenType font file path).
 */

bool
font_manager::family_record::LoadFontData (const void* os_description,
										   void*& data, size_t& data_size)
{
	data      = 0;
	data_size = 0;
	
	Win32::TempDC dc;
	
	HFONT new_font = CreateFontIndirectW (reinterpret_cast<const LOGFONTW*> (os_description));
	
	if (new_font)
	{
		HGDIOBJ old_font = SelectObject (dc, new_font);
		
		DWORD table_name   = 0;
		DWORD table_offset = 0;
		DWORD table_length = GetFontData (dc, table_name, table_offset, 0, 0);
		
		if (table_length != GDI_ERROR)
		{
			data      = new int8u[table_length];
			data_size = data ? table_length : 0;
			
			GetFontData (dc, table_name, table_offset, data, table_length);
			
			SelectObject (dc, old_font);
			DeleteObject (new_font);
		}
	}
	
	return data ? true : false;
}
#endif /* WIN32 */

void
font_manager::family_record::FreeFontData (void* data)
{
	if (data)
	{
		int8u* bytes = reinterpret_cast<int8u*> (data);
		delete[] bytes;
	}
}

/*****************************************************************************/

bool
font_manager::family_record::LoadFontAndReturnOsHandle (const void* os_description, void*& os_handle)
{
	os_handle = 0;
	
#if defined(WIN32)
#if 0
	char  buffer[2000];
	const LOGFONTW* lfw = reinterpret_cast<const LOGFONTW*> (os_description);
	
	_snprintf (buffer, 2000,
			  "LOGFONT:\n"
			  "  h=%d w=%d esc=%d orient=%d weight=%d\n"
			  "  italic=%d under=%d strike=%d charset=%d outP=%d clipP=%d q=%d p&f=%d\n"
			  "  face=%S\n",
			  lfw->lfHeight, lfw->lfWidth, lfw->lfEscapement, lfw->lfOrientation, lfw->lfWeight,
			  lfw->lfItalic, lfw->lfUnderline, lfw->lfStrikeOut, lfw->lfCharSet, lfw->lfOutPrecision, lfw->lfClipPrecision, lfw->lfQuality, lfw->lfPitchAndFamily,
			  lfw->lfFaceName);
	buffer[1999] = 0;
	::OutputDebugString (buffer);
#endif
	
	HFONT new_font = ::CreateFontIndirectW (reinterpret_cast<const LOGFONTW*> (os_description));
	
#if 0	
	_snprintf (buffer, 2000, "HFONT --> %p (%d)", (void*)(new_font), (int)(void*)(new_font));
	buffer[1999] = 0;
	::OutputDebugString (buffer);
#endif
	
	if (new_font)
	{
		os_handle = new_font;
		return true;
	}
#endif
	
	return false;
}

void
font_manager::family_record::FreeOsHandle (void* os_handle)
{
#if defined(WIN32)
	if (os_handle)
	{
		::DeleteObject (reinterpret_cast<HFONT> (os_handle));
	}
#endif
}

/*****************************************************************************/
