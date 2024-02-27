/* ////////////////////////////////// "ippj.h" ///////////////////////////////
//
//                  INTEL CORPORATION PROPRIETARY INFORMATION
//     This software is supplied under the terms of a license agreement or
//     nondisclosure agreement with Intel Corporation and may not be copied
//     or disclosed except in accordance with the terms of that agreement.
//       	Copyright(c) 1999-2003 Intel Corporation. All Rights Reserved.
//
//           	Intel(R) Integrated Performance Primitives
//                 	JPEG Processing (ippj)
//
*/

#if !defined( __IPPJ_H__ ) || defined( _OWN_BLDPCS )
#define __IPPJ_H__

#ifndef __IPPDEFS_H__
#include "ippdefs.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif


#if !defined( _OWN_BLDPCS )


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    IppiEncodeHuffmanSpec
//
//  Purpose:
//    Encoder Huffman table in fast-to-use format
//
//  Notes:
//
*/

struct EncodeHuffmanSpec;

typedef struct EncodeHuffmanSpec IppiEncodeHuffmanSpec;


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    IppiDecodeHuffmanSpec
//
//  Purpose:
//    Decoder Huffman table in fast-to-use format
//
//  Notes:
//
*/

struct DecodeHuffmanSpec;

typedef struct DecodeHuffmanSpec IppiDecodeHuffmanSpec;


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    IppiEncodeHuffmanState
//
//  Purpose:
//    Huffman encoder state
//
//  Notes:
//
*/

struct EncodeHuffmanState;

typedef struct EncodeHuffmanState IppiEncodeHuffmanState;


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    IppiDecodeHuffmanState
//
//  Purpose:
//    Huffman decoder state
//
//  Notes:
//
*/

struct DecodeHuffmanState;

typedef struct DecodeHuffmanState IppiDecodeHuffmanState;




/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    IppiEncodeState_JPEG2K
//
//  Purpose:
//    State structure for JPEG2000 entropy coder
//
//  Notes:
//
*/

struct iEncodeState_JPEG2K;

typedef struct iEncodeState_JPEG2K IppiEncodeState_JPEG2K;


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    IppiWTFilterFirst
//
//  Purpose:
//    Enumerator of relative positions of high-pass and low-pass filters
//    for JPEG 2000 wavelet transforms.
//
//  Notes:
//
*/

typedef enum
{
  ippWTFilterFirstLow,
  ippWTFilterFirstHigh

} IppiWTFilterFirst;


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    IppiWTSubband
//
//  Purpose:
//    Enumerator of wavelet transform subband
//    for JPEG 2000 entropy coder.
//
//    ippWTSubbandLxLy - low-pass filtered along x and y directions,
//    ippWTSubbandLxHy - low-pass filtered along x
//                          and high-pass filtered along y direction,
//    ippWTSubbandHxLy - high-pass filtered along x
//                          and low-pass filtered along y direction,
//    ippWTSubbandHxHy - high-pass filtered by x and y directions.
//
//  Notes:
//
*/

typedef enum
{
  ippWTSubbandLxLy,
  ippWTSubbandLxHy,
  ippWTSubbandHxLy,
  ippWTSubbandHxHy

} IppiWTSubband;


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    IppiMQTermination
//
//  Purpose:
//    Enumerator of MQ encoder termination types.
//    It used in JPEG2000 entropy coding functions.
//
//    ippMQTermSimple      - simple termination
//                           (some extra bytes can be placed),
//    ippMQTermNearOptimal - very good termination mode,
//    ippMQTermPredictable - termination mode used for
//                           predictable error resilience
//
//  Notes:
//
*/

typedef enum
{
  ippMQTermSimple,
  ippMQTermNearOptimal,
  ippMQTermPredictable

} IppiMQTermination;


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    IppiMQRateAppr
//
//  Purpose:
//    Enumerator of MQ padding approximation in rate-distortion estimation.
//    It used in JPEG2000 entropy coding functions.
//
//    ippMQRateApprGood - non-optimal approximation,
//                        rate can be overestimated a little.
//
//  Notes: only one approximation model implemented at the moment
//
*/

typedef enum
{
  ippMQRateApprGood

} IppiMQRateAppr;


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//
//  Purpose:
//    Enumerator of JPEG2000 entropy coder end decoder code style flags.
//
//  Notes:
//    IPP_JPEG2K_VERTICALLY_CAUSAL_CONTEXT
//          - vertically causal context will be formed,
//    IPP_JPEG2K_SELECTIVE_MQ_BYPASS
//          - selective MQ coding bypassing will be used (i.e. raw coding
//            will be used for some passes),
//    IPP_JPEG2K_TERMINATE_ON_EVERY_PASS
//          - terminate MQ coder on every pass,
//    IPP_JPEG2K_RESETCTX_ON_EVERY_PASS
//          - reset MQ coder context on every pass,
//    IPP_JPEG2K_USE_SEGMENTATION_SYMBOLS
//          - use segmentation symbol sequence for error resilence,
//    IPP_JPEG2K_LOSSLESS_MODE
//          - inform about the use of lossless wavelet transforms
//            in rate-distortion estimation,
//    IPP_JPEG2K_DEC_DO_NOT_CLEAR_CB
//          - do not clear codeblock data before decoding,
//    IPP_JPEG2K_DEC_DO_NOT_RESET_LOW_BITS
//          - do not reset low-order bits after decoding,
//    IPP_JPEG2K_DEC_DO_NOT_CLEAR_SFBUFFER
//          - do not clear buffer before decoding to keep previous
//            significance state information.
//    IPP_JPEG2K_DEC_CHECK_PRED_TERM
//          - check predictable termination during decoding,
//            if it is not right 'damage in codeblock' error
//            code will be generated.
//            This flag should be used only in predictable
//            termination mode.
//
*/

enum
{
  IPP_JPEG2K_VERTICALLY_CAUSAL_CONTEXT = 1,
  IPP_JPEG2K_SELECTIVE_MQ_BYPASS       = 1 << 1,
  IPP_JPEG2K_TERMINATE_ON_EVERY_PASS   = 1 << 2,
  IPP_JPEG2K_RESETCTX_ON_EVERY_PASS    = 1 << 3,
  IPP_JPEG2K_USE_SEGMENTATION_SYMBOLS  = 1 << 4,
  IPP_JPEG2K_LOSSLESS_MODE             = 1 << 5,

  IPP_JPEG2K_DEC_CONCEAL_ERRORS        = 1 << 16,
  IPP_JPEG2K_DEC_DO_NOT_CLEAR_CB       = 1 << 17,
  IPP_JPEG2K_DEC_DO_NOT_RESET_LOW_BITS = 1 << 18,
  IPP_JPEG2K_DEC_DO_NOT_CLEAR_SFBUFFER = 1 << 19,
  IPP_JPEG2K_DEC_CHECK_PRED_TERM       = 1 << 20
};


#endif /* _OWN_BLDPCS */




/* ///////////////////////////////////////////////////////////////////////////
//        Miscelenauos functions
/////////////////////////////////////////////////////////////////////////// */


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippjGetLibVersion
//
//  Purpose:
//    get the library version
//
//  Parameters:
//
//  Returns:
//    pointer to structure describing version of the ipps library
//
//  Notes:
//    don't free the pointer to IppLibraryVersion
*/

IPPAPI( const IppLibraryVersion*, ippjGetLibVersion, (void) )




/* ///////////////////////////////////////////////////////////////////////////
//        Huffman Encoding Functions (Baseline)
/////////////////////////////////////////////////////////////////////////// */


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiEncodeHuffmanRawTableInit_JPEG_8u
//
//  Purpose:
//    Build Huffman "raw" table from counted statistics of
//    Huffman symbols for 8-bit precision
//
//  Parameters:
//    pStatistics - pointer to array of 256 int,
//                  with the one entry for each of possible huffman symbol.
//    pListBits   - pointer to array of 16 bytes.
//    pListVals   - pointer to array of 256 bytes.
//
//  Returns:
//    IppStatus
//
//  Notes:
//    pListBits represents list of BITS and pListVals represent list
//    of HUFFVAL, as specified in ISO DIS 10918-1, Figure B.7
*/

IPPAPI(IppStatus, ippiEncodeHuffmanRawTableInit_JPEG_8u, (
  const int    pStatistics[256],
        Ipp8u* pListBits,
        Ipp8u* pListVals))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiEncodeHuffmanSpecGetBufSize_JPEG_8u
//
//  Purpose:
//    get size of IppjEncodeHuffmanSpec struct
//
//  Parameters:
//    size - where write size of buffer
//
//  Returns:
//    IppStatus
//
//  Notes:
//
*/

IPPAPI(IppStatus, ippiEncodeHuffmanSpecGetBufSize_JPEG_8u, (
  int* size))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiEncodeHuffmanSpecInit_JPEG_8u
//
//  Purpose:
//    Build Huffman table for encoder
//    in fast-to-use format from "raw" Huffman table
//
//  Parameters:
//    pListBits    - pointer to array of 16 bytes.
//    pListVals    - pointer to array of up to 256 bytes.
//    pEncHuffSpec - pointer to Huffman table to be initialized
//
//  Returns:
//    IppStatus
//
//  Notes:
//    pListBits represents list of BITS and pListVals represent list
//    of HUFFVAL, as specified in ISO DIS 10918-1, Figure B.7
*/

IPPAPI(IppStatus, ippiEncodeHuffmanSpecInit_JPEG_8u, (
  const Ipp8u*                 pListBits,
  const Ipp8u*                 pListVals,
        IppiEncodeHuffmanSpec* pEncHuffSpec))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiEncodeHuffmanSpecInitAlloc_JPEG_8u
//
//  Purpose:
//    Allocate memory and build Huffman table for encoder
//    in fast-to-use format from "raw" Huffman table
//
//  Parameters:
//    pListBits     - pointer to array of 16 bytes.
//    pListVals     - pointer to array of up to 256 bytes.
//    ppEncHuffSpec - pointer to pointer on Huffman table
//                    to be allocated and initialized
//
//  Returns:
//    IppStatus
//
//  Notes:
//    pListBits represents list of BITS and pListVals represent
//    list of HUFFVAL, as specified in ISO DIS 10918-1, Figure B.7
*/

IPPAPI(IppStatus, ippiEncodeHuffmanSpecInitAlloc_JPEG_8u, (
  const Ipp8u*                  pListBits,
  const Ipp8u*                  pListVals,
        IppiEncodeHuffmanSpec** ppEncHuffSpec))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiEncodeHuffmanSpecFree_JPEG_8u
//
//  Purpose:
//    Free memory for encoder Huffman table
//
//  Parameters:
//    pEncHuffSpec - pointer to Huffman table
//
//  Returns:
//    IppStatus
//
//  Notes:
//
*/

IPPAPI(IppStatus, ippiEncodeHuffmanSpecFree_JPEG_8u, (
  IppiEncodeHuffmanSpec*  pEncHuffSpec))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiEncodeHuffmanStateGetBufSize_JPEG_8u
//
//  Purpose:
//    get size of IppiEncoderHuffmanState struct
//
//  Parameters:
//    size - where write size of buffer
//
//  Returns:
//    IppStatus
//
//  Notes:
//
*/

IPPAPI(IppStatus, ippiEncodeHuffmanStateGetBufSize_JPEG_8u, (
  int*  size))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiEncodeHuffmanStateInit_JPEG_8u
//
//  Purpose:
//    Build EncHuffState struct for encoder
//
//  Parameters:
//    pEncHuffState - pointer to EncHuffState struct to be initialized
//
//  Returns:
//    IppStatus
//
//  Notes:
//
*/

IPPAPI(IppStatus, ippiEncodeHuffmanStateInit_JPEG_8u, (
  IppiEncodeHuffmanState*  pEncHuffState))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiEncodeHuffmanStateInitAlloc_JPEG_8u
//
//  Purpose:
//    Allocate memory and build EncHuffState struct for encoder
//
//  Parameters:
//    ppEncHuffState - pointer to pointer on EncHuffState struct
//                     to be allocated and initialized
//
//  Returns:
//    IppStatus
//
//  Notes:
//
*/

IPPAPI(IppStatus, ippiEncodeHuffmanStateInitAlloc_JPEG_8u, (
  IppiEncodeHuffmanState**  ppEncHuffState))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiEncodeHuffmanStateFree_JPEG_8u
//
//  Purpose:
//    Free memory for encoder EncHuffState struct
//
//  Parameters:
//    pEncHuffState - pointer to EncHuffState struct
//
//  Returns:
//    IppStatus
//
//  Notes:
//
*/

IPPAPI(IppStatus, ippiEncodeHuffmanStateFree_JPEG_8u, (
  IppiEncodeHuffmanState*  pEncHuffState))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiEncodeHuffman8x8_JPEG_16s1u_C1
//
//  Purpose:
//    Huffman encode 8x8 block of quantized DCT coefs
//
//  Parameters:
//    pSrc            pointer to 8x8 block of quantized DCT coefficients
//    pDst            pointer to output JPEG bitstream
//    dstLenBytes     bitstream length, in bytes
//    pDstCurrPos     pointer to current byte offset in buffer (in/out)
//    pLastDC         pointer to last DC coefficient from previous block of
//                    the same color component (in/out)
//    pEncHuffState   pointer to Huffman state struct
//    pDcTable        pointer to Huffman DC table
//    pAcTable        pointer to Huffman AC table
//    bFlushState     if non zero - only flush any pending bits
//                    from IppiEncodeHuffmanState to bitstream
//
//  Returns:
//    IppStatus
//
//  Notes:
//    set bFlushState to 1, after processing all MCUs in scan, to
//    flush any pending bits from IppiEncodeHuffmanState to bitstream
//    Encoding perform as defined in ISO DIS 10918-1.
//    Appendix A - Requirements and guidelines,
//    Annex F, F.1.2 - Baseline Huffman encoding procedures.
*/

IPPAPI(IppStatus, ippiEncodeHuffman8x8_JPEG_16s1u_C1, (
  const Ipp16s*                 pSrc,
        Ipp8u*                  pDst,
        int                     dstLenBytes,
        int*                    pDstCurrPos,
        Ipp16s*                 pLastDC,
  const IppiEncodeHuffmanSpec*  pDcTable,
  const IppiEncodeHuffmanSpec*  pAcTable,
        IppiEncodeHuffmanState* pEncHuffState,
        int                     bFlushState))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiEncodeHuffman8x8_Direct_JPEG_16s1u_C1
//
//  Purpose:
//    Huffman encode 8x8 block of quantized DCT coefs
//
//  Parameters:
//    pSrc            pointer to 8x8 block of quantized DCT coefficients
//    pDst            pointer to output JPEG bitstream
//    pDstBitsLen     bitstream length, in bits (in/out)
//    pLastDC         pointer to last DC coefficient from previous block of
//                    the same color component (in/out)
//    pDcTable        pointer to Huffman DC table
//    pAcTable        pointer to Huffman AC table
//
//  Returns:
//    IppStatus
//
//  Notes:
//    Encoding perform as defined in ISO DIS 10918-1.
//    Appendix A - Requirements and guidelines,
//    Annex F, F.1.2 - Baseline Huffman encoding procedures.
*/

IPPAPI(IppStatus, ippiEncodeHuffman8x8_Direct_JPEG_16s1u_C1, (
  const Ipp16s*                 pSrc,
        Ipp8u*                  pDst,
        int*                    pDstBitsLen,
        Ipp16s*                 pLastDC,
  const IppiEncodeHuffmanSpec*  pDcTable,
  const IppiEncodeHuffmanSpec*  pAcTable))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiGetHuffmanStatistics8x8_JPEG_16s_C1
//
//  Purpose:
//    Calculate statistics of huffman values
//
//  Parameters:
//    pSrc          - pointer to 8x8 block of quantized DCT coefficients
//    pDcStatistics - pointer to 256 elements array
//    pAcStatistics - pointer to 256 elements array
//    pLastDC       - pointer to DC coefficient from previous 8x8 block
//
//  Returns:
//    IppStatus
//
//  Notes:
//
*/

IPPAPI(IppStatus, ippiGetHuffmanStatistics8x8_JPEG_16s_C1, (
  const Ipp16s* pSrc,
        int     pDcStatistics[256],
        int     pAcStatistics[256],
        Ipp16s* pLastDC))




/* ///////////////////////////////////////////////////////////////////////////
//        Huffman Encoding Functions (Progressive)
/////////////////////////////////////////////////////////////////////////// */


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiGetHuffmanStatistics8x8_DCFirst_JPEG_16s_C1
//
//  Purpose:
//    Calculate statistics of huffman values, progressive coding,
//    first scan
//
//  Parameters:
//    pSrc          - pointer to 8x8 block of quantized DCT coefficients
//    pDcStatistics - pointer to 256 elements array
//    pLastDC       - pointer to DC coefficient from previous 8x8 block
//    Al            - successive approximation bit position low
//
//  Returns:
//    IppStatus
//
//  Notes:
//
*/

IPPAPI(IppStatus, ippiGetHuffmanStatistics8x8_DCFirst_JPEG_16s_C1, (
  const Ipp16s* pSrc,
        int     pDcStatistics[256],
        Ipp16s* pLastDC,
        int     Al))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiGetHuffmanStatistics8x8_ACFirst_JPEG_16s_C1
//
//  Purpose:
//    Calculate statistics of huffman values, progressive coding,
//    first scan
//
//  Parameters:
//    pSrc          - pointer to 8x8 block of quantized DCT coefficients
//    pAcStatistics - pointer to 256 elements array
//    Ss            - start of spectral selection
//    Se            - end of spectral selection
//    Al            - successive approximation bit position low
//    pEncHuffState - huffman encoder state
//    bFlushState   - set to 1, after processing all MCUs
//                    to flush EOB counter
//
//  Returns:
//    IppStatus
//
//  Notes:
//
*/

IPPAPI(IppStatus, ippiGetHuffmanStatistics8x8_ACFirst_JPEG_16s_C1, (
  const Ipp16s*                 pSrc,
        int                     pAcStatistics[256],
        int                     Ss,
        int                     Se,
        int                     Al,
        IppiEncodeHuffmanState* pEncHuffState,
        int                     bFlushState))




