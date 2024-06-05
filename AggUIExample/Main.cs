using System;
using System.Collections.Generic;
using AntigrainSharp;
using SystemTools;

namespace Example
{
    class Application : AggWindow
    {
        public Application(bool flip_y, FontManager fm)
            : base(flip_y, fm)
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

            /* Console.WriteLine($"read image"); */
            /* this.inputImage = new ImageMagick.MagickImage("transparent.png"); */
        }

        public override void OnDraw(GraphicContext gctx)
        {
            Rasterizer rast = new Rasterizer();
            rast.SetTransform(0, -1, 1, 0, 150, 150);
            rast.AddGlyph(68, 0, 0, 1.0, this.FontManager);
            rast.SetTransform(-1, 0, 0, -1, 150, 150);
            rast.AddGlyph(69, 30, 20, 2.0, this.FontManager);
            rast.AddGlyph(70, 50, -10, 1.0, this.FontManager);
            gctx.RendererSolid.Color(1, 0, 0, 1);
            rast.RenderSolid(gctx.RendererSolid);
        }
    }

    public static class Program
    {
        public static int Main(string[] args)
        {
            System.Console.WriteLine("Create Application");
            FontManager fm = new FontManager();
            Application app = new Application(true, fm);
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
