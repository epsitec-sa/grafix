/*
This file is part of AggUI.

Copyright © 2003-2024, EPSITEC SA, 1400 Yverdon-les-Bains, Switzerland

AggUI is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
any later version.

AggUI is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

using System;
using System.Reflection;
using System.Runtime.InteropServices;
using static AntigrainSharp.Native;

namespace AntigrainSharp
{
    public class GraphicContext
    {
        private const string LibAgg = "AntigrainCPP";

        internal GraphicContext(IntPtr gctx)
        {
            this.gctx = gctx;
            IntPtr solid_ren = GraphicContext_GetSolidRenderer(gctx);
            this.RendererSolid = new AntigrainSharp.Renderer.Solid(solid_ren);
            IntPtr smooth_ren = GraphicContext_GetSmoothRenderer(gctx);
            this.RendererSmooth = new AntigrainSharp.Renderer.Smooth(smooth_ren);
            IntPtr image_ren = GraphicContext_GetImageRenderer(gctx);
            this.RendererImage = new AntigrainSharp.Renderer.Image(image_ren);
            IntPtr gradient_ren = GraphicContext_GetGradientRenderer(gctx);
            this.RendererGradient = new AntigrainSharp.Renderer.Gradient(gradient_ren);
        }

        internal GraphicContext(IntPtr gctx, uint width, uint height) : this(gctx)
        {
            this.Width = width;
            this.Height = height;
        }

        public void SetColor(double r, double g, double b, double a)
        {
            GraphicContext_SetColor(this.gctx, r, g, b, a);
        }

        public void DrawEllipse(double x, double y, double rx, double ry)
        {
            GraphicContext_DrawEllipse(this.gctx, x, y, rx, ry);
        }

        public double DrawChar(char character, double x, double y)
        {
            return GraphicContext_DrawChar(this.gctx, character, x, y);
        }

        public double DrawText(string text, double x, double y)
        {
            return GraphicContext_DrawText(this.gctx, text, x, y);
        }

        public double DrawGlyph(uint glyph, double x, double y)
        {
            return GraphicContext_DrawGlyph(this.gctx, glyph, x, y);
        }

        /* public static void Paint( */
        /*     IntPtr buffer, */
        /*     IntPtr face, */
        /*     double scale, */
        /*     ushort[] glyphs, */
        /*     double[] xa, */
        /*     double[]? ya, */
        /*     double[]? sxa, */
        /*     double r, double g, double b, double a, */
        /*     double xx, double yy, */
        /*     double tx, double ty */
        /* ){ */
        /*     int n = glyphs.Length; */
        /*     if (ya is null) */
        /*     { */
        /*         if (sxa is null) */
        /*         { */
        /*             double y = ty; */
        /*             double sx = scale * xx; */
        /*             double sy = scale * yy; */

        /*             for (int i = 0; i < n; i++) */
        /*             { */
        /*                 double x = xa[i] * xx + tx; */

        /*                 AggFontPixelCacheGlyphXY(buffer, face, glyphs[i], x, y, sx, sy, r, g, b, a); */
        /*             } */
        /*         } */
        /*         else */
        /*         { */
        /*             double y = ty; */
        /*             double sy = scale * yy; */

        /*             for (int i = 0; i < n; i++) */
        /*             { */
        /*                 double x = xa[i] * xx + tx; */
        /*                 double sx = sxa[i] * scale * xx; */

        /*                 AggFontPixelCacheGlyphXY(buffer, face, glyphs[i], x, y, sx, sy, r, g, b, a); */
        /*             } */
        /*         } */
        /*     } */
        /*     else if (sxa is null) */
        /*     { */
        /*         double sx = scale * xx; */
        /*         double sy = scale * yy; */

        /*         for (int i = 0; i < n; i++) */
        /*         { */
        /*             double x = xa[i] * xx + tx; */
        /*             double y = ya[i] * yy + ty; */

        /*             AggFontPixelCacheGlyphXY(buffer, face, glyphs[i], x, y, sx, sy, r, g, b, a); */
        /*         } */
        /*     } */
        /*     else */
        /*     { */
        /*         double sy = scale * yy; */

        /*         for (int i = 0; i < n; i++) */
        /*         { */
        /*             double x = xa[i] * xx + tx; */
        /*             double y = ya[i] * yy + ty; */
        /*             double sx = sxa[i] * scale * xx; */

        /*             AggFontPixelCacheGlyphXY(buffer, face, glyphs[i], x, y, sx, sy, r, g, b, a); */
        /*         } */
        /*     } */
        /* } */

        /* public static double Paint( */
        /*     IntPtr buffer, */
        /*     IntPtr face, */
        /*     ushort[] glyphs, */
        /*     double scale, */
        /*     double ox, double oy, */
        /*     double r, double g, double b, double a */
        /* ){ */
        /*     return AggFontPixelCacheFill( */
        /*         buffer, face, glyphs, glyphs.Length, scale, */
        /*         ox, oy, */
        /*         r, g, b, a */
        /*     ); */
        /* } */

        /* public static void Fill( */
        /*     IntPtr face, */
        /*     ushort[] glyphs, */
        /*     double scale, */
        /*     double ox, double oy */
        /* ){ */
        /*     AggFontPixelCacheFill( */
        /*         IntPtr.Zero, face, glyphs, glyphs.Length, scale, */
        /*         ox, oy, */
        /*         0.0, 0.0, 0.0, 0.0 */
        /*     ); */
        /* } */

        public AntigrainSharp.Renderer.Solid RendererSolid;
        public AntigrainSharp.Renderer.Smooth RendererSmooth;
        public AntigrainSharp.Renderer.Image RendererImage;
        public AntigrainSharp.Renderer.Gradient RendererGradient;

        public uint Width;
        public uint Height;

        private IntPtr gctx;
    }
}
