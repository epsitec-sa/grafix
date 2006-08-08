/* ////////////////////////////////// "ippsc.h" ////////////////////////////////
//
//                  INTEL CORPORATION PROPRIETARY INFORMATION
//     This software is supplied under the terms of a license agreement or
//     nondisclosure agreement with Intel Corporation and may not be copied
//     or disclosed except in accordance with the terms of that agreement.
//        	Copyright(c) 2001-2003 Intel Corporation. All Rights Reserved.
//
//           	Intel(R) Integrated Performance Primitives
//                  Speech Coding (ippsc)
//
*/

#if !defined( __IPPSC_H__ ) || defined( _OWN_BLDPCS )
#define __IPPSC_H__

#ifndef __IPPDEFS_H__
  #include "ippdefs.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if !defined( _OWN_BLDPCS )
typedef enum {
    IPP_SPCHBR_4750 = 0,  /* 4.75 kbps */
    IPP_SPCHBR_5150,      /* 5.15 kbps */
    IPP_SPCHBR_5300,      /* 5.3 kbps */
    IPP_SPCHBR_5900,      /* 5.9 kbps */
    IPP_SPCHBR_6300,      /* 6.3 kbps */
    IPP_SPCHBR_6700,      /* 6.7 kbps */
    IPP_SPCHBR_7400,      /* 7.4 kbps */
    IPP_SPCHBR_7950,      /* 7.95 kbps */
    IPP_SPCHBR_9600,      /* 9.60 kbps */
    IPP_SPCHBR_10200,     /* 10.2 kbps */
    IPP_SPCHBR_12200,     /* 12.2 kbps */
    IPP_SPCHBR_12800,     /* 12.8 kbps */
    IPP_SPCHBR_16000,     /* 16 kbps */
    IPP_SPCHBR_24000,     /* 24 kbps */
    IPP_SPCHBR_32000,     /* 32 kbps */
    IPP_SPCHBR_40000,     /* 40 kbps */
    IPP_SPCHBR_DTX        /* Discontinuous TX mode */
} IppSpchBitRate;


typedef enum {
    IPP_PCM_MULAW = 0,   /* mu-Law */
    IPP_PCM_ALAW,        /* A-Law */
    IPP_PCM_LINEAR       /* uniform PCM */
} IppPCMLaw;

#endif /* _OWN_BLDPCS */

/* /////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//                   Functions declarations
////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippscGetLibVersion
//  Purpose:     getting of the library version
//  Returns:     the structure of information about version
//               of ippSC library
//  Parameters:
//
//  Notes:       not necessary to release the returned structure
*/
IPPAPI( const IppLibraryVersion*, ippscGetLibVersion, (void) )


/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsHighPassFilterSize
//  Purpose:     Knowing of G729 high pass preprocessing filter size demand
//  Parameters:
//    pSize      Pointer to the output value of the memory size needed for filtering
//  Returns:
//  Returns:  ippStsNoErr, if no errors
*/
IPPAPI( IppStatus, ippsHighPassFilterSize_G729, (int *pSize) )

/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsHighPassFilterInit_G729
//  Purpose:     Initialization of the memory allocated for preprocessing filter
//  Parameters:
//    pMemUpdated    pointer to the memory supplied for filtering
//  Returns:  ippStsNoErr, if no errors
//
*/
IPPAPI( IppStatus, ippsHighPassFilterInit_G729, (const Ipp16s *pCoeff, char* pMemUpdated) )
/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsHighPassFilter
//  Purpose:     G729 input signal preprocessing, consists of two functions applied:
//                  - scaling ( devide by a factor 2)
//                  - high-pass filtering
//  Parameters:
//    pSrcDst        pointer to the vector for inplace operation
//    pMemUpdated    pointer to the memory supplied for filtering
//  Returns:  ippStsNoErr, if no errors
*/
IPPAPI( IppStatus, ippsHighPassFilter_G729_16s_ISfs, (Ipp16s* pSrcDst, int len, int scaleFactor,
        char* pMemUpdated) )
IPPAPI( IppStatus, ippsHighPassFilter_G723_16s, (const Ipp16s* pSrc, Ipp16s* pDst, int* pMem) )
/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsMul
//  Name:        ippsMulC
//  Name:        ippsMul_D2D1
//  Purpose:     multiply operations upon every element of
//               the source vectors.
//               rounding to nearest:
//                  const1 = 1<<(scaleFactor-1)
//                  (a*b+const1)>>scaleFactor;
//  Parameters:
//    pSrc            pointer to the input vector
//    pSrc1           pointer to the first source vector
//    pSrc2           pointer to the second source vector
//    pDst            pointer to the output vector
//    pSrcDst         pointer to the source/destination vector
//    len             length of the vectors
//    scaleFactor     scale factor value
//  Returns:  ippStsNoErr, if no errors
*/
IPPAPI( IppStatus, ippsMul_NR_16s_Sfs, (const Ipp16s*  pSrc1, const Ipp16s*  pSrc2,
       Ipp16s*  pDst, int len, int scaleFactor) )
IPPAPI( IppStatus, ippsMul_NR_16s_ISfs, (const Ipp16s*  pSrc, Ipp16s*  pSrcDst,
       int len, int scaleFactor) )
IPPAPI( IppStatus, ippsMulC_NR_16s_ISfs, (Ipp16s  val, Ipp16s*  pSrcDst, int len, int scaleFactor) )
IPPAPI( IppStatus, ippsMulC_NR_16s_Sfs, ( const Ipp16s* pSrc, Ipp16s val, Ipp16s* pDst,
       int len, int scaleFactor) )
/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsMulPowerC
//  Purpose:     power weighting of every element of the source vectors
//               dst[i] = pow(val, i)*src[i] ; i=0..len-1
//               with rounding to nearest:
//                  const1 = 1<<(scaleFactor-1)
//                  (a*b+const1)>>scaleFactor;
//  Parameters:
//    pSrc            pointer to the input vector
//    pDst            pointer to the output vector
//    len             length of the vectors
//    scaleFactor     scale factor value
//  Returns:  ippStsNoErr, if no errors
*/
IPPAPI( IppStatus, ippsMulPowerC_NR_16s_Sfs, (const Ipp16s*  pSrc, Ipp16s  val, Ipp16s*  pDst,
       int len, int scaleFactor) )
