/* ////////////////////////////////// "ippcv.h" //////////////////////////////////////////
//
//                  INTEL CORPORATION PROPRIETARY INFORMATION
//     This software is supplied under the terms of a license agreement or
//     nondisclosure agreement with Intel Corporation and may not be copied
//     or disclosed except in accordance with the terms of that agreement.
//          Copyright(c) 2000-2003 Intel Corporation. All Rights Reserved.
//
//            	Intel(R) Integrated Performance Primitives
//                  Computer Vision (ippcv)
//
*/

#if !defined( __IPPCV_H__ ) || defined( _OWN_BLDPCS )
#define __IPPCV_H__

#ifndef __IPPCV_DEFINE_USER_LIST__

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __IPPDEFS_H__
  #include "ippdefs.h"
#endif

#if !defined( _OWN_BLDPCS )

typedef enum IppiShape
{
    ippiShapeRect = 0,
    ippiShapeCross = 1,
    ippiShapeEllipse = 2,
    ippiShapeCustom = 100
}
IppiShape;

struct ipcvMorphState;
typedef struct ipcvMorphState IppiMorphState;

struct ipcvConvState;
typedef struct ipcvConvState IppiConvState;

typedef struct IppiPoint2D32f
{
    float  x, y;
}
IppiPoint2D32f;

typedef struct IppiConnectedComp
{
    Ipp64f   area;    /*  area of the segmented component  */
    Ipp64f   value;   /*  gray scale value of the segmented component  */
    IppiRect rect;    /*  bounding rectangle of the segmented component  */
} IppiConnectedComp;

#define IPP_WHOLE   0
#define IPP_START   1
#define IPP_END     2
#define IPP_MIDDLE  4

#endif /* _OWN_BLDPCS */

#define  IPCV_ORIGIN_TL   0
#define  IPCV_ORIGIN_BL   1

#endif /* __IPPCV_DEFINE_USER_LIST__ */

/* ///////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//                   Functions declarations
//////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////// */

/* ///////////////////////////////////////////////////////////////////////////////////////
//  Name:       ippcvGetLibVersion
//  Purpose:    getting of the library version
//  Returns:    the structure of information about  version of ippcv library
//  Parameters:
//
//  Notes:      not necessary to release the returned structure
*/
IPPAPI( const IppLibraryVersion*, ippcvGetLibVersion, (void) )

/****************************************************************************************\
*                                          Accumulation                                  *
\****************************************************************************************/

/* ///////////////////////////////////////////////////////////////////////////////////////
//  Name:       ippiAdd_8u32f_C1IR,  ippiAdd_8s32f_C1IR,
//              ippiAdd_8u32f_C1IMR,  ippiAdd_8s32f_C1IMR,  ippiAdd_32f_C1IMR
//
//  Purpose:    Add image to accumulator.
//
//  Return:
//    ippStsNoErr              Ok
//    ippStsNullPtrErr         One of pointers is NULL
//    ippStsSizeErr            The width or height of images is less or equal zero
//
//  Arguments:
//    pSrc                     pointer to source image
//    srcStep                  step in the source image
//    pMask                    pointer to mask
//    maskStep                 step in the mask image
//    pSrcDst                  pointer to accumulator image
//    srcDstStep               step in the accumulator image
//    roiSize                  image size
*/
IPPAPI(IppStatus, ippiAdd_8u32f_C1IR, (const Ipp8u*  pSrc, int srcStep,
                                       Ipp32f* pSrcDst, int srcDstStep,
                                       IppiSize roiSize ))

IPPAPI(IppStatus, ippiAdd_8s32f_C1IR, (const Ipp8s*  pSrc, int srcStep,
                                       Ipp32f* pSrcDst, int srcDstStep,
                                       IppiSize roiSize ))


IPPAPI(IppStatus, ippiAdd_8u32f_C1IMR,(const Ipp8u*  pSrc, int srcStep,
                                       const Ipp8u* pMask, int maskStep,
                                       Ipp32f* pSrcDst, int srcDstStep,
                                       IppiSize roiSize ))

IPPAPI(IppStatus, ippiAdd_8s32f_C1IMR,(const Ipp8s*  pSrc, int srcStep,
                                       const Ipp8u* pMask, int maskStep,
                                       Ipp32f* pSrcDst, int srcDstStep,
                                       IppiSize roiSize ))

IPPAPI(IppStatus, ippiAdd_32f_C1IMR,  (const Ipp32f* pSrc, int srcStep,
                                       const Ipp8u* pMask, int maskStep,
                                       Ipp32f* pSrcDst, int srcDstStep,
                                       IppiSize roiSize ))

/* ///////////////////////////////////////////////////////////////////////////////////////
//  Name:   ippiAddSquare_8u32f_C1IR, ippiAddSquare_8s32f_C1IR, ippiAddSquare_32f_C1IR,
//          ippiAddSquare_8u32f_C1IMR, ippiAddSquare_8s32f_C1IMR, ippiAddSquare_32f_C1IMR
//
//  Purpose:    Add squared image (i.e. multiplied by itself) to accumulator.
//
//  Return:
//    ippStsNoErr              Ok
//    ippStsNullPtrErr         One of pointers is NULL
//    ippStsSizeErr            The width or height of images is less or equal zero
//
//  Arguments:
//    pSrc                     pointer to source image
//    srcStep                  step in the source image
//    pMask                    pointer to mask
//    maskStep                 step in the mask image
//    pSrcDst                  pointer to accumulator image
//    srcDstStep               step in the accumulator image
//    roiSize                  image size
*/
IPPAPI(IppStatus, ippiAddSquare_8u32f_C1IR, (const Ipp8u*  pSrc, int srcStep,
                                             Ipp32f* pSrcDst, int srcDstStep,
                                             IppiSize roiSize ))

IPPAPI(IppStatus, ippiAddSquare_8s32f_C1IR, (const Ipp8s*  pSrc, int srcStep,
                                             Ipp32f* pSrcDst, int srcDstStep,
                                             IppiSize roiSize ))

IPPAPI(IppStatus, ippiAddSquare_32f_C1IR,   (const Ipp32f* pSrc, int srcStep,
                                             Ipp32f* pSrcDst, int srcDstStep,
                                             IppiSize roiSize ))

IPPAPI(IppStatus, ippiAddSquare_8u32f_C1IMR,(const Ipp8u* pSrc, int srcStep,
                                             const Ipp8u* pMask, int maskStep,
                                             Ipp32f* pSrcDst, int srcDstStep,
                                             IppiSize roiSize ))

IPPAPI(IppStatus, ippiAddSquare_8s32f_C1IMR,(const Ipp8s* pSrc, int srcStep,
                                             const Ipp8u* pMask, int maskStep,
                                             Ipp32f* pSrcDst, int srcDstStep,
                                             IppiSize roiSize ))

IPPAPI(IppStatus, ippiAddSquare_32f_C1IMR,  (const Ipp32f* pSrc, int srcStep,
                                             const Ipp8u* pMask, int maskStep,
                                             Ipp32f* pSrcDst, int srcDstStep,
                                             IppiSize roiSize ))

/* ///////////////////////////////////////////////////////////////////////////////////////
//  Name: ippiAddProduct_8u32f_C1IR,  ippiAddProduct_8s32f_C1IR,  ippiAddProduct_32f_C1IR,
//        ippiAddProduct_8u32f_C1IMR, ippiAddProduct_8s32f_C1IMR, ippiAddProduct_32f_C1IMR
//
//  Purpose:  Add product of two images to accumulator.
//
//  Return:
//    ippStsNoErr              Ok
//    ippStsNullPtrErr         One of pointers is NULL
//    ippStsSizeErr            The width or height of images is less or equal zero
//
//  Arguments:
//    pSrc1                    pointer to first source image
//    src1Step                 step in the first source image
//    pSrc2                    pointer to second source image
//    src2Step                 step in the second source image
//    pMask                    pointer to mask
//    maskStep                 step in the mask image
//    pSrcDst                  pointer to accumulator image
//    srcDstStep               step in the accumulator image
//    roiSize                  image size
*/
IPPAPI(IppStatus, ippiAddProduct_8u32f_C1IR, (const Ipp8u*  pSrc1, int src1Step,
                                              const Ipp8u*  pSrc2, int src2Step,
                                              Ipp32f* pSrcDst, int srcDstStep,
                                              IppiSize roiSize ))

IPPAPI(IppStatus, ippiAddProduct_8s32f_C1IR, (const Ipp8s*  pSrc1, int src1Step,
                                              const Ipp8s*  pSrc2, int src2Step,
                                              Ipp32f* pSrcDst, int srcDstStep,
                                              IppiSize roiSize ))

IPPAPI(IppStatus, ippiAddProduct_32f_C1IR,   (const Ipp32f* pSrc1, int src1Step,
                                              const Ipp32f* pSrc2, int src2Step,
                                              Ipp32f* pSrcDst, int srcDstStep,
                                              IppiSize roiSize ))

IPPAPI(IppStatus, ippiAddProduct_8u32f_C1IMR,(const Ipp8u*  pSrc1, int src1Step,
                                              const Ipp8u*  pSrc2, int src2Step,
                                              const Ipp8u* pMask, int maskStep,
                                              Ipp32f* pSrcDst, int srcDstStep,
                                              IppiSize roiSize ))

IPPAPI(IppStatus, ippiAddProduct_8s32f_C1IMR,(const Ipp8s*  pSrc1, int src1Step,
                                              const Ipp8s*  pSrc2, int src2Step,
                                              const Ipp8u* pMask, int maskStep,
                                              Ipp32f* pSrcDst, int srcDstStep,
                                              IppiSize roiSize ))

IPPAPI(IppStatus, ippiAddProduct_32f_C1IMR,  (const Ipp32f* pSrc1, int src1Step,
                                              const Ipp32f* pSrc2, int src2Step,
                                              const Ipp8u* pMask, int maskStep,
                                              Ipp32f* pSrcDst, int srcDstStep,
                                              IppiSize roiSize ))

/* ///////////////////////////////////////////////////////////////////////////////////////
//  Name:ippiAddWeighted_8u32f_C1IR,ippiAddWeighted_8s32f_C1IR,ippiAddWeighted_32f_C1IR,
//       ippiAddWeighted_8u32f_C1IMR,ippiAddWeighted_8s32f_C1IMR,ippiAddWeighted_32f_C1IMR
//
//  Purpose:  Add image, multiplied by alpha, to accumulator, multiplied by (1 - alpha).
//
//  Return:
//    ippStsNoErr              Ok
//    ippStsNullPtrErr         One of pointers is NULL
//    ippStsSizeErr            The width or height of images is less or equal zero
//
//  Arguments:
//    pSrc1                    pointer to first source image
//    src1Step                 step in the first source image
//    pSrc2                    pointer to second source image
//    src2Step                 step in the second source image
//    pMask                    pointer to mask
//    maskStep                 step in the mask image
//    pSrcDst                  pointer to accumulator image
//    srcDstStep               step in the accumulator image
//    roiSize                  image size
//    alpha                    weight of source image
*/
IPPAPI(IppStatus, ippiAddWeighted_8u32f_C1IR, (const Ipp8u*  pSrc, int srcStep,
                                               Ipp32f* pSrcDst, int srcDstStep,
                                               IppiSize roiSize, Ipp32f alpha ))

IPPAPI(IppStatus, ippiAddWeighted_8s32f_C1IR, (const Ipp8s*  pSrc, int srcStep,
                                               Ipp32f* pSrcDst, int srcDstStep,
                                               IppiSize roiSize, Ipp32f alpha ))

IPPAPI(IppStatus, ippiAddWeighted_32f_C1IR,   (const Ipp32f* pSrc, int srcStep,
                                               Ipp32f* pSrcDst, int srcDstStep,
                                               IppiSize roiSize, Ipp32f alpha ))

IPPAPI(IppStatus, ippiAddWeighted_8u32f_C1IMR,(const Ipp8u* pSrc, int srcStep,
                                               const Ipp8u* pMask, int maskStep,
                                               Ipp32f* pSrcDst, int srcDstStep,
                                               IppiSize roiSize, Ipp32f alpha ))

IPPAPI(IppStatus, ippiAddWeighted_8s32f_C1IMR,(const Ipp8s* pSrc, int srcStep,
                                               const Ipp8u* pMask, int maskStep,
                                               Ipp32f* pSrcDst, int srcDstStep,
                                               IppiSize roiSize, Ipp32f alpha ))

IPPAPI(IppStatus, ippiAddWeighted_32f_C1IMR,  (const Ipp32f* pSrc, int srcStep,
                                               const Ipp8u* pMask, int maskStep,
                                               Ipp32f* pSrcDst, int srcDstStep,
                                               IppiSize roiSize, Ipp32f alpha ))

/****************************************************************************************\
*                                    Gaussian Pyramids                                   *
\****************************************************************************************/


/* ///////////////////////////////////////////////////////////////////////////////////////
//  Name:       ippiPyrUpGetSize_Gauss5x5, ippiPyrDownGetSize_Gauss5x5
//  Purpose:    Calculates cyclic buffer size for pyramids.
//  Return:
//    ippStsNoErr              Ok
//    ippStsDepthErr           Specified depth is invalid or unsupported
//    ippStsNumChannensErr     Specified number of channels is invalid or unsupported
//    ippStsSizeErr            The width or height of images is less or equal zero
//                             For ippiPyrDown*** if width or height are odd
//                             (non-divisible by 2).
//    ippStsStepErr            The steps in images are less or equal zero
//
//  Arguments:
//    roiWidth                 width of image ROI in pixels
//    depth                    image depth
//    channels                 number of image channels
//    bufSize                  output parameter. Size of cyclic buffer for pyramids.
*/
IPPAPI(IppStatus, ippiPyrUpGetBufSize_Gauss5x5, (int roiWidth, IppDataType dataType,
                                                 int channels, int* bufSize))

IPPAPI(IppStatus, ippiPyrDownGetBufSize_Gauss5x5, (int roiWidth, IppDataType dataType,
                                                   int channels, int* bufSize))


