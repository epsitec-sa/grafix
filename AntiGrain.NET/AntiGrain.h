//	AntiGrain.h
//
//	Copyright © 2003-2005, Pierre ARNAUD, OPaC bright ideas, Ch. du Fontenay 6,
//	                       CH-1400 YVERDON, Switzerland. All rights reserved. 
//
//	Contact: pierre.arnaud@opac.ch, http://www.opac.ch

#pragma once

using namespace System::Runtime::InteropServices;

namespace AntiGrain
{
	__gc private class Internals
	{
	public:
		static int OffsetToStringData = 0;
	};
	
	__gc public class Interface
	{
	public:
		static bool Initialise()
		{
			Internals::OffsetToStringData = System::Runtime::CompilerServices::RuntimeHelpers::get_OffsetToStringData ();
			return AggInitialise ();
		}
		
		static void ShutDown()
		{
			AggShutDown ();
		}
		
		static void NoOp()
		{
			AggNoOp ();
		}
		
		static void NoOpString(System::String* text)
		{
			System::String __pin * pinned_text = text;
			const wchar_t*         native_text = (const wchar_t*)((char*)(*((void**)&pinned_text)) + Internals::OffsetToStringData);
			
			AggNoOpString (native_text);
		}
		
		static System::String* GetVersion()
		{
			return __gc new System::String (AggGetVersion ());
		}
		
		static System::String* GetProductName()
		{
			return __gc new System::String (AggGetProductName ());
		}
		
		static System::Int64 DebugGetCycles()
		{
			return GetCycleCount ();
		}
		
		static int DebugGetCycleDelta()
		{
			return AggDebugGetCycleDelta ();
		}
		
		static void DebugTrapZeroPointer()
		{
			AggDebugTrapZeroPointer();
		}
	};
	
	__gc public class Buffer
	{
	public:
		static System::IntPtr New(int dx, int dy, int bpp)
		{
			return System::IntPtr ((void*) AggBufferNew (dx, dy, bpp));
		}
		
		static System::IntPtr New(System::IntPtr hdc, int dx, int dy, int bpp)
		{
			return System::IntPtr ((void*) AggBufferNewUsingOS (hdc.ToPointer (), dx, dy, bpp));
		}
		
		static void Resize(System::IntPtr buffer, int dx, int dy, int bpp)
		{
			AggBufferResize (reinterpret_cast<AggBuffer*> (buffer.ToPointer ()), dx, dy, bpp);
		}
		
		static void InfiniteClipping(System::IntPtr buffer)
		{
			AggBufferInfiniteClipping (reinterpret_cast<AggBuffer*> (buffer.ToPointer ()));
		}
		
		static void EmptyClipping(System::IntPtr buffer)
		{
			AggBufferEmptyClipping (reinterpret_cast<AggBuffer*> (buffer.ToPointer ()));
		}
		
		static void AddClipBox(System::IntPtr buffer, int x1, int y1, int x2, int y2)
		{
			AggBufferAddClipBox (reinterpret_cast<AggBuffer*> (buffer.ToPointer ()), x1, y1, x2, y2);
		}
		
		static void DrawGlyphs(System::IntPtr buffer, System::IntPtr hfont, int x, int y, unsigned short glyphs __gc[], int dx_array __gc[], int count, unsigned int color)
		{
			unsigned short __pin * p_glyphs   = & glyphs[0];
			int __pin *            p_dx_array = (dx_array == 0) ? 0 : & dx_array[0];
			
			AggBufferDrawGlyphs(reinterpret_cast<AggBuffer*> (buffer.ToPointer ()), hfont.ToPointer (), x, y, p_glyphs, p_dx_array, (unsigned int) count, color);
		}
		

		static void Paint(System::IntPtr buffer, System::IntPtr hdc, int x1, int y1, int x2, int y2)
		{
			AggBufferPaint (reinterpret_cast<AggBuffer*> (buffer.ToPointer ()),
							reinterpret_cast<void*> (hdc.ToPointer ()), x1, y1, x2, y2);
		}

		static void PaintOffset(System::IntPtr buffer, System::IntPtr hdc, int ox, int oy, int x1, int y1, int x2, int y2)
		{
			AggBufferPaintOffset (reinterpret_cast<AggBuffer*> (buffer.ToPointer ()),
								reinterpret_cast<void*> (hdc.ToPointer ()), ox, oy, x1, y1, x2, y2);
		}
		
		static void BlendOffset(System::IntPtr buffer, System::IntPtr hdc, int ox, int oy, int x1, int y1, int x2, int y2)
		{
			AggBufferBlendOffset (reinterpret_cast<AggBuffer*> (buffer.ToPointer ()),
								reinterpret_cast<void*> (hdc.ToPointer ()), ox, oy, x1, y1, x2, y2);
		}
		
		static void Clear(System::IntPtr buffer)
		{
			AggBufferClear (reinterpret_cast<AggBuffer*> (buffer.ToPointer ()));
		}
		
		static void ClearRect(System::IntPtr buffer, int x1, int y1, int x2, int y2)
		{
			AggBufferClearRect (reinterpret_cast<AggBuffer*> (buffer.ToPointer ()),
								x1, y1, x2, y2);
		}
		
		static void GetMemoryLayout(System::IntPtr buffer, [Out] int __gc & width, [Out] int __gc & height, [Out] int __gc & stride, [Out] System::IntPtr & scan0)
		{
			int nwidth, nheight, nstride;
			void* nscan0;
			AggBufferGetMemoryLayout (reinterpret_cast<AggBuffer*> (buffer.ToPointer ()),
									  nwidth, nheight, nstride, nscan0);
			
			width  = nwidth;
			height = nheight;
			stride = nstride;
			scan0  = nscan0;
		}
		
		static System::IntPtr GetMemoryBitmapHandle(System::IntPtr buffer)
		{
			return System::IntPtr (AggBufferGetMemoryBitmapHandle (reinterpret_cast<AggBuffer*> (buffer.ToPointer ())));
		}
		
		static void BltBuffer(System::IntPtr buffer, int xd, int yd, System::IntPtr source, int xs, int ys, int dx, int dy)
		{
			AggBufferBltBuffer (reinterpret_cast<AggBuffer*> (buffer.ToPointer ()), xd, yd,
								reinterpret_cast<AggBuffer*> (source.ToPointer ()), xs, ys, dx, dy);
		}
		
		static void ComposeBuffer(System::IntPtr buffer, int xd, int yd, System::IntPtr source, int xs, int ys, int dx, int dy)
		{
			AggBufferComposeBuffer (reinterpret_cast<AggBuffer*> (buffer.ToPointer ()), xd, yd,
									reinterpret_cast<AggBuffer*> (source.ToPointer ()), xs, ys, dx, dy);
		}
		
		static void Delete(System::IntPtr buffer)
		{
			AggBufferDelete (reinterpret_cast<AggBuffer*> (buffer.ToPointer ()));
		}
	};
	
