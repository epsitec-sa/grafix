cmake_minimum_required(VERSION 3.5)

project(AntiGrainWin VERSION 1.0)

if (MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

include(FetchContent)
FetchContent_Declare(
  antigrain
  GIT_REPOSITORY https://github.com/ghaerr/agg-2.6.git
  GIT_TAG        c4f36b4432142f22c0bf82c6fbdb41567a236be2
  SOURCE_SUBDIR  agg-src 
)
FetchContent_MakeAvailable(antigrain)


add_library(AntiGrainWin SHARED
    agg_buffer.cpp
    agg_font.cpp
    agg_font_face.cpp
    agg_font_opentype.cpp
    agg_font_path_provider.cpp
    agg_path.cpp
    agg_rasterizer.cpp
    agg_renderer.cpp
    fontface.cpp
    glue.cpp
    interface.cpp
    main.cpp
    structures.cpp
)
set_target_properties(AntiGrainWin PROPERTIES
                      POSITION_INDEPENDENT_CODE ON)
target_compile_definitions(AntiGrainWin PRIVATE "EXPORTING_AntiGrainWin")

target_include_directories(AntiGrainWin PRIVATE 
                           "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
                           "${antigrain_SOURCE_DIR}/agg-src/include"
)

###############################################################################
# compiler flags    

add_library(compiler_flags INTERFACE)

set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

target_compile_options(compiler_flags INTERFACE
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
  "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)
target_link_libraries(AntiGrainWin PUBLIC compiler_flags)

###############################################################################
# link antigrain

target_link_libraries(AntiGrainWin PUBLIC antigrain)

###############################################################################


add_custom_command(TARGET AntiGrainWin POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  $<TARGET_FILE:AntiGrainWin>
  "${CMAKE_SOURCE_DIR}/libs")
