using System;
using System.Reflection;
using System.Runtime.InteropServices;

namespace AntigrainCPP
{
    public class FontDrawer
    {
        private const string LibAgg = "AntigrainCPP";

        internal FontDrawer(IntPtr drawer){
            this.drawer = drawer;
        }

        public bool SetFont(Font font){
            return FontDrawer_LoadFont(this.drawer, font.fontname);
        }

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        [return: MarshalAs(UnmanagedType.U1)]
        private static extern bool FontDrawer_LoadFont(IntPtr fe,
            [MarshalAs(UnmanagedType.LPStr)] string font_name
        );

        private IntPtr drawer;
    }
}
