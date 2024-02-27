/* ////////////////////////////////// "ippmp.h" ////////////////////////////////
//
//                  INTEL CORPORATION PROPRIETARY INFORMATION
//     This software is supplied under the terms of a license agreement or
//     nondisclosure agreement with Intel Corporation and may not be copied
//     or disclosed except in accordance with the terms of that agreement.
//      	Copyright(c) 1999-2003 Intel Corporation. All Rights Reserved.
//
//           	Intel(R) Integrated Performance Primitives
//                 	Media Processing (ippmp)
//
*/

#if !defined( __IPPMP_H__ ) || defined( _OWN_BLDPCS )
#define __IPPMP_H__

#ifndef __IPPDEFS_H__
#include "ippdefs.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif


/***** Data Structures and Macro ********************************************/

/* Macro  */

#define IPP_MP3_GRANULE_LEN     576
#define IPP_MP3_SF_BUF_LEN      40  /* scalefactor buffer length */
#define IPP_MP3_V_BUF_LEN       512 /* V data buffer length */

#define IPP_MP3_ID_MPEG1        1
#define IPP_MP3_ID_MPEG2        0


#if !defined( _OWN_BLDPCS )


/* scalefactor band table length for 3 sampling frequencies */
/* for long/short block  */
#define IPP_MP3_SFB_TABLE_LONG_LEN	138
#define IPP_MP3_SFB_TABLE_SHORT_LEN	84

typedef const Ipp16s IppMP3ScaleFactorBandTableLong[IPP_MP3_SFB_TABLE_LONG_LEN];
typedef const Ipp16s IppMP3ScaleFactorBandTableShort[IPP_MP3_SFB_TABLE_SHORT_LEN];


/* Data Structures */
/* MPEG -1, -2 BC header, 32 bits. */
/* See ISO/IEC 11172-3, sect 2.4.1.3, 2.4.2.3, 2.4.2.4 */

typedef struct
{
  int id;              /* ID 1: MPEG-1, 0: MPEG-2 */
  int layer;           /* layer index 0x3: Layer I */
                       /*             0x2: Layer II */
                       /*             0x1: Layer III */
  int protectionBit;   /* CRC flag 0: CRC on, 1: CRC off */
  int bitRate;         /* bit rate index */
  int samplingFreq;    /* sampling frequency index */
  int paddingBit;      /* padding flag 0: no padding, 1 padding  */
  int privateBit;      /* private_bit, no use  */
  int mode;            /* mono/stereo select information */
  int modeExt;         /* extension to mode */
  int copyright;       /* copyright or not, 0: no, 1: yes  */
  int originalCopy;    /* original bitstream or copy, 0: copy, 1: original */
  int emphasis;        /* flag indicates the type of de-emphasis */
                       /* that shall be used */
  int CRCWord;         /* CRC-check word */

} IppMP3FrameHeader;


/* MP3 side informatin structure , for each granule.
// Other info main_data_begin, private_bits, scfsi are not included here.
// please refer to reference ISO/IEC 11172-3:1993, 2.4.1.7, 2.4.2.7. ISO/IEC
// 13818-3:1998, 2.4.1.7 ).
*/

typedef struct
{
  int  part23Len;       /* the number of bits for scale factors */
                        /* and Huffman data */
  int  bigVals;         /* the half number of Huffman data whose maximum */
                        /* amplitudes are greater than 1 */
  int  globGain;        /* the quantizer step size information */
  int  sfCompress;      /* information to select the number of bits */
                        /* used for the transmission of the scale factors */
  int  winSwitch;       /* flag signals that the block uses an other than */
                        /* normal window */
  int  blockType;       /* flag indicates the window type */
  int  mixedBlock;      /* flag 0: non mixed block, 1: mixed block */
  int  pTableSelect[3]; /* Huffman table index for the 3 regions */
                        /* in big-values field */
  int  pSubBlkGain[3];  /* gain offset from the global gain for one subblock */
  int  reg0Cnt;         /* the number of scale factor bands at the boundary */
                        /* of the first region of the big-values field  */
  int  reg1Cnt;         /* similar to reg0Cnt, but of the second region */
  int  preFlag;         /* flag of high frequency amplification */
  int  sfScale;         /* scale to the scale factors */
  int  cnt1TabSel;      /* Huffman table index for the count1 region */
                        /* of quadruples */

} IppMP3SideInfo;



/* Video Components */
typedef enum
{
  IPP_VIDEO_LUMINANCE,        /* Luminance component   */
  IPP_VIDEO_CHROMINANCE,      /* Chrominance component */
  IPP_VIDEO_ALPHA             /* Alpha component       */
} IppVideoComponent;


/* Macroblock Types */
typedef enum
{
  IPP_VIDEO_INTER        = 0,    /* P picture or P-VOP */
  IPP_VIDEO_INTER_Q      = 1,    /* P picture or P-VOP */
  IPP_VIDEO_INTER4V      = 2,    /* P picture or P-VOP */
  IPP_VIDEO_INTRA        = 3,    /* I and P picture, or I- and P-VOP */
  IPP_VIDEO_INTRA_Q      = 4,    /* I and P picture, or I- and P-VOP */
  IPP_VIDEO_INTER4V_Q    = 5,    /* P picture or P-VOP(H.263)*/
  IPP_VIDEO_DIRECT       = 6,    /* B picture or B-VOP (MPEG-4 only) */
  IPP_VIDEO_INTERPOLATE  = 7,    /* B picture or B-VOP */
  IPP_VIDEO_BACKWARD     = 8,    /* B picture or B-VOP */
  IPP_VIDEO_FORWARD      = 9     /* B picture or B-VOP */
} IppMacroblockType;


/* Motion Vector */
typedef struct _IppMotionVector
{
  Ipp16s  dx;
  Ipp16s  dy;
} IppMotionVector;


/* Transparent Status */
enum
{
  IPP_VIDEO_TRANSPARENT  = 0,
  IPP_VIDEO_PARTIAL      = 1,
  IPP_VIDEO_OPAQUE       = 2
};


/* Direction */
enum {
  IPP_VIDEO_NONE         = 0,
  IPP_VIDEO_HORIZONTAL   = 1,
  IPP_VIDEO_VERTICAL     = 2,
  IPP_VIDEO_DCONLY       = 3
};


enum
{
  IPP_DCScalerLinear     = 0,
  IPP_DCScalerNonLinear  = 1
};


#endif /* _OWN_BLDPCS */




/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippmpGetLibVersion
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

IPPAPI( const IppLibraryVersion*, ippmpGetLibVersion, (void) )




/***** Audio Coding Functions ***********************************************/

/***** MP3 Functions *****/

