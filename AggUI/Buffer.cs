// Copyright © 2003-2024, EPSITEC SA, CH-1400 Yverdon-les-Bains, Switzerland
// Author: Pierre ARNAUD, Roger VUISTINER, Maintainer: Roger VUISTINER

using System.Runtime.InteropServices;

using static AntigrainCPP.Native;

namespace AntigrainCPP
{
    public static partial class Buffer
    {
        public static IntPtr New(int dx, int dy, int bpp)
        {
            IntPtr result = AggBufferNew((uint)dx, (uint)dy, (uint)bpp);
            return result;
        }
        public static IntPtr NewFrom(int dx, int dy, int bpp, int stride, IntPtr ptr, [MarshalAs(UnmanagedType.U1)] bool copyBits)
        {
            IntPtr result = AggBufferNewFrom((uint)dx, (uint)dy, (uint)bpp, stride, ptr, copyBits);
            return result;
        }
        public static bool   Resize(IntPtr buffer, int dx, int dy, int bpp)
        {
            return AggBufferResize(buffer, (uint)dx, (uint)dy, (uint)bpp);
        }
        public static void   InfiniteClipping(IntPtr buffer)
        {
            AggBufferInfiniteClipping(buffer);
        }
        public static void   EmptyClipping(IntPtr buffer)
        {
            AggBufferEmptyClipping(buffer);
        }
        public static void   AddClipBox(IntPtr buffer, int x1, int y1, int x2, int y2)
        {
            AggBufferAddClipBox(buffer, x1, y1, x2, y2);
        }
        public static void   DrawGlyphs(IntPtr buffer, IntPtr hfont, int x, int y, ushort[] glyphs, int[] dx_array, int count, uint color)
        {
            AggBufferDrawGlyphs(buffer, hfont, x, y, glyphs, dx_array, (uint)count, color);
        }
        public static void   Paint(IntPtr buffer, IntPtr hdc, int x1, int y1, int x2, int y2)
        {
            AggBufferPaint(buffer, hdc, x1, y1, x2, y2);
        }
        public static void   PaintOffset(IntPtr buffer, IntPtr hdc, int ox, int oy, int x1, int y1, int x2, int y2)
        {
            AggBufferPaintOffset(buffer, hdc, ox, oy, x1, y1, x2, y2);
        }
        public static void   BlendOffset(IntPtr buffer, IntPtr hdc, int ox, int oy, int x1, int y1, int x2, int y2)
        {
            AggBufferBlendOffset(buffer, hdc, ox, oy, x1, y1, x2, y2);
        }
        public static void   Clear(IntPtr buffer)
        {
            AggBufferClear(buffer);
        }
        public static void   ClearRect(IntPtr buffer, int x1, int y1, int x2, int y2)
        {
            AggBufferClearRect(buffer, x1, y1, x2, y2);
        }
        public static IntPtr GetMemoryLayout(IntPtr buffer, out int width, out int height, out int stride)
        {
            AggBufferGetMemoryLayout(buffer, out width, out height, out stride, out IntPtr result);
            return result;
        }
        public static IntPtr GetMemoryBitmapHandle(IntPtr buffer)
        {
            return AggBufferGetMemoryBitmapHandle(buffer);
        }
        public static void   BltBuffer(IntPtr buffer, int xd, int yd, IntPtr source, int xs, int ys, int dx, int dy)
        {
            AggBufferBltBuffer(buffer, xd, yd, source, xs, ys, dx, dy);
        }
        public static void   ComposeBuffer(IntPtr buffer, int xd, int yd, IntPtr source, int xs, int ys, int dx, int dy)
        {
            AggBufferComposeBuffer(buffer, xd, yd, source, xs, ys, dx, dy);
        }
        public static void   Delete(IntPtr buffer)
        {
            AggBufferDelete(buffer);
        }
    }
}