/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiGetHuffmanStatistics8x8_ACRefine_JPEG_16s_C1
//
//  Purpose:
//    Calculate statistics of huffman values, progressive coding,
//    next scans
//
//  Parameters:
//    pSrc          - pointer to 8x8 block of quantized DCT coefficients
//    pAcStatistics - pointer to 256 elements array
//    Ss            - start of spectral selection
//    Se            - end of spectral selection
//    Al            - successive approximation bit position low
//    pEncHuffState - huffman encoder state
//    bFlushState   - set to 1, after processing all MCUs
//                    to flush EOB counter
//
//  Returns:
//    IppStatus
//
//  Notes:
//
*/

IPPAPI(IppStatus, ippiGetHuffmanStatistics8x8_ACRefine_JPEG_16s_C1, (
  const Ipp16s*                 pSrc,
        int                     pAcStatistics[256],
        int                     Ss,
        int                     Se,
        int                     Al,
        IppiEncodeHuffmanState* pEncHuffState,
        int                     bFlushState))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiEncodeHuffman8x8_DCFirst_JPEG_16s1u_C1
//
//  Purpose:
//    huffman encode DC coefficient from 8x8 block of quantized
//    DCT coefficients. Progressive coding, first scan
//
//  Parameters:
//    pSrc          - pointer to 8x8 block of quantized DCT coefficients
//    pDst          - pointer to output bitstream
//    dstLenBytes   - length of bitstream buffer
//    pDstCurrPos   - corrent byte position in bitstream buffer
//    pLastDC       - pointer to DC coefficient from previous 8x8 block
//    Al            - successive approximation bit position low
//    pDcTable      - pointer to DC huffman table
//    pEncHuffState - pointer to encoder huffman state
//    bFlushState   - set to 1, after processing all MCUs
//                    to flush any pending bits from state
//
//  Returns:
//    IppStatus
//
//  Notes:
//    Encoding perform as defined in ISO DIS 10918-1.
//    Appendix A - Requirements and guidelines,
//    Annex G, G.1.2 - Progressive encoding procedures with Huffman.
*/

IPPAPI(IppStatus, ippiEncodeHuffman8x8_DCFirst_JPEG_16s1u_C1, (
  const Ipp16s*                 pSrc,
        Ipp8u*                  pDst,
        int                     dstLenBytes,
        int*                    pDstCurrPos,
        Ipp16s*                 pLastDC,
        int                     Al,
  const IppiEncodeHuffmanSpec*  pDcTable,
        IppiEncodeHuffmanState* pEncHuffState,
        int                     bFlushState))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiEncodeHuffman8x8_DCRefine_JPEG_16s1u_C1
//
//  Purpose:
//    huffman encode DC coefficient from 8x8 block of quantized
//    DCT coefficients. Progressive coding, next scans
//
//  Parameters:
//    pSrc          - pointer to 8x8 block of quantized DCT coefficients
//    pDst          - pointer to output bitstream
//    dstLenBytes   - length of bitstream
//    pDstCurrPos   - current byte position in bitstream
//    Al            - successive approximation bit position low
//    pEncHuffState - pointer to encoder huffman state
//    bFlushState   - set to 1, after processing all MCUs
//                    to flush any pending bits from state
//
//  Returns:
//    IppStatus
//
//  Notes:
//    Encoding perform as defined in ISO DIS 10918-1.
//    Appendix A - Requirements and guidelines,
//    Annex G, G.1.2 - Progressive encoding procedures with Huffman.
*/

IPPAPI(IppStatus, ippiEncodeHuffman8x8_DCRefine_JPEG_16s1u_C1, (
  const Ipp16s*                 pSrc,
        Ipp8u*                  pDst,
        int                     dstLenBytes,
        int*                    pDstCurrPos,
        int                     Al,
        IppiEncodeHuffmanState* pEncHuffState,
        int                     bFlushState))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiEncodeHuffman8x8_ACFirst_JPEG_16s1u_C1
//
//  Purpose:
//    huffman encode AC coefficients from 8x8 block of quantized
//    DCT coefficients. Progressive coding, first scan
//
//  Parameters:
//    pSrc          - pointer to 8x8 block of quantized DCT coefficients
//    pDst          - pointer to output bitstream buffer
//    dstLenBytes   - length of bitstream buffer
//    pDstCurrPos   - current byte position in bitstream buffer
//    Ss            - start of spectral selection
//    Se            - end of spectral selection
//    Al            - successive approximation bit position low
//    pAcTable      - pointer to encoder haffman AC table
//    pEncHuffState - pointer encoder huffman state
//    bFlushState   - set to 1, after processing all MCUs
//                    to flush any pending bits from state
//
//  Returns:
//    IppStatus
//
//  Notes:
//    Encoding perform as defined in ISO DIS 10918-1.
//    Appendix A - Requirements and guidelines,
//    Annex G, G.1.2 - Progressive encoding procedures with Huffman.
*/

IPPAPI(IppStatus, ippiEncodeHuffman8x8_ACFirst_JPEG_16s1u_C1, (
  const Ipp16s*                 pSrc,
        Ipp8u*                  pDst,
        int                     dstLenBytes,
        int*                    pDstCurrPos,
        int                     Ss,
        int                     Se,
        int                     Al,
  const IppiEncodeHuffmanSpec*  pAcTable,
        IppiEncodeHuffmanState* pEncHuffState,
        int                     bFlushState))




/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiEncodeHuffman8x8_ACRefine_JPEG_16s1u_C1
//
//  Purpose:
//    huffman encode AC coefficients from 8x8 block of quantized
//    DCT coefficients. Progressive coding, next scans
//
//  Parameters:
//    pSrc          - pointer to 8x8 block of quantized DCT coefficeints
//    pDst          - pointer to output bitstream buffer
//    dstLenBytes   - length of bitstream buffer
//    pDstCurrPos   - current byte position in bitstream buffer
//    Ss            - start of spectral selection
//    Se            - end of spectral selection
//    Al            - successive approximation bit position low
//    pAcTable      - pointer to encoder huffman AC table
//    pEncHuffState - pointer to encoder huffman state
//    bFlushState   - set to 1, after processing all MCUs
//                    to flush any pending bits from state
//
//  Returns:
//    IppStatus
//
//  Notes:
//    Encoding perform as defined in ISO DIS 10918-1.
//    Appendix A - Requirements and guidelines,
//    Annex G, G.1.2 - Progressive encoding procedures with Huffman.
*/

IPPAPI(IppStatus, ippiEncodeHuffman8x8_ACRefine_JPEG_16s1u_C1, (
  const Ipp16s*                 pSrc,
        Ipp8u*                  pDst,
        int                     dstLenBytes,
        int*                    pDstCurrPos,
        int                     Ss,
        int                     Se,
        int                     Al,
  const IppiEncodeHuffmanSpec*  pAcTable,
        IppiEncodeHuffmanState* pEncHuffState,
        int                     bFlushState))




/* ///////////////////////////////////////////////////////////////////////////
//        Huffman Decoding Functions
/////////////////////////////////////////////////////////////////////////// */


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiDecodeHuffmanSpecGetBufSize_JPEG_8u
//
//  Purpose:
//    get size of IppiDecodeHuffmanSpec struct
//
//  Parameters:
//    size - where write size of buffer
//
//  Returns:
//    IppStatus
//
//  Notes:
//
*/

IPPAPI(IppStatus, ippiDecodeHuffmanSpecGetBufSize_JPEG_8u, (
  int*  size))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiDecodeHuffmanSpecInit_JPEG_8u
//
//  Purpose:
//    Build Huffman table for decoder in fast-to-use format
//    from "raw" Huffman table
//
//  Parameters:
//    pListBits    - pointer to array of 16 bytes.
//    pListVals    - pointer to array of up to 256 bytes.
//    pDecHuffSpec - pointer to Huffman table to be initialized
//
//  Returns:
//    IppStatus
//
//  Notes:
//    pListBits represents list of BITS and pListVals represent
//    list of HUFFVAL, as specified in ISO DIS 10918-1, Figure B.7
*/

IPPAPI(IppStatus, ippiDecodeHuffmanSpecInit_JPEG_8u, (
  const Ipp8u*                  pListBits,
  const Ipp8u*                  pListVals,
        IppiDecodeHuffmanSpec*  pDecHuffSpec))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiDecodeHuffmanSpecInitAlloc_JPEG_8u
//
//  Purpose:
//    Build Huffman table for decoder in fast-to-use format
//    from raw Huffman table
//
//  Parameters:
//    pListBits     - pointer to array of 16 bytes.
//    pListVals     - pointer to array of up to 256 bytes.
//    ppDecHuffSpec - pointer to pointer on Huffman table
//                    to be allocated and initialized
//
//  Returns:
//    IppStatus
//
//  Notes:
//    pListBits represents list of BITS and pListVals represent
//    list of HUFFVAL, as specified in ISO DIS 10918-1, Figure B.7
*/

IPPAPI(IppStatus, ippiDecodeHuffmanSpecInitAlloc_JPEG_8u, (
  const Ipp8u*                   pListBits,
  const Ipp8u*                   pListVals,
        IppiDecodeHuffmanSpec**  ppDecHuffSpec))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiDecodeHuffmanSpecFree_JPEG_8u
//
//  Purpose:
//    Free memory for decoder Huffman table
//
//  Parameters:
//    pDecHuffSpec - pointer to Huffman table
//
//  Returns:
//    IppStatus
//
//  Notes:
//
*/

IPPAPI(IppStatus, ippiDecodeHuffmanSpecFree_JPEG_8u, (
  IppiDecodeHuffmanSpec*  pDecHuffSpec))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiDecodeHuffmanStateGetBufSize_JPEG_8u
//
//  Purpose:
//    get size of IppiDecodeHuffmanState struct
//
//  Parameters:
//    size - where write size of buffer
//
//  Returns:
//    IppStatus
//
//  Notes:
//
*/

IPPAPI(IppStatus, ippiDecodeHuffmanStateGetBufSize_JPEG_8u, (
  int*  size))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiDecodeHuffmanStateInit_JPEG_8u
//
//  Purpose:
//    Build IppiDecodeHuffmanState struct for decoder
//
//  Parameters:
//    pDecHuffState - pointer to IppiDecodeHuffmanState struct
//                    to be initialized
//
//  Returns:
//    IppStatus
//
//  Notes:
//
*/

IPPAPI(IppStatus, ippiDecodeHuffmanStateInit_JPEG_8u, (
  IppiDecodeHuffmanState*  pDecHuffState))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiDecodeHuffmanStateInitAlloc_JPEG_8u
//
//  Purpose:
//    Allocate memory and build DecHuffState struct for encoder
//
//  Parameters:
//    ppDecHuffState - pointer to pointer on EncHuffState struct
//                     to be allocated and initialized
//
//  Returns:
//    IppStatus
//
//  Notes:
//
*/

IPPAPI(IppStatus, ippiDecodeHuffmanStateInitAlloc_JPEG_8u, (
  IppiDecodeHuffmanState**  ppDecHuffState))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiDecodeHuffmanStateFree_JPEG_8u
//
//  Purpose:
//    Free memory for decoder DecHuffState struct
//
//  Parameters:
//    pDecHuffState - pointer to IppiDecodeHuffmanState struct
//
//  Returns:
//    IppStatus
//
//  Notes:
//
*/

IPPAPI(IppStatus, ippiDecodeHuffmanStateFree_JPEG_8u, (
  IppiDecodeHuffmanState*  pDecHuffState))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiDecodeHuffman8x8_JPEG_1u16s_C1
//
//  Purpose:
//    Huffman decode 8x8 block of quantized DCT coefficients
//
//  Parameters:
//    pSrc          pointer to input JPEG bitstream
//    srcLenBytes   bitstream length, in bytes
//    pSrcCurrPos   pointer to current byte offset in buffer (in/out)
//    pDst          pointer to output 8x8 block of quantized DCT coefficients
//    pLastDC       pointer to last DC coefficients from preivious block
//                  of the same color component
//    pMarker       where to store marker which can be found
//    pDcTable      pointer to huffman DC table
//    pAcTable      pointer to huffman AC table
//    pDecHuffState pointer to Huffman state struct
//
//  Returns:
//    IppStatus
//
//  Notes:
//    Decoding perform as specified in ISO DIS 10918-1,
//    Appendix A - Requirements and guidelines,
//    Annex F, F.2.2 - Baseline Huffman Decoding procedures
*/

IPPAPI(IppStatus, ippiDecodeHuffman8x8_JPEG_1u16s_C1, (
  const Ipp8u*                  pSrc,
        int                     srcLenBytes,
        int*                    pSrcCurrPos,
        Ipp16s*                 pDst,
        Ipp16s*                 pLastDC,
        int*                    pMarker,
  const IppiDecodeHuffmanSpec*  pDcTable,
  const IppiDecodeHuffmanSpec*  pAcTable,
        IppiDecodeHuffmanState* pDecHuffState))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiDecodeHuffman8x8_Direct_JPEG_1u16s_C1
//
//  Description:
//    Huffman decode 8x8 block of quantized DCT coefficients
//
//  Parameters:
//    pSrc                    pointer to input JPEG bitstream
//    pSrcBitsLen             the number of bits in bitstream (in/out)
//    pDst                    pointer to output 8x8 block of quantized
//                            DCT coefficients
//    pLastDC                 pointer to last DC coefficients from preivious
//                            block of the same color component
//    pMarker                 where to store marker which can be found
//    pPrefetchedBits         prefetch buffer which contain the bits decoded
//                            in the last time
//    pNumValidPrefetchedBits number of valid bits in prefetch buffer
//    pDcTable                pointer to huffman DC table
//    pAcTable                pointer to huffman AC table
//
//  Note:
//    1. pDCPred shall be 0 in initial or after each restart interval
//    2. pMarker shall be 0 in initial or after it was processed
//    3. pNumValidPrefetchedBits shall be 0 in following case
//          1) Initial.
//          2) After each restart interval.
//          3) After each marker.
//
//  Returns:
//    IppStatus
*/

IPPAPI(IppStatus, ippiDecodeHuffman8x8_Direct_JPEG_1u16s_C1, (
  const Ipp8u*                 pSrc,
        int*                   pSrcBitsLen,
        Ipp16s*                pDst,
        Ipp16s*                pLastDC,
        int*                   pMarker,
        Ipp32u*                pPrefetchedBits,
        int*                   pNumValidPrefetchedBits,
  const IppiDecodeHuffmanSpec* pDcTable,
  const IppiDecodeHuffmanSpec* pAcTable))


/* ///////////////////////////////////////////////////////////////////////////
//        Huffman Encoding Functions (Progressive)
/////////////////////////////////////////////////////////////////////////// */


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiDecodeHuffman8x8_DCFirst_JPEG_1u16s_C1
//
//  Purpose:
//    Huffman decode DC coefficient of 8x8 block of quantized DCT coefficients
//
//  Parameters:
//    pSrc          pointer to input JPEG bitstream
//    srcLenBytes   bitstream length, in bytes
//    pSrcCurrPos   pointer to current byte offset in buffer (in/out)
//    pDst          pointer to output 8x8 block of quantized DCT coefficients
//    pLastDC       pointer to last DC coefficients from preivious block
//                  of the same color component
//    pMarker       where to store JPEG marker
//    Al            Approximation bit position low
//    pDcTable      pointer to huffman DC table
//    pDecHuffState pointer to Huffman state struct
//
//  Returns:
//    IppStatus
//
//  Notes:
//    Decoding perform as defined in ISO DIS 10918-1.
//    Appendix A - Requirements and guidelines,
//    Annex G, G.2 - Progressive decoding of the DCT.
*/

IPPAPI(IppStatus, ippiDecodeHuffman8x8_DCFirst_JPEG_1u16s_C1, (
  const Ipp8u*                  pSrc,
        int                     srcLenBytes,
        int*                    pSrcCurrPos,
        Ipp16s*                 pDst,
        Ipp16s*                 pLastDC,
        int*                    pMarker,
        int                     Al,
  const IppiDecodeHuffmanSpec*  pDcTable,
        IppiDecodeHuffmanState* pDecHuffState))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiDecodeHuffman8x8_DCRefine_JPEG_1u16s_C1
//
//  Purpose:
//    Refine DC coefficient of 8x8 block of quantized DCT coefficients
//
//  Parameters:
//    pSrc          pointer to input JPEG bitstream
//    srcLenBytes   bitstream length, in bytes
//    pSrcCurrPos   pointer to current byte offset in buffer (in/out)
//    pDst          pointer to output 8x8 block of quantized DCT coefficients
//    pMarker       where to store JPEG marker
//    Al            Approximation bit position low
//    pDecHuffState pointer to Huffman state struct
//
//  Returns:
//    IppStatus
//
//  Notes:
//    Decoding perform as defined in ISO DIS 10918-1.
//    Appendix A - Requirements and guidelines,
//    Annex G, G.2 - Progressive decoding of the DCT.
*/

IPPAPI(IppStatus, ippiDecodeHuffman8x8_DCRefine_JPEG_1u16s_C1, (
  const Ipp8u*                   pSrc,
        int                      srcLenBytes,
        int*                     pSrcCurrPos,
        Ipp16s*                  pDst,
        int*                     pMarker,
        int                      Al,
        IppiDecodeHuffmanState*  pDecHuffState))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiDecodeHuffman8x8_ACFirst_JPEG_1u16s_C1
//
//  Purpose:
//    Huffman decode AC coefficient of 8x8 block of quantized DCT coefficients
//
//  Parameters:
//    pSrc          pointer to input JPEG bitstream
//    srcLenBytes   bitstream length, in bytes
//    pSrcCurrPos   pointer to current byte offset in buffer (in/out)
//    pDst          pointer to output 8x8 block of quantized DCT coefficients
//    pMarker       where to store JPEG marker
//    Ss            spectral selection start
//    Se            spectral selection end
//    Al            Approximation bit position low
//    pAcTable      pointer to huffman AC table
//    pDecHuffState pointer to Huffman state struct
//
//  Returns:
//    IppStatus
//
//  Notes:
//    Decoding perform as defined in ISO DIS 10918-1.
//    Appendix A - Requirements and guidelines,
//    Annex G, G.2 - Progressive decoding of the DCT.
*/

