/*
 *	win32tempdc.h
 *
 *	Temporary DC wrapper. The TempDC class makes sure that the DC will be
 *	released on destruction.
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

#ifndef WIN32TEMPDC_INCLUDED
#define	WIN32TEMPDC_INCLUDED

#include "win32.h"

namespace Win32
{
	class TempDC
	{
		HDC	&				dc;
		HDC					internal_dc;
	public:
		TempDC () : dc (internal_dc), internal_dc (0)
		{
			this->dc = GetDC (0);
		}
		TempDC (HDC & dc_reference) : dc (dc_reference), internal_dc (0)
		{
			this->dc = GetDC (0);
		}
		
		~ TempDC ()
		{
			if (this->dc) {
				ReleaseDC (0, this->dc);
				this->dc = 0;
			}
		}
		
		operator HDC () const	{ return this->dc; }
	};
}

#endif /* WIN32TEMPDC_INCLUDED */
