PROJECT( antigrain )

# additional are modified Find routines
SET ( CMAKE_MODULE_PATH "${antigrain_SOURCE_DIR}/bin" )

CMAKE_MINIMUM_REQUIRED( VERSION 3.13 )

SET(AGG_MAJOR_VERSION 0 )
SET(AGG_MINOR_VERSION 1 )
SET(AGG_BUILD_VERSION 1 )

SET( AGG_FLAGS "" )
SET( AGG_INCLUDE_DIRS "" )
SET( AGG_LIBRARY_DIRS "" )
SET( AGG_LIBRARIES "" )

SET (LIBRARY_OUTPUT_PATH ${antigrain_BINARY_DIR}/lib/ CACHE PATH "Single output directory for building all libraries." FORCE )
SET( AGG_LIBRARY_DIRS  lib )

LINK_DIRECTORIES(  ${antigrain_BINARY_DIR}/lib )

OPTION( agg_USE_GPC "Use Gpc Boolean library" OFF)
OPTION( agg_USE_FREETYPE "Use Freetype library" OFF)
OPTION( agg_USE_EXPAT "Use Expat library" OFF)
OPTION( agg_USE_SDL_PLATFORM "Use SDL as platform" OFF)
OPTION( agg_USE_PACK "Package Agg" OFF)
OPTION( agg_USE_AGG2D "Agg 2D graphical context" OFF)
OPTION( agg_USE_DEBUG "For debug version" OFF)

IF( agg_USE_DEBUG )
    #SET( PFDEBUG "d" )
    SET( CMAKE_DEBUG_POSTFIX "d" )
ENDIF( agg_USE_DEBUG )

# for the moment this decides the platform code.
IF(WIN32)
    ADD_DEFINITIONS( -D_MSWVC_ -D_CRT_SECURE_NO_WARNINGS -D_CRT_SECURE_NO_DEPRECATE )
    SET( WIN32GUI WIN32 )    
    INCLUDE_DIRECTORIES( ${antigrain_SOURCE_DIR}/font_win32_tt )
# PATCHED: use absolute path for includes
set( AGG_INCLUDE_DIRS ${AGG_INCLUDE_DIRS} ${antigrain_SOURCE_DIR}/font_win32_tt )    
ENDIF()

IF(UNIX)
    ADD_DEFINITIONS( -D__UNIX__  )
    SET( WIN32GUI "" )

    FIND_PACKAGE(X11)
    IF(X11_FOUND)  
        message("found x11 at ${X11_INCLUDE_DIRS}")
        INCLUDE_DIRECTORIES(${X11_INCLUDE_DIRS})
            # PATCHED: special include dir for x11 on macos
            if(APPLE)
                message("add /opt/local/include to find x11 on macos")
                include_directories("/opt/local/include")
            endif()
        LINK_LIBRARIES(${X11_LIBRARIES})
    ENDIF(X11_FOUND)

ENDIF(UNIX)

# more specific set platform code part to use for different compilers/tool sets
IF ( ${CMAKE_GENERATOR} STREQUAL "MSYS Makefiles" )
    SET (CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG" CACHE STRING
        "Flags used by the compiler during release builds" FORCE)
    SET (CMAKE_CX_FLAGS_RELEASE "-DNDEBUG" CACHE STRING
        "Flags used by the compiler during release builds" FORCE)       
ENDIF ( ${CMAKE_GENERATOR} STREQUAL "MSYS Makefiles" )

IF ( ${CMAKE_GENERATOR} STREQUAL "MinGW Makefiles" )
    
ENDIF ( ${CMAKE_GENERATOR} STREQUAL "MinGW Makefiles" )

IF ( ${CMAKE_GENERATOR} STREQUAL "Unix Makefiles" )
    IF( CYGWIN OR MINGW )
        SET (CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG" CACHE STRING
            "Flags used by the compiler during release builds" FORCE)
        SET (CMAKE_C_FLAGS_RELEASE "-DNDEBUG" CACHE STRING
            "Flags used by the compiler during release builds" FORCE)
    ENDIF( CYGWIN OR MINGW )    
ENDIF ( ${CMAKE_GENERATOR} STREQUAL "Unix Makefiles" )

IF ( ${CMAKE_GENERATOR} MATCHES "Visual Studio.*" )
    
ENDIF ( ${CMAKE_GENERATOR} MATCHES "Visual Studio.*" )

IF ( ${CMAKE_GENERATOR} MATCHES "Borland Makefiles" )

ENDIF ( ${CMAKE_GENERATOR} MATCHES "Borland Makefiles" )

##################################################
# Set all includes, flags, libraries, related to expat
##################################################

IF( agg_USE_EXPAT )

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