/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippsUnpackFrameHeader_MP3
//
//  Purpose:
//    Unpacks the audio frame header.
//    If CRC is enabled, this function also unpacks the CRC word.
//
//  Parameter:
//    ppBitStream   - double pointer to the first byte of the MP3 frame header
//    pFrameHeader  - pointer to the MP3 frame header structure
//
//  Returns:
//    IppStatus
//
//  Notes:
//    Before calling ippsUnpackFrameHeader_MP3, the decoder application
//    should locate the bit stream sync word and ensure that *ppBitStream
//    points to the first byte of the 32-bit frame header.
//    The functions does not detect corrupted frame headers.
*/

IPPAPI(IppStatus, ippsUnpackFrameHeader_MP3, (
  Ipp8u**            ppBitStream,
  IppMP3FrameHeader* pFrameHeader))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippsUnpackSideInfo_MP3
//
//  Purpose:
//    Unpacks the side information from the input bitstream.
//
//  Parameter:
//    ppBitStream       - double pointer to the first byte of the side
//                        information associated with the current frame in
//                        the bit stream buffer
//    pDstSideInfo      - pointer to the MP3 side information structure(s).
//    pDstMainDataBegin - pointer to the main_data_begin field
//    pDstPrivateBits   - pointer to the private bits field
//    pDstScfsi         - pointer to the scalefactor selection information
//                        associated with the current frame,
//    pFrameHeader      - pointer to the structure that contains
//                        the unpacked MP3 frame header.
//
//  Returns:
//    IppStatus
//
//  Notes:
//    Before ippsUnpackSideInfo_Mp3 is called, the pointer *ppBitStream must
//    point to the first byte of the bit stream that contains the side
//    information associated with the current frame. Before returning
//    to the caller, the function updates the pointer *ppBitStream such that
//    it references the next byte after the side information.
*/

IPPAPI(IppStatus, ippsUnpackSideInfo_MP3, (
  Ipp8u**            ppBitStream,
  IppMP3SideInfo*    pDstSideInfo,
  int*               pDstMainDataBegin,
  int*               pDstPrivateBits,
  int*               pDstScfsi,
  IppMP3FrameHeader* pFrameHeader))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippsUnpackScaleFactors_MP3_1u8s
//
//  Purpose:
//    Unpacks short and/or long block scalefactors for one granule of
//    one channel and places the results in the vector pDstScaleFactor.
//
//  Parameter:
//    ppBitStream     - double pointer to the first bitstream buffer byte
//                      that is associated with the scalefactors for the
//                      current frame, granule, and channel information
//    pOffset         - pointer to the next bit in the byte referenced
//                      by *ppBitStream. Valid within the range of 0 to 7,
//                      where 0 corresponds to the most significant bit and
//                      7 corresponds to the least significant bit.
//    pDstScaleFactor - pointer to the scalefactor vector for long and/or
//                      short blocks.
//    pSideInfo       - pointer to the MP3 side information structure
//                      associated with the current granule and channel
//    pScfsi          - pointer to scalefactor selection information for
//                      the current channel
//    pFrameHeader    - pointer to MP3 frame header structure
//                      for the current frame
//    granule         - granule index; can take on the values of either 0 or 1
//    channel         - channel index; can take on the values of either 0 or 1
//
//  Returns:
//    IppStatus
//
//  Notes:
//    Before returning to the caller, the primitive updates *ppBitStream
//    and *pOffset such that they point to the next available bit
//    in the input bitstream.
//    Note on MPEG-2 intensity mode: if the intensity position is equal to the
//    maximum value of intensity position (an illegal position), the illegal
//    position is set to negative. Thus, in the requantization module,
//    negative positions indicate illegal positions. Those scalefactors that
//    are not treated as intensity positions must be made positive
//    before using them.
*/

IPPAPI(IppStatus, ippsUnpackScaleFactors_MP3_1u8s, (
  Ipp8u**            ppBitStream,
  int*               pOffset,
  Ipp8s*             pDstScaleFactor,
  IppMP3SideInfo*    pSideInfo,
  int*               pScfsi,
  IppMP3FrameHeader* pFrameHeader,
  int                granule,
  int                channel))


/* Huffman Decoding */
/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippsHuffmanDecode_MP3_1u32s
//    ippsHuffmanDecodeSfb_MP3_1u32s
//
//  Purpose:
//    Decodes Huffman symbols for the 576 spectral coefficients associated
//    with one granule of one channel.
//
//  Parameter:
//    ppBitStream      - double pointer to the first bit stream byte that
//                       contains the Huffman codewords associated with
//                       the current granule and channel
//    pOffset          - pointer to the starting bit position in the bit
//                       stream byte pointed by *ppBitStream;
//                       valid within the range of 0 to 7, where 0 corresponds
//                       to the most significant bit, and 7 corresponds
//                       to the least significant bit
//    pDstIs           - pointer to the vector of decoded Huffman symbols used
//                       to compute the quantized values of the 576 spectral
//                       coefficients that are associated with the current
//                       granule and channel
//    pDstNonZeroBound - pointer to the spectral region above which all
//                       coefficients are set equal to zero
//    pSideInfo        - pointer to MP3 structure that contains the side
//                       information associated with the current granule and
//                       channel
//    pFrameHeader     - pointer to MP3 structure that contains the header
//                       associated with the current frame
//    hufSize          - the number of Huffman code bits associated with the
//                       current granule and channel
//    pSfbTableLong    - Pointer to Scalefactor band table for long block.
//                       User can use the the default table from MPEG-1,
//                       MPEG-2 standards.
//
//  Returns:
//    IppStatus
//
//  Notes:
*/

IPPAPI(IppStatus, ippsHuffmanDecode_MP3_1u32s, (
  Ipp8u**            ppBitStream,
  int*               pOffset,
  Ipp32s*            pDstIs,
  int*               pDstNonZeroBound,
  IppMP3SideInfo*    pSideInfo,
  IppMP3FrameHeader* pFrameHeader,
  int                hufSize))

IPPAPI(IppStatus, ippsHuffmanDecodeSfb_MP3_1u32s, (
  Ipp8u**            ppBitStream,
  int*               pOffset,
  Ipp32s*            pDstIs,
  int*               pDstNonZeroBound,
  IppMP3SideInfo*    pSideInfo,
  IppMP3FrameHeader* pFrameHeader,
  int                hufSize,
  IppMP3ScaleFactorBandTableLong pSfbTableLong))


