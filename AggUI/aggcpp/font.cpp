#include <ft2build.h>
#include <freetype/ftglyph.h>

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
        SetFaceSize(face, 1.0);
        return face;
    }

    void FreetypeInfo_DoneFace(FT_Face face){
        FT_Done_Face(face);
    }

    bool FreetypeInfo_IsFaceBold(FT_Face face){
        return face->style_flags & FT_STYLE_FLAG_BOLD;
    }

    bool FreetypeInfo_IsFaceItalic(FT_Face face){
        return face->style_flags & FT_STYLE_FLAG_ITALIC;
    }

    unsigned FreetypeInfo_GetUnitsPerEm(FT_Face face){
        return (unsigned)face->units_per_EM;
    }

    unsigned FreetypeInfo_GetCharIndex(FT_Face face,
        unsigned long charcode
    ){
        return FT_Get_Char_Index(face, charcode);
    }

    double FreetypeInfo_GetGlyphAdvance(FT_Face face, unsigned glyph_index, double size){
        LoadGlyph(face, glyph_index, size);
        return F26Dot6ToDouble(face->glyph->metrics.horiAdvance);
    }

    double FreetypeInfo_GetKerning(FT_Face face, 
        unsigned left_glyph,
        unsigned right_glyph,
        double size
    ){
        SetFaceSize(face, size);
        FT_Vector kerning;
        FT_Get_Kerning(face, left_glyph, right_glyph, FT_KERNING_DEFAULT, &kerning);
        return F26Dot6ToDouble(kerning.x);
    }

    void LoadGlyph(FT_Face face, unsigned glyph_index, double size){
        SetFaceSize(face, size);
        FT_Load_Glyph(face, glyph_index, FT_LOAD_NO_BITMAP);
    }

    void SetFaceSize(FT_Face face, double size){
        FT_F26Dot6 height = doubleToF26Dot6(size);
        FT_Set_Char_Size(face, 0, height, 0, 0);
    }

    void FreetypeInfo_GetGlyphBBox(FT_Face face,
        unsigned glyph_index,
        double size,
        double &xMin,
        double &xMax,
        double &yMin,
        double &yMax
    ){
        LoadGlyph(face, glyph_index, size);
        FT_BBox bbox;
        FT_Glyph glyph;
        FT_Get_Glyph(face->glyph, &glyph);
        FT_Glyph_Get_CBox(glyph, FT_GLYPH_BBOX_GRIDFIT, &bbox);
        FT_Done_Glyph(glyph);
        xMin = F26Dot6ToDouble(bbox.xMin);
        xMax = F26Dot6ToDouble(bbox.xMax);
        yMin = F26Dot6ToDouble(bbox.yMin);
        yMax = F26Dot6ToDouble(bbox.yMax);
    }

    double FreetypeInfo_GetAscender(FT_Face face, double size)
    {
        SetFaceSize(face, size);
        return F26Dot6ToDouble(face->size->metrics.ascender);
    }

    double FreetypeInfo_GetDescender(FT_Face face, double size)
    {
        SetFaceSize(face, size);
        return F26Dot6ToDouble(face->size->metrics.descender);
    }

    double FreetypeInfo_GetHeight(FT_Face face, double size)
    {
        SetFaceSize(face, size);
        return F26Dot6ToDouble(face->size->metrics.height);
    }
}
