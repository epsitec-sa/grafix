using System;
using System.Reflection;
using System.Runtime.InteropServices;

namespace AntigrainCPP
{
    public class FontEngine
    {
        private const string LibAgg = "AntigrainCPP";

        internal FontEngine(IntPtr engine){
            this.engine = engine;
        }

        public bool LoadFont(string fontname){
            return FontEngine_LoadFont(this.engine, fontname);
        }

        public bool IsCurrentFaceBold {
            get {
                return FontEngine_IsCurrentFaceBold(this.engine);
            }
        }

        public bool IsCurrentFaceItalic {
            get {
                return FontEngine_IsCurrentFaceItalic(this.engine);
            }
        }

        public uint GetCharIndex(ulong charcode){
            return FontEngine_GetCharIndex(this.engine, charcode);
        }

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        [return: MarshalAs(UnmanagedType.U1)]
        private static extern bool FontEngine_LoadFont(IntPtr fe,
            [MarshalAs(UnmanagedType.LPStr)] string font_name
        );

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        [return: MarshalAs(UnmanagedType.U1)]
        private static extern bool FontEngine_IsCurrentFaceBold(IntPtr fe);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        [return: MarshalAs(UnmanagedType.U1)]
        private static extern bool FontEngine_IsCurrentFaceItalic(IntPtr fe);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        private static extern uint FontEngine_GetCharIndex(IntPtr fe, ulong charcode);

        private IntPtr engine;
    }
}