/* Requantization */
/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippsReQuantize_MP3_32s_I,
//    ippsReQuantizeSfb_MP3_32s_I
//
//  Purpose:
//    Requantizes the decoded Huffman symbols.
//
//  Parameter:
//    pSrcDstIsXr   - pointer to the vector of decoded Huffman symbols;
//                    for stereo and dual_channel modes, right channel data
//                    begins at the address &(pSrcDstIsXr[576])
//    pNonZeroBound - pointer to the spectral bound above which all
//                    coefficients are set to zero; for stereo and dual_channel
//                    modes, the left channel bound is pNonZeroBound [0],
//                    and the right channel bound is pNonZeroBound [1].
//    pScaleFactor  - pointer to the scalefactor buffer;
//                    for stereo and dual_channel modes, the right channel
//                    scalefactors begin at &(pScaleFactor[IPP_MP3_SF_BUF_LEN])
//    pSideInfo     - pointer to the side information for the current granule
//    pFrameHeader  - pointer to the frame header for the current frame
//    pBuffer       - pointer to a workspace buffer;
//                    the buffer length must be 576 samples
//    pSfbTableLong - pointer to scaleFactor band table for long block;
//                    user can use the the default table from MPEG-1, MPEG-2 standards
//    pSfbTableShort- pointer to scaleFactor band table for short block;
//                    user can use the the default table from MPEG-1, MPEG-2 standards
//
//  Returns:
//    IppStatus
//
//  Notes:
//    Spectral samples for the synthesis filter bank are derived from the
//    decoded symbols using the requantization equations given
//    in the ISO standard. Stereophonic mid/side (M/S) and/or intensity
//    decoding is applied if necessary. Requantized spectral samples are
//    returned in the vector pSrcDstIsXr. The reordering operation is applied
//    for short blocks.
*/

IPPAPI(IppStatus, ippsReQuantize_MP3_32s_I, (
  Ipp32s*            pSrcDstIsXr,
  int*               pNonZeroBound,
  Ipp8s*             pScaleFactor,
  IppMP3SideInfo*    pSideInfo,
  IppMP3FrameHeader* pFrameHeader,
  Ipp32s*            pBuffer))

IPPAPI(IppStatus, ippsReQuantizeSfb_MP3_32s_I, (
  Ipp32s*            pSrcDstIsXr,
  int*               pNonZeroBound,
  Ipp8s*             pScaleFactor,
  IppMP3SideInfo*    pSideInfo,
  IppMP3FrameHeader* pFrameHeader,
  Ipp32s*            pBuffer,
  IppMP3ScaleFactorBandTableLong  pSfbTableLong,
  IppMP3ScaleFactorBandTableShort pSfbTableShort))


/* Hybrid Filtering */
/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippsMDCTInv_MP3_32s
//
//  Purpose:
//    Stage 1 of the hybrid synthesis filter bank.
//    Performs the following operations:
//      a) Alias reduction,
//      b) Inverse MDCT according to block size specifiers
//         and mixed block modes,
//      c) Overlap add of IMDCT outputs,
//      d) Frequency inversion prior to PQMF bank.
//    Because the IMDCT is a lapped transform, the user must preallocate
//    a buffer referenced by pSrcDstOverlapAdd to maintain the IMDCT
//    overlap-add state. The buffer must contain 576 elements.
//
//  Parameter:
//    pSrcXr            - pointer to the vector of requantized spectral
//                        samples for the current channel and granule,
//                        represented in Q5.26 format
//    pDstY             - pointer to the vector of IMDCT outputs in
//                        Q7.24 format, for input to PQMF bank
//    pSrcDstOverlapAdd - pointer to the overlap-add buffer; contains
//                        the overlapped portion of the previous granule’s
//                        IMDCT output, in Q7.24 format
//    nonZeroBound      - the bound above which all spectral coefficients
//                        are zero for the current granule and channel
//    pPrevNumOfImdc    - pointer to the number of IMDCTs,
//                        for current granule, current channel
//    blockType         - block type indicator
//    mixedBlock        - mixed block indicator
//
//  Returns:
//    IppStatus
//
//  Notes:
//    Prior to the first call to the synthesis filter bank, all elements of
//    the overlap-add buffer should be set equal to zero. In between all
//    subsequent calls, the MP3 application must preserve the contents of
//    the overlap-add buffer. Upon entry to ippsMDCTInv_MP3_32s,
//    the overlap-add buffer should contain the IMDCT output generated by
//    operating on the previous granule; upon exit from ippsMDCTInv_MP3_32s,
//    the overlap-add buffer will contain the overlapped portion of the output
//    generated by operating on the current granule.
*/

IPPAPI(IppStatus, ippsMDCTInv_MP3_32s, (
  Ipp32s* pSrcXr,
  Ipp32s* pDstY,
  Ipp32s* pSrcDstOverlapAdd,
  int     nonZeroBound,
  int*    pPrevNumOfImdct,
  int     blockType,
  int     mixedBlock))


/* Polyphase Filtering */
/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippsSynthPQMF_MP3_32s16s
//
//  Purpose:
//    Stage 2 of the hybrid synthesis filter bank;
//    a critically-sampled 32-channel PQMF synthesis bank that generates
//    32 time-domain output samples for each 32-sample input block
//    of IMDCT outputs. For each input block, the PQMF generates an output
//    sequence of 16-bit signed little-endian PCM samples in the vector
//    pointed to by pSrcY.
//    If mode equals 2, the left and right channel output samples are
//    interleaved (i.e., LRLRLR), such that the left channel data is organized
//    as follows:
//      pDstAudioOut[2*i], i=0 to 31.
//    If mode equals 1, then the left and right channel outputs are
//    not interleaved.
//
//  Parameter:
//    pSrcY        - pointer to the block of 32 IMDCT sub-band input samples,
//                   in Q7.24 format.
//    pDstAudioOut - pointer to a block of 32 reconstructed PCM output samples
//                   in 16-bit signed format (little-endian);
//                   left and right channels are interleaved according
//                   to the mode flag.
//    pVBuffer     - pointer to the input workspace buffer
//                   containing Q7.24 data.
//    pVPosition   - pointer to the internal workspace index
//    mode         - flag that indicates whether or not the PCM audio output
//                   channels should be interleaved
//                     1 – not interleaved
//                     2 – interleaved
//
//  Returns:
//    IppStatus
//
//  Notes:
//    Because the PQMF bank contains memory, the MP3 application must maintain
//    two state variables in between calls to the primitive.
//    First, the application must preallocate for the PQMF computation
//    a workspace buffer of size 512 x Number of Channels. This buffer is
//    referenced by the pointer pVBuffer, and its elements should be
//    initialized to zero prior to the first call. During subsequent calls,
//    the pVBuffer input for the current call should contain the pVbuffer
//    output generated by the previous call. In addition to pVBuffer, the MP3
//    application must also initialize to zero and thereafter preserve
//    the value of the state variable pVPosition. The MP3 application should
//    modify the values contained in pVBuffer or pVPosition only during
//    decoder reset, and the reset values should always be zero.
*/

IPPAPI(IppStatus, ippsSynthPQMF_MP3_32s16s, (
  Ipp32s* pSrcY,
  Ipp16s* pDstAudioOut,
  Ipp32s* pVBuffer,
  int*    pVPosition,
  int     mode))





/***** Video Coding Functions ***********************************************/


/***** General Video Functions *****/

/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiDCTInv_8x8_16s8u
//
//  Purpose:
//    Inverse DCT transform and clipping.
//
//  Parameter:
//    pSrc    - pointer to source data
//    pDst    - pointer to destination data
//    dstStep - step between destination lines
//
//  Returns:
//    IppStatus
//
//  Notes:
*/