IPPAPI(IppStatus, ippiDecodeHuffman8x8_ACFirst_JPEG_1u16s_C1, (
  const Ipp8u*                  pSrc,
        int                     srcLenBytes,
        int*                    pSrcCurrPos,
        Ipp16s*                 pDst,
        int*                    pMarker,
        int                     Ss,
        int                     Se,
        int                     Al,
  const IppiDecodeHuffmanSpec*  pAcTable,
        IppiDecodeHuffmanState* pDecHuffState))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiDecodeHuffman8x8_ACRefine_JPEG_1u16s_C1
//
//  Purpose:
//    Refine AC coefficients of 8x8 block of quantized DCT coefficients
//
//  Parameters:
//    pSrc          pointer to input JPEG bitstream
//    srcLenBytes   bitstream length, in bytes
//    pSrcCurrPos   pointer to current byte offset in buffer (in/out)
//    pDst          pointer to output 8x8 block of quantized DCT coefficients
//    pMarker       where to store JPEG marker
//    Ss            spectral selection start
//    Se            spectral selection end
//    Al            Approximation bit position low
//    pAcTable      Huffman AC table
//    pDecHuffState pointer to Huffman state struct
//
//  Returns:
//    IppStatus
//
//  Notes:
//    Decoding perform as defined in ISO DIS 10918-1.
//    Appendix A - Requirements and guidelines,
//    Annex G, G.2 - Progressive decoding of the DCT.
*/

IPPAPI(IppStatus, ippiDecodeHuffman8x8_ACRefine_JPEG_1u16s_C1, (
  const Ipp8u*                  pSrc,
        int                     srcLenBytes,
        int*                    pSrcCurrPos,
        Ipp16s*                 pDst,
        int*                    pMarker,
        int                     Ss,
        int                     Se,
        int                     Al,
  const IppiDecodeHuffmanSpec*  pAcTable,
        IppiDecodeHuffmanState* pDecHuffState))




/* ///////////////////////////////////////////////////////////////////////////
//        Quantization Functions for encoder
/////////////////////////////////////////////////////////////////////////// */


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiQuantFwdRawTableInit_JPEG_8u
//
//  Purpose:
//    Adjust raw quantization table according quality factor
//
//  Parameters:
//    pQuantRawTable - pointer to "raw" Quantization table
//    qualityFactor - JPEG quality factor (valid range 1...100)
//
//  Returns:
//    IppStatus
//
//  Notes:
//    "raw" quantization table is array of 64 bytes (Q0..Q63), as specified
//    in ISO DIS 10918-1, Figure B.6
*/

IPPAPI(IppStatus, ippiQuantFwdRawTableInit_JPEG_8u, (
  Ipp8u* pQuantRawTable,
  int    qualityFactor))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiQuantFwdTableInit_JPEG_8u16u
//
//  Purpose:
//    Build 8-bit precision Quantization table for encoder
//    in fast-to-use format from "raw" Quantization table
//
//  Parameters:
//    pQuantRawTable - pointer to "raw" Quantization table
//    pQuantFwdTable - pointer to Quantization table to be initialized
//
//  Returns:
//    IppStatus
//
//  Notes:
//    "raw" quantization table is array of 64 bytes (Q0..Q63), as specified
//    in ISO DIS 10918-1, Figure B.6 in zigzag order
*/

IPPAPI(IppStatus, ippiQuantFwdTableInit_JPEG_8u16u, (
  const Ipp8u*  pQuantRawTable,
        Ipp16u* pQuantFwdTable))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiQuantFwd8x8_JPEG_16s_C1I
//
//  Purpose:
//    quantize 8x8 block of DCT coefficients
//
//  Parameters:
//    pSrcDst        - pointer to 8x8 block of DCT coefs
//    pQuantFwdTable - pointer to Quantization table
//
//  Returns:
//    IppStatus
//
//  Notes:
//    Quantization is defined in ISO DIS 10918-1,
//    Appendix A - Requrements and guidelines,
//    Annex A, A.3.4 DCT coefficient quantization and dequantization.
*/

IPPAPI(IppStatus, ippiQuantFwd8x8_JPEG_16s_C1I, (
        Ipp16s* pSrcDst,
  const Ipp16u* pQuantFwdTable))




/* ///////////////////////////////////////////////////////////////////////////
//        Quantization Functions for decoder
/////////////////////////////////////////////////////////////////////////// */


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiQuantInvTableInit_JPEG_8u16u
//
//  Purpose:
//    Build Quantization table for decoder in fast-to-use format
//    from "raw" Quantization table
//
//  Parameters:
//    pQuantRawTable - pointer to "raw" Quantization table
//    pQuantInvTable - pointer to Quantization table to be initialized
//
//  Returns:
//    IppStatus
//
//  Notes:
//    "raw" quantization table is array of 64 bytes (Q0..Q63), as specified
//    in ISO DIS 10918-1, Figure B.6 in zigzag order
*/

IPPAPI(IppStatus, ippiQuantInvTableInit_JPEG_8u16u, (
  const Ipp8u*  pQuantRawTable,
        Ipp16u* pQuantInvTable))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiQuantInv8x8_JPEG_16s_C1I
//
//  Purpose:
//    dequantize 8x8 block of DCT coefficients
//
//  Parameters:
//    pSrcDst        - pointer to 8x8 block of DCT coefficients
//    pQuantInvTable - pointer to Quantization table
//
//  Returns:
//    IppStatus
//
//  Notes:
//    Dequantization is defined in ISO DIS 10918-1,
//    Appendix A - Requrements and guidelines,
//    Annex A, A.3.4 DCT coefficient quantization and dequantization.
*/

IPPAPI(IppStatus, ippiQuantInv8x8_JPEG_16s_C1I, (
        Ipp16s* pSrcDst,
  const Ipp16u* pQuantInvTable))




/* ///////////////////////////////////////////////////////////////////////////
//        Functions for color conversion for encoder
/////////////////////////////////////////////////////////////////////////// */


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiRGBToY_JPEG_8u_P3C1R
//
//  Purpose:
//    RGB to Y color conversion
//
//  Parameter:
//    pSrcRGB   pointer to pointers to the input data.
//              pSrc[0] is pointer to RR..RR plane
//              pSrc[1] is pointer to GG..GG plane, and
//              pSrc[2] is pointer to BB..BB plane
//    srcStep   line offset in input data
//    pDstY     pointer to the output data YY..YY
//    dstStep   line offset in output data
//    roiSize   ROI size
//
//  Returns:
//    IppStatus
//
//  Notes:
//    Y = 0.299*R + 0.587*G + 0.114*B
*/

IPPAPI(IppStatus, ippiRGBToY_JPEG_8u_P3C1R, (
  const Ipp8u*   pSrcRGB[3],
        int      srcStep,
        Ipp8u*   pDstY,
        int      dstStep,
        IppiSize roiSize))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiRGBToY_JPEG_8u_C3C1R
//
//  Purpose:
//    RGB to Y color conversion
//
//  Parameter:
//    pSrcRGB   pointer to the input data RGBRGB...RGBRGB
//    srcStep   line offset in input data
//    pDstY     pointer to the output data YY..YY
//    dstStep   line offset in output data
//    roiSize   ROI size
//
//  Returns:
//    IppStatus
//
//  Notes:
//    Y = 0.299*R + 0.587*G + 0.114*B
//
*/

IPPAPI(IppStatus, ippiRGBToY_JPEG_8u_C3C1R, (
  const Ipp8u*   pSrcRGB,
        int      srcStep,
        Ipp8u*   pDstY,
        int      dstStep,
        IppiSize roiSize))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiBGRToY_JPEG_8u_C3C1R
//
//  Purpose:
//    BGR to Y color conversion
//
//  Parameter:
//    pSrcBGR   pointer to the input data BGRBGR...BGRBGR
//    srcStep   line offset in input data
//    pDstY     pointer to the output data YY..YY
//    dstStep   line offset in output data
//    roiSize   ROI size
//
//  Returns:
//    IppStatus
//
//  Notes:
//    Y = 0.299*R + 0.587*G + 0.114*B
//
*/

IPPAPI(IppStatus, ippiBGRToY_JPEG_8u_C3C1R, (
  const Ipp8u*   pSrcBGR,
        int      srcStep,
        Ipp8u*   pDstY,
        int      dstStep,
        IppiSize roiSize))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiRGBToYCbCr_JPEG_8u_P3R
//
//  Purpose:
//    RGB to YCbCr color conversion
//
//  Parameter:
//    pSrcRGB   pointer to pointers to the input data.
//              pSrc[0] is pointer to RR..RR plane
//              pSrc[1] is pointer to GG..GG plane, and
//              pSrc[2] is pointer to BB..BB plane
//    srcStep   line offset in input data
//    pDstYCbCr pointer to pointers to the output data.
//              pDst[0] is pointer to YY..YY plane
//              pDst[1] is pointer to CbCb..CbCb plane, and
//              pDst[2] is pointer to CrCr..CrCr plane
//    dstStep   line offset in output data
//    roiSize   ROI size
//
//  Returns:
//    IppStatus
//
//  Notes:
//    Y  =  0.29900*R + 0.58700*G + 0.11400*B
//    Cb = -0.16874*R - 0.33126*G + 0.50000*B + 128
//    Cr =  0.50000*R - 0.41869*G - 0.08131*B + 128
*/

IPPAPI(IppStatus, ippiRGBToYCbCr_JPEG_8u_P3R, (
  const Ipp8u*   pSrcRGB[3],
        int      srcStep,
        Ipp8u*   pDstYCbCr[3],
        int      dstStep,
        IppiSize roiSize))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiRGBToYCbCr_JPEG_8u_C3P3R
//
//  Purpose:
//    RGB to YCbCr color conversion
//
//  Parameter:
//    pSrcRGB   pointer to input data RGBRGB..RGBRGB
//    srcStep   line offset in input data
//    pDstYCbCr pointer to pointers to the output data.
//                pDstYCbCr[0] is pointer to YY..YY plane
//                pDstYCbCr[1] is pointer to CbCb..CbCb plane, and
//                pDstYCbCr[2] is pointer to CrCr..CrCr plane
//    dstStep   line offset in output data
//    roiSize   ROI size
//
//  Returns:
//    IppStatus
//
//  Notes:
//    Y  =  0.29900*R + 0.58700*G + 0.11400*B
//    Cb = -0.16874*R - 0.33126*G + 0.50000*B + 128
//    Cr =  0.50000*R - 0.41869*G - 0.08131*B + 128
*/

IPPAPI(IppStatus, ippiRGBToYCbCr_JPEG_8u_C3P3R, (
  const Ipp8u*   pSrcRGB,
        int      srcStep,
        Ipp8u*   pDstYCbCr[3],
        int      dstStep,
        IppiSize roiSize))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiBGRToYCbCr_JPEG_8u_C3P3R
//
//  Purpose:
//    BGR to YCbCr color conversion
//
//  Parameter:
//    pSrcBGR   pointer to input data BGRBGR..BGRBGR
//    srcStep   line offset in input data
//    pDstYCbCr pointer to pointers to the output data.
//                pDstYCbCr[0] is pointer to YY..YY plane
//                pDstYCbCr[1] is pointer to CbCb..CbCb plane, and
//                pDstYCbCr[2] is pointer to CrCr..CrCr plane
//    dstStep   line offset in output data
//    roiSize   ROI size
//
//  Returns:
//    IppStatus
//
//  Notes:
//    the color conversion equations:
//      Y  =  0.29900*R + 0.58700*G + 0.11400*B
//      Cb = -0.16874*R - 0.33126*G + 0.50000*B + 128.0
//      Cr =  0.50000*R - 0.41869*G - 0.08131*B + 128.0
*/

IPPAPI(IppStatus, ippiBGRToYCbCr_JPEG_8u_C3P3R, (
  const Ipp8u*   pSrcBGR,
        int      srcStep,
        Ipp8u*   pDstYCbCr[3],
        int      dstStep,
        IppiSize roiSize))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiCMYKToYCCK_JPEG_8u_P4R
//
//  Purpose:
//    CMYK to YCCK color conversion
//
//  Parameter:
//    pSrcCMYK  pointer to pointers to the input data.
//              pSrc[0] is pointer to CC..CC plane
//              pSrc[1] is pointer to MM..MM plane, and
//              pSrc[2] is pointer to YY..YY plane
//              pSrc[3] is pointer to KK..KK plane
//    srcStep   line offset in input data
//    pDstYCCK  pointer to pointers to output arrays
//              pDst[0] is pointer to YY..YY plane
//              pDst[1] is pointer to CC..CC plane, and
//              pDst[2] is pointer to CC..CC plane
//              pDst[3] is pointer to KK..KK plane
//    dstStep   line offset in output data
//    roiSize   ROI size
//
//  Returns:
//    IppStatus
//
//  Notes:
//    This version handles Adobe-style CMYK->YCCK conversion,
//    where R = 1-C, G = 1-M, and B = 1-Y are converted to YCbCr,
//    while K (black) channel is unchanged.
*/

IPPAPI(IppStatus, ippiCMYKToYCCK_JPEG_8u_P4R, (
  const Ipp8u*   pSrcCMYK[4],
        int      srcStep,
        Ipp8u*   pDstYCCK[4],
        int      dstStep,
        IppiSize roiSize))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiCMYKToYCCK_JPEG_8u_C4P4R
//
//  Purpose:
//    CMYK to YCCK color conversion
//
//  Parameter:
//    pSrcCMYK  pointer to input data CMYKCMYK..CMYKCMYK
//    srcStep   line offset in input data
//    pDstYCCK  pointer to pointers to output arrays
//              pDst[0] is pointer to YY..YY plane
//              pDst[1] is pointer to CC..CC plane, and
//              pDst[2] is pointer to CC..CC plane
//              pDst[3] is pointer to KK..KK plane
//    dstStep   line offset in output data
//    roiSize   ROI size
//
//  Returns:
//    IppStatus
//
//  Notes:
//    This version handles Adobe-style CMYK->YCCK conversion,
//    where R = 1-C, G = 1-M, and B = 1-Y are converted to YCbCr,
//    while K (black) channel is unchanged.
*/

IPPAPI(IppStatus, ippiCMYKToYCCK_JPEG_8u_C4P4R, (
  const Ipp8u*   pSrcCMYK,
        int      srcStep,
        Ipp8u*   pDstYCCK[4],
        int      dstStep,
        IppiSize roiSize))




/* ///////////////////////////////////////////////////////////////////////////
//        Shift level functions for encoder/decoder
/////////////////////////////////////////////////////////////////////////// */


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiSub128_JPEG_8u16s_C1R
//
//  Purpose:
//    convert image data from unsigned 8-bit integer to signed 16-bit
//
//  Parameter:
//    pSrc      pointer to input data
//    srcStep   line offset in input data
//    pDst      pointer to output data
//    dstStep   line offset in output data
//    roiSize   ROI size
//
//  Returns:
//    IppStatus
//
//  Notes:
//    Level Shift is defined in ISO DIS 10918-1,
//    Appendix A - Requrements and guidelines, Annex A, A.3.1 - Level Shift.
*/

IPPAPI(IppStatus, ippiSub128_JPEG_8u16s_C1R, (
  const Ipp8u*   pSrc,
        int      srcStep,
        Ipp16s*  pDst,
        int      dstStep,
        IppiSize roiSize))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiAdd128_JPEG_16s8u_C1R
//
//  Purpose:
//    convert image data from signed 16-bit to unsigned 8-bit integer
//
//  Parameter:
//    pSrc      pointer to input data
//    srcStep   line offset in input data
//    pDst      pointer to output data
//    dstStep   line offset in output data
//    roiSize   ROI size
//
//  Returns:
//    IppStatus
//
//  Notes:
//    Level Shift is defined in ISO DIS 10918-1,
//    Appendix A - Requrements and guidelines, Annex A, A.3.1 - Level Shift.
*/

IPPAPI(IppStatus, ippiAdd128_JPEG_16s8u_C1R, (
  const Ipp16s*  pSrc,
        int      srcStep,
        Ipp8u*   pDst,
        int      dstStep,
        IppiSize roiSize))




/* ///////////////////////////////////////////////////////////////////////////
//        Downsampling functions for encoder
/////////////////////////////////////////////////////////////////////////// */


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiSampleDownH2V1_JPEG_8u_C1R
//
//  Purpose:
//    Sample down by horizontal 2:1
//
//  Parameters:
//    pSrc    - pointer to source data to be sampled down
//    srcStep - line offset in input data
//    srcSize - ROI size
//    pDst    - pointer to sampled down output data
//    dstStep - line offset in input data
//    dstSize - ROI size
//
//  Returns:
//    IppStatus
//
//  Notes:
//
*/

IPPAPI(IppStatus, ippiSampleDownH2V1_JPEG_8u_C1R, (
  const Ipp8u*   pSrc,
        int      srcStep,
        IppiSize srcRoiSize,
        Ipp8u*   pDst,
        int      dstStep,
        IppiSize dstRoiSize))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiSampleDownH2V2_JPEG_8u_C1R
//
//  Purpose:
//    Sample down by horizontal 2:1 and vertical 2:1
//
//  Parameters:
//    pSrc    - pointer to source data to be sampled down
//    srcStep - line offset in input data
//    srcSize - ROI size
//    pDst    - pointer to sampled down output data
//    dstStep - line offset in input data
//    dstSize - ROI size
//
//  Returns:
//    IppStatus
//
//  Notes:
//
*/

IPPAPI(IppStatus, ippiSampleDownH2V2_JPEG_8u_C1R, (
  const Ipp8u*   pSrc,
        int      srcStep,
        IppiSize srcRoiSize,
        Ipp8u*   pDst,
        int      dstStep,
        IppiSize dstRoiSize))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiSampleDownRowH2V1_Box_JPEG_8u_C1
//
//  Purpose:
//    Sample down by horizontal 2:1
//
//  Parameters:
//    pSrc     - pointer to source row
//    srcWidth - width of source row
//    pDst     - pointer to sampled down output row
//
//  Returns:
//    IppStatus
//
//  Notes:
//    Downsampling is performed as simple "Box" filter
*/

