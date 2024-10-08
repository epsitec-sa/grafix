﻿// Copyright © 2003-2024, EPSITEC SA, CH-1400 Yverdon-les-Bains, Switzerland
// Author: Pierre ARNAUD, Roger VUISTINER, Maintainer: Roger VUISTINER

using static AntigrainCPP.Native;

namespace AntigrainCPP
{
    public static partial class Rasterizer
    {
        public static IntPtr New()
        {
            return AggRasterizerNew();
        }
        public static void   Clear(IntPtr rasterizer)
        {
            AggRasterizerClear(rasterizer);
        }
        public static bool   HitTest(IntPtr rasterizer, int x, int y)
        {
            return AggRasterizerHitTest(rasterizer, x, y);
        }
        public static void   FillingRule(IntPtr rasterizer, int mode)
        {
            AggRasterizerFillingRule(rasterizer, mode);
        }
        public static void   Gamma(IntPtr rasterizer, double gamma)
        {
            AggRasterizerGamma(rasterizer, gamma);
        }
        public static void   SetTransform(IntPtr rasterizer, double xx, double xy, double yx, double yy, double tx, double ty)
        {
            AggRasterizerSetTransform(rasterizer, xx, xy, yx, yy, tx, ty);
        }
        public static void   SetClipBox(IntPtr rasterizer, double x1, double y1, double x2, double y2)
        {
            AggRasterizerSetClipBox(rasterizer, x1, y1, x2, y2);
        }
        public static void   ResetClipBox(IntPtr rasterizer)
        {
            AggRasterizerResetClipBox(rasterizer);
        }
        public static void   AddPath(IntPtr rasterizer, IntPtr path, bool curves)
        {
            AggRasterizerAddPath(rasterizer, path, curves);
        }
        public static void   AddGlyph(IntPtr rasterizer, IntPtr face, int glyph, double x, double y, double scale)
        {
            AggRasterizerAddGlyph(rasterizer, face, glyph, x, y, scale);
        }
        public static void   AddGlyphs(IntPtr rasterizer, IntPtr face, double scale, ushort[] glyphs, double[] xa, double[]? ya, double[]? sxa)
        {
            int n = glyphs.Length;

            if (ya is null)
            {
                if (sxa is null)
                {
                    for (int i = 0; i < n; i++)
                    {
                        AggRasterizerAddGlyphXY(rasterizer, face, glyphs[i], xa[i], 0, scale, scale);
                    }
                }
                else
                {
                    for (int i = 0; i < n; i++)
                    {
                        AggRasterizerAddGlyphXY(rasterizer, face, glyphs[i], xa[i], 0, sxa[i] * scale, scale);
                    }
                }
            }
            else
            {
                if (sxa is null)
                {
                    for (int i = 0; i < n; i++)
                    {
                        AggRasterizerAddGlyphXY(rasterizer, face, glyphs[i], xa[i], ya[i], scale, scale);
                    }
                }
                else
                {
                    for (int i = 0; i < n; i++)
                    {
                        AggRasterizerAddGlyphXY(rasterizer, face, glyphs[i], xa[i], ya[i], sxa[i] * scale, scale);
                    }
                }
            }
        }
        public static void   AddPathStroke1(IntPtr rasterizer, IntPtr path, double width, bool curves)
        {
            AggRasterizerAddPathStroke1(rasterizer, path, width, curves);
        }
        public static void   AddPathStroke2(IntPtr rasterizer, IntPtr path, double width, int cap, int join, double miter_limit, bool curves)
        {
            AggRasterizerAddPathStroke2(rasterizer, path, width, cap, join, miter_limit, curves);
        }
        public static void   RenderSolid(IntPtr rasterizer, IntPtr renderer)
        {
            AggRasterizerRenderSolid(rasterizer, renderer);
        }
        public static void   RenderImage(IntPtr rasterizer, IntPtr renderer)
        {
            AggRasterizerRenderImage(rasterizer, renderer);
        }
        public static void   RenderGradient(IntPtr rasterizer, IntPtr renderer)
        {
            AggRasterizerRenderGradient(rasterizer, renderer);
        }
        public static void   Delete(IntPtr rasterizer)
        {
            AggRasterizerDelete(rasterizer);
        }
    }
}
