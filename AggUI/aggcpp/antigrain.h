#pragma once


#if defined(_WIN32)
#  if defined(EXPORTING_ANTIGRAIN_CPP)
#    define DECLSPEC __declspec(dllexport)
#  else
#    define DECLSPEC __declspec(dllimport)
#  endif
#else // non windows
#  define DECLSPEC
#endif

#include "platform/agg_platform_support.h"
using namespace agg;


namespace AntigrainCPP {
    extern "C" DECLSPEC platform_support* NewPlatformSupport(pix_format_e format, bool flip_y);

    extern "C" DECLSPEC void PlatformSupport_Caption(platform_support* ps, const char* text);

    extern "C" DECLSPEC bool PlatformSupport_Init(platform_support* ps, 
                                                  unsigned width, unsigned height,
                                                  window_flag_e flags);

    extern "C" DECLSPEC int PlatformSupport_Run(platform_support* ps);
}
