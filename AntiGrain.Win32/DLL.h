#pragma once

#if	defined(AGGWRAPPER_EXPORTS)
#define	AGGDLL	__declspec(dllexport)
extern void * global_dll_handle;
#else
#define	AGGDLL	__declspec(dllimport)
#endif

extern void Trace (const char* fmt, ...);

static inline __int64 GetCycleCount()
{
	__asm __emit 0x0f
	__asm __emit 0x31
}

