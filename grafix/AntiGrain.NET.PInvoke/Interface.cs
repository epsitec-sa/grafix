using System;
using System.Runtime.InteropServices;

namespace AntiGrain
{
	public class Interface
	{
		[DllImport ("AntiGrain.Win32.dll", EntryPoint="AggInitialise", CharSet=CharSet.Unicode)]
		public extern static bool Initialise();
		
		[DllImport ("AntiGrain.Win32.dll", EntryPoint="AggShutDown", CharSet=CharSet.Unicode)]
		public extern static void ShutDown();
		
		[DllImport ("AntiGrain.Win32.dll", EntryPoint="AggNoOp", CharSet=CharSet.Unicode)]
		public extern static void NoOp();
		
		[DllImport ("AntiGrain.Win32.dll", EntryPoint="AggNoOpString", CharSet=CharSet.Unicode)]
		public extern static void NoOpString(string text);
		
		[DllImport ("AntiGrain.Win32.dll", EntryPoint="AggGetVersion", CharSet=CharSet.Unicode)]
		public extern static string GetVersion();
		
		[DllImport ("AntiGrain.Win32.dll", EntryPoint="AggGetProductName", CharSet=CharSet.Unicode)]
		public extern static string GetProductName();
		
		public static long DebugGetCycles()
		{
			return 0;
		}
		
		[DllImport ("AntiGrain.Win32.dll", EntryPoint="AggDebugGetCycleDelta", CharSet=CharSet.Unicode)]
		public extern static int DebugGetCycleDelta();
	}
}
