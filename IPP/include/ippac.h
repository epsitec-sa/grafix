/* ////////////////////////////////// "ippac.h" ////////////////////////////////
//
//                  INTEL CORPORATION PROPRIETARY INFORMATION
//     This software is supplied under the terms of a license agreement or
//     nondisclosure agreement with Intel Corporation and may not be copied
//     or disclosed except in accordance with the terms of that agreement.
//          Copyright(c) 2001-2003 Intel Corporation. All Rights Reserved.
//
//           	Intel(R) Integrated Performance Primitives
//                  Audio Coding (ippac)
//
*/

#if !defined( __IPPAC_H__ ) || defined( _OWN_BLDPCS )
#define __IPPAC_H__

#ifndef __IPPDEFS_H__
#include "ippdefs.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

//
//             FDP
//
#if !defined( _OWN_BLDPCS )

struct FDPState_32f;
typedef struct FDPState_32f IppsFDPState_32f;

#endif /* _OWN_BLDPCS */


IPPAPI(IppStatus, ippsResetFDP_32f,(IppsFDPState_32f *pFDPState))

IPPAPI(IppStatus, ippsResetFDP_SFB_32f,(IppsFDPState_32f* pFDPState,
	   const int* pSFB_Offset, int sFB_number, const Ipp8u *reset_flag))

IPPAPI(IppStatus, ippsResetFDPGroup_32f,(IppsFDPState_32f* pFDPState,
	   int reset_group_number, int step))

IPPAPI(IppStatus, ippsFDPInitAlloc_32f,(IppsFDPState_32f **pFDPState, int len))

IPPAPI(IppStatus, ippsFDPFree_32f,(IppsFDPState_32f *pFDPState))

IPPAPI(IppStatus, ippsFDPFwd_32f, (IppsFDPState_32f* pFDPState,
	   Ipp32f* pSrc, Ipp32f* pDst))

IPPAPI(IppStatus, ippsFDPInv_32f, (IppsFDPState_32f* pFDPState,
	   Ipp32f* pSrcDst, const int* pBandOffset, int predictor_bands_number,
	   const Ipp8u* prediction_used))


//
//             FIR Block
//

#if !defined( _OWN_BLDPCS )

struct FIRBlockState_32f;
typedef struct FIRBlockState_32f IppsFIRBlockState_32f;

#endif /* _OWN_BLDPCS */

IPPAPI(IppStatus, ippsFIRBlockInitAlloc_32f,(IppsFIRBlockState_32f** pState,
int order, int len))

IPPAPI(IppStatus, ippsFIRBlockFree_32f,(IppsFIRBlockState_32f* pState))

IPPAPI(IppStatus, ippsFIRBlockOne_32f,(Ipp32f *pSrc, Ipp32f* pDst, IppsFIRBlockState_32f* pState, Ipp32f *pTaps))



//
//             MDCT
//

/* MDCT 32f definitions */

#if !defined( _OWN_BLDPCS )

struct MDCTFwdSpec_32f;
struct MDCTInvSpec_32f;

typedef struct MDCTFwdSpec_32f IppsMDCTFwdSpec_32f;
typedef struct MDCTInvSpec_32f IppsMDCTInvSpec_32f;

#endif /* _OWN_BLDPCS */

IPPAPI(IppStatus, ippsMDCTFwdInitAlloc_32f,(IppsMDCTFwdSpec_32f** pMDCTSpec, int length))

IPPAPI(IppStatus, ippsMDCTInvInitAlloc_32f,(IppsMDCTInvSpec_32f** pMDCTSpec, int length))

IPPAPI(IppStatus, ippsMDCTFwdFree_32f,(IppsMDCTFwdSpec_32f* pMDCTSpec))
IPPAPI(IppStatus, ippsMDCTInvFree_32f,(IppsMDCTInvSpec_32f* pMDCTSpec))

IPPAPI(IppStatus, ippsMDCTFwdGetBufSize_32f,(const IppsMDCTFwdSpec_32f* pMDCTSpec,
    int* pSize))

IPPAPI(IppStatus, ippsMDCTInvGetBufSize_32f,(const IppsMDCTInvSpec_32f* pMDCTSpec,
    int* pSize))

IPPAPI(IppStatus, ippsMDCTFwd_32f,(const Ipp32f* pSrc, Ipp32f* pDst,
    const IppsMDCTFwdSpec_32f* pMDCTSpec, Ipp8u* pBuffer))

IPPAPI(IppStatus, ippsMDCTInv_32f,(const Ipp32f* pSrc, Ipp32f* pDst,
    const IppsMDCTInvSpec_32f* pMDCTSpec, Ipp8u* pBuffer))

// in-place functions