/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsInvSqrt
//  Purpose:     Inverted square root with normalization
//  Parameters:
//    pSrcDst    pointer to the input/output vector
//    len        length of the input vector
//  Returns:  ippStsNoErr, if no errors
*/
IPPAPI( IppStatus, ippsInvSqrt_32s_I, (Ipp32s *pSrcDst, int len ) )
/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsAutoScale
//  Purpose:     Autoscaling:  Find and normalize (shift left) the absolute
//               maximal element and then do the same shift for all other elements
//  Parameters:
//    pSrc       pointer to the input vector
//    pDst       pointer to the output vector
//    pSrcDst    pointer to the input/output vector
//    len        length of the input vector
//    pScale     pointer to the output scaling factor
//               (number of bit the output vector has been shifted left)
//  Returns:  ippStsNoErr, if no errors
*/
IPPAPI( IppStatus, ippsAutoScale_16s, (const Ipp16s *pSrc,  Ipp16s *pDst, int Len , int *pScale) )
IPPAPI( IppStatus, ippsAutoScale_16s_I, ( Ipp16s *pSrcDst, int Len , int *pScale) )
/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsAutoCorrLagMax
//  Purpose:     Find the maximum of the correlation for the given lag range
//                 r[lag]=SUM(n=0,...,len-1) src[n]*src[n-lag]  - backward
//                 r[lag]=SUM(n=0,...,len-1) src[n]*src[n+lag]  - forward
//                 within the range [lowerLag,upperLag] of the lags.
//  Parameters:
//    pSrc       pointer to the input vector
//    len        length of the input vector
//    lowerLag   lower input lag value
//    upperLag   upper input lag value
//    pMax       pointer to the output maximum of the correlation
//    maxLag     pointer to the output lag value that hold maximum
//  Returns:  ippStsNoErr, if no errors
*/
IPPAPI( IppStatus, ippsAutoCorrLagMax_Fwd_16s, (const short *pSrc, int len, int lowerLag,
       int upperLag, Ipp32s *pMax, int *maxLag ) )
IPPAPI( IppStatus, ippsAutoCorrLagMax_Inv_16s, (const short *pSrc, int len, int lowerLag,
       int upperLag, Ipp32s *pMax, int *maxLag ) )

/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsAutoCorr_NormE
//  Purpose:     Compute autocorrelation using formula:
//                 r[n]=SUM(i=0,...,len-n-1) src[i]*src[i+n], n=0,...,lenDst-1
//               Norm in function name means multiplication of result by normalzation factor
//               of corr[0].
//  Parameters:
//    pSrc       pointer to the input vector
//    len        length of the input vector
//    step
//    pDst       pointer to the output autocorrelation vector
//    lenDst     length of the output vector
//  Returns:  ippStsNoErr, if no errors
//            ippStsOverflow, if at least one result really was saturated
*/
IPPAPI( IppStatus, ippsAutoCorr_NormE_16s32s, (const Ipp16s *pSrc, int len, Ipp32s *pDst,
       int lenDst, int *pNorm) )
IPPAPI( IppStatus, ippsAutoCorr_NormE_NR_16s, (const Ipp16s *pSrc, int len, Ipp16s *pDst,
       int lenDst, int *pNorm) )
IPPAPI( IppStatus, ippsAutoCorr_NormE_G723_16s, (const Ipp16s *pSrc, Ipp16s *pDst, int *pNorm) )
/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsToeplizMatrix
//  Purpose:     Compute of the autocorrelation matrix for the impulse response
//  Parameters:
//    pSrc       pointer to the input vector
//    pDst       pointer to the output autocorrelation matrix
//  Returns:  ippStsNoErr, if no errors
*/
IPPAPI( IppStatus, ippsToeplizMatrix_G729_16s32s, (const Ipp16s *pSrc, Ipp32s *pDst) )
IPPAPI( IppStatus, ippsToeplizMatrix_G729_16s, (const Ipp16s *pSrc, Ipp16s *pDst) )
IPPAPI( IppStatus, ippsToeplizMatrix_G723_16s32s, (const Ipp16s *pSrc, Ipp32s *pDst) )
IPPAPI( IppStatus, ippsToeplizMatrix_G723_16s,
       (const Ipp16s *pSrcImpulseResponse, Ipp16s *pDstMatrix))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsCrossCorr
//  Purpose:     Compute crosscorrelation of two vectors using formula:
//                 r[k]=SUM(i=k,...,len) src2[i]*src1[j-i] k=0,...,lenDst-1
//               result is scaled so that the crosscorrelation maximum is int 13 bit
//  Parameters:
//    pSrc1      pointer to the input vector
//    pSrc2      pointer to the input vector
//    len        length of the correlation
//    pDst       pointer to the output crosscorrelation vector
//    lenDst     length of the output vector
//  Returns:  ippStsNoErr, if no errors
*/
IPPAPI( IppStatus, ippsCrossCorr_NormM_16s, (const Ipp16s *pSrc1, const Ipp16s *pSrc2, int len,
       Ipp16s *pDst) )
IPPAPI( IppStatus, ippsCrossCorr_16s32s_Sfs, (const Ipp16s *pSrc1, const Ipp16s *pSrc2, int len,
       Ipp32s *pDst, int scaleFactor) )
/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsOpenLoopPitchSearch
//  Purpose:     Find the best codebook delay by open-loop pitch analysis
//                 r[lag]=SUM(n=0,...,L_FRAME-1) src[n]*src[n-lag]
//                 within the range [lowerLag,upperLag] of the lags.
//  Parameters:
//    pSrc       pointer to the input vector of range [pSrc-upperLag,pSrc+L_FRAME-1]
//    bestLag    pointer to the output best open-loop pitch lag
//    pPitch     pointer to the output best pitch
//  Returns:  ippStsNoErr, if no errors
*/
IPPAPI( IppStatus, ippsOpenLoopPitchSearch_G729_16s, (const Ipp16s *pSrc, Ipp16s* bestLag) )
IPPAPI( IppStatus, ippsOpenLoopPitchSearch_G729A_16s, (const Ipp16s *pSrc, Ipp16s* bestLag) )
IPPAPI( IppStatus, ippsOpenLoopPitchSearch_G723_16s, ( const Ipp16s *pSrc, Ipp16s* bestLag ) )
/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsDotProd
//  Purpose:     Compute energy of signal using formula:
//                 energy=SUM(n=0,...,len-1) src[n]*src{n)
//  Parameters:
//    pSrc1    pointer to the first input vector
//    pSrc2    pointer to the second input vector
//    srclen   length of the autocorrelation
//    dstLen   length of output vector
//    pDp      pointer to the output energy
//  Returns:  ippStsNoErr, if no errors
//            ippStsOverflow, if at least one result really was saturated
*/
IPPAPI( IppStatus, ippsDotProd_G729A_16s32s, (const Ipp16s* pSrc1, const Ipp16s* pSrc2, int len,
       Ipp32s* pDp) )
IPPAPI( IppStatus, ippsDotProdAutoScale_16s32s_Sfs, (const Ipp16s* pSrc1,const Ipp16s* pSrc2,
       int len, Ipp32s* pDp, int *pSfs) )