/* ///////////////////////////////////////////////////////////////////////////////////////
//  Name:       ippiPyrDown_Gauss5x5_8u_C1R, ippiPyrDown_Gauss5x5_8u_C3R,
//              ippiPyrDown_Gauss5x5_8s_C1R, ippiPyrDown_Gauss5x5_8s_C3R,
//              ippiPyrDown_Gauss5x5_32f_C1R, ippiPyrDown_Gauss5x5_32f_C3R,
//
//              ippiPyrUp_Gauss5x5_8u_C1R, ippiPyrUp_Gauss5x5_8u_C3R,
//              ippiPyrUp_Gauss5x5_8s_C1R, ippiPyrUp_Gauss5x5_8s_C3R,
//              ippiPyrUp_Gauss5x5_32f_C1R, ippiPyrUp_Gauss5x5_32f_C3R,
//
//  Purpose:    Perform downsampling/upsampling of the image with 5x5 gaussian.
//
//  Return:
//    ippStsNoErr              Ok
//    ippStsNullPtrErr         One of pointers is NULL
//    ippStsSizeErr            The width or height of images is less or equal zero.
//                             For ippiPyrDown*** if width or height are odd
//                             (non-divisible by 2).
//    ippStsStepErr            Step is too small to fit image.
//
//  Arguments:
//    pSrc                     pointer to source image
//    srcStep                  step in source image
//    pDst                     pointer to destination image
//    dstStep                  step in source image
//    roiSize                  source image ROI size. Destination image width and
//                             height will be twice large (PyrUp)
//                             or twice smaller (PyrDown)
//    pBuffer                  preallocated temporary cyclic buffer,
//                             which size is calculated using
//                             ippPyrUpGetSize_Gauss_5x5 or ippPyrDownGetSize_Gauss_5x5
*/
IPPAPI(IppStatus, ippiPyrUp_Gauss5x5_8u_C1R,  (const Ipp8u* pSrc, int srcStep,
                                               Ipp8u* pDst, int dstStep,
                                               IppiSize roiSize, void* pBuffer ))

IPPAPI(IppStatus, ippiPyrUp_Gauss5x5_8u_C3R,  (const Ipp8u* pSrc, int srcStep,
                                               Ipp8u* pDst, int dstStep,
                                               IppiSize roiSize, void* pBuffer ))

IPPAPI(IppStatus, ippiPyrUp_Gauss5x5_8s_C1R,  (const Ipp8s* pSrc, int srcStep,
                                               Ipp8s* pDst, int dstStep,
                                               IppiSize roiSize, void* pBuffer ))

IPPAPI(IppStatus, ippiPyrUp_Gauss5x5_8s_C3R,  (const Ipp8s* pSrc, int srcStep,
                                               Ipp8s* pDst, int dstStep,
                                               IppiSize roiSize, void* pBuffer ))

IPPAPI(IppStatus, ippiPyrUp_Gauss5x5_32f_C1R, (const Ipp32f* pSrc, int srcStep,
                                               Ipp32f* pDst, int dstStep,
                                               IppiSize roiSize, void* pBuffer ))

IPPAPI(IppStatus, ippiPyrUp_Gauss5x5_32f_C3R, (const Ipp32f* pSrc, int srcStep,
                                               Ipp32f* pDst, int dstStep,
                                               IppiSize roiSize, void* pBuffer ))

IPPAPI(IppStatus, ippiPyrDown_Gauss5x5_8u_C1R,  (const Ipp8u* pSrc, int srcStep,
                                                 Ipp8u* pDst, int dstStep,
                                                 IppiSize roiSize, void* pBuffer ))

IPPAPI(IppStatus, ippiPyrDown_Gauss5x5_8u_C3R,  (const Ipp8u* pSrc, int srcStep,
                                                 Ipp8u* pDst, int dstStep,
                                                 IppiSize roiSize, void* pBuffer ))

IPPAPI(IppStatus, ippiPyrDown_Gauss5x5_8s_C1R,  (const Ipp8s* pSrc, int srcStep,
                                                 Ipp8s* pDst, int dstStep,
                                                 IppiSize roiSize, void* pBuffer ))

IPPAPI(IppStatus, ippiPyrDown_Gauss5x5_8s_C3R,  (const Ipp8s* pSrc, int srcStep,
                                                 Ipp8s* pDst, int dstStep,
                                                 IppiSize roiSize, void* pBuffer ))

IPPAPI(IppStatus, ippiPyrDown_Gauss5x5_32f_C1R, (const Ipp32f* pSrc, int srcStep,
                                                 Ipp32f* pDst, int dstStep,
                                                 IppiSize roiSize, void* pBuffer ))

IPPAPI(IppStatus, ippiPyrDown_Gauss5x5_32f_C3R, (const Ipp32f* pSrc, int srcStep,
                                                 Ipp32f* pDst, int dstStep,
                                                 IppiSize roiSize, void* pBuffer ))


/****************************************************************************************\
*                                Morphological operations                                *
\****************************************************************************************/

/* ///////////////////////////////////////////////////////////////////////////////////////
//  Name:   ippiMorphologyInitAlloc
//
//  Purpose:  Allocate buffers and initialize internal state of morphological operation.
//  Return:
//    ippStsNoErr              Ok
//    ippStsDataTypeErr        Specified depth is invalid or unsupported
//    ippStsNumChannelsErr     Specified number of channels is invalid or unsupported
//    ippStsSizeErr            The width of image or width or height of structuring
//                             element is less or equal zero.
//    ippStsAnchorErr          Anchor point is outside the structuring element
//    ippStsOutOfRangeErr      Bad value of shape enum
//    ippStsNullPtrErr         Null pointer to element data when shape is custom
//    ippStsMemAllocErr        Memory allocation error during creating the MorphState
//
//  Arguments:
//    roiWidth                 width of image ROI in pixels
//    dataType                 image depth (data type - 8u or 32f)
//    channels                 number of image channels (1,3 or 4)
//    elSize                   size of structuring element
//    elAnchor                 anchor of the structuring element
//    elShape                  type of the element (Rect, Cross, Ellipse or Custom)
//    elData                   element pattern (mask) if elType == IPP_SHAPE_CUSTOM
//    morphState               output parameter. Double pointer to morphological state.
*/
IPPAPI(IppStatus, ippiMorphologyInitAlloc, ( int roiWidth, IppDataType dataType,
                              int channels, IppiSize elSize, IppiPoint elAnchor,
              IppiShape elShape, const int* elData, IppiMorphState** morphState ))

/* ///////////////////////////////////////////////////////////////////////////////////////
//  Name:   ippiMorphologyFree
//
//  Purpose:  Releases buffers, allocated by ippiMorphologyInitAlloc
//  Return:
//    ippStsNoErr              Ok
//    ippStsNullPtrErr         Null pointer to pointer to morphological state.
//
//  Arguments:
//    morphState               double pointer to morphological state.
*/
IPPAPI(IppStatus, ippiMorphologyFree, ( IppiMorphState** morphState ))


/* ///////////////////////////////////////////////////////////////////////////////////////
//  Name:   ippiErodeStrip_Rect_8u_C1R,         ippiErodeStrip_Rect_8u_C3R,
//          ippiErodeStrip_Rect_8u_C4R,         ippiErodeStrip_Rect_32f_C1R,
//          ippiErodeStrip_Rect_32f_C3R,        ippiErodeStrip_Rect_32f_C4R,
//          ippiErodeStrip_Cross_8u_C1R,        ippiErodeStrip_Cross_8u_C3R,
//          ippiErodeStrip_Cross_8u_C4R,        ippiErodeStrip_Cross_32f_C1R,
//          ippiErodeStrip_Cross_32f_C3R,       ippiErodeStrip_Cross_32f_C4R,
//          ippiErodeStrip_Ellipse_8u_C1R,      ippiErodeStrip_Ellipse_8u_C3R,
//          ippiErodeStrip_Ellipse_8u_C4R,      ippiErodeStrip_Ellipse_32f_C1R,
//          ippiErodeStrip_Ellipse_32f_C3R,     ippiErodeStrip_Ellipse_32f_C4R,
//          ippiErodeStrip_8u_C1R,              ippiErodeStrip_8u_C3R,
//          ippiErodeStrip_8u_C4R,              ippiErodeStrip_32f_C1R,
//          ippiErodeStrip_32f_C3R,             ippiErodeStrip_32f_C4R,
//
//          ippiDilateStrip_Rect_8u_C1R,        ippiDilateStrip_Rect_8u_C3R,
//          ippiDilateStrip_Rect_8u_C4R,        ippiDilateStrip_Rect_32f_C1R,
//          ippiDilateStrip_Rect_32f_C3R,       ippiDilateStrip_Rect_32f_C4R,
//          ippiDilateStrip_Cross_8u_C1R,       ippiDilateStrip_Cross_8u_C3R,
//          ippiDilateStrip_Cross_8u_C4R,       ippiDilateStrip_Cross_32f_C1R,
//          ippiDilateStrip_Cross_32f_C3R,      ippiDilateStrip_Cross_32f_C4R,
//          ippiDilateStrip_Ellipse_8u_C1R,     ippiDilateStrip_Ellipse_8u_C3R,
//          ippiDilateStrip_Ellipse_8u_C4R,     ippiDilateStrip_Ellipse_32f_C1R,
//          ippiDilateStrip_Ellipse_32f_C3R,    ippiDilateStrip_Ellipse_32f_C4R,
//          ippiDilateStrip_8u_C1R,             ippiDilateStrip_8u_C3R,
//          ippiDilateStrip_8u_C4R,             ippiDilateStrip_32f_C1R,
//          ippiDilateStrip_32f_C3R,            ippiDilateStrip_32f_C4R,
//
//  Purpose:    Perform erosion/dilation of image using rectangular, cross,
//              ellipse or arbitrary shape structuring element.
//  Return:
//    ippStsNoErr              Ok
//    ippStsContextMatchErr    Specified MorphState was init for another dataType,
//                             or for another number of channels, or for another
//                             shape, or ROI width during MorphState initialization
//                             was smaller then current *roiSize.width
//    ippStsOutOfRangeErr      stage is out of range (see below)
//    ippStsSizeErr            The ROI width or height is less then 1
//    ippStsStepErr            The steps in images are less then 1
//    ippStsNullPtrErr         Some of the pointers - pSrc, pDst, roiSize or state
//                             are NULL
//
//  Arguments:
//    pSrc                     The pointer to source image
//    srcStep                  The step in source image
//    pDst                     The pointer to destination image
//    dstStep                  The step in destination image
//    roiSize                  ROI size
//    state                    Pointer to morphological operation state
//    stage                    Can take one of the following values:
//                             IPP_WHOLE = 0 - function processes a whole image
//                             IPP_START  - function initializes cyclic buffer and
//                                          process top part of the large image.
//                             IPP_END    - function clears cyclic buffer and
//                                          process bottom part of the large image.
//                             IPP_MIDDLE - function processes the middle part
//                                          of the large image.
*/
IPPAPI( IppStatus, ippiErodeStrip_Rect_8u_C1R,( const Ipp8u* pSrc, int srcStep,
                                   Ipp8u* pDst, int dstStep, IppiSize* roiSize,
                                   IppiMorphState* state, int stage ))
IPPAPI( IppStatus, ippiErodeStrip_Rect_8u_C3R,( const Ipp8u* pSrc, int srcStep,
                                   Ipp8u* pDst, int dstStep, IppiSize* roiSize,
                                   IppiMorphState* state, int stage ))
IPPAPI( IppStatus, ippiErodeStrip_Rect_8u_C4R,( const Ipp8u* pSrc, int srcStep,
                                   Ipp8u* pDst, int dstStep, IppiSize* roiSize,
                                   IppiMorphState* state, int stage ))
IPPAPI( IppStatus, ippiErodeStrip_Rect_32f_C1R,( const Ipp32f* pSrc, int srcStep,
                                   Ipp32f* pDst, int dstStep, IppiSize* roiSize,
                                   IppiMorphState* state, int stage ))
IPPAPI( IppStatus, ippiErodeStrip_Rect_32f_C3R,( const Ipp32f* pSrc, int srcStep,
                                   Ipp32f* pDst, int dstStep, IppiSize* roiSize,
                                   IppiMorphState* state, int stage ))
IPPAPI( IppStatus, ippiErodeStrip_Rect_32f_C4R,( const Ipp32f* pSrc, int srcStep,
                                   Ipp32f* pDst, int dstStep, IppiSize* roiSize,
                                   IppiMorphState* state, int stage ))

IPPAPI( IppStatus, ippiErodeStrip_Cross_8u_C1R,( const Ipp8u* pSrc, int srcStep,
                                   Ipp8u* pDst, int dstStep, IppiSize* roiSize,
                                   IppiMorphState* state, int stage ))
IPPAPI( IppStatus, ippiErodeStrip_Cross_8u_C3R,( const Ipp8u* pSrc, int srcStep,
                                   Ipp8u* pDst, int dstStep, IppiSize* roiSize,
                                   IppiMorphState* state, int stage ))
IPPAPI( IppStatus, ippiErodeStrip_Cross_8u_C4R,( const Ipp8u* pSrc, int srcStep,
                                   Ipp8u* pDst, int dstStep, IppiSize* roiSize,
                                   IppiMorphState* state, int stage ))
IPPAPI( IppStatus, ippiErodeStrip_Cross_32f_C1R,( const Ipp32f* pSrc, int srcStep,
                                   Ipp32f* pDst, int dstStep, IppiSize* roiSize,
                                   IppiMorphState* state, int stage ))
IPPAPI( IppStatus, ippiErodeStrip_Cross_32f_C3R,( const Ipp32f* pSrc, int srcStep,
                                   Ipp32f* pDst, int dstStep, IppiSize* roiSize,
                                   IppiMorphState* state, int stage ))
IPPAPI( IppStatus, ippiErodeStrip_Cross_32f_C4R,( const Ipp32f* pSrc, int srcStep,
                                   Ipp32f* pDst, int dstStep, IppiSize* roiSize,
                                   IppiMorphState* state, int stage ))

IPPAPI( IppStatus, ippiErodeStrip_Ellipse_8u_C1R,( const Ipp8u* pSrc, int srcStep,
                                   Ipp8u* pDst, int dstStep, IppiSize* roiSize,
                                   IppiMorphState* state, int stage ))
IPPAPI( IppStatus, ippiErodeStrip_Ellipse_8u_C3R,( const Ipp8u* pSrc, int srcStep,
                                   Ipp8u* pDst, int dstStep, IppiSize* roiSize,
                                   IppiMorphState* state, int stage ))
IPPAPI( IppStatus, ippiErodeStrip_Ellipse_8u_C4R,( const Ipp8u* pSrc, int srcStep,
                                   Ipp8u* pDst, int dstStep, IppiSize* roiSize,
                                   IppiMorphState* state, int stage ))
IPPAPI(IppStatus, ippiErodeStrip_Ellipse_32f_C1R, ( const Ipp32f* pSrc, int srcStep,
                                   Ipp32f* pDst, int dstStep, IppiSize* roiSize,
                                   IppiMorphState* state, int stage ))
IPPAPI( IppStatus, ippiErodeStrip_Ellipse_32f_C3R,( const Ipp32f* pSrc, int srcStep,
                                   Ipp32f* pDst, int dstStep, IppiSize* roiSize,
                                   IppiMorphState* state, int stage ))
IPPAPI( IppStatus, ippiErodeStrip_Ellipse_32f_C4R,( const Ipp32f* pSrc, int srcStep,
                                   Ipp32f* pDst, int dstStep, IppiSize* roiSize,
                                   IppiMorphState* state, int stage ))

