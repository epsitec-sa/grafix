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

        public void GetGlyphBBox(uint glyph, double size,
            out double xMin,
            out double xMax,
            out double yMin,
            out double yMax
        ){
            FreetypeInfo_GetGlyphBBox(this.face, glyph, size, 
                out xMin, out xMax, 
                out yMin, out yMax
            );
        }

        public double GetKerning(uint left_glyph, uint right_glyph, double size){
            return FreetypeInfo_GetKerning(this.face, left_glyph, right_glyph, size);
        }

        public double GetAscender(double size){
            return FreetypeInfo_GetAscender(this.face, size);
        }

        public double GetDescender(double size){
            return FreetypeInfo_GetDescender(this.face, size);
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

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        private static extern void FreetypeInfo_GetGlyphBBox(IntPtr face,
            uint glyph_index,
            double size,
            out double xMin,
            out double xMax,
            out double yMin,
            out double yMax
        );

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        private static extern double FreetypeInfo_GetKerning(IntPtr face, 
            uint left_glyph,
            uint right_glyph,
            double size
        );

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        private static extern double FreetypeInfo_GetAscender(IntPtr face, double size);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        private static extern double FreetypeInfo_GetDescender(IntPtr face, double size);

        private IntPtr face;
        internal string fontname;

        private static IntPtr library = FreetypeInfo_CreateLibrary();
    }
}
