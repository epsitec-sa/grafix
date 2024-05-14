// Copyright © 2003-2024, EPSITEC SA, CH-1400 Yverdon-les-Bains, Switzerland
// Author: Pierre ARNAUD, Roger VUISTINER, Maintainer: Roger VUISTINER

using System.Runtime.InteropServices;

namespace AntigrainSharp
{
    internal static class Native
    {
        private const string LibAgg = "AntigrainCPP";

        #region AggWindow

        public delegate void OnDrawT(IntPtr gctx);
        public delegate void OnResizeT(int sx, int sy);
        public delegate void OnMouseMoveT(int x, int y, uint flags);
        public delegate void OnMouseButtonDownT(int x, int y, uint flags);
        public delegate void OnMouseButtonUpT(int x, int y, uint flags);
        public delegate void OnKeyT(int x, int y, uint key, uint flags);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern IntPtr NewApplication(
            bool flip_y,
            OnDrawT on_draw,
            OnResizeT on_resize,
            OnMouseMoveT on_mouse_move,
            OnMouseButtonDownT on_mouse_button_down,
            OnMouseButtonUpT on_mouse_button_up,
            OnKeyT on_key,
            IntPtr fm
        );

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Application_Caption(IntPtr app, string text);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern bool Application_Init(
            IntPtr app,
            uint width,
            uint height,
            WindowFlags flags
        );

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Application_ForceRedraw(IntPtr app);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Application_SetColor(IntPtr app, int r, int g, int b);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Application_DrawEllipse(
            IntPtr app,
            double x,
            double y,
            double rx,
            double ry
        );

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern int Application_Run(IntPtr app);
        #endregion

        #region Path
        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern IntPtr Path_New();

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Path_MoveTo(IntPtr path, double x, double y);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Path_LineTo(IntPtr path, double x, double y);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Path_Curve3(
            IntPtr path,
            double x_c,
            double y_c,
            double x,
            double y
        );

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Path_Curve4(
            IntPtr path,
            double x_c1,
            double y_c1,
            double x_c2,
            double y_c2,
            double x,
            double y
        );

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Path_Close(IntPtr path);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Path_AddNewPath(IntPtr path);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Path_AppendGlyph(
            IntPtr path,
            IntPtr face,
            int glyph,
            double xx,
            double xy,
            double yx,
            double yy,
            double tx,
            double ty,
            double bold
        );

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Path_AppendPathStroke(
            IntPtr path,
            IntPtr path2,
            double width,
            int cap,
            int join,
            double miter_limit,
            double scale,
            [MarshalAs(UnmanagedType.U1)] bool curved
        );

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Path_AppendPath(
            IntPtr path,
            IntPtr path2,
            double xx,
            double xy,
            double yx,
            double yy,
            double tx,
            double ty,
            double scale,
            double bold
        );

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Path_AppendArc(
            IntPtr path,
            double x,
            double y,
            double rx,
            double ry,
            double a1,
            double a2,
            [MarshalAs(UnmanagedType.U1)] bool ccw,
            double scale,
            [MarshalAs(UnmanagedType.U1)] bool continue_pa
        );

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Path_AppendDashedPath(IntPtr path, IntPtr dash, double scale);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Path_CombinePathsUsingGpc(
            IntPtr path1,
            IntPtr path2,
            IntPtr result,
            int operation
        );

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Path_ComputeBounds(
            IntPtr path,
            out double x1,
            out double y1,
            out double x2,
            out double y2
        );

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Path_RemoveAll(IntPtr path);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern int Path_ElemCount(IntPtr path);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Path_ElemGet(
            IntPtr path,
            int n,
            int[] types,
            double[] x,
            double[] y
        );

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Path_Delete(IntPtr path);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Path_DashReset(IntPtr path);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Path_DashAdd(IntPtr path, double dash_length, double gap_length);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Path_DashSetStart(IntPtr path, double start);
        #endregion