IPPAPI( IppStatus, ippiErodeStrip_8u_C1R,( const Ipp8u* pSrc, int srcStep,
                                   Ipp8u* pDst, int dstStep, IppiSize* roiSize,
                                   IppiMorphState* state, int stage ))
IPPAPI( IppStatus, ippiErodeStrip_8u_C3R,( const Ipp8u* pSrc, int srcStep,
                                   Ipp8u* pDst, int dstStep, IppiSize* roiSize,
                                   IppiMorphState* state, int stage ))
IPPAPI( IppStatus, ippiErodeStrip_8u_C4R,( const Ipp8u* pSrc, int srcStep,
                                   Ipp8u* pDst, int dstStep, IppiSize* roiSize,
                                   IppiMorphState* state, int stage ))
IPPAPI(IppStatus, ippiErodeStrip_32f_C1R, ( const Ipp32f* pSrc, int srcStep,
                                   Ipp32f* pDst, int dstStep, IppiSize* roiSize,
                                   IppiMorphState* state, int stage ))
IPPAPI( IppStatus, ippiErodeStrip_32f_C3R,( const Ipp32f* pSrc, int srcStep,
                                   Ipp32f* pDst, int dstStep, IppiSize* roiSize,
                                   IppiMorphState* state, int stage ))
IPPAPI( IppStatus, ippiErodeStrip_32f_C4R,( const Ipp32f* pSrc, int srcStep,
                                   Ipp32f* pDst, int dstStep, IppiSize* roiSize,
                                   IppiMorphState* state, int stage ))


IPPAPI( IppStatus, ippiDilateStrip_Rect_8u_C1R,( const Ipp8u* pSrc, int srcStep,
                                   Ipp8u* pDst, int dstStep, IppiSize* roiSize,
                                   IppiMorphState* state, int stage ))
IPPAPI( IppStatus, ippiDilateStrip_Rect_8u_C3R,( const Ipp8u* pSrc, int srcStep,
                                   Ipp8u* pDst, int dstStep, IppiSize* roiSize,
                                   IppiMorphState* state, int stage ))
IPPAPI( IppStatus, ippiDilateStrip_Rect_8u_C4R,( const Ipp8u* pSrc, int srcStep,
                                   Ipp8u* pDst, int dstStep, IppiSize* roiSize,
                                   IppiMorphState* state, int stage ))
IPPAPI( IppStatus, ippiDilateStrip_Rect_32f_C1R,( const Ipp32f* pSrc, int srcStep,
                                   Ipp32f* pDst, int dstStep, IppiSize* roiSize,
                                   IppiMorphState* state, int stage ))
IPPAPI( IppStatus, ippiDilateStrip_Rect_32f_C3R,( const Ipp32f* pSrc, int srcStep,
                                   Ipp32f* pDst, int dstStep, IppiSize* roiSize,
                                   IppiMorphState* state, int stage ))
IPPAPI( IppStatus, ippiDilateStrip_Rect_32f_C4R,( const Ipp32f* pSrc, int srcStep,
                                   Ipp32f* pDst, int dstStep, IppiSize* roiSize,
                                   IppiMorphState* state, int stage ))

IPPAPI( IppStatus, ippiDilateStrip_Cross_8u_C1R,( const Ipp8u* pSrc, int srcStep,
                                   Ipp8u* pDst, int dstStep, IppiSize* roiSize,
                                   IppiMorphState* state, int stage ))
IPPAPI( IppStatus, ippiDilateStrip_Cross_8u_C3R,( const Ipp8u* pSrc, int srcStep,
                                   Ipp8u* pDst, int dstStep, IppiSize* roiSize,
                                   IppiMorphState* state, int stage ))
IPPAPI( IppStatus, ippiDilateStrip_Cross_8u_C4R,( const Ipp8u* pSrc, int srcStep,
                                   Ipp8u* pDst, int dstStep, IppiSize* roiSize,
                                   IppiMorphState* state, int stage ))
IPPAPI( IppStatus, ippiDilateStrip_Cross_32f_C1R,( const Ipp32f* pSrc, int srcStep,
                                   Ipp32f* pDst, int dstStep, IppiSize* roiSize,
                                   IppiMorphState* state, int stage ))
IPPAPI( IppStatus, ippiDilateStrip_Cross_32f_C3R,( const Ipp32f* pSrc, int srcStep,
                                   Ipp32f* pDst, int dstStep, IppiSize* roiSize,
                                   IppiMorphState* state, int stage ))
IPPAPI( IppStatus, ippiDilateStrip_Cross_32f_C4R,( const Ipp32f* pSrc, int srcStep,
                                   Ipp32f* pDst, int dstStep, IppiSize* roiSize,
                                   IppiMorphState* state, int stage ))

IPPAPI( IppStatus, ippiDilateStrip_Ellipse_8u_C1R,( const Ipp8u* pSrc, int srcStep,
                                   Ipp8u* pDst, int dstStep, IppiSize* roiSize,
                                   IppiMorphState* state, int stage ))
IPPAPI( IppStatus, ippiDilateStrip_Ellipse_8u_C3R,( const Ipp8u* pSrc, int srcStep,
                                   Ipp8u* pDst, int dstStep, IppiSize* roiSize,
                                   IppiMorphState* state, int stage ))
IPPAPI( IppStatus, ippiDilateStrip_Ellipse_8u_C4R,( const Ipp8u* pSrc, int srcStep,
                                   Ipp8u* pDst, int dstStep, IppiSize* roiSize,
                                   IppiMorphState* state, int stage ))
IPPAPI(IppStatus, ippiDilateStrip_Ellipse_32f_C1R, ( const Ipp32f* pSrc, int srcStep,
                                   Ipp32f* pDst, int dstStep, IppiSize* roiSize,
                                   IppiMorphState* state, int stage ))
IPPAPI( IppStatus, ippiDilateStrip_Ellipse_32f_C3R,( const Ipp32f* pSrc, int srcStep,
                                   Ipp32f* pDst, int dstStep, IppiSize* roiSize,
                                   IppiMorphState* state, int stage ))
IPPAPI( IppStatus, ippiDilateStrip_Ellipse_32f_C4R,( const Ipp32f* pSrc, int srcStep,
                                   Ipp32f* pDst, int dstStep, IppiSize* roiSize,
                                   IppiMorphState* state, int stage ))

IPPAPI( IppStatus, ippiDilateStrip_8u_C1R,( const Ipp8u* pSrc, int srcStep,
                                   Ipp8u* pDst, int dstStep, IppiSize* roiSize,
                                   IppiMorphState* state, int stage ))
IPPAPI( IppStatus, ippiDilateStrip_8u_C3R,( const Ipp8u* pSrc, int srcStep,
                                   Ipp8u* pDst, int dstStep, IppiSize* roiSize,
                                   IppiMorphState* state, int stage ))
IPPAPI( IppStatus, ippiDilateStrip_8u_C4R,( const Ipp8u* pSrc, int srcStep,
                                   Ipp8u* pDst, int dstStep, IppiSize* roiSize,
                                   IppiMorphState* state, int stage ))
IPPAPI(IppStatus, ippiDilateStrip_32f_C1R, ( const Ipp32f* pSrc, int srcStep,
                                   Ipp32f* pDst, int dstStep, IppiSize* roiSize,
                                   IppiMorphState* state, int stage ))
IPPAPI( IppStatus, ippiDilateStrip_32f_C3R,( const Ipp32f* pSrc, int srcStep,
                                   Ipp32f* pDst, int dstStep, IppiSize* roiSize,
                                   IppiMorphState* state, int stage ))
IPPAPI( IppStatus, ippiDilateStrip_32f_C4R,( const Ipp32f* pSrc, int srcStep,
                                   Ipp32f* pDst, int dstStep, IppiSize* roiSize,
                                   IppiMorphState* state, int stage ))

/****************************************************************************************\
*                                Linear convolutions of Sobel type                       *
\****************************************************************************************/
/* ///////////////////////////////////////////////////////////////////////////////////////
//  Name:   ippiBlurInitAlloc
//
//  Purpose:  Allocate buffers and initialize internal state of convolution operation.
//  Return:
//    ippStsNoErr              Ok
//    ippStsDepthErr           Specified depth is invalid or unsupported
//    ippStsSizeErr            The width of image or width or height of structuring
//                             element is less or equal zero.
//    ippStsNullPtrErr         Null pointer to element data when shape is custom
//
//  Arguments:
//    roiWidth                 width of image ROI in pixels
//    depth                    image depth
//    kerSize                  size of kernel element
//    dx                       order of horizontal derivative
//    dy                       order of vertical derivative
//    state                    output parameter. Double pointer to convolution's state.
*/
IPPAPI(IppStatus, ippiBlurInitAlloc, ( int roiWidth, int depth,
                                       int kerSize,
                                       IppiConvState** state ))

/* ///////////////////////////////////////////////////////////////////////////////////////
//  Name:   ippiSobelInitAlloc
//
//  Purpose:  Allocate buffers and initialize internal state of convolution operation.
//  Return:
//    ippStsNoErr              Ok
//    ippStsDepthErr           Specified depth is invalid or unsupported
//    ippStsSizeErr            The width of image or width or height of structuring
//                             element is less or equal zero.
//    ippStsNullPtrErr         Null pointer to element data when shape is custom
//
//  Arguments:
//    roiWidth                 width of image ROI in pixels
//    depth                    image depth
//    kerSize                  size of structuring element
//    dx                       order of horizontal derivative
//    dy                       order of vertical derivative
//    state                    output parameter. Double pointer to convolution's state.
*/
IPPAPI(IppStatus, ippiSobelInitAlloc, ( int roiwidth,
                                        int depth,
                                        int kerSize,
                                        int origin,
                                        int  dx,
                                        int  dy,
                                        IppiConvState** state ))
/* ///////////////////////////////////////////////////////////////////////////////////////
//  Name:   ippiLaplaceInitAlloc
//
//  Purpose:  Allocate buffers and initialize internal state of convolution operation.
//  Return:
//    ippStsNoErr              Ok
//    ippStsDepthErr           Specified depth is invalid or unsupported
//    ippStsSizeErr            The width of image or width or height of structuring
//                             element is less or equal zero.
//    ippStsNullPtrErr         Null pointer to element data when shape is custom
//
//  Arguments:
//    roiWidth                 width of image ROI in pixels
//    depth                    image depth
//    kerSize                  size of structuring element
//    direct                   direction of derivative(vertical or horizontal)
//    state                    output parameter. Double pointer to convolution's state.
*/
IPPAPI(IppStatus, ippiLaplaceInitAlloc, ( int roiWidth,
                                          int depth,
                                          int kerSize,
                                          IppiConvState** state ))

/* ///////////////////////////////////////////////////////////////////////////////////////
//  Name:   ippiConvolFree
//
//  Purpose:  Releases buffers, allocated by ippiXXXInitAlloc
//  Return:
//    ippStsNoErr              Ok
//    ippStsNullPtrErr         Null pointer to pointer to convolution's state.
//
//  Arguments:
//    state               double pointer to convolution's state.
*/
IPPAPI(IppStatus, ippiConvolFree, ( IppiConvState** state ))


/* ///////////////////////////////////////////////////////////////////////////////////////
//  Name:   ippiBlur_8u16s_C1R
//          ippiBlur_8s16s_C1R
//          ippiBlur_32f_C1R
//          ippiLaplace_8u16s_C1R
//          ippiLaplace_8s16s_C1R
//          ippiLaplace_32f_C1R
//          ippiLaplace3x3_8u16s_C1R
//          ippiLaplace3x3_8s16s_C1R
//          ippiLaplace3x3_32f_C1R
//          ippiSobel_8u16s_C1R,
//          ippiSobel_8s16s_C1R,
//          ippiSobel_32f_C1R,
//          ippiScharr_Dx_8u16s_C1R,
//          ippiScharr_Dx_8s16s_C1R,
//          ippiScharr_Dx_32f_C1R,
//          ippiScharr_Dy_8u16s_C1R,
//          ippiScharr_Dy_8s16s_C1R,
//          ippiScharr_Dy_32f_C1R,
//          ippiSobel3x3_Dx_8u16s_C1R,
//          ippiSobel3x3_Dx_8s16s_C1R,
//          ippiSobel3x3_Dx_32f_C1R,
//          ippiSobel3x3_Dy_8u16s_C1R,
//          ippiSobel3x3_Dy_8s16s_C1R,
//          ippiSobel3x3_Dy_32f_C1R,
//          ippiSobel3x3_D2x_8u16s_C1R,
//          ippiSobel3x3_D2x_8s16s_C1R,
//          ippiSobel3x3_D2x_32f_C1R,
//          ippiSobel3x3_D2y_8u16s_C1R,
//          ippiSobel3x3_D2y_8s16s_C1R,
//          ippiSobel3x3_D2y_32f_C1R,
//          ippiSobel3x3_DxDy_8u16s_C1R,
//          ippiSobel3x3_DxDy_8s16s_C1R,
//          ippiSobel3x3_DxDy_32f_C1R
//
//  Purpose:    Perform convolution operation on image using various separable kernels
//  Return:
//    ippStsNoErr              Ok
//    ippStsDepthErr           Specified depth is invalid or unsupported
//    ippStsSizeErr            The width or height of images is less or equal zero
//                             For ippiPyrDown*** if width or height are odd
//                             (non-divisible by 2).
//    ippStsStepErr            The steps in images are less or equal zero
//
//  Arguments:
//    pSrc                     The pointer to source image
//    srcStep                  The step in source image
//    pDst                     The pointer to destination image
//    dstStep                  The step in destination image
//    roiSize                      ROI size
//    state                    Pointer to convolution operation state
//    stage                    Can take of the following values:
//                                0       - function processes a whole image
//                                IPP_START - function initializes cyclic buffer and
//                                            process top part of the large image.
//                                IPP_END - function clears cyclic buffer and
//                                          process bottom part of the large image.
//                                IPP_MIDDLE - function processes middle part
//                                             of the large image.
*/
IPPAPI(IppStatus, ippiBlur_8u16s_C1R, ( const Ipp8u* pSrc, int srcStep,
                                        Ipp16s* pDst, int dstStep,
                                        IppiSize* roiSize, IppiConvState* state,
                                        int stage ))

IPPAPI(IppStatus, ippiBlur_8s16s_C1R, ( const Ipp8s* pSrc, int srcStep,
                                        Ipp16s* pDst, int dstStep,
                                        IppiSize* roiSize, IppiConvState* state,
                                        int stage ))

IPPAPI(IppStatus, ippiBlur_32f_C1R, ( const Ipp32f* pSrc, int srcStep,
                                      Ipp32f* pDst, int dstStep,
                                      IppiSize* roiSize, IppiConvState* state,
                                      int stage ))

