//	AntiGrain.Win32/interface.cpp
//
//	Copyright © 2003-2007, Pierre ARNAUD, OPaC bright ideas, Ch. du Fontenay 6,
//	                       CH-1400 YVERDON, Switzerland. All rights reserved. 
//
//	Contact: pierre.arnaud@opac.ch, http://www.opac.ch
//	License: see license.txt

#include "interface.h"
#include "structures.h"

#if defined(USE_WIN32_API)
#include <windows.h>
#include <stdio.h>
#endif

/*
 *	The "interface" consists of low level functions required to set up and
 *	tear down the library itself, and to get some stats about it.
 */

/*****************************************************************************/

#if defined(USE_WIN32_API)
static BYTE*	version_data			= 0;
#endif

static wchar_t* version_file_version	= 0;
static wchar_t* version_product_name	= 0;

/*****************************************************************************/

bool
AggInitialise()
{
	return true;
}

void
AggShutDown()
{
#if defined(USE_WIN32_API)
	if (version_data)
	{
		delete version_data;
		
		version_data         = 0;
		version_file_version = 0;
		version_product_name = 0;
	}
#endif
}

/*****************************************************************************/

void
AggNoOp()
{
}

void
AggNoOpString(const wchar_t* text)
{
}

/*****************************************************************************/

/*
 *	Internal: retrieve version information for the specified version
 *	key, using a cache (info).
 */

static const wchar_t*
GetVersionInfo(const wchar_t* key, wchar_t*& info)
{
#if defined(USE_WIN32_API)

	if ( (version_data == 0)
	  && (global_dll_handle) )
	{
		const int max_len = 400;
		wchar_t module_file_name[max_len];
		
		GetModuleFileNameW ((HMODULE) global_dll_handle, module_file_name, max_len);
		module_file_name[max_len-1] = 0;
		
		DWORD handle;
		UINT  size = GetFileVersionInfoSizeW (module_file_name, &handle);
		
		if (size)
		{
			version_data = new BYTE[size];
			
			if ( (version_data)
			  && (GetFileVersionInfoW (module_file_name, handle, size, version_data)) )
			{
			}
		}
	}
	
	if ( (version_data)
	  && (key != 0)
	  && (info == 0) )
	{
		struct TRANSLATION
		{
			WORD langID;
			WORD charset;
		};
		
		TRANSLATION* translation;
		UINT info_len;
		
		if (VerQueryValueW (version_data, L"\\VarFileInfo\\Translation", (LPVOID*) &translation, &info_len))
		{
			const int max_len = 60;
			wchar_t name[max_len];
			_snwprintf (name, max_len, L"\\StringFileInfo\\%04x%04x\\%s", translation->langID, translation->charset, key);
			
			VerQueryValueW (version_data, name, (LPVOID*) &info, &info_len);
		}
	}
#endif
	
	return info;
}

/*****************************************************************************/

const wchar_t*
AggGetVersion()
{
#if defined(USE_WIN32_API)
	//	TODO: find the file version by some other platform specific means...
	version_file_version = L"2, 4, 0, 0";
#endif
	return GetVersionInfo (L"FileVersion", version_file_version);
}


const wchar_t*
AggGetProductName()
{
#if defined(USE_WIN32_API)
	//	TODO: find the product name by some other platform specific means...
	version_product_name = L"Anti-Grain Geometry Graphics Library";
#endif
	
	return GetVersionInfo (L"ProductName", version_product_name);
}

/*****************************************************************************/