IPPAPI(IppStatus, ippiDCTInv_8x8_16s8u, (
  const Ipp16s* pSrc,
        Ipp8u*  pDst,
        int     dstStep))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiZigzagInv_Horizontal_16s
//    ippiZigzagInv_Vertical_16s
//
//  Purpose:
//    Reorder zigzag to natural order.
//
//  Parameter:
//    pSrc    - pointer to source data
//    pDst    - pointer to destination data
//
//  Returns:
//    IppStatus
//
//  Notes:
*/

IPPAPI(IppStatus, ippiZigzagInv_Horizontal_16s, (
  const Ipp16s* pSrc,
        Ipp16s* pDst))


IPPAPI(IppStatus, ippiZigzagInv_Vertical_16s, (
  const Ipp16s* pSrc,
        Ipp16s* pDst))


/* ///////////////////////////////////////////////////////////////////////////
//  Name:
//    ippiZigzagInvClassical_Compact_16s
//    ippiZigzagInvHorizontal_Compact_16s
//    ippiZigzagInvVertical_Compact_16s
//
//  Purpose:
//    Reorder zigzag to natural order.
//
//  Parameter:
//    pSrc    - pointer to source data
//    pDst    - pointer to destination data
//
//  Returns:
//    IppStatus
//
//  Notes:
*/

IPPAPI(IppStatus, ippiZigzagInvClassical_Compact_16s, (
  const Ipp16s* pSrc,
        int     len,
        Ipp16s* pDst))


IPPAPI(IppStatus, ippiZigzagInvHorizontal_Compact_16s, (
  const Ipp16s* pSrc,
        int     len,
        Ipp16s* pDst))


IPPAPI(IppStatus, ippiZigzagInvVertical_Compact_16s, (
  const Ipp16s* pSrc,
        int     len,
        Ipp16s* pDst))


/* Prediction with Overlapped Block Motion Compensation (OBMC) */

IPPAPI(IppStatus, ippiPredictBlock_OBMC_8u, (
  const Ipp8u*           pSrcRef,
        Ipp8u*           pDst,
        int              step,
        IppMotionVector* pMVCur,
        IppMotionVector* pMVLeft,
        IppMotionVector* pMVRight,
        IppMotionVector* pMVAbove,
        IppMotionVector* pMVBelow))




/***** H.263+ Functions *****/

IPPAPI(IppStatus, ippiDecodeMV_H263, (
  Ipp8u**          ppBitStream,
  int*             pBitOffset,
  IppMotionVector* pSrcDstMV))


IPPAPI(IppStatus, ippiDecodeMV_TopBorder_H263, (
  Ipp8u**          ppBitStream,
  int*             pBitOffset,
  IppMotionVector* pSrcDstMV))


/* //////////////////////////////////////////////////////////////////////
// Name:
//    ippiCopyMB_H263_8u
//    ippiCopyBlock_H263_8u
//
// Purpose:
//    Ñopying of block or macroblock
//
// Parameters:
//    pSrc    - pointer to source data
//    pDst    - pointer to destination data
//    step    - step in source and destination image
//
// Returns:
//    ippStsNoErr               -   Ok
//    ippStsNullPtrErr          -   One of pointers are NULL
//    ippStsH263MBStepErr       -   Step for MB less 16
//    ippStsH263BlockStepErr    -   Step for Block less 8
//
//  Notes:
*/

IPPAPI(IppStatus, ippiCopyMB_H263_8u, (
  const Ipp8u* pSrc,
        Ipp8u* pDst,
        int    step))


IPPAPI(IppStatus, ippiCopyBlock_H263_8u, (
  const Ipp8u* pSrc,
        Ipp8u* pDst,
        int    step))

/* //////////////////////////////////////////////////////////////////////
// Name:
//    ippiCopyApproxHMB_H263_8u
//    ippiCopyApproxHBlock_H263_8u
//    ippiCopyApproxVMB_H263_8u
//    ippiCopyApproxVBlock_H263_8u
//    ippiCopyApproxHVMB_H263_8u
//    ippiCopyApproxHVBlock_H263_8u
//
// Purpose:
//    Ñopying of block or macroblock with approximation
//    (half pixel, without rounding) in horizontal(H), vertical(V)
//    or both direction(HV)
//
// Parameters:
//    pSrc    - pointer to source data
//    pDst    - pointer to destination data
//    step    - step in source and destination image
//
// Returns:
//    ippStsNoErr               -   Ok
//    ippStsNullPtrErr          -   One of pointers are NULL
//    ippStsH263MBStepErr       -   Step value is less than 16
//    ippStsH263BlockStepErr    -   Step value is less than 8
//
//  Notes:
*/

IPPAPI(IppStatus, ippiCopyApproxHMB_H263_8u, (
  const Ipp8u* pSrc,
        Ipp8u* pDst,
        int    step))

IPPAPI(IppStatus, ippiCopyApproxHBlock_H263_8u, (
  const Ipp8u* pSrc,
        Ipp8u* pDst,
        int    step))

IPPAPI(IppStatus, ippiCopyApproxVMB_H263_8u, (
  const Ipp8u* pSrc,
        Ipp8u* pDst,
        int    step))

IPPAPI(IppStatus, ippiCopyApproxVBlock_H263_8u, (
  const Ipp8u* pSrc,
        Ipp8u* pDst,
        int    step))

IPPAPI(IppStatus, ippiCopyApproxHVMB_H263_8u, (
  const Ipp8u* pSrc,
        Ipp8u* pDst,
        int    step))

IPPAPI(IppStatus, ippiCopyApproxHVBlock_H263_8u, (
  const Ipp8u* pSrc,
        Ipp8u* pDst,
        int    step))


/* Quantization */
IPPAPI(IppStatus, ippiQuantInvIntra_Compact_H263_16s_I, (
  Ipp16s* pSrcDst,
  int     len,
  int     QP))


IPPAPI(IppStatus, ippiQuantInvInter_Compact_H263_16s_I, (
  Ipp16s* pSrcDst,
  int     len,
  int     QP))


/* Reconstruction */
IPPAPI(IppStatus, ippiReconMB_H263, (
  const Ipp8u*  pSrc,
  const Ipp16s* pSrcResidual,
        Ipp8u*  pDst,
        int     step))


IPPAPI(IppStatus, ippiReconMB_H263_I, (
        Ipp8u*  pSrcDst,
  const Ipp16s* pSrcResidual,
        int     step))


IPPAPI(IppStatus, ippiReconBlock_H263, (
  const Ipp8u*  pSrc,
  const Ipp16s* pSrcResidual,
        Ipp8u*  pDst,
        int     step))


IPPAPI(IppStatus, ippiReconBlock_H263_I, (
        Ipp8u*  pSrcDst,
  const Ipp16s* pSrcResidual,
        int     step))