/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsLagWindow
//  Purpose:     A 60 Hz bandwidth expansion is applied to input auto-correlation
//                 r[0]=1.0001*r[0];
//                 r[k]=wlag[k]*r[k];
//               60 Hz bandwidth expansion coefficients
//               w_lag(k)=exp[-1/2*(2*pi*f0*k/fs)^2]
//               where : f0 = 60   Hz
//                     fs = 8000 Hz
//  Parameters:
//    pSrcDst    pointer to the autocorrelation vector
//    len        length of the autocorrelation vector
//  Returns:  ippStsNoErr, if no errors
*/
IPPAPI( IppStatus, ippsLagWindow_G729_32s_I, (Ipp32s *pSrcDst, int len) )
/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsLSPToLSF
//               pLSF[i] = arccos(pLSP[i]);  i=0,...,10
//    pLSP       pointer to the LSP input vector of values 15 bit scaled in range [-1:1]
//    pLSF       pointer to the LSF output vector
//               ippsLSPToLSF_G729_16s:      13 bit scaled in range [0:pi]
//               ippsLSPToLSF_Norm_G729_16s: 15 bit scaled in range [0:0.5]
//  Parameters:
//  Returns:  ippStsNoErr, if no errors
*/
IPPAPI( IppStatus, ippsLSPToLSF_G729_16s, (const Ipp16s *pLSP, Ipp16s *pLSF) )
IPPAPI( IppStatus, ippsLSPToLSF_Norm_G729_16s, (const Ipp16s *pLSP, Ipp16s *pLSF) )
/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsLSFQuant
//  Purpose:     Quantize of LSPs
//  Parameters:
//    pLSF             pointer to the input vector of LSF representation of LSP
//    pQuantLSFTable   pointer to the table of the previously quantized LSFs
//    prevLSF          pointer to the input vector of previously quantized LSFs
//    pQuantLSF        pointer to the output vector of quantized LSF
//    quantIndex       pointer to the output combined codebook indices
//                     G729 - MA,L0,L1,L2
//  Returns:  ippStsNoErr, if no errors
//            ippStsLSFHigh, ippStsLSFLow or ippStsLSFLowAndHigh warnings
*/
IPPAPI( IppStatus, ippsLSFQuant_G729_16s, (const Ipp16s *pLSF, Ipp16s *pQuantLSFTable,
        Ipp16s *pQuantLSF, Ipp16s *quantIndex) )
IPPAPI( IppStatus, ippsLSFQuant_G729B_16s, (const Ipp16s *pLSF, Ipp16s *pQuantLSFTable,
        Ipp16s *pQuantLSF, Ipp16s *quantIndex) )
/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsLSFDecode
//  Purpose:     Construct LSFs by codebook indices
//  Parameters:
//    quantIndex       pointer to the input vector of codebook indices ( L0,L1,L2 )
//    pQuantLSFTable   pointer to the table of the previously quantized LSFs
//    pPrevLSF         pointer to the input vector of the previously quantized LSFs
//    pLSF             pointer to the constructed LSF output vector
//  Returns:  ippStsNoErr, if no errors
//            ippStsLSFHigh, ippStsLSFLow or ippStsLSFLowAndHigh warnings
*/
IPPAPI( IppStatus, ippsLSFDecode_G729_16s, (const Ipp16s *quantIndex, Ipp16s *pQuantLSPTable,
       Ipp16s *pQuantLSF) )
IPPAPI( IppStatus, ippsLSFDecodeErased_G729_16s, (Ipp16s maIndex, Ipp16s *pQuantLSFTable,
       Ipp16s *pLSF) )
IPPAPI( IppStatus, ippsLSFDecode_G729B_16s, (const Ipp16s *quantIndex, Ipp16s *pQuantLSFTable,
        Ipp16s *pLSF) )
IPPAPI( IppStatus, ippsLSFDecode_G723_16s, ( const Ipp16s *quantIndex, const Ipp16s *pPrevLSF,
        int erase, Ipp16s *pLSF ) )
/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsLSFToLSP
//  Purpose:     LSF interpolation and conversion to LPC
//  Parameters:
//    pLSF       pointer to the LSF input vector
//    pLPC       pointer to the LPC output vector of values in range [-1,1] 15 bit scaled
//  Returns:  ippStsNoErr, if no errors
//
*/
IPPAPI( IppStatus, ippsLSFToLSP_G729_16s, (const Ipp16s *pLSF, Ipp16s *pLSP) )
/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsInterpolation
//  Purpose:     interpolation of two vector
//               ippsInterpolation_G729_16s: dst = ((src1+sign(src1) )>>1+((src2+sign(src2) )>>1
//               ippsInterpolationC_G729_16s_Sfs: dst = (val1*src1+val2*src2)>>scaleFactor
//  Parameters:
//    pSrc1      pointer to the input vector1
//    pSrc2      pointer to the input vector2
//    pDst       pointer to the interpolated output vector
//    len        length of the vectors
//  Returns:  ippStsNoErr, if no errors
*/
IPPAPI( IppStatus, ippsInterpolate_G729_16s, (const Ipp16s *pSrc1, const Ipp16s *pSrc2,
        Ipp16s *pDst, int  len) )
IPPAPI( IppStatus, ippsInterpolateC_G729_16s_Sfs, (const Ipp16s *pSrc1, Ipp16s val1,
        const Ipp16s *pSrc2, Ipp16s val2, Ipp16s *pDst, int  len, int scaleFactor) )
IPPAPI( IppStatus, ippsInterpolateC_NR_G729_16s_Sfs, (const Ipp16s *pSrc1, Ipp16s val1,
        const Ipp16s *pSrc2, Ipp16s val2, Ipp16s *pDst, int  len, int scaleFactor) )
/* ////////////////////////////////////////////////////////////////////////////////////////
//  Name:        ippsLSPToLPC
//  Name:        ippsLSFToLPC
//  Purpose:     LSP conversion to LPC
//  Parameters:
//    pLSP       pointer to the LSP input vector
//    pLPC       pointer to the LPC output vector of values in range [-1,1] 15 bit scaled
//    pLSFLPC    pointer to the input LSF/output LPC vector
//  Returns:  ippStsNoErr, if no errors
//
*/
IPPAPI( IppStatus, ippsLSPToLPC_G729_16s, (const Ipp16s *pLSP, Ipp16s *pLPC) )

/* ///////////////////////////////////////////////////////////////////////////////////////
//  Name:        ippsResidualFilter
//  Purpose:     Compute the LPC residual by filtering the input speech through A(z)
//  Parameters:
//    pSrc       pointer to the input vector
//    pLPC       pointer to the input LPC
//    pDst       pointer to the output vector of length L_SUBFR
//  Returns:  ippStsNoErr, if no errors
//
*/
IPPAPI( IppStatus, ippsResidualFilter_G729_16s, ( const Ipp16s * pSrc, const Ipp16s * pLPC,
        Ipp16s * pDst) )
