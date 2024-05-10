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

    [Flags]
    public enum InputFlags : uint
    {
        MouseLeft  = 1,
        MouseRight = 2,
        KbdShift   = 4,
        KbdCtrl    = 8
    };

    public class AggWindow
    {
        public AggWindow(bool flip_y, FontManager fm)
        {
            onDrawDelegate = InternalOnDraw;
            onResizeDelegate = OnResize;
            onMouseMoveDelegate = InternalOnMouseMove;
            onMouseButtonDownDelegate = InternalOnMouseButtonDown;
            onMouseButtonUpDelegate = InternalOnMouseButtonUp;
            onKeyDelegate = InternalOnKey;
            this.app = NewApplication(
                flip_y,
                onDrawDelegate,
                onResizeDelegate,
                onMouseMoveDelegate,
                onMouseButtonDownDelegate,
                onMouseButtonUpDelegate,
                onKeyDelegate,
                fm.manager
            );
            this.FontManager = fm;
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

        internal void InternalOnMouseMove(int x, int y, uint flags) {
            this.OnMouseMove(x, y, (InputFlags)flags);
         }

        internal void InternalOnMouseButtonDown(int x, int y, uint flags) { 
            this.OnMouseButtonDown(x, y, (InputFlags)flags);
        }

        internal void InternalOnMouseButtonUp(int x, int y, uint flags) { 
            this.OnMouseButtonUp(x, y, (InputFlags)flags);
        }

        internal void InternalOnKey(int x, int y, uint key, uint flags) { 
            this.OnKey(x, y, key, (InputFlags)flags);
        }

        public virtual void OnDraw(GraphicContext gctx) { }

        public virtual void OnResize(int sx, int sy) { }

        public virtual void OnMouseMove(int x, int y, InputFlags flags) { }

        public virtual void OnMouseButtonDown(int x, int y, InputFlags flags) { }

        public virtual void OnMouseButtonUp(int x, int y, InputFlags flags) { }

        public virtual void OnKey(int x, int y, uint key, InputFlags flags) { }

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
