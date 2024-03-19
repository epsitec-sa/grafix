//	AntiGrain.Win32/settings.h
//
//	Copyright © 2003-2007, Pierre ARNAUD, OPaC bright ideas, Ch. du Fontenay 6,
//	                       CH-1400 YVERDON, Switzerland. All rights reserved. 
//
//	Contact: pierre.arnaud@opac.ch, http://www.opac.ch
//	License: see license.txt

#pragma once

//#define	USE_IPP
#define	USE_WIN32_API
#undef	USE_OLD_CLIPPING_CODE
#undef	USE_TRACE_DEBUGGING

#undef	EMULATE_CLEARTYPE_INTERPOLATE
#undef	EMULATE_CLEARTYPE_X3

#if defined(USE_WIN32_API)

#define	_CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES		1
#define	_CRT_SECURE_NO_DEPRECATE

#endif
