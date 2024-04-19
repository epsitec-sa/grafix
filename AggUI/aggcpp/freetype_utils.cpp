#include "freetype_utils.h"

signed long doubleToF26Dot6(double x){
    return static_cast<signed long>(x*(2 << 6));
}

double F26Dot6ToDouble(signed long x){
    return static_cast<double>(x) / (2 << 6);
}
