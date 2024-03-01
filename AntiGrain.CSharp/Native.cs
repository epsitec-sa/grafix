// Copyright © 2003-2024, EPSITEC SA, CH-1400 Yverdon-les-Bains, Switzerland
// Author: Pierre ARNAUD, Roger VUISTINER, Maintainer: Roger VUISTINER

using System.Runtime.InteropServices;

namespace AntiGrain
{
    internal static class Native
    {
        private const string LibAgg = "AntiGrain.Win32";

        #region Buffer

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern IntPtr AggBufferNew(uint dx, uint dy, uint bpp);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern IntPtr AggBufferNewFrom(uint dx, uint dy, uint bpp, int stride, IntPtr ptr, [MarshalAs(UnmanagedType.U1)] bool copyBits);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        [return: MarshalAs(UnmanagedType.U1)]
        public static extern bool AggBufferResize(IntPtr buffer, uint dx, uint dy, uint bpp);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggBufferInfiniteClipping(IntPtr buffer);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggBufferEmptyClipping(IntPtr buffer);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggBufferAddClipBox(IntPtr buffer, int x1, int y1, int x2, int y2);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggBufferDrawGlyphs(IntPtr buffer, IntPtr hfont, int x, int y, ushort[] glyphs, int[] dx_array, uint count, uint color);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggBufferPaint(IntPtr buffer, IntPtr hdc, int x1, int y1, int x2, int y2);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggBufferPaintOffset(IntPtr buffer, IntPtr hdc, int ox, int oy, int x1, int y1, int x2, int y2);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggBufferBlendOffset(IntPtr buffer, IntPtr hdc, int ox, int oy, int x1, int y1, int x2, int y2);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggBufferClear(IntPtr buffer);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggBufferClearRect(IntPtr buffer, int x1, int y1, int x2, int y2);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggBufferGetMemoryLayout(IntPtr buffer, out int width, out int height, out int stride, out IntPtr value);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern IntPtr AggBufferGetMemoryBitmapHandle(IntPtr buffer);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggBufferBltBuffer(IntPtr buffer, int xd, int yd, IntPtr source, int xs, int ys, int dx, int dy);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggBufferComposeBuffer(IntPtr buffer, int xd, int yd, IntPtr source, int xs, int ys, int dx, int dy);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggBufferDelete(IntPtr buffer);

        #endregion

