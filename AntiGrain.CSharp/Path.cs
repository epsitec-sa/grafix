using System.Runtime.InteropServices;

namespace AntiGrain
{
    public static partial class Path
    {
        [DllImport("AntiGrain.Win32", CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        internal static extern IntPtr AggPathNew();

        [DllImport("AntiGrain.Win32", CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        internal static extern void AggPathMoveTo(IntPtr path, double x, double y);

        [DllImport("AntiGrain.Win32", CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        internal static extern void AggPathLineTo(IntPtr path, double x, double y);

        [DllImport("AntiGrain.Win32", CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        internal static extern void AggPathCurve3(IntPtr path, double x_c, double y_c, double x, double y);

        [DllImport("AntiGrain.Win32", CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        internal static extern void AggPathCurve4(IntPtr path, double x_c1, double y_c1, double x_c2, double y_c2, double x, double y);

        [DllImport("AntiGrain.Win32", CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        internal static extern void AggPathClose(IntPtr path);

        [DllImport("AntiGrain.Win32", CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        internal static extern void AggPathAddNewPath(IntPtr path);

        [DllImport("AntiGrain.Win32", CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        internal static extern void AggPathAppendGlyph(IntPtr path, IntPtr face, int glyph, double xx, double xy, double yx, double yy, double tx, double ty, double bold);

        [DllImport("AntiGrain.Win32", CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        internal static extern void AggPathAppendPathStroke(IntPtr path, IntPtr path2, double width, int cap, int join, double miter_limit, double scale, [MarshalAs(UnmanagedType.U1)] bool curved);

        [DllImport("AntiGrain.Win32", CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        internal static extern void AggPathAppendPath(IntPtr path, IntPtr path2, double xx, double xy, double yx, double yy, double tx, double ty, double scale, double bold);

        [DllImport("AntiGrain.Win32", CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        internal static extern void AggPathAppendArc(IntPtr path, double x, double y, double rx, double ry, double a1, double a2, [MarshalAs(UnmanagedType.U1)] bool ccw, double scale, [MarshalAs(UnmanagedType.U1)] bool continue_pa);

        [DllImport("AntiGrain.Win32", CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        internal static extern void AggPathAppendDashedPath(IntPtr path, IntPtr dash, double scale);

        [DllImport("AntiGrain.Win32", CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        internal static extern void AggPathCombinePathsUsingGpc(IntPtr path1, IntPtr path2, IntPtr result, int operation);

        [DllImport("AntiGrain.Win32", CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        internal static extern void AggPathComputeBounds(IntPtr path, out double x1, out double y1, out double x2, out double y2);

        [DllImport("AntiGrain.Win32", CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        internal static extern void AggPathRemoveAll(IntPtr path);

        [DllImport("AntiGrain.Win32", CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        internal static extern int AggPathElemCount(IntPtr path);

        [DllImport("AntiGrain.Win32", CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        internal static extern void AggPathElemGet(IntPtr path, int n, int[] types, double[] x, double[] y);

        [DllImport("AntiGrain.Win32", CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        internal static extern void AggPathDelete(IntPtr path);

        [DllImport("AntiGrain.Win32", CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        internal static extern void AggPathDashReset(IntPtr path);

        [DllImport("AntiGrain.Win32", CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        internal static extern void AggPathDashAdd(IntPtr path, double dash_length, double gap_length);

        [DllImport("AntiGrain.Win32", CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        internal static extern void AggPathDashSetStart(IntPtr path, double start);

    }
}
namespace AntiGrain
{
    public static partial class Path
    {
        public static IntPtr New()
        {
            return AggPathNew();
        }
        public static void   MoveTo(IntPtr path, double x, double y)
        {
            AggPathMoveTo(path, x, y);
        }
        public static void   LineTo(IntPtr path, double x, double y)
        {
            AggPathLineTo(path, x, y);
        }
        public static void   Curve3(IntPtr path, double x_c, double y_c, double x, double y)
        {
            AggPathCurve3(path, x_c, y_c, x, y);
        }
        public static void   Curve4(IntPtr path, double x_c1, double y_c1, double x_c2, double y_c2, double x, double y)
        {
            AggPathCurve4(path, x_c1, y_c1, x_c2, y_c2, x, y);
        }
        public static void   Close(IntPtr path)
        {
            AggPathClose(path);
        }
        public static void   AddNewPath(IntPtr path)
        {
            AggPathAddNewPath(path);
        }
        public static void   AppendGlyph(IntPtr path, IntPtr face, int glyph, double xx, double xy, double yx, double yy, double tx, double ty, double bold)
        {
            AggPathAppendGlyph(path, face, glyph, xx, xy, yx, yy, tx, ty, bold);
        }
        public static void   AppendPath(IntPtr path, IntPtr path2, double width, int cap, int join, double miter_limit, double scale, bool curved)
        {
            AggPathAppendPathStroke(path, path2, width, cap, join, miter_limit, scale, curved);
        }
        public static void   AppendPath(IntPtr path, IntPtr path2, double xx, double xy, double yx, double yy, double tx, double ty, double scale, double bold)
        {
            AggPathAppendPath(path, path2, xx, xy, yx, yy, tx, ty, scale, bold);
        }
        public static void   AppendArc(IntPtr path, double x, double y, double rx, double ry, double a1, double a2, bool ccw, double scale, bool continue_path)
        {
            AggPathAppendArc(path, x, y, rx, ry, a1, a2, ccw, scale, continue_path);
        }
        public static void   AppendDashedPath(IntPtr path, IntPtr dash, double scale)
        {
            AggPathAppendDashedPath(path, dash, scale);
        }
        public static void   CombinePathsUsingGpc(IntPtr path1, IntPtr path2, IntPtr result, int operation)
        {
            AggPathCombinePathsUsingGpc(path1, path2, result, operation);
        }
        public static void   ComputeBounds(IntPtr path, out double x1, out double y1, out double x2, out double y2)
        {
            AggPathComputeBounds(path, out x1, out y1, out x2, out y2);
        }
        public static void   RemoveAll(IntPtr path)
        {
            AggPathRemoveAll(path);
        }
        public static int    ElemCount(IntPtr path)
        {
            return AggPathElemCount(path);
        }
        public static void   ElemGet(IntPtr path, int n, int[] types, double[] x, double[] y)
        {
            AggPathElemGet(path, n, types, x, y);
        }
        public static void   Delete(IntPtr path)
        {
            AggPathDelete(path);
        }
        public static void   ResetDash(IntPtr path)
        {
            AggPathDashReset(path);
        }
        public static void   AddDash(IntPtr path, double dash_length, double gap_length)
        {
            AggPathDashAdd(path, dash_length, gap_length);
        }
        public static void   SetDashOffset(IntPtr path, double start)
        {
            AggPathDashSetStart(path, start);
        }
    }
}
