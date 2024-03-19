
message("build screeninfo: ${CMAKE_CURRENT_SOURCE_DIR}")
include_directories( "${CMAKE_CURRENT_SOURCE_DIR}" )
if(WIN32)
    add_library( screeninfo
        win32/screeninfo.cpp
    )
endif()
if(UNIX)
    add_library( screeninfo
        X11/screeninfo.cpp
    )
endif()
if(APPLE)
    add_library( screeninfo
        mac/screeninfo.cpp
    )
endif()