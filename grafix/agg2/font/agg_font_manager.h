/*
 *	agg_font_manager.h
 *
 *	Font Manager definitions.
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

#ifndef AGG_FONT_MANAGER_INCLUDED
#define AGG_FONT_MANAGER_INCLUDED

#include <memory.h>

/*****************************************************************************/

namespace agg
{
	class font_face;
	class font_manager;
	
	namespace open_type { struct table_name; }

	/*****************************************************************************/

	class font_manager
	{
		
	public:
		struct family_record
		{
			family_record*	prev;
			family_record*	next;
			
			wchar_t			name[32];
			
			font_face*		face_head;
			font_face*		face_tail;
			
			family_record ();
			~family_record ();
			
			void InsertFace (font_manager* manager, const void* os_description, size_t os_description_size, const wchar_t* os_name, const wchar_t* style_name, const wchar_t* script_name, const wchar_t* family_name, const open_type::table_name* ot_name);
			
			font_face* FindFace (const wchar_t* os_name) const;
			font_face* FindFace (const wchar_t* family_name, const wchar_t* style_name, const wchar_t* optical_name);
			
			int CountFaces () const;
			font_face* RetNthFace (int & nth) const;
			
			static bool LoadFontData (const void* os_description, void* & data, size_t & data_size);
			static void FreeFontData (void* data);
			static bool LoadFontAndReturnOsHandle (const void* os_description, void* & os_handle);
			static void FreeOsHandle (void* os_handle);
		};
		
	protected:
		mutable void*		thread_handle;		//	handle of async. initialisation thread
		
		family_record*		family_head;		//	first font family
		family_record*		family_tail;		//	last font family
		
	public:
		//	Internal methods, don't use...
		
		font_manager::family_record* FindFamily (const wchar_t* name);
		font_manager::family_record* NewFamilyRecord ();
		font_manager::family_record* RetFamilyHead ();
		
		void RemoveFamily (font_manager::family_record* family);
		void InsertFamily (font_manager::family_record* family);
		
		void BuildSystemFontList ();
		void WaitForSystemFontListCompleted () const;
		
	protected:
		//	Platform specific methods, used to asynchronously load the font descriptions and
		//	populate the family record list:
		
		static void PlatformStartInitThread (font_manager* manager);
		static void PlatformWaitForInitThread (void*& thread_handle);
		static void PlatformListFonts (font_manager* manager);
		
	private:
		font_manager (const font_manager & );
		font_manager & operator = (const font_manager & );
		
	public:
		font_manager ();
		virtual ~ font_manager ();
		
		bool Initialise ();
		
		font_face* FindFontFace (const wchar_t* os_face_name);
		font_face* FindFontFace (const wchar_t* family_name, const wchar_t* style_name, const wchar_t* optical_name = 0);
		font_face* RetNthFace (int nth) const;
		
		void ReduceMemoryUsage ();
		
		int CountFamilies () const;
		int CountFontFaces () const;
	};
}

/*****************************************************************************/

#endif /* AGG_FONT_MANAGER_INCLUDED */
