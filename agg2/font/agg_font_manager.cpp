/*
 *	agg_font_manager.cpp
 *
 *	Font Manager implementation.
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

/*****************************************************************************/

#if defined(_MSC_VER)
#include <malloc.h>
#else
#include <alloca.h>
#endif

/*****************************************************************************/

using namespace agg;

font_manager::font_manager ()
	:
	thread_handle (0),
	family_head (0),
	family_tail (0)
{
}

font_manager::~font_manager ()
{
	font_manager::PlatformWaitForInitThread (this->thread_handle);
}

bool
font_manager::Initialise ()
{
	font_manager::PlatformStartInitThread (this);
	return true;
}

/*****************************************************************************/
/* This platform specific code is only available for Win32, for now...       */
/* Other platforms welcome...                                                */

#if defined(WIN32)

#include "win32tempdc.h"

/*
 *	Initialisation of the type engine is asynchronous: this allows the
 *	application to start quickly without having to wait until all fonts
 *	in the system have been listed and analysed.
 */

long __stdcall InitThread (void* arg)
{
	font_manager* that = reinterpret_cast<font_manager*> (arg);
	that->BuildSystemFontList ();
	return 0;
}

void
font_manager::PlatformStartInitThread (font_manager* manager)
{
	if (manager->thread_handle == 0)
	{
		DWORD id = 0;
		manager->thread_handle = ::CreateThread (0, 0, (LPTHREAD_START_ROUTINE) &InitThread, (LPVOID) manager, 0, &id);
	}
}

void
font_manager::PlatformWaitForInitThread (void*& thread_handle)
{
	if (thread_handle)
	{
		::WaitForSingleObject (thread_handle, 60 * 1000);
		::CloseHandle (thread_handle);
		thread_handle = 0;
	}
}

/*
 *	Font enumeration code is platform specific. The following enumeration
 *	routines work for Win32. A first enumeration analyses every font family,
 *	and a second, nested one, analyses every font in each family.
 *
 *	During analysis, a font will be partially loaded to access to its 'name'
 *	table; this will allow the type engine to properly identify the fonts
 *	with their untranslated family and style names.
 */

static HDC gfx_type_dc = 0;

struct PatchedENUMLOGFONTEXW	//	somme GCC installations define an incorrect ENUMLOGFONTEXW
{
	LOGFONTW	elfLogFont;
	WCHAR		elfFullName[64];
	WCHAR		elfStyle[32];
	WCHAR		elfScript[32];
};

static int CALLBACK
gfx_enum_fonts_in_family (const PatchedENUMLOGFONTEXW* log_font,
						  const NEWTEXTMETRICEXW* metric,
						  DWORD font_type,
						  LPARAM param)
{
	font_manager*                type   = reinterpret_cast<font_manager*> (param);
	font_manager::family_record* family = type->RetFamilyHead ();
	
	const wchar_t* full_name   = log_font->elfFullName;
	const wchar_t* style_name  = log_font->elfStyle;
	const wchar_t* script_name = log_font->elfScript;
	const wchar_t* family_name = log_font->elfLogFont.lfFaceName;
	
	//	Only handle non-raster fonts here. The others can be omitted.
	
	if ( (font_type != 0)
	  && ((font_type & RASTER_FONTTYPE) == 0) )
	{
		if (family->FindFace (full_name) == 0)
		{
			HFONT new_font = CreateFontIndirectW (& log_font->elfLogFont);
			
			//	Load the font so that we can access the 'name' table. Win32 is smart
			//	enough to load only the bytes really needed (probably thanks to some
			//	memory mapping).
			
			if (new_font)
			{
				HGDIOBJ old_font = SelectObject (gfx_type_dc, new_font);
				
				DWORD table_name   = agg::read_big_endian (static_cast<int32u> (('n' << 24) | ('a' << 16) | ('m' << 8) | ('e' << 0)));
				DWORD table_offset = 0;
				DWORD table_length = GetFontData (gfx_type_dc, table_name, table_offset, 0, 0);
				
				if (table_length != GDI_ERROR)
				{
					open_type::table_name* ot_name = reinterpret_cast<open_type::table_name*> (alloca (table_length));
					GetFontData (gfx_type_dc, table_name, table_offset, ot_name, table_length);
					
					const void* os_desc_data = & log_font->elfLogFont;
					size_t      os_desc_size = sizeof (log_font->elfLogFont);
					
					//	Record the information about this font face:
					
					family->InsertFace (type, os_desc_data, os_desc_size, full_name, style_name, script_name, family_name, ot_name);
				}
				
				SelectObject (gfx_type_dc, old_font);
				DeleteObject (new_font);
			}
		}
	}
	else if ( (family)
		   && (family->face_head == 0)
		   && (string_equal (family->name, family_name)) )
	{
		type->RemoveFamily (family);
		delete family;
	}
	
	return 1;
}

