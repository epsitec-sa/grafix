/*
 *	win32.h
 *
 *	Plaform-dependent code.
 *
 *	(C) Copyright 2002-2006, Pierre ARNAUD, OPaC bright ideas, Ch. du Fontenay 6,
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

#ifndef WIN32_INCLUDED
#define	WIN32_INCLUDED

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#undef	WIN32_LEAN_AND_MEAN

/*****************************************************************************/

namespace OS
{
	inline void
	OutputDebugString (const char* string)
	{
		::OutputDebugStringA (string);
	}
	inline void
	Sleep (unsigned long time)
	{
		::Sleep (time);
	}
	class Lockable
	{
	public:
		virtual bool Enter (unsigned long time = 0xffffffff) = 0;
		virtual void Release () = 0;
	};
	class Event
	{
		void*		handle;
	public:
		Event () : handle (::CreateEventA (0,0,0,0))			{ }
		~ Event ()												{ ::CloseHandle (handle); }
		
		void Signal ()											{ ::SetEvent (handle); }
		void Pulse ()											{ ::PulseEvent (handle); }
		bool Wait (unsigned long time = 0xffffffff)				{ return ::WaitForSingleObject (handle, time) == 0 ? true : false; }
	};
	class Semaphore : public Lockable
	{
		void*		handle;
	public:
		Semaphore (long i = 0) : handle (::CreateSemaphoreA (0,i,1000,0))	{ }
		~ Semaphore ()											{ ::CloseHandle (handle); }
		
		void Signal ()											{ ::ReleaseSemaphore (handle,1,0); }
		bool Wait (unsigned long time = 0xffffffff)				{ return ::WaitForSingleObject (handle, time) == 0 ? true : false; }
		
		virtual bool Enter (unsigned long time = 0xffffffff)	{ return Wait (time); }
		virtual void Release ()									{ Signal (); }
	};
	class Lock : public Lockable
	{
		void*		handle;
	public:
		Lock () : handle (::CreateMutexA (0,0,0))				{ }
		~ Lock ()												{ ::CloseHandle (handle); }
		
		virtual bool Enter (unsigned long time = 0xffffffff)	{ return ::WaitForSingleObject (handle, time) == 0 ? true : false; }
		virtual void Release ()									{ ::ReleaseMutex (handle); }
	};
	class SafeCounter
	{
		int			n;
		Lock		lock;
	public:
		SafeCounter () : n (0), lock ()							{ }
		int operator ++ ()										{ int x; lock.Enter (); x = ++n; lock.Release (); return x; }
		int operator ++ (int)									{ int x; lock.Enter (); x = n++; lock.Release (); return x; }
		int operator -- ()										{ int x; lock.Enter (); x = --n; lock.Release (); return x; }
		int operator -- (int)									{ int x; lock.Enter (); x = n--; lock.Release (); return x; }
		virtual bool Enter (unsigned long time = 0xffffffff)	{ return lock.Enter (time); }
		virtual void Release ()									{ lock.Release (); }
		int & Value ()											{ return n; }
	};
	
	template<class T>
	class AutoLock
	{
		private:
			T&		lock;
		public:
			AutoLock (T& l) : lock (l)							{ lock.Enter (); }
			~AutoLock ()										{ lock.Release (); }
	};
	
	template<>
	class AutoLock<Lockable*>
	{
		private:
			Lockable*	lock;
		public:
			AutoLock (Lockable* l) : lock (l)					{ if (lock) lock->Enter (); }
			~AutoLock ()										{ if (lock) lock->Release (); }
	};
}

#endif /* WIN32_INCLUDED */
