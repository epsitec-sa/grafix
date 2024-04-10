using System;
using System.Reflection;
using System.Runtime.InteropServices;

namespace AggUI {

    public class GraphicContext {
        private const string LibAgg = "AntigrainCPP";

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        private static extern void GraphicContext_SetColor(IntPtr gctx,
            int r, int g, int b
        );

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        private static extern void GraphicContext_DrawEllipse(IntPtr gctx,
            double x, double y, double rx, double ry
        );

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        private static extern IntPtr GraphicContext_GetSolidRenderer(IntPtr gctx);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        private static extern IntPtr GraphicContext_GetSmoothRenderer(IntPtr gctx);

        internal GraphicContext(IntPtr gctx){
            this.gctx = gctx;
            IntPtr solid_ren = GraphicContext_GetSolidRenderer(gctx);
            this.renderer_solid = new AntigrainCPP.Renderer.Solid(solid_ren);
            IntPtr smooth_ren = GraphicContext_GetSmoothRenderer(gctx);
            this.renderer_smooth = new AntigrainCPP.Renderer.Smooth(smooth_ren);
        }

        public void SetColor(int r, int g, int b)
        {
            GraphicContext_SetColor(this.gctx, r, g, b);
        }

        public void DrawEllipse(double x, double y, double rx, double ry)
        {
            GraphicContext_DrawEllipse(this.gctx, x, y, rx, ry);
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

        public AntigrainCPP.Renderer.Solid renderer_solid;
        public AntigrainCPP.Renderer.Smooth renderer_smooth;

        private IntPtr gctx;
    }
}


