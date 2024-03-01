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

