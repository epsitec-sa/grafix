#pragma once

#include "agg_conv_contour.h"
#include "agg_font_freetype.h"


#include "declspec.h"
#include "pixelfmt.h"


namespace AntigrainCPP {

    class FontManager {

        typedef agg::font_engine_freetype_int32 font_engine;

        public:
            FontManager();

            bool load_font(const char* font_name);
            void set_font_size(double size);

            font_engine         m_feng;
    };

    extern "C" DECLSPEC bool FontManager_LoadFont(FontManager* fm,
        const char* font_name
    );

    extern "C" DECLSPEC void FontManager_SetFontSize(FontManager* fm,
        double size
    );
}
