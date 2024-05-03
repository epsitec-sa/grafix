using System;
using System.Reflection;
using System.Runtime.InteropServices;

namespace AntigrainCPP {

    public class GraphicBuffer {
        private const string LibAgg = "AntigrainCPP";

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        private static extern IntPtr GraphicBuffer_NewGraphicBuffer(
            uint width, uint height, int stride,
            IntPtr fm
        );

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        private static extern void GraphicBuffer_DeleteGraphicBuffer(IntPtr gbuff);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        private static extern IntPtr GraphicBuffer_GetGraphicContext(IntPtr gbuff);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        private static extern uint GraphicBuffer_GetWidth(IntPtr gbuff);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        private static extern uint GraphicBuffer_GetHeight(IntPtr gbuff);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        private static extern uint GraphicBuffer_GetBufferLength(IntPtr gbuff);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        private static extern void GraphicBuffer_GetBufferData(IntPtr gbuff, [MarshalAs(UnmanagedType.LPArray)] [In, Out] byte[] output_buffer);

        public void PrintByteArray(byte[] arr){
            int colorStep = 4;
            int width = 3;
            Console.WriteLine($"---");
            int step = 0;
            for (int i = 0; i < arr.Length; i += colorStep){
                string elem = System.Convert.ToHexString(new ArraySegment<byte>(arr, i, colorStep));
                Console.Write($"{elem} ");
                step++;
                if (step % width == 0){
                    Console.WriteLine("");
                }
            }
            Console.WriteLine($"---");
        }

        public GraphicBuffer(uint width, uint height, int stride, FontManager fm){
            System.Console.WriteLine($"GraphicBuffer with {width}x{height} stride {stride}");
            /* this.data = new byte[height * System.Math.Abs(stride)]; */
            /* this.data_handle = GCHandle.Alloc(this.data, GCHandleType.Pinned); */
            /* for (int i = 0; i < this.data.Length; i++){ */
            /*     this.data[i] = 0xff; */
            /* } */
            /* System.Console.WriteLine($"data {this.data} {this.data.Length}"); */
            /* this.PrintByteArray(this.data); */
            this.buffer = GraphicBuffer_NewGraphicBuffer(width, height, stride, fm.manager);
            IntPtr gctxHandle = GraphicBuffer_GetGraphicContext(this.buffer);
            this.gctx = new GraphicContext(gctxHandle);
        }

        ~GraphicBuffer(){
            GraphicBuffer_DeleteGraphicBuffer(this.buffer);
            /* this.data_handle.Free(); */
        }

        public GraphicContext GraphicContext
        {
            get { return this.gctx; }
        }

        public uint Width {
            get { return GraphicBuffer_GetWidth(this.buffer); }
        }

        public uint Height {
            get { return GraphicBuffer_GetHeight(this.buffer); }
        }

        public uint Length {
            get { return GraphicBuffer_GetBufferLength(this.buffer); }
        }

        public byte[] GetBufferData() {
            byte[] data = new byte[this.Length];
            GraphicBuffer_GetBufferData(this.buffer, data);
            return data;
        }

        /* private byte[] data; */
        /* private GCHandle data_handle; */
        private IntPtr buffer;
        private GraphicContext gctx;
    }
}


