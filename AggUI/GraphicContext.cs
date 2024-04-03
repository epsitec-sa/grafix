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

        internal GraphicContext(IntPtr gctx){
            this.gctx = gctx;
            IntPtr sr = GraphicContext_GetSolidRenderer(gctx);
            this.renderer = new AntigrainCPP.Renderer.Solid(sr);
        }

        public void SetColor(int r, int g, int b)
        {
            GraphicContext_SetColor(this.gctx, r, g, b);
        }

        public void DrawEllipse(double x, double y, double rx, double ry)
        {
            GraphicContext_DrawEllipse(this.gctx, x, y, rx, ry);
        }

        public AntigrainCPP.Renderer.Solid renderer;

        private IntPtr gctx;
    }
}


