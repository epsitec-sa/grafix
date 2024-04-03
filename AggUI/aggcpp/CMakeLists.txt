cmake_minimum_required(VERSION 3.5)

PROJECT( AggCPP )

# message("XX: '${XX}'")
function(dump_cmake_variables)
    get_cmake_property(_variableNames VARIABLES)
    list (SORT _variableNames)
    foreach (_variableName ${_variableNames})
        if (ARGV0)
            unset(MATCHED)
            string(REGEX MATCH ${ARGV0} MATCHED ${_variableName})
            if (NOT MATCHED)
                continue()
            endif()
        endif()
        message(STATUS "${_variableName}=${${_variableName}}")
    endforeach()
endfunction()

# We use a python script to patch agg before building it.
# See inside the script for details about what is being patched.
set(antigrain_patch bash "${CMAKE_CURRENT_SOURCE_DIR}/patch_agg.sh" "agg-src")

# this option is necessary to avoid link errors
# antigrain is a static library, but we will link it into a dynamic library
# so we need to enable PIC
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

message("Fetching antigrain. This can take some time.")
include(FetchContent)
FetchContent_Declare(
  antigrain
  GIT_REPOSITORY https://github.com/ghaerr/agg-2.6.git
  GIT_TAG        c4f36b4432142f22c0bf82c6fbdb41567a236be2
  GIT_PROGRESS   ON
  SOURCE_SUBDIR  agg-src 
  PATCH_COMMAND  ${antigrain_patch}
  OVERRIDE_FIND_PACKAGE
)
# Our code is using GPC so we enable it here.
set(agg_USE_GPC ON)
FetchContent_MakeAvailable(antigrain)

# for the moment this decides the platform code.
IF(WIN32)
    message("windows configuration")
    ADD_DEFINITIONS( -D_MSWVC_ -D_CRT_SECURE_NO_WARNINGS -D_CRT_SECURE_NO_DEPRECATE
                     -D_CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES=1
    )
    SET( WIN32GUI WIN32 )    
    INCLUDE_DIRECTORIES( ${antigrain_SOURCE_DIR}/font_win32_tt )
    INCLUDE_DIRECTORIES( ${antigrain_SOURCE_DIR}/font_freetype )
ENDIF(WIN32)

IF(UNIX)
    message("unix configuration")
    ADD_DEFINITIONS( -D__UNIX__  )
    SET( WIN32GUI "" )
    INCLUDE_DIRECTORIES( ${antigrain_SOURCE_DIR}/font_freetype )

    FIND_PACKAGE(X11)
    IF(X11_FOUND)  
        message("aggcpp: found x11")
        INCLUDE_DIRECTORIES(${X11_INCLUDE_DIRS})
        if(APPLE)
            message("add /opt/local/include to find x11 on macos")
            include_directories("/opt/local/include")
        endif()
        LINK_LIBRARIES(${X11_LIBRARIES})
    ENDIF(X11_FOUND)

ENDIF(UNIX)

##################################################
# Set all includes, flags, libraries, related to expat
##################################################

IF( agg_USE_EXPAT )
    message("use expat")

    FIND_PACKAGE( EXPAT )                    

    IF(EXPAT_FOUND)  
        INCLUDE_DIRECTORIES(${EXPAT_INCLUDE_DIRS})
        LINK_LIBRARIES(${EXPAT_LIBRARIES})
    ELSE(EXPAT_FOUND)  
        MESSAGE(SEND_ERROR "expat not found")
    ENDIF(EXPAT_FOUND)
ENDIF( agg_USE_EXPAT )
   
##################################################
# Set all includes, flags, libraries, related to freetype
##################################################

IF( agg_USE_FREETYPE )
    message("use freetype")
    FIND_PACKAGE( Freetype )                    
    IF( FREETYPE_FOUND )
        INCLUDE_DIRECTORIES( ${FREETYPE_INCLUDE_DIRS} )
        LINK_LIBRARIES( ${FREETYPE_LIBRARIES} )
        LINK_DIRECTORIES( ${FREETYPE_LINK_DIR} )
    ELSE( FREETYPE_FOUND )
        MESSAGE(SEND_ERROR "freetype not found")
    ENDIF( FREETYPE_FOUND )
ENDIF( agg_USE_FREETYPE )

##############################################################################
# C++ shared library
##############################################################################

# screeninfo subdirectory
add_subdirectory(screeninfo)

add_library(AntigrainCPP SHARED
    # agg_buffer.cpp
    # agg_font.cpp
    # agg_font_face.cpp
    # agg_font_opentype.cpp
    # agg_font_path_provider.cpp
    # agg_rasterizer.cpp
    rasterizer.cpp
    # agg_renderer.cpp
    antigrain.cpp
    graphic_context.cpp
    path.cpp
    # structures.cpp
)
set_target_properties(AntigrainCPP PROPERTIES
                      POSITION_INDEPENDENT_CODE ON)
target_compile_definitions(AntigrainCPP PRIVATE "EXPORTING_ANTIGRAIN_CPP")

target_include_directories(AntigrainCPP INTERFACE
                           $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

# antigrain headers
message("include agg headers: '${AGG_INCLUDE_DIRS}'")
target_include_directories(AntigrainCPP PRIVATE "${AGG_INCLUDE_DIRS}")

# compiler flags
add_library(compiler_flags INTERFACE)

set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

target_compile_options(compiler_flags INTERFACE
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
  "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)

target_link_libraries(AntigrainCPP PRIVATE compiler_flags screeninfo ${AGG_LIBRARIES})

file(MAKE_DIRECTORY "${CMAKE_SOURCE_DIR}/libs")
add_custom_command(TARGET AntigrainCPP POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy -t "${CMAKE_SOURCE_DIR}/libs" $<TARGET_FILE:AntigrainCPP>
    COMMAND_EXPAND_LISTS
)
