//	AntiGrain.cpp
//
//	Copyright © 2003-2005, Pierre ARNAUD, OPaC bright ideas, Ch. du Fontenay 6,
//	                       CH-1400 YVERDON, Switzerland. All rights reserved. 
//
//	Contact: pierre.arnaud@opac.ch, http://www.opac.ch

// This is the main DLL file.

//#define	AGGDLL	__declspec(dllimport)

#pragma unmanaged
#define AGG_DUMMY_TYPES
#include "../AntiGrain.Win32/interface.h"
#pragma managed

#include <malloc.h>

#using <mscorlib.dll>

#include "AntiGrain.h"

