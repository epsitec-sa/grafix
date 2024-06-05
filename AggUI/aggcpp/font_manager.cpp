#include "font_manager.h"


namespace AntigrainCPP {

  FontManager::FontManager() :
        m_feng(),
        m_outline_mode(false)
    {}


    bool FontManager::load_font(const char* font_name){
        m_current_font_name = font_name;
        if (m_outline_mode) {
            return m_feng.load_font(font_name, 0, agg::glyph_ren_outline);
        } else {
            return m_feng.load_font(font_name, 0, agg::glyph_ren_agg_gray8);
        }
    }

    void FontManager::use_outline_mode(bool mode) {
        if (m_outline_mode != mode) {
             m_outline_mode = mode;
             if (m_current_font_name.length() > 0) {
                 this->load_font(m_current_font_name.c_str());
             }
        }
    }

    void FontManager::set_font_size(double size){
        m_feng.width(size);
        m_feng.height(size);
    }

    FontManager* FontManager_New(){
        return new FontManager();
    }

    void FontManager_Delete(FontManager* fm){
        delete fm;
    }

    bool FontManager_LoadFont(FontManager* fm, const char* font_name){
        return fm->load_font(font_name);
    }

    void FontManager_SetFontSize(FontManager* fm,
        double size
    ){
        fm->set_font_size(size);
    }
}
