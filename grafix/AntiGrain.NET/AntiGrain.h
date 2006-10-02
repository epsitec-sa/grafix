//	AntiGrain.h
//
//	Copyright © 2003-2006, Pierre ARNAUD, OPaC bright ideas, Ch. du Fontenay 6,
//	                       CH-1400 YVERDON, Switzerland. All rights reserved. 
//
//	Contact: pierre.arnaud@opac.ch, http://www.opac.ch
//	License: see license.txt

#pragma once

using namespace System::Runtime::InteropServices;

namespace AntiGrain
{
	private ref class Internals
	{
	public:
		static int OffsetToStringData = 0;
	};
	
	public ref class Interface
	{
	public:
		static bool Initialise()
		{
			Internals::OffsetToStringData = System::Runtime::CompilerServices::RuntimeHelpers::OffsetToStringData;
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
		
		static void NoOpString(const System::String^ text)
		{
			cli::pin_ptr<const System::String^> pinned_text = &text;
			const wchar_t* native_text = (const wchar_t*)((char*)(*(*((void***)&pinned_text))) + Internals::OffsetToStringData);
			
			AggNoOpString (native_text);
		}
		
		static System::String^ GetVersion()
		{
			return gcnew System::String (AggGetVersion ());
		}
		
		static System::String^ GetProductName()
		{
			return gcnew System::String (AggGetProductName ());
		}
	};
	
	public ref class Buffer
	{
	public:
		static System::IntPtr New(int dx, int dy, int bpp)
		{
			return System::IntPtr ((void*) AggBufferNew (dx, dy, bpp));
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
		
		static void DrawGlyphs(System::IntPtr buffer, System::IntPtr hfont, int x, int y, cli::array<unsigned short>^ glyphs, cli::array<int>^ dx_array, int count, unsigned int color)
		{
			cli::pin_ptr<unsigned short> p_glyphs   = & glyphs[0];
			cli::pin_ptr<int>            p_dx_array = (dx_array == nullptr) ? nullptr : & dx_array[0];
			
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
		
		static System::IntPtr GetMemoryLayout(System::IntPtr buffer, [Out] int% width, [Out] int% height, [Out] int% stride)
		{
			int nwidth, nheight, nstride;
			void* nscan0;
			AggBufferGetMemoryLayout (reinterpret_cast<AggBuffer*> (buffer.ToPointer ()),
									  nwidth, nheight, nstride, nscan0);
			
			width  = nwidth;
			height = nheight;
			stride = nstride;
			
			return System::IntPtr (nscan0);
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

	public ref class Renderer
	{
	public:
		enum class MaskComponent
		{
			None = -1,
			A = 0,
			R = 1,
			G = 2,
			B = 3
		};
		
		ref class Base
		{
		public:
		};
		
		ref class Special : public Base
		{
		public:
			static void Fill4Colors(System::IntPtr renderer, int x, int y, int dx, int dy, double r1, double g1, double b1, double r2, double g2, double b2, double r3, double g3, double b3, double r4, double g4, double b4)
			{
				AggRendererFill4Colors (reinterpret_cast<AggRendererBase*> (renderer.ToPointer ()), x, y, dx, dy, r1, g1, b1, r2, g2, b2, r3, g3, b3, r4, g4, b4);
			}
		};
		
		ref class Solid : public Base
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
				AggRendererSolidSetAlphaMask (reinterpret_cast<AggRendererSolid*> (renderer.ToPointer ()), reinterpret_cast<AggBuffer*> (buffer.ToPointer ()), (int) component);
			}
		};
		ref class Smooth : public Base
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
				AggRendererSmoothSetAlphaMask (reinterpret_cast<AggRendererSmooth*> (renderer.ToPointer ()), reinterpret_cast<AggBuffer*> (buffer.ToPointer ()), (int) component);
			}
		};
		ref class Image : public Base
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
			
			static void SetStretchMode(System::IntPtr renderer, int mode, double radius)
			{
				AggRendererImageSetStretchMode (reinterpret_cast<AggRendererImage*> (renderer.ToPointer ()), mode, radius);
			}
			
			static void SetAlphaMask(System::IntPtr renderer, System::IntPtr buffer, MaskComponent component)
			{
				AggRendererImageSetAlphaMask (reinterpret_cast<AggRendererImage*> (renderer.ToPointer ()), reinterpret_cast<AggBuffer*> (buffer.ToPointer ()), (int) component);
			}
		};
		ref class Gradient : public Base
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
			
			static void Color1(System::IntPtr renderer, cli::array<double>^ r, cli::array<double>^ g, cli::array<double>^ b, cli::array<double>^ a)
			{
				double rr[256];
				double gg[256];
				double bb[256];
				double aa[256];

				System::Runtime::InteropServices::Marshal::Copy (r, 0, System::IntPtr (rr), 256);
				System::Runtime::InteropServices::Marshal::Copy (g, 0, System::IntPtr (gg), 256);
				System::Runtime::InteropServices::Marshal::Copy (b, 0, System::IntPtr (bb), 256);
				System::Runtime::InteropServices::Marshal::Copy (a, 0, System::IntPtr (aa), 256);
				
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
				AggRendererGradientSetAlphaMask (reinterpret_cast<AggRendererGradient*> (renderer.ToPointer ()), reinterpret_cast<AggBuffer*> (buffer.ToPointer ()), (int) component);
			}
		};
	};
	
	public ref class Rasterizer
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
		
		static bool HitTest(System::IntPtr rasterizer, int x, int y)
		{
			return AggRasterizerHitTest (reinterpret_cast<AggRasterizer*> (rasterizer.ToPointer ()), x, y);
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
		
		static void AddGlyphs(System::IntPtr rasterizer, System::IntPtr face, double scale, cli::array<unsigned short>^ glyphs, cli::array<double>^ x, cli::array<double>^ y, cli::array<double>^ sx)
		{
			cli::pin_ptr<unsigned short> p_glyphs = & glyphs[0];
			cli::pin_ptr<double> p_x  = & x[0];
			cli::pin_ptr<double> p_y  = (y == nullptr) ? nullptr : & y[0];
			cli::pin_ptr<double> p_sx = (sx == nullptr) ? nullptr : & sx[0];
			
			int n = glyphs->Length;
			
			AggRasterizer*  r = reinterpret_cast<AggRasterizer*> (rasterizer.ToPointer ());
			agg::font_face* f = reinterpret_cast<agg::font_face*> (face.ToPointer ());
			
			if (p_y == nullptr)
			{
				if (p_sx == nullptr)
				{
					for (int i = 0; i < n; i++)
					{
						AggRasterizerAddGlyphXY (r, f, p_glyphs[i], p_x[i], 0, scale, scale);
					}
				}
				else
				{
					for (int i = 0; i < n; i++)
					{
						AggRasterizerAddGlyphXY (r, f, p_glyphs[i], p_x[i], 0, p_sx[i] * scale, scale);
					}
				}
			}
			else
			{
				if (p_sx == nullptr)
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

	
	public ref class Path
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
		
		static void ComputeBounds(System::IntPtr path, [Out] double% x1, [Out] double% y1, [Out] double% x2, [Out] double% y2)
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
		
		static void ElemGet(System::IntPtr path, int n, cli::array<int>^ types, cli::array<double>^ x, cli::array<double>^ y)
		{
			if (n > 0)
			{
				int* types_copy = reinterpret_cast<int*> (_alloca (sizeof (int)*n));
				double* x_copy  = reinterpret_cast<double*> (_alloca (sizeof (double)*n));
				double* y_copy  = reinterpret_cast<double*> (_alloca (sizeof (double)*n));
				
				AggPathElemGet (reinterpret_cast<AggPath*> (path.ToPointer ()),
								n, types_copy, x_copy, y_copy);
				
				System::Runtime::InteropServices::Marshal::Copy (System::IntPtr (types_copy), types, 0, n);
				System::Runtime::InteropServices::Marshal::Copy (System::IntPtr (x_copy), x, 0, n);
				System::Runtime::InteropServices::Marshal::Copy (System::IntPtr (y_copy), y, 0, n);
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
	
	public ref class Font
	{
	public:
		static System::IntPtr CreateFaceHandle(cli::array<unsigned char>^ data, int size, int offset, System::IntPtr handle)
		{
			cli::pin_ptr<unsigned char> p_data = & data[0];
			return System::IntPtr (AggFontCreateFaceFromFontData (p_data, size, offset, handle.ToPointer ()));
		}
		
		static void DisposeFaceHandle(System::IntPtr face)
		{
			AggFontDisposeFace (reinterpret_cast<agg::font_face*> (face.ToPointer ()));
		}
		
		static System::String^ GetUnicodeName(int code)
		{
			wchar_t max_path_buffer[260];
			
			if (AggFontGetUnicodeName (code, max_path_buffer))
			{
				return gcnew System::String (max_path_buffer);
			}
			
			return nullptr;
		}
		
		ref class PixelCache
		{
		public:
			static double Paint(System::IntPtr buffer, System::IntPtr face, cli::array<unsigned short>^ glyphs, double scale, double ox, double oy, double r, double g, double b, double a)
			{
				cli::pin_ptr<unsigned short> p_glyphs   = & glyphs[0];
				int length = glyphs->Length;
				
				return AggFontPixelCacheFill (reinterpret_cast<AggBuffer*> (buffer.ToPointer ()), reinterpret_cast<agg::font_face*> (face.ToPointer ()), p_glyphs, length, scale, ox, oy, r, g, b, a);
			}
			
			static void Fill(System::IntPtr face, cli::array<unsigned short>^ glyphs, double scale, double ox, double oy)
			{
				cli::pin_ptr<unsigned short> p_glyphs   = & glyphs[0];
				int length = glyphs->Length;

				AggFontPixelCacheFill (0, reinterpret_cast<agg::font_face*> (face.ToPointer ()), p_glyphs, length, scale, ox, oy, 0, 0, 0, 0);
			}
		};
	};
}
