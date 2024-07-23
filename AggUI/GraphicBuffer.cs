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
    public abstract class AbstractGraphicBuffer : System.IDisposable
    {
        public GraphicContext GraphicContext
        {
            get {
                this.RequireNotDisposed();
                return this.gctx;
            }
        }

        public uint Width
        {
            get {
                this.RequireNotDisposed();
                return GraphicBuffer_GetWidth(this.buffer);
            }
        }

        public uint Height
        {
            get {
                this.RequireNotDisposed();
                return GraphicBuffer_GetHeight(this.buffer);
            }
        }

        public int Stride
        {
            get {
                this.RequireNotDisposed();
                return GraphicBuffer_GetStride(this.buffer);
            }
        }

        public uint Length
        {
            get {
                this.RequireNotDisposed();
                return GraphicBuffer_GetBufferLength(this.buffer);
            }
        }

        public byte[] GetBufferData()
        {
            this.RequireNotDisposed();
            byte[] data = new byte[this.Length];
            GraphicBuffer_GetBufferData(this.buffer, data);
            return data;
        }

        public IntPtr GetBufferDataHandle()
        {
            this.RequireNotDisposed();
            return this.buffer;
        }

        private void RequireNotDisposed(){
            if (this.buffer == IntPtr.Zero){
                throw new ObjectDisposedException(this.GetType().FullName);
            }
        }

        public abstract void Dispose();

        protected internal IntPtr buffer;
        protected GraphicContext gctx = null!;
    }

    public class GraphicBufferExternalData : AbstractGraphicBuffer
    {
        public GraphicBufferExternalData(
            IntPtr data_buffer,
            uint width,
            uint height,
            int stride,
            FontManager fm
        )
        {
            this.buffer = GraphicBuffer_NewGraphicBufferExternalData(
                data_buffer,
                width,
                height,
                stride,
                fm.manager
            );
            IntPtr gctxHandle = GraphicBuffer_GetGraphicContext(this.buffer);
            this.gctx = new GraphicContext(gctxHandle, width, height);
        }

        ~GraphicBufferExternalData(){
            this.Dispose();
        }

        public override void Dispose()
        {
            if (this.buffer != IntPtr.Zero){
                GraphicBuffer_DeleteGraphicBufferExternalData(this.buffer);
                this.buffer = IntPtr.Zero;
            }
            GC.SuppressFinalize(this);
        }
    }

    public class GraphicBuffer : AbstractGraphicBuffer
    {
        public GraphicBuffer(uint width, uint height, int stride, FontManager fm)
        {
            this.buffer = GraphicBuffer_NewGraphicBuffer(width, height, stride, fm.manager);
            IntPtr gctxHandle = GraphicBuffer_GetGraphicContext(this.buffer);
            this.gctx = new GraphicContext(gctxHandle, width, height);
        }

        ~GraphicBuffer(){
            this.Dispose();
        }

        public override void Dispose()
        {
            if (this.buffer != IntPtr.Zero){
                GraphicBuffer_DeleteGraphicBuffer(this.buffer);
                this.buffer = IntPtr.Zero;
            }
            GC.SuppressFinalize(this);
        }
    }
}