/* ///////////////////////////////////////////////////////////////////////////////////////
//  Name:        ippsSynthesisFilter
//  Purpose:     Compute the sheech signal by synthesis filtering of the input speech through
//                   1/A(z)
//  Parameters:
//    pSrc           pointer to the input vector
//    pLPC           pointer to the input LPC
//    pSrcDst        pointer to the history input/filtered output
//    pDst           pointer to the filtered output
//    pMem           Pointer to the memory supplied for filtering
//  Returns:  ippStsNoErr, if no errors
//            ippStsOverflow, if at least one result really was saturated
*/
IPPAPI( IppStatus, ippsSynthesisFilter_NR_16s_Sfs, (const Ipp16s * pLPC, const Ipp16s * pSrc,
        Ipp16s * pDst, int len, int scaleFactor, const Ipp16s *pMem) )
IPPAPI( IppStatus, ippsSynthesisFilterLow_NR_16s_ISfs, (const Ipp16s * pLPC, Ipp16s * pSrcDst,
       int len, int scaleFactor, const Ipp16s *pMem) )
IPPAPI( IppStatus, ippsSynthesisFilter_NR_16s_ISfs, (const Ipp16s * pLPC, Ipp16s * pSrcDst,
       int len, int scaleFactor, const Ipp16s *pMem) )
IPPAPI( IppStatus, ippsSynthesisFilter_G729_16s,
       (const Ipp16s * pSrcResidual, const Ipp16s * pSrcLPC, Ipp16s * pSrcDstSpch))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsConv
//  Purpose:    Linear Convolution of 1D signals
//               dst[n] = sum(i=[0,n])(src1[i]*src2[n-i]), n=[0,len-1]
//              computation is the same as for
//                  ippsConv_16s32s(pSrc1,len,pSrc2,len,pDst)
//              but only len results are computed and written to destination vector.
//  Parameters:
//    pSrc1     pointer to the first source vector
//    pSrc2     pointer to the second source vector
//    pDst      pointer to the destination vector
//    len       length of the destination vector
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI( IppStatus, ippsConvPartial_16s_Sfs,
       ( const Ipp16s* pSrc1, const Ipp16s* pSrc2,  Ipp16s* pDst, int len, int scaleFactor) )
IPPAPI(IppStatus, ippsConvPartial_16s32s,
       ( const Ipp16s* pSrc1, const Ipp16s* pSrc2,  Ipp32s* pDst, int len))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsDecodeAdaptiveVector
//  Purpose:    Compute adaptive-codebook vector by interpolatindg the past excitation signal
//              at the given integer delay and fraction
//  Parameters:
//    pSrcDstPrevExcitation   pointer to the source/destination past excitation signal
//    pDstAdptVector   pointer to the destination adaptive-codebook vector
//    pSrcDelay        pointer to fractional pitch delay:
//                        pSrcDelay[0] -  pitch delay
//                        pSrcDelay[1] -  pitch fraction
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI( IppStatus, ippsDecodeAdaptiveVector_G729_16s_I,(const Ipp16s * pSrcDelay,
       Ipp16s * pSrcDstPrevExcitation))
IPPAPI( IppStatus, ippsDecodeAdaptiveVector_G729_16s,(const Ipp16s * pSrcDelay,
       Ipp16s * pSrcDstPrevExcitation, Ipp16s * pDstAdptVector))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsAdaptiveCodebookContribution
//  Purpose:    Update target vector for codebook search
//              by subtracting the adaptive codebook contribition:
//                pDstFltAdptVector[i] = pSrcAdptTarget[i]-gain*pDstFltAdptVector[i];
//              G.729 3.8.1
//  Parameters:
//    gain               adaptive codebook gain
//    pFltAdptVector     pointer to the filtered adaptive codebook vector y(n)
//    pSrcAdptTarget     pointer to the target signal
//    pDstAdptTarget     pointer to the output target signal
                         (updated by subtracting the adaptive codebook contribition)
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI(IppStatus,ippsAdaptiveCodebookContribution_G729_16s, (Ipp16s gain,
       const Ipp16s *pFltAdptVector, const Ipp16s *pSrcAdptTarget, Ipp16s* pDstAdptTarget))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsFixedCodebookSearch
//  Purpose:    Search in fixed codebook for four non zero pulses, which minimize MSE
//              between the weighted input speech and weighted teconstructed speech.
//              The target signal used in the close-loop pitch search is updated by
//              substracting of adaptive-codebook contribution by formulae:
//                 x[n] = x[n] - g*y[n], n=0,...,39
//              where:      g - adaptive-codebook gain
//                          y - filtered adaptive-codebook vector
//                          x - weighted input
//  Parameters:
//    pSrcFixedCorr   pointer to the correlation vector of the impulse response and target
//    pSrcDstMatrix   pointer to the correlation matrix of impulse response.
//    pDstFixedVector pointer to the output selected acodeword
//    pSearchTimes    pointer to the input/output extra searching time
//    pDstFixedIndex  pointer to the output codeword index
//    pSrc1     pointer to the correlation vector of the impulse response and target
//    pSrcDst   pointer to the correlation matrix of impulse response.
//    pSrc2     Impulse response
//    pDst1     pointer to the output selected acodeword
//    pDst2     pointer to the output filteredcodeword
//    pSign     pointer to the output sign of 4 pulses selected
//    subFrame  input sub frame number      (0,1)
//    extraTime pointer to the input/output extra searching time
//    pDstFixedIndex     pointer to the output codeword index
//    len       length of the destination vectors
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI( IppStatus, ippsFixedCodebookSearch_G729_32s16s, (const Ipp16s *pSrcFixedCorr,
       Ipp32s *pSrcDstMatrix, Ipp16s *pDstFixedVector,
       Ipp16s *pDstFixedIndex, Ipp16s *pSearchTimes, Ipp16s subFrame))
IPPAPI( IppStatus, ippsFixedCodebookSearch_G729_16s, (const Ipp16s *pSrcFixedCorr,
       Ipp16s *pSrcDstMatrix, Ipp16s *pDstFixedVector,
       Ipp16s *pDstFixedIndex, Ipp16s *pSearchTimes, Ipp16s subFrame))
IPPAPI(IppStatus,ippsFixedCodebookSearch_G729A_32s16s,(const Ipp16s *pSrcFixedCorr,
       Ipp32s *pSrcDstMatrix, Ipp16s *pDstFixedVector, Ipp16s *pDstFixedIndex))
IPPAPI(IppStatus,ippsFixedCodebookSearch_G729A_16s,(const Ipp16s *pSrcFixedCorr,
       Ipp16s *pSrcDstMatrix, Ipp16s *pDstFixedVector, Ipp16s *pDstFixedIndex))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsHarmonicFilter
//  Purpose:    Enchance harmonic component of signal by formulae:
//              y[n] = x[n] + val * x[n-T] - harmonic nose shaping: 1+val*z^(-T)
//              y[n] = y[n] + val * y[n-T] - adaptive pre-filter:  1/(1-val*z^(-T) )
//  Parameters:
//    val       the input factor of filter
//    T         the value of delay
//    pSrc      pointer to the input vector
//    pDst      pointer to the output vector
//    pSrcDst   pointer to the input/output vector
//    len       number of output results needed.
//                  pSrc[-T,1] or pSrcDst[-T,-1] shell be done
//              pDst[0,len-1] or pSrcDst[0,len-1] will be computed.
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI( IppStatus, ippsHarmonicFilter_16s_I, (Ipp16s val, int T, Ipp16s *pSrcDst, int len) )
IPPAPI( IppStatus, ippsHarmonicFilter_NR_16s, (Ipp16s val, int T, const Ipp16s *pSrc,
       Ipp16s *pDst, int len) )
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsGainQuant
//  Purpose:    Quantization of the adaptive codebook gains
//    pSrcAdptTarget      pointer to the input target vector x(n).
//    pSrcFltAdptVector   pointer to the input filterd adaptive codebook vector y(n)
//    pSrcFixedVector     pointer to the input pre-filtered codebook contribition c(n)
//    pSrcFltFixedVector  pointer to the input filtered codebook vector z(n)
//    pSrcDstEnergyErr    pointer to the input/output energy error vector
//                        for 4 previous subframes
//    energy     energy  of innovative vector.
//    tameflag   1 - taming is needed
//    pD1        pointer to the output pitch gain.
//    pD2        pointer to the output code gain.
//    pIndex     pointer to the output codebook index found
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI(IppStatus, ippsGainQuant_G729_16s, (
       const Ipp16s *pSrcAdptTarget, const Ipp16s *pSrcFltAdptVector,
       const Ipp16s * pSrcFixedVector, const Ipp16s *pSrcFltFixedVector,
       Ipp16s *pSrcDstEnergyErr, Ipp16s *pDstQGain, Ipp16s *pDstQGainIndex, Ipp16s tameProcess) )

/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsGainQuant
//  Purpose:    Construct of the excitation for the high rate coder by
//              MultiPulse Maximum Likelihood Quantization (MP-MLQ) of the residual
//              signal
//    pImp      pointer to the input impulse responce of combined filter
//    pSrc      pointer to the input target vector.
//    pDstLoc   pointer to the output pulse location
//    pDstAmp   pointer to the output pulse amplitudes
//    pMaxErr   pointer to the output maximal error
//    pGrid     output grid (even = 0, odd = 1)
//    pAmp      output index of max codebook amplitude
//    Np        input number of pulses
//    isBest    shows whether best gain found (1) or not (0)
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI( IppStatus, ippsGainQuant_G723_16s, (const Ipp16s *pImp, const Ipp16s *pSrc,
       Ipp16s *pDstLoc, Ipp16s *pDstAmp, Ipp32s *pMaxErr, Ipp16s *pGrid, Ipp16s *pAmp,
       int Np, int* isBest) )
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsDecodeGain
//  Purpose:    Decode adaptive and fixed-codebook gains
//    energy       energy of code vector in Q32
//    pPastEnergy  past quantized energies
//    quaIndex     pointer to the gain quantization indexes transmitted:
//                 quaIndex[0] - GA, quaIndex[1] - GB.
//                 NULL for bad frame
//    pGain        Pointer to the vector of decoded gains:
//                 pGain[0] - adaptive and pGain[1] - fixed codebook gains.
//                 For active frame: output vector.
//                 For bad (erased) frame - input/output vector.
//                 Input of gains decoded for previous frame.
//                 See subclause G.729 3.9.1
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI( IppStatus, ippsDecodeGain_G729_16s, (Ipp32s energy, Ipp16s *pPastEnergy,
       const Ipp16s *quaIndex, Ipp16s *pGain) )

/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsTiltCompensation
//  Purpose:    Tilt compensation filter
//              G729:  transfer function 1/(1-|mu|) * (1 + mu * 1/z)
//              G723:  transfer function 1 + 0.25*k1*(1/z)
//    pSrc                 pointer to the input vector
//    val                  gain coefficient
//    pDst                 pointer to the output filtered vector
//    pSrcImpulseResponse  Pointer to the impulse response hf(n) in the length of 20, in Q12.
//    pSrcDstSpch          Pointer to the speech x(n), in Q15
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI( IppStatus, ippsTiltCompensation_G723_32s16s, (Ipp16s val, const Ipp32s *pSrc,
       Ipp16s *pDst) )

IPPAPI (IppStatus, ippsTiltCompensation_G729_16s,(const Ipp16s * pSrcImpulseResponse,
                                        Ipp16s * pSrcDstSpch))
IPPAPI (IppStatus, ippsTiltCompensation_G729A_16s,
       (const Ipp16s * pSrcLPC,Ipp16s * pSrcDstFltResidual))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsLongTermPostFilter
//  Purpose:    Long-term post G729 filtering
//    valDelay        pitch delay
//    pSrcSpch        Pointer to the resconstructed speech s[n]
//    pSrcLPC         Pointer to weighted LP coff a'[i]
//    pSrcDstResidual Pointer to LP residual signal.
//    pDstFltResidual Pointer to output filtered residual signal.
//    pResultVoice    Pointer to the voice information.
//		frameType	    The type of the frame (1 - active, 2 - SID, 0 - untransmitted).
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI(IppStatus, ippsLongTermPostFilter_G729A_16s,(Ipp16s valDelay, const Ipp16s * pSrcSpch,
       const Ipp16s * pSrcLPC, Ipp16s * pSrcDstResidual, Ipp16s * pDstFltResidual))
IPPAPI(IppStatus, ippsLongTermPostFilter_G729B_16s,(Ipp16s valDelay, const Ipp16s * pSrcSpch,
       const Ipp16s * pSrcLPC, Ipp16s * pSrcDstResidual, Ipp16s * pDstFltResidual,
       Ipp16s * pResultVoice, Ipp16s frameType))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsShortTermPostFilter
//  Purpose:    Short-term post G729 filtering
//    pSrcDstSpch         Pointer to the short-term filtered speech y(n), in Q15
//    pSrcLPC             Pointer to the quantized LP coefficients in the length of 11, in Q12
//    pDstFltResidual     Pointer to the residual signal x(n) in the length of 40, in Q15.
//    pDstImpulseResponse Pointer to the generated impulse response hf(n)
//                             in the length of 20, in Q12..
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI( IppStatus, ippsShortTermPostFilter_G729_16s, (const Ipp16s * pSrcLPC,
        const Ipp16s * pSrcFltResidual, Ipp16s * pSrcDstSpch, Ipp16s * pDstImpulseResponse))
