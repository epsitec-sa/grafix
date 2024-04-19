#include "font_manager.h"


namespace AntigrainCPP {

    FontManager::FontManager() :
        m_feng()
    {}

    bool FontManager::load_font(const char* font_name){
        return m_feng.load_font(font_name, 0, agg::glyph_ren_agg_gray8);
    }

    bool FontManager_LoadFont(FontManager* fm, const char* font_name){
        return fm->load_font(font_name);
    }
}
