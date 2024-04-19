using System;
using System.Reflection;
using System.Runtime.InteropServices;

namespace AntigrainCPP
{
    public class Font
    {
        private const string LibAgg = "AntigrainCPP";

        public static Font LoadFromFile(string fontname){
            IntPtr face = FreetypeInfo_LoadFromFile(Font.library, fontname);
            return new Font(face, fontname);
        }

        internal Font(IntPtr face, string fontname){
            this.face = face;
            this.fontname = fontname;
        }

        public bool IsBold {
            get {
                return FreetypeInfo_IsFaceBold(this.face);
            }
        }

        public bool IsItalic {
            get {
                return FreetypeInfo_IsFaceItalic(this.face);
            }
        }

        public double GetGlyphAdvance(uint glyph, double size){
            return FreetypeInfo_GetGlyphAdvance(this.face, glyph, size);
        }

        public uint GetCharIndex(ulong charcode){
            return FreetypeInfo_GetCharIndex(this.face, charcode);
        }

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        private static extern IntPtr FreetypeInfo_CreateLibrary();

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        private static extern IntPtr FreetypeInfo_LoadFromFile(
            IntPtr library,
            [MarshalAs(UnmanagedType.LPStr)] string font_name
        );

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        [return: MarshalAs(UnmanagedType.U1)]
        private static extern bool FreetypeInfo_IsFaceBold(IntPtr face);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        [return: MarshalAs(UnmanagedType.U1)]
        private static extern bool FreetypeInfo_IsFaceItalic(IntPtr face);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        private static extern uint FreetypeInfo_GetCharIndex(IntPtr face, ulong charcode);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        private static extern double FreetypeInfo_GetGlyphAdvance(IntPtr face, uint glyph_index, double size);

        private IntPtr face;
        internal string fontname;

        private static IntPtr library = FreetypeInfo_CreateLibrary();
    }
}
