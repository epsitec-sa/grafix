// Copyright © 2003-2024, EPSITEC SA, CH-1400 Yverdon-les-Bains, Switzerland
// Author: Pierre ARNAUD, Roger VUISTINER, Maintainer: Roger VUISTINER

using System.Runtime.CompilerServices;

using static AntiGrain.Native;

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
    }
}