IPPAPI(IppStatus, ippsMDCTFwd_32f_I,(Ipp32f* pSrcDst, const IppsMDCTFwdSpec_32f* pMDCTSpec, Ipp8u* pBuffer))
IPPAPI(IppStatus, ippsMDCTInv_32f_I,(Ipp32f* pSrcDst, const IppsMDCTInvSpec_32f* pMDCTSpec, Ipp8u* pBuffer))


/* Interleave */
IPPAPI(IppStatus, ippsInterleave_16s, (const Ipp16s** pChannelsSrc, int channels_number,
                                              int length, Ipp16s* pDst))
IPPAPI(IppStatus, ippsInterleave_32f, (const Ipp32f** pChannelsSrc, int channels_number,
                                              int length, Ipp32f* pDst))

/* Deinterleave */
IPPAPI(IppStatus, ippsDeinterleave_16s, (const Ipp16s* psSrc, int channels_number,
                                              int length, Ipp16s** pChannelDst))
IPPAPI(IppStatus, ippsDeinterleave_32f, (const Ipp32f* pSrc, int channels_number,
                                              int length, Ipp32f** pChannelDst))

/*Prequantization of spectral data*/
IPPAPI(IppStatus, ippsPow34_32f16s, (const Ipp32f* pSrc, Ipp16s* pDst, int len))
IPPAPI(IppStatus, ippsPow43_16s32f, (const Ipp16s* pSrc, Ipp32f* pDst, int len))
IPPAPI(IppStatus, ippsPow34_32f,(const Ipp32f* pSrc, Ipp32f* pDst, int len))

/*Scale Factors Calculation*/
IPPAPI(IppStatus,ippsCalcSF_16s32f, (const Ipp16s* pSrc, int offset,Ipp32f *pDst, int len))

/*Scale Factors Applying */
IPPAPI(IppStatus, ippsApplySF_32f_I, (Ipp32f* pSrcDst, Ipp32f* pSF,const Ipp32s* pBandOffset,int bands_number))

IPPAPI(IppStatus, ippsGetSizeHDT_32s, (const Ipp32s* pInputTable, Ipp32s* pBuffer, Ipp32s buffSize, Ipp32s *pSize))
IPPAPI(IppStatus, ippsBuildHDT_32s, (const Ipp32s* pInputTable, Ipp32s *pDecodeTable, Ipp32s size))
IPPAPI(IppStatus, ippsDecodeVLC_32s, (Ipp32s** pBitStream, Ipp32u* offset, Ipp32s *pDecodeTable, Ipp32s *pData))

IPPAPI(IppStatus, ippsDecodeVLC_Block_32s,(Ipp32s **pBitStream, Ipp32u* offset, Ipp32s *pDecodeTable, Ipp32u lenght, Ipp16s *pData))
IPPAPI(IppStatus, ippsDecodeVLC_MP3ESCBlock_32s,(Ipp32s **pBitStream, Ipp32u* offset, Ipp32s *pDecodeTable, Ipp32u lenght, Ipp32u linbits, Ipp16s *pData))
IPPAPI(IppStatus, ippsDecodeVLC_AACESCBlock_32s,(Ipp32s **pBitStream, Ipp32u* offset, Ipp32s *pDecodeTable, Ipp32u lenght, Ipp16s *pData))

IPPAPI(IppStatus, ippsGetSizeHET_16s, (const Ipp16s* pInputTable, Ipp32s *pSize))
IPPAPI(IppStatus, ippsBuildHET_16s, (const Ipp16s* pInputTable, Ipp16s *pInternalTable))
IPPAPI(IppStatus, ippsHuffmanCountBits_16s ,(const Ipp16s* pInputData, Ipp32s length,  const Ipp16s*  pInternalTable, Ipp16s *pCountBits))

IPPAPI(IppStatus, ippsEncodeVLC_Block_16s,(Ipp16s* pInput, Ipp32s len, const Ipp16s*  pInternalTable, Ipp32s **pBitStream, Ipp32u* offset))
IPPAPI(IppStatus, ippsEncodeVLC_MP3ESCBlock_16s,(Ipp16s* pInput, Ipp32s len, const Ipp16s*  pInternalTable, Ipp32s **pBitStream, Ipp32u* offset))

IPPAPI (IppStatus, ippsMakeFloat_16s32f, (Ipp16s* inmant, Ipp16s* inexp, Ipp32s size, Ipp32f* outfloat))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippacGetLibVersion
//  Purpose:    get the library version
//  Parameters:
//  Returns:    pointer to structure describing version of the ipps library
//
//  Notes:      don't free the pointer
*/
IPPAPI( const IppLibraryVersion*, ippacGetLibVersion, (void) )

#ifdef __cplusplus
}
#endif

#endif  /* #if !defined( __IPPAC_H__ ) || defined( _OWN_BLDPCS ) */

/* End of file */
