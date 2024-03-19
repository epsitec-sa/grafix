#include <windows.h>

void getScreenResolution(int &width, int &height) {
    width  = (int) GetSystemMetrics(SM_CXSCREEN);
    height = (int) GetSystemMetrics(SM_CYSCREEN);
}