message("antigrain main CMakeLists check freetype")
IF( agg_USE_FREETYPE )
	message("find package freetype")
    FIND_PACKAGE( Freetype )
	message("FREETYPE_FOUND: ${FREETYPE_FOUND}")
	message("FREETYPE_LIBRARY: ${FREETYPE_LIBRARY}")
    IF( FREETYPE_FOUND )
		message("include directories")
        INCLUDE_DIRECTORIES( ${FREETYPE_INCLUDE_DIRS} )
		message("link libraries")
        LINK_LIBRARIES( ${FREETYPE_LIBRARIES} )
        LINK_DIRECTORIES( ${FREETYPE_LINK_DIR} )        
    ELSE( FREETYPE_FOUND )
        MESSAGE(SEND_ERROR "freetype not found")
    ENDIF( FREETYPE_FOUND )
ENDIF( agg_USE_FREETYPE )

##################################################
# Set all includes, flags, libraries, related to SDL
##################################################

FIND_PACKAGE( SDL QUIET )
IF( SDL_FOUND )
    IF ( agg_USE_SDL_PLATFORM )
        INCLUDE_DIRECTORIES(${SDL_INCLUDE_DIR})
        LINK_LIBRARIES(${SDL_LIBRARY})
    ENDIF ( agg_USE_SDL_PLATFORM )
ELSE( SDL_FOUND )
    IF ( agg_USE_SDL_PLATFORM )
        MESSAGE( "SDL libray was not found, disable agg_USE_SDL_PLATFORM please" )
    ENDIF ( agg_USE_SDL_PLATFORM )
ENDIF( SDL_FOUND )

# the main include dir of Agg
INCLUDE_DIRECTORIES( ${antigrain_SOURCE_DIR}/include )
# PATCHED: use absolute path for includes
SET( AGG_INCLUDE_DIRS ${AGG_INCLUDE_DIRS} ${antigrain_SOURCE_DIR}/include )    

# freetype specific lib of Agg
IF( agg_USE_FREETYPE )
    INCLUDE_DIRECTORIES( ${antigrain_SOURCE_DIR}/font_freetype )    
    # PATCHED: use absolute path for includes
    SET( AGG_INCLUDE_DIRS ${AGG_INCLUDE_DIRS} ${antigrain_SOURCE_DIR}/font_freetype )    
    ADD_DEFINITIONS( -DAGG_USE_FREETYPE )
    SET( AGG_FLAGS ${AGG_FLAGS} -DAGG_USE_FREETYPE )
	# PATCHED: do not link freetypefont to itself
    # LINK_LIBRARIES( freetypefont )
    # PATCHED: set the original names in AGG_LIBRARIES
    SET( AGG_LIBRARIES ${AGG_LIBRARIES} freetypefont${PFDEBUG} ) 
ENDIF( agg_USE_FREETYPE )

# GPC lib if used within Agg
IF ( agg_USE_GPC )
    INCLUDE_DIRECTORIES( ${antigrain_SOURCE_DIR}/gpc )
    # PATCHED: use absolute path for includes
    SET( AGG_INCLUDE_DIRS ${AGG_INCLUDE_DIRS} ${antigrain_SOURCE_DIR}/gpc )    
    ADD_DEFINITIONS( -DAGG_USE_GPC )
    SET( AGG_FLAGS ${AGG_FLAGS} -DAGG_USE_GPC )    
    # PATCHED: do not link library to itself
    # link_libraries( gpcbool )
    # PATCHED: set the original names in AGG_LIBRARIES
    SET( AGG_LIBRARIES ${AGG_LIBRARIES} gpcbool${PFDEBUG} ) 
ENDIF ( agg_USE_GPC )

# agg2d lib if used within Agg
IF ( agg_USE_AGG2D )
    INCLUDE_DIRECTORIES( ${antigrain_SOURCE_DIR}/agg2d )
    # PATCHED: use absolute path for includes
    SET( AGG_INCLUDE_DIRS ${AGG_INCLUDE_DIRS} ${antigrain_SOURCE_DIR}/agg2d )    
    ADD_DEFINITIONS( -DAGG_USE_AGG2D )
    OPTION( agg_USE_AGG2D_FREETYPE "Agg 2D graphical context uses freetype" OFF)    
    SET( AGG_FLAGS ${AGG_FLAGS} -DAGG_USE_AGG2D )    
    LINK_LIBRARIES( agg2d )
    SET( AGG_LIBRARIES ${AGG_LIBRARIES} agg2d${PFDEBUG} ) 
ENDIF ( agg_USE_AGG2D )

IF ( agg_USE_AGG2D_FREETYPE )
    ADD_DEFINITIONS( -DAGG2D_USE_FREETYPE )
    SET( AGG_FLAGS ${AGG_FLAGS} -DAGG2D_USE_FREETYPE )    
ENDIF ( agg_USE_AGG2D_FREETYPE )

# sld as platform or os
IF( SDL_FOUND AND agg_USE_SDL_PLATFORM )
    # PATCHED: do not link library to itself
    # link_libraries( controls sdlplatform antigrain )
    # PATCHED: set the original names in AGG_LIBRARIES
    SET( AGG_LIBRARIES ${AGG_LIBRARIES} controls${PFDEBUG} sdlplatform${PFDEBUG} antigrain${PFDEBUG} )