IPPAPI( IppStatus, ippsShortTermPostFilter_G729A_16s,(const Ipp16s * pSrcLPC,
        const Ipp16s * pSrcFltResidual,Ipp16s * pSrcDstSpch))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsPreemphasize
//  Purpose:    Preemphasis post filter
//               H(z) =  1 - gamma z^-1   (G.729/A)
//    pSrcDst   pointer to the input/output vector
//    gamma     filter coeeficient
//    pMem      pointer to the filter memory of length 1
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI( IppStatus, ippsPreemphasize_G729A_16s_I, (Ipp16s gamma, Ipp16s *pSrcDst, int len,
       Ipp16s* pMem) )
IPPAPI( IppStatus, ippsPreemphasize_G729A_16s, (Ipp16s gamma, const Ipp16s *pSrc, Ipp16s *pDst,
       int len, Ipp16s* pMem) )

/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsGainControl
//  Purpose:    Adaptive gain control
//              Compensate for the gain difference between reconstructed speech signal given
//              pSrc (sr) and the postfiltered signal given by pSrcDst (spf)
//                   dst[i] = g[i] * dst[i]
//              Gain factor g[i] computed by:
//                G729  :    g[i-1] = 0.85 * g[i-1] + 0.15 * G,  where
//                              G = (sum(i=0,39)|sr[i]|) / (sum(i=0,39)|spf[i]|)
//                G729A :    g[i-1] = 0.9 * g[i-1] + 0.1 * G,   where
//                              G = sqrt((sum(i=0,39)|sr[i]^2|) / (sum(i=0,39)|spf[i]|^2) )
//                      g[-1]=1.0
//              G729A:
//                  G = sqrt(sum(i=0,39)|sr[i]|) / (sum(i=0,39)|spf[i]|) )
//                       dst[i] = g[i] * dst[i] where

//    pSrc      pointer to the input vector
//    pSrcDst   pointer to the input/output vector
//    pGain     the gain for the previous subframe
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI( IppStatus, ippsGainControl_G729_16s_I, (const Ipp16s *pSrc, Ipp16s *pSrcDst,
       Ipp16s *pGain) )
IPPAPI( IppStatus, ippsGainControl_G729A_16s_I, (const Ipp16s *pSrc, Ipp16s *pSrcDst,
       Ipp16s *pGain) )
IPPAPI( IppStatus, ippsGainControl_G723_16s_I, (Ipp32s energy, Ipp16s *pSrcDst, Ipp16s *pGain) )

/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsRandomNoiseExcitation
//  Purpose:    Generation of random noise excitation
//   gain       target sample gain
//   pSrcDst    pointer to the input/output excitation vector
//   pSeed      pointer to the input/output seed for the random generator
//   pPitch     output random pitch delay (current VAD decision)
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI( IppStatus, ippsRandomNoiseExcitation_G729B_16s, (Ipp16s *pSeed, Ipp16s *pExc, int len) )



/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsLPCLevinsonDurbin
//  Purpose:     Obtaining of the LPC
//               G.729:  filter 1/1-A(z), LPC in Q12, by solving the set of equation
//                 SUM(i=1,10)a(i)*r(|i-k|) = -r(k)  k=1,..,10
//  Parameters:
//    pSrcAutoCorr          pointer to the autocorrelation vector
//    pDstLPC               pointer to the LPC output vector
//    pSrcDstRC             pointer to the RC input/output vector
//    pResultResidualEnergy pointer to output residual energy in Q15
//
*/
IPPAPI(IppStatus,ippsLevinsonDurbin_G729B,(const Ipp32s * pSrcAutoCorr,
       Ipp16s * pDstLPC, Ipp16s * pSrcDstRC, Ipp16s * pResultResidualEnergy))

IPPAPI(IppStatus, ippsLevinsonDurbin_G723_16s,
	(const Ipp16s * pSrcAutoCorr, Ipp16s * pValResultSineDtct,
	Ipp16s * pResultResidualEnergy, Ipp16s * pDstLPC))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsIIR16s_G723_16s32s
//  Name:       ippsIIR16s_G723_16s_I
//  Name:       ippsIIR16s_G723_32s16s_Sfs
//
//  Purpose:    IIR filter
//                  1-A(1/z)/1-B(1/z)
//   pCoeffs    pointer to the input filter coefficients
//   pSrc       pointer to the input speech vector
//   pDst       pointer to the output perceptually weighted speech vector
//   pMem       pointer to the filter memory
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI( IppStatus, ippsIIR16s_G723_16s32s, (const Ipp16s *pCoeffs, const Ipp16s *pSrc,
       Ipp32s *pDst, Ipp16s *pMem ) )
IPPAPI( IppStatus, ippsIIR16s_G723_16s_I, (const Ipp16s *pCoeffs, Ipp16s *pSrcDst,
       Ipp16s *pMem ) )
IPPAPI( IppStatus, ippsIIR16s_G723_32s16s_Sfs, (const Ipp16s *pCoeffs, const Ipp32s *pSrc,
       int sFs, Ipp16s *pDst, Ipp16s *pMem ) )
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsHarmonicNoiseSubtract_G723_16s_I
//
//   Purpose:   Do harmonic noise filtering and subtract the result
//              from harmonic noise weighted vector
//   val        the input filter coefficient
//   T          the input filter lag
//   pSrc       pointer to the input vector to filter
//   pSrcDst    pointer to the input/output harmonic noise weighted vector
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI( IppStatus, ippsHarmonicNoiseSubtract_G723_16s_I, (Ipp16s val, int T, const Ipp16s *pSrc,
       Ipp16s *pSrcDst) )


/*******************************************************************************
//       StrongARM/XScale G729 compatibility function set                     //
*******************************************************************************/

/* /////////////////////////////////////////////////////////////////////////////
//   Name : ippsAutoCorr_G729B
//   Purpose: Apply window and then compute autocorelation of input speech
//            Equvalent to:
//                 ippsMul_NR_16s_Sfs
//                 ippsAutoCorr_NormE_16s32s
*/

IPPAPI(IppStatus,ippsAutoCorr_G729B,
       (const Ipp16s* pSrcSpch, Ipp16s* pResultAutoCorrExp, Ipp32s* pDstAutoCorr))

IPPAPI( IppStatus, ippsLPCToLSP_G729_16s,
       (const Ipp16s* pLPC, const Ipp16s* pSrcPrevLsp, Ipp16s* pLSP) )
IPPAPI( IppStatus, ippsLPCToLSP_G729A_16s,
       (const Ipp16s* pLPC, const Ipp16s* pSrcPrevLsp, Ipp16s* pLSP) )

