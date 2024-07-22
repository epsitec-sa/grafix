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

namespace SystemTools {
    public class ScreenInfo {
        private const string LibAgg = "AntigrainCPP";

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        private static extern void GetScreenResolution(out int width, out int height);

        public static Rect GetResolution() {
            int width;
            int height;
            GetScreenResolution(out width, out height);
            return new Rect(width, height);
        }

        public struct Rect {
            public Rect(int width, int height){
                this.Width = width;
                this.Height = height;
            }

            public int Width {get; set;}
            public int Height {get; set;}
        }
    }
}
