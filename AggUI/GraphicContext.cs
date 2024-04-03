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

        public AntigrainCPP.Renderer.Solid renderer_solid;
        public AntigrainCPP.Renderer.Smooth renderer_smooth;

        private IntPtr gctx;
    }
}


