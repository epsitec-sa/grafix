using System;
using System.Reflection;
using System.Runtime.InteropServices;
using static AntigrainSharp.Native;

namespace AntigrainSharp
{
    [Flags]
    public enum WindowFlags : uint
    {
        Resize = 1,
        HWBuffer = 2,
        KeepAspectRatio = 4,
        ProcessAllKeys = 8
    };

    public class AggWindow
    {
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
            IntPtr fd = Application_GetFontManager(this.app);
            this.FontManager = new AntigrainSharp.FontManager(fd);
        }

        public void SetCaption(string text)
        {
            Application_Caption(this.app, text);
        }

        public bool Init(uint width, uint height, WindowFlags flags)
        {
            return Application_Init(this.app, width, height, flags);
        }

        public int Run()
        {
            return Application_Run(this.app);
        }

        public void ForceRedraw()
        {
            Application_ForceRedraw(this.app);
        }

        internal void InternalOnDraw(IntPtr gctx)
        {
            GraphicContext graphicContext = new GraphicContext(gctx);
            this.OnDraw(graphicContext);
        }

        public virtual void OnDraw(GraphicContext gctx) { }

        public virtual void OnResize(int sx, int sy) { }

        public virtual void OnMouseMove(int x, int y, uint flags) { }

        public virtual void OnMouseButtonDown(int x, int y, uint flags) { }

        public virtual void OnMouseButtonUp(int x, int y, uint flags) { }

        public virtual void OnKey(int x, int y, uint key, uint flags) { }

        public AntigrainSharp.FontManager FontManager;

        private IntPtr app;
        private OnDrawT onDrawDelegate;
        private OnResizeT onResizeDelegate;
        private OnMouseMoveT onMouseMoveDelegate;
        private OnMouseButtonDownT onMouseButtonDownDelegate;
        private OnMouseButtonUpT onMouseButtonUpDelegate;
        private OnKeyT onKeyDelegate;
    }
}