        #region Rasterizer
        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern IntPtr Rasterizer_New();

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Rasterizer_Clear(IntPtr rasterizer);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        [return: MarshalAs(UnmanagedType.U1)]
        public static extern bool Rasterizer_HitTest(IntPtr rasterizer, int x, int y);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Rasterizer_FillingRule(IntPtr rasterizer, int mode);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Rasterizer_Gamma(IntPtr rasterizer, double gamma);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Rasterizer_SetTransform(
            IntPtr rasterizer,
            double xx,
            double xy,
            double yx,
            double yy,
            double tx,
            double ty
        );

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Rasterizer_SetClipBox(
            IntPtr rasterizer,
            double x1,
            double y1,
            double x2,
            double y2
        );

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Rasterizer_ResetClipBox(IntPtr rasterizer);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Rasterizer_AddPath(
            IntPtr rasterizer,
            IntPtr path,
            [MarshalAs(UnmanagedType.U1)] bool curves
        );

        /* [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)] */
        /* public static extern void Rasterizer_AddGlyph(IntPtr rasterizer, IntPtr face, int glyph, double x, double y, double scale); */

        /* [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)] */
        /* public static extern void Rasterizer_AddGlyphXY(IntPtr rasterizer, IntPtr face, int glyph, double x, double y, double scale_x, double scale_y); */

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Rasterizer_AddPathStroke1(
            IntPtr rasterizer,
            IntPtr path,
            double width,
            [MarshalAs(UnmanagedType.U1)] bool curves
        );

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Rasterizer_AddPathStroke2(
            IntPtr rasterizer,
            IntPtr path,
            double width,
            int cap,
            int join,
            double miter_limit,
            [MarshalAs(UnmanagedType.U1)] bool curves
        );

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Rasterizer_RenderSolid(IntPtr rasterizer, IntPtr renderer);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Rasterizer_RenderImage(IntPtr rasterizer, IntPtr renderer);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Rasterizer_RenderGradient(IntPtr rasterizer, IntPtr renderer);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void Rasterizer_Delete(IntPtr rasterizer);
        #endregion

        #region Renderer

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void RendererFill4Colors(
            IntPtr renderer,
            int x,
            int y,
            int dx,
            int dy,
            double r1,
            double g1,
            double b1,
            double r2,
            double g2,
            double b2,
            double r3,
            double g3,
            double b3,
            double r4,
            double g4,
            double b4
        );

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void RendererSolid_Clear(
            IntPtr renderer,
            double r,
            double g,
            double b,
            double a
        );

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void RendererSolid_Color(
            IntPtr renderer,
            double r,
            double g,
            double b,
            double a
        );

        /* [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)] */
        /* public static extern void RendererSolid_SetAlphaMask(IntPtr renderer, IntPtr buffer, int component); */

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void RendererSmooth_Color(
            IntPtr renderer,
            double r,
            double g,
            double b,
            double a
        );

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void RendererSmooth_Setup(
            IntPtr renderer,
            double r1,
            double r2,
            double xx,
            double xy,
            double yx,
            double yy,
            double tx,
            double ty
        );

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void RendererSmooth_AddPath(IntPtr renderer, IntPtr path);

        /* [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)] */
        /* public static extern void RendererSmooth_SetAlphaMask(IntPtr renderer, IntPtr buffer, int component); */

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void RendererImage_Matrix(
            IntPtr renderer,
            double xx,
            double xy,
            double yx,
            double yy,
            double tx,
            double ty
        );

        /* [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)] */
        /* public static extern void RendererImage_Source1(IntPtr renderer, IntPtr buffer); */

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void RendererImage_AttachSource(
            IntPtr renderer,
            [In] byte[] byte_buffer,
            int dx,
            int dy,
            int stride
        );

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void RendererImage_SetStretchMode(
            IntPtr renderer,
            int mode,
            double radius
        );

        /* [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)] */
        /* public static extern void RendererImage_SetAlphaMask(IntPtr renderer, IntPtr buffer, int component); */

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void RendererGradient_Select(IntPtr renderer, int id);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void RendererGradient_Color1(
            IntPtr renderer,
            double[] r,
            double[] g,
            double[] b,
            double[] a
        );

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void RendererGradient_Range(IntPtr renderer, double r1, double r2);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void RendererGradient_Matrix(
            IntPtr renderer,
            double xx,
            double xy,
            double yx,
            double yy,
            double tx,
            double ty
        );