        #region Font
        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern IntPtr AggFontCreateFaceFromFontData(byte[] data, uint size, uint offset, IntPtr handle);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggFontDisposeFace(IntPtr face);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true, CharSet = CharSet.Unicode)]
        [return: MarshalAs(UnmanagedType.U1)]
        public static extern bool AggFontGetUnicodeName(int code, [Out] char[] name);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true, CharSet = CharSet.Unicode)]
        public static extern void AggFontPixelCacheGlyphXY(IntPtr buffer, IntPtr face, ushort glyph, double x, double y, double sx, double sy, double r, double g, double b, double a);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true, CharSet = CharSet.Unicode)]
        public static extern double AggFontPixelCacheFill(IntPtr buffer, IntPtr face, ushort[] glyphs, int length, double scale, double ox, double oy, double r, double g, double b, double a);
        #endregion

        #region Interface
        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        [return: MarshalAs(UnmanagedType.U1)]
        public static extern bool AggInitialise();

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggShutDown();

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggNoOp();

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggNoOpString(string text);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true, CharSet = CharSet.Unicode)]
        public static extern string AggGetVersion();

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true, CharSet = CharSet.Unicode)]
        public static extern string AggGetProductName();
        #endregion

        #region Path
        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern IntPtr AggPathNew();

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggPathMoveTo(IntPtr path, double x, double y);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggPathLineTo(IntPtr path, double x, double y);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggPathCurve3(IntPtr path, double x_c, double y_c, double x, double y);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggPathCurve4(IntPtr path, double x_c1, double y_c1, double x_c2, double y_c2, double x, double y);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggPathClose(IntPtr path);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggPathAddNewPath(IntPtr path);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggPathAppendGlyph(IntPtr path, IntPtr face, int glyph, double xx, double xy, double yx, double yy, double tx, double ty, double bold);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggPathAppendPathStroke(IntPtr path, IntPtr path2, double width, int cap, int join, double miter_limit, double scale, [MarshalAs(UnmanagedType.U1)] bool curved);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggPathAppendPath(IntPtr path, IntPtr path2, double xx, double xy, double yx, double yy, double tx, double ty, double scale, double bold);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggPathAppendArc(IntPtr path, double x, double y, double rx, double ry, double a1, double a2, [MarshalAs(UnmanagedType.U1)] bool ccw, double scale, [MarshalAs(UnmanagedType.U1)] bool continue_pa);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggPathAppendDashedPath(IntPtr path, IntPtr dash, double scale);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggPathCombinePathsUsingGpc(IntPtr path1, IntPtr path2, IntPtr result, int operation);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggPathComputeBounds(IntPtr path, out double x1, out double y1, out double x2, out double y2);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggPathRemoveAll(IntPtr path);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern int AggPathElemCount(IntPtr path);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggPathElemGet(IntPtr path, int n, int[] types, double[] x, double[] y);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggPathDelete(IntPtr path);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggPathDashReset(IntPtr path);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggPathDashAdd(IntPtr path, double dash_length, double gap_length);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggPathDashSetStart(IntPtr path, double start);
        #endregion

        #region Rasterizer
        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern IntPtr AggRasterizerNew();

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggRasterizerClear(IntPtr rasterizer);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        [return: MarshalAs(UnmanagedType.U1)]
        public static extern bool AggRasterizerHitTest(IntPtr rasterizer, int x, int y);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggRasterizerFillingRule(IntPtr rasterizer, int mode);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggRasterizerGamma(IntPtr rasterizer, double gamma);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggRasterizerSetTransform(IntPtr rasterizer, double xx, double xy, double yx, double yy, double tx, double ty);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggRasterizerSetClipBox(IntPtr rasterizer, double x1, double y1, double x2, double y2);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggRasterizerResetClipBox(IntPtr rasterizer);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggRasterizerAddPath(IntPtr rasterizer, IntPtr path, [MarshalAs(UnmanagedType.U1)] bool curves);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggRasterizerAddGlyph(IntPtr rasterizer, IntPtr face, int glyph, double x, double y, double scale);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggRasterizerAddGlyphXY(IntPtr rasterizer, IntPtr face, int glyph, double x, double y, double scale_x, double scale_y);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggRasterizerAddPathStroke1(IntPtr rasterizer, IntPtr path, double width, [MarshalAs(UnmanagedType.U1)] bool curves);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggRasterizerAddPathStroke2(IntPtr rasterizer, IntPtr path, double width, int cap, int join, double miter_limit, [MarshalAs(UnmanagedType.U1)] bool curves);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggRasterizerRenderSolid(IntPtr rasterizer, IntPtr renderer);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggRasterizerRenderImage(IntPtr rasterizer, IntPtr renderer);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggRasterizerRenderGradient(IntPtr rasterizer, IntPtr renderer);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggRasterizerDelete(IntPtr rasterizer);
        #endregion

        #region Renderer

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggRendererFill4Colors(IntPtr renderer, int x, int y, int dx, int dy, double r1, double g1, double b1, double r2, double g2, double b2, double r3, double g3, double b3, double r4, double g4, double b4);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern IntPtr AggRendererSolidNew(IntPtr buffer);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggRendererSolidClear(IntPtr renderer, double r, double g, double b, double a);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggRendererSolidColor(IntPtr renderer, double r, double g, double b, double a);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggRendererSolidDelete(IntPtr renderer);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggRendererSolidSetAlphaMask(IntPtr renderer, IntPtr buffer, int component);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern IntPtr AggRendererSmoothNew(IntPtr buffer);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggRendererSmoothColor(IntPtr renderer, double r, double g, double b, double a);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggRendererSmoothSetup(IntPtr renderer, double r1, double r2, double xx, double xy, double yx, double yy, double tx, double ty);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggRendererSmoothAddPath(IntPtr renderer, IntPtr path);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggRendererSmoothDelete(IntPtr renderer);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggRendererSmoothSetAlphaMask(IntPtr renderer, IntPtr buffer, int component);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern IntPtr AggRendererImageNew(IntPtr buffer);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggRendererImageMatrix(IntPtr renderer, double xx, double xy, double yx, double yy, double tx, double ty);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggRendererImageSource1(IntPtr renderer, IntPtr buffer);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggRendererImageSource2(IntPtr renderer, IntPtr byte_buffer, int dx, int dy, int stride);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggRendererImageDelete(IntPtr renderer);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggRendererImageSetStretchMode(IntPtr renderer, int mode, double radius);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggRendererImageSetAlphaMask(IntPtr renderer, IntPtr buffer, int component);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern IntPtr AggRendererGradientNew(IntPtr buffer);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggRendererGradientDelete(IntPtr renderer);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggRendererGradientSelect(IntPtr renderer, int id);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggRendererGradientColor1(IntPtr renderer, double[] r, double[] g, double[] b, double[] a);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggRendererGradientRange(IntPtr renderer, double r1, double r2);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggRendererGradientMatrix(IntPtr renderer, double xx, double xy, double yx, double yy, double tx, double ty);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void AggRendererGradientSetAlphaMask(IntPtr renderer, IntPtr buffer, int component);

        #endregion
    }
}