/* /////////////////////////////////////////////////////////////////////////////
//   Name : ippsAdaptiveCodebookSearch_G729_16s
//   Purpose: Determination of optimal integer and fractional pitch delay
//            and generation of adaptive codebook vector
*/
IPPAPI( IppStatus, ippsAdaptiveCodebookSearch_G729_16s, (Ipp16s valOpenDelay,
        const Ipp16s * pSrcAdptTarget, const Ipp16s * pSrcImpulseResponse,
        Ipp16s * pSrcDstPrevExcitation, Ipp16s * pDstDelay,
        Ipp16s * pDstAdptVector, Ipp16s subFrame))
IPPAPI( IppStatus, ippsAdaptiveCodebookSearch_G729A_16s, (Ipp16s valOpenDelay,
        const Ipp16s * pSrcAdptTarget, const Ipp16s * pSrcImpulseResponse,
        Ipp16s * pSrcDstPrevExcitation, Ipp16s * pDstDelay,
        Ipp16s * pDstAdptVector, Ipp16s subFrame))
/* /////////////////////////////////////////////////////////////////////////////
//   Name : ippsLSPQuant_G729_16s
//   Purpose: LSP quantization
//            Equvalent to:
//                 ippsLSPToLSF_G729_16s
//                 ippsLSFQuant_G729_16s
*/
IPPAPI( IppStatus, ippsLSPQuant_G729_16s, (const Ipp16s * pSrcLsp, Ipp16s * pSrcDstPrevFreq,
        Ipp16s * pDstQLsp, Ipp16s * pDstQLspIndex))
/* /////////////////////////////////////////////////////////////////////////////
//   Name : ippsAdaptiveCodebookGain_G729_16s
//   Purpose: Compute the adaptive codebook gain
//
//   pSrcImpulseResponse:  Pointer to the impulse response
//                         of the perceptual weighting filter in the length of 40, in Q12.
//   pSrcAdptVector:       Pointer to the adaptive-codebook vector in the length of 40.
//   pSrcLPC:              Pointer to the LPC coefficients of the synthesis filter
//                         in the length of 11, in Q12.
//   pDstFltAdptVector:    Pointer to the output filtered adaptive-codebook vector
//   pSrcFltAdptVector:    Pointer to the input filtered adaptive-codebook vector
//                         in the length of 40.
//   pResultAdptGain:      Pointer to the adaptive-codebook gain in the length of 1, in Q14.
*/
IPPAPI( IppStatus, ippsAdaptiveCodebookGain_G729_16s, (const Ipp16s * pSrcAdptTarget,
       const Ipp16s * pSrcImpulseResponse, const Ipp16s * pSrcAdptVector,
       Ipp16s * pDstFltAdptVector, Ipp16s * pResultAdptGain))
IPPAPI( IppStatus, ippsAdaptiveCodebookGain_G729A_16s, (const Ipp16s * pSrcAdptTarget,
       const Ipp16s * pSrcLPC, const Ipp16s * pSrcAdptVector, Ipp16s * pDstFltAdptVector,
       Ipp16s * pResultAdptGain))

/*******************************************************************************
//       StrongARM/XScale G723 compatibility function set                     //
*******************************************************************************/

/* /////////////////////////////////////////////////////////////////////////////
//   Name : ippsAutoCorr_G723_16s
//   Purpose: Apply window and then compute autocorelation of input speech
//            Equvalent to:
//                 ippsAutoScale_16s
//                 ippsMul_NR_16s_ISfs
//                 ippsAutoCorr_NormE_G723_16s
*/

IPPAPI(IppStatus, ippsAutoCorr_G723_16s,(const Ipp16s * pSrcSpch,
	Ipp16s * pResultAutoCorrExp, Ipp16s * pDstAutoCorr))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:        ippsLPCToLSF_G723_16s
//  Purpose:     LSP to LSF conversion normalized
//               pLSF[i] = arccos(pLSP[i]);  i=0,...,10
//    pSrcLPC     pointer to the LPC input vector
//    pSrcPrevLSF pointer to previous normalized LSF coefficients
//    pDstLSF     pointer to the LSF output vector of values 15 bit scaled in range [0:0.5]
//  Parameters:
//  Returns:  ippStsNoErr, if no errors
*/
IPPAPI(IppStatus, ippsLPCToLSF_G723_16s,(const Ipp16s * pSrcLPC,
	const Ipp16s * pSrcPrevLSF, Ipp16s * pDstLSF))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:         ippsHarmonicSearch_G723_16s
//  Purpose:      This function searches the harmonic delay and harmonic gain for the harmonic noise shaping filter
//                 from the weighted speech and open loop pitch.
//    valOpenDelay          Open loop pitch
//    pSrcWgtSpch           Pointer to the weighted speech in the length of 205. The pointer points to the
//                           location of 146
//    pResultHarmonicDelay  Pointer to the harmonic delay
//    pResultHarmonicGain   Pointer to the harmonic gain
//  Parameters:
//  Returns:  ippStsNoErr, if no errors
*/
IPPAPI(IppStatus, ippsHarmonicSearch_G723_16s,(Ipp16s valOpenDelay, const Ipp16s * pSrcWgtSpch,
Ipp16s * pResultHarmonicDelay, Ipp16s * pResultHarmonicGain))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:         ippsAdaptiveCodebookSearch_G723
//  Purpose:      This function searches for the close loop pitch and adaptive gain index.
//    valBaseDelay         Base delay
//    pSrcAdptTarget       Pointer to the adaptive target signal in the length of 60.
//    pSrcImpulseResponse  Pointer to the impulse response in the length of 60.
//    pSrcPrevExcitation   Pointer to the previous excitation in the length of 145.
//    pSrcPrevError        Pointer to the previous error in the length of 5, in 32-bit format.
//    pResultCloseLag      Pointer to the lag of close pitch
//    pResultAdptGainIndex Pointer to the index of adaptive gain
//    subFrame             Subframe number
//    sineDtct             Sine circumstance.
//    bitRate              Transmit bit rate
//  Parameters:
//  Returns:  ippStsNoErr, if no errors
*/
IPPAPI (IppStatus, ippsAdaptiveCodebookSearch_G723,(
   Ipp16s valBaseDelay,
   const Ipp16s * pSrcAdptTarget,
   const Ipp16s * pSrcImpulseResponse,
   const Ipp16s * pSrcPrevExcitation,
   const Ipp32s * pSrcPrevError,
   Ipp16s * pResultCloseLag,
   Ipp16s * pResultAdptGainIndex,
   Ipp16s subFrame,
   Ipp16s sineDtct,
   IppSpchBitRate bitRate))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:         ippsDecodeAdaptiveVector_G723_16s