IPPAPI(IppStatus, ippiLaplace_8u16s_C1R, ( const Ipp8u* pSrc, int srcStep,
                                           Ipp16s* pDst, int dstStep,
                                           IppiSize* roiSize, IppiConvState* state,
                                           int stage ))

IPPAPI(IppStatus, ippiLaplace_8s16s_C1R, ( const Ipp8s* pSrc, int srcStep,
                                           Ipp16s* pDst, int dstStep,
                                           IppiSize* roiSize, IppiConvState* state,
                                           int stage ))

IPPAPI(IppStatus, ippiLaplace_32f_C1R, ( const Ipp32f* pSrc, int srcStep,
                                         Ipp32f* pDst, int dstStep,
                                         IppiSize* roiSize, IppiConvState* state,
                                         int stage ))


IPPAPI(IppStatus, ippiSobel_8u16s_C1R, ( const Ipp8u* pSrc, int srcStep,
                                         Ipp16s* pDst, int dstStep,
                                         IppiSize* roiSize, IppiConvState* state,
                                         int stage ))

IPPAPI(IppStatus, ippiSobel_8s16s_C1R, ( const Ipp8s* pSrc, int srcStep,
                                         Ipp16s* pDst, int dstStep,
                                         IppiSize* roiSize, IppiConvState* state,
                                         int stage ))

IPPAPI(IppStatus, ippiSobel_32f_C1R, ( const Ipp32f* pSrc, int srcStep,
                                       Ipp32f* pDst, int dstStep,
                                       IppiSize* roiSize, IppiConvState* state,
                                       int stage ))

IPPAPI(IppStatus, ippiScharr_Dx_8u16s_C1R, ( const Ipp8u* pSrc, int srcStep,
                                             Ipp16s* pDst, int dstStep,
                                             IppiSize roi,
                                             int shift))

IPPAPI(IppStatus, ippiScharr_Dx_8s16s_C1R, ( const Ipp8s* pSrc, int srcStep,
                                             Ipp16s* pDst, int dstStep,
                                             IppiSize roi,
                                             int shift))

IPPAPI(IppStatus, ippiScharr_Dx_32f_C1R, ( const Ipp32f* pSrc, int srcStep,
                                           Ipp32f* pDst, int dstStep,
                                           IppiSize roi,
                                           int shift))

IPPAPI(IppStatus, ippiScharr_Dy_8u16s_C1R, ( const Ipp8u* pSrc, int srcStep,
                                             Ipp16s* pDst, int dstStep,
                                             int origin,
                                             IppiSize roi,
                                             int shift))

IPPAPI(IppStatus, ippiScharr_Dy_8s16s_C1R, ( const Ipp8s* pSrc, int srcStep,
                                             Ipp16s* pDst, int dstStep,
                                             int origin,
                                             IppiSize roi,
                                             int shift))

IPPAPI(IppStatus, ippiScharr_Dy_32f_C1R, ( const Ipp32f* pSrc, int srcStep,
                                           Ipp32f* pDst, int dstStep,
                                           int origin,
                                           IppiSize roi,
                                           int shift))

IPPAPI(IppStatus, ippiSobel3x3_Dx_8u16s_C1R, ( const Ipp8u* pSrc, int srcStep,
                                               Ipp16s* pDst, int dstStep,
                                               IppiSize roiSize))

IPPAPI(IppStatus, ippiSobel3x3_Dx_8s16s_C1R, ( const Ipp8s* pSrc, int srcStep,
                                               Ipp16s* pDst, int dstStep,
                                               IppiSize roiSize))

IPPAPI(IppStatus, ippiSobel3x3_Dx_32f_C1R, ( const Ipp32f* pSrc, int srcStep,
                                             Ipp32f* pDst, int dstStep,
                                             IppiSize roiSize))

IPPAPI(IppStatus, ippiSobel3x3_Dy_8u16s_C1R, ( const Ipp8u* pSrc, int srcStep,
                                               Ipp16s* pDst, int dstStep,
                                               int origin, IppiSize roiSize))

IPPAPI(IppStatus, ippiSobel3x3_Dy_8s16s_C1R, ( const Ipp8s* pSrc, int srcStep,
                                               Ipp16s* pDst, int dstStep,
                                               int origin, IppiSize roiSize))

IPPAPI(IppStatus, ippiSobel3x3_Dy_32f_C1R, ( const Ipp32f* pSrc, int srcStep,
                                             Ipp32f* pDst, int dstStep,
                                             int origin, IppiSize roiSize))

IPPAPI(IppStatus, ippiSobel3x3_D2x_8u16s_C1R, ( const Ipp8u* pSrc, int srcStep,
                                                Ipp16s* pDst, int dstStep,
                                                IppiSize roiSize))

IPPAPI(IppStatus, ippiSobel3x3_D2x_8s16s_C1R, ( const Ipp8s* pSrc, int srcStep,
                                                Ipp16s* pDst, int dstStep,
                                                IppiSize roiSize))

IPPAPI(IppStatus, ippiSobel3x3_D2y_8u16s_C1R, ( const Ipp8u* pSrc, int srcStep,
                                                Ipp16s* pDst, int dstStep,
                                                IppiSize roiSize))

IPPAPI(IppStatus, ippiSobel3x3_D2y_8s16s_C1R, ( const Ipp8s* pSrc, int srcStep,
                                                Ipp16s* pDst, int dstStep,
                                                IppiSize roiSize))

IPPAPI(IppStatus, ippiSobel3x3_DxDy_8u16s_C1R, ( const Ipp8u* pSrc, int srcStep,
                                                 Ipp16s* pDst, int dstStep,
                                                 int origin, IppiSize roiSize))

IPPAPI(IppStatus, ippiSobel3x3_DxDy_8s16s_C1R, ( const Ipp8s* pSrc, int srcStep,
                                                 Ipp16s* pDst, int dstStep,
                                                 int origin, IppiSize roiSize))


/****************************************************************************************\
*                                      Motion templates                                  *
\****************************************************************************************/

/* ///////////////////////////////////////////////////////////////////////////////////////
//  Name:       ippiUpdateMotionHistory_8u32f_C1IR
//
//  Purpose:   Sets motion history image (MHI) pixels to the current time stamp
//             when the corrensonding pixels in the silhoette image are non zero.
//             Else (silhouette pixels are zero) MHI pixels are
//             cleared if their values are too small (less than timestamp - mhiDuration),
//             i.e. they were updated far ago last time. Else MHI pixels remain unchanged.
//
//  Return:
//    ippStsNoErr         Ok
//    ippStsNullPtrErr    One of pointers is NULL
//    ippStsSizeErr       The width or height of images is less or equal zero
//    ippStsStepErr       The steps in images are too small
//    ippStsRangeErr      timestamp is negative
//
//  Arguments:
//    pSilhouette        The pointer to silhouette image
//    silhStep           The step in silhouette image
//    pMHI               The pointer to motion history image
//    mhiStep            The step in mhi image
//    roiSize                ROI size
//    timestamp          Current time stamp (milliseconds)
//    mhiDuration        Maximal duration of motion track (milliseconds)
*/
IPPAPI(IppStatus, ippiUpdateMotionHistory_8u32f_C1IR,
                        ( const Ipp8u* pSilhouette, int silhStep,
                          Ipp32f* pMHI, int mhiStep, IppiSize roiSize,
                          Ipp32f timestamp, Ipp32f mhiDuration ))

/****************************************************************************************\
*                                      Flood fill                                        *
\****************************************************************************************/

/*F///////////////////////////////////////////////////////////////////////////////////////
//  Name:    ippiFloodFillGetSize_4Con, ippiFloodFillGetSize_8Con
//           ippiFloodFillGetSize_Grad4Con, ippiFloodFillGetSize_Grad8Con
//
//  Purpose: The functions calculate size of temporary buffer, required to run
//           one of the corresponding flood fill functions.
//  Return:
//    ippStsNoErr         Ok
//    ippStsNullPtrErr    One of pointers is NULL
//    ippStsSizeErr       The width or height of images is less or equal zero
//
//  Parameters:
//    pImage             filled image
//    imageStep          its step
//    roiSize                ROI size
//    seed               seed point
//    newVal             pixel value to fill with
//    pBuffer            temporary buffer
//F*/
IPPAPI( IppStatus, ippiFloodFillGetSize, ( IppiSize roiSize, int* bufferSize ))
IPPAPI( IppStatus, ippiFloodFillGetSize_Grad, ( IppiSize roiSize, int* bufferSize ))

/*F///////////////////////////////////////////////////////////////////////////////////////
//    Names:   ippiFloodFill_4Con_8u_C1IR,     ippiFloodFill_4Con_32f_C1IR,
//             ippiFloodFill_8Con_8u_C1IR,     ippiFloodFill_8Con_32f_C1IR,
//             ippiFloodFill_Grad4Con_8u_C1IR, ippiFloodFill_Grad4Con_32f_C1IR,
//             ippiFloodFill_Grad8Con_8u_C1IR, ippiFloodFill_Grad8Con_32f_C1IR
//    Purpose: The functions fill the seed pixel enewValirons inside which all pixel
//             values are equal (first 4 funcs) or not far from each other (the others).
//    Context:
//    Parameters:  pImage     - pointer to ROI of initial image (in the beginning)
//                              which is "repainted" during the function action,
//                 step       - full string length of initial image (in bytes),
//                 roi        - size of image ROI,
//                 seed       - coordinates of the seed point inside image ROI,
//                 newVal     - new value of repainted area pixels,
//                 region     - pointer to repainted region properties structure,
//                 d_lw, d_up - maximal lower and upper differences of the values of
//                              appurtenant to repainted area pixel and one of its
//                              neighbour,
//                 pBuffer    - buffer needed for calculations (its size must be
//                              calculated by ippiFloodFillGetSize_Grad function).
//
//    Returns: ippStsOk or error code
//    Notes:   This function uses a rapid non-recursive algorithm.
//F*/
IPPAPI( IppStatus, ippiFloodFill_4Con_8u_C1IR, ( Ipp8u*  pImage, int imageStep,
                                                 IppiSize roiSize,    IppiPoint seed,
                                                 int     newVal, IppiConnectedComp* region,
                                                 void* pBuffer ))

IPPAPI( IppStatus, ippiFloodFill_8Con_8u_C1IR, ( Ipp8u*  pImage, int imageStep,
                                                 IppiSize roiSize,    IppiPoint seed,
                                                 int     newVal, IppiConnectedComp* region,
                                                 void* pBuffer ))

IPPAPI( IppStatus, ippiFloodFill_4Con_32f_C1IR, ( Ipp32f* pImage, int imageStep,
                                                  IppiSize roiSize,    IppiPoint seed,
                                                  Ipp32f  newVal,IppiConnectedComp* region,
                                                  void* pBuffer ))

IPPAPI( IppStatus, ippiFloodFill_8Con_32f_C1IR, ( Ipp32f* pImage, int imageStep,
                                                  IppiSize roiSize,    IppiPoint seed,
                                                  Ipp32f  newVal,IppiConnectedComp* region,
                                                  void* pBuffer ))

IPPAPI( IppStatus, ippiFloodFill_Grad4Con_8u_C1IR, ( Ipp8u*  pImage, int imageStep,
                                                     IppiSize roiSize,    IppiPoint seed,
                                                     int     newVal, int d_lw, int d_up,
                                                      IppiConnectedComp* region,
                                                     void* pBuffer ))

IPPAPI( IppStatus, ippiFloodFill_Grad8Con_8u_C1IR, ( Ipp8u*  pImage, int imageStep,
                                                     IppiSize roiSize,    IppiPoint seed,
                                                     int     newVal,int d_lw, int d_up,
                                                     IppiConnectedComp* region,
                                                     void* pBuffer ))

IPPAPI( IppStatus, ippiFloodFill_Grad4Con_32f_C1IR, ( Ipp32f* pImage, int imageStep,
                                                      IppiSize roiSize,    IppiPoint seed,
                                                      Ipp32f  newVal,Ipp32f d_lw, Ipp32f d_up,
                                                      IppiConnectedComp* region,
                                                      void* pBuffer ))

IPPAPI( IppStatus, ippiFloodFill_Grad8Con_32f_C1IR, ( Ipp32f* pImage, int imageStep,
                                                      IppiSize roiSize,    IppiPoint seed,
                                                      Ipp32f  newVal, Ipp32f d_lw, Ipp32f d_up,
                                                      IppiConnectedComp* region,
                                                      void* pBuffer ))

/*****************************************************************************\
*                                 Template matching                           *
\*****************************************************************************/

/* ////////////////////////////////////////////////////////////////////////////
//  Names:   ippiMatchTemplateGetSize_SqDiff,
//           ippiMatchTemplateGetSize_Corr,
//           ippiMatchTemplateGetSize_Coeff,
//           ippiMatchTemplateGetSize_SqDiffNormed,
//           ippiMatchTemplateGetSize_CorrNormed,
//           ippiMatchTemplateGetSize_CoeffNormed.
//
//  Purpose: Calculates the size of temporary buffer, required to run one of
//           the MatchTemplate(SqDiff, Corr, Coeff)(Normed)_(dataType)_C1R
//           functions.
//
//  Return:
//    ippStsNoErr         Ok
//    ippStsNullPtrErr    Pointer to bufferSize is NULL
//    ippStsSizeErr       The widths or heights of ROI or template are less
//                        then 1
//    ippStsDataTypeErr   Specified dataType is invalid or unsupported
//
//  Parameters:
//    roiSize             source image ROI size
//    templSize           size of template
//    dataType            source image depth (may be 8u, 8s or 32f)
//    bufferSize          output parameter. Address to store the calculated
//                        buffer size. Calculated buffer size may be zero in
//                        case of FFT use.
*/
IPPAPI( IppStatus, ippiMatchTemplateGetBufSize_SqDiff,( IppiSize roiSize,
                IppiSize templSize, IppDataType dataType, int* bufferSize ))

IPPAPI( IppStatus, ippiMatchTemplateGetBufSize_SqDiffNormed,( IppiSize roiSize,
                IppiSize templSize, IppDataType dataType, int* bufferSize))

IPPAPI( IppStatus, ippiMatchTemplateGetBufSize_Corr,( IppiSize roiSize,
                IppiSize templSize, IppDataType dataType, int* bufferSize))

IPPAPI(IppStatus, ippiMatchTemplateGetBufSize_CorrNormed, ( IppiSize roiSize,
                IppiSize templSize, IppDataType dataType, int* bufferSize))

IPPAPI(IppStatus, ippiMatchTemplateGetBufSize_Coeff, ( IppiSize roiSize,
                IppiSize templSize, IppDataType dataType, int* bufferSize))

IPPAPI(IppStatus, ippiMatchTemplateGetBufSize_CoeffNormed, ( IppiSize roiSize,
                IppiSize templSize, IppDataType dataType, int* bufferSize))

