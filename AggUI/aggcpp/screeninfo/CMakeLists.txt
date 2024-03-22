
message("build screeninfo: ${CMAKE_CURRENT_SOURCE_DIR}")
include_directories( "${CMAKE_CURRENT_SOURCE_DIR}" )
if(WIN32)
    message("screeninfo build for win32")
    add_library( screeninfo
        win32/screeninfo.cpp
    )
endif()
if(UNIX)
    message("screeninfo build for unix")
    add_library( screeninfo
        X11/screeninfo.cpp
    )
endif()
