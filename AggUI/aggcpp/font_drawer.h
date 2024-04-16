#pragma once

#include "agg_conv_contour.h"
#include "agg_font_freetype.h"


#include "declspec.h"
#include "pixelfmt.h"


namespace AntigrainCPP {

    class extended_font_engine : public agg::font_engine_freetype_int32 {
        public:
            bool is_cur_face_bold() const;
            bool is_cur_face_italic() const;
            unsigned get_char_index(unsigned long charcode) const;
    };

    class FontDrawer {

        typedef agg::font_cache_manager<extended_font_engine> font_manager_type;

        public:
            FontDrawer();

            bool load_font(const char* font_name);

            extended_font_engine         m_feng;
            font_manager_type            m_fman;

            // Pipeline to process the vectors glyph paths (curves + contour)
            agg::conv_curve<font_manager_type::path_adaptor_type> m_curves;
            agg::conv_contour<agg::conv_curve<font_manager_type::path_adaptor_type> > m_contour;

    };

    extern "C" DECLSPEC bool FontDrawer_LoadFont(FontDrawer* fe,
        const char* font_name
    );

    extern "C" DECLSPEC bool FontDrawer_IsCurrentFaceBold(FontDrawer* fe);

    extern "C" DECLSPEC bool FontDrawer_IsCurrentFaceItalic(FontDrawer* fe);

    extern "C" DECLSPEC unsigned FontDrawer_GetCharIndex(FontDrawer* fe,
        unsigned long charcode
    );
}
