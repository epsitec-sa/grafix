using System;
using System.Reflection;
using System.Runtime.InteropServices;

namespace AggUI {

    public class RendererSolid
    {
        private const string LibAgg = "AntigrainCPP";

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        private static extern void AggRendererSolidClear(IntPtr renderer,
            double r, double g, double b, double a
        );

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        private static extern bool AggRendererSolidColor(IntPtr renderer, 
            double r, double g, double b, double a
        );

        internal RendererSolid(IntPtr renderer)
        {
            if (renderer == IntPtr.Zero){
                throw new ArgumentException("RendererSolid initialized with IntPtr.Zero");
            }
            this.renderer = renderer;
        }

        public void Clear(double r, double g, double b, double a){
            AggRendererSolidClear(this.renderer, r, g, b, a);
        }

        public void Color(double r, double g, double b, double a){
            AggRendererSolidColor(this.renderer, r, g, b, a);
        }

        private IntPtr renderer;
    }
}