/* Expand Frame */

IPPAPI(IppStatus, ippiExpandFrame_H263_8u, (
  Ipp8u* pSrcDstPlane,
  int    frameWidth,
  int    frameHeight,
  int    expandPels,
  int    step))


/* Deblock Filtering */

IPPAPI(IppStatus, ippiFilterDeblocking_HorEdge_H263_8u_I, (
  Ipp8u* pSrcDst,
  int    step,
  int    QP))


IPPAPI(IppStatus, ippiFilterDeblocking_VerEdge_H263_8u_I, (
  Ipp8u* pSrcDst,
  int    step,
  int    QP))


IPPAPI(IppStatus, ippiUpdateQuant_MQ_H263_1u32s_I, (
  Ipp8u** ppBitStream,
  int*    pBitOffset,
  Ipp32s* pSrcDstQP))


/* Middle Level */
IPPAPI(IppStatus, ippiDecodeBlockCoef_Intra_H263_1u8u, (
  Ipp8u** ppBitStream,
  int*    pBitOffset,
  Ipp8u*  pDst,
  int     step,
  int     QP))


IPPAPI(IppStatus, ippiDecodeBlockCoef_Inter_H263_1u16s, (
  Ipp8u** ppBitStream,
  int*    pBitOffset,
  Ipp16s* pDst,
  int     QP))


IPPAPI(IppStatus, ippiDecodeBlockCoef_AdvIntra_H263_1u8u, (
  Ipp8u** ppBitStream,
  int*    pBitOffset,
  Ipp8u*  pDst,
  int     dstStep,
  Ipp16s* pSrcDstCoefRow,
  Ipp16s* pSrcDstCoefCol,
  int     QP,
  int     predictMode))


IPPAPI(IppStatus, ippiDecodeBlockCoef_IntraDCOnly_H263_1u8u, (
  Ipp8u** ppBitStream,
  int*    pBitOffset,
  Ipp8u*  pDst,
  int     step))

/* //////////////////////////////////////////////////////////////////////
// Name:
//    ippiDecodeMCBPCIntra_H263
//    ippiDecodeMCBPCInter_H263
//
// Purpose:
//    Decoding macroblock type and coded block pattern for chrominance (MCBPC)
//    for INTRA and INTER blocks
//
// Parameters:
//    ppBitStream   - pointer to bitsream
//    pBitOffset    - pointer to offset in current byte
//    pDstVal       - value of macroblock type and coded block pattern
//
// Returns:
//    ippStsNoErr                   -   Ok
//    ippStsNullPtrErr              -   One of pointers are NULL
//    ippStsH263MCBPCIntraCodeErr   -   Illegal Huffman code during MCBPC Intra stream processing
//    ippStsH263MCBPCInterCodeErr   -   Illegal Huffman code during MCBPC Inter stream processing
//
//  Notes:
*/

IPPAPI(IppStatus, ippiDecodeMCBPCIntra_H263, (
  Ipp8u** ppBitStream,
  int*    pBitOffset,
  Ipp8u*  pDstVal))

IPPAPI(IppStatus, ippiDecodeMCBPCInter_H263, (
  Ipp8u** ppBitStream,
  int*    pBitOffset,
  Ipp8u*  pDstVal))

/* //////////////////////////////////////////////////////////////////////
// Name:
//    ippiDecodeMODB_H263
//
// Purpose:
//    Decoding macroblock mode for B-blocks (MODB)
//
// Parameters:
//    ppBitStream   - pointer to bitsream
//    pBitOffset    - pointer to offset in current byte
//    pDstVal       - value of macroblock mode
//
// Returns:
//    ippStsNoErr                   -   Ok
//    ippStsNullPtrErr              -   One of pointers are NULL
//
//  Notes:
*/

IPPAPI(IppStatus, ippiDecodeMODB_H263, (
  Ipp8u** ppBitStream,
  int*    pBitOffset,
  Ipp8u*  pDstVal))

/* //////////////////////////////////////////////////////////////////////
// Name:
//    ippiDecodeCBPY_H263
//
// Purpose:
//    Decoding coded block pattern for luminance (CBPY)
//
// Parameters:
//    ppBitStream   - pointer to bitsream
//    pBitOffset    - pointer to offset in current byte
//    pDstVal       - value of coded block pattern
//
// Returns:
//    ippStsNoErr                   -   Ok
//    ippStsNullPtrErr              -   One of pointers are NULL
//    ippStsH263CBPYCodeErr:        -   Illegal Huffman code during CBPY stream processing
//
//  Notes:
*/

IPPAPI(IppStatus, ippiDecodeCBPY_H263, (
  Ipp8u** ppBitStream,
  int*    pBitOffset,
  Ipp8u*  pDstVal))



/***** MPEG-4 Functions *****/

/* motion vector decoding (+ padding) */

IPPAPI(IppStatus, ippiDecodePadMV_PVOP_MPEG4,	(
  Ipp8u**           ppBitStream,
  int*              pBitOffset,
  IppMotionVector*  pSrcMVLeftMB,
  IppMotionVector*  pSrcMVUpperMB,
  IppMotionVector*  pSrcMVUpperRightMB,
  IppMotionVector*  pDstMVCurMB,
  Ipp8u*            pTranspLeftMB,
  Ipp8u*            pTranspUpperMB,
  Ipp8u*            pTranspUpperRightMB,
  Ipp8u*            pTranspCurMB,
  int               fcodeForward,
  IppMacroblockType MBType))


IPPAPI(IppStatus, ippiDecodeMV_BVOP_Forward_MPEG4, (
  Ipp8u**          ppBitStream,
  int*             pBitOffset,
  IppMotionVector* pSrcDstMVF,
  int              fcodeForward))


IPPAPI(IppStatus, ippiDecodeMV_BVOP_Backward_MPEG4, (
  Ipp8u**          ppBitStream,
  int*             pBitOffset,
  IppMotionVector* pSrcDstMVB,
  int              fcodeBackward))


IPPAPI(IppStatus, ippiDecodeMV_BVOP_Interpolate_MPEG4, (
  Ipp8u**          ppBitStream,
  int*             pBitOffset,
  IppMotionVector* pSrcDstMVF,
  IppMotionVector* pSrcDstMVB,
  int              fcodeForward,
  int              fcodeBackward))


IPPAPI(IppStatus, ippiDecodeMV_BVOP_Direct_MPEG4,	(
        Ipp8u**          ppBitStream,
        int*             pBitOffset,
  const IppMotionVector* pSrcMV,
        IppMotionVector* pDstMVF,
        IppMotionVector* pDstMVB,
        Ipp8u*           pTranspSrcMB,
        int              TRB,
        int              TRD))


IPPAPI(IppStatus, ippiDecodeMV_BVOP_DirectSkip_MPEG4,	(
  const IppMotionVector* pSrcMV,
        IppMotionVector* pDstMVF,
        IppMotionVector* pDstMVB,
        Ipp8u*           pTranspSrcMB,
        int              TRB,
        int              TRD))


