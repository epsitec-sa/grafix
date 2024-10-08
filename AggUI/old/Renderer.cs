﻿// Copyright © 2003-2024, EPSITEC SA, CH-1400 Yverdon-les-Bains, Switzerland
// Author: Pierre ARNAUD, Roger VUISTINER, Maintainer: Roger VUISTINER

using static AntigrainCPP.Native;

namespace AntigrainCPP
{
    public static partial class Renderer
    {
        public enum MaskComponent
        {
            None = -1,
            A    = 0,
            R    = 1,
            G    = 2,
            B    = 3,
        }
        public class Base { }
        public class Special : Renderer.Base
        {
            public static void Fill4Colors(IntPtr renderer, int x, int y, int dx, int dy, double r1, double g1, double b1, double r2, double g2, double b2, double r3, double g3, double b3, double r4, double g4, double b4)
            {
                AggRendererFill4Colors(renderer, x, y, dx, dy, r1, g1, b1, r2, g2, b2, r3, g3, b3, r4, g4, b4);
            }
        }
        public class Solid : Renderer.Base
        {
            public static IntPtr New(IntPtr buffer)
            {
                return AggRendererSolidNew(buffer);
            }
            public static void Clear(IntPtr renderer, double r, double g, double b, double a)
            {
                AggRendererSolidClear(renderer, r, g, b, a);
            }
            public static void Color(IntPtr renderer, double r, double g, double b, double a)
            {
                AggRendererSolidColor(renderer, r, g, b, a);
            }
            public static void Delete(IntPtr renderer)
            {
                AggRendererSolidDelete(renderer);
            }
            public static void SetAlphaMask(IntPtr renderer, IntPtr buffer, Renderer.MaskComponent component)
            {
                AggRendererSolidSetAlphaMask(renderer, buffer, (int)component);
            }
        }
        public class Smooth : Renderer.Base
        {
            public static IntPtr New(IntPtr buffer)
            {
                return AggRendererSmoothNew(buffer);
            }
            public static void Color(IntPtr renderer, double r, double g, double b, double a)
            {
                AggRendererSmoothColor(renderer, r, g, b, a);
            }
            public static void Setup(IntPtr renderer, double r1, double r2, double xx, double xy, double yx, double yy, double tx, double ty)
            {
                AggRendererSmoothSetup(renderer, r1, r2, xx, xy, yx, yy, tx, ty);
            }
            public static void AddPath(IntPtr renderer, IntPtr path)
            {
                AggRendererSmoothAddPath(renderer, path);
            }
            public static void Delete(IntPtr renderer)
            {
                AggRendererSmoothDelete(renderer);
            }
            public static void SetAlphaMask(IntPtr renderer, IntPtr buffer, Renderer.MaskComponent component)
            {
                AggRendererSmoothSetAlphaMask(renderer, buffer, (int)component);
            }
        }
        public class Image : Renderer.Base
        {
            public static IntPtr New(IntPtr buffer)
            {
                return AggRendererImageNew(buffer);
            }
            public static void Matrix(IntPtr renderer, double xx, double xy, double yx, double yy, double tx, double ty)
            {
                AggRendererImageMatrix(renderer, xx, xy, yx, yy, tx, ty);
            }
            public static void Source1(IntPtr renderer, IntPtr buffer)
            {
                AggRendererImageSource1(renderer, buffer);
            }
            public static void Source2(IntPtr renderer, IntPtr byte_buffer, int dx, int dy, int stride)
            {
                AggRendererImageSource2(renderer, byte_buffer, dx, dy, stride);
            }
            public static void Delete(IntPtr renderer)
            {
                AggRendererImageDelete(renderer);
            }
            public static void SetStretchMode(IntPtr renderer, int mode, double radius)
            {
                AggRendererImageSetStretchMode(renderer, mode, radius);
            }
            public static void SetAlphaMask(IntPtr renderer, IntPtr buffer, Renderer.MaskComponent component)
            {
                AggRendererImageSetAlphaMask(renderer, buffer, (int)component);
            }
        }
        public class Gradient : Renderer.Base
        {
            public static IntPtr New(IntPtr buffer)
            {
                return AggRendererGradientNew(buffer);
            }
            public static void Delete(IntPtr renderer)
            {
                AggRendererGradientDelete(renderer);
            }
            public static void Select(IntPtr renderer, int id)
            {
                AggRendererGradientSelect(renderer, id);
            }
            public static void Color1(IntPtr renderer, double[] r, double[] g, double[] b, double[] a)
            {
                AggRendererGradientColor1(renderer, r, g, b, a);
            }
            public static void Range(IntPtr renderer, double r1, double r2)
            {
                AggRendererGradientRange(renderer, r1, r2);
            }
            public static void Matrix(IntPtr renderer, double xx, double xy, double yx, double yy, double tx, double ty)
            {
                AggRendererGradientMatrix(renderer, xx, xy, yx, yy, tx, ty);
            }
            public static void SetAlphaMask(IntPtr renderer, IntPtr buffer, Renderer.MaskComponent component)
            {
                AggRendererGradientSetAlphaMask(renderer, buffer, (int)component);
            }
        }
    }
}
