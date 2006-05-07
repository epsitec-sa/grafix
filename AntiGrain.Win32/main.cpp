//	main.cpp
//
//	Copyright © 2003-2006, Pierre ARNAUD, OPaC bright ideas, Ch. du Fontenay 6,
//	                       CH-1400 YVERDON, Switzerland. All rights reserved. 
//
//	Contact: pierre.arnaud@opac.ch, http://www.opac.ch
//	License: see license.txt

#include "win32.h"
#include "DLL.h"

#include <stdarg.h>
#include <stdio.h>

/*
 *	The "main" body provides the DLL plumbing required by Windows and
 *	a local wrapper for OutputDebugString, named Trace(), which works
 *	just like printf().
 */

/*****************************************************************************/

HANDLE global_dll_handle = 0;

/*****************************************************************************/

/*
 *	Remember the handle to the DLL (HINSTANCE, HMODULE), which is needed
 *	by the local GetVersionInfo function in "interface".
 */

BOOL WINAPI
DllMain (HANDLE dll_handle, DWORD reason, LPVOID reserved)
{
	switch (reason)
	{
		case DLL_PROCESS_ATTACH:
			global_dll_handle = dll_handle;
			break;
		
		case DLL_PROCESS_DETACH:
			global_dll_handle = NULL;
			break;
	}
	
	return TRUE;
}

/*****************************************************************************/

void
Trace (const char* fmt, ...)
{
	char buffer[1000] = { 0 };
	va_list ap;
	va_start (ap, fmt);
	_vsnprintf (buffer, sizeof (buffer)-1, fmt, ap);
	OutputDebugStringA (buffer);
	va_end (ap);
}

/*****************************************************************************/
