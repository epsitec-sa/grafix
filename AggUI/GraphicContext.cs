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

        internal GraphicContext(IntPtr gctx){
            this.gctx = gctx;
        }

        public void SetColor(int r, int g, int b)
        {
            GraphicContext_SetColor(this.gctx, r, g, b);
        }

        public void DrawEllipse(double x, double y, double rx, double ry)
        {
            GraphicContext_DrawEllipse(this.gctx, x, y, rx, ry);
        }

        private IntPtr gctx;
    }
}