static int CALLBACK
gfx_enum_font_families (const PatchedENUMLOGFONTEXW* log_font,
						const NEWTEXTMETRICEXW* metric,
						DWORD font_type,
						LPARAM param)
{
	font_manager*  type = reinterpret_cast<font_manager*> (param);
	const wchar_t* name = log_font->elfLogFont.lfFaceName;
	
	//	Analyse every font family more in detail, unless it is already known, or it is
	//	a synthetic vertical font (we identify these by the starting '@' in the family
	//	name).
	
	if ( (name[0] != '@')
	  && (type->FindFamily (name) == 0) )
	{
		LOGFONTW family_log_font;
		
		font_manager::family_record* family = type->NewFamilyRecord ();
		
		memory_zero (&family_log_font, sizeof (family_log_font));
		string_copy (family_log_font.lfFaceName, sizeof (family_log_font.lfFaceName), name);
		string_copy (family->name, sizeof (family->name), name);
		
		type->InsertFamily (family);
		
		family_log_font.lfCharSet = DEFAULT_CHARSET;
		
		::EnumFontFamiliesExW (gfx_type_dc, &family_log_font, (FONTENUMPROCW) gfx_enum_fonts_in_family, (LPARAM) type, 0);
	}
	
	return 1;
}

void
font_manager::PlatformListFonts (font_manager* manager)
{
	Win32::TempDC dc (gfx_type_dc);
	
	LOGFONTW log_font;
	memory_zero (&log_font, sizeof (log_font));
	
	log_font.lfCharSet = DEFAULT_CHARSET;
	
	EnumFontFamiliesExW (gfx_type_dc, &log_font, (FONTENUMPROCW) gfx_enum_font_families, (LPARAM) manager, 0);
}

#endif /* WIN32 */

/*****************************************************************************/

void
font_manager::BuildSystemFontList ()
{
	font_manager::PlatformListFonts (this);
}

void
font_manager::WaitForSystemFontListCompleted () const
{
	font_manager::PlatformWaitForInitThread (this->thread_handle);
}

/*****************************************************************************/

font_face*
font_manager::FindFontFace (const wchar_t* os_name)
{
	this->WaitForSystemFontListCompleted ();
	
	family_record* iter = this->family_head;
	font_face*     face = 0;
	
	while (iter)
	{
		face = iter->FindFace (os_name);
		
		if (face)
		{
			break;
		}
		
		iter = iter->next;
	}
	
	return face;
}

font_face*
font_manager::FindFontFace (const wchar_t* family_name, const wchar_t* style_name, const wchar_t* optical_name)
{
	this->WaitForSystemFontListCompleted ();
	
	if (optical_name == 0) {
		optical_name = L"";
	}
	
	family_record* iter = this->family_head;
	font_face*     face = 0;
	
	while (iter)
	{
		face = iter->FindFace (family_name, style_name, optical_name);
		
		if (face)
		{
			break;
		}
		
		iter = iter->next;
	}
	
	return face;
}

/*****************************************************************************/

void
font_manager::ReduceMemoryUsage ()
{
	family_record* family = this->family_head;
	
	while (family)
	{
		font_face* face = family->face_head;
		
		while (face)
		{
			face->ReduceMemoryUsage ();
			face = face->next;
		}
		
		family = family->next;
	}
}

/*****************************************************************************/

font_manager::family_record*
font_manager::FindFamily (const wchar_t* name)
{
	family_record* iter = this->family_head;
	
	while (iter)
	{
		if (string_equal (iter->name, name))
		{
			break;
		}
		
		iter = iter->next;
	}
	
	return iter;
}

font_manager::family_record*
font_manager::NewFamilyRecord ()
{
	return new font_manager::family_record ();
}

font_manager::family_record*
font_manager::RetFamilyHead ()
{
	return this->family_head;
}

void
font_manager::RemoveFamily (font_manager::family_record* family)
{
	(family->next ? family->next->prev : this->family_tail) = family->prev;
	(family->prev ? family->prev->next : this->family_head) = family->next;
	
	family->prev = family;
	family->next = family;
}

void
font_manager::InsertFamily (font_manager::family_record* family)
{
	family->next = this->family_head;
	family->prev = 0;
	
	(family->next ? family->next->prev : this->family_tail) = family;
	(family->prev ? family->prev->next : this->family_head) = family;
}

/*****************************************************************************/

int
font_manager::CountFamilies () const
{
	family_record* iter = this->family_head;
	int            num  = 0;
	
	while (iter)
	{
		num += 1;
		iter = iter->next;
	}
	
	return num;
}

int
font_manager::CountFontFaces () const
{
	this->WaitForSystemFontListCompleted ();
	
	family_record* iter = this->family_head;
	int            num  = 0;
	
	while (iter)
	{
		num += iter->CountFaces ();
		iter = iter->next;
	}
	
	return num;
}

font_face*
font_manager::RetNthFace (int nth) const
{
	this->WaitForSystemFontListCompleted ();
	
	family_record* iter = this->family_head;
	font_face*     face = 0;
	
	while (iter)
	{
		face = iter->RetNthFace (nth);
		
		if (face)
		{
			return face;
		}
		
		iter = iter->next;
	}
	
	return 0;
}

/*****************************************************************************/
