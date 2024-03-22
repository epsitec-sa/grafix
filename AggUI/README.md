# AggUI

C# bindings for the Antigrain C++ library.

## Building

Make sure to have all build dependencies installed before building.
Inside your project root directory, run:
```
dotnet build
```

### Installing build dependencies

- dotnet
- python
- cmake

On windows and linux, no other additional dependencies are needed.

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

If you have installed the build dependencies above, you already have everything required and can skip this section.

Install the following tools:
- dotnet
- python

On windows and linux, no other additional dependencies are needed.

On macos, AggUI relies on Xorg to display it's windows.
Install Xorg through [macports](https://www.macports.org/install.php):
```
sudo port install xorg-server
```
You then need to log-out / log back in into your session for xorg to install properly.