IPPAPI(IppStatus, ippiSampleDownRowH2V1_Box_JPEG_8u_C1, (
  const Ipp8u*   pSrc,
        int      srcWidth,
        Ipp8u*   pDst))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiSampleDownRowH2V2_Box_JPEG_8u_C1
//
//  Purpose:
//    Sample down by horizontal 2:1 and vertical 2:1
//
//  Parameters:
//    pSrc1    - pointer to the source row
//    pSrc2    - pointer to the next(adjacent) row
//    srcWidth - width of source rows
//    pDst     - pointer to sampled down output row
//
//  Returns:
//    IppStatus
//
//  Notes:
//    Downsampling is performed as simple "Box" filter
*/

IPPAPI(IppStatus, ippiSampleDownRowH2V2_Box_JPEG_8u_C1, (
  const Ipp8u*   pSrc1,
  const Ipp8u*   pSrc2,
        int      srcWidth,
        Ipp8u*   pDst))




/* ///////////////////////////////////////////////////////////////////////////
//        Upsampling functions for decoder
/////////////////////////////////////////////////////////////////////////// */


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiSampleUpH2V1_JPEG_8u_C1R
//
//  Purpose:
//    sample up horizontally 1:2
//
//  Parameters:
//    pSrc    - pointer to source data to be sampled up
//    srcStep - line offset in input data
//    srcSize - ROI size
//    pDst    - pointer to sampled up output data
//    dstStep - line offset in input data
//    dstSize - ROI size
//
//  Returns:
//    IppStatus
//
//  Notes:
//    Triangle filter used there (3/4 * nearer pixel + 1/4 * further pixel),
//    so we need leftmost and rightmost values outside the data boundary.
*/

IPPAPI(IppStatus, ippiSampleUpH2V1_JPEG_8u_C1R, (
  const Ipp8u*   pSrc,
        int      srcStep,
        IppiSize srcRoiSize,
        Ipp8u*   pDst,
        int      dstStep,
        IppiSize dstRoiSize))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiSampleUpH2V2_JPEG_8u_C1R
//
//  Purpose:
//    sample up horizontally 1:2 and vertically 1:2
//
//  Parameters:
//    pSrc    - pointer to source data to be sampled up
//    srcStep - line offset in input data
//    srcSize - ROI size
//    pDst    - pointer to sampled up output data
//    dstStep - line offset in input data
//    dstSize - ROI size
//
//  Returns:
//    IppStatus
//
//  Notes:
//    Triangle filter used there (3/4 * nearer pixel + 1/4 * further pixel),
//    so we need leftmost and rightmost, bottommost and topmost values
//    outside the data boundary.
*/

IPPAPI(IppStatus, ippiSampleUpH2V2_JPEG_8u_C1R, (
  const Ipp8u*   pSrc,
        int      srcStep,
        IppiSize srcRoiSize,
        Ipp8u*   pDst,
        int      dstStep,
        IppiSize dstRoiSize))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiSampleUpRowH2V1_Triangle_JPEG_8u_C1
//
//  Purpose:
//    sample up horizontally 1:2
//
//  Parameters:
//    pSrc     - pointer to the source row
//    srcWidth - width of source row
//    pDst     - pointer to sampled up output row
//
//  Returns:
//    IppStatus
//
//  Notes:
//    Triangle filter used there (3/4 * nearer pixel + 1/4 * further pixel)
*/

IPPAPI(IppStatus, ippiSampleUpRowH2V1_Triangle_JPEG_8u_C1, (
  const Ipp8u*   pSrc,
        int      srcWidth,
        Ipp8u*   pDst))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiSampleUpRowH2V2_Triangle_JPEG_8u_C1
//
//  Purpose:
//    sample up horizontally 1:2 and vertically 1:2
//
//  Parameters:
//    pSrc1    - pointer to the source row
//    pSrc2    - pointer to the next(adjacent) source row
//    srcWidth - width of source rows
//    pDst     - pointer to sampled up output row
//
//  Returns:
//    IppStatus
//
//  Notes:
//    Triangle filter used there (3/4 * nearer pixel + 1/4 * further pixel),
*/

IPPAPI(IppStatus, ippiSampleUpRowH2V2_Triangle_JPEG_8u_C1, (
  const Ipp8u*   pSrc1,
  const Ipp8u*   pSrc2,
        int      srcWidth,
        Ipp8u*   pDst))




/* ///////////////////////////////////////////////////////////////////////////
//        Sampling and color conversion functions for encoder
/////////////////////////////////////////////////////////////////////////// */


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiRGBToYCbCr444LS_MCU_8u16s_C3P3R
//
//  Purpose:
//    RGB to YCbCr color conversion, 444 downsampling and level shift (-128)
//    This routine handles one 1:1:1 MCU of interleaved RGB data
//    (lines separated by srcStep) and generates a full color converted MCU
//    (i.e., one 8x8 luminance block and two 8x8 chrominance blocks).
//
//    Input data is in the order:
//      RGB,RGB,...,RGB
//        0       8                   srcStep
//      0 +-------+-------------------+
//        |       |                   |
//        |       |                   |
//        |       |                   |
//      8 +-------+-------------------+
//
//    Output data is in the order:
//      Y block, Cb block, Cr block
//
//        0       8 0       8 0       8
//      0 +-------+ +-------+ +-------+
//        |       | |       | |       |
//        |  Y    | |  Cb   | |  Cr   |
//        |       | |       | |       |
//      8 +-------+ +-------+ +-------+
//
//  Parameter:
//    pSrcRGB   pointer to input data, RGBRGB..RGBRGB
//    srcStep   line offset in input data
//    pDstMCU   pointer to output MCU.
//
//  Returns:
//    IppStatus
//
//  Notes:
//    the color conversion equations:
//      Y  =  0.29900*R + 0.58700*G + 0.11400*B - 128
//      Cb = -0.16874*R - 0.33126*G + 0.50000*B
//      Cr =  0.50000*R - 0.41869*G - 0.08131*B
//  Level Shift is defined in ISO DIS 10918-1,
//  Appendix A - Requrements and guidelines, Annex A, A.3.1 - Level Shift.
*/

IPPAPI(IppStatus, ippiRGBToYCbCr444LS_MCU_8u16s_C3P3R, (
  const Ipp8u*  pSrcRGB,
        int     srcStep,
        Ipp16s* pDstMCU[3]))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiRGBToYCbCr422LS_MCU_8u16s_C3P3R
//
//  Purpose:
//    RGB to YCbCr color conversion, 422 downsampling and level shift (-128)
//    This routine handles one 4:2:2 MCU of interleaved RGB data
//    (lines separated by srcStep) and generates a full color converted MCU
//    (i.e., two 8x8 luminance blocks and two 8x8 chrominance blocks).
//
//    Input data is in the order:
//      RGB,RGB,...,RGB
//
//        0              15       srcStep
//      0 +---------------+-------+
//        |               |       |
//        |               |       |
//        |               |       |
//      8 +---------------+-------+
//
//    Output data is in the order:
//      Y1 block, Y2 block, Cb block, Cr block.
//
//        0       8       15   0       8 0       8
//      0 +-------+-------+  0 +-------+ +-------+
//        |       |       |    |       | |       |
//        |  Y1   |  Y2   |    |  Cb   | |  Cr   |
//        |       |       |    |       | |       |
//      8 +-------+-------+  8 +-------+ +-------+
//
//    Downsampling is done via averaging. For the above example,
//    the Cb and Cr blocks would each use an average of 2 pixels
//    horizonatally to get 1 pixel into the output blocks.
//
//  Parameter:
//    pSrcRGB   pointer to input data
//    srcStep   line offset in input data
//    pDstMCU   pointer to output array
//
//  Returns:
//    IppStatus
//
//  Notes:
//    the color conversion equations:
//      Y  =  0.29900*R + 0.58700*G + 0.11400*B - 128
//      Cb = -0.16874*R - 0.33126*G + 0.50000*B
//      Cr =  0.50000*R - 0.41869*G - 0.08131*B
//  Level Shift is defined in ISO DIS 10918-1,
//  Appendix A - Requrements and guidelines, Annex A, A.3.1 - Level Shift.
*/

IPPAPI(IppStatus, ippiRGBToYCbCr422LS_MCU_8u16s_C3P3R, (
  const Ipp8u*  pSrcRGB,
        int     srcStep,
        Ipp16s* pDstMCU[3]))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiRGBToYCbCr411LS_MCU_8u16s_C3P3R
//
//  Purpose:
//    RGB to YCbCr color conversion, 411 downsampling and level shift (-128)
//    This routine handles one 4:1:1 MCU of interleaved RGB data
//    (lines separated by srcStep) and generates a full color converted MCU
//    (i.e., four 8x8 luminance blocks and two 8x8 chrominance blocks).
//
//    Input data is in the order:
//      RGB,RGB,...,RGB
//
//        0               15      srcStep
//      0 +---------------+-------+
//        |               |       |
//        |               |       |
//        |               |       |
//        |               |       |
//        |               |       |
//        |               |       |
//        |               |       |
//     15 +---------------+-------+
//
//    Output data is in the order:
//      Y1 block, Y2 block, Y3 block, Y4 block,
//      Cb block, Cr block,
//
//        0       8       15  0        8  0        8
//      0 +-------+--------+  +--------+  +--------+
//        |       |        |  |        |  |        |
//        |  Y1   |  Y2    |  |  Cb    |  |  Cr    |
//        |       |        |  |        |  |        |
//      8 +-------+--------+  +--------+  +--------+
//        |       |        |
//        |  Y3   |  Y4    |
//        |       |        |
//     15 +-------+--------+
//
//    Downsampling is done via averaging. For the above example,
//    the Cb and Cr blocks would each use an average of 4 pixels
//    to get 1 pixel into the output blocks.
//
//  Parameter:
//    pSrcRGB   pointer to input data
//    srcStep   line offset in input data
//    pDstMCU   pointer to output array
//
//  Returns:
//    IppStatus
//
//  Notes:
//    the color conversion equations:
//      Y  =  0.29900*R + 0.58700*G + 0.11400*B - 128
//      Cb = -0.16874*R - 0.33126*G + 0.50000*B
//      Cr =  0.50000*R - 0.41869*G - 0.08131*B
//  Level Shift is defined in ISO DIS 10918-1,
//  Appendix A - Requrements and guidelines, Annex A, A.3.1 - Level Shift.
*/

IPPAPI(IppStatus, ippiRGBToYCbCr411LS_MCU_8u16s_C3P3R, (
  const Ipp8u*  pSrcRGB,
        int     srcStep,
        Ipp16s* pDstMCU[3]))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiBGRToYCbCr444LS_MCU_8u16s_C3P3R
//
//  Purpose:
//    BGR to YCbCr color conversion, 444 downsampling and level shift (-128)
//    This routine handles one 1:1:1 MCU of interleaved BGR data
//    (lines separated by srcStep) and generates a full color converted MCU
//    (i.e., one 8x8 luminance block and two 8x8 chrominance blocks).
//
//    Input data is in the order:
//      BGR,BGR,...,BGR
//        0       8                   srcStep
//      0 +-------+-------------------+
//        |       |                   |
//        |       |                   |
//        |       |                   |
//      8 +-------+-------------------+
//
//    Output data is in the order:
//      Y block, Cb block, Cr block
//
//        0       8 0       8 0       8
//      0 +-------+ +-------+ +-------+
//        |       | |       | |       |
//        |  Y    | |  Cb   | |  Cr   |
//        |       | |       | |       |
//      8 +-------+ +-------+ +-------+
//
//  Parameter:
//    pSrcBGR   pointer to input data, RGBRGB..RGBRGB
//    srcStep   line offset in input data
//    pDstMCU   pointer to output MCU.
//
//  Returns:
//    IppStatus
//
//  Notes:
//    the color conversion equations:
//      Y  =  0.29900*R + 0.58700*G + 0.11400*B - 128
//      Cb = -0.16874*R - 0.33126*G + 0.50000*B
//      Cr =  0.50000*R - 0.41869*G - 0.08131*B
//  Level Shift is defined in ISO DIS 10918-1,
//  Appendix A - Requirements and guidelines, Annex A, A.3.1 - Level Shift.
*/

IPPAPI(IppStatus, ippiBGRToYCbCr444LS_MCU_8u16s_C3P3R, (
  const Ipp8u*  pSrcBGR,
        int     srcStep,
        Ipp16s* pDstMCU[3]))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiBGRToYCbCr422LS_MCU_8u16s_C3P3R
//
//  Purpose:
//    BGR to YCbCr color conversion, 422 downsampling and level shift (-128)
//    This routine handles one 4:2:2 MCU of interleaved BGR data
//    (lines separated by srcStep) and generates a full color converted MCU
//    (i.e., two 8x8 luminance blocks and two 8x8 chrominance blocks).
//
//    Input data is in the order:
//      BGR,BGR,...,BGR
//
//        0              15       srcStep
//      0 +---------------+-------+
//        |               |       |
//        |               |       |
//        |               |       |
//      8 +---------------+-------+
//
//    Output data is in the order:
//      Y1 block, Y2 block, Cb block, Cr block.
//
//        0       8       15   0       8 0       8
//      0 +-------+-------+  0 +-------+ +-------+
//        |       |       |    |       | |       |
//        |  Y1   |  Y2   |    |  Cb   | |  Cr   |
//        |       |       |    |       | |       |
//      8 +-------+-------+  8 +-------+ +-------+
//
//    Downsampling is done via averaging. For the above example,
//    the Cb and Cr blocks would each use an average of 2 pixels
//    horizonatally to get 1 pixel into the output blocks.
//
//  Parameter:
//    pSrcBGR   pointer to input data
//    srcStep   line offset in input data
//    pDstMCU   pointer to output array
//
//  Returns:
//    IppStatus
//
//  Notes:
//    the color conversion equations:
//      Y  =  0.29900*R + 0.58700*G + 0.11400*B - 128
//      Cb = -0.16874*R - 0.33126*G + 0.50000*B
//      Cr =  0.50000*R - 0.41869*G - 0.08131*B
//  Level Shift is defined in ISO DIS 10918-1,
//  Appendix A - Requrements and guidelines, Annex A, A.3.1 - Level Shift.
*/

IPPAPI(IppStatus, ippiBGRToYCbCr422LS_MCU_8u16s_C3P3R, (
  const Ipp8u*  pSrcBGR,
        int     srcStep,
        Ipp16s* pDstMCU[3]))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiBGRToYCbCr411LS_MCU_8u16s_C3P3R
//
//  Purpose:
//    BGR to YCbCr color conversion, 411 downsampling and level shift (-128)
//    This routine handles one 4:1:1 MCU of interleaved BGR data
//    (lines separated by srcStep) and generates a full color converted MCU
//    (i.e., four 8x8 luminance blocks and two 8x8 chrominance blocks).
//
//    Input data is in the order:
//      BGR,BGR,...,BGR
//
//        0               15      srcStep
//      0 +---------------+-------+
//        |               |       |
//        |               |       |
//        |               |       |
//        |               |       |
//        |               |       |
//        |               |       |
//        |               |       |
//     15 +---------------+-------+
//
//    Output data is in the order:
//      Y1 block, Y2 block, Y3 block, Y4 block,
//      Cb block, Cr block,
//
//        0       8       15  0        8  0        8
//      0 +-------+--------+  +--------+  +--------+
//        |       |        |  |        |  |        |
//        |  Y1   |  Y2    |  |  Cb    |  |  Cr    |
//        |       |        |  |        |  |        |
//      8 +-------+--------+  +--------+  +--------+
//        |       |        |
//        |  Y3   |  Y4    |
//        |       |        |
//     15 +-------+--------+
//
//    Downsampling is done via averaging. For the above example,
//    the Cb and Cr blocks would each use an average of 4 pixels
//    to get 1 pixel into the output blocks.
//
//  Parameter:
//    pSrcBGR   pointer to input data
//    srcStep   line offset in input data
//    pDstMCU   pointer to output array
//
//  Returns:
//    IppStatus
//
//  Notes:
//    the color conversion equations:
//      Y  =  0.29900*R + 0.58700*G + 0.11400*B - 128
//      Cb = -0.16874*R - 0.33126*G + 0.50000*B
//      Cr =  0.50000*R - 0.41869*G - 0.08131*B
//  Level Shift is defined in ISO DIS 10918-1,
//  Appendix A - Requrements and guidelines, Annex A, A.3.1 - Level Shift.
*/

IPPAPI(IppStatus, ippiBGRToYCbCr411LS_MCU_8u16s_C3P3R, (
  const Ipp8u*  pSrcBGR,
        int     srcStep,
        Ipp16s* pDstMCU[3]))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiSampleDown444LS_MCU_8u16s_C3P3R
//
//  Purpose:
//    No color conversion, 444 downsampling and level shift (-128)
//    This routine handles one 1:1:1 MCU of interleaved data
//    (lines separated by srcStep) and generates a full MCU
//    (i.e., one 8x8 block of Ch1 and two 8x8 blocks of Ch2 and Ch3).
//
//    Input data is in the order:
//      Ch1Ch2Ch3,...,Ch1Ch2Ch3
//        0       8                   srcStep
//      0 +-------+-------------------+
//        |       |                   |
//        |       |                   |
//        |       |                   |
//      8 +-------+-------------------+
//
//    Output data is in the order:
//      Ch1 block, Ch2 block, Ch3 block
//
//        0       8 0       8 0       8
//      0 +-------+ +-------+ +-------+
//        |       | |       | |       |
//        |       | |       | |       |
//        |       | |       | |       |
//      8 +-------+ +-------+ +-------+
//
//  Parameter:
//    pSrc      pointer to input data
//    srcStep   line offset in input data
//    pDstMCU   pointer to output MCU.
//
//  Returns:
//    IppStatus
//
//  Notes:
//  Level Shift is defined in ISO DIS 10918-1,
//  Appendix A - Requirements and guidelines, Annex A, A.3.1 - Level Shift.
*/