	__gc public class Renderer
	{
	public:
		__value enum MaskComponent
		{
			None = -1,
			A = 0,
			R = 1,
			G = 2,
			B = 3
		};
		
		__gc class Base
		{
		public:
		};
		
		__gc class Special : public Base
		{
		public:
			static void Fill4Colors(System::IntPtr renderer, int x, int y, int dx, int dy, double r1, double g1, double b1, double r2, double g2, double b2, double r3, double g3, double b3, double r4, double g4, double b4)
			{
				AggRendererFill4Colors (reinterpret_cast<AggRendererBase*> (renderer.ToPointer ()), x, y, dx, dy, r1, g1, b1, r2, g2, b2, r3, g3, b3, r4, g4, b4);
			}
		};
		
		__gc class Solid : public Base
		{
		public:
			static System::IntPtr New(System::IntPtr buffer)
			{
				return System::IntPtr ((void*) AggRendererSolidNew (reinterpret_cast<AggBuffer*> (buffer.ToPointer ())));
			}
			
			static void Clear(System::IntPtr renderer, double r, double g, double b, double a)
			{
				AggRendererSolidClear (reinterpret_cast<AggRendererSolid*> (renderer.ToPointer ()), r, g, b, a);
			}
			
			static void Color(System::IntPtr renderer, double r, double g, double b, double a)
			{
				AggRendererSolidColor (reinterpret_cast<AggRendererSolid*> (renderer.ToPointer ()), r, g, b, a);
			}
			
			static void Delete(System::IntPtr renderer)
			{
				AggRendererSolidDelete (reinterpret_cast<AggRendererSolid*> (renderer.ToPointer ()));
			}
			
			static void SetAlphaMask(System::IntPtr renderer, System::IntPtr buffer, MaskComponent component)
			{
				AggRendererSolidSetAlphaMask (reinterpret_cast<AggRendererSolid*> (renderer.ToPointer ()), reinterpret_cast<AggBuffer*> (buffer.ToPointer ()), component);
			}
		};
		__gc class Smooth : public Base
		{
		public:
			static System::IntPtr New(System::IntPtr buffer)
			{
				return System::IntPtr ((void*) AggRendererSmoothNew (reinterpret_cast<AggBuffer*> (buffer.ToPointer ())));
			}
			
			static void Color(System::IntPtr renderer, double r, double g, double b, double a)
			{
				AggRendererSmoothColor (reinterpret_cast<AggRendererSmooth*> (renderer.ToPointer ()), r, g, b, a);
			}
			
			static void Setup(System::IntPtr renderer, double r1, double r2, double xx, double xy, double yx, double yy, double tx, double ty)
			{
				AggRendererSmoothSetup (reinterpret_cast<AggRendererSmooth*> (renderer.ToPointer ()), r1, r2, xx, xy, yx, yy, tx, ty);
			}
			
			static void AddPath(System::IntPtr renderer, System::IntPtr path)
			{
				AggRendererSmoothAddPath (reinterpret_cast<AggRendererSmooth*> (renderer.ToPointer ()), reinterpret_cast<AggPath*> (path.ToPointer ()));
			}
			
			static void Delete(System::IntPtr renderer)
			{
				AggRendererSmoothDelete (reinterpret_cast<AggRendererSmooth*> (renderer.ToPointer ()));
			}
			
			static void SetAlphaMask(System::IntPtr renderer, System::IntPtr buffer, MaskComponent component)
			{
				AggRendererSmoothSetAlphaMask (reinterpret_cast<AggRendererSmooth*> (renderer.ToPointer ()), reinterpret_cast<AggBuffer*> (buffer.ToPointer ()), component);
			}
		};
		__gc class Image : public Base
		{
		public:
			static System::IntPtr New(System::IntPtr buffer)
			{
				return System::IntPtr ((void*) AggRendererImageNew (reinterpret_cast<AggBuffer*> (buffer.ToPointer ())));
			}
			
			static void Matrix(System::IntPtr renderer, double xx, double xy, double yx, double yy, double tx, double ty)
			{
				AggRendererImageMatrix (reinterpret_cast<AggRendererImage*> (renderer.ToPointer ()), xx, xy, yx, yy, tx, ty);
			}
			
			static void Source1(System::IntPtr renderer, System::IntPtr buffer)
			{
				AggRendererImageSource1 (reinterpret_cast<AggRendererImage*> (renderer.ToPointer ()),
										reinterpret_cast<AggBuffer*> (buffer.ToPointer ()));
			}
			
			static void Source2(System::IntPtr renderer, System::IntPtr byte_buffer, int dx, int dy, int stride)
			{
				AggRendererImageSource2 (reinterpret_cast<AggRendererImage*> (renderer.ToPointer ()),
										reinterpret_cast<void*> (byte_buffer.ToPointer ()), dx, dy, stride);
			}
			
			static void Delete(System::IntPtr renderer)
			{
				AggRendererImageDelete (reinterpret_cast<AggRendererImage*> (renderer.ToPointer ()));
			}
			
			static void SetAlphaMask(System::IntPtr renderer, System::IntPtr buffer, MaskComponent component)
			{
				AggRendererImageSetAlphaMask (reinterpret_cast<AggRendererImage*> (renderer.ToPointer ()), reinterpret_cast<AggBuffer*> (buffer.ToPointer ()), component);
			}
		};
		__gc class Gradient : public Base
		{
		public:
			static System::IntPtr New(System::IntPtr buffer)
			{
				return System::IntPtr ((void*) AggRendererGradientNew (reinterpret_cast<AggBuffer*> (buffer.ToPointer ())));
			}
			
			static void Delete(System::IntPtr renderer)
			{
				AggRendererGradientDelete (reinterpret_cast<AggRendererGradient*> (renderer.ToPointer ()));
			}
			
			static void Select(System::IntPtr renderer, int id)
			{
				AggRendererGradientSelect (reinterpret_cast<AggRendererGradient*> (renderer.ToPointer ()), id);
			}
			
			static void Color1(System::IntPtr renderer, double r __gc[], double g __gc[], double b __gc[], double a __gc[])
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
			
			static void Range(System::IntPtr renderer, double r1, double r2)
			{
				AggRendererGradientRange (reinterpret_cast<AggRendererGradient*> (renderer.ToPointer ()), r1, r2);
			}
			
			static void Matrix(System::IntPtr renderer, double xx, double xy, double yx, double yy, double tx, double ty)
			{
				AggRendererGradientMatrix (reinterpret_cast<AggRendererGradient*> (renderer.ToPointer ()), xx, xy, yx, yy, tx, ty);
			}
			
			static void SetAlphaMask(System::IntPtr renderer, System::IntPtr buffer, MaskComponent component)
			{
				AggRendererGradientSetAlphaMask (reinterpret_cast<AggRendererGradient*> (renderer.ToPointer ()), reinterpret_cast<AggBuffer*> (buffer.ToPointer ()), component);
			}
		};
	};
	
