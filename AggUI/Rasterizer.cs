// Copyright © 2003-2024, EPSITEC SA, CH-1400 Yverdon-les-Bains, Switzerland
// Author: Pierre ARNAUD, Roger VUISTINER, Maintainer: Roger VUISTINER

using static AntigrainCPP.Native;

namespace AntigrainCPP
{
    public class Rasterizer
    {
        public Rasterizer()
        {
            this.rasterizer = Rasterizer_New();
        }

        ~Rasterizer()
        {
            Rasterizer_Delete(rasterizer);
        }

        public void Clear()
        {
            Rasterizer_Clear(rasterizer);
        }

        public bool HitTest(int x, int y)
        {
            return Rasterizer_HitTest(rasterizer, x, y);
        }

        public void FillingRule(int mode)
        {
            Rasterizer_FillingRule(rasterizer, mode);
        }

        public void Gamma(double gamma)
        {
            Rasterizer_Gamma(rasterizer, gamma);
        }

        public void SetTransform(
            double xx, double xy,
            double yx, double yy,
            double tx, double ty
        ){
            Rasterizer_SetTransform(rasterizer, xx, xy, yx, yy, tx, ty);
        }

        public void SetClipBox(
            double x1, double y1,
            double x2, double y2
        ){
            Rasterizer_SetClipBox(rasterizer, x1, y1, x2, y2);
        }

        public void ResetClipBox()
        {
            Rasterizer_ResetClipBox(rasterizer);
        }

        public void AddPath(
            Path path,
            bool curves
        ){
            Rasterizer_AddPath(rasterizer, path.path, curves);
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

        public void AddPathStroke1(
            Path path,
            double width,
            bool curves
        ){
            Rasterizer_AddPathStroke1(rasterizer, path.path, width, curves);
        }

        public void AddPathStroke2(
            Path path,
            double width,
            int cap,
            int join,
            double miter_limit,
            bool curves
        ){
            Rasterizer_AddPathStroke2(rasterizer, path.path, width, cap, join, miter_limit, curves);
        }

        /* public void RenderSolid(IntPtr renderer) */
        /* { */
        /*     Rasterizer_RenderSolid(rasterizer, renderer); */
        /* } */

        /* public void RenderImage(IntPtr renderer) */
        /* { */
        /*     Rasterizer_RenderImage(rasterizer, renderer); */
        /* } */

        /* public void RenderGradient(IntPtr renderer) */
        /* { */
        /*     Rasterizer_RenderGradient(rasterizer, renderer); */
        /* } */

        private IntPtr rasterizer;
    }
}
