using System;
using System.IO;
using System.Reflection;
using System.Runtime.InteropServices;
using static AntigrainSharp.Native;

namespace AntigrainSharp
{
    public class Font : IDisposable
    {
        public static Font LoadFromFile(string fontname)
        {
            if (!File.Exists(fontname))
            {
                throw new FileNotFoundException($"No font file {fontname}");
            }
            IntPtr face = FreetypeInfo_LoadFromFile(Font.library, fontname);
            return new Font(face, fontname);
        }

        internal Font(IntPtr face, string fontname)
        {
            this.face = face;
            this.fontname = fontname;
        }

        ~Font(){
            this.Dispose();
        }

        public void Dispose(){
            if (this.face != IntPtr.Zero){
                FreetypeInfo_DoneFace(this.face);
                this.face = IntPtr.Zero;
            }
            this.fontname = "";
            GC.SuppressFinalize(this);
        }

        private void RequireNotDisposed(){
            if (this.face == IntPtr.Zero){
                throw new ObjectDisposedException(this.GetType().FullName);
            }
        }

        public bool IsBold
        {
            get { 
                RequireNotDisposed();
                return FreetypeInfo_IsFaceBold(this.face);
            }
        }

        public bool IsItalic
        {
            get {
                RequireNotDisposed();
                return FreetypeInfo_IsFaceItalic(this.face);
            }
        }

        public uint UnitsPerEm
        {
            get {
                RequireNotDisposed();
                return FreetypeInfo_GetUnitsPerEm(this.face);
            }
        }

        public double GetGlyphAdvance(uint glyph, double size)
        {
            RequireNotDisposed();
            return FreetypeInfo_GetGlyphAdvance(this.face, glyph, size);
        }

        public uint GetCharIndex(ulong charcode)
        {
            RequireNotDisposed();
            return FreetypeInfo_GetCharIndex(this.face, charcode);
        }

        public void GetGlyphBBox(
            uint glyph,
            double size,
            out double xMin,
            out double xMax,
            out double yMin,
            out double yMax
        )
        {
            RequireNotDisposed();
            FreetypeInfo_GetGlyphBBox(
                this.face,
                glyph,
                size,
                out xMin,
                out xMax,
                out yMin,
                out yMax
            );
        }

        public double GetKerning(uint left_glyph, uint right_glyph, double size)
        {
            RequireNotDisposed();
            return FreetypeInfo_GetKerning(this.face, left_glyph, right_glyph, size);
        }

        public double GetAscender(double size)
        {
            RequireNotDisposed();
            return FreetypeInfo_GetAscender(this.face, size);
        }

        public double GetDescender(double size)
        {
            RequireNotDisposed();
            return FreetypeInfo_GetDescender(this.face, size);
        }

        public double GetHeight(double size)
        {
            RequireNotDisposed();
            return FreetypeInfo_GetHeight(this.face, size);
        }

        private IntPtr face;
        internal string fontname;

        private static IntPtr library = FreetypeInfo_CreateLibrary();
    }
}
