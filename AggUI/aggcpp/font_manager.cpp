#include "font_manager.h"


namespace AntigrainCPP {

    FontManager::FontManager() :
        m_feng(),
        m_fman(m_feng),
        m_curves(m_fman.path_adaptor()),
        m_contour(m_curves)
    {
        m_curves.approximation_scale(2.0);
        m_contour.auto_detect_orientation(false);
    }

    bool FontManager::load_font(const char* font_name){
        return m_feng.load_font(font_name, 0, agg::glyph_ren_agg_gray8);
    }

    bool FontManager_LoadFont(FontManager* fm, const char* font_name){
        return fm->load_font(font_name);
    }
}
