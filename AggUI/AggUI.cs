using System;
using System.Reflection;
using System.Runtime.InteropServices;

namespace AggUI {

    [Flags]
    public enum WindowFlags : uint
    {
        Resize          = 1,
        HWBuffer        = 2,
        KeepAspectRatio = 4,
        ProcessAllKeys  = 8
    };

    public class AggWindow
    {
        private const string LibAgg = "AntigrainCPP";

        delegate void OnDrawT(IntPtr gctx);
        delegate void OnResizeT(int sx, int sy);
        delegate void OnMouseMoveT(int x, int y, uint flags);
        delegate void OnMouseButtonDownT(int x, int y, uint flags);
        delegate void OnMouseButtonUpT(int x, int y, uint flags);
        delegate void OnKeyT(int x, int y, uint key, uint flags);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        private static extern IntPtr NewApplication(
            bool flip_y,
            OnDrawT on_draw,
            OnResizeT on_resize,
            OnMouseMoveT on_mouse_move,
            OnMouseButtonDownT on_mouse_button_down,
            OnMouseButtonUpT on_mouse_button_up,
            OnKeyT on_key
        );

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

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        private static extern IntPtr Application_GetRendererSolid(IntPtr app);

        public AggWindow(bool flip_y)
        {
            onDrawDelegate = InternalOnDraw;
            onResizeDelegate = OnResize;
            onMouseMoveDelegate = OnMouseMove;
            onMouseButtonDownDelegate = OnMouseButtonDown;
            onMouseButtonUpDelegate = OnMouseButtonUp;
            onKeyDelegate = OnKey;
            this.app = NewApplication(
                flip_y,
                onDrawDelegate,
                onResizeDelegate,
                onMouseMoveDelegate,
                onMouseButtonDownDelegate,
                onMouseButtonUpDelegate,
                onKeyDelegate
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

        internal void InternalOnDraw(IntPtr gctx){
            GraphicContext graphicContext = new GraphicContext(gctx);
            this.OnDraw(graphicContext);
        }

        public virtual void OnDraw(GraphicContext gctx){}

        public virtual void OnResize(int sx, int sy){}

        public virtual void OnMouseMove(int x, int y, uint flags){}

        public virtual void OnMouseButtonDown(int x, int y, uint flags){}

        public virtual void OnMouseButtonUp(int x, int y, uint flags){}

        public virtual void OnKey(int x, int y, uint key, uint flags){}

        private IntPtr app;
        private OnDrawT onDrawDelegate;
        private OnResizeT onResizeDelegate;
        private OnMouseMoveT onMouseMoveDelegate;
        private OnMouseButtonDownT onMouseButtonDownDelegate;
        private OnMouseButtonUpT onMouseButtonUpDelegate;
        private OnKeyT onKeyDelegate;
    }
}
