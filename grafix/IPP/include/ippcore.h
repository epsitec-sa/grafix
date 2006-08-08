/* ////////////////////////////////// "ippcore.h" //////////////////////////////
//
//                  INTEL CORPORATION PROPRIETARY INFORMATION
//     This software is supplied under the terms of a license agreement or
//     nondisclosure agreement with Intel Corporation and may not be copied
//     or disclosed except in accordance with the terms of that agreement.
//          Copyright(c) 2001-2003 Intel Corporation. All Rights Reserved.
//
//           	Intel(R) Integrated Performance Primitives
//                  Core Library (ippcore)
//
*/

#if !defined( __IPPCORE_H__ ) || defined( _OWN_BLDPCS )
#define __IPPCORE_H__

#ifndef __IPPDEFS_H__
  #include "ippdefs.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif


/* /////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//                   Functions declarations
////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippGetLibVersion
//  Purpose:    getting of the library version
//  Returns:    the structure of information about version
//              of ippcore library
//  Parameters:
//
//  Notes:      not necessary to release the returned structure
*/
IPPAPI( const IppLibraryVersion*, ippGetLibVersion, (void) )


/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippCoreGetStatusString
//  Purpose:    convert the library status code to a readable string
//  Parameters:
//    StsCode   IPP status code
//  Returns:    pointer to string describing the library status code
//
//  Notes:      don't free the pointer
*/
IPPAPI( const char*, ippCoreGetStatusString, ( IppStatus StsCode ) )


/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippCoreGetCpuType
//  Purpose:    detects Intel's CPU
//  Parameter:  none
//  Return:     IppCpuType
//
*/

IPPAPI( IppCpuType, ippCoreGetCpuType, (void) )

/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippCoreGetCpuClocks
//  Purpose:    reading of time stamp counter (TSC) register value
//  Returns:    TSC value
//
//  Note:      An hardware exception is possible if TSC reading is not supported by
/              the current chipset
*/

IPPAPI( Ipp64u, ippCoreGetCpuClocks, (void) )


/* ///////////////////////////////////////////////////////////////////////////
//  Names:  ippCoreSetFlushToZero,
//          ippCoreSetDenormAreZero.
//
//  Purpose: ippCoreSetFlushToZero enables or disables the flush-to-zero mode,
//           ippCoreSetDenormAreZero enables or disables the denormals-are-zeros
//           mode.
//
//  Arguments:
//     value       - !0 or 0 - set or clear the corresponding bit of MXCSR
//     pUMask      - pointer to user store current underflow exception mask
//                   ( may be NULL if don't want to store )
//
//  Return:
//   ippStsNoErr              - Ok
//   ippStsCpuNotSupportedErr - the mode is not suppoted
*/

IPPAPI( IppStatus, ippCoreSetFlushToZero, ( int value, unsigned int* pUMask ))
IPPAPI( IppStatus, ippCoreSetDenormAreZeros, ( int value ))



/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippAlignPtr
//  Purpose:    pointer aligning
//  Returns:    aligned pointer
//
//  Parameter:
//    ptr        - pointer
//    alignBytes - number of bytes to align
//
*/
IPPAPI( void*, ippAlignPtr, ( void * ptr, int alignBytes ) )

/* /////////////////////////////////////////////////////////////////////////////
//                   Functions to allocate and free memory
///////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippMalloc
//  Purpose:    32-byte aligned memory allocation
//  Parameter:
//    len       number of bytes
//  Returns:    pointer to allocated memory
//
//  Notes:      the memory allocated by ippMalloc has to be free by ippFree
//              function only.
*/

IPPAPI( void*, ippMalloc,  (int length) )


/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippFree
//  Purpose:    free memory allocated by the ippMalloc function
//  Parameter:
//    ptr       pointer to the memory allocated by the ippMalloc function
//
//  Notes:      use the function to free memory allocated by ippMalloc
*/
IPPAPI( void, ippFree, (void* ptr) )


/* /////////////////////////////////////////////////////////////////////////////
//                   Functions to control emerged library
///////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippStaticInit
//  Purpose:    makes smart dispatchering for applications based on emerged library use.
//              Dispatcher searches the newest version of IPP dll's and if found it,
//              loads according dll's. Otherwise,  dispatcher calls ippStaticInitBest().
//
//  Returns:
//   ippStsNoErr               - the newest version of IPP dll's is successfully found
//                               and loaded
//   ippStsNoIppFunctionFound  - application does not contain IPP functions calls. or built
//                               with non-emerged  IPP library
//   ippStsDllNotFoundBestUsed - the newest version of IPP dll's not found by dispatcher,
//                               the best static code is used
//   ippStsTableNotCreatedBestUsed - a table for the dll functions names could
//                                   not be created, the best static code is used
//
//  Parameter:  nothing
//
//  Notes:      At the moment of this function excecution no any other IPP function
//              has to be working. This function releases resources themself after end of
//              application. In driver's implementation this function should not be used.
*/
IPPAPI( IppStatus, ippStaticInit, ( void ))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippStaticFree
//  Purpose:    releases the resources seized by ippStaticInit(), then calls
//              ippStaticInitBest() function.
//
//  Returns:
//   ippStsNoErr       - resources are released, ippStaticInitBest() call is successful
//   ippStsNonIntelCpu - px version (static) code is set.
//   ippStsNoOperationInDll - function does nothing in the dynamic version of the library
//
//  Parameter:  nothing
//
//  Notes:      At the moment of this function excecution no any other IPP function
//              has to be working. Repeating call of ippStaticFree() is enabled.
//              In driver's implementation this function should not be used..
*/
IPPAPI( IppStatus, ippStaticFree, ( void ))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippStaticInitBest
//  Purpose:    Automatic switching to to best for current cpu library code using.
//  Returns:
//   ippStsNoErr       - the best code (static) successfully set
//   ippStsNonIntelCpu - px version (static) of code was set
//   ippStsNoOperationInDll - function does nothing in the dynamic version of the library
//
//  Parameter:  nothing
//
//  Notes:      At the moment of this function excecution no any other IPP function
//              has to be working
*/
IPPAPI( IppStatus, ippStaticInitBest, ( void ))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippStaticInitCpu
//  Purpose:    switching to user defined target cpu library code using
//
//  Returns:
//   ippStsNoErr       - required target cpu library code is successfully set
//   ippStsCpuMismatch - required target cpu library can't be set, the previous
//                       set is used
//   ippStsNoOperationInDll - function does nothing in the dynamic version of the library
//
//  Parameter:  IppCpuType
//
//  Notes:      At the moment of this function excecution no any other IPP function
//              has to be working
*/
IPPAPI( IppStatus, ippStaticInitCpu, ( IppCpuType cpu ) )


#ifdef __cplusplus
}
#endif

#endif /* __IPPCORE_H__ */
/* ////////////////////////////// End of file /////////////////////////////// */
