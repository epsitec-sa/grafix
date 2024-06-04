//  AntiGrain.Win32/agg_rasterizer.cpp
//
//  Copyright � 2003-2007, Pierre ARNAUD, OPaC bright ideas, Ch. du Fontenay 6,
//                         CH-1400 YVERDON, Switzerland. All rights reserved. 
//
//  Contact: pierre.arnaud@opac.ch, http://www.opac.ch
//  License: see license.txt

#include <iostream>

#include "rasterizer.h"

/* #include "agg_font_path_provider.h" */
#include "agg_conv_curve.h"
#include "agg_conv_clip_polygon.h"
#include "agg_conv_segmentator.h"

namespace AntigrainCPP {
    /*****************************************************************************/

    Rasterizer* Rasterizer_New()
    {
        Rasterizer* rasterizer = new Rasterizer ();
        rasterizer->has_transform = false;
        rasterizer->has_clip_box  = false;
        return rasterizer;
    }

    void Rasterizer_Delete(Rasterizer* rasterizer)
    {
        delete rasterizer;
    }

    /*****************************************************************************/

    void Rasterizer_Clear(Rasterizer* rasterizer)
    {
        if (rasterizer)
        {
            rasterizer->rasterizer.reset ();
        }
    }

    void Rasterizer_FillingRule(Rasterizer* rasterizer, int rule)
    {
        if ( (rasterizer)
          && (rule) )
        {
            switch (rule)
            {
                case 1:
                    rasterizer->rasterizer.filling_rule (agg::fill_even_odd);
                    break;
                case 2:
                    rasterizer->rasterizer.filling_rule (agg::fill_non_zero);
                    break;
            }
        }
    }

    bool Rasterizer_HitTest(Rasterizer* rasterizer, int x, int y)
    {
        if (rasterizer)
        {
            return rasterizer->rasterizer.hit_test (x, y);
        }
        
        return false;
    }

    void Rasterizer_Gamma(Rasterizer* rasterizer, double gamma)
    {
        if (rasterizer)
        {
            if (gamma == 0.0)
            {
                rasterizer->rasterizer.gamma (agg::gamma_threshold ());
            }
            else
            {
                rasterizer->rasterizer.gamma (agg::gamma_power (gamma));
            }
        }
    }

    void Rasterizer_SetTransform(Rasterizer* rasterizer,
                              double xx, double xy, double yx, double yy, double tx, double ty)
    {
        if (rasterizer)
        {
            if ( (xx == 1) && (xy == 0) && (tx == 0)
              && (yx == 0) && (yy == 1) && (ty == 0) )
            {
                rasterizer->has_transform = false;
            }
            else
            {
                //  Caution: affine matrix sorts its elements in a different way than I do. AGG sorts
                //  them column by column, and I sort them as a 2x2 matrix, line by line, plus the
                //  separate translation vector.
                
                rasterizer->has_transform = true;
                rasterizer->transform_matrix = agg::trans_affine (xx, yx, xy, yy, tx, ty);
            }
        }
    }

    void Rasterizer_SetClipBox(Rasterizer* rasterizer, double x1, double y1, double x2, double y2)
    {
        if (rasterizer)
        {
#if defined(USE_OLD_CLIPPING_CODE)
            rasterizer->has_clip_box = true;
#else
            rasterizer->rasterizer.clip_box (x1, y1, x2, y2);
#endif
            
            rasterizer->x1 = x1;
            rasterizer->y1 = y1;
            rasterizer->x2 = x2;
            rasterizer->y2 = y2;
        }
    }

    void Rasterizer_ResetClipBox(Rasterizer* rasterizer)
    {
        if (rasterizer)
        {
#if defined(USE_OLD_CLIPPING_CODE)
            rasterizer->has_clip_box = false;
#else
            rasterizer->rasterizer.reset_clipping ();
#endif
        }
    }

    /*****************************************************************************/

