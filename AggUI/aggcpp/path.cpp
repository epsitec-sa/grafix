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

#include "path.h"


/*****************************************************************************/

Path* Path_New(){
    Path* path = new Path();
    return path;
}

void Path_Delete(Path* path){
    delete path;
}

/*****************************************************************************/

void Path_MoveTo(Path* path,
    double x, double y
){
    if (path)
    {
        path->path.move_to (x, y);
    }
}

void Path_LineTo(Path* path,
    double x, double y
){
    if (path)
    {
        path->path.line_to (x, y);
    }
}

void Path_Curve3(Path* path,
    double x_c, double y_c,
    double x, double y
){
    if (path)
    {
        path->path.curve3 (x_c, y_c, x, y);
    }
}

void Path_Curve4(Path* path,
    double x_c1, double y_c1,
    double x_c2, double y_c2,
    double x, double y
){
    if (path)
    {
        path->path.curve4 (x_c1, y_c1, x_c2, y_c2, x, y);
    }
}

void Path_Close(Path* path){
    if (path)
    {
        path->path.end_poly (agg::path_flags_close);
    }
}

void Path_AddNewPath(Path* path){
    if (path)
    {
        path->path.start_new_path ();
    }
}

void Path_RemoveAll(Path* path){
    if (path)
    {
        path->path.remove_all ();
    }
}

/*****************************************************************************/

int Path_ElemCount(Path* path){
    if (path)
    {
        path->path.rewind (0);
        
        int n = 0;
        unsigned cmd;
        double x, y;
        
        cmd = path->path.vertex(&x, &y);
        
        while(!agg::is_stop (cmd))
        {
            n++;
            cmd = path->path.vertex(&x, &y);
        }
        
        return n+1;
    }
    
    return 0;
}

void Path_ElemGet(Path* path,
    int max,
    int* types,
    double* x, double* y
){
    if ( (path)
      && (max > 0) )
    {
        path->path.rewind (0);
        
        int n = 0;
        unsigned cmd;
        
        cmd = path->path.vertex(x, y);
        
        while (--max && !agg::is_stop (cmd))
        {
            *types++ = cmd; x++; y++;
            n++;
            cmd = path->path.vertex(x, y);
        }
        
        *types = cmd;
    }
}

/*****************************************************************************/

/* void Path_AppendGlyph(Path* path, */
/*     agg::font_face* face, */
/*     int glyph, */
/*     double xx, double xy, */
/*     double yx, double yy, */
/*     double tx, double ty, */
/*     double bold */
/* ){ */
/*     if (path && path && face->UpdateCache () && (glyph >= 0) && (glyph < 0xff00)) */
/*     { */
/*         agg::font_face::cache_record::size_info_record* info = face->FindSizeInfo (glyph); */
        
/*         if ( (info) */
/*           && (info->num_coord) ) */
/*         { */
/*             agg::trans_affine matrix = agg::trans_affine (xx, yx, xy, yy, tx, ty); */
            
/*             if (bold) */
/*             { */
/*                 agg::font_path_provider font_path = agg::font_path_provider (face, glyph, info, 0, 0, 1, 1); */
/*                 agg::conv_transform<agg::font_path_provider, agg::trans_affine> conv (font_path, matrix); */
/*                 agg::conv_curve<agg::conv_transform<agg::font_path_provider, agg::trans_affine> > curve (conv); */
/*                 agg::conv_contour<agg::conv_curve<agg::conv_transform<agg::font_path_provider, agg::trans_affine> > > contour (curve); */
                
/*                 curve.approximation_scale (2); */
                
/*                 contour.auto_detect_orientation (false); */
/*                 contour.width (- bold); */
                
/*                 path->path.concat_path (contour, 0); */
/*             } */
/*             else */
/*             { */
/*                 agg::font_path_provider font_path = agg::font_path_provider (face, glyph, info, 0, 0, 1, 1); */
/*                 agg::conv_transform<agg::font_path_provider, agg::trans_affine> conv (font_path, matrix); */
                
/*                 path->path.concat_path (conv, 0); */
/*             } */
/*         } */
/*     } */
/* } */

/*****************************************************************************/

void Path_CombinePathsUsingGpc(Path* path1,
    Path* path2,
    Path* result,
    int op
){
    if (path1 && path2 && result)
    {
        agg::conv_curve<agg::path_storage> curve1 (path1->path);
        agg::conv_curve<agg::path_storage> curve2 (path2->path);
        
        agg::conv_gpc<agg::conv_curve<agg::path_storage>, agg::conv_curve<agg::path_storage> > gpc (curve1, curve2);
        gpc.operation (static_cast<agg::gpc_op_e> (op));
        
        result->path.concat_path (gpc, 0);
    }
}

