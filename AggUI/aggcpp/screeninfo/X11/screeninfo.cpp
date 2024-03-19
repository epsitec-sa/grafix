#include <X11/Xlib.h>

void getScreenResolution(int &width, int &height) {
    Display* disp = XOpenDisplay(NULL);
    Screen*  scrn = DefaultScreenOfDisplay(disp);
    width  = scrn->width;
    height = scrn->height;
}