	__gc public class Rasterizer
	{
	public:
		static System::IntPtr New()
		{
			return System::IntPtr ((void*) AggRasterizerNew ());
		}
		
		static void Clear(System::IntPtr rasterizer)
		{
			AggRasterizerClear (reinterpret_cast<AggRasterizer*> (rasterizer.ToPointer ()));
		}
		
		static void FillingRule(System::IntPtr rasterizer, int mode)
		{
			AggRasterizerFillingRule (reinterpret_cast<AggRasterizer*> (rasterizer.ToPointer ()), mode);
		}
		
		static void Gamma(System::IntPtr rasterizer, double gamma)
		{
			AggRasterizerGamma (reinterpret_cast<AggRasterizer*> (rasterizer.ToPointer ()), gamma);
		}
		
		static void SetTransform(System::IntPtr rasterizer, double xx, double xy, double yx, double yy, double tx, double ty)
		{
			AggRasterizerSetTransform (reinterpret_cast<AggRasterizer*> (rasterizer.ToPointer ()), xx, xy, yx, yy, tx, ty);
		}
		
		static void SetClipBox(System::IntPtr rasterizer, double x1, double y1, double x2, double y2)
		{
			AggRasterizerSetClipBox (reinterpret_cast<AggRasterizer*> (rasterizer.ToPointer ()), x1, y1, x2, y2);
		}
		
		static void ResetClipBox(System::IntPtr rasterizer)
		{
			AggRasterizerResetClipBox (reinterpret_cast<AggRasterizer*> (rasterizer.ToPointer ()));
		}
		
		static void AddPath(System::IntPtr rasterizer, System::IntPtr path, bool curves)
		{
			AggRasterizerAddPath (reinterpret_cast<AggRasterizer*> (rasterizer.ToPointer ()),
								reinterpret_cast<AggPath*> (path.ToPointer ()), curves);
		}
		
		static void AddGlyph(System::IntPtr rasterizer, System::IntPtr face, int glyph, double x, double y, double scale)
		{
			AggRasterizerAddGlyph (reinterpret_cast<AggRasterizer*> (rasterizer.ToPointer ()),
								reinterpret_cast<agg::font_face*> (face.ToPointer ()),
								glyph, x, y, scale);
		}
		
		static void AddGlyphs(System::IntPtr rasterizer, System::IntPtr face, double scale, unsigned short glyphs __gc[], double x __gc[], double y __gc[], double sx __gc[])
		{
			unsigned short __pin * p_glyphs   = & glyphs[0];
			double __pin *         p_x        = & x[0];
			double __pin *         p_y        = & y[0];
			double __pin *         p_sx       = (sx == 0) ? 0 : & sx[0];
//			double __pin *         p_sy       = (sy == 0) ? 0 : & sy[0];
			
			int n = glyphs->get_Length ();
			
			AggRasterizer*  r = reinterpret_cast<AggRasterizer*> (rasterizer.ToPointer ());
			agg::font_face* f = reinterpret_cast<agg::font_face*> (face.ToPointer ());
			
			if (p_sx == 0)
			{
				for (int i = 0; i < n; i++)
				{
					AggRasterizerAddGlyphXY (r, f, p_glyphs[i], p_x[i], p_y[i], scale, scale);
				}
			}
			else
			{
				for (int i = 0; i < n; i++)
				{
					AggRasterizerAddGlyphXY (r, f, p_glyphs[i], p_x[i], p_y[i], p_sx[i] * scale, scale);
				}
			}
		}
		
		static double AddText(System::IntPtr rasterizer, System::IntPtr face, System::String* text, int mode, double xx, double xy, double yx, double yy, double tx, double ty)
		{
			System::Diagnostics::Debug::Assert (Internals::OffsetToStringData != 0);
			
			System::String __pin * pinned_text = text;
			const wchar_t*         native_text = (const wchar_t*)((char*)(*((void**)&pinned_text)) + Internals::OffsetToStringData);
			
			return AggRasterizerAddText(reinterpret_cast<AggRasterizer*> (rasterizer.ToPointer ()),
										reinterpret_cast<agg::font_face*> (face.ToPointer ()),
										native_text, mode, xx, xy, yx, yy, tx, ty);
		}
		
		static void AddPathStroke1(System::IntPtr rasterizer, System::IntPtr path, double width, bool curves)
		{
			AggRasterizerAddPathStroke1 (reinterpret_cast<AggRasterizer*> (rasterizer.ToPointer ()),
										reinterpret_cast<AggPath*> (path.ToPointer ()),
										width, curves);
		}
		
		static void AddPathStroke2(System::IntPtr rasterizer, System::IntPtr path, double width, int cap, int join, double miter_limit, bool curves)
		{
			AggRasterizerAddPathStroke2 (reinterpret_cast<AggRasterizer*> (rasterizer.ToPointer ()),
										reinterpret_cast<AggPath*> (path.ToPointer ()),
										width, cap, join, miter_limit, curves);
		}
		
		static void RenderSolid(System::IntPtr rasterizer, System::IntPtr renderer)
		{
			AggRasterizerRenderSolid (reinterpret_cast<AggRasterizer*> (rasterizer.ToPointer ()),
									reinterpret_cast<AggRendererSolid*> (renderer.ToPointer ()));
		}
		
		static void RenderImage(System::IntPtr rasterizer, System::IntPtr renderer)
		{
			AggRasterizerRenderImage (reinterpret_cast<AggRasterizer*> (rasterizer.ToPointer ()),
									reinterpret_cast<AggRendererImage*> (renderer.ToPointer ()));
		}
		
		static void RenderGradient(System::IntPtr rasterizer, System::IntPtr renderer)
		{
			AggRasterizerRenderGradient (reinterpret_cast<AggRasterizer*> (rasterizer.ToPointer ()),
										reinterpret_cast<AggRendererGradient*> (renderer.ToPointer ()));
		}
		
		static void Delete(System::IntPtr rasterizer)
		{
			AggRasterizerDelete (reinterpret_cast<AggRasterizer*> (rasterizer.ToPointer ()));
		}
	};

	
	__gc public class Path
	{
	public:
		static System::IntPtr New()
		{
			return System::IntPtr ((void*) AggPathNew ());
		}
		
		static void MoveTo(System::IntPtr path, double x, double y)
		{
			AggPathMoveTo (reinterpret_cast<AggPath*> (path.ToPointer ()), x, y);
		}
		
		static void LineTo(System::IntPtr path, double x, double y)
		{
			AggPathLineTo (reinterpret_cast<AggPath*> (path.ToPointer ()), x, y);
		}
		
		static void Curve3(System::IntPtr path, double x_c, double y_c, double x, double y)
		{
			AggPathCurve3 (reinterpret_cast<AggPath*> (path.ToPointer ()), x_c, y_c, x, y);
		}
		
		static void Curve4(System::IntPtr path, double x_c1, double y_c1, double x_c2, double y_c2, double x, double y)
		{
			AggPathCurve4 (reinterpret_cast<AggPath*> (path.ToPointer ()), x_c1, y_c1, x_c2, y_c2, x, y);
		}
		
		static void Close(System::IntPtr path)
		{
			AggPathClose (reinterpret_cast<AggPath*> (path.ToPointer ()));
		}
		
		static void AddNewPath(System::IntPtr path)
		{
			AggPathAddNewPath (reinterpret_cast<AggPath*> (path.ToPointer ()));
		}
		
		static void AppendGlyph(System::IntPtr path, System::IntPtr face, int glyph, double xx, double xy, double yx, double yy, double tx, double ty, double bold)
		{
			AggPathAppendGlyph (reinterpret_cast<AggPath*> (path.ToPointer ()),
								reinterpret_cast<agg::font_face*> (face.ToPointer ()),
								glyph, xx, xy, yx, yy, tx, ty, bold);
		}
		
		static void AppendPath(System::IntPtr path, System::IntPtr path2, double xx, double xy, double yx, double yy, double tx, double ty, double scale, double bold)
		{
			AggPathAppendPath (reinterpret_cast<AggPath*> (path.ToPointer ()),
							   reinterpret_cast<AggPath*> (path2.ToPointer ()),
							   xx, xy, yx, yy, tx, ty, scale, bold);
		}
		
		static void AppendPath(System::IntPtr path, System::IntPtr path2, double width, int cap, int join, double miter_limit, double scale, bool curved)
		{
			AggPathAppendPathStroke(reinterpret_cast<AggPath*> (path.ToPointer ()),
									reinterpret_cast<AggPath*> (path2.ToPointer ()),
									width, cap, join, miter_limit, scale, curved);
		}
		
		static void AppendArc(System::IntPtr path, double x, double y, double rx, double ry, double a1, double a2, bool ccw, double scale, bool continue_path)
		{
			AggPathAppendArc (reinterpret_cast<AggPath*> (path.ToPointer ()), x, y, rx, ry, a1, a2, ccw, scale, continue_path);
		}
		
		static void AppendDashedPath(System::IntPtr path, System::IntPtr dash, double scale)
		{
			AggPathAppendDashedPath (reinterpret_cast<AggPath*> (path.ToPointer ()), reinterpret_cast<AggPath*> (dash.ToPointer ()), scale);
		}
		
		static void CombinePathsUsingGpc(System::IntPtr path1, System::IntPtr path2, System::IntPtr result, int operation)
		{
			AggPathCombinePathsUsingGpc (reinterpret_cast<AggPath*> (path1.ToPointer ()),
										 reinterpret_cast<AggPath*> (path2.ToPointer ()),
										 reinterpret_cast<AggPath*> (result.ToPointer ()),
										 operation);
		}
		
		static void ComputeBounds(System::IntPtr path, [Out] double __gc & x1, [Out] double __gc & y1, [Out] double __gc & x2, [Out] double __gc & y2)
		{
			double nx1, ny1, nx2, ny2;
			
			AggPathComputeBounds (reinterpret_cast<AggPath*> (path.ToPointer ()),
								  nx1, ny1, nx2, ny2);
			
			x1 = nx1;
			y1 = ny1;
			x2 = nx2;
			y2 = ny2;
		}
		
		static void RemoveAll(System::IntPtr path)
		{
			AggPathRemoveAll (reinterpret_cast<AggPath*> (path.ToPointer ()));
		}
		
		static int ElemCount(System::IntPtr path)
		{
			return AggPathElemCount (reinterpret_cast<AggPath*> (path.ToPointer ()));
		}
		
		static void ElemGet(System::IntPtr path, int n, int types __gc[], double x __gc[], double y __gc[])
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
		
		static void Delete(System::IntPtr path)
		{
			AggPathDelete (reinterpret_cast<AggPath*> (path.ToPointer ()));
		}
		
		static void ResetDash(System::IntPtr path)
		{
			AggPathDashReset (reinterpret_cast<AggPath*> (path.ToPointer ()));
		}
		
		static void AddDash(System::IntPtr path, double dash_length, double gap_length)
		{
			AggPathDashAdd (reinterpret_cast<AggPath*> (path.ToPointer ()), dash_length, gap_length);
		}
		
		static void SetDashOffset(System::IntPtr path, double start)
		{
			AggPathDashSetStart (reinterpret_cast<AggPath*> (path.ToPointer ()), start);
		}
	};
	
