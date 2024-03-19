// Copyright © 2003-2024, EPSITEC SA, CH-1400 Yverdon-les-Bains, Switzerland
// Author: Pierre ARNAUD, Roger VUISTINER, Maintainer: Roger VUISTINER

using static AntigrainCPP.Native;

namespace AntigrainCPP
{
    public static partial class Font
    {
        public static IntPtr  CreateFaceHandle(byte[] data, int size, int offset, IntPtr handle)
        {
            return AggFontCreateFaceFromFontData(data, (uint)size, (uint)offset, handle);
        }
        public static void    DisposeFaceHandle(IntPtr face)
        {
            AggFontDisposeFace(face);
        }
        public static string? GetUnicodeName(int code)
        {
            char[] buffer = new char[1024];
            if (AggFontGetUnicodeName(code, buffer))
            {
                return new string(buffer);
            }
            return null;
        }

        public class PixelCache
        {
            public static void   Paint(IntPtr buffer, IntPtr face, double scale, ushort[] glyphs, double[] xa, double[]? ya, double[]? sxa, double r, double g, double b, double a, double xx, double yy, double tx, double ty)
            {
                int n = glyphs.Length;
                if (ya is null)
                {
                    if (sxa is null)
                    {
                        double y = ty;
                        double sx = scale * xx;
                        double sy = scale * yy;

                        for (int i = 0; i < n; i++)
                        {
                            double x = xa[i] * xx + tx;

                            AggFontPixelCacheGlyphXY(buffer, face, glyphs[i], x, y, sx, sy, r, g, b, a);
                        }
                    }
                    else
                    {
                        double y = ty;
                        double sy = scale * yy;

                        for (int i = 0; i < n; i++)
                        {
                            double x = xa[i] * xx + tx;
                            double sx = sxa[i] * scale * xx;

                            AggFontPixelCacheGlyphXY(buffer, face, glyphs[i], x, y, sx, sy, r, g, b, a);
                        }
                    }
                }
                else if (sxa is null)
                {
                    double sx = scale * xx;
                    double sy = scale * yy;

                    for (int i = 0; i < n; i++)
                    {
                        double x = xa[i] * xx + tx;
                        double y = ya[i] * yy + ty;

                        AggFontPixelCacheGlyphXY(buffer, face, glyphs[i], x, y, sx, sy, r, g, b, a);
                    }
                }
                else
                {
                    double sy = scale * yy;

                    for (int i = 0; i < n; i++)
                    {
                        double x = xa[i] * xx + tx;
                        double y = ya[i] * yy + ty;
                        double sx = sxa[i] * scale * xx;

                        AggFontPixelCacheGlyphXY(buffer, face, glyphs[i], x, y, sx, sy, r, g, b, a);
                    }
                }
            }
            public static double Paint(IntPtr buffer, IntPtr face, ushort[] glyphs, double scale, double ox, double oy, double r, double g, double b, double a)
            {
                return AggFontPixelCacheFill(buffer, face, glyphs, glyphs.Length, scale, ox, oy, r, g, b, a);
            }
            public static void   Fill(IntPtr face, ushort[] glyphs, double scale, double ox, double oy)
            {
                AggFontPixelCacheFill(IntPtr.Zero, face, glyphs, glyphs.Length, scale, ox, oy, 0.0, 0.0, 0.0, 0.0);
            }
        }
    }
}
