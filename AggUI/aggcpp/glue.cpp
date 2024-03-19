//	glue.cpp
//
//	Copyright © 2003-2006, Pierre ARNAUD, OPaC bright ideas, Ch. du Fontenay 6,
//	                       CH-1400 YVERDON, Switzerland. All rights reserved. 
//
//	Contact: pierre.arnaud@opac.ch, http://www.opac.ch
//	License: see license.txt

#ifdef MANAGED_AGG

#include "interface.h"
#include <malloc.h>

#pragma managed
#using <mscorlib.dll>

/*
 *	The "glue" consists of low level functions required to set up and
 *	tear down the library itself, and to get some stats about it.
 */

/*****************************************************************************/

static const int OFFSET_TO_STRING_DATA = System::Runtime::CompilerServices::RuntimeHelpers::get_OffsetToStringData ();

namespace Agg
{
__gc public class Interface
{
public:
	static bool Initialise()
	{
		return AggInitialise ();
	}
	
	static void ShutDown()
	{
		AggShutDown ();
	}
	
	static System::IntPtr GetVersion()
	{
		return __nogc new System::IntPtr (const_cast<wchar_t*> (AggGetVersion ()));
	}
	
	static System::IntPtr GetProductName()
	{
		return __nogc new System::IntPtr (const_cast<wchar_t*> (AggGetProductName ()));
	}
	
	static System::IntPtr BufferNew(int dx, int dy, int bpp)
	{
		return AggBufferNew (dx, dy, bpp);
	}
	
	static void BufferResize(System::IntPtr buffer, int dx, int dy, int bpp)
	{
		AggBufferResize (reinterpret_cast<AggBuffer*> (buffer.ToPointer ()), dx, dy, bpp);
	}
	
	static void BufferPaint(System::IntPtr buffer, System::IntPtr hdc, int x1, int y1, int x2, int y2)
	{
		AggBufferPaint (reinterpret_cast<AggBuffer*> (buffer.ToPointer ()),
						reinterpret_cast<void*> (hdc.ToPointer ()), x1, y1, x2, y2);
	}
	
	static void BufferClear(System::IntPtr buffer)
	{
		AggBufferClear (reinterpret_cast<AggBuffer*> (buffer.ToPointer ()));
	}
	
	static void BufferDelete(System::IntPtr buffer)
	{
		AggBufferDelete (reinterpret_cast<AggBuffer*> (buffer.ToPointer ()));
	}
	
	static System::IntPtr RendererSolidNew(System::IntPtr buffer)
	{
		return __nogc new System::IntPtr (AggRendererSolidNew (reinterpret_cast<AggBuffer*> (buffer.ToPointer ())));
	}
	
	static void	RendererSolidClear(System::IntPtr renderer, double r, double g, double b, double a)
	{
		AggRendererSolidClear (reinterpret_cast<AggRendererSolid*> (renderer.ToPointer ()), r, g, b, a);
	}
	
	static void	RendererSolidColor(System::IntPtr renderer, double r, double g, double b, double a)
	{
		AggRendererSolidColor (reinterpret_cast<AggRendererSolid*> (renderer.ToPointer ()), r, g, b, a);
	}
	
	static void	RendererSolidDelete(System::IntPtr renderer)
	{
		AggRendererSolidDelete (reinterpret_cast<AggRendererSolid*> (renderer.ToPointer ()));
	}
	
	static System::IntPtr RendererImageNew(System::IntPtr buffer)
	{
		return __nogc new System::IntPtr (AggRendererImageNew (reinterpret_cast<AggBuffer*> (buffer.ToPointer ())));
	}
	
	static void RendererImageMatrix(System::IntPtr renderer, double xx, double xy, double yx, double yy, double tx, double ty)
	{
		AggRendererImageMatrix (reinterpret_cast<AggRendererImage*> (renderer.ToPointer ()), xx, xy, yx, yy, tx, ty);
	}
	
	static void RendererImageSource1(System::IntPtr renderer, System::IntPtr buffer)
	{
		AggRendererImageSource1 (reinterpret_cast<AggRendererImage*> (renderer.ToPointer ()),
							     reinterpret_cast<AggBuffer*> (buffer.ToPointer ()));
	}
	
	static void RendererImageSource2(System::IntPtr renderer, System::IntPtr byte_buffer, int dx, int dy, int stride)
	{
		AggRendererImageSource2 (reinterpret_cast<AggRendererImage*> (renderer.ToPointer ()),
							     reinterpret_cast<void*> (byte_buffer.ToPointer ()), dx, dy, stride);
	}
	
	static void RendererImageDelete(System::IntPtr renderer)
	{
		AggRendererImageDelete (reinterpret_cast<AggRendererImage*> (renderer.ToPointer ()));
	}
	
	static System::IntPtr RendererGradientNew(System::IntPtr buffer)
	{
		return __nogc new System::IntPtr (AggRendererGradientNew (reinterpret_cast<AggBuffer*> (buffer.ToPointer ())));
	}
	
	static void RendererGradientDelete(System::IntPtr renderer)
	{
		AggRendererGradientDelete (reinterpret_cast<AggRendererGradient*> (renderer.ToPointer ()));
	}
	
	static void RendererGradientSelect(System::IntPtr renderer, int id)
	{
		AggRendererGradientSelect (reinterpret_cast<AggRendererGradient*> (renderer.ToPointer ()), id);
	}
	
	static void RendererGradientColor1(System::IntPtr renderer, double r __gc[], double g __gc[], double b __gc[], double a __gc[])
	{
		double rr[256];
		double gg[256];
		double bb[256];
		double aa[256];
		
		System::Runtime::InteropServices::Marshal::Copy (r, 0, rr, 256);
		System::Runtime::InteropServices::Marshal::Copy (g, 0, gg, 256);
		System::Runtime::InteropServices::Marshal::Copy (b, 0, bb, 256);
		System::Runtime::InteropServices::Marshal::Copy (a, 0, aa, 256);
		
		AggRendererGradientColor1 (reinterpret_cast<AggRendererGradient*> (renderer.ToPointer ()), rr, gg, bb, aa);
	}
	
	static void RendererGradientRange(System::IntPtr renderer, double r1, double r2)
	{
		AggRendererGradientRange (reinterpret_cast<AggRendererGradient*> (renderer.ToPointer ()), r1, r2);
	}
	
	static void RendererGradientMatrix(System::IntPtr renderer, double xx, double xy, double yx, double yy, double tx, double ty)
	{
		AggRendererGradientMatrix (reinterpret_cast<AggRendererGradient*> (renderer.ToPointer ()), xx, xy, yx, yy, tx, ty);
	}

	static System::IntPtr RasterizerNew()
	{
		return __nogc new System::IntPtr (AggRasterizerNew ());
	}
	
	static void RasterizerClear(System::IntPtr rasterizer)
	{
		AggRasterizerClear (reinterpret_cast<AggRasterizer*> (rasterizer.ToPointer ()));
	}
	
	static void RasterizerFillingRule(System::IntPtr rasterizer, int mode)
	{
		AggRasterizerFillingRule (reinterpret_cast<AggRasterizer*> (rasterizer.ToPointer ()), mode);
	}
	
	static void RasterizerGamma(System::IntPtr rasterizer, double gamma)
	{
		AggRasterizerGamma (reinterpret_cast<AggRasterizer*> (rasterizer.ToPointer ()), gamma);
	}
	
	static void RasterizerSetTransform(System::IntPtr rasterizer, double xx, double xy, double yx, double yy, double tx, double ty)
	{
		AggRasterizerSetTransform (reinterpret_cast<AggRasterizer*> (rasterizer.ToPointer ()), xx, xy, yx, yy, tx, ty);
	}
	
	static void RasterizerSetClipBox(System::IntPtr rasterizer, double x1, double y1, double x2, double y2)
	{
		AggRasterizerSetClipBox (reinterpret_cast<AggRasterizer*> (rasterizer.ToPointer ()), x1, y1, x2, y2);
	}
	
	static void RasterizerResetClipBox(System::IntPtr rasterizer)
	{
		AggRasterizerResetClipBox (reinterpret_cast<AggRasterizer*> (rasterizer.ToPointer ()));
	}
	
	static void RasterizerAddPath(System::IntPtr rasterizer, System::IntPtr path, bool curves)
	{
		AggRasterizerAddPath (reinterpret_cast<AggRasterizer*> (rasterizer.ToPointer ()),
							  reinterpret_cast<AggPath*> (path.ToPointer ()), curves);
	}
	
	static void RasterizerAddGlyph(System::IntPtr rasterizer, System::IntPtr face, int glyph, double x, double y, double scale)
	{
		AggRasterizerAddGlyph (reinterpret_cast<AggRasterizer*> (rasterizer.ToPointer ()),
							   reinterpret_cast<FontFace*> (face.ToPointer ()),
							   glyph, x, y, scale);
	}
	
	static double RasterizerAddText(System::IntPtr rasterizer, System::IntPtr face, System::String* text, int mode, double xx, double xy, double yx, double yy, double tx, double ty)
	{
		System::String __pin * pinned_text = text;
		const wchar_t*         native_text = (const wchar_t*)((char*)(*((void**)&pinned_text)) + OFFSET_TO_STRING_DATA);
		
		return AggRasterizerAddText(reinterpret_cast<AggRasterizer*> (rasterizer.ToPointer ()),
									reinterpret_cast<FontFace*> (face.ToPointer ()),
									native_text, mode, xx, xy, yx, yy, tx, ty);
	}
	
	static void RasterizerAddPathStroke1(System::IntPtr rasterizer, System::IntPtr path, double width, bool curves)
	{
		AggRasterizerAddPathStroke1 (reinterpret_cast<AggRasterizer*> (rasterizer.ToPointer ()),
									 reinterpret_cast<AggPath*> (path.ToPointer ()),
									 width, curves);
	}
	
	static void RasterizerAddPathStroke2(System::IntPtr rasterizer, System::IntPtr path, double width, int cap, int join, double miter_limit, bool curves)
	{
		AggRasterizerAddPathStroke2 (reinterpret_cast<AggRasterizer*> (rasterizer.ToPointer ()),
									 reinterpret_cast<AggPath*> (path.ToPointer ()),
									 width, cap, join, miter_limit, curves);
	}
	
	static void RasterizerRenderSolid(System::IntPtr rasterizer, System::IntPtr renderer)
	{
		AggRasterizerRenderSolid (reinterpret_cast<AggRasterizer*> (rasterizer.ToPointer ()),
								  reinterpret_cast<AggRendererSolid*> (renderer.ToPointer ()));
	}
	
	static void RasterizerRenderImage(System::IntPtr rasterizer, System::IntPtr renderer)
	{
		AggRasterizerRenderImage (reinterpret_cast<AggRasterizer*> (rasterizer.ToPointer ()),
								  reinterpret_cast<AggRendererImage*> (renderer.ToPointer ()));
	}
	
	static void RasterizerRenderGradient(System::IntPtr rasterizer, System::IntPtr renderer)
	{
		AggRasterizerRenderGradient (reinterpret_cast<AggRasterizer*> (rasterizer.ToPointer ()),
								     reinterpret_cast<AggRendererGradient*> (renderer.ToPointer ()));
	}
	
	static void RasterizerDelete(System::IntPtr rasterizer)
	{
		AggRasterizerDelete (reinterpret_cast<AggRasterizer*> (rasterizer.ToPointer ()));
	}

	static System::IntPtr PathNew()
	{
		return __nogc new System::IntPtr (AggPathNew ());
	}
	
	static void PathMoveTo(System::IntPtr path, double x, double y)
	{
		AggPathMoveTo (reinterpret_cast<AggPath*> (path.ToPointer ()), x, y);
	}
	
	static void PathLineTo(System::IntPtr path, double x, double y)
	{
		AggPathLineTo (reinterpret_cast<AggPath*> (path.ToPointer ()), x, y);
	}
	
	static void PathCurve3(System::IntPtr path, double x_c, double y_c, double x, double y)
	{
		AggPathCurve3 (reinterpret_cast<AggPath*> (path.ToPointer ()), x_c, y_c, x, y);
	}
	
	static void PathCurve4(System::IntPtr path, double x_c1, double y_c1, double x_c2, double y_c2, double x, double y)
	{
		AggPathCurve4 (reinterpret_cast<AggPath*> (path.ToPointer ()), x_c1, y_c1, x_c2, y_c2, x, y);
	}
	
	static void PathClose(System::IntPtr path)
	{
		AggPathClose (reinterpret_cast<AggPath*> (path.ToPointer ()));
	}
	
	static void PathAddNewPath(System::IntPtr path)
	{
		AggPathAddNewPath (reinterpret_cast<AggPath*> (path.ToPointer ()));
	}
	
	static void PathAppendGlyph(System::IntPtr path, System::IntPtr face, int glyph, double xx, double xy, double yx, double yy, double tx, double ty, double bold)
	{
		AggPathAppendGlyph (reinterpret_cast<AggPath*> (path.ToPointer ()),
							reinterpret_cast<FontFace*> (face.ToPointer ()),
							glyph, xx, xy, yx, yy, tx, ty, bold);
	}
	
	static void PathAppendPath(System::IntPtr path, System::IntPtr path2, double xx, double xy, double yx, double yy, double tx, double ty, double bold)
	{
		AggPathAppendPath (reinterpret_cast<AggPath*> (path.ToPointer ()),
						   reinterpret_cast<AggPath*> (path2.ToPointer ()),
						   xx, xy, yx, yy, tx, ty, bold);
	}
	
	static void PathComputeBounds(System::IntPtr path, double& x1, double& y1, double& x2, double& y2)
	{
		AggPathComputeBounds (reinterpret_cast<AggPath*> (path.ToPointer ()),
							  x1, y1, x2, y2);
	}
	
	static void PathRemoveAll(System::IntPtr path)
	{
		AggPathRemoveAll (reinterpret_cast<AggPath*> (path.ToPointer ()));
	}
	
	static int PathElemCount(System::IntPtr path)
	{
		return AggPathElemCount (reinterpret_cast<AggPath*> (path.ToPointer ()));
	}
	
	static void PathElemGet(System::IntPtr path, int n, int types __gc[], double x __gc[], double y __gc[])
	{
		if (n > 0)
		{
			int* types_copy = reinterpret_cast<int*> (_alloca (sizeof (int)*n));
			double* x_copy  = reinterpret_cast<double*> (_alloca (sizeof (double)*n));
			double* y_copy  = reinterpret_cast<double*> (_alloca (sizeof (double)*n));
			
			AggPathElemGet (reinterpret_cast<AggPath*> (path.ToPointer ()),
							n, types_copy, x_copy, y_copy);
			
			System::Runtime::InteropServices::Marshal::Copy (types_copy, types, 0, n);
			System::Runtime::InteropServices::Marshal::Copy (x_copy, x, 0, n);
			System::Runtime::InteropServices::Marshal::Copy (y_copy, y, 0, n);
		}
	}
	
	static void PathDelete(System::IntPtr path)
	{
		AggPathDelete (reinterpret_cast<AggPath*> (path.ToPointer ()));
	}
	
	static void FontInitialise()
	{
		AggFontInitialise ();
	}
	
	static int FontGetFaceCount()
	{
		return AggFontGetFaceCount ();
	}
	
	static System::IntPtr FontGetFaceByRank(int n)
	{
		return AggFontGetFaceByRank (n);
	}
	
	static System::IntPtr FontGetFaceByName(System::String* family, System::String* style, System::String* optical)
	{
		System::String __pin * pinned_family  = family;
		System::String __pin * pinned_style   = style;
		System::String __pin * pinned_optical = optical;
		
		const wchar_t* native_family  = (const wchar_t*)((char*)(*((void**)&pinned_family )) + OFFSET_TO_STRING_DATA);
		const wchar_t* native_style   = (const wchar_t*)((char*)(*((void**)&pinned_style  )) + OFFSET_TO_STRING_DATA);
		const wchar_t* native_optical = (const wchar_t*)((char*)(*((void**)&pinned_optical)) + OFFSET_TO_STRING_DATA);
		
		return AggFontGetFaceByName (native_family, native_style, native_optical);
	}
	
	static System::String* FontFaceGetName(System::IntPtr face, int id)
	{
		const wchar_t* name = AggFontFaceGetName (reinterpret_cast<FontFace*> (face.ToPointer ()), id);
		return new System::String (name);
	}
	
	static int FontFaceGetGlyphIndex(System::IntPtr face, int unicode)
	{
		return AggFontFaceGetGlyphIndex (reinterpret_cast<FontFace*> (face.ToPointer ()), unicode);
	}
	
	static double FontFaceGetGlyphAdvance(System::IntPtr face, int glyph)
	{
		return AggFontFaceGetGlyphAdvance (reinterpret_cast<FontFace*> (face.ToPointer ()), glyph);
	}
	
	static double FontFaceGetCharAdvance(System::IntPtr face, int unicode)
	{
		return AggFontFaceGetCharAdvance (reinterpret_cast<FontFace*> (face.ToPointer ()), unicode);
	}
	
	static double FontFaceGetTextAdvance(System::IntPtr face, System::String* text, int mode)
	{
		System::String __pin * pinned_text = text;
		const wchar_t*         native_text = (const wchar_t*)((char*)(*((void**)&pinned_text)) + OFFSET_TO_STRING_DATA);
		
		return AggFontFaceGetTextAdvance (reinterpret_cast<FontFace*> (face.ToPointer ()), native_text, mode);
	}
	
	static void FontFaceGetGlyphBounds (System::IntPtr face, int glyph, double& x_min, double& y_min, double& x_max, double& y_max)
	{
		AggFontFaceGetGlyphBounds (reinterpret_cast<FontFace*> (face.ToPointer ()), glyph, x_min, y_min, x_max, y_max);
	}
	
	static void FontFaceGetCharBounds (System::IntPtr face, int unicode, double& x_min, double& y_min, double& x_max, double& y_max)
	{
		AggFontFaceGetCharBounds (reinterpret_cast<FontFace*> (face.ToPointer ()), unicode, x_min, y_min, x_max, y_max);
	}
	
	static void FontFaceGetTextBounds (System::IntPtr face, System::String* text, int mode, double& x_min, double& y_min, double& x_max, double& y_max)
	{
		System::String __pin * pinned_text = text;
		const wchar_t*         native_text = (const wchar_t*)((char*)(*((void**)&pinned_text)) + OFFSET_TO_STRING_DATA);
		
		AggFontFaceGetTextBounds (reinterpret_cast<FontFace*> (face.ToPointer ()), native_text, mode, x_min, y_min, x_max, y_max);
	}
	
	static double FontFaceGetMetrics(System::IntPtr face, int id)
	{
		return AggFontFaceGetMetrics (reinterpret_cast<FontFace*> (face.ToPointer ()), id);
	}
	
	static int FontFaceGetTextCharEndXArray(System::IntPtr face, System::String* text, int mode, double x_array __gc[])
	{
		int n = text == 0 ? 0 : text->get_Length ();
		
		if (n == 0)
		{
			return 0;
		}
		
		System::String __pin * pinned_text = text;
		const wchar_t*         native_text = (const wchar_t*)((char*)(*((void**)&pinned_text)) + OFFSET_TO_STRING_DATA);
		
		double* x_copy  = reinterpret_cast<double*> (_alloca (sizeof (double)*n));
		
		AggFontFaceGetTextCharEndXArray (reinterpret_cast<FontFace*> (face.ToPointer ()), native_text, mode, x_copy);
		
		System::Runtime::InteropServices::Marshal::Copy (x_copy, x_array, 0, n);
		
		return n;
	}
	
	static System::IntPtr FontFaceBreakNew(System::IntPtr face, System::String* text, int mode)
	{
		System::String __pin * pinned_text = text;
		const wchar_t*         native_text = (const wchar_t*)((char*)(*((void**)&pinned_text)) + OFFSET_TO_STRING_DATA);
		
		return AggFontFaceBreakNew (reinterpret_cast<FontFace*> (face.ToPointer ()), native_text, static_cast<TextBreakMode> (mode));
	}
	
	static System::String* FontFaceBreakIter(System::IntPtr context, double& width, int& n_char)
	{
		const wchar_t* text = AggFontFaceBreakIter (reinterpret_cast<BreakContext*> (context.ToPointer ()), width, n_char);
		return new System::String (text);
	}
	
	static void FontFaceBreakDelete(System::IntPtr context)
	{
		AggFontFaceBreakDelete (reinterpret_cast<BreakContext*> (context.ToPointer ()));
	}
	
	static bool FontFaceBreakHasMore(System::IntPtr context)
	{
		return AggFontFaceBreakHasMore (reinterpret_cast<BreakContext*> (context.ToPointer ()));
	}
	
	static void FontPixelCacheFill(System::IntPtr face, System::String* text, double scale, double ox, double oy)
	{
		System::String __pin * pinned_text = text;
		const wchar_t*         native_text = (const wchar_t*)((char*)(*((void**)&pinned_text)) + OFFSET_TO_STRING_DATA);
		
		AggFontPixelCacheFill (reinterpret_cast<FontFace*> (face.ToPointer ()), native_text, scale, ox, oy);
	}
	
	static void FontPixelCacheRender(System::IntPtr buffer, System::IntPtr face, System::String* text, double scale, double ox, double oy)
	{
		System::String __pin * pinned_text = text;
		const wchar_t*         native_text = (const wchar_t*)((char*)(*((void**)&pinned_text)) + OFFSET_TO_STRING_DATA);
		
		AggFontPixelCacheRender (reinterpret_cast<AggBuffer*> (buffer.ToPointer ()), reinterpret_cast<FontFace*> (face.ToPointer ()), native_text, scale, ox, oy);
	}
	
	static System::Int64 DebugGetCycles()
	{
		return GetCycleCount ();
	}
	
	static int DebugGetCycleDelta()
	{
		return AggDebugGetCycleDelta ();
	}
};
}

#pragma unmanaged
#endif
