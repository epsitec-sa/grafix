using System;
using System.Runtime.InteropServices;

namespace AntiGrain
{
	public class Rasterizer
	{
		[DllImport ("AntiGrain.Win32.dll", EntryPoint="AggRasterizerNew", CharSet=CharSet.Unicode)]
		public extern static System.IntPtr New();
		
		[DllImport ("AntiGrain.Win32.dll", EntryPoint="AggRasterizerClear", CharSet=CharSet.Unicode)]
		public extern static void Clear(System.IntPtr rasterizer);
		
		[DllImport ("AntiGrain.Win32.dll", EntryPoint="AggRasterizerFillingRule", CharSet=CharSet.Unicode)]
		public extern static void FillingRule(System.IntPtr rasterizer, int mode);
		
		[DllImport ("AntiGrain.Win32.dll", EntryPoint="AggRasterizerGamma", CharSet=CharSet.Unicode)]
		public extern static void Gamma(System.IntPtr rasterizer, double gamma);
		
		[DllImport ("AntiGrain.Win32.dll", EntryPoint="AggRasterizerSetTransform", CharSet=CharSet.Unicode)]
		public extern static void SetTransform(System.IntPtr rasterizer, double xx, double xy, double yx, double yy, double tx, double ty);
		
		[DllImport ("AntiGrain.Win32.dll", EntryPoint="AggRasterizerSetClipBox", CharSet=CharSet.Unicode)]
		public extern static void SetClipBox(System.IntPtr rasterizer, double x1, double y1, double x2, double y2);
		
		[DllImport ("AntiGrain.Win32.dll", EntryPoint="AggRasterizerResetClipBox", CharSet=CharSet.Unicode)]
		public extern static void ResetClipBox(System.IntPtr rasterizer);
		
		[DllImport ("AntiGrain.Win32.dll", EntryPoint="AggRasterizerAddPath", CharSet=CharSet.Unicode)]
		public extern static void AddPath(System.IntPtr rasterizer, System.IntPtr path, bool curves);
		
		[DllImport ("AntiGrain.Win32.dll", EntryPoint="AggRasterizerAddGlyph", CharSet=CharSet.Unicode)]
		public extern static void AddGlyph(System.IntPtr rasterizer, System.IntPtr font, int glyph, double x, double y, double scale);
		
		[DllImport ("AntiGrain.Win32.dll", EntryPoint="AggRasterizerAddText", CharSet=CharSet.Unicode)]
		public extern static double AddText(System.IntPtr rasterizer, System.IntPtr font, string text, int mode, double xx, double xy, double yx, double yy, double tx, double ty);
		
		[DllImport ("AntiGrain.Win32.dll", EntryPoint="AggRasterizerAddPathStroke1", CharSet=CharSet.Unicode)]
		public extern static void AddPathStroke1(System.IntPtr rasterizer, System.IntPtr path, double width, bool curves);
		
		[DllImport ("AntiGrain.Win32.dll", EntryPoint="AggRasterizerAddPathStroke2", CharSet=CharSet.Unicode)]
		public extern static void AddPathStroke2(System.IntPtr rasterizer, System.IntPtr path, double width, int cap, int join, double miter_limit, bool curves);
		
		[DllImport ("AntiGrain.Win32.dll", EntryPoint="AggRasterizerRenderSolid", CharSet=CharSet.Unicode)]
		public extern static void RenderSolid(System.IntPtr rasterizer, System.IntPtr renderer);
		
		[DllImport ("AntiGrain.Win32.dll", EntryPoint="AggRasterizerRenderImage", CharSet=CharSet.Unicode)]
		public extern static void RenderImage(System.IntPtr rasterizer, System.IntPtr renderer);
		
		[DllImport ("AntiGrain.Win32.dll", EntryPoint="AggRasterizerRenderGradient", CharSet=CharSet.Unicode)]
		public extern static void RenderGradient(System.IntPtr rasterizer, System.IntPtr renderer);
		
		[DllImport ("AntiGrain.Win32.dll", EntryPoint="AggRasterizerDelete", CharSet=CharSet.Unicode)]
		public extern static void Delete(System.IntPtr rasterizer);
	}
}
