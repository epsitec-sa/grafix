/* ////////////////////////////////// "ippi.h" /////////////////////////////////
//
//                  INTEL CORPORATION PROPRIETARY INFORMATION
//     This software is supplied under the terms of a license agreement or
//     nondisclosure agreement with Intel Corporation and may not be copied
//     or disclosed except in accordance with the terms of that agreement.
//     		Copyright(c) 1999-2003 Intel Corporation. All Rights Reserved.
//
//         		Intel(R) Integrated Performance Primitives
//                	Image Processing (ippi)
//
*/

#if !defined( __IPPI_H__ ) || defined( _OWN_BLDPCS )
#define __IPPI_H__

#ifndef __IPPDEFS_H__
  #include "ippdefs.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if !defined( _OWN_BLDPCS )


typedef enum {
    ippMskSize1x3 = 13,
    ippMskSize1x5 = 15,
    ippMskSize3x1 = 31,
    ippMskSize3x3 = 33,
    ippMskSize5x1 = 51,
    ippMskSize5x5 = 55
} IppiMaskSize;

typedef enum {
    ippAlphaOver,
    ippAlphaIn,
    ippAlphaOut,
    ippAlphaATop,
    ippAlphaXor,
    ippAlphaPlus,
    ippAlphaOverPremul,
    ippAlphaInPremul,
    ippAlphaOutPremul,
    ippAlphaATopPremul,
    ippAlphaXorPremul,
    ippAlphaPlusPremul
} IppiAlphaType;

typedef enum {
    ippDitherNone,
    ippDitherFS,
    ippDitherJJN,
    ippDitherStucki,
    ippDitherBayer
} IppiDitherType;

#endif /* _OWN_BLDPCS */



/* /////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//                   Functions declarations
////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippiGetLibVersion
//  Purpose:    getting of the library version
//  Returns:    the structure of information about  version of ippIP library
//  Parameters:
//
//  Notes:      not necessary to release the returned structure
*/
IPPAPI( const IppLibraryVersion*, ippiGetLibVersion, (void) )


/* /////////////////////////////////////////////////////////////////////////////
//                   Functions to allocate and free images
///////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippiMalloc
//  Purpose:    allocates memory with 32-byte aligned pointer for ippIP images,
//              every line of the image is aligned due to the padding characterized
//              by pStepBytes
//  Parameter:
//    widthPixels   width of image in pixels
//    heightPixels  height of image in pixels
//    pStepBytes    the pointer to the image step, it is an out parameter calculated
//                  by the function
//
//  Returns:    pointer to allocated memory or 0 if out of memory or wrong parameters
//  Notes:      free the allocated memory by the function ippiFree only
*/

IPPAPI( Ipp8u*,   ippiMalloc_8u_C1,    ( int widthPixels, int heightPixels, int* pStepBytes ) )
IPPAPI( Ipp16u*,  ippiMalloc_16u_C1,   ( int widthPixels, int heightPixels, int* pStepBytes ) )
IPPAPI( Ipp16s*,  ippiMalloc_16s_C1,   ( int widthPixels, int heightPixels, int* pStepBytes ) )
IPPAPI( Ipp32s*,  ippiMalloc_32s_C1,   ( int widthPixels, int heightPixels, int* pStepBytes ) )
IPPAPI( Ipp32f*,  ippiMalloc_32f_C1,   ( int widthPixels, int heightPixels, int* pStepBytes ) )
IPPAPI( Ipp32sc*, ippiMalloc_32sc_C1,  ( int widthPixels, int heightPixels, int* pStepBytes ) )
IPPAPI( Ipp32fc*, ippiMalloc_32fc_C1,  ( int widthPixels, int heightPixels, int* pStepBytes ) )

IPPAPI( Ipp8u*,   ippiMalloc_8u_C2,    ( int widthPixels, int heightPixels, int* pStepBytes ) )
IPPAPI( Ipp16u*,  ippiMalloc_16u_C2,   ( int widthPixels, int heightPixels, int* pStepBytes ) )
IPPAPI( Ipp16s*,  ippiMalloc_16s_C2,   ( int widthPixels, int heightPixels, int* pStepBytes ) )
IPPAPI( Ipp32s*,  ippiMalloc_32s_C2,   ( int widthPixels, int heightPixels, int* pStepBytes ) )
IPPAPI( Ipp32f*,  ippiMalloc_32f_C2,   ( int widthPixels, int heightPixels, int* pStepBytes ) )
IPPAPI( Ipp32sc*, ippiMalloc_32sc_C2,  ( int widthPixels, int heightPixels, int* pStepBytes ) )
IPPAPI( Ipp32fc*, ippiMalloc_32fc_C2,  ( int widthPixels, int heightPixels, int* pStepBytes ) )

IPPAPI( Ipp8u*,   ippiMalloc_8u_C3,    ( int widthPixels, int heightPixels, int* pStepBytes ) )
IPPAPI( Ipp16u*,  ippiMalloc_16u_C3,   ( int widthPixels, int heightPixels, int* pStepBytes ) )
IPPAPI( Ipp16s*,  ippiMalloc_16s_C3,   ( int widthPixels, int heightPixels, int* pStepBytes ) )
IPPAPI( Ipp32s*,  ippiMalloc_32s_C3,   ( int widthPixels, int heightPixels, int* pStepBytes ) )
IPPAPI( Ipp32f*,  ippiMalloc_32f_C3,   ( int widthPixels, int heightPixels, int* pStepBytes ) )
IPPAPI( Ipp32sc*, ippiMalloc_32sc_C3,  ( int widthPixels, int heightPixels, int* pStepBytes ) )
IPPAPI( Ipp32fc*, ippiMalloc_32fc_C3,  ( int widthPixels, int heightPixels, int* pStepBytes ) )

IPPAPI( Ipp8u*,   ippiMalloc_8u_C4,    ( int widthPixels, int heightPixels, int* pStepBytes ) )
IPPAPI( Ipp16u*,  ippiMalloc_16u_C4,   ( int widthPixels, int heightPixels, int* pStepBytes ) )
IPPAPI( Ipp16s*,  ippiMalloc_16s_C4,   ( int widthPixels, int heightPixels, int* pStepBytes ) )
IPPAPI( Ipp32s*,  ippiMalloc_32s_C4,   ( int widthPixels, int heightPixels, int* pStepBytes ) )
IPPAPI( Ipp32f*,  ippiMalloc_32f_C4,   ( int widthPixels, int heightPixels, int* pStepBytes ) )
IPPAPI( Ipp32sc*, ippiMalloc_32sc_C4,  ( int widthPixels, int heightPixels, int* pStepBytes ) )
IPPAPI( Ipp32fc*, ippiMalloc_32fc_C4,  ( int widthPixels, int heightPixels, int* pStepBytes ) )

IPPAPI( Ipp8u*,   ippiMalloc_8u_AC4,   ( int widthPixels, int heightPixels, int* pStepBytes ) )
IPPAPI( Ipp16u*,  ippiMalloc_16u_AC4,  ( int widthPixels, int heightPixels, int* pStepBytes ) )
IPPAPI( Ipp16s*,  ippiMalloc_16s_AC4,  ( int widthPixels, int heightPixels, int* pStepBytes ) )
IPPAPI( Ipp32s*,  ippiMalloc_32s_AC4,  ( int widthPixels, int heightPixels, int* pStepBytes ) )
IPPAPI( Ipp32f*,  ippiMalloc_32f_AC4,  ( int widthPixels, int heightPixels, int* pStepBytes ) )
IPPAPI( Ipp32sc*, ippiMalloc_32sc_AC4, ( int widthPixels, int heightPixels, int* pStepBytes ) )
IPPAPI( Ipp32fc*, ippiMalloc_32fc_AC4, ( int widthPixels, int heightPixels, int* pStepBytes ) )

IPPAPI( Ipp8u*,   ippiMalloc_8u_P3,    ( int widthPixels, int heightPixels, int* pStepBytes ) )
IPPAPI( Ipp16u*,  ippiMalloc_16u_P3,   ( int widthPixels, int heightPixels, int* pStepBytes ) )
IPPAPI( Ipp16s*,  ippiMalloc_16s_P3,   ( int widthPixels, int heightPixels, int* pStepBytes ) )
IPPAPI( Ipp32s*,  ippiMalloc_32s_P3,   ( int widthPixels, int heightPixels, int* pStepBytes ) )
IPPAPI( Ipp32f*,  ippiMalloc_32f_P3,   ( int widthPixels, int heightPixels, int* pStepBytes ) )
IPPAPI( Ipp32sc*, ippiMalloc_32sc_P3,  ( int widthPixels, int heightPixels, int* pStepBytes ) )
IPPAPI( Ipp32fc*, ippiMalloc_32fc_P3,  ( int widthPixels, int heightPixels, int* pStepBytes ) )


/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippiFree
//  Purpose:    free memory allocated by the ippiMalloc functions
//  Parameter:
//    ptr       pointer to the memory allocated by the ippiMalloc functions
//
//  Notes:      use the function to free memory allocated by ippiMalloc
*/
IPPAPI( void, ippiFree, (void* ptr) )



/* ///////////////////////////////////////////////////////////////////////////////////////
//                  Arithmetics functions
///////////////////////////////////////////////////////////////////////////// */
/* ///////////////////////////////////////////////////////////////////////////////////////
//  Name:  ippiAdd_8u_C1RSfs,  ippiAdd_8u_C3RSfs,  ippiAdd_8u_C4RSfs,  ippiAdd_8u_AC4RSfs,
//         ippiAdd_16s_C1RSfs, ippiAdd_16s_C3RSfs, ippiAdd_16s_C4RSfs, ippiAdd_16s_AC4RSfs,
//         ippiSub_8u_C1RSfs,  ippiSub_8u_C3RSfs,  ippiSub_8u_C4RSfs,  ippiSub_8u_AC4RSfs,
//         ippiSub_16s_C1RSfs, ippiSub_16s_C3RSfs, ippiSub_16s_C4RSfs, ippiSub_16s_AC4RSfs,
//         ippiMul_8u_C1RSfs,  ippiMul_8u_C3RSfs,  ippiMul_8u_C4RSfs,  ippiMul_8u_AC4RSfs,
//         ippiMul_16s_C1RSfs, ippiMul_16s_C3RSfs, ippiMul_16s_C4RSfs, ippiMul_16s_AC4RSfs
//
//  Purpose:    Makes corresponding operation with pixel values of two
//              source images and places the scaled result in the destination image.
//
//  Return:
//    ippStsNoErr              Ok
//    ippStsNullPtrErr         One of the pointers is NULL
//    ippStsSizeErr            The width or height of images is less than or equal to zero
//    ippStsStepErr            Any of the step values is less than or equal to zero
//
//  Arguments:
//    pSrc1, pSrc2             Pointers to the source images
//    src1Step, src2Step       Steps through the source images
//    pDst                     Pointer to the destination image
//    dstStep                  Step through the destination image
//    roiSize                  Size of the ROI
//    scaleFactor              Scale factor
*/

IPPAPI(IppStatus, ippiAdd_8u_C1RSfs,   (const Ipp8u* pSrc1, int src1Step, const Ipp8u* pSrc2,
                                        int src2Step, Ipp8u* pDst, int dstStep, IppiSize roiSize,
                                        int scaleFactor))
IPPAPI(IppStatus, ippiAdd_8u_C3RSfs,   (const Ipp8u* pSrc1, int src1Step, const Ipp8u* pSrc2,
                                        int src2Step, Ipp8u* pDst, int dstStep, IppiSize roiSize,
                                        int scaleFactor))
IPPAPI(IppStatus, ippiAdd_8u_C4RSfs,   (const Ipp8u* pSrc1, int src1Step, const Ipp8u* pSrc2,
                                        int src2Step, Ipp8u* pDst, int dstStep, IppiSize roiSize,
                                        int scaleFactor))
IPPAPI(IppStatus, ippiAdd_8u_AC4RSfs,  (const Ipp8u* pSrc1, int src1Step, const Ipp8u* pSrc2,
                                        int src2Step, Ipp8u* pDst, int dstStep, IppiSize roiSize,
                                        int scaleFactor))
IPPAPI(IppStatus, ippiAdd_16s_C1RSfs,  (const Ipp16s* pSrc1, int src1Step, const Ipp16s* pSrc2,
                                        int src2Step, Ipp16s* pDst, int dstStep, IppiSize roiSize,
                                        int scaleFactor))
IPPAPI(IppStatus, ippiAdd_16s_C3RSfs,  (const Ipp16s* pSrc1, int src1Step, const Ipp16s* pSrc2,
                                        int src2Step, Ipp16s* pDst, int dstStep, IppiSize roiSize,
                                        int scaleFactor))
IPPAPI(IppStatus, ippiAdd_16s_C4RSfs,  (const Ipp16s* pSrc1, int src1Step, const Ipp16s* pSrc2,
                                        int src2Step, Ipp16s* pDst, int dstStep, IppiSize roiSize,
                                        int scaleFactor))
IPPAPI(IppStatus, ippiAdd_16s_AC4RSfs, (const Ipp16s* pSrc1, int src1Step, const Ipp16s* pSrc2,
                                        int src2Step, Ipp16s* pDst, int dstStep, IppiSize roiSize,
                                        int scaleFactor))
IPPAPI(IppStatus, ippiSub_8u_C1RSfs,   (const Ipp8u* pSrc1, int src1Step, const Ipp8u* pSrc2,
                                        int src2Step, Ipp8u* pDst, int dstStep, IppiSize roiSize,
                                        int scaleFactor))
IPPAPI(IppStatus, ippiSub_8u_C3RSfs,   (const Ipp8u* pSrc1, int src1Step, const Ipp8u* pSrc2,
                                        int src2Step, Ipp8u* pDst, int dstStep, IppiSize roiSize,
                                        int scaleFactor))
IPPAPI(IppStatus, ippiSub_8u_C4RSfs,   (const Ipp8u* pSrc1, int src1Step, const Ipp8u* pSrc2,
                                        int src2Step, Ipp8u* pDst, int dstStep, IppiSize roiSize,
                                        int scaleFactor))
IPPAPI(IppStatus, ippiSub_8u_AC4RSfs,  (const Ipp8u* pSrc1, int src1Step, const Ipp8u* pSrc2,
                                        int src2Step, Ipp8u* pDst, int dstStep, IppiSize roiSize,
                                        int scaleFactor))
IPPAPI(IppStatus, ippiSub_16s_C1RSfs,  (const Ipp16s* pSrc1, int src1Step, const Ipp16s* pSrc2,
                                        int src2Step, Ipp16s* pDst, int dstStep, IppiSize roiSize,
                                        int scaleFactor))
IPPAPI(IppStatus, ippiSub_16s_C3RSfs,  (const Ipp16s* pSrc1, int src1Step, const Ipp16s* pSrc2,
                                        int src2Step, Ipp16s* pDst, int dstStep, IppiSize roiSize,
                                        int scaleFactor))
IPPAPI(IppStatus, ippiSub_16s_C4RSfs,  (const Ipp16s* pSrc1, int src1Step, const Ipp16s* pSrc2,
                                        int src2Step, Ipp16s* pDst, int dstStep, IppiSize roiSize,
                                        int scaleFactor))
IPPAPI(IppStatus, ippiSub_16s_AC4RSfs, (const Ipp16s* pSrc1, int src1Step, const Ipp16s* pSrc2,
                                        int src2Step, Ipp16s* pDst, int dstStep, IppiSize roiSize,
                                        int scaleFactor))
IPPAPI(IppStatus, ippiMul_8u_C1RSfs,   (const Ipp8u* pSrc1, int src1Step, const Ipp8u* pSrc2,
                                        int src2Step, Ipp8u* pDst, int dstStep, IppiSize roiSize,
                                        int scaleFactor))
IPPAPI(IppStatus, ippiMul_8u_C3RSfs,   (const Ipp8u* pSrc1, int src1Step, const Ipp8u* pSrc2,
                                        int src2Step, Ipp8u* pDst, int dstStep, IppiSize roiSize,
                                        int scaleFactor))
IPPAPI(IppStatus, ippiMul_8u_C4RSfs,   (const Ipp8u* pSrc1, int src1Step, const Ipp8u* pSrc2,
                                        int src2Step, Ipp8u* pDst, int dstStep, IppiSize roiSize,
                                        int scaleFactor))
IPPAPI(IppStatus, ippiMul_8u_AC4RSfs,  (const Ipp8u* pSrc1, int src1Step, const Ipp8u* pSrc2,
                                        int src2Step, Ipp8u* pDst, int dstStep, IppiSize roiSize,
                                        int scaleFactor))
IPPAPI(IppStatus, ippiMul_16s_C1RSfs,  (const Ipp16s* pSrc1, int src1Step, const Ipp16s* pSrc2,
                                        int src2Step, Ipp16s* pDst, int dstStep, IppiSize roiSize,
                                        int scaleFactor))
IPPAPI(IppStatus, ippiMul_16s_C3RSfs,  (const Ipp16s* pSrc1, int src1Step, const Ipp16s* pSrc2,
                                        int src2Step, Ipp16s* pDst, int dstStep, IppiSize roiSize,
                                        int scaleFactor))
IPPAPI(IppStatus, ippiMul_16s_C4RSfs,  (const Ipp16s* pSrc1, int src1Step, const Ipp16s* pSrc2,
                                        int src2Step, Ipp16s* pDst, int dstStep, IppiSize roiSize,
                                        int scaleFactor))
IPPAPI(IppStatus, ippiMul_16s_AC4RSfs, (const Ipp16s* pSrc1, int src1Step, const Ipp16s* pSrc2,
                                        int src2Step, Ipp16s* pDst, int dstStep, IppiSize roiSize,
                                        int scaleFactor))

/* //////////////////////////////////////////////////////////////////////////////////////////////
//  Name: ippiAddC_8u_C1IRSfs,  ippiAddC_8u_C3IRSfs,  ippiAddC_8u_C4IRSfs,   ippiAddC_8u_AC4IRSfs,
//        ippiAddC_16s_C1IRSfs, ippiAddC_16s_C3IRSfs, ippiAddC_16s_C4IRSfs,  ippiAddC_16s_AC4IRSfs,
//        ippiSubC_8u_C1IRSfs,  ippiSubC_8u_C3IRSfs,  ippiSubC_8u_C4IRSfs,   ippiSubC_8u_AC4IRSfs,
//        ippiSubC_16s_C1IRSfs, ippiSubC_16s_C3IRSfs, ippiSubC_16s_C4IRSfs,  ippiSubC_16s_AC4IRSfs,
//        ippiMulC_8u_C1IRSfs,  ippiMulC_8u_C3IRSfs,  ippiMulC_8u_C4IRSfs,   ippiMulC_8u_AC4IRSfs,
//        ippiMulC_16s_C1IRSfs, ippiMulC_16s_C3IRSfs, ippiMulC_16s_C4IRSfs,  ippiMulC_16s_AC4IRSfs
//
//  Purpose:    Makes corresponding operation with a constant and pixel values of an image
//              and places the scaled results in the same image.
//
//  Return:
//    ippStsNoErr              Ok
//    ippStsNullPtrErr         The pointer is NULL
//    ippStsSizeErr            The width or height of an image is less than or equal to zero
//    ippStsStepErr            The step value is less than or equal to zero
//
//  Arguments:
//    value                    The constant value for the specified operation
//    pSrcDst                  Pointer to the image
//    srcDstStep               Step through the image
//    roiSize                  Size of the ROI
//    scaleFactor              Scale factor
*/

IPPAPI(IppStatus, ippiAddC_8u_C1IRSfs,   (Ipp8u value, Ipp8u* pSrcDst, int srcDstStep,
                                          IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiAddC_8u_C3IRSfs,   (const Ipp8u value[3], Ipp8u* pSrcDst, int srcDstStep,
                                          IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiAddC_8u_C4IRSfs,   (const Ipp8u value[4], Ipp8u* pSrcDst, int srcDstStep,
                                          IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiAddC_8u_AC4IRSfs,  (const Ipp8u value[3], Ipp8u* pSrcDst, int srcDstStep,
                                          IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiAddC_16s_C1IRSfs,  (Ipp16s value, Ipp16s* pSrcDst, int srcDstStep,
                                          IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiAddC_16s_C3IRSfs,  (const Ipp16s value[3], Ipp16s* pSrcDst, int srcDstStep,
                                          IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiAddC_16s_C4IRSfs,  (const Ipp16s value[4], Ipp16s* pSrcDst, int srcDstStep,
                                          IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiAddC_16s_AC4IRSfs, (const Ipp16s value[3], Ipp16s* pSrcDst, int srcDstStep,
                                          IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiSubC_8u_C1IRSfs,   (Ipp8u value, Ipp8u* pSrcDst, int srcDstStep,
                                          IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiSubC_8u_C3IRSfs,   (const Ipp8u value[3], Ipp8u* pSrcDst, int srcDstStep,
                                          IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiSubC_8u_C4IRSfs,   (const Ipp8u value[4], Ipp8u* pSrcDst, int srcDstStep,
                                          IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiSubC_8u_AC4IRSfs,  (const Ipp8u value[3], Ipp8u* pSrcDst, int srcDstStep,
                                          IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiSubC_16s_C1IRSfs,  (Ipp16s value, Ipp16s* pSrcDst, int srcDstStep,
                                          IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiSubC_16s_C3IRSfs,  (const Ipp16s value[3], Ipp16s* pSrcDst, int srcDstStep,
                                          IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiSubC_16s_C4IRSfs,  (const Ipp16s value[4], Ipp16s* pSrcDst, int srcDstStep,
                                          IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiSubC_16s_AC4IRSfs, (const Ipp16s value[3], Ipp16s* pSrcDst, int srcDstStep,
                                          IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiMulC_8u_C1IRSfs,   (Ipp8u value, Ipp8u* pSrcDst, int srcDstStep,
                                          IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiMulC_8u_C3IRSfs,   (const Ipp8u value[3], Ipp8u* pSrcDst, int srcDstStep,
                                          IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiMulC_8u_C4IRSfs,   (const Ipp8u value[4], Ipp8u* pSrcDst, int srcDstStep,
                                          IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiMulC_8u_AC4IRSfs,  (const Ipp8u value[3], Ipp8u* pSrcDst, int srcDstStep,
                                          IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiMulC_16s_C1IRSfs,  (Ipp16s value, Ipp16s* pSrcDst, int srcDstStep,
                                          IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiMulC_16s_C3IRSfs,  (const Ipp16s value[3], Ipp16s* pSrcDst, int srcDstStep,
                                          IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiMulC_16s_C4IRSfs,  (const Ipp16s value[4], Ipp16s* pSrcDst, int srcDstStep,
                                          IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiMulC_16s_AC4IRSfs, (const Ipp16s value[3], Ipp16s* pSrcDst, int srcDstStep,
                                          IppiSize roiSize, int scaleFactor))

/* /////////////////////////////////////////////////////////////////////////////////////////////
//  Name: ippiAddC_8u_C1RSfs,  ippiAddC_8u_C3RSfs,  ippiAddC_8u_C4RSfs   ippiAddC_8u_AC4RSfs,
//        ippiAddC_16s_C1RSfs, ippiAddC_16s_C3RSfs, ippiAddC_16s_C4RSfs, ippiAddC_16s_AC4RSfs,
//        ippiSubC_8u_C1RSfs,  ippiSubC_8u_C3RSfs,  ippiSubC_8u_C4RSfs,  ippiSubC_8u_AC4RSfs,
//        ippiSubC_16s_C1RSfs, ippiSubC_16s_C3RSfs, ippiSubC_16s_C4RSfs, ippiSubC_16s_AC4RSfs,
//        ippiMulC_8u_C1RSfs,  ippiMulC_8u_C3RSfs,  ippiMulC_8u_C4RSfs,  ippiMulC_8u_AC4RSfs,
//        ippiMulC_16s_C1RSfs, ippiMulC_16s_C3RSfs, ippiMulC_16s_C4RSfs, ippiMulC_16s_AC4RSfs
//
//  Purpose:    Makes corresponding operation with a constant and pixel values of
//              a source image and places the scaled results in a destination image.
//
//  Return:
//    ippStsNoErr              Ok
//    ippStsNullPtrErr         One of the pointers is NULL
//    ippStsSizeErr            The width or height of images is less than or equal to zero
//    ippStsStepErr            Any of the step values is less than or equal to zero
//
//  Arguments:
//    value                    The constant value for the specified operation
//    pSrc                     Pointer to the source image
//    srcStep                  Step through the source image
//    pDst                     Pointer to the destination image
//    dstStep                  Step through the destination image
//    roiSize                  Size of the ROI
//    scaleFactor              Scale factor
*/

IPPAPI(IppStatus, ippiAddC_8u_C1RSfs,   (const Ipp8u* pSrc, int srcStep, Ipp8u value, Ipp8u* pDst,
                                         int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiAddC_8u_C3RSfs,   (const Ipp8u* pSrc, int srcStep,const Ipp8u value[3],
                                         Ipp8u* pDst, int dstStep, IppiSize roiSize,
                                         int scaleFactor))
IPPAPI(IppStatus, ippiAddC_8u_C4RSfs,   (const Ipp8u* pSrc, int srcStep, const Ipp8u value[4],
                                         Ipp8u* pDst, int dstStep, IppiSize roiSize,
                                         int scaleFactor))
IPPAPI(IppStatus, ippiAddC_8u_AC4RSfs,  (const Ipp8u* pSrc, int srcStep, const Ipp8u value[3],
                                         Ipp8u* pDst, int dstStep, IppiSize roiSize,
                                         int scaleFactor))
IPPAPI(IppStatus, ippiAddC_16s_C1RSfs,  (const Ipp16s* pSrc, int srcStep, Ipp16s value, Ipp16s* pDst,
                                         int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiAddC_16s_C3RSfs,  (const Ipp16s* pSrc, int srcStep,const Ipp16s value[3],
                                         Ipp16s* pDst, int dstStep, IppiSize roiSize,
                                         int scaleFactor))
IPPAPI(IppStatus, ippiAddC_16s_C4RSfs,  (const Ipp16s* pSrc, int srcStep, const Ipp16s value[4],
                                         Ipp16s* pDst, int dstStep, IppiSize roiSize,
                                         int scaleFactor))
IPPAPI(IppStatus, ippiAddC_16s_AC4RSfs, (const Ipp16s* pSrc, int srcStep, const Ipp16s value[3],
                                         Ipp16s* pDst, int dstStep, IppiSize roiSize,
                                         int scaleFactor))
IPPAPI(IppStatus, ippiSubC_8u_C1RSfs,   (const Ipp8u* pSrc, int srcStep, Ipp8u value, Ipp8u* pDst,
                                         int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiSubC_8u_C3RSfs,   (const Ipp8u* pSrc, int srcStep,const Ipp8u value[3],
                                         Ipp8u* pDst, int dstStep, IppiSize roiSize,
                                         int scaleFactor))
IPPAPI(IppStatus, ippiSubC_8u_C4RSfs,   (const Ipp8u* pSrc, int srcStep, const Ipp8u value[4],
                                         Ipp8u* pDst, int dstStep, IppiSize roiSize,
                                         int scaleFactor))
IPPAPI(IppStatus, ippiSubC_8u_AC4RSfs,  (const Ipp8u* pSrc, int srcStep,const Ipp8u value[3],
                                         Ipp8u* pDst, int dstStep, IppiSize roiSize,
                                         int scaleFactor))
IPPAPI(IppStatus, ippiSubC_16s_C1RSfs,  (const Ipp16s* pSrc, int srcStep, Ipp16s value, Ipp16s* pDst,
                                         int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiSubC_16s_C3RSfs,  (const Ipp16s* pSrc, int srcStep, const Ipp16s value[3],
                                         Ipp16s* pDst, int dstStep, IppiSize roiSize,
                                         int scaleFactor))
IPPAPI(IppStatus, ippiSubC_16s_C4RSfs,  (const Ipp16s* pSrc, int srcStep, const Ipp16s value[4],
                                         Ipp16s* pDst, int dstStep, IppiSize roiSize,
                                         int scaleFactor))
IPPAPI(IppStatus, ippiSubC_16s_AC4RSfs, (const Ipp16s* pSrc, int srcStep, const Ipp16s value[3],
                                         Ipp16s* pDst, int dstStep, IppiSize roiSize,
                                         int scaleFactor))
IPPAPI(IppStatus, ippiMulC_8u_C1RSfs,   (const Ipp8u* pSrc, int srcStep, Ipp8u value, Ipp8u* pDst,
                                         int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiMulC_8u_C3RSfs,   (const Ipp8u* pSrc, int srcStep, const Ipp8u value[3],
                                         Ipp8u* pDst, int dstStep, IppiSize roiSize,
                                         int scaleFactor))
IPPAPI(IppStatus, ippiMulC_8u_C4RSfs,   (const Ipp8u* pSrc, int srcStep, const Ipp8u value[4],
                                         Ipp8u* pDst, int dstStep, IppiSize roiSize,
                                         int scaleFactor))
IPPAPI(IppStatus, ippiMulC_8u_AC4RSfs,  (const Ipp8u* pSrc, int srcStep, const Ipp8u value[3],
                                         Ipp8u* pDst, int dstStep, IppiSize roiSize,
                                         int scaleFactor))
IPPAPI(IppStatus, ippiMulC_16s_C1RSfs,  (const Ipp16s* pSrc, int srcStep, Ipp16s value, Ipp16s* pDst,
                                         int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiMulC_16s_C3RSfs,  (const Ipp16s* pSrc, int srcStep, const Ipp16s value[3],
                                         Ipp16s* pDst, int dstStep, IppiSize roiSize,
                                         int scaleFactor))
IPPAPI(IppStatus, ippiMulC_16s_C4RSfs,  (const Ipp16s* pSrc, int srcStep, const Ipp16s value[4],
                                         Ipp16s* pDst, int dstStep, IppiSize roiSize,
                                         int scaleFactor))
IPPAPI(IppStatus, ippiMulC_16s_AC4RSfs, (const Ipp16s* pSrc, int srcStep, const Ipp16s value[3],
                                         Ipp16s* pDst, int dstStep, IppiSize roiSize,
                                         int scaleFactor))

/* ////////////////////////////////////////////////////////////////////////////////////////////
//  Name: ippiAdd_8u_C1IRSfs,  ippiAdd_8u_C3IRSfs,  ippiAdd_8u_C4IRSfs,  ippiAdd_8u_AC4IRSfs,
//        ippiAdd_16s_C1IRSfs, ippiAdd_16s_C3IRSfs, ippiAdd_16s_C4IRSfs, ippiAdd_16s_AC4IRSfs,
//        ippiSub_8u_C1IRSfs,  ippiSub_8u_C3IRSfs,  ippiSub_8u_C4IRSfs,  ippiSub_8u_AC4IRSfs,
//        ippiSub_16s_C1IRSfs, ippiSub_16s_C3IRSfs, ippiSub_16s_C4IRSfs  ippiSub_16s_AC4IRSfs,
//        ippiMul_8u_C1IRSfs,  ippiMul_8u_C3IRSfs,  ippiMul_8u_C4IRSfs,  ippiMul_8u_AC4IRSfs,
//        ippiMul_16s_C1IRSfs, ippiMul_16s_C3IRSfs, ippiMul_16s_C4IRSfs, ippiMul_16s_AC4IRSfs
//
//  Purpose:    Makes corresponding operation with pixel values of two source images
//              and places the scaled results in a destination image.
//
//  Return:
//    ippStsNoErr              Ok
//    ippStsNullPtrErr         One of the pointers is NULL
//    ippStsSizeErr            The width or height of images is less than or equal to zero
//    ippStsStepErr            Any of the step values is less than or equal to zero
//
//  Arguments:
//    pSrc                     Pointer to the source image
//    srcStep                  Step through the source image
//    pSrcDst                  Pointer to the source & destination image
//    srcDstStep               Step through the source & destination image
//    roiSize                  Size of the ROI
//    scaleFactor              Scale factor
*/

IPPAPI(IppStatus, ippiAdd_8u_C1IRSfs,   (const Ipp8u* pSrc, int srcStep, Ipp8u* pSrcDst,
                                         int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiAdd_8u_C3IRSfs,   (const Ipp8u* pSrc, int srcStep, Ipp8u* pSrcDst,
                                         int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiAdd_8u_C4IRSfs,   (const Ipp8u* pSrc, int srcStep, Ipp8u* pSrcDst,
                                         int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiAdd_8u_AC4IRSfs,  (const Ipp8u* pSrc, int srcStep, Ipp8u* pSrcDst,
                                         int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiAdd_16s_C1IRSfs,  (const Ipp16s* pSrc, int srcStep, Ipp16s* pSrcDst,
                                         int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiAdd_16s_C3IRSfs,  (const Ipp16s* pSrc, int srcStep, Ipp16s* pSrcDst,
                                         int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiAdd_16s_C4IRSfs,  (const Ipp16s* pSrc, int srcStep, Ipp16s* pSrcDst,
                                         int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiAdd_16s_AC4IRSfs, (const Ipp16s* pSrc, int srcStep, Ipp16s* pSrcDst,
                                         int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiSub_8u_C1IRSfs,   (const Ipp8u* pSrc, int srcStep, Ipp8u* pSrcDst,
                                         int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiSub_8u_C3IRSfs,   (const Ipp8u* pSrc, int srcStep, Ipp8u* pSrcDst,
                                         int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiSub_8u_C4IRSfs,   (const Ipp8u* pSrc, int srcStep, Ipp8u* pSrcDst,
                                         int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiSub_8u_AC4IRSfs,  (const Ipp8u* pSrc, int srcStep, Ipp8u* pSrcDst,
                                         int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiSub_16s_C1IRSfs,  (const Ipp16s* pSrc, int srcStep, Ipp16s* pSrcDst,
                                         int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiSub_16s_C3IRSfs,  (const Ipp16s* pSrc, int srcStep, Ipp16s* pSrcDst,
                                         int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiSub_16s_C4IRSfs,  (const Ipp16s* pSrc, int srcStep, Ipp16s* pSrcDst,
                                         int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiSub_16s_AC4IRSfs, (const Ipp16s* pSrc, int srcStep, Ipp16s* pSrcDst,
                                         int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiMul_8u_C1IRSfs,   (const Ipp8u* pSrc, int srcStep, Ipp8u* pSrcDst,
                                         int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiMul_8u_C3IRSfs,   (const Ipp8u* pSrc, int srcStep, Ipp8u* pSrcDst,
                                         int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiMul_8u_C4IRSfs,   (const Ipp8u* pSrc, int srcStep, Ipp8u* pSrcDst,
                                         int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiMul_8u_AC4IRSfs,  (const Ipp8u* pSrc, int srcStep, Ipp8u* pSrcDst,
                                         int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiMul_16s_C1IRSfs,  (const Ipp16s* pSrc, int srcStep, Ipp16s* pSrcDst,
                                         int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiMul_16s_C3IRSfs,  (const Ipp16s* pSrc, int srcStep, Ipp16s* pSrcDst,
                                         int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiMul_16s_C4IRSfs,  (const Ipp16s* pSrc, int srcStep, Ipp16s* pSrcDst,
                                         int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiMul_16s_AC4IRSfs, (const Ipp16s* pSrc, int srcStep, Ipp16s* pSrcDst,
                                         int srcDstStep, IppiSize roiSize, int scaleFactor))

/* /////////////////////////////////////////////////////////////////////////////////
//  Name: ippiAddC_32f_C1R, ippiAddC_32f_C3R, ippiAddC_32f_C4R,  ippiAddC_32f_AC4R,
//        ippiSubC_32f_C1R, ippiSubC_32f_C3R, ippiSubC_32f_C4R,  ippiSubC_32f_AC4R,
//        ippiMulC_32f_C1R, ippiMulC_32f_C3R, ippiMulC_32f_C4R,  ippiMulC_32f_AC4R
//
//  Purpose:    Makes corresponding operation with a constant and pixel values of
//              a source image and places the results in a destination image.
//
//  Return:
//    ippStsNoErr              Ok
//    ippStsNullPtrErr         One of the pointers is NULL
//    ippStsSizeErr            The width or height of images is less than or equal to zero
//    ippStsStepErr            Any of the step values is less than or equal to zero
//
//  Arguments:
//    value                    The constant value for the specified operation
//    pSrc                     Pointer to the source image
//    srcStep                  Step through the source image
//    pDst                     Pointer to the destination image
//    dstStep                  Step through the destination image
//    roiSize                  Size of the ROI
*/

IPPAPI(IppStatus, ippiAddC_32f_C1R,  (const Ipp32f* pSrc, int srcStep, Ipp32f value, Ipp32f* pDst,
                                      int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAddC_32f_C3R,  (const Ipp32f* pSrc, int srcStep, const Ipp32f value[3],
                                      Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAddC_32f_C4R,  (const Ipp32f* pSrc, int srcStep, const Ipp32f value[4],
                                      Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAddC_32f_AC4R, (const Ipp32f* pSrc, int srcStep, const Ipp32f value[3],
                                      Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiSubC_32f_C1R,  (const Ipp32f* pSrc, int srcStep, Ipp32f value, Ipp32f* pDst,
                                      int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiSubC_32f_C3R,  (const Ipp32f* pSrc, int srcStep, const Ipp32f value[3],
                                      Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiSubC_32f_C4R,  (const Ipp32f* pSrc, int srcStep, const Ipp32f value[4],
                                      Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiSubC_32f_AC4R, (const Ipp32f* pSrc, int srcStep, const Ipp32f value[3],
                                      Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMulC_32f_C1R,  (const Ipp32f* pSrc, int srcStep, Ipp32f value, Ipp32f* pDst,
                                      int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMulC_32f_C3R,  (const Ipp32f* pSrc, int srcStep, const Ipp32f value[3],
                                      Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMulC_32f_C4R,  (const Ipp32f* pSrc, int srcStep, const Ipp32f value[4],
                                      Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMulC_32f_AC4R, (const Ipp32f* pSrc, int srcStep, const Ipp32f value[3],
                                      Ipp32f* pDst, int dstStep, IppiSize roiSize))

/* ///////////////////////////////////////////////////////////////////////////////////////
//  Name: ippiAddC_32f_C1IR, ippiAddC_32f_C3IR, ippiAddC_32f_C4IR, ippiAddC_32f_AC4IR,
//        ippiSubC_32f_C1IR, ippiSubC_32f_C3IR, ippiSubC_32f_C4IR, ippiSubC_32f_AC4IR,
//        ippiMulC_32f_C1IR, ippiMulC_32f_C3IR, ippiMulC_32f_C4IR, ippiMulC_32f_AC4IR
//
//  Purpose:    Makes corresponding operation with a constant and pixel values of
//              an image and places the results in the same image.
//
//  Return:
//    ippStsNoErr              Ok
//    ippStsNullPtrErr         The pointer is NULL
//    ippStsSizeErr            The width or height of an image is less than or equal to zero
//    ippStsStepErr            The step value is less than or equal to zero
//
//  Arguments:
//    value                    The constant value for the specified operation
//    pSrcDst                  Pointer to the image
//    srcDstStep               Step through the image
//    roiSize                  Size of the ROI
*/

IPPAPI(IppStatus, ippiAddC_32f_C1IR,  (Ipp32f value, Ipp32f* pSrcDst, int srcDstStep,
                                       IppiSize roiSize))
IPPAPI(IppStatus, ippiAddC_32f_C3IR,  (const Ipp32f value[3], Ipp32f* pSrcDst, int srcDstStep,
                                       IppiSize roiSize))
IPPAPI(IppStatus, ippiAddC_32f_C4IR,  (const Ipp32f value[4], Ipp32f* pSrcDst, int srcDstStep,
                                       IppiSize roiSize))
IPPAPI(IppStatus, ippiAddC_32f_AC4IR, (const Ipp32f value[3], Ipp32f* pSrcDst, int srcDstStep,
                                       IppiSize roiSize))
IPPAPI(IppStatus, ippiSubC_32f_C1IR,  (Ipp32f value, Ipp32f* pSrcDst, int srcDstStep,
                                       IppiSize roiSize))
IPPAPI(IppStatus, ippiSubC_32f_C3IR,  (const Ipp32f value[3], Ipp32f* pSrcDst, int srcDstStep,
                                       IppiSize roiSize))
IPPAPI(IppStatus, ippiSubC_32f_C4IR,  (const Ipp32f value[4], Ipp32f* pSrcDst, int srcDstStep,
                                       IppiSize roiSize))
IPPAPI(IppStatus, ippiSubC_32f_AC4IR, (const Ipp32f value[3], Ipp32f* pSrcDst, int srcDstStep,
                                       IppiSize roiSize))
IPPAPI(IppStatus, ippiMulC_32f_C1IR,  (Ipp32f value, Ipp32f* pSrcDst, int srcDstStep,
                                       IppiSize roiSize))
IPPAPI(IppStatus, ippiMulC_32f_C3IR,  (const Ipp32f value[3], Ipp32f* pSrcDst, int srcDstStep,
                                       IppiSize roiSize))
IPPAPI(IppStatus, ippiMulC_32f_C4IR,  (const Ipp32f value[4], Ipp32f* pSrcDst, int srcDstStep,
                                       IppiSize roiSize))
IPPAPI(IppStatus, ippiMulC_32f_AC4IR, (const Ipp32f value[3], Ipp32f* pSrcDst, int srcDstStep,
                                       IppiSize roiSize))

/* ////////////////////////////////////////////////////////////////////////////////////
//  Name: ippiAdd_32f_C1IR, ippiAdd_32f_C3IR, ippiAdd_32f_C4IR, ippiAdd_32f_AC4IR,
//        ippiSub_32f_C1IR, ippiSub_32f_C3IR, ippiSub_32f_C4IR, ippiSub_32f_AC4IR,
//        ippiMul_32f_C1IR, ippiMul_32f_C3IR, ippiMul_32f_C4IR, ippiMul_32f_AC4IR
//
//  Purpose:    Makes corresponding operation with pixel values of two source images
//              and places the results in a destination image.
//
//  Return:
//    ippStsNoErr              Ok
//    ippStsNullPtrErr         One of the pointers is NULL
//    ippStsSizeErr            The width or height of images is less than or equal to zero
//    ippStsStepErr            Any of the step values is less than or equal to zero
//
//  Arguments:
//    pSrc                     Pointer to the source image
//    srcStep                  Step through the source image
//    pSrcDst                  Pointer to the source & destination image
//    srcDstStep               Step through the source & destination image
//    roiSize                  Size of the ROI
*/

IPPAPI(IppStatus, ippiAdd_32f_C1IR,  (const Ipp32f* pSrc, int srcStep, Ipp32f* pSrcDst,
                                      int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAdd_32f_C3IR,  (const Ipp32f* pSrc, int srcStep, Ipp32f* pSrcDst,
                                      int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAdd_32f_C4IR,  (const Ipp32f* pSrc, int srcStep, Ipp32f* pSrcDst,
                                      int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAdd_32f_AC4IR, (const Ipp32f* pSrc, int srcStep, Ipp32f* pSrcDst,
                                      int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiSub_32f_C1IR,  (const Ipp32f* pSrc, int srcStep, Ipp32f* pSrcDst,
                                      int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiSub_32f_C3IR,  (const Ipp32f* pSrc, int srcStep, Ipp32f* pSrcDst,
                                      int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiSub_32f_C4IR,  (const Ipp32f* pSrc, int srcStep, Ipp32f* pSrcDst,
                                      int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiSub_32f_AC4IR, (const Ipp32f* pSrc, int srcStep, Ipp32f* pSrcDst,
                                      int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMul_32f_C1IR,  (const Ipp32f* pSrc, int srcStep, Ipp32f* pSrcDst,
                                      int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMul_32f_C3IR,  (const Ipp32f* pSrc, int srcStep, Ipp32f* pSrcDst,
                                      int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMul_32f_C4IR,  (const Ipp32f* pSrc, int srcStep, Ipp32f* pSrcDst,
                                      int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMul_32f_AC4IR, (const Ipp32f* pSrc, int srcStep, Ipp32f* pSrcDst,
                                      int srcDstStep, IppiSize roiSize))

/* ////////////////////////////////////////////////////////////////////////////
//  Name: ippiAdd_32f_C1R, ippiAdd_32f_C3R, ippiAdd_32f_C4R, ippiAdd_32f_AC4R,
//        ippiSub_32f_C1R, ippiSub_32f_C3R, ippiSub_32f_C4R, ippiSub_32f_AC4R,
//        ippiMul_32f_C1R, ippiMul_32f_C3R, ippiMul_32f_C4R, ippiMul_32f_AC4R
//
//  Purpose:    Makes corresponding operation with pixel values of two
//              source images and places the results in a destination image.
//
//  Return:
//    ippStsNoErr            Ok
//    ippStsNullPtrErr       One of the pointers is NULL
//    ippStsSizeErr          The width or height of images is less than or equal to zero
//    ippStsStepErr          Any of the step values is less than or equal to zero
//
//  Arguments:
//    pSrc1, pSrc2           Pointers to the source images
//    src1Step, src2Step     Steps through the source images
//    pDst                   Pointer to the destination image
//    dstStep                Step through the destination image
//    roiSize                Size of the ROI
*/

IPPAPI(IppStatus, ippiAdd_32f_C1R,  (const Ipp32f* pSrc1, int src1Step, const Ipp32f* pSrc2,
                                     int src2Step, Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAdd_32f_C3R,  (const Ipp32f* pSrc1, int src1Step, const Ipp32f* pSrc2,
                                     int src2Step, Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAdd_32f_C4R,  (const Ipp32f* pSrc1, int src1Step, const Ipp32f* pSrc2,
                                     int src2Step, Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAdd_32f_AC4R, (const Ipp32f* pSrc1, int src1Step, const Ipp32f* pSrc2,
                                     int src2Step, Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiSub_32f_C1R,  (const Ipp32f* pSrc1, int src1Step, const Ipp32f* pSrc2,
                                     int src2Step, Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiSub_32f_C3R,  (const Ipp32f* pSrc1, int src1Step, const Ipp32f* pSrc2,
                                     int src2Step, Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiSub_32f_C4R,  (const Ipp32f* pSrc1, int src1Step, const Ipp32f* pSrc2,
                                     int src2Step, Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiSub_32f_AC4R, (const Ipp32f* pSrc1, int src1Step, const Ipp32f* pSrc2,
                                     int src2Step, Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMul_32f_C1R,  (const Ipp32f* pSrc1, int src1Step, const Ipp32f* pSrc2,
                                     int src2Step, Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMul_32f_C3R,  (const Ipp32f* pSrc1, int src1Step, const Ipp32f* pSrc2,
                                     int src2Step, Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMul_32f_C4R,  (const Ipp32f* pSrc1, int src1Step, const Ipp32f* pSrc2,
                                     int src2Step, Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMul_32f_AC4R, (const Ipp32f* pSrc1, int src1Step, const Ipp32f* pSrc2,
                                     int src2Step, Ipp32f* pDst, int dstStep, IppiSize roiSize))

/* ////////////////////////////////////////////////////////////////////////////
//  Name:       ippiComplement_32s_C1IR
//
//  Purpose:    Converts negative integer number from complement to
//              direct code reserving the sign in the upper bit.
//
//  Return:
//    ippStsNoErr              Ok
//    ippStsNullPtrErr         Pointer is NULL
//    ippStsStepErr            Step is less than or equal to zero
//    ippStsStrideErr          Step is less than the width of an image
//
//  Arguments:
//    pSrcDst                  Pointer to the source/destination image
//    srcdstStep               Step in bytes through the image
//    roiSize                  Size of ROI
*/

IPPAPI (IppStatus, ippiComplement_32s_C1IR, ( Ipp32s* pSrcDst, int srcdstStep, IppiSize roiSize ))


/* ////////////////////////////////////////////////////////////////////////////
//  Name:       ippiDiv_32f_C1R, ippiDiv_32f_C3R ippiDiv_32f_C4R ippiDiv_32f_AC4R
//
//  Purpose:    Divides pixel values of an image by pixel values of
//              another image and places the results in a destination
//              image.
//
//  Return:
//    ippStsNoErr              Ok
//    ippStsNullPtrErr         One of the pointers is NULL
//    ippStsSizeErr            The roiSize has a field with zero or negative value
//    ippStsStepErr            Any of the step values is less than or equal to zero
//    ippStsDivByZero          A warning that a divisor value is zero, the function
//                             execution is continued.
//                             If a dividend is equal to zero, then the result is zero;
//                             if it is greater than zero, then the result is IPP_ABSMAX_32F,
//                             if it is less than zero, then the result is -IPP_ABSMAX_32F
//
//  Arguments:
//    pSrc1                    Pointer to the divisor source image
//    src1Step                 Step through the divisor source image
//    pSrc2                    Pointer to the dividend source image
//    src2Step                 Step through the dividend source image
//    pDst                     Pointer to the destination vector
//    dstStep                  Step through the destination image
//    roiSize                  Size of the ROI
*/

IPPAPI(IppStatus, ippiDiv_32f_C1R,    (const Ipp32f* pSrc1, int src1Step,
                                       const Ipp32f* pSrc2, int src2Step,
                                             Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiDiv_32f_C3R,    (const Ipp32f* pSrc1, int src1Step,
                                       const Ipp32f* pSrc2, int src2Step,
                                             Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiDiv_32f_C4R,    (const Ipp32f* pSrc1, int src1Step,
                                       const Ipp32f* pSrc2, int src2Step,
                                             Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiDiv_32f_AC4R,    (const Ipp32f* pSrc1, int src1Step,
                                        const Ipp32f* pSrc2, int src2Step,
                                             Ipp32f* pDst, int dstStep, IppiSize roiSize))




/* ////////////////////////////////////////////////////////////////////////////
//  Name:       ippiDiv_16s_C1RSfs, ippiDiv_8u_C1RSfs,
//              ippiDiv_16s_C3RSfs, ippiDiv_8u_C3RSfs
//
//  Purpose:    Divides pixel values of an image by pixel values of
//              another image and places the scaled results in a destination
//              image.
//
//  Return:
//    ippStsNoErr              Ok
//    ippStsNullPtrErr         One of the pointers is NULL
//    ippStsSizeErr            The roiSize has a field with zero or negative value
//    ippStsStepErr            Any of the step values is less than or equal to zero
//    ippStsDivByZero          A warning that a divisor value is zero, the function
//                             execution is continued.
//                             If a dividend is equal to zero, then the result is zero;
//                             if it is greater than zero, then the result is IPP_ABSMAX_32F,
//                             if it is less than zero, then the result is -IPP_ABSMAX_32F
//
//  Arguments:
//    pSrc1                    Pointer to the divisor source image
//    src1Step                 Step through the divisor source image
//    pSrc2                    Pointer to the dividend source image
//    src2Step                 Step through the dividend source image
//    pDst                     Pointer to the destination vector
//    dstStep                  Step through the destination image
//    roiSize                  Size of the ROI
//    scaleFactor              Scale factor
*/

IPPAPI(IppStatus, ippiDiv_16s_C1RSfs, (const Ipp16s* pSrc1, int src1Step,
                                       const Ipp16s* pSrc2, int src2Step,
                                             Ipp16s* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiDiv_16s_C3RSfs, (const Ipp16s* pSrc1, int src1Step,
                                       const Ipp16s* pSrc2, int src2Step,
                                             Ipp16s* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiDiv_8u_C1RSfs,  (const Ipp8u* pSrc1, int src1Step,
                                       const Ipp8u* pSrc2, int src2Step,
                                             Ipp8u* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiDiv_8u_C3RSfs,  (const Ipp8u* pSrc1, int src1Step,
                                       const Ipp8u* pSrc2, int src2Step,
                                             Ipp8u* pDst, int dstStep, IppiSize roiSize, int scaleFactor))


/* ////////////////////////////////////////////////////////////////////////////
//  Name:       ippiDivC_32f_C1R, ippiDivC_32f_C3R
//
//  Purpose:    Divides pixel values of a source image by a constant
//              and places the results in a destination image.
//
//  Return:
//    ippStsNoErr              Ok
//    ippStsNullPtrErr         One of the pointers is NULL
//    ippStsSizeErr            The roiSize has a field with zero or negative value
//    ippStsStepErr            The step value is less than or equal to zero
//    ippStsDivByZeroErr       The constant is equal to zero
//
//  Arguments:
//    value                    The constant divisor
//    pSrc                     Pointer to the source image
//    pDst                     Pointer to the destination image
//    roiSize                  Size of the ROI
*/

IPPAPI(IppStatus, ippiDivC_32f_C1R,    (const Ipp32f* pSrc, int srcStep, Ipp32f value,
                                        Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiDivC_32f_C3R,    (const Ipp32f* pSrc, int srcStep, const Ipp32f value[3],
                                        Ipp32f* pDst, int dstStep, IppiSize roiSize))

/* ////////////////////////////////////////////////////////////////////////////
//  Name:       ippiDivC_16s_C1RSfs, ippiDivC_8u_C1RSfs
//              ippiDivC_16s_C3RSfs, ippiDivC_8u_C3RSfs
//
//  Purpose:    Divides pixel values of a source image by a constant
//              and places the scaled results in a destination image.
//
//  Return:
//    ippStsNoErr              Ok
//    ippStsNullPtrErr         One of the pointers is NULL
//    ippStsSizeErr            The roiSize has a field with zero or negative value
//    ippStsStepErr            The step value is less than or equal to zero
//    ippStsDivByZeroErr       The constant is equal to zero
//
//  Arguments:
//    value                    The constant divisor
//    pSrc                     Pointer to the source image
//    pDst                     Pointer to the destination image
//    roiSize                  Size of the ROI
//    scaleFactor              Scale factor
*/

IPPAPI(IppStatus, ippiDivC_16s_C1RSfs, (const Ipp16s* pSrc, int srcStep, Ipp16s value,
                                        Ipp16s* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiDivC_16s_C3RSfs, (const Ipp16s* pSrc, int srcStep, const Ipp16s value[3],
                                        Ipp16s* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiDivC_8u_C1RSfs,  (const Ipp8u* pSrc, int srcStep, Ipp8u value,
                                        Ipp8u* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiDivC_8u_C3RSfs,  (const Ipp8u* pSrc, int srcStep, const Ipp8u value[3],
                                        Ipp8u* pDst, int dstStep, IppiSize roiSize, int scaleFactor))

/* ////////////////////////////////////////////////////////////////////////////
//  Name:       ippiDiv_32f_C1IR, ippiDiv_32f_C3IR ippiDiv_32f_C4IR ippiDiv_32f_AC4IR
//
//  Purpose:    Divides pixel values of an image by pixel values of
//              another image and places the results in a destination
//              image.
//
//  Return:
//    ippStsNoErr              Ok
//    ippStsNullPtrErr         One of the pointers is NULL
//    ippStsSizeErr            The roiSize has a field with zero or negative value
//    ippStsStepErr            Any of the step values is less than or equal to zero
//    ippStsDivByZero          A warning that a divisor value is zero, the function
//                             execution is continued.
//                             If a dividend is equal to zero, then the result is zero;
//                             if it is greater than zero, then the result is IPP_ABSMAX_32F,
//                             if it is less than zero, then the result is -IPP_ABSMAX_32F
//
//  Arguments:
//    pSrc                     Pointer to the divisor source image
//    srcStep                  Step through the divisor source image
//    pSrcDst                  Pointer to the dividend source/destination image
//    srcDstStep               Step through the dividend source/destination image
//    roiSize                  Size of the ROI
*/

IPPAPI(IppStatus, ippiDiv_32f_C1IR,    (const Ipp32f* pSrc, int srcStep,
                                              Ipp32f* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiDiv_32f_C3IR,    (const Ipp32f* pSrc, int srcStep,
                                              Ipp32f* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiDiv_32f_C4IR,    (const Ipp32f* pSrc, int srcStep,
                                              Ipp32f* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiDiv_32f_AC4IR,    (const Ipp32f* pSrc, int srcStep,
                                              Ipp32f* pSrcDst, int srcDstStep, IppiSize roiSize))

/* ////////////////////////////////////////////////////////////////////////////
//  Name:       ippiDiv_16s_C1IRSfs, ippiDiv_8u_C1IRSfs
//              ippiDiv_16s_C3IRSfs, ippiDiv_8u_C3IRSfs
//
//  Purpose:    Divides pixel values of an image by pixel values of
//              another image and places the scaled results in a destination
//              image.
//
//  Return:
//    ippStsNoErr              Ok
//    ippStsNullPtrErr         One of the pointers is NULL
//    ippStsSizeErr            The roiSize has a field with zero or negative value
//    ippStsStepErr            Any of the step values is less than or equal to zero
//    ippStsDivByZero          A warning that a divisor value is zero, the function
//                             execution is continued.
//                             If a dividend is equal to zero, then the result is zero;
//                             if it is greater than zero, then the result is IPP_ABSMAX_32F,
//                             if it is less than zero, then the result is -IPP_ABSMAX_32F
//
//  Arguments:
//    pSrc                     Pointer to the divisor source image
//    srcStep                  Step through the divisor source image
//    pSrcDst                  Pointer to the dividend source/destination image
//    srcDstStep               Step through the dividend source/destination image
//    roiSize                  Size of the ROI
//    scaleFactor              Scale factor
*/

IPPAPI(IppStatus, ippiDiv_16s_C1IRSfs, (const Ipp16s* pSrc, int srcStep,
                                              Ipp16s* pSrcDst, int srcDstStep,
                                              IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiDiv_16s_C3IRSfs, (const Ipp16s* pSrc, int srcStep,
                                              Ipp16s* pSrcDst, int srcDstStep,
                                              IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiDiv_8u_C1IRSfs,  (const Ipp8u* pSrc, int srcStep,
                                              Ipp8u* pSrcDst, int srcDstStep,
                                              IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiDiv_8u_C3IRSfs,  (const Ipp8u* pSrc, int srcStep,
                                              Ipp8u* pSrcDst, int srcDstStep,
                                              IppiSize roiSize, int scaleFactor))

/* ////////////////////////////////////////////////////////////////////////////
//  Name:       ippsDivC_32f_C1IR, ippsDivC_32f_C3IR
//
//  Purpose:    Divides pixel values of a source image by a constant
//              and places the results in the same image.
//
//  Return:
//    ippStsNoErr              Ok
//    ippStsNullPtrErr         The pointer is NULL
//    ippStsSizeErr            The roiSize has a field with zero or negative value
//    ippStsStepErr            The step value is less than or equal to zero
//    ippStsDivByZeroErr       The constant is equal zero
//
//  Arguments:
//    value                    The constant divisor
//    pSrcDst                  Pointer to the soutce/destination image
//    srcDstStep               Step through the source/destination image
//    roiSize                  Size of the ROI
*/

IPPAPI(IppStatus, ippiDivC_32f_C1IR,    (Ipp32f value, Ipp32f* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiDivC_32f_C3IR,    (const Ipp32f value[3], Ipp32f* pSrcDst, int srcDstStep, IppiSize roiSize))

/* ////////////////////////////////////////////////////////////////////////////
//  Name:       ippsDivC_16s_C1IRSfs, ippsDivC_8u_C1IRSfs,
//              ippsDivC_16s_C3IRSfs, ippsDivC_8u_C3IRSfs
//
//  Purpose:    Divides pixel values of a source image by a constant
//              and places the scaled results in the same image.
//
//  Return:
//    ippStsNoErr              Ok
//    ippStsNullPtrErr         The pointer is NULL
//    ippStsSizeErr            The roiSize has a field with zero or negative value
//    ippStsStepErr            The step value is less than or equal to zero
//    ippStsDivByZeroErr       The constant is equal zero
//
//  Arguments:
//    value                    The constant divisor
//    pSrcDst                  Pointer to the soutce/destination image
//    srcDstStep               Step through the source/destination image
//    roiSize                  Size of the ROI
//    scaleFactor              Scale factor
*/

IPPAPI(IppStatus, ippiDivC_16s_C1IRSfs, (Ipp16s value, Ipp16s* pSrcDst,
                                         int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiDivC_16s_C3IRSfs, (const Ipp16s value[3], Ipp16s* pSrcDst,
                                         int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiDivC_8u_C1IRSfs,  (Ipp8u value, Ipp8u* pSrcDst,
                                         int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiDivC_8u_C3IRSfs,  (const Ipp8u value[3], Ipp8u* pSrcDst,
                                         int srcDstStep, IppiSize roiSize, int scaleFactor))


/* ////////////////////////////////////////////////////////////////////////////
//  Names:      ippiAbs_16s_C1R
//              ippiAbs_16s_C3R
//              ippiAbs_16s_C4R
//              ippiAbs_16s_AC4R
//              ippiAbs_32f_C1R
//              ippiAbs_32f_C3R
//              ippiAbs_32f_C4R
//              ippiAbs_32f_AC4R
//
//              ippiAbs_16s_C1IR
//              ippiAbs_16s_C3IR
//              ippiAbs_16s_C4IR
//              ippiAbs_16s_AC4IR
//              ippiAbs_32f_C1IR
//              ippiAbs_32f_C3IR
//              ippiAbs_32f_C4IR
//              ippiAbs_32f_AC4IR
//
//  Purpose:    computes absolute values of each pixel of asource image and
//              places results in the output image
//  Return:
//   ippStsNoErr       Ok
//   ippStsNullPtrErr  Some of the pointers is NULL
//   ippStsSizeErr     The roiSize has a field with negative or zero value
//
//  Parameters:
//   pSrc       pointer to the input image
//   srcStep    size of the input image scan-line
//   pDst       pointer to the output image
//   dstStep    size of the output image scan-line
//   pSrcDst    pointer to the input/output image (for in-place function)
//   srcDstStep size of the input/output image scan-line (for in-place function)
//   roiSize    ROI size of the output image
*/
IPPAPI(IppStatus,ippiAbs_16s_C1R,(const Ipp16s* pSrc, int srcStep, Ipp16s* pDst, int dstStep,
       IppiSize roiSize))
IPPAPI(IppStatus,ippiAbs_16s_C3R,(const Ipp16s* pSrc, int srcStep, Ipp16s* pDst, int dstStep,
       IppiSize roiSize))
IPPAPI(IppStatus,ippiAbs_16s_AC4R,(const Ipp16s* pSrc, int srcStep, Ipp16s* pDst, int dstStep,
       IppiSize roiSize))
IPPAPI(IppStatus,ippiAbs_32f_C1R,(const Ipp32f* pSrc, int srcStep, Ipp32f* pDst, int dstStep,
       IppiSize roiSize))
IPPAPI(IppStatus,ippiAbs_32f_C3R,(const Ipp32f* pSrc, int srcStep, Ipp32f* pDst, int dstStep,
       IppiSize roiSize))
IPPAPI(IppStatus,ippiAbs_32f_AC4R,(const Ipp32f* pSrc, int srcStep, Ipp32f* pDst, int dstStep,
       IppiSize roiSize))
IPPAPI(IppStatus,ippiAbs_16s_C1IR,(Ipp16s* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiAbs_16s_C3IR,(Ipp16s* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiAbs_16s_AC4IR,(Ipp16s* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiAbs_32f_C1IR,(Ipp32f* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiAbs_32f_C3IR,(Ipp32f* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiAbs_32f_AC4IR,(Ipp32f* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiAbs_16s_C4R,(const Ipp16s* pSrc, int srcStep, Ipp16s* pDst, int dstStep,
       IppiSize roiSize))
IPPAPI(IppStatus,ippiAbs_32f_C4R,(const Ipp32f* pSrc, int srcStep, Ipp32f* pDst, int dstStep,
       IppiSize roiSize))
IPPAPI(IppStatus,ippiAbs_16s_C4IR,(Ipp16s* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiAbs_32f_C4IR,(Ipp32f* pSrcDst, int srcDstStep, IppiSize roiSize))


/* ////////////////////////////////////////////////////////////////////////////
//  Names:      ippiSqr_8u_C1RSfs
//              ippiSqr_8u_C3RSfs
//              ippiSqr_8u_AC4RSfs
//              ippiSqr_8u_C4RSfs
//              ippiSqr_16u_C1RSfs
//              ippiSqr_16u_C3RSfs
//              ippiSqr_16u_AC4RSfs
//              ippiSqr_16u_C4RSfs
//              ippiSqr_16s_C1RSfs
//              ippiSqr_16s_C3RSfs
//              ippiSqr_16s_AC4RSfs
//              ippiSqr_16s_C4RSfs
//              ippiSqr_32f_C1R
//              ippiSqr_32f_C3R
//              ippiSqr_32f_AC4R
//              ippiSqr_32f_C4R
//
//              ippiSqr_8u_C1IRSfs
//              ippiSqr_8u_C3IRSfs
//              ippiSqr_8u_AC4IRSfs
//              ippiSqr_8u_C4IRSfs
//              ippiSqr_16u_C1IRSfs
//              ippiSqr_16u_C3IRSfs
//              ippiSqr_16u_AC4IRSfs
//              ippiSqr_16u_C4IRSfs
//              ippiSqr_16s_C1IRSfs
//              ippiSqr_16s_C3IRSfs
//              ippiSqr_16s_AC4IRSfs
//              ippiSqr_16s_C4IRSfs
//              ippiSqr_32f_C1IR
//              ippiSqr_32f_C3IR
//              ippiSqr_32f_AC4IR
//              ippiSqr_32f_C4IR
//  Purpose:    computes squares of pixel values of an image and
//              stores results in the output image
//  Return:
//   ippStsNoErr       Ok
//   ippStsNullPtrErr  One of the pointers is NULL
//   ippStsSizeErr     The roiSize has a field with negative or zero value
//
//  Parameters:
//   pSrc       pointer to the input image
//   srcStep    size of the input image scan-line
//   pDst       pointer to the output image
//   dstStep    size of the output image scan-line
//   pSrcDst    pointer to the input/output image (for in-place function)
//   srcDstStep size of the input/output image scan-line (for in-place function)
//   roiSize    ROI size of the output image
//   scaleFactor scaleFactor
*/

IPPAPI(IppStatus,ippiSqr_8u_C1RSfs,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus,ippiSqr_8u_C3RSfs,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus,ippiSqr_8u_AC4RSfs,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus,ippiSqr_8u_C4RSfs,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus,ippiSqr_16u_C1RSfs,(const Ipp16u* pSrc, int srcStep,
       Ipp16u* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus,ippiSqr_16u_C3RSfs,(const Ipp16u* pSrc, int srcStep,
       Ipp16u* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus,ippiSqr_16u_AC4RSfs,(const Ipp16u* pSrc, int srcStep,
       Ipp16u* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus,ippiSqr_16u_C4RSfs,(const Ipp16u* pSrc, int srcStep,
       Ipp16u* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus,ippiSqr_16s_C1RSfs,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus,ippiSqr_16s_C3RSfs,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus,ippiSqr_16s_AC4RSfs,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus,ippiSqr_16s_C4RSfs,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus,ippiSqr_32f_C1R, (const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiSqr_32f_C3R, (const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiSqr_32f_AC4R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiSqr_32f_C4R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiSqr_8u_C1IRSfs, (Ipp8u* pSrcDst, int srcDstStep,
       IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus,ippiSqr_8u_C3IRSfs, (Ipp8u* pSrcDst, int srcDstStep,
       IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus,ippiSqr_8u_AC4IRSfs,(Ipp8u* pSrcDst, int srcDstStep,
       IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus,ippiSqr_8u_C4IRSfs,(Ipp8u* pSrcDst, int srcDstStep,
       IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus,ippiSqr_16u_C1IRSfs, (Ipp16u* pSrcDst, int srcDstStep,
       IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus,ippiSqr_16u_C3IRSfs, (Ipp16u* pSrcDst, int srcDstStep,
       IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus,ippiSqr_16u_AC4IRSfs,(Ipp16u* pSrcDst, int srcDstStep,
       IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus,ippiSqr_16u_C4IRSfs,(Ipp16u* pSrcDst, int srcDstStep,
       IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus,ippiSqr_16s_C1IRSfs, (Ipp16s* pSrcDst, int srcDstStep,
       IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus,ippiSqr_16s_C3IRSfs, (Ipp16s* pSrcDst, int srcDstStep,
       IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus,ippiSqr_16s_AC4IRSfs,(Ipp16s* pSrcDst, int srcDstStep,
       IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus,ippiSqr_16s_C4IRSfs,(Ipp16s* pSrcDst, int srcDstStep,
       IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus,ippiSqr_32f_C1IR, (Ipp32f* pSrcDst, int srcDstStep,
       IppiSize roiSize))
IPPAPI(IppStatus,ippiSqr_32f_C3IR, (Ipp32f* pSrcDst, int srcDstStep,
       IppiSize roiSize))
IPPAPI(IppStatus,ippiSqr_32f_AC4IR,(Ipp32f* pSrcDst, int srcDstStep,
       IppiSize roiSize))
IPPAPI(IppStatus,ippiSqr_32f_C4IR,(Ipp32f* pSrcDst, int srcDstStep,
       IppiSize roiSize))


/* ////////////////////////////////////////////////////////////////////////////
//  Names:      ippiSqrt_8u_C1RSfs
//              ippiSqrt_8u_C3RSfs
//              ippiSqrt_8u_AC4RSfs
//              ippiSqrt_16u_C1RSfs
//              ippiSqrt_16u_C3RSfs
//              ippiSqrt_16u_AC4RSfs
//              ippiSqrt_16s_C1RSfs
//              ippiSqrt_16s_C3RSfs
//              ippiSqrt_16s_AC4RSfs
//              ippiSqrt_32f_C1R
//              ippiSqrt_32f_C3R
//              ippiSqrt_32f_AC4R
//
//              ippiSqrt_8u_C1IRSfs
//              ippiSqrt_8u_C3IRSfs
//              ippiSqrt_8u_AC4IRSfs
//              ippiSqrt_16u_C1IRSfs
//              ippiSqrt_16u_C3IRSfs
//              ippiSqrt_16u_AC4IRSfs
//              ippiSqrt_16s_C1IRSfs
//              ippiSqrt_16s_C3IRSfs
//              ippiSqrt_16s_AC4IRSfs
//              ippiSqrt_32f_C1IR
//              ippiSqrt_32f_C3IR
//              ippiSqrt_32f_AC4IR
//              ippiSqrt_32f_C4IR
//  Purpose:    computes square roots of pixel values of a source image and
//              stores results in the output image
//  Return:
//   ippStsNoErr       Ok
//   ippStsNullPtrErr  Some of pointers to pSrc or pDst are NULL
//   ippStsSizeErr     Some size of dstRoi less or equal zero
//   ippStsSqrtNegArg  Negative value in source pixel
//
//  Parameters:
//   pSrc       pointer to input image
//   srcStep    size of input image scan-line
//   pDst       pointer to output image
//   dstStep    size of output image scan-line
//   pSrcDst    pointer to the input/output image (for in-place function)
//   srcDstStep size of input/output image scan-line (for in-place function)
//   roiSize    ROI size of output image
//   sacleFactor scaleFactor
*/
IPPAPI(IppStatus,ippiSqrt_8u_C1RSfs,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus,ippiSqrt_8u_C3RSfs,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus,ippiSqrt_8u_AC4RSfs,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus,ippiSqrt_16u_C1RSfs,(const Ipp16u* pSrc, int srcStep,
       Ipp16u* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus,ippiSqrt_16u_C3RSfs,(const Ipp16u* pSrc, int srcStep,
       Ipp16u* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus,ippiSqrt_16u_AC4RSfs,(const Ipp16u* pSrc, int srcStep,
       Ipp16u* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus,ippiSqrt_16s_C1RSfs,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus,ippiSqrt_16s_C3RSfs,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus,ippiSqrt_16s_AC4RSfs,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus,ippiSqrt_32f_C1R, (const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiSqrt_32f_C3R, (const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiSqrt_32f_AC4R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiSqrt_8u_C1IRSfs, (Ipp8u* pSrcDst, int srcDstStep,
       IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus,ippiSqrt_8u_C3IRSfs, (Ipp8u* pSrcDst, int srcDstStep,
       IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus,ippiSqrt_8u_AC4IRSfs,(Ipp8u* pSrcDst, int srcDstStep,
       IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus,ippiSqrt_16u_C1IRSfs, (Ipp16u* pSrcDst, int srcDstStep,
       IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus,ippiSqrt_16u_C3IRSfs, (Ipp16u* pSrcDst, int srcDstStep,
       IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus,ippiSqrt_16u_AC4IRSfs,(Ipp16u* pSrcDst, int srcDstStep,
       IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus,ippiSqrt_16s_C1IRSfs, (Ipp16s* pSrcDst, int srcDstStep,
       IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus,ippiSqrt_16s_C3IRSfs, (Ipp16s* pSrcDst, int srcDstStep,
       IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus,ippiSqrt_16s_AC4IRSfs,(Ipp16s* pSrcDst, int srcDstStep,
       IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus,ippiSqrt_32f_C1IR, (Ipp32f* pSrcDst, int srcDstStep,
       IppiSize roiSize))
IPPAPI(IppStatus,ippiSqrt_32f_C3IR, (Ipp32f* pSrcDst, int srcDstStep,
       IppiSize roiSize))
IPPAPI(IppStatus,ippiSqrt_32f_AC4IR,(Ipp32f* pSrcDst, int srcDstStep,
       IppiSize roiSize))
IPPAPI(IppStatus,ippiSqrt_32f_C4IR,(Ipp32f* pSrcDst, int srcDstStep,
       IppiSize roiSize))



/* /////////////////////////////////////////////////////////////////////////////
//  Names:
//  ippiLn_32f_C1IR   ippiLn_16s_C1IRSfs  ippiLn_8u_C1IRSfs
//  ippiLn_32f_C3IR   ippiLn_16s_C3IRSfs  ippiLn_8u_C3IRSfs
//  ippiLn_32f_C1R    ippiLn_16s_C1RSfs   ippiLn_8u_C1RSfs
//  ippiLn_32f_C3R    ippiLn_16s_C3RSfs   ippiLn_8u_C3RSfs
//  Purpose:
//     computes the natural logarithm of every pixel values in a source image
//  Parameters:
//    pSrc         Pointer to the source image.
//    pDst         Pointer to the destination image.
//    pSrcDst      Pointer to the input/output image for inplace functions.
//    srcStep      Step through the source image.
//    dstStep      Step through the destination image.
//    srcDstStep   Step through the input/output image for inplace functions.
//    roiSize      Size of the ROI.
//    scaleFactor  Scale factor for integer data.
//  Return:
//    ippStsNullPtrErr    One of the pointers is NULL
//    ippStsSizeErr       width or height of images is less than or equal to zero
//    ippStsStepErr       Any of the step values is less than or equal to zero
//    ippStsLnZeroArg     Zero value of the source pixel
//    ippStsLnNegArg      Negative value of the source pixel
//    ippStsNoErr         otherwise
*/

IPPAPI(IppStatus, ippiLn_32f_C1IR,(Ipp32f* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiLn_32f_C3IR,(Ipp32f* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiLn_32f_C1R, (const Ipp32f* pSrc, int srcStep, Ipp32f* pDst,
                                                       int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiLn_32f_C3R, (const Ipp32f* pSrc, int srcStep, Ipp32f* pDst,
                                                       int dstStep, IppiSize roiSize))

IPPAPI(IppStatus, ippiLn_16s_C1IRSfs,(Ipp16s* pSrcDst, int srcDstStep,
                                    IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiLn_16s_C3IRSfs,(Ipp16s* pSrcDst, int srcDstStep,
                                    IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiLn_16s_C1RSfs, (const Ipp16s* pSrc, int srcStep, Ipp16s* pDst,
                                     int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiLn_16s_C3RSfs, (const Ipp16s* pSrc, int srcStep, Ipp16s* pDst,
                                     int dstStep, IppiSize roiSize, int scaleFactor))


IPPAPI(IppStatus, ippiLn_8u_C1IRSfs,(Ipp8u* pSrcDst, int srcDstStep,
                                    IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiLn_8u_C3IRSfs,(Ipp8u* pSrcDst, int srcDstStep,
                                    IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiLn_8u_C1RSfs, (const Ipp8u* pSrc, int srcStep, Ipp8u* pDst,
                                     int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiLn_8u_C3RSfs, (const Ipp8u* pSrc, int srcStep, Ipp8u* pDst,
                                     int dstStep, IppiSize roiSize, int scaleFactor))

/* /////////////////////////////////////////////////////////////////////////////
//  Names:
//  ippiExp_32f_C1IR   ippiExp_16s_C1IRSfs  ippiExp_8u_C1IRSfs
//  ippiExp_32f_C3IR   ippiExp_16s_C3IRSfs  ippiExp_8u_C3IRSfs
//  ippiExp_32f_C1R    ippiExp_16s_C1RSfs   ippiExp_8u_C1RSfs
//  ippiExp_32f_C3R    ippiExp_16s_C3RSfs   ippiExp_8u_C3RSfs
//  Purpose:
//     computes the exponent of pixel values in a source image
//  Parameters:
//    pSrc         Pointer to the source image.
//    pDst         Pointer to the destination image.
//    pSrcDst      Pointer to the input/output image for inplace functions.
//    srcStep      Step through the source image.
//    dstStep      Step through the in destination image.
//    srcDstStep   Step through the input/output image for inplace functions.
//    roiSize      Size of the ROI.
//    scaleFactor  Scale factor for integer data.
//  Return:
//    ippStsNullPtrErr    One of the pointers is NULL
//    ippStsSizeErr       width or height of images is less than or equal to zero
//    ippStsStepErr       Any the step values is less than or equal to zero
//    ippStsNoErr         otherwise
*/


IPPAPI(IppStatus, ippiExp_32f_C1IR,(Ipp32f* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiExp_32f_C3IR,(Ipp32f* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiExp_32f_C1R, (const Ipp32f* pSrc, int srcStep, Ipp32f* pDst,
                                                       int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiExp_32f_C3R, (const Ipp32f* pSrc, int srcStep, Ipp32f* pDst,
                                                       int dstStep, IppiSize roiSize))

IPPAPI(IppStatus, ippiExp_16s_C1IRSfs,(Ipp16s* pSrcDst, int srcDstStep,
                                    IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiExp_16s_C3IRSfs,(Ipp16s* pSrcDst, int srcDstStep,
                                    IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiExp_16s_C1RSfs, (const Ipp16s* pSrc, int srcStep, Ipp16s* pDst,
                                     int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiExp_16s_C3RSfs, (const Ipp16s* pSrc, int srcStep, Ipp16s* pDst,
                                     int dstStep, IppiSize roiSize, int scaleFactor))


IPPAPI(IppStatus, ippiExp_8u_C1IRSfs,(Ipp8u* pSrcDst, int srcDstStep,
                                    IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiExp_8u_C3IRSfs,(Ipp8u* pSrcDst, int srcDstStep,
                                    IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiExp_8u_C1RSfs, (const Ipp8u* pSrc, int srcStep, Ipp8u* pDst,
                                     int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiExp_8u_C3RSfs, (const Ipp8u* pSrc, int srcStep, Ipp8u* pDst,
                                     int dstStep, IppiSize roiSize, int scaleFactor))

/* /////////////////////////////////////////////////////////////////////////////
//                  Arithmetics functions with complex data
///////////////////////////////////////////////////////////////////////////// */
/* ////////////////////////////////////////////////////////////////////////////
//  Name:       ippiAddC_32fc_C1R, ippiAddC_32fc_C3R, ippiAddC_32fc_AC4R,
//              ippiSubC_32fc_C1R, ippiSubC_32fc_C3R, ippiSubC_32fc_AC4R,
//              ippiMulC_32fc_C1R, ippiMulC_32fc_C3R, ippiMulC_32fc_AC4R
//              ippiDivC_32fc_C1R, ippiDivC_32fc_C3R, ippiDivC_32fc_AC4R
//
//  Purpose:    Makes corresponding operations with a constant and values of each element
//              of the source image and stores results in the destination image.
//
//  Return:
//    ippStsNoErr              Ok
//    ippStsNullPtrErr         One of the pointers is NULL
//    ippStsSizeErr            The width or height of images is less than or equal to zero
//    ippStsStepErr            Any of the step values is less than or equal to zero
//
//  Arguments:
//    value                    The constant value for the specified operation
//    pSrc                     Pointer to the source image
//    srcStep                  Step through the source image
//    pDst                     Pointer to the destination image
//    dstStep                  Step through the destination image
//    roiSize                  Size of the ROI
*/

IPPAPI(IppStatus, ippiAddC_32fc_C1R,  (const Ipp32fc* pSrc, int srcStep, Ipp32fc value, Ipp32fc* pDst,
                                      int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAddC_32fc_C3R,  (const Ipp32fc* pSrc, int srcStep, const Ipp32fc value[3],
                                      Ipp32fc* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAddC_32fc_AC4R, (const Ipp32fc* pSrc, int srcStep, const Ipp32fc value[3],
                                      Ipp32fc* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiSubC_32fc_C1R,  (const Ipp32fc* pSrc, int srcStep, Ipp32fc value, Ipp32fc* pDst,
                                      int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiSubC_32fc_C3R,  (const Ipp32fc* pSrc, int srcStep, const Ipp32fc value[3],
                                      Ipp32fc* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiSubC_32fc_AC4R, (const Ipp32fc* pSrc, int srcStep, const Ipp32fc value[3],
                                      Ipp32fc* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMulC_32fc_C1R,  (const Ipp32fc* pSrc, int srcStep, Ipp32fc value, Ipp32fc* pDst,
                                      int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMulC_32fc_C3R,  (const Ipp32fc* pSrc, int srcStep, const Ipp32fc value[3],
                                      Ipp32fc* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMulC_32fc_AC4R, (const Ipp32fc* pSrc, int srcStep, const Ipp32fc value[3],
                                      Ipp32fc* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiDivC_32fc_C1R,  (const Ipp32fc* pSrc,
                                      int srcStep, Ipp32fc value, Ipp32fc* pDst,
                                      int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiDivC_32fc_C3R,  (const Ipp32fc* pSrc,
                                      int srcStep, const Ipp32fc value[3], Ipp32fc* pDst,
                                      int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiDivC_32fc_AC4R, (const Ipp32fc* pSrc,
                                      int srcStep, const Ipp32fc value[3], Ipp32fc* pDst,
                                      int dstStep, IppiSize roiSize))

/* ////////////////////////////////////////////////////////////////////////////
//  Name:       ippiAddC_32fc_C1IR, ippiAddC_32fc_C3IR, ippiAddC_32fc_AC4IR,
//              ippiSubC_32fc_C1IR, ippiSubC_32fc_C3IR, ippiSubC_32fc_AC4IR,
//              ippiMulC_32fc_C1IR, ippiMulC_32fc_C3IR, ippiMulC_32fc_AC4IR
//              ippiDivC_32fc_C1IR, ippiDivC_32fc_C3IR, ippiDivC_32fc_AC4IR
//
//  Purpose:    Makes corresponding operations with a constant and values of each elements of
//              an image and stores results in the same image.
//
//  Return:
//    ippStsNoErr              Ok
//    ippStsNullPtrErr         One of the pointers is NULL
//    ippStsSizeErr            The width or height of image is less than or equal to zero
//    ippStsStepErr            The step value is less than or equal to zero
//
//  Arguments:
//    value                    The constant value for the specified operation
//    pSrcDst                  Pointer to the image
//    srcDstStep               Step through the image
//    roiSize                  Size of the ROI
*/
IPPAPI(IppStatus, ippiAddC_32fc_C1IR,  (Ipp32fc value, Ipp32fc* pSrcDst, int srcDstStep,
                                       IppiSize roiSize))
IPPAPI(IppStatus, ippiAddC_32fc_C3IR,  (const Ipp32fc value[3], Ipp32fc* pSrcDst, int srcDstStep,
                                       IppiSize roiSize))
IPPAPI(IppStatus, ippiAddC_32fc_AC4IR, (const Ipp32fc value[3], Ipp32fc* pSrcDst, int srcDstStep,
                                       IppiSize roiSize))
IPPAPI(IppStatus, ippiSubC_32fc_C1IR,  (Ipp32fc value, Ipp32fc* pSrcDst, int srcDstStep,
                                       IppiSize roiSize))
IPPAPI(IppStatus, ippiSubC_32fc_C3IR,  (const Ipp32fc value[3], Ipp32fc* pSrcDst, int srcDstStep,
                                       IppiSize roiSize))
IPPAPI(IppStatus, ippiSubC_32fc_AC4IR, (const Ipp32fc value[3], Ipp32fc* pSrcDst, int srcDstStep,
                                       IppiSize roiSize))
IPPAPI(IppStatus, ippiMulC_32fc_C1IR,  (Ipp32fc value, Ipp32fc* pSrcDst, int srcDstStep,
                                       IppiSize roiSize))
IPPAPI(IppStatus, ippiMulC_32fc_C3IR,  (const Ipp32fc value[3], Ipp32fc* pSrcDst, int srcDstStep,
                                       IppiSize roiSize))
IPPAPI(IppStatus, ippiMulC_32fc_AC4IR, (const Ipp32fc value[3], Ipp32fc* pSrcDst, int srcDstStep,
                                       IppiSize roiSize))
IPPAPI(IppStatus, ippiDivC_32fc_C1IR,  (Ipp32fc value, Ipp32fc* pSrcDst, int srcDstStep,
                                       IppiSize roiSize))
IPPAPI(IppStatus, ippiDivC_32fc_C3IR,  (const Ipp32fc value[3], Ipp32fc* pSrcDst, int srcDstStep,
                                       IppiSize roiSize))
IPPAPI(IppStatus, ippiDivC_32fc_AC4IR, (const Ipp32fc value[3], Ipp32fc* pSrcDst, int srcDstStep,
                                       IppiSize roiSize))

/* ////////////////////////////////////////////////////////////////////////////
//  Name:       ippiAdd_32fc_C1IR, ippiAdd_32fc_C3IR, ippiAdd_32fc_AC4IR,
//              ippiSub_32fc_C1IR, ippiSub_32fc_C3IR, ippiSub_32fc_AC4IR,
//              ippiMul_32fc_C1IR, ippiMul_32fc_C3IR, ippiMul_32fc_AC4IR
//              ippiDiv_32fc_C1IR, ippiDiv_32fc_C3IR, ippiDiv_32fc_AC4IR
//
//  Purpose:    Makes corresponding operations with values of each elements of
//              two source images and stores results in the destination image.
//
//  Return:
//    ippStsNoErr              Ok
//    ippStsNullPtrErr         One of the pointers is NULL
//    ippStsSizeErr            The width or height of images is less than or equal to zero
//    ippStsStepErr            Any of the step values is less than or equal to zero
//
//  Arguments:
//    pSrc                     Pointer to the source image
//    srcStep                  Step through the source image
//    pSrcDst                  Pointer to the source and destination image
//    srcDstStep               Step through the source and destination image
//    roiSize                  Size of the ROI
*/

IPPAPI(IppStatus, ippiAdd_32fc_C1IR,  (const Ipp32fc* pSrc, int srcStep, Ipp32fc* pSrcDst,
                                      int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAdd_32fc_C3IR,  (const Ipp32fc* pSrc, int srcStep, Ipp32fc* pSrcDst,
                                      int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAdd_32fc_AC4IR, (const Ipp32fc* pSrc, int srcStep, Ipp32fc* pSrcDst,
                                      int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiSub_32fc_C1IR,  (const Ipp32fc* pSrc, int srcStep, Ipp32fc* pSrcDst,
                                      int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiSub_32fc_C3IR,  (const Ipp32fc* pSrc, int srcStep, Ipp32fc* pSrcDst,
                                      int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiSub_32fc_AC4IR, (const Ipp32fc* pSrc, int srcStep, Ipp32fc* pSrcDst,
                                      int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMul_32fc_C1IR,  (const Ipp32fc* pSrc, int srcStep, Ipp32fc* pSrcDst,
                                      int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMul_32fc_C3IR,  (const Ipp32fc* pSrc, int srcStep, Ipp32fc* pSrcDst,
                                      int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMul_32fc_AC4IR, (const Ipp32fc* pSrc, int srcStep, Ipp32fc* pSrcDst,
                                      int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiDiv_32fc_C1IR,  (const Ipp32fc* pSrc, int srcStep, Ipp32fc* pSrcDst,
                                      int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiDiv_32fc_C3IR,  (const Ipp32fc* pSrc, int srcStep, Ipp32fc* pSrcDst,
                                      int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiDiv_32fc_AC4IR, (const Ipp32fc* pSrc, int srcStep, Ipp32fc* pSrcDst,
                                      int srcDstStep, IppiSize roiSize))

/* ////////////////////////////////////////////////////////////////////////////
//  Name:       ippiAdd_32fc_C1R, ippiAdd_32fc_C3R, ippiAdd_32fc_AC4R,
//              ippiSub_32fc_C1R, ippiSub_32fc_C3R, ippiSub_32fc_AC4R,
//              ippiMul_32fc_C1R, ippiMul_32fc_C3R, ippiMul_32fc_AC4R
//              ippiDiv_32fc_C1R, ippiDiv_32fc_C3R, ippiDiv_32fc_AC4R
//
//  Purpose:    Makes corresponding operation with values of each elements of two
//              source images and stores results in the destination image.
//
//  Return:
//    ippStsNoErr              Ok
//    ippStsNullPtrErr         One of the pointers is NULL
//    ippStsSizeErr            The width or height of images is less than or equal to zero
//    ippStsStepErr            Any of the step values is less than or equal to zero
//
//  Arguments:
//    pSrc1, pSrc2             Pointers to the source images
//    src1Step, src2Step       Steps through the source images
//    pDst                     Pointer to the destination image
//    dstStep                  Steps through the destination image
//    roiSize                  Size of the ROI
*/

IPPAPI(IppStatus, ippiAdd_32fc_C1R,  (const Ipp32fc* pSrc1, int src1Step, const Ipp32fc* pSrc2,
                                     int src2Step, Ipp32fc* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAdd_32fc_C3R,  (const Ipp32fc* pSrc1, int src1Step, const Ipp32fc* pSrc2,
                                     int src2Step, Ipp32fc* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAdd_32fc_AC4R, (const Ipp32fc* pSrc1, int src1Step, const Ipp32fc* pSrc2,
                                     int src2Step, Ipp32fc* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiSub_32fc_C1R,  (const Ipp32fc* pSrc1, int src1Step, const Ipp32fc* pSrc2,
                                     int src2Step, Ipp32fc* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiSub_32fc_C3R,  (const Ipp32fc* pSrc1, int src1Step, const Ipp32fc* pSrc2,
                                     int src2Step, Ipp32fc* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiSub_32fc_AC4R, (const Ipp32fc* pSrc1, int src1Step, const Ipp32fc* pSrc2,
                                     int src2Step, Ipp32fc* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMul_32fc_C1R,  (const Ipp32fc* pSrc1, int src1Step, const Ipp32fc* pSrc2,
                                     int src2Step, Ipp32fc* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMul_32fc_C3R,  (const Ipp32fc* pSrc1, int src1Step, const Ipp32fc* pSrc2,
                                     int src2Step, Ipp32fc* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMul_32fc_AC4R, (const Ipp32fc* pSrc1, int src1Step, const Ipp32fc* pSrc2,
                                     int src2Step, Ipp32fc* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiDiv_32fc_C1R,  (const Ipp32fc* pSrc1, int src1Step, const Ipp32fc* pSrc2,
                                     int src2Step, Ipp32fc* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiDiv_32fc_C3R,  (const Ipp32fc* pSrc1, int src1Step, const Ipp32fc* pSrc2,
                                     int src2Step, Ipp32fc* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiDiv_32fc_AC4R, (const Ipp32fc* pSrc1, int src1Step, const Ipp32fc* pSrc2,
                                     int src2Step, Ipp32fc* pDst, int dstStep, IppiSize roiSize))

/* ////////////////////////////////////////////////////////////////////////////
//  Name:       ippiAdd_16sc_C1IRSfs, ippiAdd_16sc_C3IRSfs, ippiAdd_16sc_AC4IRSfs,
//              ippiSub_16sc_C1IRSfs, ippiSub_16sc_C3IRSfs, ippiSub_16sc_AC4IRSfs,
//              ippiMul_16sc_C1IRSfs, ippiMul_16sc_C3IRSfs, ippiMul_16sc_AC4IRSfs,
//              ippiDiv_16sc_C1IRSfs, ippiDiv_16sc_C3IRSfs, ippiDiv_16sc_AC4IRSfs
//
//  Purpose:    Makes corresponding operations with values of each elements of
//              two source images and stores results in the destination image.
//
//  Return:
//    ippStsNoErr              Ok
//    iippStsNullPtrErr        One of the pointers is NULL
//    ippStsSizeErr            The width or height of images is less than or equal to zero
//    ippStsStepErr            Any of the step values is less than or equal to zero
//
//  Arguments:
//    pSrc                     Pointer to the source image
//    srcStep                  Step through the source image
//    pSrcDst                  Pointer to the source and destination image
//    srcDstStep               Step through the source and destination image
//    roiSize                  Size of the ROI
//    scaleFactor              Scale factor
*/

IPPAPI(IppStatus, ippiAdd_16sc_C1IRSfs,  (const Ipp16sc* pSrc, int srcStep, Ipp16sc* pSrcDst,
                                         int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiAdd_16sc_C3IRSfs,  (const Ipp16sc* pSrc, int srcStep, Ipp16sc* pSrcDst,
                                         int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiAdd_16sc_AC4IRSfs, (const Ipp16sc* pSrc, int srcStep, Ipp16sc* pSrcDst,
                                          int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiSub_16sc_C1IRSfs,  (const Ipp16sc* pSrc, int srcStep, Ipp16sc* pSrcDst,
                                          int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiSub_16sc_C3IRSfs,  (const Ipp16sc* pSrc, int srcStep, Ipp16sc* pSrcDst,
                                          int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiSub_16sc_AC4IRSfs, (const Ipp16sc* pSrc, int srcStep, Ipp16sc* pSrcDst,
                                          int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiMul_16sc_C1IRSfs,  (const Ipp16sc* pSrc, int srcStep, Ipp16sc* pSrcDst,
                                          int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiMul_16sc_C3IRSfs,  (const Ipp16sc* pSrc, int srcStep, Ipp16sc* pSrcDst,
                                          int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiMul_16sc_AC4IRSfs, (const Ipp16sc* pSrc, int srcStep, Ipp16sc* pSrcDst,
                                          int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiDiv_16sc_C1IRSfs,  (const Ipp16sc* pSrc, int srcStep, Ipp16sc* pSrcDst,
                                          int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiDiv_16sc_C3IRSfs,  (const Ipp16sc* pSrc, int srcStep, Ipp16sc* pSrcDst,
                                          int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiDiv_16sc_AC4IRSfs, (const Ipp16sc* pSrc, int srcStep, Ipp16sc* pSrcDst,
                                          int srcDstStep, IppiSize roiSize, int scaleFactor))

/* ////////////////////////////////////////////////////////////////////////////
//  Name:       ippiAdd_16sc_C1RSfs, ippiAdd_16sc_C3RSfs, ippiAdd_16sc_AC4RSfs,
//              ippiSub_16sc_C1RSfs, ippiSub_16sc_C3RSfs, ippiSub_16sc_AC4RSfs,
//              ippiMul_16sc_C1RSfs, ippiMul_16sc_C3RSfs, ippiMul_16sc_AC4RSfs,
//              ippiDiv_16sc_C1RSfs, ippiDiv_16sc_C3RSfs, ippiDiv_16sc_AC4RSfs
//
//  Purpose:    Makes corresponding operation with values of each elements of two
//              source images and stores results in the destination image.
//
//  Return:
//    ippStsNoErr              Ok
//    ippStsNullPtrErr         One of the pointers is NULL
//    ippStsSizeErr            The width or height of images is less than or equal to zero
//    ippStsStepErr            Any of the step values is less than or equal to zero
//
//  Arguments:
//    pSrc1, pSrc2             Pointers to source images
//    src1Step, src2Step       Steps through the source images
//    pDst                     Pointer to the destination image
//    dstStep                  Step through the destination image
//    roiSize                  Size of the ROI
//    scaleFactor              Scale factor
*/

IPPAPI(IppStatus, ippiAdd_16sc_C1RSfs,  (const Ipp16sc* pSrc1, int src1Step, const Ipp16sc* pSrc2,
                                        int src2Step, Ipp16sc* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiAdd_16sc_C3RSfs,  (const Ipp16sc* pSrc1, int src1Step, const Ipp16sc* pSrc2,
                                        int src2Step, Ipp16sc* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiAdd_16sc_AC4RSfs, (const Ipp16sc* pSrc1, int src1Step, const Ipp16sc* pSrc2,
                                        int src2Step, Ipp16sc* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiSub_16sc_C1RSfs,  (const Ipp16sc* pSrc1, int src1Step, const Ipp16sc* pSrc2,
                                        int src2Step, Ipp16sc* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiSub_16sc_C3RSfs,  (const Ipp16sc* pSrc1, int src1Step, const Ipp16sc* pSrc2,
                                        int src2Step, Ipp16sc* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiSub_16sc_AC4RSfs, (const Ipp16sc* pSrc1, int src1Step, const Ipp16sc* pSrc2,
                                        int src2Step, Ipp16sc* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiMul_16sc_C1RSfs,  (const Ipp16sc* pSrc1, int src1Step, const Ipp16sc* pSrc2,
                                        int src2Step, Ipp16sc* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiMul_16sc_C3RSfs,  (const Ipp16sc* pSrc1, int src1Step, const Ipp16sc* pSrc2,
                                        int src2Step, Ipp16sc* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiMul_16sc_AC4RSfs, (const Ipp16sc* pSrc1, int src1Step, const Ipp16sc* pSrc2,
                                        int src2Step, Ipp16sc* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiDiv_16sc_C1RSfs,  (const Ipp16sc* pSrc1, int src1Step, const Ipp16sc* pSrc2,
                                        int src2Step, Ipp16sc* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiDiv_16sc_C3RSfs,  (const Ipp16sc* pSrc1, int src1Step, const Ipp16sc* pSrc2,
                                        int src2Step, Ipp16sc* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiDiv_16sc_AC4RSfs, (const Ipp16sc* pSrc1, int src1Step, const Ipp16sc* pSrc2,
                                        int src2Step, Ipp16sc* pDst, int dstStep, IppiSize roiSize, int scaleFactor))


/* ////////////////////////////////////////////////////////////////////////////
//  Name:       ippiAdd_32sc_C1IRSfs, ippiAdd_32sc_C3IRSfs, ippiAdd_32sc_AC4IRSfs,
//              ippiSub_32sc_C1IRSfs, ippiSub_32sc_C3IRSfs, ippiSub_32sc_AC4IRSfs,
//              ippiMul_32sc_C1IRSfs, ippiMul_32sc_C3IRSfs, ippiMul_32sc_AC4IRSfs,
//              ippiDiv_32sc_C1IRSfs, ippiDiv_32sc_C3IRSfs, ippiDiv_32sc_AC4IRSfs
//
//  Purpose:    Makes corresponding operation with values of each elements of two
//              source images and stores results in the destination image.
//
//  Return:
//    ippStsNoErr              Ok
//    ippStsNullPtrErr         One of the pointers is NULL
//    ippStsSizeErr            The width or height of images is less than or equal to zero
//    ippStsStepErr            Any of the step values is less than or equal to zero
//
//  Arguments:
//    pSrc                     Pointer to the source image
//    srcStep                  Step through the source image
//    pSrcDst                  Pointer to the source and destination image
//    srcDstStep               Step through the source and destination image
//    roiSize                  Size of the ROI
//    scaleFactor              Scale factor
*/

IPPAPI(IppStatus, ippiAdd_32sc_C1IRSfs,  (const Ipp32sc* pSrc, int srcStep, Ipp32sc* pSrcDst,
                                          int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiAdd_32sc_C3IRSfs,  (const Ipp32sc* pSrc, int srcStep, Ipp32sc* pSrcDst,
                                          int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiAdd_32sc_AC4IRSfs, (const Ipp32sc* pSrc, int srcStep, Ipp32sc* pSrcDst,
                                          int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiSub_32sc_C1IRSfs,  (const Ipp32sc* pSrc, int srcStep, Ipp32sc* pSrcDst,
                                          int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiSub_32sc_C3IRSfs,  (const Ipp32sc* pSrc, int srcStep, Ipp32sc* pSrcDst,
                                          int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiSub_32sc_AC4IRSfs, (const Ipp32sc* pSrc, int srcStep, Ipp32sc* pSrcDst,
                                          int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiMul_32sc_C1IRSfs,  (const Ipp32sc* pSrc, int srcStep, Ipp32sc* pSrcDst,
                                          int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiMul_32sc_C3IRSfs,  (const Ipp32sc* pSrc, int srcStep, Ipp32sc* pSrcDst,
                                          int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiMul_32sc_AC4IRSfs, (const Ipp32sc* pSrc, int srcStep, Ipp32sc* pSrcDst,
                                          int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiDiv_32sc_C1IRSfs,  (const Ipp32sc* pSrc, int srcStep, Ipp32sc* pSrcDst,
                                          int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiDiv_32sc_C3IRSfs,  (const Ipp32sc* pSrc, int srcStep, Ipp32sc* pSrcDst,
                                          int srcDstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiDiv_32sc_AC4IRSfs, (const Ipp32sc* pSrc, int srcStep, Ipp32sc* pSrcDst,
                                          int srcDstStep, IppiSize roiSize, int scaleFactor))

/* ////////////////////////////////////////////////////////////////////////////
//  Name:       ippiAdd_32sc_C1RSfs, ippiAdd_32sc_C3RSfs, ippiAdd_32sc_AC4RSfs,
//              ippiSub_32sc_C1RSfs, ippiSub_32sc_C3RSfs, ippiSub_32sc_AC4RSfs,
//              ippiMul_32sc_C1RSfs, ippiMul_32sc_C3RSfs, ippiMul_32sc_AC4RSfs,
//              ippiDiv_32sc_C1RSfs, ippiDiv_32sc_C3RSfs, ippiDiv_32sc_AC4RSfs
//
//  Purpose:    Makes corresponding operation with values of each elements of two
//              source images and stores results in the destination image.
//
//  Return:
//    ippStsNoErr              Ok
//    ippStsNullPtrErr         One of the pointers is NULL
//    ippStsSizeErr            The width or height of images is less than or equal to zero
//    ippStsStepErr            Any of the step values is less than or equal to zero
//
//  Arguments:
//    pSrc1, pSrc2             Pointers to source images
//    src1Step, src2Step       The steps of the source images
//    pDst                     The pointer to destination image
//    dstStep                  The step of the destination image
//    roiSize                  ROI size
//    scaleFactor              Scale factor
*/

IPPAPI(IppStatus, ippiAdd_32sc_C1RSfs,  (const Ipp32sc* pSrc1, int src1Step, const Ipp32sc* pSrc2,
                                         int src2Step, Ipp32sc* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiAdd_32sc_C3RSfs,  (const Ipp32sc* pSrc1, int src1Step, const Ipp32sc* pSrc2,
                                         int src2Step, Ipp32sc* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiAdd_32sc_AC4RSfs, (const Ipp32sc* pSrc1, int src1Step, const Ipp32sc* pSrc2,
                                         int src2Step, Ipp32sc* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiSub_32sc_C1RSfs,  (const Ipp32sc* pSrc1, int src1Step, const Ipp32sc* pSrc2,
                                         int src2Step, Ipp32sc* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiSub_32sc_C3RSfs,  (const Ipp32sc* pSrc1, int src1Step, const Ipp32sc* pSrc2,
                                         int src2Step, Ipp32sc* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiSub_32sc_AC4RSfs, (const Ipp32sc* pSrc1, int src1Step, const Ipp32sc* pSrc2,
                                         int src2Step, Ipp32sc* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiMul_32sc_C1RSfs,  (const Ipp32sc* pSrc1, int src1Step, const Ipp32sc* pSrc2,
                                         int src2Step, Ipp32sc* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiMul_32sc_C3RSfs,  (const Ipp32sc* pSrc1, int src1Step, const Ipp32sc* pSrc2,
                                         int src2Step, Ipp32sc* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiMul_32sc_AC4RSfs, (const Ipp32sc* pSrc1, int src1Step, const Ipp32sc* pSrc2,
                                         int src2Step, Ipp32sc* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiDiv_32sc_C1RSfs,  (const Ipp32sc* pSrc1, int src1Step, const Ipp32sc* pSrc2,
                                         int src2Step, Ipp32sc* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiDiv_32sc_C3RSfs,  (const Ipp32sc* pSrc1, int src1Step, const Ipp32sc* pSrc2,
                                        int src2Step, Ipp32sc* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiDiv_32sc_AC4RSfs, (const Ipp32sc* pSrc1, int src1Step, const Ipp32sc* pSrc2,
                                        int src2Step, Ipp32sc* pDst, int dstStep, IppiSize roiSize, int scaleFactor))


/* ////////////////////////////////////////////////////////////////////////////
//  Name:       ippiAddC_16sc_C1IRSfs, ippiAddC_16sc_C3IRSfs, ippiAddC_16sc_AC4IRSfs,
//              ippiSubC_16sc_C1IRSfs, ippiSubC_16sc_C3IRSfs, ippiSubC_16sc_AC4IRSfs,
//              ippiMulC_16sc_C1IRSfs, ippiMulC_16sc_C3IRSfs, ippiMulC_16sc_AC4IRSfs,
//              ippiDivC_16sc_C1IRSfs, ippiDivC_16sc_C3IRSfs, ippiDivC_16sc_AC4IRSfs
//
//  Purpose:    Makes corresponding operations with a constant and value of each elements of
//              an image and stores results in the same image.
//
//  Return:
//    ippStsNoErr              Ok
//    ippStsNullPtrErr         The pointer is NULL
//    ippStsSizeErr            The width or height of image is less than or equal to zero
//    ippStsStepErr            The step value is less than or equal to zero
//
//  Arguments:
//    value                    The constant for operation
//    pSrcDst                  Pointer to the image
//    srcDstStep               Step through the image
//    roiSize                  Size of the ROI
//    scaleFactor              Scale factor
*/
IPPAPI(IppStatus, ippiAddC_16sc_C1IRSfs,  (Ipp16sc value, Ipp16sc* pSrcDst, int srcDstStep,
                                           IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiAddC_16sc_C3IRSfs,  (const Ipp16sc value[3], Ipp16sc* pSrcDst, int srcDstStep,
                                           IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiAddC_16sc_AC4IRSfs, (const Ipp16sc value[3], Ipp16sc* pSrcDst, int srcDstStep,
                                           IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiSubC_16sc_C1IRSfs,  (Ipp16sc value, Ipp16sc* pSrcDst, int srcDstStep,
                                           IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiSubC_16sc_C3IRSfs,  (const Ipp16sc value[3], Ipp16sc* pSrcDst, int srcDstStep,
                                           IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiSubC_16sc_AC4IRSfs, (const Ipp16sc value[3], Ipp16sc* pSrcDst, int srcDstStep,
                                           IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiMulC_16sc_C1IRSfs,  (Ipp16sc value, Ipp16sc* pSrcDst, int srcDstStep,
                                           IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiMulC_16sc_C3IRSfs,  (const Ipp16sc value[3], Ipp16sc* pSrcDst, int srcDstStep,
                                           IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiMulC_16sc_AC4IRSfs, (const Ipp16sc value[3], Ipp16sc* pSrcDst, int srcDstStep,
                                           IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiDivC_16sc_C1IRSfs,  (Ipp16sc value, Ipp16sc* pSrcDst, int srcDstStep,
                                           IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiDivC_16sc_C3IRSfs,  (const Ipp16sc value[3], Ipp16sc* pSrcDst, int srcDstStep,
                                           IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiDivC_16sc_AC4IRSfs, (const Ipp16sc value[3], Ipp16sc* pSrcDst, int srcDstStep,
                                           IppiSize roiSize, int scaleFactor))

/* //////////////////////////////////////////////////////////////////////////////////
//  Name:       ippiAddC_16sc_C1RSfs, ippiAddC_16sc_C3RSfs, ippiAddC_16sc_AC4RSfs,
//              ippiSubC_16sc_C1RSfs, ippiSubC_16sc_C3RSfs, ippiSubC_16sc_AC4RSfs,
//              ippiMulC_16sc_C1RSfs, ippiMulC_16sc_C3RSfs, ippiMulC_16sc_AC4RSfs
//              ippiDivC_16sc_C1RSfs, ippiDivC_16sc_C3RSfs, ippiDivC_16sc_AC4RSfs
//
//
//  Purpose:    Makes corresponding operations with a constant and value of each elements of
//              the source image and stores results in the destination image.
//
//  Return:
//    ippStsNoErr              Ok
//    ippStsNullPtrErr         One of the pointers is NULL
//    ippStsSizeErr            The width or height of image is less than or equal to zero
//    ippStsStepErr            Any of the step values is less than or equal to zero
//
//  Arguments:
//    value                    The constant value for the specified operation
//    pSrc                     Pointer to the source image
//    srcStep                  Step through the source image
//    pDst                     Pointer to the destination image
//    dstStep                  Step through the destination image
//    roiSize                  Size of the ROI
//    scaleFactor              Scale factor
*/

IPPAPI(IppStatus, ippiAddC_16sc_C1RSfs,  (const Ipp16sc* pSrc, int srcStep, Ipp16sc value, Ipp16sc* pDst,
                                          int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiAddC_16sc_C3RSfs,  (const Ipp16sc* pSrc, int srcStep, const Ipp16sc value[3],
                                          Ipp16sc* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiAddC_16sc_AC4RSfs, (const Ipp16sc* pSrc, int srcStep, const Ipp16sc value[3],
                                          Ipp16sc* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiSubC_16sc_C1RSfs,  (const Ipp16sc* pSrc, int srcStep, Ipp16sc value, Ipp16sc* pDst,
                                          int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiSubC_16sc_C3RSfs,  (const Ipp16sc* pSrc, int srcStep, const Ipp16sc value[3],
                                          Ipp16sc* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiSubC_16sc_AC4RSfs, (const Ipp16sc* pSrc, int srcStep, const Ipp16sc value[3],
                                          Ipp16sc* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiMulC_16sc_C1RSfs,  (const Ipp16sc* pSrc, int srcStep, Ipp16sc value, Ipp16sc* pDst,
                                          int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiMulC_16sc_C3RSfs,  (const Ipp16sc* pSrc, int srcStep, const Ipp16sc value[3],
                                          Ipp16sc* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiMulC_16sc_AC4RSfs, (const Ipp16sc* pSrc, int srcStep, const Ipp16sc value[3],
                                          Ipp16sc* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiDivC_16sc_C1RSfs,  (const Ipp16sc* pSrc,
                                          int srcStep, Ipp16sc value, Ipp16sc* pDst,
                                          int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiDivC_16sc_C3RSfs,  (const Ipp16sc* pSrc,
                                          int srcStep, const Ipp16sc value[3], Ipp16sc* pDst,
                                          int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiDivC_16sc_AC4RSfs, (const Ipp16sc* pSrc,
                                          int srcStep, const Ipp16sc value[3], Ipp16sc* pDst,
                                          int dstStep, IppiSize roiSize, int scaleFactor))


/* ////////////////////////////////////////////////////////////////////////////
//  Name:       ippiAddC_32sc_C1IRSfs, ippiAddC_32sc_C3IRSfs, ippiAddC_32sc_AC4IRSfs,
//              ippiSubC_32sc_C1IRSfs, ippiSubC_32sc_C3IRSfs, ippiSubC_32sc_AC4IRSfs,
//              ippiMulC_32sc_C1IRSfs, ippiMulC_32sc_C3IRSfs, ippiMulC_32sc_AC4IRSfs,
//              ippiDivC_32sc_C1IRSfs, ippiDivC_32sc_C3IRSfs, ippiDivC_32sc_AC4IRSfs
//
//  Purpose:    Makes corresponding operations with a constant and value of each elements of
//              an image and stores results in the same image.
//
//  Return:
//    ippStsNoErr              Ok
//    ippStsNullPtrErr         The pointer is NULL
//    ippStsSizeErr            The width or height of image is less than or equal to zero
//    ippStsStepErr            The step value is less than or equal to zero
//
//  Arguments:
//    value                    The constant value for the specified operation
//    pSrcDst                  Pointer to the image
//    srcDstStep               Step through the image
//    roiSize                  Size of the ROI
//    scaleFactor              Scale factor
*/
IPPAPI(IppStatus, ippiAddC_32sc_C1IRSfs,  (Ipp32sc value, Ipp32sc* pSrcDst, int srcDstStep,
                                           IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiAddC_32sc_C3IRSfs,  (const Ipp32sc value[3], Ipp32sc* pSrcDst, int srcDstStep,
                                           IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiAddC_32sc_AC4IRSfs, (const Ipp32sc value[3], Ipp32sc* pSrcDst, int srcDstStep,
                                           IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiSubC_32sc_C1IRSfs,  (Ipp32sc value, Ipp32sc* pSrcDst, int srcDstStep,
                                           IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiSubC_32sc_C3IRSfs,  (const Ipp32sc value[3], Ipp32sc* pSrcDst, int srcDstStep,
                                           IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiSubC_32sc_AC4IRSfs, (const Ipp32sc value[3], Ipp32sc* pSrcDst, int srcDstStep,
                                           IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiMulC_32sc_C1IRSfs,  (Ipp32sc value, Ipp32sc* pSrcDst, int srcDstStep,
                                           IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiMulC_32sc_C3IRSfs,  (const Ipp32sc value[3], Ipp32sc* pSrcDst, int srcDstStep,
                                           IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiMulC_32sc_AC4IRSfs, (const Ipp32sc value[3], Ipp32sc* pSrcDst, int srcDstStep,
                                           IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiDivC_32sc_C1IRSfs,  (Ipp32sc value, Ipp32sc* pSrcDst, int srcDstStep,
                                           IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiDivC_32sc_C3IRSfs,  (const Ipp32sc value[3], Ipp32sc* pSrcDst, int srcDstStep,
                                           IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiDivC_32sc_AC4IRSfs, (const Ipp32sc value[3], Ipp32sc* pSrcDst, int srcDstStep,
                                           IppiSize roiSize, int scaleFactor))

/* ////////////////////////////////////////////////////////////////////////////
//  Name:       ippiAddC_32sc_C1RSfs, ippiAddC_32sc_C3RSfs, ippiAddC_32sc_AC4RSfs,
//              ippiSubC_32sc_C1RSfs, ippiSubC_32sc_C3RSfs, ippiSubC_32sc_AC4RSfs,
//              ippiMulC_32sc_C1RSfs, ippiMulC_32sc_C3RSfs, ippiMulC_32sc_AC4RSfs,
//              ippiDivC_32sc_C1RSfs, ippiDivC_32sc_C3RSfs, ippiDivC_32sc_AC4RSfs
//
//  Purpose:    Makes corresponding operations with a constant and value of each elements
//              of the source image and pstores results in the destination image.
//
//  Return:
//    ippStsNoErr              Ok
//    ippStsNullPtrErr         One of the pointers is NULL
//    ippStsSizeErr            The width or height of images is less than or equal to zero
//    ippStsStepErr            Any of the step values is less than or equal to zero
//
//  Arguments:
//    value                    The constant value for the specified operation
//    pSrc                     Pointer to the source image
//    srcStep                  Step through the source image
//    pDst                     Pointer to the destination image
//    dstStep                  Step through the destination image
//    roiSize                  ROI
//    scaleFactor              Scale factor
*/

IPPAPI(IppStatus, ippiAddC_32sc_C1RSfs,  (const Ipp32sc* pSrc, int srcStep, Ipp32sc value, Ipp32sc* pDst,
                                          int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiAddC_32sc_C3RSfs,  (const Ipp32sc* pSrc, int srcStep, const Ipp32sc value[3],
                                          Ipp32sc* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiAddC_32sc_AC4RSfs, (const Ipp32sc* pSrc, int srcStep, const Ipp32sc value[3],
                                          Ipp32sc* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiSubC_32sc_C1RSfs,  (const Ipp32sc* pSrc, int srcStep, Ipp32sc value, Ipp32sc* pDst,
                                          int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiSubC_32sc_C3RSfs,  (const Ipp32sc* pSrc, int srcStep, const Ipp32sc value[3],
                                          Ipp32sc* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiSubC_32sc_AC4RSfs, (const Ipp32sc* pSrc, int srcStep, const Ipp32sc value[3],
                                          Ipp32sc* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiMulC_32sc_C1RSfs,  (const Ipp32sc* pSrc, int srcStep, Ipp32sc value, Ipp32sc* pDst,
                                          int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiMulC_32sc_C3RSfs,  (const Ipp32sc* pSrc, int srcStep, const Ipp32sc value[3],
                                          Ipp32sc* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiMulC_32sc_AC4RSfs, (const Ipp32sc* pSrc, int srcStep, const Ipp32sc value[3],
                                          Ipp32sc* pDst, int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiDivC_32sc_C1RSfs,  (const Ipp32sc* pSrc,
                                          int srcStep, Ipp32sc value, Ipp32sc* pDst,
                                          int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiDivC_32sc_C3RSfs,  (const Ipp32sc* pSrc,
                                          int srcStep, const Ipp32sc value[3], Ipp32sc* pDst,
                                          int dstStep, IppiSize roiSize, int scaleFactor))
IPPAPI(IppStatus, ippiDivC_32sc_AC4RSfs, (const Ipp32sc* pSrc,
                                          int srcStep, const Ipp32sc value[3], Ipp32sc* pDst,
                                          int dstStep, IppiSize roiSize, int scaleFactor))


/* /////////////////////////////////////////////////////////////////////////////////////////////////
//                      Functions of multiplication with scaling
///////////////////////////////////////////////////////////////////////////////////////////////// */
/*
//  Names:              ippiMulScale, ippiMulCScale
//
//  Purpose:            multiplies the pixel values of two images (MulScale)
//                      or the pixel values of image by a constant (MulScaleC) with scaling
//
//  Parameters:
//   value              constant to be multiplpy with each pixel of the image
//   pSrc               source image data pointer
//   srcStep            step in source image
//   pSrcDst            source/destination image data pointer (for in-place case)
//   srcDstStep         step in source/destination image (for in-place case)
//   pSrc1              first source image data pointer
//   src1Step           step in first source image
//   pSrc2              second source image data pointer
//   src2Step           step in second source image
//   pDst               destination image data pointer
//   dstStep            step in destination image
//   roiSize            size of source image
//
//  Returns:
//   ippStsNullPtrErr   pointer(s) to the data is NULL
//   ippStsStepErr      step in any image is less or equal zero
//   ippStsSizeErr      width or height of images is less or equal zero
//   ippStsNoErr        otherwise
*/

IPPAPI(IppStatus, ippiMulScale_8u_C1R, (const Ipp8u* pSrc1, int src1Step, const Ipp8u* pSrc2, int src2Step, Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMulScale_8u_C3R, (const Ipp8u* pSrc1, int src1Step, const Ipp8u* pSrc2, int src2Step, Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMulScale_8u_C4R, (const Ipp8u* pSrc1, int src1Step, const Ipp8u* pSrc2, int src2Step, Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMulScale_8u_AC4R, (const Ipp8u* pSrc1, int src1Step, const Ipp8u* pSrc2, int src2Step, Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMulScale_8u_C1IR, (const Ipp8u* pSrc, int srcStep, Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMulScale_8u_C3IR, (const Ipp8u* pSrc, int srcStep, Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMulScale_8u_C4IR, (const Ipp8u* pSrc, int srcStep, Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMulScale_8u_AC4IR, (const Ipp8u* pSrc, int srcStep, Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMulCScale_8u_C1R, (const Ipp8u* pSrc, int srcStep, Ipp8u value, Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMulCScale_8u_C3R, (const Ipp8u* pSrc, int srcStep, const Ipp8u value[3], Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMulCScale_8u_C4R, (const Ipp8u* pSrc, int srcStep, const Ipp8u value[4], Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMulCScale_8u_AC4R, (const Ipp8u* pSrc, int srcStep, const Ipp8u value[3], Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMulCScale_8u_C1IR, (Ipp8u value, Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMulCScale_8u_C3IR, (const Ipp8u value[3], Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMulCScale_8u_C4IR, (const Ipp8u value[4], Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMulCScale_8u_AC4IR, (const Ipp8u value[3], Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize))

IPPAPI(IppStatus, ippiMulScale_16u_C1R, (const Ipp16u* pSrc1, int src1Step, const Ipp16u* pSrc2, int src2Step, Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMulScale_16u_C3R, (const Ipp16u* pSrc1, int src1Step, const Ipp16u* pSrc2, int src2Step, Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMulScale_16u_C4R, (const Ipp16u* pSrc1, int src1Step, const Ipp16u* pSrc2, int src2Step, Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMulScale_16u_AC4R, (const Ipp16u* pSrc1, int src1Step, const Ipp16u* pSrc2, int src2Step, Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMulScale_16u_C1IR, (const Ipp16u* pSrc, int srcStep, Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMulScale_16u_C3IR, (const Ipp16u* pSrc, int srcStep, Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMulScale_16u_C4IR, (const Ipp16u* pSrc, int srcStep, Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMulScale_16u_AC4IR, (const Ipp16u* pSrc, int srcStep, Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMulCScale_16u_C1R, (const Ipp16u* pSrc, int srcStep, Ipp16u value, Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMulCScale_16u_C3R, (const Ipp16u* pSrc, int srcStep, const Ipp16u value[3], Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMulCScale_16u_C4R, (const Ipp16u* pSrc, int srcStep, const Ipp16u value[4], Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMulCScale_16u_AC4R, (const Ipp16u* pSrc, int srcStep, const Ipp16u value[3], Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMulCScale_16u_C1IR, (Ipp16u value, Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMulCScale_16u_C3IR, (const Ipp16u value[3], Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMulCScale_16u_C4IR, (const Ipp16u value[4], Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMulCScale_16u_AC4IR, (const Ipp16u value[3], Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize))

/* /////////////////////////////////////////////////////////////////////////////
//              Vector multiplication in RCPack for image processing
///////////////////////////////////////////////////////////////////////////// */
/*  Name:               ippiMulPack
//
//  Purpose:            Multiply of two images and store in RCPack format
//
//  Returns:             IppStatus
//      ippStsNoErr,      if no errors
//      ippStsNullPtrErr, if some of pointers to input or output data are NULL
//      ippStsStepErr,    if step in some image is less or equal zero
//      ippStsSizeErr,    if width or height of image is less or equal zero
//
//  Parameters:
//      pSrc1           first source image data
//      src1Step        step in src1
//      pSrc2           second source image data
//      src1Step        step in src2
//      pDst            destination image data
//      dstStep         step in dst
//      roiSize         region of interest of src
//      sFactor         scale factor
//
//  Notes:              non in-place and in-pace cases done
*/

IPPAPI(IppStatus, ippiMulPack_16s_C1IRSfs, (const Ipp16s* pSrc, int srcStep, Ipp16s* pSrcDst, int srcDstStep,
                                        IppiSize roiSize, int sFactor))
IPPAPI(IppStatus, ippiMulPack_16s_C3IRSfs, (const Ipp16s* pSrc, int srcStep, Ipp16s* pSrcDst, int srcDstStep,
                                        IppiSize roiSize, int sFactor))
IPPAPI(IppStatus, ippiMulPack_16s_C4IRSfs, (const Ipp16s* pSrc, int srcStep, Ipp16s* pSrcDst, int srcDstStep,
                                        IppiSize roiSize, int sFactor))
IPPAPI(IppStatus, ippiMulPack_16s_AC4IRSfs, (const Ipp16s* pSrc, int srcStep, Ipp16s* pSrcDst, int srcDstStep,
                                        IppiSize roiSize, int sFactor))
IPPAPI(IppStatus, ippiMulPack_16s_C1RSfs, (const Ipp16s* pSrc1, int src1Step, const Ipp16s* pSrc2, int src2Step,
                                        Ipp16s* pDst, int dstStep, IppiSize roiSize, int sFactor))
IPPAPI(IppStatus, ippiMulPack_16s_C3RSfs, (const Ipp16s* pSrc1, int src1Step, const Ipp16s* pSrc2, int src2Step,
                                        Ipp16s* pDst, int dstStep, IppiSize roiSize, int sFactor))
IPPAPI(IppStatus, ippiMulPack_16s_C4RSfs, (const Ipp16s* pSrc1, int src1Step, const Ipp16s* pSrc2, int src2Step,
                                        Ipp16s* pDst, int dstStep, IppiSize roiSize, int sFactor))
IPPAPI(IppStatus, ippiMulPack_16s_AC4RSfs, (const Ipp16s* pSrc1, int src1Step, const Ipp16s* pSrc2, int src2Step,
                                        Ipp16s* pDst, int dstStep, IppiSize roiSize, int sFactor))

IPPAPI(IppStatus, ippiMulPack_32s_C1IRSfs, (const Ipp32s* pSrc, int srcStep, Ipp32s* pSrcDst, int srcDstStep,
                                        IppiSize roiSize, int sFactor))
IPPAPI(IppStatus, ippiMulPack_32s_C3IRSfs, (const Ipp32s* pSrc, int srcStep, Ipp32s* pSrcDst, int srcDstStep,
                                        IppiSize roiSize, int sFactor))
IPPAPI(IppStatus, ippiMulPack_32s_C4IRSfs, (const Ipp32s* pSrc, int srcStep, Ipp32s* pSrcDst, int srcDstStep,
                                        IppiSize roiSize, int sFactor))
IPPAPI(IppStatus, ippiMulPack_32s_AC4IRSfs, (const Ipp32s* pSrc, int srcStep, Ipp32s* pSrcDst, int srcDstStep,
                                        IppiSize roiSize, int sFactor))
IPPAPI(IppStatus, ippiMulPack_32s_C1RSfs, (const Ipp32s* pSrc1, int src1Step, const Ipp32s* pSrc2, int src2Step,
                                        Ipp32s* pDst, int dstStep, IppiSize roiSize, int sFactor))
IPPAPI(IppStatus, ippiMulPack_32s_C3RSfs, (const Ipp32s* pSrc1, int src1Step, const Ipp32s* pSrc2, int src2Step,
                                        Ipp32s* pDst, int dstStep, IppiSize roiSize, int sFactor))
IPPAPI(IppStatus, ippiMulPack_32s_C4RSfs, (const Ipp32s* pSrc1, int src1Step, const Ipp32s* pSrc2, int src2Step,
                                        Ipp32s* pDst, int dstStep, IppiSize roiSize, int sFactor))
IPPAPI(IppStatus, ippiMulPack_32s_AC4RSfs, (const Ipp32s* pSrc1, int src1Step, const Ipp32s* pSrc2, int src2Step,
                                        Ipp32s* pDst, int dstStep, IppiSize roiSize, int sFactor))

IPPAPI(IppStatus, ippiMulPack_32f_C1IR, (const Ipp32f* pSrc, int srcStep, Ipp32f* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMulPack_32f_C3IR, (const Ipp32f* pSrc, int srcStep, Ipp32f* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMulPack_32f_C4IR, (const Ipp32f* pSrc, int srcStep, Ipp32f* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMulPack_32f_AC4IR, (const Ipp32f* pSrc, int srcStep, Ipp32f* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMulPack_32f_C1R, (const Ipp32f* pSrc1, int src1Step, const Ipp32f* pSrc2, int src2Step,
                                        Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMulPack_32f_C3R, (const Ipp32f* pSrc1, int src1Step, const Ipp32f* pSrc2, int src2Step,
                                        Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMulPack_32f_C4R, (const Ipp32f* pSrc1, int src1Step, const Ipp32f* pSrc2, int src2Step,
                                        Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMulPack_32f_AC4R, (const Ipp32f* pSrc1, int src1Step, const Ipp32f* pSrc2, int src2Step,
                                        Ipp32f* pDst, int dstStep, IppiSize roiSize))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:               ippiMulPackConj
//
//  Purpose:            Multiply of two images and store in RCPack format
//
//  Returns:             IppStatus
//      ippStsNoErr,      if no errors
//      ippStsNullPtrErr, if some of pointers to input or output data are NULL
//      ippStsStepErr,    if step in some image is less or equal zero
//      ippStsSizeErr,    if width or height of image is less or equal zero
//
//  Parameters:
//      pSrc            source image data
//      srcStep         step in src
//      pSrcDst         destination image data
//      srcDstStep      step in dst
//      roiSize         region of interest of src
*/

IPPAPI(IppStatus, ippiMulPackConj_32f_C1IR, (const Ipp32f* pSrc, int srcStep, Ipp32f* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMulPackConj_32f_C3IR, (const Ipp32f* pSrc, int srcStep, Ipp32f* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMulPackConj_32f_C4IR, (const Ipp32f* pSrc, int srcStep, Ipp32f* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiMulPackConj_32f_AC4IR, (const Ipp32f* pSrc, int srcStep, Ipp32f* pSrcDst, int srcDstStep, IppiSize roiSize))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiPackToCplxExtend
//  Purpose:        To convert a RCPack2D format to full complex data format.
//  Context:
//
//  Returns:             IppStatus
//      ippStsNoErr,            if no errors
//      ippStsNullPtrErr,       if pSrc == NULL or pDst == NULL
//      ippStsStepErr,          if srcStep or dstStep is less than or equal to zero
//      ippStsSizeErr           if width or height of image is less than or equal to zero
//
//  Parameters:
//    pSrc        POinter to the source image data (point to pixel (0,0)).
//    srcSize     The size of Src image.
//    srcStep     The step in Src image
//    pDst        Pointer to the destination image data.
//    dstStep     The step in Dst image
//  Notes:
*/

IPPAPI (IppStatus, ippiPackToCplxExtend_32s32sc_C1R, (const Ipp32s* pSrc,
        IppiSize srcSize, int srcStep,
        Ipp32sc* pDst, int dstStep ))

IPPAPI (IppStatus, ippiPackToCplxExtend_32f32fc_C1R, (const Ipp32f* pSrc,
        IppiSize srcSize, int srcStep,
        Ipp32fc* pDst, int dstStep ))


/* /////////////////////////////////////////////////////////////////////////////
//                  Alpha Composition operations
///////////////////////////////////////////////////////////////////////////// */
/*
//  Contents:
//      ippiAlphaPremul_8u_AC4R,  ippiAlphaPremul_16u_AC4R
//      ippiAlphaPremul_8u_AC4IR, ippiAlphaPremul_16u_AC4IR
//      ippiAlphaPremul_8u_AP4R,  ippiAlphaPremul_16u_AP4R
//      ippiAlphaPremul_8u_AP4IR, ippiAlphaPremul_16u_AP4IR
//   Pre-multiplies pixel values of an image by its alpha values.

//      ippiAlphaPremulC_8u_AC4R,  ippiAlphaPremulC_16u_AC4R
//      ippiAlphaPremulC_8u_AC4IR, ippiAlphaPremulC_16u_AC4IR
//      ippiAlphaPremulC_8u_AP4R,  ippiAlphaPremulC_16u_AP4R
//      ippiAlphaPremulC_8u_AP4IR, ippiAlphaPremulC_16u_AP4IR
//      ippiAlphaPremulC_8u_C4R,   ippiAlphaPremulC_16u_C4R
//      ippiAlphaPremulC_8u_C4IR,  ippiAlphaPremulC_16u_C4IR
//      ippiAlphaPremulC_8u_C3R,   ippiAlphaPremulC_16u_C3R
//      ippiAlphaPremulC_8u_C3IR,  ippiAlphaPremulC_16u_C3IR
//      ippiAlphaPremulC_8u_C1R,   ippiAlphaPremulC_16u_C1R
//      ippiAlphaPremulC_8u_C1IR,  ippiAlphaPremulC_16u_C1IR
//   Pre-multiplies pixel values of an image by constant alpha values.
//
//      ippiAlphaComp_8u_AC4R, ippiAlphaComp_16u_AC4R
//      ippiAlphaComp_8u_AC1R, ippiAlphaComp_16u_AC1R
//   Composites two images using alpha values of both images
//
//      ippiAlphaCompC_8u_AC4R, ippiAlphaCompC_16u_AC4R
//      ippiAlphaCompC_8u_AP4R, ippiAlphaCompC_16u_AP4R
//      ippiAlphaCompC_8u_C4R,  ippiAlphaCompC_16u_C4R
//      ippiAlphaCompC_8u_C3R,  ippiAlphaCompC_16u_C3R
//      ippiAlphaCompC_8u_C1R,  ippiAlphaCompC_16u_C1R
//   Composites two images using constant alpha values
//
//  The type of composition operation (alphaType)
//      OVER   ippAlphaOver   ippAlphaOverPremul
//      IN     ippAlphaIn     ippAlphaInPremul
//      OUT    ippAlphaOut    ippAlphaOutPremul
//      ATOP   ippAlphaATop   ippAlphaATopPremul
//      XOR    ippAlphaXor    ippAlphaXorPremul
//      PLUS   ippAlphaPlus   ippAlphaPlusPremul
//
//  Type  result pixel           result pixel (Premul)    result alpha
//  OVER  aA*A+(1-aA)*aB*B         A+(1-aA)*B             aA+(1-aA)*aB
//  IN    aA*A*aB                  A*aB                   aA*aB
//  OUT   aA*A*(1-aB)              A*(1-aB)               aA*(1-aB)
//  ATOP  aA*A*aB+(1-aA)*aB*B      A*aB+(1-aA)*B          aA*aB+(1-aA)*aB
//  XOR   aA*A*(1-aB)+(1-aA)*aB*B  A*(1-aB)+(1-aA)*B      aA*(1-aB)+(1-aA)*aB
//  PLUS  aA*A+aB*B                A+B                    aA+aB
//      Here 1 corresponds significance VAL_MAX, all multiplies execute
//      with scaling
//          X * Y => (X * Y) / VAL_MAX
//      and VAL_MAX is the maximum presentable pixel value
//          VAL_MAX == IPP_MAX_8U  for 8u
//          VAL_MAX == IPP_MAX_16U for 16u
*/

/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiAlphaPremul_8u_AC4R,  ippiAlphaPremul_16u_AC4R
//                  ippiAlphaPremul_8u_AC4IR, ippiAlphaPremul_16u_AC4IR
//                  ippiAlphaPremul_8u_AP4R,  ippiAlphaPremul_16u_AP4R
//                  ippiAlphaPremul_8u_AP4IR, ippiAlphaPremul_16u_AP4IR
//  Purpose:        PreMultiplies on inner alpha for 4-channel images
//                  For channels 1-3
//                      dst_pixel = (src_pixel * src_alpha) / VAL_MAX
//                  For alpha-channel (channel 4)
//                      dst_alpha = src_alpha
//  Arguments:
//     pSrc         Pointer to start of source image
//     srcStep      Step through the source image
//     pDst         Pointer to start of destination image
//     dstStep      Step through the destination image
//     pSrcDst      Pointer to start input/output image (for in-place function)
//     srcDstStep   Step through the input/output image (for in-place function)
//     roiSize      Size of the rectangle to operate upon
//  Returns:
//     ippStsNoErr            no errors
//     ippStsNullPtrErr       if pSrc == NULL or pDst == NULL or
//                               pSrcDst == NULL
//     ippStsSizeErr          if ROI sizes are negative or zero
//     ippStsStepErr          if the steps in images are negative or zero
*/

IPPAPI (IppStatus, ippiAlphaPremul_8u_AC4R,
                   ( const Ipp8u* pSrc, int srcStep,
                     Ipp8u* pDst, int dstStep,
                     IppiSize roiSize ))
IPPAPI (IppStatus, ippiAlphaPremul_16u_AC4R,
                   ( const Ipp16u* pSrc, int srcStep,
                     Ipp16u* pDst, int dstStep,
                     IppiSize roiSize ))

IPPAPI (IppStatus, ippiAlphaPremul_8u_AC4IR,
                   ( Ipp8u* pSrcDst, int srcDstStep,
                     IppiSize roiSize ))
IPPAPI (IppStatus, ippiAlphaPremul_16u_AC4IR,
                   ( Ipp16u* pSrcDst, int srcDstStep,
                     IppiSize roiSize ))

IPPAPI (IppStatus, ippiAlphaPremul_8u_AP4R,
                   ( const Ipp8u* const pSrc[4], int srcStep,
                     Ipp8u* const pDst[4], int dstStep,
                     IppiSize roiSize ))
IPPAPI (IppStatus, ippiAlphaPremul_16u_AP4R,
                   ( const Ipp16u* const pSrc[4], int srcStep,
                     Ipp16u* const pDst[4], int dstStep,
                     IppiSize roiSize ))

IPPAPI (IppStatus, ippiAlphaPremul_8u_AP4IR,
                   ( Ipp8u* const pSrcDst[4], int srcDstStep,
                     IppiSize roiSize ))
IPPAPI (IppStatus, ippiAlphaPremul_16u_AP4IR,
                   ( Ipp16u* const pSrcDst[4], int srcDstStep,
                     IppiSize roiSize ))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiAlphaPremulC_8u_AC4R,  ippiAlphaPremulC_16u_AC4R
//                  ippiAlphaPremulC_8u_AC4IR, ippiAlphaPremulC_16u_ACI4R
//                  ippiAlphaPremulC_8u_AP4R,  ippiAlphaPremulC_16u_AP4R
//                  ippiAlphaPremulC_8u_AP4IR, ippiAlphaPremulC_16u_API4R
//  Purpose:        PreMultiplies on constant alpha for 4-channel images
//                  For channels 1-3
//                      dst_pixel = (src_pixel * const_alpha) / VAL_MAX
//                  For alpha-channel (channel 4)
//                      dst_alpha = const_alpha
//  Arguments:
//     pSrc         Pointer to start of source image
//     srcStep      Step through the source image
//     alpha        The constant alpha value to use
//     pDst         Pointer to start of destination image
//     dstStep      Step through the destination image
//     pSrcDst      Pointer to start input/output image (for in-place function)
//     srcDstStep   Step through the input/output image (for in-place function)
//     roiSize      Size of the rectangle to operate upon
//  Returns:
//     ippStsNoErr            no errors
//     ippStsNullPtrErr       if pSrc == NULL or pDst == NULL or
//                               pSrcDst == NULL
//     ippStsSizeErr          if ROI sizes are negative or zero
//     ippStsStepErr          if the steps in images are negative or zero
//
//  Notes:          Value becomes 0 <= alpha <= VAL_MAX
*/

IPPAPI (IppStatus, ippiAlphaPremulC_8u_AC4R,
                   ( const Ipp8u* pSrc, int srcStep,
                     Ipp8u alpha,
                     Ipp8u* pDst, int dstStep,
                     IppiSize roiSize ))
IPPAPI (IppStatus, ippiAlphaPremulC_16u_AC4R,
                   ( const Ipp16u* pSrc, int srcStep,
                     Ipp16u alpha,
                     Ipp16u* pDst, int dstStep,
                     IppiSize roiSize ))

IPPAPI (IppStatus, ippiAlphaPremulC_8u_AC4IR,
                   ( Ipp8u alpha,
                     Ipp8u* pSrcDst, int srcDstStep,
                     IppiSize roiSize ))
IPPAPI (IppStatus, ippiAlphaPremulC_16u_AC4IR,
                   ( Ipp16u alpha,
                     Ipp16u* pSrcDst, int srcDstStep,
                     IppiSize roiSize ))

IPPAPI (IppStatus, ippiAlphaPremulC_8u_AP4R,
                   ( const Ipp8u* const pSrc[4], int srcStep,
                     Ipp8u alpha,
                     Ipp8u* const pDst[4], int dstStep,
                     IppiSize roiSize ))
IPPAPI (IppStatus, ippiAlphaPremulC_16u_AP4R,
                   ( const Ipp16u* const pSrc[4], int srcStep,
                     Ipp16u alpha,
                     Ipp16u* const pDst[4], int dstStep,
                     IppiSize roiSize ))

IPPAPI (IppStatus, ippiAlphaPremulC_8u_AP4IR,
                   ( Ipp8u alpha,
                     Ipp8u* const pSrcDst[4], int srcDstStep,
                     IppiSize roiSize ))
IPPAPI (IppStatus, ippiAlphaPremulC_16u_AP4IR,
                   ( Ipp16u alpha,
                     Ipp16u* const pSrcDst[4], int srcDstStep,
                     IppiSize roiSize ))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiAlphaPremulC_8u_C4R,  ippiAlphaPremulC_16u_C4R
//                  ippiAlphaPremulC_8u_C4IR, ippiAlphaPremulC_16u_C4IR
//  Purpose:        PreMultiplies on constant alpha for 4-channel images
//                      dst_pixel = (src_pixel * const_alpha) / VAL_MAX
//  Arguments:
//     pSrc         Pointer to start of source image
//     srcStep      Step through the source image
//     alpha        The constant alpha value to use
//     pDst         Pointer to start of destination image
//     dstStep      Step through the destination image
//     pSrcDst      Pointer to start input/output image (for in-place function)
//     srcDstStep   Step through the input/output image (for in-place function)
//     roiSize      Size of the rectangle to operate upon
//  Returns:
//     ippStsNoErr            no errors
//     ippStsNullPtrErr       if pSrc == NULL or pDst == NULL or
//                               pSrcDst == NULL
//     ippStsSizeErr          if ROI sizes are negative or zero
//     ippStsStepErr          if the steps in images are negative or zero
//
//  Notes:          Value becomes 0 <= alpha <= VAL_MAX
*/

IPPAPI (IppStatus, ippiAlphaPremulC_8u_C4R,
                   ( const Ipp8u* pSrc, int srcStep,
                     Ipp8u alpha,
                     Ipp8u* pDst, int dstStep,
                     IppiSize roiSize ))
IPPAPI (IppStatus, ippiAlphaPremulC_16u_C4R,
                   ( const Ipp16u* pSrc, int srcStep,
                     Ipp16u alpha,
                     Ipp16u* pDst, int dstStep,
                     IppiSize roiSize ))

IPPAPI (IppStatus, ippiAlphaPremulC_8u_C4IR,
                   ( Ipp8u alpha,
                     Ipp8u* pSrcDst, int srcDstStep,
                     IppiSize roiSize ))
IPPAPI (IppStatus, ippiAlphaPremulC_16u_C4IR,
                   ( Ipp16u alpha,
                     Ipp16u* pSrcDst, int srcDstStep,
                     IppiSize roiSize ))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiAlphaPremulC_8u_C3R,  ippiAlphaPremulC_16u_C3R
//                  ippiAlphaPremulC_8u_C3IR, ippiAlphaPremulC_16u_C3IR
//  Purpose:        PreMultiplies on constant alpha for 3-channel images
//                      dst_pixel = (src_pixel * const_alpha) / VAL_MAX
//  Arguments:
//     pSrc         Pointer to start of source image
//     srcStep      Step through the source image
//     alpha        The constant alpha value to use
//     pDst         Pointer to start of destination image
//     dstStep      Step through the destination image
//     pSrcDst      Pointer to start input/output image (for in-place function)
//     srcDstStep   Step through the input/output image (for in-place function)
//     roiSize      Size of the rectangle to operate upon
//  Returns:
//     ippStsNoErr            no errors
//     ippStsNullPtrErr       if pSrc == NULL or pDst == NULL or
//                               pSrcDst == NULL
//     ippStsSizeErr          if ROI sizes are negative or zero
//     ippStsStepErr          if the steps in images are negative or zero
//
//  Notes:          Value becomes 0 <= alpha <= VAL_MAX
*/

IPPAPI (IppStatus, ippiAlphaPremulC_8u_C3R,
                   ( const Ipp8u* pSrc, int srcStep,
                     Ipp8u alpha,
                     Ipp8u* pDst, int dstStep,
                     IppiSize roiSize ))
IPPAPI (IppStatus, ippiAlphaPremulC_16u_C3R,
                   ( const Ipp16u* pSrc, int srcStep,
                     Ipp16u alpha,
                     Ipp16u* pDst, int dstStep,
                     IppiSize roiSize ))

IPPAPI (IppStatus, ippiAlphaPremulC_8u_C3IR,
                   ( Ipp8u alpha,
                     Ipp8u* pSrcDst, int srcDstStep,
                     IppiSize roiSize ))
IPPAPI (IppStatus, ippiAlphaPremulC_16u_C3IR,
                   ( Ipp16u alpha,
                     Ipp16u* pSrcDst, int srcDstStep,
                     IppiSize roiSize ))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiAlphaPremulC_8u_C1R,  ippiAlphaPremulC_16u_C1R
//                  ippiAlphaPremulC_8u_C1IR, ippiAlphaPremulC_16u_C1IR
//  Purpose:        PreMultiplies on constant alpha for 1-channel images
//                      dst_pixel = (src_pixel * const_alpha) / VAL_MAX
//  Arguments:
//     pSrc         Pointer to start of source image
//     srcStep      Step through the source image
//     alpha        The constant alpha value to use
//     pDst         Pointer to start of destination image
//     dstStep      Step through the destination image
//     pSrcDst      Pointer to start input/output image (for in-place function)
//     srcDstStep   Step through the input/output image (for in-place function)
//     roiSize      Size of the rectangle to operate upon
//  Returns:
//     ippStsNoErr            no errors
//     ippStsNullPtrErr       if pSrc == NULL or pDst == NULL or
//                               pSrcDst == NULL
//     ippStsSizeErr          if ROI sizes are negative or zero
//     ippStsStepErr          if the steps in images are negative or zero
//
//  Notes:          Value becomes 0 <= alpha <= VAL_MAX
*/

IPPAPI (IppStatus, ippiAlphaPremulC_8u_C1R,
                   ( const Ipp8u* pSrc, int srcStep,
                     Ipp8u alpha,
                     Ipp8u* pDst, int dstStep,
                     IppiSize roiSize ))
IPPAPI (IppStatus, ippiAlphaPremulC_16u_C1R,
                   ( const Ipp16u* pSrc, int srcStep,
                     Ipp16u alpha,
                     Ipp16u* pDst, int dstStep,
                     IppiSize roiSize ))

IPPAPI (IppStatus, ippiAlphaPremulC_8u_C1IR,
                   ( Ipp8u alpha,
                     Ipp8u* pSrcDst, int srcDstStep,
                     IppiSize roiSize ))
IPPAPI (IppStatus, ippiAlphaPremulC_16u_C1IR,
                   ( Ipp16u alpha,
                     Ipp16u* pSrcDst, int srcDstStep,
                     IppiSize roiSize ))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiAlphaComp_8u_AC4R, ippiAlphaComp_16u_AC4R
//                  ippiAlphaComp_8u_AP4R, ippiAlphaComp_16u_AP4R
//  Purpose:        Alpha Composite in ROI of 4-channel images with
//                  inner alpha
//  Arguments:
//     pSrc1        Pointer to start of first source image
//     src1Step     Step through the first source image
//     pSrc2        Pointer to start of second source image
//     src2Step     Step through the second source image
//     pDst         Pointer to start of destination image
//     dstStep      Step through the destination image
//     roiSize      Size of the rectangle to operate upon
//     alphaType    The type of composition to perform
//  Returns:
//     ippStsNoErr            no errors
//     ippStsNullPtrErr       if pSrc1== NULL or pSrc2== NULL or pDst == NULL
//     ippStsSizeErr          if ROI sizes are negative or zero
//     ippStsStepErr          if the steps in images are negative or zero
//     ippStsAlphaTypeErr     if alphaType incorrect
*/

IPPAPI (IppStatus, ippiAlphaComp_8u_AC4R,
                   ( const Ipp8u* pSrc1, int src1Step,
                     const Ipp8u* pSrc2, int src2Step,
                     Ipp8u* pDst, int dstStep,
                     IppiSize roiSize,
                     IppiAlphaType alphaType ))
IPPAPI (IppStatus, ippiAlphaComp_16u_AC4R,
                   ( const Ipp16u* pSrc1, int src1Step,
                     const Ipp16u* pSrc2, int src2Step,
                     Ipp16u* pDst, int dstStep,
                     IppiSize roiSize,
                     IppiAlphaType alphaType ))

IPPAPI (IppStatus, ippiAlphaComp_8u_AP4R,
                   ( const Ipp8u* const pSrc1[4], int src1Step,
                     const Ipp8u* const pSrc2[4], int src2Step,
                     Ipp8u* const pDst[4], int dstStep,
                     IppiSize roiSize,
                     IppiAlphaType alphaType ))
IPPAPI (IppStatus, ippiAlphaComp_16u_AP4R,
                   ( const Ipp16u* const pSrc1[4], int src1Step,
                     const Ipp16u* const pSrc2[4], int src2Step,
                     Ipp16u* const pDst[4], int dstStep,
                     IppiSize roiSize,
                     IppiAlphaType alphaType ))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiAlphaComp_8u_AC1R, ippiAlphaComp_16u_AC1R
//  Purpose:        Alpha Composite in ROI of 1-channel images (with alpha)
//  Arguments:
//     pSrc1        Pointer to start of first source image
//     src1Step     Step through the first source image
//     pSrc2        Pointer to start of second source image
//     src2Step     Step through the second source image
//     pDst         Pointer to start of destination image
//     dstStep      Step through the destination image
//     roiSize      Size of the rectangle to operate upon
//     alphaType    The type of composition to perform
//  Returns:
//     ippStsNoErr            no errors
//     ippStsNullPtrErr       if pSrc1== NULL or pSrc2== NULL or pDst == NULL
//     ippStsSizeErr          if ROI sizes are negative or zero
//     ippStsStepErr          if the steps in images are negative or zero
//     ippStsAlphaTypeErr     if alphaType incorrect
*/

IPPAPI (IppStatus, ippiAlphaComp_8u_AC1R,
                   ( const Ipp8u* pSrc1, int src1Step,
                     const Ipp8u* pSrc2, int src2Step,
                     Ipp8u* pDst, int dstStep,
                     IppiSize roiSize,
                     IppiAlphaType alphaType ))
IPPAPI (IppStatus, ippiAlphaComp_16u_AC1R,
                   ( const Ipp16u* pSrc1, int src1Step,
                     const Ipp16u* pSrc2, int src2Step,
                     Ipp16u* pDst, int dstStep,
                     IppiSize roiSize,
                     IppiAlphaType alphaType ))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiAlphaCompC_8u_AC4R, ippiAlphaCompC_16u_AC4R
//                  ippiAlphaCompC_8u_AP4R, ippiAlphaCompC_16u_AP4R
//  Purpose:        Alpha Composite in ROI of 4-channel images with
//                  constant alpha
//  Arguments:
//     pSrc1        Pointer to start of first source image
//     src1Step     Step through the first source image
//     alpha1       The constant alpha value to use for src1
//     pSrc2        Pointer to start of second source image
//     src2Step     Step through the second source image
//     alpha2       The constant alpha value to use for src2
//     pDst         Pointer to start of destination image
//     dstStep      Step through the destination image
//     roiSize      Size of the rectangle to operate upon
//     alphaType    The type of composition to perform
//  Returns:
//     ippStsNoErr            no errors
//     ippStsNullPtrErr       if pSrc1== NULL or pSrc2== NULL or pDst == NULL
//     ippStsSizeErr          if ROI sizes are negative or zero
//     ippStsStepErr          if the steps in images are negative or zero
//     ippStsAlphaTypeErr     if alphaType incorrect
//
//  Notes:          Alpha-channel (channel 4) remains without modifications
//                  Value becomes 0 <= alphaA <= VAL_MAX
//                                0 <= alphaB <= VAL_MAX
*/

IPPAPI (IppStatus, ippiAlphaCompC_8u_AC4R,
                   ( const Ipp8u* pSrc1, int src1Step,
                     Ipp8u alpha1,
                     const Ipp8u* pSrc2, int src2Step,
                     Ipp8u alpha2,
                     Ipp8u* pDst, int dstStep,
                     IppiSize roiSize,
                     IppiAlphaType alphaType ))
IPPAPI (IppStatus, ippiAlphaCompC_16u_AC4R,
                   ( const Ipp16u* pSrc1, int src1Step,
                     Ipp16u alpha1,
                     const Ipp16u* pSrc2, int src2Step,
                     Ipp16u alpha2,
                     Ipp16u* pDst, int dstStep,
                     IppiSize roiSize,
                     IppiAlphaType alphaType ))

IPPAPI (IppStatus, ippiAlphaCompC_8u_AP4R,
                   ( const Ipp8u* const pSrc1[4], int src1Step,
                     Ipp8u alpha1,
                     const Ipp8u* const pSrc2[4], int src2Step,
                     Ipp8u alpha2,
                     Ipp8u* const pDst[4], int dstStep,
                     IppiSize roiSize,
                     IppiAlphaType alphaType ))
IPPAPI (IppStatus, ippiAlphaCompC_16u_AP4R,
                   ( const Ipp16u* const pSrc1[4], int src1Step,
                     Ipp16u alpha1,
                     const Ipp16u* const pSrc2[4], int src2Step,
                     Ipp16u alpha2,
                     Ipp16u* const pDst[4], int dstStep,
                     IppiSize roiSize,
                     IppiAlphaType alphaType ))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiAlphaCompC_8u_C4R, ippiAlphaCompC_16u_C4R
//  Purpose:        Alpha Composite in ROI of 4-channel images with
//                  constant alpha
//  Arguments:
//     pSrc1        Pointer to start of first source image
//     src1Step     Step through the first source image
//     alpha1       The constant alpha value to use for src1
//     pSrc2        Pointer to start of second source image
//     src2Step     Step through the second source image
//     alpha2       The constant alpha value to use for src2
//     pDst         Pointer to start of destination image
//     dstStep      Step through the destination image
//     roiSize      Size of the rectangle to operate upon
//     alphaType    The type of composition to perform
//  Returns:
//     ippStsNoErr            no errors
//     ippStsNullPtrErr       if pSrc1== NULL or pSrc2== NULL or pDst == NULL
//     ippStsSizeErr          if ROI sizes are negative or zero
//     ippStsStepErr          if the steps in images are negative or zero
//     ippStsAlphaTypeErr     if alphaType incorrect
//
//  Notes:          Value becomes 0 <= alphaA <= VAL_MAX
//                                0 <= alphaB <= VAL_MAX
*/

IPPAPI (IppStatus, ippiAlphaCompC_8u_C4R,
                   ( const Ipp8u* pSrc1, int src1Step,
                     Ipp8u alpha1,
                     const Ipp8u* pSrc2, int src2Step,
                     Ipp8u alpha2,
                     Ipp8u* pDst, int dstStep,
                     IppiSize roiSize,
                     IppiAlphaType alphaType ))
IPPAPI (IppStatus, ippiAlphaCompC_16u_C4R,
                   ( const Ipp16u* pSrc1, int src1Step,
                     Ipp16u alpha1,
                     const Ipp16u* pSrc2, int src2Step,
                     Ipp16u alpha2,
                     Ipp16u* pDst, int dstStep,
                     IppiSize roiSize,
                     IppiAlphaType alphaType ))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiAlphaCompC_8u_C3R, ippiAlphaCompC_16u_C3R
//  Purpose:        Alpha Composite in ROI of 3-channel images with
//                  constant alpha
//  Arguments:
//     pSrc1        Pointer to start of first source image
//     src1Step     Step through the first source image
//     alpha1       The constant alpha value to use for src1
//     pSrc2        Pointer to start of second source image
//     src2Step     Step through the second source image
//     alpha2       The constant alpha value to use for src2
//     pDst         Pointer to start of destination image
//     dstStep      Step through the destination image
//     roiSize      Size of the rectangle to operate upon
//     alphaType    The type of composition to perform
//  Returns:
//     ippStsNoErr            no errors
//     ippStsNullPtrErr       if pSrc1== NULL or pSrc2== NULL or pDst == NULL
//     ippStsSizeErr          if ROI sizes are negative or zero
//     ippStsStepErr          if the steps in images are negative or zero
//     ippStsAlphaTypeErr     if alphaType incorrect
//
//  Notes:          Value becomes 0 <= alphaA <= VAL_MAX
//                                0 <= alphaB <= VAL_MAX
*/

IPPAPI (IppStatus, ippiAlphaCompC_8u_C3R,
                   ( const Ipp8u* pSrc1, int src1Step,
                     Ipp8u alpha1,
                     const Ipp8u* pSrc2, int src2Step,
                     Ipp8u alpha2,
                     Ipp8u* pDst, int dstStep,
                     IppiSize roiSize,
                     IppiAlphaType alphaType ))
IPPAPI (IppStatus, ippiAlphaCompC_16u_C3R,
                   ( const Ipp16u* pSrc1, int src1Step,
                     Ipp16u alpha1,
                     const Ipp16u* pSrc2, int src2Step,
                     Ipp16u alpha2,
                     Ipp16u* pDst, int dstStep,
                     IppiSize roiSize,
                     IppiAlphaType alphaType ))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiAlphaCompC_8u_C1R, ippiAlphaCompC_16u_C1R
//  Purpose:        Alpha Composite in ROI of 1-channel images with
//                  constant alpha
//  Arguments:
//     pSrc1        Pointer to start of first source image
//     src1Step     Step through the first source image
//     alpha1       The constant alpha value to use for src1
//     pSrc2        Pointer to start of second source image
//     src2Step     Step through the second source image
//     alpha2       The constant alpha value to use for src2
//     pDst         Pointer to start of destination image
//     dstStep      Step through the destination image
//     roiSize      Size of the rectangle to operate upon
//     alphaType    The type of composition to perform
//  Returns:
//     ippStsNoErr            no errors
//     ippStsNullPtrErr       if pSrc1== NULL or pSrc2== NULL or pDst == NULL
//     ippStsSizeErr          if ROI sizes are negative or zero
//     ippStsStepErr          if the steps in images are negative or zero
//     ippStsAlphaTypeErr     if alphaType incorrect
//
//  Notes:          Value becomes 0 <= alphaA <= VAL_MAX
//                                0 <= alphaB <= VAL_MAX
*/

IPPAPI (IppStatus, ippiAlphaCompC_8u_C1R,
                   ( const Ipp8u* pSrc1, int src1Step,
                     Ipp8u alpha1,
                     const Ipp8u* pSrc2, int src2Step,
                     Ipp8u alpha2,
                     Ipp8u* pDst, int dstStep,
                     IppiSize roiSize,
                     IppiAlphaType alphaType ))
IPPAPI (IppStatus, ippiAlphaCompC_16u_C1R,
                   ( const Ipp16u* pSrc1, int src1Step,
                     Ipp16u alpha1,
                     const Ipp16u* pSrc2, int src2Step,
                     Ipp16u alpha2,
                     Ipp16u* pDst, int dstStep,
                     IppiSize roiSize,
                     IppiAlphaType alphaType ))




/* /////////////////////////////////////////////////////////////////////////////
//                  Operations of Linear Transforming
///////////////////////////////////////////////////////////////////////////// */

/* /////////////////////////////////////////////////////////////////////////////
//                  Definitions for FFT Functions
///////////////////////////////////////////////////////////////////////////// */

#if !defined( _OWN_BLDPCS )

struct FFT2DSpec_C_32fc;
typedef struct FFT2DSpec_C_32fc IppiFFTSpec_C_32fc;
struct FFT2DSpec_R_32f;
typedef struct FFT2DSpec_R_32f IppiFFTSpec_R_32f;

struct FFT2DSpec_R_32s;
typedef struct FFT2DSpec_R_32s IppiFFTSpec_R_32s;

#endif /* _OWN_BLDPCS */


/* /////////////////////////////////////////////////////////////////////////////
//                  FFT Context Functions
///////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippiFFTInitAlloc
//  Purpose:    create and initialize of FFT context
//  Arguments:
//     orderX   - base-2 logarithm of the number of samples in FFT (width)
//     orderY   - base-2 logarithm of the number of samples in FFT (height)
//     flag     - normalization flag
//     hint     - code specific use hints
//     pFFTSpec - where write pointer to new context
//  Returns:
//     ippStsNoErr            no errors
//     ippStsNullPtrErr       pFFTSpec == NULL
//     ippStsFftOrderErr      bad the order value
//     ippStsFFTFlagErr       bad the normalization flag value
//     ippStsMemAllocErr      memory allocation error
*/

IPPAPI (IppStatus, ippiFFTInitAlloc_C_32fc,
                   ( IppiFFTSpec_C_32fc** pFFTSpec,
                     int orderX, int orderY, int flag, IppHintAlgorithm hint ))
IPPAPI (IppStatus, ippiFFTInitAlloc_R_32f,
                   ( IppiFFTSpec_R_32f** pFFTSpec,
                     int orderX, int orderY, int flag, IppHintAlgorithm hint ))

IPPAPI (IppStatus, ippiFFTInitAlloc_R_32s,
                   ( IppiFFTSpec_R_32s** pFFTSpec,
                     int orderX, int orderY, int flag, IppHintAlgorithm hint ))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippiFFTFree
//  Purpose:    delete FFT context
//  Arguments:
//     pFFTSpec - pointer to FFT context to be deleted
//  Returns:
//     ippStsNoErr            no errors
//     ippStsNullPtrErr       pFFTSpec == NULL
//     ippStsContextMatchErr  bad context identifier
*/

IPPAPI (IppStatus, ippiFFTFree_C_32fc, ( IppiFFTSpec_C_32fc* pFFTSpec ))
IPPAPI (IppStatus, ippiFFTFree_R_32f, ( IppiFFTSpec_R_32f*  pFFTSpec ))

IPPAPI (IppStatus, ippiFFTFree_R_32s, ( IppiFFTSpec_R_32s*  pFFTSpec ))


/* /////////////////////////////////////////////////////////////////////////////
//                  FFT Buffer Size
///////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippiFFTGetBufSize
//  Purpose:    get size of the FFT work buffer (on bytes)
//  Arguments:
//     pFFTSpec - pointer to FFT context
//     size     - where write size of buffer
//  Returns:
//     ippStsNoErr            no errors
//     ippStsNullPtrErr       pFFTSpec == NULL or size == NULL
//     ippStsContextMatchErr  bad context identifier
*/

IPPAPI (IppStatus, ippiFFTGetBufSize_C_32fc,
                   ( const IppiFFTSpec_C_32fc* pFFTSpec, int* size ))
IPPAPI (IppStatus, ippiFFTGetBufSize_R_32f,
                   ( const IppiFFTSpec_R_32f* pFFTSpec, int* size ))

IPPAPI (IppStatus, ippiFFTGetBufSize_R_32s,
                   ( const IppiFFTSpec_R_32s* pFFTSpec, int* size ))


/* /////////////////////////////////////////////////////////////////////////////
//                  FFT Transforms
///////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippiFFTFwd, ippiFFTInv
//  Purpose:    compute forward and inverse FFT of image
//  Arguments:
//     pFFTSpec - pointer to FFT context
//     pSrc     - pointer to source signal
//     srcStep  - the step in Src image
//     pDst     - pointer to destination signal
//     dstStep  - the step in Dst image
//     pBuffer  - pointer to work buffer
//  Returns:
//     ippStsNoErr            no errors
//     ippStsNullPtrErr       pFFTSpec == NULL or
//                            pSrc == NULL or pDst == NULL
//     ippStsStepErr          bad srcStep or dstStep value
//     ippStsContextMatchErr  bad context identifier
//     ippStsMemAllocErr      memory allocation error
*/

IPPAPI (IppStatus, ippiFFTFwd_CToC_32fc_C1R,
                   ( const Ipp32fc* pSrc, int srcStep,
                     Ipp32fc* pDst, int dstStep,
                     const IppiFFTSpec_C_32fc* pFFTSpec,
                     Ipp8u* pBuffer ))
IPPAPI (IppStatus, ippiFFTInv_CToC_32fc_C1R,
                   ( const Ipp32fc* pSrc, int srcStep,
                     Ipp32fc* pDst, int dstStep,
                     const IppiFFTSpec_C_32fc* pFFTSpec,
                     Ipp8u* pBuffer ))

IPPAPI (IppStatus, ippiFFTFwd_RToPack_32f_C1R,
                   ( const Ipp32f* pSrc, int srcStep,
                     Ipp32f* pDst, int dstStep,
                     const IppiFFTSpec_R_32f* pFFTSpec,
                     Ipp8u* pBuffer ))
IPPAPI (IppStatus, ippiFFTFwd_RToPack_32f_C3R,
                   ( const Ipp32f* pSrc, int srcStep,
                     Ipp32f* pDst, int dstStep,
                     const IppiFFTSpec_R_32f* pFFTSpec,
                     Ipp8u* pBuffer ))
IPPAPI (IppStatus, ippiFFTFwd_RToPack_32f_C4R,
                   ( const Ipp32f* pSrc, int srcStep,
                     Ipp32f* pDst, int dstStep,
                     const IppiFFTSpec_R_32f* pFFTSpec,
                     Ipp8u* pBuffer ))
IPPAPI (IppStatus, ippiFFTFwd_RToPack_32f_AC4R,
                   ( const Ipp32f* pSrc, int srcStep,
                     Ipp32f* pDst, int dstStep,
                     const IppiFFTSpec_R_32f* pFFTSpec,
                     Ipp8u* pBuffer ))

IPPAPI (IppStatus, ippiFFTInv_PackToR_32f_C1R,
                   ( const Ipp32f* pSrc, int srcStep,
                     Ipp32f* pDst, int dstStep,
                     const IppiFFTSpec_R_32f* pFFTSpec,
                     Ipp8u* pBuffer ))
IPPAPI (IppStatus, ippiFFTInv_PackToR_32f_C3R,
                   ( const Ipp32f* pSrc, int srcStep,
                     Ipp32f* pDst, int dstStep,
                     const IppiFFTSpec_R_32f* pFFTSpec,
                     Ipp8u* pBuffer ))
IPPAPI (IppStatus, ippiFFTInv_PackToR_32f_C4R,
                   ( const Ipp32f* pSrc, int srcStep,
                     Ipp32f* pDst, int dstStep,
                     const IppiFFTSpec_R_32f* pFFTSpec,
                     Ipp8u* pBuffer ))
IPPAPI (IppStatus, ippiFFTInv_PackToR_32f_AC4R,
                   ( const Ipp32f* pSrc, int srcStep,
                     Ipp32f* pDst, int dstStep,
                     const IppiFFTSpec_R_32f* pFFTSpec,
                     Ipp8u* pBuffer ))

IPPAPI (IppStatus, ippiFFTFwd_RToPack_8u32s_C1RSfs,
                   ( const Ipp8u *pSrc, int srcStep,
                     Ipp32s *pDst, int dstStep,
                     const IppiFFTSpec_R_32s* pFFTSpec,
                     int scaleFactor, Ipp8u *pBuffer ))
IPPAPI (IppStatus, ippiFFTFwd_RToPack_8u32s_C3RSfs,
                   ( const Ipp8u *pSrc, int srcStep,
                     Ipp32s *pDst, int dstStep,
                     const IppiFFTSpec_R_32s* pFFTSpec,
                     int scaleFactor, Ipp8u *pBuffer ))
IPPAPI (IppStatus, ippiFFTFwd_RToPack_8u32s_C4RSfs,
                   ( const Ipp8u *pSrc, int srcStep,
                     Ipp32s *pDst, int dstStep,
                     const IppiFFTSpec_R_32s* pFFTSpec,
                     int scaleFactor, Ipp8u *pBuffer ))
IPPAPI (IppStatus, ippiFFTFwd_RToPack_8u32s_AC4RSfs,
                   ( const Ipp8u *pSrc, int srcStep,
                     Ipp32s *pDst, int dstStep,
                     const IppiFFTSpec_R_32s* pFFTSpec,
                     int scaleFactor, Ipp8u *pBuffer ))

IPPAPI (IppStatus, ippiFFTInv_PackToR_32s8u_C1RSfs,
                   ( const Ipp32s *pSrc, int srcStep,
                     Ipp8u *pDst, int dstStep,
                     const IppiFFTSpec_R_32s* pFFTSpec,
                     int scaleFactor, Ipp8u *pBuffer ))
IPPAPI (IppStatus, ippiFFTInv_PackToR_32s8u_C3RSfs,
                   ( const Ipp32s *pSrc, int srcStep,
                     Ipp8u *pDst, int dstStep,
                     const IppiFFTSpec_R_32s* pFFTSpec,
                     int scaleFactor, Ipp8u *pBuffer ))
IPPAPI (IppStatus, ippiFFTInv_PackToR_32s8u_C4RSfs,
                   ( const Ipp32s *pSrc, int srcStep,
                     Ipp8u *pDst, int dstStep,
                     const IppiFFTSpec_R_32s* pFFTSpec,
                     int scaleFactor, Ipp8u *pBuffer ))
IPPAPI (IppStatus, ippiFFTInv_PackToR_32s8u_AC4RSfs,
                   ( const Ipp32s *pSrc, int srcStep,
                     Ipp8u *pDst, int dstStep,
                     const IppiFFTSpec_R_32s* pFFTSpec,
                     int scaleFactor, Ipp8u *pBuffer ))


/* /////////////////////////////////////////////////////////////////////////////
//                  Definitions for DFT Functions
///////////////////////////////////////////////////////////////////////////// */

#if !defined( _OWN_BLDPCS )

struct DFT2DSpec_C_32fc;
typedef struct DFT2DSpec_C_32fc IppiDFTSpec_C_32fc;
struct DFT2DSpec_R_32f;
typedef struct DFT2DSpec_R_32f IppiDFTSpec_R_32f;

struct DFT2DSpec_R_32s;
typedef struct DFT2DSpec_R_32s IppiDFTSpec_R_32s;

#endif /* _OWN_BLDPCS */


/* /////////////////////////////////////////////////////////////////////////////
//                  DFT Context Functions
///////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippiDFTInitAlloc
//  Purpose:    create and initialize of DFT context
//  Arguments:
//     roiSize  - size of ROI
//     flag     - normalization flag
//     hint     - code specific use hints
//     pDFTSpec - where write pointer to new context
//  Returns:
//     ippStsNoErr            no errors
//     ippStsNullPtrErr       pDFTSpec == NULL
//     ippStsSizeErr          bad size of the ROI
//     ippStsFFTFlagErr       bad the normalization flag value
//     ippStsMemAllocErr      memory allocation error
*/

IPPAPI (IppStatus, ippiDFTInitAlloc_C_32fc,
                   ( IppiDFTSpec_C_32fc** pDFTSpec,
                     IppiSize roiSize, int flag, IppHintAlgorithm hint ))
IPPAPI (IppStatus, ippiDFTInitAlloc_R_32f,
                   ( IppiDFTSpec_R_32f** pDFTSpec,
                     IppiSize roiSize, int flag, IppHintAlgorithm hint ))

IPPAPI (IppStatus, ippiDFTInitAlloc_R_32s,
                   ( IppiDFTSpec_R_32s** pDFTSpec,
                     IppiSize roiSize, int flag, IppHintAlgorithm hint ))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippiDFTFree
//  Purpose:    delete DFT context
//  Arguments:
//     pDFTSpec - pointer to DFT context to be deleted
//  Returns:
//     ippStsNoErr            no errors
//     ippStsNullPtrErr       pDFTSpec == NULL
//     ippStsContextMatchErr  bad context identifier
*/

IPPAPI (IppStatus, ippiDFTFree_C_32fc, ( IppiDFTSpec_C_32fc* pDFTSpec ))
IPPAPI (IppStatus, ippiDFTFree_R_32f, ( IppiDFTSpec_R_32f*  pDFTSpec ))

IPPAPI (IppStatus, ippiDFTFree_R_32s, ( IppiDFTSpec_R_32s*  pFFTSpec ))


/* /////////////////////////////////////////////////////////////////////////////
//                  DFT Buffer Size
///////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippiDFTGetBufSize
//  Purpose:    get size of the DFT work buffer (on bytes)
//  Arguments:
//     pDFTSpec - pointer to DFT context
//     size     - where write size of buffer
//  Returns:
//     ippStsNoErr            no errors
//     ippStsNullPtrErr       pDFTSpec == NULL or size == NULL
//     ippStsContextMatchErr  bad context identifier
*/

IPPAPI (IppStatus, ippiDFTGetBufSize_C_32fc,
                   ( const IppiDFTSpec_C_32fc* pDFTSpec, int* size ))
IPPAPI (IppStatus, ippiDFTGetBufSize_R_32f,
                   ( const IppiDFTSpec_R_32f* pDFTSpec, int* size ))

IPPAPI (IppStatus, ippiDFTGetBufSize_R_32s,
                   ( const IppiDFTSpec_R_32s* pDFTSpec, int* size ))


/* /////////////////////////////////////////////////////////////////////////////
//                  DFT Transforms
///////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippiDFTFwd, ippiDFTInv
//  Purpose:    compute forward and inverse DFT of image
//  Arguments:
//     pDFTSpec - pointer to DFT context
//     pSrc     - pointer to source signal
//     srcStep  - the step in Src image
//     pDst     - pointer to destination signal
//     dstStep  - the step in Dst image
//     pBuffer  - pointer to work buffer
//  Returns:
//     ippStsNoErr            no errors
//     ippStsNullPtrErr       pDFTSpec == NULL or
//                            pSrc == NULL or pDst == NULL
//     ippStsStepErr          bad srcStep or dstStep value
//     ippStsContextMatchErr  bad context identifier
//     ippStsMemAllocErr      memory allocation error
*/

IPPAPI (IppStatus, ippiDFTFwd_CToC_32fc_C1R,
                   ( const Ipp32fc* pSrc, int srcStep,
                     Ipp32fc* pDst, int dstStep,
                     const IppiDFTSpec_C_32fc* pDFTSpec,
                     Ipp8u* pBuffer ))
IPPAPI (IppStatus, ippiDFTInv_CToC_32fc_C1R,
                   ( const Ipp32fc* pSrc, int srcStep,
                     Ipp32fc* pDst, int dstStep,
                     const IppiDFTSpec_C_32fc* pDFTSpec,
                     Ipp8u* pBuffer ))

IPPAPI (IppStatus, ippiDFTFwd_RToPack_32f_C1R,
                   ( const Ipp32f* pSrc, int srcStep,
                     Ipp32f* pDst, int dstStep,
                     const IppiDFTSpec_R_32f* pDFTSpec,
                     Ipp8u* pBuffer ))
IPPAPI (IppStatus, ippiDFTFwd_RToPack_32f_C3R,
                   ( const Ipp32f* pSrc, int srcStep,
                     Ipp32f* pDst, int dstStep,
                     const IppiDFTSpec_R_32f* pDFTSpec,
                     Ipp8u* pBuffer ))
IPPAPI (IppStatus, ippiDFTFwd_RToPack_32f_C4R,
                   ( const Ipp32f* pSrc, int srcStep,
                     Ipp32f* pDst, int dstStep,
                     const IppiDFTSpec_R_32f* pDFTSpec,
                     Ipp8u* pBuffer ))
IPPAPI (IppStatus, ippiDFTFwd_RToPack_32f_AC4R,
                   ( const Ipp32f* pSrc, int srcStep,
                     Ipp32f* pDst, int dstStep,
                     const IppiDFTSpec_R_32f* pDFTSpec,
                     Ipp8u* pBuffer ))

IPPAPI (IppStatus, ippiDFTInv_PackToR_32f_C1R,
                   ( const Ipp32f* pSrc, int srcStep,
                     Ipp32f* pDst, int dstStep,
                     const IppiDFTSpec_R_32f* pDFTSpec,
                     Ipp8u* pBuffer ))
IPPAPI (IppStatus, ippiDFTInv_PackToR_32f_C3R,
                   ( const Ipp32f* pSrc, int srcStep,
                     Ipp32f* pDst, int dstStep,
                     const IppiDFTSpec_R_32f* pDFTSpec,
                     Ipp8u* pBuffer ))
IPPAPI (IppStatus, ippiDFTInv_PackToR_32f_C4R,
                   ( const Ipp32f* pSrc, int srcStep,
                     Ipp32f* pDst, int dstStep,
                     const IppiDFTSpec_R_32f* pDFTSpec,
                     Ipp8u* pBuffer ))
IPPAPI (IppStatus, ippiDFTInv_PackToR_32f_AC4R,
                   ( const Ipp32f* pSrc, int srcStep,
                     Ipp32f* pDst, int dstStep,
                     const IppiDFTSpec_R_32f* pDFTSpec,
                     Ipp8u* pBuffer ))

IPPAPI (IppStatus, ippiDFTFwd_RToPack_8u32s_C1RSfs,
                   ( const Ipp8u *pSrc, int srcStep,
                     Ipp32s *pDst, int dstStep,
                     const IppiDFTSpec_R_32s* pDFTSpec,
                     int scaleFactor, Ipp8u *pBuffer ))
IPPAPI (IppStatus, ippiDFTFwd_RToPack_8u32s_C3RSfs,
                   ( const Ipp8u *pSrc, int srcStep,
                     Ipp32s *pDst, int dstStep,
                     const IppiDFTSpec_R_32s* pDFTSpec,
                     int scaleFactor, Ipp8u *pBuffer ))
IPPAPI (IppStatus, ippiDFTFwd_RToPack_8u32s_C4RSfs,
                   ( const Ipp8u *pSrc, int srcStep,
                     Ipp32s *pDst, int dstStep,
                     const IppiDFTSpec_R_32s* pDFTSpec,
                     int scaleFactor, Ipp8u *pBuffer ))
IPPAPI (IppStatus, ippiDFTFwd_RToPack_8u32s_AC4RSfs,
                   ( const Ipp8u *pSrc, int srcStep,
                     Ipp32s *pDst, int dstStep,
                     const IppiDFTSpec_R_32s* pDFTSpec,
                     int scaleFactor, Ipp8u *pBuffer ))

IPPAPI (IppStatus, ippiDFTInv_PackToR_32s8u_C1RSfs,
                   ( const Ipp32s *pSrc, int srcStep,
                     Ipp8u *pDst, int dstStep,
                     const IppiDFTSpec_R_32s* pDFTSpec,
                     int scaleFactor, Ipp8u *pBuffer ))
IPPAPI (IppStatus, ippiDFTInv_PackToR_32s8u_C3RSfs,
                   ( const Ipp32s *pSrc, int srcStep,
                     Ipp8u *pDst, int dstStep,
                     const IppiDFTSpec_R_32s* pDFTSpec,
                     int scaleFactor, Ipp8u *pBuffer ))
IPPAPI (IppStatus, ippiDFTInv_PackToR_32s8u_C4RSfs,
                   ( const Ipp32s *pSrc, int srcStep,
                     Ipp8u *pDst, int dstStep,
                     const IppiDFTSpec_R_32s* pDFTSpec,
                     int scaleFactor, Ipp8u *pBuffer ))
IPPAPI (IppStatus, ippiDFTInv_PackToR_32s8u_AC4RSfs,
                   ( const Ipp32s *pSrc, int srcStep,
                     Ipp8u *pDst, int dstStep,
                     const IppiDFTSpec_R_32s* pDFTSpec,
                     int scaleFactor, Ipp8u *pBuffer ))


/* /////////////////////////////////////////////////////////////////////////////
//                  Definitions for DCT Functions
///////////////////////////////////////////////////////////////////////////// */

#if !defined( _OWN_BLDPCS )

struct DCT2DFwdSpec_32f;
typedef struct DCT2DFwdSpec_32f IppiDCTFwdSpec_32f;
struct DCT2DInvSpec_32f;
typedef struct DCT2DInvSpec_32f IppiDCTInvSpec_32f;

#endif /* _OWN_BLDPCS */


/* /////////////////////////////////////////////////////////////////////////////
//                  DCT Context Functions
///////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippiDCTFwdInitAlloc, ippiDCTInvInitAlloc
//  Purpose:    create and initialize of DCT context
//  Arguments:
//     roiSize  - size of ROI
//     hint     - code specific use hints
//     pDCTSpec - where write pointer to new context
//  Returns:
//     ippStsNoErr            no errors
//     ippStsNullPtrErr       pDCTSpec == NULL
//     ippStsSizeErr          bad size of the ROI
//     ippStsMemAllocErr      memory allocation error
*/

IPPAPI (IppStatus, ippiDCTFwdInitAlloc_32f,
                   ( IppiDCTFwdSpec_32f** pDCTSpec,
                     IppiSize roiSize, IppHintAlgorithm hint ))
IPPAPI (IppStatus, ippiDCTInvInitAlloc_32f,
                   ( IppiDCTInvSpec_32f** pDCTSpec,
                     IppiSize roiSize, IppHintAlgorithm hint ))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippiDCTFwdFree, ippiDCTInvFree
//  Purpose:    delete DCT context
//  Arguments:
//     pDCTSpec - pointer to DCT context to be deleted
//  Returns:
//     ippStsNoErr            no errors
//     ippStsNullPtrErr       pDCTSpec == NULL
//     ippStsContextMatchErr  bad context identifier
*/

IPPAPI (IppStatus, ippiDCTFwdFree_32f, ( IppiDCTFwdSpec_32f*  pDCTSpec ))
IPPAPI (IppStatus, ippiDCTInvFree_32f, ( IppiDCTInvSpec_32f*  pDCTSpec ))


/* /////////////////////////////////////////////////////////////////////////////
//                  DCT Buffer Size
///////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippiDCTFwdGetBufSize, ippiDCTInvGetBufSize
//  Purpose:    get size of the DCT work buffer (on bytes)
//  Arguments:
//     pDCTSpec - pointer to DCT context
//     size     - where write size of buffer
//  Returns:
//     ippStsNoErr            no errors
//     ippStsNullPtrErr       pDCTSpec == NULL or size == NULL
//     ippStsContextMatchErr  bad context identifier
*/

IPPAPI (IppStatus, ippiDCTFwdGetBufSize_32f,
                   ( const IppiDCTFwdSpec_32f* pDCTSpec, int* size ))
IPPAPI (IppStatus, ippiDCTInvGetBufSize_32f,
                   ( const IppiDCTInvSpec_32f* pDCTSpec, int* size ))


/* /////////////////////////////////////////////////////////////////////////////
//                  DCT Transforms
///////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippiDCTFwd, ippiDCTInv
//  Purpose:    compute forward and inverse DCT of image
//  Arguments:
//     pDCTSpec - pointer to DCT context
//     pSrc     - pointer to source signal
//     srcStep  - the step in Src image
//     pDst     - pointer to destination signal
//     dstStep  - the step in Dst image
//     pBuffer  - pointer to work buffer
//  Returns:
//     ippStsNoErr            no errors
//     ippStsNullPtrErr       pDCTSpec == NULL or
//                            pSrc == NULL or pDst == NULL
//     ippStsStepErr          bad srcStep or dstStep value
//     ippStsContextMatchErr  bad context identifier
//     ippStsMemAllocErr      memory allocation error
*/

IPPAPI (IppStatus, ippiDCTFwd_32f_C1R,
                   ( const Ipp32f* pSrc, int srcStep,
                     Ipp32f* pDst, int dstStep,
                     const IppiDCTFwdSpec_32f* pDCTSpec,
                     Ipp8u* pBuffer ))
IPPAPI (IppStatus, ippiDCTFwd_32f_C3R,
                   ( const Ipp32f* pSrc, int srcStep,
                     Ipp32f* pDst, int dstStep,
                     const IppiDCTFwdSpec_32f* pDCTSpec,
                     Ipp8u* pBuffer ))
IPPAPI (IppStatus, ippiDCTFwd_32f_C4R,
                   ( const Ipp32f* pSrc, int srcStep,
                     Ipp32f* pDst, int dstStep,
                     const IppiDCTFwdSpec_32f* pDCTSpec,
                     Ipp8u* pBuffer ))
IPPAPI (IppStatus, ippiDCTFwd_32f_AC4R,
                   ( const Ipp32f* pSrc, int srcStep,
                     Ipp32f* pDst, int dstStep,
                     const IppiDCTFwdSpec_32f* pDCTSpec,
                     Ipp8u* pBuffer ))

IPPAPI (IppStatus, ippiDCTInv_32f_C1R,
                   ( const Ipp32f* pSrc, int srcStep,
                     Ipp32f* pDst, int dstStep,
                     const IppiDCTInvSpec_32f* pDCTSpec,
                     Ipp8u* pBuffer ))
IPPAPI (IppStatus, ippiDCTInv_32f_C3R,
                   ( const Ipp32f* pSrc, int srcStep,
                     Ipp32f* pDst, int dstStep,
                     const IppiDCTInvSpec_32f* pDCTSpec,
                     Ipp8u* pBuffer ))
IPPAPI (IppStatus, ippiDCTInv_32f_C4R,
                   ( const Ipp32f* pSrc, int srcStep,
                     Ipp32f* pDst, int dstStep,
                     const IppiDCTInvSpec_32f* pDCTSpec,
                     Ipp8u* pBuffer ))
IPPAPI (IppStatus, ippiDCTInv_32f_AC4R,
                   ( const Ipp32f* pSrc, int srcStep,
                     Ipp32f* pDst, int dstStep,
                     const IppiDCTInvSpec_32f* pDCTSpec,
                     Ipp8u* pBuffer ))


/* /////////////////////////////////////////////////////////////////////////////
//                  DCT 8x8 Transforms
///////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////
//  Name:      ippiDCT8x8Fwd_16s_C1, ippiDCT8x8Fwd_16s_C1I
//             ippiDCT8x8Inv_16s_C1, ippiDCT8x8Inv_16s_C1I
//             ippiDCT8x8Fwd_16s_C1R
//             ippiDCT8x8Inv_16s_C1R
//  Purpose:   Forward and Inverse Discrete Cosine Transform 8x8 for 16s data
//
//  Arguments:
//     pSrc     - pointer to start of source buffer
//     pDst     - pointer to start of destination buffer
//     pSrcDst  - pointer to start of in-place buffer
//     srcStep  - the step in Src image
//     dstStep  - the step in Dst image
//  Returns:
//     ippStsNoErr            no errors
//     ippStsNullPtrErr       one of pointers are NULL
//     ippStsStepErr          bad srcStep or dstStep value
*/

IPPAPI (IppStatus, ippiDCT8x8Fwd_16s_C1,  ( const Ipp16s* pSrc, Ipp16s* pDst ))
IPPAPI (IppStatus, ippiDCT8x8Inv_16s_C1,  ( const Ipp16s* pSrc, Ipp16s* pDst ))

IPPAPI (IppStatus, ippiDCT8x8Fwd_16s_C1I, ( Ipp16s* pSrcDst ))
IPPAPI (IppStatus, ippiDCT8x8Inv_16s_C1I, ( Ipp16s* pSrcDst ))

IPPAPI (IppStatus, ippiDCT8x8Fwd_16s_C1R,
                           ( const Ipp16s* pSrc, int srcStep, Ipp16s* pDst ))
IPPAPI (IppStatus, ippiDCT8x8Inv_16s_C1R,
                           ( const Ipp16s* pSrc, Ipp16s* pDst, int dstStep ))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:      ippiDCT8x8Fwd_8u16s_C1R
//             ippiDCT8x8Inv_16s8u_C1R
//  Purpose:   Forward and Inverse Discrete Cosine Transform 8x8 for 16s data
//             with conversion from/to 8u
//  Arguments:
//     pSrc     - pointer to start of source buffer
//     pDst     - pointer to start of destination buffer
//     srcStep  - the step in Src image
//     dstStep  - the step in Dst image
//  Returns:
//     ippStsNoErr            no errors
//     ippStsNullPtrErr       one of pointers are NULL
//     ippStsStepErr          bad srcStep or dstStep value
*/

IPPAPI (IppStatus, ippiDCT8x8Fwd_8u16s_C1R,
                   ( const Ipp8u* pSrc, int srcStep, Ipp16s* pDst ))

IPPAPI (IppStatus, ippiDCT8x8Inv_16s8u_C1R,
                   ( const Ipp16s* pSrc, Ipp8u* pDst, int dstStep ))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:      ippiDCT8x8FwdLS_8u16s_C1R
//  Purpose:   Forward Discrete Cosine Transform 8x8 for 16s data
//             with conversion from 8u and level shift
//  Arguments:
//     pSrc     - pointer to start of source buffer
//     pDst     - pointer to start of destination buffer
//     srcStep  - the step in Src image
//     addVal   - constant value for ADD before DCT transform (level shift)
//  Returns:
//     ippStsNoErr            no errors
//     ippStsNullPtrErr       one of pointers are NULL
//     ippStsStepErr          bad srcStep value
*/

IPPAPI (IppStatus, ippiDCT8x8FwdLS_8u16s_C1R,
                   ( const Ipp8u* pSrc, int srcStep, Ipp16s* pDst,
                     Ipp16s addVal ))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:      ippiDCT8x8InvLSClip_16s8u_C1R
//  Purpose:   Inverse Discrete Cosine Transform 8x8 for 16s data
//             with level shift, clipping and conversion to 8u
//  Arguments:
//     pSrc     - pointer to start of source buffer
//     pDst     - pointer to start of destination buffer
//     dstStep  - the step in Dst image
//     addVal   - constant value for ADD after DCT transform (level shift)
//     clipDown - constant value for clipping (MIN)
//     clipUp   - constant value for clipping (MAX)
//  Returns:
//     ippStsNoErr            no errors
//     ippStsNullPtrErr       one of pointers are NULL
//     ippStsStepErr          bad dstStep value
*/

IPPAPI (IppStatus, ippiDCT8x8InvLSClip_16s8u_C1R,
                   ( const Ipp16s* pSrc, Ipp8u* pDst, int dstStep,
                     Ipp16s addVal, Ipp8u clipDown, Ipp8u clipUp ))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:      ippiDCT8x8Fwd_32f_C1, ippiDCT8x8Fwd_32f_C1I
//             ippiDCT8x8Inv_32f_C1, ippiDCT8x8Inv_32f_C1I
//  Purpose:   Forward and Inverse Discrete Cosine Transform 8x8 for 32f data
//  Arguments:
//     pSrc     - pointer to start of source buffer
//     pDst     - pointer to start of destination buffer
//     pSrcDst  - pointer to start of in-place buffer
//  Returns:
//     ippStsNoErr            no errors
//     ippStsNullPtrErr       one of pointers are NULL
*/

IPPAPI (IppStatus, ippiDCT8x8Fwd_32f_C1,  ( const Ipp32f* pSrc, Ipp32f* pDst ))
IPPAPI (IppStatus, ippiDCT8x8Inv_32f_C1,  ( const Ipp32f* pSrc, Ipp32f* pDst ))

IPPAPI (IppStatus, ippiDCT8x8Fwd_32f_C1I, ( Ipp32f* pSrcDst ))
IPPAPI (IppStatus, ippiDCT8x8Inv_32f_C1I, ( Ipp32f* pSrcDst ))



/* /////////////////////////////////////////////////////////////////////////////
//          Wavelet Transform Fucntions for User Filter Banks
///////////////////////////////////////////////////////////////////////////// */

#if !defined( _OWN_BLDPCS )

struct iWTFwdSpec_32f_C1R;
typedef struct iWTFwdSpec_32f_C1R IppiWTFwdSpec_32f_C1R;

struct iWTInvSpec_32f_C1R;
typedef struct iWTInvSpec_32f_C1R IppiWTInvSpec_32f_C1R;

struct iWTFwdSpec_32f_C3R;
typedef struct iWTFwdSpec_32f_C3R IppiWTFwdSpec_32f_C3R;

struct iWTInvSpec_32f_C3R;
typedef struct iWTInvSpec_32f_C3R IppiWTInvSpec_32f_C3R;

#endif /* _OWN_BLDPCS */


/* //////////////////////////////////////////////////////////////////////
// Name:       ippiWTFwdInitAlloc_32f_C1R
//             ippiWTFwdInitAlloc_32f_C3R
// Purpose:    Allocate and initialize
//                forward wavelet transform context structure.
// Parameters:
//   pSpec      - pointer to pointer to allocated and initialized
//                 context structure;
//   pTapsLow   - pointer to lowpass filter taps;
//   lenLow     - length of lowpass filter;
//   anchorLow  - anchor position of lowpass filter;
//   pTapsHigh  - pointer to highpass filter taps;
//   lenHigh    - length of highpass filter;
//   anchorHigh - anchor position of highpass filter.
//
// Returns:
//   ippStsNoErr       - Ok;
//   ippStsNullPtrErr  - pointer to filter taps are NULL
//                         or pointer to pSpec structure is NULL;
//   ippStsSizeErr     - filter length is less then 2;
//   ippStsAnchorErr   - anchor is less then zero;
//   ippStsMemAllocErr - no memory to allocate context structure.
//
*/
IPPAPI (IppStatus, ippiWTFwdInitAlloc_32f_C1R, (IppiWTFwdSpec_32f_C1R** pSpec,
        const Ipp32f* pTapsLow,  int lenLow,  int anchorLow,
        const Ipp32f* pTapsHigh, int lenHigh, int anchorHigh))

IPPAPI (IppStatus, ippiWTFwdInitAlloc_32f_C3R, (IppiWTFwdSpec_32f_C3R** pSpec,
        const Ipp32f* pTapsLow,  int lenLow,  int anchorLow,
        const Ipp32f* pTapsHigh, int lenHigh, int anchorHigh))


/* //////////////////////////////////////////////////////////////////////
// Name:        ippiWTFwdFree_32f_C1R
//              ippiWTFwdFree_32f_C3R
//
// Purpose:     Free and deallocate
//               forward wavelet transofrm context structure.
//
// Parameters:
//   pSpec  - pointer to context structure.
//
// Returns:
//   ippStsNoErr            - Ok;
//   ippStsNullPtrErr       - Pointer to context structure is NULL;
//   ippStsContextMatchErr  - Mismatch context structure.
//
// Notes:      if pointer to context structure is NULL,
//                      ippStsNullPtrErr will be returned.
*/
IPPAPI (IppStatus, ippiWTFwdFree_32f_C1R, (IppiWTFwdSpec_32f_C1R* pSpec))
IPPAPI (IppStatus, ippiWTFwdFree_32f_C3R, (IppiWTFwdSpec_32f_C3R* pSpec))


/* //////////////////////////////////////////////////////////////////////
// Name:        ippiWTFwdGetBufSize_C1R
//              ippiWTFwdGetBufSize_C3R
//
// Purpose:     Function intended to retrieve size of work buffer.
//
// Parameters:
//   pSpec  - pointer to context structure.
//   size   - pointer to value that will receive the size of work buffer for
//              forward wavelet transform.
//
// Returns:
//   ippStsNoErr            - Ok;
//   ippStsNullPtrErr       - Some of pointers is NULL;
//   ippStsContextMatchErr  - Mismatch context structure.
//
// Notes:      if pointer to context structure is NULL,
//                      ippStsNullPtrErr will be returned.
*/
IPPAPI (IppStatus, ippiWTFwdGetBufSize_C1R,
                   ( const IppiWTFwdSpec_32f_C1R* pSpec, int* size ))

IPPAPI (IppStatus, ippiWTFwdGetBufSize_C3R,
                   ( const IppiWTFwdSpec_32f_C3R* pSpec, int* size ))



/* //////////////////////////////////////////////////////////////////////
// Name:        ippiWTFwd_32f_C1R
//              ippiWTFwd_32f_C3R
//
// Purpose:     Forward wavelet transform.
//
// Parameters:
//   pSrc         - pointer to source image ROI;
//   srcStep      - step in bytes to each next line of source image;
//
//   pApproxDst   - pointer to destination "approximation" image ROI;
//   approxStep   - step in bytes to each next line
//                   of destination approximation image;
//   pDetailXDst  - pointer to destination "horizontal detils" image ROI;
//   detailXStep  - step in bytes to each next line
//                   of destination horizontal detil image;
//   pDetailYDst  - pointer to destination "vertical detils" image ROI;
//   detailYStep  - step in bytes to each next line
//                   of destination "vertical detils" image;
//   pDetailXYDst - pointer to destination "diagonal detils" image ROI;
//   detailXYStep - step in bytes to each next line
//                   of destination "diagonal detils" image;
//   dstRoiSize   - ROI size for all destination images.
//
//   pSpec       - pointer to context structure.
//
// Returns:
//   ippStsNoErr            - Ok;
//   ippStsNullPtrErr       - some of pointers are NULL;
//   ippStsSizeErr          - the width or height of ROI is less or equal zero;
//   ippStsContextMatchErr  - mismatch context structure.
//
// Notes:
//   No any fixed borders extension (wrap, symm.) will be applied!
//   Source image must have valid and accessible border data outside of ROI.
//
//   Only the same ROI sizes for destination images are supported.
//
//   Source ROI size should be calculated by the following rule:
//          srcRoiSize.width  = 2 * dstRoiSize.width;
//          srcRoiSize.height = 2 * dstRoiSize.height.
//
//   Conventional tokens for destination images have next meaning:
//    "Approximation"     - image obtained by vertical
//                              and horizontal lowpass filtering.
//    "Horizontal detail" - image obtained by vertical highpass
//                              and horizontal lowpass filtering.
//    "Vertical detail"   - image obtained by vertical lowpass
//                              and horizontal highpass filtering.
//    "Diagonal detail"   - image obtained by vertical
//                              and horizontal highpass filtering.
//   These tokens are used only for identification convenience in this manual.
//
//
*/
IPPAPI (IppStatus, ippiWTFwd_32f_C1R, (const Ipp32f* pSrc,  int srcStep,
        Ipp32f* pApproxDst,   int approxStep,
        Ipp32f* pDetailXDst,  int detailXStep,
        Ipp32f* pDetailYDst,  int detailYStep,
        Ipp32f* pDetailXYDst, int detailXYStep,
        IppiSize dstRoiSize, const IppiWTFwdSpec_32f_C1R* pSpec,
        Ipp8u* pBuffer))

IPPAPI (IppStatus, ippiWTFwd_32f_C3R, (const Ipp32f* pSrc,  int srcStep,
        Ipp32f* pApproxDst,   int approxStep,
        Ipp32f* pDetailXDst,  int detailXStep,
        Ipp32f* pDetailYDst,  int detailYStep,
        Ipp32f* pDetailXYDst, int detailXYStep,
        IppiSize dstRoiSize, const IppiWTFwdSpec_32f_C3R* pSpec,
        Ipp8u* pBuffer))


/* //////////////////////////////////////////////////////////////////////
// Name:       ippiWTInvInitAlloc_32f_C1R
//             ippiWTInvInitAlloc_32f_C3R
// Purpose:    Allocate and initialize
//                inverse wavelet transform context structure.
// Parameters:
//   pSpec     - pointer to pointer to allocated and initialized
//                 context structure;
//   pTapsLow   - pointer to lowpass filter taps;
//   lenLow     - length of lowpass filter;
//   anchorLow  - anchor position of lowpass filter;
//   pTapsHigh  - pointer to highpass filter taps;
//   lenHigh    - length of highpass filter;
//   anchorHigh - anchor position of highpass filter.
//
// Returns:
//   ippStsNoErr       - Ok;
//   ippStsNullPtrErr  - pointer to filter taps are NULL
//                         or pointer to pSpec structure is NULL;
//   ippStsSizeErr     - filter length is less then 2;
//   ippStsAnchorErr   - anchor is less then zero;
//   ippStsMemAllocErr - no memory to allocate context structure.
//
// Notes:   anchor position value should be given for upsampled data.
//
*/
IPPAPI (IppStatus, ippiWTInvInitAlloc_32f_C1R, (IppiWTInvSpec_32f_C1R** pSpec,
        const Ipp32f* pTapsLow,  int lenLow,  int anchorLow,
        const Ipp32f* pTapsHigh, int lenHigh, int anchorHigh))

IPPAPI (IppStatus, ippiWTInvInitAlloc_32f_C3R, (IppiWTInvSpec_32f_C3R** pSpec,
        const Ipp32f* pTapsLow,  int lenLow,  int anchorLow,
        const Ipp32f* pTapsHigh, int lenHigh, int anchorHigh))


/* //////////////////////////////////////////////////////////////////////
// Name:        ippiWTInvFree_32f_C1R
//              ippiWTInvFree_32f_C3R
//
// Purpose:     Free and deallocate
//                  inverse wavelet transofrm context structure.
//
// Parameters:
//   pSpec  - pointer to context structure.
//
// Returns:
//   ippStsNoErr            - Ok;
//   ippStsNullPtrErr       - Pointer to context structure is NULL;
//   ippStsContextMatchErr  - Mismatch context structure.
//
// Notes:      if pointer to context structure is NULL,
//                      ippStsNullPtrErr will be returned.
*/
IPPAPI (IppStatus, ippiWTInvFree_32f_C1R, (IppiWTInvSpec_32f_C1R* pSpec))
IPPAPI (IppStatus, ippiWTInvFree_32f_C3R, (IppiWTInvSpec_32f_C3R* pSpec))


/* //////////////////////////////////////////////////////////////////////
// Name:        ippiWTInvGetBufSize_C1R
//              ippiWTInvGetBufSize_C3R
//
// Purpose:     Function intended to retrieve size of work buffer for
//                  inverse wavelet transform.
//
// Parameters:
//   pSpec  - pointer to context structure.
//   size   - pointer to value that will receive the size of work buffer.
//
// Returns:
//   ippStsNoErr            - Ok;
//   ippStsNullPtrErr       - Some of pointers is NULL;
//   ippStsContextMatchErr  - Mismatch context structure.
//
// Notes:      if pointer to context structure is NULL,
//                      ippStsNullPtrErr will be returned.
*/
IPPAPI (IppStatus, ippiWTInvGetBufSize_C1R,
                   ( const IppiWTInvSpec_32f_C1R* pSpec, int* size ))

IPPAPI (IppStatus, ippiWTInvGetBufSize_C3R,
                   ( const IppiWTInvSpec_32f_C3R* pSpec, int* size ))


/* //////////////////////////////////////////////////////////////////////
// Name:        ippiWTInv_32f_C1R
//              ippiWTInv_32f_C3R
//
// Purpose:     Inverse wavelet transform.
//
// Parameters:
//   pApproxSrc   - pointer to source "approximation" image ROI;
//   approxStep   - step in bytes to each next line
//                   of source approximation image;
//   pDetailXSrc  - pointer to source "horizontal detils" image ROI;
//   detailXStep  - step in bytes to each next line
//                   of source horizontal detil image;
//   pDetailYSrc  - pointer to source "vertical detils" image ROI;
//   detailYStep  - step in bytes to each next line
//                   of source "vertical detils" image;
//   pDetailXYSrc - pointer to source "diagonal detils" image ROI;
//   detailXYStep - step in bytes to each next line
//                   of source "diagonal detils" image;
//   srcRoiSize   - ROI size for all source images.
//
//   pDst         - pointer to destination image ROI;
//   dstStep      - step in bytes to each next line of destination image;
//
//   pSpec        - pointer to context structure.
//
// Returns:
//   ippStsNoErr            - Ok;
//   ippStsNullPtrErr       - some of pointers are NULL;
//   ippStsSizeErr          - the width or height of ROI is less or equal zero;
//   ippStsContextMatchErr  - mismatch context structure.
//
// Notes:
//   No any fixed borders extension (wrap, symm.) will be applayed! Source
//    images must have valid and accessable border data outside of ROI.
//
//   Only the same ROI size for source images supported. Destination ROI size
//     should be calculated by next rule:
//          dstRoiSize.width  = 2 * srcRoiSize.width;
//          dstRoiSize.height = 2 * srcRoiSize.height.
//
//
//   Monikers for source images act in concert with decomposition destination.
//
//
*/
IPPAPI (IppStatus, ippiWTInv_32f_C1R, (
        const Ipp32f* pApproxSrc,   int approxStep,
        const Ipp32f* pDetailXSrc,  int detailXStep,
        const Ipp32f* pDetailYSrc,  int detailYStep,
        const Ipp32f* pDetailXYSrc, int detailXYStep,
        IppiSize srcRoiSize, Ipp32f* pDst,  int dstStep,
        const IppiWTInvSpec_32f_C1R* pSpec, Ipp8u* pBuffer))

IPPAPI (IppStatus, ippiWTInv_32f_C3R, (
        const Ipp32f* pApproxSrc,   int approxStep,
        const Ipp32f* pDetailXSrc,  int detailXStep,
        const Ipp32f* pDetailYSrc,  int detailYStep,
        const Ipp32f* pDetailXYSrc, int detailXYStep,
        IppiSize srcRoiSize, Ipp32f* pDst,  int dstStep,
        const IppiWTInvSpec_32f_C3R* pSpec, Ipp8u* pBuffer))





/* /////////////////////////////////////////////////////////////////////////////
//                   Color space  conversion functions
///////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////
//  Name: ippiRGBToYCbCr422_8u_C3C2R,ippiYCbCr422ToRGB_8u_C2C3R.
//        ippiRGBToYCbCr422_8u_P3C2R,ippiYCbCr422ToRGB_8u_C2P3R.
//        ippiYCbCr422ToRGB_8u_P3C3R,ippiCbYCr422ToRGB_8u_C2C3R
//        ippiRGBToCbYCr422Gamma_8u_C3C2R,ippiRGBToCbYCr422_8u_C3C2R
//  Purpose:    Convert RGB Image to and from YCbCr Image.
//  Arguments:
//     pSrc - Pointer to the source image (for pixel-order data).An array of pointers
//            to separate source color planes (in case of plane-order data)
//     pDst - Pointer to the resultant image (for pixel-order data).An array of pointers
//            to separate source color planes (in case of plane-order data)
//     roiSize - region of interest in pixels.
//     srcStep - step in bytes through source image to jump on the next line
//     dstStep - step in bytes through destination image to jump on the next line
//  Returns:
//           ippStsNullPtrErr  if src == NULL or dst == NULL
//           ippStsStepErr,    if srcStep or dstStep is less or equal zero
//           ippStsSizeErr     if imgSize.width <= 0 || imgSize.height <= 0
//           ippStsNoErr       else
//  Reference:
//      Jack Keith
//      Video Demystified: a handbook for the digital engineer, 2nd ed.
//      1996.pp.(42-43)
//
//  The YCbCr color space was developed as part of Recommendation ITU-R BT.601
//  (formely CCI 601). Y is defined to have a nominal range of 16 to 235;
//  Cb and Cr are defined to have a range of 16 to 240, with 128 equal to zero.
//  The function ippiRGBToYCbCr422_8u_P3C2R uses 4:2:2 sampling format.For every
//  two  horisontal Y samples, there is one Cb and Cr sample.
//  Each pixel in the input RGB image is of 24 bit depth. Each pixel in the
//  output YCbCr image is of 16 bit depth. Sequence of bytes in the output
//  image is
//             Y0Cb0Y1Cr,Y2Cb1Y3Cr1,...
//  And for CbYCr image we have
//             Cb0Y0CrY1,Cb1Y2Cr1Y3,...
//  If the gamma-corrected RGB(R'G'B') image has a range 0 .. 255, as is commonly
//  found in computer system (and in our library), the following equations may be
//  used:
//
//       Y  =  0.257*R' + 0.504*G' + 0.098*B' + 16
//       Cb = -0.148*R' - 0.291*G' + 0.439*B' + 128
//       Cr =  0.439*R' - 0.368*G' - 0.071*B' + 128
//
//       R' = 1.164*(Y - 16) + 1.596*(Cr - 128 )
//       G' = 1.164*(Y - 16) - 0.813*(Cr - 128 )- 0.392*( Cb - 128 )
//       B' = 1.164*(Y - 16) + 2.017*(Cb - 128 )
//
//   Note that for the YCbCr-to-RGB equations, the RGB values must be saturated
//   at the 0 and 255 levels due to occasional excursions outside the nominal
//   YCbCr ranges.
//   For f.ippiRGBToCbYCr422Gamma_8u_C3C2R and ippiRGBToCbYCr422Gamma_8u_C3C2R there is
//   sample down filter(1/4,1/2,1/4).
*/
IPPAPI(IppStatus, ippiYCbCr411ToBGR_8u_P3C3R,(const Ipp8u* pSrc[3],int srcStep[3],Ipp8u* pDst,
       int dstStep, IppiSize roiSize))

IPPAPI(IppStatus, ippiCbYCr422ToRGB_8u_C2C3R,(const Ipp8u* pSrc,int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize))

IPPAPI(IppStatus, ippiRGBToCbYCr422Gamma_8u_C3C2R,(const Ipp8u* pSrc, int srcStep ,
       Ipp8u* pDst, int dstStep, IppiSize roiSize))

IPPAPI(IppStatus, ippiRGBToCbYCr422_8u_C3C2R,(const Ipp8u* pSrc, int srcStep ,
       Ipp8u* pDst, int dstStep, IppiSize roiSize))

IPPAPI(IppStatus, ippiYCbCr422ToRGB_8u_P3C3R,(const Ipp8u* const pSrc[3],int srcStep[3],
       Ipp8u* pDst,int dstStep, IppiSize roiSize))

IPPAPI(IppStatus, ippiRGBToYCbCr422_8u_C3C2R,(const Ipp8u* pSrc, int srcStep ,
       Ipp8u* pDst, int dstStep,IppiSize roiSize))
IPPAPI(IppStatus, ippiYCbCr422ToRGB_8u_C2C3R,(const Ipp8u* pSrc, int srcStep ,
       Ipp8u* pDst, int dstStep,IppiSize roiSize))

IPPAPI(IppStatus, ippiRGBToYCbCr422_8u_P3C2R,(const Ipp8u* const pSrc[3], int srcStep ,
       Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiYCbCr422ToRGB_8u_C2P3R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst[3], int dstStep,IppiSize roiSize))

IPPAPI(IppStatus, ippiYCbCr420ToBGR_8u_P3C3R,(const Ipp8u* const pSrc[3],int srcStep[3],
       Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiYCbCr420ToRGB_8u_P3C3R,(const Ipp8u* const pSrc[3],int srcStep[3],
       Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRGBToYCbCr420_8u_C3P3R,(const Ipp8u* pSrc, int srcStep ,
       Ipp8u* pDst[3],int dstStep[3], IppiSize roiSize))

IPPAPI(IppStatus, ippiYCbCr422ToRGB565_8u16u_C2C3R,(const Ipp8u* pSrc, int srcStep,
       Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiYCbCr422ToBGR565_8u16u_C2C3R,(const Ipp8u* pSrc, int srcStep,
       Ipp16u* pDst, int dstStep, IppiSize roiSize))

IPPAPI(IppStatus, ippiYCbCr422ToRGB555_8u16u_C2C3R,(const Ipp8u* pSrc, int srcStep,
       Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiYCbCr422ToBGR555_8u16u_C2C3R,(const Ipp8u* pSrc, int srcStep,
       Ipp16u* pDst, int dstStep, IppiSize roiSize))

IPPAPI(IppStatus, ippiYCbCr422ToRGB444_8u16u_C2C3R,(const Ipp8u* pSrc, int srcStep,
       Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiYCbCr422ToBGR444_8u16u_C2C3R,(const Ipp8u* pSrc, int srcStep,
       Ipp16u* pDst, int dstStep, IppiSize roiSize))

/* ////////////////////////////////////////////////////////////////////////////
//  Name:       ippiJoin422_8u_P3C2R, ippiSplit422_8u_C2P3R
//
//  Purpose:    Convert form 422 plane image format to 2-channal pixel
//              image format and vice versa.
//
//  Return:
//    ippStsNoErr              Ok
//    ippStsNullPtrErr         One or more pointers are NULL
//    ippStsStepErr            One or more steps is less or equal zero
//    ippStsSizeErr            Width of first plain 422-image less then 2(4)
//                             or height equal zero
//    ippStsStrideErr          Step is less then width of image
//
//  Arguments:
//    pSrc[3]                  It is three pointers to source images
//    srcStep[3]               It is three steps for previous three images
//    pDst[3]                  It is three pointers to destination images
//    dstStep[3]               It is three steps for previous three images
//    pSrc                     The pointer to source image
//    srcStep                  The step for source image
//    pDst                     The pointer to destination image
//    dstStep                  The step for destination image
//    roiSize                  Size of ROI
*/
IPPAPI (IppStatus, ippiJoin422_8u_P3C2R,  ( const Ipp8u* pSrc[3], int srcStep[3], Ipp8u* pDst, int dstStep, IppiSize  roiSize))
IPPAPI (IppStatus, ippiSplit422_8u_C2P3R, ( const Ipp8u* pSrc, int srcStep, Ipp8u* pDst[3], int dstStep[3], IppiSize  roiSize))


/* /////////////////////////////////////////////////////////////////////////////
//  Name: ippiRGBToYCbCr_8u_C3R, ippiYCbCrToRGB_8u_C3R.
//        ippiRGBToYCbCr_8u_AC4R,ippiYCbCrToRGB_8u_AC4R.
//        ippiRGBToYCbCr_8u_P3R, ippiYCbCrToRGB_8u_P3R.
//        ippiYCbCrToRGB_8u_P3C3R
//  Purpose:    Convert RGB Image to and from YCbCr Image.
//  Arguments:
//     pSrc - Pointer to the source image (for pixel-order data).An array of pointers
//            to separate source color planes (in case of plane-order data)
//     pDst - Pointer to the resultant image (for pixel-order data).An array of pointers
//            to separate source color planes (in case of plane-order data)
//     roiSize - region of interest in pixels.
//     srcStep - step in bytes through source image to jump on the next line
//     dstStep - step in bytes through destination image to jump on the next line
//  Returns:
//           ippStsNullPtrErr  if src == NULL or dst == NULL
//           ippStsStepErr,    if srcStep or dstStep is less or equal zero
//           ippStsSizeErr     if imgSize.width <= 0 || imgSize.height <= 0
//           ippStsNoErr       else
//  Reference:
//      Jack Keith
//      Video Demystified:a handbook for the digital engineer, 2nd ed.
//      1996.pp.(42-43)
//
//  The YCbCr color space was developed as part of Recommendation ITU-R BT.601
//  (formely CCI 601). Y is defined to have a nominal range of 16 to 235;
//  Cb and Cr are defined to have a range of 16 to 240, with 128 equal to zero.
//  If the gamma-corrected RGB(R'G'B') image has a range 0 .. 255, as is commonly
//  found in computer system (and in our library), the following equations may be
//  used:
//
//       Y  =  0.257*R' + 0.504*G' + 0.098*B' + 16
//       Cb = -0.148*R' - 0.291*G' + 0.439*B' + 128
//       Cr =  0.439*R' - 0.368*G' - 0.071*B' + 128
//
//       R' = 1.164*(Y - 16) + 1.596*(Cr - 128 )
//       G' = 1.164*(Y - 16) - 0.813*(Cr - 128 )- 0.392*( Cb - 128 )
//       B' = 1.164*(Y - 16) + 2.017*(Cb - 128 )
//
//   Note that for the YCbCr-to-RGB equations, the RGB values must be saturated
//   at the 0 and 255 levels due to occasional excursions outside the nominal
//   YCbCr ranges.
//
*/
IPPAPI(IppStatus, ippiRGBToYCbCr_8u_C3R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRGBToYCbCr_8u_AC4R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRGBToYCbCr_8u_P3R,(const Ipp8u* const pSrc[3], int srcStep,
       Ipp8u* pDst[3], int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiYCbCrToRGB_8u_P3C3R,(const Ipp8u* const pSrc[3],int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiYCbCrToRGB_8u_C3R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiYCbCrToRGB_8u_AC4R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiYCbCrToRGB_8u_P3R,(const Ipp8u* const pSrc[3],int srcStep,
       Ipp8u* pDst[3], int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiYCbCrToBGR444_8u16u_C3R,(const Ipp8u* pSrc, int srcStep,
       Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiYCbCrToRGB444_8u16u_C3R,(const Ipp8u* pSrc, int srcStep,
       Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiYCbCrToBGR555_8u16u_C3R,(const Ipp8u* pSrc, int srcStep,
       Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiYCbCrToRGB555_8u16u_C3R,(const Ipp8u* pSrc, int srcStep,
       Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiYCbCrToBGR565_8u16u_C3R,(const Ipp8u* pSrc, int srcStep,
       Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiYCbCrToRGB565_8u16u_C3R,(const Ipp8u* pSrc, int srcStep,
       Ipp16u* pDst, int dstStep, IppiSize roiSize))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippiRGBToYUV_8u_C3R,  ippiYUVToRGB_8u_C3R.
//              ippiRGBToYUV_8u_AC4R, ippiYUVToRGB_8u_AC4R.
//              ippiRGBToYUV_8u_P3R,  ippiYUVToRGB_8u_P3R.
//              ippiRGBToYUV_8u_C3P3R,ippiYUVToRGB_8u_P3C3R.
//  Purpose:    Convert a RGB image to and from an YUV format image.
//  Arguments:
//     pSrc - Pointer to the source image (for pixel-order data).An array of pointers
//            to separate source color planes (in case of plane-order data)
//     pDst - Pointer to the resultant image (for pixel-order data).An array of pointers
//            to separate source color planes (in case of plane-order data)
//     roiSize - region of interest in pixels.
//     srcStep - step in bytes through source image to jump on the next line
//     dstStep - step in bytes through destination image to jump on the next line
//  Returns:
//           ippStsNullPtrErr  if src == NULL or dst == NULL
//           ippStsStepErr,    if srcStep or dstStep is less or equal zero
//           ippStsSizeErr     if imgSize.width <= 0 || imgSize.height <= 0
//           ippStsNoErr       else
//  Reference:
//      Jack Keith
//      Video Demystified: a handbook for the digital engineer, 2nd ed.
//      1996.pp.(40-41)
//
//     The YUV color space is the basic color space used by the PAL , NTSC , and
//  SECAM composite color video standarts.
//
//  The basic equations to convert between gamma-corrected RGB(R'G'B')and YUV are:
//
//       Y' =  0.299*R' + 0.587*G' + 0.114*B'
//       U  = -0.147*R' - 0.289*G' + 0.436*B' = 0.492*(B' - Y' )
//       V  =  0.615*R' - 0.515*G' - 0.100*B' = 0.877*(R' - Y' )
//
//       R' = Y' + 1.140 * V
//       G' = Y' - 0.394 * U - 0.581 * V
//       B' = Y' + 2.032 * U
//
//     For digital RGB values with the range [0 .. 255], Y has the range [0..255],
//   U the range [-112 .. +112],V the range [-157..+157].
//
//   These equations are usually scaled to simplify the implementation in an actual
//   NTSC or PAL digital encoder or decoder.
//
*/
/* Pixel to Pixel */
IPPAPI(IppStatus, ippiRGBToYUV_8u_C3R,(const Ipp8u* pSrc, int srcStep ,
       Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiYUVToRGB_8u_C3R,(const Ipp8u* pSrc, int srcStep ,
       Ipp8u* pDst, int dstStep, IppiSize roiSize))
/* Pixel to Pixel */
IPPAPI(IppStatus, ippiRGBToYUV_8u_AC4R,(const Ipp8u* pSrc, int srcStep ,
       Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiYUVToRGB_8u_AC4R,(const Ipp8u* pSrc, int srcStep ,
       Ipp8u* pDst, int dstStep, IppiSize roiSize))
/* Plane to Plane */
IPPAPI(IppStatus, ippiRGBToYUV_8u_P3R,(const Ipp8u* const pSrc[3], int srcStep ,
       Ipp8u* pDst[3], int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiYUVToRGB_8u_P3R,(const Ipp8u* const pSrc[3], int srcStep,
       Ipp8u* pDst[3], int dstStep, IppiSize roiSize))
/* Pixel to Plane */
IPPAPI(IppStatus, ippiRGBToYUV_8u_C3P3R,( const Ipp8u* pSrc, int srcStep ,
       Ipp8u* pDst[3], int dstStep, IppiSize roiSize))
/* Plane to Pixel */
IPPAPI(IppStatus, ippiYUVToRGB_8u_P3C3R,(const Ipp8u* const pSrc[3], int srcStep,
       Ipp8u* pDst,int dstStep, IppiSize roiSize))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippiRGBToYUV422_8u_C3P3R, ippiYUV422ToRGB_8u_P3C3R.
//              ippiRGBToYUV422_8u_P3R,   ippiYUV422ToRGB_8u_P3R.
//              ippiRGBToYUV420_8u_C3P3R, ippiYUV420ToRGB_8u_P3C3R.
//              ippiRGBToYUV422_8u_C3C2R,   ippiYUV422ToRGB_8u_C2C3R.
//  Purpose:    Convert a RGB image to and from an YUV format image.
//  Arguments:
//     pSrc - Pointer to the source image (for pixel-order data).An array of pointers
//            to separate source color planes (in case of plane-order data)
//     pDst - Pointer to the resultant image (for pixel-order data).An array of pointers
//            to separate source color planes (in case of plane-order data)
//     roiSize - region of interest in pixels.
//     srcStep - step in bytes through source image to jump on the next line(for pixel-order data).
//               An array of step to separate source color planes (in case of plane-order data).
//     dstStep - step in bytes through destination image to jump on the next line(for pixel-order data).
//               An array of step to separate resultant color planes (in case of plane-order data).
//  Returns:
//           ippStsNullPtrErr  if src == NULL or dst == NULL
//           ippStsStepErr,    if srcStep or dstStep is less or equal zero
//           ippStsSizeErr     if imgSize.width <= 0 || imgSize.height <= 0
//           ippStsNoErr       else
//  Reference:
//      Jack Keith
//      Video Demystified: a handbook for the digital engineer, 2nd ed.
//      1996.pp.(40-41)
//
//     The YUV color space is the basic color space used by the PAL , NTSC , and
//  SECAM composite color video standarts.
//
//  The function ippiRGBToYUV422_ uses 4:2:2 sampling format.For every
//  two  horisontal Y samples, there is one U and V sample.
//
//  The function ippiRGBToYUV420_ uses 4:2:0 sampling format. 4:2:0 implements
//  2:1 reduction of U and V in both the vertical and horizontal directions.
//
//  The basic equations to convert between gamma-corrected RGB(R'G'B')and YUV are:
//
//       Y' =  0.299*R' + 0.587*G' + 0.114*B'
//       U  = -0.147*R' - 0.289*G' + 0.436*B' = 0.492*(B' - Y' )
//       V  =  0.615*R' - 0.515*G' - 0.100*B' = 0.877*(R' - Y' )
//
//       R' = Y' + 1.140 * V
//       G' = Y' - 0.394 * U - 0.581 * V
//       B' = Y' + 2.032 * U
//
//     For digital RGB values with the range [0 .. 255], Y has the range [0..255],
//   U the range [-112 .. +112],V the range [-157..+157].
//
//   These equations are usually scaled to simplify the implementation in an actual
//   NTSC or PAL digital encoder or decoder.
//
*/
IPPAPI(IppStatus, ippiYUV420ToRGB_8u_P3AC4R,(const Ipp8u* const pSrc[3],int srcStep[3],Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiYUV422ToRGB_8u_P3AC4R,(const Ipp8u* const pSrc[3],int srcStep[3],Ipp8u* pDst, int dstStep, IppiSize roiSize))
/* Pixel to Plane */
IPPAPI(IppStatus, ippiRGBToYUV422_8u_C3P3R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst[3],int dstStep[3], IppiSize roiSize))
/* Plane to Pixel */
IPPAPI(IppStatus, ippiYUV422ToRGB_8u_P3C3R,(const Ipp8u* const pSrc[3],int srcStep[3],
       Ipp8u* pDst,int dstStep, IppiSize roiSize))
/* Plane to Plane */
IPPAPI(IppStatus, ippiRGBToYUV422_8u_P3R,(const Ipp8u*  const pSrc[3], int srcStep ,
       Ipp8u* pDst[3], int dstStep[3],IppiSize roiSize))
/* Plane to Plane */
IPPAPI(IppStatus, ippiYUV422ToRGB_8u_P3R,(const Ipp8u* const pSrc[3],
       int srcStep[3],Ipp8u* pDst[3], int dstStep, IppiSize roiSize))
/* Pixel to Plane */
IPPAPI(IppStatus, ippiRGBToYUV420_8u_C3P3R,(const Ipp8u* pSrc, int srcStep ,
       Ipp8u* pDst[3], int dstStep[3], IppiSize roiSize))
/* Plane to Pixel */
IPPAPI(IppStatus, ippiYUV420ToRGB_8u_P3C3R,(const Ipp8u* const pSrc[3],int srcStep[3],
       Ipp8u* pDst, int dstStep, IppiSize roiSize))
/* Plane to Plane */
IPPAPI(IppStatus, ippiRGBToYUV420_8u_P3R,(const Ipp8u* const pSrc[3], int srcStep ,
       Ipp8u* pDst[3], int dstStep[3], IppiSize roiSize))
/* Plane to Plane */
IPPAPI(IppStatus, ippiYUV420ToRGB_8u_P3R,(const Ipp8u* const pSrc[3],int srcStep[3],
       Ipp8u* pDst[3], int dstStep, IppiSize roiSize))
/* Pixel to Pixel */
IPPAPI(IppStatus, ippiRGBToYUV422_8u_C3C2R,(const Ipp8u* pSrc, int srcStep ,
       Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiYUV422ToRGB_8u_C2C3R,(const Ipp8u* pSrc,int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiYUV420ToBGR565_8u16u_P3C3R,(const Ipp8u* const pSrc[3], int srcStep[3], Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiYUV420ToBGR555_8u16u_P3C3R,(const Ipp8u* const pSrc[3], int srcStep[3], Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiYUV420ToBGR444_8u16u_P3C3R,(const Ipp8u* const pSrc[3], int srcStep[3], Ipp16u* pDst, int dstStep, IppiSize roiSize))

IPPAPI(IppStatus, ippiYUV420ToRGB565_8u16u_P3C3R,(const Ipp8u* const pSrc[3], int srcStep[3], Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiYUV420ToRGB555_8u16u_P3C3R,(const Ipp8u* const pSrc[3], int srcStep[3], Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiYUV420ToRGB444_8u16u_P3C3R,(const Ipp8u* const pSrc[3], int srcStep[3], Ipp16u* pDst, int dstStep, IppiSize roiSize))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippiRGBToYUV422_8u_P3,   ippiYUV422ToRGB_8u_P3.
//              ippiRGBToYUV422_8u_C3P3, ippiYUV422ToRGB_8u_P3C3.
//              ippiRGBToYUV420_8u_C3P3, ippiYUV420ToRGB_8u_P3C3.
//              ippiRGBToYUV420_8u_P3,   ippiYUV420ToRGB_8u_P3.
//  Purpose:    Convert a RGB image to and from an YUV format image.
//  Arguments:
//     pSrc - Pointer to the source image (for pixel-order data).An array of pointers
//            to separate source color planes (in case of plane-order data)
//     pDst - Pointer to the resultant image (for pixel-order data).An array of pointers
//            to separate source color planes (in case of plane-order data)
//     imgSize - size of the source and destination images in pixels
//  Returns:
//           ippStsNullPtrErr  if src == NULL or dst == NULL
//           ippStsStepErr,    if srcStep or dstStep is less or equal zero
//           ippStsSizeErr     if imgSize.width <= 0 || imgSize.height <= 0
//           ippStsNoErr       else
//  Reference:
//      Jack Keith
//      Video Demystified: a handbook for the digital engineer, 2nd ed.
//      1996.pp.(40-41)
//
//     The YUV color space is the basic color space used by the PAL , NTSC , and
//  SECAM composite color video standarts.
//
//  The function ippiRGBToYUV422_ uses 4:2:2 sampling format.For every
//  two  horisontal Y samples, there is one U and V sample.
//
//  The function ippiRGBToYUV420_ uses 4:2:0 sampling format. 4:2:0 implements
//  2:1 reduction of U and V in both the vertical and horizontal directions.
//
//  The basic equations to convert between gamma-corrected RGB(R'G'B')and YUV are:
//
//       Y' =  0.299*R' + 0.587*G' + 0.114*B'
//       U  = -0.147*R' - 0.289*G' + 0.436*B' = 0.492*(B' - Y' )
//       V  =  0.615*R' - 0.515*G' - 0.100*B' = 0.877*(R' - Y' )
//
//       R' = Y' + 1.140 * V
//       G' = Y' - 0.394 * U - 0.581 * V
//       B' = Y' + 2.032 * U
//
//   For digital RGB values with the range [0 .. 255], Y has the range [0..255],
//   U the range [-112 .. +112],V the range [-157..+157].
//
//   These equations are usually scaled to simplify the implementation in an actual
//   NTSC or PAL digital encoder or decoder.
//
*/
/* Plane to Plane */
IPPAPI(IppStatus, ippiRGBToYUV422_8u_P3,(const Ipp8u* const pSrc[3], Ipp8u* pDst[3], IppiSize imgSize))
IPPAPI(IppStatus, ippiYUV422ToRGB_8u_P3,(const Ipp8u* const pSrc[3], Ipp8u* pDst[3], IppiSize imgSize))
/* Pixel to Plane */
IPPAPI(IppStatus, ippiRGBToYUV422_8u_C3P3,(const Ipp8u* pSrc, Ipp8u* pDst[3], IppiSize imgSize))
/* Plane to Pixel */
IPPAPI(IppStatus, ippiYUV422ToRGB_8u_P3C3,(const Ipp8u* const pSrc[3],Ipp8u* pDst, IppiSize imgSize ))
/* Pixel to Plane */
IPPAPI(IppStatus, ippiRGBToYUV420_8u_C3P3,(const Ipp8u* pSrc, Ipp8u* pDst[3], IppiSize imgSize))
/* Plane to Pixel */
IPPAPI(IppStatus, ippiYUV420ToRGB_8u_P3C3,(const Ipp8u* const pSrc[3], Ipp8u* pDst, IppiSize imgSize))
/* Plane to Plane */
IPPAPI(IppStatus, ippiRGBToYUV420_8u_P3,(const Ipp8u* const pSrc[3], Ipp8u* pDst[3], IppiSize imgSize))
IPPAPI(IppStatus, ippiYUV420ToRGB_8u_P3,(const Ipp8u* const pSrc[3], Ipp8u* pDst[3], IppiSize imgSize))



/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippiRGBToGray
//  Purpose:    Convert a RGB image to the gray image
//  Arguments:
//     pSrc     - the source image , points to point(0,0)
//     pDst     - the resultant image , points to point(0,0)
//     roiSize - region of interest in pixels. Because the function does a point
//          operation (that's without a border) the parameter can be the size of
//          the images
//     srcStep - step in bytes through source image to jump on the next line
//     dstStep - step in bytes through destination image to jump on the next line
//  Returns:
//           ippStsNullPtrErr  if src == NULL or dst == NULL
//           ippStsSizeErr     if imgSize.width <= 0 || imgSize.height <= 0
//           ippStsNullPtrErr       else
//  Reference:
//      Jack Keith
//      Video Demystified: a handbook for the digital engineer, 2nd ed.
//      1996.p.(82)
//
//  The coefficients of equation below correspond to the "NTSC" red, green and blue CRT
//  phosphors of 1953 are standardized in ITU-R Recommendation BT. 601-2
//  (formerly CCIR Rec. 601-2).
//
//   The basic equation to compute nonlinear video  luma(monochrome) from nonlinear
//  (gamma-corrected) RGB(R'G'B') is:
//
//  Y' = 0.299 * R' + 0.587 * G' + 0.114 * B';
//
//
*/
IPPAPI(IppStatus,ippiRGBToGray_8u_C3C1R,(const Ipp8u* pSrc,int srcStep,Ipp8u* pDst,int dstStep,IppiSize roiSize))
IPPAPI(IppStatus,ippiRGBToGray_16u_C3C1R,(const Ipp16u* pSrc,int srcStep,Ipp16u* pDst,int dstStep,IppiSize roiSize))
IPPAPI(IppStatus,ippiRGBToGray_16s_C3C1R,(const Ipp16s* pSrc,int srcStep,Ipp16s* pDst,int dstStep,IppiSize roiSize))
IPPAPI(IppStatus,ippiRGBToGray_32f_C3C1R,(const Ipp32f* pSrc,int srcStep,Ipp32f* pDst,int dstStep,IppiSize roiSize))
IPPAPI(IppStatus,ippiRGBToGray_8u_AC4C1R,(const Ipp8u* pSrc,int srcStep,Ipp8u* pDst,int dstStep,IppiSize roiSize))
IPPAPI(IppStatus,ippiRGBToGray_16u_AC4C1R,(const Ipp16u* pSrc,int srcStep,Ipp16u* pDst,int dstStep,IppiSize roiSize))
IPPAPI(IppStatus,ippiRGBToGray_16s_AC4C1R,(const Ipp16s* pSrc,int srcStep,Ipp16s* pDst,int dstStep,IppiSize roiSize))
IPPAPI(IppStatus,ippiRGBToGray_32f_AC4C1R,(const Ipp32f* pSrc,int srcStep,Ipp32f* pDst,int dstStep,IppiSize roiSize))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippiColorToGray
//  Purpose:    Convert a RGB image to the gray image
//  Arguments:
//     pSrc     - the source image , points to point(0,0)
//     pDst     - the resultant image , points to point(0,0)
//     roiSize - region of interest in pixels. Because the function does a point
//          operation (that's without a border) the parameter can be the size of
//          the images
//     srcStep - step in bytes through source image to jump on the next line
//     dstStep - step in bytes through destination image to jump on the next line
//     coeffs[3] - the user  defined  vector of coefficients.
//                 The sum of coefficients should be less or is equal to unit.
//  Returns:
//           ippStsNullPtrErr  if src == NULL or dst == NULL
//           ippStsSizeErr     if imgSize.width <= 0 || imgSize.height <= 0
//           ippStsNullPtrErr       else
//
//  The basic equation to convert an image from RGB color to gray ckale is:
//
//   Y = coeffs[0] * R + coeffs[1] * G + coeffs[2] * B;
//
//
*/
IPPAPI(IppStatus,ippiColorToGray_8u_C3C1R,(const Ipp8u* pSrc,int srcStep,Ipp8u* pDst,int dstStep,IppiSize roiSize,const Ipp32f coeffs[3]))
IPPAPI(IppStatus,ippiColorToGray_16u_C3C1R,(const Ipp16u* pSrc,int srcStep,Ipp16u* pDst,int dstStep,IppiSize roiSize,const Ipp32f coeffs[3]))
IPPAPI(IppStatus,ippiColorToGray_16s_C3C1R,(const Ipp16s* pSrc,int srcStep,Ipp16s* pDst,int dstStep,IppiSize roiSize,const Ipp32f coeffs[3]))
IPPAPI(IppStatus,ippiColorToGray_32f_C3C1R,(const Ipp32f* pSrc,int srcStep,Ipp32f* pDst,int dstStep,IppiSize roiSize,const Ipp32f coeffs[3]))

IPPAPI(IppStatus,ippiColorToGray_8u_AC4C1R,(const Ipp8u* pSrc,int srcStep,Ipp8u* pDst,int dstStep,IppiSize roiSize,const Ipp32f coeffs[3]))
IPPAPI(IppStatus,ippiColorToGray_16u_AC4C1R,(const Ipp16u* pSrc,int srcStep,Ipp16u* pDst,int dstStep,IppiSize roiSize,const Ipp32f coeffs[3]))
IPPAPI(IppStatus,ippiColorToGray_16s_AC4C1R,(const Ipp16s* pSrc,int srcStep,Ipp16s* pDst,int dstStep,IppiSize roiSize,const Ipp32f coeffs[3]))
IPPAPI(IppStatus,ippiColorToGray_32f_AC4C1R,(const Ipp32f* pSrc,int srcStep,Ipp32f* pDst,int dstStep,IppiSize roiSize,const Ipp32f coeffs[3]))


/* ////////////////////////////////////////////////////////////////////////////
//  Name: ippiRGBToHLS and ippiHLSToRGB
//  Purpose:    Convert an image from RGB to HLS format and vice versa
//  Arguments:
//     pSrc - Pointer to the source image .
//     pDst - Pointer to the resultant image .
//     roiSize - region of interest in pixels.
//     srcStep - step in bytes through source image to jump on the next line
//     dstStep - step in bytes through destination image to jump on the next line
//  Returns:
//           ippStsNullPtrErr  if src == NULL or dst == NULL
//           ippStsStepErr,    if srcStep or dstStep is less or equal zero
//           ippStsSizeErr     if imgSize.width <= 0 || imgSize.height <= 0
//           ippStsNoErr       else
//  RGB and HLS values for the 32f data type should be in the range [0..1]
//  Reference:
//      David F.Rogers
//      Procedural elements for computer graphics
//      1985.pp.(403-406)
//
//       H is the hue red at 0 degrees, which has range [0 .. 360 degrees],
//       L is the lightness,
//       S is the saturation,
//
//       The RGB to HLS conversion algorithm in pseudocode:
//   Lightness:
//      M1 = max(R,G,B); M2 = max(R,G,B); L = (M1+M2)/2
//   Saturation:
//      if M1 = M2 then // achromatics case
//          S = 0
//          H = 0
//      else // chromatics case
//          if L <= 0.5 then
//               S = (M1-M2) / (M1+M2)
//          else
//               S = (M1-M2) / (2-M1-M2)
//   Hue:
//      Cr = (M1-R) / (M1-M2)
//      Cg = (M1-G) / (M1-M2)
//      Cb = (M1-B) / (M1-M2)
//      if R = M2 then H = Cb - Cg
//      if G = M2 then H = 2 + Cr - Cb
//      if B = M2 then H = 4 + Cg - Cr
//      H = 60*H
//      if H < 0 then H = H + 360
//
//      The HSL to RGB conversion algorithm in pseudocode:
//      if L <= 0.5 then
//           M2 = L *(1 + S)
//      else
//           M2 = L + S - L * S
//      M1 = 2 * L - M2
//      if S = 0 then
//         R = G = B = L
//      else
//          h = H + 120
//          if h > 360 then
//              h = h - 360
//          if h  <  60 then
//              R = ( M1 + ( M2 - M1 ) * h / 60)
//          else if h < 180 then
//              R = M2
//          else if h < 240 then
//              R = M1 + ( M2 - M1 ) * ( 240 - h ) / 60
//          else
//              R = M1
//          h = H
//          if h  <  60 then
//              G = ( M1 + ( M2 - M1 ) * h / 60
//          else if h < 180 then
//              G = M2
//          else if h < 240 then
//              G = M1 + ( M2 - M1 ) * ( 240 - h ) / 60
//          else
//              G  = M1
//          h = H - 120
//          if h < 0 then
//              h += 360
//          if h  <  60 then
//              B = ( M1 + ( M2 - M1 ) * h / 60
//          else if h < 180 then
//              B = M2
//          else if h < 240 then
//              B = M1 + ( M2 - M1 ) * ( 240 - h ) / 60
//          else
//              B = M1
//
//     H,L,S,R,G,B - are scaled in the range [0..1] for the 32f depth,
//           in the range [0..IPP_MAX_8u] for the 8u depth,
//           in the range [0..IPP_MAX_16u] for the 16u depth,
//           in the range [IPP_MIN_16S..IPP_MAX_16s] for the 16s depth.
//
*/
IPPAPI(IppStatus, ippiBGRToHLS_8u_AC4R,(const Ipp8u* pSrc,int srcStep,Ipp8u* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRGBToHLS_8u_C3R,(const Ipp8u* pSrc,int srcStep,Ipp8u* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiHLSToRGB_8u_C3R,(const Ipp8u* pSrc,int srcStep,Ipp8u* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRGBToHLS_8u_AC4R,(const Ipp8u* pSrc,int srcStep,Ipp8u* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiHLSToRGB_8u_AC4R,(const Ipp8u* pSrc,int srcStep,Ipp8u* pDst,int dstStep, IppiSize roiSize))

IPPAPI(IppStatus, ippiRGBToHLS_16s_C3R,(const Ipp16s* pSrc,int srcStep,Ipp16s* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiHLSToRGB_16s_C3R,(const Ipp16s* pSrc,int srcStep,Ipp16s* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRGBToHLS_16s_AC4R,(const Ipp16s* pSrc,int srcStep,Ipp16s* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiHLSToRGB_16s_AC4R,(const Ipp16s* pSrc,int srcStep,Ipp16s* pDst,int dstStep, IppiSize roiSize))

IPPAPI(IppStatus, ippiRGBToHLS_16u_C3R,(const Ipp16u* pSrc,int srcStep,Ipp16u* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiHLSToRGB_16u_C3R,(const Ipp16u* pSrc,int srcStep,Ipp16u* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRGBToHLS_16u_AC4R,(const Ipp16u* pSrc,int srcStep,Ipp16u* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiHLSToRGB_16u_AC4R,(const Ipp16u* pSrc,int srcStep,Ipp16u* pDst,int dstStep, IppiSize roiSize))

IPPAPI(IppStatus, ippiRGBToHLS_32f_C3R,(const Ipp32f* pSrc,int srcStep,Ipp32f* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiHLSToRGB_32f_C3R,(const Ipp32f* pSrc,int srcStep,Ipp32f* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRGBToHLS_32f_AC4R,(const Ipp32f* pSrc,int srcStep,Ipp32f* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiHLSToRGB_32f_AC4R,(const Ipp32f* pSrc,int srcStep,Ipp32f* pDst,int dstStep, IppiSize roiSize))

IPPAPI(IppStatus, ippiBGRToHLS_8u_AP4R, (const Ipp8u* const pSrc[4], int srcStep, Ipp8u* pDst[4], int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiBGRToHLS_8u_AP4C4R, (const Ipp8u* const pSrc[4], int srcStep, Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiBGRToHLS_8u_AC4P4R, (const Ipp8u* pSrc, int srcStep, Ipp8u* pDst[4], int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiBGRToHLS_8u_P3R, (const Ipp8u* const pSrc[3], int srcStep, Ipp8u* pDst[3], int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiBGRToHLS_8u_P3C3R, (const Ipp8u* const pSrc[3], int srcStep, Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiBGRToHLS_8u_C3P3R, (const Ipp8u* pSrc, int srcStep, Ipp8u* pDst[3], int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiHLSToBGR_8u_AP4R, (const Ipp8u* const pSrc[4], int srcStep, Ipp8u* pDst[4], int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiHLSToBGR_8u_AP4C4R, (const Ipp8u* const pSrc[4], int srcStep, Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiHLSToBGR_8u_AC4P4R, (const Ipp8u* pSrc, int srcStep, Ipp8u* pDst[4], int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiHLSToBGR_8u_P3R, (const Ipp8u* const pSrc[3], int srcStep, Ipp8u* pDst[3], int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiHLSToBGR_8u_P3C3R, (const Ipp8u* const pSrc[3], int srcStep, Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiHLSToBGR_8u_C3P3R, (const Ipp8u* pSrc, int srcStep, Ipp8u* pDst[3], int dstStep, IppiSize roiSize))

/* ////////////////////////////////////////////////////////////////////////////
//  Name: ippiRGBToHSV and ippiHSVToRGB
//  Purpose:    Convert an image from RGB to HSV format and vice versa
//  Arguments:
//     pSrc - Pointer to the source image .
//     pDst - Pointer to the resultant image .
//     roiSize - region of interest in pixels.
//     srcStep - step in bytes through source image to jump on the next line
//     dstStep - step in bytes through destination image to jump on the next line
//  Returns:
//           ippStsNullPtrErr  if src == NULL or dst == NULL
//           ippStsStepErr,    if srcStep or dstStep is less or equal zero
//           ippStsSizeErr     if imgSize.width <= 0 || imgSize.height <= 0
//           ippStsNoErr       else
//  Reference:
//      David F.Rogers
//      Procedural elements for computer graphics
//      1985.pp.(401-403)
//
//       H is the hue red at 0 degrees, which has range [0 .. 360 degrees],
//       S is the saturation,
//       V is the value
//       The RGB to HSV conversion algorithm in pseudocode:
//   Value:
//      V = max(R,G,B);
//   Saturation:
//      temp = min(R,G,B);
//      if V = 0 then // achromatics case
//          S = 0
//          H = 0
//      else // chromatics case
//          S = (V - temp)/V
//   Hue:
//      Cr = (V - R) / (V - temp)
//      Cg = (V - G) / (V - temp)
//      Cb = (V - B) / (V - temp)
//      if R = V then H = Cb - Cg
//      if G = V then H = 2 + Cr - Cb
//      if B = V then H = 4 + Cg - Cr
//      H = 60*H
//      if H < 0 then H = H + 360
//
//      The HSV to RGB conversion algorithm in pseudocode:
//      if S = 0 then
//         R = G = B = V
//      else
//          if H = 360 then
//              H = 0
//          else
//              H = H/60
//           I = floor(H)
//           F = H - I;
//           M = V * ( 1 - S);
//           N = V * ( 1 - S * F);
//           K = V * ( 1 - S * (1 - F));
//           if(I == 0)then{ R = V;G = K;B = M;}
//           if(I == 1)then{ R = N;G = V;B = M;}
//           if(I == 2)then{ R = M;G = V;B = K;}
//           if(I == 3)then{ R = M;G = N;B = V;}
//           if(I == 4)then{ R = K;G = M;B = V;}
//           if(I == 5)then{ R = V;G = M;B = N;}
//
//           in the range [0..IPP_MAX_8u ] for the 8u depth,
//           in the range [0..IPP_MAX_16u] for the 16u depth,
//
*/
IPPAPI(IppStatus, ippiRGBToHSV_8u_C3R,(const Ipp8u* pSrc,int srcStep,Ipp8u* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiHSVToRGB_8u_C3R,(const Ipp8u* pSrc,int srcStep,Ipp8u* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRGBToHSV_8u_AC4R,(const Ipp8u* pSrc,int srcStep,Ipp8u* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiHSVToRGB_8u_AC4R,(const Ipp8u* pSrc,int srcStep,Ipp8u* pDst,int dstStep, IppiSize roiSize))

IPPAPI(IppStatus, ippiRGBToHSV_16u_C3R,(const Ipp16u* pSrc,int srcStep,Ipp16u* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiHSVToRGB_16u_C3R,(const Ipp16u* pSrc,int srcStep,Ipp16u* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRGBToHSV_16u_AC4R,(const Ipp16u* pSrc,int srcStep,Ipp16u* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiHSVToRGB_16u_AC4R,(const Ipp16u* pSrc,int srcStep,Ipp16u* pDst,int dstStep, IppiSize roiSize))

/* /////////////////////////////////////////////////////////////////////////////
//  Name: ippiRGBToYCC and ippiYCCToRGB
//  Purpose:    Convert an image from RGB to YCC format and backward.
//  Arguments:
//    pSrc          pointer to the source image ROI
//    srcStep       source image scan-line size (bytes)
//    pDst          pointer to the target image ROI
//    dstStep       target image scan-line size (bytes)
//    dstRoiSize    size of ROI
//  Returns:
//           ippStsNullPtrErr  if src == NULL or dst == NULL
//           ippStsStepErr     if srcStep or dstStep is less or equal zero
//           ippStsSizeErr     if imgSize.width <= 0 || imgSize.height <= 0
//           ippStsNoErr       otherwise
//  Reference:
//      Jack Keith
//      Video Demystified: a handbook for the digital engineer, 2nd ed.
//      1996.pp.(46-47)
//
//  The basic equations to convert gamma-corrected R'G'B' to YCC are:
//
//   R’G’B’ data is transformed into PhotoYCC data:
//    Y  =  0.299*R' + 0.587*G' + 0.114*B'
//    C1 = -0.299*R' - 0.587*G' + 0.886*B' = B'- Y
//    C2 =  0.701*R' - 0.587*G' - 0.114*B' = R'- Y
//   Y,C1,C2 are quantized and limited to the range [0..1]
//    Y  = 1. / 1.402 * Y
//    C1 = 111.4 / 255. * C1 + 156. / 255.
//    C2 = 135.64 /255. * C2 + 137. / 255.
//
//  Conversion of PhotoYCC data to RGB data for CRT computer display:
//
//   normal luminance and chrominance data are recovered
//    Y  = 1.3584 * Y
//    C1 = 2.2179 * (C1 - 156./255.)
//    C2 = 1.8215 * (C2 - 137./255.)
//   PhotoYCC data is transformed into R’G’B’ data
//    R' = L + C2
//    G' = L - 0.194*C1 - 0.509*C2
//    B' = L + C1
//    Where:  Y -  luminance; and C1, C2  - two chrominance values.
//
//  Equations are given above in assumption that the Y, C1, C2, R, G, and B
//   values are in the range [0..1].
//   Y, C1, C2, R, G, B - are scaled to the range [0..1] for the 32f depth,
//   to the range [0..IPP_MAX_8u] for the 8u depth,
//   to the range [0..IPP_MAX_16u] for the 16u depth,
//   to the range [IPP_MIN_16s..IPP_MAX_16s] for the 16s depth.
*/

IPPAPI(IppStatus, ippiRGBToYCC_8u_C3R,(const Ipp8u* pSrc,int srcStep,Ipp8u* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiYCCToRGB_8u_C3R,(const Ipp8u* pSrc,int srcStep,Ipp8u* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRGBToYCC_8u_AC4R,(const Ipp8u* pSrc,int srcStep,Ipp8u* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiYCCToRGB_8u_AC4R,(const Ipp8u* pSrc,int srcStep,Ipp8u* pDst,int dstStep, IppiSize roiSize))

IPPAPI(IppStatus, ippiRGBToYCC_16u_C3R,(const Ipp16u* pSrc,int srcStep,Ipp16u* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiYCCToRGB_16u_C3R,(const Ipp16u* pSrc,int srcStep,Ipp16u* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRGBToYCC_16u_AC4R,(const Ipp16u* pSrc,int srcStep,Ipp16u* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiYCCToRGB_16u_AC4R,(const Ipp16u* pSrc,int srcStep,Ipp16u* pDst,int dstStep, IppiSize roiSize))

IPPAPI(IppStatus, ippiRGBToYCC_16s_C3R,(const Ipp16s* pSrc,int srcStep,Ipp16s* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiYCCToRGB_16s_C3R,(const Ipp16s* pSrc,int srcStep,Ipp16s* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRGBToYCC_16s_AC4R,(const Ipp16s* pSrc,int srcStep,Ipp16s* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiYCCToRGB_16s_AC4R,(const Ipp16s* pSrc,int srcStep,Ipp16s* pDst,int dstStep, IppiSize roiSize))

IPPAPI(IppStatus, ippiRGBToYCC_32f_C3R,(const Ipp32f* pSrc,int srcStep,Ipp32f* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiYCCToRGB_32f_C3R,(const Ipp32f* pSrc,int srcStep,Ipp32f* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRGBToYCC_32f_AC4R,(const Ipp32f* pSrc,int srcStep,Ipp32f* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiYCCToRGB_32f_AC4R,(const Ipp32f* pSrc,int srcStep,Ipp32f* pDst,int dstStep, IppiSize roiSize))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippiRGBToXYZ and ippiXYZToRGB
//  Purpose:    Convert an image from RGB to XYZ format and backward.
//  Arguments:
//    pSrc          pointer to the source image ROI
//    srcStep       source image scan-line size (bytes)
//    pDst          pointer to the target image ROI
//    dstStep       target image scan-line size (bytes)
//    roiSize    size of ROI
//  Returns:
//           ippStsNullPtrErr  if src == NULL or dst == NULL
//           ippStsStepErr     if srcStep or dstStep is less or equal zero
//           ippStsSizeErr     if imgSize.width <= 0 || imgSize.height <= 0
//           ippStsNoErr       otherwise
//  Reference:
//      David F. Rogers
//      Procedupal elements for computer graphics.
//      1985.
//
//  The basic equations to convert between Rec. 709 RGB (with its D65 white point) and CIE XYZ are:
//
//       X =  0.412453 * R + 0.35758 * G + 0.180423 * B
//       Y =  0.212671 * R + 0.71516 * G + 0.072169 * B
//       Z =  0.019334 * R + 0.119193* G + 0.950227 * B
//
//       R = 3.240479 * X - 1.53715  * Y  - 0.498535 * Z
//       G =-0.969256 * X + 1.875991 * Y  + 0.041556 * Z
//       B = 0.055648 * X - 0.204043 * Y  + 1.057311 * Z
//  Equations are given above in assumption that the X,Y,Z,R,G,and B
//   values are in the range [0..1].
//   Y, C1, C2, R, G, B - are scaled to the range [0..1] for the 32f depth,
//   to the range [0..IPP_MAX_8u] for the 8u depth,
//   to the range [0..IPP_MAX_16u] for the 16u depth,
//   to the range [IPP_MIN_16s..IPP_MAX_16s] for the 16s depth.
//
*/
IPPAPI(IppStatus, ippiRGBToXYZ_8u_C3R,(const Ipp8u* pSrc,int srcStep,Ipp8u* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXYZToRGB_8u_C3R,(const Ipp8u* pSrc,int srcStep,Ipp8u* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRGBToXYZ_8u_AC4R,(const Ipp8u* pSrc,int srcStep,Ipp8u* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXYZToRGB_8u_AC4R,(const Ipp8u* pSrc,int srcStep,Ipp8u* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRGBToXYZ_16u_C3R,(const Ipp16u* pSrc,int srcStep,Ipp16u* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXYZToRGB_16u_C3R,(const Ipp16u* pSrc,int srcStep,Ipp16u* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRGBToXYZ_16u_AC4R,(const Ipp16u* pSrc,int srcStep,Ipp16u* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXYZToRGB_16u_AC4R,(const Ipp16u* pSrc,int srcStep,Ipp16u* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRGBToXYZ_16s_C3R,(const Ipp16s* pSrc,int srcStep,Ipp16s* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXYZToRGB_16s_C3R,(const Ipp16s* pSrc,int srcStep,Ipp16s* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRGBToXYZ_16s_AC4R,(const Ipp16s* pSrc,int srcStep,Ipp16s* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXYZToRGB_16s_AC4R,(const Ipp16s* pSrc,int srcStep,Ipp16s* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRGBToXYZ_32f_C3R,(const Ipp32f* pSrc,int srcStep,Ipp32f* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXYZToRGB_32f_C3R,(const Ipp32f* pSrc,int srcStep,Ipp32f* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRGBToXYZ_32f_AC4R,(const Ipp32f* pSrc,int srcStep,Ipp32f* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXYZToRGB_32f_AC4R,(const Ipp32f* pSrc,int srcStep,Ipp32f* pDst,int dstStep, IppiSize roiSize))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippiRGBToLUV and ippiLUVToRGB
//  Purpose:    Convert an image from RGB to XYZ format and backward.
//  Arguments:
//    pSrc          pointer to the source image ROI
//    srcStep       source image scan-line size (bytes)
//    pDst          pointer to the target image ROI
//    dstStep       target image scan-line size (bytes)
//    roiSize       size of ROI
//  Returns:
//           ippStsNullPtrErr  if src == NULL or dst == NULL
//           ippStsStepErr     if srcStep or dstStep is less or equal zero
//           ippStsSizeErr     if imgSize.width <= 0 || imgSize.height <= 0
//           ippStsNoErr       otherwise
//  Reference:
//     Computer graphics: principles and practices. James D. Foley... [et al.]. 2nd ed.
//     Addison-Wesley, c1990.p.(584)
//
//    At first an RGB image is converted to the XYZ format image (look at the function
//    ippRGB2XYZ8uC3R), then to the CIELUV with the white point D65 and CIE chromaticity
//    coordinates of white point (xn,yn) = (0.312713, 0.329016) and Yn = 1.0. is the luminance of white point.
//
//       L = 116. * (Y/Yn)**1/3. - 16.
//       U = 13. * L * ( u - un )
//       V = 13. * L * ( v - vn )
//      These are quantized and limited to the 8-bit range of 0 to 255.
//       L =   L * 255. / 100.
//       U = ( U + 134. ) * 255. / 354.
//       V = ( V + 140. ) * 255. / 256.
//       where:
//       u' = 4.*X / (X + 15.*Y + 3.*Z)
//       v' = 9.*Y / (X + 15.*Y + 3.*Z)
//       un = 4.*xn / ( -2.*xn + 12.*yn + 3. )
//       vn = 9.*yn / ( -2.*xn + 12.*yn + 3. ).
//       xn, yn is the CIE chromaticity coordinates of white point.
//       Yn = 255. is the luminance of white point.
//
//       The L component values are in the range [0..100], the U component values are
//       in the range [-134..220], and the V component values are in the range [-140..122].
//
//      The CIELUV to RGB conversion is performed as following. At first
//      a LUV image is converted to the XYZ image
//       L  =   L * 100./ 255.
//       U  = ( U * 354./ 255.) - 134.
//       V  = ( V * 256./ 255.) - 140.
//       u = U / ( 13.* L ) + un
//       v = V / ( 13.* L ) + vn
//       Y = (( L + 16. ) / 116. )**3.
//       Y *= Yn
//       X =  -9.* Y * u / (( u - 4.)* v - u * v )
//       Z = ( 9.*Y - 15*v*Y - v*X ) / 3. * v
//       where:
//       un = 4.*xn / ( -2.*xn + 12.*yn + 3. )
//       vn = 9.*yn / ( -2.*xn + 12.*yn + 3. ).
//       xn, yn is the CIE chromaticity coordinates of white point.
//       Yn = 255. is the luminance of white point.
//
//     Then the XYZ image is converted to the RGB image (look at the function
//     ippXYZ2RGB8uC3R ).
//
*/

IPPAPI(IppStatus, ippiRGBToLUV_8u_C3R,(const Ipp8u* pSrc,int srcStep,Ipp8u* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiLUVToRGB_8u_C3R,(const Ipp8u* pSrc,int srcStep,Ipp8u* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRGBToLUV_8u_AC4R,(const Ipp8u* pSrc,int srcStep,Ipp8u* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiLUVToRGB_8u_AC4R,(const Ipp8u* pSrc,int srcStep,Ipp8u* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRGBToLUV_16u_C3R,(const Ipp16u* pSrc,int srcStep,Ipp16u* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiLUVToRGB_16u_C3R,(const Ipp16u* pSrc,int srcStep,Ipp16u* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRGBToLUV_16u_AC4R,(const Ipp16u* pSrc,int srcStep,Ipp16u* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiLUVToRGB_16u_AC4R,(const Ipp16u* pSrc,int srcStep,Ipp16u* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRGBToLUV_16s_C3R,(const Ipp16s* pSrc,int srcStep,Ipp16s* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiLUVToRGB_16s_C3R,(const Ipp16s* pSrc,int srcStep,Ipp16s* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRGBToLUV_16s_AC4R,(const Ipp16s* pSrc,int srcStep,Ipp16s* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiLUVToRGB_16s_AC4R,(const Ipp16s* pSrc,int srcStep,Ipp16s* pDst,int dstStep, IppiSize roiSize))

IPPAPI(IppStatus, ippiRGBToLUV_32f_C3R,(const Ipp32f* pSrc,int srcStep,Ipp32f* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiLUVToRGB_32f_C3R,(const Ipp32f* pSrc,int srcStep,Ipp32f* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRGBToLUV_32f_AC4R,(const Ipp32f* pSrc,int srcStep,Ipp32f* pDst,int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiLUVToRGB_32f_AC4R,(const Ipp32f* pSrc,int srcStep,Ipp32f* pDst,int dstStep, IppiSize roiSize))

/* ////////////////////////////////////////////////////////////////////////////
//  Name:       ippReduceBits
//  Purpose:    Transforms Image of a higher bit resolution to a lower bit resolution.
//  Arguments:
//     pSrc - Pointer to the source image .
//     pDst - Pointer to the resultant image .
//     roiSize - region of interest in pixels.
//     srcStep - step in bytes through source image to jump on the next line
//     dstStep - step in bytes through destination image to jump on the next line
//     noise   - the number specifying the noise added,is set in percentage of a range [0..100]
//     levels  - the number of output levels for halftoning (dithering)[2.. MAX_LEVELS],
//            where  MAX_LEVELS is  0x01 << depth and depth is depth of the destination image
//     dtype  -  the type of dithering to be used. The following are allowed
//        ippDitherNone     no dithering is done
//        ippDitherStucki   Stucki's dithering algorithm
//        ippDitherFS       Floid-Steinberg's dithering algorithm
//        ippDitherJJN      Jarvice-Judice-Ninke's dithering algorithm
//        ippDitherBayer    Bayer's dithering algorithm
//      RGB  values for the 32f data type should be in the range [0..1]
//  Returns:
//           ippStsNullPtrErr  if src == NULL or dst == NULL
//           ippStsStepErr,    if srcStep or dstStep is less or equal zero
//           ippStsSizeErr     if imgSize.width <= 0 || imgSize.height <= 0
//           ippStsNoiseValErr : "Bad value of noise amplitude for dithering"
//           ippStsDitherLevelsErr : "Number of dithering levels is out of range"
//           ippStsNoErr       else
*/

IPPAPI(IppStatus, ippiReduceBits_8u_C1R,(const Ipp8u* pSrc,int srcStep,Ipp8u* pDst,int dstStep,IppiSize roiSize,
       int noise, IppiDitherType dtype, int levels))
IPPAPI(IppStatus, ippiReduceBits_8u_C3R,(const Ipp8u* pSrc,int srcStep,Ipp8u* pDst,int dstStep,IppiSize roiSize,
       int noise, IppiDitherType dtype, int levels))
IPPAPI(IppStatus, ippiReduceBits_8u_AC4R,(const Ipp8u* pSrc,int srcStep,Ipp8u* pDst,int dstStep,IppiSize roiSize,
       int noise, IppiDitherType dtype, int levels))
IPPAPI(IppStatus, ippiReduceBits_8u_C4R,(const Ipp8u* pSrc,int srcStep,Ipp8u* pDst,int dstStep,IppiSize roiSize,
       int noise, IppiDitherType dtype, int levels))

IPPAPI(IppStatus, ippiReduceBits_16u_C1R,(const Ipp16u* pSrc,int srcStep,Ipp16u* pDst,int dstStep,IppiSize roiSize,
       int noise, IppiDitherType dtype, int levels))
IPPAPI(IppStatus, ippiReduceBits_16u_C3R,(const Ipp16u* pSrc,int srcStep,Ipp16u* pDst,int dstStep,IppiSize roiSize,
       int noise, IppiDitherType dtype, int levels))
IPPAPI(IppStatus, ippiReduceBits_16u_AC4R,(const Ipp16u* pSrc,int srcStep,Ipp16u* pDst,int dstStep,IppiSize roiSize,
       int noise, IppiDitherType dtype, int levels))
IPPAPI(IppStatus, ippiReduceBits_16u_C4R,(const Ipp16u* pSrc,int srcStep,Ipp16u* pDst,int dstStep,IppiSize roiSize,
       int noise, IppiDitherType dtype, int levels))

IPPAPI(IppStatus, ippiReduceBits_16u8u_C1R,(const Ipp16u* pSrc,int srcStep,Ipp8u* pDst,int dstStep,IppiSize roiSize,
       int noise, IppiDitherType dtype, int levels))
IPPAPI(IppStatus, ippiReduceBits_16u8u_C3R,(const Ipp16u* pSrc,int srcStep,Ipp8u* pDst,int dstStep,IppiSize roiSize,
       int noise, IppiDitherType dtype, int levels))
IPPAPI(IppStatus, ippiReduceBits_16u8u_AC4R,(const Ipp16u* pSrc,int srcStep,Ipp8u* pDst,int dstStep,IppiSize roiSize,
       int noise, IppiDitherType dtype, int levels))
IPPAPI(IppStatus, ippiReduceBits_16u8u_C4R,(const Ipp16u* pSrc,int srcStep,Ipp8u* pDst,int dstStep,IppiSize roiSize,
       int noise, IppiDitherType dtype, int levels))

IPPAPI(IppStatus, ippiReduceBits_16s_C1R,(const Ipp16s* pSrc,int srcStep,Ipp16s* pDst,int dstStep,IppiSize roiSize,
       int noise, IppiDitherType dtype, int levels))
IPPAPI(IppStatus, ippiReduceBits_16s_C3R,(const Ipp16s* pSrc,int srcStep,Ipp16s* pDst,int dstStep,IppiSize roiSize,
       int noise, IppiDitherType dtype, int levels))
IPPAPI(IppStatus, ippiReduceBits_16s_AC4R,(const Ipp16s* pSrc,int srcStep,Ipp16s* pDst,int dstStep,IppiSize roiSize,
       int noise, IppiDitherType dtype, int levels))
IPPAPI(IppStatus, ippiReduceBits_16s_C4R,(const Ipp16s* pSrc,int srcStep,Ipp16s* pDst,int dstStep,IppiSize roiSize,
       int noise, IppiDitherType dtype, int levels))

IPPAPI(IppStatus, ippiReduceBits_16s8u_C1R,(const Ipp16s* pSrc,int srcStep,Ipp8u* pDst,int dstStep,IppiSize roiSize,
       int noise, IppiDitherType dtype, int levels))
IPPAPI(IppStatus, ippiReduceBits_16s8u_C3R,(const Ipp16s* pSrc,int srcStep,Ipp8u* pDst,int dstStep,IppiSize roiSize,
       int noise, IppiDitherType dtype, int levels))
IPPAPI(IppStatus, ippiReduceBits_16s8u_AC4R,(const Ipp16s* pSrc,int srcStep,Ipp8u* pDst,int dstStep,IppiSize roiSize,
       int noise, IppiDitherType dtype, int levels))
IPPAPI(IppStatus, ippiReduceBits_16s8u_C4R,(const Ipp16s* pSrc,int srcStep,Ipp8u* pDst,int dstStep,IppiSize roiSize,
       int noise, IppiDitherType dtype, int levels))

IPPAPI(IppStatus, ippiReduceBits_32f8u_C1R,(const Ipp32f* pSrc,int srcStep,Ipp8u* pDst,int dstStep,IppiSize roiSize,
       int noise, IppiDitherType dtype, int levels))
IPPAPI(IppStatus, ippiReduceBits_32f8u_C3R,(const Ipp32f* pSrc,int srcStep,Ipp8u* pDst,int dstStep,IppiSize roiSize,
       int noise, IppiDitherType dtype, int levels))
IPPAPI(IppStatus, ippiReduceBits_32f8u_AC4R,(const Ipp32f* pSrc,int srcStep,Ipp8u* pDst,int dstStep,IppiSize roiSize,
       int noise, IppiDitherType dtype, int levels))
IPPAPI(IppStatus, ippiReduceBits_32f8u_C4R,(const Ipp32f* pSrc,int srcStep,Ipp8u* pDst,int dstStep,IppiSize roiSize,
       int noise, IppiDitherType dtype, int levels))

IPPAPI(IppStatus, ippiReduceBits_32f16u_C1R,(const Ipp32f* pSrc,int srcStep,Ipp16u* pDst,int dstStep,IppiSize roiSize,
       int noise, IppiDitherType dtype, int levels))
IPPAPI(IppStatus, ippiReduceBits_32f16u_C3R,(const Ipp32f* pSrc,int srcStep,Ipp16u* pDst,int dstStep,IppiSize roiSize,
       int noise, IppiDitherType dtype, int levels))
IPPAPI(IppStatus, ippiReduceBits_32f16u_AC4R,(const Ipp32f* pSrc,int srcStep,Ipp16u* pDst,int dstStep,IppiSize roiSize,
       int noise, IppiDitherType dtype, int levels))
IPPAPI(IppStatus, ippiReduceBits_32f16u_C4R,(const Ipp32f* pSrc,int srcStep,Ipp16u* pDst,int dstStep,IppiSize roiSize,
       int noise, IppiDitherType dtype, int levels))

IPPAPI(IppStatus, ippiReduceBits_32f16s_C1R,(const Ipp32f* pSrc,int srcStep,Ipp16s* pDst,int dstStep,IppiSize roiSize,
       int noise, IppiDitherType dtype, int levels))
IPPAPI(IppStatus, ippiReduceBits_32f16s_C3R,(const Ipp32f* pSrc,int srcStep,Ipp16s* pDst,int dstStep,IppiSize roiSize,
       int noise, IppiDitherType dtype, int levels))
IPPAPI(IppStatus, ippiReduceBits_32f16s_AC4R,(const Ipp32f* pSrc,int srcStep,Ipp16s* pDst,int dstStep,IppiSize roiSize,
       int noise, IppiDitherType dtype, int levels))
IPPAPI(IppStatus, ippiReduceBits_32f16s_C4R,(const Ipp32f* pSrc,int srcStep,Ipp16s* pDst,int dstStep,IppiSize roiSize,
       int noise, IppiDitherType dtype, int levels))

/* ////////////////////////////////////////////////////////////////////////////
//  Name:       ippiColorTwist
//
//  Purpose:    Applies a color-twist matrix to an image.
//              |R|   | t11 t12 t13 t14 |   |r|
//              |G| = | t21 t22 t23 t24 | * |g|
//              |B|   | t31 t32 t33 t34 |   |b|
//
//               R = t11*r + t12*g + t13*b + t14
//               G = t21*r + t22*g + t23*b + t24
//               B = t31*r + t32*g + t33*b + t34
//
//  Return:
//    ippStsNullPtrErr      One of pointers are NULL
//    ippStsSizeErr         The size of images is less or equal zero
//    ippStsStepErr         The steps of images are less or equal zero
//    ippStsNoErr           Ok
//
//  Arguments:
//    pSrc                  pointer  to the source image
//    srcStep               size of input image scan-line
//    pDst                  pointer to the  destination image
//    dstStep               size of output image scan-line
//    roiSize               size of ROI
//    twist                 color-twist matrix
*/
IPPAPI ( IppStatus, ippiColorTwist32f_8u_C3R, ( const Ipp8u* pSrc, int srcStep, Ipp8u* pDst, int dstStep,
                    IppiSize roiSize, const Ipp32f twist[3][4] ))
IPPAPI ( IppStatus, ippiColorTwist32f_8u_C3IR, ( Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize,
                    const Ipp32f twist[3][4] ))
IPPAPI ( IppStatus, ippiColorTwist32f_8u_AC4R, ( const Ipp8u* pSrc, int srcStep, Ipp8u* pDst, int dstStep,
                    IppiSize roiSize, const Ipp32f twist[3][4] ))
IPPAPI ( IppStatus, ippiColorTwist32f_8u_AC4IR, ( Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize,
                    const Ipp32f twist[3][4] ))
IPPAPI ( IppStatus, ippiColorTwist32f_8u_P3R, ( const Ipp8u* const pSrc[3], int srcStep,
                    Ipp8u* const pDst[3], int dstStep,
                    IppiSize roiSize, const Ipp32f twist[3][4] ))
IPPAPI ( IppStatus, ippiColorTwist32f_8u_IP3R, ( Ipp8u* const pSrcDst[3], int srcDstStep,
                    IppiSize roiSize, const Ipp32f twist[3][4] ))
IPPAPI ( IppStatus, ippiColorTwist32f_16u_C3R, ( const Ipp16u* pSrc, int srcStep, Ipp16u* pDst, int dstStep,
                    IppiSize roiSize, const Ipp32f twist[3][4] ))
IPPAPI ( IppStatus, ippiColorTwist32f_16u_C3IR, ( Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize,
                    const Ipp32f twist[3][4] ))
IPPAPI ( IppStatus, ippiColorTwist32f_16u_AC4R, ( const Ipp16u* pSrc, int srcStep, Ipp16u* pDst, int dstStep,
                    IppiSize roiSize, const Ipp32f twist[3][4] ))
IPPAPI ( IppStatus, ippiColorTwist32f_16u_AC4IR, ( Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize,
                    const Ipp32f twist[3][4] ))
IPPAPI ( IppStatus, ippiColorTwist32f_16u_P3R, ( const Ipp16u* const pSrc[3], int srcStep,
                    Ipp16u* const pDst[3], int dstStep,
                    IppiSize roiSize, const Ipp32f twist[3][4] ))
IPPAPI ( IppStatus, ippiColorTwist32f_16u_IP3R, ( Ipp16u* const pSrcDst[3], int srcDstStep,
                    IppiSize roiSize, const Ipp32f twist[3][4] ))
IPPAPI ( IppStatus, ippiColorTwist32f_16s_C3R, ( const Ipp16s* pSrc, int srcStep, Ipp16s* pDst, int dstStep,
                    IppiSize roiSize, const Ipp32f twist[3][4] ))
IPPAPI ( IppStatus, ippiColorTwist32f_16s_C3IR, ( Ipp16s* pSrcDst, int srcDstStep, IppiSize roiSize,
                    const Ipp32f twist[3][4] ))
IPPAPI ( IppStatus, ippiColorTwist32f_16s_AC4R, ( const Ipp16s* pSrc, int srcStep, Ipp16s* pDst, int dstStep,
                    IppiSize roiSize, const Ipp32f twist[3][4] ))
IPPAPI ( IppStatus, ippiColorTwist32f_16s_AC4IR, ( Ipp16s* pSrcDst, int srcDstStep, IppiSize roiSize,
                    const Ipp32f twist[3][4] ))
IPPAPI ( IppStatus, ippiColorTwist32f_16s_P3R, ( const Ipp16s* const pSrc[3], int srcStep,
                    Ipp16s* const pDst[3], int dstStep,
                    IppiSize roiSize, const Ipp32f twist[3][4] ))
IPPAPI ( IppStatus, ippiColorTwist32f_16s_IP3R, ( Ipp16s* const pSrcDst[3], int srcDstStep,
                    IppiSize roiSize, const Ipp32f twist[3][4] ))
IPPAPI ( IppStatus, ippiColorTwist_32f_C3R, ( const Ipp32f* pSrc, int srcStep, Ipp32f* pDst, int dstStep,
                    IppiSize roiSize, const Ipp32f twist[3][4] ))
IPPAPI ( IppStatus, ippiColorTwist_32f_C3IR, ( Ipp32f* pSrcDst, int srcDstStep, IppiSize roiSize,
                    const Ipp32f twist[3][4] ))
IPPAPI ( IppStatus, ippiColorTwist_32f_AC4R, ( const Ipp32f* pSrc, int srcStep, Ipp32f* pDst, int dstStep,
                    IppiSize roiSize, const Ipp32f twist[3][4] ))
IPPAPI ( IppStatus, ippiColorTwist_32f_AC4IR, ( Ipp32f* pSrcDst, int srcDstStep, IppiSize roiSize,
                    const Ipp32f twist[3][4] ))
IPPAPI ( IppStatus, ippiColorTwist_32f_P3R, ( const Ipp32f* const pSrc[3], int srcStep,
                    Ipp32f* const pDst[3], int dstStep,
                    IppiSize roiSize, const Ipp32f twist[3][4] ))
IPPAPI ( IppStatus, ippiColorTwist_32f_IP3R, ( Ipp32f* const pSrcDst[3], int srcDstStep,
                    IppiSize roiSize, const Ipp32f twist[3][4] ))

/* ////////////////////////////////////////////////////////////////////////////
//  Name:       ippiColorTwist_32f_C4R
//
//  Purpose:    Applies a color-twist matrix to an image.
//              |R|   | t11 t12 t13 t14 |   |r|
//              |G| = | t21 t22 t23 t24 | * |g|
//              |B|   | t31 t32 t33 t34 |   |b|
//              |W|   | t41 t42 t43 t44 |   |w|
//               R = t11*r + t12*g + t13*b + t14*w
//               G = t21*r + t22*g + t23*b + t24*w
//               B = t31*r + t32*g + t33*b + t34*w
//               W = t41*r + t42*g + t43*b + t44*w
//
//  Return:
//    ippStsNullPtrErr      One of pointers are NULL
//    ippStsSizeErr         The size of images is less or equal zero
//    ippStsStepErr         The steps of images are less or equal zero
//    ippStsNoErr           Ok
//
//  Arguments:
//    pSrc                  pointer  to the source image
//    srcStep               size of input image scan-line
//    pDst                  pointer to the  destination image
//    dstStep               size of output image scan-line
//    roiSize               size of ROI
//    twist                 color-twist matrix
*/

IPPAPI ( IppStatus, ippiColorTwist_32f_C4R,( const Ipp32f* pSrc, int srcStep,Ipp32f* pDst, int dstStep,
           IppiSize roiSize, const Ipp32f twist[4][4]))

/* ////////////////////////////////////////////////////////////////////////////
//  Name:       ippiGamma
//
//  Purpose:    Converting RGB image to and from gamma-corrected R'G'B' image.
//                  1). Fwd:
//                      for R,G,B < 0.018
//                          R' = 4.5 * R
//                          G' = 4.5 * G
//                          B' = 4.5 * B
//                      for R,G,B >= 0.018
//                          R' = 1.099 * (R**0.45) - 0.099
//                          G' = 1.099 * (G**0.45) - 0.099
//                          B' = 1.099 * (B**0.45) - 0.099
//
//                  2). Inv:
//                      for R',G',B' < 0.0812
//                          R = R' / 4.5
//                          G = G' / 4.5
//                          B = B' / 4.5
//                      for R',G',B' >= 0.0812
//                          R = (( R' + 0.099 ) / 1.099 )** 1 / 0.45
//                          G = (( G' + 0.099 ) / 1.099 )** 1 / 0.45
//                          B = (( B' + 0.099 ) / 1.099 )** 1 / 0.45
//
//                  Note: example for range[0,1].
//
//  Return:
//    ippStsNullPtrErr      One of pointers are NULL
//    ippStsSizeErr         The size of images is less or equal zero
//    ippStsStepErr         The steps of images are less or equal zero
//    ippStsGammaRangeErr   vMax - vMin <= 0 (for 32f)
//    ippStsNoErr           Ok
//
//  Arguments:
//    pSrc                  pointer  to the source image
//    srcStep               size of input image scan-line
//    pDst                  pointer to the  destination image
//    dstStep               size of output image scan-line
//    roiSize               size of ROI
//    [vMin...vMax]         range for depth 32f.
*/
IPPAPI(IppStatus,ippiGammaFwd_8u_C3R, ( const Ipp8u* pSrc, int srcStep, Ipp8u* pDst, int dstStep, IppiSize roiSize ))
IPPAPI(IppStatus,ippiGammaFwd_8u_C3IR, ( Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize ))
IPPAPI(IppStatus,ippiGammaInv_8u_C3R, ( const Ipp8u* pSrc, int srcStep, Ipp8u* pDst, int dstStep, IppiSize roiSize ))
IPPAPI(IppStatus,ippiGammaInv_8u_C3IR, ( Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize ))
IPPAPI(IppStatus,ippiGammaFwd_8u_AC4R, ( const Ipp8u* pSrc, int srcStep, Ipp8u* pDst, int dstStep, IppiSize roiSize ))
IPPAPI(IppStatus,ippiGammaFwd_8u_AC4IR, ( Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize ))
IPPAPI(IppStatus,ippiGammaInv_8u_AC4R, ( const Ipp8u* pSrc, int srcStep, Ipp8u* pDst, int dstStep, IppiSize roiSize ))
IPPAPI(IppStatus,ippiGammaInv_8u_AC4IR, ( Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize ))
IPPAPI(IppStatus,ippiGammaFwd_8u_P3R, ( const Ipp8u* const pSrc[3], int srcStep, Ipp8u* const pDst[3], int dstStep, IppiSize roiSize ))
IPPAPI(IppStatus,ippiGammaFwd_8u_IP3R, ( Ipp8u* const pSrcDst[3], int srcDstStep, IppiSize roiSize ))
IPPAPI(IppStatus,ippiGammaInv_8u_P3R, ( const Ipp8u* const pSrc[3], int srcStep, Ipp8u* const pDst[3], int dstStep, IppiSize roiSize ))
IPPAPI(IppStatus,ippiGammaInv_8u_IP3R, ( Ipp8u* const pSrcDst[3], int srcDstStep, IppiSize roiSize ))
IPPAPI(IppStatus,ippiGammaFwd_16u_C3R, ( const Ipp16u* pSrc, int srcStep, Ipp16u* pDst, int dstStep, IppiSize roiSize ))
IPPAPI(IppStatus,ippiGammaFwd_16u_C3IR, ( Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize ))
IPPAPI(IppStatus,ippiGammaInv_16u_C3R, ( const Ipp16u* pSrc, int srcStep, Ipp16u* pDst, int dstStep, IppiSize roiSize ))
IPPAPI(IppStatus,ippiGammaInv_16u_C3IR, ( Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize ))
IPPAPI(IppStatus,ippiGammaFwd_16u_AC4R, ( const Ipp16u* pSrc, int srcStep, Ipp16u* pDst, int dstStep, IppiSize roiSize ))
IPPAPI(IppStatus,ippiGammaFwd_16u_AC4IR, ( Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize ))
IPPAPI(IppStatus,ippiGammaInv_16u_AC4R, ( const Ipp16u* pSrc, int srcStep, Ipp16u* pDst, int dstStep, IppiSize roiSize ))
IPPAPI(IppStatus,ippiGammaInv_16u_AC4IR, ( Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize ))
IPPAPI(IppStatus,ippiGammaFwd_16u_P3R, ( const Ipp16u* const pSrc[3], int srcStep, Ipp16u* const pDst[3], int dstStep, IppiSize roiSize ))
IPPAPI(IppStatus,ippiGammaFwd_16u_IP3R, ( Ipp16u* const pSrcDst[3], int srcDstStep, IppiSize roiSize ))
IPPAPI(IppStatus,ippiGammaInv_16u_P3R, ( const Ipp16u* const pSrc[3], int srcStep, Ipp16u* const pDst[3], int dstStep, IppiSize roiSize ))
IPPAPI(IppStatus,ippiGammaInv_16u_IP3R, ( Ipp16u* const pSrcDst[3], int srcDstStep, IppiSize roiSize ))
IPPAPI(IppStatus,ippiGammaFwd_32f_C3R, ( const Ipp32f* pSrc, int srcStep, Ipp32f* pDst, int dstStep, IppiSize roiSize, Ipp32f vMin, Ipp32f vMax  ))
IPPAPI(IppStatus,ippiGammaFwd_32f_C3IR, ( Ipp32f* pSrcDst, int srcDstStep, IppiSize roiSize, Ipp32f vMin, Ipp32f vMax ))
IPPAPI(IppStatus,ippiGammaInv_32f_C3R, ( const Ipp32f* pSrc, int srcStep, Ipp32f* pDst, int dstStep, IppiSize roiSize, Ipp32f vMin, Ipp32f vMax  ))
IPPAPI(IppStatus,ippiGammaInv_32f_C3IR, ( Ipp32f* pSrcDst, int srcDstStep, IppiSize roiSize, Ipp32f vMin, Ipp32f vMax ))
IPPAPI(IppStatus,ippiGammaFwd_32f_AC4R, ( const Ipp32f* pSrc, int srcStep, Ipp32f* pDst, int dstStep, IppiSize roiSize, Ipp32f vMin, Ipp32f vMax  ))
IPPAPI(IppStatus,ippiGammaFwd_32f_AC4IR, ( Ipp32f* pSrcDst, int srcDstStep, IppiSize roiSize, Ipp32f vMin, Ipp32f vMax ))
IPPAPI(IppStatus,ippiGammaInv_32f_AC4R, ( const Ipp32f* pSrc, int srcStep, Ipp32f* pDst, int dstStep, IppiSize roiSize, Ipp32f vMin, Ipp32f vMax  ))
IPPAPI(IppStatus,ippiGammaInv_32f_AC4IR, ( Ipp32f* pSrcDst, int srcDstStep, IppiSize roiSize, Ipp32f vMin, Ipp32f vMax ))
IPPAPI(IppStatus,ippiGammaFwd_32f_P3R, ( const Ipp32f* const pSrc[3], int srcStep, Ipp32f* const pDst[3], int dstStep, IppiSize roiSize, Ipp32f vMin, Ipp32f vMax  ))
IPPAPI(IppStatus,ippiGammaFwd_32f_IP3R, ( Ipp32f* const pSrcDst[3], int srcDstStep, IppiSize roiSize, Ipp32f vMin, Ipp32f vMax  ))
IPPAPI(IppStatus,ippiGammaInv_32f_P3R, ( const Ipp32f* const pSrc[3], int srcStep, Ipp32f* const pDst[3], int dstStep, IppiSize roiSize, Ipp32f vMin, Ipp32f vMax  ))
IPPAPI(IppStatus,ippiGammaInv_32f_IP3R, ( Ipp32f* const pSrcDst[3], int srcDstStep, IppiSize roiSize, Ipp32f vMin, Ipp32f vMax  ))



/* /////////////////////////////////////////////////////////////////////////////
//                   Geometrical functions
///////////////////////////////////////////////////////////////////////////// */

#if !defined( _OWN_BLDPCS )
typedef enum {
    ippAxsHorizontal,
    ippAxsVertical,
    ippAxsBoth
} IppiAxis;


enum {
    IPPI_INTER_NN     = 1,
    IPPI_INTER_LINEAR = 2,
    IPPI_INTER_CUBIC  = 4,
    IPPI_INTER_SUPER  = 8,
    IPPI_SMOOTH_EDGE  = (1 << 31)
};

#endif /* _OWN_BLDPCS */


/* /////////////////////////////////////////////////////////////////////////////
//
//  Name:        ippiMirror
//
//  Purpose:     ippiMirror mirrors the source image about a horizontal
//               or vertical or both together axes into resultant image
//
//  Context:
//
//  Returns:     IppStatus
//      ippStsNoErr,         if no errors
//      ippStsNullPtrErr,    if pSrc == NULL or pDst == NULL
//      ippStsStepErr,       if srcStep or dstStep is less or equal zero
//      ippStsSizeErr,       if width or height of images is less or equal zero
//      ippStsMirrorFlipErr, if (flip != ippAxsHorizontal) &&
//                              (flip != ippAxsVertical) &&
//                              (flip != ippAxsBoth)
//
//  Parameters:
//      pSrc     source image data
//      srcStep  step in src
//      pDst     resultant image data
//      dstStep  step in pDst
//      roiSize  region of interest
//      flip     specifies the axes to mirror the image:
//               ippAxsHorizontal for the horizontal axis,
//               ippAxsVertical   for a vertical axis,
//               ippAxsBoth       for both horizontal and vertical axes
//
//  Notes:
//
*/

IPPAPI(IppStatus, ippiMirror_8u_C1R, (const Ipp8u* pSrc, int srcStep, Ipp8u* pDst, int dstStep,
                                      IppiSize roiSize, IppiAxis flip))
IPPAPI(IppStatus, ippiMirror_8u_C3R, (const Ipp8u* pSrc, int srcStep, Ipp8u* pDst, int dstStep,
                                      IppiSize roiSize, IppiAxis flip))
IPPAPI(IppStatus, ippiMirror_8u_AC4R, (const Ipp8u* pSrc, int srcStep, Ipp8u* pDst, int dstStep,
                                       IppiSize roiSize, IppiAxis flip))
IPPAPI(IppStatus, ippiMirror_8u_C4R, (const Ipp8u* pSrc, int srcStep, Ipp8u* pDst, int dstStep,
                                                       IppiSize roiSize, IppiAxis flip))
IPPAPI(IppStatus, ippiMirror_8u_C1IR, (Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize, IppiAxis flip))
IPPAPI(IppStatus, ippiMirror_8u_C3IR, (Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize, IppiAxis flip))
IPPAPI(IppStatus, ippiMirror_8u_AC4IR, (Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize, IppiAxis flip))
IPPAPI(IppStatus, ippiMirror_8u_C4IR, (Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize, IppiAxis flip))

IPPAPI(IppStatus, ippiMirror_16u_C1R, (const Ipp16u* pSrc, int srcStep, Ipp16u* pDst, int dstStep,
                                       IppiSize roiSize, IppiAxis flip))
IPPAPI(IppStatus, ippiMirror_16u_C3R, (const Ipp16u* pSrc, int srcStep, Ipp16u* pDst, int dstStep,
                                       IppiSize roiSize, IppiAxis flip))
IPPAPI(IppStatus, ippiMirror_16u_AC4R, (const Ipp16u* pSrc, int srcStep, Ipp16u* pDst, int dstStep,
                                        IppiSize roiSize, IppiAxis flip))
IPPAPI(IppStatus, ippiMirror_16u_C4R, (const Ipp16u* pSrc, int srcStep, Ipp16u* pDst, int dstStep,
                                                        IppiSize roiSize, IppiAxis flip))
IPPAPI(IppStatus, ippiMirror_16u_C1IR, (Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize, IppiAxis flip))
IPPAPI(IppStatus, ippiMirror_16u_C3IR, (Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize, IppiAxis flip))
IPPAPI(IppStatus, ippiMirror_16u_AC4IR, (Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize, IppiAxis flip))
IPPAPI (IppStatus, ippiMirror_16u_C4IR, (Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize, IppiAxis flip))

IPPAPI(IppStatus, ippiMirror_32s_C1R, (const Ipp32s* pSrc, int srcStep, Ipp32s* pDst, int dstStep,
                                       IppiSize roiSize, IppiAxis flip))
IPPAPI(IppStatus, ippiMirror_32s_C3R, (const Ipp32s* pSrc, int srcStep, Ipp32s* pDst, int dstStep,
                                       IppiSize roiSize, IppiAxis flip))
IPPAPI(IppStatus, ippiMirror_32s_AC4R, (const Ipp32s* pSrc, int srcStep, Ipp32s* pDst, int dstStep,
                                        IppiSize roiSize, IppiAxis flip))
IPPAPI(IppStatus, ippiMirror_32s_C4R, (const Ipp32s* pSrc, int srcStep, Ipp32s* pDst, int dstStep,
                                                        IppiSize roiSize, IppiAxis flip ) )
IPPAPI(IppStatus, ippiMirror_32s_C1IR, (Ipp32s* pSrcDst, int srcDstStep, IppiSize roiSize, IppiAxis flip))
IPPAPI(IppStatus, ippiMirror_32s_C3IR, (Ipp32s* pSrcDst, int srcDstStep, IppiSize roiSize, IppiAxis flip))
IPPAPI(IppStatus, ippiMirror_32s_AC4IR, (Ipp32s* pSrcDst, int srcDstStep, IppiSize roiSize, IppiAxis flip))
IPPAPI(IppStatus, ippiMirror_32s_C4IR, (Ipp32s* pSrcDst, int srcDstStep, IppiSize roiSize, IppiAxis flip))




/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiRemap
//  Purpose:        Remap srcImage with map.
//                  dst[i,j] = src[xMap[i,j], yMap[i,j]]
//  Context:
//  Returns:             IppStatus
//    ippStsNoErr           Ok
//    ippStsNullPtrErr      Some of pointers to input or output data are NULL
//    ippStsSizeErr         The width or height of images is less or equal zero
//    ippStsInterpolateErr  The interpolation is bad
//
//  Parameters:
//    pSrc        The source image data pointer (point to pixel (0,0)).
//    srcSize     The size of Src image.
//    srcStep     The step in Src image
//    srcPlane    The size of plane of Src image
//    srcROI      The Region Of Interest of Src image.
//    pxMap       The pointer to image with x coords of map.
//    xMapStep    The step in xMap image
//    pyMap       The pointer to image with y coords of map.
//    yMapStep    The step in yMap image
//    pDst        The resultant image data pointer.
//    dstStep     The step in Dst image
//    dstPlane    The size of plane of Dst image
//    dstRoiSize  Size of ROI in the Dst image
//                interpolation The type of interpolation to perform for resampling
//                the input image. The following are currently supported.
//                IPPI_INTER_NN     Nearest Neighbour interpolation.
//                IPPI_INTER_LINEAR Linear interpolation.
//                IPPI_INTER_CUBIC  Cubic interpolation.
//  Notes:
*/

IPPAPI(IppStatus, ippiRemap_8u_C1R, (const Ipp8u* pSrc, IppiSize srcSize,
    int srcStep, IppiRect srcROI, const Ipp32f* pxMap, int xMapStep,
    const Ipp32f* pyMap, int yMapStep, Ipp8u* pDst, int dstStep,
    IppiSize dstRoiSize, int interpolation))

IPPAPI(IppStatus, ippiRemap_8u_C3R, (const Ipp8u* pSrc, IppiSize srcSize,
    int srcStep, IppiRect srcROI, const Ipp32f* pxMap, int xMapStep,
    const Ipp32f* pyMap, int yMapStep, Ipp8u* pDst, int dstStep,
    IppiSize dstRoiSize, int interpolation))

IPPAPI(IppStatus, ippiRemap_8u_AC4R, (const Ipp8u* pSrc, IppiSize srcSize,
    int srcStep, IppiRect srcROI, const Ipp32f* pxMap, int xMapStep,
    const Ipp32f* pyMap, int yMapStep, Ipp8u* pDst, int dstStep,
    IppiSize dstRoiSize, int interpolation))

IPPAPI(IppStatus, ippiRemap_8u_P3R, (const Ipp8u* const pSrc[3], IppiSize srcSize,
    int srcStep, IppiRect srcROI, const Ipp32f* pxMap, int xMapStep, const Ipp32f* pyMap,
    int yMapStep, Ipp8u* const pDst[3], int dstStep, IppiSize dstROI, int interpolation))

IPPAPI(IppStatus, ippiRemap_32f_C1R, (const Ipp32f* pSrc, IppiSize srcSize,
    int srcStep, IppiRect srcROI, const Ipp32f* pxMap, int xMapStep,
    const Ipp32f* pyMap, int yMapStep, Ipp32f* pDst, int dstStep,
    IppiSize dstRoiSize, int interpolation))

IPPAPI(IppStatus, ippiRemap_32f_C3R, (const Ipp32f* pSrc, IppiSize srcSize,
    int srcStep, IppiRect srcROI, const Ipp32f* pxMap, int xMapStep,
    const Ipp32f* pyMap, int yMapStep, Ipp32f* pDst, int dstStep,
    IppiSize dstRoiSize, int interpolation))

IPPAPI(IppStatus, ippiRemap_32f_AC4R, (const Ipp32f* pSrc, IppiSize srcSize,
    int srcStep, IppiRect srcROI, const Ipp32f* pxMap, int xMapStep,
    const Ipp32f* pyMap, int yMapStep, Ipp32f* pDst, int dstStep,
    IppiSize dstRoiSize, int interpolation))

IPPAPI(IppStatus, ippiRemap_32f_P3R, (const Ipp32f* const pSrc[3], IppiSize srcSize,
    int srcStep, IppiRect srcROI, const Ipp32f* pxMap, int xMapStep, const Ipp32f* pyMap,
    int yMapStep, Ipp32f* const pDst[3], int dstStep, IppiSize dstROI, int interpolation))

IPPAPI(IppStatus, ippiRemap_8u_C4R, (const Ipp8u* pSrc, IppiSize srcSize,
    int srcStep, IppiRect srcROI, const Ipp32f* pxMap, int xMapStep,
    const Ipp32f* pyMap, int yMapStep, Ipp8u* pDst, int dstStep,
    IppiSize dstRoiSize, int interpolation))

IPPAPI(IppStatus, ippiRemap_8u_P4R, (const Ipp8u* const pSrc[4], IppiSize srcSize,
    int srcStep, IppiRect srcROI, const Ipp32f* pxMap, int xMapStep, const Ipp32f* pyMap,
    int yMapStep, Ipp8u* const pDst[4], int dstStep, IppiSize dstROI, int interpolation))

IPPAPI(IppStatus, ippiRemap_32f_C4R, (const Ipp32f* pSrc, IppiSize srcSize,
    int srcStep, IppiRect srcROI, const Ipp32f* pxMap, int xMapStep,
    const Ipp32f* pyMap, int yMapStep, Ipp32f* pDst, int dstStep,
    IppiSize dstRoiSize, int interpolation))

IPPAPI(IppStatus, ippiRemap_32f_P4R, (const Ipp32f* const pSrc[4], IppiSize srcSize,
    int srcStep, IppiRect srcROI, const Ipp32f* pxMap, int xMapStep, const Ipp32f* pyMap,
    int yMapStep, Ipp32f* const pDst[4], int dstStep, IppiSize dstROI, int interpolation))


/* /////////////////////////////////////////////////////////////////////////////
//
//  Name:                ippiResize
//
//  Context:             Resizes a source image by xFactor and yFactor (not in-place)
//
//  Returns:             IppStatus
//      ippStsNoErr,            if no errors
//      ippStsNullPtrErr,       if pSrc == NULL or pDst == NULL
//      ippStsStepErr,          if srcStep or dstStep is less than or equal to zero
//      ippStsSizeErr,          if width or height of images is less than or equal to zero
//      ippStsResizeFactorErr,  if xFactor or yFactor is less than or equal to zero
//      ippStsInterpolationErr, if (interpolation != IPPI_INTER_NN) &&
//                                 (interpolation != IPPI_INTER_LINEAR) &&
//                                 (interpolation != IPPI_INTER_CUBIC) &&
//                                 (interpolation != IPPI_INTER_SUPER)
//  Parameters:
//      pSrc             pointer to the source image
//      srcSize          size of the source image
//      srcStep          step in bytes through the source image
//      srcROI           region of interest of the source image
//      pDst             pointer to the destination image
//      dstStep          step in bytes through the destination image
//      dstRoiSize       region of interest of the destination image
//      xFactor, yFactor factors by which the x and y dimensions are changed
//      interpolation    type of interpolation to perform for image resampling:
//                        IPPI_INTER_NN      nearest neighbour interpolation
//                        IPPI_INTER_LINEAR  linear interpolation
//                        IPPI_INTER_CUBIC   cubic convolution interpolation
//                        IPPI_INTER_SUPER   supersampling interpolation
//
//  Notes:
//
*/

IPPAPI(IppStatus, ippiResize_8u_C1R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI,
                                      Ipp8u* pDst, int dstStep, IppiSize dstRoiSize,
                                      double xFactor, double yFactor, int interpolation))

IPPAPI(IppStatus, ippiResize_8u_C3R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI,
                                      Ipp8u* pDst, int dstStep, IppiSize dstRoiSize,
                                      double xFactor, double yFactor, int interpolation))

IPPAPI(IppStatus, ippiResize_8u_C4R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI,
                                      Ipp8u* pDst, int dstStep, IppiSize dstRoiSize,
                                      double xFactor, double yFactor, int interpolation))

IPPAPI(IppStatus, ippiResize_8u_AC4R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI,
                                      Ipp8u* pDst, int dstStep, IppiSize dstRoiSize,
                                      double xFactor, double yFactor, int interpolation))

IPPAPI(IppStatus, ippiResize_8u_P3R, (const Ipp8u* const pSrc[3], IppiSize srcSize, int srcStep, IppiRect srcROI,
                                      Ipp8u* const pDst[3], int dstStep, IppiSize dstRoiSize,
                                      double xFactor, double yFactor, int interpolation))

IPPAPI(IppStatus, ippiResize_8u_P4R, (const Ipp8u* const pSrc[4], IppiSize srcSize, int srcStep, IppiRect srcROI,
                                      Ipp8u* const pDst[4], int dstStep, IppiSize dstRoiSize,
                                      double xFactor, double yFactor, int interpolation))

IPPAPI(IppStatus, ippiResize_16u_C1R, (const Ipp16u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI,
                                      Ipp16u* pDst, int dstStep, IppiSize dstRoiSize,
                                      double xFactor, double yFactor, int interpolation))

IPPAPI(IppStatus, ippiResize_16u_C3R, (const Ipp16u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI,
                                      Ipp16u* pDst, int dstStep, IppiSize dstRoiSize,
                                      double xFactor, double yFactor, int interpolation))

IPPAPI(IppStatus, ippiResize_16u_C4R, (const Ipp16u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI,
                                      Ipp16u* pDst, int dstStep, IppiSize dstRoiSize,
                                      double xFactor, double yFactor, int interpolation))

IPPAPI(IppStatus, ippiResize_16u_AC4R, (const Ipp16u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI,
                                      Ipp16u* pDst, int dstStep, IppiSize dstRoiSize,
                                      double xFactor, double yFactor, int interpolation))

IPPAPI(IppStatus, ippiResize_16u_P3R, (const Ipp16u* const pSrc[3], IppiSize srcSize, int srcStep, IppiRect srcROI,
                                      Ipp16u* const pDst[3], int dstStep, IppiSize dstRoiSize,
                                      double xFactor, double yFactor, int interpolation))

IPPAPI(IppStatus, ippiResize_16u_P4R, (const Ipp16u* const pSrc[4], IppiSize srcSize, int srcStep, IppiRect srcROI,
                                      Ipp16u* const pDst[4], int dstStep, IppiSize dstRoiSize,
                                      double xFactor, double yFactor, int interpolation))

IPPAPI(IppStatus, ippiResize_32f_C1R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI,
                                      Ipp32f* pDst, int dstStep, IppiSize dstRoiSize,
                                      double xFactor, double yFactor, int interpolation))

IPPAPI(IppStatus, ippiResize_32f_C3R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI,
                                      Ipp32f* pDst, int dstStep, IppiSize dstRoiSize,
                                      double xFactor, double yFactor, int interpolation))

IPPAPI(IppStatus, ippiResize_32f_C4R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI,
                                      Ipp32f* pDst, int dstStep, IppiSize dstRoiSize,
                                      double xFactor, double yFactor, int interpolation))

IPPAPI(IppStatus, ippiResize_32f_AC4R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI,
                                      Ipp32f* pDst, int dstStep, IppiSize dstRoiSize,
                                      double xFactor, double yFactor, int interpolation))

IPPAPI(IppStatus, ippiResize_32f_P3R, (const Ipp32f* const pSrc[3], IppiSize srcSize, int srcStep, IppiRect srcROI,
                                      Ipp32f* const pDst[3], int dstStep, IppiSize dstRoiSize,
                                      double xFactor, double yFactor, int interpolation))

IPPAPI(IppStatus, ippiResize_32f_P4R, (const Ipp32f* const pSrc[4], IppiSize srcSize, int srcStep, IppiRect srcROI,
                                      Ipp32f* const pDst[4], int dstStep, IppiSize dstRoiSize,
                                      double xFactor, double yFactor, int interpolation))


/* /////////////////////////////////////////////////////////////////////////////
//
//  Name:                ippiResizeCenter
//
//  Purpose:             Resizes a source image by xFactor and yFactor
//                       and shifts the destination image relative to the specified
//                       point with coordinates xCenter and yCenter  (not in-place)
//
//  Returns:             IppStatus
//      ippStsNoErr,            if no errors
//      ippStsNullPtrErr,       if pSrc == NULL or pDst == NULL
//      ippStsStepErr,          if srcStep or dstStep is less than or equal to zero
//      ippStsSizeErr,          if width or height of images is less than or equal to zero
//      ippStsResizeFactorErr,  if xFactor or yFactor is less than or equal to zero
//      ippStsInterpolationErr, if (interpolation != IPPI_INTER_NN) &&
//                                 (interpolation != IPPI_INTER_LINEAR) &&
//                                 (interpolation != IPPI_INTER_CUBIC) &&
//                                 (interpolation != IPPI_INTER_SUPER)
//  Parameters:
//      pSrc             pointer to the source image
//      srcSize          size of the source image
//      srcStep          step in bytes through the source image
//      srcROI           region of interest of the source image
//      pDst             pointer to the destination image
//      dstStep          step in bytes through the destination image
//      dstRoiSize       region of interest of the destination image
//      xFactor, yFactor factors by which the x and y dimensions are changed
//      xCenter, yCenter coordinates of the point that isn't shifted after image tesizing
//      interpolation    type of interpolation to perform for resampling the input image:
//                        IPPI_INTER_NN      nearest neighbour interpolation
//                        IPPI_INTER_LINEAR  linear interpolation
//                        IPPI_INTER_CUBIC   cubic convolution interpolation
//                        IPPI_INTER_SUPER   supersampling interpolation
//
//  Notes:
//
*/

IPPAPI(IppStatus, ippiResizeCenter_8u_C1R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI,
                                            Ipp8u* pDst, int dstStep, IppiSize dstRoiSize,
                                            double xFactor, double yFactor,
                                            double xCenter, double yCenter, int interpolation))

IPPAPI(IppStatus, ippiResizeCenter_8u_C3R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI,
                                            Ipp8u* pDst, int dstStep, IppiSize dstRoiSize,
                                            double xFactor, double yFactor,
                                            double xCenter, double yCenter, int interpolation))

IPPAPI(IppStatus, ippiResizeCenter_8u_C4R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI,
                                            Ipp8u* pDst, int dstStep, IppiSize dstRoiSize,
                                            double xFactor, double yFactor,
                                            double xCenter, double yCenter, int interpolation))

IPPAPI(IppStatus, ippiResizeCenter_8u_AC4R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI,
                                            Ipp8u* pDst, int dstStep, IppiSize dstRoiSize,
                                            double xFactor, double yFactor,
                                            double xCenter, double yCenter, int interpolation))

IPPAPI(IppStatus, ippiResizeCenter_8u_P3R, (const Ipp8u* const pSrc[3], IppiSize srcSize, int srcStep, IppiRect srcROI,
                                            Ipp8u* const pDst[3], int dstStep, IppiSize dstRoiSize,
                                            double xFactor, double yFactor,
                                            double xCenter, double yCenter, int interpolation))

IPPAPI(IppStatus, ippiResizeCenter_8u_P4R, (const Ipp8u* const pSrc[4], IppiSize srcSize, int srcStep, IppiRect srcROI,
                                            Ipp8u* const pDst[4], int dstStep, IppiSize dstRoiSize,
                                            double xFactor, double yFactor,
                                            double xCenter, double yCenter, int interpolation))

IPPAPI(IppStatus, ippiResizeCenter_16u_C1R, (const Ipp16u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI,
                                            Ipp16u* pDst, int dstStep, IppiSize dstRoiSize,
                                            double xFactor, double yFactor,
                                            double xCenter, double yCenter, int interpolation))

IPPAPI(IppStatus, ippiResizeCenter_16u_C3R, (const Ipp16u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI,
                                            Ipp16u* pDst, int dstStep, IppiSize dstRoiSize,
                                            double xFactor, double yFactor,
                                            double xCenter, double yCenter, int interpolation))

IPPAPI(IppStatus, ippiResizeCenter_16u_C4R, (const Ipp16u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI,
                                            Ipp16u* pDst, int dstStep, IppiSize dstRoiSize,
                                            double xFactor, double yFactor,
                                            double xCenter, double yCenter, int interpolation))

IPPAPI(IppStatus, ippiResizeCenter_16u_AC4R, (const Ipp16u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI,
                                            Ipp16u* pDst, int dstStep, IppiSize dstRoiSize,
                                            double xFactor, double yFactor,
                                            double xCenter, double yCenter, int interpolation))

IPPAPI(IppStatus, ippiResizeCenter_16u_P3R, (const Ipp16u* const pSrc[3], IppiSize srcSize, int srcStep, IppiRect srcROI,
                                            Ipp16u* const pDst[3], int dstStep, IppiSize dstRoiSize,
                                            double xFactor, double yFactor,
                                            double xCenter, double yCenter, int interpolation))

IPPAPI(IppStatus, ippiResizeCenter_16u_P4R, (const Ipp16u* const pSrc[4], IppiSize srcSize, int srcStep, IppiRect srcROI,
                                            Ipp16u* const pDst[4], int dstStep, IppiSize dstRoiSize,
                                            double xFactor, double yFactor,
                                            double xCenter, double yCenter, int interpolation))

IPPAPI(IppStatus, ippiResizeCenter_32f_C1R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI,
                                            Ipp32f* pDst, int dstStep, IppiSize dstRoiSize,
                                            double xFactor, double yFactor,
                                            double xCenter, double yCenter, int interpolation))

IPPAPI(IppStatus, ippiResizeCenter_32f_C3R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI,
                                            Ipp32f* pDst, int dstStep, IppiSize dstRoiSize,
                                            double xFactor, double yFactor,
                                            double xCenter, double yCenter, int interpolation))

IPPAPI(IppStatus, ippiResizeCenter_32f_C4R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI,
                                            Ipp32f* pDst, int dstStep, IppiSize dstRoiSize,
                                            double xFactor, double yFactor,
                                            double xCenter, double yCenter, int interpolation))

IPPAPI(IppStatus, ippiResizeCenter_32f_AC4R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI,
                                            Ipp32f* pDst, int dstStep, IppiSize dstRoiSize,
                                            double xFactor, double yFactor,
                                            double xCenter, double yCenter, int interpolation))

IPPAPI(IppStatus, ippiResizeCenter_32f_P3R, (const Ipp32f* const pSrc[3], IppiSize srcSize, int srcStep, IppiRect srcROI,
                                            Ipp32f* const pDst[3], int dstStep, IppiSize dstRoiSize,
                                            double xFactor, double yFactor,
                                            double xCenter, double yCenter, int interpolation))

IPPAPI(IppStatus, ippiResizeCenter_32f_P4R, (const Ipp32f* const pSrc[4], IppiSize srcSize, int srcStep, IppiRect srcROI,
                                            Ipp32f* const pDst[4], int dstStep, IppiSize dstRoiSize,
                                            double xFactor, double yFactor,
                                            double xCenter, double yCenter, int interpolation))


/* /////////////////////////////////////////////////////////////////////////////
//
//  Name:                ippiGetResizeFract
//
//  Context:             Recalculate resize factors for tiled image processing
//
//  Returns:             IppStatus
//      ippStsNoErr,            if no errors
//      ippStsSizeErr,          if width or height of images is less than or equal to zero
//      ippStsResizeFactorErr,  if xFactor or yFactor is less or equal zero
//      ippStsInterpolationErr, if (interpolation != IPPI_INTER_NN) &&
//                                 (interpolation != IPPI_INTER_LINEAR) &&
//                                 (interpolation != IPPI_INTER_CUBIC)
//  Parameters:
//      srcSize          size of the source image
//      srcROI           region of interest of the source image
//      xFactor, yFactor factors by which the x and y dimensions are changed
//      xFr, yFr         pointers to the recalculated resize factors
//      interpolation    type of interpolation to perform for resampling the input image:
//                        IPPI_INTER_NN      nearest neighbour interpolation
//                        IPPI_INTER_LINEAR  linear interpolation
//                        IPPI_INTER_CUBIC   cubic convolution interpolation
// Notes:
*/

IPPAPI(IppStatus, ippiGetResizeFract, (IppiSize srcSize, IppiRect srcROI, double xFactor, double yFactor,
                                       double* xFr, double* yFr, int interpolation))


/* /////////////////////////////////////////////////////////////////////////////
//
//  Name:                ippiResizeShift
//
//  Context:             Resize an image tile by xFactor and yFactor
//
//  Returns:             IppStatus
//      ippStsNoErr,            if no errors
//      ippStsNullPtrErr,       if pSrc == NULL or pDst == NULL
//      ippStsStepErr,          if srcStep or dstStep is less than or equal to zero
//      ippStsSizeErr,          if width or height of images is less than or equal to zero
//      ippStsResizeFactorErr,  if xFactor or yFactor is less or equal zero
//      ippStsInterpolationErr, if (interpolation != IPPI_INTER_NN) &&
//                                 (interpolation != IPPI_INTER_LINEAR) &&
//                                 (interpolation != IPPI_INTER_CUBIC)
//  Parameters:
//      pSrc             pointer to the source image
//      srcSize          size of the source image
//      srcStep          step in bytes through the source image
//      srcROI           region of interest of the source image
//      pDst             pointer to the destination image
//      dstStep          step in bytes through the destination image
//      dstROI           region of interest of the destination image
//      xFr, yFr         factors by which the x and y dimensions are changed
//      xShift, yShift   offsets(double) for processing area
//      interpolation    type of interpolation to perform for image resampling:
//                        IPPI_INTER_NN      nearest neighbour interpolation
//                        IPPI_INTER_LINEAR  linear interpolation
//                        IPPI_INTER_CUBIC   cubic convolution interpolation
// Notes:
//  - not in-place
//  - without supersampling interpolation
*/

IPPAPI(IppStatus, ippiResizeShift_8u_C1R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI,
                                       Ipp8u* pDst, int dstStep, IppiSize dstRoiSize,
                                       double xFr, double yFr, double xShift, double yShift, int interpolation))

IPPAPI(IppStatus, ippiResizeShift_8u_C3R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI,
                                       Ipp8u* pDst, int dstStep, IppiSize dstRoiSize,
                                       double xFr, double yFr, double xShift, double yShift, int interpolation))

IPPAPI(IppStatus, ippiResizeShift_8u_C4R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI,
                                       Ipp8u* pDst, int dstStep, IppiSize dstRoiSize,
                                       double xFr, double yFr, double xShift, double yShift, int interpolation))

IPPAPI(IppStatus, ippiResizeShift_8u_AC4R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI,
                                       Ipp8u* pDst, int dstStep, IppiSize dstRoiSize,
                                       double xFr, double yFr, double xShift, double yShift, int interpolation))

IPPAPI(IppStatus, ippiResizeShift_8u_P3R, (const Ipp8u* const pSrc[3], IppiSize srcSize, int srcStep, IppiRect srcROI,
                                       Ipp8u* const pDst[3], int dstStep, IppiSize dstRoiSize,
                                       double xFr, double yFr, double xShift, double yShift, int interpolation))

IPPAPI(IppStatus, ippiResizeShift_8u_P4R, (const Ipp8u* const pSrc[4], IppiSize srcSize, int srcStep, IppiRect srcROI,
                                       Ipp8u* const pDst[4], int dstStep, IppiSize dstRoiSize,
                                       double xFr, double yFr, double xShift, double yShift, int interpolation))

IPPAPI(IppStatus, ippiResizeShift_16u_C1R, (const Ipp16u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI,
                                       Ipp16u* pDst, int dstStep, IppiSize dstRoiSize,
                                       double xFr, double yFr, double xShift, double yShift, int interpolation))

IPPAPI(IppStatus, ippiResizeShift_16u_C3R, (const Ipp16u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI,
                                       Ipp16u* pDst, int dstStep, IppiSize dstRoiSize,
                                       double xFr, double yFr, double xShift, double yShift, int interpolation))

IPPAPI(IppStatus, ippiResizeShift_16u_C4R, (const Ipp16u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI,
                                       Ipp16u* pDst, int dstStep, IppiSize dstRoiSize,
                                       double xFr, double yFr, double xShift, double yShift, int interpolation))

IPPAPI(IppStatus, ippiResizeShift_16u_AC4R, (const Ipp16u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI,
                                       Ipp16u* pDst, int dstStep, IppiSize dstRoiSize,
                                       double xFr, double yFr, double xShift, double yShift, int interpolation))

IPPAPI(IppStatus, ippiResizeShift_16u_P3R, (const Ipp16u* const pSrc[3], IppiSize srcSize, int srcStep, IppiRect srcROI,
                                       Ipp16u* const pDst[3], int dstStep, IppiSize dstRoiSize,
                                       double xFr, double yFr, double xShift, double yShift, int interpolation))

IPPAPI(IppStatus, ippiResizeShift_16u_P4R, (const Ipp16u* const pSrc[4], IppiSize srcSize, int srcStep, IppiRect srcROI,
                                       Ipp16u* const pDst[4], int dstStep, IppiSize dstRoiSize,
                                       double xFr, double yFr, double xShift, double yShift, int interpolation))

IPPAPI(IppStatus, ippiResizeShift_32f_C1R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI,
                                       Ipp32f* pDst, int dstStep, IppiSize dstRoiSize,
                                       double xFr, double yFr, double xShift, double yShift, int interpolation))

IPPAPI(IppStatus, ippiResizeShift_32f_C3R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI,
                                       Ipp32f* pDst, int dstStep, IppiSize dstRoiSize,
                                       double xFr, double yFr, double xShift, double yShift, int interpolation))

IPPAPI(IppStatus, ippiResizeShift_32f_C4R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI,
                                       Ipp32f* pDst, int dstStep, IppiSize dstRoiSize,
                                       double xFr, double yFr, double xShift, double yShift, int interpolation))

IPPAPI(IppStatus, ippiResizeShift_32f_AC4R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI,
                                       Ipp32f* pDst, int dstStep, IppiSize dstRoiSize,
                                       double xFr, double yFr, double xShift, double yShift, int interpolation))

IPPAPI(IppStatus, ippiResizeShift_32f_P3R, (const Ipp32f* const pSrc[3], IppiSize srcSize, int srcStep, IppiRect srcROI,
                                       Ipp32f* const pDst[3], int dstStep, IppiSize dstRoiSize,
                                       double xFr, double yFr, double xShift, double yShift, int interpolation))

IPPAPI(IppStatus, ippiResizeShift_32f_P4R, (const Ipp32f* const pSrc[4], IppiSize srcSize, int srcStep, IppiRect srcROI,
                                       Ipp32f* const pDst[4], int dstStep, IppiSize dstRoiSize,
                                       double xFr, double yFr, double xShift, double yShift, int interpolation))



/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiGetAffineBound
//  Purpose:        calculates bounding rectangle of the transformed image ROI.
//  Context:
//  Returns:        IppStatus
//    ippStsNoErr   Ok
//  Parameters:
//      roi         The image roi.
//      coeffs      The transform matrix
//                  |X'|   |a11 a12| |X| |a13|
//                  |  | = |       |*| |+|   |
//                  |Y'|   |a21 a22| |Y| |a23|
//      bound       resultant bounding rectangle
//  Notes:
*/

IPPAPI(IppStatus, ippiGetAffineBound, (IppiRect roi, double bound[2][2], const double coeffs[2][3]))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiGetAffineQuad
//  Purpose:        calculates coordinates of quadrangle from transformed image ROI.
//  Context:
//  Returns:        IppStatus.
//    ippStsNoErr   Ok
//  Parameters:
//      roi         The image roi.
//      coeffs      The transform matrix
//                  |X'|   |a11 a12| |X| |a13|
//                  |  | = |       |*| |+|   |
//                  |Y'|   |a21 a22| |Y| |a23|
//      quadr       resultant quadrangle
//  Notes:
*/

IPPAPI(IppStatus, ippiGetAffineQuad, (IppiRect roi, double quad[4][2], const double coeffs[2][3]))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiGetAffineTransform
//  Purpose:        calculates transform matrix from vertexes of quadrangle.
//  Context:
//  Returns:        IppStatus.
//    ippStsNoErr   Ok
//  Parameters:
//      roi         The image roi.
//      coeffs      The resultant transform matrix
//                  |X'|   |a11 a12| |X| |a13|
//                  |  | = |       |*| |+|   |
//                  |Y'|   |a21 a22| |Y| |a23|
//      quad        quadrangle
//  Notes:
*/

IPPAPI(IppStatus, ippiGetAffineTransform, (IppiRect roi, const double quad[4][2], double coeffs[2][3]))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiWarpAffine
//  Purpose:        makes Affine transform of image.
//                  |X'|   |a11 a12| |X| |a13|
//                  |  | = |       |*| |+|   |
//                  |Y'|   |a21 a22| |Y| |a23|
//  Context:
//  Returns:                IppStatus
//    ippStsNoErr           Ok
//    ippStsNullPtrErr      Some of pointers to input or output data are NULL
//    ippStsSizeErr         The width or height of images is less or equal zero
//    ippStsInterpolateErr  The interpolation is bad
//  Parameters:
//      pSrc        The source image data (point to pixel (0,0)).
//      srcSize     The size of src.
//      srcStep     The step in src
//      srcROI      The Region Of Interest of src.
//      pDst        The resultant image data (point to pixel (0,0)).
//      dstStep     The step in dst
//      dstROI      The Region Of Interest of dst.
//      coeffs      The transform matrix
//      interpolate The type of interpolation to perform for resampling
//                  the input image. The following are currently supported.
//                  IPPI_INTER_NN       Nearest neighbour interpolation.
//                  IPPI_INTER_LINEAR   Linear interpolation.
//                  IPPI_INTER_CUBIC    Cubic convolution interpolation.
//                 +IPPI_SMOOTH_EDGE    smoothed edges
//  Notes:
*/

IPPAPI(IppStatus, ippiWarpAffine_8u_C1R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* pDst, int dstStep, IppiRect dstROI, const double coeffs[2][3], int interpolation))
IPPAPI(IppStatus, ippiWarpAffine_8u_C3R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* pDst, int dstStep, IppiRect dstROI, const double coeffs[2][3], int interpolation))
IPPAPI(IppStatus, ippiWarpAffine_8u_AC4R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* pDst, int dstStep, IppiRect dstROI, const double coeffs[2][3], int interpolation))
IPPAPI(IppStatus, ippiWarpAffine_8u_P3R, (const Ipp8u* const pSrc[3], IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* const pDst[3], int dstStep, IppiRect dstROI, const double coeffs[2][3], int interpolation))
IPPAPI(IppStatus, ippiWarpAffine_32f_C1R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* pDst, int dstStep, IppiRect dstROI, const double coeffs[2][3], int interpolation))
IPPAPI(IppStatus, ippiWarpAffine_32f_C3R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* pDst, int dstStep, IppiRect dstROI, const double coeffs[2][3], int interpolation))
IPPAPI(IppStatus, ippiWarpAffine_32f_AC4R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* pDst, int dstStep, IppiRect dstROI, const double coeffs[2][3], int interpolation))
IPPAPI(IppStatus, ippiWarpAffine_32f_P3R, (const Ipp32f* const pSrc[3], IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* const pDst[3], int dstStep, IppiRect dstROI, const double coeffs[2][3], int interpolation))
IPPAPI(IppStatus, ippiWarpAffine_8u_C4R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* pDst, int dstStep, IppiRect dstROI, const double coeffs[2][3], int interpolation))
IPPAPI(IppStatus, ippiWarpAffine_8u_P4R, (const Ipp8u* const pSrc[4], IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* const pDst[4], int dstStep, IppiRect dstROI, const double coeffs[2][3], int interpolation))
IPPAPI(IppStatus, ippiWarpAffine_32f_C4R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* pDst, int dstStep, IppiRect dstROI, const double coeffs[2][3], int interpolation))
IPPAPI(IppStatus, ippiWarpAffine_32f_P4R, (const Ipp32f* const pSrc[4], IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* const pDst[4], int dstStep, IppiRect dstROI, const double coeffs[2][3], int interpolation))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiWarpAffineBack
//  Purpose:        makes Back Affine transform of image.
//                  |X'|   |a11 a12| |X| |a13|
//                  |  | = |       |*| |+|   |
//                  |Y'|   |a21 a22| |Y| |a23|
//  Context:
//  Returns:                IppStatus
//    ippStsNoErr           Ok
//    ippStsNullPtrErr      Some of pointers to input or output data are NULL
//    ippStsSizeErr         The width or height of images is less or equal zero
//    ippStsInterpolateErr  The interpolation is bad
//  Parameters:
//      pSrc        The source image data (point to pixel (0,0)).
//      srcSize     The size of src.
//      srcStep     The step in src
//      srcROI      The Region Of Interest of src.
//      pDst        The resultant image data (point to pixel (0,0)).
//      dstStep     The step in dst
//      dstROI      The Region Of Interest of dst.
//      coeffs      The transform matrix
//      interpolate The type of interpolation to perform for resampling
//                  the input image. The following are currently supported.
//                  IPPI_INTER_NN       Nearest neighbour interpolation.
//                  IPPI_INTER_LINEAR   Linear interpolation.
//                  IPPI_INTER_CUBIC    Cubic convolution interpolation.
//  Notes:
*/

IPPAPI(IppStatus, ippiWarpAffineBack_8u_C1R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* pDst, int dstStep, IppiRect dstROI, const double coeffs[2][3], int interpolation))
IPPAPI(IppStatus, ippiWarpAffineBack_8u_C3R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* pDst, int dstStep, IppiRect dstROI, const double coeffs[2][3], int interpolation))
IPPAPI(IppStatus, ippiWarpAffineBack_8u_AC4R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* pDst, int dstStep, IppiRect dstROI, const double coeffs[2][3], int interpolation))
IPPAPI(IppStatus, ippiWarpAffineBack_8u_P3R, (const Ipp8u* const pSrc[3], IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* const pDst[3], int dstStep, IppiRect dstROI, const double coeffs[2][3], int interpolation))
IPPAPI(IppStatus, ippiWarpAffineBack_32f_C1R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* pDst, int dstStep, IppiRect dstROI, const double coeffs[2][3], int interpolation))
IPPAPI(IppStatus, ippiWarpAffineBack_32f_C3R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* pDst, int dstStep, IppiRect dstROI, const double coeffs[2][3], int interpolation))
IPPAPI(IppStatus, ippiWarpAffineBack_32f_AC4R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* pDst, int dstStep, IppiRect dstROI, const double coeffs[2][3], int interpolation))
IPPAPI(IppStatus, ippiWarpAffineBack_32f_P3R, (const Ipp32f* const pSrc[3], IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* const pDst[3], int dstStep, IppiRect dstROI, const double coeffs[2][3], int interpolation))
IPPAPI(IppStatus, ippiWarpAffineBack_8u_C4R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* pDst, int dstStep, IppiRect dstROI, const double coeffs[2][3], int interpolation))
IPPAPI(IppStatus, ippiWarpAffineBack_8u_P4R, (const Ipp8u* const pSrc[4], IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* const pDst[4], int dstStep, IppiRect dstROI, const double coeffs[2][3], int interpolation))
IPPAPI(IppStatus, ippiWarpAffineBack_32f_C4R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* pDst, int dstStep, IppiRect dstROI, const double coeffs[2][3], int interpolation))
IPPAPI(IppStatus, ippiWarpAffineBack_32f_P4R, (const Ipp32f* const pSrc[4], IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* const pDst[4], int dstStep, IppiRect dstROI, const double coeffs[2][3], int interpolation))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiWarpAffineQuad
//  Purpose:        makes Affine transform of image from srcQuad to dstQuad.
//                  |X'|   |a11 a12| |X| |a13|
//                  |  | = |       |*| |+|   |
//                  |Y'|   |a21 a22| |Y| |a23|
//  Context:
//  Returns:                IppStatus
//    ippStsNoErr           Ok
//    ippStsNullPtrErr      Some of pointers to input or output data are NULL
//    ippStsSizeErr         The width or height of images is less or equal zero
//    ippStsInterpolateErr  The interpolation is bad
//  Parameters:
//      pSrc        The source image data (point to pixel (0,0)).
//      srcSize     The size of src.
//      srcStep     The step in src
//      srcROI      The Region Of Interest of src.
//      srcQuad     The Quadrangle in src
//      pDst        The resultant image data (point to pixel (0,0)).
//      dstStep     The step in dst
//      dstROI      The Region Of Interest of dst.
//      dstQuad     The Quadrangle in dst
//      interpolate The type of interpolation to perform for resampling
//                  the input image. The following are currently supported.
//                  IPPI_INTER_NN       Nearest neighbour interpolation.
//                  IPPI_INTER_LINEAR   Linear interpolation.
//                  IPPI_INTER_CUBIC    Cubic convolution interpolation.
//                 +IPPI_SMOOTH_EDGE    smoothed edges
//  Notes:
*/

IPPAPI(IppStatus, ippiWarpAffineQuad_8u_C1R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, const double srcQuad[4][2], Ipp8u* pDst, int dstStep, IppiRect dstROI, const double dstQuad[4][2], int interpolation))
IPPAPI(IppStatus, ippiWarpAffineQuad_8u_C3R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, const double srcQuad[4][2], Ipp8u* pDst, int dstStep, IppiRect dstROI, const double dstQuad[4][2], int interpolation))
IPPAPI(IppStatus, ippiWarpAffineQuad_8u_AC4R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, const double srcQuad[4][2], Ipp8u* pDst, int dstStep, IppiRect dstROI, const double dstQuad[4][2], int interpolation))
IPPAPI(IppStatus, ippiWarpAffineQuad_8u_P3R, (const Ipp8u* const pSrc[3], IppiSize srcSize, int srcStep, IppiRect srcROI, const double srcQuad[4][2], Ipp8u* const pDst[3], int dstStep, IppiRect dstROI, const double dstQuad[4][2], int interpolation))
IPPAPI(IppStatus, ippiWarpAffineQuad_32f_C1R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, const double srcQuad[4][2], Ipp32f* pDst, int dstStep, IppiRect dstROI, const double dstQuad[4][2], int interpolation))
IPPAPI(IppStatus, ippiWarpAffineQuad_32f_C3R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, const double srcQuad[4][2], Ipp32f* pDst, int dstStep, IppiRect dstROI, const double dstQuad[4][2], int interpolation))
IPPAPI(IppStatus, ippiWarpAffineQuad_32f_AC4R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, const double srcQuad[4][2], Ipp32f* pDst, int dstStep, IppiRect dstROI, const double dstQuad[4][2], int interpolation))
IPPAPI(IppStatus, ippiWarpAffineQuad_32f_P3R, (const Ipp32f* const pSrc[3], IppiSize srcSize, int srcStep, IppiRect srcROI, const double srcQuad[4][2], Ipp32f* const pDst[3], int dstStep, IppiRect dstROI, const double dstQuad[4][2], int interpolation))
IPPAPI(IppStatus, ippiWarpAffineQuad_8u_C4R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, const double srcQuad[4][2], Ipp8u* pDst, int dstStep, IppiRect dstROI, const double dstQuad[4][2], int interpolation))
IPPAPI(IppStatus, ippiWarpAffineQuad_8u_P4R, (const Ipp8u* const pSrc[4], IppiSize srcSize, int srcStep, IppiRect srcROI, const double srcQuad[4][2], Ipp8u* const pDst[4], int dstStep, IppiRect dstROI, const double dstQuad[4][2], int interpolation))
IPPAPI(IppStatus, ippiWarpAffineQuad_32f_C4R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, const double srcQuad[4][2], Ipp32f* pDst, int dstStep, IppiRect dstROI, const double dstQuad[4][2], int interpolation))
IPPAPI(IppStatus, ippiWarpAffineQuad_32f_P4R, (const Ipp32f* const pSrc[4], IppiSize srcSize, int srcStep, IppiRect srcROI, const double srcQuad[4][2], Ipp32f* const pDst[4], int dstStep, IppiRect dstROI, const double dstQuad[4][2], int interpolation))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiRotate
//  Purpose:        rotates an image around (0, 0) by specified angle + shifts it.
//  Context:
//  Returns:        IppStatus
//    ippStsNoErr           Ok
//    ippStsNullPtrErr      At least one pointer is NULL
//    ippStsSizeErr         The width or height of images is less than or equal to zero
//    ippStsInterpolateErr  The interpolation has an illegal value
//  Parameters:
//      pSrc        Pointer to the source image origin (0,0).
//      srcSize     The size of the source image.
//      srcStep     The step in bytes through the source image.
//      srcROI      The Region Of Interest of the source image.
//      pDst        Pointer to the destination image origin (0,0).
//      dstStep     The step in bytes through the destination image.
//      dstROI      The Region Of Interest of the destination image.
//      angle       The angle of rotation in degrees
//      xShift      The shift along x direction
//      yShift      The shift along y direction
//      interpolate The type of interpolation to perform for resampling
//                  the input image. The following types are currently supported:
//                  IPPI_INTER_NN       Nearest neighbour interpolation.
//                  IPPI_INTER_LINEAR   Linear interpolation.
//                  IPPI_INTER_CUBIC    Cubic convolution interpolation.
//                 +IPPI_SMOOTH_EDGE    edge smoothing (addition to one of the above types)
//  Notes:
*/

IPPAPI(IppStatus, ippiRotate_8u_C1R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* pDst, int dstStep, IppiRect dstROI, double angle, double xShift, double yShift, int interpolation))
IPPAPI(IppStatus, ippiRotate_8u_C3R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* pDst, int dstStep, IppiRect dstROI, double angle, double xShift, double yShift, int interpolation))
IPPAPI(IppStatus, ippiRotate_8u_AC4R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* pDst, int dstStep, IppiRect dstROI, double angle, double xShift, double yShift, int interpolation))
IPPAPI(IppStatus, ippiRotate_8u_P3R, (const Ipp8u* const pSrc[3], IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* const pDst[3], int dstStep, IppiRect dstROI, double angle, double xShift, double yShift, int interpolation))
IPPAPI(IppStatus, ippiRotate_8u_C4R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* pDst, int dstStep, IppiRect dstROI, double angle, double xShift, double yShift, int interpolation))
IPPAPI(IppStatus, ippiRotate_8u_P4R, (const Ipp8u* const pSrc[4], IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* const pDst[4], int dstStep, IppiRect dstROI, double angle, double xShift, double yShift, int interpolation))
IPPAPI(IppStatus, ippiRotate_32f_C1R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* pDst, int dstStep, IppiRect dstROI, double angle, double xShift, double yShift, int interpolation))
IPPAPI(IppStatus, ippiRotate_32f_C3R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* pDst, int dstStep, IppiRect dstROI, double angle, double xShift, double yShift, int interpolation))
IPPAPI(IppStatus, ippiRotate_32f_AC4R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* pDst, int dstStep, IppiRect dstROI, double angle, double xShift, double yShift, int interpolation))
IPPAPI(IppStatus, ippiRotate_32f_P3R, (const Ipp32f* const pSrc[3], IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* const pDst[3], int dstStep, IppiRect dstROI, double angle, double xShift, double yShift, int interpolation))
IPPAPI(IppStatus, ippiRotate_32f_C4R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* pDst, int dstStep, IppiRect dstROI, double angle, double xShift, double yShift, int interpolation))
IPPAPI(IppStatus, ippiRotate_32f_P4R, (const Ipp32f* const pSrc[4], IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* const pDst[4], int dstStep, IppiRect dstROI, double angle, double xShift, double yShift, int interpolation))
IPPAPI(IppStatus, ippiRotate_16u_C1R, (const Ipp16u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp16u* pDst, int dstStep, IppiRect dstROI, double angle, double xShift, double yShift, int interpolation))
IPPAPI(IppStatus, ippiRotate_16u_C3R, (const Ipp16u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp16u* pDst, int dstStep, IppiRect dstROI, double angle, double xShift, double yShift, int interpolation))
IPPAPI(IppStatus, ippiRotate_16u_AC4R, (const Ipp16u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp16u* pDst, int dstStep, IppiRect dstROI, double angle, double xShift, double yShift, int interpolation))
IPPAPI(IppStatus, ippiRotate_16u_P3R, (const Ipp16u* const pSrc[3], IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp16u* const pDst[3], int dstStep, IppiRect dstROI, double angle, double xShift, double yShift, int interpolation))
IPPAPI(IppStatus, ippiRotate_16u_C4R, (const Ipp16u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp16u* pDst, int dstStep, IppiRect dstROI, double angle, double xShift, double yShift, int interpolation))
IPPAPI(IppStatus, ippiRotate_16u_P4R, (const Ipp16u* const pSrc[4], IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp16u* const pDst[4], int dstStep, IppiRect dstROI, double angle, double xShift, double yShift, int interpolation))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiAddRotateShift
//  Purpose:        recalculates shifts for rotation around point
//                  (xCenter, yCenter) and sums to xShift, yShift.
//  Context:
//  Returns:        IppStatus.
//    ippStsNoErr           Ok
//    ippStsNullPtrErr      Some of pointers to output data are NULL
//  Parameters:
//                  xCenter, yCenter    center of rotation
//                  angle               the angle of rotation
//                  xShift, yShift      pointers to modified shifts
//  Notes:
*/

IPPAPI(IppStatus, ippiAddRotateShift, (double xCenter, double yCenter, double angle,
                                       double *xShift, double *yShift))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiGetRotateShift
//  Purpose:        recalculates shifts for rotation around point
//                  (xCenter, yCenter) and store to xShift, yShift.
//  Context:
//  Returns:        IppStatus.
//    ippStsNoErr           Ok
//    ippStsNullPtrErr      Some of pointers to output data are NULL
//  Parameters:
//                  xCenter, yCenter    center of rotation
//                  angle               the angle of rotation
//                  xShift, yShift      pointers to new shifts
//  Notes:
*/

IPPAPI(IppStatus, ippiGetRotateShift, (double xCenter, double yCenter, double angle,
                                       double *xShift, double *yShift))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiGetRotateQuad
//  Purpose:        calculates quadrangle of the transformed image ROI.
//  Context:
//  Returns:        IppStatus
//    ippStsNoErr      Ok
//  Parameters:
//      roi             The image roi.
//      angle           The angle of rotation.
//      xShift, yShift  Shifts.
//      quad            Resultant quadrangle.
//  Notes:
*/

IPPAPI(IppStatus, ippiGetRotateQuad, (IppiRect roi, double quad[4][2], double angle, double xShift, double yShift))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiGetRotateBound
//  Purpose:        calculates bounding rectangle of the transformed image ROI.
//  Context:
//  Returns:        IppStatus
//    ippStsNoErr      Ok
//  Parameters:
//      roi             The image roi.
//      angle           The angle of rotation.
//      xShift, yShift  Shifts.
//      bound           Resultant bounding rectangle.
//  Notes:
*/

IPPAPI(IppStatus, ippiGetRotateBound, (IppiRect roi, double bound[2][2], double angle, double xShift, double yShift))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiRotateCenter
//  Purpose:        Rotates an image about an arbitrary center.
//  Context:
//  Returns:        IppStatus
//    ippStsNoErr           Ok
//    ippStsNullPtrErr      At least one of pointers is NULL
//    ippStsSizeErr         The width or height of images is less than or equal to zero
//    ippStsInterpolateErr  The interpolation has an illegal value.
//  Parameters:
//      pSrc        Pointer to the source image origin (0,0).
//      srcSize     The size of the source image.
//      srcStep     The step in bytes through the source image.
//      srcROI      The Region Of Interest of the source image.
//      pDst        POinter to the destination image origin (0,0).
//      dstStep     The step in bytes through the destination image.
//      dstROI      The Region Of Interest of the destination image.
//      angle       The angle of rotation in degrees.
//      xCenter     x coordinate of the center of rotation.
//      yCenter     y coordinate of the center of rotation.
//      interpolate The type of interpolation to perform for resampling
//                  the input image. The following types are currently supported:
//                  IPPI_INTER_NN       Nearest neighbour interpolation.
//                  IPPI_INTER_LINEAR   Linear interpolation.
//                  IPPI_INTER_CUBIC    Cubic convolution interpolation.
//                 +IPPI_SMOOTH_EDGE    edge smoothing (addition to one of the above types)
//  Notes:
*/

IPPAPI(IppStatus, ippiRotateCenter_8u_C1R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* pDst, int dstStep, IppiRect dstROI, double angle, double xCenter, double yCenter, int interpolation))
IPPAPI(IppStatus, ippiRotateCenter_8u_C3R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* pDst, int dstStep, IppiRect dstROI, double angle, double xCenter, double yCenter, int interpolation))
IPPAPI(IppStatus, ippiRotateCenter_8u_AC4R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* pDst, int dstStep, IppiRect dstROI, double angle, double xCenter, double yCenter, int interpolation))
IPPAPI(IppStatus, ippiRotateCenter_8u_P3R, (const Ipp8u* const pSrc[3], IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* const pDst[3], int dstStep, IppiRect dstROI, double angle, double xCenter, double yCenter, int interpolation))
IPPAPI(IppStatus, ippiRotateCenter_8u_C4R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* pDst, int dstStep, IppiRect dstROI, double angle, double xCenter, double yCenter, int interpolation))
IPPAPI(IppStatus, ippiRotateCenter_8u_P4R, (const Ipp8u* const pSrc[4], IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* const pDst[4], int dstStep, IppiRect dstROI, double angle, double xCenter, double yCenter, int interpolation))
IPPAPI(IppStatus, ippiRotateCenter_32f_C1R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* pDst, int dstStep, IppiRect dstROI, double angle, double xCenter, double yCenter, int interpolation))
IPPAPI(IppStatus, ippiRotateCenter_32f_C3R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* pDst, int dstStep, IppiRect dstROI, double angle, double xCenter, double yCenter, int interpolation))
IPPAPI(IppStatus, ippiRotateCenter_32f_AC4R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* pDst, int dstStep, IppiRect dstROI, double angle, double xCenter, double yCenter, int interpolation))
IPPAPI(IppStatus, ippiRotateCenter_32f_P3R, (const Ipp32f* const pSrc[3], IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* const pDst[3], int dstStep, IppiRect dstROI, double angle, double xCenter, double yCenter, int interpolation))
IPPAPI(IppStatus, ippiRotateCenter_32f_C4R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* pDst, int dstStep, IppiRect dstROI, double angle, double xCenter, double yCenter, int interpolation))
IPPAPI(IppStatus, ippiRotateCenter_32f_P4R, (const Ipp32f* const pSrc[4], IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* const pDst[4], int dstStep, IppiRect dstROI, double angle, double xCenter, double yCenter, int interpolation))
IPPAPI(IppStatus, ippiRotateCenter_16u_C1R, (const Ipp16u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp16u* pDst, int dstStep, IppiRect dstROI, double angle, double xCenter, double yCenter, int interpolation))
IPPAPI(IppStatus, ippiRotateCenter_16u_C3R, (const Ipp16u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp16u* pDst, int dstStep, IppiRect dstROI, double angle, double xCenter, double yCenter, int interpolation))
IPPAPI(IppStatus, ippiRotateCenter_16u_AC4R, (const Ipp16u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp16u* pDst, int dstStep, IppiRect dstROI, double angle, double xCenter, double yCenter, int interpolation))
IPPAPI(IppStatus, ippiRotateCenter_16u_P3R, (const Ipp16u* const pSrc[3], IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp16u* const pDst[3], int dstStep, IppiRect dstROI, double angle, double xCenter, double yCenter, int interpolation))
IPPAPI(IppStatus, ippiRotateCenter_16u_C4R, (const Ipp16u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp16u* pDst, int dstStep, IppiRect dstROI, double angle, double xCenter, double yCenter, int interpolation))
IPPAPI(IppStatus, ippiRotateCenter_16u_P4R, (const Ipp16u* const pSrc[4], IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp16u* const pDst[4], int dstStep, IppiRect dstROI, double angle, double xCenter, double yCenter, int interpolation))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiShear
//  Purpose:        Makes shear transform of image.
//                  |X'|   |1  Shx| |X|
//                  |  | = |      |*| |
//                  |Y'|   |Shy  1| |Y|
//  Context:
//  Returns:        IppStatus.
//    ippStsNoErr           Ok
//    ippStsNullPtrErr      Some of pointers to input or output data are NULL
//    ippStsSizeErr         The width or height of images is less or equal zero
//    ippStsInterpolateErr  The interpolation is bad
//  Parameters:
//      pSrc        The source image data (point to pixel (0,0)).
//      srcSize     The size of src.
//      srcStep     The step in src
//      srcROI      The Region Of Interest of src.
//      pDst        The resultant image data (point to pixel (0,0)).
//      dstStep     The step in dst
//      dstROI      The Region Of Interest of dst.
//      xShift      The shift along x direction
//      yShift      The shift along y direction
//      interpolate The type of interpolation to perform for resampling
//                  the input image. The following are currently supported.
//                  IPPI_INTER_NN       Nearest neighbour interpolation.
//                  IPPI_INTER_LINEAR   Linear interpolation.
//                  IPPI_INTER_CUBIC    Cubic convolution interpolation.
//                 +IPPI_SMOOTH_EDGE    smoothed edges
//  Notes:
*/

IPPAPI(IppStatus, ippiShear_8u_C1R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* pDst, int dstStep, IppiRect dstROI, double xShear, double yShear, double xShift, double yShift, int interpolation))
IPPAPI(IppStatus, ippiShear_8u_C3R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* pDst, int dstStep, IppiRect dstROI, double xShear, double yShear, double xShift, double yShift, int interpolation))
IPPAPI(IppStatus, ippiShear_8u_AC4R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* pDst, int dstStep, IppiRect dstROI, double xShear, double yShear, double xShift, double yShift, int interpolation))
IPPAPI(IppStatus, ippiShear_8u_P3R, (const Ipp8u* const pSrc[3], IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* const pDst[3], int dstStep, IppiRect dstROI, double xShear, double yShear, double xShift, double yShift, int interpolation))
IPPAPI(IppStatus, ippiShear_8u_C4R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* pDst, int dstStep, IppiRect dstROI, double xShear, double yShear, double xShift, double yShift, int interpolation))
IPPAPI(IppStatus, ippiShear_8u_P4R, (const Ipp8u* const pSrc[4], IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* const pDst[4], int dstStep, IppiRect dstROI, double xShear, double yShear, double xShift, double yShift, int interpolation))
IPPAPI(IppStatus, ippiShear_32f_C1R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* pDst, int dstStep, IppiRect dstROI, double xShear, double yShear, double xShift, double yShift, int interpolation))
IPPAPI(IppStatus, ippiShear_32f_C3R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* pDst, int dstStep, IppiRect dstROI, double xShear, double yShear, double xShift, double yShift, int interpolation))
IPPAPI(IppStatus, ippiShear_32f_AC4R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* pDst, int dstStep, IppiRect dstROI, double xShear, double yShear, double xShift, double yShift, int interpolation))
IPPAPI(IppStatus, ippiShear_32f_P3R, (const Ipp32f* const pSrc[3], IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* const pDst[3], int dstStep, IppiRect dstROI, double xShear, double yShear, double xShift, double yShift, int interpolation))
IPPAPI(IppStatus, ippiShear_32f_C4R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* pDst, int dstStep, IppiRect dstROI, double xShear, double yShear, double xShift, double yShift, int interpolation))
IPPAPI(IppStatus, ippiShear_32f_P4R, (const Ipp32f* const pSrc[4], IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* const pDst[4], int dstStep, IppiRect dstROI, double xShear, double yShear, double xShift, double yShift, int interpolation))




/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiGetShearQuad
//  Purpose:        calculates quadrangle of the transformed image ROI.
//  Context:
//  Returns:        IppStatus
//    ippStsNoErr   Ok
//  Parameters:
//      roi             The image roi.
//      xShear, yShear  The coeffs of shear.
//      xShift, yShift  Shifts.
//      quad            Resultant quadrangle.
//  Notes:
*/

IPPAPI(IppStatus, ippiGetShearQuad, (IppiRect roi, double quad[4][2], double xShear, double yShear, double xShift, double yShift))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiGetShearBound
//  Purpose:        calculates bounding rectangle of the transformed image ROI.
//  Context:
//  Returns:        IppStatus
//    ippStsNoErr   Ok
//  Parameters:
//      roi             The image roi.
//      xShear, yShear  The coeffs of shear.
//      xShift, yShift  Shifts.
//      bound           Resultant bounding rectangle.
//  Notes:
*/

IPPAPI(IppStatus, ippiGetShearBound, (IppiRect roi, double bound[2][2], double xShear, double yShear, double xShift, double yShift))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiGetPerspectiveBound
//  Purpose:        calculates bounding rectangle of the transformed image ROI.
//  Context:
//  Returns:        IppStatus.
//    ippStsNoErr   Ok
//  Parameters:
//      roi         The image roi.
//      coeffs      The transform matrix
//                     a11*j + a12*i + a13
//                 x = -------------------
//                     a31*j + a32*i + a33
//
//                     a21*j + a22*i + a23
//                 y = -------------------
//                     a31*j + a32*i + a33
//      bound       resultant bounding rectangle
//  Notes:
*/

IPPAPI(IppStatus, ippiGetPerspectiveBound, (IppiRect roi, double bound[2][2], const double coeffs[3][3]))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiGetPerspectiveQuad
//  Purpose:        calculates coordinates of quadrangle from transformed image ROI.
//  Context:
//  Returns:        IppStatus.
//    ippStsNoErr   Ok
//  Parameters:
//      roi         The image roi.
//      coeffs      The transform matrix
//                     a11*j + a12*i + a13
//                 x = -------------------
//                     a31*j + a32*i + a33
//
//                     a21*j + a22*i + a23
//                 y = -------------------
//                     a31*j + a32*i + a33
//      quadr       resultant quadrangle
//  Notes:
*/

IPPAPI(IppStatus, ippiGetPerspectiveQuad, (IppiRect roi, double quad[4][2], const double coeffs[3][3]))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiGetPerspectiveTransform
//  Purpose:        calculates transform matrix from vertexes of quadrangle.
//  Context:
//  Returns:        IppStatus.
//    ippStsNoErr   Ok
//  Parameters:
//      roi         The image roi.
//      coeffs      The resultant transform matrix
//                     a11*j + a12*i + a13
//                 x = -------------------
//                     a31*j + a32*i + a33
//
//                     a21*j + a22*i + a23
//                 y = -------------------
//                     a31*j + a32*i + a33
//      quad        quadrangle
//  Notes:
*/

IPPAPI(IppStatus, ippiGetPerspectiveTransform, (IppiRect roi, const double quad[4][2], double coeffs[3][3]))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiWarpPerspective
//  Purpose:        makes Perspective transform of image.
//                     a11*j + a12*i + a13
//                 x = -------------------
//                     a31*j + a32*i + a33
//
//                     a21*j + a22*i + a23
//                 y = -------------------
//                     a31*j + a32*i + a33
//  Context:
//  Returns:        IppStatus
//    ippStsNoErr           Ok
//    ippStsNullPtrErr      Some of pointers to input or output data are NULL
//    ippStsSizeErr         The width or height of images is less or equal zero
//    ippStsInterpolateErr  The interpolation is bad
//  Parameters:
//      pSrc        The source image data (point to pixel (0,0)).
//      srcSize     The size of src.
//      srcStep     The step in src
//      srcROI      The Region Of Interest of src.
//      pDst        The resultant image data (point to pixel (0,0)).
//      dstStep     The step in dst
//      dstROI      The Region Of Interest of dst.
//      coeffs      The transform matrix
//      interpolate The type of interpolation to perform for resampling
//                  the input image. The following are currently supported.
//                  IPPI_INTER_NN       Nearest neighbour interpolation.
//                  IPPI_INTER_LINEAR   Linear interpolation.
//                  IPPI_INTER_CUBIC    Cubic convolution interpolation.
//                 +IPPI_SMOOTH_EDGE    smoothed edges
//  Notes:
*/

IPPAPI(IppStatus, ippiWarpPerspective_8u_C1R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* pDst, int dstStep, IppiRect dstROI, const double coeffs[3][3], int interpolation))
IPPAPI(IppStatus, ippiWarpPerspective_8u_C3R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* pDst, int dstStep, IppiRect dstROI, const double coeffs[3][3], int interpolation))
IPPAPI(IppStatus, ippiWarpPerspective_8u_AC4R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* pDst, int dstStep, IppiRect dstROI, const double coeffs[3][3], int interpolation))
IPPAPI(IppStatus, ippiWarpPerspective_8u_P3R, (const Ipp8u* const pSrc[3], IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* const pDst[3], int dstStep, IppiRect dstROI, const double coeffs[3][3], int interpolation))
IPPAPI(IppStatus, ippiWarpPerspective_8u_C4R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* pDst, int dstStep, IppiRect dstROI, const double coeffs[3][3], int interpolation))
IPPAPI(IppStatus, ippiWarpPerspective_8u_P4R, (const Ipp8u* const pSrc[4], IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* const pDst[4], int dstStep, IppiRect dstROI, const double coeffs[3][3], int interpolation))
IPPAPI(IppStatus, ippiWarpPerspective_32f_C1R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* pDst, int dstStep, IppiRect dstROI, const double coeffs[3][3], int interpolation))
IPPAPI(IppStatus, ippiWarpPerspective_32f_C3R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* pDst, int dstStep, IppiRect dstROI, const double coeffs[3][3], int interpolation))
IPPAPI(IppStatus, ippiWarpPerspective_32f_AC4R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* pDst, int dstStep, IppiRect dstROI, const double coeffs[3][3], int interpolation))
IPPAPI(IppStatus, ippiWarpPerspective_32f_P3R, (const Ipp32f* const pSrc[3], IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* const pDst[3], int dstStep, IppiRect dstROI, const double coeffs[3][3], int interpolation))
IPPAPI(IppStatus, ippiWarpPerspective_32f_C4R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* pDst, int dstStep, IppiRect dstROI, const double coeffs[3][3], int interpolation))
IPPAPI(IppStatus, ippiWarpPerspective_32f_P4R, (const Ipp32f* const pSrc[4], IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* const pDst[4], int dstStep, IppiRect dstROI, const double coeffs[3][3], int interpolation))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiWarpPerspectiveBack
//  Purpose:        makes Back Perspective transform of image.
//                     a11*j + a12*i + a13
//                 x = -------------------
//                     a31*j + a32*i + a33
//
//                     a21*j + a22*i + a23
//                 y = -------------------
//                     a31*j + a32*i + a33
//  Context:
//  Returns:        IppStatus
//    ippStsNoErr           Ok
//    ippStsNullPtrErr      Some of pointers to input or output data are NULL
//    ippStsSizeErr         The width or height of images is less or equal zero
//    ippStsInterpolateErr  The interpolation is bad
//  Parameters:
//      pSrc        The source image data (point to pixel (0,0)).
//      srcSize     The size of src.
//      srcStep     The step in src
//      srcROI      The Region Of Interest of src.
//      pDst        The resultant image data (point to pixel (0,0)).
//      dstStep     The step in dst
//      dstROI      The Region Of Interest of dst.
//      coeffs      The transform matrix
//      interpolate The type of interpolation to perform for resampling
//                  the input image. The following are currently supported.
//                  IPPI_INTER_NN       Nearest neighbour interpolation.
//                  IPPI_INTER_LINEAR   Linear interpolation.
//                  IPPI_INTER_CUBIC    Cubic convolution interpolation.
//  Notes:
*/

IPPAPI(IppStatus, ippiWarpPerspectiveBack_8u_C1R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* pDst, int dstStep, IppiRect dstROI, const double coeffs[3][3], int interpolation))
IPPAPI(IppStatus, ippiWarpPerspectiveBack_8u_C3R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* pDst, int dstStep, IppiRect dstROI, const double coeffs[3][3], int interpolation))
IPPAPI(IppStatus, ippiWarpPerspectiveBack_8u_AC4R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* pDst, int dstStep, IppiRect dstROI, const double coeffs[3][3], int interpolation))
IPPAPI(IppStatus, ippiWarpPerspectiveBack_8u_P3R, (const Ipp8u* const pSrc[3], IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* const pDst[3], int dstStep, IppiRect dstROI, const double coeffs[3][3], int interpolation))
IPPAPI(IppStatus, ippiWarpPerspectiveBack_8u_C4R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* pDst, int dstStep, IppiRect dstROI, const double coeffs[3][3], int interpolation))
IPPAPI(IppStatus, ippiWarpPerspectiveBack_8u_P4R, (const Ipp8u* const pSrc[4], IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* const pDst[4], int dstStep, IppiRect dstROI, const double coeffs[3][3], int interpolation))
IPPAPI(IppStatus, ippiWarpPerspectiveBack_32f_C1R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* pDst, int dstStep, IppiRect dstROI, const double coeffs[3][3], int interpolation))
IPPAPI(IppStatus, ippiWarpPerspectiveBack_32f_C3R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* pDst, int dstStep, IppiRect dstROI, const double coeffs[3][3], int interpolation))
IPPAPI(IppStatus, ippiWarpPerspectiveBack_32f_AC4R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* pDst, int dstStep, IppiRect dstROI, const double coeffs[3][3], int interpolation))
IPPAPI(IppStatus, ippiWarpPerspectiveBack_32f_P3R, (const Ipp32f* const pSrc[3], IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* const pDst[3], int dstStep, IppiRect dstROI, const double coeffs[3][3], int interpolation))
IPPAPI(IppStatus, ippiWarpPerspectiveBack_32f_C4R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* pDst, int dstStep, IppiRect dstROI, const double coeffs[3][3], int interpolation))
IPPAPI(IppStatus, ippiWarpPerspectiveBack_32f_P4R, (const Ipp32f* const pSrc[4], IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* const pDst[4], int dstStep, IppiRect dstROI, const double coeffs[3][3], int interpolation))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiWarpPerspectiveQuad
//  Purpose:        makes Back Perspective transform of image from srcQuad to dstQuad.
//                     a11*j + a12*i + a13
//                 x = -------------------
//                     a31*j + a32*i + a33
//
//                     a21*j + a22*i + a23
//                 y = -------------------
//                     a31*j + a32*i + a33
//  Context:
//  Returns:        IppStatus
//    ippStsNoErr           Ok
//    ippStsNullPtrErr      Some of pointers to input or output data are NULL
//    ippStsSizeErr         The width or height of images is less or equal zero
//    ippStsInterpolateErr  The interpolation is bad
//  Parameters:
//      pSrc        The source image data (point to pixel (0,0)).
//      srcSize     The size of src.
//      srcStep     The step in src
//      srcROI      The Region Of Interest of src.
//      srcQuad     The Quadrangle in src
//      pDst        The resultant image data (point to pixel (0,0)).
//      dstStep     The step in dst
//      dstROI      The Region Of Interest of dst.
//      dstQuad     The Quadrangle in dst
//      interpolate The type of interpolation to perform for resampling
//                  the input image. The following are currently supported.
//                  IPPI_INTER_NN       Nearest neighbour interpolation.
//                  IPPI_INTER_LINEAR   Linear interpolation.
//                  IPPI_INTER_CUBIC    Cubic convolution interpolation.
//  Notes:
*/

IPPAPI(IppStatus, ippiWarpPerspectiveQuad_8u_C1R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, const double srcQuad[4][2], Ipp8u* pDst, int dstStep, IppiRect dstROI, const double dstQuad[4][2], int interpolation))
IPPAPI(IppStatus, ippiWarpPerspectiveQuad_8u_C3R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, const double srcQuad[4][2], Ipp8u* pDst, int dstStep, IppiRect dstROI, const double dstQuad[4][2], int interpolation))
IPPAPI(IppStatus, ippiWarpPerspectiveQuad_8u_AC4R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, const double srcQuad[4][2], Ipp8u* pDst, int dstStep, IppiRect dstROI, const double dstQuad[4][2], int interpolation))
IPPAPI(IppStatus, ippiWarpPerspectiveQuad_8u_P3R, (const Ipp8u* const pSrc[3], IppiSize srcSize, int srcStep, IppiRect srcROI, const double srcQuad[4][2], Ipp8u* const pDst[3], int dstStep, IppiRect dstROI, const double dstQuad[4][2], int interpolation))
IPPAPI(IppStatus, ippiWarpPerspectiveQuad_8u_C4R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, const double srcQuad[4][2], Ipp8u* pDst, int dstStep, IppiRect dstROI, const double dstQuad[4][2], int interpolation))
IPPAPI(IppStatus, ippiWarpPerspectiveQuad_8u_P4R, (const Ipp8u* const pSrc[4], IppiSize srcSize, int srcStep, IppiRect srcROI, const double srcQuad[4][2], Ipp8u* const pDst[4], int dstStep, IppiRect dstROI, const double dstQuad[4][2], int interpolation))
IPPAPI(IppStatus, ippiWarpPerspectiveQuad_32f_C1R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, const double srcQuad[4][2], Ipp32f* pDst, int dstStep, IppiRect dstROI, const double dstQuad[4][2], int interpolation))
IPPAPI(IppStatus, ippiWarpPerspectiveQuad_32f_C3R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, const double srcQuad[4][2], Ipp32f* pDst, int dstStep, IppiRect dstROI, const double dstQuad[4][2], int interpolation))
IPPAPI(IppStatus, ippiWarpPerspectiveQuad_32f_AC4R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, const double srcQuad[4][2], Ipp32f* pDst, int dstStep, IppiRect dstROI, const double dstQuad[4][2], int interpolation))
IPPAPI(IppStatus, ippiWarpPerspectiveQuad_32f_P3R, (const Ipp32f* const pSrc[3], IppiSize srcSize, int srcStep, IppiRect srcROI, const double srcQuad[4][2], Ipp32f* const pDst[3], int dstStep, IppiRect dstROI, const double dstQuad[4][2], int interpolation))
IPPAPI(IppStatus, ippiWarpPerspectiveQuad_32f_C4R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, const double srcQuad[4][2], Ipp32f* pDst, int dstStep, IppiRect dstROI, const double dstQuad[4][2], int interpolation))
IPPAPI(IppStatus, ippiWarpPerspectiveQuad_32f_P4R, (const Ipp32f* const pSrc[4], IppiSize srcSize, int srcStep, IppiRect srcROI, const double srcQuad[4][2], Ipp32f* const pDst[4], int dstStep, IppiRect dstROI, const double dstQuad[4][2], int interpolation))



/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiGetBilinearBound
//  Purpose:        calculates bounding rectangle of the transformed image ROI.
//  Context:
//  Returns:        IppStatus.
//    ippStsNoErr       Ok
//  Parameters:
//      roi         The image roi.
//      coeffs      The transform matrix
//                  |X|   |a11|      |a12 a13| |J|   |a14|
//                  | | = |   |*JI + |       |*| | + |   |
//                  |Y|   |a21|      |a22 a23| |I|   |a24|
//      bound       resultant bounding rectangle
//  Notes:
*/

IPPAPI(IppStatus, ippiGetBilinearBound, (IppiRect roi, double bound[2][2], const double coeffs[2][4]))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiGetBilinearQuad
//  Purpose:        calculates coordinates of quadrangle from transformed image ROI.
//  Context:
//  Returns:        IppStatus.
//    ippStsNoErr        Ok
//  Parameters:
//      roi         The image roi.
//      coeffs      The transform matrix
//                  |X|   |a11|      |a12 a13| |J|   |a14|
//                  | | = |   |*JI + |       |*| | + |   |
//                  |Y|   |a21|      |a22 a23| |I|   |a24|
//      quadr       resultant quadrangle
//  Notes:
*/

IPPAPI(IppStatus, ippiGetBilinearQuad, (IppiRect roi, double quad[4][2], const double coeffs[2][4]))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiGetBilinearTransform
//  Purpose:        calculates transform matrix from vertexes of quadrangle.
//  Context:
//  Returns:        IppStatus.
//    ippStsNoErr        Ok
//  Parameters:
//      roi         The image roi.
//      coeffs      The resultant transform matrix
//                  |X|   |a11|      |a12 a13| |J|   |a14|
//                  | | = |   |*JI + |       |*| | + |   |
//                  |Y|   |a21|      |a22 a23| |I|   |a24|
//      quad        quadrangle
//  Notes:
*/

IPPAPI(IppStatus, ippiGetBilinearTransform, (IppiRect roi, const double quad[4][2], double coeffs[2][4]))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiWarpBilinear
//  Purpose:        makes Bilinear transform of image.
//                  |X|   |a11|      |a12 a13| |J|   |a14|
//                  | | = |   |*JI + |       |*| | + |   |
//                  |Y|   |a21|      |a22 a23| |I|   |a24|
//  Context:
//  Returns:        IppStatus
//    ippStsNoErr           Ok
//    ippStsNullPtrErr      Some of pointers to input or output data are NULL
//    ippStsSizeErr         The width or height of images is less or equal zero
//    ippStsInterpolateErr  The interpolation is bad
//  Parameters:
//      pSrc        The source image data (point to pixel (0,0)).
//      srcSize     The size of src.
//      srcStep     The step in src
//      srcROI      The Region Of Interest of src.
//      pDst        The resultant image data (point to pixel (0,0)).
//      dstStep     The step in dst
//      dstROI      The Region Of Interest of dst.
//      coeffs      The transform matrix
//      interpolate The type of interpolation to perform for resampling
//                  the input image. The following are currently supported.
//                  IPPI_INTER_NN       Nearest neighbour interpolation.
//                  IPPI_INTER_LINEAR   Linear interpolation.
//                  IPPI_INTER_CUBIC    Cubic convolution interpolation.
//                 +IPPI_SMOOTH_EDGE    smoothed edges
//  Notes:
*/

IPPAPI(IppStatus, ippiWarpBilinear_8u_C1R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* pDst, int dstStep, IppiRect dstROI, const double coeffs[2][4], int interpolation))
IPPAPI(IppStatus, ippiWarpBilinear_8u_C3R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* pDst, int dstStep, IppiRect dstROI, const double coeffs[2][4], int interpolation))
IPPAPI(IppStatus, ippiWarpBilinear_8u_AC4R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* pDst, int dstStep, IppiRect dstROI, const double coeffs[2][4], int interpolation))
IPPAPI(IppStatus, ippiWarpBilinear_8u_P3R, (const Ipp8u* const pSrc[3], IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* const pDst[3], int dstStep, IppiRect dstROI, const double coeffs[2][4], int interpolation))
IPPAPI(IppStatus, ippiWarpBilinear_8u_C4R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* pDst, int dstStep, IppiRect dstROI, const double coeffs[2][4], int interpolation))
IPPAPI(IppStatus, ippiWarpBilinear_8u_P4R, (const Ipp8u* const pSrc[4], IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* const pDst[4], int dstStep, IppiRect dstROI, const double coeffs[2][4], int interpolation))
IPPAPI(IppStatus, ippiWarpBilinear_32f_C1R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* pDst, int dstStep, IppiRect dstROI, const double coeffs[2][4], int interpolation))
IPPAPI(IppStatus, ippiWarpBilinear_32f_C3R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* pDst, int dstStep, IppiRect dstROI, const double coeffs[2][4], int interpolation))
IPPAPI(IppStatus, ippiWarpBilinear_32f_AC4R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* pDst, int dstStep, IppiRect dstROI, const double coeffs[2][4], int interpolation))
IPPAPI(IppStatus, ippiWarpBilinear_32f_P3R, (const Ipp32f* const pSrc[3], IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* const pDst[3], int dstStep, IppiRect dstROI, const double coeffs[2][4], int interpolation))
IPPAPI(IppStatus, ippiWarpBilinear_32f_C4R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* pDst, int dstStep, IppiRect dstROI, const double coeffs[2][4], int interpolation))
IPPAPI(IppStatus, ippiWarpBilinear_32f_P4R, (const Ipp32f* const pSrc[4], IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* const pDst[4], int dstStep, IppiRect dstROI, const double coeffs[2][4], int interpolation))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiWarpBilinearBack
//  Purpose:        makes Back Bilinear transform of image.
//                  |X|   |a11|      |a12 a13| |J|   |a14|
//                  | | = |   |*JI + |       |*| | + |   |
//                  |Y|   |a21|      |a22 a23| |I|   |a24|
//  Context:
//  Returns:        IppStatus
//    ippStsNoErr           Ok
//    ippStsNullPtrErr      Some of pointers to input or output data are NULL
//    ippStsSizeErr         The width or height of images is less or equal zero
//    ippSstsInterpolateErr  The interpolation is bad
//  Parameters:
//      pSrc        The source image data (point to pixel (0,0)).
//      srcSize     The size of src.
//      srcStep     The step in src
//      srcROI      The Region Of Interest of src.
//      pDst        The resultant image data (point to pixel (0,0)).
//      dstStep     The step in dst
//      dstROI      The Region Of Interest of dst.
//      coeffs      The transform matrix
//      interpolate The type of interpolation to perform for resampling
//                  the input image. The following are currently supported.
//                  IPPI_INTER_NN       Nearest neighbour interpolation.
//                  IPPI_INTER_LINEAR   Linear interpolation.
//                  IPPI_INTER_CUBIC    Cubic convolution interpolation.
//  Notes:
*/

IPPAPI(IppStatus, ippiWarpBilinearBack_8u_C1R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* pDst, int dstStep, IppiRect dstROI, const double coeffs[2][4], int interpolation))
IPPAPI(IppStatus, ippiWarpBilinearBack_8u_C3R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* pDst, int dstStep, IppiRect dstROI, const double coeffs[2][4], int interpolation))
IPPAPI(IppStatus, ippiWarpBilinearBack_8u_AC4R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* pDst, int dstStep, IppiRect dstROI, const double coeffs[2][4], int interpolation))
IPPAPI(IppStatus, ippiWarpBilinearBack_8u_P3R, (const Ipp8u* const pSrc[3], IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* const pDst[3], int dstStep, IppiRect dstROI, const double coeffs[2][4], int interpolation))
IPPAPI(IppStatus, ippiWarpBilinearBack_8u_C4R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* pDst, int dstStep, IppiRect dstROI, const double coeffs[2][4], int interpolation))
IPPAPI(IppStatus, ippiWarpBilinearBack_8u_P4R, (const Ipp8u* const pSrc[4], IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp8u* const pDst[4], int dstStep, IppiRect dstROI, const double coeffs[2][4], int interpolation))
IPPAPI(IppStatus, ippiWarpBilinearBack_32f_C1R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* pDst, int dstStep, IppiRect dstROI, const double coeffs[2][4], int interpolation))
IPPAPI(IppStatus, ippiWarpBilinearBack_32f_C3R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* pDst, int dstStep, IppiRect dstROI, const double coeffs[2][4], int interpolation))
IPPAPI(IppStatus, ippiWarpBilinearBack_32f_AC4R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* pDst, int dstStep, IppiRect dstROI, const double coeffs[2][4], int interpolation))
IPPAPI(IppStatus, ippiWarpBilinearBack_32f_P3R, (const Ipp32f* const pSrc[3], IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* const pDst[3], int dstStep, IppiRect dstROI, const double coeffs[2][4], int interpolation))
IPPAPI(IppStatus, ippiWarpBilinearBack_32f_C4R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* pDst, int dstStep, IppiRect dstROI, const double coeffs[2][4], int interpolation))
IPPAPI(IppStatus, ippiWarpBilinearBack_32f_P4R, (const Ipp32f* const pSrc[4], IppiSize srcSize, int srcStep, IppiRect srcROI, Ipp32f* const pDst[4], int dstStep, IppiRect dstROI, const double coeffs[2][4], int interpolation))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiWarpBilinearQuad
//  Purpose:        makes Bilinear transform of image from srcQuad to dstQuad.
//                  |X|   |a11|      |a12 a13| |J|   |a14|
//                  | | = |   |*JI + |       |*| | + |   |
//                  |Y|   |a21|      |a22 a23| |I|   |a24|
//  Context:
//  Returns:        IppStatus
//    ippStsNoErr           Ok
//    ippStsNullPtrErr      Some of pointers to input or output data are NULL
//    ippStsSizeErr         The width or height of images is less or equal zero
//    ippStsInterpolateErr  The interpolation is bad
//  Parameters:
//      pSrc        The source image data (point to pixel (0,0)).
//      srcSize     The size of src.
//      srcStep     The step in src
//      srcROI      The Region Of Interest of src.
//      srcQuad     The Quadrangle in src
//      pDst        The resultant image data (point to pixel (0,0)).
//      dstStep     The step in dst
//      dstROI      The Region Of Interest of dst.
//      dstQuad     The Quadrangle in dst
//      interpolate The type of interpolation to perform for resampling
//                  the input image. The following are currently supported.
//                  IPPI_INTER_NN       Nearest neighbour interpolation.
//                  IPPI_INTER_LINEAR   Linear interpolation.
//                  IPPI_INTER_CUBIC    Cubic convolution interpolation.
//                 +IPPI_SMOOTH_EDGE    smoothed edges
//  Notes:
*/

IPPAPI(IppStatus, ippiWarpBilinearQuad_8u_C1R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, const double srcQuad[4][2], Ipp8u* pDst, int dstStep, IppiRect dstROI, const double dstQuad[4][2], int interpolation))
IPPAPI(IppStatus, ippiWarpBilinearQuad_8u_C3R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, const double srcQuad[4][2], Ipp8u* pDst, int dstStep, IppiRect dstROI, const double dstQuad[4][2], int interpolation))
IPPAPI(IppStatus, ippiWarpBilinearQuad_8u_AC4R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, const double srcQuad[4][2], Ipp8u* pDst, int dstStep, IppiRect dstROI, const double dstQuad[4][2], int interpolation))
IPPAPI(IppStatus, ippiWarpBilinearQuad_8u_P3R, (const Ipp8u* const pSrc[3], IppiSize srcSize, int srcStep, IppiRect srcROI, const double srcQuad[4][2], Ipp8u* const pDst[3], int dstStep, IppiRect dstROI, const double dstQuad[4][2], int interpolation))
IPPAPI(IppStatus, ippiWarpBilinearQuad_8u_C4R, (const Ipp8u* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, const double srcQuad[4][2], Ipp8u* pDst, int dstStep, IppiRect dstROI, const double dstQuad[4][2], int interpolation))
IPPAPI(IppStatus, ippiWarpBilinearQuad_8u_P4R, (const Ipp8u* const pSrc[4], IppiSize srcSize, int srcStep, IppiRect srcROI, const double srcQuad[4][2], Ipp8u* const pDst[4], int dstStep, IppiRect dstROI, const double dstQuad[4][2], int interpolation))
IPPAPI(IppStatus, ippiWarpBilinearQuad_32f_C1R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, const double srcQuad[4][2], Ipp32f* pDst, int dstStep, IppiRect dstROI, const double dstQuad[4][2], int interpolation))
IPPAPI(IppStatus, ippiWarpBilinearQuad_32f_C3R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, const double srcQuad[4][2], Ipp32f* pDst, int dstStep, IppiRect dstROI, const double dstQuad[4][2], int interpolation))
IPPAPI(IppStatus, ippiWarpBilinearQuad_32f_AC4R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, const double srcQuad[4][2], Ipp32f* pDst, int dstStep, IppiRect dstROI, const double dstQuad[4][2], int interpolation))
IPPAPI(IppStatus, ippiWarpBilinearQuad_32f_P3R, (const Ipp32f* const pSrc[3], IppiSize srcSize, int srcStep, IppiRect srcROI, const double srcQuad[4][2], Ipp32f* const pDst[3], int dstStep, IppiRect dstROI, const double dstQuad[4][2], int interpolation))
IPPAPI(IppStatus, ippiWarpBilinearQuad_32f_C4R, (const Ipp32f* pSrc, IppiSize srcSize, int srcStep, IppiRect srcROI, const double srcQuad[4][2], Ipp32f* pDst, int dstStep, IppiRect dstROI, const double dstQuad[4][2], int interpolation))
IPPAPI(IppStatus, ippiWarpBilinearQuad_32f_P4R, (const Ipp32f* const pSrc[4], IppiSize srcSize, int srcStep, IppiRect srcROI, const double srcQuad[4][2], Ipp32f* const pDst[4], int dstStep, IppiRect dstROI, const double dstQuad[4][2], int interpolation))




/* /////////////////////////////////////////////////////////////////////////////
//                   Statistic functions
///////////////////////////////////////////////////////////////////////////// */

#if !defined( _OWN_BLDPCS )
struct MomentState64f;
struct MomentState64s;

typedef struct MomentState64f IppiMomentState_64f;
typedef struct MomentState64s IppiMomentState_64s;

typedef Ipp64f IppiHuMoment_64f[7];
typedef Ipp64s IppiHuMoment_64s[7];
#endif /* _OWN_BLDPCS */


/* /////////////////////////////////////////////////////////////////////////////
//  Name:      ippiMomentInitAlloc()
//
//  Purpose:   Initializes MomentState structure
//
//  Returns:
//    ippStsMemAllocErr memory allocation failure
//    ippStsNoErr       no errors
//
//  Parameters:
//    hint     option to specify the computation algorithm
//    pState   pointer to the MomentState structure
*/
IPPAPI(IppStatus, ippiMomentInitAlloc_64f, (IppiMomentState_64f** pState, IppHintAlgorithm hint))
IPPAPI(IppStatus, ippiMomentInitAlloc_64s, (IppiMomentState_64s** pState, IppHintAlgorithm hint))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:      ippiMomentFree()
//
//  Purpose:   Deallocates the MomentState structure
//
//  Returns:
//    ippStsNullPtrErr       pState==NULL
//    ippStsContextMatchErr  pState->idCtx != idCtxMoment
//    ippStsNoErr,           no errors
//
//  Parameters:
//    pState   pointer to the MomentState structure
//
*/
IPPAPI (IppStatus, ippiMomentFree_64f, (IppiMomentState_64f* pState))
IPPAPI (IppStatus, ippiMomentFree_64s, (IppiMomentState_64s* pState))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:      ippiMoments
//
//  Purpose:   Computes statistical moments of an image
//
//  Returns:
//    ippStsContextMatchErr   pState->idCtx != idCtxMoment
//    ippStsNullPtrErr        (pSrc == NULL) or (pState == NULL)
//    ippStsStepErr           pSrcStep <0
//    ippStsSizeErr           (roiSize.width  <1) or (roiSize.height <1)
//    ippStsNoErr             no errors
//
//  Parameters:
//    pSrc     pointer to the source image
//    srcStep  step in bytes through the source image
//    roiSize  size of the source ROI
//    pState   pointer to the MomentState structure
//
//  Notes:
//    We consider moments up to the 3-rd order only
//
*/
IPPAPI(IppStatus,ippiMoments64f_8u_C1R, (const Ipp8u* pSrc, int srcStep, IppiSize roiSize, IppiMomentState_64f* pCtx))
IPPAPI(IppStatus,ippiMoments64f_8u_C3R, (const Ipp8u* pSrc, int srcStep, IppiSize roiSize, IppiMomentState_64f* pCtx))
IPPAPI(IppStatus,ippiMoments64f_8u_AC4R,(const Ipp8u* pSrc, int srcStep, IppiSize roiSize, IppiMomentState_64f* pCtx))

IPPAPI(IppStatus,ippiMoments64f_32f_C1R, (const Ipp32f* pSrc, int srcStep, IppiSize roiSize, IppiMomentState_64f* pCtx))
IPPAPI(IppStatus,ippiMoments64f_32f_C3R, (const Ipp32f* pSrc, int srcStep, IppiSize roiSize, IppiMomentState_64f* pCtx))
IPPAPI(IppStatus,ippiMoments64f_32f_AC4R,(const Ipp32f* pSrc, int srcStep, IppiSize roiSize, IppiMomentState_64f* pCtx))

IPPAPI(IppStatus,ippiMoments64s_8u_C1R, (const Ipp8u* pSrc, int srcStep, IppiSize roiSize, IppiMomentState_64s* pCtx))
IPPAPI(IppStatus,ippiMoments64s_8u_C3R, (const Ipp8u* pSrc, int srcStep, IppiSize roiSize, IppiMomentState_64s* pCtx))
IPPAPI(IppStatus,ippiMoments64s_8u_AC4R,(const Ipp8u* pSrc, int srcStep, IppiSize roiSize, IppiMomentState_64s* pCtx))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:      ippiGetSpatialMoment()
//             ippiGetCentralMoment()
//
//  Purpose:   Retrieves the value of the image spatial/central moment.
//
//  Returns:
//    ippStsNullPtrErr      (pState == NULL) or (pValue == NULL)
//    ippStsContextMatchErr pState->idCtx != idCtxMoment
//    ippStsSizeErr         (mOrd+nOrd) >3 or
//                          (nChannel<0) or (nChannel>=pState->nChannelInUse)
//    ippStsNoErr           if no errors
//
//  Parameters:
//    pState      pointer to the MomentState structure
//    mOrd        m- Order (X direction)
//    nOrd        n- Order (Y direction)
//    nChannel    channel number
//    roiOffset   offset of the ROI origin (ippiGetSpatialMoment ONLY!)
//    pValue      pointer to the retrieved moment value
//    scaleFactor factor to scale the moment value (for integer data)
//
//  NOTE:
//    ippiGetSpatialMoment use Absolute Coordinates (left-top image has 0,0).
//
*/
IPPAPI(IppStatus,ippiGetSpatialMoment_64f,(const IppiMomentState_64f* pState,
                                       int mOrd, int nOrd, int nChannel,
                                       IppiPoint roiOffset, Ipp64f* pValue))
IPPAPI(IppStatus,ippiGetCentralMoment_64f,(const IppiMomentState_64f* pState,
                                       int mOrd, int nOrd, int nChannel,
                                       Ipp64f* pValue))

IPPAPI(IppStatus,ippiGetSpatialMoment_64s,(const IppiMomentState_64s* pState,
                                       int mOrd, int nOrd, int nChannel,
                                       IppiPoint roiOffset, Ipp64s* pValue, int scaleFactor))
IPPAPI(IppStatus,ippiGetCentralMoment_64s,(const IppiMomentState_64s* pState,
                                       int mOrd, int nOrd, int nChannel,
                                       Ipp64s* pValue, int scaleFactor))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:      ippiGetNormalizedSpatialMoment()
//             ippiGetNormalizedCentralMoment()
//
//  Purpose:   Retrieves the normalized value of the image spatial/central moment.
//
//  Returns:
//    ippStsNullPtrErr      (pState == NULL) or (pValue == NULL)
//    ippStsContextMatchErr pState->idCtx != idCtxMoment
//    ippStsSizeErr         (mOrd+nOrd) >3 or
//                          (nChannel<0) or (nChannel>=pState->nChannelInUse)
//    ippStsMoment00ZeroErr mm[0][0] < IPP_EPS52
//    ippStsNoErr           if no errors
//
//  Parameters:
//    pState      pointer to the MomentState structure
//    mOrd        m- Order (X direction)
//    nOrd        n- Order (Y direction)
//    nChannel    channel number
//    roiOffset   offset of the ROI origin (ippiGetSpatialMoment ONLY!)
//    pValue      pointer to the normalized moment value
//    scaleFactor factor to scale the moment value (for integer data)
//
*/
IPPAPI(IppStatus,ippiGetNormalizedSpatialMoment_64f,(const IppiMomentState_64f* pState,
                                   int mOrd, int nOrd, int nChannel,
                                   IppiPoint roiOffset, Ipp64f* pValue))
IPPAPI(IppStatus,ippiGetNormalizedCentralMoment_64f,(const IppiMomentState_64f* pState,
                                   int mOrd, int nOrd, int nChannel,
                                   Ipp64f* pValue))

IPPAPI(IppStatus,ippiGetNormalizedSpatialMoment_64s,(const IppiMomentState_64s* pState,
                                   int mOrd, int nOrd, int nChannel,
                                   IppiPoint roiOffset, Ipp64s* pValue, int scaleFactor))
IPPAPI(IppStatus,ippiGetNormalizedCentralMoment_64s,(const IppiMomentState_64s* pState,
                                   int mOrd, int nOrd, int nChannel,
                                   Ipp64s* pValue, int scaleFactor))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:      ippiGetHuMoments()
//
//  Purpose:   Retrieves image Hu moment invariants.
//
//  Returns:
//    ippStsNullPtrErr      (pState == NULL) or (pHu == NULL)
//    ippStsContextMatchErr pState->idCtx != idCtxMoment
//    ippStsSizeErr         (nChannel<0) or (nChannel>=pState->nChannelInUse)
//    ippStsMoment00ZeroErr mm[0][0] < IPP_EPS52
//    ippStsNoErr           if no errors
//
//  Parameters:
//    pState      pointer to the MomentState structure
//    nChannel    channel number
//    pHm         pointer to the array of the Hu moment invariants
//    scaleFactor factor to scale the moment value (for integer data)
//
//  Notes:
//    We only consider Hu moments up to the 7-th order
*/
IPPAPI(IppStatus,ippiGetHuMoments_64f,(const IppiMomentState_64f* pState,
                                   int nChannel, IppiHuMoment_64f pHm))
IPPAPI(IppStatus,ippiGetHuMoments_64s,(const IppiMomentState_64s* pState,
                                   int nChannel, IppiHuMoment_64s pHm, int scaleFactor))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiNorm_Inf
//  Purpose:        computes the C-norm of pixel values of the image: n = MAX |src1|
//  Context:
//  Returns:        IppStatus
//    ippStsNoErr        Ok
//    ippStsNullPtrErr   Any of the pointers is NULL
//    ippStsSizeErr      roiSize has a field with zero or negative value
//  Parameters:
//    pSrc        Pointer to the source image.
//    srcStep     Step through the source image
//    roiSize     Size of the source ROI.
//    pValue      Pointer to the computed norm (one-channel data)
//    value       Array of the computed norms for each channel (multi-channel data)
//  Notes:
*/

IPPAPI(IppStatus, ippiNorm_Inf_8u_C1R, (const Ipp8u* pSrc, int srcStep,
                                     IppiSize roiSize, Ipp64f* pValue))

IPPAPI(IppStatus, ippiNorm_Inf_8u_C3R, (const Ipp8u* pSrc, int srcStep,
                                     IppiSize roiSize, Ipp64f value[3]))

IPPAPI(IppStatus, ippiNorm_Inf_8u_AC4R, (const Ipp8u* pSrc, int srcStep,
                                     IppiSize roiSize, Ipp64f value[3]))

IPPAPI(IppStatus, ippiNorm_Inf_8u_C4R, (const Ipp8u* pSrc, int srcStep,
                                     IppiSize roiSize, Ipp64f value[4]))

IPPAPI(IppStatus, ippiNorm_Inf_16s_C1R, (const Ipp16s* pSrc, int srcStep,
                                     IppiSize roiSize, Ipp64f* pValue))

IPPAPI(IppStatus, ippiNorm_Inf_16s_C3R, (const Ipp16s* pSrc, int srcStep,
                                     IppiSize roiSize, Ipp64f value[3]))

IPPAPI(IppStatus, ippiNorm_Inf_16s_AC4R, (const Ipp16s* pSrc, int srcStep,
                                     IppiSize roiSize, Ipp64f value[3]))

IPPAPI(IppStatus, ippiNorm_Inf_16s_C4R, (const Ipp16s* pSrc, int srcStep,
                                     IppiSize roiSize, Ipp64f value[4]))

IPPAPI(IppStatus, ippiNorm_Inf_32s_C1R, (const Ipp32s* pSrc, int srcStep,
                                     IppiSize roiSize, Ipp64f* value))
IPPAPI(IppStatus, ippiNorm_Inf_32f_C1R, (const Ipp32f* pSrc, int srcStep,
                                     IppiSize roiSize, Ipp64f* pValue))

IPPAPI(IppStatus, ippiNorm_Inf_32f_C3R, (const Ipp32f* pSrc, int srcStep,
                                     IppiSize roiSize, Ipp64f value[3]))

IPPAPI(IppStatus, ippiNorm_Inf_32f_AC4R, (const Ipp32f* pSrc, int srcStep,
                                     IppiSize roiSize, Ipp64f value[3]))

IPPAPI(IppStatus, ippiNorm_Inf_32f_C4R, (const Ipp32f* pSrc, int srcStep,
                                     IppiSize roiSize, Ipp64f value[4]))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiNorm_L1
//  Purpose:        computes the L1-norm of pixel values of the image: n = SUM |src1|
//  Context:
//  Returns:        IppStatus
//    ippStsNoErr        Ok
//    ippStsNullPtrErr   Any of the pointers is NULL
//    ippStsSizeErr      roiSize has a field with zero or negative value
//  Parameters:
//    pSrc        Pointer to the source image.
//    srcStep     Step through the source image
//    roiSize     Size of the source ROI.
//    pValue      Pointer to the computed norm (one-channel data)
//    value       Array of the computed norms for each channel (multi-channel data)
//    hint        Option to specify the computation algorithm
//  Notes:
*/

IPPAPI(IppStatus, ippiNorm_L1_8u_C1R, (const Ipp8u* pSrc, int srcStep,
                                      IppiSize roiSize, Ipp64f* pValue))

IPPAPI(IppStatus, ippiNorm_L1_8u_C3R, (const Ipp8u* pSrc, int srcStep,
                                      IppiSize roiSize, Ipp64f value[3]))

IPPAPI(IppStatus, ippiNorm_L1_8u_AC4R, (const Ipp8u* pSrc, int srcStep,
                                       IppiSize roiSize, Ipp64f value[3]))

IPPAPI(IppStatus, ippiNorm_L1_8u_C4R, (const Ipp8u* pSrc, int srcStep,
                                       IppiSize roiSize, Ipp64f value[4]))

IPPAPI(IppStatus, ippiNorm_L1_16s_C1R, (const Ipp16s* pSrc, int srcStep,
                                      IppiSize roiSize, Ipp64f* pValue))

IPPAPI(IppStatus, ippiNorm_L1_16s_C3R, (const Ipp16s* pSrc, int srcStep,
                                      IppiSize roiSize, Ipp64f value[3]))

IPPAPI(IppStatus, ippiNorm_L1_16s_AC4R, (const Ipp16s* pSrc, int srcStep,
                                       IppiSize roiSize, Ipp64f value[3]))

IPPAPI(IppStatus, ippiNorm_L1_16s_C4R, (const Ipp16s* pSrc, int srcStep,
                                       IppiSize roiSize, Ipp64f value[4]))

IPPAPI(IppStatus, ippiNorm_L1_32f_C1R, (const Ipp32f* pSrc, int srcStep,
                                      IppiSize roiSize, Ipp64f* pValue, IppHintAlgorithm hint))

IPPAPI(IppStatus, ippiNorm_L1_32f_C3R, (const Ipp32f* pSrc, int srcStep,
                                      IppiSize roiSize, Ipp64f value[3], IppHintAlgorithm hint))

IPPAPI(IppStatus, ippiNorm_L1_32f_AC4R, (const Ipp32f* pSrc, int srcStep,
                                       IppiSize roiSize, Ipp64f value[3], IppHintAlgorithm hint))

IPPAPI(IppStatus, ippiNorm_L1_32f_C4R, (const Ipp32f* pSrc, int srcStep,
                                       IppiSize roiSize, Ipp64f value[4], IppHintAlgorithm hint))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiNorm_L2
//  Purpose:        computes the L2-norm of pixel values of the image: n = SQRT(SUM |src1|^2)
//  Context:
//  Returns:        IppStatus
//    ippStsNoErr        Ok
//    ippStsNullPtrErr   Any of the pointers is NULL
//    ippStsSizeErr      roiSize has a field with zero or negative value
//  Parameters:
//    pSrc        Pointer to the source image.
//    srcStep     Step through the source image
//    roiSize     Size of the source ROI.
//    pValue      Pointer to the computed norm (one-channel data)
//    value       Array of the computed norms for each channel (multi-channel data)
//    hint        Option to specify the computation algorithm
//  Notes:
//    simple mul is better than table for P6 family
*/

IPPAPI(IppStatus, ippiNorm_L2_8u_C1R, (const Ipp8u* pSrc, int srcStep,
                                      IppiSize roiSize, Ipp64f* pValue))

IPPAPI(IppStatus, ippiNorm_L2_8u_C3R, (const Ipp8u* pSrc, int srcStep,
                                      IppiSize roiSize, Ipp64f value[3]))

IPPAPI(IppStatus, ippiNorm_L2_8u_AC4R, (const Ipp8u* pSrc, int srcStep,
                                       IppiSize roiSize, Ipp64f value[3]))

IPPAPI(IppStatus, ippiNorm_L2_8u_C4R, (const Ipp8u* pSrc, int srcStep,
                                       IppiSize roiSize, Ipp64f value[4]))

IPPAPI(IppStatus, ippiNorm_L2_16s_C1R, (const Ipp16s* pSrc, int srcStep,
                                      IppiSize roiSize, Ipp64f* pValue))

IPPAPI(IppStatus, ippiNorm_L2_16s_C3R, (const Ipp16s* pSrc, int srcStep,
                                      IppiSize roiSize, Ipp64f value[3]))

IPPAPI(IppStatus, ippiNorm_L2_16s_AC4R, (const Ipp16s* pSrc, int srcStep,
                                       IppiSize roiSize, Ipp64f value[3]))

IPPAPI(IppStatus, ippiNorm_L2_16s_C4R, (const Ipp16s* pSrc, int srcStep,
                                       IppiSize roiSize, Ipp64f value[4]))

IPPAPI(IppStatus, ippiNorm_L2_32f_C1R, (const Ipp32f* pSrc, int srcStep,
                                      IppiSize roiSize, Ipp64f* pValue, IppHintAlgorithm hint))

IPPAPI(IppStatus, ippiNorm_L2_32f_C3R, (const Ipp32f* pSrc, int srcStep,
                                      IppiSize roiSize, Ipp64f value[3], IppHintAlgorithm hint))

IPPAPI(IppStatus, ippiNorm_L2_32f_AC4R, (const Ipp32f* pSrc, int srcStep,
                                       IppiSize roiSize, Ipp64f value[3], IppHintAlgorithm hint))

IPPAPI(IppStatus, ippiNorm_L2_32f_C4R, (const Ipp32f* pSrc, int srcStep,
                                       IppiSize roiSize, Ipp64f value[4], IppHintAlgorithm hint))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiNormDiff_Inf
//  Purpose:        computes the C-norm of pixel values of two images: n = MAX |src1 - src2|
//  Context:
//  Returns:        IppStatus
//    ippStsNoErr         Ok
//    ippStsNullPtrErr    Any of the pointers is NULL
//    ippStsSizeErr       roiSize has a field with zero or negative value
//  Parameters:
//    pSrc1, pSrc2        Pointers to the source images.
//    src1Step, src2Step  Steps in bytes through the source images
//    roiSize             Size of the source ROI.
//    pValue              Pointer to the computed norm (one-channel data)
//    value               Array of the computed norms for each channel (multi-channel data)
//  Notes:
*/

IPPAPI(IppStatus, ippiNormDiff_Inf_8u_C1R, (const Ipp8u* pSrc1, int src1Step,
                                        const Ipp8u* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f* pValue))

IPPAPI(IppStatus, ippiNormDiff_Inf_8u_C3R, (const Ipp8u* pSrc1, int src1Step,
                                        const Ipp8u* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[3]))

IPPAPI(IppStatus, ippiNormDiff_Inf_8u_AC4R, (const Ipp8u* pSrc1, int src1Step,
                                        const Ipp8u* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[3]))

IPPAPI(IppStatus, ippiNormDiff_Inf_8u_C4R, (const Ipp8u* pSrc1, int src1Step,
                                        const Ipp8u* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[4]))

IPPAPI(IppStatus, ippiNormDiff_Inf_16s_C1R, (const Ipp16s* pSrc1, int src1Step,
                                        const Ipp16s* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f* pValue))

IPPAPI(IppStatus, ippiNormDiff_Inf_16s_C3R, (const Ipp16s* pSrc1, int src1Step,
                                        const Ipp16s* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[3]))

IPPAPI(IppStatus, ippiNormDiff_Inf_16s_AC4R, (const Ipp16s* pSrc1, int src1Step,
                                        const Ipp16s* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[3]))

IPPAPI(IppStatus, ippiNormDiff_Inf_16s_C4R, (const Ipp16s* pSrc1, int src1Step,
                                        const Ipp16s* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[4]))

IPPAPI(IppStatus, ippiNormDiff_Inf_32f_C1R, (const Ipp32f* pSrc1, int src1Step,
                                        const Ipp32f* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f* pValue))

IPPAPI(IppStatus, ippiNormDiff_Inf_32f_C3R, (const Ipp32f* pSrc1, int src1Step,
                                        const Ipp32f* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[3]))

IPPAPI(IppStatus, ippiNormDiff_Inf_32f_AC4R, (const Ipp32f* pSrc1, int src1Step,
                                        const Ipp32f* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[3]))

IPPAPI(IppStatus, ippiNormDiff_Inf_32f_C4R, (const Ipp32f* pSrc1, int src1Step,
                                        const Ipp32f* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[4]))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiNormDiff_L1
//  Purpose:        computes the L1-norm of pixel values of two images: n = SUM |src1 - src2|
//  Context:
//  Returns:        IppStatus
//    ippStsNoErr         Ok
//    ippStsNullPtrErr    Any of the pointers is NULL
//    ippStsSizeErr       roiSize has a field with zero or negative value
//  Parameters:
//    pSrc1, pSrc2        Pointers to the source images.
//    src1Step, src2Step  Steps in bytes through the source images
//    roiSize             Size of the source ROI.
//    pValue              Pointer to the computed norm (one-channel data)
//    value               Array of the computed norms for each channel (multi-channel data)
//    hint                Option to specify the computation algorithm
//  Notes:
*/

IPPAPI(IppStatus, ippiNormDiff_L1_8u_C1R, (const Ipp8u* pSrc1, int src1Step,
                                        const Ipp8u* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f* pValue))

IPPAPI(IppStatus, ippiNormDiff_L1_8u_C3R, (const Ipp8u* pSrc1, int src1Step,
                                        const Ipp8u* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[3]))

IPPAPI(IppStatus, ippiNormDiff_L1_8u_AC4R, (const Ipp8u* pSrc1, int src1Step,
                                        const Ipp8u* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[3]))

IPPAPI(IppStatus, ippiNormDiff_L1_8u_C4R, (const Ipp8u* pSrc1, int src1Step,
                                        const Ipp8u* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[4]))

IPPAPI(IppStatus, ippiNormDiff_L1_16s_C1R, (const Ipp16s* pSrc1, int src1Step,
                                        const Ipp16s* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f* pValue))

IPPAPI(IppStatus, ippiNormDiff_L1_16s_C3R, (const Ipp16s* pSrc1, int src1Step,
                                        const Ipp16s* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[3]))

IPPAPI(IppStatus, ippiNormDiff_L1_16s_AC4R, (const Ipp16s* pSrc1, int src1Step,
                                        const Ipp16s* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[3]))

IPPAPI(IppStatus, ippiNormDiff_L1_16s_C4R, (const Ipp16s* pSrc1, int src1Step,
                                        const Ipp16s* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[4]))

IPPAPI(IppStatus, ippiNormDiff_L1_32f_C1R, (const Ipp32f* pSrc1, int src1Step,
                                        const Ipp32f* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f* pValue, IppHintAlgorithm hint))

IPPAPI(IppStatus, ippiNormDiff_L1_32f_C3R, (const Ipp32f* pSrc1, int src1Step,
                                        const Ipp32f* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[3], IppHintAlgorithm hint))

IPPAPI(IppStatus, ippiNormDiff_L1_32f_AC4R, (const Ipp32f* pSrc1, int src1Step,
                                        const Ipp32f* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[3], IppHintAlgorithm hint))

IPPAPI(IppStatus, ippiNormDiff_L1_32f_C4R, (const Ipp32f* pSrc1, int src1Step,
                                        const Ipp32f* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[4], IppHintAlgorithm hint))

/* /////////////////////////////////////////////////////////////////////////////////
//  Name:           ippiNormDiff_L2
//  Purpose:        computes the L2-norm of pixel values of two images:
//                    n = SQRT(SUM |src1 - src2|^2)
//  Context:
//  Returns:        IppStatus
//    ippStsNoErr         Ok
//    ippStsNullPtrErr    Any of the pointers is NULL
//    ippStsSizeErr       roiSize has a field with zero or negative value
//  Parameters:
//    pSrc1, pSrc2        Pointers to the source images.
//    src1Step, src2Step  Steps in bytes through the source images
//    roiSize             Size of the source ROI.
//    pValue              Pointer to the computed norm (one-channel data)
//    value               Array of the computed norms for each channel (multi-channel data)
//    hint                Option to specify the computation algorithm
//  Notes:
*/

IPPAPI(IppStatus, ippiNormDiff_L2_8u_C1R, (const Ipp8u* pSrc1, int src1Step,
                                        const Ipp8u* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f* pValue))

IPPAPI(IppStatus, ippiNormDiff_L2_8u_C3R, (const Ipp8u* pSrc1, int src1Step,
                                        const Ipp8u* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[3]))

IPPAPI(IppStatus, ippiNormDiff_L2_8u_AC4R, (const Ipp8u* pSrc1, int src1Step,
                                        const Ipp8u* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[3]))

IPPAPI(IppStatus, ippiNormDiff_L2_8u_C4R, (const Ipp8u* pSrc1, int src1Step,
                                        const Ipp8u* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[4]))

IPPAPI(IppStatus, ippiNormDiff_L2_16s_C1R, (const Ipp16s* pSrc1, int src1Step,
                                        const Ipp16s* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f* pValue))

IPPAPI(IppStatus, ippiNormDiff_L2_16s_C3R, (const Ipp16s* pSrc1, int src1Step,
                                        const Ipp16s* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[3]))

IPPAPI(IppStatus, ippiNormDiff_L2_16s_AC4R, (const Ipp16s* pSrc1, int src1Step,
                                        const Ipp16s* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[3]))

IPPAPI(IppStatus, ippiNormDiff_L2_16s_C4R, (const Ipp16s* pSrc1, int src1Step,
                                        const Ipp16s* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[4]))

IPPAPI(IppStatus, ippiNormDiff_L2_32f_C1R, (const Ipp32f* pSrc1, int src1Step,
                                        const Ipp32f* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f* pValue, IppHintAlgorithm hint))

IPPAPI(IppStatus, ippiNormDiff_L2_32f_C3R, (const Ipp32f* pSrc1, int src1Step,
                                        const Ipp32f* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[3], IppHintAlgorithm hint))

IPPAPI(IppStatus, ippiNormDiff_L2_32f_AC4R, (const Ipp32f* pSrc1, int src1Step,
                                        const Ipp32f* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[3], IppHintAlgorithm hint))

IPPAPI(IppStatus, ippiNormDiff_L2_32f_C4R, (const Ipp32f* pSrc1, int src1Step,
                                        const Ipp32f* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[4], IppHintAlgorithm hint))

/* //////////////////////////////////////////////////////////////////////////////////////////
//  Name:           ippiNormRel_Inf
//  Purpose:        computes the relative error for the C-norm of pixel values of two images:
//                      n = MAX |src1 - src2| / MAX |src2|
//  Context:
//  Returns:        IppStatus
//    ippStsNoErr         Ok
//    ippStsNullPtrErr    Any of the pointers is NULL
//    ippStsSizeErr       roiSize has a field with zero or negative value
//    ippStsDivByZero     if MAX |src2| == 0
//  Parameters:
//    pSrc1, pSrc2        Pointers to the source images.
//    src1Step, src2Step  Steps in bytes through the source images
//    roiSize             Size of the source ROI.
//    pValue              Pointer to the computed norm (one-channel data)
//    value               Array of the computed norms for each channel (multi-channel data)
//  Notes:
*/

IPPAPI(IppStatus, ippiNormRel_Inf_8u_C1R, (const Ipp8u* pSrc1, int src1Step,
                                        const Ipp8u* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f* pValue))

IPPAPI(IppStatus, ippiNormRel_Inf_8u_C3R, (const Ipp8u* pSrc1, int src1Step,
                                        const Ipp8u* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[3]))

IPPAPI(IppStatus, ippiNormRel_Inf_8u_AC4R, (const Ipp8u* pSrc1, int src1Step,
                                        const Ipp8u* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[3]))

IPPAPI(IppStatus, ippiNormRel_Inf_8u_C4R, (const Ipp8u* pSrc1, int src1Step,
                                        const Ipp8u* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[4]))

IPPAPI(IppStatus, ippiNormRel_Inf_16s_C1R, (const Ipp16s* pSrc1, int src1Step,
                                        const Ipp16s* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f* pValue))

IPPAPI(IppStatus, ippiNormRel_Inf_16s_C3R, (const Ipp16s* pSrc1, int src1Step,
                                        const Ipp16s* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[3]))

IPPAPI(IppStatus, ippiNormRel_Inf_16s_AC4R, (const Ipp16s* pSrc1, int src1Step,
                                        const Ipp16s* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[3]))

IPPAPI(IppStatus, ippiNormRel_Inf_16s_C4R, (const Ipp16s* pSrc1, int src1Step,
                                        const Ipp16s* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[4]))

IPPAPI(IppStatus, ippiNormRel_Inf_32f_C1R, (const Ipp32f* pSrc1, int src1Step,
                                        const Ipp32f* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f* pValue))

IPPAPI(IppStatus, ippiNormRel_Inf_32f_C3R, (const Ipp32f* pSrc1, int src1Step,
                                        const Ipp32f* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[3]))

IPPAPI(IppStatus, ippiNormRel_Inf_32f_AC4R, (const Ipp32f* pSrc1, int src1Step,
                                        const Ipp32f* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[3]))

IPPAPI(IppStatus, ippiNormRel_Inf_32f_C4R, (const Ipp32f* pSrc1, int src1Step,
                                        const Ipp32f* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[4]))

/* /////////////////////////////////////////////////////////////////////////////////////////
//  Name:           ippiNormRel_L1
//  Purpose:        computes the relative error for the 1-norm of pixel values of two images:
//                      n = SUM |src1 - src2| / SUM |src2|
//  Context:
//  Returns:        IppStatus
//    ippStsNoErr         Ok
//    ippStsNullPtrErr    Any of the pointers is NULL
//    ippStsSizeErr       roiSize has a field with zero or negative value
//    ippStsDivByZero     if SUM |src2| == 0
//  Parameters:
//    pSrc1, pSrc2        Pointers to the source images.
//    src1Step, src2Step  Steps in bytes through the source images
//    roiSize             Size of the source ROI.
//    pValue              Pointer to the computed norm (one-channel data)
//    value               Array of the computed norms for each channel (multi-channel data)
//    hint                Option to specify the computation algorithm
//  Notes:
*/

IPPAPI(IppStatus, ippiNormRel_L1_8u_C1R, (const Ipp8u* pSrc1, int src1Step,
                                        const Ipp8u* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f* pValue))

IPPAPI(IppStatus, ippiNormRel_L1_8u_C3R, (const Ipp8u* pSrc1, int src1Step,
                                        const Ipp8u* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[3]))

IPPAPI(IppStatus, ippiNormRel_L1_8u_AC4R, (const Ipp8u* pSrc1, int src1Step,
                                        const Ipp8u* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[3]))

IPPAPI(IppStatus, ippiNormRel_L1_8u_C4R, (const Ipp8u* pSrc1, int src1Step,
                                        const Ipp8u* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[4]))

IPPAPI(IppStatus, ippiNormRel_L1_16s_C1R, (const Ipp16s* pSrc1, int src1Step,
                                        const Ipp16s* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f* pValue))

IPPAPI(IppStatus, ippiNormRel_L1_16s_C3R, (const Ipp16s* pSrc1, int src1Step,
                                        const Ipp16s* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[3]))

IPPAPI(IppStatus, ippiNormRel_L1_16s_AC4R, (const Ipp16s* pSrc1, int src1Step,
                                        const Ipp16s* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[3]))

IPPAPI(IppStatus, ippiNormRel_L1_16s_C4R, (const Ipp16s* pSrc1, int src1Step,
                                        const Ipp16s* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[4]))

IPPAPI(IppStatus, ippiNormRel_L1_32f_C1R, (const Ipp32f* pSrc1, int src1Step,
                                        const Ipp32f* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f* pValue, IppHintAlgorithm hint))

IPPAPI(IppStatus, ippiNormRel_L1_32f_C3R, (const Ipp32f* pSrc1, int src1Step,
                                        const Ipp32f* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[3], IppHintAlgorithm hint))

IPPAPI(IppStatus, ippiNormRel_L1_32f_AC4R, (const Ipp32f* pSrc1, int src1Step,
                                        const Ipp32f* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[3], IppHintAlgorithm hint))

IPPAPI(IppStatus, ippiNormRel_L1_32f_C4R, (const Ipp32f* pSrc1, int src1Step,
                                        const Ipp32f* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[4], IppHintAlgorithm hint))

/* //////////////////////////////////////////////////////////////////////////////////////////
//  Name:           ippiNormRel_L2
//  Purpose:        computes the relative error for the L2-norm of pixel values of two images:
//                      n = SQRT(SUM |src1 - src2|^2 / SUM |src2|^2)
//  Context:
//  Returns:        IppStatus
//    ippStsNoErr         Ok
//    ippStsNullPtrErr    Any of the pointers is NULL
//    ippStsSizeErr       roiSize has a field with zero or negative value
//    ippStsDivByZero     if SUM |src2|^2 == 0
//  Parameters:
//    pSrc1, pSrc2        Pointers to the source images.
//    src1Step, src2Step  Steps in bytes through the source images
//    roiSize             Size of the source ROI.
//    pValue              Pointer to the computed norm (one-channel data)
//    value               Array of the computed norms for each channel (multi-channel data)
//    hint                Option to specify the computation algorithm
//  Notes:
*/

IPPAPI(IppStatus, ippiNormRel_L2_8u_C1R, (const Ipp8u* pSrc1, int src1Step,
                                        const Ipp8u* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f* pValue))

IPPAPI(IppStatus, ippiNormRel_L2_8u_C3R, (const Ipp8u* pSrc1, int src1Step,
                                        const Ipp8u* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[3]))

IPPAPI(IppStatus, ippiNormRel_L2_8u_AC4R, (const Ipp8u* pSrc1, int src1Step,
                                        const Ipp8u* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[3]))

IPPAPI(IppStatus, ippiNormRel_L2_8u_C4R, (const Ipp8u* pSrc1, int src1Step,
                                        const Ipp8u* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[4]))

IPPAPI(IppStatus, ippiNormRel_L2_16s_C1R, (const Ipp16s* pSrc1, int src1Step,
                                        const Ipp16s* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f* pValue))

IPPAPI(IppStatus, ippiNormRel_L2_16s_C3R, (const Ipp16s* pSrc1, int src1Step,
                                        const Ipp16s* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[3]))

IPPAPI(IppStatus, ippiNormRel_L2_16s_AC4R, (const Ipp16s* pSrc1, int src1Step,
                                        const Ipp16s* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[3]))

IPPAPI(IppStatus, ippiNormRel_L2_16s_C4R, (const Ipp16s* pSrc1, int src1Step,
                                        const Ipp16s* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[4]))

IPPAPI(IppStatus, ippiNormRel_L2_32f_C1R, (const Ipp32f* pSrc1, int src1Step,
                                        const Ipp32f* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f* pValue, IppHintAlgorithm hint))

IPPAPI(IppStatus, ippiNormRel_L2_32f_C3R, (const Ipp32f* pSrc1, int src1Step,
                                        const Ipp32f* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[3], IppHintAlgorithm hint))

IPPAPI(IppStatus, ippiNormRel_L2_32f_AC4R, (const Ipp32f* pSrc1, int src1Step,
                                        const Ipp32f* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[3], IppHintAlgorithm hint))

IPPAPI(IppStatus, ippiNormRel_L2_32f_C4R, (const Ipp32f* pSrc1, int src1Step,
                                        const Ipp32f* pSrc2, int src2Step,
                                        IppiSize roiSize, Ipp64f value[4], IppHintAlgorithm hint))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiSum
//  Purpose:        computes the sum of image pixel values
//  Context:
//  Returns:        IppStatus
//    ippStsNoErr        Ok
//    ippStsNullPtrErr   Any of the pointers is NULL
//    ippStsSizeErr      roiSize has a field with zero or negative value
//    ippStsStepErr      srcStep has a field with zero or negative value
//  Parameters:
//    pSrc        Pointer to the source image.
//    srcStep     Step in bytes through the source image
//    roiSize     Size of the source image ROI.
//    pSum        POinter to the result (one-channel data)
//    sum         Array containing the results (multi-channel data)
//    hint        Option to select the algorithmic implementation of the function
//  Notes:
*/

IPPAPI(IppStatus, ippiSum_8u_C1R, (const Ipp8u* pSrc, int srcStep,
                                   IppiSize roiSize, Ipp64f* pSum))

IPPAPI(IppStatus, ippiSum_8u_C3R, (const Ipp8u* pSrc, int srcStep,
                                   IppiSize roiSize, Ipp64f sum[3]))

IPPAPI(IppStatus, ippiSum_8u_AC4R, (const Ipp8u* pSrc, int srcStep,
                                    IppiSize roiSize, Ipp64f sum[3]))

IPPAPI(IppStatus, ippiSum_8u_C4R, (const Ipp8u* pSrc, int srcStep,
                                    IppiSize roiSize, Ipp64f sum[4]))

IPPAPI(IppStatus, ippiSum_16s_C1R, (const Ipp16s* pSrc, int srcStep,
                                    IppiSize roiSize, Ipp64f* pSum))

IPPAPI(IppStatus, ippiSum_16s_C3R, (const Ipp16s* pSrc, int srcStep,
                                    IppiSize roiSize, Ipp64f sum[3]))

IPPAPI(IppStatus, ippiSum_16s_AC4R, (const Ipp16s* pSrc, int srcStep,
                                     IppiSize roiSize, Ipp64f sum[3]))

IPPAPI(IppStatus, ippiSum_16s_C4R, (const Ipp16s* pSrc, int srcStep,
                                     IppiSize roiSize, Ipp64f sum[4]))

IPPAPI(IppStatus, ippiSum_32f_C1R, (const Ipp32f* pSrc, int srcStep,
                                    IppiSize roiSize, Ipp64f* pSum, IppHintAlgorithm hint))

IPPAPI(IppStatus, ippiSum_32f_C3R, (const Ipp32f* pSrc, int srcStep,
                                    IppiSize roiSize, Ipp64f sum[3], IppHintAlgorithm hint))

IPPAPI(IppStatus, ippiSum_32f_AC4R, (const Ipp32f* pSrc, int srcStep,
                                     IppiSize roiSize, Ipp64f sum[3], IppHintAlgorithm hint))

IPPAPI(IppStatus, ippiSum_32f_C4R, (const Ipp32f* pSrc, int srcStep,
                                     IppiSize roiSize, Ipp64f sum[4], IppHintAlgorithm hint))



/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiMean
//  Purpose:        computes the mean of image pixel values
//  Context:
//  Returns:        IppStatus
//    ippStsNoErr        Ok
//    ippStsNullPtrErr   Any of the pointers is NULL
//    ippStsSizeErr      roiSize has a field with zero or negative value.
//    ippStsStepErr      srcStep is less than or equal to zero
//  Parameters:
//    pSrc        Pointer to the source image.
//    srcStep     Step in bytes through the soutce image
//    roiSize     Size of the source ROI.
//    pMean       Pointer to the result (one-channel data)
//    mean        Array containing the results (multi-channel data)
//    hint        Option to select the algorithmic implementation of the function
//  Notes:
*/

IPPAPI(IppStatus, ippiMean_8u_C1R, (const Ipp8u* pSrc, int srcStep,
                                   IppiSize roiSize, Ipp64f* pMean))

IPPAPI(IppStatus, ippiMean_8u_C3R, (const Ipp8u* pSrc, int srcStep,
                                   IppiSize roiSize, Ipp64f mean[3]))

IPPAPI(IppStatus, ippiMean_8u_AC4R, (const Ipp8u* pSrc, int srcStep,
                                    IppiSize roiSize, Ipp64f mean[3]))

IPPAPI(IppStatus, ippiMean_8u_C4R, (const Ipp8u* pSrc, int srcStep,
                                    IppiSize roiSize, Ipp64f mean[4]))

IPPAPI(IppStatus, ippiMean_16s_C1R, (const Ipp16s* pSrc, int srcStep,
                                    IppiSize roiSize, Ipp64f* pMean))

IPPAPI(IppStatus, ippiMean_16s_C3R, (const Ipp16s* pSrc, int srcStep,
                                    IppiSize roiSize, Ipp64f mean[3]))

IPPAPI(IppStatus, ippiMean_16s_AC4R, (const Ipp16s* pSrc, int srcStep,
                                     IppiSize roiSize, Ipp64f mean[3]))

IPPAPI(IppStatus, ippiMean_16s_C4R, (const Ipp16s* pSrc, int srcStep,
                                     IppiSize roiSize, Ipp64f mean[4]))

IPPAPI(IppStatus, ippiMean_32f_C1R, (const Ipp32f* pSrc, int srcStep,
                                    IppiSize roiSize, Ipp64f* pMean, IppHintAlgorithm hint))

IPPAPI(IppStatus, ippiMean_32f_C3R, (const Ipp32f* pSrc, int srcStep,
                                    IppiSize roiSize, Ipp64f mean[3], IppHintAlgorithm hint))

IPPAPI(IppStatus, ippiMean_32f_AC4R, (const Ipp32f* pSrc, int srcStep,
                                     IppiSize roiSize, Ipp64f mean[3], IppHintAlgorithm hint))

IPPAPI(IppStatus, ippiMean_32f_C4R, (const Ipp32f* pSrc, int srcStep,
                                     IppiSize roiSize, Ipp64f mean[4], IppHintAlgorithm hint))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiHistogramRange
//  Purpose:        computes the intensity histogram of an image
//  Context:
//  Returns:        IppStatus
//    ippStsNoErr        Ok
//    ippStsNullPtrErr   Any of the pointers is NULL
//    ippStsSizeErr      roiSize has a field with zero or negative value
//    ippStsMemAllocErr  There is not enough memory for the inner histogram
//    ippStsHistoNofLevelsErr Number of levels is less than 2
//  Parameters:
//    pSrc        Pointer to the source image.
//    srcStep     Step in bytes through the source image
//    roiSize     Size of the source ROI.
//    pHist       Pointer to the computed histogram.
//    pLevels     Pointer to the array of level values.
//    nLevels     Number of levels
//  Notes:
*/
IPPAPI(IppStatus, ippiHistogramRange_8u_C1R, (const Ipp8u* pSrc, int srcStep, IppiSize roiSize, Ipp32s* pHist, const Ipp32s* pLevels, int nLevels))
IPPAPI(IppStatus, ippiHistogramRange_8u_C3R, (const Ipp8u* pSrc, int srcStep, IppiSize roiSize, Ipp32s* pHist[3], const Ipp32s* pLevels[3], int nLevels[3]))
IPPAPI(IppStatus, ippiHistogramRange_8u_AC4R, (const Ipp8u* pSrc, int srcStep, IppiSize roiSize, Ipp32s* pHist[3], const Ipp32s* pLevels[3], int nLevels[3]))
IPPAPI(IppStatus, ippiHistogramRange_8u_C4R, (const Ipp8u* pSrc, int srcStep, IppiSize roiSize, Ipp32s* pHist[4],  const Ipp32s* pLevels[4], int nLevels[4]))
IPPAPI(IppStatus, ippiHistogramRange_16s_C1R, (const Ipp16s* pSrc, int srcStep, IppiSize roiSize, Ipp32s* pHist, const Ipp32s* pLevels, int nLevels))
IPPAPI(IppStatus, ippiHistogramRange_16s_C3R, (const Ipp16s* pSrc, int srcStep, IppiSize roiSize, Ipp32s* pHist[3],const Ipp32s* pLevels[3], int nLevels[3]))
IPPAPI(IppStatus, ippiHistogramRange_16s_AC4R, (const Ipp16s* pSrc, int srcStep, IppiSize roiSize, Ipp32s* pHist[3],const Ipp32s* pLevels[3], int nLevels[3]))
IPPAPI(IppStatus, ippiHistogramRange_16s_C4R, (const Ipp16s* pSrc, int srcStep, IppiSize roiSize, Ipp32s* pHist[4],const Ipp32s* pLevels[4], int nLevels[4]))
IPPAPI(IppStatus, ippiHistogramRange_32f_C1R, (const Ipp32f* pSrc, int srcStep, IppiSize roiSize, Ipp32s* pHist, const Ipp32f* pLevels, int nLevels))
IPPAPI(IppStatus, ippiHistogramRange_32f_C3R, (const Ipp32f* pSrc, int srcStep, IppiSize roiSize, Ipp32s* pHist[3],  const Ipp32f* pLevels[3], int nLevels[3]))
IPPAPI(IppStatus, ippiHistogramRange_32f_AC4R, (const Ipp32f* pSrc, int srcStep, IppiSize roiSize, Ipp32s* pHist[3], const Ipp32f* pLevels[3], int nLevels[3]))
IPPAPI(IppStatus, ippiHistogramRange_32f_C4R, (const Ipp32f* pSrc, int srcStep, IppiSize roiSize, Ipp32s* pHist[4],  const Ipp32f* pLevels[4], int nLevels[4]))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiHistogramEven
//  Purpose:        computes the intensity histogram of an image
//                  using equal bins - even histogram
//  Context:
//  Returns:        IppStatus
//    ippStsNoErr        Ok
//    ippStsNullPtrErr   Any of the pointers is NULL
//    ippStsSizeErr      roiSize has a field with zero or negative value
//    ippStsMemAllocErr  There is not enough memory for the inner histogram
//    ippStsHistoNofLevelsErr Number of levels is less 2
//  Parameters:
//    pSrc        Pointer to the source image.
//    srcStep     Step in bytes through the source image
//    roiSize     Size of the source ROI.
//    pHist       Pointer to the computed histogram.
//    pLevels     Pointer to the array of level values.
//    nLevels     Number of levels
//    lowerLevel  Lower level boundary
//    upperLevel  Upper level boundary
//  Notes:
*/
IPPAPI(IppStatus, ippiHistogramEven_8u_C1R, (const Ipp8u* pSrc, int srcStep, IppiSize roiSize, Ipp32s* pHist, Ipp32s* pLevels, int nLevels, Ipp32s lowerLevel, Ipp32s upperLevel))
IPPAPI(IppStatus, ippiHistogramEven_8u_C3R, (const Ipp8u* pSrc, int srcStep, IppiSize roiSize, Ipp32s* pHist[3], Ipp32s* pLevels[3], int nLevels[3], Ipp32s lowerLevel[3], Ipp32s upperLevel[3]))
IPPAPI(IppStatus, ippiHistogramEven_8u_AC4R, (const Ipp8u* pSrc, int srcStep, IppiSize roiSize, Ipp32s* pHist[3], Ipp32s* pLevels[3], int nLevels[3], Ipp32s lowerLevel[3], Ipp32s upperLevel[3]))
IPPAPI(IppStatus, ippiHistogramEven_8u_C4R, (const Ipp8u* pSrc, int srcStep, IppiSize roiSize, Ipp32s* pHist[4],  Ipp32s* pLevels[4], int nLevels[4], Ipp32s lowerLevel[4], Ipp32s upperLevel[4]))
IPPAPI(IppStatus, ippiHistogramEven_16s_C1R, (const Ipp16s* pSrc, int srcStep, IppiSize roiSize, Ipp32s* pHist, Ipp32s* pLevels, int nLevels, Ipp32s lowerLevel, Ipp32s upperLevel))
IPPAPI(IppStatus, ippiHistogramEven_16s_C3R, (const Ipp16s* pSrc, int srcStep, IppiSize roiSize, Ipp32s* pHist[3],Ipp32s* pLevels[3], int nLevels[3], Ipp32s lowerLevel[3], Ipp32s upperLevel[3]))
IPPAPI(IppStatus, ippiHistogramEven_16s_AC4R, (const Ipp16s* pSrc, int srcStep, IppiSize roiSize, Ipp32s* pHist[3],Ipp32s* pLevels[3], int nLevels[3], Ipp32s lowerLevel[3], Ipp32s upperLevel[3]))
IPPAPI(IppStatus, ippiHistogramEven_16s_C4R, (const Ipp16s* pSrc, int srcStep, IppiSize roiSize, Ipp32s* pHist[4],Ipp32s* pLevels[4], int nLevels[4], Ipp32s lowerLevel[4], Ipp32s upperLevel[4]))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiLUT
//  Purpose:        Performs intensity transformation of an image
//                  using lookup table (LUT)
//
//  Context:
//  Returns:        IppStatus
//    ippStsNoErr        Ok
//    ippStsNullPtrErr   Any of the pointers is NULL
//    ippStsSizeErr      roiSize has a field with zero or negative value
//    ippStsMemAllocErr  There is not enough memory for the inner histogram
//    ippStsLUTNofLevelsErr Number of levels is less 2
//  Parameters:
//    pSrc        Pointer to the source image.
//    srcStep     Step in bytes through the source image
//    pDst        Pointer to the destination image.
//    dstStep     Step in bytes through the destination image
//    roiSize     Size of the source and destination ROI.
//    pValues     Pointer to the array of intensity values
//    pLevels     Pointer to the array of level values
//    nLevels     Number of levels
//  Notes:
*/
IPPAPI(IppStatus, ippiLUT_8u_C1R,(const Ipp8u* pSrc, int srcStep, Ipp8u* pDst, int dstStep, IppiSize roiSize, const Ipp32s* pValues, const Ipp32s* pLevels, int nLevels))
IPPAPI(IppStatus, ippiLUT_8u_C3R,(const Ipp8u* pSrc, int srcStep, Ipp8u* pDst, int dstStep, IppiSize roiSize, const Ipp32s* pValues[3], const Ipp32s* pLevels[3], int nLevels[3]))
IPPAPI(IppStatus, ippiLUT_8u_AC4R,(const Ipp8u* pSrc, int srcStep, Ipp8u* pDst, int dstStep, IppiSize roiSize, const Ipp32s* pValues[3], const Ipp32s* pLevels[3], int nLevels[3]))
IPPAPI(IppStatus, ippiLUT_8u_C4R,(const Ipp8u* pSrc, int srcStep, Ipp8u* pDst, int dstStep, IppiSize roiSize, const Ipp32s* pValues[4], const Ipp32s* pLevels[4], int nLevels[4]))

IPPAPI(IppStatus, ippiLUT_16s_C1R,(const Ipp16s* pSrc, int srcStep, Ipp16s* pDst, int dstStep, IppiSize roiSize, const Ipp32s* pValues, const Ipp32s* pLevels, int nLevels))
IPPAPI(IppStatus, ippiLUT_16s_C3R,(const Ipp16s* pSrc, int srcStep, Ipp16s* pDst, int dstStep, IppiSize roiSize, const Ipp32s* pValues[3], const Ipp32s* pLevels[3], int nLevels[3]))
IPPAPI(IppStatus, ippiLUT_16s_AC4R,(const Ipp16s* pSrc, int srcStep, Ipp16s* pDst, int dstStep, IppiSize roiSize, const Ipp32s* pValues[3], const Ipp32s* pLevels[3], int nLevels[3]))
IPPAPI(IppStatus, ippiLUT_16s_C4R,(const Ipp16s* pSrc, int srcStep, Ipp16s* pDst, int dstStep, IppiSize roiSize, const Ipp32s* pValues[4], const Ipp32s* pLevels[4], int nLevels[4]))

IPPAPI(IppStatus, ippiLUT_32f_C1R,(const Ipp32f* pSrc, int srcStep, Ipp32f* pDst, int dstStep, IppiSize roiSize, const Ipp32f* pValues, const Ipp32f* pLevels, int nLevels))
IPPAPI(IppStatus, ippiLUT_32f_C3R,(const Ipp32f* pSrc, int srcStep, Ipp32f* pDst, int dstStep, IppiSize roiSize, const Ipp32f* pValues[3], const Ipp32f* pLevels[3], int nLevels[3]))
IPPAPI(IppStatus, ippiLUT_32f_AC4R,(const Ipp32f* pSrc, int srcStep, Ipp32f* pDst, int dstStep, IppiSize roiSize, const Ipp32f* pValues[3], const Ipp32f* pLevels[3], int nLevels[3]))
IPPAPI(IppStatus, ippiLUT_32f_C4R,(const Ipp32f* pSrc, int srcStep, Ipp32f* pDst, int dstStep, IppiSize roiSize, const Ipp32f* pValues[4], const Ipp32f* pLevels[4], int nLevels[4]))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiLUT_Linear
//  Purpose:        Performs intensity transformation of an image
//                  using lookup table (LUT) with linear interpolation
//  Context:
//  Returns:        IppStatus
//    ippStsNoErr        Ok
//    ippStsNullPtrErr   Any of the pointers is NULL
//    ippStsSizeErr      roiSize has a field with zero or negative value
//    ippStsMemAllocErr  There is not enough memory for the inner histogram
//    ippStsLUTNofLevelsErr Number of levels is less 2
//  Parameters:
//    pSrc        Pointer to the source image.
//    srcStep     Step in bytes through the source image
//    pDst        Pointer to the destination image.
//    dstStep     Step in bytes through the destination image
//    roiSize     Size of the source and destination ROI.
//    pValues     Pointer to the array of intensity values
//    pLevels     Pointer to the array of level values
//    nLevels     Number of levels
//  Notes:
*/
IPPAPI(IppStatus, ippiLUT_Linear_8u_C1R,(const Ipp8u* pSrc, int srcStep, Ipp8u* pDst, int dstStep, IppiSize roiSize, const Ipp32s* pValues, const Ipp32s* pLevels, int nLevels))
IPPAPI(IppStatus, ippiLUT_Linear_8u_C3R,(const Ipp8u* pSrc, int srcStep, Ipp8u* pDst, int dstStep, IppiSize roiSize, const Ipp32s* pValues[3], const Ipp32s* pLevels[3], int nLevels[3]))
IPPAPI(IppStatus, ippiLUT_Linear_8u_AC4R,(const Ipp8u* pSrc, int srcStep, Ipp8u* pDst, int dstStep, IppiSize roiSize, const Ipp32s* pValues[3], const Ipp32s* pLevels[3], int nLevels[3]))
IPPAPI(IppStatus, ippiLUT_Linear_8u_C4R,(const Ipp8u* pSrc, int srcStep, Ipp8u* pDst, int dstStep, IppiSize roiSize, const Ipp32s* pValues[4], const Ipp32s* pLevels[4], int nLevels[4]))

IPPAPI(IppStatus, ippiLUT_Linear_16s_C1R,(const Ipp16s* pSrc, int srcStep, Ipp16s* pDst, int dstStep, IppiSize roiSize, const Ipp32s* pValues, const Ipp32s* pLevels, int nLevels))
IPPAPI(IppStatus, ippiLUT_Linear_16s_C3R,(const Ipp16s* pSrc, int srcStep, Ipp16s* pDst, int dstStep, IppiSize roiSize, const Ipp32s* pValues[3], const Ipp32s* pLevels[3], int nLevels[3]))
IPPAPI(IppStatus, ippiLUT_Linear_16s_AC4R,(const Ipp16s* pSrc, int srcStep, Ipp16s* pDst, int dstStep, IppiSize roiSize, const Ipp32s* pValues[3], const Ipp32s* pLevels[3], int nLevels[3]))
IPPAPI(IppStatus, ippiLUT_Linear_16s_C4R,(const Ipp16s* pSrc, int srcStep, Ipp16s* pDst, int dstStep, IppiSize roiSize, const Ipp32s* pValues[4], const Ipp32s* pLevels[4], int nLevels[4]))

IPPAPI(IppStatus, ippiLUT_Linear_32f_C1R,(const Ipp32f* pSrc, int srcStep, Ipp32f* pDst, int dstStep, IppiSize roiSize, const Ipp32f* pValues, const Ipp32f* pLevels, int nLevels))
IPPAPI(IppStatus, ippiLUT_Linear_32f_C3R,(const Ipp32f* pSrc, int srcStep, Ipp32f* pDst, int dstStep, IppiSize roiSize, const Ipp32f* pValues[3], const Ipp32f* pLevels[3], int nLevels[3]))
IPPAPI(IppStatus, ippiLUT_Linear_32f_AC4R,(const Ipp32f* pSrc, int srcStep, Ipp32f* pDst, int dstStep, IppiSize roiSize, const Ipp32f* pValues[3], const Ipp32f* pLevels[3], int nLevels[3]))
IPPAPI(IppStatus, ippiLUT_Linear_32f_C4R,(const Ipp32f* pSrc, int srcStep, Ipp32f* pDst, int dstStep, IppiSize roiSize, const Ipp32f* pValues[4], const Ipp32f* pLevels[4], int nLevels[4]))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiLUT_Cubic
//  Purpose:        Performs intensity transformation of an image
//                  using lookup table (LUT) with cubic interpolation
//  Context:
//  Returns:        IppStatus
//    ippStsNoErr        Ok
//    ippStsNullPtrErr   Any of the pointers is NULL
//    ippStsSizeErr      roiSize has a field with zero or negative value
//    ippStsMemAllocErr  There is not enough memory for the inner histogram
//    ippStsLUTNofLevelsErr Number of levels is less 2
//  Parameters:
//    pSrc        Pointer to the source image.
//    srcStep     Step in bytes through the source image
//    pDst        Pointer to the destination image.
//    dstStep     Step in bytes through the destination image
//    roiSize     Size of the source and destination ROI.
//    pValues     Pointer to the array of intensity values
//    pLevels     Pointer to the array of level values
//    nLevels     Number of levels
//  Notes:
*/
IPPAPI(IppStatus, ippiLUT_Cubic_8u_C1R,(const Ipp8u* pSrc, int srcStep, Ipp8u* pDst, int dstStep, IppiSize roiSize, const Ipp32s* pValues, const Ipp32s* pLevels, int nLevels))
IPPAPI(IppStatus, ippiLUT_Cubic_8u_C3R,(const Ipp8u* pSrc, int srcStep, Ipp8u* pDst, int dstStep, IppiSize roiSize, const Ipp32s* pValues[3], const Ipp32s* pLevels[3], int nLevels[3]))
IPPAPI(IppStatus, ippiLUT_Cubic_8u_AC4R,(const Ipp8u* pSrc, int srcStep, Ipp8u* pDst, int dstStep, IppiSize roiSize, const Ipp32s* pValues[3], const Ipp32s* pLevels[3], int nLevels[3]))
IPPAPI(IppStatus, ippiLUT_Cubic_8u_C4R,(const Ipp8u* pSrc, int srcStep, Ipp8u* pDst, int dstStep, IppiSize roiSize, const Ipp32s* pValues[4], const Ipp32s* pLevels[4], int nLevels[4]))

IPPAPI(IppStatus, ippiLUT_Cubic_16s_C1R,(const Ipp16s* pSrc, int srcStep, Ipp16s* pDst, int dstStep, IppiSize roiSize, const Ipp32s* pValues, const Ipp32s* pLevels, int nLevels))
IPPAPI(IppStatus, ippiLUT_Cubic_16s_C3R,(const Ipp16s* pSrc, int srcStep, Ipp16s* pDst, int dstStep, IppiSize roiSize, const Ipp32s* pValues[3], const Ipp32s* pLevels[3], int nLevels[3]))
IPPAPI(IppStatus, ippiLUT_Cubic_16s_AC4R,(const Ipp16s* pSrc, int srcStep, Ipp16s* pDst, int dstStep, IppiSize roiSize, const Ipp32s* pValues[3], const Ipp32s* pLevels[3], int nLevels[3]))
IPPAPI(IppStatus, ippiLUT_Cubic_16s_C4R,(const Ipp16s* pSrc, int srcStep, Ipp16s* pDst, int dstStep, IppiSize roiSize, const Ipp32s* pValues[4], const Ipp32s* pLevels[4], int nLevels[4]))

IPPAPI(IppStatus, ippiLUT_Cubic_32f_C1R,(const Ipp32f* pSrc, int srcStep, Ipp32f* pDst, int dstStep, IppiSize roiSize, const Ipp32f* pValues, const Ipp32f* pLevels, int nLevels))
IPPAPI(IppStatus, ippiLUT_Cubic_32f_C3R,(const Ipp32f* pSrc, int srcStep, Ipp32f* pDst, int dstStep, IppiSize roiSize, const Ipp32f* pValues[3], const Ipp32f* pLevels[3], int nLevels[3]))
IPPAPI(IppStatus, ippiLUT_Cubic_32f_AC4R,(const Ipp32f* pSrc, int srcStep, Ipp32f* pDst, int dstStep, IppiSize roiSize, const Ipp32f* pValues[3], const Ipp32f* pLevels[3], int nLevels[3]))
IPPAPI(IppStatus, ippiLUT_Cubic_32f_C4R,(const Ipp32f* pSrc, int srcStep, Ipp32f* pDst, int dstStep, IppiSize roiSize, const Ipp32f* pValues[4], const Ipp32f* pLevels[4], int nLevels[4]))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:                ippiCountInRange
//
//  Purpose:             The counter of pixels whose intensity values are in the given range
//
//  Returns:             IppStatus
//      ippStsNoErr,      if no errors
//      ippStsNullPtrErr, if pSrc == NULL
//      ippStsStepErr,    if srcStep is less than or equal to zero
//      ippStsSizeErr,    if roiSize has a field with zero or negative value
//      ippStsRangeErr,   if lowerBound is greater than upperBound
//
//  Parameters:
//      pSrc             pointer to the source buffer
//      roiSize          size of the source ROI
//      srcStep          step through the source image buffer
//      counts           number of pixels within the given intensity range
//      lowerBound       lower limit of the range
//      upperBound       upper limit of the range
*/

IPPAPI(IppStatus, ippiCountInRange_8u_C1R, (const Ipp8u* pSrc, int srcStep, IppiSize roiSize,
                                            int* counts, Ipp8u lowerBound, Ipp8u upperBound))
IPPAPI(IppStatus, ippiCountInRange_8u_C3R, (const Ipp8u* pSrc, int srcStep, IppiSize roiSize,
                                            int counts[3], Ipp8u lowerBound[3], Ipp8u upperBound[3]))
IPPAPI(IppStatus, ippiCountInRange_8u_AC4R, (const Ipp8u* pSrc, int srcStep, IppiSize roiSize,
                                            int counts[3], Ipp8u lowerBound[3], Ipp8u upperBound[3]))
IPPAPI(IppStatus, ippiCountInRange_32f_C1R, (const Ipp32f* pSrc, int srcStep, IppiSize roiSize,
                                            int* counts, Ipp32f lowerBound, Ipp32f upperBound))
IPPAPI(IppStatus, ippiCountInRange_32f_C3R, (const Ipp32f* pSrc, int srcStep, IppiSize roiSize,
                                            int counts[3], Ipp32f lowerBound[3], Ipp32f upperBound[3]))
IPPAPI(IppStatus, ippiCountInRange_32f_AC4R, (const Ipp32f* pSrc, int srcStep, IppiSize roiSize,
                                            int counts[3], Ipp32f lowerBound[3], Ipp32f upperBound[3]))


/* ///////////////////////////////////////////////////////////////////////////
//             Non-linear Filters
/////////////////////////////////////////////////////////////////////////// */

/* ////////////////////////////////////////////////////////////////////////////
//  Names:      ippiFilterMedianHoriz_8u_C1R
//              ippiFilterMedianHoriz_8u_C3R
//              ippiFilterMedianHoriz_8u_AC4R
//              ippiFilterMedianHoriz_16s_C1R
//              ippiFilterMedianHoriz_16s_C3R
//              ippiFilterMedianHoriz_16s_AC4R
//              ippiFilterMedianHoriz_8u_C4R
//              ippiFilterMedianHoriz_16s_C4R
//  Purpose:    Horizontal Median Filter
//  Return:
//   ippStsNoErr       Ok
//   ippStsNullPtrErr  Some of pointers to pSrc or pDst are NULL
//   ippStsSizeErr     Some size of dstRoi less or equal zero
//   ippStsMaskSizeErr Bad mask
//
//  Parameters:
//   pSrc       pointer to input image
//   srcStep    size of input image scan-line
//   pDst       pointer to output image
//   dstStep    size of output image scan-line
//   dstRoiSize ROI size of output image
//   mask       filter mask
*/
IPPAPI(IppStatus,ippiFilterMedianHoriz_8u_C1R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize dstRoiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterMedianHoriz_8u_C3R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize dstRoiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterMedianHoriz_8u_AC4R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize dstRoiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterMedianHoriz_16s_C1R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize dstRoiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterMedianHoriz_16s_C3R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize dstRoiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterMedianHoriz_16s_AC4R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize dstRoiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterMedianHoriz_8u_C4R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize dstRoiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterMedianHoriz_16s_C4R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize dstRoiSize, IppiMaskSize mask))

/* ////////////////////////////////////////////////////////////////////////////
//  Names:      ippiFilterMedianVert_8u_C1R
//              ippiFilterMedianVert_8u_C3R
//              ippiFilterMedianVert_8u_AC4R
//              ippiFilterMedianVert_16s_C1R
//              ippiFilterMedianVert_16s_C3R
//              ippiFilterMedianVert_16s_AC4R
//              ippiFilterMedianVert_8u_C4R
//              ippiFilterMedianVert_16s_C4R
//  Purpose:    Vertical Median Filter
//  Return:
//   ippStsNoErr       Ok
//   ippStsNullPtrErr  Some of pointers to pSrc or pDst are NULL
//   ippStsSizeErr     Some size of dstRoi less or equal zero
//   ippStsMaskSizeErr Bad mask
//
//  Parameters:
//   pSrc       pointer to input image
//   srcStep    size of input image scan-line
//   pDst       pointer to output image
//   dstStep    size of output image scan-line
//   dstRoiSize ROI size of output image
//   mask       filter mask
*/
IPPAPI(IppStatus,ippiFilterMedianVert_8u_C1R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize dstRoiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterMedianVert_8u_C3R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize dstRoiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterMedianVert_8u_AC4R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize dstRoiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterMedianVert_16s_C1R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize dstRoiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterMedianVert_16s_C3R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize dstRoiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterMedianVert_16s_AC4R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize dstRoiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterMedianVert_8u_C4R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize dstRoiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterMedianVert_16s_C4R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize dstRoiSize, IppiMaskSize mask))

/* ////////////////////////////////////////////////////////////////////////////
//  Names:      ippiFilterMedian_8u_C1R
//              ippiFilterMedian_8u_C3R
//              ippiFilterMedian_8u_AC4R
//              ippiFilterMedian_16s_C1R
//              ippiFilterMedian_16s_C3R
//              ippiFilterMedian_16s_AC4R
//              ippiFilterMedian_8u_C4R
//              ippiFilterMedian_16s_C4R
//  Purpose:    Box Median Filter
//  Return:
//   ippStsNoErr       Ok
//   ippStsNullPtrErr  Some of pointers to pSrc or pDst are NULL
//   ippStsSizeErr     Some size of dstRoi less or equal zero
//   ippStsMaskSizeErr Bad mask
//
//  Parameters:
//   pSrc       pointer to input image
//   srcStep    size of input image scan-line
//   pDst       pointer to output image
//   dstStep    size of output image scan-line
//   dstRoiSize ROI size of output image
//   maskSize   size of the mask in pixels
//   anchor     anchor cell specifying thr mask alignment with respect to
//              the position of input
*/
IPPAPI(IppStatus,ippiFilterMedian_8u_C1R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize dstRoiSize, IppiSize maskSize,
       IppiPoint anchor))
IPPAPI(IppStatus,ippiFilterMedian_8u_C3R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize dstRoiSize, IppiSize maskSize,
       IppiPoint anchor))
IPPAPI(IppStatus,ippiFilterMedian_8u_AC4R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize dstRoiSize, IppiSize maskSize,
       IppiPoint anchor))
IPPAPI(IppStatus,ippiFilterMedian_16s_C1R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize dstRoiSize, IppiSize maskSize,
       IppiPoint anchor))
IPPAPI(IppStatus,ippiFilterMedian_16s_C3R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize dstRoiSize, IppiSize maskSize,
       IppiPoint anchor))
IPPAPI(IppStatus,ippiFilterMedian_16s_AC4R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize dstRoiSize, IppiSize maskSize,
       IppiPoint anchor))
IPPAPI(IppStatus,ippiFilterMedian_8u_C4R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize dstRoiSize, IppiSize maskSize,
       IppiPoint anchor))
IPPAPI(IppStatus,ippiFilterMedian_16s_C4R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize dstRoiSize, IppiSize maskSize,
       IppiPoint anchor))

/* ////////////////////////////////////////////////////////////////////////////
//  Names:      ippiFilterMedianCross_8u_C1R
//              ippiFilterMedianCross_8u_C3R
//              ippiFilterMedianCross_8u_AC4R
//              ippiFilterMedianCross_16s_C1R
//              ippiFilterMedianCross_16s_C3R
//              ippiFilterMedianCross_16s_AC4R
//  Purpose:    Cross Median Filter
//  Return:
//   ippStsNoErr       Ok
//   ippStsNullPtrErr  Some of pointers to pSrc or pDst are NULL
//   ippStsSizeErr     Some size of dstRoi less or equal zero
//   ippStsMaskSizeErr Bad mask
//
//  Parameters:
//   pSrc       pointer to input image
//   srcStep    size of input image scan-line
//   pDst       pointer to output image
//   dstStep    size of output image scan-line
//   dstRoiSize ROI size of output image
//   mask       filter mask
*/
IPPAPI(IppStatus,ippiFilterMedianCross_8u_C1R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize dstRoiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterMedianCross_8u_C3R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize dstRoiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterMedianCross_8u_AC4R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize dstRoiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterMedianCross_16s_C1R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize dstRoiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterMedianCross_16s_C3R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize dstRoiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterMedianCross_16s_AC4R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize dstRoiSize, IppiMaskSize mask))

/* ////////////////////////////////////////////////////////////////////////////
//  Names:      ippiFilterMedianColor_8u_C3R
//              ippiFilterMedianColor_8u_AC4R
//              ippiFilterMedianColor_16s_C3R
//              ippiFilterMedianColor_16s_AC4R
//              ippiFilterMedianColor_32f_C3R
//              ippiFilterMedianColor_32f_AC4R
//  Purpose:    Box Color Median Filter
//  Return:
//   ippStsNoErr       Ok
//   ippStsNullPtrErr  Some of pointers to pSrc or pDst are NULL
//   ippStsSizeErr     Some size of dstRoi less or equal zero
//   ippStsMaskSizeErr Bad mask
//
//  Parameters:
//   pSrc       pointer to input image
//   srcStep    size of input image scan-line
//   pDst       pointer to output image
//   dstStep    size of output image scan-line
//   dstRoiSize ROI size of output image
//   mask       filter mask
*/
IPPAPI(IppStatus,ippiFilterMedianColor_8u_C3R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize dstRoiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterMedianColor_8u_AC4R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize dstRoiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterMedianColor_16s_C3R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize dstRoiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterMedianColor_16s_AC4R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize dstRoiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterMedianColor_32f_C3R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize dstRoiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterMedianColor_32f_AC4R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize dstRoiSize, IppiMaskSize mask))


/* ////////////////////////////////////////////////////////////////////////////
//  Names:      ippiFilterMax_8u_C1R
//              ippiFilterMax_8u_C3R
//              ippiFilterMax_8u_AC4R
//              ippiFilterMax_16s_C1R
//              ippiFilterMax_16s_C3R
//              ippiFilterMax_16s_AC4R
//              ippiFilterMax_32f_C1R
//              ippiFilterMax_32f_C3R
//              ippiFilterMax_32f_AC4R
//              ippiFilterMax_8u_C4R
//              ippiFilterMax_16s_C4R
//              ippiFilterMax_32f_C4R
//  Purpose:    Max Filter
//  Return:
//   ippStsNoErr       Ok
//   ippStsNullPtrErr  Some of pointers to pSrc or pDst are NULL
//   ippStsSizeErr     Some size of dstRoi less or equal zero
//   ippStsMaskSizeErr Bad mask size
//   ippStsAnchorErr   Bad anchor point
//
//  Parameters:
//   pSrc       pointer to input image
//   srcStep    size of input image scan-line
//   pDst       pointer to output image
//   dstStep    size of output image scan-line
//   dstRoiSize ROI size of output image
//   maskSize   mask size
//   anchor     anchor point
*/
IPPAPI(IppStatus,ippiFilterMax_8u_C1R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize dstRoiSize, IppiSize maskSize,
       IppiPoint anchor))
IPPAPI(IppStatus,ippiFilterMax_8u_C3R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize dstRoiSize, IppiSize maskSize,
       IppiPoint anchor))
IPPAPI(IppStatus,ippiFilterMax_8u_AC4R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize dstRoiSize, IppiSize maskSize,
       IppiPoint anchor))
IPPAPI(IppStatus,ippiFilterMax_16s_C1R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize dstRoiSize, IppiSize maskSize,
       IppiPoint anchor))
IPPAPI(IppStatus,ippiFilterMax_16s_C3R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize dstRoiSize, IppiSize maskSize,
       IppiPoint anchor))
IPPAPI(IppStatus,ippiFilterMax_16s_AC4R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize dstRoiSize, IppiSize maskSize,
       IppiPoint anchor))
IPPAPI(IppStatus,ippiFilterMax_32f_C1R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize dstRoiSize, IppiSize maskSize,
       IppiPoint anchor))
IPPAPI(IppStatus,ippiFilterMax_32f_C3R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize dstRoiSize, IppiSize maskSize,
       IppiPoint anchor))
IPPAPI(IppStatus,ippiFilterMax_32f_AC4R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize dstRoiSize, IppiSize maskSize,
       IppiPoint anchor))
IPPAPI(IppStatus,ippiFilterMax_8u_C4R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize dstRoiSize, IppiSize maskSize,
       IppiPoint anchor))
IPPAPI(IppStatus,ippiFilterMax_16s_C4R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize dstRoiSize, IppiSize maskSize,
       IppiPoint anchor))
IPPAPI(IppStatus,ippiFilterMax_32f_C4R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize dstRoiSize, IppiSize maskSize,
       IppiPoint anchor))

/* ////////////////////////////////////////////////////////////////////////////
//  Names:      ippiFilterMin_8u_C1R
//              ippiFilterMin_8u_C3R
//              ippiFilterMin_8u_AC4R
//              ippiFilterMin_16s_C1R
//              ippiFilterMin_16s_C3R
//              ippiFilterMin_16s_AC4R
//              ippiFilterMin_32f_C1R
//              ippiFilterMin_32f_C3R
//              ippiFilterMin_32f_AC4R
//              ippiFilterMin_8u_C4R
//              ippiFilterMin_16s_C4R
//              ippiFilterMin_32f_C4R
//  Purpose:    Min Filter
//  Return:
//   ippStsNoErr       Ok
//   ippStsNullPtrErr  Some of pointers to pSrc or pDst are NULL
//   ippStsSizeErr     Some size of dstRoi less or equal zero
//   ippStsMaskSizeErr Bad mask size
//   ippStsAnchorErr   Bad anchor point
//
//  Parameters:
//   pSrc       pointer to input image
//   srcStep    size of input image scan-line
//   pDst       pointer to output image
//   dstStep    size of output image scan-line
//   dstRoiSize ROI size of output image
//   maskSize   mask size
//   anchor     anchor point
*/
IPPAPI(IppStatus,ippiFilterMin_8u_C1R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize dstRoiSize, IppiSize maskSize,
       IppiPoint anchor))
IPPAPI(IppStatus,ippiFilterMin_8u_C3R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize dstRoiSize, IppiSize maskSize,
       IppiPoint anchor))
IPPAPI(IppStatus,ippiFilterMin_8u_AC4R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize dstRoiSize, IppiSize maskSize,
       IppiPoint anchor))
IPPAPI(IppStatus,ippiFilterMin_16s_C1R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize dstRoiSize, IppiSize maskSize,
       IppiPoint anchor))
IPPAPI(IppStatus,ippiFilterMin_16s_C3R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize dstRoiSize, IppiSize maskSize,
       IppiPoint anchor))
IPPAPI(IppStatus,ippiFilterMin_16s_AC4R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize dstRoiSize, IppiSize maskSize,
       IppiPoint anchor))
IPPAPI(IppStatus,ippiFilterMin_32f_C1R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize dstRoiSize, IppiSize maskSize,
       IppiPoint anchor))
IPPAPI(IppStatus,ippiFilterMin_32f_C3R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize dstRoiSize, IppiSize maskSize,
       IppiPoint anchor))
IPPAPI(IppStatus,ippiFilterMin_32f_AC4R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize dstRoiSize, IppiSize maskSize,
       IppiPoint anchor))
IPPAPI(IppStatus,ippiFilterMin_8u_C4R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize dstRoiSize, IppiSize maskSize,
       IppiPoint anchor))
IPPAPI(IppStatus,ippiFilterMin_16s_C4R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize dstRoiSize, IppiSize maskSize,
       IppiPoint anchor))
IPPAPI(IppStatus,ippiFilterMin_32f_C4R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize dstRoiSize, IppiSize maskSize,
       IppiPoint anchor))

/* ///////////////////////////////////////////////////////////////////////////
//             Linear Filters
/////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////
// Name:   ippiFilterBox_8u_C1R
//         ippiFilterBox_8u_C3R
//         ippiFilterBox_8u_AC4R
//         ippiFilterBox_16s_C1R
//         ippiFilterBox_16s_C3R
//         ippiFilterBox_16s_AC4R
//         ippiFilterBox_32f_C1R
//         ippiFilterBox_32f_C3R
//         ippiFilterBox_32f_AC4R
//
// Purpose:    Applies simple neighborhood averaging filter to blur the image.
// Returns:             IppStatus
//      ippStsNoErr,       if no errors.
//      ippStsNullPtrErr,  if pSrc == NULL or pDst == NULL.
//      ippStsSizeErr,     if width or height of images is less or equal zero.
//      ippStsMemAllocErrr,  can not allocate moment buffer.
//      ippStsAnchorErr    if width or height of images is less  zero.
//      ippStsMaskSizeErr  if width or height of cell is less or equal one.
// Parameters:
//      pSrc         - source image data(point to pixel (0,0)).
//      srcStep      - step in src
//      pDst         - resultant image data.
//      dstStep      - step in dst
//      dstRoiSize   - region of interest of dst
//      pSrcDst      - pointer to input for in-place operation
//      srcDstStep   - size of image scan-line for in-place operation
//      roiSize      - region of interest of image for in-place operation
//      maskSize     - Number of columns and rows in the neighbourhood(cell)to use.
//      anchor       - The [x,y] coordinates of the anchor cell in the neighbourhood.
//
*/
IPPAPI(IppStatus, ippiFilterBox_8u_C1R,(const Ipp8u* pSrc,int srcStep ,
       Ipp8u* pDst,int dstStep,IppiSize dstRoiSize, IppiSize maskSize, IppiPoint anchor ))
IPPAPI(IppStatus, ippiFilterBox_8u_C3R,(const Ipp8u* pSrc,int srcStep ,
       Ipp8u* pDst,int dstStep,IppiSize dstRoiSize, IppiSize maskSize, IppiPoint anchor ))
IPPAPI(IppStatus, ippiFilterBox_8u_AC4R,(const Ipp8u* pSrc,int srcStep ,
       Ipp8u* pDst,int dstStep,IppiSize dstRoiSize, IppiSize maskSize, IppiPoint anchor ))
IPPAPI(IppStatus, ippiFilterBox_8u_C4R,(const Ipp8u* pSrc,int srcStep ,
       Ipp8u* pDst,int dstStep,IppiSize dstRoiSize, IppiSize maskSize, IppiPoint anchor))


IPPAPI(IppStatus, ippiFilterBox_16s_C1R,(const Ipp16s* pSrc,int srcStep ,
       Ipp16s* pDst,int dstStep,IppiSize dstRoiSize,IppiSize maskSize, IppiPoint anchor))
IPPAPI(IppStatus, ippiFilterBox_16s_C3R,(const Ipp16s* pSrc,int srcStep ,
       Ipp16s* pDst,int dstStep,IppiSize dstRoiSize, IppiSize maskSize, IppiPoint anchor ))
IPPAPI(IppStatus, ippiFilterBox_16s_AC4R,(const Ipp16s* pSrc,int srcStep ,
       Ipp16s* pDst,int dstStep,IppiSize dstRoiSize,IppiSize maskSize, IppiPoint anchor ))
IPPAPI(IppStatus, ippiFilterBox_16s_C4R,(const Ipp16s* pSrc,int srcStep ,
       Ipp16s* pDst,int dstStep,IppiSize dstRoiSize, IppiSize maskSize, IppiPoint anchor))

IPPAPI(IppStatus, ippiFilterBox_32f_C1R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep,IppiSize dstRoiSize, IppiSize maskSize, IppiPoint anchor))
IPPAPI(IppStatus, ippiFilterBox_32f_C3R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep,IppiSize dstRoiSize, IppiSize maskSize, IppiPoint anchor))
IPPAPI(IppStatus, ippiFilterBox_32f_AC4R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep,IppiSize dstRoiSize, IppiSize maskSize, IppiPoint anchor))
IPPAPI(IppStatus, ippiFilterBox_32f_C4R,(const Ipp32f* pSrc,int srcStep ,
       Ipp32f* pDst,int dstStep,IppiSize dstRoiSize, IppiSize maskSize, IppiPoint anchor))

IPPAPI(IppStatus, ippiFilterBox_8u_C1IR,( Ipp8u* pSrcDst,int srcDstStep,
       IppiSize roiSize, IppiSize maskSize, IppiPoint anchor ))
IPPAPI(IppStatus, ippiFilterBox_8u_C3IR,( Ipp8u* pSrcDst,int srcDstStep,
       IppiSize roiSize, IppiSize maskSize, IppiPoint anchor ))
IPPAPI(IppStatus, ippiFilterBox_8u_AC4IR,( Ipp8u* pSrcDst,int srcDstStep,
       IppiSize roiSize, IppiSize maskSize, IppiPoint anchor ))
IPPAPI(IppStatus, ippiFilterBox_8u_C4IR,( Ipp8u* pSrcDst,int srcDstStep,IppiSize roiSize,IppiSize maskSize,IppiPoint anchor))

IPPAPI(IppStatus, ippiFilterBox_16s_C1IR,( Ipp16s* pSrcDst,int srcDstStep,
       IppiSize roiSize, IppiSize maskSize, IppiPoint anchor ))
IPPAPI(IppStatus, ippiFilterBox_16s_C3IR,( Ipp16s* pSrcDst,int srcDstStep,
       IppiSize roiSize, IppiSize maskSize, IppiPoint anchor ))
IPPAPI(IppStatus, ippiFilterBox_16s_AC4IR,( Ipp16s* pSrc,int srcDstStep,
       IppiSize roiSize, IppiSize maskSize, IppiPoint anchor ))
IPPAPI(IppStatus, ippiFilterBox_16s_C4IR,( Ipp16s* pSrcDst,int srcDstStep,IppiSize roiSize,IppiSize maskSize,IppiPoint anchor))

IPPAPI(IppStatus, ippiFilterBox_32f_C1IR,( Ipp32f* pSrcDst,int srcDstStep ,
       IppiSize roiSize, IppiSize maskSize, IppiPoint anchor ))
IPPAPI(IppStatus, ippiFilterBox_32f_C3IR,( Ipp32f* pSrcDst,int srcDstStep ,
       IppiSize roiSize, IppiSize maskSize, IppiPoint anchor ))
IPPAPI(IppStatus, ippiFilterBox_32f_AC4IR,( Ipp32f* pSrcDst,int srcDstStep,
       IppiSize roiSize, IppiSize maskSize, IppiPoint anchor ))
IPPAPI(IppStatus, ippiFilterBox_32f_C4IR,( Ipp32f* pSrcDst,int srcDstStep,IppiSize roiSize,IppiSize maskSize,IppiPoint anchor))


/* ///////////////////////////////////////////////////////////////////////////
//             Filters with fixed kernal
/////////////////////////////////////////////////////////////////////////// */
/* ////////////////////////////////////////////////////////////////////////////
//  Names:      ippiFilterPrewittHoriz_8u_C1R
//              ippiFilterPrewittHoriz_8u_C3R
//              ippiFilterPrewittHoriz_8u_AC4R
//              ippiFilterPrewittHoriz_16s_C1R
//              ippiFilterPrewittHoriz_16s_C3R
//              ippiFilterPrewittHoriz_16s_AC4R
//              ippiFilterPrewittHoriz_32f_C1R
//              ippiFilterPrewittHoriz_32f_C3R
//              ippiFilterPrewittHoriz_32f_AC4R
//              ippiFilterPrewittVert_8u_C1R
//              ippiFilterPrewittVert_8u_C3R
//              ippiFilterPrewittVert_8u_AC4R
//              ippiFilterPrewittVert_16s_C1R
//              ippiFilterPrewittVert_16s_C3R
//              ippiFilterPrewittVert_16s_AC4R
//              ippiFilterPrewittVert_32f_C1R
//              ippiFilterPrewittVert_32f_C3R
//              ippiFilterPrewittVert_32f_AC4R
//              ippiFilterSobelHoriz_8u_C1R
//              ippiFilterSobelHoriz_8u_C3R
//              ippiFilterSobelHoriz_8u_AC4R
//              ippiFilterSobelHoriz_16s_C1R
//              ippiFilterSobelHoriz_16s_C3R
//              ippiFilterSobelHoriz_16s_AC4R
//              ippiFilterSobelHoriz_32f_C1R
//              ippiFilterSobelHoriz_32f_C3R
//              ippiFilterSobelHoriz_32f_AC4R
//              ippiFilterSobelVert_8u_C1R
//              ippiFilterSobelVert_8u_C3R
//              ippiFilterSobelVert_8u_AC4R
//              ippiFilterSobelVert_16s_C1R
//              ippiFilterSobelVert_16s_C3R
//              ippiFilterSobelVert_16s_AC4R
//              ippiFilterSobelVert_32f_C1R
//              ippiFilterSobelVert_32f_C3R
//              ippiFilterSobelVert_32f_AC4R
//              ippiFilterRobertsDown_8u_C1R
//              ippiFilterRobertsDown_8u_C3R
//              ippiFilterRobertsDown_8u_AC4R
//              ippiFilterRobertsDown_16s_C1R
//              ippiFilterRobertsDown_16s_C3R
//              ippiFilterRobertsDown_16s_AC4R
//              ippiFilterRobertsDown_32f_C1R
//              ippiFilterRobertsDown_32f_C3R
//              ippiFilterRobertsDown_32f_AC4R
//              ippiFilterRobertsUp_8u_C1R
//              ippiFilterRobertsUp_8u_C3R
//              ippiFilterRobertsUp_8u_AC4R
//              ippiFilterRobertsUp_16s_C1R
//              ippiFilterRobertsUp_16s_C3R
//              ippiFilterRobertsUp_16s_AC4R
//              ippiFilterRobertsUp_32f_C1R
//              ippiFilterRobertsUp_32f_C3R
//              ippiFilterRobertsUp_32f_AC4R
//              ippiFilterSharpen_8u_C1R
//              ippiFilterSharpen_8u_C3R
//              ippiFilterSharpen_8u_AC4R
//              ippiFilterSharpen_16s_C1R
//              ippiFilterSharpen_16s_C3R
//              ippiFilterSharpen_16s_AC4R
//              ippiFilterSharpen_32f_C1R
//              ippiFilterSharpen_32f_C3R
//              ippiFilterSharpen_32f_AC4R
//              ippiFilterScharrVert_8u16s_C1R
//              ippiFilterScharrVert_8s16s_C1R
//              ippiFilterScharrVert_32f_C1R
//              ippiFilterScharrHoriz_8u16s_C1R
//              ippiFilterScharrHoriz_8s16s_C1R
//              ippiFilterScharrHoriz_32f_C1R
//              ippiFilterPrewittHoriz_8u_C4R
//              ippiFilterPrewittHoriz_16s_C4R
//              ippiFilterPrewittHoriz_32f_C4R
//              ippiFilterPrewittVert_8u_C4R
//              ippiFilterPrewittVert_16s_C4R
//              ippiFilterPrewittVert_32f_C4R
//              ippiFilterSobelHoriz_8u_C4R
//              ippiFilterSobelHoriz_16s_C4R
//              ippiFilterSobelHoriz_32f_C4R
//              ippiFilterSobelVert_8u_C4R
//              ippiFilterSobelVert_16s_C4R
//              ippiFilterSobelVert_32f_C4R
//              ippiFilterSharpen_8u_C4R
//              ippiFilterSharpen_16s_C4R
//              ippiFilterSharpen_32f_C4R
//
//  Purpose:    Fixed Filter with Matrix
//
//                                1  1  1
//              PrewittHoriz      0  0  0
//                               -1 -1 -1
//
//
//                               -1  0  1
//              PrewittVert      -1  0  1
//                               -1  0  1
//
//
//                                1  2  1
//              SobelHoriz        0  0  0
//                               -1 -2 -1
//
//
//                               -1  0  1
//              SobelVert        -2  0  2
//                               -1  0  1
//
//
//                                0  0  0
//              RobetsDown        0  1  0
//                                0  0 -1
//
//
//                                0  0  0
//              RobertsUp         0  1  0
//                               -1  0  0
//
//
//                               -1 -1  1
//              Sharpen          -1 16  1  X  1/8
//                               -1 -1  1
//
//
//                                3  0  -3
//              ScharrVert       10  0 -10
//                                3  0  -3
//
//
//                                3  10  3
//              ScharrHoriz       0   0  0
//                               -3 -10 -3
//
//
//  Return:
//   ippStsNoErr       Ok
//   ippStsNullPtrErr  Some of pointers to pSrc or pDst are NULL
//   ippStsSizeErr     Some size of roi less or equal zero
//
//  Parameters:
//   pSrc       pointer to input image
//   srcStep    size of input image scan-line
//   pDst       pointer to output image
//   dstStep    size of output image scan-line
//   roiSize    ROI size
*/
IPPAPI(IppStatus,ippiFilterPrewittVert_8u_C1R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterPrewittVert_8u_C3R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterPrewittVert_8u_AC4R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterPrewittVert_16s_C1R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterPrewittVert_16s_C3R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterPrewittVert_16s_AC4R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterPrewittVert_32f_C1R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterPrewittVert_32f_C3R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterPrewittVert_32f_AC4R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterPrewittHoriz_8u_C1R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterPrewittHoriz_8u_C3R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterPrewittHoriz_8u_AC4R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterPrewittHoriz_16s_C1R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterPrewittHoriz_16s_C3R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterPrewittHoriz_16s_AC4R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterPrewittHoriz_32f_C1R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterPrewittHoriz_32f_C3R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterPrewittHoriz_32f_AC4R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterSobelVert_8u_C1R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterSobelVert_8u_C3R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterSobelVert_8u_AC4R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterSobelVert_16s_C1R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterSobelVert_16s_C3R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterSobelVert_16s_AC4R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterSobelVert_32f_C1R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterSobelVert_32f_C3R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterSobelVert_32f_AC4R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterSobelHoriz_8u_C1R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterSobelHoriz_8u_C3R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterSobelHoriz_8u_AC4R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterSobelHoriz_16s_C1R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterSobelHoriz_16s_C3R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterSobelHoriz_16s_AC4R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterSobelHoriz_32f_C1R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterSobelHoriz_32f_C3R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterSobelHoriz_32f_AC4R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterRobertsUp_8u_C1R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterRobertsUp_8u_C3R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterRobertsUp_8u_AC4R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterRobertsUp_16s_C1R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterRobertsUp_16s_C3R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterRobertsUp_16s_AC4R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterRobertsUp_32f_C1R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterRobertsUp_32f_C3R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterRobertsUp_32f_AC4R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterRobertsDown_8u_C1R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterRobertsDown_8u_C3R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterRobertsDown_8u_AC4R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterRobertsDown_16s_C1R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterRobertsDown_16s_C3R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterRobertsDown_16s_AC4R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterRobertsDown_32f_C1R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterRobertsDown_32f_C3R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterRobertsDown_32f_AC4R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterSharpen_8u_C1R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterSharpen_8u_C3R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterSharpen_8u_AC4R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterSharpen_16s_C1R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterSharpen_16s_C3R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterSharpen_16s_AC4R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterSharpen_32f_C1R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterSharpen_32f_C3R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterSharpen_32f_AC4R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterScharrVert_8u16s_C1R,(const Ipp8u* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize ))
IPPAPI(IppStatus,ippiFilterScharrHoriz_8u16s_C1R,(const Ipp8u* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize ))
IPPAPI(IppStatus,ippiFilterScharrVert_8s16s_C1R,(const Ipp8s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize ))
IPPAPI(IppStatus,ippiFilterScharrHoriz_8s16s_C1R,(const Ipp8s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize ))
IPPAPI(IppStatus,ippiFilterScharrVert_32f_C1R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize ))
IPPAPI(IppStatus,ippiFilterScharrHoriz_32f_C1R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize ))
IPPAPI(IppStatus,ippiFilterPrewittVert_8u_C4R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterPrewittVert_16s_C4R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterPrewittVert_32f_C4R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterPrewittHoriz_8u_C4R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterPrewittHoriz_16s_C4R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterPrewittHoriz_32f_C4R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterSobelVert_8u_C4R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterSobelVert_16s_C4R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterSobelVert_32f_C4R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterSobelHoriz_8u_C4R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterSobelHoriz_16s_C4R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterSobelHoriz_32f_C4R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterSharpen_8u_C4R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterSharpen_16s_C4R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus,ippiFilterSharpen_32f_C4R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize))


/* ////////////////////////////////////////////////////////////////////////////
//  Names:      ippiFilterLaplace_8u_C1R
//              ippiFilterLaplace_8u_C3R
//              ippiFilterLaplace_8u_AC4R
//              ippiFilterLaplace_16s_C1R
//              ippiFilterLaplace_16s_C3R
//              ippiFilterLaplace_16s_AC4R
//              ippiFilterLaplace_32f_C1R
//              ippiFilterLaplace_32f_C3R
//              ippiFilterLaplace_32f_AC4R
//              ippiFilterGauss_8u_C1R
//              ippiFilterGauss_8u_C3R
//              ippiFilterGauss_8u_AC4R
//              ippiFilterGauss_16s_C1R
//              ippiFilterGauss_16s_C3R
//              ippiFilterGauss_16s_AC4R
//              ippiFilterGauss_32f_C1R
//              ippiFilterGauss_32f_C3R
//              ippiFilterGauss_32f_AC4R
//              ippiFilterLowpass_8u_C1R
//              ippiFilterLowpass_8u_C3R
//              ippiFilterLowpass_8u_AC4R
//              ippiFilterLowpass_16s_C1R
//              ippiFilterLowpass_16s_C3R
//              ippiFilterLowpass_16s_AC4R
//              ippiFilterLowpass_32f_C1R
//              ippiFilterLowpass_32f_C3R
//              ippiFilterLowpass_32f_AC4R
//              ippiFilterHipass_8u_C1R
//              ippiFilterHipass_8u_C3R
//              ippiFilterHipass_8u_AC4R
//              ippiFilterHipass_16s_C1R
//              ippiFilterHipass_16s_C3R
//              ippiFilterHipass_16s_AC4R
//              ippiFilterHipass_32f_C1R
//              ippiFilterHipass_32f_C3R
//              ippiFilterHipass_32f_AC4R
//              ippiFilterSobelVert_8u16s_C1R
//              ippiFilterSobelVert_8s16s_C1R
//              ippiFilterSobelVertMask_32f_C1R
//              ippiFilterSobelHoriz_8u16s_C1R
//              ippiFilterSobelHoriz_8s16s_C1R
//              ippiFilterSobelHorizMask_32f_C1R
//              ippiFilterSobelVertSecond_8u16s_C1R
//              ippiFilterSobelVertSecond_8s16s_C1R
//              ippiFilterSobelVertSecond_32f_C1R
//              ippiFilterSobelHorizSecond_8u16s_C1R
//              ippiFilterSobelHorizSecond_8s16s_C1R
//              ippiFilterSobelHorizSecond_32f_C1R
//              ippiFilterSobelCross_8u16s_C1R
//              ippiFilterSobelCross_8s16s_C1R
//              ippiFilterSobelCross_32f_C1R
//              ippiFilterLaplace_8u_C4R
//              ippiFilterLaplace_16s_C4R
//              ippiFilterLaplace_32f_C4R
//              ippiFilterGauss_8u_C4R
//              ippiFilterGauss_16s_C4R
//              ippiFilterGauss_32f_C4R
//              ippiFilterHipass_8u_C4R
//              ippiFilterHipass_16s_C4R
//              ippiFilterHipass_32f_C4R
//
//  Purpose:    Fixed Filter with Matrix
//
//                               -1 -1  1
//              Laplace (3x3)    -1  8  1
//                               -1 -1  1
//
//
//                                1  2  1
//              Gauss (3x3)       2  4  2  X  1/16
//                                1  2  1
//
//
//                                1  1  1
//              Lowpass (3x3)     1  1  1  X  1/9
//                                1  1  1
//
//
//                               -1 -1 -1
//              Hipass (3x3 )    -1  8 -1
//                               -1 -1 -1
//
//
//                               -1  0  1
//              SobelVert (3x3)  -2  0  2
//                               -1  0  1
//
//
//                                1  2  1
//              SobelHoriz (3x3)  0  0  0
//                               -1 -2 -1
//
//
//                                       1 -2  1
//              SobelVertSecond (3x3)    2 -4  2
//                                       1 -2  1
//
//
//                                       1  2  1
//              SobelHorizSecond (3x3)  -2 -4 -2
//                                       1  2  1
//
//
//                               -1  0  1
//              SobelCross (3x3)  0  0  0
//                                1  0 -1
//
//
//                               -1 -3 -4 -3 -1
//                               -3  0  6  0 -3
//              Laplace (5x5)    -4  6 20  6 -4
//                               -3  0  6  0 -3
//                               -1 -3 -4 -3 -1
//
//                                2   7  12   7   2
//                                7  31  52  31   7
//              Gauss (5x5)      12  52 127  52  12  X  1/571
//                                7  31  52  31   7
//                                2   7  12   7   2
//
//                                1 1 1 1 1
//                                1 1 1 1 1
//              Lowpass (5x5)     1 1 1 1 1  X  1/25
//                                1 1 1 1 1
//                                1 1 1 1 1
//
//                               -1 -1 -1 -1 -1
//                               -1 -1 -1 -1 -1
//              Hipass (5x5)     -1 -1 24 -1 -1
//                               -1 -1 -1 -1 -1
//                               -1 -1 -1 -1 -1
//
//                               -1  -2   0   2   1
//                               -4  -8   0   8   4
//              SobelVert (5x5)  -6 -12   0  12   6
//                               -4  -8   0   8   4
//                               -1  -2   0   2   1
//
//                                1   4   6   4   1
//                                2   8  12   8   2
//              SobelHoriz (5x5)  0   0   0   0   0
//                               -2  -8 -12  -8  -4
//                               -1  -4  -6  -4  -1
//
//                                       1   0  -2   0   1
//                                       4   0  -8   0   4
//              SobelVertSecond (5x5)    6   0 -12   0   6
//                                       4   0  -8   0   4
//                                       1   0  -2   0   1
//
//                                       1   4   6   4   1
//                                       0   0   0   0   0
//              SobelVertHoriz (5x5)    -2  -8 -12  -8  -2
//                                       0   0   0   0   0
//                                       1   4   6   4   1
//
//                               -1  -2   0   2   1
//                               -2  -4   0   4   2
//              SobelCross (5x5)  0   0   0   0   0
//                                2   4   0  -4  -2
//                                1   2   0  -2  -1
//
//  Return:
//   ippStsNoErr       Ok
//   ippStsNullPtrErr  Some of pointers to pSrc or pDst are NULL
//   ippStsSizeErr     Some size of roi less or equal zero
//   ippStsMaskSizeErr Bad mask
//
//  Parameters:
//   pSrc       pointer to input image
//   srcStep    size of input image scan-line
//   pDst       pointer to output image
//   dstStep    size of output image scan-line
//   roiSize    ROI size
//   mask       filter mask
*/
IPPAPI(IppStatus,ippiFilterLaplace_8u_C1R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterLaplace_8u_C3R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterLaplace_8u_AC4R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterLaplace_16s_C1R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterLaplace_16s_C3R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterLaplace_16s_AC4R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterLaplace_32f_C1R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterLaplace_32f_C3R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterLaplace_32f_AC4R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterGauss_8u_C1R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterGauss_8u_C3R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterGauss_8u_AC4R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterGauss_16s_C1R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterGauss_16s_C3R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterGauss_16s_AC4R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterGauss_32f_C1R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterGauss_32f_C3R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterGauss_32f_AC4R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterHipass_8u_C1R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterHipass_8u_C3R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterHipass_8u_AC4R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterHipass_16s_C1R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterHipass_16s_C3R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterHipass_16s_AC4R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterHipass_32f_C1R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterHipass_32f_C3R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterHipass_32f_AC4R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterLowpass_8u_C1R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterLowpass_8u_C3R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterLowpass_8u_AC4R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterLowpass_16s_C1R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterLowpass_16s_C3R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterLowpass_16s_AC4R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterLowpass_32f_C1R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterLowpass_32f_C3R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterLowpass_32f_AC4R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterLaplace_8u16s_C1R,(const Ipp8u* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask ))
IPPAPI(IppStatus,ippiFilterLaplace_8s16s_C1R,(const Ipp8s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask ))
IPPAPI(IppStatus,ippiFilterSobelVert_8u16s_C1R,(const Ipp8u* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask ))
IPPAPI(IppStatus,ippiFilterSobelHoriz_8u16s_C1R,(const Ipp8u* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask ))
IPPAPI(IppStatus,ippiFilterSobelVertSecond_8u16s_C1R,(const Ipp8u* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask ))
IPPAPI(IppStatus,ippiFilterSobelHorizSecond_8u16s_C1R,(const Ipp8u* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask ))
IPPAPI(IppStatus,ippiFilterSobelCross_8u16s_C1R,(const Ipp8u* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask ))
IPPAPI(IppStatus,ippiFilterSobelVert_8s16s_C1R,(const Ipp8s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask ))
IPPAPI(IppStatus,ippiFilterSobelHoriz_8s16s_C1R,(const Ipp8s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask ))
IPPAPI(IppStatus,ippiFilterSobelVertSecond_8s16s_C1R,(const Ipp8s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask ))
IPPAPI(IppStatus,ippiFilterSobelHorizSecond_8s16s_C1R,(const Ipp8s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask ))
IPPAPI(IppStatus,ippiFilterSobelCross_8s16s_C1R,(const Ipp8s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask ))
IPPAPI(IppStatus,ippiFilterSobelVertMask_32f_C1R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask ))
IPPAPI(IppStatus,ippiFilterSobelHorizMask_32f_C1R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask ))
IPPAPI(IppStatus,ippiFilterSobelVertSecond_32f_C1R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask ))
IPPAPI(IppStatus,ippiFilterSobelHorizSecond_32f_C1R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask ))
IPPAPI(IppStatus,ippiFilterSobelCross_32f_C1R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask ))
IPPAPI(IppStatus,ippiFilterLaplace_8u_C4R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterLaplace_16s_C4R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterLaplace_32f_C4R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterGauss_8u_C4R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterGauss_16s_C4R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterGauss_32f_C4R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterHipass_8u_C4R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterHipass_16s_C4R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask))
IPPAPI(IppStatus,ippiFilterHipass_32f_C4R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize, IppiMaskSize mask))


/* ////////////////////////////////////////////////////////////////////////////
//   Names:     ippiFilter_8u_C1R
//              ippiFilter_8u_C3R
//              ippiFilter_8u_C4R
//              ippiFilter_8u_AC4R
//              ippiFilter_16s_C1R
//              ippiFilter_16s_C3R
//              ippiFilter_16s_C4R
//              ippiFilter_16s_AC4R
//
//  Purpose:    Filters an image using a general integer rectangular kernel.
//  Return:
//   ippStsNoErr       Ok
//   ippStsNullPtrErr  Some of pointers to pSrc, pDst or pKernal are NULL
//   ippStsSizeErr     Some size of dstRoiSize or kernalSize less or equal zero
//   ippStsDivisorErr  Divisor is equal zero, function is aborted.
//
//  Parameters:
//      pSrc        Pointer to the source buffer
//      srcStep     Step in bytes through the source image buffer
//      pDst        Pointer to the destination buffer
//      dstStep     Step in bytes through the destination image buffer
//      dstRoiSize  Size of the source and destination ROI in pixels
//      pKernel     Pointer to the kernel values ( 32s kernel )
//      kernelSize  Size of the rectangular kernel in pixels.
//      anchor      Anchor cell specifying the rectangular kernel alignment
//                  with respect to the position of the input pixel
//      divisor     The integer value by which the computed result is divided.
*/

IPPAPI( IppStatus, ippiFilter_8u_C1R, ( const Ipp8u* pSrc, int srcStep,
        Ipp8u* pDst, int dstStep, IppiSize dstRoiSize, const Ipp32s* pKernel,
        IppiSize kernelSize, IppiPoint anchor, int divisor ))
IPPAPI( IppStatus, ippiFilter_8u_C3R, ( const Ipp8u* pSrc, int srcStep,
        Ipp8u* pDst, int dstStep, IppiSize dstRoiSize, const Ipp32s* pKernel,
        IppiSize kernelSize, IppiPoint anchor, int divisor ))
IPPAPI( IppStatus, ippiFilter_8u_C4R, ( const Ipp8u* pSrc, int srcStep,
        Ipp8u* pDst, int dstStep, IppiSize dstRoiSize, const Ipp32s* pKernel,
        IppiSize kernelSize, IppiPoint anchor, int divisor ))
IPPAPI( IppStatus, ippiFilter_8u_AC4R, ( const Ipp8u* pSrc, int srcStep,
        Ipp8u* pDst, int dstStep, IppiSize dstRoiSize, const Ipp32s* pKernel,
        IppiSize kernelSize, IppiPoint anchor, int divisor ))
IPPAPI( IppStatus, ippiFilter_16s_C1R, ( const Ipp16s* pSrc, int srcStep,
        Ipp16s* pDst, int dstStep, IppiSize dstRoiSize, const Ipp32s* pKernel,
        IppiSize kernelSize, IppiPoint anchor, int divisor ))
IPPAPI( IppStatus, ippiFilter_16s_C3R, ( const Ipp16s* pSrc, int srcStep,
        Ipp16s* pDst, int dstStep, IppiSize dstRoiSize, const Ipp32s* pKernel,
        IppiSize kernelSize, IppiPoint anchor, int divisor ))
IPPAPI( IppStatus, ippiFilter_16s_C4R, ( const Ipp16s* pSrc, int srcStep,
        Ipp16s* pDst, int dstStep, IppiSize dstRoiSize, const Ipp32s* pKernel,
        IppiSize kernelSize, IppiPoint anchor, int divisor ))
IPPAPI( IppStatus, ippiFilter_16s_AC4R, ( const Ipp16s* pSrc, int srcStep,
        Ipp16s* pDst, int dstStep, IppiSize dstRoiSize, const Ipp32s* pKernel,
        IppiSize kernelSize, IppiPoint anchor, int divisor ))

/* ////////////////////////////////////////////////////////////////////////////
//  Names:      ippiFilter32f_8u_C1R
//              ippiFilter32f_8u_C3R
//              ippiFilter32f_8u_C4R
//              ippiFilter32f_8u_AC4R
//              ippiFilter32f_16s_C1R
//              ippiFilter32f_16s_C3R
//              ippiFilter32f_16s_C4R
//              ippiFilter32f_16s_AC4R
//              ippiFilter_32f_C1R
//              ippiFilter_32f_C3R
//              ippiFilter_32f_C4R
//              ippiFilter_32f_AC4R
//  Purpose:    Filters an image using a general float rectangular kernel.
//  Return:
//   ippStsNoErr        Ok
//   ippStsNullPtrErr   Some of pointers to pSrc, pDst or pKernal are NULL
//   ippStsSizeErr      Some size of dstRoiSize or kernalSize less or equal zero
//
//  Parameters:
//      pSrc            Pointer to the source buffer
//      srcStep         Step in bytes through the source image buffer
//      pDst            Pointer to the destination buffer
//      dstStep         Step in bytes through the destination image buffer
//      dstRoiSize      Size of the source and destination ROI in pixels
//      pKernel         Pointer to the kernel values ( 32f kernel )
//      kernelSize      Size of the rectangular kernel in pixels.
//      anchor          Anchor cell specifying the rectangular kernel alignment
//                      with respect to the position of the input pixel
*/
IPPAPI( IppStatus, ippiFilter32f_8u_C1R, ( const Ipp8u* pSrc, int srcStep,
        Ipp8u* pDst, int dstStep, IppiSize dstRoiSize, const Ipp32f* pKernel,
        IppiSize kernelSize, IppiPoint anchor ))
IPPAPI( IppStatus, ippiFilter32f_8u_C3R, ( const Ipp8u* pSrc, int srcStep,
        Ipp8u* pDst, int dstStep, IppiSize dstRoiSize, const Ipp32f* pKernel,
        IppiSize kernelSize, IppiPoint anchor ))
IPPAPI( IppStatus, ippiFilter32f_8u_C4R, ( const Ipp8u* pSrc, int srcStep,
        Ipp8u* pDst, int dstStep, IppiSize dstRoiSize, const Ipp32f* pKernel,
        IppiSize kernelSize, IppiPoint anchor ))
IPPAPI( IppStatus, ippiFilter32f_8u_AC4R, ( const Ipp8u* pSrc, int srcStep,
        Ipp8u* pDst, int dstStep, IppiSize dstRoiSize, const Ipp32f* pKernel,
        IppiSize kernelSize, IppiPoint anchor ))
IPPAPI( IppStatus, ippiFilter32f_16s_C1R, ( const Ipp16s* pSrc, int srcStep,
        Ipp16s* pDst, int dstStep, IppiSize dstRoiSize, const Ipp32f* pKernel,
        IppiSize kernelSize, IppiPoint anchor ))
IPPAPI( IppStatus, ippiFilter32f_16s_C3R, ( const Ipp16s* pSrc, int srcStep,
        Ipp16s* pDst, int dstStep, IppiSize dstRoiSize, const Ipp32f* pKernel,
        IppiSize kernelSize, IppiPoint anchor ))
IPPAPI( IppStatus, ippiFilter32f_16s_C4R, ( const Ipp16s* pSrc, int srcStep,
        Ipp16s* pDst, int dstStep, IppiSize dstRoiSize, const Ipp32f* pKernel,
        IppiSize kernelSize, IppiPoint anchor ))
IPPAPI( IppStatus, ippiFilter32f_16s_AC4R, ( const Ipp16s* pSrc, int srcStep,
        Ipp16s* pDst, int dstStep, IppiSize dstRoiSize, const Ipp32f* pKernel,
        IppiSize kernelSize, IppiPoint anchor ))
IPPAPI( IppStatus, ippiFilter_32f_C1R, ( const Ipp32f* pSrc, int srcStep,
        Ipp32f* pDst, int dstStep, IppiSize dstRoiSize, const Ipp32f* pKernel,
        IppiSize kernelSize, IppiPoint anchor ))
IPPAPI( IppStatus, ippiFilter_32f_C3R, ( const Ipp32f* pSrc, int srcStep,
        Ipp32f* pDst, int dstStep, IppiSize dstRoiSize, const Ipp32f* pKernel,
        IppiSize kernelSize, IppiPoint anchor ))
IPPAPI( IppStatus, ippiFilter_32f_C4R, ( const Ipp32f* pSrc, int srcStep,
        Ipp32f* pDst, int dstStep, IppiSize dstRoiSize, const Ipp32f* pKernel,
        IppiSize kernelSize, IppiPoint anchor ))
IPPAPI( IppStatus, ippiFilter_32f_AC4R, ( const Ipp32f* pSrc, int srcStep,
        Ipp32f* pDst, int dstStep, IppiSize dstRoiSize, const Ipp32f* pKernel,
        IppiSize kernelSize, IppiPoint anchor ))

/* ////////////////////////////////////////////////////////////////////////////
//   Names:     ippiFilterColumn_8u_C1R
//              ippiFilterColumn_8u_C3R
//              ippiFilterColumn_8u_C4R
//              ippiFilterColumn_8u_AC4R
//              ippiFilterColumn_16s_C1R
//              ippiFilterColumn_16s_C3R
//              ippiFilterColumn_16s_C4R
//              ippiFilterColumn_16s_AC4R
//
//  Purpose:    Separable filters use a spatial 32s kernel consisting of a
//              single column
//  Return:
//   ippStsNoErr       Ok
//   ippStsNullPtrErr  Some of pointers to pSrc, pDst or pKernal are NULL
//   ippStsSizeErr     Some size of dstRoiSize or kernalSize less or equal zero
//   ippStsDivisorErr  Divisor is equal zero, function is aborted.
//
//  Parameters:
//      pSrc        Pointer to the source buffer
//      srcStep     Step in bytes through the source image buffer
//      pDst        Pointer to the destination buffer
//      dstStep     Step in bytes through the destination image buffer
//      dstRoiSize  Size of the source and destination ROI in pixels
//      pKernel     Pointer to the column kernel values ( 32s kernel )
//      kernelSize  Size of the column kernel in pixels.
//      yAnchor     Anchor cell specifying the kernel vertical alignment with
//                  respect to the position of the input pixel
//      divisor     The integer value by which the computed result is divided.
*/
IPPAPI( IppStatus, ippiFilterColumn_8u_C1R, ( const Ipp8u* pSrc,
        int srcStep, Ipp8u* pDst, int dstStep, IppiSize dstRoiSize,
        const Ipp32s* pKernel, int kernelSize, int yAnchor, int divisor ))
IPPAPI( IppStatus, ippiFilterColumn_8u_C3R, ( const Ipp8u* pSrc,
        int srcStep, Ipp8u* pDst, int dstStep, IppiSize dstRoiSize,
        const Ipp32s* pKernel, int kernelSize, int yAnchor, int divisor ))
IPPAPI( IppStatus, ippiFilterColumn_8u_C4R, ( const Ipp8u* pSrc,
        int srcStep, Ipp8u* pDst, int dstStep, IppiSize dstRoiSize,
        const Ipp32s* pKernel, int kernelSize, int yAnchor, int divisor ))
IPPAPI( IppStatus, ippiFilterColumn_8u_AC4R, ( const Ipp8u* pSrc,
        int srcStep, Ipp8u* pDst, int dstStep, IppiSize dstRoiSize,
        const Ipp32s* pKernel, int kernelSize, int yAnchor, int divisor ))
IPPAPI( IppStatus, ippiFilterColumn_16s_C1R, ( const Ipp16s* pSrc,
        int srcStep, Ipp16s* pDst, int dstStep, IppiSize dstRoiSize,
        const Ipp32s* pKernel, int kernelSize, int yAnchor, int divisor ))
IPPAPI( IppStatus, ippiFilterColumn_16s_C3R, ( const Ipp16s* pSrc,
        int srcStep, Ipp16s* pDst, int dstStep, IppiSize dstRoiSize,
        const Ipp32s* pKernel, int kernelSize, int yAnchor, int divisor ))
IPPAPI( IppStatus, ippiFilterColumn_16s_C4R, ( const Ipp16s* pSrc,
        int srcStep, Ipp16s* pDst, int dstStep, IppiSize dstRoiSize,
        const Ipp32s* pKernel, int kernelSize, int yAnchor, int divisor ))
IPPAPI( IppStatus, ippiFilterColumn_16s_AC4R, ( const Ipp16s* pSrc,
        int srcStep, Ipp16s* pDst, int dstStep, IppiSize dstRoiSize,
        const Ipp32s* pKernel, int kernelSize, int yAnchor, int divisor ))

/* ////////////////////////////////////////////////////////////////////////////
//  Names:      ippiFilterColumn32f_8u_C1R
//              ippiFilterColumn32f_8u_C3R
//              ippiFilterColumn32f_8u_C4R
//              ippiFilterColumn32f_8u_AC4R
//              ippiFilterColumn32f_16s_C1R
//              ippiFilterColumn32f_16s_C3R
//              ippiFilterColumn32f_16s_C4R
//              ippiFilterColumn32f_16s_AC4R
//              ippiFilterColumn_32f_C1R
//              ippiFilterColumn_32f_C3R
//              ippiFilterColumn_32f_C4R
//              ippiFilterColumn_32f_AC4R
//
//  Purpose:    Separable filters use a spatial 32f kernel consisting of a
//              single column
//  Return:
//   ippStsNoErr       Ok
//   ippStsNullPtrErr  Some of pointers to pSrc, pDst or pKernal are NULL
//   ippStsSizeErr     Some size of dstRoiSize or kernalSize less or equal zero
//
//  Parameters:
//      pSrc        Pointer to the source buffer
//      srcStep     Step in bytes through the source image buffer
//      pDst        Pointer to the destination buffer
//      dstStep     Step in bytes through the destination image buffer
//      dstRoiSize  Size of the source and destination ROI in pixels
//      pKernel     Pointer to the column kernel values ( 32f kernel )
//      kernelSize  Size of the column kernel in pixels.
//      yAnchor     Anchor cell specifying the kernel vertical alignment with
//                  respect to the position of the input pixel
*/
IPPAPI( IppStatus, ippiFilterColumn32f_8u_C1R, ( const Ipp8u* pSrc,
        int srcStep, Ipp8u* pDst, int dstStep, IppiSize dstRoiSize,
        const Ipp32f* pKernel, int kernelSize, int yAnchor ))
IPPAPI( IppStatus, ippiFilterColumn32f_8u_C3R, ( const Ipp8u* pSrc,
        int srcStep, Ipp8u* pDst, int dstStep, IppiSize dstRoiSize,
        const Ipp32f* pKernel, int kernelSize, int yAnchor ))
IPPAPI( IppStatus, ippiFilterColumn32f_8u_C4R, ( const Ipp8u* pSrc,
        int srcStep, Ipp8u* pDst, int dstStep, IppiSize dstRoiSize,
        const Ipp32f* pKernel, int kernelSize, int yAnchor ))
IPPAPI( IppStatus, ippiFilterColumn32f_8u_AC4R, ( const Ipp8u* pSrc,
        int srcStep, Ipp8u* pDst, int dstStep, IppiSize dstRoiSize,
        const Ipp32f* pKernel, int kernelSize, int yAnchor ))
IPPAPI( IppStatus, ippiFilterColumn32f_16s_C1R, ( const Ipp16s* pSrc,
        int srcStep, Ipp16s* pDst, int dstStep, IppiSize dstRoiSize,
        const Ipp32f* pKernel, int kernelSize, int yAnchor ))
IPPAPI( IppStatus, ippiFilterColumn32f_16s_C3R, ( const Ipp16s* pSrc,
        int srcStep, Ipp16s* pDst, int dstStep, IppiSize dstRoiSize,
        const Ipp32f* pKernel, int kernelSize, int yAnchor ))
IPPAPI( IppStatus, ippiFilterColumn32f_16s_C4R, ( const Ipp16s* pSrc,
        int srcStep, Ipp16s* pDst, int dstStep, IppiSize dstRoiSize,
        const Ipp32f* pKernel, int kernelSize, int yAnchor ))
IPPAPI( IppStatus, ippiFilterColumn32f_16s_AC4R, ( const Ipp16s* pSrc,
        int srcStep, Ipp16s* pDst, int dstStep, IppiSize dstRoiSize,
        const Ipp32f* pKernel, int kernelSize, int yAnchor ))
IPPAPI( IppStatus, ippiFilterColumn_32f_C1R, ( const Ipp32f* pSrc,
        int srcStep, Ipp32f* pDst, int dstStep, IppiSize dstRoiSize,
        const Ipp32f* pKernel, int kernelSize, int yAnchor ))
IPPAPI( IppStatus, ippiFilterColumn_32f_C3R, ( const Ipp32f* pSrc,
        int srcStep, Ipp32f* pDst, int dstStep, IppiSize dstRoiSize,
        const Ipp32f* pKernel, int kernelSize, int yAnchor ))
IPPAPI( IppStatus, ippiFilterColumn_32f_C4R, ( const Ipp32f* pSrc,
        int srcStep, Ipp32f* pDst, int dstStep, IppiSize dstRoiSize,
        const Ipp32f* pKernel, int kernelSize, int yAnchor ))
IPPAPI( IppStatus, ippiFilterColumn_32f_AC4R, ( const Ipp32f* pSrc,
        int srcStep, Ipp32f* pDst, int dstStep, IppiSize dstRoiSize,
        const Ipp32f* pKernel, int kernelSize, int yAnchor ))

/* ////////////////////////////////////////////////////////////////////////////
//  Names:      ippiFilterRow_8u_C1R
//              ippiFilterRow_8u_C3R
//              ippiFilterRow_8u_C4R
//              ippiFilterRow_8u_AC4R
//              ippiFilterRow_16s_C1R
//              ippiFilterRow_16s_C3R
//              ippiFilterRow_16s_C4R
//              ippiFilterRow_16s_AC4R
//
//  Purpose:    Separable filters use a spatial 32s kernel consisting of a
//              single row
//  Return:
//   ippStsNoErr       Ok
//   ippStsNullPtrErr  Some of pointers to pSrc, pDst or pKernal are NULL
//   ippStsSizeErr     Some size of dstRoiSize or kernalSize less or equal zero
//   ippStsDivisorErr  Divisor is equal zero, function is aborted.
//
//  Parameters:
//      pSrc        Pointer to the source buffer
//      srcStep     Step in bytes through the source image buffer
//      pDst        Pointer to the destination buffer
//      dstStep     Step in bytes through the destination image buffer
//      dstRoiSize  Size of the source and destination ROI in pixels
//      pKernel     Pointer to the row kernel values ( 32s kernel )
//      kernelSize  Size of the row kernel in pixels.
//      xAnchor     Anchor cell specifying the kernel horizontal alignment with
//                  respect to the position of the input pixel.
//      divisor     The integer value by which the computed result is divided.
*/
IPPAPI( IppStatus, ippiFilterRow_8u_C1R, ( const Ipp8u* pSrc, int srcStep,
        Ipp8u* pDst, int dstStep, IppiSize dstRoiSize, const Ipp32s* pKernel,
        int kernelSize, int xAnchor, int divisor ))
IPPAPI( IppStatus, ippiFilterRow_8u_C3R, ( const Ipp8u* pSrc, int srcStep,
        Ipp8u* pDst, int dstStep, IppiSize dstRoiSize, const Ipp32s* pKernel,
        int kernelSize, int xAnchor, int divisor ))
IPPAPI( IppStatus, ippiFilterRow_8u_C4R, ( const Ipp8u* pSrc, int srcStep,
        Ipp8u* pDst, int dstStep, IppiSize dstRoiSize, const Ipp32s* pKernel,
        int kernelSize, int xAnchor, int divisor ))
IPPAPI( IppStatus, ippiFilterRow_8u_AC4R, ( const Ipp8u* pSrc, int srcStep,
        Ipp8u* pDst, int dstStep, IppiSize dstRoiSize, const Ipp32s* pKernel,
        int kernelSize, int xAnchor, int divisor ))
IPPAPI( IppStatus, ippiFilterRow_16s_C1R, ( const Ipp16s* pSrc, int srcStep,
        Ipp16s* pDst, int dstStep, IppiSize dstRoiSize, const Ipp32s* pKernel,
        int kernelSize, int xAnchor, int divisor ))
IPPAPI( IppStatus, ippiFilterRow_16s_C3R, ( const Ipp16s* pSrc, int srcStep,
        Ipp16s* pDst, int dstStep, IppiSize dstRoiSize, const Ipp32s* pKernel,
        int kernelSize, int xAnchor, int divisor ))
IPPAPI( IppStatus, ippiFilterRow_16s_C4R, ( const Ipp16s* pSrc, int srcStep,
        Ipp16s* pDst, int dstStep, IppiSize dstRoiSize, const Ipp32s* pKernel,
        int kernelSize, int xAnchor, int divisor ))
IPPAPI( IppStatus, ippiFilterRow_16s_AC4R, ( const Ipp16s* pSrc, int srcStep,
        Ipp16s* pDst, int dstStep, IppiSize dstRoiSize, const Ipp32s* pKernel,
        int kernelSize, int xAnchor, int divisor ))

/* ////////////////////////////////////////////////////////////////////////////
//  Names:      ippiFilterRow32f_8u_C1R
//              ippiFilterRow32f_8u_C3R
//              ippiFilterRow32f_8u_C4R
//              ippiFilterRow32f_8u_AC4R
//              ippiFilterRow32f_16s_C1R
//              ippiFilterRow32f_16s_C3R
//              ippiFilterRow32f_16s_C4R
//              ippiFilterRow32f_16s_AC4R
//              ippiFilterRow_32f_C1R
//              ippiFilterRow_32f_C3R
//              ippiFilterRow_32f_C4R
//              ippiFilterRow_32f_AC4R
//
//  Purpose:    Separable filters use a spatial 32f kernel consisting of a
//              single row
//  Return:
//   ippStsNoErr       Ok
//   ippStsNullPtrErr  Some of pointers to pSrc, pDst or pKernal are NULL
//   ippStsSizeErr     Some size of dstRoiSize or kernalSize less or equal zero
//
//  Parameters:
//      pSrc        Pointer to the source buffer;
//      srcStep     Step in bytes through the source image buffer;
//      pDst        Pointer to the destination buffer;
//      dstStep     Step in bytes through the destination image buffer;
//      dstRoiSize  Size of the source and destination ROI in pixels;
//      pKernel     Pointer to the row kernel values ( 32f kernel );
//      kernelSize  Size of the row kernel in pixels;
//      xAnchor     Anchor cell specifying the kernel horizontal alignment with
//                  respect to the position of the input pixel.
*/
IPPAPI( IppStatus, ippiFilterRow32f_8u_C1R, ( const Ipp8u* pSrc, int srcStep,
        Ipp8u* pDst, int dstStep, IppiSize dstRoiSize, const Ipp32f* pKernel,
        int kernelSize, int xAnchor ))
IPPAPI( IppStatus, ippiFilterRow32f_8u_C3R, ( const Ipp8u* pSrc, int srcStep,
        Ipp8u* pDst, int dstStep, IppiSize dstRoiSize, const Ipp32f* pKernel,
        int kernelSize, int xAnchor ))
IPPAPI( IppStatus, ippiFilterRow32f_8u_C4R, ( const Ipp8u* pSrc, int srcStep,
        Ipp8u* pDst, int dstStep, IppiSize dstRoiSize, const Ipp32f* pKernel,
        int kernelSize, int xAnchor ))
IPPAPI( IppStatus, ippiFilterRow32f_8u_AC4R, ( const Ipp8u* pSrc, int srcStep,
        Ipp8u* pDst, int dstStep, IppiSize dstRoiSize, const Ipp32f* pKernel,
        int kernelSize, int xAnchor ))
IPPAPI( IppStatus, ippiFilterRow32f_16s_C1R, ( const Ipp16s* pSrc, int srcStep,
        Ipp16s* pDst, int dstStep, IppiSize dstRoiSize, const Ipp32f* pKernel,
        int kernelSize, int xAnchor ))
IPPAPI( IppStatus, ippiFilterRow32f_16s_C3R, ( const Ipp16s* pSrc, int srcStep,
        Ipp16s* pDst, int dstStep, IppiSize dstRoiSize, const Ipp32f* pKernel,
        int kernelSize, int xAnchor ))
IPPAPI( IppStatus, ippiFilterRow32f_16s_C4R, ( const Ipp16s* pSrc, int srcStep,
        Ipp16s* pDst, int dstStep, IppiSize dstRoiSize, const Ipp32f* pKernel,
        int kernelSize, int xAnchor ))
IPPAPI( IppStatus, ippiFilterRow32f_16s_AC4R, ( const Ipp16s* pSrc, int srcStep,
        Ipp16s* pDst, int dstStep, IppiSize dstRoiSize, const Ipp32f* pKernel,
        int kernelSize, int xAnchor ))
IPPAPI( IppStatus, ippiFilterRow_32f_C1R, ( const Ipp32f* pSrc, int srcStep,
        Ipp32f* pDst, int dstStep, IppiSize dstRoiSize, const Ipp32f* pKernel,
        int kernelSize, int xAnchor ))
IPPAPI( IppStatus, ippiFilterRow_32f_C3R, ( const Ipp32f* pSrc, int srcStep,
        Ipp32f* pDst, int dstStep, IppiSize dstRoiSize, const Ipp32f* pKernel,
        int kernelSize, int xAnchor ))
IPPAPI( IppStatus, ippiFilterRow_32f_C4R, ( const Ipp32f* pSrc, int srcStep,
        Ipp32f* pDst, int dstStep, IppiSize dstRoiSize, const Ipp32f* pKernel,
        int kernelSize, int xAnchor ))
IPPAPI( IppStatus, ippiFilterRow_32f_AC4R, ( const Ipp32f* pSrc, int srcStep,
        Ipp32f* pDst, int dstStep, IppiSize dstRoiSize, const Ipp32f* pKernel,
        int kernelSize, int xAnchor ))


/* ////////////////////////////////////////////////////////////////////////////
//   Names:     ippiConvFull_32f_C1R
//              ippiConvFull_32f_C3R
//              ippiConvFull_32f_AC4R
//              ippiConvFull_16s_C1R
//              ippiConvFull_16s_C3R
//              ippiConvFull_16s_AC4R
//              ippiConvFull_8u_C1R
//              ippiConvFull_8u_C3R
//              ippiConvFull_8u_AC4R
//
//  Purpose: Performs the 2-D convolution of matrices (images). If IppiSize's
//           of matrices are Wa*Ha and Wb*Hb correspondingly, then the
//           IppiSize of the resulting matrice (image) will be
//              (Wa+Wb-1)*(Ha+Hb-1).
//           If the resulting IppiSize > CRITERION, then convolusion is done
//             using 2D FFT.
//
//  Return:
//      ippStsNoErr       Ok;
//      ippStsNullPtrErr  Some of pointers to pSrc1, pSrc2 or pDst are NULL;
//      ippStsSizeErr     Some size of Src1Size, Src2Size or src1Step, src2Step,
//                        dstStep less or equal zero;
//      ippStsDivisorErr  Divisor is equal zero, function is aborted;
//      ippStsMemAllocErr Memory allocation error.
//
//  Parameters:
//      pSrc1       Pointer to the source buffer 1;
//      src1Step    Step in bytes through the source image buffer 1;
//      Src1Size    Size of the source 1 in pixels;
//      pSrc2       Pointer to the source buffer 2;
//      src2Step    Step in bytes through the source image buffer 2;
//      Src2Size    Size of the source 2 in pixels;
//      pDst        Pointer to the destination buffer;
//      dstStep     Step in bytes through the destination image buffer;
//      divisor     The integer value by which the computed result is divided
//                  (in case of 8u or 16s data).
*/

IPPAPI( IppStatus, ippiConvFull_32f_C1R,( const Ipp32f* pSrc1, int src1Step,
        IppiSize Src1Size, const Ipp32f* pSrc2, int src2Step, IppiSize Src2Size,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiConvFull_32f_C3R,( const Ipp32f* pSrc1, int src1Step,
        IppiSize Src1Size, const Ipp32f* pSrc2, int src2Step, IppiSize Src2Size,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiConvFull_32f_AC4R,( const Ipp32f* pSrc1, int src1Step,
        IppiSize Src1Size, const Ipp32f* pSrc2, int src2Step, IppiSize Src2Size,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiConvFull_16s_C1R,( const Ipp16s* pSrc1, int src1Step,
        IppiSize Src1Size, const Ipp16s* pSrc2, int src2Step, IppiSize Src2Size,
        Ipp16s* pDst, int dstStep, int divisor ))
IPPAPI( IppStatus, ippiConvFull_16s_C3R,( const Ipp16s* pSrc1, int src1Step,
        IppiSize Src1Size, const Ipp16s* pSrc2, int src2Step, IppiSize Src2Size,
        Ipp16s* pDst, int dstStep, int divisor ))
IPPAPI( IppStatus, ippiConvFull_16s_AC4R,( const Ipp16s* pSrc1, int src1Step,
        IppiSize Src1Size, const Ipp16s* pSrc2, int src2Step, IppiSize Src2Size,
        Ipp16s* pDst, int dstStep, int divisor ))
IPPAPI( IppStatus, ippiConvFull_8u_C1R,( const Ipp8u* pSrc1, int src1Step,
        IppiSize Src1Size, const Ipp8u* pSrc2, int src2Step, IppiSize Src2Size,
        Ipp8u* pDst, int dstStep, int divisor ))
IPPAPI( IppStatus, ippiConvFull_8u_C3R,( const Ipp8u* pSrc1, int src1Step,
        IppiSize Src1Size, const Ipp8u* pSrc2, int src2Step, IppiSize Src2Size,
        Ipp8u* pDst, int dstStep, int divisor ))
IPPAPI( IppStatus, ippiConvFull_8u_AC4R,( const Ipp8u* pSrc1, int src1Step,
        IppiSize Src1Size, const Ipp8u* pSrc2, int src2Step, IppiSize Src2Size,
        Ipp8u* pDst, int dstStep, int divisor ))



/* ////////////////////////////////////////////////////////////////////////////
//   Names:     ippiConvValid_32f_C1R
//              ippiConvValid_32f_C3R
//              ippiConvValid_32f_AC4R
//              ippiConvValid_16s_C1R
//              ippiConvValid_16s_C3R
//              ippiConvValid_16s_AC4R
//              ippiConvValid_8u_C1R
//              ippiConvValid_8u_C3R
//              ippiConvValid_8u_AC4R
//
//  Purpose: Performs the VALID 2-D convolution of matrices (images).
//           If IppiSize's of matrices (images) are Wa*Ha and Wb*Hb
//           correspondingly, then the IppiSize of the resulting matrice
//           (image) will be (|Wa-Wb|+1)*(|Ha-Hb|+1).
//           If the smalest image IppiSize > CRITERION, then convolusion
//           is done using 2D FFT.
//
//  Return:
//      ippStsNoErr       Ok;
//      ippStsNullPtrErr  Some of pointers to pSrc1, pSrc2 or pDst are NULL;
//      ippStsSizeErr     Some size of Src1Size, Src2Size or src1Step, src2Step,
//                        dstStep less or equal zero;
//      ippStsDivisorErr  Divisor is equal zero, function is aborted;
//      ippStsMemAllocErr Memory allocation error.
//
//  Parameters:
//      pSrc1       Pointer to the source buffer 1;
//      src1Step    Step in bytes through the source image buffer 1;
//      Src1Size    Size of the source 1 in pixels;
//      pSrc2       Pointer to the source buffer 2;
//      src2Step    Step in bytes through the source image buffer 2;
//      Src2Size    Size of the source 2 in pixels;
//      pDst        Pointer to the destination buffer;
//      dstStep     Step in bytes through the destination image buffer;
//      divisor     The integer value by which the computed result is divided
//                  (in case of 8u or 16s data).
*/

IPPAPI( IppStatus, ippiConvValid_32f_C1R,( const Ipp32f* pSrc1, int src1Step,
        IppiSize Src1Size, const Ipp32f* pSrc2, int src2Step, IppiSize Src2Size,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiConvValid_32f_C3R,( const Ipp32f* pSrc1, int src1Step,
        IppiSize Src1Size, const Ipp32f* pSrc2, int src2Step, IppiSize Src2Size,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiConvValid_32f_AC4R,( const Ipp32f* pSrc1, int src1Step,
        IppiSize Src1Size, const Ipp32f* pSrc2, int src2Step, IppiSize Src2Size,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiConvValid_16s_C1R,( const Ipp16s* pSrc1, int src1Step,
        IppiSize Src1Size, const Ipp16s* pSrc2, int src2Step, IppiSize Src2Size,
        Ipp16s* pDst, int dstStep, int divisor ))
IPPAPI( IppStatus, ippiConvValid_16s_C3R,( const Ipp16s* pSrc1, int src1Step,
        IppiSize Src1Size, const Ipp16s* pSrc2, int src2Step, IppiSize Src2Size,
        Ipp16s* pDst, int dstStep, int divisor ))
IPPAPI( IppStatus, ippiConvValid_16s_AC4R,( const Ipp16s* pSrc1, int src1Step,
        IppiSize Src1Size, const Ipp16s* pSrc2, int src2Step, IppiSize Src2Size,
        Ipp16s* pDst, int dstStep, int divisor ))
IPPAPI( IppStatus, ippiConvValid_8u_C1R,( const Ipp8u* pSrc1, int src1Step,
        IppiSize Src1Size, const Ipp8u* pSrc2, int src2Step, IppiSize Src2Size,
        Ipp8u* pDst, int dstStep, int divisor ))
IPPAPI( IppStatus, ippiConvValid_8u_C3R,( const Ipp8u* pSrc1, int src1Step,
        IppiSize Src1Size, const Ipp8u* pSrc2, int src2Step, IppiSize Src2Size,
        Ipp8u* pDst, int dstStep, int divisor ))
IPPAPI( IppStatus, ippiConvValid_8u_AC4R,( const Ipp8u* pSrc1, int src1Step,
        IppiSize Src1Size, const Ipp8u* pSrc2, int src2Step, IppiSize Src2Size,
        Ipp8u* pDst, int dstStep, int divisor ))




/*/////////////////////////////////////////////////////////////////////////////////////////////
//  Names:
//      ippiCrossCorrFull_Norm_32f_C1R,         ippiCrossCorrSame_Norm_32f_C1R,
//      ippiCrossCorrFull_Norm_32f_C3R,         ippiCrossCorrSame_Norm_32f_C3R,
//      ippiCrossCorrFull_Norm_32f_AC4R,        ippiCrossCorrSame_Norm_32f_AC4R,
//      ippiCrossCorrFull_Norm_8u_C1RSfs,       ippiCrossCorrSame_Norm_8u_C1RSfs,
//      ippiCrossCorrFull_Norm_8u_C3RSfs,       ippiCrossCorrSame_Norm_8u_C3RSfs,
//      ippiCrossCorrFull_Norm_8u_AC4RSfs,      ippiCrossCorrSame_Norm_8u_AC4RSfs,
//      ippiCrossCorrFull_Norm_8u32f_C1R,       ippiCrossCorrSame_Norm_8u32f_C1R,
//      ippiCrossCorrFull_Norm_8u32f_C3R,       ippiCrossCorrSame_Norm_8u32f_C3R,
//      ippiCrossCorrFull_Norm_8u32f_AC4R,      ippiCrossCorrSame_Norm_8u32f_AC4R,
//
//      ippiCrossCorrValid_Norm_32f_C1R,
//      ippiCrossCorrValid_Norm_32f_C3R,
//      ippiCrossCorrValid_Norm_32f_AC4R,
//      ippiCrossCorrValid_Norm_8u_C1RSfs,
//      ippiCrossCorrValid_Norm_8u_C3RSfs,
//      ippiCrossCorrValid_Norm_8u_AC4RSfs,
//      ippiCrossCorrValid_Norm_8u32f_C1R,
//      ippiCrossCorrValid_Norm_8u32f_C3R,
//      ippiCrossCorrValid_Norm_8u32f_AC4R.
//
//      ippiCrossCorrFull_Norm_32f_C4R,    ippiCrossCorrSame_Norm_32f_C4R,
//      ippiCrossCorrFull_Norm_8u_C4RSfs,  ippiCrossCorrSame_Norm_8u_C4RSfs,
//      ippiCrossCorrFull_Norm_8u32f_C4R,  ippiCrossCorrSame_Norm_8u32f_C4R,
//      ippiCrossCorrFull_Norm_8s32f_C1R,  ippiCrossCorrSame_Norm_8s32f_C1R,
//      ippiCrossCorrFull_Norm_8s32f_C3R,  ippiCrossCorrSame_Norm_8s32f_C3R,
//      ippiCrossCorrFull_Norm_8s32f_C4R,  ippiCrossCorrSame_Norm_8s32f_C4R,
//      ippiCrossCorrFull_Norm_8s32f_AC4R, ippiCrossCorrSame_Norm_8s32f_AC4R,
//
//      ippiCrossCorrValid_Norm_32f_C4R,
//      ippiCrossCorrValid_Norm_8u_C4RSfs,
//      ippiCrossCorrValid_Norm_8u32f_C4R,
//      ippiCrossCorrValid_Norm_8s32f_C1R,
//      ippiCrossCorrValid_Norm_8s32f_C3R,
//      ippiCrossCorrValid_Norm_8s32f_C4R,
//      ippiCrossCorrValid_Norm_8s32f_AC4R.
//
//  Purpose: ippiCrossCorr_Norm() function allows you to compute the
//           cross-correlation of an image and a template (another image).
//           The cross-correlation values are image similarity measures: the
//           higher cross-correlation at a particular pixel, the more
//           similarity between the template and the image in the neighborhood
//           of the pixel. If IppiSize's of image and template are Wa * Ha and
//           Wb * Hb correspondingly, then the IppiSize of the resulting
//           matrice with normalized cross-correlation coefficients will be
//           a) in case of 'Full' suffix:
//              ( Wa + Wb - 1 )*( Ha + Hb - 1 ).
//           b) in case of 'Same' suffix:
//              ( Wa )*( Ha ).
//           c) in case of 'Valid' suffix:
//              ( Wa - Wb + 1 )*( Ha - Hb + 1 ).
//  Notice:
//           suffix 'R' (ROI) means only scanline alingment (srcStep), in
//           'Same' and 'Full' cases no any requirements for data outstand
//           the ROI - it's assumes that template and src are zerro padded.
//
//           Intel(R) Performance Primitives Libraries
//           for Image Processing  (ippi)
//
//  Arguments:
//      pSrc        - pointer to the source image ROI;
//      srcStep     - step in bytes through the source image buffer;
//      srcRoiSize  - size of the source ROI in pixels;
//      pTpl        - pointer to the template ( feature ) image ROI;
//      tplStep     - step in bytes through the template image buffer;
//      tplRoiSize  - size of the template ROI in pixels;
//      pDst        - pointer to the destination buffer;
//      dstStep     - step in bytes through the destination image buffer;
//      scaleFactor - scale factor value ( in case of integer output data ).
//
//  Return:
//   ippStsNoErr        - Ok
//   ippStsNullPtrErr   - at least one of the pointers to pSrc, pDst or pTpl
//                                                                   is NULL;
//   ippStsSizeErr      - at least one of the sizes of srcRoiSize or tplRoiSize
//                        is less or equal zero, or at least one of the sizes
//                        of srcRoiSize is smaller then the corresponding size
//                        of the tplRoiSize;
//   ippStsStepErr      - at least one of the srcStep, tplStep or dstStep is
//                                                          less or equal zero;
//   ippStsMemAllocErr  - an error occur during allocation memory for internal
//                                                                     buffers.
*/

IPPAPI( IppStatus, ippiCrossCorrFull_Norm_32f_C1R, ( const Ipp32f* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp32f* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrFull_Norm_32f_C3R, ( const Ipp32f* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp32f* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrFull_Norm_32f_AC4R, ( const Ipp32f* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp32f* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrFull_Norm_8u32f_C1R, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrFull_Norm_8u32f_C3R, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrFull_Norm_8u32f_AC4R, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrFull_Norm_8u_C1RSfs, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp8u* pDst, int dstStep, int scaleFactor ))
IPPAPI( IppStatus, ippiCrossCorrFull_Norm_8u_C3RSfs, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp8u* pDst, int dstStep, int scaleFactor ))
IPPAPI( IppStatus, ippiCrossCorrFull_Norm_8u_AC4RSfs, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp8u* pDst, int dstStep, int scaleFactor ))

IPPAPI( IppStatus, ippiCrossCorrValid_Norm_32f_C1R, ( const Ipp32f* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp32f* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrValid_Norm_32f_C3R, ( const Ipp32f* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp32f* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrValid_Norm_32f_AC4R, ( const Ipp32f* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp32f* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrValid_Norm_8u32f_C1R, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrValid_Norm_8u32f_C3R, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrValid_Norm_8u32f_AC4R, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrValid_Norm_8u_C1RSfs, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp8u* pDst, int dstStep, int scaleFactor ))
IPPAPI( IppStatus, ippiCrossCorrValid_Norm_8u_C3RSfs, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp8u* pDst, int dstStep, int scaleFactor ))
IPPAPI( IppStatus, ippiCrossCorrValid_Norm_8u_AC4RSfs, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp8u* pDst, int dstStep, int scaleFactor ))

IPPAPI( IppStatus, ippiCrossCorrSame_Norm_32f_C1R, ( const Ipp32f* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp32f* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrSame_Norm_32f_C3R, ( const Ipp32f* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp32f* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrSame_Norm_32f_AC4R, ( const Ipp32f* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp32f* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrSame_Norm_8u32f_C1R, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrSame_Norm_8u32f_C3R, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrSame_Norm_8u32f_AC4R, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrSame_Norm_8u_C1RSfs, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp8u* pDst, int dstStep, int scaleFactor ))
IPPAPI( IppStatus, ippiCrossCorrSame_Norm_8u_C3RSfs, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp8u* pDst, int dstStep, int scaleFactor ))
IPPAPI( IppStatus, ippiCrossCorrSame_Norm_8u_AC4RSfs, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp8u* pDst, int dstStep, int scaleFactor ))
IPPAPI( IppStatus, ippiCrossCorrFull_Norm_32f_C4R, ( const Ipp32f* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp32f* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrFull_Norm_8u32f_C4R, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrFull_Norm_8s32f_C1R, ( const Ipp8s* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8s* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrFull_Norm_8s32f_C3R, ( const Ipp8s* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8s* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrFull_Norm_8s32f_C4R, ( const Ipp8s* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8s* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrFull_Norm_8s32f_AC4R, ( const Ipp8s* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8s* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrFull_Norm_8u_C4RSfs, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp8u* pDst, int dstStep, int scaleFactor ))

IPPAPI( IppStatus, ippiCrossCorrValid_Norm_32f_C4R, ( const Ipp32f* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp32f* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrValid_Norm_8u32f_C4R, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrValid_Norm_8s32f_C1R, ( const Ipp8s* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8s* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrValid_Norm_8s32f_C3R, ( const Ipp8s* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8s* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrValid_Norm_8s32f_C4R, ( const Ipp8s* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8s* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrValid_Norm_8s32f_AC4R, ( const Ipp8s* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8s* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrValid_Norm_8u_C4RSfs, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp8u* pDst, int dstStep, int scaleFactor ))

IPPAPI( IppStatus, ippiCrossCorrSame_Norm_32f_C4R, ( const Ipp32f* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp32f* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrSame_Norm_8u32f_C4R, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrSame_Norm_8s32f_C1R, ( const Ipp8s* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8s* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrSame_Norm_8s32f_C3R, ( const Ipp8s* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8s* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrSame_Norm_8s32f_C4R, ( const Ipp8s* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8s* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrSame_Norm_8s32f_AC4R, ( const Ipp8s* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8s* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrSame_Norm_8u_C4RSfs, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp8u* pDst, int dstStep, int scaleFactor ))

/*/////////////////////////////////////////////////////////////////////////////////////////////
//  Names:
//      ippiCrossCorrFull_NormLevel_32f_C1R,    ippiCrossCorrSame_NormLevel_32f_C1R,
//      ippiCrossCorrFull_NormLevel_32f_C3R,    ippiCrossCorrSame_NormLevel_32f_C3R,
//      ippiCrossCorrFull_NormLevel_32f_C4R,    ippiCrossCorrSame_NormLevel_32f_C4R,
//      ippiCrossCorrFull_NormLevel_32f_AC4R,   ippiCrossCorrSame_NormLevel_32f_AC4R,
//      ippiCrossCorrFull_NormLevel_8u_C1RSfs,  ippiCrossCorrSame_NormLevel_8u_C1RSfs,
//      ippiCrossCorrFull_NormLevel_8u_C3RSfs,  ippiCrossCorrSame_NormLevel_8u_C3RSfs,
//      ippiCrossCorrFull_NormLevel_8u_C4RSfs,  ippiCrossCorrSame_NormLevel_8u_C4RSfs,
//      ippiCrossCorrFull_NormLevel_8u_AC4RSfs, ippiCrossCorrSame_NormLevel_8u_AC4RSfs,
//      ippiCrossCorrFull_NormLevel_8u32f_C1R,  ippiCrossCorrSame_NormLevel_8u32f_C1R,
//      ippiCrossCorrFull_NormLevel_8u32f_C3R,  ippiCrossCorrSame_NormLevel_8u32f_C3R,
//      ippiCrossCorrFull_NormLevel_8u32f_C4R,  ippiCrossCorrSame_NormLevel_8u32f_C4R,
//      ippiCrossCorrFull_NormLevel_8u32f_AC4R, ippiCrossCorrSame_NormLevel_8u32f_AC4R,
//      ippiCrossCorrFull_NormLevel_8s32f_C1R,  ippiCrossCorrSame_NormLevel_8s32f_C1R,
//      ippiCrossCorrFull_NormLevel_8s32f_C3R,  ippiCrossCorrSame_NormLevel_8s32f_C3R,
//      ippiCrossCorrFull_NormLevel_8s32f_C4R,  ippiCrossCorrSame_NormLevel_8s32f_C4R,
//      ippiCrossCorrFull_NormLevel_8s32f_AC4R, ippiCrossCorrSame_NormLevel_8s32f_AC4R,
//
//      ippiCrossCorrValid_NormLevel_32f_C1R,
//      ippiCrossCorrValid_NormLevel_32f_C3R,
//      ippiCrossCorrValid_NormLevel_32f_C4R,
//      ippiCrossCorrValid_NormLevel_32f_AC4R,
//      ippiCrossCorrValid_NormLevel_8u_C1RSfs,
//      ippiCrossCorrValid_NormLevel_8u_C3RSfs,
//      ippiCrossCorrValid_NormLevel_8u_C4RSfs,
//      ippiCrossCorrValid_NormLevel_8u_AC4RSfs,
//      ippiCrossCorrValid_NormLevel_8u32f_C1R,
//      ippiCrossCorrValid_NormLevel_8u32f_C3R,
//      ippiCrossCorrValid_NormLevel_8u32f_C4R,
//      ippiCrossCorrValid_NormLevel_8u32f_AC4R,
//      ippiCrossCorrValid_NormLevel_8s32f_C1R,
//      ippiCrossCorrValid_NormLevel_8s32f_C3R,
//      ippiCrossCorrValid_NormLevel_8s32f_C4R,
//      ippiCrossCorrValid_NormLevel_8s32f_AC4R.
//
//  Purpose: ippiCrossCorr_NormLevel() function allows you to compute the
//           cross-correlation of an image and a template (another image).
//           The cross-correlation values are image similarity measures: the
//           higher cross-correlation at a particular pixel, the more
//           similarity between the template and the image in the neighborhood
//           of the pixel. If IppiSize's of image and template are Wa * Ha and
//           Wb * Hb correspondingly, then the IppiSize of the resulting
//           matrice with normalized cross-correlation coefficients will be
//           a) in case of 'Full' suffix:
//              ( Wa + Wb - 1 )*( Ha + Hb - 1 ).
//           b) in case of 'Same' suffix:
//              ( Wa )*( Ha ).
//           c) in case of 'Valid' suffix:
//              ( Wa - Wb + 1 )*( Ha - Hb + 1 ).
//  Notice:
//           suffix 'R' (ROI) means only scanline alingment (srcStep), in
//           'Same' and 'Full' cases no any requirements for data outstand
//           the ROI - it's assumes that template and src are zerro padded.
//           The difference from ippiCrossCorr_Norm() functions is the using
//           of Zerro Mean image and Template to avoid brightness impact.
//           (Before the calculation of the cross-correlation coefficients,
//           the mean of the image in the region under the feature is subtracted
//           from every image pixel; the same for the template.)
//
//  Arguments:
//      pSrc        - pointer to the source image ROI;
//      srcStep     - step in bytes through the source image buffer;
//      srcRoiSize  - size of the source ROI in pixels;
//      pTpl        - pointer to the template ( feature ) image ROI;
//      tplStep     - step in bytes through the template image buffer;
//      tplRoiSize  - size of the template ROI in pixels;
//      pDst        - pointer to the destination buffer;
//      dstStep     - step in bytes through the destination image buffer;
//      scaleFactor - scale factor value ( in case of integer output data ).
//
//  Return:
//   ippStsNoErr        - Ok
//   ippStsNullPtrErr   - at least one of the pointers to pSrc, pDst or pTpl is NULL;
//   ippStsSizeErr      - at least one of the sizes of srcRoiSize or tplRoiSize is less or equal zero,
//                        or at least one of the sizes of srcRoiSize is smaller then the corresponding
//                        size of the tplRoiSize;
//   ippStsStepErr      - at least one of the srcStep, tplStep or dstStep is less or equal zero;
//   ippStsMemAllocErr  - an error occur during allocation memory for internal buffers.
*/

IPPAPI( IppStatus, ippiCrossCorrFull_NormLevel_32f_C1R, ( const Ipp32f* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp32f* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrFull_NormLevel_32f_C3R, ( const Ipp32f* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp32f* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrFull_NormLevel_32f_C4R, ( const Ipp32f* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp32f* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrFull_NormLevel_32f_AC4R, ( const Ipp32f* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp32f* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrFull_NormLevel_8u32f_C1R, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrFull_NormLevel_8u32f_C3R, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrFull_NormLevel_8u32f_C4R, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrFull_NormLevel_8u32f_AC4R, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrFull_NormLevel_8s32f_C1R, ( const Ipp8s* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8s* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrFull_NormLevel_8s32f_C3R, ( const Ipp8s* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8s* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrFull_NormLevel_8s32f_C4R, ( const Ipp8s* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8s* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrFull_NormLevel_8s32f_AC4R, ( const Ipp8s* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8s* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrFull_NormLevel_8u_C1RSfs, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp8u* pDst, int dstStep, int scaleFactor ))
IPPAPI( IppStatus, ippiCrossCorrFull_NormLevel_8u_C3RSfs, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp8u* pDst, int dstStep, int scaleFactor ))
IPPAPI( IppStatus, ippiCrossCorrFull_NormLevel_8u_C4RSfs, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp8u* pDst, int dstStep, int scaleFactor ))
IPPAPI( IppStatus, ippiCrossCorrFull_NormLevel_8u_AC4RSfs, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp8u* pDst, int dstStep, int scaleFactor ))

IPPAPI( IppStatus, ippiCrossCorrValid_NormLevel_32f_C1R, ( const Ipp32f* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp32f* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrValid_NormLevel_32f_C3R, ( const Ipp32f* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp32f* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrValid_NormLevel_32f_C4R, ( const Ipp32f* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp32f* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrValid_NormLevel_32f_AC4R, ( const Ipp32f* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp32f* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrValid_NormLevel_8u32f_C1R, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrValid_NormLevel_8u32f_C3R, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrValid_NormLevel_8u32f_C4R, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrValid_NormLevel_8u32f_AC4R, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrValid_NormLevel_8s32f_C1R, ( const Ipp8s* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8s* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrValid_NormLevel_8s32f_C3R, ( const Ipp8s* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8s* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrValid_NormLevel_8s32f_C4R, ( const Ipp8s* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8s* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrValid_NormLevel_8s32f_AC4R, ( const Ipp8s* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8s* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrValid_NormLevel_8u_C1RSfs, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp8u* pDst, int dstStep, int scaleFactor ))
IPPAPI( IppStatus, ippiCrossCorrValid_NormLevel_8u_C3RSfs, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp8u* pDst, int dstStep, int scaleFactor ))
IPPAPI( IppStatus, ippiCrossCorrValid_NormLevel_8u_C4RSfs, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp8u* pDst, int dstStep, int scaleFactor ))
IPPAPI( IppStatus, ippiCrossCorrValid_NormLevel_8u_AC4RSfs, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp8u* pDst, int dstStep, int scaleFactor ))

IPPAPI( IppStatus, ippiCrossCorrSame_NormLevel_32f_C1R, ( const Ipp32f* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp32f* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrSame_NormLevel_32f_C3R, ( const Ipp32f* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp32f* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrSame_NormLevel_32f_C4R, ( const Ipp32f* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp32f* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrSame_NormLevel_32f_AC4R, ( const Ipp32f* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp32f* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrSame_NormLevel_8u32f_C1R, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrSame_NormLevel_8u32f_C3R, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrSame_NormLevel_8u32f_C4R, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrSame_NormLevel_8u32f_AC4R, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrSame_NormLevel_8s32f_C1R, ( const Ipp8s* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8s* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrSame_NormLevel_8s32f_C3R, ( const Ipp8s* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8s* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrSame_NormLevel_8s32f_C4R, ( const Ipp8s* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8s* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrSame_NormLevel_8s32f_AC4R, ( const Ipp8s* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8s* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiCrossCorrSame_NormLevel_8u_C1RSfs, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp8u* pDst, int dstStep, int scaleFactor ))
IPPAPI( IppStatus, ippiCrossCorrSame_NormLevel_8u_C3RSfs, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp8u* pDst, int dstStep, int scaleFactor ))
IPPAPI( IppStatus, ippiCrossCorrSame_NormLevel_8u_C4RSfs, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp8u* pDst, int dstStep, int scaleFactor ))
IPPAPI( IppStatus, ippiCrossCorrSame_NormLevel_8u_AC4RSfs, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp8u* pDst, int dstStep, int scaleFactor ))


/*/////////////////////////////////////////////////////////////////////////////////////////////
//  Names:
//      ippiSqrDistanceFull_Norm_32f_C1R,    ippiSqrDistanceSame_Norm_32f_C1R,
//      ippiSqrDistanceFull_Norm_32f_C3R,    ippiSqrDistanceSame_Norm_32f_C3R,
//      ippiSqrDistanceFull_Norm_32f_AC4R,   ippiSqrDistanceSame_Norm_32f_AC4R,
//      ippiSqrDistanceFull_Norm_8u_C1RSfs,  ippiSqrDistanceSame_Norm_8u_C1RSfs,
//      ippiSqrDistanceFull_Norm_8u_C3RSfs,  ippiSqrDistanceSame_Norm_8u_C3RSfs,
//      ippiSqrDistanceFull_Norm_8u_AC4RSfs, ippiSqrDistanceSame_Norm_8u_AC4RSfs,
//      ippiSqrDistanceFull_Norm_8u32f_C1R,  ippiSqrDistanceSame_Norm_8u32f_C1R,
//      ippiSqrDistanceFull_Norm_8u32f_C3R,  ippiSqrDistanceSame_Norm_8u32f_C3R,
//      ippiSqrDistanceFull_Norm_8u32f_AC4R, ippiSqrDistanceSame_Norm_8u32f_AC4R,
//
//      ippiSqrDistanceValid_Norm_32f_C1R,
//      ippiSqrDistanceValid_Norm_32f_C3R,
//      ippiSqrDistanceValid_Norm_32f_AC4R,
//      ippiSqrDistanceValid_Norm_8u_C1RSfs,
//      ippiSqrDistanceValid_Norm_8u_C3RSfs,
//      ippiSqrDistanceValid_Norm_8u_AC4RSfs,
//      ippiSqrDistanceValid_Norm_8u32f_C1R,
//      ippiSqrDistanceValid_Norm_8u32f_C3R,
//      ippiSqrDistanceValid_Norm_8u32f_AC4R.
//
//      ippiSqrDistanceFull_Norm_32f_C4R,    ippiSqrDistanceSame_Norm_32f_C4R,
//      ippiSqrDistanceFull_Norm_8u_C4RSfs,  ippiSqrDistanceSame_Norm_8u_C4RSfs,
//      ippiSqrDistanceFull_Norm_8u32f_C4R,  ippiSqrDistanceSame_Norm_8u32f_C4R,
//      ippiSqrDistanceFull_Norm_8s32f_C1R,  ippiSqrDistanceSame_Norm_8s32f_C1R,
//      ippiSqrDistanceFull_Norm_8s32f_C3R,  ippiSqrDistanceSame_Norm_8s32f_C3R,
//      ippiSqrDistanceFull_Norm_8s32f_C4R,  ippiSqrDistanceSame_Norm_8s32f_C4R,
//      ippiSqrDistanceFull_Norm_8s32f_AC4R, ippiSqrDistanceSame_Norm_8s32f_AC4R,
//
//      ippiSqrDistanceValid_Norm_32f_C4R,
//      ippiSqrDistanceValid_Norm_8u_C4RSfs,
//      ippiSqrDistanceValid_Norm_8u32f_C4R,
//      ippiSqrDistanceValid_Norm_8s32f_C1R,
//      ippiSqrDistanceValid_Norm_8s32f_C3R,
//      ippiSqrDistanceValid_Norm_8s32f_C4R,
//      ippiSqrDistanceValid_Norm_8s32f_AC4R.
//
//  Purpose: ippiSqrDistance_Norm() function allows you to compute the
//           Euclidean Distance or Sum of Squared Distance (SSD) of an image
//           and a template (another image).
//               The SSD values are image similarity measures: the smaller
//           value of SSD at a particular pixel, the more similarity between
//           the template and the image in the neighborhood of the pixel.
//               If IppiSize's of image and template are Wa * Ha and
//           Wb * Hb correspondingly, then the IppiSize of the resulting
//           matrice with normalized SSD coefficients will be
//           a) in case of 'Full' suffix:
//              ( Wa + Wb - 1 )*( Ha + Hb - 1 ).
//           b) in case of 'Same' suffix:
//              ( Wa )*( Ha ).
//           c) in case of 'Valid' suffix:
//              ( Wa - Wb + 1 )*( Ha - Hb + 1 ).
//  Notice:
//           suffix 'R' (ROI) means only scanline alingment (srcStep), in
//           'Same' and 'Full' cases no any requirements for data outstand
//           the ROI - it's assumes that template and src are zerro padded.
//
//  Arguments:
//      pSrc        - pointer to the source image ROI;
//      srcStep     - step in bytes through the source image buffer;
//      srcRoiSize  - size of the source ROI in pixels;
//      pTpl        - pointer to the template ( feature ) image ROI;
//      tplStep     - step in bytes through the template image buffer;
//      tplRoiSize  - size of the template ROI in pixels;
//      pDst        - pointer to the destination buffer;
//      dstStep     - step in bytes through the destination image buffer;
//      scaleFactor - scale factor value ( in case of integer output data ).
//
//  Return:
//   ippStsNoErr        - Ok
//   ippStsNullPtrErr   - at least one of the pointers to pSrc, pDst or pTpl is NULL;
//   ippStsSizeErr      - at least one of the sizes of srcRoiSize or tplRoiSize is less or equal zero,
//                        or at least one of the sizes of srcRoiSize is smaller then the corresponding
//                        size of the tplRoiSize;
//   ippStsStepErr      - at least one of the srcStep, tplStep or dstStep is less or equal zero;
//   ippStsMemAllocErr  - an error occur during allocation memory for internal buffers.
*/

IPPAPI( IppStatus, ippiSqrDistanceFull_Norm_32f_C1R, ( const Ipp32f* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp32f* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiSqrDistanceFull_Norm_32f_C3R, ( const Ipp32f* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp32f* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiSqrDistanceFull_Norm_32f_AC4R, ( const Ipp32f* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp32f* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiSqrDistanceFull_Norm_8u32f_C1R, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiSqrDistanceFull_Norm_8u32f_C3R, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiSqrDistanceFull_Norm_8u32f_AC4R, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiSqrDistanceFull_Norm_8u_C1RSfs, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp8u* pDst, int dstStep, int scaleFactor ))
IPPAPI( IppStatus, ippiSqrDistanceFull_Norm_8u_C3RSfs, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp8u* pDst, int dstStep, int scaleFactor ))
IPPAPI( IppStatus, ippiSqrDistanceFull_Norm_8u_AC4RSfs, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp8u* pDst, int dstStep, int scaleFactor ))

IPPAPI( IppStatus, ippiSqrDistanceValid_Norm_32f_C1R, ( const Ipp32f* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp32f* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiSqrDistanceValid_Norm_32f_C3R, ( const Ipp32f* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp32f* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiSqrDistanceValid_Norm_32f_AC4R, ( const Ipp32f* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp32f* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiSqrDistanceValid_Norm_8u32f_C1R, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiSqrDistanceValid_Norm_8u32f_C3R, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiSqrDistanceValid_Norm_8u32f_AC4R, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiSqrDistanceValid_Norm_8u_C1RSfs, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp8u* pDst, int dstStep, int scaleFactor ))
IPPAPI( IppStatus, ippiSqrDistanceValid_Norm_8u_C3RSfs, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp8u* pDst, int dstStep, int scaleFactor ))
IPPAPI( IppStatus, ippiSqrDistanceValid_Norm_8u_AC4RSfs, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp8u* pDst, int dstStep, int scaleFactor ))

IPPAPI( IppStatus, ippiSqrDistanceSame_Norm_32f_C1R, ( const Ipp32f* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp32f* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiSqrDistanceSame_Norm_32f_C3R, ( const Ipp32f* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp32f* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiSqrDistanceSame_Norm_32f_AC4R, ( const Ipp32f* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp32f* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiSqrDistanceSame_Norm_8u32f_C1R, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiSqrDistanceSame_Norm_8u32f_C3R, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiSqrDistanceSame_Norm_8u32f_AC4R, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiSqrDistanceSame_Norm_8u_C1RSfs, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp8u* pDst, int dstStep, int scaleFactor ))
IPPAPI( IppStatus, ippiSqrDistanceSame_Norm_8u_C3RSfs, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp8u* pDst, int dstStep, int scaleFactor ))
IPPAPI( IppStatus, ippiSqrDistanceSame_Norm_8u_AC4RSfs, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp8u* pDst, int dstStep, int scaleFactor ))

IPPAPI( IppStatus, ippiSqrDistanceFull_Norm_32f_C4R, ( const Ipp32f* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp32f* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiSqrDistanceFull_Norm_8u32f_C4R, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiSqrDistanceFull_Norm_8s32f_C1R, ( const Ipp8s* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8s* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiSqrDistanceFull_Norm_8s32f_C3R, ( const Ipp8s* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8s* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiSqrDistanceFull_Norm_8s32f_C4R, ( const Ipp8s* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8s* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiSqrDistanceFull_Norm_8s32f_AC4R, ( const Ipp8s* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8s* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiSqrDistanceFull_Norm_8u_C4RSfs, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp8u* pDst, int dstStep, int scaleFactor ))

IPPAPI( IppStatus, ippiSqrDistanceValid_Norm_32f_C4R, ( const Ipp32f* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp32f* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiSqrDistanceValid_Norm_8u32f_C4R, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiSqrDistanceValid_Norm_8s32f_C1R, ( const Ipp8s* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8s* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiSqrDistanceValid_Norm_8s32f_C3R, ( const Ipp8s* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8s* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiSqrDistanceValid_Norm_8s32f_C4R, ( const Ipp8s* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8s* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiSqrDistanceValid_Norm_8s32f_AC4R, ( const Ipp8s* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8s* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiSqrDistanceValid_Norm_8u_C4RSfs, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp8u* pDst, int dstStep, int scaleFactor ))

IPPAPI( IppStatus, ippiSqrDistanceSame_Norm_32f_C4R, ( const Ipp32f* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp32f* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiSqrDistanceSame_Norm_8u32f_C4R, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiSqrDistanceSame_Norm_8s32f_C1R, ( const Ipp8s* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8s* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiSqrDistanceSame_Norm_8s32f_C3R, ( const Ipp8s* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8s* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiSqrDistanceSame_Norm_8s32f_C4R, ( const Ipp8s* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8s* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiSqrDistanceSame_Norm_8s32f_AC4R, ( const Ipp8s* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8s* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp32f* pDst, int dstStep ))
IPPAPI( IppStatus, ippiSqrDistanceSame_Norm_8u_C4RSfs, ( const Ipp8u* pSrc, int srcStep,
        IppiSize srcRoiSize, const Ipp8u* pTpl, int tplStep, IppiSize tplRoiSize,
        Ipp8u* pDst, int dstStep, int scaleFactor ))


/* /////////////////////////////////////////////////////////////////////////////
//                   Threshold operations
///////////////////////////////////////////////////////////////////////////// */

/* ////////////////////////////////////////////////////////////////////////////
//  Names:      ippiThreshold_8u_C1R
//              ippiThreshold_8u_C3R
//              ippiThreshold_8u_AC4R
//              ippiThreshold_16s_C1R
//              ippiThreshold_16s_C3R
//              ippiThreshold_16s_AC4R
//              ippiThreshold_32f_C1R
//              ippiThreshold_32f_C3R
//              ippiThreshold_32f_AC4R
//              ippiThreshold_8u_C1IR
//              ippiThreshold_8u_C3IR
//              ippiThreshold_8u_AC4IR
//              ippiThreshold_16s_C1IR
//              ippiThreshold_16s_C3IR
//              ippiThreshold_16s_AC4IR
//              ippiThreshold_32f_C1IR
//              ippiThreshold_32f_C3IR
//              ippiThreshold_32f_AC4IR
//
//  Purpose:        Threshold operation
//  Return:
//   ippStsNoErr       Ok
//   ippStsNullPtrErr  Some of pointers to pSrc or pDst are NULL
//   ippStsSizeErr     Some size of roi less or equal zero
//
//  Parameters:
//   pSrc       pointer to input image
//   srcStep    size of input image scan-line
//   pDst       pointer to output image
//   dstStep    size of output image scan-line
//   pSrcDst    pointer to input for in-place operation
//   srcDstStep size of image scan-line for in-place operation
//   roiSize    ROI size
//   threshold  level (or levels) of the threshold operation
//   ippCmpOp      comparison mode, ippCmpLess or ippCmpGreater
*/
IPPAPI(IppStatus,ippiThreshold_8u_C1R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize, Ipp8u threshold,
       IppCmpOp ippCmpOp))
IPPAPI(IppStatus,ippiThreshold_16s_C1R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, Ipp16s threshold,
       IppCmpOp ippCmpOp))
IPPAPI(IppStatus,ippiThreshold_32f_C1R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize, Ipp32f threshold,
       IppCmpOp ippCmpOp))
IPPAPI(IppStatus,ippiThreshold_8u_C3R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize, const Ipp8u threshold[3],
       IppCmpOp ippCmpOp))
IPPAPI(IppStatus,ippiThreshold_16s_C3R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, const Ipp16s threshold[3],
       IppCmpOp ippCmpOp))
IPPAPI(IppStatus,ippiThreshold_32f_C3R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize, const Ipp32f threshold[3],
       IppCmpOp ippCmpOp))
IPPAPI(IppStatus,ippiThreshold_8u_AC4R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize, const Ipp8u threshold[3],
       IppCmpOp ippCmpOp))
IPPAPI(IppStatus,ippiThreshold_16s_AC4R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, const Ipp16s threshold[3],
       IppCmpOp ippCmpOp))
IPPAPI(IppStatus,ippiThreshold_32f_AC4R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize, const Ipp32f threshold[3],
       IppCmpOp ippCmpOp))
IPPAPI(IppStatus,ippiThreshold_8u_C1IR,(Ipp8u* pSrcDst, int srcDstStep,
       IppiSize roiSize, Ipp8u threshold, IppCmpOp ippCmpOp))
IPPAPI(IppStatus,ippiThreshold_16s_C1IR,(Ipp16s* pSrcDst, int srcDstStep,
       IppiSize roiSize, Ipp16s threshold, IppCmpOp ippCmpOp))
IPPAPI(IppStatus,ippiThreshold_32f_C1IR,(Ipp32f* pSrcDst, int srcDstStep,
       IppiSize roiSize, Ipp32f threshold, IppCmpOp ippCmpOp))
IPPAPI(IppStatus,ippiThreshold_8u_C3IR,(Ipp8u* pSrcDst, int srcDstStep,
       IppiSize roiSize, const Ipp8u threshold[3], IppCmpOp ippCmpOp))
IPPAPI(IppStatus,ippiThreshold_16s_C3IR,(Ipp16s* pSrcDst, int srcDstStep,
       IppiSize roiSize, const Ipp16s threshold[3], IppCmpOp ippCmpOp))
IPPAPI(IppStatus,ippiThreshold_32f_C3IR,(Ipp32f* pSrcDst, int srcDstStep,
       IppiSize roiSize, const Ipp32f threshold[3], IppCmpOp ippCmpOp))
IPPAPI(IppStatus,ippiThreshold_8u_AC4IR,(Ipp8u* pSrcDst, int srcDstStep,
       IppiSize roiSize, const Ipp8u threshold[3], IppCmpOp ippCmpOp))
IPPAPI(IppStatus,ippiThreshold_16s_AC4IR,(Ipp16s* pSrcDst, int srcDstStep,
       IppiSize roiSize, const Ipp16s threshold[3], IppCmpOp ippCmpOp))
IPPAPI(IppStatus,ippiThreshold_32f_AC4IR,(Ipp32f* pSrcDst, int srcDstStep,
       IppiSize roiSize, const Ipp32f threshold[3], IppCmpOp ippCmpOp))

/* ////////////////////////////////////////////////////////////////////////////
//  Names:      ippiThreshold_GT_8u_C1R
//              ippiThreshold_GT_8u_C3R
//              ippiThreshold_GT_8u_AC4R
//              ippiThreshold_GT_16s_C1R
//              ippiThreshold_GT_16s_C3R
//              ippiThreshold_GT_16s_AC4R
//              ippiThreshold_GT_32f_C1R
//              ippiThreshold_GT_32f_C3R
//              ippiThreshold_GT_32f_AC4R
//              ippiThreshold_GT_8u_C1IR
//              ippiThreshold_GT_8u_C3IR
//              ippiThreshold_GT_8u_AC4IR
//              ippiThreshold_GT_16s_C1IR
//              ippiThreshold_GT_16s_C3IR
//              ippiThreshold_GT_16s_AC4IR
//              ippiThreshold_GT_32f_C1IR
//              ippiThreshold_GT_32f_C3IR
//              ippiThreshold_GT_32f_AC4IR
//
//  Purpose:        Threshold operation if Greater
//  Return:
//   ippStsNoErr       Ok
//   ippStsNullPtrErr  Some of pointers to pSrc or pDst are NULL
//   ippStsSizeErr     Some size of roi less or equal zero
//
//  Parameters:
//   pSrc       pointer to input image
//   srcStep    size of input image scan-line
//   pDst       pointer to output image
//   dstStep    size of output image scan-line
//   pSrcDst    pointer to input for in-place operation
//   srcDstStep size of image scan-line for in-place operation
//   roiSize    ROI size
//   threshold  level (or levels) of the threshold operation
*/
IPPAPI(IppStatus,ippiThreshold_GT_8u_C1R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize, Ipp8u threshold))
IPPAPI(IppStatus,ippiThreshold_GT_16s_C1R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, Ipp16s threshold))
IPPAPI(IppStatus,ippiThreshold_GT_32f_C1R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize, Ipp32f threshold))
IPPAPI(IppStatus,ippiThreshold_GT_8u_C3R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize, const Ipp8u threshold[3]))
IPPAPI(IppStatus,ippiThreshold_GT_16s_C3R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, const Ipp16s threshold[3]))
IPPAPI(IppStatus,ippiThreshold_GT_32f_C3R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize, const Ipp32f threshold[3]))
IPPAPI(IppStatus,ippiThreshold_GT_8u_AC4R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize, const Ipp8u threshold[3]))
IPPAPI(IppStatus,ippiThreshold_GT_16s_AC4R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, const Ipp16s threshold[3]))
IPPAPI(IppStatus,ippiThreshold_GT_32f_AC4R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize, const Ipp32f threshold[3]))
IPPAPI(IppStatus,ippiThreshold_GT_8u_C1IR,(Ipp8u* pSrcDst, int srcDstStep,
       IppiSize roiSize, Ipp8u threshold))
IPPAPI(IppStatus,ippiThreshold_GT_16s_C1IR,(Ipp16s* pSrcDst, int srcDstStep,
       IppiSize roiSize, Ipp16s threshold))
IPPAPI(IppStatus,ippiThreshold_GT_32f_C1IR,(Ipp32f* pSrcDst, int srcDstStep,
       IppiSize roiSize, Ipp32f threshold))
IPPAPI(IppStatus,ippiThreshold_GT_8u_C3IR,(Ipp8u* pSrcDst, int srcDstStep,
       IppiSize roiSize, const Ipp8u threshold[3]))
IPPAPI(IppStatus,ippiThreshold_GT_16s_C3IR,(Ipp16s* pSrcDst, int srcDstStep,
       IppiSize roiSize, const Ipp16s threshold[3]))
IPPAPI(IppStatus,ippiThreshold_GT_32f_C3IR,(Ipp32f* pSrcDst, int srcDstStep,
       IppiSize roiSize, const Ipp32f threshold[3]))
IPPAPI(IppStatus,ippiThreshold_GT_8u_AC4IR,(Ipp8u* pSrcDst, int srcDstStep,
       IppiSize roiSize, const Ipp8u threshold[3]))
IPPAPI(IppStatus,ippiThreshold_GT_16s_AC4IR,(Ipp16s* pSrcDst, int srcDstStep,
       IppiSize roiSize, const Ipp16s threshold[3]))
IPPAPI(IppStatus,ippiThreshold_GT_32f_AC4IR,(Ipp32f* pSrcDst, int srcDstStep,
       IppiSize roiSize, const Ipp32f threshold[3]))

/* ////////////////////////////////////////////////////////////////////////////
//  Names:      ippiThreshold_LT_8u_C1R
//              ippiThreshold_LT_8u_C3R
//              ippiThreshold_LT_8u_AC4R
//              ippiThreshold_LT_16s_C1R
//              ippiThreshold_LT_16s_C3R
//              ippiThreshold_LT_16s_AC4R
//              ippiThreshold_LT_32f_C1R
//              ippiThreshold_LT_32f_C3R
//              ippiThreshold_LT_32f_AC4R
//              ippiThreshold_LT_8u_C1IR
//              ippiThreshold_LT_8u_C3IR
//              ippiThreshold_LT_8u_AC4IR
//              ippiThreshold_LT_16s_C1IR
//              ippiThreshold_LT_16s_C3IR
//              ippiThreshold_LT_16s_AC4IR
//              ippiThreshold_LT_32f_C1IR
//              ippiThreshold_LT_32f_C3IR
//              ippiThreshold_LT_32f_AC4IR
//
//  Purpose:        Threshold operation if Less
//  Return:
//   ippStsNoErr       Ok
//   ippStsNullPtrErr  Some of pointers to pSrc or pDst are NULL
//   ippStsSizeErr     Some size of roi less or equal zero
//
//  Parameters:
//   pSrc       pointer to input image
//   srcStep    size of input image scan-line
//   pDst       pointer to output image
//   dstStep    size of output image scan-line
//   pSrcDst    pointer to input for in-place operation
//   srcDstStep size of image scan-line for in-place operation
//   roiSize    ROI size
//   threshold  level (or levels) of the threshold operation
*/
IPPAPI(IppStatus,ippiThreshold_LT_8u_C1R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize, Ipp8u threshold))
IPPAPI(IppStatus,ippiThreshold_LT_16s_C1R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, Ipp16s threshold))
IPPAPI(IppStatus,ippiThreshold_LT_32f_C1R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize, Ipp32f threshold))
IPPAPI(IppStatus,ippiThreshold_LT_8u_C3R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize, const Ipp8u threshold[3]))
IPPAPI(IppStatus,ippiThreshold_LT_16s_C3R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, const Ipp16s threshold[3]))
IPPAPI(IppStatus,ippiThreshold_LT_32f_C3R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize, const Ipp32f threshold[3]))
IPPAPI(IppStatus,ippiThreshold_LT_8u_AC4R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize, const Ipp8u threshold[3]))
IPPAPI(IppStatus,ippiThreshold_LT_16s_AC4R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, const Ipp16s threshold[3]))
IPPAPI(IppStatus,ippiThreshold_LT_32f_AC4R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize, const Ipp32f threshold[3]))
IPPAPI(IppStatus,ippiThreshold_LT_8u_C1IR,(Ipp8u* pSrcDst, int srcDstStep,
       IppiSize roiSize, Ipp8u threshold))
IPPAPI(IppStatus,ippiThreshold_LT_16s_C1IR,(Ipp16s* pSrcDst, int srcDstStep,
       IppiSize roiSize, Ipp16s threshold))
IPPAPI(IppStatus,ippiThreshold_LT_32f_C1IR,(Ipp32f* pSrcDst, int srcDstStep,
       IppiSize roiSize, Ipp32f threshold))
IPPAPI(IppStatus,ippiThreshold_LT_8u_C3IR,(Ipp8u* pSrcDst, int srcDstStep,
       IppiSize roiSize, const Ipp8u threshold[3]))
IPPAPI(IppStatus,ippiThreshold_LT_16s_C3IR,(Ipp16s* pSrcDst, int srcDstStep,
       IppiSize roiSize, const Ipp16s threshold[3]))
IPPAPI(IppStatus,ippiThreshold_LT_32f_C3IR,(Ipp32f* pSrcDst, int srcDstStep,
       IppiSize roiSize, const Ipp32f threshold[3]))
IPPAPI(IppStatus,ippiThreshold_LT_8u_AC4IR,(Ipp8u* pSrcDst, int srcDstStep,
       IppiSize roiSize, const Ipp8u threshold[3]))
IPPAPI(IppStatus,ippiThreshold_LT_16s_AC4IR,(Ipp16s* pSrcDst, int srcDstStep,
       IppiSize roiSize, const Ipp16s threshold[3]))
IPPAPI(IppStatus,ippiThreshold_LT_32f_AC4IR,(Ipp32f* pSrcDst, int srcDstStep,
       IppiSize roiSize, const Ipp32f threshold[3]))

/* ////////////////////////////////////////////////////////////////////////////
//  Names:      ippiThreshold_Val_8u_C1R
//              ippiThreshold_Val_8u_C3R
//              ippiThreshold_Val_8u_AC4R
//              ippiThreshold_Val_16s_C1R
//              ippiThreshold_Val_16s_C3R
//              ippiThreshold_Val_16s_AC4R
//              ippiThreshold_Val_32f_C1R
//              ippiThreshold_Val_32f_C3R
//              ippiThreshold_Val_32f_AC4R
//              ippiThreshold_Val_8u_C1IR
//              ippiThreshold_Val_8u_C3IR
//              ippiThreshold_Val_8u_AC4IR
//              ippiThreshold_Val_16s_C1IR
//              ippiThreshold_Val_16s_C3IR
//              ippiThreshold_Val_16s_AC4IR
//              ippiThreshold_Val_32f_C1IR
//              ippiThreshold_Val_32f_C3IR
//              ippiThreshold_Val_32f_AC4IR
//
//  Purpose:        Thresold operations
//  Return:
//   ippStsNoErr       Ok
//   ippStsNullPtrErr  Some of pointers to pSrc or pDst are NULL
//   ippStsSizeErr     Some size of roi less or equal zero
//
//  Parameters:
//   pSrc       pointer to input image
//   srcStep    size of input image scan-line
//   pDst       pointer to output image
//   dstStep    size of output image scan-line
//   pSrcDst    pointer to input for in-place operation
//   srcDstStep size of image scan-line for in-place operation
//   roiSize    ROI size
//   threshold  level (or levels) of the threshold operation
//   value      replacing value (or values)
//   ippCmpOp      comparison mode, ippCmpLess or ippCmpGreater
*/
IPPAPI(IppStatus,ippiThreshold_Val_8u_C1R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize, Ipp8u threshold,
       Ipp8u value, IppCmpOp ippCmpOp))
IPPAPI(IppStatus,ippiThreshold_Val_16s_C1R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, Ipp16s threshold,
       Ipp16s value, IppCmpOp ippCmpOp))
IPPAPI(IppStatus,ippiThreshold_Val_32f_C1R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize, Ipp32f threshold,
       Ipp32f value, IppCmpOp ippCmpOp))
IPPAPI(IppStatus,ippiThreshold_Val_8u_C3R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize, const Ipp8u threshold[3],
       const Ipp8u value[3], IppCmpOp ippCmpOp))
IPPAPI(IppStatus,ippiThreshold_Val_16s_C3R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, const Ipp16s threshold[3],
       const Ipp16s value[3], IppCmpOp ippCmpOp))
IPPAPI(IppStatus,ippiThreshold_Val_32f_C3R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize, const Ipp32f threshold[3],
       const Ipp32f value[3], IppCmpOp ippCmpOp))
IPPAPI(IppStatus,ippiThreshold_Val_8u_AC4R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize, const Ipp8u threshold[3],
       const Ipp8u value[3], IppCmpOp ippCmpOp))
IPPAPI(IppStatus,ippiThreshold_Val_16s_AC4R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, const Ipp16s threshold[3],
       const Ipp16s value[3], IppCmpOp ippCmpOp))
IPPAPI(IppStatus,ippiThreshold_Val_32f_AC4R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize, const Ipp32f threshold[3],
       const Ipp32f value[3], IppCmpOp ippCmpOp))
IPPAPI(IppStatus,ippiThreshold_Val_8u_C1IR,(Ipp8u* pSrcDst, int srcDstStep,
       IppiSize roiSize, Ipp8u threshold, Ipp8u value, IppCmpOp ippCmpOp))
IPPAPI(IppStatus,ippiThreshold_Val_16s_C1IR,(Ipp16s* pSrcDst, int srcDstStep,
       IppiSize roiSize, Ipp16s threshold, Ipp16s value, IppCmpOp ippCmpOp))
IPPAPI(IppStatus,ippiThreshold_Val_32f_C1IR,(Ipp32f* pSrcDst, int srcDstStep,
       IppiSize roiSize, Ipp32f threshold, Ipp32f value, IppCmpOp ippCmpOp))
IPPAPI(IppStatus,ippiThreshold_Val_8u_C3IR,(Ipp8u* pSrcDst, int srcDstStep,
       IppiSize roiSize, const Ipp8u threshold[3], const Ipp8u value[3],
       IppCmpOp ippCmpOp))
IPPAPI(IppStatus,ippiThreshold_Val_16s_C3IR,(Ipp16s* pSrcDst, int srcDstStep,
       IppiSize roiSize, const Ipp16s threshold[3], const Ipp16s value[3],
       IppCmpOp ippCmpOp))
IPPAPI(IppStatus,ippiThreshold_Val_32f_C3IR,(Ipp32f* pSrcDst, int srcDstStep,
       IppiSize roiSize, const Ipp32f threshold[3], const Ipp32f value[3],
       IppCmpOp ippCmpOp))
IPPAPI(IppStatus,ippiThreshold_Val_8u_AC4IR,(Ipp8u* pSrcDst, int srcDstStep,
       IppiSize roiSize, const Ipp8u threshold[3], const Ipp8u value[3],
       IppCmpOp ippCmpOp))
IPPAPI(IppStatus,ippiThreshold_Val_16s_AC4IR,(Ipp16s* pSrcDst, int srcDstStep,
       IppiSize roiSize, const Ipp16s threshold[3], const Ipp16s value[3],
       IppCmpOp ippCmpOp))
IPPAPI(IppStatus,ippiThreshold_Val_32f_AC4IR,(Ipp32f* pSrcDst, int srcDstStep,
       IppiSize roiSize, const Ipp32f threshold[3], const Ipp32f value[3],
       IppCmpOp ippCmpOp))

/* ////////////////////////////////////////////////////////////////////////////
//  Names:      ippiThreshold_GTVal_8u_C1R
//              ippiThreshold_GTVal_8u_C3R
//              ippiThreshold_GTVal_8u_AC4R
//              ippiThreshold_GTVal_16s_C1R
//              ippiThreshold_GTVal_16s_C3R
//              ippiThreshold_GTVal_16s_AC4R
//              ippiThreshold_GTVal_32f_C1R
//              ippiThreshold_GTVal_32f_C3R
//              ippiThreshold_GTVal_32f_AC4R
//              ippiThreshold_GTVal_8u_C1IR
//              ippiThreshold_GTVal_8u_C3IR
//              ippiThreshold_GTVal_8u_AC4IR
//              ippiThreshold_GTVal_16s_C1IR
//              ippiThreshold_GTVal_16s_C3IR
//              ippiThreshold_GTVal_16s_AC4IR
//              ippiThreshold_GTVal_32f_C1IR
//              ippiThreshold_GTVal_32f_C3IR
//              ippiThreshold_GTVal_32f_AC4IR
//              ippiThreshold_GTVal_8u_C4R
//              ippiThreshold_GTVal_16s_C4R
//              ippiThreshold_GTVal_32f_C4R
//              ippiThreshold_GTVal_8u_C4IR
//              ippiThreshold_GTVal_16s_C4IR
//              ippiThreshold_GTVal_32f_C4IR
//
//  Purpose:        Thresold operations. Replace if Greater.
//  Return:
//   ippStsNoErr       Ok
//   ippStsNullPtrErr  Some of pointers to pSrc or pDst are NULL
//   ippStsSizeErr     Some size of roi less or equal zero
//
//  Parameters:
//   pSrc       pointer to input image
//   srcStep    size of input image scan-line
//   pDst       pointer to output image
//   dstStep    size of output image scan-line
//   pSrcDst    pointer to input for in-place operation
//   srcDstStep size of image scan-line for in-place operation
//   roiSize    ROI size
//   threshold  level (or levels) of the threshold operation
//   value      replacing value (or values)
//   ippCmpOp      comparison mode, ippCmpLess or ippCmpGreater
*/
IPPAPI(IppStatus,ippiThreshold_GTVal_8u_C1R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize, Ipp8u threshold,
       Ipp8u value))
IPPAPI(IppStatus,ippiThreshold_GTVal_16s_C1R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, Ipp16s threshold,
       Ipp16s value))
IPPAPI(IppStatus,ippiThreshold_GTVal_32f_C1R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize, Ipp32f threshold,
       Ipp32f value))
IPPAPI(IppStatus,ippiThreshold_GTVal_8u_C3R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize, const Ipp8u threshold[3],
       const Ipp8u value[3]))
IPPAPI(IppStatus,ippiThreshold_GTVal_16s_C3R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, const Ipp16s threshold[3],
       const Ipp16s value[3]))
IPPAPI(IppStatus,ippiThreshold_GTVal_32f_C3R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize, const Ipp32f threshold[3],
       const Ipp32f value[3]))
IPPAPI(IppStatus,ippiThreshold_GTVal_8u_AC4R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize, const Ipp8u threshold[3],
       const Ipp8u value[3]))
IPPAPI(IppStatus,ippiThreshold_GTVal_16s_AC4R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, const Ipp16s threshold[3],
       const Ipp16s value[3]))
IPPAPI(IppStatus,ippiThreshold_GTVal_32f_AC4R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize, const Ipp32f threshold[3],
       const Ipp32f value[3]))
IPPAPI(IppStatus,ippiThreshold_GTVal_8u_C1IR,(Ipp8u* pSrcDst, int srcDstStep,
       IppiSize roiSize, Ipp8u threshold, Ipp8u value))
IPPAPI(IppStatus,ippiThreshold_GTVal_16s_C1IR,(Ipp16s* pSrcDst, int srcDstStep,
       IppiSize roiSize, Ipp16s threshold, Ipp16s value))
IPPAPI(IppStatus,ippiThreshold_GTVal_32f_C1IR,(Ipp32f* pSrcDst, int srcDstStep,
       IppiSize roiSize, Ipp32f threshold, Ipp32f value))
IPPAPI(IppStatus,ippiThreshold_GTVal_8u_C3IR,(Ipp8u* pSrcDst, int srcDstStep,
       IppiSize roiSize, const Ipp8u threshold[3], const Ipp8u value[3]))
IPPAPI(IppStatus,ippiThreshold_GTVal_16s_C3IR,(Ipp16s* pSrcDst, int srcDstStep,
       IppiSize roiSize, const Ipp16s threshold[3], const Ipp16s value[3]))
IPPAPI(IppStatus,ippiThreshold_GTVal_32f_C3IR,(Ipp32f* pSrcDst, int srcDstStep,
       IppiSize roiSize, const Ipp32f threshold[3], const Ipp32f value[3]))
IPPAPI(IppStatus,ippiThreshold_GTVal_8u_AC4IR,(Ipp8u* pSrcDst, int srcDstStep,
       IppiSize roiSize, const Ipp8u threshold[3], const Ipp8u value[3]))
IPPAPI(IppStatus,ippiThreshold_GTVal_16s_AC4IR,(Ipp16s* pSrcDst, int srcDstStep,
       IppiSize roiSize, const Ipp16s threshold[3], const Ipp16s value[3]))
IPPAPI(IppStatus,ippiThreshold_GTVal_32f_AC4IR,(Ipp32f* pSrcDst, int srcDstStep,
       IppiSize roiSize, const Ipp32f threshold[3], const Ipp32f value[3]))
IPPAPI(IppStatus,ippiThreshold_GTVal_8u_C4R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize, const Ipp8u threshold[4],
       const Ipp8u value[4]))
IPPAPI(IppStatus,ippiThreshold_GTVal_16s_C4R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, const Ipp16s threshold[4],
       const Ipp16s value[4]))
IPPAPI(IppStatus,ippiThreshold_GTVal_32f_C4R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize, const Ipp32f threshold[4],
       const Ipp32f value[4]))
IPPAPI(IppStatus,ippiThreshold_GTVal_8u_C4IR,(Ipp8u* pSrcDst, int srcDstStep,
       IppiSize roiSize, const Ipp8u threshold[4], const Ipp8u value[4]))
IPPAPI(IppStatus,ippiThreshold_GTVal_16s_C4IR,(Ipp16s* pSrcDst, int srcDstStep,
       IppiSize roiSize, const Ipp16s threshold[4], const Ipp16s value[4]))
IPPAPI(IppStatus,ippiThreshold_GTVal_32f_C4IR,(Ipp32f* pSrcDst, int srcDstStep,
       IppiSize roiSize, const Ipp32f threshold[4], const Ipp32f value[4]))

/* ////////////////////////////////////////////////////////////////////////////
//  Names:      ippiThreshold_LTVal_8u_C1R
//              ippiThreshold_LTVal_8u_C3R
//              ippiThreshold_LTVal_8u_AC4R
//              ippiThreshold_LTVal_16s_C1R
//              ippiThreshold_LTVal_16s_C3R
//              ippiThreshold_LTVal_16s_AC4R
//              ippiThreshold_LTVal_32f_C1R
//              ippiThreshold_LTVal_32f_C3R
//              ippiThreshold_LTVal_32f_AC4R
//              ippiThreshold_LTVal_8u_C1IR
//              ippiThreshold_LTVal_8u_C3IR
//              ippiThreshold_LTVal_8u_AC4IR
//              ippiThreshold_LTVal_16s_C1IR
//              ippiThreshold_LTVal_16s_C3IR
//              ippiThreshold_LTVal_16s_AC4IR
//              ippiThreshold_LTVal_32f_C1IR
//              ippiThreshold_LTVal_32f_C3IR
//              ippiThreshold_LTVal_32f_AC4IR
//              ippiThreshold_LTVal_8u_C4R
//              ippiThreshold_LTVal_16s_C4R
//              ippiThreshold_LTVal_32f_C4R
//              ippiThreshold_LTVal_8u_C4IR
//              ippiThreshold_LTVal_16s_C4IR
//              ippiThreshold_LTVal_32f_C4IR
//
//  Purpose:        Thresold operations. Replace if Less.
//  Return:
//   ippStsNoErr       Ok
//   ippStsNullPtrErr  Some of pointers to pSrc or pDst are NULL
//   ippStsSizeErr     Some size of roi less or equal zero
//
//  Parameters:
//   pSrc       pointer to input image
//   srcStep    size of input image scan-line
//   pDst       pointer to output image
//   dstStep    size of output image scan-line
//   pSrcDst    pointer to input for in-place operation
//   srcDstStep size of image scan-line for in-place operation
//   roiSize    ROI size
//   threshold  level (or levels) of the threshold operation
//   value      replacing value (or values)
//   ippCmpOp      comparison mode, ippCmpLess or ippCmpGreater
*/
IPPAPI(IppStatus,ippiThreshold_LTVal_8u_C1R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize, Ipp8u threshold,
       Ipp8u value))
IPPAPI(IppStatus,ippiThreshold_LTVal_16s_C1R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, Ipp16s threshold,
       Ipp16s value))
IPPAPI(IppStatus,ippiThreshold_LTVal_32f_C1R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize, Ipp32f threshold,
       Ipp32f value))
IPPAPI(IppStatus,ippiThreshold_LTVal_8u_C3R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize, const Ipp8u threshold[3],
       const Ipp8u value[3]))
IPPAPI(IppStatus,ippiThreshold_LTVal_16s_C3R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, const Ipp16s threshold[3],
       const Ipp16s value[3]))
IPPAPI(IppStatus,ippiThreshold_LTVal_32f_C3R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize, const Ipp32f threshold[3],
       const Ipp32f value[3]))
IPPAPI(IppStatus,ippiThreshold_LTVal_8u_AC4R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize, const Ipp8u threshold[3],
       const Ipp8u value[3]))
IPPAPI(IppStatus,ippiThreshold_LTVal_16s_AC4R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, const Ipp16s threshold[3],
       const Ipp16s value[3]))
IPPAPI(IppStatus,ippiThreshold_LTVal_32f_AC4R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize, const Ipp32f threshold[3],
       const Ipp32f value[3]))
IPPAPI(IppStatus,ippiThreshold_LTVal_8u_C1IR,(Ipp8u* pSrcDst, int srcDstStep,
       IppiSize roiSize, Ipp8u threshold, Ipp8u value))
IPPAPI(IppStatus,ippiThreshold_LTVal_16s_C1IR,(Ipp16s* pSrcDst, int srcDstStep,
       IppiSize roiSize, Ipp16s threshold, Ipp16s value))
IPPAPI(IppStatus,ippiThreshold_LTVal_32f_C1IR,(Ipp32f* pSrcDst, int srcDstStep,
       IppiSize roiSize, Ipp32f threshold, Ipp32f value))
IPPAPI(IppStatus,ippiThreshold_LTVal_8u_C3IR,(Ipp8u* pSrcDst, int srcDstStep,
       IppiSize roiSize, const Ipp8u threshold[3], const Ipp8u value[3]))
IPPAPI(IppStatus,ippiThreshold_LTVal_16s_C3IR,(Ipp16s* pSrcDst, int srcDstStep,
       IppiSize roiSize, const Ipp16s threshold[3], const Ipp16s value[3]))
IPPAPI(IppStatus,ippiThreshold_LTVal_32f_C3IR,(Ipp32f* pSrcDst, int srcDstStep,
       IppiSize roiSize, const Ipp32f threshold[3], const Ipp32f value[3]))
IPPAPI(IppStatus,ippiThreshold_LTVal_8u_AC4IR,(Ipp8u* pSrcDst, int srcDstStep,
       IppiSize roiSize, const Ipp8u threshold[3], const Ipp8u value[3]))
IPPAPI(IppStatus,ippiThreshold_LTVal_16s_AC4IR,(Ipp16s* pSrcDst, int srcDstStep,
       IppiSize roiSize, const Ipp16s threshold[3], const Ipp16s value[3]))
IPPAPI(IppStatus,ippiThreshold_LTVal_32f_AC4IR,(Ipp32f* pSrcDst, int srcDstStep,
       IppiSize roiSize, const Ipp32f threshold[3], const Ipp32f value[3]))
IPPAPI(IppStatus,ippiThreshold_LTVal_8u_C4R,(const Ipp8u* pSrc, int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize, const Ipp8u threshold[4],
       const Ipp8u value[4]))
IPPAPI(IppStatus,ippiThreshold_LTVal_16s_C4R,(const Ipp16s* pSrc, int srcStep,
       Ipp16s* pDst, int dstStep, IppiSize roiSize, const Ipp16s threshold[4],
       const Ipp16s value[4]))
IPPAPI(IppStatus,ippiThreshold_LTVal_32f_C4R,(const Ipp32f* pSrc, int srcStep,
       Ipp32f* pDst, int dstStep, IppiSize roiSize, const Ipp32f threshold[4],
       const Ipp32f value[4]))
IPPAPI(IppStatus,ippiThreshold_LTVal_8u_C4IR,(Ipp8u* pSrcDst, int srcDstStep,
       IppiSize roiSize, const Ipp8u threshold[4], const Ipp8u value[4]))
IPPAPI(IppStatus,ippiThreshold_LTVal_16s_C4IR,(Ipp16s* pSrcDst, int srcDstStep,
       IppiSize roiSize, const Ipp16s threshold[4], const Ipp16s value[4]))
IPPAPI(IppStatus,ippiThreshold_LTVal_32f_C4IR,(Ipp32f* pSrcDst, int srcDstStep,
       IppiSize roiSize, const Ipp32f threshold[4], const Ipp32f value[4]))

/* ////////////////////////////////////////////////////////////////////////////
//  Names:      ippiThreshold_LTValGTVal_8u_C1R
//              ippiThreshold_LTValGTVal_8u_C3R
//              ippiThreshold_LTValGTVal_8u_AC4R
//              ippiThreshold_LTValGTVal_16s_C1R
//              ippiThreshold_LTValGTVal_16s_C3R
//              ippiThreshold_LTValGTVal_16s_AC4R
//              ippiThreshold_LTValGTVal_32f_C1R
//              ippiThreshold_LTValGTVal_32f_C3R
//              ippiThreshold_LTValGTVal_32f_AC4R
//
//  Purpose:        Threshold operation
//  Return:
//   ippStsNoErr       Ok
//   ippStsNullPtrErr  Some of pointers to pSrc or pDst are NULL
//   ippStsSizeErr     Some size of roi less or equal zero
//
//  Parameters:
//   pSrc           pointer to input image
//   srcStep        size of input image scan-line
//   pDst           pointer to output image
//   dstStep        size of output image scan-line
//   pSrcDst        pointer to input for in-place operation
//   srcDstStep     size of image scan-line for in-place operation
//   roiSize        ROI size
//   thresholdGT    level (or levels) of the threshold operation Greater
//   valueGT        replacing value (or values) of the threshold operation
//                  Greater
//   thresholdLT    level (or levels) of the threshold operation Less
//   valueLT        replacing value (or values) of the threshold operation
//                  Less
*/
IPPAPI(IppStatus,ippiThreshold_LTValGTVal_8u_C1R,(const Ipp8u* pSrc,int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize, Ipp8u thresholdLT,
       Ipp8u valueLT, Ipp8u thresholdGT, Ipp8u valueGT))
IPPAPI(IppStatus,ippiThreshold_LTValGTVal_16s_C1R,(const Ipp16s* pSrc,
       int srcStep, Ipp16s* pDst, int dstStep, IppiSize roiSize,
       Ipp16s thresholdLT, Ipp16s valueLT, Ipp16s thresholdGT,
       Ipp16s valueGT))
IPPAPI(IppStatus,ippiThreshold_LTValGTVal_32f_C1R,(const Ipp32f* pSrc,
       int srcStep, Ipp32f* pDst, int dstStep, IppiSize roiSize,
       Ipp32f thresholdLT, Ipp32f valueLT, Ipp32f thresholdGT,
       Ipp32f valueGT))
IPPAPI(IppStatus,ippiThreshold_LTValGTVal_8u_C3R,(const Ipp8u* pSrc,int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize, const Ipp8u thresholdLT[3],
       const Ipp8u valueLT[3], const Ipp8u thresholdGT[3],
       const Ipp8u valueGT[3]))
IPPAPI(IppStatus,ippiThreshold_LTValGTVal_16s_C3R,(const Ipp16s* pSrc,
       int srcStep, Ipp16s* pDst, int dstStep, IppiSize roiSize,
       const Ipp16s thresholdLT[3], const Ipp16s valueLT[3],
       const Ipp16s thresholdGT[3], const Ipp16s valueGT[3]))
IPPAPI(IppStatus,ippiThreshold_LTValGTVal_32f_C3R,(const Ipp32f* pSrc,
       int srcStep, Ipp32f* pDst, int dstStep, IppiSize roiSize,
       const Ipp32f thresholdLT[3], const Ipp32f valueLT[3],
       const Ipp32f thresholdGT[3], const Ipp32f valueGT[3]))
IPPAPI(IppStatus,ippiThreshold_LTValGTVal_8u_AC4R,(const Ipp8u* pSrc,int srcStep,
       Ipp8u* pDst, int dstStep, IppiSize roiSize, const Ipp8u thresholdLT[3],
       const Ipp8u valueLT[3], const Ipp8u thresholdGT[3],
       const Ipp8u valueGT[3]))
IPPAPI(IppStatus,ippiThreshold_LTValGTVal_16s_AC4R,(const Ipp16s* pSrc,
       int srcStep, Ipp16s* pDst, int dstStep, IppiSize roiSize,
       const Ipp16s thresholdLT[3], const Ipp16s valueLT[3],
       const Ipp16s thresholdGT[3], const Ipp16s valueGT[3]))
IPPAPI(IppStatus,ippiThreshold_LTValGTVal_32f_AC4R,(const Ipp32f* pSrc,
       int srcStep, Ipp32f* pDst, int dstStep, IppiSize roiSize,
       const Ipp32f thresholdLT[3], const Ipp32f valueLT[3],
       const Ipp32f thresholdGT[3], const Ipp32f valueGT[3]))
IPPAPI(IppStatus,ippiThreshold_LTValGTVal_8u_C1IR,(Ipp8u* pSrcDst, int srcDstStep,
       IppiSize roiSize, Ipp8u thresholdLT, Ipp8u valueLT, Ipp8u thresholdGT,
       Ipp8u valueGT))
IPPAPI(IppStatus,ippiThreshold_LTValGTVal_16s_C1IR,(Ipp16s* pSrcDst, int srcDstStep,
       IppiSize roiSize, Ipp16s thresholdLT, Ipp16s valueLT, Ipp16s thresholdGT,
       Ipp16s valueGT))
IPPAPI(IppStatus,ippiThreshold_LTValGTVal_32f_C1IR,(Ipp32f* pSrcDst, int srcDstStep,
       IppiSize roiSize, Ipp32f thresholdLT, Ipp32f valueLT, Ipp32f thresholdGT,
       Ipp32f valueGT))
IPPAPI(IppStatus,ippiThreshold_LTValGTVal_8u_C3IR,(Ipp8u* pSrcDst,int srcDstStep,
       IppiSize roiSize, const Ipp8u thresholdLT[3], const Ipp8u valueLT[3],
       const Ipp8u thresholdGT[3], const Ipp8u valueGT[3]))
IPPAPI(IppStatus,ippiThreshold_LTValGTVal_16s_C3IR,(Ipp16s* pSrcDst, int srcDstStep,
       IppiSize roiSize, const Ipp16s thresholdLT[3], const Ipp16s valueLT[3],
       const Ipp16s thresholdGT[3], const Ipp16s valueGT[3]))
IPPAPI(IppStatus,ippiThreshold_LTValGTVal_32f_C3IR,(Ipp32f* pSrcDst, int srcDstStep,
       IppiSize roiSize,  const Ipp32f thresholdLT[3], const Ipp32f valueLT[3],
       const Ipp32f thresholdGT[3], const Ipp32f valueGT[3]))
IPPAPI(IppStatus,ippiThreshold_LTValGTVal_8u_AC4IR,(Ipp8u* pSrcDst,int srcDstStep,
       IppiSize roiSize, const Ipp8u thresholdLT[3], const Ipp8u valueLT[3],
       const Ipp8u thresholdGT[3], const Ipp8u valueGT[3]))
IPPAPI(IppStatus,ippiThreshold_LTValGTVal_16s_AC4IR,(Ipp16s* pSrcDst, int srcDstStep,
       IppiSize roiSize, const Ipp16s thresholdLT[3], const Ipp16s valueLT[3],
       const Ipp16s thresholdGT[3], const Ipp16s valueGT[3]))
IPPAPI(IppStatus,ippiThreshold_LTValGTVal_32f_AC4IR,(Ipp32f* pSrcDst, int srcDstStep,
       IppiSize roiSize, const Ipp32f thresholdLT[3], const Ipp32f valueLT[3],
       const Ipp32f thresholdGT[3], const Ipp32f valueGT[3]))


/* /////////////////////////////////////////////////////////////////////////////
//                   Convert and Initialization functions
///////////////////////////////////////////////////////////////////////////// */
/* ////////////////////////////////////////////////////////////////////////////
//  Name:       ippiCopy
//
//  Purpose:    copy pixel values from the source image to the destination  image.
//
//
//  Return:
//    ippStsNullPtrErr      One of the pointers is NULL
//    ippStsSizeErr         roiSize has a field with zero or negative value
//    ippStsStepErr         One of the steps is less than or equal to zero
//    ippStsNoErr           Ok
//
//  Arguments:
//    pSrc                  pointer  to the source image buffer
//    srcStep               step in bytes through the source image buffer
//    pDst                  pointer to the  destination image buffer
//    dstStep               step in bytes through the destination image buffer
//    roiSize               size of ROI
//    pMask                 pointer to the mask image buffer
//    maskStep              step in bytes through the mask image buffer
*/

IPPAPI( IppStatus, ippiCopy_8u_C3C1R,
                   ( const Ipp8u* pSrc, int srcStep,
                     Ipp8u* pDst, int dstStep, IppiSize roiSize ))
IPPAPI( IppStatus, ippiCopy_8u_C1C3R,
                   ( const Ipp8u* pSrc, int srcStep,
                     Ipp8u* pDst, int dstStep, IppiSize roiSize ))
IPPAPI( IppStatus, ippiCopy_8u_C4C1R,
                   ( const Ipp8u* pSrc, int srcStep,
                     Ipp8u* pDst, int dstStep, IppiSize roiSize ))
IPPAPI( IppStatus, ippiCopy_8u_C1C4R,
                   ( const Ipp8u* pSrc, int srcStep,
                     Ipp8u* pDst, int dstStep, IppiSize roiSize ))
IPPAPI( IppStatus, ippiCopy_8u_C3CR,
                   ( const Ipp8u* pSrc, int srcStep,
                     Ipp8u* pDst, int dstStep, IppiSize roiSize ))
IPPAPI( IppStatus, ippiCopy_8u_C4CR,
                   ( const Ipp8u* pSrc, int srcStep,
                     Ipp8u* pDst, int dstStep, IppiSize roiSize ))
IPPAPI( IppStatus, ippiCopy_8u_AC4C3R,
                   ( const Ipp8u* pSrc, int srcStep,
                     Ipp8u* pDst, int dstStep, IppiSize roiSize ))
IPPAPI( IppStatus, ippiCopy_8u_C3AC4R,
                   ( const Ipp8u* pSrc, int srcStep,
                     Ipp8u* pDst, int dstStep, IppiSize roiSize ))
IPPAPI ( IppStatus, ippiCopy_8u_C1R,
                    ( const Ipp8u* pSrc, int srcStep,
                      Ipp8u* pDst, int dstStep,IppiSize roiSize ))
IPPAPI ( IppStatus, ippiCopy_8u_C3R,
                    ( const Ipp8u* pSrc, int srcStep,
                      Ipp8u* pDst, int dstStep,IppiSize roiSize ))
IPPAPI ( IppStatus, ippiCopy_8u_C4R,
                    ( const Ipp8u* pSrc, int srcStep,
                      Ipp8u* pDst, int dstStep,IppiSize roiSize ))
IPPAPI ( IppStatus, ippiCopy_8u_AC4R,
                    ( const Ipp8u* pSrc, int srcStep,
                      Ipp8u* pDst, int dstStep,IppiSize roiSize ))
IPPAPI ( IppStatus, ippiCopy_8u_C1MR,
                    ( const Ipp8u* pSrc, int srcStep,
                      Ipp8u* pDst, int dstStep,IppiSize roiSize,
                      const Ipp8u* pMask, int maskStep ))
IPPAPI ( IppStatus, ippiCopy_8u_C3MR,
                    ( const Ipp8u* pSrc, int srcStep,
                      Ipp8u* pDst, int dstStep,IppiSize roiSize,
                      const Ipp8u* pMask, int maskStep ))
IPPAPI ( IppStatus, ippiCopy_8u_C4MR,
                    ( const Ipp8u* pSrc, int srcStep,
                      Ipp8u* pDst, int dstStep,IppiSize roiSize,
                      const Ipp8u* pMask, int maskStep ))
IPPAPI ( IppStatus, ippiCopy_8u_AC4MR,
                    ( const Ipp8u* pSrc, int srcStep,
                      Ipp8u* pDst, int dstStep,IppiSize roiSize,
                      const Ipp8u* pMask, int maskStep ))
IPPAPI( IppStatus, ippiCopy_16s_C3C1R,
                   ( const Ipp16s* pSrc, int srcStep,
                     Ipp16s* pDst, int dstStep, IppiSize roiSize ))
IPPAPI( IppStatus, ippiCopy_16s_C1C3R,
                   ( const Ipp16s* pSrc, int srcStep,
                     Ipp16s* pDst, int dstStep, IppiSize roiSize ))
IPPAPI( IppStatus, ippiCopy_16s_C4C1R,
                   ( const Ipp16s* pSrc, int srcStep,
                     Ipp16s* pDst, int dstStep, IppiSize roiSize ))
IPPAPI( IppStatus, ippiCopy_16s_C1C4R,
                   ( const Ipp16s* pSrc, int srcStep,
                     Ipp16s* pDst, int dstStep, IppiSize roiSize ))
IPPAPI( IppStatus, ippiCopy_16s_C3CR,
                   ( const Ipp16s* pSrc, int srcStep,
                     Ipp16s* pDst, int dstStep, IppiSize roiSize ))
IPPAPI( IppStatus, ippiCopy_16s_C4CR,
                   ( const Ipp16s* pSrc, int srcStep,
                     Ipp16s* pDst, int dstStep, IppiSize roiSize ))
IPPAPI( IppStatus, ippiCopy_16s_AC4C3R,
                   ( const Ipp16s* pSrc, int srcStep,
                     Ipp16s* pDst, int dstStep, IppiSize roiSize ))
IPPAPI( IppStatus, ippiCopy_16s_C3AC4R,
                   ( const Ipp16s* pSrc, int srcStep,
                     Ipp16s* pDst, int dstStep, IppiSize roiSize ))
IPPAPI ( IppStatus, ippiCopy_16s_C1R,
                    ( const Ipp16s* pSrc, int srcStep,
                      Ipp16s* pDst, int dstStep,IppiSize roiSize ))
IPPAPI ( IppStatus, ippiCopy_16s_C3R,
                    ( const Ipp16s* pSrc, int srcStep,
                      Ipp16s* pDst, int dstStep,IppiSize roiSize ))
IPPAPI ( IppStatus, ippiCopy_16s_C4R,
                    ( const Ipp16s* pSrc, int srcStep,
                      Ipp16s* pDst, int dstStep,IppiSize roiSize ))
IPPAPI ( IppStatus, ippiCopy_16s_AC4R,
                    ( const Ipp16s* pSrc, int srcStep,
                      Ipp16s* pDst, int dstStep,IppiSize roiSize ))
IPPAPI ( IppStatus, ippiCopy_16s_C1MR,
                    ( const Ipp16s* pSrc, int srcStep,
                      Ipp16s* pDst, int dstStep,IppiSize roiSize,
                      const Ipp8u* pMask, int maskStep ))
IPPAPI ( IppStatus, ippiCopy_16s_C3MR,
                    ( const Ipp16s* pSrc, int srcStep,
                      Ipp16s* pDst, int dstStep,IppiSize roiSize,
                      const Ipp8u* pMask, int maskStep ))
IPPAPI ( IppStatus, ippiCopy_16s_C4MR,
                    ( const Ipp16s* pSrc, int srcStep,
                      Ipp16s* pDst, int dstStep,IppiSize roiSize,
                      const Ipp8u* pMask, int maskStep ))
IPPAPI ( IppStatus, ippiCopy_16s_AC4MR,
                    ( const Ipp16s* pSrc, int srcStep,
                      Ipp16s* pDst, int dstStep,IppiSize roiSize,
                      const Ipp8u* pMask, int maskStep ))
IPPAPI( IppStatus, ippiCopy_32f_C3C1R,
                   ( const Ipp32f* pSrc, int srcStep,
                     Ipp32f* pDst, int dstStep, IppiSize roiSize ))
IPPAPI( IppStatus, ippiCopy_32f_C1C3R,
                   ( const Ipp32f* pSrc, int srcStep,
                     Ipp32f* pDst, int dstStep, IppiSize roiSize ))
IPPAPI( IppStatus, ippiCopy_32f_C4C1R,
                   ( const Ipp32f* pSrc, int srcStep,
                     Ipp32f* pDst, int dstStep, IppiSize roiSize ))
IPPAPI( IppStatus, ippiCopy_32f_C1C4R,
                   ( const Ipp32f* pSrc, int srcStep,
                     Ipp32f* pDst, int dstStep, IppiSize roiSize ))
IPPAPI( IppStatus, ippiCopy_32f_C3CR,
                   ( const Ipp32f* pSrc, int srcStep,
                     Ipp32f* pDst, int dstStep, IppiSize roiSize ))
IPPAPI( IppStatus, ippiCopy_32f_C4CR,
                   ( const Ipp32f* pSrc, int srcStep,
                     Ipp32f* pDst, int dstStep, IppiSize roiSize ))
IPPAPI( IppStatus, ippiCopy_32f_AC4C3R,
                   ( const Ipp32f* pSrc, int srcStep,
                     Ipp32f* pDst, int dstStep, IppiSize roiSize ))
IPPAPI( IppStatus, ippiCopy_32f_C3AC4R,
                   ( const Ipp32f* pSrc, int srcStep,
                     Ipp32f* pDst, int dstStep, IppiSize roiSize ))
IPPAPI ( IppStatus, ippiCopy_32f_C1R,
                    ( const Ipp32f* pSrc, int srcStep,
                      Ipp32f* pDst, int dstStep,IppiSize roiSize ))
IPPAPI ( IppStatus, ippiCopy_32f_C3R,
                    ( const Ipp32f* pSrc, int srcStep,
                      Ipp32f* pDst, int dstStep,IppiSize roiSize ))
IPPAPI ( IppStatus, ippiCopy_32f_C4R,
                    ( const Ipp32f* pSrc, int srcStep,
                      Ipp32f* pDst, int dstStep,IppiSize roiSize ))
IPPAPI ( IppStatus, ippiCopy_32f_AC4R,
                    ( const Ipp32f* pSrc, int srcStep,
                      Ipp32f* pDst, int dstStep,IppiSize roiSize ))
IPPAPI ( IppStatus, ippiCopy_32f_C1MR,
                    ( const Ipp32f* pSrc, int srcStep,
                      Ipp32f* pDst, int dstStep,IppiSize roiSize,
                      const Ipp8u* pMask, int maskStep ))
IPPAPI ( IppStatus, ippiCopy_32f_C3MR,
                    ( const Ipp32f* pSrc, int srcStep,
                      Ipp32f* pDst, int dstStep,IppiSize roiSize,
                      const Ipp8u* pMask, int maskStep ))
IPPAPI ( IppStatus, ippiCopy_32f_C4MR,
                    ( const Ipp32f* pSrc, int srcStep,
                      Ipp32f* pDst, int dstStep,IppiSize roiSize,
                      const Ipp8u* pMask, int maskStep ))
IPPAPI ( IppStatus, ippiCopy_32f_AC4MR,
                    ( const Ipp32f* pSrc, int srcStep,
                      Ipp32f* pDst, int dstStep,IppiSize roiSize,
                      const Ipp8u* pMask, int maskStep ))
IPPAPI ( IppStatus, ippiCopy_8u_C3P3R, ( const Ipp8u* pSrc, int srcStep,
                    Ipp8u* const pDst[3], int dstStep, IppiSize roiSize ))
IPPAPI ( IppStatus, ippiCopy_8u_P3C3R, (const  Ipp8u* const pSrc[3],
                            int srcStep, Ipp8u* pDst, int dstStep, IppiSize roiSize ))
IPPAPI ( IppStatus, ippiCopy_8u_C4P4R, ( const Ipp8u* pSrc, int srcStep,
                    Ipp8u* const pDst[4], int dstStep, IppiSize roiSize ))
IPPAPI ( IppStatus, ippiCopy_8u_P4C4R, (const  Ipp8u* const pSrc[4],
                            int srcStep, Ipp8u* pDst, int dstStep, IppiSize roiSize ))
IPPAPI ( IppStatus, ippiCopy_16s_C3P3R, ( const Ipp16s* pSrc, int srcStep,
                    Ipp16s* const pDst[3], int dstStep, IppiSize roiSize ))
IPPAPI ( IppStatus, ippiCopy_16s_P3C3R, (const  Ipp16s* const pSrc[3],
                            int srcStep, Ipp16s* pDst, int dstStep, IppiSize roiSize ))
IPPAPI ( IppStatus, ippiCopy_16s_C4P4R, ( const Ipp16s* pSrc, int srcStep,
                    Ipp16s* const pDst[4], int dstStep, IppiSize roiSize ))
IPPAPI ( IppStatus, ippiCopy_16s_P4C4R, (const  Ipp16s* const pSrc[4],
                            int srcStep, Ipp16s* pDst, int dstStep, IppiSize roiSize ))
IPPAPI ( IppStatus, ippiCopy_32f_C3P3R, ( const Ipp32f* pSrc, int srcStep,
                    Ipp32f* const pDst[3], int dstStep, IppiSize roiSize ))
IPPAPI ( IppStatus, ippiCopy_32f_P3C3R, (const  Ipp32f* const pSrc[3],
                            int srcStep, Ipp32f* pDst, int dstStep, IppiSize roiSize ))
IPPAPI ( IppStatus, ippiCopy_32f_C4P4R, ( const Ipp32f* pSrc, int srcStep,
                    Ipp32f* const pDst[4], int dstStep, IppiSize roiSize ))
IPPAPI ( IppStatus, ippiCopy_32f_P4C4R, (const  Ipp32f* const pSrc[4],
                            int srcStep, Ipp32f* pDst, int dstStep, IppiSize roiSize ))

/* ////////////////////////////////////////////////////////////////////////////
//  Name:       ippiCopyReplicateBorder
//
//  Purpose:     Copies pixel values between two buffers and adds the border pixels.
//
//  Return:
//    ippStsNullPtrErr      One of the pointers is NULL
//    ippStsSizeErr         1). srcRoiSize or dstRoiSize has a field with negative or zero value
//                          2). topBorderWidth or leftBorderWidth is less than zero
//                          3). dstRoiSize.width < srcRoiSize.width + leftBorderWidth
//                          4). dstRoiSize.height < srcRoiSize.height + topBorderWidth
//    ippStsStepErr         srcStep or dstStep is less than or equal to zero
//    ippStsNoErr           Ok
//
//  Arguments:
//    pSrc                  pointer  to the source image buffer
//    srcStep               size of the source image scan-line in bytes
//    pDst                  pointer to the  destination image buffer
//    dstStep               size of the destination image scan-line in bytes
//    scrRoiSize            size of the source ROI in pixels
//    dstRoiSize            size of the destination ROI in pixels
//    topBorderWidth        width of the top border in pixels
//    leftBorderWidth       width of the left border in pixels
*/

IPPAPI (IppStatus, ippiCopyReplicateBorder_8u_C1R,
            ( const Ipp8u* pSrc,  int srcStep, IppiSize srcRoiSize,
                    Ipp8u* pDst,  int dstStep, IppiSize dstRoiSize,
                    int topBorderWidth, int leftBorderWidth ) )
IPPAPI (IppStatus, ippiCopyReplicateBorder_8u_C3R,
            ( const Ipp8u* pSrc,  int srcStep, IppiSize srcRoiSize,
                    Ipp8u* pDst,  int dstStep, IppiSize dstRoiSize,
                    int topBorderWidth, int leftBorderWidth ) )
IPPAPI (IppStatus, ippiCopyReplicateBorder_8u_AC4R,
            ( const Ipp8u* pSrc,  int srcStep, IppiSize srcRoiSize,
                    Ipp8u* pDst,  int dstStep, IppiSize dstRoiSize,
                    int topBorderWidth, int leftBorderWidth ) )
IPPAPI (IppStatus, ippiCopyReplicateBorder_8u_C4R,
            ( const Ipp8u* pSrc,  int srcStep, IppiSize srcRoiSize,
                    Ipp8u* pDst,  int dstStep, IppiSize dstRoiSize,
                    int topBorderWidth, int leftBorderWidth ) )
IPPAPI (IppStatus, ippiCopyReplicateBorder_16s_C1R,
            ( const Ipp16s* pSrc,  int srcStep, IppiSize srcRoiSize,
                    Ipp16s* pDst,  int dstStep, IppiSize dstRoiSize,
                    int topBorderWidth, int leftBorderWidth ) )
IPPAPI (IppStatus, ippiCopyReplicateBorder_16s_C3R,
            ( const Ipp16s* pSrc,  int srcStep, IppiSize srcRoiSize,
                    Ipp16s* pDst,  int dstStep, IppiSize dstRoiSize,
                    int topBorderWidth, int leftBorderWidth ) )
IPPAPI (IppStatus, ippiCopyReplicateBorder_16s_AC4R,
            ( const Ipp16s* pSrc,  int srcStep, IppiSize srcRoiSize,
                    Ipp16s* pDst,  int dstStep, IppiSize dstRoiSize,
                    int topBorderWidth, int leftBorderWidth ) )
IPPAPI (IppStatus, ippiCopyReplicateBorder_16s_C4R,
            ( const Ipp16s* pSrc,  int srcStep, IppiSize srcRoiSize,
                    Ipp16s* pDst,  int dstStep, IppiSize dstRoiSize,
                    int topBorderWidth, int leftBorderWidth ) )
IPPAPI (IppStatus, ippiCopyReplicateBorder_32s_C1R,
            ( const Ipp32s* pSrc,  int srcStep, IppiSize srcRoiSize,
                    Ipp32s* pDst,  int dstStep, IppiSize dstRoiSize,
                    int topBorderWidth, int leftBorderWidth ) )
IPPAPI (IppStatus, ippiCopyReplicateBorder_32s_C3R,
            ( const Ipp32s* pSrc,  int srcStep, IppiSize srcRoiSize,
                    Ipp32s* pDst,  int dstStep, IppiSize dstRoiSize,
                    int topBorderWidth, int leftBorderWidth ) )
IPPAPI (IppStatus, ippiCopyReplicateBorder_32s_AC4R,
            ( const Ipp32s* pSrc,  int srcStep, IppiSize srcRoiSize,
                    Ipp32s* pDst,  int dstStep, IppiSize dstRoiSize,
                    int topBorderWidth, int leftBorderWidth ) )
IPPAPI (IppStatus, ippiCopyReplicateBorder_32s_C4R,
            ( const Ipp32s* pSrc,  int srcStep, IppiSize srcRoiSize,
                    Ipp32s* pDst,  int dstStep, IppiSize dstRoiSize,
                    int topBorderWidth, int leftBorderWidth ) )

/* ////////////////////////////////////////////////////////////////////////////
//  Name:       ippiCopyConstBorder
//
//  Purpose:    Copies pixel values between two buffers and adds the border pixels with constant value.
//
//  Return:
//    ippStsNullPtrErr      One of the pointers is NULL
//    ippStsSizeErr         1). srcRoiSize or dstRoiSize has a field with negative or zero value
//                          2). topBorderWidth or leftBorderWidth is less than zero
//                          3). dstRoiSize.width < srcRoiSize.width + leftBorderWidth
//                          4). dstRoiSize.height < srcRoiSize.height + topBorderWidth
//    ippStsStepErr         srcStep or dstStep is less than or equal to zero
//    ippStsNoErr           Ok
//
//  Arguments:
//    pSrc                  pointer  to the source image buffer
//    srcStep               size of the source image scan-line in bytes
//    pDst                  pointer to the  destination image buffer
//    dstStep               size of the destination image scan-line in bytes
//    srcRoiSize            size of the source ROI in pixels
//    dstRoiSize            size of the destination ROI in pixels
//    topBorderWidth        width of the top border in pixels
//    leftBorderWidth       width of the left border in pixels
//    value                 value that is assigned to the elements of the border
*/

IPPAPI (IppStatus, ippiCopyConstBorder_8u_C1R,
            ( const Ipp8u* pSrc,  int srcStep, IppiSize srcRoiSize,
                    Ipp8u* pDst,  int dstStep, IppiSize dstRoiSize,
                            int topBorderWidth, int leftBorderWidth,
                            Ipp8u value ) )
IPPAPI (IppStatus, ippiCopyConstBorder_8u_C3R,
            ( const Ipp8u* pSrc,  int srcStep, IppiSize srcRoiSize,
                    Ipp8u* pDst,  int dstStep, IppiSize dstRoiSize,
                            int topBorderWidth, int leftBorderWidth,
                            const Ipp8u value[3] ) )
IPPAPI (IppStatus, ippiCopyConstBorder_8u_AC4R,
            ( const Ipp8u* pSrc,  int srcStep, IppiSize srcRoiSize,
                    Ipp8u* pDst,  int dstStep, IppiSize dstRoiSize,
                            int topBorderWidth, int leftBorderWidth,
                            const Ipp8u value[3] ) )
IPPAPI (IppStatus, ippiCopyConstBorder_8u_C4R,
            ( const Ipp8u* pSrc,  int srcStep, IppiSize srcRoiSize,
                    Ipp8u* pDst,  int dstStep, IppiSize dstRoiSize,
                            int topBorderWidth, int leftBorderWidth,
                            const Ipp8u value[4] ) )
IPPAPI (IppStatus, ippiCopyConstBorder_16s_C1R,
            ( const Ipp16s* pSrc,  int srcStep, IppiSize srcRoiSize,
                    Ipp16s* pDst,  int dstStep, IppiSize dstRoiSize,
                            int topBorderWidth, int leftBorderWidth,
                            Ipp16s value ) )
IPPAPI (IppStatus, ippiCopyConstBorder_16s_C3R,
            ( const Ipp16s* pSrc,  int srcStep, IppiSize srcRoiSize,
                    Ipp16s* pDst,  int dstStep, IppiSize dstRoiSize,
                            int topBorderWidth, int leftBorderWidth,
                            const Ipp16s value[3] ) )
IPPAPI (IppStatus, ippiCopyConstBorder_16s_AC4R,
            ( const Ipp16s* pSrc,  int srcStep, IppiSize srcRoiSize,
                    Ipp16s* pDst,  int dstStep, IppiSize dstRoiSize,
                            int topBorderWidth, int leftBorderWidth,
                            const Ipp16s value[3] ) )
IPPAPI (IppStatus, ippiCopyConstBorder_16s_C4R,
            ( const Ipp16s* pSrc,  int srcStep, IppiSize srcRoiSize,
                    Ipp16s* pDst,  int dstStep, IppiSize dstRoiSize,
                            int topBorderWidth, int leftBorderWidth,
                            const Ipp16s value[4] ) )
IPPAPI (IppStatus, ippiCopyConstBorder_32s_C1R,
            ( const Ipp32s* pSrc,  int srcStep, IppiSize srcRoiSize,
                    Ipp32s* pDst,  int dstStep, IppiSize dstRoiSize,
                            int topBorderWidth, int leftBorderWidth,
                            Ipp32s value ) )
IPPAPI (IppStatus, ippiCopyConstBorder_32s_C3R,
            ( const Ipp32s* pSrc,  int srcStep, IppiSize srcRoiSize,
                    Ipp32s* pDst,  int dstStep, IppiSize dstRoiSize,
                            int topBorderWidth, int leftBorderWidth,
                            const Ipp32s value[3] ) )
IPPAPI (IppStatus, ippiCopyConstBorder_32s_AC4R,
            ( const Ipp32s* pSrc,  int srcStep, IppiSize srcRoiSize,
                    Ipp32s* pDst,  int dstStep, IppiSize dstRoiSize,
                            int topBorderWidth, int leftBorderWidth,
                            const Ipp32s value[3] ) )
IPPAPI (IppStatus, ippiCopyConstBorder_32s_C4R,
            ( const Ipp32s* pSrc,  int srcStep, IppiSize srcRoiSize,
                    Ipp32s* pDst,  int dstStep, IppiSize dstRoiSize,
                            int topBorderWidth, int leftBorderWidth,
                            const Ipp32s value[4] ) )

/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippiSet
//
//  Purpose:    set elements of the destination image to a constant value
//
//  Return:
//    ippStsNullPtrErr  One of pointers is NULL
//    ippStsSizeErr     The length of the vector is less or equal zero
//    ippStsStepErr     The steps in images are less or equal zero
//    ippStsNoErr       Ok
//
//  Arguments:
//    value             value to set each element of the image to
//    pDst              pointer to the destination image buffer
//    dstStep           step in bytes through the destination image buffer
//    roiSize           size of ROI
//    pMask             pointer to the mask image buffer
//    maskStep          step in bytes through the mask image buffer
*/

IPPAPI ( IppStatus, ippiSet_8u_C1R,
                    ( Ipp8u value, Ipp8u* pDst, int dstStep,
                      IppiSize roiSize ))
IPPAPI ( IppStatus, ippiSet_8u_C3CR,
                    ( Ipp8u value, Ipp8u* pDst, int dstStep,
                      IppiSize roiSize ))
IPPAPI ( IppStatus, ippiSet_8u_C4CR,
                    ( Ipp8u value, Ipp8u* pDst, int dstStep,
                      IppiSize roiSize ))
IPPAPI ( IppStatus, ippiSet_8u_C3R,
                    ( const Ipp8u value[3], Ipp8u* pDst, int dstStep,
                      IppiSize roiSize ))
IPPAPI ( IppStatus, ippiSet_8u_C4R,
                    ( const Ipp8u value[4], Ipp8u* pDst, int dstStep,
                      IppiSize roiSize ))
IPPAPI ( IppStatus, ippiSet_8u_AC4R,
                    ( const Ipp8u value[3], Ipp8u* pDst, int dstStep,
                      IppiSize roiSize ))
IPPAPI ( IppStatus, ippiSet_8u_C1MR,
                    ( Ipp8u value, Ipp8u* pDst, int dstStep,
                      IppiSize roiSize,
                      const Ipp8u* pMask, int maskStep ))
IPPAPI ( IppStatus, ippiSet_8u_C3MR,
                    ( const Ipp8u value[3], Ipp8u* pDst, int dstStep,
                      IppiSize roiSize,
                      const Ipp8u* pMask, int maskStep ))
IPPAPI ( IppStatus, ippiSet_8u_C4MR,
                    ( const Ipp8u value[4], Ipp8u* pDst, int dstStep,
                      IppiSize roiSize,
                      const Ipp8u* pMask, int maskStep ))
IPPAPI ( IppStatus, ippiSet_8u_AC4MR,
                    ( const Ipp8u value[3], Ipp8u* pDst, int dstStep,
                      IppiSize roiSize,
                      const Ipp8u* pMask, int maskStep ))
IPPAPI ( IppStatus, ippiSet_16s_C1R,
                    ( Ipp16s value, Ipp16s* pDst, int dstStep,
                      IppiSize roiSize ))
IPPAPI ( IppStatus, ippiSet_16s_C3CR,
                    ( Ipp16s value, Ipp16s* pDst, int dstStep,
                      IppiSize roiSize ))
IPPAPI ( IppStatus, ippiSet_16s_C4CR,
                    ( Ipp16s value, Ipp16s* pDst, int dstStep,
                      IppiSize roiSize ))
IPPAPI ( IppStatus, ippiSet_16s_C3R,
                    ( const Ipp16s value[3], Ipp16s* pDst, int dstStep,
                      IppiSize roiSize ))
IPPAPI ( IppStatus, ippiSet_16s_C4R,
                    ( const Ipp16s value[4], Ipp16s* pDst, int dstStep,
                      IppiSize roiSize ))
IPPAPI ( IppStatus, ippiSet_16s_AC4R,
                    ( const Ipp16s value[3], Ipp16s* pDst, int dstStep,
                      IppiSize roiSize ))
IPPAPI ( IppStatus, ippiSet_16s_C1MR,
                    ( Ipp16s value, Ipp16s* pDst, int dstStep,
                      IppiSize roiSize,
                      const Ipp8u* pMask, int maskStep ))
IPPAPI ( IppStatus, ippiSet_16s_C3MR,
                    ( const Ipp16s value[3], Ipp16s* pDst, int dstStep,
                      IppiSize roiSize,
                      const Ipp8u* pMask, int maskStep ))
IPPAPI ( IppStatus, ippiSet_16s_C4MR,
                    ( const Ipp16s value[4], Ipp16s* pDst, int dstStep,
                      IppiSize roiSize,
                      const Ipp8u* pMask, int maskStep ))
IPPAPI ( IppStatus, ippiSet_16s_AC4MR,
                    ( const Ipp16s value[3], Ipp16s* pDst, int dstStep,
                      IppiSize roiSize,
                      const Ipp8u* pMask, int maskStep ))
IPPAPI ( IppStatus, ippiSet_32f_C1R,
                    ( Ipp32f value, Ipp32f* pDst, int dstStep,
                      IppiSize roiSize ))
IPPAPI ( IppStatus, ippiSet_32f_C3CR,
                    ( Ipp32f value, Ipp32f* pDst, int dstStep,
                      IppiSize roiSize ))
IPPAPI ( IppStatus, ippiSet_32f_C4CR,
                    ( Ipp32f value, Ipp32f* pDst, int dstStep,
                      IppiSize roiSize ))
IPPAPI ( IppStatus, ippiSet_32f_C3R,
                    ( const Ipp32f value[3], Ipp32f* pDst, int dstStep,
                      IppiSize roiSize ))
IPPAPI ( IppStatus, ippiSet_32f_C4R,
                    ( const Ipp32f value[4], Ipp32f* pDst, int dstStep,
                      IppiSize roiSize ))
IPPAPI ( IppStatus, ippiSet_32f_AC4R,
                    ( const Ipp32f value[3], Ipp32f* pDst, int dstStep,
                      IppiSize roiSize ))
IPPAPI ( IppStatus, ippiSet_32f_C1MR,
                    ( Ipp32f value, Ipp32f* pDst, int dstStep,
                      IppiSize roiSize,
                      const Ipp8u* pMask, int maskStep ))
IPPAPI ( IppStatus, ippiSet_32f_C3MR,
                    ( const Ipp32f value[3], Ipp32f* pDst, int dstStep,
                      IppiSize roiSize,
                      const Ipp8u* pMask, int maskStep ))
IPPAPI ( IppStatus, ippiSet_32f_C4MR,
                    ( const Ipp32f value[4], Ipp32f* pDst, int dstStep,
                      IppiSize roiSize,
                      const Ipp8u* pMask, int maskStep ))
IPPAPI ( IppStatus, ippiSet_32f_AC4MR,
                    ( const Ipp32f value[3], Ipp32f* pDst, int dstStep,
                      IppiSize roiSize,
                      const Ipp8u* pMask, int maskStep ))

/* ////////////////////////////////////////////////////////////////////////////
//  Name:       ippiAddRandUniform_Direct_8u_C1IR,  ippiAddRandUniform_Direct_8u_C3IR,
//  Name:       ippiAddRandUniform_Direct_8u_C4IR,  ippiAddRandUniform_Direct_8u_AC4IR,
//  Name:       ippiAddRandUniform_Direct_16s_C1IR, ippiAddRandUniform_Direct_16s_C3IR,
//  Name:       ippiAddRandUniform_Direct_16s_C4IR, ippiAddRandUniform_Direct_16s_AC4IR,
//  Name:       ippiAddRandUniform_Direct_32f_C1IR, ippiAddRandUniform_Direct_32f_C3IR,
//  Name:       ippiAddRandUniform_Direct_32f_C4IR, ippiAddRandUniform_Direct_32f_AC4IR
//
//  Purpose:    Generates pseudo-random samples with uniform distribution and adds them
//              to an image.
//
//  Return:
//    ippStsNoErr              Ok
//    ippStsNullPtrErr         One of the pointers is NULL
//    ippStsSizeErr            The width or height of an image is less than or equal to zero
//    ippStsStepErr            The step in image is less than or equal to zero
//
//  Arguments:
//    pSrcDst                  Pointer to the image
//    srcDstStep               Step in bytes through the image
//    roiSize                  ROI size
//    low                      The lower bounds of the uniform distributions range
//    high                     The upper bounds of the uniform distributions range
//    pSeed                    Pointer to the seed value for the pseudo-random number
//                             generator
*/

IPPAPI(IppStatus, ippiAddRandUniform_Direct_8u_C1IR,   (Ipp8u* pSrcDst, int srcDstStep,
                                                        IppiSize roiSize, Ipp8u low, Ipp8u high,
                                                        unsigned int* pSeed))
IPPAPI(IppStatus, ippiAddRandUniform_Direct_8u_C3IR,   (Ipp8u* pSrcDst, int srcDstStep,
                                                        IppiSize roiSize, Ipp8u low, Ipp8u high,
                                                        unsigned int* pSeed))
IPPAPI(IppStatus, ippiAddRandUniform_Direct_8u_C4IR,   (Ipp8u* pSrcDst, int srcDstStep,
                                                        IppiSize roiSize, Ipp8u low, Ipp8u high,
                                                        unsigned int* pSeed))
IPPAPI(IppStatus, ippiAddRandUniform_Direct_8u_AC4IR,  (Ipp8u* pSrcDst, int srcDstStep,
                                                        IppiSize roiSize, Ipp8u low, Ipp8u high,
                                                        unsigned int* pSeed))
IPPAPI(IppStatus, ippiAddRandUniform_Direct_16s_C1IR,  (Ipp16s* pSrcDst, int srcDstStep,
                                                        IppiSize roiSize, Ipp16s low, Ipp16s high,
                                                        unsigned int* pSeed))
IPPAPI(IppStatus, ippiAddRandUniform_Direct_16s_C3IR,  (Ipp16s* pSrcDst, int srcDstStep,
                                                        IppiSize roiSize, Ipp16s low, Ipp16s high,
                                                        unsigned int* pSeed))
IPPAPI(IppStatus, ippiAddRandUniform_Direct_16s_C4IR,  (Ipp16s* pSrcDst, int srcDstStep,
                                                        IppiSize roiSize, Ipp16s low, Ipp16s high,
                                                        unsigned int* pSeed))
IPPAPI(IppStatus, ippiAddRandUniform_Direct_16s_AC4IR, (Ipp16s* pSrcDst, int srcDstStep,
                                                        IppiSize roiSize, Ipp16s low, Ipp16s high,
                                                        unsigned int* pSeed))
IPPAPI(IppStatus, ippiAddRandUniform_Direct_32f_C1IR,  (Ipp32f* pSrcDst, int srcDstStep,
                                                        IppiSize roiSize, Ipp32f low, Ipp32f high,
                                                        unsigned int* pSeed))
IPPAPI(IppStatus, ippiAddRandUniform_Direct_32f_C3IR,  (Ipp32f* pSrcDst, int srcDstStep,
                                                        IppiSize roiSize, Ipp32f low, Ipp32f high,
                                                        unsigned int* pSeed))
IPPAPI(IppStatus, ippiAddRandUniform_Direct_32f_C4IR,  (Ipp32f* pSrcDst, int srcDstStep,
                                                        IppiSize roiSize, Ipp32f low, Ipp32f high,
                                                        unsigned int* pSeed))
IPPAPI(IppStatus, ippiAddRandUniform_Direct_32f_AC4IR, (Ipp32f* pSrcDst, int srcDstStep,
                                                        IppiSize roiSize, Ipp32f low, Ipp32f high,
                                                        unsigned int* pSeed))

/* ////////////////////////////////////////////////////////////////////////////
//  Name:       ippiAddRandGauss_Direct_8u_C1IR,  ippiAddRandGauss_Direct_8u_C3IR,
//              ippiAddRandGauss_Direct_8u_C4IR,  ippiAddRandGauss_Direct_8u_AC4IR
//              ippiAddRandGauss_Direct_16s_C1IR, ippiAddRandGauss_Direct_16s_C3IR,
//              ippiAddRandGauss_Direct_16s_C4IR, ippiAddRandGauss_Direct_16s_AC4IR,
//              ippiAddRandGauss_Direct_32f_C1IR, ippiAddRandGauss_Direct_32f_C3IR,
//              ippiAddRandGauss_Direct_32f_C4IR, ippiAddRandGauss_Direct_32f_AC4IR
//
//  Purpose:    Generates pseudo-random samples with normal distribution and adds them
//              to an image.
//
//  Return:
//    ippStsNoErr              Ok
//    ippStsNullPtrErr         One of the pointers is NULL
//    ippStsSizeErr            The width or height of the image is less than or equal to zero
//    ippStsStepErr            The step value is less than or equal to zero
//
//  Arguments:
//    pSrcDst                  Pointer to the image
//    srcDstStep               Step in bytes through the image
//    roiSize                  ROI size
//    mean                     The mean of the normal distribution
//    stdev                    The standard deviation of the normal distribution
//    pSeed                    Pointer to the seed value for the pseudo-random number
//                             generator
*/

IPPAPI(IppStatus, ippiAddRandGauss_Direct_8u_C1IR,   (Ipp8u* pSrcDst, int srcDstStep,
                                                      IppiSize roiSize, Ipp8u mean, Ipp8u stdev,
                                                      unsigned int* pSeed))
IPPAPI(IppStatus, ippiAddRandGauss_Direct_8u_C3IR,   (Ipp8u* pSrcDst, int srcDstStep,
                                                      IppiSize roiSize, Ipp8u mean, Ipp8u stdev,
                                                      unsigned int* pSeed))
IPPAPI(IppStatus, ippiAddRandGauss_Direct_8u_C4IR,   (Ipp8u* pSrcDst, int srcDstStep,
                                                      IppiSize roiSize, Ipp8u mean, Ipp8u stdev,
                                                      unsigned int* pSeed))
IPPAPI(IppStatus, ippiAddRandGauss_Direct_8u_AC4IR,  (Ipp8u* pSrcDst, int srcDstStep,
                                                      IppiSize roiSize, Ipp8u mean, Ipp8u stdev,
                                                      unsigned int* pSeed))
IPPAPI(IppStatus, ippiAddRandGauss_Direct_16s_C1IR,  (Ipp16s* pSrcDst, int srcDstStep,
                                                      IppiSize roiSize, Ipp16s mean, Ipp16s stdev,
                                                      unsigned int* pSeed))
IPPAPI(IppStatus, ippiAddRandGauss_Direct_16s_C3IR,  (Ipp16s* pSrcDst, int srcDstStep,
                                                      IppiSize roiSize, Ipp16s mean, Ipp16s stdev,
                                                      unsigned int* pSeed))
IPPAPI(IppStatus, ippiAddRandGauss_Direct_16s_C4IR,  (Ipp16s* pSrcDst, int srcDstStep,
                                                      IppiSize roiSize, Ipp16s mean, Ipp16s stdev,
                                                      unsigned int* pSeed))
IPPAPI(IppStatus, ippiAddRandGauss_Direct_16s_AC4IR, (Ipp16s* pSrcDst, int srcDstStep,
                                                      IppiSize roiSize, Ipp16s mean, Ipp16s stdev,
                                                      unsigned int* pSeed))
IPPAPI(IppStatus, ippiAddRandGauss_Direct_32f_C1IR,  (Ipp32f* pSrcDst, int srcDstStep,
                                                      IppiSize roiSize, Ipp32f mean, Ipp32f stdev,
                                                      unsigned int* pSeed))
IPPAPI(IppStatus, ippiAddRandGauss_Direct_32f_C3IR,  (Ipp32f* pSrcDst, int srcDstStep,
                                                      IppiSize roiSize, Ipp32f mean, Ipp32f stdev,
                                                      unsigned int* pSeed))
IPPAPI(IppStatus, ippiAddRandGauss_Direct_32f_C4IR,  (Ipp32f* pSrcDst, int srcDstStep,
                                                      IppiSize roiSize, Ipp32f mean, Ipp32f stdev,
                                                      unsigned int* pSeed))
IPPAPI(IppStatus, ippiAddRandGauss_Direct_32f_AC4IR, (Ipp32f* pSrcDst, int srcDstStep,
                                                      IppiSize roiSize, Ipp32f mean, Ipp32f stdev,
                                                      unsigned int* pSeed))


/* /////////////////////////////////////////////////////////////////////////
//  Name:               ippiImageJaehne
//  Purpose:            functions to create ippi test image (Jaehne's)
//  Returns:
//    ippStsNoErr       indicates no error, an ippi test image is created
//    ippStsNullPtrErr  indicates an error when pDst pointer is NULL
//    ippStsSizeErr     indicates an error when size of roi or DstStep is less than or equal to zero
//  Parameters:
//    pDst              pointer to the destination buffer
//    DstStep           step in bytes through the destination buffer
//    roiSize           size of the destination image roi in pixels
//  Notes:
//                      Dst(x,y,) = A*Sin(0.5*IPP_PI* (x2^2 + y2^2) / roiSize.height),
//                      x variables from 0 to roi.width-1,
//                      y variables from 0 to roi.height-1,
//                      x2 = (x-roi.width+1)/2.0 ,   y2 = (y-roi.height+1)/2.0 .
//                      A is the constant value depends on the image type being created.
*/

IPPAPI(IppStatus, ippiImageJaehne_8u_C1R, (Ipp8u* pDst, int DstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiImageJaehne_8u_C3R, (Ipp8u* pDst, int DstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiImageJaehne_8s_C1R, (Ipp8s* pDst, int DstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiImageJaehne_8s_C3R, (Ipp8s* pDst, int DstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiImageJaehne_16u_C1R, (Ipp16u* pDst, int DstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiImageJaehne_16u_C3R, (Ipp16u* pDst, int DstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiImageJaehne_16s_C1R, (Ipp16s* pDst, int DstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiImageJaehne_16s_C3R, (Ipp16s* pDst, int DstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiImageJaehne_32s_C1R, (Ipp32s* pDst, int DstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiImageJaehne_32s_C3R, (Ipp32s* pDst, int DstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiImageJaehne_32f_C1R, (Ipp32f* pDst, int DstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiImageJaehne_32f_C3R, (Ipp32f* pDst, int DstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiImageJaehne_8u_C4R,  (Ipp8u* pDst,  int DstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiImageJaehne_8s_C4R,  (Ipp8s* pDst,  int DstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiImageJaehne_16u_C4R, (Ipp16u* pDst, int DstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiImageJaehne_16s_C4R, (Ipp16s* pDst, int DstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiImageJaehne_32s_C4R, (Ipp32s* pDst, int DstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiImageJaehne_32f_C4R, (Ipp32f* pDst, int DstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiImageJaehne_8u_AC4R, (Ipp8u* pDst,  int DstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiImageJaehne_8s_AC4R, (Ipp8s* pDst,  int DstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiImageJaehne_16u_AC4R,(Ipp16u* pDst, int DstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiImageJaehne_16s_AC4R,(Ipp16s* pDst, int DstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiImageJaehne_32s_AC4R,(Ipp32s* pDst, int DstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiImageJaehne_32f_AC4R,(Ipp32f* pDst, int DstStep, IppiSize roiSize))


/* /////////////////////////////////////////////////////////////////////////
//  Name:               ippiImageRamp
//  Purpose:            functions to create ippi test image (Ramp)
//  Returns:
//    ippStsNoErr       indicates no error, an ippi test image is created
//    ippStsNullPtrErr  indicates an error when pDst pointer is NULL
//    ippStsSizeErr     indicates an error, if size of roi or DstStep is less than or equal to zero
//  Parameters:
//    pDst              pointer to the destination buffer
//    DstStep           step in bytes through the destination buffer
//    roiSize           size of the destination image roi in pixels
//    offset            offset value
//    slope             slope coefficient
//    axis              specifies the direction of the image intensity ramp,
//                      one of the following:
//                        ippAxsHorizontal   in X-direction,
//                        ippAxsVertical     in Y-direction,
//                        ippAxsBoth         in both X and Y-directions.
//  Notes:              Dst(x,y) = offset + slope * x   (if ramp for X-direction)
//                      Dst(x,y) = offset + slope * y   (if ramp for Y-direction)
//                      Dst(x,y) = offset + slope * x*y (if ramp for X,Y-direction)
*/
IPPAPI(IppStatus, ippiImageRamp_8u_C1R, (Ipp8u* pDst, int DstStep, IppiSize roiSize, float offset, float slope, IppiAxis axis))
IPPAPI(IppStatus, ippiImageRamp_8u_C3R, (Ipp8u* pDst, int DstStep, IppiSize roiSize, float offset, float slope, IppiAxis axis))
IPPAPI(IppStatus, ippiImageRamp_8s_C1R, (Ipp8s* pDst, int DstStep, IppiSize roiSize, float offset, float slope, IppiAxis axis))
IPPAPI(IppStatus, ippiImageRamp_8s_C3R, (Ipp8s* pDst, int DstStep, IppiSize roiSize, float offset, float slope, IppiAxis axis))
IPPAPI(IppStatus, ippiImageRamp_16u_C1R, (Ipp16u* pDst, int DstStep, IppiSize roiSize, float offset, float slope, IppiAxis axis))
IPPAPI(IppStatus, ippiImageRamp_16u_C3R, (Ipp16u* pDst, int DstStep, IppiSize roiSize, float offset, float slope, IppiAxis axis))
IPPAPI(IppStatus, ippiImageRamp_16s_C1R, (Ipp16s* pDst, int DstStep, IppiSize roiSize, float offset, float slope, IppiAxis axis))
IPPAPI(IppStatus, ippiImageRamp_16s_C3R, (Ipp16s* pDst, int DstStep, IppiSize roiSize, float offset, float slope, IppiAxis axis))
IPPAPI(IppStatus, ippiImageRamp_32s_C1R, (Ipp32s* pDst, int DstStep, IppiSize roiSize, float offset, float slope, IppiAxis axis))
IPPAPI(IppStatus, ippiImageRamp_32s_C3R, (Ipp32s* pDst, int DstStep, IppiSize roiSize, float offset, float slope, IppiAxis axis))
IPPAPI(IppStatus, ippiImageRamp_32f_C1R, (Ipp32f* pDst, int DstStep, IppiSize roiSize, float offset, float slope, IppiAxis axis))
IPPAPI(IppStatus, ippiImageRamp_32f_C3R, (Ipp32f* pDst, int DstStep, IppiSize roiSize, float offset, float slope, IppiAxis axis))
IPPAPI(IppStatus, ippiImageRamp_8u_C4R, (Ipp8u* pDst, int DstStep, IppiSize roiSize, float offset, float slope, IppiAxis axis))
IPPAPI(IppStatus, ippiImageRamp_8s_C4R, (Ipp8s* pDst, int DstStep, IppiSize roiSize, float offset, float slope, IppiAxis axis))
IPPAPI(IppStatus, ippiImageRamp_16u_C4R,(Ipp16u* pDst, int DstStep, IppiSize roiSize, float offset, float slope, IppiAxis axis))
IPPAPI(IppStatus, ippiImageRamp_16s_C4R,(Ipp16s* pDst, int DstStep, IppiSize roiSize, float offset, float slope, IppiAxis axis))
IPPAPI(IppStatus, ippiImageRamp_32s_C4R,(Ipp32s* pDst, int DstStep, IppiSize roiSize, float offset, float slope, IppiAxis axis))
IPPAPI(IppStatus, ippiImageRamp_32f_C4R,(Ipp32f* pDst, int DstStep, IppiSize roiSize, float offset, float slope, IppiAxis axis))
IPPAPI(IppStatus, ippiImageRamp_8u_AC4R, (Ipp8u* pDst, int DstStep, IppiSize roiSize, float offset, float slope, IppiAxis axis))
IPPAPI(IppStatus, ippiImageRamp_8s_AC4R, (Ipp8s* pDst, int DstStep, IppiSize roiSize, float offset, float slope, IppiAxis axis))
IPPAPI(IppStatus, ippiImageRamp_16u_AC4R,(Ipp16u* pDst, int DstStep, IppiSize roiSize, float offset, float slope, IppiAxis axis))
IPPAPI(IppStatus, ippiImageRamp_16s_AC4R,(Ipp16s* pDst, int DstStep, IppiSize roiSize, float offset, float slope, IppiAxis axis))
IPPAPI(IppStatus, ippiImageRamp_32s_AC4R,(Ipp32s* pDst, int DstStep, IppiSize roiSize, float offset, float slope, IppiAxis axis))
IPPAPI(IppStatus, ippiImageRamp_32f_AC4R,(Ipp32f* pDst, int DstStep, IppiSize roiSize, float offset, float slope, IppiAxis axis))


/* ////////////////////////////////////////////////////////////////////////////
//  Name:       ippiConvert
//
//  Purpose:    Convert pixel values from one bit depth to another
//
//  Return:
//    ippStsNullPtrErr      One of the pointers is NULL
//    ippStsSizeErr         The size is less than or equal to zero
//    ippStsStepErr         The srcStep or dstStep has a field with negative or zero value
//    ippStsNoErr           Ok
//
//  Arguments:
//    pSrc                  pointer  to the source image
//    srcStep               size of the source image scan-line
//    pDst                  pointer to the  destination image
//    dstStep               size of te destination image scan-line
//    roiSize               size of ROI
//    roundMode             rounding mode, ippRndZero or ippRndNear
*/
IPPAPI ( IppStatus, ippiConvert_8u16u_C1R,
        (const Ipp8u* pSrc, int srcStep, Ipp16u* pDst, int dstStep,
         IppiSize roiSize ))
IPPAPI ( IppStatus, ippiConvert_8u16u_C3R,
        (const Ipp8u* pSrc, int srcStep, Ipp16u* pDst, int dstStep,
         IppiSize roiSize ))
IPPAPI ( IppStatus, ippiConvert_8u16u_AC4R,
        (const Ipp8u* pSrc, int srcStep, Ipp16u* pDst, int dstStep,
         IppiSize roiSize ))
IPPAPI ( IppStatus, ippiConvert_8u16u_C4R,
        (const Ipp8u* pSrc, int srcStep, Ipp16u* pDst, int dstStep,
         IppiSize roiSize ))
IPPAPI ( IppStatus, ippiConvert_16u8u_C1R,
        ( const Ipp16u* pSrc, int srcStep, Ipp8u* pDst, int dstStep,
          IppiSize roiSize ))
IPPAPI ( IppStatus, ippiConvert_16u8u_C3R,
        ( const Ipp16u* pSrc, int srcStep, Ipp8u* pDst, int dstStep,
          IppiSize roiSize ))
IPPAPI ( IppStatus, ippiConvert_16u8u_AC4R,
        ( const Ipp16u* pSrc, int srcStep, Ipp8u* pDst, int dstStep,
          IppiSize roiSize ))
IPPAPI ( IppStatus, ippiConvert_16u8u_C4R,
        ( const Ipp16u* pSrc, int srcStep, Ipp8u* pDst, int dstStep,
          IppiSize roiSize ))
IPPAPI ( IppStatus, ippiConvert_8u16s_C1R,
        (const Ipp8u* pSrc, int srcStep, Ipp16s* pDst, int dstStep,
         IppiSize roiSize ))
IPPAPI ( IppStatus, ippiConvert_8u16s_C3R,
        (const Ipp8u* pSrc, int srcStep, Ipp16s* pDst, int dstStep,
         IppiSize roiSize ))
IPPAPI ( IppStatus, ippiConvert_8u16s_AC4R,
        (const Ipp8u* pSrc, int srcStep, Ipp16s* pDst, int dstStep,
         IppiSize roiSize ))
IPPAPI ( IppStatus, ippiConvert_8u16s_C4R,
        (const Ipp8u* pSrc, int srcStep, Ipp16s* pDst, int dstStep,
         IppiSize roiSize ))
IPPAPI ( IppStatus, ippiConvert_16s8u_C1R,
        ( const Ipp16s* pSrc, int srcStep, Ipp8u* pDst, int dstStep,
          IppiSize roiSize ))
IPPAPI ( IppStatus, ippiConvert_16s8u_C3R,
        ( const Ipp16s* pSrc, int srcStep, Ipp8u* pDst, int dstStep,
          IppiSize roiSize ))
IPPAPI ( IppStatus, ippiConvert_16s8u_AC4R,
        ( const Ipp16s* pSrc, int srcStep, Ipp8u* pDst, int dstStep,
          IppiSize roiSize ))
IPPAPI ( IppStatus, ippiConvert_16s8u_C4R,
        ( const Ipp16s* pSrc, int srcStep, Ipp8u* pDst, int dstStep,
          IppiSize roiSize ))
IPPAPI ( IppStatus, ippiConvert_8u32f_C1R,
        (const Ipp8u* pSrc, int srcStep, Ipp32f* pDst, int dstStep,
         IppiSize roiSize ))
IPPAPI ( IppStatus, ippiConvert_8u32f_C3R,
        (const Ipp8u* pSrc, int srcStep, Ipp32f* pDst, int dstStep,
         IppiSize roiSize ))
IPPAPI ( IppStatus, ippiConvert_8u32f_AC4R,
        (const Ipp8u* pSrc, int srcStep, Ipp32f* pDst, int dstStep,
         IppiSize roiSize ))
IPPAPI ( IppStatus, ippiConvert_8u32f_C4R,
        (const Ipp8u* pSrc, int srcStep, Ipp32f* pDst, int dstStep,
         IppiSize roiSize ))
IPPAPI ( IppStatus, ippiConvert_32f8u_C1R,
        ( const Ipp32f* pSrc, int srcStep, Ipp8u* pDst, int dstStep,
          IppiSize roiSize, IppRoundMode roundMode ))
IPPAPI ( IppStatus, ippiConvert_32f8u_C3R,
        ( const Ipp32f* pSrc, int srcStep, Ipp8u* pDst, int dstStep,
          IppiSize roiSize, IppRoundMode roundMode ))
IPPAPI ( IppStatus, ippiConvert_32f8u_AC4R,
        ( const Ipp32f* pSrc, int srcStep, Ipp8u* pDst, int dstStep,
          IppiSize roiSize, IppRoundMode roundMode ))
IPPAPI ( IppStatus, ippiConvert_32f8u_C4R,
        ( const Ipp32f* pSrc, int srcStep, Ipp8u* pDst, int dstStep,
          IppiSize roiSize, IppRoundMode roundMode ))
IPPAPI ( IppStatus, ippiConvert_16s32f_C1R,
        (const Ipp16s* pSrc, int srcStep, Ipp32f* pDst, int dstStep,
         IppiSize roiSize ))
IPPAPI ( IppStatus, ippiConvert_16s32f_C3R,
        (const Ipp16s* pSrc, int srcStep, Ipp32f* pDst, int dstStep,
         IppiSize roiSize ))
IPPAPI ( IppStatus, ippiConvert_16s32f_AC4R,
        (const Ipp16s* pSrc, int srcStep, Ipp32f* pDst, int dstStep,
         IppiSize roiSize ))
IPPAPI ( IppStatus, ippiConvert_16s32f_C4R,
        (const Ipp16s* pSrc, int srcStep, Ipp32f* pDst, int dstStep,
         IppiSize roiSize ))
IPPAPI ( IppStatus, ippiConvert_32f16s_C1R,
        ( const Ipp32f* pSrc, int srcStep, Ipp16s* pDst, int dstStep,
          IppiSize roiSize, IppRoundMode roundMode ))
IPPAPI ( IppStatus, ippiConvert_32f16s_C3R,
        ( const Ipp32f* pSrc, int srcStep, Ipp16s* pDst, int dstStep,
          IppiSize roiSize, IppRoundMode roundMode ))
IPPAPI ( IppStatus, ippiConvert_32f16s_AC4R,
        ( const Ipp32f* pSrc, int srcStep, Ipp16s* pDst, int dstStep,
          IppiSize roiSize, IppRoundMode roundMode ))
IPPAPI ( IppStatus, ippiConvert_32f16s_C4R,
        ( const Ipp32f* pSrc, int srcStep, Ipp16s* pDst, int dstStep,
          IppiSize roiSize, IppRoundMode roundMode ))
IPPAPI ( IppStatus, ippiConvert_8s32f_C1R,
        (const Ipp8s* pSrc, int srcStep, Ipp32f* pDst, int dstStep,
         IppiSize roiSize ))
IPPAPI ( IppStatus, ippiConvert_8s32f_C3R,
        (const Ipp8s* pSrc, int srcStep, Ipp32f* pDst, int dstStep,
         IppiSize roiSize ))
IPPAPI ( IppStatus, ippiConvert_8s32f_AC4R,
        (const Ipp8s* pSrc, int srcStep, Ipp32f* pDst, int dstStep,
         IppiSize roiSize ))
IPPAPI ( IppStatus, ippiConvert_8s32f_C4R,
        (const Ipp8s* pSrc, int srcStep, Ipp32f* pDst, int dstStep,
         IppiSize roiSize ))
IPPAPI ( IppStatus, ippiConvert_32f8s_C1R,
        ( const Ipp32f* pSrc, int srcStep, Ipp8s* pDst, int dstStep,
          IppiSize roiSize, IppRoundMode roundMode ))
IPPAPI ( IppStatus, ippiConvert_32f8s_C3R,
        ( const Ipp32f* pSrc, int srcStep, Ipp8s* pDst, int dstStep,
          IppiSize roiSize, IppRoundMode roundMode ))
IPPAPI ( IppStatus, ippiConvert_32f8s_AC4R,
        ( const Ipp32f* pSrc, int srcStep, Ipp8s* pDst, int dstStep,
          IppiSize roiSize, IppRoundMode roundMode ))
IPPAPI ( IppStatus, ippiConvert_32f8s_C4R,
        ( const Ipp32f* pSrc, int srcStep, Ipp8s* pDst, int dstStep,
          IppiSize roiSize, IppRoundMode roundMode ))
IPPAPI ( IppStatus, ippiConvert_16u32f_C1R,
        (const Ipp16u* pSrc, int srcStep, Ipp32f* pDst, int dstStep,
         IppiSize roiSize ))
IPPAPI ( IppStatus, ippiConvert_16u32f_C3R,
        (const Ipp16u* pSrc, int srcStep, Ipp32f* pDst, int dstStep,
         IppiSize roiSize ))
IPPAPI ( IppStatus, ippiConvert_16u32f_AC4R,
        (const Ipp16u* pSrc, int srcStep, Ipp32f* pDst, int dstStep,
         IppiSize roiSize ))
IPPAPI ( IppStatus, ippiConvert_16u32f_C4R,
        (const Ipp16u* pSrc, int srcStep, Ipp32f* pDst, int dstStep,
         IppiSize roiSize ))
IPPAPI ( IppStatus, ippiConvert_32f16u_C1R,
        ( const Ipp32f* pSrc, int srcStep, Ipp16u* pDst, int dstStep,
          IppiSize roiSize, IppRoundMode roundMode ))
IPPAPI ( IppStatus, ippiConvert_32f16u_C3R,
        ( const Ipp32f* pSrc, int srcStep, Ipp16u* pDst, int dstStep,
          IppiSize roiSize, IppRoundMode roundMode ))
IPPAPI ( IppStatus, ippiConvert_32f16u_AC4R,
        ( const Ipp32f* pSrc, int srcStep, Ipp16u* pDst, int dstStep,
          IppiSize roiSize, IppRoundMode roundMode ))
IPPAPI ( IppStatus, ippiConvert_32f16u_C4R,
        ( const Ipp32f* pSrc, int srcStep, Ipp16u* pDst, int dstStep,
          IppiSize roiSize, IppRoundMode roundMode ))
IPPAPI ( IppStatus, ippiConvert_8u32s_C1R,
        (const Ipp8u* pSrc, int srcStep, Ipp32s* pDst, int dstStep,
         IppiSize roiSize ))
IPPAPI ( IppStatus, ippiConvert_8u32s_C3R,
        (const Ipp8u* pSrc, int srcStep, Ipp32s* pDst, int dstStep,
         IppiSize roiSize ))
IPPAPI ( IppStatus, ippiConvert_8u32s_AC4R,
        (const Ipp8u* pSrc, int srcStep, Ipp32s* pDst, int dstStep,
         IppiSize roiSize ))
IPPAPI ( IppStatus, ippiConvert_8u32s_C4R,
        (const Ipp8u* pSrc, int srcStep, Ipp32s* pDst, int dstStep,
         IppiSize roiSize ))
IPPAPI ( IppStatus, ippiConvert_32s8u_C1R,
        ( const Ipp32s* pSrc, int srcStep, Ipp8u* pDst, int dstStep,
          IppiSize roiSize ))
IPPAPI ( IppStatus, ippiConvert_32s8u_C3R,
        ( const Ipp32s* pSrc, int srcStep, Ipp8u* pDst, int dstStep,
          IppiSize roiSize ))
IPPAPI ( IppStatus, ippiConvert_32s8u_AC4R,
        ( const Ipp32s* pSrc, int srcStep, Ipp8u* pDst, int dstStep,
          IppiSize roiSize ))
IPPAPI ( IppStatus, ippiConvert_32s8u_C4R,
        ( const Ipp32s* pSrc, int srcStep, Ipp8u* pDst, int dstStep,
          IppiSize roiSize ))
IPPAPI ( IppStatus, ippiConvert_8s32s_C1R,
        (const Ipp8s* pSrc, int srcStep, Ipp32s* pDst, int dstStep,
         IppiSize roiSize ))
IPPAPI ( IppStatus, ippiConvert_8s32s_C3R,
        (const Ipp8s* pSrc, int srcStep, Ipp32s* pDst, int dstStep,
         IppiSize roiSize ))
IPPAPI ( IppStatus, ippiConvert_8s32s_AC4R,
        (const Ipp8s* pSrc, int srcStep, Ipp32s* pDst, int dstStep,
         IppiSize roiSize ))
IPPAPI ( IppStatus, ippiConvert_8s32s_C4R,
        (const Ipp8s* pSrc, int srcStep, Ipp32s* pDst, int dstStep,
         IppiSize roiSize ))
IPPAPI ( IppStatus, ippiConvert_32s8s_C1R,
        ( const Ipp32s* pSrc, int srcStep, Ipp8s* pDst, int dstStep,
          IppiSize roiSize ))
IPPAPI ( IppStatus, ippiConvert_32s8s_C3R,
        ( const Ipp32s* pSrc, int srcStep, Ipp8s* pDst, int dstStep,
          IppiSize roiSize ))
IPPAPI ( IppStatus, ippiConvert_32s8s_AC4R,
        ( const Ipp32s* pSrc, int srcStep, Ipp8s* pDst, int dstStep,
          IppiSize roiSize ))
IPPAPI ( IppStatus, ippiConvert_32s8s_C4R,
        ( const Ipp32s* pSrc, int srcStep, Ipp8s* pDst, int dstStep,
          IppiSize roiSize ))

/* ////////////////////////////////////////////////////////////////////////////
//  Name:       ippiSwapChannels
//
//  Purpose:    Changes the order of channels of the image
//              The function does it for anyone pixel:
//                  pDst[0] = pSrc[ dstOrder[0] ]
//                  pDst[1] = pSrc[ dstOrder[1] ]
//                  pDst[2] = pSrc[ dstOrder[2] ]
//
//  Return:
//    ippStsNullPtrErr      One of the pointers is NULL
//    ippStsSizeErr         The roiSize has a field that is less than or equal to zero
//    ippStsStepErr         One of the step values is less than or equal to zero
//    ippStsChannelOrderErr dstOrder is out of the range,
//                          must be: dstOrder[3] = { 0..2, 0..2, 0..2 }
//    ippStsNoErr           Ok
//
//  Arguments:
//    pSrc                  pointer  to the source image
//    srcStep               step in bytes through the source image
//    pDst                  pointer to the  destination image
//    dstStep               step in bytes through the destination image
//    roiSize               size of ROI
//    dstOrder              the order of channels in the destination image
*/
IPPAPI ( IppStatus, ippiSwapChannels_8u_C3R,
       ( const Ipp8u* pSrc, int srcStep, Ipp8u* pDst, int dstStep,
         IppiSize roiSize, const int dstOrder[3] ))
IPPAPI ( IppStatus, ippiSwapChannels_8u_AC4R,
       ( const Ipp8u* pSrc, int srcStep, Ipp8u* pDst, int dstStep,
         IppiSize roiSize, const int dstOrder[3] ))
IPPAPI ( IppStatus, ippiSwapChannels_16u_C3R,
       ( const Ipp16u* pSrc, int srcStep, Ipp16u* pDst, int dstStep,
         IppiSize roiSize, const int dstOrder[3] ))
IPPAPI ( IppStatus, ippiSwapChannels_16u_AC4R,
       ( const Ipp16u* pSrc, int srcStep, Ipp16u* pDst, int dstStep,
         IppiSize roiSize, const int dstOrder[3] ))
IPPAPI ( IppStatus, ippiSwapChannels_32s_C3R,
       ( const Ipp32s* pSrc, int srcStep, Ipp32s* pDst, int dstStep,
         IppiSize roiSize, const int dstOrder[3] ))
IPPAPI ( IppStatus, ippiSwapChannels_32s_AC4R,
       ( const Ipp32s* pSrc, int srcStep, Ipp32s* pDst, int dstStep,
         IppiSize roiSize, const int dstOrder[3] ))
IPPAPI ( IppStatus, ippiSwapChannels_32f_C3R,
       ( const Ipp32f* pSrc, int srcStep, Ipp32f* pDst, int dstStep,
         IppiSize roiSize, const int dstOrder[3] ))
IPPAPI ( IppStatus, ippiSwapChannels_32f_AC4R,
       ( const Ipp32f* pSrc, int srcStep, Ipp32f* pDst, int dstStep,
         IppiSize roiSize, const int dstOrder[3] ))
IPPAPI ( IppStatus, ippiSwapChannels_8u_C3IR,
       ( Ipp8u* pSrcDst, int srcDstStep,
             IppiSize roiSize, const int dstOrder[3] ))


/* ////////////////////////////////////////////////////////////////////////////
//  Name:       ippiScale
//
//  Purpose:
//              dst = a + b * src;
//              a = type_min_dst - b * type_min_src;
//              b = (type_max_dst - type_min_dst) / (type_max_src - type_min_src).
//
//  Return:
//    ippStsNullPtrErr      One of pointers are NULL
//    ippStsSizeErr         The size is less or equal zero
//    ippStsStepErr         The steps in images are less or equal zero
//    ippStsScaleRangeErr   Scale bounds is out of range (vMax - vMin <= 0)
//    ippStsNoErr           Ok
//
//  Arguments:
//    pSrc                  pointer  to the source image
//    srcStep               size of input image scan-line
//    pDst                  pointer to the  destination image
//    dstStep               size of output image scan-line
//    roiSize               size of ROI
//    [vMin...vMax]         range for depth 32f.
//    hint                  utilized kind of code hint:
//                             1). hint == ippAlgHintAccurate
//                                        - accuracy e-8, but slowly;
//                             2). hint == ippAlgHintFast or ippAlgHintNone
//                                        - accuracy e-3, but quickly.
*/
IPPAPI ( IppStatus, ippiScale_8u16u_C1R,
        (const Ipp8u* pSrc, int srcStep, Ipp16u* pDst, int dstStep,
         IppiSize roiSize ))
IPPAPI ( IppStatus, ippiScale_8u16s_C1R,
        (const Ipp8u* pSrc, int srcStep, Ipp16s* pDst, int dstStep,
         IppiSize roiSize ))
IPPAPI ( IppStatus, ippiScale_8u32s_C1R,
        (const Ipp8u* pSrc, int srcStep, Ipp32s* pDst, int dstStep,
         IppiSize roiSize ))
IPPAPI ( IppStatus, ippiScale_8u32f_C1R,
        (const Ipp8u* pSrc, int srcStep, Ipp32f* pDst, int dstStep,
         IppiSize roiSize, Ipp32f vMin, Ipp32f vMax ))
IPPAPI ( IppStatus, ippiScale_8u16u_C3R,
        (const Ipp8u* pSrc, int srcStep, Ipp16u* pDst, int dstStep,
         IppiSize roiSize ))
IPPAPI ( IppStatus, ippiScale_8u16s_C3R,
        (const Ipp8u* pSrc, int srcStep, Ipp16s* pDst, int dstStep,
         IppiSize roiSize ))
IPPAPI ( IppStatus, ippiScale_8u32s_C3R,
        (const Ipp8u* pSrc, int srcStep, Ipp32s* pDst, int dstStep,
         IppiSize roiSize ))
IPPAPI ( IppStatus, ippiScale_8u32f_C3R,
        (const Ipp8u* pSrc, int srcStep, Ipp32f* pDst, int dstStep,
         IppiSize roiSize, Ipp32f vMin, Ipp32f vMax ))
IPPAPI ( IppStatus, ippiScale_8u16u_AC4R,
        (const Ipp8u* pSrc, int srcStep, Ipp16u* pDst, int dstStep,
         IppiSize roiSize ))
IPPAPI ( IppStatus, ippiScale_8u16s_AC4R,
        (const Ipp8u* pSrc, int srcStep, Ipp16s* pDst, int dstStep,
         IppiSize roiSize ))
IPPAPI ( IppStatus, ippiScale_8u32s_AC4R,
        (const Ipp8u* pSrc, int srcStep, Ipp32s* pDst, int dstStep,
         IppiSize roiSize ))
IPPAPI ( IppStatus, ippiScale_8u32f_AC4R,
        (const Ipp8u* pSrc, int srcStep, Ipp32f* pDst, int dstStep,
         IppiSize roiSize, Ipp32f vMin, Ipp32f vMax ))
IPPAPI ( IppStatus, ippiScale_8u16u_C4R,
        (const Ipp8u* pSrc, int srcStep, Ipp16u* pDst, int dstStep,
         IppiSize roiSize ))
IPPAPI ( IppStatus, ippiScale_8u16s_C4R,
        (const Ipp8u* pSrc, int srcStep, Ipp16s* pDst, int dstStep,
         IppiSize roiSize ))
IPPAPI ( IppStatus, ippiScale_8u32s_C4R,
        (const Ipp8u* pSrc, int srcStep, Ipp32s* pDst, int dstStep,
         IppiSize roiSize ))
IPPAPI ( IppStatus, ippiScale_8u32f_C4R,
        (const Ipp8u* pSrc, int srcStep, Ipp32f* pDst, int dstStep,
         IppiSize roiSize, Ipp32f vMin, Ipp32f vMax ))
IPPAPI ( IppStatus, ippiScale_16u8u_C1R,
        (const Ipp16u* pSrc, int srcStep, Ipp8u* pDst, int dstStep,
         IppiSize roiSize, IppHintAlgorithm hint ))
IPPAPI ( IppStatus, ippiScale_16s8u_C1R,
        (const Ipp16s* pSrc, int srcStep, Ipp8u* pDst, int dstStep,
         IppiSize roiSize, IppHintAlgorithm hint ))
IPPAPI ( IppStatus, ippiScale_32s8u_C1R,
        (const Ipp32s* pSrc, int srcStep, Ipp8u* pDst, int dstStep,
         IppiSize roiSize, IppHintAlgorithm hint ))
IPPAPI ( IppStatus, ippiScale_32f8u_C1R,
        (const Ipp32f* pSrc, int srcStep, Ipp8u* pDst, int dstStep,
         IppiSize roiSize, Ipp32f vMin, Ipp32f vMax ))
IPPAPI ( IppStatus, ippiScale_16u8u_C3R,
        (const Ipp16u* pSrc, int srcStep, Ipp8u* pDst, int dstStep,
         IppiSize roiSize, IppHintAlgorithm hint ))
IPPAPI ( IppStatus, ippiScale_16s8u_C3R,
        (const Ipp16s* pSrc, int srcStep, Ipp8u* pDst, int dstStep,
         IppiSize roiSize, IppHintAlgorithm hint ))
IPPAPI ( IppStatus, ippiScale_32s8u_C3R,
        (const Ipp32s* pSrc, int srcStep, Ipp8u* pDst, int dstStep,
         IppiSize roiSize, IppHintAlgorithm hint ))
IPPAPI ( IppStatus, ippiScale_32f8u_C3R,
        (const Ipp32f* pSrc, int srcStep, Ipp8u* pDst, int dstStep,
         IppiSize roiSize, Ipp32f vMin, Ipp32f vMax ))
IPPAPI ( IppStatus, ippiScale_16u8u_AC4R,
        (const Ipp16u* pSrc, int srcStep, Ipp8u* pDst, int dstStep,
         IppiSize roiSize, IppHintAlgorithm hint ))
IPPAPI ( IppStatus, ippiScale_16s8u_AC4R,
        (const Ipp16s* pSrc, int srcStep, Ipp8u* pDst, int dstStep,
         IppiSize roiSize, IppHintAlgorithm hint ))
IPPAPI ( IppStatus, ippiScale_32s8u_AC4R,
        (const Ipp32s* pSrc, int srcStep, Ipp8u* pDst, int dstStep,
         IppiSize roiSize, IppHintAlgorithm hint ))
IPPAPI ( IppStatus, ippiScale_32f8u_AC4R,
        (const Ipp32f* pSrc, int srcStep, Ipp8u* pDst, int dstStep,
         IppiSize roiSize, Ipp32f vMin, Ipp32f vMax ))
IPPAPI ( IppStatus, ippiScale_16u8u_C4R,
        (const Ipp16u* pSrc, int srcStep, Ipp8u* pDst, int dstStep,
         IppiSize roiSize, IppHintAlgorithm hint ))
IPPAPI ( IppStatus, ippiScale_16s8u_C4R,
        (const Ipp16s* pSrc, int srcStep, Ipp8u* pDst, int dstStep,
         IppiSize roiSize, IppHintAlgorithm hint ))
IPPAPI ( IppStatus, ippiScale_32s8u_C4R,
        (const Ipp32s* pSrc, int srcStep, Ipp8u* pDst, int dstStep,
         IppiSize roiSize, IppHintAlgorithm hint ))
IPPAPI ( IppStatus, ippiScale_32f8u_C4R,
        (const Ipp32f* pSrc, int srcStep, Ipp8u* pDst, int dstStep,
         IppiSize roiSize, Ipp32f vMin, Ipp32f vMax ))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiMin
//  Purpose:        computes the minimum of image pixel values
//  Context:
//  Returns:        IppStatus
//    ippStsNoErr        Ok
//    ippStsNullPtrErr   Any of the pointers is NULL
//    ippStsSizeErr      roiSize has a field with zero or negative value
//  Parameters:
//    pSrc        Pointer to the source image.
//    srcStep     Step through the source image
//    roiSize     Size of the source image ROI.
//    pMin        Pointer to the result (C1)
//    min         Array containing results (C3, AC4, C4)
//  Notes:
*/

IPPAPI(IppStatus, ippiMin_8u_C1R, (const Ipp8u* pSrc, int srcStep, IppiSize roiSize, Ipp8u* pMin))

IPPAPI(IppStatus, ippiMin_8u_C3R, (const Ipp8u* pSrc, int srcStep, IppiSize roiSize, Ipp8u min[3]))

IPPAPI(IppStatus, ippiMin_8u_AC4R, (const Ipp8u* pSrc, int srcStep, IppiSize roiSize, Ipp8u min[3]))

IPPAPI(IppStatus, ippiMin_8u_C4R, (const Ipp8u* pSrc, int srcStep, IppiSize roiSize, Ipp8u min[4]))

IPPAPI(IppStatus, ippiMin_16s_C1R, (const Ipp16s* pSrc, int srcStep, IppiSize roiSize, Ipp16s* pMin))

IPPAPI(IppStatus, ippiMin_16s_C3R, (const Ipp16s* pSrc, int srcStep, IppiSize roiSize, Ipp16s min[3]))

IPPAPI(IppStatus, ippiMin_16s_AC4R, (const Ipp16s* pSrc, int srcStep, IppiSize roiSize, Ipp16s min[3]))

IPPAPI(IppStatus, ippiMin_16s_C4R, (const Ipp16s* pSrc, int srcStep, IppiSize roiSize, Ipp16s min[4]))

IPPAPI(IppStatus, ippiMin_32f_C1R, (const Ipp32f* pSrc, int srcStep, IppiSize roiSize, Ipp32f* pMin))

IPPAPI(IppStatus, ippiMin_32f_C3R, (const Ipp32f* pSrc, int srcStep, IppiSize roiSize, Ipp32f min[3]))

IPPAPI(IppStatus, ippiMin_32f_AC4R, (const Ipp32f* pSrc, int srcStep, IppiSize roiSize, Ipp32f min[3]))

IPPAPI(IppStatus, ippiMin_32f_C4R, (const Ipp32f* pSrc, int srcStep, IppiSize roiSize, Ipp32f min[4]))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiMinIndx
//  Purpose:        computes the minimum of image pixel values and retrieves
//                  the x and y coordinates of pixels with this value
//  Context:
//  Returns:        IppStatus
//    ippStsNoErr        Ok
//    ippStsNullPtrErr   Any of the pointers is NULL
//    ippStsSizeErr      roiSize has a field with zero or negative value
//  Parameters:
//    pSrc        Pointer to the source image.
//    srcStep     Step in bytes through the source image
//    roiSize     Size of the source image ROI.
//    pMin        Pointer to the result (C1)
//    min         Array of the results (C3, AC4, C4)
//    pIndexX     Pointer to the x coordinate of the pixel with min value (C1)
//    pIndexY     Pointer to the y coordinate of the pixel with min value (C1)
//    indexX      Array containing the x coordinates of the pixel with min value (C3, AC4, C4)
//    indexY      Array containing the y coordinates of the pixel with min value (C3, AC4, C4)
//  Notes:
*/

IPPAPI(IppStatus, ippiMinIndx_8u_C1R, (const Ipp8u* pSrc, int srcStep, IppiSize roiSize, Ipp8u* pMin, int* pIndexX, int* pIndexY))

IPPAPI(IppStatus, ippiMinIndx_8u_C3R, (const Ipp8u* pSrc, int srcStep, IppiSize roiSize, Ipp8u min[3], int indexX[3], int indexY[3]))

IPPAPI(IppStatus, ippiMinIndx_8u_AC4R, (const Ipp8u* pSrc, int srcStep, IppiSize roiSize, Ipp8u min[3], int indexX[3], int indexY[3]))

IPPAPI(IppStatus, ippiMinIndx_8u_C4R, (const Ipp8u* pSrc, int srcStep, IppiSize roiSize, Ipp8u min[4], int indexX[4], int indexY[4]))

IPPAPI(IppStatus, ippiMinIndx_16s_C1R, (const Ipp16s* pSrc, int srcStep, IppiSize roiSize, Ipp16s* pMin, int* pIndexX, int* pIndexY))

IPPAPI(IppStatus, ippiMinIndx_16s_C3R, (const Ipp16s* pSrc, int srcStep, IppiSize roiSize, Ipp16s min[3], int indexX[3], int indexY[3]))

IPPAPI(IppStatus, ippiMinIndx_16s_AC4R, (const Ipp16s* pSrc, int srcStep, IppiSize roiSize, Ipp16s min[3], int indexX[3], int indexY[3]))

IPPAPI(IppStatus, ippiMinIndx_16s_C4R, (const Ipp16s* pSrc, int srcStep, IppiSize roiSize, Ipp16s min[4], int indexX[4], int indexY[4]))

IPPAPI(IppStatus, ippiMinIndx_32f_C1R, (const Ipp32f* pSrc, int srcStep, IppiSize roiSize, Ipp32f* pMin, int* pIndexX, int* pIndexY))

IPPAPI(IppStatus, ippiMinIndx_32f_C3R, (const Ipp32f* pSrc, int srcStep, IppiSize roiSize, Ipp32f min[3], int indexX[3], int indexY[3]))

IPPAPI(IppStatus, ippiMinIndx_32f_AC4R, (const Ipp32f* pSrc, int srcStep, IppiSize roiSize, Ipp32f min[3], int indexX[3], int indexY[3]))

IPPAPI(IppStatus, ippiMinIndx_32f_C4R, (const Ipp32f* pSrc, int srcStep, IppiSize roiSize, Ipp32f min[4], int indexX[4], int indexY[4]))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiMax
//  Purpose:        computes the maximum of image pixel values
//  Context:
//  Returns:        IppStatus
//    ippStsNoErr        Ok
//    ippStsNullPtrErr   Any of the pointers is NULL
//    ippStsSizeErr      roiSize has a field with zero or negative valueo
//  Parameters:
//    pSrc        Pointer to the source image.
//    srcStep     Step in bytes through the source image
//    roiSize     Size of the source image ROI.
//    pMax        Pointer to the result (C1)
//    max         Array containing the results (C3, AC4, C4)
//  Notes:
*/


IPPAPI(IppStatus, ippiMax_8u_C1R, (const Ipp8u* pSrc, int srcStep, IppiSize roiSize, Ipp8u* pMax))

IPPAPI(IppStatus, ippiMax_8u_C3R, (const Ipp8u* pSrc, int srcStep, IppiSize roiSize, Ipp8u max[3]))

IPPAPI(IppStatus, ippiMax_8u_AC4R, (const Ipp8u* pSrc, int srcStep, IppiSize roiSize, Ipp8u max[3]))

IPPAPI(IppStatus, ippiMax_8u_C4R, (const Ipp8u* pSrc, int srcStep, IppiSize roiSize, Ipp8u max[4]))

IPPAPI(IppStatus, ippiMax_16s_C1R, (const Ipp16s* pSrc, int srcStep, IppiSize roiSize, Ipp16s* pMax))

IPPAPI(IppStatus, ippiMax_16s_C3R, (const Ipp16s* pSrc, int srcStep, IppiSize roiSize, Ipp16s max[3]))

IPPAPI(IppStatus, ippiMax_16s_AC4R, (const Ipp16s* pSrc, int srcStep, IppiSize roiSize, Ipp16s max[3]))

IPPAPI(IppStatus, ippiMax_16s_C4R, (const Ipp16s* pSrc, int srcStep, IppiSize roiSize, Ipp16s max[4]))

IPPAPI(IppStatus, ippiMax_32f_C1R, (const Ipp32f* pSrc, int srcStep, IppiSize roiSize, Ipp32f* pMax))

IPPAPI(IppStatus, ippiMax_32f_C3R, (const Ipp32f* pSrc, int srcStep, IppiSize roiSize, Ipp32f max[3]))

IPPAPI(IppStatus, ippiMax_32f_AC4R, (const Ipp32f* pSrc, int srcStep, IppiSize roiSize, Ipp32f max[3]))

IPPAPI(IppStatus, ippiMax_32f_C4R, (const Ipp32f* pSrc, int srcStep, IppiSize roiSize, Ipp32f max[4]))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiMaxIndx
//  Purpose:        computes the maximum of image pixel values and retrieves
//                  the x and y coordinates of pixels with this value
//  Context:
//  Returns:        IppStatus
//    ippStsNoErr        Ok
//    ippStsNullPtrErr   Any of the pointers is NULL
//    ippStsSizeErr      roiSize has a field with zero or negative value
//  Parameters:
//    pSrc        Pointer to the source image.
//    srcStep     Step in bytes through the source image
//    roiSize     Size of the source image ROI.
//    pMax        Pointer to the result (C1)
//    max         Array of the results (C3, AC4, C4)
//    pIndexX     Pointer to the x coordinate of the pixel with max value (C1)
//    pIndexY     Pointer to the y coordinate of the pixel with max value (C1)
//    indexX      Array containing the x coordinates of the pixel with max value (C3, AC4, C4)
//    indexY      Array containing the y coordinates of the pixel with max value (C3, AC4, C4)
//  Notes:
*/


IPPAPI(IppStatus, ippiMaxIndx_8u_C1R, (const Ipp8u* pSrc, int srcStep, IppiSize roiSize, Ipp8u* pMax, int* pIndexX, int* pIndexY))

IPPAPI(IppStatus, ippiMaxIndx_8u_C3R, (const Ipp8u* pSrc, int srcStep, IppiSize roiSize, Ipp8u max[3], int indexX[3], int indexY[3]))

IPPAPI(IppStatus, ippiMaxIndx_8u_AC4R, (const Ipp8u* pSrc, int srcStep, IppiSize roiSize, Ipp8u max[3], int indexX[3], int indexY[3]))

IPPAPI(IppStatus, ippiMaxIndx_8u_C4R, (const Ipp8u* pSrc, int srcStep, IppiSize roiSize, Ipp8u max[4], int indexX[4], int indexY[4]))

IPPAPI(IppStatus, ippiMaxIndx_16s_C1R, (const Ipp16s* pSrc, int srcStep, IppiSize roiSize, Ipp16s* pMax, int* pIndexX, int* pIndexY))

IPPAPI(IppStatus, ippiMaxIndx_16s_C3R, (const Ipp16s* pSrc, int srcStep, IppiSize roiSize, Ipp16s max[3], int indexX[3], int indexY[3]))

IPPAPI(IppStatus, ippiMaxIndx_16s_AC4R, (const Ipp16s* pSrc, int srcStep, IppiSize roiSize, Ipp16s max[3], int indexX[3], int indexY[3]))

IPPAPI(IppStatus, ippiMaxIndx_16s_C4R, (const Ipp16s* pSrc, int srcStep, IppiSize roiSize, Ipp16s max[4], int indexX[4], int indexY[4]))

IPPAPI(IppStatus, ippiMaxIndx_32f_C1R, (const Ipp32f* pSrc, int srcStep, IppiSize roiSize, Ipp32f* pMax, int* pIndexX, int* pIndexY))

IPPAPI(IppStatus, ippiMaxIndx_32f_C3R, (const Ipp32f* pSrc, int srcStep, IppiSize roiSize, Ipp32f max[3], int indexX[3], int indexY[3]))

IPPAPI(IppStatus, ippiMaxIndx_32f_AC4R, (const Ipp32f* pSrc, int srcStep, IppiSize roiSize, Ipp32f max[3], int indexX[3], int indexY[3]))

IPPAPI(IppStatus, ippiMaxIndx_32f_C4R, (const Ipp32f* pSrc, int srcStep, IppiSize roiSize, Ipp32f max[4], int indexX[4], int indexY[4]))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiMinMax
//  Purpose:        computes the minimum and maximum of image pixel value
//  Context:
//  Returns:        IppStatus
//    ippStsNoErr        Ok
//    ippStsNullPtrErr   Any of the pointers is NULL
//    ippStsSizeErr      roiSize has a field with zero or negative value
//  Parameters:
//    pSrc        Pointer to the source image
//    srcStep     Step in bytes through the source image
//    roiSize     Size of the source image ROI.
//    pMin, pMax  Pointers to the results (C1)
//    min, max    Arrays containing the results (C3, AC4, C4)
//  Notes:
*/

IPPAPI(IppStatus, ippiMinMax_8u_C1R, (const Ipp8u* pSrc, int srcStep, IppiSize roiSize, Ipp8u* pMin, Ipp8u* pMax))

IPPAPI(IppStatus, ippiMinMax_8u_C3R, (const Ipp8u* pSrc, int srcStep, IppiSize roiSize, Ipp8u min[3], Ipp8u max[3]))

IPPAPI(IppStatus, ippiMinMax_8u_AC4R, (const Ipp8u* pSrc, int srcStep, IppiSize roiSize, Ipp8u min[3], Ipp8u max[3]))

IPPAPI(IppStatus, ippiMinMax_8u_C4R, (const Ipp8u* pSrc, int srcStep, IppiSize roiSize, Ipp8u min[4], Ipp8u max[4]))

IPPAPI(IppStatus, ippiMinMax_16s_C1R, (const Ipp16s* pSrc, int srcStep, IppiSize roiSize, Ipp16s* pMin, Ipp16s* pMax))

IPPAPI(IppStatus, ippiMinMax_16s_C3R, (const Ipp16s* pSrc, int srcStep, IppiSize roiSize, Ipp16s min[3], Ipp16s max[3]))

IPPAPI(IppStatus, ippiMinMax_16s_AC4R, (const Ipp16s* pSrc, int srcStep, IppiSize roiSize, Ipp16s min[3], Ipp16s max[3]))

IPPAPI(IppStatus, ippiMinMax_16s_C4R, (const Ipp16s* pSrc, int srcStep, IppiSize roiSize, Ipp16s min[4], Ipp16s max[4]))

IPPAPI(IppStatus, ippiMinMax_32f_C1R, (const Ipp32f* pSrc, int srcStep, IppiSize roiSize, Ipp32f* pMin, Ipp32f* pMax))

IPPAPI(IppStatus, ippiMinMax_32f_C3R, (const Ipp32f* pSrc, int srcStep, IppiSize roiSize, Ipp32f min[3], Ipp32f max[3]))

IPPAPI(IppStatus, ippiMinMax_32f_AC4R, (const Ipp32f* pSrc, int srcStep, IppiSize roiSize, Ipp32f min[3], Ipp32f max[3]))

IPPAPI(IppStatus, ippiMinMax_32f_C4R, (const Ipp32f* pSrc, int srcStep, IppiSize roiSize, Ipp32f min[4], Ipp32f max[4]))

/* /////////////////////////////////////////////////////////////////////////////////////////////////
//                      Logical functions and Shift functions
///////////////////////////////////////////////////////////////////////////////////////////////// */
/*
//  Names:              ippiAnd, ippiOr, ippiXor, ippiAndC, ippiOrC, ippiXorC, ippiNot,
//                      ippiLShiftC, ippiRShiftC
//
//  Purpose:            performs logical operations (AndC/OrC/XorC works with constant) and
//                      shifts operations with constant (LShiftC, RShiftC)
//  Parameters:
//   value              1) constant to be ANDed/ORed/XORed with each pixel of the image (and, or, xor);
//                      2) position`s number which pixels of the image to be SHIFTed on (shift)
//   pSrc               pointer to the source image data
//   srcStep            step through the source image
//   pSrcDst            pointer to the source/destination image data (for in-place case)
//   srcDstStep         step through the source/destination image (for in-place case)
//   pSrc1              pointer to first source image data
//   src1Step           step through first source image
//   pSrc2              pointer to second source image data
//   src2Step           step through second source image
//   pDst               pointer to the destination image data
//   dstStep            step in destination image
//   roiSize            size of the ROI
//
//  Returns:
//   ippStsNullPtrErr   any of the pointers is NULL
//   ippStsStepErr      any of the step values is less than or equal to zero
//   ippStsSizeErr      width or height of images is less than or equal to zero
//   ippStsShiftErr     shift`s value is less than zero
//   ippStsNoErr        otherwise
*/

IPPAPI(IppStatus, ippiAnd_8u_C1R, (const Ipp8u* pSrc1, int src1Step, const Ipp8u* pSrc2, int src2Step, Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAnd_8u_C3R, (const Ipp8u* pSrc1, int src1Step, const Ipp8u* pSrc2, int src2Step, Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAnd_8u_C4R, (const Ipp8u* pSrc1, int src1Step, const Ipp8u* pSrc2, int src2Step, Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAnd_8u_AC4R, (const Ipp8u* pSrc1, int src1Step, const Ipp8u* pSrc2, int src2Step, Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAnd_8u_C1IR, (const Ipp8u* pSrc, int srcStep, Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAnd_8u_C3IR, (const Ipp8u* pSrc, int srcStep, Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAnd_8u_C4IR, (const Ipp8u* pSrc, int srcStep, Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAnd_8u_AC4IR, (const Ipp8u* pSrc, int srcStep, Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAndC_8u_C1R, (const Ipp8u* pSrc, int srcStep, Ipp8u value, Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAndC_8u_C3R, (const Ipp8u* pSrc, int srcStep, const Ipp8u value[3], Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAndC_8u_C4R, (const Ipp8u* pSrc, int srcStep, const Ipp8u value[4], Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAndC_8u_AC4R, (const Ipp8u* pSrc, int srcStep, const Ipp8u value[3], Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAndC_8u_C1IR, (Ipp8u value, Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAndC_8u_C3IR, (const Ipp8u value[3], Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAndC_8u_C4IR, (const Ipp8u value[4], Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAndC_8u_AC4IR, (const Ipp8u value[3], Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAnd_16u_C1R, (const Ipp16u* pSrc1, int src1Step, const Ipp16u* pSrc2, int src2Step, Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAnd_16u_C3R, (const Ipp16u* pSrc1, int src1Step, const Ipp16u* pSrc2, int src2Step, Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAnd_16u_C4R, (const Ipp16u* pSrc1, int src1Step, const Ipp16u* pSrc2, int src2Step, Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAnd_16u_AC4R, (const Ipp16u* pSrc1, int src1Step, const Ipp16u* pSrc2, int src2Step, Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAnd_16u_C1IR, (const Ipp16u* pSrc, int srcStep, Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAnd_16u_C3IR, (const Ipp16u* pSrc, int srcStep, Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAnd_16u_C4IR, (const Ipp16u* pSrc, int srcStep, Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAnd_16u_AC4IR, (const Ipp16u* pSrc, int srcStep, Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAndC_16u_C1R, (const Ipp16u* pSrc, int srcStep, Ipp16u value, Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAndC_16u_C3R, (const Ipp16u* pSrc, int srcStep, const Ipp16u value[3], Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAndC_16u_C4R, (const Ipp16u* pSrc, int srcStep, const Ipp16u value[4], Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAndC_16u_AC4R, (const Ipp16u* pSrc, int srcStep, const Ipp16u value[3], Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAndC_16u_C1IR, (Ipp16u value, Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAndC_16u_C3IR, (const Ipp16u value[3], Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAndC_16u_C4IR, (const Ipp16u value[4], Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAndC_16u_AC4IR, (const Ipp16u value[3], Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAnd_32s_C1R, (const Ipp32s* pSrc1, int src1Step, const Ipp32s* pSrc2, int src2Step, Ipp32s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAnd_32s_C3R, (const Ipp32s* pSrc1, int src1Step, const Ipp32s* pSrc2, int src2Step, Ipp32s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAnd_32s_C4R, (const Ipp32s* pSrc1, int src1Step, const Ipp32s* pSrc2, int src2Step, Ipp32s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAnd_32s_AC4R, (const Ipp32s* pSrc1, int src1Step, const Ipp32s* pSrc2, int src2Step, Ipp32s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAnd_32s_C1IR, (const Ipp32s* pSrc, int srcStep, Ipp32s* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAnd_32s_C3IR, (const Ipp32s* pSrc, int srcStep, Ipp32s* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAnd_32s_C4IR, (const Ipp32s* pSrc, int srcStep, Ipp32s* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAnd_32s_AC4IR, (const Ipp32s* pSrc, int srcStep, Ipp32s* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAndC_32s_C1R, (const Ipp32s* pSrc, int srcStep, Ipp32s value, Ipp32s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAndC_32s_C3R, (const Ipp32s* pSrc, int srcStep, const Ipp32s value[3], Ipp32s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAndC_32s_C4R, (const Ipp32s* pSrc, int srcStep, const Ipp32s value[4], Ipp32s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAndC_32s_AC4R, (const Ipp32s* pSrc, int srcStep, const Ipp32s value[3], Ipp32s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAndC_32s_C1IR, (Ipp32s value, Ipp32s* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAndC_32s_C3IR, (const Ipp32s value[3], Ipp32s* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAndC_32s_C4IR, (const Ipp32s value[4], Ipp32s* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiAndC_32s_AC4IR, (const Ipp32s value[3], Ipp32s* pSrcDst, int srcDstStep, IppiSize roiSize))

IPPAPI(IppStatus, ippiOr_8u_C1R, (const Ipp8u* pSrc1, int src1Step, const Ipp8u* pSrc2, int src2Step, Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiOr_8u_C3R, (const Ipp8u* pSrc1, int src1Step, const Ipp8u* pSrc2, int src2Step, Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiOr_8u_C4R, (const Ipp8u* pSrc1, int src1Step, const Ipp8u* pSrc2, int src2Step, Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiOr_8u_AC4R, (const Ipp8u* pSrc1, int src1Step, const Ipp8u* pSrc2, int src2Step, Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiOr_8u_C1IR, (const Ipp8u* pSrc, int srcStep, Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiOr_8u_C3IR, (const Ipp8u* pSrc, int srcStep, Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiOr_8u_C4IR, (const Ipp8u* pSrc, int srcStep, Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiOr_8u_AC4IR, (const Ipp8u* pSrc, int srcStep, Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiOrC_8u_C1R, (const Ipp8u* pSrc, int srcStep, Ipp8u value, Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiOrC_8u_C3R, (const Ipp8u* pSrc, int srcStep, const Ipp8u value[3], Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiOrC_8u_C4R, (const Ipp8u* pSrc, int srcStep, const Ipp8u value[4], Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiOrC_8u_AC4R, (const Ipp8u* pSrc, int srcStep, const Ipp8u value[3], Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiOrC_8u_C1IR, (Ipp8u value, Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiOrC_8u_C3IR, (const Ipp8u value[3], Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiOrC_8u_C4IR, (const Ipp8u value[4], Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiOrC_8u_AC4IR, (const Ipp8u value[3], Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiOr_16u_C1R, (const Ipp16u* pSrc1, int src1Step, const Ipp16u* pSrc2, int src2Step, Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiOr_16u_C3R, (const Ipp16u* pSrc1, int src1Step, const Ipp16u* pSrc2, int src2Step, Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiOr_16u_C4R, (const Ipp16u* pSrc1, int src1Step, const Ipp16u* pSrc2, int src2Step, Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiOr_16u_AC4R, (const Ipp16u* pSrc1, int src1Step, const Ipp16u* pSrc2, int src2Step, Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiOr_16u_C1IR, (const Ipp16u* pSrc, int srcStep, Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiOr_16u_C3IR, (const Ipp16u* pSrc, int srcStep, Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiOr_16u_C4IR, (const Ipp16u* pSrc, int srcStep, Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiOr_16u_AC4IR, (const Ipp16u* pSrc, int srcStep, Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiOrC_16u_C1R, (const Ipp16u* pSrc, int srcStep, Ipp16u value, Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiOrC_16u_C3R, (const Ipp16u* pSrc, int srcStep, const Ipp16u value[3], Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiOrC_16u_C4R, (const Ipp16u* pSrc, int srcStep, const Ipp16u value[4], Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiOrC_16u_AC4R, (const Ipp16u* pSrc, int srcStep, const Ipp16u value[3], Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiOrC_16u_C1IR, (Ipp16u value, Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiOrC_16u_C3IR, (const Ipp16u value[3], Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiOrC_16u_C4IR, (const Ipp16u value[4], Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiOrC_16u_AC4IR, (const Ipp16u value[3], Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiOr_32s_C1R, (const Ipp32s* pSrc1, int src1Step, const Ipp32s* pSrc2, int src2Step, Ipp32s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiOr_32s_C3R, (const Ipp32s* pSrc1, int src1Step, const Ipp32s* pSrc2, int src2Step, Ipp32s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiOr_32s_C4R, (const Ipp32s* pSrc1, int src1Step, const Ipp32s* pSrc2, int src2Step, Ipp32s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiOr_32s_AC4R, (const Ipp32s* pSrc1, int src1Step, const Ipp32s* pSrc2, int src2Step, Ipp32s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiOr_32s_C1IR, (const Ipp32s* pSrc, int srcStep, Ipp32s* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiOr_32s_C3IR, (const Ipp32s* pSrc, int srcStep, Ipp32s* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiOr_32s_C4IR, (const Ipp32s* pSrc, int srcStep, Ipp32s* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiOr_32s_AC4IR, (const Ipp32s* pSrc, int srcStep, Ipp32s* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiOrC_32s_C1R, (const Ipp32s* pSrc, int srcStep, Ipp32s value, Ipp32s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiOrC_32s_C3R, (const Ipp32s* pSrc, int srcStep, const Ipp32s value[3], Ipp32s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiOrC_32s_C4R, (const Ipp32s* pSrc, int srcStep, const Ipp32s value[4], Ipp32s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiOrC_32s_AC4R, (const Ipp32s* pSrc, int srcStep, const Ipp32s value[3], Ipp32s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiOrC_32s_C1IR, (Ipp32s value, Ipp32s* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiOrC_32s_C3IR, (const Ipp32s value[3], Ipp32s* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiOrC_32s_C4IR, (const Ipp32s value[4], Ipp32s* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiOrC_32s_AC4IR, (const Ipp32s value[3], Ipp32s* pSrcDst, int srcDstStep, IppiSize roiSize))

IPPAPI(IppStatus, ippiXor_8u_C1R, (const Ipp8u* pSrc1, int src1Step, const Ipp8u* pSrc2, int src2Step, Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXor_8u_C3R, (const Ipp8u* pSrc1, int src1Step, const Ipp8u* pSrc2, int src2Step, Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXor_8u_C4R, (const Ipp8u* pSrc1, int src1Step, const Ipp8u* pSrc2, int src2Step, Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXor_8u_AC4R, (const Ipp8u* pSrc1, int src1Step, const Ipp8u* pSrc2, int src2Step, Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXor_8u_C1IR, (const Ipp8u* pSrc, int srcStep, Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXor_8u_C3IR, (const Ipp8u* pSrc, int srcStep, Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXor_8u_C4IR, (const Ipp8u* pSrc, int srcStep, Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXor_8u_AC4IR, (const Ipp8u* pSrc, int srcStep, Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXorC_8u_C1R, (const Ipp8u* pSrc, int srcStep, Ipp8u value, Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXorC_8u_C3R, (const Ipp8u* pSrc, int srcStep, const Ipp8u value[3], Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXorC_8u_C4R, (const Ipp8u* pSrc, int srcStep, const Ipp8u value[4], Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXorC_8u_AC4R, (const Ipp8u* pSrc, int srcStep, const Ipp8u value[3], Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXorC_8u_C1IR, (Ipp8u value, Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXorC_8u_C3IR, (const Ipp8u value[3], Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXorC_8u_C4IR, (const Ipp8u value[4], Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXorC_8u_AC4IR, (const Ipp8u value[3], Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXor_16u_C1R, (const Ipp16u* pSrc1, int src1Step, const Ipp16u* pSrc2, int src2Step, Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXor_16u_C3R, (const Ipp16u* pSrc1, int src1Step, const Ipp16u* pSrc2, int src2Step, Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXor_16u_C4R, (const Ipp16u* pSrc1, int src1Step, const Ipp16u* pSrc2, int src2Step, Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXor_16u_AC4R, (const Ipp16u* pSrc1, int src1Step, const Ipp16u* pSrc2, int src2Step, Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXor_16u_C1IR, (const Ipp16u* pSrc, int srcStep, Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXor_16u_C3IR, (const Ipp16u* pSrc, int srcStep, Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXor_16u_C4IR, (const Ipp16u* pSrc, int srcStep, Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXor_16u_AC4IR, (const Ipp16u* pSrc, int srcStep, Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXorC_16u_C1R, (const Ipp16u* pSrc, int srcStep, Ipp16u value, Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXorC_16u_C3R, (const Ipp16u* pSrc, int srcStep, const Ipp16u value[3], Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXorC_16u_C4R, (const Ipp16u* pSrc, int srcStep, const Ipp16u value[4], Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXorC_16u_AC4R, (const Ipp16u* pSrc, int srcStep, const Ipp16u value[3], Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXorC_16u_C1IR, (Ipp16u value, Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXorC_16u_C3IR, (const Ipp16u value[3], Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXorC_16u_C4IR, (const Ipp16u value[4], Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXorC_16u_AC4IR, (const Ipp16u value[3], Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXor_32s_C1R, (const Ipp32s* pSrc1, int src1Step, const Ipp32s* pSrc2, int src2Step, Ipp32s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXor_32s_C3R, (const Ipp32s* pSrc1, int src1Step, const Ipp32s* pSrc2, int src2Step, Ipp32s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXor_32s_C4R, (const Ipp32s* pSrc1, int src1Step, const Ipp32s* pSrc2, int src2Step, Ipp32s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXor_32s_AC4R, (const Ipp32s* pSrc1, int src1Step, const Ipp32s* pSrc2, int src2Step, Ipp32s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXor_32s_C1IR, (const Ipp32s* pSrc, int srcStep, Ipp32s* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXor_32s_C3IR, (const Ipp32s* pSrc, int srcStep, Ipp32s* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXor_32s_C4IR, (const Ipp32s* pSrc, int srcStep, Ipp32s* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXor_32s_AC4IR, (const Ipp32s* pSrc, int srcStep, Ipp32s* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXorC_32s_C1R, (const Ipp32s* pSrc, int srcStep, Ipp32s value, Ipp32s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXorC_32s_C3R, (const Ipp32s* pSrc, int srcStep, const Ipp32s value[3], Ipp32s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXorC_32s_C4R, (const Ipp32s* pSrc, int srcStep, const Ipp32s value[4], Ipp32s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXorC_32s_AC4R, (const Ipp32s* pSrc, int srcStep, const Ipp32s value[3], Ipp32s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXorC_32s_C1IR, (Ipp32s value, Ipp32s* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXorC_32s_C3IR, (const Ipp32s value[3], Ipp32s* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXorC_32s_C4IR, (const Ipp32s value[4], Ipp32s* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiXorC_32s_AC4IR, (const Ipp32s value[3], Ipp32s* pSrcDst, int srcDstStep, IppiSize roiSize))

IPPAPI(IppStatus, ippiNot_8u_C1R, (const Ipp8u* pSrc, int srcStep, Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiNot_8u_C3R, (const Ipp8u* pSrc, int srcStep, Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiNot_8u_C4R, (const Ipp8u* pSrc, int srcStep, Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiNot_8u_AC4R, (const Ipp8u* pSrc, int srcStep, Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiNot_8u_C1IR, (Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiNot_8u_C3IR, (Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiNot_8u_C4IR, (Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiNot_8u_AC4IR, (Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize))

IPPAPI(IppStatus, ippiLShiftC_8u_C1R, (const Ipp8u* pSrc, int srcStep, Ipp32u value, Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiLShiftC_8u_C3R, (const Ipp8u* pSrc, int srcStep, const Ipp32u value[3], Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiLShiftC_8u_C4R, (const Ipp8u* pSrc, int srcStep, const Ipp32u value[4], Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiLShiftC_8u_AC4R, (const Ipp8u* pSrc, int srcStep, const Ipp32u value[3], Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiLShiftC_8u_C1IR, (Ipp32u value, Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiLShiftC_8u_C3IR, (const Ipp32u value[3], Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiLShiftC_8u_C4IR, (const Ipp32u value[4], Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiLShiftC_8u_AC4IR, (const Ipp32u value[3], Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiLShiftC_16u_C1R, (const Ipp16u* pSrc, int srcStep, Ipp32u value, Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiLShiftC_16u_C3R, (const Ipp16u* pSrc, int srcStep, const Ipp32u value[3], Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiLShiftC_16u_C4R, (const Ipp16u* pSrc, int srcStep, const Ipp32u value[4], Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiLShiftC_16u_AC4R, (const Ipp16u* pSrc, int srcStep, const Ipp32u value[3], Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiLShiftC_16u_C1IR, (Ipp32u value, Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiLShiftC_16u_C3IR, (const Ipp32u value[3], Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiLShiftC_16u_C4IR, (const Ipp32u value[4], Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiLShiftC_16u_AC4IR, (const Ipp32u value[3], Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiLShiftC_32s_C1R, (const Ipp32s* pSrc, int srcStep, Ipp32u value, Ipp32s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiLShiftC_32s_C3R, (const Ipp32s* pSrc, int srcStep, const Ipp32u value[3], Ipp32s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiLShiftC_32s_C4R, (const Ipp32s* pSrc, int srcStep, const Ipp32u value[4], Ipp32s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiLShiftC_32s_AC4R, (const Ipp32s* pSrc, int srcStep, const Ipp32u value[3], Ipp32s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiLShiftC_32s_C1IR, (Ipp32u value, Ipp32s* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiLShiftC_32s_C3IR, (const Ipp32u value[3], Ipp32s* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiLShiftC_32s_C4IR, (const Ipp32u value[4], Ipp32s* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiLShiftC_32s_AC4IR, (const Ipp32u value[3], Ipp32s* pSrcDst, int srcDstStep, IppiSize roiSize))

IPPAPI(IppStatus, ippiRShiftC_8u_C1R, (const Ipp8u* pSrc, int srcStep, Ipp32u value, Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRShiftC_8u_C3R, (const Ipp8u* pSrc, int srcStep, const Ipp32u value[3], Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRShiftC_8u_C4R, (const Ipp8u* pSrc, int srcStep, const Ipp32u value[4], Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRShiftC_8u_AC4R, (const Ipp8u* pSrc, int srcStep, const Ipp32u value[3], Ipp8u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRShiftC_8u_C1IR, (Ipp32u value, Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRShiftC_8u_C3IR, (const Ipp32u value[3], Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRShiftC_8u_C4IR, (const Ipp32u value[4], Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRShiftC_8u_AC4IR, (const Ipp32u value[3], Ipp8u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRShiftC_8s_C1R, (const Ipp8s* pSrc, int srcStep, Ipp32u value, Ipp8s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRShiftC_8s_C3R, (const Ipp8s* pSrc, int srcStep, const Ipp32u value[3], Ipp8s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRShiftC_8s_C4R, (const Ipp8s* pSrc, int srcStep, const Ipp32u value[4], Ipp8s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRShiftC_8s_AC4R, (const Ipp8s* pSrc, int srcStep, const Ipp32u value[3], Ipp8s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRShiftC_8s_C1IR, (Ipp32u value, Ipp8s* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRShiftC_8s_C3IR, (const Ipp32u value[3], Ipp8s* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRShiftC_8s_C4IR, (const Ipp32u value[4], Ipp8s* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRShiftC_8s_AC4IR, (const Ipp32u value[3], Ipp8s* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRShiftC_16u_C1R, (const Ipp16u* pSrc, int srcStep, Ipp32u value, Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRShiftC_16u_C3R, (const Ipp16u* pSrc, int srcStep, const Ipp32u value[3], Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRShiftC_16u_C4R, (const Ipp16u* pSrc, int srcStep, const Ipp32u value[4], Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRShiftC_16u_AC4R, (const Ipp16u* pSrc, int srcStep, const Ipp32u value[3], Ipp16u* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRShiftC_16u_C1IR, (Ipp32u value, Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRShiftC_16u_C3IR, (const Ipp32u value[3], Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRShiftC_16u_C4IR, (const Ipp32u value[4], Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRShiftC_16u_AC4IR, (const Ipp32u value[3], Ipp16u* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRShiftC_16s_C1R, (const Ipp16s* pSrc, int srcStep, Ipp32u value, Ipp16s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRShiftC_16s_C3R, (const Ipp16s* pSrc, int srcStep, const Ipp32u value[3], Ipp16s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRShiftC_16s_C4R, (const Ipp16s* pSrc, int srcStep, const Ipp32u value[4], Ipp16s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRShiftC_16s_AC4R, (const Ipp16s* pSrc, int srcStep, const Ipp32u value[3], Ipp16s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRShiftC_16s_C1IR, (Ipp32u value, Ipp16s* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRShiftC_16s_C3IR, (const Ipp32u value[3], Ipp16s* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRShiftC_16s_C4IR, (const Ipp32u value[4], Ipp16s* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRShiftC_16s_AC4IR, (const Ipp32u value[3], Ipp16s* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRShiftC_32s_C1R, (const Ipp32s* pSrc, int srcStep, Ipp32u value, Ipp32s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRShiftC_32s_C3R, (const Ipp32s* pSrc, int srcStep, const Ipp32u value[3], Ipp32s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRShiftC_32s_C4R, (const Ipp32s* pSrc, int srcStep, const Ipp32u value[4], Ipp32s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRShiftC_32s_AC4R, (const Ipp32s* pSrc, int srcStep, const Ipp32u value[3], Ipp32s* pDst, int dstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRShiftC_32s_C1IR, (Ipp32u value, Ipp32s* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRShiftC_32s_C3IR, (const Ipp32u value[3], Ipp32s* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRShiftC_32s_C4IR, (const Ipp32u value[4], Ipp32s* pSrcDst, int srcDstStep, IppiSize roiSize))
IPPAPI(IppStatus, ippiRShiftC_32s_AC4IR, (const Ipp32u value[3], Ipp32s* pSrcDst, int srcDstStep, IppiSize roiSize))


/* /////////////////////////////////////////////////////////////////////////////////////////////////
//                                 Compare functions
///////////////////////////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippiCompare
//
//  Purpose:        comparing of two arrays or array and scalar for
//                  <, <=, ==, >, >= or for equality with accuracy epsilon
//  Context:
//
//  Returns:        IppStatus
//    ippStsNoErr        Ok;
//    ippStsNullPtrErr   Some of pointers to input or output data are NULL;
//    ippStsSizeErr      The width or height of images is less or equal zero or
//                       horizontal step of some arrays in bytes is less then
//                       roiSize.width;
//    ippStsEpsValErr    accuracy to compare two floats for equality is negative.
//
//  Parameters:
//    pSrc1         Pointer to first source image data;
//    src1Step      Step in first source image;
//    pSrc2         Pointer to second source image data;
//    src2Step      Step in second source image;
//    pDst          Pointer to destination image data;
//    dstStep       Step in destination image;
//    roiSize       Size of comparing region;
//    ippCmpOp         Relation, that is tested: <, <=, ==, >=, >,
//    value         scalar or scalar[3] to compare instead of second array
//    eps           accuracy to compare two floats for equality in
//                  ippiCompareEqualEps... functions
//
//  Notes:
*/

IPPAPI (IppStatus, ippiCompare_8u_C1R, ( const Ipp8u* pSrc1, int src1Step,
                                         const Ipp8u* pSrc2, int src2Step,
                                               Ipp8u* pDst,  int dstStep,
                                         IppiSize roiSize,   IppCmpOp ippCmpOp))
IPPAPI (IppStatus, ippiCompare_8u_C3R, ( const Ipp8u* pSrc1, int src1Step,
                                         const Ipp8u* pSrc2, int src2Step,
                                               Ipp8u* pDst,  int dstStep,
                                         IppiSize roiSize,   IppCmpOp ippCmpOp))
IPPAPI (IppStatus, ippiCompare_8u_AC4R, (const Ipp8u* pSrc1, int src1Step,
                                         const Ipp8u* pSrc2, int src2Step,
                                               Ipp8u* pDst,  int dstStep,
                                         IppiSize roiSize,   IppCmpOp ippCmpOp))
IPPAPI (IppStatus, ippiCompare_8u_C4R, ( const Ipp8u* pSrc1, int src1Step,
                                         const Ipp8u* pSrc2, int src2Step,
                                               Ipp8u* pDst,  int dstStep,
                                         IppiSize roiSize,   IppCmpOp ippCmpOp))

IPPAPI (IppStatus, ippiCompareC_8u_C1R,(const Ipp8u* pSrc, int srcStep, Ipp8u value,
                                              Ipp8u* pDst, int dstStep,
                                        IppiSize roiSize,  IppCmpOp ippCmpOp))
IPPAPI (IppStatus, ippiCompareC_8u_C3R,(const Ipp8u* pSrc, int srcStep, const Ipp8u value[3],
                                              Ipp8u* pDst, int dstStep,
                                        IppiSize roiSize,  IppCmpOp ippCmpOp))
IPPAPI (IppStatus, ippiCompareC_8u_AC4R,( const Ipp8u* pSrc, int srcStep, const Ipp8u value[3],
                                                Ipp8u* pDst, int dstStep,
                                          IppiSize roiSize,  IppCmpOp ippCmpOp))
IPPAPI (IppStatus, ippiCompareC_8u_C4R,(const Ipp8u* pSrc, int srcStep, const Ipp8u value[4],
                                              Ipp8u* pDst, int dstStep,
                                        IppiSize roiSize,  IppCmpOp ippCmpOp))

IPPAPI (IppStatus, ippiCompare_16s_C1R, ( const Ipp16s* pSrc1, int src1Step,
                                          const Ipp16s* pSrc2, int src2Step,
                                                Ipp8u*  pDst,  int dstStep,
                                          IppiSize roiSize,    IppCmpOp ippCmpOp))
IPPAPI (IppStatus, ippiCompare_16s_C3R, ( const Ipp16s* pSrc1, int src1Step,
                                          const Ipp16s* pSrc2, int src2Step,
                                                Ipp8u*  pDst,  int dstStep,
                                          IppiSize roiSize,    IppCmpOp ippCmpOp))
IPPAPI (IppStatus, ippiCompare_16s_AC4R, (const Ipp16s* pSrc1, int src1Step,
                                          const Ipp16s* pSrc2, int src2Step,
                                                Ipp8u*  pDst,  int dstStep,
                                          IppiSize roiSize,    IppCmpOp ippCmpOp))
IPPAPI (IppStatus, ippiCompare_16s_C4R, ( const Ipp16s* pSrc1, int src1Step,
                                          const Ipp16s* pSrc2, int src2Step,
                                                Ipp8u*  pDst,  int dstStep,
                                          IppiSize roiSize,    IppCmpOp ippCmpOp))

IPPAPI (IppStatus, ippiCompareC_16s_C1R, ( const Ipp16s* pSrc, int srcStep, Ipp16s value,
                                                Ipp8u*  pDst,  int dstStep,
                                           IppiSize roiSize,   IppCmpOp ippCmpOp))
IPPAPI (IppStatus, ippiCompareC_16s_C3R, ( const Ipp16s* pSrc, int srcStep, const Ipp16s value[3],
                                                 Ipp8u*  pDst, int dstStep,
                                           IppiSize roiSize,   IppCmpOp ippCmpOp))
IPPAPI (IppStatus, ippiCompareC_16s_AC4R, ( const Ipp16s* pSrc, int srcStep, const Ipp16s value[3],
                                                  Ipp8u*  pDst, int dstStep,
                                            IppiSize roiSize,   IppCmpOp ippCmpOp))
IPPAPI (IppStatus, ippiCompareC_16s_C4R, ( const Ipp16s* pSrc, int srcStep, const Ipp16s value[4],
                                                 Ipp8u*  pDst, int dstStep,
                                           IppiSize roiSize,   IppCmpOp ippCmpOp))

IPPAPI (IppStatus, ippiCompare_32f_C1R, ( const Ipp32f* pSrc1, int src1Step,
                                          const Ipp32f* pSrc2, int src2Step,
                                                 Ipp8u*  pDst, int dstStep,
                                          IppiSize roiSize,    IppCmpOp ippCmpOp))
IPPAPI (IppStatus, ippiCompare_32f_C3R, ( const Ipp32f* pSrc1, int src1Step,
                                          const Ipp32f* pSrc2, int src2Step,
                                                 Ipp8u*  pDst, int dstStep,
                                          IppiSize roiSize,    IppCmpOp ippCmpOp))
IPPAPI (IppStatus, ippiCompare_32f_AC4R,( const Ipp32f* pSrc1, int src1Step,
                                          const Ipp32f* pSrc2, int src2Step,
                                                 Ipp8u*  pDst, int dstStep,
                                          IppiSize roiSize,    IppCmpOp ippCmpOp))
IPPAPI (IppStatus, ippiCompare_32f_C4R, ( const Ipp32f* pSrc1, int src1Step,
                                          const Ipp32f* pSrc2, int src2Step,
                                                 Ipp8u*  pDst, int dstStep,
                                          IppiSize roiSize,    IppCmpOp ippCmpOp))

IPPAPI (IppStatus, ippiCompareC_32f_C1R, ( const Ipp32f* pSrc, int srcStep, Ipp32f value,
                                                 Ipp8u*  pDst, int dstStep,
                                           IppiSize roiSize,   IppCmpOp ippCmpOp))
IPPAPI (IppStatus, ippiCompareC_32f_C3R, ( const Ipp32f* pSrc, int srcStep, const Ipp32f value[3],
                                                 Ipp8u*  pDst, int dstStep,
                                           IppiSize roiSize,   IppCmpOp ippCmpOp))
IPPAPI (IppStatus, ippiCompareC_32f_AC4R, ( const Ipp32f* pSrc, int srcStep, const Ipp32f value[3],
                                                  Ipp8u*  pDst, int dstStep,
                                            IppiSize roiSize,   IppCmpOp ippCmpOp))
IPPAPI (IppStatus, ippiCompareC_32f_C4R, ( const Ipp32f* pSrc, int srcStep, const Ipp32f value[4],
                                                 Ipp8u*  pDst, int dstStep,
                                           IppiSize roiSize,   IppCmpOp ippCmpOp))

IPPAPI(IppStatus,ippiCompareEqualEps_32f_C1R,(const Ipp32f* pSrc1, int src1Step,
                                              const Ipp32f* pSrc2, int src2Step,
                                                    Ipp8u*  pDst,  int dstStep,
                                              IppiSize roiSize,    Ipp32f eps))
IPPAPI(IppStatus,ippiCompareEqualEps_32f_C3R,(const Ipp32f* pSrc1, int src1Step,
                                              const Ipp32f* pSrc2, int src2Step,
                                                    Ipp8u*  pDst,  int dstStep,
                                              IppiSize roiSize,    Ipp32f eps))
IPPAPI(IppStatus,ippiCompareEqualEps_32f_AC4R,(const Ipp32f* pSrc1,int src1Step,
                                               const Ipp32f* pSrc2,int src2Step,
                                                     Ipp8u*  pDst,  int dstStep,
                                               IppiSize roiSize,   Ipp32f eps))
IPPAPI(IppStatus,ippiCompareEqualEps_32f_C4R,(const Ipp32f* pSrc1, int src1Step,
                                              const Ipp32f* pSrc2, int src2Step,
                                                    Ipp8u*  pDst,  int dstStep,
                                              IppiSize roiSize,    Ipp32f eps))

IPPAPI(IppStatus,ippiCompareEqualEpsC_32f_C1R,(const Ipp32f* pSrc, int srcStep, Ipp32f value,
                                                    Ipp8u*   pDst,  int dstStep,
                                               IppiSize roiSize,   Ipp32f eps))
IPPAPI(IppStatus,ippiCompareEqualEpsC_32f_C3R,(const Ipp32f* pSrc, int srcStep,const Ipp32f value[3],
                                                     Ipp8u*  pDst, int dstStep,
                                               IppiSize roiSize,   Ipp32f eps))
IPPAPI(IppStatus,ippiCompareEqualEpsC_32f_AC4R,(const Ipp32f* pSrc, int srcStep,const Ipp32f value[3],
                                                      Ipp8u*  pDst, int dstStep,
                                                IppiSize roiSize,   Ipp32f eps))
IPPAPI(IppStatus,ippiCompareEqualEpsC_32f_C4R,(const Ipp32f* pSrc, int srcStep,const Ipp32f value[4],
                                                     Ipp8u*  pDst, int dstStep,
                                               IppiSize roiSize,   Ipp32f eps))


/* /////////////////////////////////////////////////////////////////////////////////////////////////
//                                 Morphological functions
///////////////////////////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////
//  Name:      ippiErode3x3_8u_C1R()    ippiDilate3x3_8u_C1R()
//             ippiErode3x3_8u_C3R()    ippiDilate3x3_8u_C3R()
//             ippiErode3x3_8u_AC4R()   ippiDilate3x3_8u_AC4R()
//             ippiErode3x3_8u_C4R()    ippiDilate3x3_8u_C4R()
//
//             ippiErode3x3_32f_C1R()   ippiDilate3x3_32f_C1R()
//             ippiErode3x3_32f_C3R()   ippiDilate3x3_32f_C3R()
//             ippiErode3x3_32f_AC4R()  ippiDilate3x3_32f_AC4R()
//             ippiErode3x3_32f_C4R()   ippiDilate3x3_32f_C4R()
//
//  Purpose:   Performs not inplace Morphological Operation ERODE (DILATE)
//             using 3x3 solid mask
//
//  Returns:
//    ippStsNullPtrErr,   if pSrc == NULL or
//                           pDst == NULL
//    ippStsStepErr,      if srcStep <= 0 or
//                           dstStep <= 0
//    ippStsSizeErr,      if roiSize.width  <1 or
//                           roiSize.height <1
//    ippStsStrideErr,    if (2+roiSize.width)*nChannels*sizeof(item) > srcStep or
//                           (2+roiSize.width)*nChannels*sizeof(item) > dstStep
//    ippStsNoErr,        if no errors
//
//  Parameters:
//    pSrc          pointer to the source image ROI
//    srcStep       source image scan-line size (bytes)
//    pDst          pointer to the target image ROI
//    dstStep       target image scan-line size (bytes)
//    dstRoiSize    size of ROI
*/
IPPAPI (IppStatus, ippiErode3x3_8u_C1R,   (const Ipp8u*  pSrc, int srcStep, Ipp8u*  pDst, int dstStep, IppiSize dstRoiSize))
IPPAPI (IppStatus, ippiErode3x3_8u_C3R,   (const Ipp8u*  pSrc, int srcStep, Ipp8u*  pDst, int dstStep, IppiSize dstRoiSize))
IPPAPI (IppStatus, ippiErode3x3_8u_AC4R,  (const Ipp8u*  pSrc, int srcStep, Ipp8u*  pDst, int dstStep, IppiSize dstRoiSize))
IPPAPI (IppStatus, ippiErode3x3_8u_C4R,   (const Ipp8u*  pSrc, int srcStep, Ipp8u*  pDst, int dstStep, IppiSize dstRoiSize))

IPPAPI (IppStatus, ippiDilate3x3_8u_C1R,  (const Ipp8u*  pSrc, int srcStep, Ipp8u*  pDst, int dstStep, IppiSize dstRoiSize))
IPPAPI (IppStatus, ippiDilate3x3_8u_C3R,  (const Ipp8u*  pSrc, int srcStep, Ipp8u*  pDst, int dstStep, IppiSize dstRoiSize))
IPPAPI (IppStatus, ippiDilate3x3_8u_AC4R, (const Ipp8u*  pSrc, int srcStep, Ipp8u*  pDst, int dstStep, IppiSize dstRoiSize))
IPPAPI (IppStatus, ippiDilate3x3_8u_C4R,  (const Ipp8u*  pSrc, int srcStep, Ipp8u*  pDst, int dstStep, IppiSize dstRoiSize))

IPPAPI (IppStatus, ippiErode3x3_32f_C1R,  (const Ipp32f* pSrc, int srcStep, Ipp32f* pDst, int dstStep, IppiSize dstRoiSize))
IPPAPI (IppStatus, ippiErode3x3_32f_C3R,  (const Ipp32f* pSrc, int srcStep, Ipp32f* pDst, int dstStep, IppiSize dstRoiSize))
IPPAPI (IppStatus, ippiErode3x3_32f_AC4R, (const Ipp32f* pSrc, int srcStep, Ipp32f* pDst, int dstStep, IppiSize dstRoiSize))
IPPAPI (IppStatus, ippiErode3x3_32f_C4R,  (const Ipp32f* pSrc, int srcStep, Ipp32f* pDst, int dstStep, IppiSize dstRoiSize))

IPPAPI (IppStatus, ippiDilate3x3_32f_C1R, (const Ipp32f* pSrc, int srcStep, Ipp32f* pDst, int dstStep, IppiSize dstRoiSize))
IPPAPI (IppStatus, ippiDilate3x3_32f_C3R, (const Ipp32f* pSrc, int srcStep, Ipp32f* pDst, int dstStep, IppiSize dstRoiSize))
IPPAPI (IppStatus, ippiDilate3x3_32f_AC4R,(const Ipp32f* pSrc, int srcStep, Ipp32f* pDst, int dstStep, IppiSize dstRoiSize))
IPPAPI (IppStatus, ippiDilate3x3_32f_C4R, (const Ipp32f* pSrc, int srcStep, Ipp32f* pDst, int dstStep, IppiSize dstRoiSize))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:      ippiErode3x3_8u_C1IR()    ippiDilate3x3_8u_C1IR()
//             ippiErode3x3_8u_C3IR()    ippiDilate3x3_8u_C3IR()
//             ippiErode3x3_8u_AC4IR()   ippiDilate3x3_8u_AC4IR()
//             ippiErode3x3_8u_C4IR()    ippiDilate3x3_8u_C4IR()
//
//             ippiErode3x3_32f_C1IR()   ippiDilate3x3_32f_C1IR()
//             ippiErode3x3_32f_C3IR()   ippiDilate3x3_32f_C3IR()
//             ippiErode3x3_32f_AC4IR()  ippiDilate3x3_32f_AC4IR()
//             ippiErode3x3_32f_C4IR()   ippiDilate3x3_32f_C4IR()
//
//  Purpose:   Performs inplace Morphological Operation EIRODE (DILATE)
//             using 3x3 solid mask
//
//  IReturns:
//    ippStsNullPtrErr,   if pSrcDst == NULL
//    ippStsStepErr,      if srcDstStep <= 0
//    ippStsSizeErr,      if dstRoiSize.width  <1 or
//                           dstRoiSize.height <1
//    ippStsStrideErr,    if (2+dstRoiSize.width)*nChannels*sizeof(item) > srcDstStep
//    ippStsMemAllocErr,  if can not allocate memory
//    ippStsNoErr,        if no errors
//
//  Parameters:
//    pSrcDst     pointer to the source image IROI
//    srcDstStep  source image scan-line size (bytes)
//    dstRoiSize  size of ROI
*/
IPPAPI (IppStatus, ippiErode3x3_8u_C1IR,   (Ipp8u*  pSrcDst, int srcDstStep, IppiSize dstRoiSize))
IPPAPI (IppStatus, ippiErode3x3_8u_C3IR,   (Ipp8u*  pSrcDst, int srcDstStep, IppiSize dstRoiSize))
IPPAPI (IppStatus, ippiErode3x3_8u_AC4IR,  (Ipp8u*  pSrcDst, int srcDstStep, IppiSize dstRoiSize))
IPPAPI (IppStatus, ippiErode3x3_8u_C4IR,   (Ipp8u*  pSrcDst, int srcDstStep, IppiSize dstRoiSize))

IPPAPI (IppStatus, ippiDilate3x3_8u_C1IR,  (Ipp8u*  pSrcDst, int srcDstStep, IppiSize dstRoiSize))
IPPAPI (IppStatus, ippiDilate3x3_8u_C3IR,  (Ipp8u*  pSrcDst, int srcDstStep, IppiSize dstRoiSize))
IPPAPI (IppStatus, ippiDilate3x3_8u_AC4IR, (Ipp8u*  pSrcDst, int srcDstStep, IppiSize dstRoiSize))
IPPAPI (IppStatus, ippiDilate3x3_8u_C4IR,  (Ipp8u*  pSrcDst, int srcDstStep, IppiSize dstRoiSize))

IPPAPI (IppStatus, ippiErode3x3_32f_C1IR,  (Ipp32f* pSrcDst, int srcDstStep, IppiSize dstRoiSize))
IPPAPI (IppStatus, ippiErode3x3_32f_C3IR,  (Ipp32f* pSrcDst, int srcDstStep, IppiSize dstRoiSize))
IPPAPI (IppStatus, ippiErode3x3_32f_AC4IR, (Ipp32f* pSrcDst, int srcDstStep, IppiSize dstRoiSize))
IPPAPI (IppStatus, ippiErode3x3_32f_C4IR,  (Ipp32f* pSrcDst, int srcDstStep, IppiSize dstRoiSize))

IPPAPI (IppStatus, ippiDilate3x3_32f_C1IR, (Ipp32f* pSrcDst, int srcDstStep, IppiSize dstRoiSize))
IPPAPI (IppStatus, ippiDilate3x3_32f_C3IR, (Ipp32f* pSrcDst, int srcDstStep, IppiSize dstRoiSize))
IPPAPI (IppStatus, ippiDilate3x3_32f_AC4IR,(Ipp32f* pSrcDst, int srcDstStep, IppiSize dstRoiSize))
IPPAPI (IppStatus, ippiDilate3x3_32f_C4IR, (Ipp32f* pSrcDst, int srcDstStep, IppiSize dstRoiSize))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:      ippiErode_8u_C1R()   ippiDilate_8u_C1R()
//             ippiErode_8u_C3R()   ippiDilate_8u_C3R()
//             ippiErode_8u_C4R()   ippiDilate_8u_C4R()
//             ippiErode_8u_AC4R()  ippiDilate_8u_AC4R()
//
//             ippiErode_32f_C1R()  ippiDilate_32f_C1R()
//             ippiErode_32f_C3R()  ippiDilate_32f_C3R()
//             ippiErode_32f_C4R()  ippiDilate_32f_C4R()
//             ippiErode_32f_AC4R() ippiDilate_32f_AC4R()
//
//  Purpose:   Performs not inplace Morphological Operation ERODE (DILATE)
//             using arbitrary mask
//
//  Returns:
//    ippStsNullPtrErr,   if pSrc == NULL or
//                           pDst == NULL or
//                           pMask== NULL
//    ippStsStepErr,      if srcStep <= 0 or
//                           dstStep <= 0
//    ippStsSizeErr,      if dstRoiSize.width  <1 or
//                           dstRoiSize.height <1
//    ippStsSizeErr,      if maskSize.width  <1 or
//                           maskSize.height <1
//    ippStsAnchorErr,    if (0>anchor.x)||(anchor.x>=maskSize.width) or
//                           (0>anchor.y)||(anchor.y>=maskSize.height)
//    ippStsStrideErr,    if (maskSize.width-1+dstRoiSize.width)*nChannels*sizeof(item)) > srcStep or
//                           (maskSize.width-1+dstRoiSize.width)*nChannels*sizeof(item)) > dstStep
//    ippStsMemAllocErr,  if can not allocate memory
//    ippStsZeroMaskValuesErr, if all values of the mask are zero
//    ippStsNoErr,        if no errors
//
//  Parameters:
//    pSrc          pointer to the source image ROI
//    srcStep       source image scan-line size (bytes)
//    pDst          pointer to the target image ROI
//    dstStep       target image scan-line size (bytes)
//    dstRoiSize    size of ROI
//    pMask         pointer to the mask
//    maskSize      size of mask
//    anchor        position of the anchor
*/
IPPAPI (IppStatus, ippiErode_8u_C1R,   (const Ipp8u* pSrc, int srcStep, Ipp8u* pDst, int dstStep, IppiSize dstRoiSize,
                             const Ipp8u* pMask, IppiSize maskSize, IppiPoint anchor))
IPPAPI (IppStatus, ippiErode_8u_C3R,   (const Ipp8u* pSrc, int srcStep, Ipp8u* pDst, int dstStep, IppiSize dstRoiSize,
                             const Ipp8u* pMask, IppiSize maskSize, IppiPoint anchor))
IPPAPI (IppStatus, ippiErode_8u_C4R,   (const Ipp8u* pSrc, int srcStep, Ipp8u* pDst, int dstStep, IppiSize dstRoiSize,
                             const Ipp8u* pMask, IppiSize maskSize, IppiPoint anchor))
IPPAPI (IppStatus, ippiErode_8u_AC4R,  (const Ipp8u* pSrc, int srcStep, Ipp8u* pDst, int dstStep, IppiSize dstRoiSize,
                             const Ipp8u* pMask, IppiSize maskSize, IppiPoint anchor))

IPPAPI (IppStatus, ippiDilate_8u_C1R,  (const Ipp8u* pSrc, int srcStep, Ipp8u* pDst, int dstStep, IppiSize dstRoiSize,
                             const Ipp8u* pMask, IppiSize maskSize, IppiPoint anchor))
IPPAPI (IppStatus, ippiDilate_8u_C3R,  (const Ipp8u* pSrc, int srcStep, Ipp8u* pDst, int dstStep, IppiSize dstRoiSize,
                             const Ipp8u* pMask, IppiSize maskSize, IppiPoint anchor))
IPPAPI (IppStatus, ippiDilate_8u_C4R,  (const Ipp8u* pSrc, int srcStep, Ipp8u* pDst, int dstStep, IppiSize dstRoiSize,
                             const Ipp8u* pMask, IppiSize maskSize, IppiPoint anchor))
IPPAPI (IppStatus, ippiDilate_8u_AC4R, (const Ipp8u* pSrc, int srcStep, Ipp8u* pDst, int dstStep, IppiSize dstRoiSize,
                             const Ipp8u* pMask, IppiSize maskSize, IppiPoint anchor))

IPPAPI (IppStatus, ippiErode_32f_C1R,  (const Ipp32f* pSrc, int srcStep, Ipp32f* pDst, int dstStep, IppiSize dstRoiSize,
                             const Ipp8u*  pMask, IppiSize maskSize, IppiPoint anchor))
IPPAPI (IppStatus, ippiErode_32f_C3R,  (const Ipp32f* pSrc, int srcStep, Ipp32f* pDst, int dstStep, IppiSize dstRoiSize,
                             const Ipp8u*  pMask, IppiSize maskSize, IppiPoint anchor))
IPPAPI (IppStatus, ippiErode_32f_C4R,  (const Ipp32f* pSrc, int srcStep, Ipp32f* pDst, int dstStep, IppiSize dstRoiSize,
                             const Ipp8u*  pMask, IppiSize maskSize, IppiPoint anchor))
IPPAPI (IppStatus, ippiErode_32f_AC4R, (const Ipp32f* pSrc, int srcStep, Ipp32f* pDst, int dstStep, IppiSize dstRoiSize,
                             const Ipp8u*  pMask, IppiSize maskSize, IppiPoint anchor))

IPPAPI (IppStatus, ippiDilate_32f_C1R, (const Ipp32f* pSrc, int srcStep, Ipp32f* pDst, int dstStep, IppiSize dstRoiSize,
                             const Ipp8u*  pMask, IppiSize maskSize, IppiPoint anchor))
IPPAPI (IppStatus, ippiDilate_32f_C3R, (const Ipp32f* pSrc, int srcStep, Ipp32f* pDst, int dstStep, IppiSize dstRoiSize,
                             const Ipp8u*  pMask, IppiSize maskSize, IppiPoint anchor))
IPPAPI (IppStatus, ippiDilate_32f_C4R, (const Ipp32f* pSrc, int srcStep, Ipp32f* pDst, int dstStep, IppiSize dstRoiSize,
                             const Ipp8u*  pMask, IppiSize maskSize, IppiPoint anchor))
IPPAPI (IppStatus, ippiDilate_32f_AC4R,(const Ipp32f* pSrc, int srcStep, Ipp32f* pDst, int dstStep, IppiSize dstRoiSize,
                             const Ipp8u*  pMask, IppiSize maskSize, IppiPoint anchor))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:      ippiErode_8u_C1IR()   ippiDilate_8u_C1IR()
//             ippiErode_8u_C3IR()   ippiDilate_8u_C3IR()
//             ippiErode_8u_AC4IR()  ippiDilate_8u_AC4IR()
//
//             ippiErode_32f_C1IR()  ippiDilate_32f_C1IR()
//             ippiErode_32f_C3IR()  ippiDilate_32f_C3IR()
//             ippiErode_32f_AC4IR() ippiDilate_32f_AC4IR()
//
//  Purpose:   Performs inplace Morphological Operation ERODE (DILATE)
//             using arbitrary mask
//
//  Returns:
//    ippstsNullPtrErr,   if pSrcDst == NULL or
//                           pMask== NULL
//    ippStsStepErr,      if srcDstStep <= 0
//    ippStsSizeErr,      if dstRoiSize.width  <1 or
//                           dstRoiSize.height <1
//    ippStsSizeErr,      if maskSize.width  <1 or
//                           maskSize.height <1
//    ippStsAnchorErr,    if (0>anchor.x)||(anchor.x>=maskSize.width) or
//                           (0>anchor.y)||(anchor.y>=maskSize.height)
//    ippStsStrideErr,    if (maskSize.width-1+dstRoiSize.width)*nChannels*sizeof(item)) > srcDstStep
//    ippStsMemAllocErr,  if can not allocate memory
//    ippStsZeroMaskValuesErr, if all values of the mask are zero
//    ippStsNoErr,        if no errors
//
//  Parameters:
//    pSrcDst       pointer to the source image ROI
//    srcDstStep    source image scan-line size (bytes)
//    dstRoiSize    size of ROI
//    pMask         pointer to the mask
//    maskSize      size of mask
//    anchor        position of the anchor
*/
IPPAPI (IppStatus, ippiErode_8u_C1IR,   (Ipp8u* pSrcDst, int srcDstStep, IppiSize dstRoiSize,
                              const Ipp8u* pMask, IppiSize maskSize, IppiPoint anchor))
IPPAPI (IppStatus, ippiErode_8u_C3IR,   (Ipp8u* pSrcDst, int srcDstStep, IppiSize dstRoiSize,
                              const Ipp8u* pMask, IppiSize maskSize, IppiPoint anchor))
IPPAPI (IppStatus, ippiErode_8u_AC4IR,  (Ipp8u* pSrcDst, int srcDstStep, IppiSize dstRoiSize,
                              const Ipp8u* pMask, IppiSize maskSize, IppiPoint anchor))

IPPAPI (IppStatus, ippiDilate_8u_C1IR,  (Ipp8u* pSrcDst, int srcDstStep, IppiSize dstRoiSize,
                              const Ipp8u* pMask, IppiSize maskSize, IppiPoint anchor))
IPPAPI (IppStatus, ippiDilate_8u_C3IR,  (Ipp8u* pSrcDst, int srcDstStep, IppiSize dstRoiSize,
                              const Ipp8u* pMask, IppiSize maskSize, IppiPoint anchor))
IPPAPI (IppStatus, ippiDilate_8u_AC4IR, (Ipp8u* pSrcDst, int srcDstStep, IppiSize dstRoiSize,
                              const Ipp8u* pMask, IppiSize maskSize, IppiPoint anchor))

IPPAPI (IppStatus, ippiErode_32f_C1IR,  (Ipp32f* pSrcDst, int srcDstStep, IppiSize dstRoiSize,
                              const Ipp8u*  pMask, IppiSize maskSize, IppiPoint anchor))
IPPAPI (IppStatus, ippiErode_32f_C3IR,  (Ipp32f* pSrcDst, int srcDstStep, IppiSize dstRoiSize,
                              const Ipp8u*  pMask, IppiSize maskSize, IppiPoint anchor))
IPPAPI (IppStatus, ippiErode_32f_AC4IR, (Ipp32f* pSrcDst, int srcDstStep, IppiSize dstRoiSize,
                              const Ipp8u*  pMask, IppiSize maskSize, IppiPoint anchor))

IPPAPI (IppStatus, ippiDilate_32f_C1IR, (Ipp32f* pSrcDst, int srcDstStep, IppiSize dstRoiSize,
                              const Ipp8u*  pMask, IppiSize maskSize, IppiPoint anchor))
IPPAPI (IppStatus, ippiDilate_32f_C3IR, (Ipp32f* pSrcDst, int srcDstStep, IppiSize dstRoiSize,
                              const Ipp8u*  pMask, IppiSize maskSize, IppiPoint anchor))
IPPAPI (IppStatus, ippiDilate_32f_AC4IR,(Ipp32f* pSrcDst, int srcDstStep, IppiSize dstRoiSize,
                              const Ipp8u*  pMask, IppiSize maskSize, IppiPoint anchor))



/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiZigzagInv8x8_16s_C1
//    ippiZigzagFwd8x8_16s_C1
//
//  Purpose:
//    reorder natural to zigzag 8x8 block (forward funnction) and
//    reorder zigzag to natural 8x8 block (inversion function)
//
//  Parameter:
//    pSrc - pointer to source block
//    pDst - pointer to destination block
//
//  Returns:
//    IppStatus
//
*/

IPPAPI(IppStatus, ippiZigzagInv8x8_16s_C1,(const Ipp16s* pSrc, Ipp16s* pDst))
IPPAPI(IppStatus, ippiZigzagFwd8x8_16s_C1, (const Ipp16s* pSrc, Ipp16s* pDst))



#ifdef _IPPI_PLUS

/* /////////////////////////////////////////////////////////////////////////////
//  Names:      ippiDrawText_8u_C3R
//
//  Purpose:    Draw text on the image
//  Return:
//    ippStsNoErr              Ok
//    ippStsNullPtrErr         One of pointers are NULL
//    ippStsSizeErr            The width or height of image is less or equal zero
//    ippStsStepErr            The step in image are less or equal zero
//    ippStsDrawTextErr        The system error
//  Arguments:
//    pDst                     The pointer to image
//    dstStep                  The step in image
//    roiSize                  ROI size
//    startText                Bottom left point of text rect
//    hight                    Hight of text
//    color                    Color of text
//
//  Notes:
//    For Linux system: The function assumes that X-server has been
//    installed!
//    The function asserts: pDst[0] - the top left corner of an image.
//    To draw the text the system functions (WinAPI for Windows or Xlib for Linux)
//    are used. If one of the system funcions returns an error condition,
//    ippiDrawText returns ippStsDrawTextErr status.
//    The real text size may not match the specified one.
*/

IPPAPI(IppStatus, ippiDrawText_8u_C3R,   ( Ipp8u* pDst, int dstStep, IppiSize roiSize,
                  IppiPoint startText, const char* text, int hight, Ipp8u color[3] ))

#endif /* _IPPI_PLUS */


#ifdef __cplusplus
}
#endif

#endif /* __IPPI_H__ */
/* ////////////////////////// End of file "ippi.h" ////////////////////////// */
