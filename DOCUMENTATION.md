# AggUI usage documentation

## Referencing the project

To use this library, you need to reference it inside you csproj file.

```xml
<ProjectReference Include="<adapt-this-path>\grafix\AggUI\AntigrainSharp.csproj" />
```

## Overview

Everything in this library lives in the `AntigrainSharp` namespace.

### Drawing with the GraphicContext

To draw anything with AggUI, you need a `GraphicContext`.

To draw shapes, the process is as follows:
- create the shape you want with a `Path`
- add that `Path` to a `Rasterizer`
- call one of the render method on the `Rasterizer` with one of the renderer of the `GraphicContext`

To draw text, the `GraphicContext` directly provides some useful methods (`DrawChar`, `DrawGlyph`, `DrawText`). If you need more control on how the text is rendered (e.g. to rotate it), use `AddGlyph` or `AddChar` on a `Rasterizer`.

:warning: Before drawing text, you should set a font in your `FontManager`.

Note that you cannot create a `GraphicContext` directly. How to get one depends on whether you want to render directly to a window through the built-in support or to an off-screen buffer.

### Using the built-in window support

To use the built-in window support, create a class that inherits from `AggWindow`.

You can then override the virtual method `OnDraw` to draw what you want in the window:

```c#
public override void OnDraw(GraphicContext gctx)
{
    // use the GraphicContext here to draw
}
```

There are other `On____` methods you can override to react to various events (mouse events, keyboard input, window resize…).

Then, to create a window and run the application:
- create an instance of your class inheriting from `AggWindow`
- call it's `Init` method to open the window
- call it's `Run` method to run the application event loop

### Drawing to an off-screen buffer

Instead of drawing to a window, we can also draw to an off-screen buffer.
This is achieved by creating a `GraphicBuffer`, which provides a `GraphicContext` property that can be used for drawing.

The graphic buffer comes in two flavors:
- `GraphicBuffer` creates and manages the low-level memory buffer for you. After drawing, you can retrieve it's data with methods like `GetBufferData`.
- `GraphicBufferExternalData` takes a handle to an external memory buffer and will draw to this external memory. You are responsible responsible of the proper lifetime management of this external memory buffer. Use this class only when you need to draw to a memory buffer managed by another library (e.g. drawing to an SDL Surface)

### Managing fonts

To be able to draw text, AggUI needs to read the glyph shapes from a font file.
This is managed by the `FontManager` class, which allows you to set a specific font to use for drawing text.

To help you manage fonts, AggUI also provides the `Font` class, which gives you access to usefull informations about a specific font face (font style like bold and italic, various glyph informations…)