//  Purpose:      This function decodes the adaptive vector from excitation,
//                close loop pitch, adaptive gain index and bit rate.
*/
IPPAPI (IppStatus, ippsDecodeAdaptiveVector_G723_16s,(
        Ipp16s valBaseDelay,
        Ipp16s valCloseLag,
        Ipp16s valAdptGainIndex,
        const Ipp16s * pSrcPrevExcitation,
        Ipp16s * pDstAdptVector,
        IppSpchBitRate bitRate))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:         ippsLSFToLPC_G723_16s
//  Purpose:      This function converts a set of 10-order LSF coefficients to LPC coefficients.
//            Equvalent to:
//                 ippsLSFToLPC_G723_16s_I
*/
IPPAPI (IppStatus, ippsLSFToLPC_G723_16s,(const Ipp16s * pSrcLSF, Ipp16s * pDstLPC))
IPPAPI( IppStatus, ippsLSFToLPC_G723_16s_I, (Ipp16s *pLSFLPC) )

/* /////////////////////////////////////////////////////////////////////////////
//  Name:         ippsLSFQuant_G723_16s32s
//  Purpose:      This function searches for the close loop pitch and adaptive gain index.
//    pSrcLSF           Pointer to LSF coefficients
//    pSrcPrevLSF       Pointer to previous LSF coefficients
//    pResultQLSFIndex  Pointer to combined index of quantized LSF coefficients.
//  Parameters:
//  Returns:  ippStsNoErr, if no errors
*/
IPPAPI(IppStatus, ippsLSFQuant_G723_16s32s,(const Ipp16s * pSrcLSF, const Ipp16s *pSrcPrevLSF,
                                       Ipp32s * pResultQLSFIndex))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:         ippsACELPFixedCodebookSearch_G723_16s
//  Purpose:      TThis function searches for the ACELP fixed codebook for the excitation for 5.3 Kbps bit rate.
//            Equvalent to:
//                 ippsFixedCodebookSearch_G723_16s
*/
IPPAPI (IppStatus, ippsACELPFixedCodebookSearch_G723_16s,(
        const Ipp16s * pSrcFixedCorr,
        const Ipp16s * pSrcMatrix,
        Ipp16s * pDstFixedSign,
        Ipp16s * pDstFixedPosition,
        Ipp16s * pResultGrid,
        Ipp16s * pDstFixedVector,
        Ipp16s * pSearchTimes))
IPPAPI( IppStatus, ippsACELPFixedCodebookSearch_G723_32s16s,(
        const Ipp16s * pSrcFixedCorr,
        Ipp32s * pSrcDstMatrix,
        Ipp16s * pDstFixedSign,
        Ipp16s * pDstFixedPosition,
        Ipp16s * pResultGrid,
        Ipp16s * pDstFixedVector,
        Ipp16s * pSearchTimes))

/* /////////////////////////////////////////////////////////////////////////////
// Name:       ippsMPMLQFixedCodebookSearch_G723
//
// Purpose:       This function searches for the MP-MLQ fixed-codebook for the excitation for 6.3Kbps bit rate.
// valBaseDelay        - Base delay, in Q0.
// pSrcImpulseResponse - Pointer to the impulse response in the length of 60.
// pSrcResidualTraget  - Pointer to the residue target signal in the length of 60.
// pDstFixedVector     - Pointer to the fixed codebook vector in the length of 60.
// pResultGrid         - Pointer to the begin grid location, in Q0, 0 or 1.
// pResultTrainDirac   - Pointer to the flag if train Dirac function used, 0: unused, 1: used.
// pResultAmpIndex     - Pointer to the index of quantized amplitude, in Q0.
// pResultAmplitude    - Pointer to the amplitude of the fixed codebook vector.
// pResultPosition     - Pointer to the position of fixed codebook vector, which amplitude is not equal
//                        to 0, in Q0.
// subFrame            - Subframe number, in Q0, from 0 to 3.
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI (IppStatus, ippsMPMLQFixedCodebookSearch_G723,(
             Ipp16s valBaseDelay,
             const Ipp16s * pSrcImpulseResponse,
             const Ipp16s * pSrcResidualTraget,
             Ipp16s * pDstFixedVector,
             Ipp16s * pResultGrid,
             Ipp16s * pResultTrainDirac,
             Ipp16s * pResultAmpIndex,
             Ipp16s * pResultAmplitude,
             Ipp32s * pResultPosition,
             Ipp16s subFrame))
/* /////////////////////////////////////////////////////////////////////////////
// Name:       ippsSynthesisFilter_G723_16s
//
// Purpose:       function implements the LPC synthesis filter.
// pSrcLPC      - Pointer to the LPC coefficients in the length of 10, in Q13.
// pSrcResidual - Pointer to the residual signal in the length of 60.
// pSrcDstIIRState - Pointer to the history of synthesized speech signal in the
//                 length of 10.
// pDstSpch     - Pointer to the output speech signal in the length of 60.
// pMem           pointer to the filter memory
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI( IppStatus, ippsSynthesisFilter_G723_16s32s, (const Ipp16s *pQntLPC,  const Ipp16s *pSrc,
       Ipp32s *pDst, Ipp16s *pMem ) )

IPPAPI(IppStatus, ippsSynthesisFilter_G723_16s, (const Ipp16s *pSrcLPC, const Ipp16s *pSrcResidual,
                   Ipp16s *pSrcDstIIRState, Ipp16s *pDstSpch))

/* /////////////////////////////////////////////////////////////////////////////
// Name:       ippsPitchPostFilter_G723_16s
//
// Purpose:       function calculates the coefficients of the pitch post filter..
// valBaseDelay - Base delay, in Q0.
// pSrcResidual - Pointer to the residual signal in the length of 365.
//                 The pointer points to the location of 146.
// subFrame     - Subframe number, in Q0, from 0 to 3.
// bitRate      - Transmit bit rate, IPP_SPCHBR_6300 stands for 6.3 Kbps
//                 and IPP_SPCHBR_5300 stands for 5.3 Kbps.
// pResultDelay - Point to the delay of the pitch post filter, in Q0.
// pResultPitchGain - Point to the gain of the pitch post filter, in Q15.
// pResultScalingGain - Point to the scaling gain of the pitch post filter, in Q15.
//  Returns:    IppStatus
//      ippStsNoErr          if no error
*/
IPPAPI(IppStatus, ippsPitchPostFilter_G723_16s, (Ipp16s valBaseDelay, const Ipp16s *pSrcResidual,
                    Ipp16s *pResultDelay, Ipp16s *pResultPitchGain, Ipp16s *pResultScalingGain,
                    Ipp16s subFrame, IppSpchBitRate bitRate))

#ifdef __cplusplus
}
#endif

#endif /* __IPPSC_H__ */
/* ////////////////////////////// End of file /////////////////////////////// */

