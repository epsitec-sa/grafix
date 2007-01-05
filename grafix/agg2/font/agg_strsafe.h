/*
 *	agg_strsafe.h
 *
 *	String functions.
 *
 *	(C) Copyright 2002-2007, Pierre ARNAUD, OPaC bright ideas, Ch. du Fontenay 6,
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

#ifndef AGG_STRSAFE_INCLUDED
#define AGG_STRSAFE_INCLUDED

#ifdef _MSC_VER
#pragma warning(disable: 4996)
#endif

#include <string.h>
#include <wchar.h>

/*****************************************************************************/

namespace agg
{
	//	Should be using #include <strsafe.h> here, but since the header file is soooo large,
	//	we currently just use a home made version of the needed functions:

	static void string_copy(char* dst, size_t size, const char* src)
	{
		memset (dst, 0, size);
		strncpy (dst, src, size / sizeof (char) - 1);
	}

	static void string_copy(wchar_t* dst, size_t size, const wchar_t* src)
	{
		memset (dst, 0, size);
		wcsncpy (dst, src, size / sizeof (wchar_t) - 1);
	}

	static void string_cat(char* dst, size_t size, const char* src)
	{
		size_t dst_len = strlen (dst);
		
		if (size > dst_len)
		{
			string_copy (dst + dst_len, size - dst_len, src);
		}
	}

	static void string_cat(wchar_t* dst, size_t size, const wchar_t* src)
	{
		size_t dst_len = wcslen (dst) * sizeof (wchar_t);
		
		if (size > dst_len)
		{
			string_copy (dst + dst_len, size - dst_len, src);
		}
	}

	static bool string_equal(const char* a, const char* b)
	{
		if ( (a == 0) || (b == 0) ) {
			return a == b;
		} else {
			return strcmp (a, b) == 0;
		}
	}

	static bool string_equal(const wchar_t* a, const wchar_t* b)
	{
		if ( (a == 0) || (b == 0) ) {
			return a == b;
		} else {
			return wcscmp (a, b) == 0;
		}
	}

	static void string_zero(void* str, size_t size)
	{
		memset (str, 0, size);
	}

	static void memory_zero(void* str, size_t size)
	{
		memset (str, 0, size);
	}
}

/*****************************************************************************/

#endif
