# AggUI design

AggUI mostly consists of C# bindings for some C++ libraries:
- [Antigrain Geometry](https://github.com/ghaerr/agg-2.6) for all the drawings
- [Freetype](https://freetype.org/) to read fonts

## Overview

AggUI consists of two layers:
- a C++ library named `aggcpp` which uses antigrain and freetype and combines them into a higher-level toolbox for creating graphical applications
- a C# project with interop bindings to `aggcpp`, allowing to use the library from a C# project

## Build system

### Aggcpp

Aggcpp is built using [cmake](https://cmake.org/).

It's build script (`CMakeLists.txt`) consists of the following steps:
- clone the original antigrain repository
- apply our patches (details below)
- compile the original antigrain library
- compile aggcpp as a dynamic library

The resulting dynamic library is written to the `libs` folder.

#### Patching antigrain

Antigrain was developed with the intention that you would use it as a C++ library. It was not meant to be compiled into a dynamic library that is called from C#. Little adjustments to antigrain's build scripts were necessary to make aggcpp work.

The script `patch_agg.sh` is responsible of patching the library. It is invoked by `CMakeLists.txt` after cloning the antigrain repo. It works by overwritting files in the cloned antigrain repo by their corresponding patch found in the `agg_patch_files` directory. The lines that were patched are indicated in the patch file by a comment starting with "PATCHED" and followed by an explanation as to why the patch is necessary.

Note that the patch is only applied after the antigrain repository is *cloned*. If you make changes to the patch files, you will need to re-run `patch_agg.sh` manually. Another option is to delete the `build` directory: on the next build, antigrain will be redownloaded and your new patch applied.

### AggUI

AggUI's build script (`AggUI.csproj`) consists of the following steps:
- build aggcpp by invoking `aggcpp/build_lib.sh`
- copy the generated dynamic library from `aggcpp/libs` to the output directory
- compile AggUI

# Reference

[Antigrain Geometry](https://github.com/ghaerr/agg-2.6)

[Freetype](https://freetype.org/)