    void Rasterizer_AddPath(Rasterizer* rasterizer, Path* path, bool curved)
    {
        if ( (rasterizer)
          && (path) )
        {
            if (curved)
            {
                if (rasterizer->has_transform)
                {
                    if (rasterizer->has_clip_box)
                    {
                        agg::conv_transform<agg::path_storage, agg::trans_affine> conv (path->path, rasterizer->transform_matrix);
                        agg::conv_curve<agg::conv_transform<agg::path_storage, agg::trans_affine> > curve (conv);
                        agg::conv_clip_polygon<agg::conv_curve<agg::conv_transform<agg::path_storage, agg::trans_affine> > > clip (curve);
                        
                        curve.approximation_scale (2);
                        
                        double x1 = rasterizer->x1; double y1 = rasterizer->y1;
                        double x2 = rasterizer->x2; double y2 = rasterizer->y2;
                        
                        clip.clip_box (x1, y1, x2, y2);
                        
                        rasterizer->rasterizer.add_path (clip);
                    }
                    else
                    {
                        agg::conv_transform<agg::path_storage, agg::trans_affine> conv (path->path, rasterizer->transform_matrix);
                        agg::conv_curve<agg::conv_transform<agg::path_storage, agg::trans_affine> > curve (conv);
                        
                        curve.approximation_scale (2);
                        
                        rasterizer->rasterizer.add_path (curve);
                    }
                }
                else
                {
                    if (rasterizer->has_clip_box)
                    {
                        agg::conv_curve<agg::path_storage> curve (path->path);
                        agg::conv_clip_polygon<agg::conv_curve<agg::path_storage> > clip (curve);
                        
                        curve.approximation_scale (2);
                        
                        double x1 = rasterizer->x1; double y1 = rasterizer->y1;
                        double x2 = rasterizer->x2; double y2 = rasterizer->y2;
                        
                        clip.clip_box (x1, y1, x2, y2);
                        
                        rasterizer->rasterizer.add_path (clip);
                    }
                    else
                    {
                        agg::conv_curve<agg::path_storage> curve (path->path);
                        
                        curve.approximation_scale (2);
                        
                        rasterizer->rasterizer.add_path (curve);
                    }
                }
            }
            else
            {
                if (rasterizer->has_transform)
                {
                    if (rasterizer->has_clip_box)
                    {
                        agg::conv_transform<agg::path_storage, agg::trans_affine> conv (path->path, rasterizer->transform_matrix);
                        agg::conv_clip_polygon<agg::conv_transform<agg::path_storage, agg::trans_affine> > clip (conv);
                        
                        double x1 = rasterizer->x1; double y1 = rasterizer->y1;
                        double x2 = rasterizer->x2; double y2 = rasterizer->y2;
                        
                        clip.clip_box (x1, y1, x2, y2);
                        
                        rasterizer->rasterizer.add_path (clip);
                    }
                    else
                    {
                        agg::conv_transform<agg::path_storage, agg::trans_affine> conv (path->path, rasterizer->transform_matrix);
                        rasterizer->rasterizer.add_path (conv);
                    }
                }
                else
                {
                    if (rasterizer->has_clip_box)
                    {
                        agg::conv_clip_polygon<agg::path_storage> clip (path->path);
                        
                        double x1 = rasterizer->x1; double y1 = rasterizer->y1;
                        double x2 = rasterizer->x2; double y2 = rasterizer->y2;
                        
                        clip.clip_box (x1, y1, x2, y2);
                        
                        rasterizer->rasterizer.add_path (clip);
                    }
                    else
                    {
                        rasterizer->rasterizer.add_path (path->path);
                    }
                }
            }
        }
    }

    /*****************************************************************************/

    void Rasterizer_AddChar(Rasterizer* rasterizer, char c, double x, double y, FontManager* font_manager) {
        std::cout << "[C++] make path from char" << std::endl;
        if(!font_manager->m_feng.prepare_glyph(c))
        {
            std::cout << "[C++] glyph prepare failed" << std::endl;
            return;
        }
        unsigned currGlyph = font_manager->m_feng.glyph_index();
        std::cout << "[C++] glyph prepare done" << std::endl;

        typedef typename FontManager::path_adaptor_type adaptor_type;
        typedef typename agg::conv_curve<adaptor_type>            conv_font_curve_type;
        typedef typename agg::conv_segmentator<conv_font_curve_type>   conv_font_segm_type;

        agg::int8u* glyph_data = (agg::int8u*)std::malloc(font_manager->m_feng.data_size());
        font_manager->m_feng.write_glyph_to(glyph_data);

        std::cout << "[C++] glyph data write done" << std::endl;

        adaptor_type adaptor;

        conv_font_curve_type fcurves(adaptor);
        conv_font_segm_type  fsegm(fcurves);
        fsegm.approximation_scale(3.0);
        fcurves.approximation_scale(2.0);

        adaptor.init(glyph_data, font_manager->m_feng.data_size(), x, y);

        std::cout << "[C++] adaptor init done" << std::endl;

        rasterizer->rasterizer.add_path(fsegm);
        /* path->path.join_path(fsegm, 0); */

        std::free(glyph_data);
        std::cout << "[C++] make path from char done" << std::endl;
    }
    /*void */
    /*Rasterizer_AddGlyph(Rasterizer* rasterizer, agg::font_face* face, */
    /*                      int glyph, double x, double y, double scale) */
    /*{ */
    /*    if ( (rasterizer) */
    /*      && (face) && (face->UpdateCache ()) */
    /*      && (scale) */
    /*      && (glyph < 0xffff) && (glyph >= 0) ) */
    /*    { */
    /*        face->RetGlyphAdvance (glyph); */
            
