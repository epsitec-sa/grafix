using System;
using System.Linq;
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
            double fontSize = 150.0;
            Font font = Font.LoadFromFile("Impacted.ttf");
            this.FontManager.SetFont(font, fontSize);
            this.glyphs = "The godfather".Select(c => font.GetCharIndex(c))
                                     .ToList();
            this.glyphsOffset = this.ComputeGlyphsOffset(this.glyphs, font, fontSize);
            System.Console.WriteLine(this.glyphsOffset);
        }

        public override void OnDraw(GraphicContext gctx)
        {
            // black background
            Rasterizer rast = new Rasterizer();
            Path rect = new RectanglePath(
                0, 0, 
                gctx.Width, gctx.Height
            );
            rast.AddPath(rect, curves: false);
            gctx.RendererSolid.Color(0, 0, 0, 1);
            rast.RenderSolid(gctx.RendererSolid);

            // drawing images
            var magicImage = new ImageMagick.MagickImage("godfather.png");
            var pixels = magicImage.GetPixels().ToByteArray(ImageMagick.PixelMapping.BGRA);
            int stride = -magicImage.Width * magicImage.Depth * magicImage.ChannelCount / 8;
            gctx.RendererImage.AttachSource(
                pixels,
                magicImage.BaseWidth,
                magicImage.BaseHeight,
                stride
            );
            rast = new Rasterizer();
            rect = new RectanglePath(
                0, 0, 
                magicImage.BaseWidth, magicImage.BaseHeight
            );
            rast.AddPath(rect, curves: false);
            rast.RenderImage(gctx.RendererImage);

            // drawing text
            rast = new Rasterizer();
            double a = 9.0 / 41.0;
            double b = 40.0 / 41.0;
            rast.SetTransform(b, -a, a, b, 150, 50);
            foreach (var (glyph, offset) in this.glyphs.Zip(this.glyphsOffset)){
                rast.AddGlyph((int)glyph, offset, 0, 1.0, this.FontManager);
            }
            gctx.RendererSolid.Color(0.98, 0.05, 0.2, 0.8);
            rast.RenderSolid(gctx.RendererSolid);
        }

        private List<double> ComputeGlyphsOffset(List<uint> glyphs, Font font, double size){
            List<double> offsets = new();
            double x = 0;
            uint? prevGlyph = null;
            foreach (uint glyph in glyphs){
                offsets.Add(x);
                x += font.GetGlyphAdvance(glyph, size);
                if (prevGlyph != null){
                    x += font.GetKerning(prevGlyph.Value, glyph, size);
                }
                prevGlyph = glyph;
            }
            return offsets;
        }

        private List<uint> glyphs;
        private List<double> glyphsOffset;
    }

    public static class Program
    {
        public static int Main(string[] args)
        {
            System.Console.WriteLine("Create Application");
            FontManager fm = new FontManager();
            Application app = new Application(true, fm);
            app.SetCaption("AggUI example");

            if (app.Init(1000, 900, WindowFlags.Resize))
            {
                System.Console.WriteLine("Run");
                return app.Run();
            }
            return 1;
        }
    }
}
