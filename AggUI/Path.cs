// Copyright © 2003-2024, EPSITEC SA, CH-1400 Yverdon-les-Bains, Switzerland
// Author: Pierre ARNAUD, Roger VUISTINER, Maintainer: Roger VUISTINER

using static AntigrainCPP.Native;

namespace AntigrainCPP
{
    public class Path
    {
        public Path()
        {
            this.path = Path_New();
        }

        ~Path()
        {
            Path_Delete(path);
        }

        public void MoveTo(double x, double y)
        {
            Path_MoveTo(path, x, y);
        }

        public void LineTo(double x, double y)
        {
            Path_LineTo(path, x, y);
        }

        public void Curve3(double x_c, double y_c, double x, double y)
        {
            Path_Curve3(path, x_c, y_c, x, y);
        }

        public void Curve4(double x_c1, double y_c1, double x_c2, double y_c2, double x, double y)
        {
            Path_Curve4(path, x_c1, y_c1, x_c2, y_c2, x, y);
        }

        public void Close()
        {
            Path_Close(path);
        }

        public void AddNewPath()
        {
            Path_AddNewPath(path);
        }

        public void AppendGlyph(IntPtr face, int glyph, double xx, double xy, double yx, double yy, double tx, double ty, double bold)
        {
            Path_AppendGlyph(path, face, glyph, xx, xy, yx, yy, tx, ty, bold);
        }

        public void AppendPath(Path otherPath, double width, int cap, int join, double miter_limit, double scale, bool curved)
        {
            Path_AppendPathStroke(path, otherPath.path, width, cap, join, miter_limit, scale, curved);
        }

        public void AppendPath(Path otherPath, double xx, double xy, double yx, double yy, double tx, double ty, double scale, double bold)
        {
            Path_AppendPath(path, otherPath.path, xx, xy, yx, yy, tx, ty, scale, bold);
        }

        public void AppendArc(double x, double y, double rx, double ry, double a1, double a2, bool ccw, double scale, bool continue_path)
        {
            Path_AppendArc(path, x, y, rx, ry, a1, a2, ccw, scale, continue_path);
        }

        public void AppendDashedPath(Path dash, double scale)
        {
            Path_AppendDashedPath(path, dash.path, scale);
        }

        public void CombinePathsUsingGpc(Path path1, Path path2, IntPtr result, int operation)
        {
            Path_CombinePathsUsingGpc(path1.path, path2.path, result, operation);
        }

        public void ComputeBounds(out double x1, out double y1, out double x2, out double y2)
        {
            Path_ComputeBounds(path, out x1, out y1, out x2, out y2);
        }

        public void RemoveAll()
        {
            Path_RemoveAll(path);
        }

        public int ElemCount()
        {
            return Path_ElemCount(path);
        }

        public void ElemGet(int n, int[] types, double[] x, double[] y)
        {
            Path_ElemGet(path, n, types, x, y);
        }

        public void ResetDash()
        {
            Path_DashReset(path);
        }

        public void AddDash(double dash_length, double gap_length)
        {
            Path_DashAdd(path, dash_length, gap_length);
        }

        public void SetDashOffset(double start)
        {
            Path_DashSetStart(path, start);
        }

        internal IntPtr path;
    }
}
