using System;
using System.Runtime.InteropServices;

namespace AntiGrain
{
	public class Renderer
	{
		public class Base
		{
		}
		public class Solid : Base
		{
			[DllImport ("AntiGrain.Win32.dll", EntryPoint="AggRendererSolidNew", CharSet=CharSet.Unicode)]
			public extern static System.IntPtr New(System.IntPtr buffer);
			
			[DllImport ("AntiGrain.Win32.dll", EntryPoint="AggRendererSolidClear", CharSet=CharSet.Unicode)]
			public extern static void Clear(System.IntPtr renderer, double r, double g, double b, double a);
			
			[DllImport ("AntiGrain.Win32.dll", EntryPoint="AggRendererSolidColor", CharSet=CharSet.Unicode)]
			public extern static void Color(System.IntPtr renderer, double r, double g, double b, double a);
			
			[DllImport ("AntiGrain.Win32.dll", EntryPoint="AggRendererSolidDelete", CharSet=CharSet.Unicode)]
			public extern static void Delete(System.IntPtr renderer);
		}
		public class Image : Base
		{
		}
		public class Gradient : Base
		{
		}
	}
}