    /*        agg::font_face::cache_record::size_info_record* info = face->FindSizeInfo (glyph); */
            
    /*        if ( (info) */
    /*          && (info->num_coord) ) */
    /*        { */
    /*            if (rasterizer->has_transform) */
    /*            { */
    /*                if (rasterizer->has_clip_box) */
    /*                { */
    /*                    agg::font_path_provider font_path = agg::font_path_provider (face, glyph, info, x, y, scale, scale); */
    /*                    agg::conv_transform<agg::font_path_provider, agg::trans_affine> conv (font_path, rasterizer->transform_matrix); */
    /*                    agg::conv_curve<agg::conv_transform<agg::font_path_provider, agg::trans_affine> > curve (conv); */
    /*                    agg::conv_clip_polygon<agg::conv_curve<agg::conv_transform<agg::font_path_provider, agg::trans_affine> > > clip (curve); */
                        
    /*                    curve.approximation_scale (2); */
                        
    /*                    double x1 = rasterizer->x1; double y1 = rasterizer->y1; */
    /*                    double x2 = rasterizer->x2; double y2 = rasterizer->y2; */
                        
    /*                    clip.clip_box (x1, y1, x2, y2); */
                        
    /*                    rasterizer->rasterizer.add_path (clip); */
    /*                } */
    /*                else */
    /*                { */
    /*                    agg::font_path_provider font_path = agg::font_path_provider (face, glyph, info, x, y, scale, scale); */
    /*                    agg::conv_transform<agg::font_path_provider, agg::trans_affine> conv (font_path, rasterizer->transform_matrix); */
    /*                    agg::conv_curve<agg::conv_transform<agg::font_path_provider, agg::trans_affine> > curve (conv); */
                        
    /*                    curve.approximation_scale (2); */
                        
    /*                    rasterizer->rasterizer.add_path (curve); */
    /*                } */
    /*            } */
    /*            else */
    /*            { */
    /*                if (rasterizer->has_clip_box) */
    /*                { */
    /*                    agg::font_path_provider font_path = agg::font_path_provider (face, glyph, info, x, y, scale, scale); */
    /*                    agg::conv_curve<agg::font_path_provider> curve (font_path); */
    /*                    agg::conv_clip_polygon<agg::conv_curve<agg::font_path_provider> > clip (curve); */
                        
    /*                    curve.approximation_scale (2); */
                        
    /*                    double x1 = rasterizer->x1; double y1 = rasterizer->y1; */
    /*                    double x2 = rasterizer->x2; double y2 = rasterizer->y2; */
                        
    /*                    clip.clip_box (x1, y1, x2, y2); */
                        
    /*                    rasterizer->rasterizer.add_path (clip); */
    /*                } */
    /*                else */
    /*                { */
    /*                    agg::font_path_provider font_path = agg::font_path_provider (face, glyph, info, x, y, scale, scale); */
    /*                    agg::conv_curve<agg::font_path_provider> curve (font_path); */
                        
    /*                    curve.approximation_scale (2); */
                        
    /*                    rasterizer->rasterizer.add_path (curve); */
    /*                } */
    /*            } */
    /*        } */
    /*    } */
    /*} */

    /*****************************************************************************/

    /* void */
    /* Rasterizer_AddGlyphXY(Rasterizer* rasterizer, */
    /*     agg::font_face* face, */
    /*     int glyph, */
    /*     double x, double y, */
    /*     double scale_x, double scale_y */
    /* ){ */
    /*     if (!(    rasterizer */
    /*            && face */
    /*            && face->UpdateCache () */
    /*            && scale_x */
    /*            && scale_y */
    /*            && glyph < 0xffff */ 
    /*            && glyph >= 0 */
    /*         ) */
    /*     ){ */
    /*         return; */
    /*     } */
    /*     face->RetGlyphAdvance(glyph); */
        
    /*     agg::font_face::cache_record::size_info_record* info = face->FindSizeInfo(glyph); */
        
    /*     if(!( info && info->num_coord )) */
    /*     { */
    /*         return; */
    /*     } */
    /*     agg::font_path_provider font_path = agg::font_path_provider( */
    /*         face, */
    /*         glyph, */
    /*         info, */
    /*         x, */
    /*         y, */
    /*         scale_x, */
    /*         scale_y */
    /*     ); */
    /*     if(rasterizer->has_transform) */
    /*     { */
    /*         agg::conv_transform<agg::font_path_provider, agg::trans_affine> conv( */
    /*             font_path, */
    /*             rasterizer->transform_matrix */
    /*         ); */
    /*         agg::conv_curve<agg::conv_transform<agg::font_path_provider, agg::trans_affine>> curve(conv); */
    /*         if(rasterizer->has_clip_box) */
    /*         { */
    /*             agg::conv_clip_polygon<agg::conv_curve<agg::conv_transform<agg::font_path_provider, agg::trans_affine>>> clip(curve); */
                