ELSE( SDL_FOUND AND agg_USE_SDL_PLATFORM )
    # PATCHED: do not link library to itself
    # link_libraries( controls platform antigrain )
    # PATCHED: set the original names in AGG_LIBRARIES
    SET( AGG_LIBRARIES ${AGG_LIBRARIES} controls${PFDEBUG} platform${PFDEBUG} antigrain${PFDEBUG} )
ENDIF( SDL_FOUND AND agg_USE_SDL_PLATFORM )

SET( AGG_FLAGS ${AGG_FLAGS} CACHE STRING "Agg package flags" FORCE )
SET( AGG_INCLUDE_DIRS ${AGG_INCLUDE_DIRS} CACHE STRING "Agg package libs include paths" FORCE )
SET( AGG_LIBRARY_DIRS ${AGG_LIBRARY_DIRS} CACHE STRING "Agg package libs directory paths" FORCE )
SET( AGG_LIBRARIES ${AGG_LIBRARIES} CACHE STRING "Agg package libraries" FORCE )

ADD_SUBDIRECTORY( src )

# PATCHED: do not build examples
# add_subdirectory( examples )

CONFIGURE_FILE( ${antigrain_SOURCE_DIR}/bin/AggConfig.cmake.in
                ${antigrain_BINARY_DIR}/bin/AggConfig.cmake
                @ONLY IMMEDIATE )

CONFIGURE_FILE( ${antigrain_SOURCE_DIR}/bin/AggConfigOutBuild.cmake.in
                ${antigrain_BINARY_DIR}/bin/AggConfigOutBuild.cmake
                @ONLY IMMEDIATE )
                
CONFIGURE_FILE( ${antigrain_SOURCE_DIR}/bin/FindAgg.cmake
                ${antigrain_BINARY_DIR}/myapp/FindAgg.cmake
                @ONLY IMMEDIATE )

CONFIGURE_FILE( ${antigrain_SOURCE_DIR}/bin/UseAgg.cmake.in
                ${antigrain_BINARY_DIR}/bin/UseAgg.cmake
                @ONLY IMMEDIATE )

SET( prefix ${CMAKE_INSTALL_PREFIX} )
SET( exec_prefix ${CMAKE_INSTALL_PREFIX}/bin )
SET( libdir ${CMAKE_INSTALL_PREFIX}/lib )
SET( includedir ${CMAKE_INSTALL_PREFIX}/include )

CONFIGURE_FILE( ${antigrain_SOURCE_DIR}/libagg.pc.in libagg.pc
                @ONLY )


# PATCHED: do not build example app
# add_subdirectory( myapp )

INSTALL( FILES ${antigrain_BINARY_DIR}/bin/AggConfigOutBuild.cmake DESTINATION "bin" RENAME AggConfig.cmake )
INSTALL( FILES ${antigrain_BINARY_DIR}/bin/AggConfig.cmake DESTINATION "bin" )
INSTALL( FILES ${antigrain_BINARY_DIR}/bin/UseAgg.cmake DESTINATION "bin" )
INSTALL( FILES ${antigrain_BINARY_DIR}/libagg.pc DESTINATION "lib/pkgconfig" )

#-------------------------------------------------------------------
# Build a CPack installer if CPack is available and this is a build 
IF ( agg_USE_PACK )    
    IF(EXISTS "${CMAKE_ROOT}/Modules/CPack.cmake")
        SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Agg - Vector Graphics")
        SET(CPACK_PACKAGE_VENDOR "Agg")
        SET(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/copying")
        SET(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/copying")
        SET(CPACK_PACKAGE_VERSION_MAJOR "${AGG_MAJOR_VERSION}")
        SET(CPACK_PACKAGE_VERSION_MINOR "${AGG_MINOR_VERSION}")
        SET(CPACK_PACKAGE_VERSION_PATCH "${AGG_BUILD_VERSION}")
        SET(CPACK_PACKAGE_INSTALL_DIRECTORY "AGG_${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}")
        SET(CPACK_SOURCE_PACKAGE_FILE_NAME "agg-${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}.${CPACK_PACKAGE_VERSION_PATCH}")
        SET(CPACK_PACKAGE_EXECUTABLES
        "agg" "AGG"
        )
        SET(CPACK_SOURCE_STRIP_FILES "")
        SET(CPACK_STRIP_FILES "bin/ccmake;bin/cmake;bin/cpack;bin/ctest")
 

        IF(WIN32)
            SET(CPACK_NSIS_DISPLAY_NAME "${CPACK_PACKAGE_INSTALL_DIRECTORY}")
            SET(CPACK_NSIS_HELP_LINK "http://agg.sourceforge.net")
            SET(CPACK_NSIS_URL_INFO_ABOUT "http://agg.sourceforge.net")
            SET(CPACK_NSIS_CONTACT "http://agg.sourceforge.net")
        ENDIF(WIN32)

        INCLUDE(CPack)
    ENDIF(EXISTS "${CMAKE_ROOT}/Modules/CPack.cmake")   
ENDIF ( agg_USE_PACK )

INCLUDE( myapp/myproject.cmake )
