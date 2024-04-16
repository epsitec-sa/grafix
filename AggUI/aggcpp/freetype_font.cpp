#include "freetype_font.h"


namespace AntigrainCPP {

    FontEngine::FontEngine() :
        m_feng(),
        m_fman(m_feng),
        m_curves(m_fman.path_adaptor()),
        m_contour(m_curves)
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

    bool FontEngine_IsCurrentFaceBold(FontEngine* fe){
        return fe->m_feng.is_cur_face_bold();
    }

    bool FontEngine_IsCurrentFaceItalic(FontEngine* fe){
        return fe->m_feng.is_cur_face_italic();
    }

    unsigned FontEngine_GetCharIndex(FontEngine* fe,
        unsigned long charcode
    ){
        return fe->m_feng.get_char_index(charcode);
    }

    bool extended_font_engine::is_cur_face_bold() const
    {
        if(m_cur_face)
        {
            return m_cur_face->style_flags & FT_STYLE_FLAG_BOLD;
        }
        return false;
    }

    bool extended_font_engine::is_cur_face_italic() const
    {
        if(m_cur_face)
        {
            return m_cur_face->style_flags & FT_STYLE_FLAG_ITALIC;
        }
        return false;
    }

    unsigned extended_font_engine::get_char_index(unsigned long charcode) const
    {
        if(m_cur_face)
        {
            return FT_Get_Char_Index(m_cur_face, charcode);
        }
        return 0;
    }
}