    /*             curve.approximation_scale(2); */
                
    /*             double x1 = rasterizer->x1; double y1 = rasterizer->y1; */
    /*             double x2 = rasterizer->x2; double y2 = rasterizer->y2; */
                
    /*             clip.clip_box(x1, y1, x2, y2); */
                
    /*             rasterizer->rasterizer.add_path(clip); */
    /*         } */
    /*         else */
    /*         { */
    /*             curve.approximation_scale(2); */
    /*             rasterizer->rasterizer.add_path(curve); */
    /*         } */
    /*     } */
    /*     else */
    /*     { */
    /*         agg::conv_curve<agg::font_path_provider> curve(font_path); */
    /*         if(rasterizer->has_clip_box) */
    /*         { */
    /*             agg::conv_clip_polygon<agg::conv_curve<agg::font_path_provider>> clip(curve); */
                
    /*             curve.approximation_scale(2); */
                
    /*             double x1 = rasterizer->x1; double y1 = rasterizer->y1; */
    /*             double x2 = rasterizer->x2; double y2 = rasterizer->y2; */
                
    /*             clip.clip_box(x1, y1, x2, y2); */
    /*             rasterizer->rasterizer.add_path(clip); */
    /*         } */
    /*         else */
    /*         { */
    /*             curve.approximation_scale(2); */
    /*             rasterizer->rasterizer.add_path(curve); */
    /*         } */
    /*     } */
    /* } */

    /*****************************************************************************/

#if 0
    double
    Rasterizer_AddText(Rasterizer* rasterizer, agg::font_face* face,
                         const wchar_t* text, int mode,
                         double xx, double xy, double yx, double yy, double tx, double ty)
    {
        double width = 0;
        
        if ( (rasterizer)
          && (face) && (face->UpdateCache ())
          && (text) )
        {
            double scale = 1.0;
            
            while (*text)
            {
                agg::trans_affine matrix = agg::trans_affine (xx, yx, xy, yy, tx, ty);
                
                if (rasterizer->has_transform)
                {
                    matrix *= rasterizer->transform_matrix;
                }
                
                agg::int32u unicode = *text++;
                agg::int16u glyph   = face->RetGlyphIndex (unicode);
                double advance = face->RetGlyphAdvance (glyph) * xx;
                
                width += advance;
                tx += advance;
                
                agg::font_face::cache_record::size_info_record* info = face->FindSizeInfo (glyph);
                
                if ( (info)
                  && (info->num_coord) )
                {
                    if (rasterizer->has_clip_box)
                    {
                        agg::font_path_provider font_path = agg::font_path_provider (face, glyph, info, 0, 0, scale, scale);
                        agg::conv_transform<agg::font_path_provider, agg::trans_affine> conv (font_path, matrix);
                        agg::conv_curve<agg::conv_transform<agg::font_path_provider, agg::trans_affine> > curve (conv);
                        agg::conv_clip_polygon<agg::conv_curve<agg::conv_transform<agg::font_path_provider, agg::trans_affine> > > clip (curve);
                        
                        curve.approximation_scale (2);
                        
                        double x1 = rasterizer->x1; double y1 = rasterizer->y1;
                        double x2 = rasterizer->x2; double y2 = rasterizer->y2;
                        
                        clip.clip_box (x1, y1, x2, y2);
                        
                        rasterizer->rasterizer.add_path (clip);
                    }
                    else
                    {
                        agg::font_path_provider font_path = agg::font_path_provider (face, glyph, info, 0, 0, scale, scale);
                        agg::conv_transform<agg::font_path_provider, agg::trans_affine> conv (font_path, matrix);
                        agg::conv_curve<agg::conv_transform<agg::font_path_provider, agg::trans_affine> > curve (conv);
                        
                        curve.approximation_scale (2);
                        
                        rasterizer->rasterizer.add_path (curve);
                    }
                }
            }
        }
        
        return width;
    }
#endif

    /*****************************************************************************/

