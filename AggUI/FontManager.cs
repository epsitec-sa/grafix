using System;
using System.Reflection;
using System.Runtime.InteropServices;

namespace AntigrainCPP
{
    public class FontManager
    {
        private const string LibAgg = "AntigrainCPP";

        internal FontManager(IntPtr manager){
            this.manager = manager;
        }

        public bool SetFont(Font font){
            return FontManager_LoadFont(this.manager, font.fontname);
        }

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        [return: MarshalAs(UnmanagedType.U1)]
        private static extern bool FontManager_LoadFont(IntPtr fm,
            [MarshalAs(UnmanagedType.LPStr)] string font_name
        );

        private IntPtr manager;
    }
}
