/*
This file is part of AggUI.

Copyright © 2003-2024, EPSITEC SA, 1400 Yverdon-les-Bains, Switzerland

AggUI is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
any later version.

AggUI is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

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
