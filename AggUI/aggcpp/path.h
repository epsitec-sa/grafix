#pragma once

#include "declspec.h"

#include "agg_conv_gpc.h"

#include "agg_arc.h"
#include "agg_bounding_rect.h"
/* #include "agg_font_path_provider.h" */
#include "agg_conv_contour.h"
#include "agg_conv_curve.h"
#include "agg_conv_dash.h"
#include "agg_conv_stroke.h"
#include "agg_path_storage.h"

struct Path
{
    agg::path_storage                                   path;
    agg::conv_curve<agg::path_storage>                  curve;
    agg::conv_dash<agg::conv_curve<agg::path_storage> > dash;
    
    bool                has_dashes;
    
    Path() : path(), curve(path), dash(curve), has_dashes(false)
    {
    }
};

extern "C" DECLSPEC Path* Path_New();

extern "C" DECLSPEC void Path_Delete(Path* path);

extern "C" DECLSPEC void Path_MoveTo(Path* path,
    double x, double y
);

extern "C" DECLSPEC void Path_LineTo(Path* path,
    double x, double y
);

extern "C" DECLSPEC void Path_Curve3(Path* path,
    double x_c, double y_c,
    double x, double y
);

extern "C" DECLSPEC void Path_Curve4(Path* path,
    double x_c1, double y_c1,
    double x_c2, double y_c2,
    double x, double y
);

extern "C" DECLSPEC void Path_Close(Path* path
);

extern "C" DECLSPEC void Path_AddNewPath(Path* path
);

/* extern "C" DECLSPEC void Path_AppendGlyph(Path* path, */
/*     agg::font_face* face, */
/*     int glyph, */
/*     double xx, double xy, */
/*     double yx, double yy, */
/*     double tx, double ty, */
/*     double bold */
/* ); */

extern "C" DECLSPEC void Path_AppendPath(Path* path,
    Path* path2,
    double xx, double xy,
    double yx, double yy,
    double tx, double ty,
    double scale,
    double bold
);

extern "C" DECLSPEC void Path_AppendPathStroke(Path* path,
    Path* path2,
    double width,
    int cap,
    int join,
    double miter_limit,
    double scale,
    bool curved
);

extern "C" DECLSPEC void Path_AppendArc(Path* path,
    double x, double y,
    double rx, double ry,
    double a1, double a2,
    bool ccw,
    double scale,
    bool continue_path
);

extern "C" DECLSPEC void Path_AppendDashedPath(Path* path,
    Path* dash,
    double scale
);

extern "C" DECLSPEC void Path_CombinePathsUsingGpc(Path* path1,
    Path* path2,
    Path* result,
    int op
);

extern "C" DECLSPEC void Path_ComputeBounds(Path* path,
    double& x1, double& y1,
    double& x2, double& y2
);

extern "C" DECLSPEC void Path_RemoveAll(Path* path
);

extern "C" DECLSPEC int Path_ElemCount(Path* path
);

extern "C" DECLSPEC void Path_ElemGet(Path* path,
    int n,
    int* types,
    double* x, double* y
);

extern "C" DECLSPEC void Path_DashReset(Path* path
);

extern "C" DECLSPEC void Path_DashAdd(Path* path,
    double dash_len,
    double gap_len
);

extern "C" DECLSPEC void Path_DashSetStart(Path* path,
    double dash_start
);

