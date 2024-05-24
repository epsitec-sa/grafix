// Copyright © 2003-2024, EPSITEC SA, CH-1400 Yverdon-les-Bains, Switzerland
// Author: Pierre ARNAUD, Roger VUISTINER, Maintainer: Roger VUISTINER

using static AntigrainSharp.Native;

namespace AntigrainSharp
{
    public class RectanglePath : Path
    {
        public RectanglePath(double x1, double y1, double x2, double y2)
            : base()
        {
            this.MoveTo(x1, y1);
            this.LineTo(x1, y2);
            this.LineTo(x2, y2);
            this.LineTo(x2, y1);
            this.Close();
        }

        ~RectanglePath(){
            base.Dispose();
        }
    }

    public class Path : System.IDisposable
    {
        public Path()
        {
            this.path = Path_New();
        }

        ~Path(){
            this.Dispose();
        }

        public void Dispose(){
            if (this.path != IntPtr.Zero){
                Path_Delete(path);
                this.path = IntPtr.Zero;
            }
            GC.SuppressFinalize(this);
        }

        protected internal void RequireNotDisposed(){
            if (this.path == IntPtr.Zero){
                throw new ObjectDisposedException(this.GetType().FullName);
            }
        }

        public void MoveTo(double x, double y)
        {
            this.RequireNotDisposed();
            Path_MoveTo(path, x, y);
        }

        public void LineTo(double x, double y)
        {
            this.RequireNotDisposed();
            Path_LineTo(path, x, y);
        }

        public void Curve3(double x_c, double y_c, double x, double y)
        {
            this.RequireNotDisposed();
            Path_Curve3(path, x_c, y_c, x, y);
        }

        public void Curve4(double x_c1, double y_c1, double x_c2, double y_c2, double x, double y)
        {
            this.RequireNotDisposed();
            Path_Curve4(path, x_c1, y_c1, x_c2, y_c2, x, y);
        }

        public void Close()
        {
            this.RequireNotDisposed();
            Path_Close(path);
        }

        public void AddNewPath()
        {
            this.RequireNotDisposed();
            Path_AddNewPath(path);
        }

        public void AppendGlyph(
            IntPtr face,
            int glyph,
            double xx,
            double xy,
            double yx,
            double yy,
            double tx,
            double ty,
            double bold
        )
        {
            this.RequireNotDisposed();
            Path_AppendGlyph(path, face, glyph, xx, xy, yx, yy, tx, ty, bold);
        }

        public void AppendPath(
            Path otherPath,
            double width,
            int cap,
            int join,
            double miter_limit,
            double scale,
            bool curved
        )
        {
            this.RequireNotDisposed();
            otherPath.RequireNotDisposed();
            Path_AppendPathStroke(
                path,
                otherPath.path,
                width,
                cap,
                join,
                miter_limit,
                scale,
                curved
            );
        }

        public void AppendPath(
            Path otherPath,
            double xx,
            double xy,
            double yx,
            double yy,
            double tx,
            double ty,
            double scale,
            double bold
        )
        {
            this.RequireNotDisposed();
            otherPath.RequireNotDisposed();
            Path_AppendPath(path, otherPath.path, xx, xy, yx, yy, tx, ty, scale, bold);
        }

        public void AppendArc(
            double x,
            double y,
            double rx,
            double ry,
            double a1,
            double a2,
            bool ccw,
            double scale,
            bool continue_path
        )
        {
            this.RequireNotDisposed();
            Path_AppendArc(path, x, y, rx, ry, a1, a2, ccw, scale, continue_path);
        }

        public void AppendDashedPath(Path dash, double scale)
        {
            this.RequireNotDisposed();
            dash.RequireNotDisposed();
            Path_AppendDashedPath(path, dash.path, scale);
        }

        public Path CombinePathUsingGpc(Path otherPath, int operation)
        {
            this.RequireNotDisposed();
            otherPath.RequireNotDisposed();
            Path result = new Path();
            Path_CombinePathsUsingGpc(this.path, otherPath.path, result.path, operation);
            return result;
        }

        public void ComputeBounds(out double x1, out double y1, out double x2, out double y2)
        {
            this.RequireNotDisposed();
            Path_ComputeBounds(path, out x1, out y1, out x2, out y2);
        }

        public void RemoveAll()
        {
            this.RequireNotDisposed();
            Path_RemoveAll(path);
        }

        public int ElemCount()
        {
            this.RequireNotDisposed();
            return Path_ElemCount(path);
        }

        public void ElemGet(int n, int[] types, double[] x, double[] y)
        {
            this.RequireNotDisposed();
            Path_ElemGet(path, n, types, x, y);
        }

        public void ResetDash()
        {
            this.RequireNotDisposed();
            Path_DashReset(path);
        }

        public void AddDash(double dash_length, double gap_length)
        {
            this.RequireNotDisposed();
            Path_DashAdd(path, dash_length, gap_length);
        }

        public void SetDashOffset(double start)
        {
            this.RequireNotDisposed();
            Path_DashSetStart(path, start);
        }

        internal IntPtr path;
    }
}