IPPAPI(IppStatus, ippiLimitMVToRect_MPEG4, (
  const IppMotionVector* pSrcMV,
        IppMotionVector* pDstMV,
        IppiRect*        pRectVOPRef,
        int              x,
        int              y,
        int              size))


/* coefficient prediction + reconstruction */

IPPAPI(IppStatus, ippiPredictReconCoefIntra_MPEG4_16s, (
  Ipp16s*           pSrcDst,
  Ipp16s*           pPredBufRow,
  Ipp16s*           pPredBufCol,
  int               curQP,
  int               predQP,
  int               predDir,
  int               ACPredFlag,
  IppVideoComponent videoComp))


/* motion padding */
IPPAPI(IppStatus, ippiPadMBHorizontal_MPEG4_8u,	(
  const Ipp8u* pSrcY,
  const Ipp8u* pSrcU,
	const Ipp8u* pSrcV,
  const Ipp8u* pSrcA,
        Ipp8u* pDstY,
        Ipp8u* pDstU,
        Ipp8u* pDstV,
        Ipp8u* pDstA,
        int    stepYA,
        int    stepCbCr))


IPPAPI(IppStatus, ippiPadMBVertical_MPEG4_8u, (
  const Ipp8u* pSrcY,
  const Ipp8u* pSrcU,
  const Ipp8u* pSrcV,
  const Ipp8u* pSrcA,
        Ipp8u* pDstY,
        Ipp8u* pDstU,
        Ipp8u* pDstV,
        Ipp8u* pDstA,
        int    stepYA,
        int    stepCbCr))


IPPAPI(IppStatus, ippiPadMBGray_MPEG4_8u, (
  Ipp8u grayVal,
  Ipp8u* pDstY,
  Ipp8u* pDstU,
  Ipp8u* pDstV,
  Ipp8u* pDstA,
  int    stepYA,
  int    stepCbCr))


IPPAPI(IppStatus, ippiPadCurrent_16x16_MPEG4_8u_I, (
        Ipp8u* pSrcDst,
        int    step,
  const Ipp8u* pBAB))


IPPAPI(IppStatus, ippiPadCurrent_8x8_MPEG4_8u_I, (
        Ipp8u* pSrcDst,
        int    step,
  const Ipp8u* pBAB))


/* vector padding */

IPPAPI(IppStatus, ippiPadMV_MPEG4, (
  IppMotionVector* pSrcDstMV,
  Ipp8u*           pTransp))


/* inverse quantization */

IPPAPI(IppStatus, ippiQuantInvIntraFirst_MPEG4_16s_I, (
        Ipp16s* pSrcDst,
        int     QP,
  const Ipp8u*  pQMatrix,
        int     linearMode,
        int     colorType,
        int     bitsPerPixel))

IPPAPI(IppStatus, ippiQuantInvInterFirst_MPEG4_16s_I,	(
        Ipp16s* pSrcDst,
        int     QP,
  const Ipp8u*  pQMatrix,
        int     bitsPerPixel))

IPPAPI(IppStatus, ippiQuantInvIntraSecond_MPEG4_16s_I, (
  Ipp16s* pSrcDst,
  int     QP,
  int     linearMode,
  int     colorType,
  int     bitsPerPixel))

IPPAPI(IppStatus, ippiQuantInvInterSecond_MPEG4_16s_I, (
  Ipp16s* pSrcDst,
  int     QP,
  int     bitsPerPixel))


IPPAPI(IppStatus, ippiQuantInvIntra_MPEG4_16s_I, (
        Ipp16s*           pSrcDst,
        int               QP,
  const Ipp8u*            pQMatrix,
        IppVideoComponent videoComp))


IPPAPI(IppStatus, ippiQuantInvInter_MPEG4_16s_I, (
        Ipp16s* pSrcDst,
        int     QP,
  const Ipp8u*  pQMatrix))


/* vlc decoding + zigzag */
IPPAPI(IppStatus, ippiDecodeVLCZigzag_IntraDCVLC_MPEG4_1u16s,	(
  Ipp8u**           ppBitStream,
  int*              pBitOffset,
  Ipp16s*           pDst,
  int               predDir,
  IppVideoComponent videoComp))


IPPAPI(IppStatus, ippiDecodeVLCZigzag_IntraACVLC_MPEG4_1u16s,	(
  Ipp8u** ppBitStream,
  int*    pBitOffset,
  Ipp16s* pDst,
  int     predDir))


IPPAPI(IppStatus, ippiDecodeVLCZigzag_Inter_MPEG4_1u16s, (
  Ipp8u** ppBitStream,
  int*    pBitOffset,
  Ipp16s* pDst))


/* block decoding */
IPPAPI(IppStatus, ippiDecodeBlockCoef_Intra_MPEG4_1u8u, (
        Ipp8u** ppBitStream,
        int*    pBitOffset,
        Ipp8u*  pDst,
        int     step,
        Ipp16s* pCoefBufRow,
        Ipp16s* pCoefBufCol,
        Ipp8u   curQP,
        Ipp8u*  pQPBuf,
  const Ipp8u*  pQMatrix,
        int     blockIndex,
        int     intraDCVLC,
        int     ACPredFlag))


IPPAPI(IppStatus, ippiDecodeBlockCoef_Inter_MPEG4_1u16s, (
  Ipp8u**      ppBitStream,
  int*         pBitOffset,
  Ipp16s*      pDst,
  int          QP,
  const Ipp8u* pQMatrix))


/***************************************************************************
// Name:    ippiComputeChromaMV_MPEG4
// Description:   Compute the motion vector for chroma blocks.
// Input Arguments:
//      lumaMV    - Pointer to the motion vector of current luma macroblock.
// Output Arguments:
//      chromaMV  - Pointer to the chroma motion vector.
// Returns: IppStatus
// Note: Tables 7.6-7.9
*******************************************************************************/
IPPAPI(IppStatus, ippiComputeChromaMV_MPEG4, (
  const IppMotionVector*    lumaMV,
  IppMotionVector*          chromaMV))


/***************************************************************************
// Name:    ippiComputeChroma4MV_MPEG4
// Description:   Compute the motion vector for chroma blocks.
// Input Arguments:
//      lumaMV    - Array of 4 motion vectors of luma blocks.
//      pTranspMB - Transparent status for each luma block.
// Output Arguments:
//      chromaMV  - Pointer to the chroma motion vector.
// Returns: IppStatus
// Note: Tables 7.6-7.9
*******************************************************************************/
IPPAPI(IppStatus, ippiComputeChroma4MV_MPEG4, (
  const IppMotionVector     lumaMV[4],
        IppMotionVector*    chromaMV,
        Ipp8u               pTranspMB[4]))


