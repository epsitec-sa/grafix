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

namespace AggUI {

    [Flags]
    public enum WindowFlags : uint
    {
        Resize          = 1,
        HWBuffer        = 2,
        KeepAspectRatio = 4,
        ProcessAllKeys  = 8
    };

    public enum PixFmt
    {
        pix_format_undefined = 0,  // By default. No conversions are applied 
        pix_format_bw,             // 1 bit per color B/W
        pix_format_gray8,          // Simple 256 level grayscale
        pix_format_sgray8,         // Simple 256 level grayscale (sRGB)
        pix_format_gray16,         // Simple 65535 level grayscale
        pix_format_gray32,         // Grayscale, one 32-bit float per pixel
        pix_format_rgb555,         // 15 bit rgb. Depends on the byte ordering!
        pix_format_rgb565,         // 16 bit rgb. Depends on the byte ordering!
        pix_format_rgbAAA,         // 30 bit rgb. Depends on the byte ordering!
        pix_format_rgbBBA,         // 32 bit rgb. Depends on the byte ordering!
        pix_format_bgrAAA,         // 30 bit bgr. Depends on the byte ordering!
        pix_format_bgrABB,         // 32 bit bgr. Depends on the byte ordering!
        pix_format_rgb24,          // R-G-B, one byte per color component
        pix_format_srgb24,         // R-G-B, one byte per color component (sRGB)
        pix_format_bgr24,          // B-G-R, one byte per color component
        pix_format_sbgr24,         // B-G-R, native win32 BMP format (sRGB)
        pix_format_rgba32,         // R-G-B-A, one byte per color component
        pix_format_srgba32,        // R-G-B-A, one byte per color component (sRGB)
        pix_format_argb32,         // A-R-G-B, native MAC format
        pix_format_sargb32,        // A-R-G-B, native MAC format (sRGB)
        pix_format_abgr32,         // A-B-G-R, one byte per color component
        pix_format_sabgr32,        // A-B-G-R, one byte per color component (sRGB)
        pix_format_bgra32,         // B-G-R-A, native win32 BMP format
        pix_format_sbgra32,        // B-G-R-A, native win32 BMP format (sRGB)
        pix_format_rgb48,          // R-G-B, 16 bits per color component
        pix_format_bgr48,          // B-G-R, native win32 BMP format.
        pix_format_rgb96,          // R-G-B, one 32-bit float per color component
        pix_format_bgr96,          // B-G-R, one 32-bit float per color component
        pix_format_rgba64,         // R-G-B-A, 16 bits byte per color component
        pix_format_argb64,         // A-R-G-B, native MAC format
        pix_format_abgr64,         // A-B-G-R, one byte per color component
        pix_format_bgra64,         // B-G-R-A, native win32 BMP format
        pix_format_rgba128,        // R-G-B-A, one 32-bit float per color component
        pix_format_argb128,        // A-R-G-B, one 32-bit float per color component
        pix_format_abgr128,        // A-B-G-R, one 32-bit float per color component
        pix_format_bgra128,        // B-G-R-A, one 32-bit float per color component
  
        end_of_pix_formats
    };

    public class AggWindow
    {
        private const string LibAgg = "AntigrainCPP";

        delegate void OnResizeT(int sx, int sy);
        delegate void OnMouseMoveT(int x, int y, uint flags);
        delegate void OnMouseButtonDownT(int x, int y, uint flags);
        delegate void OnMouseButtonUpT(int x, int y, uint flags);
        delegate void OnKeyT(int x, int y, uint key, uint flags);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        private static extern IntPtr NewApplication(
            bool flip_y,
            Action on_draw,
            OnResizeT on_resize,
            OnMouseMoveT on_mouse_move,
            OnMouseButtonDownT on_mouse_button_down,
            OnMouseButtonUpT on_mouse_button_up,
            OnKeyT on_key
        );

        /* [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)] */
        /* private static extern IntPtr Application_(); */

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        private static extern void Application_Caption(IntPtr app, string text);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        private static extern bool Application_Init(IntPtr app, 
                                                        uint width, uint height,
                                                        WindowFlags flags);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        private static extern void Application_ForceRedraw(IntPtr app);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        private static extern void Application_SetColor(IntPtr app, int r, int g, int b);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        private static extern void Application_DrawEllipse(IntPtr app,
                                                           double x, double y,
                                                           double rx, double ry);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        private static extern int Application_Run(IntPtr app);

        public AggWindow(bool flip_y)
        {
            this.app = NewApplication(
                flip_y,
                OnDraw,
                OnResize,
                OnMouseMove,
                OnMouseButtonDown,
                OnMouseButtonUp,
                OnKey
            );
        }

        public void SetCaption(string text)
        {
            Application_Caption(this.app, text);
        }

        public bool Init(uint width, uint height, WindowFlags flags){
            return Application_Init(this.app, width, height, flags);
        }

        public int Run(){
            return Application_Run(this.app);
        }

        public void ForceRedraw()
        {
            Application_ForceRedraw(this.app);
        }

        public void SetColor(int r, int g, int b)
        {
            Application_SetColor(this.app, r, g, b);
        }

        public void DrawEllipse(double x, double y, double rx, double ry)
        {
            Application_DrawEllipse(this.app, x, y, rx, ry);
        }

        public virtual void OnDraw(){}

        public virtual void OnResize(int sx, int sy){}

        public virtual void OnMouseMove(int x, int y, uint flags){}

        public virtual void OnMouseButtonDown(int x, int y, uint flags){}

        public virtual void OnMouseButtonUp(int x, int y, uint flags){}

        public virtual void OnKey(int x, int y, uint key, uint flags){}

        private IntPtr app;
    }
}