IPPAPI(IppStatus, ippiSampleDown444LS_MCU_8u16s_C3P3R, (
  const Ipp8u*  pSrc,
        int     srcStep,
        Ipp16s* pDstMCU[3]))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiSampleDown422LS_MCU_8u16s_C3P3R
//
//  Purpose:
//    No color conversion, 422 downsampling and level shift (-128)
//    This routine handles one 4:2:2 MCU of interleaved data
//    (lines separated by srcStep) and generates a full MCU
//    (i.e., two 8x8 blocks of Ch1 and two 8x8 blocks of Ch2 and Ch3).
//
//    Input data is in the order:
//      Ch1Ch2Ch3,,...,Ch1Ch2Ch3
//
//        0              15       srcStep
//      0 +---------------+-------+
//        |               |       |
//        |               |       |
//        |               |       |
//      8 +---------------+-------+
//
//    Output data is in the order:
//      Ch1 block, Ch1 block, Ch2 block, Ch3 block.
//
//        0       8       15   0       8 0       8
//      0 +-------+-------+  0 +-------+ +-------+
//        |       |       |    |       | |       |
//        |       |       |    |       | |       |
//        |       |       |    |       | |       |
//      8 +-------+-------+  8 +-------+ +-------+
//
//    Downsampling is done via averaging. For the above example,
//    the Cb and Cr blocks would each use an average of 2 pixels
//    horizonatally to get 1 pixel into the output blocks.
//
//  Parameter:
//    pSrc      pointer to input data
//    srcStep   line offset in input data
//    pDstMCU   pointer to output array
//
//  Returns:
//    IppStatus
//
//  Notes:
//  Level Shift is defined in ISO DIS 10918-1,
//  Appendix A - Requrements and guidelines, Annex A, A.3.1 - Level Shift.
*/

IPPAPI(IppStatus, ippiSampleDown422LS_MCU_8u16s_C3P3R, (
  const Ipp8u*  pSrc,
        int     srcStep,
        Ipp16s* pDstMCU[3]))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiSampleDown411LS_MCU_8u16s_C3P3R
//
//  Purpose:
//    No color conversion, 411 downsampling and level shift (-128)
//    This routine handles one 4:1:1 MCU of interleaved data
//    (lines separated by srcStep) and generates a full MCU
//    (i.e., four 8x8 blocks of Ch1 and two 8x8 blocks of Ch2 and Ch3).
//
//    Input data is in the order:
//      Ch1Ch2Ch3,,...,Ch1Ch2Ch3
//
//        0               15      srcStep
//      0 +---------------+-------+
//        |               |       |
//        |               |       |
//        |               |       |
//        |               |       |
//        |               |       |
//        |               |       |
//        |               |       |
//     15 +---------------+-------+
//
//    Output data is in the order:
//      Ch1 block, Ch1 block, Ch1 block, Ch1 block,
//      Ch2 block, Ch3 block,
//
//        0       8       15  0        8  0        8
//      0 +-------+--------+  +--------+  +--------+
//        |       |        |  |        |  |        |
//        |  ch1  |  ch1   |  |  ch2   |  |  ch3   |
//        |       |        |  |        |  |        |
//      8 +-------+--------+  +--------+  +--------+
//        |       |        |
//        |  ch1  |  ch1   |
//        |       |        |
//     15 +-------+--------+
//
//    Downsampling is done via averaging. For the above example,
//    the Ch2 and Ch3 blocks would each use an average of 4 pixels
//    to get 1 pixel into the output blocks.
//
//  Parameter:
//    pSrc      pointer to input data
//    srcStep   line offset in input data
//    pDstMCU   pointer to output array
//
//  Returns:
//    IppStatus
//
//  Notes:
//  Level Shift is defined in ISO DIS 10918-1,
//  Appendix A - Requirements and guidelines, Annex A, A.3.1 - Level Shift.
*/

IPPAPI(IppStatus, ippiSampleDown411LS_MCU_8u16s_C3P3R, (
  const Ipp8u*  pSrc,
        int     srcStep,
        Ipp16s* pDstMCU[3]))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiSplit422LS_MCU_8u16s_C2P3R
//
//  Purpose:
//    No color conversion, no up-sampling,
//    only pixel to planar transformation and level shift (+128)
//    for one MCU
//
//  Parameter:
//    pSrc      pointer to input data
//    srcStep   line offset in output data
//    pDstMCU   pointer to pointers to output data
//
//  Returns:
//    IppStatus
//
//  Notes:
*/

IPPAPI(IppStatus,ippiSplit422LS_MCU_8u16s_C2P3R,(
  const Ipp8u*  pSrc,
        int     srcStep,
        Ipp16s* pDstMCU[3]))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiCMYKToYCCK444LS_MCU_8u16s_C4P4R
//
//  Purpose:
//    CMYK to YCCK color conversion, 444 downsampling and level shift (-128)
//    This routine handles one 1:1:1:1 MCU of interleaved CMYK data
//    (lines separated by srcStep) and generates a full color converted MCU
//    (one 8x8 luminance block, two 8x8 chrominance blocks
//    and one 8x8 alpha block).
//
//    Input data is in the order:
//      CMYK,CMYK,...,CMYK
//
//        0       8              srcStep
//      0 +-------+--------------+
//        |       |              |
//        |       |              |
//        |       |              |
//      8 +-------+--------------+
//
//    Output data is in the order:
//      Y block, Cb block, Cr block, K block.
//
//        0       8 0       8 0       8 0       8
//      0 +-------+ +-------+ +-------+ +-------+
//        |       | |       | |       | |       |
//        |  Y    | |  Cb   | |  Cr   | |  K    |
//        |       | |       | |       | |       |
//      8 +-------+ +-------+ +-------+ +-------+
//
//  Parameter:
//    pSrcCMYK  pointer to input data
//    srcStep   line offset in input data
//    pDstYCCK  pointer to output array
//
//  Returns:
//    IppStatus
//
//  Notes:
//    This version handles Adobe-style CMYK->YCCK conversion,
//    where R = 1-C, G = 1-M, and B = 1-Y are converted to YCbCr,
//    while K (black) channel is unchanged.
//  Level Shift is defined in ISO DIS 10918-1,
//  Appendix A - Requirements and guidelines, Annex A, A.3.1 - Level Shift.
*/

IPPAPI(IppStatus, ippiCMYKToYCCK444LS_MCU_8u16s_C4P4R, (
  const Ipp8u*  pSrcCMYK,
        int     srcStep,
        Ipp16s* pDstYCCK[4]))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiCMYKToYCCK422LS_MCU_8u16s_C4P4R
//
//  Purpose:
//    CMYK to YCCK color conversion, 4224 downsampling and level shift (-128)
//    This routine handles one "partial" 4:2:2:4 MCU of interleaved
//    RGBA_FPX DIB data (lines separated by lineoffset) and generates
//    a full color converted MCU (i.e., two 8x8 luminance blocks
//    and two 4x8 chrominance blocks and two 8x8 alpha blocks).
//
//    Input data is in the order:
//      CMYK,CMYK,...,CMYK
//
//        0               15      srcStep
//      0 +---------------+-------+
//        |               |       |
//        |               |       |
//        |               |       |
//      8 +---------------+-------+
//
//    Output data is in the order:
//      Y1 block, Y2 block, Cb block, Cr block, K1 block, K2 block.
//
//        0       8       15 0       8 0        8  0       8       15
//      0 +-------+-------+  +-------+ +--------+  +-------+-------+
//        |       |       |  |       | |        |  |       |       |
//        |  Y1   |  Y2   |  |  Cb   | |  Cr    |  |  K1   |  K2   |
//        |       |       |  |       | |        |  |       |       |
//      8 +-------+-------+  +-------+ +--------+  +-------+-------+
//
//    Downsampling is done via averaging. For the above example,
//    the Cb and Cr blocks would each use an average of 2 pixels horizonatally
//    to get 1 pixel into the output blocks.
//
//  Parameter:
//    pSrcCMYK  pointer to input data
//    srcStep   line offset in input data
//    pDstYCCK  pointer to output array
//
//  Returns:
//    IppStatus
//
//  Notes:
//    This version handles Adobe-style CMYK->YCCK conversion,
//    where R = 1-C, G = 1-M, and B = 1-Y are converted to YCbCr,
//    while K (black) channel is unchanged.
//  Level Shift is defined in ISO DIS 10918-1,
//  Appendix A - Requirements and guidelines, Annex A, A.3.1 - Level Shift.
*/

IPPAPI(IppStatus, ippiCMYKToYCCK422LS_MCU_8u16s_C4P4R, (
  const Ipp8u*  pSrcCMYK,
        int     srcStep,
        Ipp16s* pDstYCCK[4]))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiCMYKToYCCK411LS_MCU_8u16s_C4P4R
//
//  Purpose:
//    CMYK to YCCK color conversion, 4114 downsampling and level shift (-128)
//    This routine handles one 4:1:1:4 MCU of interleaved CMYK data
//    (lines separated by srcStep) and generates a full color converted MCU
//    (i.e., four 8x8 luminance blocks and two 8x8 chrominance blocks
//    and four 8x8 alpha blocks).
//
//    Input data is in the order:
//      CMYK,CMYK,...,CMYK
//
//        0               15      srcStep
//      0 +---------------+-------+
//        |               |       |
//        |               |       |
//        |               |       |
//        |               |       |
//        |               |       |
//        |               |       |
//        |               |       |
//     15 +---------------+-------+
//
//    Output data is in the order:
//      Y1 block, Y2 block, Y3 block, Y4 block,
//      Cb block, Cr block,
//      K1 block, K2 block, K3 block, K4 block.
//
//        0       8       15  0        8  0        8  0       8       15
//      0 +-------+--------+  +--------+  +--------+  +-------+--------+
//        |       |        |  |        |  |        |  |       |        |
//        |  Y1   |  Y2    |  |  Cb    |  |  Cr    |  |  K1   |  K2    |
//        |       |        |  |        |  |        |  |       |        |
//      8 +-------+--------+  +--------+  +--------+  +-------+--------+
//        |       |        |                          |       |        |
//        |  Y3   |  Y4    |                          |  K3   |  K4    |
//        |       |        |                          |       |        |
//     15 +-------+--------+                          +-------+--------+
//
//    Downsampling is done via averaging. For the above example,
//    the Cb and Cr blocks would each use an average of 4 pixels
//    to get 1 pixel into the output blocks.
//
//  Parameter:
//    pSrcCMYK  pointer to input data
//    srcStep   line offset in input data
//    pDstYCCK  pointer to output array
//
//  Returns:
//    IppStatus
//
//  Notes:
//    This version handles Adobe-style CMYK->YCCK conversion,
//    where R = 1-C, G = 1-M, and B = 1-Y are converted to YCbCr,
//    while K (black) channel is unchanged.
//  Level Shift is defined in ISO DIS 10918-1,
//  Appendix A - Requirements and guidelines, Annex A, A.3.1 - Level Shift.
*/

IPPAPI(IppStatus, ippiCMYKToYCCK411LS_MCU_8u16s_C4P4R, (
  const Ipp8u*  pSrcCMYK,
        int     srcStep,
        Ipp16s* pDstYCCK[4]))




/* ///////////////////////////////////////////////////////////////////////////
//        Functions for color conversion for decoder
/////////////////////////////////////////////////////////////////////////// */


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiYCbCrToRGB_JPEG_8u_P3R
//
//  Purpose:
//    YCbCr to RGB color conversion
//
//  Parameter:
//    pSrcYCbCr pointer to pointers on input data.
//              pSrc[0] pointer to YY..YY
//              pSrc[1] pointer to CbCb..CbCb
//              pSrc[2] pointer to CrCr..CrCr
//    srcStep   line offset in input data
//    pDstRGB   pointer to pointers to output arrays
//              pDst[0] pointer to RR..RR
//              pDst[1] pointer to GG..GG
//              pDst[2] pointer to BB..BB
//    dstStep   line offset in output data
//    roiSize   ROI size
//
//  Returns:
//    IppStatus
//
//  Notes:
//    R = Y +              1.40200*Cr - 179.456
//    G = Y - 0.34414*Cb - 0.71414*Cr + 135.45984
//    B = Y + 1.77200*Cb              - 226.816
*/

IPPAPI(IppStatus, ippiYCbCrToRGB_JPEG_8u_P3R, (
  const Ipp8u*   pSrcYCbCr[3],
        int      srcStep,
        Ipp8u*   pDstRGB[3],
        int      dstStep,
        IppiSize roiSize))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiYCbCrToRGB_JPEG_8u_P3C3R
//
//  Purpose:
//    YCbCr to RGB color conversion
//
//  Parameter:
//    pSrcYCbCr pointer to pointers to input data
//                pSrcYCbCr[0] pointer to YY..YY
//                pSrcYCbCr[1] pointer to CbCb..CbCb
//                pSrcYCbCr[2] pointer to CrCr..CrCr
//    srcStep   line offset in input data
//    pDstRGB   pointer to output array RGBRGB..RGBRGB
//    dstStep   line offset in output data
//    roiSize   ROI size
//
//  Returns:
//    IppStatus
//
//  Notes:
//    R = Y +              1.40200*Cr - 179.456
//    G = Y - 0.34414*Cb - 0.71414*Cr + 135.45984
//    B = Y + 1.77200*Cb              - 226.816
*/

IPPAPI(IppStatus, ippiYCbCrToRGB_JPEG_8u_P3C3R, (
  const Ipp8u*   pSrcYCbCr[3],
        int      srcStep,
        Ipp8u*   pDstRGB,
        int      dstStep,
        IppiSize roiSize))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiYCbCrToBGR_JPEG_8u_P3C3R
//
//  Purpose:
//    YCbCr to BGR color conversion
//
//  Parameter:
//    pSrcYCbCr pointer to pointers to input data
//      pSrcYCbCr[0] pointer to YY..YY
//      pSrcYCbCr[1] pointer to CbCb..CbCb
//      pSrcYCbCr[2] pointer to CrCr..CrCr
//    srcStep line offset in input data
//    pDstBGR pointer to output array BGRBGR..BGRBGR
//    dstStep line offset in output data
//    roiSize ROI size
//
//  Returns:
//    IppStatus
//
//  Notes:
//    R = Y + 1.40200*Cr - 179.456
//    G = Y - 0.34414*Cb - 0.71414*Cr + 135.45984
//    B = Y + 1.77200*Cb - 226.816
*/

IPPAPI(IppStatus, ippiYCbCrToBGR_JPEG_8u_P3C3R, (
  const Ipp8u*   pSrcYCbCr[3],
        int      srcStep,
        Ipp8u*   pDstBGR,
        int      dstStep,
        IppiSize roiSize))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiYCCKToCMYK_JPEG_8u_P4R
//
//  Purpose:
//    YCCK to CMYK color conversion
//
//  Parameter:
//    pSrcYCCK  pointer to pointers to input data
//              pSrc[0] pointer to YY..YY
//              pSrc[1] pointer to CC..CC
//              pSrc[2] pointer to CC..CC
//              pSrc[3] pointer to KK..KK
//    srcStep   line offset in input data
//    pDstCMYK  pointer to pointers to output arrays
//              pDst[0] pointer to CC..CC
//              pDst[1] pointer to MM..MM
//              pDst[2] pointer to YY..YY
//              pDst[3] pointer to KK..KK
//    dstStep   line offset in output data
//    roiSize   ROI size
//
//  Returns:
//    IppStatus
//
//  Notes:
//    This version handles Adobe-style YCCK->CMYK conversion,
//    Where YCbCr are converted to R = 1-C, G = 1-M, B = 1-Y,
//    while K (black) channel is unchanged.
*/

IPPAPI(IppStatus, ippiYCCKToCMYK_JPEG_8u_P4R, (
  const Ipp8u*   pSrcYCCK[4],
        int      srcStep,
        Ipp8u*   pDstCMYK[4],
        int      dstStep,
        IppiSize roiSize))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiYCCKToCMYK_JPEG_8u_P4C4R
//
//  Purpose:
//    YCCK to CMYK color conversion
//
//  Parameter:
//    pSrcYCCK  pointer to pointers to input data
//              pSrc[0] pointer to YY..YY
//              pSrc[1] pointer to CC..CC
//              pSrc[2] pointer to CC..CC
//              pSrc[3] pointer to KK..KK
//    srcStep   line offset in input data
//    pDstCMYK  pointer to output array CMYKCMYK..CMYKCMYK
//    dstStep   line offset in output data
//    roiSize   ROI size
//
//  Returns:
//    IppStatus
//
//  Notes:
//    This version handles Adobe-style YCCK->CMYK conversion,
//    Where YCbCr are converted to R = 1-C, G = 1-M, B = 1-Y,
//    while K (black) channel is unchanged.
*/

IPPAPI(IppStatus, ippiYCCKToCMYK_JPEG_8u_P4C4R, (
  const Ipp8u*   pSrcYCCK[4],
        int      srcStep,
        Ipp8u*   pDstCMYK,
        int      dstStep,
        IppiSize roiSize))




/* ///////////////////////////////////////////////////////////////////////////
//        Sampling and color conversion functions for decoder
/////////////////////////////////////////////////////////////////////////// */


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiYCbCr444ToRGBLS_MCU_16s8u_P3C3R
//
//  Purpose:
//
//    This procedure implements the 1:1:1 upsampling and
//    color space conversion from YCbCr to RGB color space
//
//    Input data is in the order:
//      Y block, Cb block, Cr block
//
//        0       8 0       8 0       8
//      0 +-------+ +-------+ +-------+
//        |       | |       | |       |
//        |  Y    | |  Cb   | |  Cr   |
//        |       | |       | |       |
//      8 +-------+ +-------+ +-------+
//
//    Output data is in the order:
//      RGB,RGB,...,RGB
//        0       8                   dstStep
//      0 +-------+-------------------+
//        |       |                   |
//        |       |                   |
//        |       |                   |
//      8 +-------+-------------------+
//
//  Parameter:
//    pSrcMCU   pointer to input data
//    pDstRGB   pointer to pointers to output arrays
//    dstStep   line offset in output data
//
//  Returns:
//    IppStatus
//
//  Notes:
//    the color conversion equations (including level shift +128):
//      R = Y +              1.40200*Cr + 128
//      G = Y - 0.34414*Cb - 0.71414*Cr + 128
//      B = Y + 1.77200*Cb              + 128
//    up-sampling is just box filter
//    Level Shift is defined in ISO DIS 10918-1,
//    Appendix A - Requirements and guidelines, Annex A, A.3.1 - Level Shift.
*/