    void Rasterizer_AddPathStroke1(Rasterizer* rasterizer,
                                Path* path, double width, bool curved)
    {
        if ( (rasterizer)
          && (path) )
        {
            if (curved)
            {
                if (rasterizer->has_transform)
                {
                    if (rasterizer->has_clip_box)
                    {
                        agg::conv_curve<agg::path_storage> curve (path->path);
                        agg::conv_stroke<agg::conv_curve<agg::path_storage> > stroke (curve);
                        
                        double s = rasterizer->transform_matrix.scale () * 2;
                        curve.approximation_scale (s);
                        stroke.approximation_scale (s);
                        stroke.width (width);
                        
                        agg::conv_transform<agg::conv_stroke<agg::conv_curve<agg::path_storage> >, agg::trans_affine> conv (stroke, rasterizer->transform_matrix);
                        agg::conv_clip_polygon<agg::conv_transform<agg::conv_stroke<agg::conv_curve<agg::path_storage> >, agg::trans_affine> > clip (conv);
                        
                        double x1 = rasterizer->x1; double y1 = rasterizer->y1;
                        double x2 = rasterizer->x2; double y2 = rasterizer->y2;
                        
                        clip.clip_box (x1, y1, x2, y2);
                        
                        rasterizer->rasterizer.add_path (clip);
                    }
                    else
                    {
                        agg::conv_curve<agg::path_storage> curve (path->path);
                        agg::conv_stroke<agg::conv_curve<agg::path_storage> > stroke (curve);
                        
                        double s = rasterizer->transform_matrix.scale () * 2;
                        curve.approximation_scale (s);
                        stroke.approximation_scale (s);
                        stroke.width (width);
                        
                        agg::conv_transform<agg::conv_stroke<agg::conv_curve<agg::path_storage> >, agg::trans_affine> conv (stroke, rasterizer->transform_matrix);
                        
                        rasterizer->rasterizer.add_path (conv);
                    }
                }
                else
                {
                    if (rasterizer->has_clip_box)
                    {
                        agg::conv_curve<agg::path_storage> curve (path->path);
                        agg::conv_stroke<agg::conv_curve<agg::path_storage> > stroke (curve);
                        
                        curve.approximation_scale (2);
                        
                        stroke.width (width);
                        
                        agg::conv_clip_polygon<agg::conv_stroke<agg::conv_curve<agg::path_storage> > > clip (stroke);
                        
                        double x1 = rasterizer->x1; double y1 = rasterizer->y1;
                        double x2 = rasterizer->x2; double y2 = rasterizer->y2;
                        
                        clip.clip_box (x1, y1, x2, y2);
                        
                        rasterizer->rasterizer.add_path (clip);
                    }
                    else
                    {
                        agg::conv_curve<agg::path_storage> curve (path->path);
                        agg::conv_stroke<agg::conv_curve<agg::path_storage> > stroke (curve);
                        
                        curve.approximation_scale (2);
                        
                        stroke.width (width);
                        
                        rasterizer->rasterizer.add_path (stroke);
                    }
                }
            }
            else
            {
                if (rasterizer->has_transform)
                {
                    if (rasterizer->has_clip_box)
                    {
                        agg::conv_stroke<agg::path_storage> stroke (path->path);
                        
                        double s = rasterizer->transform_matrix.scale ();
                        stroke.approximation_scale (s);
                        stroke.width (width);
                        
                        agg::conv_transform<agg::conv_stroke<agg::path_storage>, agg::trans_affine> conv (stroke, rasterizer->transform_matrix);
                        agg::conv_clip_polygon<agg::conv_transform<agg::conv_stroke<agg::path_storage>, agg::trans_affine> > clip (conv);
                        
                        double x1 = rasterizer->x1; double y1 = rasterizer->y1;
                        double x2 = rasterizer->x2; double y2 = rasterizer->y2;
                        
                        clip.clip_box (x1, y1, x2, y2);
                        
                        rasterizer->rasterizer.add_path (clip);
                    }
                    else
                    {
                        agg::conv_stroke<agg::path_storage> stroke (path->path);
                        
                        double s = rasterizer->transform_matrix.scale ();
                        stroke.approximation_scale (s);
                        stroke.width (width);
                        
                        agg::conv_transform<agg::conv_stroke<agg::path_storage>, agg::trans_affine> conv (stroke, rasterizer->transform_matrix);
                        rasterizer->rasterizer.add_path (conv);
                    }
                }
                else
                {
                    if (rasterizer->has_clip_box)
                    {
                        agg::conv_stroke<agg::path_storage> stroke (path->path);
                        
                        stroke.width (width);
                        
                        agg::conv_clip_polygon<agg::conv_stroke<agg::path_storage> > clip (stroke);
                        
                        double x1 = rasterizer->x1; double y1 = rasterizer->y1;
                        double x2 = rasterizer->x2; double y2 = rasterizer->y2;
                        
                        clip.clip_box (x1, y1, x2, y2);
                        
                        rasterizer->rasterizer.add_path (clip);
                    }
                    else
                    {
                        agg::conv_stroke<agg::path_storage> stroke (path->path);
                        
                        stroke.width (width);
                        
                        rasterizer->rasterizer.add_path (stroke);
                    }
                }
            }
        }
    }