	__gc public class Font
	{
	public:
		static void Initialise()
		{
			AggFontInitialise ();
		}
		
		static int GetFaceCount()
		{
			return AggFontGetFaceCount ();
		}
		
		static System::IntPtr GetFaceByRank(int n)
		{
			return System::IntPtr ((void*) AggFontGetFaceByRank (n));
		}
		
		static System::IntPtr GetFaceByName(System::String* family, System::String* style, System::String* optical)
		{
			System::Diagnostics::Debug::Assert (Internals::OffsetToStringData != 0);
			
			System::String __pin * pinned_family  = family;
			System::String __pin * pinned_style   = style;
			System::String __pin * pinned_optical = optical;
			
			const wchar_t* native_family  = (const wchar_t*)((char*)(*((void**)&pinned_family )) + Internals::OffsetToStringData);
			const wchar_t* native_style   = (const wchar_t*)((char*)(*((void**)&pinned_style  )) + Internals::OffsetToStringData);
			const wchar_t* native_optical = (const wchar_t*)((char*)(*((void**)&pinned_optical)) + Internals::OffsetToStringData);
			
			return System::IntPtr ((void*) AggFontGetFaceByName (native_family, native_style, native_optical));
		}
		
		__gc class Face
		{
		public:
			static System::String* GetName(System::IntPtr face, int id)
			{
				const wchar_t* name = AggFontFaceGetName (reinterpret_cast<agg::font_face*> (face.ToPointer ()), id);
				return __gc new System::String (name);
			}
			
			static System::IntPtr GetOsHandle(System::IntPtr face)
			{
				return System::IntPtr (AggFontFaceGetOsHandle (reinterpret_cast<agg::font_face*> (face.ToPointer ())));
			}
			
			static double GetCaretSlope(System::IntPtr face)
			{
				return AggFontFaceGetCaretSlope (reinterpret_cast<agg::font_face*> (face.ToPointer ()));
			}
			
			static int GetGlyphIndex(System::IntPtr face, int unicode)
			{
				return AggFontFaceGetGlyphIndex (reinterpret_cast<agg::font_face*> (face.ToPointer ()), unicode);
			}
			
			static double GetGlyphAdvance(System::IntPtr face, int glyph)
			{
				return AggFontFaceGetGlyphAdvance (reinterpret_cast<agg::font_face*> (face.ToPointer ()), glyph);
			}
			
			static double GetCharAdvance(System::IntPtr face, int unicode)
			{
				return AggFontFaceGetCharAdvance (reinterpret_cast<agg::font_face*> (face.ToPointer ()), unicode);
			}
			
			static double GetTextAdvance(System::IntPtr face, System::String* text, int mode)
			{
				System::Diagnostics::Debug::Assert (Internals::OffsetToStringData != 0);
				
				System::String __pin * pinned_text = text;
				const wchar_t*         native_text = (const wchar_t*)((char*)(*((void**)&pinned_text)) + Internals::OffsetToStringData);
				
				return AggFontFaceGetTextAdvance (reinterpret_cast<agg::font_face*> (face.ToPointer ()), native_text, mode);
			}
			
			static void GetGlyphBounds (System::IntPtr face, int glyph, [Out] double __gc & x_min, [Out] double __gc & y_min, [Out] double __gc & x_max, [Out] double __gc & y_max)
			{
				double nx_min, ny_min, nx_max, ny_max;
				
				AggFontFaceGetGlyphBounds (reinterpret_cast<agg::font_face*> (face.ToPointer ()), glyph, nx_min, ny_min, nx_max, ny_max);
				
				x_min = nx_min;
				y_min = ny_min;
				x_max = nx_max;
				y_max = ny_max;
			}
			
			static void GetCharBounds (System::IntPtr face, int unicode, [Out] double __gc & x_min, [Out] double __gc & y_min, [Out] double __gc & x_max, [Out] double __gc & y_max)
			{
				double nx_min, ny_min, nx_max, ny_max;
				
				AggFontFaceGetCharBounds (reinterpret_cast<agg::font_face*> (face.ToPointer ()), unicode, nx_min, ny_min, nx_max, ny_max);
				
				x_min = nx_min;
				y_min = ny_min;
				x_max = nx_max;
				y_max = ny_max;
			}
			
			static void GetTextBounds (System::IntPtr face, System::String* text, int mode, [Out] double __gc & x_min, [Out] double __gc & y_min, [Out] double __gc & x_max, [Out] double __gc & y_max)
			{
				System::Diagnostics::Debug::Assert (Internals::OffsetToStringData != 0);
				
				System::String __pin * pinned_text = text;
				const wchar_t*         native_text = (const wchar_t*)((char*)(*((void**)&pinned_text)) + Internals::OffsetToStringData);
				
				double nx_min, ny_min, nx_max, ny_max;
				
				AggFontFaceGetTextBounds (reinterpret_cast<agg::font_face*> (face.ToPointer ()), native_text, mode, nx_min, ny_min, nx_max, ny_max);
				
				x_min = nx_min;
				y_min = ny_min;
				x_max = nx_max;
				y_max = ny_max;
			}
			
			static double GetMetrics(System::IntPtr face, int id)
			{
				return AggFontFaceGetMetrics (reinterpret_cast<agg::font_face*> (face.ToPointer ()), id);
			}
			
			static int GetTextCharEndXArray(System::IntPtr face, System::String* text, int mode, double x_array __gc[])
			{
				System::Diagnostics::Debug::Assert (Internals::OffsetToStringData != 0);
				
				int n = text == 0 ? 0 : text->get_Length ();
				
				if (n == 0)
				{
					return 0;
				}
				
				System::String __pin * pinned_text = text;
				const wchar_t*         native_text = (const wchar_t*)((char*)(*((void**)&pinned_text)) + Internals::OffsetToStringData);
				
				double* x_copy  = reinterpret_cast<double*> (_alloca (sizeof (double)*n));
				
				AggFontFaceGetTextCharEndXArray (reinterpret_cast<agg::font_face*> (face.ToPointer ()), native_text, mode, x_copy);
				
				System::Runtime::InteropServices::Marshal::Copy (x_copy, x_array, 0, n);
				
				return n;
			}
		};
		__gc class Break
		{
		public:
			static System::IntPtr New(System::IntPtr face, System::String* text, int mode)
			{
				System::Diagnostics::Debug::Assert (Internals::OffsetToStringData != 0);
				
				System::String __pin * pinned_text = text;
				const wchar_t*         native_text = (const wchar_t*)((char*)(*((void**)&pinned_text)) + Internals::OffsetToStringData);
				
				return System::IntPtr ((void*) AggFontFaceBreakNew (reinterpret_cast<agg::font_face*> (face.ToPointer ()), native_text, static_cast<TextBreakMode> (mode)));
			}
			
			static System::String* Iter(System::IntPtr context, [In][Out] double __gc & width, [Out] int __gc & n_char)
			{
				double nwidth = width;
				int nn_char;
				
				const wchar_t* text = AggFontFaceBreakIter (reinterpret_cast<BreakContext*> (context.ToPointer ()), nwidth, nn_char);
				
				width  = nwidth;
				n_char = nn_char;
				
				if (text == 0)
				{
					return 0;
				}
				
				return __gc new System::String (text);
			}
			
			static void Delete(System::IntPtr context)
			{
				AggFontFaceBreakDelete (reinterpret_cast<BreakContext*> (context.ToPointer ()));
			}
			
			static bool HasMore(System::IntPtr context)
			{
				return AggFontFaceBreakHasMore (reinterpret_cast<BreakContext*> (context.ToPointer ()));
			}
		};
		__gc class PixelCache
		{
		public:
			static double Paint(System::IntPtr buffer, System::IntPtr face, System::String* text, double scale, double ox, double oy, double r, double g, double b, double a)
			{
				System::Diagnostics::Debug::Assert (Internals::OffsetToStringData != 0);
				
				System::String __pin * pinned_text = text;
				const wchar_t*         native_text = (const wchar_t*)((char*)(*((void**)&pinned_text)) + Internals::OffsetToStringData);
				
				return AggFontPixelCacheFill (reinterpret_cast<AggBuffer*> (buffer.ToPointer ()), reinterpret_cast<agg::font_face*> (face.ToPointer ()), native_text, scale, ox, oy, r, g, b, a);
			}
			
			static void Fill(System::IntPtr face, System::String* text, double scale, double ox, double oy)
			{
				System::Diagnostics::Debug::Assert (Internals::OffsetToStringData != 0);
				
				System::String __pin * pinned_text = text;
				const wchar_t*         native_text = (const wchar_t*)((char*)(*((void**)&pinned_text)) + Internals::OffsetToStringData);
				
				AggFontPixelCacheFill (0, reinterpret_cast<agg::font_face*> (face.ToPointer ()), native_text, scale, ox, oy, 0, 0, 0, 0);
			}
		};
	};
	__gc public class TextBreak
	{
	public:
		static void InitialiseLineBreakInformation(System::Byte data[], int length)
		{
			System::Byte __pin * ptr_data = &data[0];
			const char* ptr_native = reinterpret_cast<char*> (ptr_data);
			AggTextBreakInitialiseLineBreak (ptr_native, length);
		}
		
		static System::IntPtr New()
		{
			return System::IntPtr ((void*) AggTextBreakNew ());
		}
		
		static bool SetText(System::IntPtr text_break, System::String* text, int mode)
		{
			System::Diagnostics::Debug::Assert (Internals::OffsetToStringData != 0);
			
			System::String __pin * pinned_text = text;
			const wchar_t*         native_text = (const wchar_t*)((char*)(*((void**)&pinned_text)) + Internals::OffsetToStringData);
			
			return AggTextBreakSetText (reinterpret_cast<agg::text_break*> (text_break.ToPointer ()), native_text, mode);
		}

		
		static void SetFontFaceCount(System::IntPtr text_break, int n)
		{
			AggTextBreakSetFontFaceCount(reinterpret_cast<agg::text_break*> (text_break.ToPointer ()), n);
		}
		
		static void SetNthFontFace(System::IntPtr text_break, int nth, System::IntPtr face)
		{
			AggTextBreakSetNthFontFace(reinterpret_cast<agg::text_break*> (text_break.ToPointer ()), nth, reinterpret_cast<agg::font_face*> (face.ToPointer ()));
		}
		
		static void SetRunCount(System::IntPtr text_break, int n)
		{
			AggTextBreakSetRunCount(reinterpret_cast<agg::text_break*> (text_break.ToPointer ()), n);
		}
		
		static void SetNthRun(System::IntPtr text_break, int nth, int run_length, int face_index, double scale)
		{
			AggTextBreakSetNthRun(reinterpret_cast<agg::text_break*> (text_break.ToPointer ()), nth, run_length, face_index, scale);
		}
		
		
		static void Rewind(System::IntPtr text_break)
		{
			AggTextBreakRewind (reinterpret_cast<agg::text_break*> (text_break.ToPointer ()));
		}
		
		static System::String* FindNextBreak(System::IntPtr text_break, [In][Out] double __gc & width, [Out] int __gc & n_char)
		{
			double nwidth = width;
			int nn_char;
			
			const wchar_t* text = AggTextBreakFindNextBreak (reinterpret_cast<agg::text_break*> (text_break.ToPointer ()), nwidth, nn_char);
			
			width  = nwidth;
			n_char = nn_char;
			
			if (text == 0)
			{
				return 0;
			}
			
			return __gc new System::String (text);
		}
		
		static void Hyphenate(System::IntPtr text_break)
		{
			AggTextBreakHyphenate (reinterpret_cast<agg::text_break*> (text_break.ToPointer ()));
		}
		
		static int HyphenateWord(System::String* text, int text_length, short breaks __gc[])
		{
			System::String __pin * pinned_text = text;
			const wchar_t*         native_text = (const wchar_t*)((char*)(*((void**)&pinned_text)) + Internals::OffsetToStringData);
			int                    breaks_len  = breaks->Count;
			short __pin *          breaks_ptr = & breaks[0];
			
			return AggTextBreakHyphenateWord (native_text, text_length, breaks_ptr, breaks_len);
		}
		
		static void Delete(System::IntPtr text_break)
		{
			AggTextBreakDelete (reinterpret_cast<agg::text_break*> (text_break.ToPointer ()));
		}
//		
//		static bool HasMore(System::IntPtr text_break)
//		{
//			return AggTextBreakHasMore (reinterpret_cast<agg::text_break*> (text_break.ToPointer ()));
//		}
		
		static System::String* GetUnicodeName(int code)
		{
			wchar_t max_path_buffer[260];
			
			if (AggFontGetUnicodeName (code, max_path_buffer))
			{
				return __gc new System::String (max_path_buffer);
			}
			
			return 0;
		}
	};
}
