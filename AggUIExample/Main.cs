using System;
using System.Collections.Generic;
using AntigrainCPP;
using SystemTools;

namespace Example
{
    class Application : AggWindow
    {
        public Application(bool flip_y)
            : base(flip_y)
        {
            Font font = Font.LoadFromFile("Impacted.ttf");
            bool isBold = font.IsBold;
            bool isItalic = font.IsItalic;
            double fontSize = 12;
            double ascender = font.GetAscender(fontSize);
            double descender = font.GetDescender(fontSize);
            double height = font.GetHeight(fontSize);
            Console.WriteLine($"bold: {isBold} italic: {isItalic} font size: {fontSize}");
            Console.WriteLine($"ascender {ascender} descender {descender} height {height}");
            double xMin,
                xMax,
                yMin,
                yMax;
            foreach (char testChar in "abcdœéß!+-¿ÆæÊ")
            {
                uint code = font.GetCharIndex((ulong)testChar);
                double advance = font.GetGlyphAdvance(code, fontSize);
                font.GetGlyphBBox(code, fontSize, out xMin, out xMax, out yMin, out yMax);
                Console.WriteLine(
                    $"'{testChar}': code {code}, advance {advance} bbox x[{xMin}, {xMax}] y[{yMin}, {yMax}]"
                );
            }
            this.FontManager.SetFont(font);

            Console.WriteLine($"read image");
            this.inputImage = new ImageMagick.MagickImage("grid.png");
        }

        public override void OnDraw(GraphicContext gctx)
        {
            /* Path path = new Path(); */
            /* gctx.RendererSmooth.Color(0, 0, 0, 1); */
            /* gctx.RendererSmooth.Setup(7, 2, */
            /*     1, 0, */
            /*     0, 1, */
            /*     0, 0 */
            /* ); */
            /* bool first = true; */
            /* foreach (var point in points){ */
            /*     (int x, int y, int r, int g, int b, int s) = point; */
            /*     if (first) { */
            /*         path.MoveTo(x, y); */
            /*         first = false; */
            /*     } else { */
            /*         path.LineTo(x, y); */
            /*     } */
            /*     gctx.SetColor(r / 255.0, g / 255.0, b / 255.0, 0.8); */
            /*     gctx.DrawEllipse(x, y, s, s); */
            /* } */
            /* gctx.RendererSmooth.AddPath(path); */
            /* double xp = 0; */
            GenerateOutputImage(gctx, this.inputImage);
        }

        public void PrintByteArray(byte[] arr)
        {
            int colorStep = 4;
            int width = 3;
            Console.WriteLine($"---");
            int step = 0;
            for (int i = 0; i < arr.Length; i += colorStep)
            {
                string elem = Convert.ToHexString(new ArraySegment<byte>(arr, i, colorStep));
                Console.Write($"{elem} ");
                step++;
                if (step % width == 0)
                {
                    Console.WriteLine("");
                }
            }
            Console.WriteLine($"---");
        }

        public void GenerateOutputImage(GraphicContext gctx, ImageMagick.MagickImage image)
        {
            //byte[] buffer = image.GetPixels().ToByteArray(ImageMagick.PixelMapping.BGRA);
            //Console.WriteLine(
            //    $"GenerateOutputImage: got an image {image.Width}x{image.Height} buffer size {buffer.Length}"
            //);
            //this.PrintByteArray(buffer);
            //int stride = -sizeof(byte) * image.Width * 4;

            //gctx.RendererImage.Matrix(1, 0, 0, 1, 0, 0);
            //Console.WriteLine($"attach input buffer: {buffer.Length}");
            //this.PrintByteArray(buffer);
            //gctx.RendererImage.AttachSource(buffer, image.Width, image.Height, stride);
            //gctx.RendererImage.SetStretchMode(0, 0.0); // important to call after attach source
            //var rast = new AntigrainCPP.Rasterizer();
            //Console.WriteLine($"Make rect");
            //var rect = new AntigrainCPP.RectanglePath(0, 0, image.Width, image.Height);
            //Console.WriteLine($"Add rect to rasterizer");
            //rast.AddPath(rect, false);
            //Console.WriteLine($"render image");
            //rast.RenderImage(gctx.RendererImage);

            gctx.SetColor(0.9, 0.0, 0.0, 1.0);
            //this.FontManager.SetFontSize(155);
            //gctx.DrawText("M", -10, 0);
            gctx.DrawEllipse(0, 0, 10, 10);
            Console.WriteLine($"GenerateOutputImage done");
        }

