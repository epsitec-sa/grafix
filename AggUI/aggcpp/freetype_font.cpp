#include "freetype_font.h"


namespace AntigrainCPP {

    FontEngine::FontEngine() :
        m_feng(),
        m_fman(m_feng),
        m_curves(m_fman.path_adaptor()),
        m_contour(m_curves)
        /* ren_base(pixf), */
        /* ren_solid(ren_base), */
        /* ren_bin(ren_base) */
    {
        m_curves.approximation_scale(2.0);
        m_contour.auto_detect_orientation(false);
    }

    bool FontEngine::load_font(const char* font_name){
        return m_feng.load_font(font_name, 0, agg::glyph_ren_agg_gray8);
    }

    bool FontEngine_LoadFont(FontEngine* fe, const char* font_name){
        return fe->load_font(font_name);
    }

}
