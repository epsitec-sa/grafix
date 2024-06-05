// Copyright © 2003-2024, EPSITEC SA, CH-1400 Yverdon-les-Bains, Switzerland
// Author: Pierre ARNAUD, Roger VUISTINER, Maintainer: Roger VUISTINER

using static AntigrainSharp.Native;

namespace AntigrainSharp
{
    public class Rasterizer : System.IDisposable
    {
        public Rasterizer()
        {
            this.rasterizer = Rasterizer_New();
        }

        ~Rasterizer()
        {
            this.Dispose();
        }

        public void Dispose()
        {
            if (this.rasterizer != IntPtr.Zero)
            {
                Rasterizer_Delete(rasterizer);
                this.rasterizer = IntPtr.Zero;
            }
            GC.SuppressFinalize(this);
        }

        private void RequireNotDisposed()
        {
            if (this.rasterizer == IntPtr.Zero)
            {
                throw new ObjectDisposedException(this.GetType().FullName);
            }
        }

        public void Clear()
        {
            this.RequireNotDisposed();
            Rasterizer_Clear(rasterizer);
        }

        public bool HitTest(int x, int y)
        {
            this.RequireNotDisposed();
            return Rasterizer_HitTest(rasterizer, x, y);
        }

        public void FillingRule(int mode)
        {
            this.RequireNotDisposed();
            Rasterizer_FillingRule(rasterizer, mode);
        }

        public void Gamma(double gamma)
        {
            this.RequireNotDisposed();
            Rasterizer_Gamma(rasterizer, gamma);
        }

        public void SetTransform(double xx, double xy, double yx, double yy, double tx, double ty)
        {
            this.RequireNotDisposed();
            Rasterizer_SetTransform(rasterizer, xx, xy, yx, yy, tx, ty);
        }

        public void SetClipBox(double x1, double y1, double x2, double y2)
        {
            this.RequireNotDisposed();
            Rasterizer_SetClipBox(rasterizer, x1, y1, x2, y2);
        }

        public void ResetClipBox()
        {
            this.RequireNotDisposed();
            Rasterizer_ResetClipBox(rasterizer);
        }

        public void AddPath(Path path, bool curves)
        {
            this.RequireNotDisposed();
            path.RequireNotDisposed();
            Rasterizer_AddPath(rasterizer, path.path, curves);
        }

        public void AddGlyph(int glyph, double x, double y, double scale, FontManager font_manager)
        {
            this.RequireNotDisposed();
            Rasterizer_AddGlyph(rasterizer, glyph, x, y, scale, font_manager.manager);
        }

        public void AddChar(char c, double x, double y, double scale, FontManager font_manager)
        {
            this.RequireNotDisposed();
            Rasterizer_AddChar(rasterizer, c, x, y, scale, font_manager.manager);
        }

        /* public void AddGlyph( */
        /*     IntPtr face, */
        /*     int glyph, */
        /*     double x, */
        /*     double y, */
        /*     double scale */
        /* ){ */
        /*     Rasterizer_AddGlyph(rasterizer, face, glyph, x, y, scale); */
        /* } */

        /* public void AddGlyphs( */
        /*     IntPtr face, */
        /*     double scale, */
        /*     ushort[] glyphs, */
        /*     double[] xa, */
        /*     double[]? ya, */
        /*     double[]? sxa */
        /* ) */
        /* { */
        /*     int n = glyphs.Length; */

        /*     if (ya is null) */
        /*     { */
        /*         if (sxa is null) */
        /*         { */
        /*             for (int i = 0; i < n; i++) */
        /*             { */
        /*                 Rasterizer_AddGlyphXY(rasterizer, face, glyphs[i], xa[i], 0, scale, scale); */
        /*             } */
        /*         } */
        /*         else */
        /*         { */
        /*             for (int i = 0; i < n; i++) */
        /*             { */
        /*                 Rasterizer_AddGlyphXY(rasterizer, face, glyphs[i], xa[i], 0, sxa[i] * scale, scale); */
        /*             } */
        /*         } */
        /*     } */
        /*     else */
        /*     { */
        /*         if (sxa is null) */
        /*         { */
        /*             for (int i = 0; i < n; i++) */
        /*             { */
        /*                 Rasterizer_AddGlyphXY(rasterizer, face, glyphs[i], xa[i], ya[i], scale, scale); */
        /*             } */
        /*         } */
        /*         else */
        /*         { */
        /*             for (int i = 0; i < n; i++) */
        /*             { */
        /*                 Rasterizer_AddGlyphXY(rasterizer, face, glyphs[i], xa[i], ya[i], sxa[i] * scale, scale); */
        /*             } */
        /*         } */
        /*     } */
        /* } */

        public void AddPathStroke1(Path path, double width, bool curves)
        {
            this.RequireNotDisposed();
            path.RequireNotDisposed();
            Rasterizer_AddPathStroke1(rasterizer, path.path, width, curves);
        }

        public void AddPathStroke2(
            Path path,
            double width,
            int cap,
            int join,
            double miter_limit,
            bool curves
        )
        {
            this.RequireNotDisposed();
            path.RequireNotDisposed();
            Rasterizer_AddPathStroke2(rasterizer, path.path, width, cap, join, miter_limit, curves);
        }

        public void RenderSolid(Renderer.Solid renderer)
        {
            this.RequireNotDisposed();
            Rasterizer_RenderSolid(rasterizer, renderer.renderer);
        }

        public void RenderImage(Renderer.Image renderer)
        {
            this.RequireNotDisposed();
            Rasterizer_RenderImage(rasterizer, renderer.renderer);
        }

        public void RenderGradient(Renderer.Gradient renderer)
        {
            this.RequireNotDisposed();
            Rasterizer_RenderGradient(rasterizer, renderer.renderer);
        }

        private IntPtr rasterizer;
    }
}
