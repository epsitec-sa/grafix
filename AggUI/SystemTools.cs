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