    /*****************************************************************************/

    void Rasterizer_AddPathStroke2(Rasterizer* rasterizer,
                                Path* path, double width, int cap, int join,
                                double miter_limit, bool curved)
    {
        if (miter_limit < 0)
        {
            miter_limit = - miter_limit;
        }
        
        if ( (rasterizer)
          && (path) )
        {
            if (curved)
            {
                if (rasterizer->has_transform)
                {
                    if (rasterizer->has_clip_box)
                    {
                        agg::conv_curve<agg::path_storage> curve (path->path);
                        agg::conv_stroke<agg::conv_curve<agg::path_storage> > stroke (curve);
                        
                        double s = 2 * rasterizer->transform_matrix.scale ();
                        curve.approximation_scale (s);
                        stroke.approximation_scale (s);
                        stroke.width (width);
                        stroke.line_cap ((agg::line_cap_e) cap);
                        stroke.line_join ((agg::line_join_e) join);
                        stroke.miter_limit (miter_limit);
                        
                        agg::conv_transform<agg::conv_stroke<agg::conv_curve<agg::path_storage> >, agg::trans_affine> conv (stroke, rasterizer->transform_matrix);
                        agg::conv_clip_polygon<agg::conv_transform<agg::conv_stroke<agg::conv_curve<agg::path_storage> >, agg::trans_affine> > clip (conv);
                        
                        double x1 = rasterizer->x1; double y1 = rasterizer->y1;
                        double x2 = rasterizer->x2; double y2 = rasterizer->y2;
                        
                        clip.clip_box (x1, y1, x2, y2);
                        
                        rasterizer->rasterizer.add_path (clip);
                    }
                    else
                    {
                        agg::conv_curve<agg::path_storage> curve (path->path);
                        agg::conv_stroke<agg::conv_curve<agg::path_storage> > stroke (curve);
                        
                        double s = 2 * rasterizer->transform_matrix.scale ();
                        curve.approximation_scale (s);
                        stroke.approximation_scale (s);
                        stroke.width (width);
                        stroke.line_cap ((agg::line_cap_e) cap);
                        stroke.line_join ((agg::line_join_e) join);
                        stroke.miter_limit (miter_limit);
                        
                        agg::conv_transform<agg::conv_stroke<agg::conv_curve<agg::path_storage> >, agg::trans_affine> conv (stroke, rasterizer->transform_matrix);
                        
                        rasterizer->rasterizer.add_path (conv);
                    }
                }
                else
                {
                    if (rasterizer->has_clip_box)
                    {
                        agg::conv_curve<agg::path_storage> curve (path->path);
                        agg::conv_stroke<agg::conv_curve<agg::path_storage> > stroke (curve);
                        
                        curve.approximation_scale (2);
                        
                        stroke.approximation_scale (2);
                        stroke.width (width);
                        stroke.line_cap ((agg::line_cap_e) cap);
                        stroke.line_join ((agg::line_join_e) join);
                        stroke.miter_limit (miter_limit);
                        
                        agg::conv_clip_polygon<agg::conv_stroke<agg::conv_curve<agg::path_storage> > > clip (stroke);
                        
                        double x1 = rasterizer->x1; double y1 = rasterizer->y1;
                        double x2 = rasterizer->x2; double y2 = rasterizer->y2;
                        
                        clip.clip_box (x1, y1, x2, y2);
                        
                        rasterizer->rasterizer.add_path (clip);
                    }
                    else
                    {
                        agg::conv_curve<agg::path_storage> curve (path->path);
                        agg::conv_stroke<agg::conv_curve<agg::path_storage> > stroke (curve);
                        
                        curve.approximation_scale (2);
                        
                        stroke.approximation_scale (2);
                        stroke.width (width);
                        stroke.line_cap ((agg::line_cap_e) cap);
                        stroke.line_join ((agg::line_join_e) join);
                        stroke.miter_limit (miter_limit);
                        
                        rasterizer->rasterizer.add_path (stroke);
                    }
                }
            }
            else
            {
                if (rasterizer->has_transform)
                {
                    if (rasterizer->has_clip_box)
                    {
                        agg::conv_stroke<agg::path_storage> stroke (path->path);
                        
                        double s = 2 * rasterizer->transform_matrix.scale ();
                        stroke.approximation_scale (s);
                        stroke.width (width);
                        stroke.line_cap ((agg::line_cap_e) cap);
                        stroke.line_join ((agg::line_join_e) join);
                        stroke.miter_limit (miter_limit);
                        
                        agg::conv_transform<agg::conv_stroke<agg::path_storage>, agg::trans_affine> conv (stroke, rasterizer->transform_matrix);
                        agg::conv_clip_polygon<agg::conv_transform<agg::conv_stroke<agg::path_storage>, agg::trans_affine> > clip (conv);
                        
                        double x1 = rasterizer->x1; double y1 = rasterizer->y1;
                        double x2 = rasterizer->x2; double y2 = rasterizer->y2;
                        
                        clip.clip_box (x1, y1, x2, y2);
                        
                        rasterizer->rasterizer.add_path (clip);
                    }
                    else
                    {
                        agg::conv_stroke<agg::path_storage> stroke (path->path);
                        
                        double s = 2 * rasterizer->transform_matrix.scale ();
                        stroke.approximation_scale (s);
                        stroke.width (width);
                        stroke.line_cap ((agg::line_cap_e) cap);
                        stroke.line_join ((agg::line_join_e) join);
                        stroke.miter_limit (miter_limit);
                        
                        agg::conv_transform<agg::conv_stroke<agg::path_storage>, agg::trans_affine> conv (stroke, rasterizer->transform_matrix);
                        
                        rasterizer->rasterizer.add_path (conv);
                    }
                }
                else
                {
                    if (rasterizer->has_clip_box)
                    {
                        agg::conv_stroke<agg::path_storage> stroke (path->path);
                        
                        stroke.approximation_scale (2);
                        stroke.width (width);
                        stroke.line_cap ((agg::line_cap_e) cap);
                        stroke.line_join ((agg::line_join_e) join);
                        stroke.miter_limit (miter_limit);
                        
                        agg::conv_clip_polygon<agg::conv_stroke<agg::path_storage> > clip (stroke);
                        
                        double x1 = rasterizer->x1; double y1 = rasterizer->y1;
                        double x2 = rasterizer->x2; double y2 = rasterizer->y2;
                        
                        clip.clip_box (x1, y1, x2, y2);
                        
                        rasterizer->rasterizer.add_path (clip);
                    }
                    else
                    {
                        agg::conv_stroke<agg::path_storage> stroke (path->path);
                        
                        stroke.approximation_scale (2);
                        stroke.width (width);
                        stroke.line_cap ((agg::line_cap_e) cap);
                        stroke.line_join ((agg::line_join_e) join);
                        stroke.miter_limit (miter_limit);
                        
                        rasterizer->rasterizer.add_path (stroke);
                    }
                }
            }
        }
    }

