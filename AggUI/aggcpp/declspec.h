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
