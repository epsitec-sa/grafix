// This is the main DLL file.

//#define	AGGDLL	__declspec(dllimport)

#pragma unmanaged
#define AGG_DUMMY_TYPES
#include "../AntiGrain.Win32/interface.h"
#pragma managed

#include <malloc.h>

#using <mscorlib.dll>

#include "AntiGrain.h"

