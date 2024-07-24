# Building AggUI

Make sure to have all build dependencies installed before building.
Inside the project root directory, run:

```
dotnet build -p:Configuration=Release
```

You can set the configuration to `Release` to build everything (the C# bindings and the C++ libraries).
If you set the configuration to `Debug`, only the C# bindings are built.

## Installing build dependencies

On all systems, you need:

- dotnet
- cmake
- a bash runtime
- freetype library (runtime and header files)

On linux, you should be able to install all the dependencies through your usual distribution package manager. No other additional dependencies are needed.

On windows, you should install git-bash for the bash runtime. You will also need to download and build the freetype library. See instructions bellow.

### Building freetype (windows)

This step has been automated, these instructions are provided here as a reference.

- Get the [freetype sources](https://download.savannah.gnu.org/releases/freetype/) and unpack them in some directory
- Inside the freetype directory, open the file `builds\windows\vc2010\freetype.sln` in VisualStudio. In the build options, select "Release Static" and build the solution.
- Set the environment variable `FREETYPE_DIR` to the location of the unpacked freetype directory before building AggUI (e.g. in PowerShell `$Env:FREETYPE_DIR="/path/to/freetype"`)

### Installing Xorg on macos

On macos, AggUI relies on Xorg to display it's windows.
Note that this step is only necessary if you want to use the window system provided in AggUI.

Install Xorg through [macports](https://www.macports.org/install.php):

```
sudo port install xorg
```

You then need to log-out / log back in into your session for xorg to install properly.
