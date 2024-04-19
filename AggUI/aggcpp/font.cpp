#include <ft2build.h>
#include "font.h"
#include "freetype_utils.h"


namespace AntigrainCPP {

    FT_Library FreetypeInfo_CreateLibrary(){
        FT_Library library;
        FT_Init_FreeType(&library);
        return library;
    }

    FT_Face FreetypeInfo_LoadFromFile(FT_Library library,
        const char* font_name
    ){
        FT_Face face;
        FT_New_Face(library, font_name, 0, &face); 
        return face;
    }

    bool FreetypeInfo_IsFaceBold(FT_Face face){
        return face->style_flags & FT_STYLE_FLAG_BOLD;
    }

    bool FreetypeInfo_IsFaceItalic(FT_Face face){
        return face->style_flags & FT_STYLE_FLAG_ITALIC;
    }

    unsigned FreetypeInfo_GetCharIndex(FT_Face face,
        unsigned long charcode
    ){
        return FT_Get_Char_Index(face, charcode);
    }

    double FreetypeInfo_GetGlyphAdvance(FT_Face face, unsigned glyph_index, double size){
        FT_F26Dot6 height = doubleToF26Dot6(size);
        int err = FT_Set_Char_Size(face, 0, height, 0, 0);
        err = FT_Load_Glyph(face, glyph_index, FT_LOAD_NO_BITMAP);
        return F26Dot6ToDouble(face->glyph->metrics.horiAdvance);
    }

}