    /*****************************************************************************/

    void
    Rasterizer_RenderSolid(Rasterizer* rasterizer, RendererSolid* renderer)
    {
        if ( (rasterizer)
          && (renderer) )
        {
            switch (renderer->active_mask_component)
            {
                case 0:
                    agg::render_scanlines (rasterizer->rasterizer, renderer->sl_a, renderer->ren_solid);
                    break;
                    
                case 1:
                    agg::render_scanlines (rasterizer->rasterizer, renderer->sl_r, renderer->ren_solid);
                    break;
                
                case 2:
                    agg::render_scanlines (rasterizer->rasterizer, renderer->sl_g, renderer->ren_solid);
                    break;
                
                case 3:
                    agg::render_scanlines (rasterizer->rasterizer, renderer->sl_b, renderer->ren_solid);
                    break;
                
                default:
                    agg::render_scanlines (rasterizer->rasterizer, renderer->scanline, renderer->ren_solid);
                    break;
            }
        }
    }

    void
    Rasterizer_RenderImage(Rasterizer* rasterizer, RendererImage* renderer)
    {
        if ( (rasterizer)
          && (renderer)
          && (renderer->Validate ()) )
        {
            /*
            std::cout << "RenderImage"
                      << " use_nn " << renderer->use_nn 
                      << " mode " << renderer->mode
                      << std::endl;
                      */
            switch (renderer->active_mask_component)
            {
                case 0:
                    if (renderer->use_nn)
                    {
                        agg::render_scanlines_aa (rasterizer->rasterizer, renderer->sl_a, renderer->ren_base, renderer->span_alloc, renderer->span_gen_nn);
                    }
                    else if (renderer->mode == 1)
                    {
                        agg::render_scanlines_aa (rasterizer->rasterizer, renderer->sl_a, renderer->ren_base, renderer->span_alloc, renderer->span_gen);
                    }
                    else if (renderer->mode > 1)
                    {
                        agg::render_scanlines_aa (rasterizer->rasterizer, renderer->sl_a, renderer->ren_base, renderer->span_alloc, renderer->span_gen_general);
                    }
                    else
                    {
                        agg::render_scanlines_aa (rasterizer->rasterizer, renderer->sl_a, renderer->ren_base, renderer->span_alloc, renderer->span_gen_resample);
                    }
                    break;
                
                case 1:
                    if (renderer->use_nn)
                    {
                        agg::render_scanlines_aa (rasterizer->rasterizer, renderer->sl_r, renderer->ren_base, renderer->span_alloc, renderer->span_gen_nn);
                    }
                    else if (renderer->mode == 1)
                    {
                        agg::render_scanlines_aa (rasterizer->rasterizer, renderer->sl_r, renderer->ren_base, renderer->span_alloc, renderer->span_gen);
                    }
                    else if (renderer->mode > 1)
                    {
                        agg::render_scanlines_aa (rasterizer->rasterizer, renderer->sl_r, renderer->ren_base, renderer->span_alloc, renderer->span_gen_general);
                    }
                    else
                    {
                        agg::render_scanlines_aa (rasterizer->rasterizer, renderer->sl_r, renderer->ren_base, renderer->span_alloc, renderer->span_gen_resample);
                    }
                    break;
                
                case 2:
                    if (renderer->use_nn)
                    {
                        agg::render_scanlines_aa (rasterizer->rasterizer, renderer->sl_g, renderer->ren_base, renderer->span_alloc, renderer->span_gen_nn);
                    }
                    else if (renderer->mode == 1)
                    {
                        agg::render_scanlines_aa (rasterizer->rasterizer, renderer->sl_g, renderer->ren_base, renderer->span_alloc, renderer->span_gen);
                    }
                    else if (renderer->mode > 1)
                    {
                        agg::render_scanlines_aa (rasterizer->rasterizer, renderer->sl_g, renderer->ren_base, renderer->span_alloc, renderer->span_gen_resample);
                    }
                    else
                    {
                        agg::render_scanlines_aa (rasterizer->rasterizer, renderer->sl_g, renderer->ren_base, renderer->span_alloc, renderer->span_gen_general);
                    }
                    break;
                
                case 3:
                    if (renderer->use_nn)
                    {
                        agg::render_scanlines_aa (rasterizer->rasterizer, renderer->sl_b, renderer->ren_base, renderer->span_alloc, renderer->span_gen_nn);
                    }
                    else if (renderer->mode == 1)
                    {
                        agg::render_scanlines_aa (rasterizer->rasterizer, renderer->sl_b, renderer->ren_base, renderer->span_alloc, renderer->span_gen);
                    }
                    else if (renderer->mode > 1)
                    {
                        agg::render_scanlines_aa (rasterizer->rasterizer, renderer->sl_b, renderer->ren_base, renderer->span_alloc, renderer->span_gen_general);
                    }
                    else
                    {
                        agg::render_scanlines_aa (rasterizer->rasterizer, renderer->sl_b, renderer->ren_base, renderer->span_alloc, renderer->span_gen_resample);
                    }
                    break;
                
                default:
                    if (renderer->use_nn)
                    {
                        agg::render_scanlines_aa (rasterizer->rasterizer, renderer->scanline, renderer->ren_base, renderer->span_alloc, renderer->span_gen_nn);
                    }
                    else if (renderer->mode == 1)
                    {
                        agg::render_scanlines_aa (rasterizer->rasterizer, renderer->scanline, renderer->ren_base, renderer->span_alloc, renderer->span_gen);
                    }
                    else if (renderer->mode > 1)
                    {
                        agg::render_scanlines_aa (rasterizer->rasterizer, renderer->scanline, renderer->ren_base, renderer->span_alloc, renderer->span_gen_general);
                    }
                    else
                    {
                        agg::render_scanlines_aa (rasterizer->rasterizer, renderer->scanline, renderer->ren_base, renderer->span_alloc, renderer->span_gen_resample);
                    }
                    break;
                
            }
        }
    }

    void
    Rasterizer_RenderGradient(Rasterizer* rasterizer, RendererGradient* renderer)
    {
        if ( (rasterizer)
          && (renderer)
          && (renderer->Validate ()) )
        {
            switch (renderer->active_mask_component)
            {
                case 0:  agg::render_scanlines (rasterizer->rasterizer, renderer->sl_a, renderer->ren_gradient); break;
                case 1:  agg::render_scanlines (rasterizer->rasterizer, renderer->sl_r, renderer->ren_gradient); break;
                case 2:  agg::render_scanlines (rasterizer->rasterizer, renderer->sl_g, renderer->ren_gradient); break;
                case 3:  agg::render_scanlines (rasterizer->rasterizer, renderer->sl_b, renderer->ren_gradient); break;
                default: agg::render_scanlines (rasterizer->rasterizer, renderer->scanline, renderer->ren_gradient); break;
            }
        }
    }

    /*****************************************************************************/
}
