#include "antigrain.h"
#include <iostream>

namespace AntigrainCPP {
    extern "C" agg::platform_support* NewPlatformSupport(agg::pix_format_e format, bool flip_y){
		std::cout << "[C++] new platform_support(format=" << format << ", flip_y=" << flip_y << ")" << std::endl;
        return new agg::platform_support(format, flip_y);
    }

    extern "C" void PlatformSupport_Caption(agg::platform_support* ps, const char* text){
		std::cout << "[C++] caption: " << text << std::endl;
        ps->caption(text);
    }

    extern "C" bool PlatformSupport_Init(agg::platform_support* ps, 
                                         unsigned width, unsigned height,
                                         agg::window_flag_e flags){
		std::cout << "[C++] init: (" << width << ", " << height << ") flags: " << flags << std::endl;
        return ps->init(width, height, flags);
    }

    extern "C" int PlatformSupport_Run(agg::platform_support* ps){
		std::cout << "[C++] run" << std::endl;
        return ps->run();
    }
}

int agg_main(int argc, char* argv[]){
	return 1;
}
