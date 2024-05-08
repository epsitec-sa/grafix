using System;
using System.Reflection;
using System.Runtime.InteropServices;
using static AntigrainSharp.Native;

namespace AntigrainSharp
{
    public class GraphicBuffer : System.IDisposable
    {
        public GraphicBuffer(uint width, uint height, int stride, FontManager fm)
        {
            System.Console.WriteLine($"GraphicBuffer with {width}x{height} stride {stride}");
            this.buffer = GraphicBuffer_NewGraphicBuffer(width, height, stride, fm.manager);
            IntPtr gctxHandle = GraphicBuffer_GetGraphicContext(this.buffer);
            this.gctx = new GraphicContext(gctxHandle);
        }

        public void Dispose()
        {
            GraphicBuffer_DeleteGraphicBuffer(this.buffer);
        }

        public GraphicContext GraphicContext
        {
            get { return this.gctx; }
        }

        public uint Width
        {
            get { return GraphicBuffer_GetWidth(this.buffer); }
        }

        public uint Height
        {
            get { return GraphicBuffer_GetHeight(this.buffer); }
        }

        public uint Stride
        {
            get { return GraphicBuffer_GetStride(this.buffer); }
        }

        public uint Length
        {
            get { return GraphicBuffer_GetBufferLength(this.buffer); }
        }

        public byte[] GetBufferData()
        {
            byte[] data = new byte[this.Length];
            GraphicBuffer_GetBufferData(this.buffer, data);
            return data;
        }

        private IntPtr buffer;
        private GraphicContext gctx;
    }
}
