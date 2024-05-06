using System;
using System.Reflection;
using System.Runtime.InteropServices;
using static AntigrainSharp.Native;

namespace AntigrainSharp
{
    public class FontManager
    {
        internal FontManager(IntPtr manager)
        {
            this.manager = manager;
        }

        public bool SetFont(string fontname)
        {
            return FontManager_LoadFont(this.manager, fontname);
        }

        public bool SetFont(Font font)
        {
            return FontManager_LoadFont(this.manager, font.fontname);
        }

        public void SetFontSize(double size)
        {
            FontManager_SetFontSize(this.manager, size);
        }

        internal IntPtr manager;
    }
}