/* ////////////////////////////////////////////////////////////////////////////
//  Names:  ippiMatchTemplate_SqDiff_8u32f_C1R,
//          ippiMatchTemplate_SqDiffNormed_8u32f_C1R,
//          ippiMatchTemplate_Corr_8u32f_C1R,
//          ippiMatchTemplate_CorrNormed_8u32f_C1R,
//          ippiMatchTemplate_Coeff_8u32f_C1R,
//          ippiMatchTemplate_CoeffNormed_8u32f_C1R,
//
//          ippiMatchTemplate_SqDiff_8s32f_C1R,
//          ippiMatchTemplate_SqDiffNormed_8s32f_C1R,
//          ippiMatchTemplate_Corr_8s32f_C1R,
//          ippiMatchTemplate_CorrNormed_8s32f_C1R,
//          ippiMatchTemplate_Coeff_8s32f_C1R,
//          ippiMatchTemplate_CoeffNormed_8s32f_C1R,
//
//          ippiMatchTemplate_SqDiff_32f_C1R,
//          ippiMatchTemplate_SqDiffNormed_32f_C1R,
//          ippiMatchTemplate_Corr_32f_C1R,
//          ippiMatchTemplate_CorrNormed_32f_C1R,
//          ippiMatchTemplate_Coeff_32f_C1R,
//          ippiMatchTemplate_CoeffNormed_32f_C1R.
//
//  Purpose: ippiMatchTemplate_Corr(Normed)() function allows you to compute
//           the cross-correlation of an image and a template (another image).
//           The cross-correlation values are image similarity measures: the
//           higher cross-correlation at a particular pixel, the more
//           similarity between the template and the image in the neighborhood
//           of the pixel.
//
//           The difference of ippiMatchTemplate_Coeff(Normed) from
//           ippiMatchTemplate_Corr(Normed)() functions is the using
//           of Zerro Mean image and Template to avoid brightness impact.
//           (Before the calculation of the cross-correlation coefficients,
//           the mean of the image in the region under the feature is
//           subtracted from every image pixel; the same for the template.)
//
//           ippiMatchTemplate_SqDiff(Normed)() function allows you to compute
//           the Euclidean Distance or Sum of Squared Distance (SSD) of an
//           image and a template (another image).
//               The SSD values are image similarity measures: the smaller
//           value of SSD at a particular pixel, the more similarity between
//           the template and the image in the neighborhood of the pixel.
//
//           If IppiSize's of image and template are Wa * Ha and Wb * Hb
//           correspondingly, then the IppiSize of the resulting matrice with
//           normalized cross-correlation coefficients will be
//
//                      ( Wa - Wb + 1 )*( Ha - Hb + 1 )
//
//           ('Valid' case in MatLab notation)
//
//  Return:
//   ippStsNoErr       - Ok
//   ippStsNullPtrErr  - at least one of the pointers to pSrc, pDst or pTpl
//                       is NULL;
//   ippStsSizeErr     - at least one of the sizes of srcRoiSize or tplRoiSize
//                       is less then 1, or at least one of the sizes of
//                       srcRoiSize is smaller then the corresponding size of
//                       the tplRoiSize;
//   ippStsStepErr     - at least one of the srcStep, tplStep or dstStep is
//                       less then 1;
//   ippStsMemAllocErr - an error occur during allocation memory for internal
//                       buffers.
//
//  Arguments:
//    pImage           - pointer to the source image ROI;
//    imageStep        - step in bytes through the source image buffer;
//    roiSize          - size of the source ROI in pixels;
//    pTemplate        - pointer to the template ( feature ) image ROI;
//    templStep        - step in bytes through the template image buffer;
//    templSize        - size of the template ROI in pixels;
//    pResult          - pointer to the destination buffer;
//    resultStep       - step in bytes through the destination image buffer.
*/

IPPAPI( IppStatus, ippiMatchTemplate_SqDiff_8u32f_C1R,(
                   const Ipp8u* pImage, int imageStep, IppiSize roiSize,
                   const Ipp8u* pTemplate, int templStep, IppiSize templSize,
                   Ipp32f* pResult, int resultStep, void* pBuffer ))
IPPAPI( IppStatus, ippiMatchTemplate_SqDiffNormed_8u32f_C1R,(
                   const Ipp8u* pImage, int imageStep, IppiSize roiSize,
                   const Ipp8u* pTemplate, int templStep, IppiSize templSize,
                   Ipp32f* pResult, int resultStep, void* pBuffer ))
IPPAPI( IppStatus, ippiMatchTemplate_Corr_8u32f_C1R,(
                   const Ipp8u* pImage, int imageStep, IppiSize roiSize,
                   const Ipp8u* pTemplate, int templStep, IppiSize templSize,
                   Ipp32f* pResult, int resultStep, void* pBuffer ))
IPPAPI( IppStatus, ippiMatchTemplate_CorrNormed_8u32f_C1R,(
                   const Ipp8u* pImage, int imageStep, IppiSize roiSize,
                   const Ipp8u* pTemplate, int templStep, IppiSize templSize,
                   Ipp32f* pResult, int resultStep, void* pBuffer ))
IPPAPI( IppStatus, ippiMatchTemplate_Coeff_8u32f_C1R,(
                   const Ipp8u* pImage, int imageStep, IppiSize roiSize,
                   const Ipp8u* pTemplate, int templStep, IppiSize templSize,
                   Ipp32f* pResult, int resultStep, void* pBuffer ))
IPPAPI( IppStatus, ippiMatchTemplate_CoeffNormed_8u32f_C1R,(
                   const Ipp8u* pImage, int imageStep, IppiSize roiSize,
                   const Ipp8u* pTemplate, int templStep, IppiSize templSize,
                   Ipp32f* pResult, int resultStep, void* pBuffer ))
IPPAPI( IppStatus, ippiMatchTemplate_SqDiff_8s32f_C1R,(
                   const Ipp8s* pImage, int imageStep, IppiSize roiSize,
                   const Ipp8s* pTemplate, int templStep, IppiSize templSize,
                   Ipp32f* pResult, int resultStep, void* pBuffer ))
IPPAPI( IppStatus, ippiMatchTemplate_SqDiffNormed_8s32f_C1R,(
                   const Ipp8s* pImage, int imageStep, IppiSize roiSize,
                   const Ipp8s* pTemplate, int templStep, IppiSize templSize,
                   Ipp32f* pResult, int resultStep, void* pBuffer ))
IPPAPI( IppStatus, ippiMatchTemplate_Corr_8s32f_C1R,(
                   const Ipp8s* pImage, int imageStep, IppiSize roiSize,
                   const Ipp8s* pTemplate, int templStep, IppiSize templSize,
                   Ipp32f* pResult, int resultStep, void* pBuffer ))
IPPAPI( IppStatus, ippiMatchTemplate_CorrNormed_8s32f_C1R,(
                   const Ipp8s* pImage, int imageStep, IppiSize roiSize,
                   const Ipp8s* pTemplate, int templStep, IppiSize templSize,
                   Ipp32f* pResult, int resultStep, void* pBuffer ))
IPPAPI( IppStatus, ippiMatchTemplate_Coeff_8s32f_C1R,(
                   const Ipp8s* pImage, int imageStep, IppiSize roiSize,
                   const Ipp8s* pTemplate, int templStep, IppiSize templSize,
                   Ipp32f* pResult, int resultStep, void* pBuffer ))
IPPAPI( IppStatus, ippiMatchTemplate_CoeffNormed_8s32f_C1R,(
                   const Ipp8s* pImage, int imageStep, IppiSize roiSize,
                   const Ipp8s* pTemplate, int templStep, IppiSize templSize,
                   Ipp32f* pResult, int resultStep, void* pBuffer ))
IPPAPI( IppStatus, ippiMatchTemplate_SqDiff_32f_C1R,(
                   const Ipp32f* pImage, int imageStep, IppiSize roiSize,
                   const Ipp32f* pTemplate, int templStep, IppiSize templSize,
                   Ipp32f* pResult, int resultStep, void* pBuffer ))
IPPAPI( IppStatus, ippiMatchTemplate_SqDiffNormed_32f_C1R,(
                   const Ipp32f* pImage, int imageStep, IppiSize roiSize,
                   const Ipp32f* pTemplate, int templStep, IppiSize templSize,
                   Ipp32f* pResult, int resultStep, void* pBuffer ))
IPPAPI( IppStatus, ippiMatchTemplate_Corr_32f_C1R,(
                   const Ipp32f* pImage, int imageStep, IppiSize roiSize,
                   const Ipp32f* pTemplate, int templStep, IppiSize templSize,
                   Ipp32f* pResult, int resultStep, void* pBuffer ))
IPPAPI( IppStatus, ippiMatchTemplate_CorrNormed_32f_C1R,(
                   const Ipp32f* pImage, int imageStep, IppiSize roiSize,
                   const Ipp32f* pTemplate, int templStep, IppiSize templSize,
                   Ipp32f* pResult, int resultStep, void* pBuffer ))
IPPAPI( IppStatus, ippiMatchTemplate_Coeff_32f_C1R,(
                   const Ipp32f* pImage, int imageStep, IppiSize roiSize,
                   const Ipp32f* pTemplate, int templStep, IppiSize templSize,
                   Ipp32f* pResult, int resultStep, void* pBuffer ))
IPPAPI( IppStatus, ippiMatchTemplate_CoeffNormed_32f_C1R,(
                   const Ipp32f* pImage, int imageStep, IppiSize roiSize,
                   const Ipp32f* pTemplate, int templStep, IppiSize templSize,
                   Ipp32f* pResult, int resultStep, void* pBuffer ))

/****************************************************************************************\
*                                   Distance Transform                                   *
\****************************************************************************************/

/*F///////////////////////////////////////////////////////////////////////////////////////
//  Name:    ippiDistanceTransform_3x3_8u32f_C1R, ippiDistanceTransform_5x5_8u32f_C1R,
//
//  Purpose: For every non-zero pixel in the source image, the functions calculate
//           distance between that pixel and nearest zero pixel.
//
//  Return:
//    ippStsNoErr         Ok
//    ippStsNullPtrErr    One of pointers is NULL
//    ippStsSizeErr       The width or height of images is less or equal zero
//    ippStsStepErr       The steps in images are too small
//
//  Parameters:
//    pSrc                source image
//    srcStep             its step
//    pDst                output image with distances
//    dstStep             its step
//    roiSize             ROI size
//    pMetrics            array that determines metrics used.
//F*/
IPPAPI(IppStatus, ippiDistanceTransform_3x3_8u32f_C1R, ( const Ipp8u* pSrc, int srcStep,
                                                         Ipp32f* pDst, int dstStep,
                                                         IppiSize roiSize, Ipp32f* pMetrics ))

IPPAPI(IppStatus, ippiDistanceTransform_5x5_8u32f_C1R, ( const Ipp8u* pImage, int imgStep,
                                                         Ipp32f* pDist, int distStep,
                                                         IppiSize roiSize, Ipp32f* pMetrics ))


/*F///////////////////////////////////////////////////////////////////////////////////////
//  Name:    ippiGetDistanceTransformMask
//
//  Purpose: Calculates optimal mask for given type of metrics and given mask size
//
//  Return:
//    ippStsOk              Succeed
//    ippStsOutOfRangeErr   mask type is incorrect
//    ippStsNullPtrErr      null pointer passed
//
//  Parameters:
//    maskType            type of distance:
//                           30 - 3x3 aperture for infinify norm,
//                           31 - 3x3 aperture for L1 norm,
//                           32 - 3x3 aperture for L2 norm,
//                           52 - 5x5 aperture for L2 norm
//    pMetrics            pointer to resultant metrics
//F*/
IPPAPI( IppStatus, ippiGetDistanceTransformMask, ( int maskType, Ipp32f* pMetrics ))


/****************************************************************************************\
*                                 Absolute difference                                    *
\****************************************************************************************/

/*F///////////////////////////////////////////////////////////////////////////////////////
//  Name:    ippiAbsDiff_8u_C1R, ippiAbsDiff_32f_C1R,
//
//  Purpose: Calculate absolute difference between corresponding pixels of the two images
//           or between image pixels and scalar.
//  Return:
//    ippStsNoErr         Ok
//    ippStsNullPtrErr    One of pointers is NULL
//    ippStsSizeErr       The width or height of images is less or equal zero
//    ippStsStepErr       The steps in images are too small
//
//  Parameters:
//    pSrc1               source image
//    srcStep             its step
//    pSrc2               second source image
//    src2Step            its step
//    pDst                destination image
//    dstStep             its step
//    roiSize             ROI size
//F*/
IPPAPI(IppStatus, ippiAbsDiff_8u_C1R, ( const Ipp8u* pSrc1, int srcStep,
                                        const Ipp8u* pSrc2, int src2Step,
                                        Ipp8u* pDst, int dstStep, IppiSize roiSize ))

IPPAPI(IppStatus, ippiAbsDiff_32f_C1R, ( const Ipp32f* pSrc1, int srcStep,
                                         const Ipp32f* pSrc2, int src2Step,
                                         Ipp32f* pDst, int dstStep, IppiSize roiSize ))

/*F///////////////////////////////////////////////////////////////////////////////////////
//  Name:    ippiAbsDiffC_8u_C1R, ippiAbsDiffC_32f_C1R,
//
//  Purpose: Calculate absolute difference between between image pixels and scalar.
//  Return:
//    ippStsNoErr         Ok
//    ippStsNullPtrErr    One of pointers is NULL
//    ippStsSizeErr       The width or height of images is less or equal zero
//    ippStsStepErr       The steps in images are too small
//
//  Parameters:
//    pSrc                source image
//    srcStep             its step
//    pDst                destination image: dst(x,y) = abs(src(x,y) - value)
//    dstStep             its step
//    roiSize                 ROI size
//    value               scalar value to compare with. For 8u function
//                        if scalar is not within [0,255], it is clipped
//                        ( value = value < 0 ? 0 : value > 255 ? 255 : value )
//F*/
IPPAPI(IppStatus, ippiAbsDiffC_8u_C1R, ( const Ipp8u* pSrc, int srcStep,
                                         Ipp8u* pDst, int dstStep,
                                         IppiSize roiSize, int value ))

IPPAPI(IppStatus, ippiAbsDiffC_32f_C1R, ( const Ipp32f* pSrc, int srcStep,
                                          Ipp32f* pDst, int dstStep,
                                          IppiSize roiSize, Ipp32f value ))
/****************************************************************************************\
*                                     Line sampling                                      *
\****************************************************************************************/

