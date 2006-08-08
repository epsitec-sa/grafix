using System;
using AntiGrain;

namespace TestAGG
{
	/// <summary>
	/// Summary description for Class1.
	/// </summary>
	class Class1
	{
		/// <summary>
		/// The main entry point for the application.
		/// </summary>
		[STAThread]
		static void Main(string[] args)
		{
			System.Console.Out.WriteLine ("Trying to load DLL");
			AntiGrain.Interface.Initialise ();
			System.Console.Out.WriteLine ("Initialised successfully");
		}
	}
}
