import sys
import re
import textwrap
from pathlib import Path

SCRIPT_ROOT = Path(__file__).parent

"""
PATCHES is a dictionary that describes the patches that need to be applied to agg sources
Each key is the path of a file to patch (relative to the "agg-src" directory)
Each value is a list of patches to apply

Each patch consists in a tuple of three strings: `(comment_message, old_string, new_string)`
When applying a patch, `old_string` is search in the source file and replaced with `new_string`.
A comment is also added on the line above the patched line.
It contains the word "PATCHED" followed by `comment_message` that indicate the reason for this patch.

/!\ WHEN ADDING PATCH ENTRIES, MAKE SURE THEY ARE IDEMPOTENT.
"""
PATCHES = {
    "CMakeLists.txt": [
        (
            'use absolute path for includes',
            'SET( AGG_INCLUDE_DIRS ${AGG_INCLUDE_DIRS} include )',
            'SET( AGG_INCLUDE_DIRS ${AGG_INCLUDE_DIRS} ${antigrain_SOURCE_DIR}/include )'
        ),
        (
            'use absolute path for includes',
            'SET( AGG_INCLUDE_DIRS ${AGG_INCLUDE_DIRS} font_win32_tt )',
            'SET( AGG_INCLUDE_DIRS ${AGG_INCLUDE_DIRS} ${antigrain_SOURCE_DIR}/font_win32_tt )'
        ),
        (
            'use absolute path for includes',
            'SET( AGG_INCLUDE_DIRS ${AGG_INCLUDE_DIRS} font_freetype )',
            'SET( AGG_INCLUDE_DIRS ${AGG_INCLUDE_DIRS} ${antigrain_SOURCE_DIR}/font_freetype )'
        ),
        (
            'use absolute path for includes',
            'SET( AGG_INCLUDE_DIRS ${AGG_INCLUDE_DIRS} gpc )',
            'SET( AGG_INCLUDE_DIRS ${AGG_INCLUDE_DIRS} ${antigrain_SOURCE_DIR}/gpc )'
        ),
        (
            'use absolute path for includes',
            'SET( AGG_INCLUDE_DIRS ${AGG_INCLUDE_DIRS} agg2d )',
            'SET( AGG_INCLUDE_DIRS ${AGG_INCLUDE_DIRS} ${antigrain_SOURCE_DIR}/agg2d )'
        ),
        (
            'do not link library to itself',
            'LINK_LIBRARIES( gpcbool )',
            '# link_libraries( gpcbool )'
        ),
        (
            'do not link library to itself',
            'LINK_LIBRARIES( controls sdlplatform antigrain )',
            '# link_libraries( controls sdlplatform antigrain )',
        ),
        (
            'do not link library to itself',
            'LINK_LIBRARIES( controls platform antigrain )',
            '# link_libraries( controls platform antigrain )',
        ),
        (
            'set the original names in AGG_LIBRARIES',
            'SET( AGG_LIBRARIES ${AGG_LIBRARIES} gpc${PFDEBUG} )',
            'SET( AGG_LIBRARIES ${AGG_LIBRARIES} gpcbool${PFDEBUG} )',
        ),
        (
            'set the original names in AGG_LIBRARIES',
            'SET( AGG_LIBRARIES ${AGG_LIBRARIES} aggctrl${PFDEBUG} aggsdlplatform${PFDEBUG} agg${PFDEBUG} )',
            'SET( AGG_LIBRARIES ${AGG_LIBRARIES} controls${PFDEBUG} sdlplatform${PFDEBUG} antigrain${PFDEBUG} )',
        ),
        (
            'set the original names in AGG_LIBRARIES',
            'SET( AGG_LIBRARIES ${AGG_LIBRARIES} aggctrl${PFDEBUG} aggplatform${PFDEBUG} agg${PFDEBUG} )',
            'SET( AGG_LIBRARIES ${AGG_LIBRARIES} controls${PFDEBUG} platform${PFDEBUG} antigrain${PFDEBUG} )',
        ),
        (
            'do not build examples',
            'ADD_SUBDIRECTORY( examples )',
            '# add_subdirectory( examples )'
        ),
        (
            'do not build example app',
            'ADD_SUBDIRECTORY( myapp )',
            '# add_subdirectory( myapp )'
        ),
    ],
    "src/platform/win32/agg_platform_support.cpp": [
        (
            '''
            The agg library has been made with the assumption that you would use it from a C++ program.
            These global variables are normally set by the main entry point (`WinMain` function).
            Since we are building a shared library around antigrain (to use it with C#),
            we never call `WinMain` so we need to set these global variables here.
            ''',
            'HINSTANCE g_windows_instance = 0;',
            'HINSTANCE g_windows_instance = NULL;'
        ),
        (
            'See comment above.',
            'int       g_windows_cmd_show = 0;',
            'int       g_windows_cmd_show = SW_NORMAL;'
        ),
    ],
}

def get_comment_string(extension):
    if extension == ".txt":
        return "#"
    elif extension == ".cpp":
        return "//"
    raise NotImplementedException(f"No known comment string for file extension {extension}")

def patch_file(file_to_patch, patch):
    with open(file_to_patch) as file:
        content = file.read()

    comment_string = get_comment_string(file_to_patch.suffix)
    new_content = patch_source(content, patch, comment_string)

    with open(file_to_patch, 'w') as file:
        file.write(new_content)

def patch_source(source, patch, comment_string):
    return "\n".join(
        (patch_line(line, patch, comment_string)
         for line in source.split("\n"))
    )

def patch_line(line, patch, comment_string):
    result = line
    for justification, old, new in patch:
        dedent = textwrap.dedent(justification)
        formatted_justification = textwrap.indent(dedent, f"{comment_string} ")
        replace = f'{comment_string} PATCHED: {formatted_justification}\n{new}'
        if line.strip() == old:
            result = line.replace(old, replace)
    return result

def main():
    '''
    This script patches some issues in the main antigrain CMakeLists.txt file.

    I tried to use git to generate the patch but I did not managed to make it
    work properly on both linux and windows: the patch would work only on one
    system and not the other because of the different line endings (LF / CRLF).
    '''
    agg_root = Path(sys.argv[1])
    for path, patch in PATCHES.items():
        file_to_patch = agg_root / path
        patch_file(file_to_patch, patch)

try:
    main()
except Exception as ex:
    with open(SCRIPT_ROOT  / 'log.txt', 'w') as file:
        file.write(str(ex))
        sys.exit(1)