/*F///////////////////////////////////////////////////////////////////////////////////////
//  Name:    ippiSampleLine_8u_C1R, ippiSampleLine_8u_C3R,
//           ippiSampleLine_32f_C1R, ippiSampleLine_32f_C3R,
//
//  Purpose: Reads values of pixels on the raster
//           line between two given points and write them to buffer.
//  Return:
//    ippStsNoErr         Ok
//    ippStsNullPtrErr    One of pointers is NULL
//    ippStsSizeErr       The width or height of images is less or equal zero
//    ippStsStepErr       The steps in images are too small
//    ippStsBadRange      At least one of the points is outside the image ROI.
//
//  Parameters:
//    pSrc                source image
//    srcStep             its step
//    roiSize                 ROI size
//    pBuffer             pointer to buffer where the pixels are stored.
//                        It must have size >= max(abs(pt2.y - pt1.y)+1,
//                                                 abs(pt2.x - pt1.x)+1)*
//                                             <size_of_pixel>.
//    pt1                 Starting point of the line segment.
//                        The pixel value will be stored to buffer first.
//    pt2                 Ending point of the line segment.
//                        The pixel value will be stored to buffer last.
//F*/
IPPAPI(IppStatus, ippiSampleLine_8u_C1R, ( const Ipp8u* pSrc, int srcStep,
                                           IppiSize roiSize, Ipp8u* pDst,
                                           IppiPoint pt1, IppiPoint pt2 ))

IPPAPI(IppStatus, ippiSampleLine_8u_C3R, ( const Ipp8u* pSrc, int srcStep,
                                           IppiSize roiSize, Ipp8u* pDst,
                                           IppiPoint pt1, IppiPoint pt2 ))

IPPAPI(IppStatus, ippiSampleLine_32f_C1R, ( const Ipp32f* pSrc, int srcStep,
                                            IppiSize roiSize, Ipp32f* pDst,
                                            IppiPoint pt1, IppiPoint pt2 ))

IPPAPI(IppStatus, ippiSampleLine_32f_C3R, ( const Ipp32f* pSrc, int srcStep,
                                            IppiSize roiSize, Ipp32f* pDst,
                                            IppiPoint pt1, IppiPoint pt2 ))

/****************************************************************************************\
*                                       Detection                                        *
\****************************************************************************************/

/*F///////////////////////////////////////////////////////////////////////////////////////
//  Name:    ippiMinEigenValGetSize
//
//  Purpose: Calculates size of temporary buffer, required to run one of MinEigenVal***
//           functions.
//
//  Return:
//    ippStsNoErr         Ok
//    ippStsNullPtrErr    One of pointers is NULL
//    ippStsSizeErr       The width is less or equal zero
//    ippStsBadRange      Aperture size or average window size are less than 3 or even.
//                        Or depth is invalid or unsupported.
//  Parameters:
//    roiWidth            width of source image ROI
//    depth               source image depth
//    apertureSize        linear size of derivative filter aperture
//    avgWindow           linear size of averaging window
//    bufferSize          output parameter. Calculated buffer size.
//F*/
IPPAPI(IppStatus, ippiMinEigenValGetSize, ( int roiWidth,
                                            int apertureSize, int avgWindow,
                                            int* bufferSize ))

/*F///////////////////////////////////////////////////////////////////////////////////////
//  Name:    ippiMinEigenVal_8u_C1R, ippiMinEigenVal_8s_C1R, ippiMinEigenVal_32f_C1R
//
//  Purpose: Calculate minimal eigen value of 2x2 autocorrelation gradient matrix
//           for every pixel. Pixels with relatively large minimal eigen values
//           are strong corners on the picture.
//  Return:
//    ippStsNoErr         Ok
//    ippStsNullPtrErr    One of pointers is NULL
//    ippStsSizeErr       The width or height of images is less or equal zero
//    ippStsStepErr       The steps in images are too small
//    ippStsBadRange      Aperture size or average window size are less than 3 or even.
//
//  Parameters:
//    pSrc                source image
//    srcStep             its step
//    pMinEigenVal        image, filled with minimal eigen values for every pixel
//    minValStep          its step
//    roiSize                 ROI size
//    apertureSize        linear size of derivative filter aperture
//    avgWindow           linear size of averaging window
//    pBuffer             preallocated temporary buffer, which size can be calculated
//                        using ippiMinEigenValGetSize function
//F*/
IPPAPI(IppStatus, ippiMinEigenVal_8u32f_C1R, ( const Ipp8u* pSrc, int srcStep,
                                               Ipp32f* pMinEigenVal, int minValStep,
                                               IppiSize roiSize, int apertureSize,
                                               int avgWindow, void* pBuffer ))

IPPAPI(IppStatus, ippiMinEigenVal_8s32f_C1R, ( const Ipp8s* pSrc, int srcStep,
                                               Ipp32f* pMinEigenVal, int minValStep,
                                               IppiSize roiSize, int apertureSize,
                                               int avgWindow, void* pBuffer ))

IPPAPI(IppStatus, ippiMinEigenVal_32f_C1R, ( const Ipp32f* pSrc, int srcStep,
                                             Ipp32f* pMinEigenVal, int minValStep,
                                             IppiSize roiSize, int apertureSize,
                                             int avgWindow, void* pBuffer ))

/*F///////////////////////////////////////////////////////////////////////////////////////
//  Name:    ippiEigenValsVecsGetSize
//
//  Purpose: Calculates size of temporary buffer, required to run one of EigenValsVecs***
//           functions.
//
//  Return:
//    ippStsNoErr         Ok
//    ippStsNullPtrErr    One of pointers is NULL
//    ippStsSizeErr       The width is less or equal zero
//    ippStsBadRange      Aperture size or average window size are less than 3 or even.
//                        Or depth is invalid or unsupported.
//  Parameters:
//    roiWidth            width of source image ROI
//    depth               source image depth
//    apertureSize        linear size of derivative filter aperture
//    avgWindow           linear size of averaging window
//    bufferSize          output parameter. Calculated buffer size.
//F*/
IPPAPI(IppStatus, ippiEigenValsVecsGetSize, ( int roiWidth,int apertureSize,
                                              int avgWindow, int* bufferSize ))

/*F///////////////////////////////////////////////////////////////////////////////////////
//  Name:    ippiEigenValsVecs_8u_C1R, ippiEigenValsVecs_8s_C1R, ippiEigenValsVecs_32f_C1R
//
//  Purpose: Calculate both eigen values and eigen vectors of 2x2 autocorrelation
//           gradient matrix for every pixel. Can be used for sophisticated
//           edge and corner detection
//  Return:
//    ippStsNoErr         Ok
//    ippStsNullPtrErr    One of pointers is NULL
//    ippStsSizeErr       The width or height of images is less or equal zero
//    ippStsStepErr       The steps in images are too small
//    ippStsBadRange      Aperture size or average window size are less than 3 or even.
//
//  Parameters:
//    pSrc                source image
//    srcStep             its step
//    pEigenVV            image, which is 6 times wider that source image,
//                        filled with 6-tuples:
//                        (eig_val1, eig_val2, eig_vec1_x, eig_vec1_y,
//                         eig_vec2_x, eig_vec2_y)
//    eigStep             output image step
//    roiSize                 ROI size
//    apertureSize        linear size of derivative filter aperture
//    avgWindow           linear size of averaging window
//    pBuffer             preallocated temporary buffer, which size can be calculated
//                        using ippiEigenValsVecsGetSize function
//F*/
IPPAPI(IppStatus, ippiEigenValsVecs_8u32f_C1R, ( const Ipp8u* pSrc, int srcStep,
                                                 Ipp32f* pEigenVV, int eigStep,
                                                 IppiSize roiSize, int apertureSize,
                                                 int avgWindow, void* pBuffer ))

IPPAPI(IppStatus, ippiEigenValsVecs_8s32f_C1R, ( const Ipp8s* pSrc, int srcStep,
                                                 Ipp32f* pEigenVV, int eigStep,
                                                 IppiSize roiSize, int apertureSize,
                                                 int avgWindow, void* pBuffer ))

IPPAPI(IppStatus, ippiEigenValsVecs_32f_C1R, ( const Ipp32f* pSrc, int srcStep,
                                               Ipp32f* pEigenVV, int eigStep,
                                               IppiSize roiSize, int apertureSize,
                                               int avgWindow, void* pBuffer ))

/*F///////////////////////////////////////////////////////////////////////////////////////
//  Name:    ippiCannyGetSize
//
//  Purpose: Calculates size of temporary buffer, required to run Canny function.
//
//  Return:
//    ippStsNoErr         Ok
//    ippStsNullPtrErr    One of pointers is NULL
//    ippStsSizeErr       The width is less or equal zero
//  Parameters:
//    roiSize                 source image ROI
//    bufferSize          output parameter. Calculated buffer size.
//F*/
IPPAPI( IppStatus, ippiCannyGetSize, ( IppiSize roiSize, int* bufferSize ))

/*F///////////////////////////////////////////////////////////////////////////////////////
//  Name:    ippiCanny_16s8u_C1IR
//
//  Purpose: Creates binary image of source's image edges,
//           using derivatives of the first order.
//  Return:
//    ippStsNoErr         Ok
//    ippStsNullPtrErr    One of pointers is NULL
//    ippStsSizeErr       The width or height of images is less or equal zero
//    ippStsStepErr       The steps in images are too small
//
//  Parameters:
//    pDx                 derivative of the source image with respect to x
//    xStep               step of the array of x derivatives
//    pDy                 derivative of the source image with respect to y
//    yStep               step of the array of y derivatives
//    roiSize                 ROI size
//    lowThresh           low threshold for hysteresis thresholding
//    highThresh          high threshold for hysteresis thresholding
//    edges               pointerto the output array
//    edgestep            its step
//    pBuffer             preallocated temporary buffer, which size can be calculated
//                        using ippiEigenValsVecsGetSize function
//F*/
IPPAPI(IppStatus, ippiCanny_16s8u_C1R, ( Ipp16s* pSrcDx, int srcDxStep,
                                          Ipp16s* pSrcDy, int srcDyStep,
                                          Ipp8u*  pDstEdges, int dstEdgeStep,
                                          IppiSize roiSize,
                                          Ipp32f  lowThresh,
                                          Ipp32f  highThresh,
                                          void*   pBuffer ))

/****************************************************************************************\
*                                      Image Statistics                                  *
\****************************************************************************************/

/*F///////////////////////////////////////////////////////////////////////////////////////
//    Name: ippiMinMaxIndx_8u_C1R, ippiMinMaxIndx_8s_C1R, ippiMinMaxIndx_32f_C1R,
//          ippiMinMaxIndx_8u_C3CR, ippiMinMaxIndx_8s_C3CR,
//          ippiMinMaxIndx_32f_C3CR,
//    Purpose:  Finds minimum and maximum values in the image and their coordinates
//
//    Return:
//      ippStsNoErr         Ok
//      ippStsNullPtrErr    One of image pointers is NULL
//      ippStsSizeErr       The width or height of images is less or equal zero
//      ippStsStepErr       The steps in images are too small
//
//    Parameters:
//      pSrc     pointer to image
//      srcStep  image step
//      roiSize      size of image ROI
//      coi      index of color channel (1..3) (if color image)
//      minVal   pointer to minimum value
//      maxVal   pointer to maximum value
//      minIdx   minimum's coordinates
//      maxIdx   maximum's coordinates
//
//    Notes:
//      Any of output parameters is optional
//F*/
IPPAPI(IppStatus, ippiMinMaxIndx_8u_C1R,( const Ipp8u* pSrc, int srcStep, IppiSize roiSize,
                                          Ipp32f* minVal, Ipp32f* maxVal,
                                          IppiPoint* minIdx, IppiPoint* maxIdx ))

IPPAPI(IppStatus, ippiMinMaxIndx_8u_C3CR,( const Ipp8u* pSrc, int srcStep,
                                           IppiSize roiSize, int coi,
                                           Ipp32f* minVal, Ipp32f* maxVal,
                                           IppiPoint* minIdx, IppiPoint* maxIdx ))

IPPAPI(IppStatus, ippiMinMaxIndx_8s_C1R,( const Ipp8s* img, int step, IppiSize roiSize,
                                          Ipp32f* minVal, Ipp32f* maxVal,
                                          IppiPoint* minIdx, IppiPoint* maxIdx ))

IPPAPI(IppStatus, ippiMinMaxIndx_8s_C3CR,( const Ipp8s* img, int step, IppiSize roiSize,
                                           int coi, Ipp32f* minVal, Ipp32f* maxVal,
                                           IppiPoint* minIdx, IppiPoint* maxIdx ))

IPPAPI(IppStatus, ippiMinMaxIndx_32f_C1R,( const Ipp32f* img, int step, IppiSize roiSize,
                                           Ipp32f* minVal, Ipp32f* maxVal,
                                           IppiPoint* minIdx, IppiPoint* maxIdx ))

IPPAPI(IppStatus, ippiMinMaxIndx_32f_C3CR,( const Ipp32f* img, int step, IppiSize roiSize,
                                            int coi, Ipp32f* minVal, Ipp32f* maxVal,
                                            IppiPoint* minIdx, IppiPoint* maxIdx))


/*F///////////////////////////////////////////////////////////////////////////////////////
//    Name: ippiMinMaxIndx_8u_C1R, ippiMinMaxIndx_8s_C1R, ippiMinMaxIndx_32f_C1R,
//          ippiMinMaxIndx_8u_C3CR, ippiMinMaxIndx_8s_C3CR,
//          ippiMinMaxIndx_32f_C3CR,
//    Purpose:  Finds minimum and maximum values in the image and their coordinates
//
//    Return:
//      ippStsNoErr         Ok
//      ippStsNullPtrErr    One of image pointers is NULL
//      ippStsSizeErr       The width or height of images is less or equal zero
//      ippStsStepErr       The steps in images are too small
//
//    Parameters:
//      pSrc       pointer to image
//      srcStep    image step
//      pMask      pointer to mask image
//      maskStep   step in the mask image
//      roiSize    size of image ROI
//      coi        index of color channel (1..3) (if color image)
//      minVal     pointer to minimum value
//      maxVal     pointer to maximum value
//      minIndex   minimum's coordinates
//      maxIndex   maximum's coordinates
//    Notes:
//      Any of output parameters is optional
//
//F*/
IPPAPI(IppStatus, ippiMinMaxIndx_8u_C1MR,( const Ipp8u* pSrc, int srcStep,
                                           const Ipp8u* pMask, int maskStep,
                                           IppiSize roiSize,
                                           Ipp32f* minVal, Ipp32f* maxVal,
                                           IppiPoint* minIdx, IppiPoint* maxIdx ))

IPPAPI( IppStatus, ippiMinMaxIndx_8u_C3CMR, ( const Ipp8u* pSrc, int srcStep,
                                              const Ipp8u* pMask, int maskStep,
                                              IppiSize roiSize, int coi,
                                              Ipp32f* minVal, Ipp32f* maxVal,
                                              IppiPoint* minIdx, IppiPoint* maxIdx ))

IPPAPI( IppStatus, ippiMinMaxIndx_8s_C1MR, ( const Ipp8s* pSrc, int srcStep,
                                             const Ipp8u* pMask, int maskStep,
                                             IppiSize roiSize,
                                             Ipp32f* minVal, Ipp32f* maxVal,
                                             IppiPoint* minIdx, IppiPoint* maxIdx ))

