using System;
using System.Collections.Generic;

using AggUI;
using SystemTools;

namespace Example {

    using AntigrainCPP;

    class Application : AggWindow
    {

        public Application(bool flip_y) : base(flip_y)
        {
            this.fontEngine.LoadFont("Impacted.ttf");
            bool isBold = this.fontEngine.IsCurrentFaceBold;
            bool isItalic = this.fontEngine.IsCurrentFaceItalic;
            uint code = this.fontEngine.GetCharIndex((ulong)'A');
            Console.WriteLine($"bold: {isBold} italic: {isItalic} | code for 'A': {code}");
        }

        public override void OnDraw(GraphicContext gctx)
        {
            Path path = new Path();
            gctx.RendererSmooth.Color(0, 0, 0, 1);
            gctx.RendererSmooth.Setup(7, 2,
                1, 0,
                0, 1,
                0, 0
            );
            bool first = true;
            foreach (var point in points){
                (int x, int y, int r, int g, int b, int s) = point;
                if (first) {
                    path.MoveTo(x, y);
                    first = false;
                } else {
                    path.LineTo(x, y);
                }
                gctx.SetColor(r, g, b);
                gctx.DrawEllipse(x, y, s, s);
            }
            gctx.RendererSmooth.AddPath(path);
        }

        public override void OnKey(int x, int y, uint key, uint flags){
            points = new();
            this.ForceRedraw();
        }

        public override void OnMouseMove(int x, int y, uint flags){
            /* OnMouseMove(x, y, flags); */
        }

        public override void OnMouseButtonDown(int x, int y, uint flags){
            if (flags == 0){
                return;
            }
            if (count <= 0){
                count = rnd.Next(100, 500);
                size = rnd.Next(10, 50);
                color = (
                    rnd.Next(0, 256),
                    rnd.Next(0, 256),
                    rnd.Next(0, 256)
                );
            }
            count -= size;
            (int r, int g, int b) = color;
            int f;
            int s;
            if (flags == 1){
                f = 300;
                s = size;
            } else {
                f = 10;
                s = 15;
            } 
            double m = f / Math.Sqrt(r*r + g*g + b*b);
            r = (int)Math.Round(r*m);
            g = (int)Math.Round(g*m);
            b = (int)Math.Round(b*m);
            points.Add((x, y, r, g, b, s));
            this.ForceRedraw();
        }

        private List<(int, int, int, int, int, int)> points = new();
        private Random rnd = new();
        private (int, int, int) color = (0, 0, 0);
        private int size = 0;
        private int count = 0;

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

            if(app.Init(800, 600, WindowFlags.Resize))
            {
                System.Console.WriteLine("Run");
                return app.Run();
            }
            return 1;
        }
    }
}