IPPAPI(IppStatus, ippiYCbCr444ToRGBLS_MCU_16s8u_P3C3R, (
  const Ipp16s* pSrcMCU[3],
        Ipp8u*  pDstRGB,
        int     dstStep))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiYCbCr422ToRGBLS_MCU_16s8u_P3C3R
//
//  Purpose:
//
//    Performs upsampling and YCbCr->RGB color conversion,
//    and output data formatting of DCT output blocks,
//    for a subset of a 4:2:2 MCU.
//
//    Input data is in the order:
//      Y1 block, Y2 block, Cb block, Cr block.
//
//        0       8       15   0       8 0       8
//      0 +-------+-------+  0 +-------+ +-------+
//        |       |       |    |       | |       |
//        |  Y1   |  Y2   |    |  Cb   | |  Cr   |
//        |       |       |    |       | |       |
//      8 +-------+-------+  8 +-------+ +-------+
//
//    Output data is in the order:
//      RGB,RGB,...,RGB
//
//        0              15       dstStep
//      0 +---------------+-------+
//        |               |       |
//        |               |       |
//        |               |       |
//      8 +---------------+-------+
//
//  Parameter:
//    pSrcMCU   pointer to input data
//    pDstRGB   pointer to pointers to output arrays
//    dstStep   line offset in output data
//
//  Returns:
//    IppStatus
//
//  Notes:
//    the color conversion equations (including level shift +128):
//      R = Y +              1.40200*Cr + 128
//      G = Y - 0.34414*Cb - 0.71414*Cr + 128
//      B = Y + 1.77200*Cb              + 128
//    up-sampling is just box filter
//    Level Shift is defined in ISO DIS 10918-1,
//    Appendix A - Requirements and guidelines, Annex A, A.3.1 - Level Shift.
*/

IPPAPI(IppStatus, ippiYCbCr422ToRGBLS_MCU_16s8u_P3C3R, (
  const Ipp16s* pSrcMCU[3],
        Ipp8u*  pDstRGB,
        int     dstStep))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiYCbCr411ToRGBLS_MCU_16s8u_P3C3R
//
//  Purpose:
//
//    Performs upsampling and YCbCr->RGB color conversion,
//    and output data formatting of DCT output blocks,
//    for a subset of a 4:1:1 MCU.
//
//    Input data is in the order:
//      Y1 block, Y2 block, Y3 block, Y4 block,
//      Cb block, Cr block,
//
//        0       8       15  0        8  0        8
//      0 +-------+--------+  +--------+  +--------+
//        |       |        |  |        |  |        |
//        |  Y1   |  Y2    |  |  Cb    |  |  Cr    |
//        |       |        |  |        |  |        |
//      8 +-------+--------+  +--------+  +--------+
//        |       |        |
//        |  Y3   |  Y4    |
//        |       |        |
//     15 +-------+--------+
//
//    Output data is in the order:
//      RGB,RGB,...,RGB
//
//        0               15      dstStep
//      0 +---------------+-------+
//        |               |       |
//        |               |       |
//        |               |       |
//        |               |       |
//        |               |       |
//        |               |       |
//        |               |       |
//     15 +---------------+-------+
//
//  Parameter:
//    pSrcMCU   pointer to input data
//    pDstRGB   pointer to pointers to output arrays
//    dstStep   line offset in output data
//
//  Returns:
//    IppStatus
//
//  Notes:
//    the color conversion equations (including level shift +128):
//      R = Y +              1.40200*Cr + 128
//      G = Y - 0.34414*Cb - 0.71414*Cr + 128
//      B = Y + 1.77200*Cb              + 128
//    up-sampling is just box filter
//    Level Shift is defined in ISO DIS 10918-1,
//    Appendix A - Requirements and guidelines, Annex A, A.3.1 - Level Shift.
*/

IPPAPI(IppStatus, ippiYCbCr411ToRGBLS_MCU_16s8u_P3C3R, (
  const Ipp16s* pSrcMCU[3],
        Ipp8u*  pDstRGB,
        int     dstStep))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiYCbCr444ToBGRLS_MCU_16s8u_P3C3R
//
//  Purpose:
//
//    This procedure implements the 1:1:1 upsampling and
//    color space conversion from YCbCr to BGR color space
//
//    Input data is in the order:
//      Y block, Cb block, Cr block
//
//        0       8 0       8 0       8
//      0 +-------+ +-------+ +-------+
//        |       | |       | |       |
//        |  Y    | |  Cb   | |  Cr   |
//        |       | |       | |       |
//      8 +-------+ +-------+ +-------+
//
//    Output data is in the order:
//      BGR,BGR,...,BGR
//        0       8                   dstStep
//      0 +-------+-------------------+
//        |       |                   |
//        |       |                   |
//        |       |                   |
//      8 +-------+-------------------+
//
//  Parameter:
//    pSrcMCU   pointer to input data
//    pDstBGR   pointer to pointers to output arrays
//    dstStep   line offset in output data
//
//  Returns:
//    IppStatus
//
//  Notes:
//    the color conversion equations (including level shift +128):
//      R = Y +              1.40200*Cr + 128
//      G = Y - 0.34414*Cb - 0.71414*Cr + 128
//      B = Y + 1.77200*Cb              + 128
//    up-sampling is just box filter
//    Level Shift is defined in ISO DIS 10918-1,
//    Appendix A - Requirements and guidelines, Annex A, A.3.1 - Level Shift.
*/

IPPAPI(IppStatus, ippiYCbCr444ToBGRLS_MCU_16s8u_P3C3R, (
  const Ipp16s* pSrcMCU[3],
        Ipp8u*  pDstBGR,
        int     dstStep))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiYCbCr422ToBGRLS_MCU_16s8u_P3C3R
//
//  Purpose:
//
//    Performs upsampling and YCbCr->BGR color conversion,
//    and output data formatting of DCT output blocks,
//    for a subset of a 4:2:2 MCU.
//
//    Input data is in the order:
//      Y1 block, Y2 block, Cb block, Cr block.
//
//        0       8       15   0       8 0       8
//      0 +-------+-------+  0 +-------+ +-------+
//        |       |       |    |       | |       |
//        |  Y1   |  Y2   |    |  Cb   | |  Cr   |
//        |       |       |    |       | |       |
//      8 +-------+-------+  8 +-------+ +-------+
//
//    Output data is in the order:
//      BGR,BGR,...,BGR
//
//        0              15       dstStep
//      0 +---------------+-------+
//        |               |       |
//        |               |       |
//        |               |       |
//      8 +---------------+-------+
//
//  Parameter:
//    pSrcMCU   pointer to input data
//    pDstBGR   pointer to pointers to output arrays
//    dstStep   line offset in output data
//
//  Returns:
//    IppStatus
//
//  Notes:
//    the color conversion equations (including level shift +128):
//      R = Y +              1.40200*Cr + 128
//      G = Y - 0.34414*Cb - 0.71414*Cr + 128
//      B = Y + 1.77200*Cb              + 128
//    up-sampling is just box filter
//    Level Shift is defined in ISO DIS 10918-1,
//    Appendix A - Requirements and guidelines, Annex A, A.3.1 - Level Shift.
*/

IPPAPI(IppStatus, ippiYCbCr422ToBGRLS_MCU_16s8u_P3C3R, (
  const Ipp16s* pSrcMCU[3],
        Ipp8u*  pDstBGR,
        int     dstStep))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiYCbCr411ToBGRLS_MCU_16s8u_P3C3R
//
//  Purpose:
//
//    Performs upsampling and YCbCr->BGR color conversion,
//    and output data formatting of DCT output blocks,
//    for a subset of a 4:1:1 MCU.
//
//    Input data is in the order:
//      Y1 block, Y2 block, Y3 block, Y4 block,
//      Cb block, Cr block,
//
//        0       8       15  0        8  0        8
//      0 +-------+--------+  +--------+  +--------+
//        |       |        |  |        |  |        |
//        |  Y1   |  Y2    |  |  Cb    |  |  Cr    |
//        |       |        |  |        |  |        |
//      8 +-------+--------+  +--------+  +--------+
//        |       |        |
//        |  Y3   |  Y4    |
//        |       |        |
//     15 +-------+--------+
//
//    Output data is in the order:
//      BGR,BGR,...,BGR
//
//        0               15      dstStep
//      0 +---------------+-------+
//        |               |       |
//        |               |       |
//        |               |       |
//        |               |       |
//        |               |       |
//        |               |       |
//        |               |       |
//     15 +---------------+-------+
//
//  Parameter:
//    pSrcMCU   pointer to input data
//    pDstBGR   pointer to pointers to output arrays
//    dstStep   line offset in output data
//
//  Returns:
//    IppStatus
//
//  Notes:
//    the color conversion equations (including level shift +128):
//      R = Y +              1.40200*Cr + 128
//      G = Y - 0.34414*Cb - 0.71414*Cr + 128
//      B = Y + 1.77200*Cb              + 128
//    up-sampling is just box filter
//    Level Shift is defined in ISO DIS 10918-1,
//    Appendix A - Requirements and guidelines, Annex A, A.3.1 - Level Shift.
*/

IPPAPI(IppStatus, ippiYCbCr411ToBGRLS_MCU_16s8u_P3C3R, (
  const Ipp16s* pSrcMCU[3],
        Ipp8u*  pDstBGR,
        int     dstStep))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiSampleUp444LS_MCU_16s8u_P3C3R
//
//  Purpose:
//
//    This procedure implements the 1:1:1 upsampling.
//    No color conversion is performed.
//
//    Input data is in the order:
//      C1 block, C2 block, C3 block
//
//        0       8 0       8 0       8
//      0 +-------+ +-------+ +-------+
//        |       | |       | |       |
//        |  C1   | |  C2   | |  C3   |
//        |       | |       | |       |
//      8 +-------+ +-------+ +-------+
//
//    Output data is in the order:
//      C1C2C3,C1C2C3,...,C1C2C3
//        0       8                   dstStep
//      0 +-------+-------------------+
//        |       |                   |
//        |       |                   |
//        |       |                   |
//      8 +-------+-------------------+
//
//  Parameter:
//    pSrcMCU   pointer to input data
//    pDst      pointer to pointers to output arrays
//    dstStep   line offset in output data
//
//  Returns:
//    IppStatus
//
//  Notes:
//
//    Level Shift is defined in ISO DIS 10918-1,
//    Appendix A - Requirements and guidelines, Annex A, A.3.1 - Level Shift.
*/

IPPAPI(IppStatus, ippiSampleUp444LS_MCU_16s8u_P3C3R, (
  const Ipp16s* pSrcMCU[3],
        Ipp8u*  pDst,
        int     dstStep))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiSampleUp422LS_MCU_16s8u_P3C3R
//
//  Purpose:
//
//    Performs upsampling and output data
//    formatting of DCT output blocks,
//    for a subset of a 4:2:2 MCU. No color conversion
//    is performed.
//
//    Input data is in the order:
//      C1 1th block, C1 2th block, C2 block, C3 block.
//
//        0       8       15   0       8 0       8
//      0 +-------+-------+  0 +-------+ +-------+
//        |       |       |    |       | |       |
//        |       |       |    |       | |       |
//        |       |       |    |       | |       |
//      8 +-------+-------+  8 +-------+ +-------+
//
//    Output data is in the order:
//      C1C2C3,C1C2C3,...,C1C2C3
//
//        0              15       dstStep
//      0 +---------------+-------+
//        |               |       |
//        |               |       |
//        |               |       |
//      8 +---------------+-------+
//
//  Parameter:
//    pSrcMCU   pointer to input data
//    pDst      pointer to pointers to output arrays
//    dstStep   line offset in output data
//
//  Returns:
//    IppStatus
//
//  Notes:
//    up-sampling is just box filter
//    Level Shift is defined in ISO DIS 10918-1,
//    Appendix A - Requirements and guidelines, Annex A, A.3.1 - Level Shift.
*/

IPPAPI(IppStatus, ippiSampleUp422LS_MCU_16s8u_P3C3R, (
  const Ipp16s* pSrcMCU[3],
        Ipp8u*  pDst,
        int     dstStep))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiSampleUp411LS_MCU_16s8u_P3C3R
//
//  Purpose:
//
//    Performs upsampling and output data
//    formatting of DCT output blocks,
//    for a subset of a 4:1:1 MCU. No color conversion
//    is performed.
//
//    Input data is in the order:
//      C1 1th block, C1 2th block, C1 3th block, C1 4th block,
//      C2 block, C3 block,
//
//        0       8       15  0        8  0        8
//      0 +-------+--------+  +--------+  +--------+
//        |       |        |  |        |  |        |
//        |       |        |  |        |  |        |
//        |       |        |  |        |  |        |
//      8 +-------+--------+  +--------+  +--------+
//        |       |        |
//        |       |        |
//        |       |        |
//     15 +-------+--------+
//
//    Output data is in the order:
//      C1C2C3,C1C2C3,...,C1C2C3
//
//        0               15      dstStep
//      0 +---------------+-------+
//        |               |       |
//        |               |       |
//        |               |       |
//        |               |       |
//        |               |       |
//        |               |       |
//        |               |       |
//     15 +---------------+-------+
//
//  Parameter:
//    pSrcMCU   pointer to input data
//    pDst      pointer to pointers to output arrays
//    dstStep   line offset in output data
//
//  Returns:
//    IppStatus
//
//  Notes:
//    up-sampling is just box filter
//    Level Shift is defined in ISO DIS 10918-1,
//    Appendix A - Requrements and guidelines, Annex A, A.3.1 - Level Shift.
*/

IPPAPI(IppStatus, ippiSampleUp411LS_MCU_16s8u_P3C3R, (
  const Ipp16s* pSrcMCU[3],
        Ipp8u*  pDst,
        int     dstStep))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiJoin422LS_MCU_16s8u_P3C2R
//
//  Purpose:
//
//    Performs planar to pixel conversion,
//    preserving 422 sampling, for a subset of a 4:2:2 MCU.
//
//    Input data is in the order:
//      Y1 block, Y2 block, Cb block, Cr block.
//
//        0       8       15   0       8 0       8
//      0 +-------+-------+  0 +-------+ +-------+
//        |       |       |    |       | |       |
//        |  Y1   |  Y2   |    |  Cb   | |  Cr   |
//        |       |       |    |       | |       |
//      8 +-------+-------+  8 +-------+ +-------+
//
//    Output data is in the order:
//      YCbYCr,YCbYCr,...,YCbYCr
//
//        0              15       dstStep
//      0 +---------------+-------+
//        |               |       |
//        |               |       |
//        |               |       |
//      8 +---------------+-------+
//
//  Parameter:
//    pSrcMCU   pointer to the array of pointers to input data
//    pDst      pointer to output data
//    dstStep   line offset in output data
//
//  Returns:
//    IppStatus
//
//  Notes:
*/

IPPAPI(IppStatus, ippiJoin422LS_MCU_16s8u_P3C2R, (
  const Ipp16s* pSrcMCU[3],
        Ipp8u*  pDst,
        int     dstStep))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiYCCK444ToCMYKLS_MCU_16s8u_P4C4R
//
//  Purpose:
//
//    This procedure implements the 1:1:1:1 upsampling and
//    color space conversion from YCCK to CMYK color space
//
//    Input data is in the order:
//      Y block, Cb block, Cr block, K block.
//
//        0       8 0       8 0       8 0       8
//      0 +-------+ +-------+ +-------+ +-------+
//        |       | |       | |       | |       |
//        |  Y    | |  Cb   | |  Cr   | |  K    |
//        |       | |       | |       | |       |
//      8 +-------+ +-------+ +-------+ +-------+
//
//    Output data is in the order:
//      CMYK,CMYK,...,CMYK
//
//        0       8              dstStep
//      0 +-------+--------------+
//        |       |              |
//        |       |              |
//        |       |              |
//      8 +-------+--------------+
//
//  Parameter:
//    pSrcMCU   pointer to input data
//    pDstCMYK  pointer to pointers to output arrays
//    dstStep   line offset in output data
//
//  Returns:
//    IppStatus
//
//  Notes:
//    This version handles Adobe-style YCCK->CMYK conversion,
//    Where YCbCr are converted to R = 1-C, G = 1-M, B = 1-Y,
//    while K (black) channel is unchanged.
//    Level Shift is defined in ISO DIS 10918-1,
//    Appendix A - Requirements and guidelines, Annex A, A.3.1 - Level Shift.
*/

IPPAPI(IppStatus, ippiYCCK444ToCMYKLS_MCU_16s8u_P4C4R, (
  const Ipp16s* pSrcMCU[4],
        Ipp8u*  pDstCMYK,
        int     dstStep))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiYCCK422ToCMYKLS_MCU_16s8u_P4C4R
//
//  Purpose:
//
//    Performs upsampling and YCbCr->RGB color conversion,
//    and output data formatting of DCT output blocks,
//    for a subset of a 4:2:2:4 MCU.
//
//    Input data is in the order:
//      Y1 block, Y2 block, Cb block, Cr block, K1 block, K2 block.
//
//        0       8       15 0       8 0        8  0       8       15
//      0 +-------+-------+  +-------+ +--------+  +-------+-------+
//        |       |       |  |       | |        |  |       |       |
//        |  Y1   |  Y2   |  |  Cb   | |  Cr    |  |  K1   |  K2   |
//        |       |       |  |       | |        |  |       |       |
//      8 +-------+-------+  +-------+ +--------+  +-------+-------+
//
//    Output data is in the order:
//      CMYK,CMYK,...,CMYK
//
//        0               15      dstStep
//      0 +---------------+-------+
//        |               |       |
//        |               |       |
//        |               |       |
//      8 +---------------+-------+
//
//  Parameter:
//    pSrcMCU   pointer to input data
//    pDstCMYK  pointer to pointers to output arrays
//    dstStep   line offset in output data
//
//  Returns:
//    IppStatus
//
//  Notes:
//    This version handles Adobe-style YCCK->CMYK conversion,
//    Where YCbCr are converted to R = 1-C, G = 1-M, B = 1-Y,
//    while K (black) channel is unchanged.
//    Level Shift is defined in ISO DIS 10918-1,
//    Appendix A - Requirements and guidelines, Annex A, A.3.1 - Level Shift.
*/

