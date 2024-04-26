using System;
using System.Reflection;
using System.Runtime.InteropServices;

namespace AntigrainCPP {

    public class GraphicBuffer {
        private const string LibAgg = "AntigrainCPP";

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        private static extern IntPtr GraphicBuffer_NewGraphicBuffer(IntPtr fm);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        private static extern IntPtr GraphicBuffer_GetGraphicContext(IntPtr gbuff);

        public GraphicBuffer(IntPtr fm){
            this.buffer = GraphicBuffer_NewGraphicBuffer(fm);
            IntPtr gctxHandle = GraphicBuffer_GetGraphicContext(this.buffer);
            this.gctx = new GraphicContext(gctxHandle);
        }

        public GraphicContext GraphicContext
        {
            get { return this.gctx; }
        }

        private IntPtr buffer;
        private GraphicContext gctx;
    }
}


