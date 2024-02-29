using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

namespace AntiGrain
{
    public static partial class Interface
    {
        [DllImport("AntiGrain.Win32", CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        [return: MarshalAs(UnmanagedType.U1)]
        internal static extern bool AggInitialise();

        [DllImport("AntiGrain.Win32", CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        internal static extern void AggShutDown();

        [DllImport("AntiGrain.Win32", CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        internal static extern void AggNoOp();

        [DllImport("AntiGrain.Win32", CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        internal static extern void AggNoOpString(string text);

        [DllImport("AntiGrain.Win32", CallingConvention = CallingConvention.Cdecl, SetLastError = true, CharSet = CharSet.Unicode)]
        internal static extern string AggGetVersion();

        [DllImport("AntiGrain.Win32", CallingConvention = CallingConvention.Cdecl, SetLastError = true, CharSet = CharSet.Unicode)]
        internal static extern string AggGetProductName();

    }
}
namespace AntiGrain
{
    public static partial class Interface
    {
        public static bool   Initialise()
        {
            Internals.OffsetToStringData = RuntimeHelpers.OffsetToStringData;
            return AggInitialise();
        }
        public static void   ShutDown()
        {
            AggShutDown();
        }
        public static void   NoOp()
        {
            AggNoOp();
        }
        public static void   NoOpString(string text)
        {
            AggNoOpString(text.Substring(Internals.OffsetToStringData));
        }
        public static string GetVersion()
        {
            return AggGetVersion();
        }
        public static string GetProductName()
        {
            return AggGetProductName();
        }
    }
}
