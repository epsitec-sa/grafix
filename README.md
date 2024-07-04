# Grafix (a.k.a AggUI)

C# bindings for the C++ Antigrain Geometry library.

## Usage

### Installing runtime dependencies

To run this software, you need a dotnet runtime.

If you have installed the [build dependencies](./BUILDING.md), you already have everything required and can skip this section.

On windows and linux, no other additional dependencies are needed.

On macos, AggUI relies on Xorg to display it's windows.
Install Xorg through [macports](https://www.macports.org/install.php):

```
sudo port install xorg-server
```

You then need to log-out / log back in into your session for xorg to install properly.

### Example

Look at [AggUIExample](./AggUIExample/) for an example use of this library.

To run the example, call `dotnet run` from inside the example root directory:

## Building

See [BUILDING.md](./BUILDING.md)

## Authors