/*************************************************************************************
// Name:            ippiAverageBlock_MPEG4_8u_I
// Description:     Performs averaging of two blocks with rounding. (7.6.9)
// Input Arguments: pSrcDst - Pointer to the first pixel of 1-st block
//                  srcDststep - Width of the source and destination plane.
//                  pSrc    - Pointer to the first pixel of 2-st block
//                  srcStep - Width of the source plane.
// Output Arguments:pSrcDst - Pointer to the first pixel of the dest block
// Returns:         One of the following IPP status code:
//                  ippStsNoErr      - No error.
//                  ippStsBadArgErr  - At least one of the arguments is invalid.
*************************************************************************************/
IPPAPI(IppStatus, ippiAverageBlock_MPEG4_8u_I, (
  const Ipp8u*      pSrc,
        int         srcStep,
        Ipp8u*      pSrcDst,
        int         srcDstStep))



/*************************************************************************************
// Name:            ippiAverageMB_MPEG4_8u_I
// Description:     Performs averaging of two macroblocks with rounding. (7.6.9)
// Input Arguments: pSrcDst - Pointer to the first pixel of 1-st mblock
//                  srcDststep - Width of the source and destination plane.
//                  pSrc    - Pointer to the first pixel of 2-st mblock
//                  srcStep - Width of the source plane.
// Output Arguments:pSrcDst - Pointer to the first pixel of the dest mblock
// Returns:         One of the following IPP status code:
//                  ippStsNoErr      - No error.
//                  ippStsBadArgErr  - At least one of the arguments is invalid.
*************************************************************************************/
IPPAPI(IppStatus, ippiAverageMB_MPEG4_8u_I,  (
  const Ipp8u*      pSrc,
        int         srcStep,
        Ipp8u*      pSrcDst,
        int         srcDstStep))



/*************************************************************************************
// Name:            ippiAverageBlock_MPEG4_8u
// Description:     Performs averaging of two blocks with rounding. (7.6.9)
// Input Arguments: pSrc1 - Pointer to the first pixel of 1-st block
//                  src1Step - Width of the source plane.
//                  pSrc2    - Pointer to the first pixel of 2-st block
//                  src2Step - Width of the source plane.
//                  dstStep  - Width of the destination plane.
// Output Arguments:pDst - Pointer to the first pixel of the dest block
// Returns:         One of the following IPP status code:
//                  ippStsNoErr      - No error.
//                  ippStsBadArgErr  - At least one of the arguments is invalid.
*************************************************************************************/
IPPAPI(IppStatus, ippiAverageBlock_MPEG4_8u, (
  const Ipp8u*      pSrc1,
        int         src1Step,
  const Ipp8u*      pSrc2,
        int         src2Step,
        Ipp8u*      pDst,
        int         dstStep))



/*************************************************************************************
// Name:            ippiAverageMB_MPEG4_8u
// Description:     Performs averaging of two blocks with rounding. (7.6.9)
// Input Arguments: pSrc1 - Pointer to the first pixel of 1-st mblock
//                  src1Step - Width of the source plane.
//                  pSrc2    - Pointer to the first pixel of 2-st mblock
//                  src2Step - Width of the source plane.
//                  dstStep  - Width of the destination plane.
// Output Arguments:pDst - Pointer to the first pixel of the dest mblock
// Returns:         One of the following IPP status code:
//                  ippStsNoErr      - No error.
//                  ippStsBadArgErr  - At least one of the arguments is invalid.
*************************************************************************************/
IPPAPI(IppStatus, ippiAverageMB_MPEG4_8u,  (
  const Ipp8u*      pSrc1,
        int         src1Step,
  const Ipp8u*      pSrc2,
        int         src2Step,
        Ipp8u*      pDst,
        int         dstStep))



/*************************************************************************************
// Name:            ippiCopyBlockHalfpel_MPEG4_8u
// Description:     Performs copy blocks with halfpel accuracy (7.6.2.1)
// Input Arguments: pSrc - Pointer to the first pixel of ref block
//                  srcStep - Width of the source plane.
//                  dstStep  - Width of the destination plane.
//                  mV - motion vector of current block
//                  rounding - round mode as defined in 7.6.2.1
// Output Arguments:pDst - Pointer to the first pixel of the dest block
// Returns:         One of the following IPP status code:
//                  ippStsNoErr      - No error.
//                  ippStsBadArgErr  - At least one of the arguments is invalid.
*************************************************************************************/
IPPAPI(IppStatus, ippiCopyBlockHalfpel_MPEG4_8u, (
  const Ipp8u*              pSrc,
        int                 srcStep,
        Ipp8u*              pDst,
        int                 dstStep,
  const IppMotionVector*    mV,
        int                 rounding))



/*************************************************************************************
// Name:            ippiCopyMBHalfpel_MPEG4_8u
// Description:     Performs copy mblocks with halfpel accuracy (7.6.2.1)
// Input Arguments: pSrc - Pointer to the first pixel of ref mblock
//                  srcStep - Width of the source plane.
//                  dstStep  - Width of the destination plane.
//                  mV - motion vector of current block
//                  rounding - round mode as defined in 7.6.2.1
// Output Arguments:pDst - Pointer to the first pixel of the dest mblock
// Returns:         One of the following IPP status code:
//                  ippStsNoErr      - No error.
//                  ippStsBadArgErr  - At least one of the arguments is invalid.
*************************************************************************************/
IPPAPI(IppStatus, ippiCopyMBHalfpel_MPEG4_8u, (
  const Ipp8u*              pSrc,
        int                 srcStep,
        Ipp8u*              pDst,
        int                 dstStep,
  const IppMotionVector*    mV,
        int                 rounding))



/*************************************************************************************
// Name:            ippiReconBlockHalfpel_MPEG4_8u
// Description:     Performs recon blocks with halfpel accuracy (7.6.2.1)
// Input Arguments: pSrc - Pointer to the first pixel of ref block
//                  srcStep - Width of the source plane.
//                  pResidue - error
//                  dstStep  - Width of the destination plane.
//                  mV - motion vector of current block
//                  rounding - round mode as defined in 7.6.2.1
// Output Arguments:pDst - Pointer to the first pixel of the dest block
// Returns:         One of the following IPP status code:
//                  ippStsNoErr      - No error.
//                  ippStsBadArgErr  - At least one of the arguments is invalid.
*************************************************************************************/
IPPAPI(IppStatus, ippiReconBlockHalfpel_MPEG4_8u,  (
  const Ipp8u*              pSrc,
        int                 srcStep,
        Ipp16s              pResidue[64],
        Ipp8u*              pDst,
        int                 dstStep,
  const IppMotionVector*    mV,
        int                 rounding))



