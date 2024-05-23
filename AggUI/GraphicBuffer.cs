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

        public int Stride
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

        public IntPtr GetBufferDataHandle()
        {
            return this.buffer;
        }

        public abstract void Dispose();

        protected internal IntPtr buffer;
        protected GraphicContext gctx;
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
            //System.Console.WriteLine($"GraphicBuffer with {width}x{height} stride {stride}");
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

        public override void Dispose()
        {
            GraphicBuffer_DeleteGraphicBufferExternalData(this.buffer);
        }
    }

    public class GraphicBuffer : AbstractGraphicBuffer
    {
        public GraphicBuffer(uint width, uint height, int stride, FontManager fm)
        {
            //System.Console.WriteLine($"GraphicBuffer with {width}x{height} stride {stride}");
            this.buffer = GraphicBuffer_NewGraphicBuffer(width, height, stride, fm.manager);
            IntPtr gctxHandle = GraphicBuffer_GetGraphicContext(this.buffer);
            this.gctx = new GraphicContext(gctxHandle, width, height);
        }

        ~GraphicBuffer()
        {
            System.Console.WriteLine("delete GraphicBuffer");
        }

        public override void Dispose()
        {
            System.Console.WriteLine("Dispose GraphicBuffer");
            GraphicBuffer_DeleteGraphicBuffer(this.buffer);
        }
    }
}
