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
            onResizeDelegate = InternalOnResize;
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
            this.Width = width;
            this.Height = height;
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
            GraphicContext graphicContext = new GraphicContext(
                gctx,
                this.Width, this.Height
            );
            this.OnDraw(graphicContext);
        }

        internal void InternalOnResize(int sx, int sy) {
            this.Width = (uint)sx;
            this.Height = (uint)sy;
            this.OnResize(sx, sy);
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

        public uint Width { get; private set; }
        public uint Height { get; private set; }

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
