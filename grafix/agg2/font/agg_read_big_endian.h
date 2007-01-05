/*
 *	agg_read_big_endian.h
 *
 *	Byte swapping functions, needed to read data in big endian format from the
 *	Open Type tables.
 *
 *	(C) Copyright 1996, 1997, Alain Malek, original development.
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

#ifndef AGG_SWAPFUNCS_INCLUDED
#define AGG_SWAPFUNCS_INCLUDED

#include "agg_basics.h"

/*****************************************************************************/

namespace agg
{
#if defined BIG_ENDIAN
	
	static inline int32u read_big_endian(int32u val)	{ return val; }
	static inline int32  read_big_endian(int32 val)		{ return val; }
	static inline int16u read_big_endian(int16u val)	{ return val; }
	static inline int16  read_big_endian(int16 val)		{ return val; }
	
#else /* if not BIG_ENDIAN */

  #if defined _MSVC
	
	static inline int32u read_big_endian(int32u val)
	{
		int32u res;
		
		__asm mov eax,(val)
		__asm bswap eax
		__asm mov (res),eax;
		
		return res;
	}

	static inline int32 read_big_endian(int32 val)
	{
		return read_big_endian (static_cast<int32u> (val));
	}

	static inline int16u read_big_endian(int16u val)
	{
		int16u res;
		
		__asm mov ax,(val)
		__asm ror ax,8
		__asm mov (res),ax;
		
		return res;
	}

	static inline int16 read_big_endian(int16 val)
	{
		int16 res;
		
		__asm mov ax,(val)
		__asm ror ax,8
		__asm mov (res),ax;
		
		return res;
	}
	
  #else /* if not _MSVC */
	
	static inline int32u read_big_endian(int32u val)
	{
		int8u b1 = static_cast<int8u> (val >> 24);
		int8u b2 = static_cast<int8u> (val >> 16);
		int8u b3 = static_cast<int8u> (val >>  8);
		int8u b4 = static_cast<int8u> (val >>  0);
		
		return (b1) | (b2 << 8) | (b3 << 16) | (b4 << 24);
	}

	static inline int32 read_big_endian(int32 val)
	{
		return read_big_endian (static_cast<int32u> (val));
	}

	static inline int16u read_big_endian(int16u val)
	{
		int8u b1 = static_cast<int8u> (val >>  8);
		int8u b2 = static_cast<int8u> (val >>  0);
		
		return (b1) | (b2 << 8);
	}

	static inline int16 read_big_endian(int16 val)
	{
		return read_big_endian (static_cast<int16u> (val));
	}
	
  #endif
#endif
}

/*****************************************************************************/

#endif /* AGG_SWAPFUNCS_INCLUDED */