IPPAPI( IppStatus, ippiMinMaxIndx_8s_C3CMR, ( const Ipp8s* pSrc, int srcStep,
                                              const Ipp8u* pMask, int maskStep,
                                              IppiSize roiSize, int coi,
                                              Ipp32f* minVal, Ipp32f* maxVal,
                                              IppiPoint* minIdx, IppiPoint* maxIdx ))

IPPAPI( IppStatus, ippiMinMaxIndx_32f_C1MR, ( const Ipp32f* pSrc, int srcStep,
                                              const Ipp8u* pMask, int maskStep,
                                              IppiSize roiSize,
                                              Ipp32f* minVal, Ipp32f* maxVal,
                                              IppiPoint* minIdx, IppiPoint* maxIdx ))

IPPAPI( IppStatus, ippiMinMaxIndx_32f_C3CMR, ( const Ipp32f* pSrc, int srcStep,
                                               const Ipp8u* pMask, int maskStep,
                                               IppiSize roiSize, int coi,
                                               Ipp32f* minVal, Ipp32f* maxVal,
                                               IppiPoint* minIdx, IppiPoint* maxIdx ))


/*F///////////////////////////////////////////////////////////////////////////////////////
//    Name: ippiMean_8u_C1MR, ippiMean_8s_C1MR, ippiMean_32f_C1MR,
//          ippiMean_8u_C3CMR, ippiMean_8s_C3CMR, ippiMean_32f_C3CMR
//
//    Purpose:  Find mean value for selected region
//
//    Return:
//      ippStsNoErr         Ok
//      ippStsNullPtrErr    Some of pointers is NULL
//      ippStsSizeErr       The width or height of images is less or equal zero
//      ippStsStepErr       The steps in images are too small
//
//    Parameters:
//      pSrc      pointer to image
//      srcStep   image step
//      pMask     pointer to mask image
//      maskStep  step in the mask image
//      roiSize   size of image ROI
//      coi       index of color channel (1..3) (if color image)
//      mean      returned mean value
//    Returns:
//      ippStsOk if success or error code
//    Notes:
//F*/
IPPAPI( IppStatus, ippiMean_8u_C1MR, ( const Ipp8u* pSrc, int srcStep,
                                       const Ipp8u* pMask, int maskStep,
                                       IppiSize roiSize, Ipp64f* mean ))

IPPAPI( IppStatus, ippiMean_8u_C3CMR, ( const Ipp8u* pSrc, int srcStep,
                                        const Ipp8u* pMask, int maskStep,
                                        IppiSize roiSize, int coi, Ipp64f* mean ))

IPPAPI( IppStatus, ippiMean_8s_C1MR, ( const Ipp8s* pSrc, int srcStep,
                                       const Ipp8u* pMask, int maskStep,
                                       IppiSize roiSize, Ipp64f* mean ))

IPPAPI( IppStatus, ippiMean_8s_C3CMR, ( const Ipp8s* pSrc, int srcStep,
                                        const Ipp8u* pMask, int maskStep,
                                        IppiSize roiSize, int coi, Ipp64f* mean ))

IPPAPI( IppStatus, ippiMean_32f_C1MR, ( const Ipp32f* pSrc, int srcStep,
                                        const Ipp8u* pMask, int maskStep,
                                        IppiSize roiSize, Ipp64f* mean ))

IPPAPI( IppStatus, ippiMean_32f_C3CMR, ( const Ipp32f* pSrc, int srcStep,
                                         const Ipp8u* pMask, int maskStep,
                                         IppiSize roiSize, int coi, Ipp64f* mean ))


/*F///////////////////////////////////////////////////////////////////////////////////////
//    Name: ippiMean_StdDev_8u_C1R, ippiMean_StdDev_8s_C1R, ippiMean_StdDev_32f_C1R,
//          ippiMean_StdDev_8u_C3CR, ippiMean_StdDev_8s_C3CR, ippiMean_StdDev_32f_C3CR
//
//    Purpose:  Find mean and standard deviation values for selected region
//
//    Return:
//      ippStsNoErr         Ok
//      ippStsNullPtrErr    Some of pointers is NULL
//      ippStsSizeErr       The width or height of images is less or equal zero
//      ippStsStepErr       The steps in images are too small
//
//    Parameters:
//      pSrc      pointer to image
//      srcStep   image step
//      roiSize   size of image ROI
//      coi       index of color channel (1..3) (if color image)
//      mean      returned mean value
//      stddev    returned standard deviation
//    Returns:
//      ippStsOk if success or error code
//    Notes:
//F*/
IPPAPI( IppStatus, ippiMean_StdDev_8u_C1R, ( const Ipp8u* pSrc, int srcStep,
                                             IppiSize roiSize,
                                             Ipp64f* mean, Ipp64f* stddev ))

IPPAPI( IppStatus, ippiMean_StdDev_8u_C3CR, ( const Ipp8u* pSrc, int srcStep,
                                              IppiSize roiSize, int coi,
                                              Ipp64f* mean, Ipp64f* stddev ))

IPPAPI( IppStatus, ippiMean_StdDev_8s_C1R, ( const Ipp8s* pSrc, int srcStep,
                                             IppiSize roiSize,
                                             Ipp64f* mean, Ipp64f* stddev ))

IPPAPI( IppStatus, ippiMean_StdDev_8s_C3CR, ( const Ipp8s* pSrc, int srcStep,
                                              IppiSize roiSize, int coi,
                                              Ipp64f* mean, Ipp64f* stddev ))

IPPAPI( IppStatus, ippiMean_StdDev_32f_C1R, ( const Ipp32f* pSrc, int srcStep,
                                              IppiSize roiSize,
                                              Ipp64f* mean, Ipp64f* stddev ))

IPPAPI( IppStatus, ippiMean_StdDev_32f_C3CR, ( const Ipp32f* pSrc, int srcStep,
                                               IppiSize roiSize, int coi,
                                               Ipp64f* mean, Ipp64f* stddev ))


/*F///////////////////////////////////////////////////////////////////////////////////////
//    Name: ippiMean_StdDev_8u_C1MR, ippiMean_StdDev_8s_C1MR, ippiMean_StdDev_32f_C1MR,
//          ippiMean_StdDev_8u_C3CMR, ippiMean_StdDev_8s_C3CMR, ippiMean_StdDev_32f_C3CMR
//
//    Purpose:  Find mean and standard deviation values for selected region
//
//    Return:
//      ippStsNoErr         Ok
//      ippStsNullPtrErr    Some of pointers is NULL
//      ippStsSizeErr       The width or height of images is less or equal zero
//      ippStsStepErr       The steps in images are too small
//
//    Parameters:
//      pSrc      pointer to image
//      srcStep   image step
//      pMask     pointer to mask image
//      maskStep  step in the mask image
//      roiSize   size of image ROI
//      coi       index of color channel (1..3) (if color image)
//      mean      returned mean value
//      stddev    returned standard deviation
//    Returns:
//      ippStsOk if success or error code
//    Notes:
//F*/
IPPAPI( IppStatus, ippiMean_StdDev_8u_C1MR, ( const Ipp8u* pSrc, int srcStep,
                                              const Ipp8u* pMask, int maskStep,
                                              IppiSize roiSize,
                                              Ipp64f* mean, Ipp64f* stddev ))

IPPAPI( IppStatus, ippiMean_StdDev_8u_C3CMR, ( const Ipp8u* pSrc, int srcStep,
                                               const Ipp8u* pMask, int maskStep,
                                               IppiSize roiSize, int coi,
                                               Ipp64f* mean, Ipp64f* stddev ))

IPPAPI( IppStatus, ippiMean_StdDev_8s_C1MR, ( const Ipp8s* pSrc, int srcStep,
                                              const Ipp8u* pMask, int maskStep,
                                              IppiSize roiSize,
                                              Ipp64f* mean, Ipp64f* stddev ))

IPPAPI( IppStatus, ippiMean_StdDev_8s_C3CMR, ( const Ipp8s* pSrc, int srcStep,
                                               const Ipp8u* pMask, int maskStep,
                                               IppiSize roiSize, int coi,
                                               Ipp64f* mean, Ipp64f* stddev ))

IPPAPI( IppStatus, ippiMean_StdDev_32f_C1MR, ( const Ipp32f* pSrc, int srcStep,
                                               const Ipp8u* pMask, int maskStep,
                                               IppiSize roiSize,
                                               Ipp64f* mean, Ipp64f* stddev ))

IPPAPI( IppStatus, ippiMean_StdDev_32f_C3CMR, ( const Ipp32f* pSrc, int srcStep,
                                                const Ipp8u* pMask, int maskStep,
                                                IppiSize roiSize, int coi,
                                                Ipp64f* mean, Ipp64f* stddev ))


/*F///////////////////////////////////////////////////////////////////////////////////////
//  Names: ippiNorm_Inf_8u_C1MR,      ippiNorm_Inf_8s_C1MR,      ippiNorm_Inf_32f_C1MR,
//         ippiNorm_Inf_8u_C3CMR,     ippiNorm_Inf_8s_C3CMR,     ippiNorm_Inf_32f_C3CMR,
//         ippiNormDiff_Inf_8u_C1MR,  ippiNormDiff_Inf_8s_C1MR,  ippiNormDiff_Inf_32f_C1MR,
//         ippiNormDiff_Inf_8u_C3CMR, ippiNormDiff_Inf_8s_C3CMR, ippiNormDiff_Inf_32f_C3CMR,
//         ippiNormRel_Inf_8u_C1MR,   ippiNormRel_Inf_8s_C1MR,   ippiNormRel_Inf_32f_C1MR,
//         ippiNormRel_Inf_8u_C3CMR,  ippiNormRel_Inf_8s_C3CMR,  ippiNormRel_Inf_32f_C3CMR,
//
//         ippiNorm_L1_8u_C1MR,       ippiNorm_L1_8s_C1MR,       ippiNorm_L1_32f_C1MR,
//         ippiNorm_L1_8u_C3CMR,      ippiNorm_L1_8s_C3CMR,      ippiNorm_L1_32f_C3CMR,
//         ippiNormDiff_L1_8u_C1MR,   ippiNormDiff_L1_8s_C1MR,   ippiNormDiff_L1_32f_C1MR,
//         ippiNormDiff_L1_8u_C3CMR,  ippiNormDiff_L1_8s_C3CMR,  ippiNormDiff_L1_32f_C3CMR,
//         ippiNormRel_L1_8u_C1MR,    ippiNormRel_L1_8s_C1MR,    ippiNormRel_L1_32f_C1MR,
//         ippiNormRel_L1_8u_C3CMR,   ippiNormRel_L1_8s_C3CMR,   ippiNormRel_L1_32f_C3CMR,
//
//         ippiNorm_L2_8u_C1MR,       ippiNorm_L2_8s_C1MR,       ippiNorm_L2_32f_C1MR,
//         ippiNorm_L2_8u_C3CMR,      ippiNorm_L2_8s_C3CMR,      ippiNorm_L2_32f_C3CMR,
//         ippiNormDiff_L2_8u_C1MR,   ippiNormDiff_L2_8s_C1MR,   ippiNormDiff_L2_32f_C1MR,
//         ippiNormDiff_L2_8u_C3CMR,  ippiNormDiff_L2_8s_C3CMR,  ippiNormDiff_L2_32f_C3CMR,
//         ippiNormRel_L2_8u_C1MR,    ippiNormRel_L2_8s_C1MR,    ippiNormRel_L2_32f_C1MR,
//         ippiNormRel_L2_8u_C3CMR,   ippiNormRel_L2_8s_C3CMR,   ippiNormRel_L2_32f_C3CMR
//
//    Purpose: Calculates ordinary, differential or relative norms of one or two images
//             in an arbitrary image region.
//
//    Parameters:
//        pSrc, pSrc1, pSrc2, pMask             - pointers to source images and mask file
//        srcStep, src1Step, src2Step, maskStep - their steps
//        roiSize                               - their size or ROI size
//        coi                                   - COI index (1..3) (if 3-channel images)
//
//    Returns:
//        Ipp status
//
//    Notes:
//F*/

/* ///////////////////////////////// 8uC1 flavor ////////////////////////////////////// */
IPPAPI( IppStatus, ippiNorm_Inf_8u_C1MR, ( const Ipp8u* pSrc, int srcStep,
                                           const Ipp8u* pMask,int maskStep,
                                           IppiSize roiSize, Ipp64f* norm ) )

IPPAPI( IppStatus, ippiNorm_Inf_8s_C1MR, ( const Ipp8s* pSrc, int srcStep,
                                           const Ipp8u* pMask,int maskStep,
                                           IppiSize roiSize, Ipp64f* norm ) )

IPPAPI( IppStatus, ippiNorm_Inf_32f_C1MR, ( const Ipp32f* pSrc, int srcStep,
                                            const Ipp8u* pMask, int maskStep,
                                            IppiSize roiSize, Ipp64f* norm ) )

IPPAPI( IppStatus, ippiNorm_Inf_8u_C3CMR, ( const Ipp8u* pSrc, int srcStep,
                                            const Ipp8u* pMask,int maskStep,
                                            IppiSize roiSize, int coi, Ipp64f* norm ) )

IPPAPI( IppStatus, ippiNorm_Inf_8s_C3CMR, ( const Ipp8s* pSrc, int srcStep,
                                            const Ipp8u* pMask,int maskStep,
                                            IppiSize roiSize, int coi, Ipp64f* norm ) )

IPPAPI( IppStatus, ippiNorm_Inf_32f_C3CMR, ( const Ipp32f* pSrc, int srcStep,
                                             const Ipp8u* pMask, int maskStep,
                                             IppiSize roiSize, int coi, Ipp64f* norm ) )


IPPAPI( IppStatus, ippiNormDiff_Inf_8u_C1MR, ( const Ipp8u* pSrc1, int src1Step,
                                               const Ipp8u* pSrc2, int src2Step,
                                               const Ipp8u* pMask, int maskStep,
                                               IppiSize roiSize,   Ipp64f* norm ) )

IPPAPI( IppStatus, ippiNormDiff_Inf_8s_C1MR, ( const Ipp8s* pSrc1, int src1Step,
                                               const Ipp8s* pSrc2, int src2Step,
                                               const Ipp8u* pMask, int maskStep,
                                               IppiSize roiSize,   Ipp64f* norm ) )

IPPAPI( IppStatus, ippiNormDiff_Inf_32f_C1MR, ( const Ipp32f* pSrc1, int src1Step,
                                                const Ipp32f* pSrc2, int src2Step,
                                                const Ipp8u* pMask,  int maskStep,
                                                IppiSize roiSize,    Ipp64f* norm ) )