/*************************************************************************************
// Name:            ippiOBMCHalfpel_MPEG4_8u
// Description:     Performs obmc for block with halfpel accuracy (7.6.6)
// Input Arguments: pSrc - Pointer to the first pixel of ref mblock
//                  srcStep - Width of the source plane.
//                  pResidue - error
//                  dstStep  - Width of the destination plane.
//                  mV - motion vector of current block
//                  rounding - round mode as defined in 7.6.2.1
// Output Arguments:pDst - Pointer to the first pixel of the dest mblock
// Returns:         One of the following IPP status code:
//                  ippStsNoErr      - No error.
//                  ippStsBadArgErr  - At least one of the arguments is invalid.
*************************************************************************************/
IPPAPI(IppStatus, ippiOBMCHalfpel_MPEG4_8u, (
  const Ipp8u*              pSrc,
        int                 srcStep,
        Ipp8u*              pDst,
        int                 dstStep,
  const IppMotionVector*    pMVCur,
  const IppMotionVector*    pMVLeft,
  const IppMotionVector*    pMVRight,
  const IppMotionVector*    pMVAbove,
  const IppMotionVector*    pMVBelow,
        int                 rounding))


/*************************************************************************************
//  Name:       ippiDecodeVLC_IntraDCVLC_MPEG4_1u16s
//  Description: Perform VLC decoding of one DC coeff.
//  Input Arguments:
//              ppBitStream     - Pointer to the pointer to the current byte
//                                from which the intra block starts.
//              pBitOffset      - Pointer to the bit position in the byte
//                                pointed by *ppBitStream. Valid within 0 to 7.
//              videoComp       - Video component type (luminance, chrominance or
//                                alpha) of the current block.
//  Output Arguments:
//              ppBitStream     - Pointer to the pointer to the byte after the
//                                decoded intra block.
//              pBitOffset      - Pointer to the bit position in the byte
//                                pointed by *ppBitStream.
//              pDst            - pointer to the coefficient buffer of current block
//  Returns:    IPP status code.
//  Notes:      This version uses Intra DC VLC to decode Intra DC coefficients.
*************************************************************************************/
IPPAPI(IppStatus, ippiDecodeVLC_IntraDCVLC_MPEG4_1u16s, (
        Ipp8u**             ppBitStream,
        int*                pBitOffset,
        Ipp16s*             pDst,
        IppVideoComponent   videoComp))


IPPAPI(IppStatus, ippiDecodeBlockCoef_IntraDCOnly_MPEG4_1u8u, (
        Ipp8u**             ppBitStream,
        int*                pBitOffset,
        Ipp8u*              pDst,
        int                 step,
        Ipp16s*             pPredRow,
        Ipp16s*             pPredCol,
        Ipp8u               curQP,
        Ipp8u*              pQpBuf,
  const Ipp8u*              pQMatrix,
        int                 blockIndex,
        int                 intraDCVLC,
        int                 ACPredFlag))

/*************************************************************************************
// Name:            ippiFilterDeblocking_HorEdge_MPEG4_8u_I
// Description:     Performs deblocking filtering of one horizontal block edge
//                  on the reconstructed frames, which is described in Annex F.3.1.
// Input Arguments: pSrcDst - Pointer to the first pixel of the bottom block of
//                            the two applied blocks.
//                  step    - Width of the source and destination plane.
//                  QP      - Quantization parameter.
//                  THR1, THR2 - threshold values for choosing filtering mode
// Output Arguments:pSrcDst - Pointer to the first pixel of the bottom block
//                            of the two applied blocks.
// Returns:         One of the following IPP status code:
//                  ippStsNoErr      - No error.
//                  ippStsBadArgErr  - At least one of the arguments is invalid.
*************************************************************************************/
IPPAPI(IppStatus, ippiFilterDeblocking_HorEdge_MPEG4_8u_I, (
       Ipp8u*       pSrcDst,
       int          step,
       int          QP,
       int          THR1,
       int          THR2))


/*************************************************************************************
// Name:            ippiFilterDeblocking_VerEdge_MPEG4_8u_I
// Description:     Performs deblocking filtering of one vertical block edge
//                  on the reconstructed frames, which is described in Annex  F.3.1.
// Input Arguments: pSrcDst - Pointer to the first pixel of the right block of
//                            the two applied blocks.
//                  step    - Width of the source and destination plane.
//                  QP      - Quantization parameter.
//                  THR1, THR2 - threshold values for choosing filtering mode
// Output Arguments:pSrcDst - Pointer to the first pixel of the right block
//                            of the two applied blocks.
// Returns:         One of the following IPP status code:
//                  ippStsNoErr      - No error.
//                  ippStsBadArgErr  - At least one of the arguments is invalid.
*************************************************************************************/
IPPAPI(IppStatus, ippiFilterDeblocking_VerEdge_MPEG4_8u_I, (
       Ipp8u*       pSrcDst,
       int          step,
       int          QP,
       int          THR1,
       int          THR2))


/*************************************************************************************
// Name:            ippiFilterDeringingThresholdMB_MPEG4_8u
// Description:     Performs Threshold determination of 6 blocks in one macroblock
//                  (4Y, Cb, Cr), which is described in Annex F.3.1.
// Input Arguments: pSrcY  - Pointer to the first pixel of the first Y block
//                           in macroblock.
//                  stepY  - Width of the Y plane.
//                  pSrcCb - Pointer to the first pixel of the Cb block
//                  stepCb - Width of the Cb plane.
//                  pSrcCr - Pointer to the first pixel of the Cr block
//                  stepCr - Width of the Cr plane.
// Output Arguments:threshold - 6 threshold values for each block
// Returns:         One of the following IPP status code:
//                  ippStsNoErr      - No error.
//                  ippStsBadArgErr  - At least one of the arguments is invalid.
*************************************************************************************/
IPPAPI(IppStatus, ippiFilterDeringingThresholdMB_MPEG4_8u, (
  const Ipp8u*      pSrcY,
        int         stepY,
  const Ipp8u*      pSrcCb,
        int         stepCb,
  const Ipp8u*      pSrcCr,
        int         stepCr,
        int         threshold[6]))


/*************************************************************************************
// Name:            ippiFilterDeringingSmoothBlock_MPEG4_8u
// Description:     Performs adaptive filtering of block, which is described in
//                  Annex F.3.1.
// Input Arguments: pSrc - Pointer to the first pixel of the block
//                  stepSrc - Width of the source plane.
//                  stepDst - Width of the source plane.
//                  QP      - Quantization parameter.
//                  threshold - threshold values for block
// Output Arguments:pDst - Pointer to the first pixel of the block
// Returns:         One of the following IPP status code:
//                  ippStsNoErr      - No error.
//                  ippStsBadArgErr  - At least one of the arguments is invalid.
*************************************************************************************/
IPPAPI(IppStatus, ippiFilterDeringingSmoothBlock_MPEG4_8u, (
  const Ipp8u*      pSrc,
        int         stepSrc,
        Ipp8u*      pDst,
        int         stepDst,
        int         QP,
        int         threshold))


#ifdef __cplusplus
}
#endif

#endif /* __IPPMP_H__ */

