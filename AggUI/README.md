# AggUI

C# bindings for the Antigrain C++ library.

## Building

Make sure to have all build dependencies installed before building.
Inside your project root directory, run:
```
dotnet build
```

### Installing build dependencies

On all systems, you need:
- dotnet
- cmake
- a bash runtime
- freetype library (runtime and header files)

On linux, you should be able to install all the dependencies through your usual distribution package manager. No other additional dependencies are needed.

On windows, you should install git-bash for the bash runtime. You will also need to download and build the freetype library. See instructions bellow.

#### Building freetype (windows)

- Get the [freetype sources](https://download.savannah.gnu.org/releases/freetype/) and unpack them in some directory
- Inside the freetype directory, open the file `builds\windows\vc2010\freetype.slf` in VisualStudio. In the build options, select "Release Static" and build the solution.
- Set the environment variable `FREETYPE_DIR` to the location of the unpacked freetype directory before building AggUI (e.g. in PowerShell `$Env:FREETYPE_DIR="/path/to/freetype"`)

On macos, AggUI relies on Xorg to display it's windows.
Install Xorg through [macports](https://www.macports.org/install.php):
```
sudo port install xorg
```
You then need to log-out / log back in into your session for xorg to install properly.


## Running

Make sure to have all runtime dependencies installed before running.
Inside your project root directory, run:
```
dotnet run
```

### Installing runtime dependencies

To run this software, you need a dotnet runtime.

If you have installed the build dependencies above, you already have everything required and can skip this section.

On windows and linux, no other additional dependencies are needed.

On macos, AggUI relies on Xorg to display it's windows.
Install Xorg through [macports](https://www.macports.org/install.php):
```
sudo port install xorg-server
```
You then need to log-out / log back in into your session for xorg to install properly.

