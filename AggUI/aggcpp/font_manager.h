#pragma once

#include <string>

#include "agg_conv_contour.h"
#include "agg_font_freetype.h"


#include "declspec.h"
#include "pixelfmt.h"


namespace AntigrainCPP {

    class FontManager {

        public:
            typedef agg::font_engine_freetype_int32 font_engine;
            typedef agg::font_engine_freetype_int32::path_adaptor_type path_adaptor_type;

            FontManager();

            bool load_font(const char* font_name);
            void set_font_size(double size);
            void use_outline_mode(bool mode);

            font_engine              m_feng;
            std::string m_current_font_name;
            bool             m_outline_mode;
    };

    extern "C" DECLSPEC FontManager* FontManager_New();

    extern "C" DECLSPEC void FontManager_Delete(FontManager* fm);

    extern "C" DECLSPEC bool FontManager_LoadFont(FontManager* fm,
        const char* font_name
    );

    extern "C" DECLSPEC void FontManager_SetFontSize(FontManager* fm,
        double size
    );
}
