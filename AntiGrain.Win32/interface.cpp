#include "interface.h"
#include "structures.h"

#include <windows.h>
#include <stdio.h>



static BYTE* version_data = 0;
static wchar_t* version_file_version = 0;
static wchar_t* version_product_name = 0;


bool AggInitialise()
{
	return true;
}

void AggShutDown()
{
	if (version_data)
	{
		delete version_data;
		
		version_data         = 0;
		version_file_version = 0;
	}
}

void AggNoOp()
{
}

void AggNoOpString(const wchar_t* text)
{
}

const wchar_t* AggGetVersionInfo(const wchar_t* key, wchar_t*& info)
{
	if ( (version_data == 0)
	  && (global_dll_handle) )
	{
		const int max_len = 400;
		wchar_t module_file_name[max_len];
		
		GetModuleFileNameW ((HMODULE) global_dll_handle, module_file_name, max_len);
		module_file_name[max_len-1] = 0;
		
		DWORD handle;
		UINT  size = GetFileVersionInfoSizeW (module_file_name, &handle);
		
		if (size)
		{
			version_data = new BYTE[size];
			
			if ( (version_data)
			  && (GetFileVersionInfoW (module_file_name, handle, size, version_data)) )
			{
			}
		}
	}
	
	if ( (version_data)
	  && (key != 0)
	  && (info == 0) )
	{
		struct TRANSLATION
		{
			WORD langID;
			WORD charset;
		};
		
		TRANSLATION* translation;
		UINT info_len;
		
		if (VerQueryValueW (version_data, L"\\VarFileInfo\\Translation", (LPVOID*) &translation, &info_len))
		{
			const int max_len = 60;
			wchar_t name[max_len];
			_snwprintf (name, max_len, L"\\StringFileInfo\\%04x%04x\\%s", translation->langID, translation->charset, key);
			
			VerQueryValueW (version_data, name, (LPVOID*) &info, &info_len);
		}
	}
	
	return info;
}


const wchar_t* AggGetVersion()
{
	return AggGetVersionInfo (L"FileVersion", version_file_version);
}


const wchar_t* AggGetProductName()
{
	return AggGetVersionInfo (L"ProductName", version_product_name);
}

void AggDebugGetCycles(unsigned int& h, unsigned int& l)
{
	unsigned __int64 c = GetCycleCount ();
	h = (unsigned int)(c >> 32);
	l = (unsigned int)(c);
}

int AggDebugGetCycleDelta()
{
	static unsigned __int64 cycles = GetCycleCount ();
	unsigned __int64 now = GetCycleCount ();
	unsigned __int64 delta = now - cycles;
	cycles = now;
	return static_cast<int> (delta);
}


static int exception_filter(EXCEPTION_POINTERS * pex)
{
	char text[10000];
	sprintf (text, "Ex.code = %08x at %08p - start at %08p\n"
		/**/	   "EAX=%08X EBX=%08X ECX=%08X EDX=%08X\n"
		/**/	   "EIP=%08X EBP=%08X ESP=%08X\n",
		/**/	   pex->ExceptionRecord->ExceptionCode,
		/**/	   pex->ExceptionRecord->ExceptionAddress,
		/**/	   & AggDebugTrapZeroPointer,
		/**/	   pex->ContextRecord->Eax,
		/**/	   pex->ContextRecord->Ebx,
		/**/	   pex->ContextRecord->Ecx,
		/**/	   pex->ContextRecord->Edx,
		/**/	   pex->ContextRecord->Eip,
		/**/	   pex->ContextRecord->Ebp,
		/**/	   pex->ContextRecord->Esp);
	OutputDebugString (text);
	
	return EXCEPTION_CONTINUE_SEARCH;
}

void AggDebugTrapZeroPointer()
{
	__try
	{
		int* ptr = (int*)(0);
		ptr[0] = 0;
	}
	__except(exception_filter(GetExceptionInformation()))
	{
	}
}