IPPAPI(IppStatus, ippiYCCK422ToCMYKLS_MCU_16s8u_P4C4R, (
  const Ipp16s* pSrcMCU[4],
        Ipp8u*  pDstCMYK,
        int     dstStep))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiYCCK411ToCMYKLS_MCU_16s8u_P4C4R
//
//  Purpose:
//
//    Performs upsampling and YCbCr->RGB color conversion,
//    and output data formatting of DCT output blocks,
//    for a subset of a 4:1:1:4 MCU.
//
//    Input data is in the order:
//      Y1 block, Y2 block, Y3 block, Y4 block,
//      Cb block, Cr block,
//      K1 block, K2 block, K3 block, K4 block.
//
//        0       8       15  0        8  0        8  0       8       15
//      0 +-------+--------+  +--------+  +--------+  +-------+--------+
//        |       |        |  |        |  |        |  |       |        |
//        |  Y1   |  Y2    |  |  Cb    |  |  Cr    |  |  K1   |  K2    |
//        |       |        |  |        |  |        |  |       |        |
//      8 +-------+--------+  +--------+  +--------+  +-------+--------+
//        |       |        |                          |       |        |
//        |  Y3   |  Y4    |                          |  K3   |  K4    |
//        |       |        |                          |       |        |
//     15 +-------+--------+                          +-------+--------+
//
//    Output data is in the order:
//      CMYK,CMYK,...,CMYK
//
//        0               15      dstStep
//      0 +---------------+-------+
//        |               |       |
//        |               |       |
//        |               |       |
//        |               |       |
//        |               |       |
//        |               |       |
//        |               |       |
//     15 +---------------+-------+
//
//  Parameter:
//    pSrcMCU   pointer to input data
//    pDstCMYK  pointer to pointers to output arrays
//    dstStep   line offset in output data
//
//  Returns:
//    IppStatus
//
//  Notes:
//    This version handles Adobe-style YCCK->CMYK conversion,
//    Where YCbCr are converted to R = 1-C, G = 1-M, B = 1-Y,
//    while K (black) channel is unchanged.
//    Level Shift is defined in ISO DIS 10918-1,
//    Appendix A - Requirements and guidelines, Annex A, A.3.1 - Level Shift.
*/

IPPAPI(IppStatus, ippiYCCK411ToCMYKLS_MCU_16s8u_P4C4R, (
  const Ipp16s* pSrcMCU[4],
        Ipp8u*  pDstCMYK,
        int     dstStep))




/* ///////////////////////////////////////////////////////////////////////////
//        DCT + Quantization + Level Shift Functions for encoder
/////////////////////////////////////////////////////////////////////////// */


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiDCTQuantFwd8x8LS_JPEG_8u16s_C1R
//
//  Purpose:
//    Forward DCT transform, quantization and level shift
//
//  Parameter:
//    pSrc           - pointer to source color component data
//    srcStep        - line offset for source data
//    pDst           - pointer to output 8x8 block
//                     of quantized DCT coefficients
//    pQuantFwdTable - pointer to Quantization table
//
//  Returns:
//    IppStatus
//
//  Notes:
//    DCT is defined in ISO DIS 10918-1,
//    Appendix A - Requrements and guidelines, Annex A, A.3.3 FDCT and IDCT.
//    Quantization is defined in ISO DIS 10918-1,
//    Appendix A - Requrements and guidelines,
//    Annex A, A.3.4 DCT coefficient quantization and dequantization.
//    Level Shift is defined in ISO DIS 10918-1,
//    Appendix A - Requrements and guidelines, Annex A, A.3.1 - Level Shift.
*/

IPPAPI(IppStatus, ippiDCTQuantFwd8x8LS_JPEG_8u16s_C1R, (
  const Ipp8u*  pSrc,
        int     srcStep,
        Ipp16s* pDst,
  const Ipp16u* pQuantFwdTable))




/* ///////////////////////////////////////////////////////////////////////////
//        DCT + Dequantization + Level Shift Functions for decoder
/////////////////////////////////////////////////////////////////////////// */


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiDCTQuantInv8x8LS_JPEG_16s8u_C1R
//
//  Purpose:
//    Inverse DCT transform, de-quantization and level shift
//
//  Parameter:
//    pSrc           - pointer to input 8x8 block of quantized DCT coefficients
//    pDst           - pointer to output color component data
//    dstStep        - line offset for destination data
//    pQuantInvTable - pointer to Quantization table
//
//  Returns:
//    IppStatus
//
//  Notes:
//    DCT is defined in ISO DIS 10918-1,
//    Appendix A - Requrements and guidelines, Annex A, A.3.3 FDCT and IDCT.
//    Quantization is defined in ISO DIS 10918-1,
//    Appendix A - Requrements and guidelines,
//    Annex A, A.3.4 DCT coefficient quantization and dequantization.
//    Level Shift is defined in ISO DIS 10918-1,
//    Appendix A - Requrements and guidelines, Annex A, A.3.1 - Level Shift.
*/

IPPAPI(IppStatus, ippiDCTQuantInv8x8LS_JPEG_16s8u_C1R, (
  const Ipp16s* pSrc,
        Ipp8u*  pDst,
        int     dstStep,
  const Ipp16u* pQuantInvTable))




/* ///////////////////////////////////////////////////////////////////////////
//        JPEG 2000 specific functions
/////////////////////////////////////////////////////////////////////////// */


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiWTFwdRow_B53_JPEG2K_16s_C1R,
//    ippiWTFwdRow_B53_JPEG2K_32s_C1R
//
//  Purpose:
//    Performs forward wavelet transform on image rows
//    (biorthogonal 5,3 filter bank for JPEG 2000 lossless mode).
//
//  Parameters:
//    pSrc        - pointer to source image;
//    srcStep     - step in bytes to each next line of source image ROI;
//    pDstLow     - pointer to low frequency component image ROI;
//    dstLowStep  - step in bytes to each next line
//                  of low frequency component image;
//    pDstHigh    - pointer to high frequency component image ROI;
//    dstHighStep - step in bytes to each next line
//                  of high frequency component image;
//    dstRoiSize  - ROI size for destination images.
//    phase       - relative position of high-pass and low-pass filters.
//
//  Returns:
//    ippStsNoErr      - Ok;
//    ippStsNullPtrErr - some of pointers are NULL;
//    ippStsSizeErr    - the width or height of ROI is less or equal zero;
//
//  Notes:
//    Not any fixed borders extension (wrap, symm.) will be applied!
//    Source image must have valid and accessible horizontal border data
//    outside of ROI.
//
//    Only the same ROI sizes for destination images are supported.
//
//    Source ROI size should be calculated by the following rule:
//      srcRoiSize.width  = 2 * dstRoiSize.width;
//      srcRoiSize.height = dstRoiSize.height.
//
//    If phase is ippWTFilterFirstLow, it's required to apply
//      left border of width 2 and right border of width 1.
//    If phase is ippWTFilterFirstHigh, it's required to apply
//      left border of width 1 and right border of width 2.
//
*/

IPPAPI(IppStatus, ippiWTFwdRow_B53_JPEG2K_16s_C1R, (
  const Ipp16s*           pSrc,
        int               srcStep,
        Ipp16s*           pDstLow,
        int               dstLowStep,
        Ipp16s*           pDstHigh,
        int               dstHighStep,
        IppiSize          dstRoiSize,
        IppiWTFilterFirst phase))

IPPAPI(IppStatus, ippiWTFwdRow_B53_JPEG2K_32s_C1R, (
  const Ipp32s*           pSrc,
        int               srcStep,
        Ipp32s*           pDstLow,
        int               dstLowStep,
        Ipp32s*           pDstHigh,
        int               dstHighStep,
        IppiSize          dstRoiSize,
        IppiWTFilterFirst phase))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiWTFwdCol_B53_JPEG2K_16s_C1R,
//    ippiWTFwdCol_B53_JPEG2K_32s_C1R
//
//  Purpose:
//    Performs forward wavelet transform on image columns
//    (biorthogonal 5,3 filter bank for JPEG 2000 lossless mode).
//
//  Parameters:
//    pSrc        - pointer to source image;
//    srcStep     - step in bytes to each next line of source image ROI;
//    pDstLow     - pointer to low frequency component image ROI;
//    dstLowStep  - step in bytes to each next line
//                  of low frequency component image;
//    pDstHigh    - pointer to high frequency component image ROI;
//    dstHighStep - step in bytes to each next line
//                  of high frequency component image;
//    dstRoiSize  - ROI size for destination images.
//    phase       - relative position of high-pass and low-pass filters.
//
//  Returns:
//    ippStsNoErr      - Ok;
//    ippStsNullPtrErr - some of pointers are NULL;
//    ippStsSizeErr    - the width or height of ROI is less or equal zero;
//
//  Notes:
//    Not any fixed borders extension (wrap, symm.) will be applied!
//    Source image must have valid and accessible horizontal border data
//    outside of ROI.
//
//    Only the same ROI sizes for destination images are supported.
//
//    Source ROI size should be calculated by the following rule:
//      srcRoiSize.width  =     dstRoiSize.width;
//      srcRoiSize.height = 2 * dstRoiSize.height.
//
//    If phase is ippWTFilterFirstLow, it's required to apply
//      top border of width 2 and bottom border of width 1.
//    If phase is ippWTFilterFirstHigh, it's required to apply
//      top border of width 1 and bottom border of width 2.
//
*/

IPPAPI(IppStatus, ippiWTFwdCol_B53_JPEG2K_16s_C1R, (
  const Ipp16s*           pSrc,
        int               srcStep,
        Ipp16s*           pDstLow,
        int               dstLowStep,
        Ipp16s*           pDstHigh,
        int               dstHighStep,
        IppiSize          dstRoiSize,
        IppiWTFilterFirst phase))

IPPAPI(IppStatus, ippiWTFwdCol_B53_JPEG2K_32s_C1R, (
  const Ipp32s*           pSrc,
        int               srcStep,
        Ipp32s*           pDstLow,
        int               dstLowStep,
        Ipp32s*           pDstHigh,
        int               dstHighStep,
        IppiSize          dstRoiSize,
        IppiWTFilterFirst phase))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiWTInvRow_B53_JPEG2K_16s_C1R,
//    ippiWTInvRow_B53_JPEG2K_32s_C1R
//
//  Purpose:
//    Performs inverse wavelet transform on image rows
//    (biorthogonal 5,3 filter bank for JPEG 2000 lossless mode).
//
//  Parameters:
//    pSrcLow     - pointer to low frequency component image ROI;
//    srcLowStep  - step in bytes to each next line
//                  of low frequency component image;
//    pSrcHigh    - pointer to high frequency component image ROI;
//    srcHighStep - step in bytes to each next line
//                  of high frequency component image;
//    srcRoiSize  - step in bytes to each next line
//                  of high frequency component image;
//    pDst        - destination image ROI;
//    dstStep     - step in bytes to each next line
//                  of source image ROI;
//    phase       - relative position of high-pass and low-pass filters.
//
//  Returns:
//    ippStsNoErr      - Ok;
//    ippStsNullPtrErr - some of pointers are NULL;
//    ippStsSizeErr    - the width or height of ROI is less or equal zero;
//
//  Notes:
//    Not any fixed borders extension (wrap, symm.) will be applied!
//    Source images must have valid and accessible horizontal border data
//    outside of ROI.
//
//    Only the same ROI sizes for source images are supported.
//
//    Destinageion ROI size should be calculated by the following rule:
//      dstRoiSize.width  = 2 * dstRoiSize.width;
//      dstRoiSize.height = dstRoiSize.height.
//
//    For low frequency component:
//      if phase is ippWTFilterFirstLow, it's required to apply
//      left border of width 0 and right border of width 1.
//      If phase is ippWTFilterFirstHigh, it's required to apply
//      left border of width 1 and right border of width 0.
//    For high frequency component it's always required to have
//      left and right border of equal width 1.
//
*/

IPPAPI(IppStatus, ippiWTInvRow_B53_JPEG2K_16s_C1R, (
  const Ipp16s*           pSrcLow,
        int               srcLowStep,
  const Ipp16s*           pSrcHigh,
        int               srcHighStep,
        IppiSize          srcRoiSize,
        Ipp16s*           pDst,
        int               dstStep,
        IppiWTFilterFirst phase))

IPPAPI(IppStatus, ippiWTInvRow_B53_JPEG2K_32s_C1R, (
  const Ipp32s*           pSrcLow,
        int               srcLowStep,
  const Ipp32s*           pSrcHigh,
        int               srcHighStep,
        IppiSize          srcRoiSize,
        Ipp32s*           pDst,
        int               dstStep,
        IppiWTFilterFirst phase))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiWTInvCol_B53_JPEG2K_16s_C1R,
//    ippiWTInvCol_B53_JPEG2K_32s_C1R
//
//  Purpose:
//    Performs inverse wavelet transform on image columns
//    (biorthogonal 5,3 filter bank for JPEG 2000 lossless mode).
//
//  Parameters:
//    pSrcLow     - pointer to low frequency component image ROI;
//    srcLowStep  - step in bytes to each next line
//                  of low frequency component image;
//    pSrcHigh    - pointer to high frequency component image ROI;
//    srcHighStep - step in bytes to each next line
//                  of high frequency component image;
//    srcRoiSize  - step in bytes to each next line
//                  of high frequency component image;
//    pDst        - destination image ROI;
//    dstStep     - step in bytes to each next line
//                  of source image ROI;
//    phase       - relative position of high-pass and low-pass filters.
//
//  Returns:
//    ippStsNoErr      - Ok;
//    ippStsNullPtrErr - any of the pointers is NULL;
//    ippStsSizeErr    - the width or height of ROI is less or equal zero;
//
//  Notes:
//    Not any fixed borders extension (wrap, symm.) will be applied!
//    Source images must have valid and accessible horizontal border data
//    outside of ROI.
//
//    Only the same ROI sizes for source images are supported.
//
//    Destination ROI size should be calculated by the following rule:
//      dstRoiSize.width  = dstRoiSize.width;
//      dstRoiSize.height = dstRoiSize.height * 2.
//
//    For low frequency component:
//      if phase is ippWTFilterFirstLow, it's required to apply
//      left border of width 0 and right border of width 1.
//      If phase is ippWTFilterFirstHigh, it's required to apply
//      left border of width 1 and right border of width 0.
//    For high frequency component it's always required to have
//      left and right border of equal width 1.
//
*/

IPPAPI(IppStatus, ippiWTInvCol_B53_JPEG2K_16s_C1R, (
  const Ipp16s*           pSrcLow,
        int               srcLowStep,
  const Ipp16s*           pSrcHigh,
        int               srcHighStep,
        IppiSize          srcRoiSize,
        Ipp16s*           pDst,
        int               dstStep,
        IppiWTFilterFirst phase))

IPPAPI(IppStatus, ippiWTInvCol_B53_JPEG2K_32s_C1R, (
  const Ipp32s*           pSrcLow,
        int               srcLowStep,
  const Ipp32s*           pSrcHigh,
        int               srcHighStep,
        IppiSize          srcRoiSize,
        Ipp32s*           pDst,
        int               dstStep,
        IppiWTFilterFirst phase))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiWTFwdRow_D97_JPEG2K_32f_C1R,
//
//  Purpose:
//    Performs forward wavelet transform on image rows
//    (Cohen-Daubechies-Feauveau 9,7 filter bank for JPEG 2000 lossy mode).
//
//  Parameters:
//    pSrc        - pointer to source image;
//    srcStep     - step in bytes to each next line of source image ROI;
//    pDstLow     - pointer to low frequency component image ROI;
//    dstLowStep  - step in bytes to each next line
//                  of low frequency component image;
//    pDstHigh    - pointer to high frequency component image ROI;
//    dstHighStep - step in bytes to each next line
//                  of high frequency component image;
//    dstRoiSize  - ROI size for destination images.
//    phase       - relative position of high-pass and low-pass filters.
//
//  Returns:
//    ippStsNoErr      - Ok;
//    ippStsNullPtrErr - some of pointers are NULL;
//    ippStsSizeErr    - the width or height of ROI is less or equal zero;
//
//  Notes:
//    Not any fixed borders extension (wrap, symm.) will be applied!
//    Source image must have valid and accessible horizontal border data
//    outside of ROI.
//
//    Only the same ROI sizes for destination images are supported.
//
//    Source ROI size should be calculated by the following rule:
//      srcRoiSize.width  = 2 * dstRoiSize.width;
//      srcRoiSize.height = dstRoiSize.height.
//
//    If phase is ippWTFilterFirstLow, it's required to apply
//      left border of width 4 and right border of width 3.
//    If phase is ippWTFilterFirstHigh, it's required to apply
//      left border of width 3 and right border of width 4.
//
*/

IPPAPI(IppStatus, ippiWTFwdRow_D97_JPEG2K_32f_C1R, (
  const Ipp32f*           pSrc,
        int               srcStep,
        Ipp32f*           pDstLow,
        int               dstLowStep,
        Ipp32f*           pDstHigh,
        int               dstHighStep,
        IppiSize          dstRoiSize,
        IppiWTFilterFirst phase))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiWTFwdCol_D97_JPEG2K_32f_C1R
