/*
This file is part of AggUI.

Copyright © 2003-2024, EPSITEC SA, 1400 Yverdon-les-Bains, Switzerland

AggUI is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
any later version.

AggUI is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

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

        public bool SetFont(string fontname, double size=1.0)
        {
            this.RequireNotDisposed();
            bool ok = FontManager_LoadFont(this.manager, fontname);
            this.SetFontSize(size);
            return ok;
        }

        public bool SetFont(Font font, double size=1.0)
        {
            this.RequireNotDisposed();
            bool ok = FontManager_LoadFont(this.manager, font.fontname);
            this.SetFontSize(size);
            return ok;
        }

        public void SetFontSize(double size)
        {
            this.RequireNotDisposed();
            FontManager_SetFontSize(this.manager, size);
        }

        internal IntPtr manager;
    }
}
