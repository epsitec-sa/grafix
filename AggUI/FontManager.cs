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

        public bool SetFont(string fontname){
            return FontManager_LoadFont(this.manager, fontname);
        }

        public bool SetFont(Font font){
            return FontManager_LoadFont(this.manager, font.fontname);
        }

        public void SetFontSize(double size){
            FontManager_SetFontSize(this.manager, size);
        }

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        [return: MarshalAs(UnmanagedType.U1)]
        private static extern bool FontManager_LoadFont(IntPtr fm,
            [MarshalAs(UnmanagedType.LPStr)] string font_name
        );

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        private static extern void FontManager_SetFontSize(IntPtr fm, double size);

        private IntPtr manager;
    }
}
