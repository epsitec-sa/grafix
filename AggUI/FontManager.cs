using System;
using System.Reflection;
using System.Runtime.InteropServices;
using static AntigrainSharp.Native;

namespace AntigrainSharp
{
    public class FontManager
    {

        public FontManager(){
            this.manager = FontManager_New();
        }

        ~FontManager(){
            this.Dispose();
        }

        public void Dispose(){
            if (this.manager != IntPtr.Zero){
                FontManager_Delete(this.manager);
                this.manager = IntPtr.Zero;
            }
            GC.SuppressFinalize(this);
        }

        private void RequireNotDisposed(){
            if (this.manager == IntPtr.Zero){
                throw new ObjectDisposedException(this.GetType().FullName);
            }
        }

        public bool SetFont(string fontname)
        {
            this.RequireNotDisposed();
            return FontManager_LoadFont(this.manager, fontname);
        }

        public bool SetFont(Font font)
        {
            this.RequireNotDisposed();
            return FontManager_LoadFont(this.manager, font.fontname);
        }

        public void SetFontSize(double size)
        {
            this.RequireNotDisposed();
            FontManager_SetFontSize(this.manager, size);
        }

        internal IntPtr manager;
    }
}
