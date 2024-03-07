/*
 *	agg_turboheap.h
 *
 *	Basic Turbo Heap for very fast allocation (not best memory usage, but never
 *	mind, we want some fast code).
 *
 *	(C) Copyright 2003-2007, Pierre ARNAUD, OPaC bright ideas, Ch. du Fontenay 6,
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

#ifndef AGG_TURBOHEAP_INCLUDED
#define AGG_TURBOHEAP_INCLUDED

#include "agg_basics.h"

/*****************************************************************************/

namespace agg
{
	template<int32u SIZE, int32u ALIGN>
	class turbo_heap
	{
		struct data_heap
		{
			data_heap*			next;
			int8u*				data_free;
			int32u				data_size;
			int8u				data[SIZE];
		};
		
		data_heap*				heap;
		
	public:
		turbo_heap ()
		{
			this->heap = 0;
		}
		
		~turbo_heap ()
		{
			data_heap* heap = this->heap;
			
			while (heap)
			{
				data_heap* next = heap->next;
				delete heap;
				heap = next;
			}
			
			this->heap = 0;
		}
		
		int8u* alloc (int32u size)
		{
			size += ALIGN - 1;
			size &= 0xffffffff - ALIGN + 1;
			
			if ( (this->heap == 0)
			  || (this->heap->data_size < size) )
			{
				data_heap* heap = new data_heap;
				
				if (heap == 0)
				{
					throw "Memory full";
				}
				
				heap->next = this->heap;
				heap->data_free = heap->data;
				heap->data_size = SIZE;
				
				this->heap = heap;
			}
			
			int8u* data = this->heap->data_free;
			
			this->heap->data_free += size;
			this->heap->data_size -= size;
			
			return data;
		}
	};
}

/*****************************************************************************/

#endif /* AGG_TURBOHEAP_INCLUDED */