        /* [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)] */
        /* public static extern void RendererGradient_SetAlphaMask(IntPtr renderer, IntPtr buffer, int component); */

        #endregion

        #region Font
        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern IntPtr FreetypeInfo_CreateLibrary();

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern IntPtr FreetypeInfo_LoadFromFile(
            IntPtr library,
            [MarshalAs(UnmanagedType.LPStr)] string font_name
        );

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        [return: MarshalAs(UnmanagedType.U1)]
        public static extern bool FreetypeInfo_IsFaceBold(IntPtr face);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        [return: MarshalAs(UnmanagedType.U1)]
        public static extern bool FreetypeInfo_IsFaceItalic(IntPtr face);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern uint FreetypeInfo_GetCharIndex(IntPtr face, ulong charcode);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern double FreetypeInfo_GetGlyphAdvance(
            IntPtr face,
            uint glyph_index,
            double size
        );

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void FreetypeInfo_GetGlyphBBox(
            IntPtr face,
            uint glyph_index,
            double size,
            out double xMin,
            out double xMax,
            out double yMin,
            out double yMax
        );

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern double FreetypeInfo_GetKerning(
            IntPtr face,
            uint left_glyph,
            uint right_glyph,
            double size
        );

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern double FreetypeInfo_GetAscender(IntPtr face, double size);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern double FreetypeInfo_GetDescender(IntPtr face, double size);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern double FreetypeInfo_GetHeight(IntPtr face, double size);
        #endregion

        #region FontManager

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern IntPtr FontManager_New();

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        [return: MarshalAs(UnmanagedType.U1)]
        public static extern bool FontManager_LoadFont(
            IntPtr fm,
            [MarshalAs(UnmanagedType.LPStr)] string font_name
        );

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void FontManager_SetFontSize(IntPtr fm, double size);
        #endregion

        #region GraphicBuffer

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern IntPtr GraphicBuffer_NewGraphicBuffer(
            uint width,
            uint height,
            int stride,
            IntPtr fm
        );

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void GraphicBuffer_DeleteGraphicBuffer(IntPtr gbuff);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern IntPtr GraphicBuffer_NewGraphicBufferExternalData(
            IntPtr data_buffer,
            uint width,
            uint height,
            int stride,
            IntPtr fm
        );

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void GraphicBuffer_DeleteGraphicBufferExternalData(IntPtr gbuff);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern IntPtr GraphicBuffer_GetGraphicContext(IntPtr gbuff);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern uint GraphicBuffer_GetWidth(IntPtr gbuff);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern uint GraphicBuffer_GetHeight(IntPtr gbuff);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern int GraphicBuffer_GetStride(IntPtr gbuff);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern uint GraphicBuffer_GetBufferLength(IntPtr gbuff);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void GraphicBuffer_GetBufferData(
            IntPtr gbuff,
            [MarshalAs(UnmanagedType.LPArray)] [In, Out] byte[] output_buffer
        );
        #endregion

        #region GraphicContext

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void GraphicContext_SetColor(
            IntPtr gctx,
            double r,
            double g,
            double b,
            double a
        );

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void GraphicContext_DrawEllipse(
            IntPtr gctx,
            double x,
            double y,
            double rx,
            double ry
        );

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern double GraphicContext_DrawChar(
            IntPtr gctx,
            char character,
            double x,
            double y
        );

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern double GraphicContext_DrawText(
            IntPtr gctx,
            [MarshalAs(UnmanagedType.LPStr)] string text,
            double x,
            double y
        );

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern double GraphicContext_DrawGlyph(
            IntPtr gctx,
            uint glyph,
            double x,
            double y
        );

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern IntPtr GraphicContext_GetSolidRenderer(IntPtr gctx);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern IntPtr GraphicContext_GetSmoothRenderer(IntPtr gctx);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern IntPtr GraphicContext_GetImageRenderer(IntPtr gctx);

        [DllImport(LibAgg, CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern IntPtr GraphicContext_GetGradientRenderer(IntPtr gctx);
        #endregion
    }
}
