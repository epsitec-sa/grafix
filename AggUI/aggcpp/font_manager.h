#pragma once

#include "agg_conv_contour.h"
#include "agg_font_freetype.h"


#include "declspec.h"
#include "pixelfmt.h"


namespace AntigrainCPP {

    class FontManager {

        typedef agg::font_engine_freetype_int32 font_engine;
        typedef agg::font_cache_manager<font_engine> font_manager_type;

        public:
            FontManager();

            bool load_font(const char* font_name);

            font_engine         m_feng;
            font_manager_type            m_fman;

            // Pipeline to process the vectors glyph paths (curves + contour)
            agg::conv_curve<font_manager_type::path_adaptor_type> m_curves;
            agg::conv_contour<agg::conv_curve<font_manager_type::path_adaptor_type> > m_contour;

    };

    extern "C" DECLSPEC bool FontManager_LoadFont(FontManager* fm,
        const char* font_name
    );
}
