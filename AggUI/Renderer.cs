// Copyright © 2003-2024, EPSITEC SA, CH-1400 Yverdon-les-Bains, Switzerland
// Author: Pierre ARNAUD, Roger VUISTINER, Maintainer: Roger VUISTINER

using static AntigrainSharp.Native;

namespace AntigrainSharp
{
    public static class Renderer
    {
        public enum MaskComponent
        {
            None = -1,
            A = 0,
            R = 1,
            G = 2,
            B = 3,
        }

        public class Base
        {
            protected Base(IntPtr renderer)
            {
                this.renderer = renderer;
            }

            public void Fill4Colors(
                int x,
                int y,
                int dx,
                int dy,
                double r1,
                double g1,
                double b1,
                double r2,
                double g2,
                double b2,
                double r3,
                double g3,
                double b3,
                double r4,
                double g4,
                double b4
            )
            {
                RendererBase_Fill4Colors(
                    renderer,
                    x,
                    y,
                    dx,
                    dy,
                    r1,
                    g1,
                    b1,
                    r2,
                    g2,
                    b2,
                    r3,
                    g3,
                    b3,
                    r4,
                    g4,
                    b4
                );
            }

            protected internal IntPtr renderer;
        }

        public class Solid : Renderer.Base
        {
            internal Solid(IntPtr renderer)
                : base(renderer) { }

            public void Clear(double r, double g, double b, double a)
            {
                RendererSolid_Clear(renderer, r, g, b, a);
            }

            public void Color(double r, double g, double b, double a)
            {
                RendererSolid_Color(renderer, r, g, b, a);
            }

            public void SetAlphaMask(AbstractGraphicBuffer buffer, Renderer.MaskComponent component)
            {
                RendererSolid_SetAlphaMask(renderer, buffer.buffer, (int)component);
            }
        }

        public class Smooth : Renderer.Base
        {
            internal Smooth(IntPtr renderer)
                : base(renderer) { }

            public void Color(double r, double g, double b, double a)
            {
                RendererSmooth_Color(renderer, r, g, b, a);
            }

            public void Setup(
                double r1,
                double r2,
                double xx,
                double xy,
                double yx,
                double yy,
                double tx,
                double ty
            )
            {
                RendererSmooth_Setup(renderer, r1, r2, xx, xy, yx, yy, tx, ty);
            }

            public void AddPath(Path path)
            {
                RendererSmooth_AddPath(renderer, path.path);
            }

            public void SetAlphaMask(AbstractGraphicBuffer buffer, Renderer.MaskComponent component)
            {
                RendererSmooth_SetAlphaMask(renderer, buffer.buffer, (int)component);
            }
        }

        public class Image : Renderer.Base
        {
            internal Image(IntPtr renderer)
                : base(renderer) { }

            public void Matrix(double xx, double xy, double yx, double yy, double tx, double ty)
            {
                RendererImage_Matrix(renderer, xx, xy, yx, yy, tx, ty);
            }

            /* public void Source1(IntPtr buffer) */
            /* { */
            /*     RendererImage_Source1(renderer, buffer); */
            /* } */

            public void AttachSource(byte[] byte_buffer, int dx, int dy, int stride)
            {
                RendererImage_AttachSource(renderer, byte_buffer, dx, dy, stride);
            }

            public void SetStretchMode(int mode, double radius)
            {
                RendererImage_SetStretchMode(renderer, mode, radius);
            }

            public void SetAlphaMask(AbstractGraphicBuffer buffer, Renderer.MaskComponent component)
            {
                RendererImage_SetAlphaMask(renderer, component == Renderer.MaskComponent.None ? IntPtr.Zero : buffer.buffer, (int)component);
            }
        }

        public class Gradient : Renderer.Base
        {
            internal Gradient(IntPtr renderer)
                : base(renderer) { }

            public void Select(int id)
            {
                RendererGradient_Select(renderer, id);
            }

            public void Color1(double[] r, double[] g, double[] b, double[] a)
            {
                RendererGradient_Color1(renderer, r, g, b, a);
            }

            public void Range(double r1, double r2)
            {
                RendererGradient_Range(renderer, r1, r2);
            }

            public void Matrix(double xx, double xy, double yx, double yy, double tx, double ty)
            {
                RendererGradient_Matrix(renderer, xx, xy, yx, yy, tx, ty);
            }

            public void SetAlphaMask(AbstractGraphicBuffer buffer, Renderer.MaskComponent component)
            {
                RendererGradient_SetAlphaMask(renderer, buffer.buffer, (int)component);
            }
        }
    }
}
