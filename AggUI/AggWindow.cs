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

    public class AggWindow : IDisposable
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
            this.fontManager = fm;
        }

        ~AggWindow(){
            this.Dispose();
        }

        public void Dispose(){
            if (this.app != IntPtr.Zero){
                Application_Delete(this.app);
                this.app = IntPtr.Zero;
            }
            this.fontManager = null;
            this.onDrawDelegate = null;
            this.onResizeDelegate = null;
            this.onMouseMoveDelegate = null;
            this.onMouseButtonDownDelegate = null;
            this.onMouseButtonUpDelegate = null;
            this.onKeyDelegate = null;
            GC.SuppressFinalize(this);
        }

        private void RequireNotDisposed(){
            if (this.app == IntPtr.Zero){
                throw new ObjectDisposedException(this.GetType().FullName);
            }
        }

        public AntigrainSharp.FontManager FontManager{
            get {
                this.RequireNotDisposed();
                return this.fontManager;
            }
        }

        public void SetCaption(string text)
        {
            this.RequireNotDisposed();
            Application_Caption(this.app, text);
        }

        public bool Init(uint width, uint height, WindowFlags flags)
        {
            this.RequireNotDisposed();
            return Application_Init(this.app, width, height, flags);
        }

        public int Run()
        {
            this.RequireNotDisposed();
            return Application_Run(this.app);
        }

        public void ForceRedraw()
        {
            this.RequireNotDisposed();
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

        public AntigrainSharp.FontManager fontManager;

        private IntPtr app;
        private OnDrawT onDrawDelegate;
        private OnResizeT onResizeDelegate;
        private OnMouseMoveT onMouseMoveDelegate;
        private OnMouseButtonDownT onMouseButtonDownDelegate;
        private OnMouseButtonUpT onMouseButtonUpDelegate;
        private OnKeyT onKeyDelegate;
    }
}
