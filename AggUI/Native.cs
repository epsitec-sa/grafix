// Copyright © 2003-2024, EPSITEC SA, CH-1400 Yverdon-les-Bains, Switzerland
// Author: Pierre ARNAUD, Roger VUISTINER, Maintainer: Roger VUISTINER

using System.Runtime.InteropServices;

namespace AntigrainCPP
{
    internal static class Native
    {
        private const string LibAgg = "AntigrainCPP";

        #region Path
        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern IntPtr Path_New();

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Path_MoveTo(IntPtr path, double x, double y);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Path_LineTo(IntPtr path, double x, double y);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Path_Curve3(IntPtr path, double x_c, double y_c, double x, double y);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Path_Curve4(IntPtr path, double x_c1, double y_c1, double x_c2, double y_c2, double x, double y);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Path_Close(IntPtr path);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Path_AddNewPath(IntPtr path);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Path_AppendGlyph(IntPtr path, IntPtr face, int glyph, double xx, double xy, double yx, double yy, double tx, double ty, double bold);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Path_AppendPathStroke(IntPtr path, IntPtr path2, double width, int cap, int join, double miter_limit, double scale, [MarshalAs(UnmanagedType.U1)] bool curved);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Path_AppendPath(IntPtr path, IntPtr path2, double xx, double xy, double yx, double yy, double tx, double ty, double scale, double bold);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Path_AppendArc(IntPtr path, double x, double y, double rx, double ry, double a1, double a2, [MarshalAs(UnmanagedType.U1)] bool ccw, double scale, [MarshalAs(UnmanagedType.U1)] bool continue_pa);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Path_AppendDashedPath(IntPtr path, IntPtr dash, double scale);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Path_CombinePathsUsingGpc(IntPtr path1, IntPtr path2, IntPtr result, int operation);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Path_ComputeBounds(IntPtr path, out double x1, out double y1, out double x2, out double y2);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Path_RemoveAll(IntPtr path);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern int Path_ElemCount(IntPtr path);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Path_ElemGet(IntPtr path, int n, int[] types, double[] x, double[] y);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Path_Delete(IntPtr path);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Path_DashReset(IntPtr path);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Path_DashAdd(IntPtr path, double dash_length, double gap_length);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Path_DashSetStart(IntPtr path, double start);
        #endregion

        #region Rasterizer
        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern IntPtr Rasterizer_New();

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Rasterizer_Clear(IntPtr rasterizer);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        [return: MarshalAs(UnmanagedType.U1)]
        public static extern bool Rasterizer_HitTest(IntPtr rasterizer, int x, int y);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Rasterizer_FillingRule(IntPtr rasterizer, int mode);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Rasterizer_Gamma(IntPtr rasterizer, double gamma);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Rasterizer_SetTransform(IntPtr rasterizer, double xx, double xy, double yx, double yy, double tx, double ty);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Rasterizer_SetClipBox(IntPtr rasterizer, double x1, double y1, double x2, double y2);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Rasterizer_ResetClipBox(IntPtr rasterizer);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Rasterizer_AddPath(IntPtr rasterizer, IntPtr path, [MarshalAs(UnmanagedType.U1)] bool curves);

        /* [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)] */
        /* public static extern void Rasterizer_AddGlyph(IntPtr rasterizer, IntPtr face, int glyph, double x, double y, double scale); */

        /* [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)] */
        /* public static extern void Rasterizer_AddGlyphXY(IntPtr rasterizer, IntPtr face, int glyph, double x, double y, double scale_x, double scale_y); */

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Rasterizer_AddPathStroke1(IntPtr rasterizer, IntPtr path, double width, [MarshalAs(UnmanagedType.U1)] bool curves);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Rasterizer_AddPathStroke2(IntPtr rasterizer, IntPtr path, double width, int cap, int join, double miter_limit, [MarshalAs(UnmanagedType.U1)] bool curves);

        /* [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)] */
        /* public static extern void Rasterizer_RenderSolid(IntPtr rasterizer, IntPtr renderer); */

        /* [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)] */
        /* public static extern void Rasterizer_RenderImage(IntPtr rasterizer, IntPtr renderer); */

        /* [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)] */
        /* public static extern void Rasterizer_RenderGradient(IntPtr rasterizer, IntPtr renderer); */

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Rasterizer_Delete(IntPtr rasterizer);
        #endregion
    }
}