//
//  Purpose:
//    Performs forward wavelet transform on image columns
//    (Cohen-Daubechies-Feauveau 9,7 filter bank for JPEG 2000 lossy mode).
//
//  Parameters:
//    pSrc        - pointer to source image;
//    srcStep     - step in bytes to each next line of source image ROI;
//    pDstLow     - pointer to low frequency component image ROI;
//    dstLowStep  - step in bytes to each next line
//                  of low frequency component image;
//    pDstHigh    - pointer to high frequency component image ROI;
//    dstHighStep - step in bytes to each next line
//                  of high frequency component image;
//    dstRoiSize  - ROI size for destination images.
//    phase       - relative position of high-pass and low-pass filters.
//
//  Returns:
//    ippStsNoErr      - Ok;
//    ippStsNullPtrErr - some of pointers are NULL;
//    ippStsSizeErr    - the width or height of ROI is less or equal zero;
//
//  Notes:
//    Not any fixed borders extension (wrap, symm.) will be applied!
//    Source image must have valid and accessible horizontal border data
//    outside of ROI.
//
//    Only the same ROI sizes for destination images are supported.
//
//    Source ROI size should be calculated by the following rule:
//      srcRoiSize.width  =     dstRoiSize.width;
//      srcRoiSize.height = 2 * dstRoiSize.height.
//
//    If phase is ippWTFilterFirstLow, it's required to apply
//      top border of width 4 and bottom border of width 3.
//    If phase is ippWTFilterFirstHigh, it's required to apply
//      top border of width 3 and bottom border of width 4.
//
*/

IPPAPI(IppStatus, ippiWTFwdCol_D97_JPEG2K_32f_C1R, (
  const Ipp32f*           pSrc,
        int               srcStep,
        Ipp32f*           pDstLow,
        int               dstLowStep,
        Ipp32f*           pDstHigh,
        int               dstHighStep,
        IppiSize          dstRoiSize,
        IppiWTFilterFirst phase))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiWTInvRow_D97_JPEG2K_32f_C1R,
//
//  Purpose:
//    Performs inverse wavelet transform on image rows
//    (Cohen-Daubechies-Feauveau 9,7 filter bank for JPEG 2000 lossy mode).
//
//  Parameters:
//    pSrcLow     - pointer to low frequency component image ROI;
//    srcLowStep  - step in bytes to each next line
//                  of low frequency component image;
//    pSrcHigh    - pointer to high frequency component image ROI;
//    srcHighStep - step in bytes to each next line
//                  of high frequency component image;
//    srcRoiSize  - step in bytes to each next line
//                  of high frequency component image;
//    pDst        - destination image ROI;
//    dstStep     - step in bytes to each next line
//                  of source image ROI;
//    phase       - relative position of high-pass and low-pass filters.
//
//  Returns:
//    ippStsNoErr      - Ok;
//    ippStsNullPtrErr - some of pointers are NULL;
//    ippStsSizeErr    - the width or height of ROI is less or equal zero;
//
//  Notes:
//    Not any fixed borders extension (wrap, symm.) will be applied!
//    Source images must have valid and accessible horizontal border data
//    outside of ROI.
//
//    Only the same ROI sizes for source images are supported.
//
//    Destinageion ROI size should be calculated by the following rule:
//      dstRoiSize.width  = 2 * dstRoiSize.width;
//      dstRoiSize.height = dstRoiSize.height.
//
//    For low frequency component:
//      if phase is ippWTFilterFirstLow, it's required to apply
//      left border of width 1 and right border of width 2.
//      If phase is ippWTFilterFirstHigh, it's required to apply
//      left border of width 2 and right border of width 1.
//    For high frequency component it's always required to have
//      left and right border of equal width 2.
//
*/

IPPAPI(IppStatus, ippiWTInvRow_D97_JPEG2K_32f_C1R, (
  const Ipp32f*           pSrcLow,
        int               srcLowStep,
  const Ipp32f*           pSrcHigh,
        int               srcHighStep,
        IppiSize          srcRoiSize,
        Ipp32f*           pDst,
        int               dstStep,
        IppiWTFilterFirst phase))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiWTInvCol_D97_JPEG2K_32f_C1R
//
//  Purpose:
//    Performs inverse wavelet transform on image columns
//    (Cohen-Daubechies-Feauveau 9,7 filter bank for JPEG 2000 lossy mode).
//
//  Parameters:
//    pSrcLow     - pointer to low frequency component image ROI;
//    srcLowStep  - step in bytes to each next line
//                  of low frequency component image;
//    pSrcHigh    - pointer to high frequency component image ROI;
//    srcHighStep - step in bytes to each next line
//                  of high frequency component image;
//    srcRoiSize  - step in bytes to each next line
//                  of high frequency component image;
//    pDst        - destination image ROI;
//    dstStep     - step in bytes to each next line
//                  of source image ROI;
//    phase       - relative position of high-pass and low-pass filters.
//
//  Returns:
//    ippStsNoErr      - Ok;
//    ippStsNullPtrErr - any of the pointers is NULL;
//    ippStsSizeErr    - the width or height of ROI is less or equal zero;
//
//  Notes:
//    Not any fixed borders extension (wrap, symm.) will be applied!
//    Source images must have valid and accessible horizontal border data
//    outside of ROI.
//
//    Only the same ROI sizes for source images are supported.
//
//    Destination ROI size should be calculated by the following rule:
//      dstRoiSize.width  = dstRoiSize.width;
//      dstRoiSize.height = dstRoiSize.height * 2.
//
//    For low frequency component:
//      if phase is ippWTFilterFirstLow, it's required to apply
//      left border of width 1 and right border of width 2.
//      If phase is ippWTFilterFirstHigh, it's required to apply
//      top border of width 2 and bottom border of width 1.
//    For high frequency component it's always required to have
//      left and right border of equal width 2.
//
*/

IPPAPI(IppStatus, ippiWTInvCol_D97_JPEG2K_32f_C1R, (
  const Ipp32f*           pSrcLow,
        int               srcLowStep,
  const Ipp32f*           pSrcHigh,
        int               srcHighStep,
        IppiSize          srcRoiSize,
        Ipp32f*           pDst,
        int               dstStep,
        IppiWTFilterFirst phase))




/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiEncodeInitAlloc_JPEG2K
//
//  Purpose:
//    Allocate and initialize entropy encoder state structure.
//
//  Parameters:
//    pState           - pointer to the variable that returns the pointer
//                       to the allocated and initialized encoder state structure,
//    codeBlockMaxSize - maximal size of codeblock for coding.
//
//  Returns:
//   ippStsNoErr       - Ok,
//   ippStsSizeErr     - error in size of codeblock,
//   ippStsMemAllocErr - no memory to allocate state structure.
//
*/

IPPAPI(IppStatus, ippiEncodeInitAlloc_JPEG2K, (
  IppiEncodeState_JPEG2K** pState,
  IppiSize                 codeBlockMaxSize))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiEncodeFree_JPEG2K
//
//  Purpose:
//    Free and deallocate entropy encoder state structure.
//
//  Parameters:
//    pState  - pointer to allocated and initialized encoder state structure,
//
//  Returns:
//   ippStsNoErr            - Ok,
//   ippStsNullPtrErr       - Pointer to the context structure is NULL;
//   ippStsContextMatchErr  - Mismatch context structure.
//
*/

IPPAPI(IppStatus, ippiEncodeFree_JPEG2K, (
  IppiEncodeState_JPEG2K* pState))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiEncodeLoadCodeBlock_JPEG2K_32s_C1R
//
//  Purpose:
//    First coding procedure that prepare data for coding.
//
//  Parameters:
//    pSrc           - pointer to source codeblock,
//    srcStep        - step in bytes to each next line of codeblock,
//    codeBlockSize  - size of codeblock,
//    pState         - pointer to allocated and initialized
//                     encoder state structure,
//    subband        - subband that is represented by codeblock,
//    magnBits       - magnitude (non fractional) bits
//                     in integer representation,
//    codeStyleFlags - options for coding,
//    mqTermType     - termination mode for MQ coder,
//    mqRateAppr     - rate estimation model,
//    pSfBits        - pointer to variable that returns a number of significant bit planes,
//    pNOfPasses     - pointer to variable that returns a number of coding passes,
//    pNOfTermPasses - pointer to variable that returns a number of terminated coding passes.
//
//  Returns:
//    ippStsNoErr            - Ok,
//    ippStsNullPtrErr       - any of the pointers is NULL,
//    ippStsSizeErr          - error in size of codeblock,
//    ippStsContextMatchErr  - Mismatch context structure.
//
//  Notes:
//    As an example if maximum value of source pixels is 0xA (binary 1010),
//    then sfBits should return 4 significant bits. The higher bits will not
//    be coded.
//
//   Only significant non-fractional bits
//   in integer representation will be coded.
//   magnBits passes a number of non-fractional bits.
//   For example, if magnBits = 11,
//   the 20 (31-11) least-significant bits will not be coded.
//
*/

IPPAPI(IppStatus, ippiEncodeLoadCodeBlock_JPEG2K_32s_C1R, (
  const Ipp32s*                 pSrc,
        int                     srcStep,
        IppiSize                codeBlockSize,
        IppiEncodeState_JPEG2K* pState,
        IppiWTSubband           subband,
        int                     magnBits,
        IppiMQTermination       mqTermType,
        IppiMQRateAppr          mqRateAppr,
        int                     codeStyleFlags,
        int*                    pSfBits,
        int*                    pNOfPasses,
        int*                    pNOfTermPasses))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiEncodeStoreBits_JPEG2K_1u_C1R
//
//  Purpose:
//    Second coding procedure that forms output stream.
//
//  Parameters:
//    pDst         - pointer to destination data buffer,
//    pDstLen      - pointer to destination buffer length,
//    pState       - pointer to allocated and initialized
//                  encoder state structure,
//    pIsNotFinish - pointer to variable that indicates finishing of coding.
//
//  Returns:
//    ippStsNoErr           - Ok,
//    ippStsNullPtrErr      - any of pointers is NULL,
//    ippStsSizeErr         - size of buffer less or equal 0,
//    ippStsContextMatchErr - Mismatch context structure.
//
//  Notes:
//    dstLen parameter used both for reading and writing,
//    it should be passed to function with valid buffer length
//    and it will be returned with used (filled) buffer length.
//    The function can be used on the following manner:
//
//    int isNotFinish = 1;
//    while(isNotFinish)
//    {
//      int len = BUFFER_LEN;
//      ippiEncodeStoreBits_JPEG2K_1u(buffer, &len, state, &isNotFinish);
//      // writing_append(writing_obj, (char*)buffer, len);
//    }
//
//
*/

IPPAPI(IppStatus, ippiEncodeStoreBits_JPEG2K_1u, (
  Ipp8u*                  pDst,
  int*                    pDstLen,
  IppiEncodeState_JPEG2K* pState,
  int*                    pIsNotFinish))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiEncodeGetPassTermLen_JPEG2K
//
//  Purpose:
//    Return the length of the terminated coding pass with a given
//    terminated pass number.
//
//  Parameters:
//    pState     - pointer to allocated and initialized
//                 encoder state structure,
//    passNumber - pass number,
//    pPassLen   - pointer to variable to return pass length.
//
//
//  Returns:
//    ippStsNoErr               - Ok,
//    ippStsNullPtrErr          - any of pointers is NULL,
//    ippStsContextMatchErr     - mismatch context structure,
//    ippStsJPEG2KBadPassNumber - pass number exceeds allowed boundaries.
//
*/

IPPAPI(IppStatus, ippiEncodeGetTermPassLen_JPEG2K, (
  IppiEncodeState_JPEG2K* pState,
  int                     passNumber,
  int*                    pPassLen))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiEncodeGetRate_JPEG2K
//
//  Purpose:
//    Return the esimated target bit-rate for a given pass number.
//
//  Parameters:
//    pState     - pointer to allocated and initialized encoder state structure,
//    passNumber - pass number,
//    pRate      - pointer to the variable that returns esimated rate.
//
//
//  Returns:
//    ippStsNoErr               - Ok,
//    ippStsNullPtrErr          - any of pointers is NULL,
//    ippStsContextMatchErr     - mismatch context structure,
//    ippStsJPEG2KBadPassNumber - pass number exceeds allowed boundaries.
//
*/

IPPAPI(IppStatus, ippiEncodeGetRate_JPEG2K, (
  IppiEncodeState_JPEG2K* pState,
  int                     passNumber,
  int*                    pRate))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiEncodeGetDist_JPEG2K
//
//  Purpose:
//    Return the esimated distortion for a given pass number.
//
//  Parameters:
//    pState     - pointer to allocated and initialized encoder state structure,
//    passNumber - pass number,
//    pDist      - pointer to the variable that returns esimated distortion.
//
//
//  Returns:
//    ippStsNoErr               - Ok,
//    ippStsNullPtrErr          - any of pointers is NULL,
//    ippStsContextMatchErr     - mismatch context structure,
//    ippStsJPEG2KBadPassNumber - pass number exceeds allowed boundaries.
//
*/

IPPAPI(IppStatus, ippiEncodeGetDist_JPEG2K, (
  IppiEncodeState_JPEG2K* pState,
  int                     passNumber,
  Ipp64f*                 pDist))




/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiDecodeGetBufSize_JPEG2K
//
//  Purpose:
//    Return size of working buffer.
//
//  Parameters:
//    codeBlockMaxSize - maximal size of codeblock for coding.
//    pSize            - pointer to the variable that returns the size of working buffer
//
//  Returns:
//   ippStsNoErr      - Ok,
//   ippStsNullPtrErr - any of the pointers is NULL,
//   ippStsSizeErr    - error in size of codeblock,
//
*/

IPPAPI(IppStatus, ippiDecodeGetBufSize_JPEG2K, (
  IppiSize  codeBlockMaxSize,
  int*      pSize))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiDecodeCodeBlock_JPEG2K_1u32s_C1R
//
//  Purpose:
//    Decode compressed JPEG2000 codeblock data.
//
//  Parameters:
//    pSrc           - pointer to the source of compressed data,
//    pDst           - pointer to the destination for codeblock,
//    dstStep        - step in bytes to each next line of codeblock,
//    codeBlockSize  - size of codeblock,
//    subband        - subband that is represented by codeblock,
//    sfBits         - number of significant bit planes,
//    nOfPasses      - number of coding passes,
//    pTermPassLen   - pointer to the array of legnths for each terminated pass,
//    nOfTermPasses  - number of terminated passes,
//    codeStyleFlags - options for coding,
//    pErrorBitPlane - pointer to the bit plane that contain first error returned for
//                     damaged codeblock,
//    pBuffer        - pointer to the working buffer.
//
//  Returns:
//    ippStsNoErr                  - Ok,
//    ippStsNullPtrErr             - any of pointers is NULL,
//    ippStsSizeErr                - error in size of codeblock,
//    ippStsJPEG2KDamagedCodeBlock - codeblock contains damaged data.
//
//  Notes:
//    errorBitPlane can be NULL if such information does not required.
//
*/

IPPAPI(IppStatus, ippiDecodeCodeBlock_JPEG2K_1u32s_C1R, (
  const Ipp8u*         pSrc,
        Ipp32s*        pDst,
        int            dstStep,
        IppiSize       codeBlockSize,
        IppiWTSubband  subband,
        int            sfBits,
        int            nOfPasses,
  const int*           pTermPassLen,
        int            nOfTermPasses,
        int            codeStyleFlags,
        int*           pErrorBitPlane,
        Ipp8u*         pBuffer))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiRCTFwd_JPEG2K_32s_C3P3R
//
//  Purpose:
//    forward reversible component transformation
//
//  Parameter:
//    pSrc      pointer to input data
//    srcStep   line offset in input data
//    pDst      pointer to pointers to output data
//    dstStep   line offset in output data
//    roiSize   ROI size
//
//  Returns:
//    IppStatus
//
//  Notes:
//    color conversion equations:
//      Y0 = (I0 + 2*I1 + I2) >> 2
//      Y1 = I2 - I1
//      Y2 = I0 - I1
*/

IPPAPI(IppStatus, ippiRCTFwd_JPEG2K_32s_C3P3R, (
  const Ipp32s*  pSrc,
        int      srcStep,
        Ipp32s*  pDst[3],
        int      dstStep,
        IppiSize roiSize))


/* ////////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiRCTFwd_JPEG2K_32s_P3IR
//
//  Purpose:
//    forward reversible color conversion (three planes, in-place)
//
//  Parameter:
//    pSrcDst    pointer to pointers to input/ouput data
//    srcDstStep line offset in input/ouput data
//    roiSize    ROI size
//
//  Returns:
//    IppStatus
//
//  Notes:
//    color conversion equations:
//      Y0 = (I0 + 2*I1 + I2) >> 2
//      Y1 = I2 - I1
//      Y2 = I0 - I1
*/

IPPAPI(IppStatus, ippiRCTFwd_JPEG2K_32s_P3IR, (
  Ipp32s*  pSrcDst[3],
  int      srcDstStep,
  IppiSize roiSize))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiRCTInv_JPEG2K_32s_P3C3R
//
//  Purpose:
//    inverse reversible component transformation
//
//  Parameter:
//    pSrc      pointer to pointers to input data
//    srcStep   line offset in input data
//    pDst      pointer to output data
//    dstStep   line offset in output data
//    roiSize   ROI size
//
//  Returns:
//    IppStatus
//
//  Notes:
//    color conversion equations:
//      I1 = Y0 - ((Y2 + Y1) >> 2)
//      I0 = Y2 + I1
//      I2 = Y1 + I1
*/

IPPAPI(IppStatus, ippiRCTInv_JPEG2K_32s_P3C3R, (
  const Ipp32s*  pSrc[3],
        int      srcStep,
        Ipp32s*  pDst,
        int      dstStep,
        IppiSize roiSize))


/* ////////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiRCTInv_JPEG2K_32s_P3IR
//
//  Purpose:
//    inverse reversible color conversion (three planes, in-place)
//
//  Parameter:
//    pSrcDst    pointer to pointers to input/ouput data
//    srcDstStep line offset in input/ouput data
//    roiSize    ROI size
//
//  Returns:
//    IppStatus
//
//  Notes:
//    color conversion equations:
//      I1 = Y0 - ((Y2 + Y1) >> 2)
//      I0 = Y2 + I1
//      I2 = Y1 + I1
*/

IPPAPI(IppStatus, ippiRCTInv_JPEG2K_32s_P3IR, (
  Ipp32s*  pSrcDst[3],
  int      srcDstStep,
  IppiSize roiSize))


#ifdef __cplusplus
}
#endif

#endif /* __IPPJ_H__ */

/* //////////////////////// End of file "ippj.h" ////////////////////////// */

