//	AntiGrain.Win32/DLL.h
//
//	Copyright © 2003-2007, Pierre ARNAUD, OPaC bright ideas, Ch. du Fontenay 6,
//	                       CH-1400 YVERDON, Switzerland. All rights reserved. 
//
//	Contact: pierre.arnaud@opac.ch, http://www.opac.ch
//	License: see license.txt

#pragma once

#include "settings.h"

#if defined(USE_WIN32_API)
#if	defined(AGGWRAPPER_EXPORTS)

//	If compiling the DLL itself, AGGWRAPPER_EXPORTS is defined and we
//	mark every API entry as 'dllexport' so they can be easily accessed
//	by external code.

#define	AGGDLL	__declspec(dllexport)

extern void * global_dll_handle;
extern void Trace (const char* fmt, ...);

#else

//	If just including the *.h files of the DLL, we mark every API entry
//	as 'dllimport', so that the linker knows that these must be looked
//	for in an external DLL (in fact the *.lib stubs file associated to
//	the *.dll).

#define	AGGDLL	__declspec(dllimport)

#endif
#else

#define	AGGDLL

//	TODO: define AGGDLL in order to export the symbols when compiling

#endif