IPPAPI( IppStatus, ippiNormDiff_Inf_8u_C3CMR, (const Ipp8u* pSrc1, int src1Step,
                                               const Ipp8u* pSrc2, int src2Step,
                                               const Ipp8u* pMask, int maskStep,
                                               IppiSize roiSize, int coi, Ipp64f* norm ))

IPPAPI( IppStatus, ippiNormDiff_Inf_8s_C3CMR, (const Ipp8s* pSrc1, int src1Step,
                                               const Ipp8s* pSrc2, int src2Step,
                                               const Ipp8u* pMask, int maskStep,
                                               IppiSize roiSize, int coi, Ipp64f* norm ))

IPPAPI( IppStatus, ippiNormDiff_Inf_32f_C3CMR, (const Ipp32f* pSrc1, int src1Step,
                                                const Ipp32f* pSrc2, int src2Step,
                                                const Ipp8u* pMask,  int maskStep,
                                                IppiSize roiSize, int coi, Ipp64f* norm ))


IPPAPI( IppStatus, ippiNormRel_Inf_8u_C1MR, ( const Ipp8u* pSrc1, int src1Step,
                                              const Ipp8u* pSrc2, int src2Step,
                                              const Ipp8u* pMask, int maskStep,
                                              IppiSize roiSize,   Ipp64f* norm ) )

IPPAPI( IppStatus, ippiNormRel_Inf_8s_C1MR, ( const Ipp8s* pSrc1, int src1Step,
                                              const Ipp8s* pSrc2, int src2Step,
                                              const Ipp8u* pMask, int maskStep,
                                              IppiSize roiSize,   Ipp64f* norm ) )

IPPAPI( IppStatus, ippiNormRel_Inf_32f_C1MR, ( const Ipp32f* pSrc1, int src1Step,
                                               const Ipp32f* pSrc2, int src2Step,
                                               const Ipp8u* pMask,  int maskStep,
                                               IppiSize roiSize,    Ipp64f* norm ) )

IPPAPI( IppStatus, ippiNormRel_Inf_8u_C3CMR, ( const Ipp8u* pSrc1, int src1Step,
                                               const Ipp8u* pSrc2, int src2Step,
                                               const Ipp8u* pMask, int maskStep,
                                               IppiSize roiSize, int coi, Ipp64f* norm ))

IPPAPI( IppStatus, ippiNormRel_Inf_8s_C3CMR, ( const Ipp8s* pSrc1, int src1Step,
                                               const Ipp8s* pSrc2, int src2Step,
                                               const Ipp8u* pMask, int maskStep,
                                               IppiSize roiSize, int coi, Ipp64f* norm ))

IPPAPI( IppStatus, ippiNormRel_Inf_32f_C3CMR, ( const Ipp32f* pSrc1, int src1Step,
                                                const Ipp32f* pSrc2, int src2Step,
                                                const Ipp8u* pMask,  int maskStep,
                                                IppiSize roiSize, int coi, Ipp64f* norm ))


IPPAPI( IppStatus, ippiNorm_L1_8u_C1MR, ( const Ipp8u* pSrc, int srcStep,
                                           const Ipp8u* pMask,int maskStep,
                                           IppiSize roiSize, Ipp64f* norm ) )

IPPAPI( IppStatus, ippiNorm_L1_8s_C1MR, ( const Ipp8s* pSrc, int srcStep,
                                           const Ipp8u* pMask,int maskStep,
                                           IppiSize roiSize, Ipp64f* norm ) )

IPPAPI( IppStatus, ippiNorm_L1_32f_C1MR, ( const Ipp32f* pSrc, int srcStep,
                                            const Ipp8u* pMask, int maskStep,
                                            IppiSize roiSize, Ipp64f* norm ) )

IPPAPI( IppStatus, ippiNorm_L1_8u_C3CMR, ( const Ipp8u* pSrc, int srcStep,
                                            const Ipp8u* pMask,int maskStep,
                                            IppiSize roiSize, int coi, Ipp64f* norm ) )

IPPAPI( IppStatus, ippiNorm_L1_8s_C3CMR, ( const Ipp8s* pSrc, int srcStep,
                                            const Ipp8u* pMask,int maskStep,
                                            IppiSize roiSize, int coi, Ipp64f* norm ) )

IPPAPI( IppStatus, ippiNorm_L1_32f_C3CMR, ( const Ipp32f* pSrc, int srcStep,
                                             const Ipp8u* pMask, int maskStep,
                                             IppiSize roiSize, int coi, Ipp64f* norm ) )


IPPAPI( IppStatus, ippiNormDiff_L1_8u_C1MR, ( const Ipp8u* pSrc1, int src1Step,
                                              const Ipp8u* pSrc2, int src2Step,
                                              const Ipp8u* pMask, int maskStep,
                                              IppiSize roiSize,   Ipp64f* norm ) )

IPPAPI( IppStatus, ippiNormDiff_L1_8s_C1MR, ( const Ipp8s* pSrc1, int src1Step,
                                              const Ipp8s* pSrc2, int src2Step,
                                              const Ipp8u* pMask, int maskStep,
                                              IppiSize roiSize,   Ipp64f* norm ) )

IPPAPI( IppStatus, ippiNormDiff_L1_32f_C1MR, ( const Ipp32f* pSrc1, int src1Step,
                                               const Ipp32f* pSrc2, int src2Step,
                                               const Ipp8u* pMask,  int maskStep,
                                               IppiSize roiSize,    Ipp64f* norm ) )

IPPAPI( IppStatus, ippiNormDiff_L1_8u_C3CMR, ( const Ipp8u* pSrc1, int src1Step,
                                               const Ipp8u* pSrc2, int src2Step,
                                               const Ipp8u* pMask, int maskStep,
                                               IppiSize roiSize, int coi, Ipp64f* norm ))

IPPAPI( IppStatus, ippiNormDiff_L1_8s_C3CMR, ( const Ipp8s* pSrc1, int src1Step,
                                               const Ipp8s* pSrc2, int src2Step,
                                               const Ipp8u* pMask, int maskStep,
                                               IppiSize roiSize, int coi, Ipp64f* norm ))

IPPAPI( IppStatus, ippiNormDiff_L1_32f_C3CMR, ( const Ipp32f* pSrc1, int src1Step,
                                                const Ipp32f* pSrc2, int src2Step,
                                                const Ipp8u* pMask,  int maskStep,
                                                IppiSize roiSize, int coi, Ipp64f* norm ))


IPPAPI( IppStatus, ippiNormRel_L1_8u_C1MR, ( const Ipp8u* pSrc1, int src1Step,
                                              const Ipp8u* pSrc2, int src2Step,
                                              const Ipp8u* pMask, int maskStep,
                                              IppiSize roiSize,   Ipp64f* norm ) )

IPPAPI( IppStatus, ippiNormRel_L1_8s_C1MR, ( const Ipp8s* pSrc1, int src1Step,
                                              const Ipp8s* pSrc2, int src2Step,
                                              const Ipp8u* pMask, int maskStep,
                                              IppiSize roiSize,   Ipp64f* norm ) )

IPPAPI( IppStatus, ippiNormRel_L1_32f_C1MR, ( const Ipp32f* pSrc1, int src1Step,
                                               const Ipp32f* pSrc2, int src2Step,
                                               const Ipp8u* pMask,  int maskStep,
                                               IppiSize roiSize,    Ipp64f* norm ) )

IPPAPI( IppStatus, ippiNormRel_L1_8u_C3CMR, ( const Ipp8u* pSrc1, int src1Step,
                                               const Ipp8u* pSrc2, int src2Step,
                                               const Ipp8u* pMask, int maskStep,
                                               IppiSize roiSize, int coi, Ipp64f* norm ))

IPPAPI( IppStatus, ippiNormRel_L1_8s_C3CMR, ( const Ipp8s* pSrc1, int src1Step,
                                               const Ipp8s* pSrc2, int src2Step,
                                               const Ipp8u* pMask, int maskStep,
                                               IppiSize roiSize, int coi, Ipp64f* norm ))

IPPAPI( IppStatus, ippiNormRel_L1_32f_C3CMR, ( const Ipp32f* pSrc1, int src1Step,
                                                const Ipp32f* pSrc2, int src2Step,
                                                const Ipp8u* pMask,  int maskStep,
                                                IppiSize roiSize, int coi, Ipp64f* norm ))


IPPAPI( IppStatus, ippiNorm_L2_8u_C1MR, ( const Ipp8u* pSrc, int srcStep,
                                           const Ipp8u* pMask,int maskStep,
                                           IppiSize roiSize, Ipp64f* norm ) )

IPPAPI( IppStatus, ippiNorm_L2_8s_C1MR, ( const Ipp8s* pSrc, int srcStep,
                                           const Ipp8u* pMask,int maskStep,
                                           IppiSize roiSize, Ipp64f* norm ) )

IPPAPI( IppStatus, ippiNorm_L2_32f_C1MR, ( const Ipp32f* pSrc, int srcStep,
                                            const Ipp8u* pMask, int maskStep,
                                            IppiSize roiSize, Ipp64f* norm ) )

IPPAPI( IppStatus, ippiNorm_L2_8u_C3CMR, ( const Ipp8u* pSrc, int srcStep,
                                            const Ipp8u* pMask,int maskStep,
                                            IppiSize roiSize, int coi, Ipp64f* norm ) )

IPPAPI( IppStatus, ippiNorm_L2_8s_C3CMR, ( const Ipp8s* pSrc, int srcStep,
                                            const Ipp8u* pMask,int maskStep,
                                            IppiSize roiSize, int coi, Ipp64f* norm ) )

IPPAPI( IppStatus, ippiNorm_L2_32f_C3CMR, ( const Ipp32f* pSrc, int srcStep,
                                             const Ipp8u* pMask, int maskStep,
                                             IppiSize roiSize, int coi, Ipp64f* norm ) )


IPPAPI( IppStatus, ippiNormDiff_L2_8u_C1MR, ( const Ipp8u* pSrc1, int src1Step,
                                              const Ipp8u* pSrc2, int src2Step,
                                              const Ipp8u* pMask, int maskStep,
                                              IppiSize roiSize,   Ipp64f* norm ) )

IPPAPI( IppStatus, ippiNormDiff_L2_8s_C1MR, ( const Ipp8s* pSrc1, int src1Step,
                                              const Ipp8s* pSrc2, int src2Step,
                                              const Ipp8u* pMask, int maskStep,
                                              IppiSize roiSize,   Ipp64f* norm ) )

IPPAPI( IppStatus, ippiNormDiff_L2_32f_C1MR, ( const Ipp32f* pSrc1, int src1Step,
                                               const Ipp32f* pSrc2, int src2Step,
                                               const Ipp8u* pMask,  int maskStep,
                                               IppiSize roiSize,    Ipp64f* norm ) )

IPPAPI( IppStatus, ippiNormDiff_L2_8u_C3CMR, ( const Ipp8u* pSrc1, int src1Step,
                                               const Ipp8u* pSrc2, int src2Step,
                                               const Ipp8u* pMask, int maskStep,
                                               IppiSize roiSize, int coi, Ipp64f* norm ))

IPPAPI( IppStatus, ippiNormDiff_L2_8s_C3CMR, ( const Ipp8s* pSrc1, int src1Step,
                                               const Ipp8s* pSrc2, int src2Step,
                                               const Ipp8u* pMask, int maskStep,
                                               IppiSize roiSize, int coi, Ipp64f* norm ))

IPPAPI( IppStatus, ippiNormDiff_L2_32f_C3CMR, ( const Ipp32f* pSrc1, int src1Step,
                                                const Ipp32f* pSrc2, int src2Step,
                                                const Ipp8u* pMask,  int maskStep,
                                                IppiSize roiSize, int coi, Ipp64f* norm ))


IPPAPI( IppStatus, ippiNormRel_L2_8u_C1MR, ( const Ipp8u* pSrc1, int src1Step,
                                              const Ipp8u* pSrc2, int src2Step,
                                              const Ipp8u* pMask, int maskStep,
                                              IppiSize roiSize,   Ipp64f* norm ) )

IPPAPI( IppStatus, ippiNormRel_L2_8s_C1MR, ( const Ipp8s* pSrc1, int src1Step,
                                              const Ipp8s* pSrc2, int src2Step,
                                              const Ipp8u* pMask, int maskStep,
                                              IppiSize roiSize,   Ipp64f* norm ) )

IPPAPI( IppStatus, ippiNormRel_L2_32f_C1MR, ( const Ipp32f* pSrc1, int src1Step,
                                               const Ipp32f* pSrc2, int src2Step,
                                               const Ipp8u* pMask,  int maskStep,
                                               IppiSize roiSize,    Ipp64f* norm ) )

IPPAPI( IppStatus, ippiNormRel_L2_8u_C3CMR, ( const Ipp8u* pSrc1, int src1Step,
                                               const Ipp8u* pSrc2, int src2Step,
                                               const Ipp8u* pMask, int maskStep,
                                               IppiSize roiSize, int coi, Ipp64f* norm ))

IPPAPI( IppStatus, ippiNormRel_L2_8s_C3CMR, ( const Ipp8s* pSrc1, int src1Step,
                                               const Ipp8s* pSrc2, int src2Step,
                                               const Ipp8u* pMask, int maskStep,
                                               IppiSize roiSize, int coi, Ipp64f* norm ))

IPPAPI( IppStatus, ippiNormRel_L2_32f_C3CMR, ( const Ipp32f* pSrc1, int src1Step,
                                                const Ipp32f* pSrc2, int src2Step,
                                                const Ipp8u* pMask,  int maskStep,
                                                IppiSize roiSize, int coi, Ipp64f* norm ))

/* ///////////////////////////////////////////////////////////////////////////////////////
//  Name:       ippibFastArctan
//
//  Purpose:    Given "X" and "Y" images, calculates "angle" image
//              (i.e. atan(y/x)). Resultant angles are in degrees.
//
//  Return:
//    ippStsNoErr              Ok
//    ippStsNullPtrErr         One of pointers is NULL
//    ippStsSizeErr            The width or height of images is less or equal zero
//
//  Arguments:
//    pSrcY                    pointer to source "Y" image
//    srcYStep                 step in the source "Y" image
//    pSrcX                    pointer to source "X" image
//    srcXStep                 step in the source "X" image
//    pDst                     pointer to "angle" image
//    dstStep                  step in the "angle" image
//    roiSize                  images' ROI size
//
//  Note:
//    For current version angle precision is ~0.1 degree
*/
IPPAPI(IppStatus, ippibFastArctan_32f, ( const Ipp32f*  pSrcY, const Ipp32f*  pSrcX,
                                         Ipp32f* pDst, int length ))

#if defined __cplusplus && !defined __IPPCV_DEFINE_USER_LIST__
}
#endif

#endif /* __IPPCV_H__ */
/* ////////////////////////// End of file "ippCV.h" ////////////////////////// */