        public override void OnKey(int x, int y, uint key, uint flags)
        {
            points = new();

            Console.WriteLine(
                $"=============================== START FILE OUTPUT IMAGE ==============================="
            );
            Console.WriteLine($"create graphic buffer");
            int stride = -sizeof(byte) * this.inputImage.Width * 4;
            GraphicBuffer gbuff = new GraphicBuffer(
                (uint)this.inputImage.Width,
                (uint)this.inputImage.Height,
                stride,
                this.FontManager
            );
            Console.WriteLine($"graphic buffer size {gbuff.Width}x{gbuff.Height}");

            //Console.WriteLine($"get buffer pixels before paint");
            //byte[] pre_buffer = gbuff.GetBufferData();
            //Console.WriteLine($"buffer length: {pre_buffer.Length}");
            //this.PrintByteArray(pre_buffer);

            this.GenerateOutputImage(gbuff.GraphicContext, this.inputImage);

            var settings = new ImageMagick.PixelImportSettings(
                // image.Width,
                // image.Height,
                (int)gbuff.Width,
                (int)gbuff.Height,
                ImageMagick.StorageType.Char,
                ImageMagick.PixelMapping.BGRA
            );
            Console.WriteLine($"create output image");
            using var outputImage = new ImageMagick.MagickImage(
                new ImageMagick.MagickColor("#ffffffff"),
                (int)gbuff.Width,
                (int)gbuff.Height
            );

            Console.WriteLine($"get buffer pixels after paint");
            byte[] out_buffer = gbuff.GetBufferData();
            Console.WriteLine($"buffer length: {out_buffer.Length}");
            this.PrintByteArray(out_buffer);

            Console.WriteLine($"import pixels");
            outputImage.ImportPixels(out_buffer, settings);
            Console.WriteLine($"write output image");
            outputImage.Write("output.png");

            Console.WriteLine(
                $"=============================== END FILE OUTPUT IMAGE ==============================="
            );

            this.ForceRedraw();
        }

        public override void OnMouseMove(int x, int y, uint flags)
        {
            /* OnMouseMove(x, y, flags); */
        }

        public override void OnMouseButtonDown(int x, int y, uint flags)
        {
            if (flags == 0)
            {
                return;
            }
            if (count <= 0)
            {
                count = rnd.Next(100, 500);
                size = rnd.Next(10, 50);
                color = (rnd.Next(0, 256), rnd.Next(0, 256), rnd.Next(0, 256));
            }
            count -= size;
            (int r, int g, int b) = color;
            int f;
            int s;
            if (flags == 1)
            {
                f = 300;
                s = size;
            }
            else
            {
                f = 10;
                s = 15;
            }
            double m = f / Math.Sqrt(r * r + g * g + b * b);
            r = (int)Math.Round(r * m);
            g = (int)Math.Round(g * m);
            b = (int)Math.Round(b * m);
            points.Add((x, y, r, g, b, s));
            this.ForceRedraw();
        }

        private List<(int, int, int, int, int, int)> points = new();
        private Random rnd = new();
        private (int, int, int) color = (0, 0, 0);
        private int size = 0;
        private int count = 0;

        private ImageMagick.MagickImage inputImage;
    }

    public static class Program
    {
        public static int Main(string[] args)
        {
            System.Console.WriteLine("Create Application");
            Application app = new Application(true);
            ScreenInfo.Rect res = ScreenInfo.GetResolution();
            System.Console.WriteLine($"Screen resolution: {res.Width}, {res.Height}");
            app.SetCaption("AggUI example");

            if (app.Init(800, 600, WindowFlags.Resize))
            {
                System.Console.WriteLine("Run");
                return app.Run();
            }
            return 1;
        }
    }
}
