# Grafix (a.k.a AggUI)

AggUI is a library that allows you to build graphical applications.
It provides basic primitives to render shapes and texts to a memory buffer.
There is also an optional support for creating window and receiving input events.
The library supports windows, macos and linux systems.

## Design

AggUI mostly consists of C# bindings for some C++ libraries:
- [Antigrain Geometry](https://github.com/ghaerr/agg-2.6) for all the drawings
- [Freetype](https://freetype.org/) to read fonts

See [DESIGN.md](./DESIGN.md) for more details.

## Building

See [BUILDING.md](./BUILDING.md)

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

## Documentation

See [DOCUMENTATION.md](./DOCUMENTATION.md)

## Authors

The original bindings were developed by Pierre Arnaud and Daniel Roux.
They were refactored and adapted to be cross-platform by Roger Vuistiner and Baptiste Lambert.
