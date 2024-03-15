using AggUI;

namespace Example {

    class Application : AggWindow
    {


        public Application(PixFmt format, bool flip_y) : base(format, flip_y)
        {
        }

        public virtual void on_resize(int cx, int cy)
        {
        }

        public virtual void on_draw()
        {
        }


        public void transform(double width, double height, double x, double y)
        {
        }


        public virtual void on_mouse_button_down(int x, int y, uint flags)
        {
        }


        public virtual void on_mouse_move(int x, int y, uint flags)
        {
            on_mouse_button_down(x, y, flags);
        }

    }

    public static class Program
    {

        public static int Main(string[] args)
        {
            System.Console.WriteLine("main.cs:Main()");
            System.Console.WriteLine("Create Application");
            Application app = new Application(PixFmt.pix_format_bgr24, true);
            System.Console.WriteLine("set caption");
            app.caption("AggUI example");

            System.Console.WriteLine("try init");
            if(app.init(800, 600, WindowFlags.Resize))
            {
                System.Console.WriteLine("run");
                return app.run();
            }
            return 1;
        }
    }
}