/*****************************************************************************/

void Path_AppendPath(Path* path,
    Path* path2,
    double xx, double xy,
    double yx, double yy,
    double tx, double ty,
    double scale,
    double bold
){
    if (path && path2)
    {
        agg::trans_affine matrix = agg::trans_affine (xx, yx, xy, yy, tx, ty);
        
        if (bold)
        {
            agg::conv_transform<agg::path_storage, agg::trans_affine> conv (path2->path, matrix);
            agg::conv_curve<agg::conv_transform<agg::path_storage, agg::trans_affine> > curve (conv);
            agg::conv_contour<agg::conv_curve<agg::conv_transform<agg::path_storage, agg::trans_affine> > > contour (curve);
            
            curve.approximation_scale (scale * 2);
            
            contour.auto_detect_orientation (true);
            contour.width (bold);
            
            path->path.concat_path (contour, 0);
        }
        else
        {
            if (scale)
            {
                agg::conv_transform<agg::path_storage, agg::trans_affine> conv (path2->path, matrix);
                agg::conv_curve<agg::conv_transform<agg::path_storage, agg::trans_affine> > curve (conv);
                
                curve.approximation_scale (scale * 2);
                
                path->path.concat_path (curve, 0);
            }
            else
            {
                agg::conv_transform<agg::path_storage, agg::trans_affine> conv (path2->path, matrix);
                
                path->path.concat_path (conv, 0);
            }
        }
    }
}

/*****************************************************************************/

void Path_AppendPathStroke(Path* path,
    Path* path2,
    double width,
    int cap,
    int join,
    double miter_limit,
    double scale,
    bool curved
){
    if (path && path2)
    {
        if (curved)
        {
            agg::conv_curve<agg::path_storage> curve (path2->path);
            agg::conv_stroke<agg::conv_curve<agg::path_storage> > stroke (curve);
            
            curve.approximation_scale (scale * 2);
            
            stroke.approximation_scale (scale * 2);
            stroke.width (width);
            stroke.line_cap ((agg::line_cap_e) cap);
            stroke.line_join ((agg::line_join_e) join);
            stroke.miter_limit (miter_limit);
            
            path->path.concat_path (stroke, 0);
        }
        else
        {
            agg::conv_stroke<agg::path_storage> stroke (path2->path);
            
            stroke.approximation_scale (scale * 2);
            stroke.width (width);
            stroke.line_cap ((agg::line_cap_e) cap);
            stroke.line_join ((agg::line_join_e) join);
            stroke.miter_limit (miter_limit);
            
            path->path.concat_path (stroke, 0);
        }
    }
}

/*****************************************************************************/

void Path_ComputeBounds(Path* path,
    double& x1, double& y1,
    double& x2, double& y2
){
    if (path)
    {
        unsigned path_i [1] = { 0 };
        
        x1 = 0;
        y1 = 0;
        x2 = 0;
        y2 = 0;
        
        agg::bounding_rect (path->curve, path_i, 0, 1, &x1, &y1, &x2, &y2);
    }
}

void Path_AppendArc(Path* path,
    double x, double y,
    double rx, double ry,
    double a1, double a2,
    bool ccw,
    double scale,
    bool continue_path
){
    if (path)
    {
        agg::arc arc (x, y, rx, ry, a1, a2, ccw);
        
        arc.approximation_scale (scale * 2);
        if (continue_path)
        {
            path->path.join_path (arc, 0);
        }
        else
        {
            path->path.concat_path (arc, 0);
        }
    }
}

/*****************************************************************************/

void Path_DashReset(Path* path){
    if (path)
    {
        path->dash.remove_all_dashes ();
        path->has_dashes = false;
    }
}

void Path_DashAdd(Path* path,
    double dash_len,
    double gap_len
){
    if (path)
    {
        path->dash.add_dash (dash_len, gap_len);
        path->has_dashes = true;
    }
}

void Path_DashSetStart(Path* path,
    double dash_start
){
    if (path)
    {
        path->dash.dash_start (dash_start);
    }
}

void Path_AppendDashedPath(Path* path,
    Path* dash,
    double scale
){
    if (path && dash && (scale > 0))
    {
        dash->curve.approximation_scale (scale * 2);
        path->path.concat_path (dash->dash, 0);
    }
}

/*****************************************************************************/
