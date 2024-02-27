/* ////////////////////////////////// "ippsr.h" ////////////////////////////////
//
//                  INTEL CORPORATION PROPRIETARY INFORMATION
//     This software is supplied under the terms of a license agreement or
//     nondisclosure agreement with Intel Corporation and may not be copied
//     or disclosed except in accordance with the terms of that agreement.
//          Copyright(c) 1999-2003 Intel Corporation. All Rights Reserved.
//
//           	Intel(R) Integrated Performance Primitives
//                  Speech Recognition (ippsr)
//
*/

#if !defined( __IPPSR_H__ ) || defined( _OWN_BLDPCS )
#define __IPPSR_H__

#ifndef __IPPDEFS_H__
  #include "ippdefs.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if !defined( _OWN_BLDPCS )

/* types */
/*   definition common with reference code   */
typedef enum {
    IPP_DELTA_BEGIN=0x0001,
    IPP_DELTA_END=0x0002
} DeltaMode;

#define   ippsDeltaBegin   IPP_DELTA_BEGIN
#define   ippsDeltaEnd     IPP_DELTA_END

typedef enum {
   IPP_FBANK_MELWGT = 1,
   IPP_FBANK_FREQWGT = 2,
   IPP_POWER_SPECTRUM = 4
} IppMelMode;

typedef enum {
    IPP_CDBK_FULL = 1,
    IPP_CDBK_KMEANS_LONG = 2,
    IPP_CDBK_KMEANS_NUM = 3
} Ipp_Cdbk_Hint;
/////////////////////////////////////////////////////////////////////////////

struct BlockDMatrix_32f;
struct BlockDMatrix_64f;
struct BlockDMatrix_16s;

typedef struct BlockDMatrix_32f IppsBlockDMatrix_32f;
typedef struct BlockDMatrix_64f IppsBlockDMatrix_64f;
typedef struct BlockDMatrix_16s IppsBlockDMatrix_16s;

struct FBankState_16s;
struct DCTLifterState_16s;
struct FBankState_32f;
struct DCTLifterState_32f;

typedef struct FBankState_16s IppsFBankState_16s;
typedef struct DCTLifterState_16s IppsDCTLifterState_16s;
typedef struct FBankState_32f IppsFBankState_32f;
typedef struct DCTLifterState_32f IppsDCTLifterState_32f;

struct CdbkState_32f;
typedef struct CdbkState_32f IppsCdbkState_32f;

struct CdbkState_16s;
typedef struct CdbkState_16s IppsCdbkState_16s;

#endif /* _OWN_BLDPCS */

#define IPP_TRUNC(a,b) ((a)&~((b)-1))
#define IPP_APPEND(a,b) (((a)+(b)-1)&~((b)-1))

/* /////////////////////////////////////////////////////////////////////////////
//                  Definitions for LogAdd Functions
///////////////////////////////////////////////////////////////////////////// */
/*Ipp64f*/
#define IPPSLOGZERO         (-1.0e+10)
#define IPPSLOGSMALL        (-0.9e+10)
#define IPPSMINLOGEXP  -23.0258509299405  /*-log(-LOGZERO)*/
#define IPPSMAXFWDP         (-1.0e-8)     /* highest p<0: exp(p) < DBL_EPSILON */
#define IPPSMINFWDP         -20.0         /* minimum forward probability */
/*Ipp32f*/
#define IPPSLOGZERO_F       (-4.5e+6)
#define IPPSLOGSMALL_F      (-4.5e+6)
#define IPPSMINLOGEXP_F -15.3195879547406 /*-log(-LOGZERO) */
#define IPPSMAXFWDP_F        (-1.0e-4)    /* highest p<0: exp(p) < FLT_EPSILON */
#define IPPSMINFWDP_F       -10.0         /* minimum forward probability */

/* /////////////////////////////////////////////////////////////////////////////
//                  Definitions for LogSub Functions
///////////////////////////////////////////////////////////////////////////// */
#define IPPSMINLARG         (2.45E-308)  /* lowest log() arg  = exp(MINEARG) */
#define IPPSMINMIX          (-11.5129254649702) /* log(1.0e-5) */
#define IPPSMINEARG         (-708.3)     /* lowest exp() arg  = log(MINLARG) */
#define IPPSMINEARG_F         (-85.19)     /* lowest exp() arg  = log(MINLARG_F) */
#define IPPSMINLARG_F       (1.0057e-037)  /* lowest log() arg  = exp(MINEARG_F) */


/*==== Functions declaration =================================================*/
/* /////////////////////////////////////////////////////////////////////////////
//  Name:       ippsrGetLibVersion
//  Purpose:    getting of the library version
//  Returns:    the structure of information about  version of ippsr library
//  Parameters:
//
//  Notes:      not necessary to release the returned structure
*/
IPPAPI( const IppLibraryVersion*, ippsrGetLibVersion, (void) )
/* /////////////////////////////////////////////////////////////////////////////
//  Basic Arithmetics
///////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsAddAllRowSum_32f_D2
//  Purpose:           Calculates the sums of column vectors in a matrix
//                     and adds the sums to a vector.
//  Parameters:
//    pSrc             Pointer to the input vector [height*sStep].
//    mSrc             Pointer to the input matrix [height][width].
//    step             The row step in pSrc.
//    height           The number of rows in the input matrix mSrc.
//    width            Number of columns in the input matrix mSrc, and also the
//                     length of the output vector pSrcDst.
//
//  Returns:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrc, or mSrc, or pSrcDst
//                     pointer is null.
//    ippStsSizeErr    Indicates an error when height or width is less than
//                     or equal to 0.
//    ippStsStrideErr  Indicates an error when width > step.
//
*/
IPPAPI(IppStatus, ippsAddAllRowSum_32f_D2, (const Ipp32f* pSrc, int step,
       int height, Ipp32f* pSrcDst, int width))

IPPAPI(IppStatus, ippsAddAllRowSum_32f_D2L, (const Ipp32f** mSrc, int height,
       Ipp32f* pSrcDst, int width))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsSumColumn_*
//  Purpose:           Calculates sums of column vectors in a matrix.
//
//  Parameters:
//    pSrc             Pointer to the input vector [height*step].
//    mSrc             Pointer to the input matrix [height][width].
//    step             The row step in the input vector pSrc.
//    height           The number of rows in the input matrix mSrc.
//    pDst             Pointer to the output vector [width].
//    width            The number of columns in the input matrix and the length
//                        of the result vector pDst.
//
//  Returns:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrc, mSrc, or pDst pointer
//                     is null.
//    ippStsSizeErr    Indicates an error when height or width is less than
//                     or equal to 0.
//    ippStsStrideErr  Indicates an error when width > step.
//
*/
IPPAPI(IppStatus, ippsSumColumn_16s32s_D2Sfs,(const Ipp16s* pSrc, int step,
       int height, Ipp32s* pDst, int width, int scaleFactor))

IPPAPI(IppStatus, ippsSumColumn_16s32f_D2,(const Ipp16s* pSrc, int step,
       int height, Ipp32f* pDst, int width))

IPPAPI(IppStatus, ippsSumColumn_16s32s_D2LSfs,(const Ipp16s** mSrc, int height,
       Ipp32s* pDst, int width, int scaleFactor))

IPPAPI(IppStatus, ippsSumColumn_16s32f_D2L,(const Ipp16s** mSrc, int height,
       Ipp32f* pDst, int width))

IPPAPI(IppStatus, ippsSumColumn_32f_D2,(const Ipp32f* pSrc, int step,
       int height, Ipp32f* pDst, int width))

IPPAPI(IppStatus, ippsSumColumn_64f_D2,(const Ipp64f* pSrc, int step,
       int height, Ipp64f* pDst, int width))

IPPAPI(IppStatus, ippsSumColumn_32f_D2L,(const Ipp32f** mSrc, int height,
       Ipp32f* pDst, int width))

IPPAPI(IppStatus, ippsSumColumn_64f_D2L,(const Ipp64f** mSrc, int height,
       Ipp64f* pDst, int width))

// The functions use for compatibility
IPPAPI(IppStatus, ippsSumCol_32f_D2,(const Ipp32f* pSrc, int step,
       Ipp32f* pDst, int height, int width))

IPPAPI(IppStatus, ippsSumCol_64f_D2,(const Ipp64f* pSrc, int step,
       Ipp64f* pDst, int height, int width))

IPPAPI(IppStatus, ippsSumCol_32f_D2L,(const Ipp32f** mSrc, int width,
       Ipp32f* pDst, int height))

IPPAPI(IppStatus, ippsSumCol_64f_D2L,(const Ipp64f** mSrc, int width,
       Ipp64f* pDst, int height))

IPPAPI(IppStatus, ippsSumAllRow_32f_D2, (const Ipp32f* pSrc, int step,
       int height, Ipp32f* pDst, int width))

IPPAPI(IppStatus, ippsSumAllRow_32f_D2L, (const Ipp32f** mSrc, int height,
       Ipp32f* pDst, int width))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsSumRow_*
//  Purpose:           Computes the sum of a list of vectors row-wise.
//  Parameters:
//    pSrc             Pointer to the input vector [height*step].
//    mSrc             Pointer to the input matrix [height][width].
//    height           The number of rows in the matrix mSrc and also the length
//                     of the output vector pDst.
//    step             The row step in input vector pSrc.
//    pDst             Pointer to the output vector [height].
//    width            The number of columns in the matrix mSrc.
//    scaleFactor
//
//  Returns:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when pSrc, mSrc, or pDst pointer
//                     is null.
//    ippStsSizeErr    Indicates an error when height or srcWidth is less than
//                     or equal to 0.
//    ippStsStrideErr  Indicates an error when srcWidth > step.
//
*/
IPPAPI(IppStatus, ippsSumRow_32f_D2,(const Ipp32f* pSrc, int width,
       int step, Ipp32f* pDst, int height))

IPPAPI(IppStatus, ippsSumRow_64f_D2,(const Ipp64f* pSrc, int width,
       int step, Ipp64f* pDst, int height))

IPPAPI(IppStatus, ippsSumRow_32f_D2L,(const Ipp32f** mSrc, int width,
       Ipp32f* pDst, int height))

IPPAPI(IppStatus, ippsSumRow_64f_D2L,(const Ipp64f** mSrc, int width,
       Ipp64f* pDst, int height))

IPPAPI(IppStatus, ippsSumRow_16s32s_D2Sfs,(const Ipp16s* pSrc, int width,
       int step, Ipp32s* pDst, int height, int scaleFactor))

IPPAPI(IppStatus, ippsSumRow_16s32f_D2,(const Ipp16s* pSrc, int width,
       int step, Ipp32f* pDst, int height))

IPPAPI(IppStatus, ippsSumRow_16s32s_D2LSfs,(const Ipp16s** mSrc, int width,
       Ipp32s* pDst, int height, int scaleFactor))

IPPAPI(IppStatus, ippsSumRow_16s32f_D2L,(const Ipp16s** mSrc, int width,
       Ipp32f* pDst, int height))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsSubRow_*
//  Purpose:           Subtracts a vector from all matrix rows.
//  Parameters:
//    pSrc             Pointer to the input vector [width].
//    pSrcDst          Pointer to the the source and destination vector
//                     [height*dstStep].
//    mSrcDst          Pointer to the source and destination matrix
//                     [height][width].
//    width            The number of columns in the matrix mSrcDst.
//    dstStep          The row step in the vector pSrcDst.
//    height           The number of rows in the matrix mSrcDst.
//
//  Returns:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrc, pSrcDst, or mSrcDst
//                     pointer is null.
//    ippStsSizeErr    Indicates an error when height or width is less than or
//                     equal to 0.
//    ippStsStrideErr  Indicates an error when width > dstStep.
//
*/
IPPAPI(IppStatus, ippsSubRow_32f_D2, (const Ipp32f* pSrc, int width,
       Ipp32f* pSrcDst, int dstStep, int height))

IPPAPI(IppStatus, ippsSubRow_32f_D2L, (const Ipp32f* pSrc, Ipp32f** mSrcDst,
       int width, int height))

IPPAPI(IppStatus, ippsSubRow_16s_D2,(const Ipp16s* pSrc, int width,
       Ipp16s* pSrcDst, int dstStep, int height))

IPPAPI(IppStatus, ippsSubRow_16s_D2L,(const Ipp16s* pSrc, Ipp16s** mSrcDst,
       int width, int height))

/*///////////////////////////////////////////////////////////////////////////////
//  Name:              ippsCopyColumn_Indirect_*
//  Purpose:           Copies the input matrix with columns redirection.
//  Parameters:
//    pSrc             Pointer to the input vector [height*srcStep].
//    mSrc             Pointer to the input matrix [height][srcLen].
//    srcLen           The number of columns in the input matrix mSrc.
//    srcStep          The row step in pSrc
//    pDst             Pointer to the output vector [height*dstStep]
//    mDst             Pointer to the output matrix [height][dstLen]
//    pIndx            Pointer to the redirection vector [dstLen]
//    dstLen           The number of columns in the output matrix mDst
//    dstStep          The row step in pDst
//    height           The number of rows in both the input and output matrices.
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrc, mSrc, pDst, mDst or
//                     pIndx pointer is null.
//    ippStsSizeErr    Indicates an error when height, srcLen, or dstLen is less
//                     than or equal to 0,
//                     pIndx[j]>=srcLen or pIndx[j]<0 for j=0,:,dstlen-1
//    ippStsStrideErr  Indicates an error when srcLen > srcStep, dstLen > dstStep.
//
*/
IPPAPI(IppStatus, ippsCopyColumn_Indirect_32f_D2, (const Ipp32f* pSrc,
       int srcLen, int srcStep, Ipp32f* pDst, const Ipp32s* pIndx, int dstLen,
       int dstStep, int height))

IPPAPI(IppStatus, ippsCopyColumn_Indirect_16s_D2, (const Ipp16s* pSrc,
       int srcLen, int srcStep, Ipp16s* pDst, const Ipp32s* pIndx, int dstLen,
       int dstStep, int height))

IPPAPI(IppStatus, ippsCopyColumn_Indirect_32f_D2L, (const Ipp32f** mSrc,
       int srcLen, Ipp32f** mDst, const Ipp32s* pIndx, int dstLen, int height))

IPPAPI(IppStatus, ippsCopyColumn_Indirect_16s_D2L, (const Ipp16s** mSrc,
       int srcLen, Ipp16s** mDst, const Ipp32s* pIndx, int dstLen, int height))

/*///////////////////////////////////////////////////////////////////////////////
//  Name:              ippsBlockDMatrixInitAlloc_*
//  Purpose:           Initializes the structure that represents a symmetric
//                     block diagonal matrix.
//  Parameters:
//    pMatrix          Pointer to the block diagonal matrix to be created.
//    mSrc             Pointer to the vector of pointers to matrix rows.
//    bSize               Pointer to vector of block sizes [nBlocks].
//    nBlocks          Number of blocks.
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pMatrix or mSrc pointer is null.
//    ippStsSizeErr    Indicates an error when bSize or nBlocks is less than or
//                     equal to 0
//    ippStsMemAllocErr Indicates an error when no memory allocated.
//
*/
IPPAPI(IppStatus, ippsBlockDMatrixInitAlloc_64f,(IppsBlockDMatrix_64f** pMatrix,
       const Ipp64f** mSrc, const int* bSize, int nBlocks))

IPPAPI(IppStatus, ippsBlockDMatrixInitAlloc_16s,(IppsBlockDMatrix_16s** pMatrix,
       const Ipp16s** mSrc, const int* bSize, int nBlocks))

IPPAPI(IppStatus, ippsBlockDMatrixInitAlloc_32f,(IppsBlockDMatrix_32f** pMatrix,
       const Ipp32f** mSrc, const int* bSize, int nBlocks))

/*///////////////////////////////////////////////////////////////////////////////
//  Name:              ippsBlockDMatrixFree_*
//  Purpose:           Deallocates the block diagonal matrix structure.
//
//  Parameters:
//    pMatrix          Pointer to the block diagonal matrix.
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the mSrc.
//
*/
IPPAPI(IppStatus, ippsBlockDMatrixFree_32f,(IppsBlockDMatrix_32f* pMatrix))

IPPAPI(IppStatus, ippsBlockDMatrixFree_64f,(IppsBlockDMatrix_64f* pMatrix))

IPPAPI(IppStatus, ippsBlockDMatrixFree_16s,(IppsBlockDMatrix_16s* pMatrix))


/* /////////////////////////////////////////////////////////////////////////////
//  Feature Processing
///////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsZeroMean_16s
//  Purpose:           Subtracts the mean value from all elements of
//                     the input vector.
//
//  Parameters:
//    pSrcDst          Pointer to the source and destination vector [len].
//    len              The number of elements in the vector.
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrcDst pointer is null.
//    ippStsSizeErr    Indicates an error when len is less than or equal to 0.
//
*/

IPPAPI(IppStatus, ippsZeroMean_16s, (Ipp16s *pSrcDst, int len))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsCompensateOffset_*
//  Purpose:           Removes the DC offset of the input signals.
//
//  Parameters:
//    pSrc             Pointer to the source vector[len].
//    pDst             Pointer to the destination vector[len].
//    pSrcDst          Pointer to the source and destination vector for in-place
//                     operations [len].
//    pSrcDst0         Pointer to the previous source element.
//    pSrc0            Pointer to previous source element. The last source
//                     element is saved there.
//    dst0             Previous destination element.
//    val              Constant of offset compensation formula.
//    len              The number of elements in the vector.
//    scaleFactor
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrc or pSrcDst or pDst or
//                     pSrc0 pointer is null.
//    ippStsSizeErr    Indicates an error when len is less than or equal to 0
//
*/

IPPAPI(IppStatus, ippsCompensateOffset_32f, (const Ipp32f* pSrc, Ipp32f* pDst,
       int len, Ipp32f* pSrc0, Ipp32f dst0, Ipp32f val))

IPPAPI(IppStatus, ippsCompensateOffset_16s, (const Ipp16s* pSrc, Ipp16s* pDst,
       int len, Ipp16s* pSrcDst0, Ipp16s dst0, Ipp32f val))

IPPAPI(IppStatus, ippsCompensateOffset_32f_I, (Ipp32f* pSrcDst, int len,
       Ipp32f* pSrc0, Ipp32f dst0, Ipp32f val))

IPPAPI(IppStatus, ippsCompensateOffset_16s_I, (Ipp16s* pSrcDst, int len,
       Ipp16s* pSrcDst0, Ipp16s dst0, Ipp32f val))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsSignChangeRate_*
//  Purpose:           Counts the zero-cross rate for the input signal.
//
//  Parameters:
//    pSrc             Pointer to the input signal [len].
//    len              Number of elements in the input signal.
//    pRes             Pointer to the result variable.
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrc or pRes pointer is null.
//    ippStsSizeErr    Indicates an error when len is less than or equal to 0.
//
*/
IPPAPI(IppStatus, ippsSignChangeRate_16s,(const Ipp16s* pSrc, int len,
       Ipp32s* pRes))

IPPAPI(IppStatus, ippsSignChangeRate_32f,(const Ipp32f* pSrc, int len,
       Ipp32f* pRes))

IPPAPI(IppStatus, ippsSignChangeRate_Count0_16s,(const Ipp16s* pSrc, int len,
       Ipp32s* pRes))

IPPAPI(IppStatus, ippsSignChangeRate_Count0_32f,(const Ipp32f* pSrc, int len,
       Ipp32f* pRes))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsLinearPrediction_*
//  Purpose:           Performs linear prediction analysis on the input vector.
//
//  Parameters:
//    pSrc             Pointer to the input vector [lenSrc]
//    lenSrc           Length of the input vector pSrc.
//    pDst             Pointer to the output LPC coefficients vector [lenDst].
//    lenDst           Length of the output vector pDst.
//    scaleFactor
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrc or  pDst pointer is null.
//    ippStsSizeErr    Indicates an error when lenSrc or  lenDst is less than or
//                     equal to 0, lenDst is greater or equal than lenSrc.
//    ippStsNoOperation Indicates no solution to the LPC problem.
//
*/
IPPAPI(IppStatus, ippsLinearPrediction_Cov_32f,(const Ipp32f *pSrc, int lenSrc,
       Ipp32f *pDst, int lenDst))

IPPAPI(IppStatus, ippsLinearPrediction_Cov_16s_Sfs,(const Ipp16s* pSrc, int lenSrc,
       Ipp16s* pDst, int lenDst, int scaleFactor))

IPPAPI(IppStatus, ippsLinearPrediction_Auto_32f,(const Ipp32f *pSrc, int lenSrc,
       Ipp32f *pDst, int lenDst))

IPPAPI(IppStatus, ippsLinearPrediction_Auto_16s_Sfs,(const Ipp16s* pSrc, int lenSrc,
       Ipp16s* pDst, int lenDst, int scaleFactor))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsLinearPredictionNeg_Auto_*
//  Purpose:           Performs linear prediction analysis on the input vector.
//			The same formula as ippsLinearPrediction_Auto with -r[k] in the right part
//
//  Parameters:
//    pSrc             Pointer to the input vector [lenSrc]
//    lenSrc           Length of the input vector pSrc.
//    pDst             Pointer to the output LPC coefficients vector [lenDst].
//    lenDst           Length of the output vector pDst.
//    scaleFactor
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrc or  pDst pointer is null.
//    ippStsSizeErr    Indicates an error when lenSrc or  lenDst is less than or
//                     equal to 0, lenDst is greater or equal than lenSrc.
//    ippStsNoOperation Indicates no solution to the LPC problem.
//
*/
IPPAPI(IppStatus, ippsLinearPredictionNeg_Auto_32f,(const float *pSrc,int lenSrc,float *pDst,
													int lenDst))
IPPAPI(IppStatus, ippsLinearPredictionNeg_Auto_16s_Sfs, (const Ipp16s* pSrc, int lenSrc,
	   Ipp16s* pDst, int lenDst, int scaleFactor))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsDurbin_*
//  Purpose:           Performs Durbin's recursion on an input vector
//                     of autocorrelations.
//  Parameters:
//    pSrc             Pointer to the input vector [ len+1].
//    pDst             Pointer to the output LPC coefficients vector [len].
//    len              Length of the input and output vectors.
//    pErr             Pointer to the residual prediction error.
//    scaleFactor
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrc or  pDst or pErr
//                     pointer is null.
//   ippStsSizeErr     Indicates an error when lenis less than or equal to 0
//   ippStsMemAllocErr memory alllocation error
//   ippStsNoOperation ndicates no solution to the LPC problem.
//
*/
IPPAPI(IppStatus, ippsDurbin_32f,(const Ipp32f *pSrc, Ipp32f *pDst, int lenDst,
       Ipp32f* pErr))

IPPAPI(IppStatus, ippsDurbin_16s_Sfs,(const Ipp16s* pSrc, Ipp16s* pDst,
       int lenDst,Ipp32f* pErr, int scaleFactor))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsLPToCepstrum_*
//  Purpose:           Calculates cepstrum coefficients from linear
//                     prediction coefficients.
//  Parameters:
//    pSrc             Pointer to the linear prediction coefficients [len].
//    pDst             Pointer to the cepstrum coefficients [len].
//    len              Number of elements in the source and destination vectors.
//    scaleFactor
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrc or pDst pointer is null.
//    ippStsSizeErr    Indicates an error when len is less than or equal to 0
//
*/
IPPAPI(IppStatus, ippsLPToCepstrum_32f,(const Ipp32f* pSrc, Ipp32f* pDst,
       int len))

IPPAPI(IppStatus, ippsLPToCepstrum_16s_Sfs,(const Ipp16s* pSrc, Ipp16s* pDst,
       int len, int scaleFactor))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsCepstrumToLP_*
//  Purpose:           Calculates linear prediction coefficients from
//                     cepstrum coefficients.
//  Parameters:
//    pSrc             Pointer to the cepstrum coefficients [len].
//    pDst             Pointer to the linear prediction coefficients [len].
//    len              Number of elements in the source and destination vectors.
//    scaleFactor
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrc or pDst pointer is null.
//    ippStsSizeErr    Indicates an error when len is less than or equal to 0.
//
*/
IPPAPI(IppStatus, ippsCepstrumToLP_32f,(const Ipp32f* pSrc, Ipp32f* pDst,
       int len))

IPPAPI(IppStatus, ippsCepstrumToLP_16s_Sfs,(const Ipp16s* pSrc, Ipp16s* pDst,
       int len, int scaleFactor))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsLPToReflection_*
//  Purpose:           Calculates the linear prediction reflection
//                     coefficients from the linear prediction coefficients.
//  Parameters:
//    pSrc             Pointer to the linear prediction coefficients [len].
//    pDst             Pointer to the linear prediction reflection coefficients [len].
//    len              Number of elements in the source and destination vectors.
//    scaleFactor
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrc or  pDst pointer is null.
//    ippStsSizeErr    Indicates an error when len is less than or equal to 0.
//    ippStsNoOperation Indicates that reflection coefficients could not be calculated
//
*/
IPPAPI(IppStatus, ippsLPToReflection_32f,(const Ipp32f* pSrc, Ipp32f* pDst,
       int len))

IPPAPI(IppStatus, ippsLPToReflection_16s_Sfs,(const Ipp16s* pSrc, Ipp16s* pDst,
       int len, int scaleFactor))
/********************************************************************************
ippsDTW_L2_32f_D2L
Arguments:
    pSrc1		Pointer to the first input (observation) vector   [height1*step].
    pSrc2		Pointer to the second input (reference) vector   [height2*step].
    mSrc1		Pointer to the first input (observation) matrix   [height1][width].
    mSrc2		Pointer to the second input (reference) matrix   [height2][width].
    height1		Number of rows in the first input matrix N1.
    height2		Number of rows in the first input matrix N2.
    width		Length of the input matrices row M.
    step		Row step in pSrc1 and pSrc2.
    pDist		Pointer to the distance value.
    beam		Beam value, used if positive.
    delta		Endpoint constraint value.
    scaleFactor	Scale factor for input values .

 Discussion:  Computes the distance between observation and reference vector
             sequences using Dynamic Time Warping algorithm.
  Return Value
    ippStsNoErr		Indicates no error.
    ippStsNullPtrErr	Indicates an error when the pSrc1, pSrc2, mSrc1, mSrc2, or pDist pointer is null.
    ippStsSizeErr		Indicates an error when height1, height2, or width is less than or equal to 0 or delta is less than 0 or greater than height2.
    ippStsStrideErr		Indicates an error when step is less than width.
    ippStsLPCCalcErr 	Indicates that there are now admissible paths for height1, height2 and delta values.
*/
IPPAPI(IppStatus, ippsDTW_L2_32f_D2L,(const Ipp32f** mSrc1, int height1,
                                      const Ipp32f** mSrc2, int height2,
                                      int width, Ipp32f* pDist, int delta,
                                      Ipp32f beam))
IPPAPI(IppStatus, ippsDTW_L2_32f_D2,(const Ipp32f* mSrc1, int height1,
                                      const Ipp32f* mSrc2, int height2,
                                      int width, int step, Ipp32f* pDist, int delta,
                                      Ipp32f beam))
IPPAPI(IppStatus, ippsDTW_L2_8u32s_D2Sfs,(const Ipp8u* pSrc1, int height1,
                                          const Ipp8u* pSrc2, int height2,
                                          int width, int step, Ipp32s* pDist, int delta,
                                          Ipp32s beam, int scaleFactor))
IPPAPI(IppStatus, ippsDTW_L2_8u32s_D2LSfs,(const Ipp8u** mSrc1, int height1,
                                           const Ipp8u** mSrc2, int height2,
                                           int width, Ipp32s* pDist, int delta,
                                           Ipp32s beam, int scaleFactor))
IPPAPI(IppStatus, ippsDTW_L2Low_16s32s_D2Sfs,(const Ipp16s* pSrc1, int height1,
                                              const Ipp16s* pSrc2, int height2,
                                              int width, int step, Ipp32s* pDist, int delta,
                                              Ipp32s beam, int scaleFactor))
IPPAPI(IppStatus, ippsDTW_L2Low_16s32s_D2LSfs,(const Ipp16s** mSrc1, int height1,
                                               const Ipp16s** mSrc2, int height2,
                                               int width, Ipp32s* pDist, int delta,
                                               Ipp32s beam, int scaleFactor))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsSchur_*
//  Purpose:           Schur's recursion for an input vector of
//                     autocorrelations.
//
//  Parameters:
//    pSrc		Pointer to the input autocorrelations vector [len+1].
//    pDst		Pointer to the output reflection coefficients vector [len].
//    len			Length of the output vectors.
//    pErr		Pointer to the resulting prediction error.
//    scaleFactor
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrc or pDst or pErr pointer
//                     is null.
//    ippStsSizeErr    Indicates an error when lenSrc or  lenDst is less than or
//                     equal to 0 or pSrc <  pDst.
//    ippStsMemAllocErr memory alllocation error
//    ippStsDivByZeroErr Indicates no solution to the LPC problem
*/
IPPAPI(IppStatus, ippsSchur_32f,(const Ipp32f* pSrc, Ipp32f* pDst, int len, Ipp32f* pErr))
IPPAPI(IppStatus, ippsSchur_16s_Sfs,(const Ipp16s* pSrc, Ipp16s* pDst, int len,
											Ipp32f* pErr,int scaleFactor))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsReflectionToLP_*
//  Purpose:           Calculates the linear prediction coefficients from
//                     the linear prediction reflection coefficients.
//  Parameters:
//    pSrc             Pointer to the linear prediction reflection coefficients [len].
//    pDst             Pointer to the linear prediction coefficients [len].
//    len              Number of elements in the source and destination vectors.
//    scaleFactor
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrc or  pDst pointer is null.
//    ippStsSizeErr    Indicates an error when len is less than or equal to 0
//
*/
IPPAPI(IppStatus, ippsReflectionToLP_32f,(const Ipp32f* pSrc, Ipp32f* pDst,
       int len))
IPPAPI(IppStatus, ippsReflectionToLP_16s_Sfs,(const Ipp16s* pSrc, Ipp16s* pDst,
       int len, int scaleFactor))

/*/////////////////////////////////////////////////////////////////////////////
//  Name:         ippsReflectionToAR_*
//                ippsReflectionToLAR_*
//                ippsReflectionToTrueAR_*
//  Purpose:      Converts reflection coefficients to area ratios.
//
//  Parameters:
//    pSrc		   Pointer to the input vector [len].
//    pDst		   Pointer to the destination vector [len].
//    val			Threshold value ( 0 < val < 1 ).
//    len			Length of the input and output vectors.
//
//  Returns:
//    ippStsNoErr       Indicates no error.
//    ippStsNullPtrErr  Indicates an error when the pSrc or pDst
//                      pointer is null.
//    ippStsSizeErr     Indicates an error when len is less than or equal to 0.
//    ippStsDivByZero   Indicates a warning for zero-valued divisor vector
//                      element. Operation execution is not aborted. The value of
//                      the destination vector element in the floating-point
//                      operations +Inf. The value of the destination vector
//                      element in the integer operations IPP_MAX_16S.
//    ippStsNoOperation	Indicates an error when 0<val<1 is not true.
//  Notes:
//
*/
IPPAPI(IppStatus, ippsReflectionToAR_16s_Sfs, (const Ipp16s* pSrc,
       int srcShiftVal, Ipp16s* pDst, int len, int scaleFactor))

IPPAPI(IppStatus, ippsReflectionToAR_32f, (const Ipp32f* pSrc, Ipp32f* pDst,
       int len))

IPPAPI(IppStatus, ippsReflectionToLAR_16s_Sfs, (const Ipp16s* pSrc,
       int srcShiftVal, Ipp16s* pDst, int len, Ipp32f val, int scaleFactor))

IPPAPI(IppStatus, ippsReflectionToLAR_32f, (const Ipp32f* pSrc,
       Ipp32f* pDst, int len, Ipp32f val))

IPPAPI(IppStatus, ippsReflectionToTrueAR_16s_Sfs, (const Ipp16s* pSrc,
       int srcShiftVal, Ipp16s* pDst, int len, int scaleFactor))

IPPAPI(IppStatus, ippsReflectionToTrueAR_32f, (const Ipp32f* pSrc,
       Ipp32f* pDst, int len))

/*/////////////////////////////////////////////////////////////////////////////
//  Name:              ippsPitchmarkToF0Cand_*
//  Purpose:           Calculates rise and fall amplitude and duration for tilt.
//
//  Parameters:
//    pSrc		Pointer to the input vector [len].
//    pDst		Pointer to the destination vector [len].
//    len		Length of the input and output vectors.
//
//  Returns:
//    ippStsNoErr       Indicates no error.
//    ippStsNullPtrErr  Indicates an error when the pSrc or pDst
//                      pointer is null.
//    ippStsSizeErr     Indicates an error when len is less than or equal to 0.
//    ippStsDivByZero   Indicates a warning for zero-valued divisor vector
//                      element. Operation execution is not aborted. The value of
//                      the destination vector element in the floating-point
//                      operations +Inf. The value of the destination vector
//                      element in the integer operations IPP_MAX_16S.
//  Notes:
*/
IPPAPI(IppStatus, ippsPitchmarkToF0Cand_32f, (const Ipp32f* pSrc,
       Ipp32f* pDst, int len))

IPPAPI(IppStatus, ippsPitchmarkToF0Cand_16s_Sfs, (const Ipp16s* pSrc,
       Ipp16s* pDst, int len, int scaleFactor))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:         ippsUnitCurve_*_*
//
//  Purpose:      Calculates tilt for rise and fall coefficients.
///
//  Parameters:
//    pSrc        Pointer to the input array [len].
//    pSrcDst     Pointer to the input and destination vector [len].
//    pDst        Pointer to the output array [len].
//    len         Number of elements in the input vector.
//    srcShiftVal Input scale factor.
//    scaleFactor
//
//  Return:
//    ippStsNoErr       Indicates no error.
//    ippStsNullPtrErr  Indicates an error when the pSrc, pSrcDst or pDst
//                      pointer is null.
//    ippStsSizeErr     Indicates an error when len is less than or equal to 0.
//
*/
IPPAPI(IppStatus, ippsUnitCurve_16s_Sfs, (const Ipp16s* pSrc, int srcShiftVal,
       Ipp16s* pDst, int len, int scaleFactor))

IPPAPI(IppStatus, ippsUnitCurve_32f, (const Ipp32f* pSrc,
       Ipp32f* pDst, int len))

IPPAPI(IppStatus, ippsUnitCurve_16s_ISfs, (Ipp16s* pSrcDst, int srcShiftVal,
       int len, int scaleFactor))

IPPAPI(IppStatus, ippsUnitCurve_32f_I, (Ipp32f* pSrcDst, int len))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsLPToLSP_32f
//  Purpose:           computes linear spectral pairs from LPC (in the cosine domain).
//
//  Parameters:
//  pSrcLPC            Pointer to the input LPC coefficients vector [len].
//  pDstLSP            Pointer to the output LSP coefficients vector [len].
//  len                Number of LPC coefficients.
//  nRoots             Number of found LSP values.
//  nInt               Number of intervals while roots finding.
//  nDiv               Number of interval divisions while roots finding.
//  inScale            Scale factor for pSrcLPC values.
//  scaleFactor        Scale factor for pDstLSP values .
//  srcShiftVal	Scale factor for pSrcLP values .
//
//    Return:
// ippStsNoErr         Indicates no error.
// ippStsNullPtrErr    Indicates an error when the pSrc or  pDst pointer is null.
// ippStsSizeErr       Indicates an error when lenSrc or  len is less than or equal to 0
//                     or pSrc <  pDst.
// ippStsMemAllocErr   memory alllocation error
// ippStsNoRootFoundErr   if no decision exists2
*/
IPPAPI(IppStatus, ippsLPToLSP_32f,(const Ipp32f* pSrcLPC, Ipp32f* pDstLSP, int len,
		int* nRoots,int nInt, int nDiv))
IPPAPI(IppStatus, ippsLPToLSP_16s_Sfs,(const Ipp16s* pSrcLP, int srcShiftVal, Ipp16s* pDstLSP,
	   int len,int* nRoots,int nInt, int nDiv, int scaleFactor))
/* for compatibility */
IPPAPI(IppStatus, ippsLPToLSP_32f_D2,(const Ipp32f* pSrcLPC, Ipp32f* pDstLSP, int len,
		int* nRoots,int nInt, int nDiv))
IPPAPI(IppStatus, ippsLPToLSP_16s_D2Sfs,(const Ipp16s* pSrcLP, int srcShiftVal, Ipp16s* pDstLSP,
	   int len,int* nRoots,int nInt, int nDiv, int scaleFactor))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsLSPToLP_32f
//  Purpose:           computes linear sprediction coefficients from LSP (in the cosine domain).
//
//Arguments:
//    pDstLPC		Pointer to the output LPC coefficients vector [len].
//    pSrcLSP		Pointer to the input LSP coefficients vector [len].
//    len			Number of LPC coefficients.
//    inScale		Scale factor for pSrcLPC values.
//    scaleFactor	Scale factor for pDstLSP values .
//
// Discussion:  computes linear spectral pairs from LPC (in the cosine domain).
//  Return Value
//   ippStsNoErr      Indicates no error.
//   ippStsNullPtrErr Indicates an error when the pSrc or  pDst pointer is null.
//   ippStsSizeErr    Indicates an error when lenSrc or  len is less than or equal to 0
//                    or pSrc <  pDst.
//   ippStsMemAllocErr memory alllocation error
*/
IPPAPI(IppStatus, ippsLSPToLP_32f,(const Ipp32f* pSrcLSP, Ipp32f* pDstLPC, int len))
IPPAPI(IppStatus, ippsLSPToLP_16s_Sfs,(const Ipp16s* pSrcLSP, int srcShiftVal, Ipp16s* pDstLP,
		 int len, int scaleFactor))
/* for compatibility */
IPPAPI(IppStatus, ippsLSPToLP_32f_D2,(const Ipp32f* pSrcLSP, Ipp32f* pDstLPC, int len))
IPPAPI(IppStatus, ippsLSPToLP_16s_D2Sfs,(const Ipp16s* pSrcLSP, int srcShiftVal, Ipp16s* pDstLP,
		 int len, int scaleFactor))
/********************************************************************************
	ippsLPToSpectrum_32f
	Arguments:
	pSrc		Pointer to the input LPC coefficients vector [len].
	pDst		Pointer to the output LP spectrum coefficients vector [2order-1].
	len			Number of LPC coefficients.
	order		FFT order for spectrum calculation.
	val			The value of add to spectrum.
    scaleFactor	Scale factor for pDst values .

 Discussion:
	The function ippsLPSpectrum compute the first half of a linear prediction magnitude spectrum
 Return Value
	ippStsNoErr		Indicates no error.
	ippStsNullPtrErr	Indicates an error when the pSrc or pDst pointer is null.
	ippStsSizeErr		Indicates an error when len is less than or equal to 0.
	ippStsFftOrderErr	Indicates an error when the order value is incorrect.
	ippStsDivByZero		Indicates a warning for zero-valued divisor vector element. Operation
	  execution is not aborted. The value of the destination vector element in the floating-point
	  operations is equal to +Inf : and in the integer operations is equal to IPP_MAX_16S.
*/

IPPAPI(IppStatus, ippsLPToSpectrum_32f,(const Ipp32f *LPCoeffs,int nLP,Ipp32f *pDst,
										int lenFFT,Ipp32f val))
IPPAPI(IppStatus, ippsLPToSpectrum_16s_Sfs,(const Ipp16s* pSrc, int len, Ipp16s* pDst, int order,
											Ipp32s val, int scaleFactor))
/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsMelToLinear_32f
//  Purpose:           Converts Mel-scaled values to linear scale values.
//
//  Parameters:
//    pSrc             Pointer to the input vector [len]
//    pDst             Pointer to the output vector [len]
//    len              The length of input and output vectors
//    melMul           Multiply factor in the mel-scale equation
//    melDiv           Divide factor in the mel-scale equation
//
//    Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrc or pDst pointer is null.
//    ippStsSizeErr    Indicates an error when len is less than or equal to 0,
//                        of melMul or melDiv is equal to 0.
//
*/

IPPAPI(IppStatus, ippsMelToLinear_32f,(const Ipp32f* pSrc, Ipp32f* pDst, int len,
       Ipp32f melMul, Ipp32f melDiv))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsLinearToMel_32f
//  Purpose:           Converts linear-scale values to Mel-scale values.
//
//  Parameters:
//    pSrc             Pointer to the input vector [len]
//    pDst             Pointer to the output vector [len]
//    len              The length of input and output vectors
//    melMul           Multiply factor in the mel-scale equation
//    melDiv           Divide factor in the mel-scale equation
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrc or pDst pointer is null.
//    ippStsSizeErr    Indicates an error when len is less than or equal to 0,
//                        of melMul or melDiv is equal to 0.
//
*/
IPPAPI(IppStatus, ippsLinearToMel_32f,(const Ipp32f* pSrc, Ipp32f* pDst, int len,
       Ipp32f melMul, Ipp32f melDiv))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsCopyWithPadding_*
//  Purpose:           Copies the input signal to the output with zero padding
//  Parameters:
//    pSrc             Pointer to the input vector [lenSrc]
//    pDst             Pointer to the output vector [lenDst]
//    lenSrc           The length of pSrc vector.
//    lenDst           The length of pDst vector.
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrc or pDst pointer is null.
//    ippStsSizeErr    Indicates an error when lenSrc or lenDst is less than or
//                     equal to 0 or lenDst is less than lenSrc
*/


IPPAPI(IppStatus, ippsCopyWithPadding_16s,(const Ipp16s* pSrc, int lenSrc,
       Ipp16s* pDst, int lenDst))

IPPAPI(IppStatus, ippsCopyWithPadding_32f,(const Ipp32f* pSrc, int lenSrc,
       Ipp32f* pDst, int lenDst))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsMelFBankInitAlloc_*
//  Purpose:           Initializes the structure for performing the Mel
//                     frequency filter bank analysis.
//  Parameters:
//      pFBank         Pointer to the Mel-scale filter bank structure to be created.
//      pFFTLen        Pointer to the order of FFT used for the filter bank evaluation.
//      winSize        Frame length (samples)
//      sampFreq       Input signal sampling frequency (in Hz)
//      lowFreq        Start frequency of the first band pass filter (in Hz)
//      highFreq       End frequency of the last band pass filter (in Hz)
//      nFilter        Number of Mel-scale filters banks K.
//      melMul         Mel-scale formula multiply factor.
//      melDiv         Mel-scale formula divisor.
//      mode           Flags that determine the execution mode; can have
//                            the following values:
//                            IPP_FBANK_MELWGT    - the function calculates filter bank
//                            weights in Mel-scale;
//                     IPP_FBANK_FREQWGT    - the function calculates filter bank
//                            weights in the frequency space.
//                            One of the above two flags should necessarily be set.
//                     IPP_POWER_SPECTRUM    - indicates that the FFT power
//                            spectrum is used during the filter bank analysis.
       scaleFactor
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when pFBank or pFFTLen pointer is null.
//    ippStsSizeErr    Indicates an error when winSize, nFilter, sampFreq, or
//                     lowFreqis less than or equal to 0.
//       ippStsFBankFreqErr Indicates an error when highFreqis less than lowFreqor
//                     highFreq is greater than sampFreq/2.
//       ippStsFBankFlagErr Indicates an error when the modevalue is incorrect.
//       ippStsMemAllocErr Indicates an error when no memory was allocated.
//
*/

IPPAPI(IppStatus, ippsMelFBankInitAlloc_16s,(IppsFBankState_16s** pFBank,
       int* pFFTLen, int winSize, Ipp32f sampFreq, Ipp32f lowFreq,
       Ipp32f highFreq, int nFilter, Ipp32f melMul, Ipp32f melDiv,
       IppMelMode mode))

IPPAPI(IppStatus, ippsMelFBankInitAlloc_32f,(IppsFBankState_32f** pFBank,
       int* pFFTLen, int winSize, Ipp32f sampFreq, Ipp32f lowFreq,
       Ipp32f highFreq, int nFilter, Ipp32f melMul, Ipp32f melDiv,
       IppMelMode mode))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsMelLinFBankInitAlloc_*
//  Purpose:           Initializes the linear and mel-frequency filter banks
//   Parameters:
//    pFBank           Pointer to the mel scale filter bank structure to be created.
//    FFTLen           Pointer to the length of FFT N used for filter bank evaluation.
//    winSize          Frame length (samples)
//    sampFreq         Input signal sampling frequency   (in Hz)
//    lowFreq          Start frequency  of the first band pass filter (in Hz)
//    highLinFreq      End frequency  of the last band pass filter on linear
//                     scale (in Hz)
//    highFreq         End frequency  of the last band pass filter (in Hz)
//    nFilter          Number of Mel-scale filters   in the filter bank
//    nLinFilter       umber of Linear-scale filters   in the filter bank
//    melMul           Mel scale formula factor
//    melDiv           Mel scale formula divisor
//    mode             One of the following values:
//                     IPP_FBANK_MELWGT - calculate fbank weights in Mel-scale
//                     IPP_FBANK_FREQWGT - calculate fbank weights in
//                     frequency space
//                     IPP_POWER_SPECTRUM - indicates that FFT power logarithm
//                     of input signal is calculated before filter bank
//                     evaluation by ippsEvalFBank function.
//                     Corresponding internal structures are initialized in
//                     the result filter bank structure.
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsSizeErr    Indicates an error when winSize, nFilter, nLinFilter,
//                     freq, lowFreq is less than or equal to 0 or nLinFilter
//                     is greater than nFilter;
//    ippStsFBankFreqErr Indicates an error when (lowFreq > highlinFreq)
//                     or (highlinFreq > highFreq) or (highFreq > sampFreq/2)
//                     or (highLinFreq> lowFreq)&&(nLinFilter==0)
//                     or (highLinFreq< highFreq)&&(nLinFilter==nFilter)
//    ippStsFBankFlagErr Indicates an error when the mode value is incorrect.
//    ippStsMemAllocErr Indicates an error when no memory allocated.
*/

IPPAPI(IppStatus, ippsMelLinFBankInitAlloc_32f,(IppsFBankState_32f** pFBank,
       int* pFFTLen, int winSize, Ipp32f sampFreq, Ipp32f lowFreq,
       Ipp32f highFreq, int nFilter, Ipp32f highLinFreq, int nLinFilter,
       Ipp32f melMul, Ipp32f melDiv, IppMelMode mode))

IPPAPI(IppStatus, ippsMelLinFBankInitAlloc_16s,(IppsFBankState_16s** pFBank,
       int* pFFTLen, int winSize, Ipp32f sampFreq, Ipp32f lowFreq,
       Ipp32f highFreq, int nFilter, Ipp32f highLinFreq, int nLinFilter,
       Ipp32f melMul, Ipp32f melDiv, IppMelMode mode))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsEmptyFBankInitAlloc_*
//  Purpose:           Initializes an empty filter bank structure.
//  Parameters:
//    pFBank           Pointer to the filter bank structure to be created.
//    pFFTLen          Pointer to the order of FFT used for the
//                     filter bank evaluation.
//    winSize          Frame length (samples)
//    nFilter          Number of filters banks K.
//    mode             Flag determining the function's execution mode; can have
//                     the following value:
//                     IPP_POWER_SPECTRUM - indicates that the logarithm of the
//                     FFT power spectrum is used during the filter
//                     bank analysis.
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when pFBank or pFFTLen pointer is null.
//    ippStsSizeErr    Indicates an error when winSize or nFilter or pFBank
//                     is less than or equal to 0;
//    ippStsMemAllocErr Indicates an error when no memory allocated.
//
*/
IPPAPI(IppStatus, ippsEmptyFBankInitAlloc_32f,(IppsFBankState_32f** pFBank, int* pFFTLen,
       int winSize, int nFilter, IppMelMode mode))

IPPAPI(IppStatus, ippsEmptyFBankInitAlloc_16s,(IppsFBankState_16s** pFBank, int* pFFTLen,
       int winSize, int nFilter, IppMelMode mode))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsFBankFree_*
//  Purpose:           Destroys the structure for the filter bank analysis.
//  Parameters:
//    pFBank           Pointer to the filter bank structure.
//
//  Return:
//    ippStsNoErr       Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pFBank pointer is null.
*/
IPPAPI(IppStatus, ippsFBankFree_16s,(IppsFBankState_16s* pFBank))

IPPAPI(IppStatus, ippsFBankFree_32f,(IppsFBankState_32f* pFBank))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsFBankGetCenters_*
//  Purpose:           Retrieves the center frequencies of the
//                     triangular filter banks.
//  Parameters:
//    pFBank           Pointer to the filter bank structure.
//    pCenters         Pointer to the output vector that contains the center
//                     frequencies.
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pFBank or pCenters pointer is null.
//    ippStsFBankErr   Indicates an error when filter centers are not valid after filter
//                     bank initialization by ippsEmptyFBankInitAlloc function.
//
*/

IPPAPI(IppStatus, ippsFBankGetCenters_32f,(const IppsFBankState_32f* pFBank, int* pCenters))

IPPAPI(IppStatus, ippsFBankGetCenters_16s,(const IppsFBankState_16s* pFBank, int* pCenters))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsFBankSetCenters_*
//  Purpose:           Sets the center frequencies of the
//                     triangular filter banks.
//  Parameters:
//    pFBank           Pointer to the filter bank structure
//    pCenters         Pointer to the vector that contains center frequencies.
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pFBank or pCenters pointer is null.
//
*/

IPPAPI(IppStatus, ippsFBankSetCenters_16s,(IppsFBankState_16s* pFBank,
       const int* pCenters))

IPPAPI(IppStatus, ippsFBankSetCenters_32f,(IppsFBankState_32f* pFBank,
       const int* pCenters))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsFBankGetCoeffs_*
//  Purpose:           Retrieves the filter bank weight coefficients.
//  Parameters:
//    pFBank           Pointer to the filter bank structure
//    fIdx             Filter index.
//    pCoeffs          Pointer to the filter coefficients vector.
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pFBank or pCoeffs pointer is null.
//    ippStsSizeErr    Indicates an error when fIdx is less then 1 or greater
//                     then nFilter.
//    ippStsFBankErr   Indicates an error when fIdx filter coeffitients are not
//                     valid after filter centers reset or filter centers are not
//                     valid after filter bank initialization by
//                     ippsEmptyFBankInitAlloc function.
//
*/

IPPAPI(IppStatus, ippsFBankGetCoeffs_16s,(const IppsFBankState_16s* pFBank,
       int fIdx, Ipp32f* pCoeffs))

IPPAPI(IppStatus, ippsFBankGetCoeffs_32f,(const IppsFBankState_32f* pFBank,
       int fIdx, Ipp32f* pCoeffs))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsFBankSetCoeffs_*
//  Purpose:           Sets the filter bank weight coefficients.
//  Parameters:
//    pFBank           Pointer to the filter bank structure
//    fIdx             Filter index.
//    pCoeffs          Pointer to the output coefficients vector.
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pFBank or pCoeffs pointer is null.
//    ippStsSizeErr    Indicates an error when fIdx is less then 1 or greater
//                     then nFilter.
//    ippStsFBankErr   Indicates an error when the weight coefficients are not
//                     available or valid.
//
*/
IPPAPI(IppStatus, ippsFBankSetCoeffs_16s,(IppsFBankState_16s* pFBank, int fIdx,
       const Ipp32f* pCoeffs))

IPPAPI(IppStatus, ippsFBankSetCoeffs_32f,(IppsFBankState_32f* pFBank, int fIdx,
       const Ipp32f* pCoeffs))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsEvalFBank_*
//  Purpose:           Performs the filter bank analysis
//  Parameters:
//    pSrc             Pointer to the source vector
//    pDst             Pointer to the filter bank coefficients vector [nFilter].
//    pFBank           Pointer to the filter bank structure.
//    scaleFactor
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrc, pDst pointer is null.
//    ippStsFBankErr   Indicates an error when pFBank structure is not ready for
//                     calculation.
//
*/

IPPAPI(IppStatus, ippsEvalFBank_16s_Sfs,(const Ipp16s* pSrc, Ipp16s* pDst,
       const IppsFBankState_16s* pFBank, int scaleFactor))

IPPAPI(IppStatus, ippsEvalFBank_16s32s_Sfs,(const Ipp16s* pSrc, Ipp32s* pDst,
       const IppsFBankState_16s* pFBank, int scaleFactor))

IPPAPI(IppStatus, ippsEvalFBank_32f,(const Ipp32f* pSrc, Ipp32f* pDst,
       const IppsFBankState_32f* pFBank))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsDCTLifterInitAlloc_MulC0_*
//  Purpose:           Initializes the structure to perform DCT
//                     and lift the DCT coefficients.
//  Parameters:
//    pDCTLifter       Pointer to the created structure for DCT calculation and
//                     liftering.
//    lenDCT           Length of DCT will be used for MFCC calculation
//    lenCeps          Number (without c0) of cepstral coefficients to be calculated.
//    nLifter          Liftering factor
//    pLifter          Pointer to liftering coefficients vector
//    val              Value to multiply output MFCC except c0 coefficient
//    val0             Value to multiply output c0 coefficient
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pLifter pointer is null.
//    ippStsSizeErr    Indicates an error when lenDCT, lenCeps or nLifter is
//                     less than or equal to 0 or lenDCT is less than lenCeps.
//    ippStsMemAllocErr    Indicates an error when no memory allocated.
//
*/

IPPAPI(IppStatus, ippsDCTLifterInitAlloc_32f,(IppsDCTLifterState_32f** pDCTLifter,
       int lenDCT, int lenCeps, int nLifter, Ipp32f val))

IPPAPI(IppStatus, ippsDCTLifterInitAlloc_C0_32f,(IppsDCTLifterState_32f** pDCTLifter,
       int lenDCT, int lenCeps, int nLifter, Ipp32f val, Ipp32f val0))

IPPAPI(IppStatus, ippsDCTLifterInitAlloc_Mul_32f,(IppsDCTLifterState_32f** pDCTLifter,
       int lenDCT, const Ipp32f* pLifter, int lenCeps))

IPPAPI(IppStatus, ippsDCTLifterInitAlloc_MulC0_32f,(IppsDCTLifterState_32f** pDCTLifter,
       int lenDCT, const Ipp32f* pLifter, int lenCeps))

IPPAPI(IppStatus, ippsDCTLifterInitAlloc_16s,(IppsDCTLifterState_16s** pDCTLifter,
       int lenDCT, int lenCeps, int nLifter, Ipp32f val))

IPPAPI(IppStatus, ippsDCTLifterInitAlloc_C0_16s,(IppsDCTLifterState_16s** pDCTLifter,
       int lenDCT, int lenCeps, int nLifter, Ipp32f val, Ipp32f val0))

IPPAPI(IppStatus, ippsDCTLifterInitAlloc_Mul_16s,(IppsDCTLifterState_16s** pDCTLifter,
       int lenDCT, const Ipp32f* pLifter, int lenCeps))

IPPAPI(IppStatus, ippsDCTLifterInitAlloc_MulC0_16s,(IppsDCTLifterState_16s** pDCTLifter,
       int lenDCT, const Ipp32f* pLifter, int lenCeps))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsDCTLifterFree_*
//  Purpose:           Destroys the structure for DCT and liftering
//  Parameters:
//    pDCTLifter       Pointer to the filter bank structure
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pDCTLifter pointer is null.
//
*/

IPPAPI(IppStatus, ippsDCTLifterFree_32f,(IppsDCTLifterState_32f* pDCTLifter))

IPPAPI(IppStatus, ippsDCTLifterFree_16s,(IppsDCTLifterState_16s* pDCTLifter))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsDCTLifter_*
//  Purpose:           Performs DCT and lifts the DCT coefficients.
//  Parameters:
//    pSrc             Pointer to the filter output vector [lenDCT]
//    pDst             Pointer to the MFCC feature vector.
//    pDCTLifter       Pointer to the filter bank structure
//    scaleFactor
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicate an error when the pSrc, pDst, pFBank pointer is null.
//
*/

IPPAPI(IppStatus, ippsDCTLifter_32f,(const Ipp32f* pSrc, Ipp32f* pDst,
       const IppsDCTLifterState_32f* pDCTLifter))

IPPAPI(IppStatus, ippsDCTLifter_16s_Sfs,(const Ipp16s* pSrc, Ipp16s* pDst,
       const IppsDCTLifterState_16s* pDCTLifter, int scaleFactor))

IPPAPI(IppStatus, ippsDCTLifter_32s16s_Sfs, (const Ipp32s* pSrc, Ipp16s* pDst,
       const IppsDCTLifterState_16s* pDCTLifter, int scaleFactor))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsNormEnergy_*
//  Purpose:           Normalizes a vector of energy values.
//  Parameters:
//    pSrcDst          Pointer to the input/output vector [height*step].
//    step             Sample step in the vector pSrcDst.
//    height           Number of samples for normalization
//    silFloor         Silence floor in log10 value
//    val              Coefficient value.
//    maxE             Maximum energy value
//    enScale          Energy scale
//  Returns:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrcDst pointer is null.
//    ippStsSizeErr    Indicates an error when step or height is less than
//                     or equal to 0
//
*/

IPPAPI(IppStatus, ippsNormEnergy_32f,(Ipp32f* pSrcDst, int step, int height,
       Ipp32f silFloor, Ipp32f enScale))

IPPAPI(IppStatus, ippsNormEnergy_16s,(Ipp16s* pSrcDst, int step, int height,
       Ipp16s silFloor, Ipp16s val, Ipp32f enScale))

IPPAPI(IppStatus, ippsNormEnergy_RT_32f,(Ipp32f* pSrcDst, int step, int height,
       Ipp32f silFloor, Ipp32f maxE, Ipp32f enScale))

IPPAPI(IppStatus, ippsNormEnergy_RT_16s,(Ipp16s* pSrcDst, int step, int height,
       Ipp16s silFloor, Ipp16s maxE, Ipp16s val, Ipp32f enScale))

/*/////////////////////////////////////////////////////////////////////////////
//  Name:              ippsSumMeanVar_*
//  Purpose:           The function sums the vector elements and their
//                     squares according.
//
//  Parameters:
//    pSrc             Pointer to the source vector [height* srcStep].
//    pDstMean         Pointer to the result vector that contains sums [width].
//    pdstVar          Pointer to the result vector that contains square sums [width].
//    width            Number of columns in the pSrc.
//    srcStep          Row step in pSrc.
//    height           Number of rows in pSrc.
//    scaleFactor
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrc, pDstMean, pDstVar,
//                     pSrcDstMean or pSrcDstVar pointer is null.
//    ippStsSizeErr    Indicates an error when srcStep, width or height is less
//                     than or equal to 0 or width is greater than srcStep;
//
*/

IPPAPI(IppStatus,ippsSumMeanVar_32f,(const Ipp32f* pSrc, int srcStep, int height,
       Ipp32f* pDstMean, Ipp32f* pDstVar, int width))

IPPAPI(IppStatus,ippsSumMeanVar_16s32f,(const Ipp16s* pSrc, int srcStep,
       int height, Ipp32f* pDstMean, Ipp32f* pDstVar, int width))

IPPAPI(IppStatus,ippsSumMeanVar_16s32s_Sfs,(const Ipp16s* pSrc, int srcStep,
       int height, Ipp32s* pDstMean, Ipp32s* pDstVar, int width, int scaleFactor))

IPPAPI(IppStatus,ippsSumMeanVar_32f_I,(const Ipp32f* pSrc, int srcStep,
       int height, Ipp32f* pSrcDstMean, Ipp32f* pSrcDstVar, int width))

IPPAPI(IppStatus,ippsSumMeanVar_16s32f_I,(const Ipp16s* pSrc, int srcStep,
       int height, Ipp32f* pSrcDstMean, Ipp32f* pSrcDstVar, int width))

IPPAPI(IppStatus,ippsSumMeanVar_16s32s_ISfs,(const Ipp16s* pSrc, int srcStep,
       int height, Ipp32s* pSrcDstMean, Ipp32s* pSrcDstVar, int width,
       int scaleFactor))

/////////////////////////////////////////////////////////////////////////////
//  Name:              ippsNewVar_*
//  Purpose:           The function computes the variance vector.
//
//  Parameters:
//    pSrcMean         Pointer to the source vector of element sums [width].
//    pSrcVar          Pointer to the source vector of element sum squares [width].
//    pSrcDstVar       Pointer to the source and result vector of element sum squares [width].
//    width            Number of columns in the pSrc.
//    val1, val2       Multiplicative constants.
//    scaleFactor
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrcMean, pSrcVar, pDstVar or
//                     pSrcDstVar pointer is null.
//    ippStsSizeErr    Indicates an error when width is less than or equal to 0;
//



IPPAPI(IppStatus, ippsNewVar_32s_Sfs,(const Ipp32s* pSrcMean,
       const Ipp32s* pSrcVar, Ipp32s* pDstVar, int width, Ipp32f val1,
       Ipp32f val2, int scaleFactor))

IPPAPI(IppStatus, ippsNewVar_32s_ISfs,(const Ipp32s* pSrcMean,
       Ipp32s* pSrcDstVar, int width, Ipp32f val1, Ipp32f val2, int scaleFactor))

IPPAPI(IppStatus, ippsNewVar_32f,(const Ipp32f* pSrcMean, const Ipp32f* pSrcVar,
       Ipp32f* pDstVar, int width, Ipp32f val1, Ipp32f val2))

IPPAPI(IppStatus, ippsNewVar_32f_I,(const Ipp32f* pSrcMean, Ipp32f* pSrcDstVar,
       int width, Ipp32f val1, Ipp32f val2))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsRecSqrt_*
//  Purpose:           Computes square root reciprocals of vector
//                     elements in-place.
//  Parameters:
//      pSrcDst        Pointer to the source and destination vector pSrcDst.
//      len            The number of elements in the vector.
//      val            The threshold factor.
//    scaleFactor
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrcDst pointer is null.
//    ippStsInvByZero  Indicates an error when pSrcDst[i]is less than val.
//    ippStsSizeErr    Indicates an error when len is less than or equal to 0.
//    ippStsBadArgErr  Indicates an error when val is less than or equal to 0
//
*/
IPPAPI(IppStatus,ippsRecSqrt_32s_Sfs,(Ipp32s* pSrcDst, int len,Ipp32s val,
       int scaleFactor))

IPPAPI(IppStatus, ippsRecSqrt_32f, (Ipp32f* pSrcDst, int len, Ipp32f val))

// The functions use for compatibility
IPPAPI(IppStatus, ippsRecSqrt_32f_Th, (Ipp32f* pSrcDst, int len, Ipp32f val))

/*//////////////////////////////////////////////////////////////////////
// Name:                ippsAccCovarianceMatrix_*
// Purpose:             Accumulate covariance matrix.
// Parameters:
//    pSrc              Pointer to the input vector [height*srcStep].
//    mSrc              Pointer to the input matrix [height][width].
//    srcStep           Row step in pSrc.
//    pMean             Pointer to the mean vector [width].
//    width             Length of the input matrix row, mean, and variance vectors.
//    pSrcDst           Pointer to the source and result matrix [width*dstStep].
//    mSrcDst           Pointer to the source and result matrix [width][width].
//    dstStep           Row step in pDst.
//    height            Number of rows in the input matrix.
//    val               Value to multiply to each distance.
// Return:
//    ippStsNoErr       Indicates no error.
//    ippStsNullPtrErr  Indicates an error when the pSrc, mSrc, pMean, pSrcDst,
//                      or mSrcDst pointer is null.
//    ippStsSizeErr     Indicates an error when width or height is less than
//                      or equal to 0.
//    ippStsStrideErr   Indicates an error when srcStep or dstStep is less
//                      than width.
*/
IPPAPI(IppStatus, ippsAccCovarianceMatrix_16s64f_D2L,(const Ipp16s** mSrc,
       int height, const Ipp16s* pMean, Ipp64f** mSrcDst, int width, Ipp64f val))

IPPAPI(IppStatus, ippsAccCovarianceMatrix_32f64f_D2L, (const Ipp32f** mSrc,
       int height, const Ipp32f* pMean, Ipp64f** mSrcDst, int width, Ipp64f val))

IPPAPI(IppStatus, ippsAccCovarianceMatrix_16s64f_D2, (const Ipp16s* pSrc,
       int srcStep, int height, const Ipp16s* pMean, Ipp64f* pSrcDst, int width,
       int dstStep, Ipp64f val))

IPPAPI(IppStatus, ippsAccCovarianceMatrix_32f64f_D2, (const Ipp32f* pSrc,
       int srcStep, int height, const Ipp32f* pMean, Ipp64f* pSrcDst, int width,
       int dstStep, Ipp64f val))

///////////////////////////////////////////////////////////////////////////// */
//  Derivatives
///////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsCopyColumn_32f_D2
//  Purpose:           Copies the input sequence into the output sequence.
//  Parameters:
//    pSrc             Pointer to the input feature sequence [height*srcWidth].
//    srcWidth         Length of each input feature vector.
//    pDst             Pointer to the output feature sequence [height*dstWidth].
//    dstWidth         Length of each output feature vector.
//    height           Number of features in the sequence.
//
//  Returns:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrc or pDst pointer is null.
//    ippStsSizeErr    Indicates an error when height or srcWidth is less than or
//                     equal to 0.
//    ippStsStrideErr  Indicates an error when dstWidth is less than srcWidth.
//
*/
IPPAPI(IppStatus, ippsCopyColumn_16s_D2, (const Ipp16s* pSrc, int srcWidth,
       Ipp16s* pDst, int dstWidth, int height))

IPPAPI(IppStatus, ippsCopyColumn_32f_D2, (const Ipp32f* pSrc, int srcWidth,
       Ipp32f* pDst, int dstWidth, int height))

// The functions use for compatibility
IPPAPI(IppStatus, ippsCopyCol_32f_D2, (const Ipp32f* pSrc, int srcWidth,
       Ipp32f* pDst, int dstWidth, int height))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsEvalDelta_16s_D2
//  Purpose:           Computes the derivatives of vector elements.
//
//  Parameters:
//    pSrcDst          Pointer to the input and output vector [height*step].
//    height           The number of rows in pSrcDst.
//    step             Length of each feature in pSrcDst
//    width            The number of derivatives to be calculated for each feature.
//    offset           Offset to place the derivative values.
//    winSize          The delta window size
//    val              The delta coefficient.
//    pVal             Pointer to the delta coefficients vector [width].
//    scaleFactor
//
//  Return:
//    ippStsNoErr          Indicates no error.
//    ippStsNullPtrErr     Indicates an error when the pSrcDst pointer is null.
//    ippStsSizeErr        Indicates an error when height, width, or winSize
//                         is less than or equal to 0 or offset is less than 0
//                         or width is less than or equal to offset or height is
//                         less than 2*winSize.
//    ippStsStrideErr      Indicates an error when step is less than offset+2*width.
//
//
*/

IPPAPI(IppStatus, ippsEvalDelta_16s_D2Sfs, (Ipp16s*pSrcDst, int height, int step,
       int width, int offset, int winSize, Ipp16s val, int scaleFactor))

IPPAPI(IppStatus, ippsEvalDelta_32f_D2, (Ipp32f *pSrcDst, int height, int step,
       int width, int offset, int winSize, Ipp32f val))

IPPAPI(IppStatus, ippsEvalDeltaMul_16s_D2Sfs, (Ipp16s* pSrcDst, int height,
       int step, const Ipp16s* pVal, int width, int offset, int winSize,
       int scaleFactor))

IPPAPI(IppStatus, ippsEvalDeltaMul_32f_D2, (Ipp32f* pSrcDst, int height,
       int step, const Ipp32f* pVal, int width, int offset, int winSize))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsDelta*_16s_D2
//  Purpose:           Copies the base features and calculates the
//                     derivatives of feature vectors.
//  Parameters:
//    pSrc             Pointer to the source vector [height*srcWidth].
//    srcWidth         The number of columns in the pSrc.
//    pDst             Pointer to the result vector [height*dstStep].
//    dstStep          The row step in pDst.
//    val              The delta coefficient.
//    height           Number of feature vectors.
//    deltaMode        Execution mode.
//    pVal             Pointer to the delta coefficients vector [width].
//    scaleFactor
//
//    ippStsNoErr         Indicates no error.
//    ippStsNullPtrErr    Indicates an error when the pSrc, pDst or pVal pointer is null.
//    ippStsSizeErr       Indicates an error when srcWidth is less than or equal to 0 or
//                        height is less than or equal 2*w (for ippsDelta_Win1_* w=1,
//                        ippsDelta_Win2_* w=2);
//    ippStsStrideErr     Indicates an error when dstStep is less than 2*srcWidth.
//
//
*/

IPPAPI(IppStatus, ippsDelta_Win1_16s_D2Sfs, (const Ipp16s* pSrc, int srcWidth,
       Ipp16s*  pDst, int dstStep, int height, Ipp16s val,  int deltaMode,
       int scaleFactor))

IPPAPI(IppStatus, ippsDelta_Win2_16s_D2Sfs, (const Ipp16s* pSrc, int srcWidth,
       Ipp16s*  pDst, int dstStep, int height, Ipp16s val, int deltaMode,
       int scaleFactor))

IPPAPI(IppStatus, ippsDelta_Win1_32f_D2, (const Ipp32f* pSrc, int srcWidth,
       Ipp32f*  pDst, int dstStep, int height, Ipp32f val, int deltaMode))

IPPAPI(IppStatus, ippsDelta_Win2_32f_D2, (const Ipp32f* pSrc, int srcWidth,
       Ipp32f*  pDst, int dstStep, int height, Ipp32f val, int deltaMode))

IPPAPI(IppStatus, ippsDeltaMul_Win1_16s_D2Sfs, (const Ipp16s* pSrc,
       const Ipp16s* pVal, int srcWidth, Ipp16s* pDst, int dstStep,
       int height, int deltaMode, int scaleFactor))

IPPAPI(IppStatus, ippsDeltaMul_Win2_16s_D2Sfs, (const Ipp16s* pSrc,
       const Ipp16s* pSrc1, int srcWidth, Ipp16s* pDst, int dstStep,
       int height, int deltaMode, int scaleFactor))

IPPAPI(IppStatus, ippsDeltaMul_Win1_32f_D2, (const Ipp32f* pSrc,
       const Ipp32f* pVal, int srcWidth, Ipp32f* pDst, int dstStep,
       int height, int deltamode))

IPPAPI(IppStatus, ippsDeltaMul_Win2_32f_D2, (const Ipp32f* pSrc,
       const Ipp32f* pVal, int srcWidth, Ipp32f* pDst, int dstStep,
       int height, int deltamode))

// The functions use for compatibility
IPPAPI(IppStatus, ippsDeltaW1_32f_D2, (const Ipp32f* pSrc, int srcWidth,
       Ipp32f*  pDst, int dstStep, int height, Ipp32f val, int deltaMode))

IPPAPI(IppStatus, ippsDeltaW2_32f_D2, (const Ipp32f* pSrc, int srcWidth,
       Ipp32f*  pDst, int dstStep, int height, Ipp32f val, int deltaMode))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsDeltaDelta*_16s_D2
//  Purpose:           Copies the base features and calculates their first
//                     and second derivatives.
//  Parameters:
//    pSrc             Pointer to the source vector [height*srcWidth].
//    srcWidth         Length of the input feature in the input sequence pSrc.
//    pDst             Pointer to the result vector [height*dstStep].
//    dstStep          The row step in pDst.
//    height           The number of rows in pSrc and pDst.
//    val1, val2       The first and second delta coefficients.
//    deltaMode        Execution mode.
//    pVal             Pointer to the delta coefficients vector [width].
//  scaleFactor
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrc or pDst pointer is null.
//    ippStsSizeErr    Indicates an error when srcWidth is less than or equal to 0
//                     or height is less than or equal to 3*w
//                     (for ippsDeltaDelta_Win1_* w=1,ippsDeltaDelta_Win2_* w=2);
//    ippStsStrideErr  Indicates an error when dstStep is less than 3*srcWidth.
//
*/

IPPAPI(IppStatus, ippsDeltaDelta_Win1_16s_D2Sfs, (const Ipp16s* pSrc, int srcWidth,
       Ipp16s* pDst, int dstStep, int height, Ipp16s val1,
       Ipp16s val2, int deltaMode, int scaleFactor))

IPPAPI(IppStatus, ippsDeltaDelta_Win2_16s_D2Sfs, (const Ipp16s* pSrc, int srcWidth,
       Ipp16s* pDst, int dstStep, int height, Ipp16s val1,
       Ipp16s val2, int deltaMode, int scaleFactor))

IPPAPI(IppStatus, ippsDeltaDeltaMul_Win1_16s_D2Sfs, (const Ipp16s* pSrc,
       const Ipp16s* pVal, int srcWidth, Ipp16s* pDst, int dstStep, int height,
       int deltamode, int scaleFactor))

IPPAPI(IppStatus, ippsDeltaDeltaMul_Win2_16s_D2Sfs, (const Ipp16s* pSrc,
       const Ipp16s* pVal, int srcWidth, Ipp16s* pDst, int dstStep, int height,
       int deltamode, int scaleFactor))

IPPAPI(IppStatus, ippsDeltaDeltaMul_Win1_32f_D2, (const Ipp32f* pSrc,
       const Ipp32f* pSrc1, int srcWidth, Ipp32f* pDst, int dstStep, int height,
       int deltamode))

IPPAPI(IppStatus, ippsDeltaDeltaMul_Win2_32f_D2, (const Ipp32f* pSrc,
       const Ipp32f* pSrc1, int srcWidth, Ipp32f* pDst, int dstStep, int height,
       int deltamode))

IPPAPI(IppStatus, ippsDeltaDelta_Win1_32f_D2, (const Ipp32f* pSrc, int srcWidth,
       Ipp32f* pDst, int dstStep, int height, Ipp32f val1,
       Ipp32f val2, int deltaMode))

IPPAPI(IppStatus, ippsDeltaDelta_Win2_32f_D2, (const Ipp32f* pSrc, int srcWidth,
       Ipp32f* pDst, int dstStep, int height, Ipp32f val1,
       Ipp32f val2, int deltaMode))

// The functions use for compatibility
IPPAPI(IppStatus, ippsDeltaDeltaW1_32f_D2, (const Ipp32f* pSrc, int srcWidth,
       Ipp32f* pDst, int dstStep, int height, Ipp32f val1,
       Ipp32f val2, int deltaMode))

IPPAPI(IppStatus, ippsDeltaDeltaW2_32f_D2, (const Ipp32f* pSrc, int srcWidth,
       Ipp32f* pDst, int dstStep, int height, Ipp32f val1,
       Ipp32f val2, int deltaMode))


/* /////////////////////////////////////////////////////////////////////////////
//  Model Evaluation
///////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsAddNRows_32f
//  Purpose:           Adds N vectors from the table
//  Parameters:
//    pSrc             Pointer to the input vector [height*step].
//    height           The number of rows in the pSrc.
//    offset
//    step             The row step in pSrc.
//    pInd             Pointer to the indexes vector [rows].
//    pAddInd          Pointer to the indexes addition vector [rows].
//    rows             The number of rows to add.
//    pDst             Pointer to the output vector [width].
//    width            The number of elements in the output vector pDst.
//    weight           The value to add to output vector elements.
//
//  Returns:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrc, pInd, pAddIndex, or
//                     pDst pointer is null.
//    ippStsSizeErr    Indicates an error when height, width, rows, or
//                     (pInd[i]+pAddIndex[i]) is less than 0;
//                     or (pInd[i]+pAddIndex[i]) >= height;
//                     or offset>segCount.
//    ippStsStrideErr  Indicates an error when width > step.
//
*/
IPPAPI(IppStatus, ippsAddNRows_32f_D2, (Ipp32f* pSrc, int height, int offset,
       int step, Ipp32s* pInd, Ipp16u* pAddInd, int rows, Ipp32f* pDst, int width,
       Ipp32f weight))

// The functions use for compatibility
IPPAPI(IppStatus, ippsAddNRow_32f_D2, (Ipp32f* pSrc, int height, int offset,
       int step, Ipp32s* pInd, Ipp16u* pAddInd, int rows, Ipp32f* pDst, int width,
       Ipp32f weight))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsScaleLM_*
//  Purpose:           Scales vector elements with thresholding.
//
//  Parameters:
//    pSrc             Pointer to the input vector [len].
//    pDst             Pointer to the output vector [len].
//    len              The number of elements in the pSrc and pDst vectors.
//    floor            A value used to limit each element of pSrc.
//    scale            The multiplier factor value.
//    base             The additive value.
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrc or pDst pointer is null.
//    ippStsSizeErr    Indicates an error when len is less than or equal to 0.
//
*/
IPPAPI(IppStatus, ippsScaleLM_32f, (const Ipp32f *pSrc, Ipp32f *pDst,
       int len, Ipp32f floor, Ipp32f scale, Ipp32f base))

IPPAPI(IppStatus, ippsScaleLM_16s32s, (const Ipp16s* pSrc, Ipp32s* pDst,
       int len, Ipp16s floor, Ipp16s scale, Ipp32s base))

// The functions use for compatibility
IPPAPI(IppStatus, ippsLMThreshold_32f, (Ipp32f floor, Ipp32f scale,
       Ipp32f base, const Ipp32f *pSrc, Ipp32f *pDst, int len))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsLogAdd_*
//  Purpose:           Logarithmically adds two vectors in-place.
//  Parameters:
//    pSrc             The first input vector [len].
//    pDst             The second input and output vector [len].
//    len              The number of elements in the input and output vectors.
//    hint             Recommends to use a specific code for the
                       Logarithmically adds.
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrc or pDst pointer is null.
//    ippStsSizeErr    Indicates an error when lenis less than or equal to 0.
//
*/
IPPAPI(IppStatus,ippsLogAdd_64f,(const Ipp64f* pSrc, Ipp64f* pDst, int len,
       IppHintAlgorithm hint))

IPPAPI(IppStatus,ippsLogAdd_32f,(const Ipp32f* pSrc, Ipp32f* pDst, int len,
       IppHintAlgorithm hint))

IPPAPI(IppStatus,ippsLogAdd_32s,(const Ipp32s* pSrc, Ipp32s* pDst, int len,
        int scaleFactor, IppHintAlgorithm hint))

IPPAPI(IppStatus,ippsLogAdd_16s,(const Ipp16s* pSrc, Ipp16s* pDst, int len,
        int scaleFactor, IppHintAlgorithm hint))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsLogSub_*
//  Purpose:           Logarithmically subtracts two vectors in place .
//  Parameters:
//    pSrc             Pointer to the input vector [len].
//    pDst             Pointer to the input and output vectors [len].
//    len              The number of elements in the input and output vectors.
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrc or pDst pointer is null.
//    ippStsSizeErr    Indicates an error when len is less than or equal to 0.
//    ippStsNoOperation Indicates an error when pDst[i] > pSrc[i]is more than 0.
//
*/
IPPAPI(IppStatus,ippsLogSub_32f,(const Ipp32f* pSrc, Ipp32f* pDst, int len))

IPPAPI(IppStatus,ippsLogSub_64f,(const Ipp64f* pSrc, Ipp64f* pDst, int len))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsMahDistSingle_*
//  Purpose:           Calculates the Mahalanobis distance
//                     for a single observation vector.
//  Parameters:
//    pSrc             Pointer to the input vector [len].
//    pMean            Pointer to the mean vector [len].
//    pVar             Pointer to the variance vector [len].
//    len              The number of elements in the input, mean,
//                     and variance vectors.
//    pResult          Pointer to the result value.
//    scaleFactor
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrc, pMean, pVar, or
//                     pResult pointer is null.
//    ippStsSizeErr    Indicates an error when len is less than or equal to 0
*/

IPPAPI(IppStatus, ippsMahDistSingle_32f, (const Ipp32f* pSrc,
       const Ipp32f* pMean, const Ipp32f* pVar, int len,
       Ipp32f* pResult))

IPPAPI(IppStatus, ippsMahDistSingle_64f, (const Ipp64f* pSrc,
       const Ipp64f* pMean, const Ipp64f* pVar, int len,
       Ipp64f* pResult))

IPPAPI(IppStatus, ippsMahDistSingle_32f64f,(const Ipp32f* pSrc,
       const Ipp32f* pMean, const Ipp32f* pVar, int len, Ipp64f* pResult))

IPPAPI(IppStatus, ippsMahDistSingle_16s32f,(const Ipp16s* pSrc,
       const Ipp16s* pMean, const Ipp16s* pVar, int len, Ipp32f* pResult))

IPPAPI(IppStatus, ippsMahDistSingle_16s32s_Sfs,(const Ipp16s* pSrc,
       const Ipp16s* pMean, const Ipp16s* pVar, int len, Ipp32s* pResult,
       int scaleFactor))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsMahDist_*_*
//  Purpose:           Calculates the Mahalanobis distances
//                     for multiple observation vectors.
//  Parameters:
//    pSrc             Pointer to the input vector [height*step].
//    mSrc             Pointer to the input matrix [height][width].
//    step             The row step in pSrc.
//    pMean            Pointer to the mean vector [width].
//    pVar             Pointer to the variance vector [width].
//    width            The length of the input matrix row, mean,
//                     and variance vectors.
//    pDst             Pointer to the result value [height].
//    height           The number of rows in the input matrix and the length of
//                     the result vector pDst.
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrc, pMean, pVar,
//                     pDst,o rmSrc pointer is null.
//    ippStsSizeErr    Indicates an error when width or heightis less than or
//                     equal to 0.
//    ippStsStrideErr  Indicates an error when width > step.
//
*/
IPPAPI(IppStatus, ippsMahDist_32f_D2, (const Ipp32f* pSrc, int step,
       const Ipp32f* pMean, const Ipp32f* pVar, int width, Ipp32f* pDst,
       int height))

IPPAPI(IppStatus, ippsMahDist_64f_D2, (const Ipp64f* pSrc, int step,
       const Ipp64f* pMean, const Ipp64f* pVar, int width, Ipp64f* pDst,
       int height))

IPPAPI(IppStatus, ippsMahDist_32f_D2L, (const Ipp32f** mSrc,
       const Ipp32f* pMean, const Ipp32f* pVar, int width, Ipp32f* pDst,
       int height))

IPPAPI(IppStatus, ippsMahDist_64f_D2L, (const Ipp64f** mSrc,
       const Ipp64f* pMean, const Ipp64f* pVar, int width, Ipp64f* pDst,
       int height))

// The functions use for compatibility
IPPAPI(IppStatus, ippsMahDist1_32f_D2, (const Ipp32f* pSrc, int step,
       const Ipp32f* pMean, const Ipp32f* pVar, int width, Ipp32f* pDst,
       int height))

IPPAPI(IppStatus, ippsMahDist1_64f_D2, (const Ipp64f* pSrc, int step,
       const Ipp64f* pMean, const Ipp64f* pVar, int width, Ipp64f* pDst,
       int height))

IPPAPI(IppStatus, ippsMahDist1_32f_D2L, (const Ipp32f** mSrc,
       const Ipp32f* pMean, const Ipp32f* pVar, int width, Ipp32f* pDst,
       int height))

IPPAPI(IppStatus, ippsMahDist1_64f_D2L, (const Ipp64f** mSrc,
       const Ipp64f* pMean, const Ipp64f* pVar, int width, Ipp64f* pDst,
       int height))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsMahDistMultiMix_*_*
//  Purpose:           Calculates the Mahalanobis distances
//                     for multiple means and variances
//  Parameters:
//    pMean            Pointer to the mean vector [height*step].
//    pVar             Pointer to the variance vector [height*step].
//    mMean            Pointer to the mean matrix [height][width].
//    mVar             Pointer to the variance matrix [height][width].
//    step             Row step in pSrc.
//    pSrc             Pointer to the input vector [width].
//    width            Length of the input matrix row and pSrc vector.
//    pDst             Pointer to the result vector [height].
//    height           Number of rows in input matrices and length of result
//                     vector pDst.
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrc, pMean, pVar,
//                     mMean, mVar, or pDst pointer is null.
//    ippStsSizeErr    Indicates an error when height or width is less than or
//                     equal to 0.
//    ippStsStrideErr  Indicates an error when width > step.
//
*/
IPPAPI(IppStatus, ippsMahDistMultiMix_32f_D2, (const Ipp32f* pMean,
       const Ipp32f* pVar, int step, const Ipp32f* pSrc, int width,
       Ipp32f* pDst, int height))

IPPAPI(IppStatus, ippsMahDistMultiMix_64f_D2, (const Ipp64f* pMean,
       const Ipp64f* pVar, int step, const Ipp64f* pSrc, int width,
       Ipp64f* pDst, int height))

IPPAPI(IppStatus, ippsMahDistMultiMix_32f_D2L, (const Ipp32f** mMean,
       const Ipp32f** mVar, const Ipp32f* pSrc, int width, Ipp32f* pDst,
       int height))

IPPAPI(IppStatus, ippsMahDistMultiMix_64f_D2L, (const Ipp64f** mMean,
       const Ipp64f** mVar, const Ipp64f* pSrc, int width, Ipp64f* pDst,
       int height))

// The functions use for compatibility
IPPAPI(IppStatus, ippsMahDist2_32f_D2, (const Ipp32f* pMean,
       const Ipp32f* pVar, int step, const Ipp32f* pSrc, int width,
       Ipp32f* pDst, int height))

IPPAPI(IppStatus, ippsMahDist2_64f_D2, (const Ipp64f* pMean,
       const Ipp64f* pVar, int step, const Ipp64f* pSrc, int width,
       Ipp64f* pDst, int height))

IPPAPI(IppStatus, ippsMahDist2_32f_D2L, (const Ipp32f** mMean,
       const Ipp32f** mVar, const Ipp32f* pSrc, int width, Ipp32f* pDst,
       int height))

IPPAPI(IppStatus, ippsMahDist2_64f_D2L, (const Ipp64f** mMean,
       const Ipp64f** mVar, const Ipp64f* pSrc, int width, Ipp64f* pDst,
       int height))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsLogGaussSingle_*
//  Purpose:           Calculates the observation probability for a
//                     single Gaussian with an observation vector.
//
//  Parameters:
//    pSrc             Pointer to the input vector [len].
//    pMean            Pointer to the mean vector [len].
//    pVar             Pointer to the variance vector [len].
//    pBlockVar        Pointer to the block diagonal variance matrix.
//    len              Number of elements in the input, mean, and variance
//                     vectors.
//    pResult          Pointer to the result value.
//    val              Gaussian constant.
//    scaleFactor
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrc, pMean, pVar, or
//                     pResult or pBlockVar pointer is null.
//    ippStsSizeErr    Indicates an error when len is less than or equal to 0.
//
*/

//Case 1: Operation for the inverse diagonal covariance matrix

IPPAPI(IppStatus, ippsLogGaussSingle_Scaled_16s32f, (const Ipp16s* pSrc,
       const Ipp16s* pMean, const Ipp16s* pVar, int width, Ipp32f* dst,
       Ipp32f val, int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussSingle_16s32s_Sfs, (const Ipp16s* pSrc,
       const Ipp16s* pMean, const Ipp16s* pVar, int width, Ipp32s* dst,
       Ipp32s val, int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussSingle_32f, (const Ipp32f* pSrc,
       const Ipp32f* pMean, const Ipp32f* pVar, int len,
       Ipp32f* pResult, Ipp32f val))

IPPAPI(IppStatus, ippsLogGaussSingle_64f, (const Ipp64f* pSrc,
       const Ipp64f* pMean, const Ipp64f* pVar, int len,
       Ipp64f* pResult, Ipp64f val))

IPPAPI(IppStatus, ippsLogGaussSingle_32f64f, (const Ipp32f* pSrc,
       const Ipp32f* pMean, const Ipp32f* pVar, int len,
       Ipp64f* pResult, Ipp64f val))

// The functions use for compatibility
IPPAPI(IppStatus, ippsLogGaussSingle_16s32f, (const Ipp16s* pSrc,
       const Ipp16s* pMean, const Ipp16s* pVar, int width, Ipp32f* dst,
       Ipp32f val))


//Case 2: Operation for the diagonal covariance matrix
IPPAPI(IppStatus, ippsLogGaussSingle_DirectVar_32f,(const Ipp32f* pSrc,
       const Ipp32f* pMean, const Ipp32f* pVar, int len, Ipp32f* pResult,
       Ipp32f val))

IPPAPI(IppStatus, ippsLogGaussSingle_DirectVar_64f,(const Ipp64f* pSrc,
       const Ipp64f* pMean, const Ipp64f* pVar, int len, Ipp64f* pResult,
       Ipp64f val))

IPPAPI(IppStatus, ippsLogGaussSingle_DirectVar_32f64f,(const Ipp32f* pSrc,
       const Ipp32f* pMean, const Ipp32f* pVar, int len, Ipp64f* pResult,
       Ipp64f val))

IPPAPI(IppStatus, ippsLogGaussSingle_DirectVarScaled_16s32f,(const Ipp16s* pSrc,
       const Ipp16s* pMean, const Ipp16s* pVar, int len, Ipp32f* pResult,
       Ipp32f val, int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussSingle_DirectVar_16s32s_Sfs,(const Ipp16s* pSrc,
       const Ipp16s* pMean, const Ipp16s* pVar, int len, Ipp32s* pResult,
       Ipp32s val, int scaleFactor))

// The functions use for compatibility
IPPAPI(IppStatus, ippsLogGaussSingle_DirectVar_16s32f,(const Ipp16s* pSrc,
       const Ipp16s* pMean, const Ipp16s* pVar, int len, Ipp32f* pResult,
       Ipp32f val))


//Case 3: Operation for the identity covariance matrix
IPPAPI(IppStatus, ippsLogGaussSingle_IdVar_32f,(const Ipp32f* pSrc,
       const Ipp32f* pMean, int len, Ipp32f* pResult, Ipp32f val))

IPPAPI(IppStatus, ippsLogGaussSingle_IdVar_64f,(const Ipp64f* pSrc,
       const Ipp64f* pMean, int len, Ipp64f* pResult, Ipp64f val))

IPPAPI(IppStatus, ippsLogGaussSingle_IdVar_32f64f,(const Ipp32f* pSrc,
       const Ipp32f* pMean, int len, Ipp64f* pResult, Ipp64f val))

IPPAPI(IppStatus, ippsLogGaussSingle_IdVar_16s32s_Sfs,(const Ipp16s* pSrc,
       const Ipp16s* pMean, int len, Ipp32s* pResult, Ipp32s val,
       int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussSingle_IdVarScaled_16s32f,(const Ipp16s* pSrc,
       const Ipp16s* pMean, int len, Ipp32f* pResult, Ipp32f va,
       int scaleFactorl))

// The functions use for compatibility
IPPAPI(IppStatus, ippsLogGaussSingle_IdVar_16s32f,(const Ipp16s* pSrc,
       const Ipp16s* pMean, int len, Ipp32f* pResult, Ipp32f val))


//Case 4: Operation for the block diagonal covariance matrix
IPPAPI(IppStatus, ippsLogGaussSingle_BlockDVar_32f,(const Ipp32f* pSrc,
       const Ipp32f* pMean,const IppsBlockDMatrix_32f* pVar, int len,
       Ipp32f* pResult, Ipp32f val))
IPPAPI(IppStatus, ippsLogGaussSingle_BlockDVar_64f,(const Ipp64f* pSrc,
       const Ipp64f* pMean, const IppsBlockDMatrix_64f * pVar, int len,
       Ipp64f* pResult, Ipp64f val))

IPPAPI(IppStatus, ippsLogGaussSingle_BlockDVar_32f64f,(const Ipp32f* pSrc,
       const Ipp32f* pMean, const IppsBlockDMatrix_32f * pVar, int len,
       Ipp64f* pResult, Ipp64f val))

IPPAPI(IppStatus, ippsLogGaussSingle_BlockDVar_16s32f,(const Ipp16s* pSrc,
       const Ipp16s* pMean, const IppsBlockDMatrix_16s* pVar, int len,
       Ipp32f* pResult, Ipp32f val))

IPPAPI(IppStatus, ippsLogGaussSingle_BlockDVarScaled_16s32f,(const Ipp16s* pSrc,
       const Ipp16s* pSrcMean,const IppsBlockDMatrix_16s* pSrcVar, int srcLen,Ipp32f* pResult,
       Ipp32f val,int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussSingle_BlockDVar_16s32s_Sfs,(const Ipp16s* pSrc,
       const Ipp16s* pMean, const IppsBlockDMatrix_16s * pVar, int len,
       Ipp32s* pResult, Ipp32s val, int scaleFactor))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsLogGauss_*
//  Purpose:           Calculates the observation probability for a single
//                     Gaussian with multiple observation vectors.
//  Parameters:
//    pSrc             Pointer to the input vector [height*step].
//    mSrc             Pointer to the input matrix [height][width].
//    step             The row step in pSrc.
//    pMean            Pointer to the mean vector [width].
//    pVar             Pointer to the variance vector [width].
//    width            Length of the mean and variance vectors.
//    pDst             Pointer to the result value [height].
//    pSrcDst          Pointer to the input and output vector [height].
//    height           The number of rows in the input matrix and the length of
//                     the result vector pDst.
//    val              Gaussian constant.
//    scaleFactor
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrc, pMean, pVar,
//                     pDst,or mSrc pointer is null.
//    ippStsSizeErr    Indicates an error when height or width is less than or
//                     equal to 0.
//    ippStsStrideErr  Indicates an error when width > step.
//
*/

//Case 1: Operation for the inverse diagonal covariance matrix
IPPAPI(IppStatus, ippsLogGauss_16s32s_D2Sfs, (const Ipp16s* pSrc, int step,
       const Ipp16s* pMean, const Ipp16s* pVar, int width, Ipp32s* pDst,
       int height, Ipp32s val, int scaleFactor))

IPPAPI(IppStatus, ippsLogGauss_16s32s_D2LSfs, (const Ipp16s** mSrc,
       const Ipp16s* pMean, const Ipp16s* pVar, int width, Ipp32s* pDst,
       int height, Ipp32s val, int scaleFactor))

IPPAPI(IppStatus, ippsLogGauss_32f_D2, (const Ipp32f* pSrc, int step,
       const Ipp32f* pMean, const Ipp32f* pVar, int width, Ipp32f* pDst,
       int height, Ipp32f val))

IPPAPI(IppStatus, ippsLogGauss_64f_D2, (const Ipp64f* pSrc, int step,
       const Ipp64f* pMean, const Ipp64f* pVar, int width, Ipp64f* pDst,
       int height, Ipp64f val))

IPPAPI(IppStatus, ippsLogGauss_32f_D2L, (const Ipp32f** mSrc,
       const Ipp32f* pMean, const Ipp32f* pVar, int width,
       Ipp32f* pDst, int height, Ipp32f val))

IPPAPI(IppStatus, ippsLogGauss_64f_D2L, (const Ipp64f** mSrc,
       const Ipp64f* pMean, const Ipp64f* pVar, int width,
       Ipp64f* pDst, int height, Ipp64f val))

IPPAPI(IppStatus, ippsLogGauss_Scaled_16s32f_D2, (const Ipp16s* pSrc, int step,
       const Ipp16s* pMean, const Ipp16s* pVar, int width, Ipp32f* pDst,
       int height, Ipp32f val, int scaleFactor))

IPPAPI(IppStatus, ippsLogGauss_Scaled_16s32f_D2L, (const Ipp16s** mSrc,
       const Ipp16s* pMean, const Ipp16s* pVar, int width, Ipp32f* pDst,
       int height, Ipp32f val, int scaleFactor))


// The functions use for compatibility
IPPAPI(IppStatus, ippsLogGauss_16s32f_D2, (const Ipp16s* pSrc, int step,
       const Ipp16s* pMean, const Ipp16s* pVar, int width, Ipp32f* pDst,
       int height, Ipp32f val))

IPPAPI(IppStatus, ippsLogGauss_16s32f_D2L, (const Ipp16s** mSrc,
       const Ipp16s* pMean, const Ipp16s* pVar, int width, Ipp32f* pDst,
       int height, Ipp32f val))

IPPAPI(IppStatus, ippsLogGauss1_32f_D2, (const Ipp32f* pSrc, int step,
       const Ipp32f* pMean, const Ipp32f* pVar, int width, Ipp32f* pDst,
       int height, Ipp32f val))

IPPAPI(IppStatus, ippsLogGauss1_64f_D2, (const Ipp64f* pSrc, int step,
       const Ipp64f* pMean, const Ipp64f* pVar, int width, Ipp64f* pDst,
       int height, Ipp64f val))

IPPAPI(IppStatus, ippsLogGauss1_32f_D2L, (const Ipp32f** mSrc,
       const Ipp32f* pMean, const Ipp32f* pVar, int width,
       Ipp32f* pDst, int height, Ipp32f val))

IPPAPI(IppStatus, ippsLogGauss1_64f_D2L, (const Ipp64f** mSrc,
       const Ipp64f* pMean, const Ipp64f* pVar, int width,
       Ipp64f* pDst, int height, Ipp64f val))
//Case 2: Operation for the identity covariance matrix

IPPAPI(IppStatus, ippsLogGauss_IdVar_16s32s_D2Sfs,(const Ipp16s* pSrc,
       int step, const Ipp16s* pMean, int width, Ipp32s* pDst, int height,
       Ipp32s val, int scaleFactor))

IPPAPI(IppStatus, ippsLogGauss_IdVarScaled_16s32f_D2,(const Ipp16s* pSrc,
       int step, const Ipp16s* pMean, int width, Ipp32f* pDst, int height,
       Ipp32f val, int scaleFactor))

IPPAPI(IppStatus, ippsLogGauss_IdVar_32f_D2,(const Ipp32f* pSrc, int step,
       const Ipp32f* pMean, int width, Ipp32f* pDst, int height,
       Ipp32f val))

IPPAPI(IppStatus, ippsLogGauss_IdVar_64f_D2,(const Ipp64f* pSrc, int step,
       const Ipp64f* pMean, int width, Ipp64f* pDst, int height,
       Ipp64f val))

IPPAPI(IppStatus, ippsLogGauss_IdVar_16s32s_D2LSfs,(const Ipp16s** mSrc,
       const Ipp16s* pMean, int width, Ipp32s* pDst, int height, Ipp32s val,
       int scaleFactor))

IPPAPI(IppStatus, ippsLogGauss_IdVarScaled_16s32f_D2L,(const Ipp16s** mSrc,
       const Ipp16s* pMean, int width, Ipp32f* pDst, int height, Ipp32f val,
       int scaleFactor))

IPPAPI(IppStatus, ippsLogGauss_IdVar_32f_D2L,(const Ipp32f** mSrc,
       const Ipp32f* pMean, int width, Ipp32f* pDst, int height, Ipp32f val))

IPPAPI(IppStatus, ippsLogGauss_IdVar_64f_D2L,(const Ipp64f** mSrc,
       const Ipp64f* pMean, int width, Ipp64f* pDst, int height, Ipp64f val))

// The functions use for compatibility
IPPAPI(IppStatus, ippsLogGauss_IdVar_16s32f_D2,(const Ipp16s* pSrc,
       int step, const Ipp16s* pMean, int width, Ipp32f* pDst, int height,
       Ipp32f val))

IPPAPI(IppStatus, ippsLogGauss_IdVar_16s32f_D2L,(const Ipp16s** mSrc,
       const Ipp16s* pMean, int width, Ipp32f* pDst, int height, Ipp32f val))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsLogGaussMultiMix_*
//  Purpose:           Calculates the observation probability for
//                     multiple Gaussian mixture components.
//
//  Parameters:
//    pMean            Pointer to the mean vector [height*step].
//    pVar             Pointer to the variance vector [height*step].
//    mMean            Pointer to the mean matrix [height][width].
//    mVar             Pointer to the variance matrix [height][width].
//    pSrcDst          Pointer to the input additive values and
//                     the result vector [height].
//    step             The row step in pMean.
//    pSrc             Pointer to the input vector [width].
//    height           The number of rows in input matrices and the length of
//                     the result vector pSrcDst.
//    width            The length of the input matrices row and the vector pSrc.
//    scaleFactor
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrc, pMean, pVar,
//                     pSrcDst, mMean, or mVar pointer is null.
//    ippStsSizeErr    Indicates an error when height or width is less than or
//                     equal to 0.
//    ippStsStrideErr  Indicates an error when width > step.
//
*/
IPPAPI(IppStatus, ippsLogGaussMultiMix_16s32s_D2Sfs, (const Ipp16s* pMean,
       const Ipp16s* pVar, int step, const Ipp16s* pSrc, int width,
       Ipp32s* pSrcDst, int height, int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussMultiMix_16s32s_D2LSfs, (const Ipp16s** mMean,
       const Ipp16s** mVar, const Ipp16s* pSrc, int width, Ipp32s* pSrcDst,
       int height, int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussMultiMix_Scaled_16s32f_D2, (const Ipp16s* pMean,
       const Ipp16s* pVar, int step, const Ipp16s* pSrc, int width,
       Ipp32f* pSrcDst, int height, int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussMultiMix_Scaled_16s32f_D2L, (const Ipp16s** mMean,
       const Ipp16s** mVar, const Ipp16s* pSrc, int width, Ipp32f* pSrcDst,
       int height, int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussMultiMix_32f_D2, (const Ipp32f* pMean,
       const Ipp32f* pVar, int step, const Ipp32f* pSrc, int width,
       Ipp32f* pSrcDst, int height))

IPPAPI(IppStatus, ippsLogGaussMultiMix_64f_D2, (const Ipp64f* pMean,
       const Ipp64f* pVar, int step, const Ipp64f* pSrc, int width,
       Ipp64f* pSrcDst, int height))

IPPAPI(IppStatus, ippsLogGaussMultiMix_32f_D2L, (const Ipp32f** mMean,
       const Ipp32f** mVar, const Ipp32f* pSrc, int width, Ipp32f* pSrcDst,
       int height))

IPPAPI(IppStatus, ippsLogGaussMultiMix_64f_D2L, (const Ipp64f** mMean,
       const Ipp64f** mVar, const Ipp64f* pSrc, int width, Ipp64f* pSrcDst,
       int height))

// The functions use for compatibility
IPPAPI(IppStatus, ippsLogGaussMultiMix_16s32f_D2, (const Ipp16s* pMean,
       const Ipp16s* pVar, int step, const Ipp16s* pSrc, int width,
       Ipp32f* pSrcDst, int height))

IPPAPI(IppStatus, ippsLogGaussMultiMix_16s32f_D2L, (const Ipp16s** mMean,
       const Ipp16s** mVar, const Ipp16s* pSrc, int width, Ipp32f* pSrcDst,
       int height))

IPPAPI(IppStatus, ippsLogGauss2_32f_D2, (const Ipp32f* pMean,
       const Ipp32f* pVar, int step, const Ipp32f* pSrc, int width,
       Ipp32f* pSrcDst, int height))

IPPAPI(IppStatus, ippsLogGauss2_64f_D2, (const Ipp64f* pMean,
       const Ipp64f* pVar, int step, const Ipp64f* pSrc, int width,
       Ipp64f* pSrcDst, int height))

IPPAPI(IppStatus, ippsLogGauss2_32f_D2L, (const Ipp32f** mMean,
       const Ipp32f** mVar, const Ipp32f* pSrc, int width, Ipp32f* pSrcDst,
       int height))

IPPAPI(IppStatus, ippsLogGauss2_64f_D2L, (const Ipp64f** mMean,
       const Ipp64f** mVar, const Ipp64f* pSrc, int width, Ipp64f* pSrcDst,
       int height))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsLogGaussMax_*_D2
//  Purpose:           Computes maximum  value of a vector dst and
//                     logarithms of the Gaussian probability distribution function.
//  Parameters:
//    pSrc             Pointer to the input vector [height*step].
//    mSrc             Pointer to the input matrix [height][width].
//    step             The row step in pSrc.
//    pMean            Pointer to the mean vector [width].
//    pVar             Pointer to the variance vector [width].
//    width            The length of the input matrix row, mean,
//                     and variance vectors.
//    pSrcDst          Pointer to the input and output vector [height].
//    height           The number of rows in the input matrix and the length of
//                     the result vector pSrcDst.
//    val              The value to add to each distance.
//    scaleFactor
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrc, pMean, pVar,
//                     pSrcDst, mSrc pointer is null.
//    ippStsSizeErr    Indicates an error when height or width is less than or
//                     equal to 0.
//    ippStsStrideErr  Indicates an error when width > step.
//
*/

//Case 1: Operation for the inverse diagonal covariance matrix
IPPAPI(IppStatus, ippsLogGaussMax_32f_D2, (const Ipp32f* pSrc, int step,
      const Ipp32f* pMean, const Ipp32f* pVar, int width,
      Ipp32f* pSrcDst, int height, Ipp32f val))

IPPAPI(IppStatus, ippsLogGaussMax_32f_D2L, (const Ipp32f** mSrc,
      const Ipp32f* pMean, const Ipp32f*  pVar, int width, Ipp32f* pSrcDst,
      int height, Ipp32f  val))

IPPAPI(IppStatus, ippsLogGaussMax_64f_D2, (const Ipp64f* pSrc, int step,
      const Ipp64f* pMean, const Ipp64f* pVar, int width, Ipp64f* pSrcDst,
      int height, Ipp64f val))

IPPAPI(IppStatus, ippsLogGaussMax_64f_D2L, (const Ipp64f** mSrc,
      const Ipp64f* pMean, const Ipp64f* pVar, int width, Ipp64f* pSrcDst,
      int height, Ipp64f val))

IPPAPI(IppStatus, ippsLogGaussMax_16s32s_D2Sfs, (const Ipp16s* pSrc,
      int step, const Ipp16s* pMean, const Ipp16s* pVar, int width,
      Ipp32s* pSrcDst, int height, Ipp32s val, int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussMax_16s32s_D2LSfs, (const Ipp16s** mSrc,
      const Ipp16s* pMean, const Ipp16s*  pVar, int width, Ipp32s* pSrcDst,
      int height, Ipp32s  val, int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussMax_Scaled_16s32f_D2, (const Ipp16s* pSrc, int step,
      const Ipp16s* pMean, const Ipp16s* pVar, int width,
      Ipp32f* pSrcDst, int height, Ipp32f val, int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussMax_Scaled_16s32f_D2L, (const Ipp16s** mSrc,
      const Ipp16s* pMean, const Ipp16s*  pVar, int width, Ipp32f* pSrcDst,
      int height, Ipp32f  val, int scaleFactor))

// The functions use for compatibility
IPPAPI(IppStatus, ippsLogGaussMax1_32f_D2, (const Ipp32f* pSrc, int step,
       const Ipp32f* pMean, const Ipp32f* pVar, int width,
       Ipp32f* pSrcDst, int height, Ipp32f val))

IPPAPI(IppStatus, ippsLogGaussMax_16s32f_D2, (const Ipp16s* pSrc, int step,
      const Ipp16s* pMean, const Ipp16s* pVar, int width,
      Ipp32f* pSrcDst, int height, Ipp32f val))

IPPAPI(IppStatus, ippsLogGaussMax_16s32f_D2L, (const Ipp16s** mSrc,
      const Ipp16s* pMean, const Ipp16s*  pVar, int width, Ipp32f* pSrcDst,
      int height, Ipp32f  val))

//Case 2: Operation for the identity covariance matrix
IPPAPI(IppStatus, ippsLogGaussMax_IdVar_32f_D2, (const Ipp32f* pSrc,
       int step, const Ipp32f* pMean, int width, Ipp32f* pSrcDst,
       int height, Ipp32f val))

IPPAPI(IppStatus, ippsLogGaussMax_IdVar_32f_D2L, (const Ipp32f** mSrc,
       const Ipp32f* pMean, int width, Ipp32f* pSrcDst, int height,
       Ipp32f val))

IPPAPI(IppStatus, ippsLogGaussMax_IdVar_64f_D2, (const Ipp64f* pSrc,
       int step, const Ipp64f* pMean, int width, Ipp64f* pSrcDst,
       int height, Ipp64f val))

IPPAPI(IppStatus, ippsLogGaussMax_IdVar_64f_D2L, (const Ipp64f** mSrc,
       const Ipp64f* pMean, int width, Ipp64f* pSrcDst, int height,
       Ipp64f val))

IPPAPI(IppStatus, ippsLogGaussMax_IdVar_16s32s_D2Sfs, (const Ipp16s* pSrc,
       int step, const Ipp16s* pMean, int width, Ipp32s* pSrcDst,
       int height, Ipp32s val, int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussMax_IdVar_16s32s_D2LSfs, (const Ipp16s** mSrc,
       const Ipp16s* pMean, int width, Ipp32s* pSrcDst, int height,
       Ipp32s val, int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussMax_IdVarScaled_16s32f_D2, (const Ipp16s* pSrc,
       int step, const Ipp16s* pMean, int width, Ipp32f* pSrcDst,
       int height, Ipp32f val, int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussMax_IdVarScaled_16s32f_D2L, (const Ipp16s** mSrc,
       const Ipp16s* pMean, int width, Ipp32f* pSrcDst, int height,
       Ipp32f val, int scaleFactor))

// The functions use for compatibility
IPPAPI(IppStatus, ippsLogGaussMax_IdVar_16s32f_D2, (const Ipp16s* pSrc,
       int step, const Ipp16s* pMean, int width, Ipp32f* pSrcDst,
       int height, Ipp32f val))

IPPAPI(IppStatus, ippsLogGaussMax_IdVar_16s32f_D2L, (const Ipp16s** mSrc,
       const Ipp16s* pMean, int width, Ipp32f* pSrcDst, int height,
       Ipp32f val))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsLogGaussMaxMultiMix_*_*
//  Purpose:           Computes the maximum of the Gaussian probability
//                     distribution function.
//  Parameters:
//    pMean            Pointer to the mean vector [height*step].
//    pVar             Pointer to the variance vector [height*step].
//    mMean            Pointer to the mean matrix [height][width].
//    mVar             Pointer to the variance matrix [height][width].
//    pVal             Pointer to the input vector of Max values [height].
//    pSrcDst          Pointer to the input and output vector [height].
//    step             Row step in pMean and pVar.
//    pSrc             Pointer to theinput vector [width].
//    height           Number of rows in input matrices and the length of
//                     the result vector pSrcDst.
//    width            Length of the input matrices row and the vector pSrc.
//    scaleFactor
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrc, pMean, pVar,
//                     pSrcDst, mMean, mVar or pVal pointer is null.
//    ippStsSizeErr    Indicates an error when height or width is less than or
//                     equal to 0.
//    ippStsStrideErr  Indicates an error when width > step.
//
*/
IPPAPI(IppStatus, ippsLogGaussMaxMultiMix_32f_D2, (const Ipp32f* pMean,
       const Ipp32f* pVar, int step, const Ipp32f* pSrc, int width,
       const Ipp32f* pVal, Ipp32f* pSrcDst, int height))

IPPAPI(IppStatus, ippsLogGaussMaxMultiMix_32f_D2L, (const Ipp32f** mMean,
       const Ipp32f** mVar, const Ipp32f* pSrc, int width, const Ipp32f* pVal,
       Ipp32f* pSrcDst, int height))

IPPAPI(IppStatus, ippsLogGaussMaxMultiMix_64f_D2, (const Ipp64f* pMean,
       const Ipp64f* pVar, int step, const Ipp64f* pSrc, int width,
       const Ipp64f* pVal, Ipp64f* pSrcDst, int height))

IPPAPI(IppStatus, ippsLogGaussMaxMultiMix_64f_D2L, (const Ipp64f** mMean,
       const Ipp64f** mVar, const Ipp64f* pSrc, int width, const Ipp64f* pVal,
       Ipp64f* pSrcDst, int height))

IPPAPI(IppStatus, ippsLogGaussMaxMultiMix_Scaled_16s32f_D2, (const Ipp16s* pMean,
       const Ipp16s* pVar, int step, const Ipp16s* pSrc, int width,
       const Ipp32f* pVal, Ipp32f* pSrcDst, int height, int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussMaxMultiMix_Scaled_16s32f_D2L, (const Ipp16s** mMean,
       const Ipp16s** mVar, const Ipp16s* pSrc, int width, const Ipp32f* pVal,
       Ipp32f* pSrcDst, int height, int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussMaxMultiMix_16s32s_D2Sfs, (const Ipp16s* pMean,
       const Ipp16s* pVar, int step, const Ipp16s* pSrc, int width,
       const Ipp32s* pVal, Ipp32s* pSrcDst, int height, int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussMaxMultiMix_16s32s_D2LSfs, (const Ipp16s** mMean,
       const Ipp16s** mVar, const Ipp16s* pSrc, int width, const Ipp32s* pVal,
       Ipp32s* pSrcDst, int height, int scaleFactor))

// The functions use for compatibility
IPPAPI(IppStatus, ippsLogGaussMaxMultiMix_16s32f_D2, (const Ipp16s* pMean,
       const Ipp16s* pVar, int step, const Ipp16s* pSrc, int width,
       const Ipp32f* pVal, Ipp32f* pSrcDst, int height))

IPPAPI(IppStatus, ippsLogGaussMaxMultiMix_16s32f_D2L, (const Ipp16s** mMean,
       const Ipp16s** mVar, const Ipp16s* pSrc, int width, const Ipp32f* pVal,
       Ipp32f* pSrcDst, int height))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsLogGaussAdd_32f_D2
//  Purpose:           Calculates the likelihood probability for multiple
//                     observation vectors.
//
//  Parameters:
//    pSrc             Pointer to the input vector [width*height]
//    mSrc             Pointer to the input matrix [height][width].
//    step             Row step in pSrc.
//    pMean            Pointer to the mean vector [width]
//    pVar             Pointer to the variance vector [width]
//    width            Length of the mean, and variance vectors.
//    pSrcDst          Pointer to input vector and output vector [height]
//    height           Length of  the input and output vector pSrcDst
//    val              Value to add to each distance.
//
//  Returns:
//    ippStsNoErr      Indicates no error
//    ippStsNullPtrErr Indicates an error when the pSrc, pMean, pVar,
//                     pSrcDst or mSrc pointer is null.
//    ippStsSizeErr    Indicates an error when width or height
//                     is less than or equal to 0.
//    ippStsStrideErr  Indicates an error when width > step.
*/

//Case 1: Operation for the inverse diagonal covariance matrix
IPPAPI(IppStatus, ippsLogGaussAdd_32f_D2, (const Ipp32f* pSrc, int step,
       const Ipp32f* pMean, const Ipp32f* pVar, int width, Ipp32f* pSrcDst,
       int height, Ipp32f val))

IPPAPI(IppStatus, ippsLogGaussAdd_32f_D2L, (const Ipp32f** mSrc,
       const Ipp32f* pMean, const Ipp32f* pVar, int width, Ipp32f* pSrcDst,
       int height, Ipp32f val))

IPPAPI(IppStatus, ippsLogGaussAdd_64f_D2,(const Ipp64f* pSrc, int step,
       const Ipp64f* pMean, const Ipp64f* pVar, int width,
       Ipp64f* pSrcDst, int height, Ipp64f val))

IPPAPI(IppStatus, ippsLogGaussAdd_64f_D2L, (const Ipp64f** mSrc, const Ipp64f* pMean,
       const Ipp64f* pVar, int width, Ipp64f* pSrcDst, int height, Ipp64f val))

IPPAPI(IppStatus, ippsLogGaussAdd_Scaled_16s32f_D2,(const Ipp16s* pSrc, int step,
       const Ipp16s* pMean, const Ipp16s* pVar, int width,
       Ipp32f* pSrcDst, int height, Ipp32f val, int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussAdd_Scaled_16s32f_D2L, (const Ipp16s** mSrc,
       const Ipp16s* pMean, const Ipp16s* pVar, int width, Ipp32f* pSrcDst,
       int height, Ipp32f val, int scaleFactor))

// The functions use for compatibility
IPPAPI(IppStatus, ippsLogGaussAdd1_32f_D2, (const Ipp32f* pSrc, int step,
       const Ipp32f* pMean, const Ipp32f* pVar, int width, Ipp32f* pSrcDst,
       int height, Ipp32f val))

IPPAPI(IppStatus, ippsLogGaussAdd_16s32f_D2,(const Ipp16s* pSrc, int step,
       const Ipp16s* pMean, const Ipp16s* pVar, int width,
       Ipp32f* pSrcDst, int height, Ipp32f val, int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussAdd_16s32f_D2L, (const Ipp16s** mSrc,
       const Ipp16s* pMean, const Ipp16s* pVar, int width, Ipp32f* pSrcDst,
       int height, Ipp32f val, int scaleFactor))

//Case 2: Operation for the identity covariance matrix
IPPAPI(IppStatus, ippsLogGaussAdd_IdVarScaled_16s32f_D2,(const Ipp16s* pSrc,
       int step, const Ipp16s* pMean, int width, Ipp32f* pSrcDst,
       int height, Ipp32f val, int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussAdd_IdVarScaled_16s32f_D2L,(const Ipp16s** mSrc,
       const Ipp16s* pMean, int width, Ipp32f* pSrcDst, int height, Ipp32f val,
       int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussAdd_IdVar_32f_D2,(const Ipp32f* pSrc,
       int step, const Ipp32f* pMean, int width, Ipp32f* pSrcDst, int height,
       Ipp32f val))

IPPAPI(IppStatus, ippsLogGaussAdd_IdVar_32f_D2L,(const Ipp32f** mSrc,
       const Ipp32f* pMean, int width, Ipp32f* pSrcDst, int height, Ipp32f val))

IPPAPI(IppStatus, ippsLogGaussAdd_IdVar_64f_D2,(const Ipp64f* pSrc, int step,
       const Ipp64f* pMean, int width, Ipp64f* pSrcDst, int height, Ipp64f val))

IPPAPI(IppStatus, ippsLogGaussAdd_IdVar_64f_D2L,(const Ipp64f** mSrc,
       const Ipp64f* pMean, int width, Ipp64f* pSrcDst, int height, Ipp64f val))

// The functions use for compatibility
IPPAPI(IppStatus, ippsLogGaussAdd_IdVar_16s32f_D2,(const Ipp16s* pSrc,
       int step, const Ipp16s* pMean, int width, Ipp32f* pSrcDst,
       int height, Ipp32f val, int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussAdd_IdVar_16s32f_D2L,(const Ipp16s** mSrc,
       const Ipp16s* pMean, int width, Ipp32f* pSrcDst, int height, Ipp32f val,
       int scaleFactor))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsLogGaussAddMultiMix_*_*
//  Purpose:           Calculates the likelihood probability for multiple
//                     Gaussian mixture components.
//
//  Parameters:
//    pMean            Pointer to the variance vector [height*step].
//    mMean            Pointer to the mean matrix [height][width].
//    pVar             Pointer to the variance vector [height*step].
//    mVar             Pointer to the variance matrix [height][width].
//    pVal             Pointer to the input vector of additive values [height].
//    pSrcDst          Pointer to the input and output vector [height].
//    step             The row step in pMean.
//    pSrc             Pointer to the input vector [width].
//    height           The number of rows in input matrices and the length of
//                     the result vector pSrcDst.
//    width            The length of the input matrices row and the vector pSrc.
//    scaleFactor
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrc, pMean, pVar,
//                     pSrcDst, mMean, mVar or pVal pointer is null.
//    ippStsSizeErr    Indicates an error when height or width is less than or
//                     equal to 0.
//    ippStsStrideErr  Indicates an error when width > step.
//
*/

IPPAPI(IppStatus, ippsLogGaussAddMultiMix_Scaled_16s32f_D2, (const Ipp16s* pMean,
       const Ipp16s* pVar, int step, const Ipp16s* pSrc, int width,
        const Ipp32f* pVal, Ipp32f* pSrcDst, int height, int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussAddMultiMix_Scaled_16s32f_D2L, (const Ipp16s** mMean,
       const Ipp16s** mVar, const Ipp16s* pSrc, int width, const Ipp32f* pVal,
       Ipp32f* pSrcDst, int height, int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussAddMultiMix_32f_D2, (const Ipp32f* pMean,
       const Ipp32f* pVar, int step, const Ipp32f* pSrc, int width,
       const Ipp32f* pVal, Ipp32f* pSrcDst, int height))

IPPAPI(IppStatus, ippsLogGaussAddMultiMix_32f_D2L, (const Ipp32f** mMean,
       const Ipp32f** mVar, const Ipp32f* pSrc, int width, const Ipp32f* pVal,
       Ipp32f* pSrcDst, int height))

IPPAPI(IppStatus, ippsLogGaussAddMultiMix_64f_D2, (const Ipp64f* pMean,
       const Ipp64f* pVar, int step, const Ipp64f* pSrc, int width,
       const Ipp64f* pVal, Ipp64f* pSrcDst, int height))

IPPAPI(IppStatus, ippsLogGaussAddMultiMix_64f_D2L, (const Ipp64f** mMean,
       const Ipp64f** mVar, const Ipp64f* pSrc, int width,  const Ipp64f* pVal,
       Ipp64f* pSrcDst, int height))
// The functions use for compatibility
IPPAPI(IppStatus, ippsLogGaussAdd2_32f_D2, (const Ipp32f* meanVector,
       const Ipp32f* varVector, int stride, const Ipp32f* src, int dim,
       const Ipp32f* pVal, Ipp32f* dst, int length))

IPPAPI(IppStatus, ippsLogGaussAddMultiMix_16s32f_D2, (const Ipp16s* pMean,
       const Ipp16s* pVar, int step, const Ipp16s* pSrc, int width,
        const Ipp32f* pVal, Ipp32f* pSrcDst, int height, int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussAddMultiMix_16s32f_D2L, (const Ipp16s** mMean,
       const Ipp16s** mVar, const Ipp16s* pSrc, int width, const Ipp32f* pVal,
       Ipp32f* pSrcDst, int height, int scaleFactor))



/* /////////////////////////////////////////////////////////////////////////////
//  Model Estimation
///////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsMeanCol_*
//  Purpose:           Computes the mean values vector of column
//  Parameters:
//    pSrc             Pointer to the input vector [height*step].
//    mSrc             Pointer to the input matrix [height][width].
//    height           The number rows in the input matrix.
//    step             The row step in pSrc.
//    pDstMean         Pointer to the output mean vector [width].
//    width            The number of columns in the input matrix and the length
//                     of the output mean vector pDstMean.
//    scaleFactor
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrc, mSrc, or pDstMean
//                     pointer is null.
//    ippStsSizeErr    Indicates an error when height or width is less than
//                     or equal to 0.
//    ippStsStrideErr  Indicates an error when width > step.
//
*/
IPPAPI(IppStatus, ippsMeanColumn_16s_D2,(const Ipp16s* pSrc, int height,
       int step, Ipp16s* pDstMean, int width))

IPPAPI(IppStatus, ippsMeanColumn_16s_D2L,(const Ipp16s** mSrc, int height,
       Ipp16s* pDstMean, int width))


IPPAPI(IppStatus, ippsMeanColumn_32f_D2,(const Ipp32f* pSrc, int height,
       int step, Ipp32f* pDstMean, int width))

IPPAPI(IppStatus, ippsMeanColumn_32f_D2L,(const Ipp32f** mSrc, int height,
       Ipp32f* pDstMean, int width))

// The functions use for compatibility
IPPAPI(IppStatus, ippsMeanCol_32f_D2,(const Ipp32f* pSrc, int height,
       int step, Ipp32f* pDstMean, int width))

IPPAPI(IppStatus, ippsMeanCol_32f_D2L,(const Ipp32f** mSrc, int height,
       Ipp32f* pDstMean, int width))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsVarCol_*
//  Purpose:           Computes the variance values vector of column elements.
//  Parameters:
//    pSrc             Pointer to the input vector [height*step].
//    mSrc             Pointer to the input matrix [height][width].
//    height           The number of rows in the input matrix.
//    step             The row step in pSrc.
//    pSrcMean         Pointer to the input mean vector [width].
//    pDstVar          Pointer to the output variance vector of length [width].
//    width            Number of columns in the input matrix and the length of
//                     the input mean vector pSrcMean and output variance
//                     vector pDstVar.
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the mSrc, pSrcMean, pDstVar, or
//                     pSrc pointer is null.
//    ippStsSizeErr    Indicates an error when srcHight or width is less than or
//                     equal to 0.
//    ippStsStrideErr  Indicates an error when width > step.
//
*/

IPPAPI(IppStatus, ippsVarColumn_16s_D2Sfs,(const Ipp16s* pSrc, int height,
       int step, Ipp16s* pSrcMean, Ipp16s* pDstVar, int width, int scaleFactor))

IPPAPI(IppStatus, ippsVarColumn_16s_D2LSfs,(const Ipp16s** mSrc, int height,
       Ipp16s* pSrcMean, Ipp16s* pDstVar, int width, int scaleFactor))

IPPAPI(IppStatus, ippsVarColumn_32f_D2,(const Ipp32f* pSrc, int height,
       int step, Ipp32f* pSrcMean, Ipp32f* pDstVar, int width))

IPPAPI(IppStatus, ippsVarColumn_32f_D2L,(const Ipp32f** mSrc, int height,
       Ipp32f* pSrcMean, Ipp32f* pDstVar, int width))

// The functions use for compatibility
IPPAPI(IppStatus, ippsVarCol_32f_D2,(const Ipp32f* pSrc, int height,
       int step, Ipp32f* pSrcMean, Ipp32f* pDstVar, int width))

IPPAPI(IppStatus, ippsVarCol_32f_D2L,(const Ipp32f** mSrc, int height,
       Ipp32f* pSrcMean, Ipp32f* pDstVar, int width))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsMeanVarCol_*
//  Purpose:           Computes the mean and variance values vector of
//                     column elements.
//  Parameters:
//    pSrc             Pointer to the input vector [height*step].
//    mSrc             Pointer to the input matrix [height][width].
//    height           The number of rows in the input matrix.
//    step             The row step in pSrc.
//    pDstMean         Pointer to the output mean vector [width].
//    pDstVar          Pointer to the output variance vector [width].
//    width            The number of columns in the input matrix and the length
//                     of the output mean vector pDstMean and
//                     variance vector pDstVar.
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrc, mSrc, pDstMean, or
//                     pDstVar pointer is null.
//    ippStsSizeErr    Indicates an error when height or width is less than
//                     or equal to 0.
//    ippStsStrideErr  Indicates an error when width > step.
//
*/
IPPAPI(IppStatus, ippsMeanVarColumn_16s_D2Sfs,(const Ipp16s* pSrc, int height,
       int step, Ipp16s* pDstMean, Ipp16s* pDstVar, int width, int scaleFactor))

IPPAPI(IppStatus, ippsMeanVarColumn_16s_D2LSfs,(const Ipp16s** mSrc, int height,
       Ipp16s* pDstMean, Ipp16s* pDstVar, int width, int scaleFactor))

IPPAPI(IppStatus, ippsMeanVarColumn_32f_D2,(const Ipp32f* pSrc, int height,
       int step, Ipp32f* pDstMean, Ipp32f* pDstVar, int width))

IPPAPI(IppStatus, ippsMeanVarColumn_32f_D2L,(const Ipp32f** mSrc, int height,
       Ipp32f* pDstMean, Ipp32f* pDstVar, int width))

// The functions use for compatibility
IPPAPI(IppStatus, ippsMeanVarCol_32f_D2,(const Ipp32f* pSrc, int height,
       int step, Ipp32f* pDstMean, Ipp32f* pDstVar, int width))

IPPAPI(IppStatus, ippsMeanVarCol_32f_D2L,(const Ipp32f** mSrc, int height,
       Ipp32f* pDstMean, Ipp32f* pDstVar, int width))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsNormalizeColumn_*_*
//  Purpose:           Normalizes the matrix rows with the help of mean
//                     and variance vectors.
//  Parameters:
//    pMean              Pointer to the mean vector [width].
//    pVar               Pointer to the variance vector [width].
//    pSrcDst            Pointer to the input and output vector [height*step].
//    mSrcDst            Pointer to the input/output matrix [height][width]
//    width              The number of elements in the mean
//                       and variance vectors.
//    step               The row step in pSrcDst.
//    height             The number of rows in the input and output matrix
//    scaleFactor
//
//  Return:
//    ippStsNoErr        Indicates no error.
//    ippStsNullPtrErr   Indicates an error when the pMean, pVar, or pSrcDst
//                       or mSrcDst pointer is null.
//    ippStsSizeErr      Indicates an error when height or width is less than or
//                       equal to 0.
//    ippStsStrideErr    Indicates an error when width > step.
//
*/
IPPAPI(IppStatus, ippsNormalizeColumn_32f_D2,(Ipp32f* pSrcDst, int step,
       int height, const Ipp32f* pMean, const Ipp32f* pVar, int width))

IPPAPI(IppStatus, ippsNormalizeColumn_32f_D2L,(Ipp32f** mSrcDst, int height,
       const Ipp32f* pMean, const Ipp32f* pVar, int width))

IPPAPI(IppStatus, ippsNormalizeColumn_16s_D2Sfs,(Ipp16s* pSrcDst, int step,
       int height, const Ipp16s* pMean, const Ipp16s* pVar, int width,
       int scaleFactor))

IPPAPI(IppStatus, ippsNormalizeColumn_16s_D2LSfs,(Ipp16s** mSrcDst, int height,
       const Ipp16s* pMean, const Ipp16s* pVar, int width, int scaleFactor))

// The functions use for compatibility
IPPAPI(IppStatus, ippsNormalizeCol_32f_D2, (const Ipp32f* pMean,
       const Ipp32f* pVar, int width, Ipp32f* pSrcDst, int step, int height))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:         ippsNormalizeInRange_*
//
//  Purpose:      Normalizes and scales input vector elements.
//
//  Parameters:
//    pSrc        Pointer to the input array [len].
//    pSrcDst     Pointer to the input and output array
//                (for the in-place operation) [len].
//    pDst        Pointer to the output array [len].
//    len         Number of elements in the input and output array.
//    lowCut      Lower cutoff value.
//    highCut     High cutoff value.
//    range       Upper bound of output data value (lower bound is 0).
//
//  Return:
//    ippStsNoErr       Indicates no error.
//    ippStsNullPtrErr  Indicates an error when the pSrc or pDst pointer is null.
//    ippStsSizeErr     Indicates an error when len is less than or equal to 0.
//    ippStsBadArgErr   Indicates an error when 0<=lowCut<highCut<=1 condition
//                      is not true or range is less than 0.
//    ippStsInvZero     Indicates a warning when  Xmin = Xmax. All elements of
//                      the output vector are set to 0.
*/
IPPAPI(IppStatus, ippsNormalizeInRange_16s8u, (const Ipp16s* pSrc, Ipp8u* pDst,
       int len, Ipp32f lowCut, Ipp32f highCut, Ipp8u range))

IPPAPI(IppStatus, ippsNormalizeInRange_16s, (const Ipp16s* pSrc, Ipp16s* pDst,
       int len, Ipp32f lowCut, Ipp32f highCut, Ipp16s range))

IPPAPI(IppStatus, ippsNormalizeInRange_16s_I, (Ipp16s* pSrcDst,
       int len, Ipp32f lowCut, Ipp32f highCut, Ipp16s range))

IPPAPI(IppStatus, ippsNormalizeInRange_32f8u, (const Ipp32f* pSrc, Ipp8u* pDst,
       int len, Ipp32f lowCut, Ipp32f highCut, Ipp8u range))

IPPAPI(IppStatus, ippsNormalizeInRange_32f16s, (const Ipp32f* pSrc, Ipp16s* pDst,
       int len, Ipp32f lowCut, Ipp32f highCut, Ipp16s range))

IPPAPI(IppStatus, ippsNormalizeInRange_32f, (const Ipp32f* pSrc, Ipp32f* pDst,
       int len, Ipp32f lowCut, Ipp32f highCut, Ipp32f range))

IPPAPI(IppStatus, ippsNormalizeInRange_32f_I, (Ipp32f* pSrcDst,
       int len, Ipp32f lowCut, Ipp32f highCut, Ipp32f range))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:         ippsNormalizeInRangeMinMax_*
//
//  Purpose:      Normalizes and scales input vector elements.
//
//  Parameters:
//    pSrc        Pointer to the input array [len].
//    pSrcDst     Pointer to the input and output array
//                (for the in-place operation) [len].
//    pDst        Pointer to the output array [len].
//    len         Number of elements in the input and output array.
//    lowCut      Lower cutoff value.
//    highCut     High cutoff value.
//    range       Upper bound of output data value (lower bound is 0).
//    valMin      Minimum of input data.
//    valMax      Maximum of input data.
//
//  Return:
//    ippStsNoErr       Indicates no error.
//    ippStsNullPtrErr  Indicates an error when the pSrc or pDst pointer is null.
//    ippStsSizeErr     Indicates an error when len is less than or equal to 0.
//    ippStsBadArgErr   Indicates an error when 0<=lowCut<highCut<=1 condition
//                      is not true or range is less than 0 or valMin is greater
//                      than valMax.
//    ippStsInvZero		Indicates a warning when  valMin=valMax. All elements of
//                      the output vector are set to 0.
*/
IPPAPI(IppStatus, ippsNormalizeInRangeMinMax_16s8u, (const Ipp16s* pSrc, Ipp8u* pDst,
       int len, Ipp16s valMin, Ipp16s valMax,
       Ipp32f lowCut, Ipp32f highCut, Ipp8u range))

IPPAPI(IppStatus, ippsNormalizeInRangeMinMax_16s, (const Ipp16s* pSrc, Ipp16s* pDst,
       int len, Ipp16s valMin, Ipp16s valMax,
       Ipp32f lowCut, Ipp32f highCut, Ipp16s range))

IPPAPI(IppStatus, ippsNormalizeInRangeMinMax_16s_I, (Ipp16s* pSrcDst,
       int len, Ipp16s valMin, Ipp16s valMax, Ipp32f
       lowCut, Ipp32f highCut, Ipp16s range))

IPPAPI(IppStatus, ippsNormalizeInRangeMinMax_32f8u, (const Ipp32f* pSrc, Ipp8u* pDst,
       int len, Ipp32f valMin, Ipp32f valMax,
       Ipp32f lowCut, Ipp32f highCut, Ipp8u range))

IPPAPI(IppStatus, ippsNormalizeInRangeMinMax_32f16s, (const Ipp32f* pSrc, Ipp16s* pDst,
       int len, Ipp32f valMin, Ipp32f valMax,
       Ipp32f lowCut, Ipp32f highCut, Ipp16s range))

IPPAPI(IppStatus, ippsNormalizeInRangeMinMax_32f, (const Ipp32f* pSrc, Ipp32f* pDst,
       int len, Ipp32f valMin, Ipp32f valMax,
       Ipp32f lowCut, Ipp32f highCut, Ipp32f range))

IPPAPI(IppStatus, ippsNormalizeInRangeMinMax_32f_I, (Ipp32f* pSrcDst,
       int len, Ipp32f valMin, Ipp32f valMax,
       Ipp32f lowCut, Ipp32f highCut, Ipp32f range))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsMeanVarAcc_*
//  Purpose:           Computes mean and variance accumulators.
//  Parameters:
//    pSrc             Pointer to the input vector [len].
//    pSrcMean         Pointer to the mean vector [len].
//    pDstMeanAcc      Pointer to the mean accumulated vector [len].
//    pDstVarAcc       Pointer to the variance accumulated vector [len].
//    len              The number of elements in the input, mean,
//                     and variance vectors.
//    val              The value of the multiplyed mean and variance vectors
//                     before accumulated.
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrc, pSrcMean, pDstMeanAcc,
//                     or pDstVarAcc pointer is null.
//    ippStsSizeErr    Indicates an error when lenis less than or equal to 0.
//
*/
IPPAPI(IppStatus, ippsMeanVarAcc_32f, (Ipp32f const* pSrc,
       Ipp32f const* pSrcMean, Ipp32f* pDstMeanAcc, Ipp32f* pDstVarAcc,
       int len, Ipp32f val))

IPPAPI(IppStatus, ippsMeanVarAcc_64f, (Ipp64f const* pSrc,
       Ipp64f const* pSrcMean, Ipp64f* pDstMeanAcc, Ipp64f* pDstVarAcc,
       int len, Ipp64f val))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsGaussianDist_32f
//  Purpose:           Computes distance between Gaussians.
//  Parameters:
//    pSrcMean1        Pointer to the mean vector of the first Gaussian [len]
//    pSrcVar1         Pointer to the variance vector of the
//                     first Gaussian [len].
//    pSrcMean2        Pointer to the mean vector of the second
//                     Gaussian [len].
//    pSrcVar2         Pointer to the variance vector of the second
//                     Gaussian [len].
//    len              The number of elements in the mean and variance vectors.
//    pResult          Pointer to the distance value.
//    wgt1             The first Gaussian weight.
//    det1             The first Gaussian determinant.
//    wgt2             The second Gaussian weight.
//    det2             The second Gaussian determinant.
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrcMean1, pSrcMean2,
//                     pSrcVar1, pSrcVar2, or pResult pointer is null.
//    ippStsSizeErr    Indicates an error when lenis less than or equal to 0.
//
*/
IPPAPI(IppStatus, ippsGaussianDist_32f,(const Ipp32f* pSrcMean1,
       const Ipp32f* pSrcVar1, const Ipp32f* pSrcMean2, const Ipp32f* pSrcVar2,
       int len, Ipp32f* pResult, Ipp32f wgt1, Ipp32f det1, Ipp32f wgt2,
       Ipp32f det2))

IPPAPI(IppStatus, ippsGaussianDist_64f,(const Ipp64f* pSrcMean1,
       const Ipp64f* pSrcVar1, const Ipp64f* pSrcMean2, const Ipp64f* pSrcVar2,
       int len, Ipp64f* pResult, Ipp64f wgt1, Ipp64f det1, Ipp64f wgt2,
       Ipp64f det2))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsGaussianSplit_32f
//  Purpose:           Splits simple Gaussian probability distribution functions
//
//  Parameters:
//    pSrcMean1        Pointer to the input and the first output mean
//                     vector [len].
//    pSrcVar1         Pointer to the input and the first variance vector [len].
//    pSrcMean2        Pointer to the second output mean vector [len].
//    pSrcVar2         Pointer to the input and the second variance vector [len].
//    len              The number of elements in the mean and variance vectors.
//    val              The variance perturbation value.
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrcMean1, pSrcMean2,
//                     pSrcVar1, or pSrcVar2 pointer is null.
//    ippStsSizeErr    Indicates an error when lenis less than or equal to 0.
//
*/
IPPAPI(IppStatus, ippsGaussianSplit_32f,(Ipp32f* pSrcMean1, Ipp32f* pSrcVar1,
       Ipp32f* pSrcMean2, Ipp32f* pSrcVar2, int len, Ipp32f val))

IPPAPI(IppStatus, ippsGaussianSplit_64f,(Ipp64f* pSrcMean1,  Ipp64f* pSrcVar1,
       Ipp64f* pSrcMean2, Ipp64f* pSrcVar2, int len, Ipp64f val))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsGaussianMerge_32f
//  Purpose:           Merges two simple Gaussian probability
//                     distribution functions.
//  Parameters:
//    pSrcMean1        Pointer to the mean vector of the first Gaussian [len].
//    pSrcVar1         Pointer to the variance vector of the first
//                     Gaussian [len].
//    pSrcMean2        Pointer to the mean vector of the second Gaussian [len].
//    pSrcVar2         Pointer to the variance vector of the second
//                     Gaussian [len].
//    pDstMean         Pointer to the mean vector of the merged Gaussian [len].
//    pDstVar          Pointer to the variance vector of the merged
//                     Gaussian [len].
//    len              The number of elements in the mean and variance vectors.
//    pDstDet          Pointer to the determinant of the merged Gaussian.
//    wgt1             The first Gaussian weight.
//    wgt2             The second Gaussian weight.
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrcMean1, pSrcMean2,
//                     pSrcVar1, pSrcVar2, pDstMean, pDstVar, or pDstDet
//                     pointer is null.
//    ippStsSizeErr    Indicates an error when lenis less than or equal to 0.
//
*/
IPPAPI(IppStatus, ippsGaussianMerge_32f,(const Ipp32f* pSrcMean1,
       const Ipp32f* pSrcVar1, const Ipp32f* pSrcMean2, const Ipp32f* pSrcVar2,
       Ipp32f* pDstMean, Ipp32f* pDstVar, int len, Ipp32f* pDstDet, Ipp32f wgt1,
       Ipp32f wgt2))

IPPAPI(IppStatus, ippsGaussianMerge_64f,(const Ipp64f* pSrcMean1,
       const  Ipp64f* pSrcVar1, const Ipp64f* pSrcMean2, const Ipp64f* pSrcVar2,
       Ipp64f* pDstMean, Ipp64f* pDstVar, int len, Ipp64f* pDstDet, Ipp64f wgt1,
       Ipp64f wgt2))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:         ippsEntropy_*
//
//  Purpose:      Calculate exponent of minus squared argument.
//
//  Parameters:
//    pSrc        Pointer to the input vector [len].
//    pResult     Pointer to the destination enropy value.
//    len         Length of the input vector.
//    srcShiftVal
//    scaleFactor
//
//  Return:
//    ippStsNoErr       Indicates no error.
//    ippStsNullPtrErr  Indicates an error when the pSrc or pResult pointer is null.
//    ippStsSizeErr     Indicates an error when len is less than or equal to 0.
//    ippStsLnNegArg		Indicates a warning for input vector elements less than 0.
//                      Operation execution is aborted. The destination
//                      value NaN and for integer operations is 0.
//
*/
IPPAPI(IppStatus, ippsEntropy_32f, (const Ipp32f* pSrc, int len, Ipp32f* pResult))

IPPAPI(IppStatus, ippsEntropy_16s32s_Sfs, (const Ipp16s* pSrc, int srcShiftVal,
       int len, Ipp32s* pResult, int scaleFactor))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:         ippsSinC_*
//
//  Purpose:      Calculate sine divided by argument.
//
//  Parameters:
//    pSrc        Pointer to the input array [len].
//    pSrcDst     Pointer to the input and destination vector [len].
//    pDst        Pointer to the output array [len].
//    len         Number of elements in the input vector.
//
//  Return:
//    ippStsNoErr       Indicates no error.
//    ippStsNullPtrErr  Indicates an error when the pSrc, pSrcDst or pDst
//                      pointer is null.
//    ippStsSizeErr     Indicates an error when len is less than or equal to 0.
//
*/
IPPAPI(IppStatus, ippsSinC_32f, (const Ipp32f* pSrc, Ipp32f* pDst, int len))

IPPAPI(IppStatus, ippsSinC_32f64f, (const Ipp32f* pSrc, Ipp64f* pDst, int len))

IPPAPI(IppStatus, ippsSinC_64f, (const Ipp64f* pSrc, Ipp64f* pDst, int len))

IPPAPI(IppStatus, ippsSinC_32f_I, (Ipp32f* pSrcDst, int len))

IPPAPI(IppStatus, ippsSinC_64f_I, (Ipp64f* pSrcDst, int len))

/* /////////////////////////////////////////////////////////////////////////////
// Name:          ippsExpNegSqr_*
//
// Purpose:       Calculate exponent of minus squared argument.
//
// Parameters:
//    pSrc        Pointer to the input array [len].
//    pSrcDst     Pointer to the input and destination vector [len].
//    pDst        Pointer to the destination vector [len].
//    len         Length of the input and output vectors.
//
// Return:
//    ippStsNoErr       Indicates no error.
//    ippStsNullPtrErr  Indicates an error when the pSrc, pSrcDst or pDst
//                      pointer is null.
//    ippStsSizeErr     Indicates an error when len is less than or equal to 0.
//
// File:    psexpns.c
*/
IPPAPI(IppStatus, ippsExpNegSqr_32f, (const Ipp32f* pSrc, Ipp32f* pDst, int len))

IPPAPI(IppStatus, ippsExpNegSqr_32f64f,(const Ipp32f* pSrc, Ipp64f* pDst, int len))

IPPAPI(IppStatus, ippsExpNegSqr_64f, (const Ipp64f* pSrc, Ipp64f* pDst, int len))

IPPAPI(IppStatus, ippsExpNegSqr_32f_I, (Ipp32f* pSrcDst, int len))

IPPAPI(IppStatus, ippsExpNegSqr_64f_I, (Ipp64f* pSrcDst, int len))


/*///////////////////////////////////////////////////////////////////////////////
//  Name:              IppStatus ippsBhatDistSLog_*
//  Purpose:           Calculates the Bhattacharia distance between two Gaussians.
//
//  Parameters:
//    pSrcMean1        Pointer to the first mean vector [len].
//    pSrcVar1         Pointer to the first variance vector [len].
//    pSrcMean2        Pointer to the second mean vector [len].
//    pSrcVar2         Pointer to the second variance vector [len].
//    pResult          Pointer to the result value.
//    len              Length of the input mean and variance vectors.
//    sumLog1          Sum of the first Gaussian variance in the logarithmic
//                     representation.
//    sumLog2          Sum of the second Gaussian variance in the logarithmic
//                     representation.
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates  an error when the pSrcMean1, pSrcVar1,
//                     pSrcMean2, pSrcVar2 or pResult pointer is null.
//    ippStsSizeErr    Indicates an error when len is less than or equal to 0
//    ippStsLnZeroArg  Indicates a warning that a zero value was detected in
//                     the input vector. The execution is not aborted.
//                     The result value is set to -Inf if there is no negative
//                     element in the vector.
//    ippStsLnNegArg   Indicates a warning that negative values were detected
//                     in the input vector. The execution is not aborted.
//                     The result value is set to NaN.
//
*/

IPPAPI(IppStatus, ippsBhatDist_32f,(const Ipp32f* pSrcMean1,
       const Ipp32f* pSrcVar1, const Ipp32f* pSrcMean2, const Ipp32f* pSrcVar2,
       int len, Ipp32f* pResult))

IPPAPI(IppStatus, ippsBhatDist_32f64f,(const Ipp32f* pSrcMean1,
       const Ipp32f* pSrcVar1, const Ipp32f* pSrcMean2, const Ipp32f* pSrcVar2,
       int len, Ipp64f* pResult))

IPPAPI(IppStatus, ippsBhatDistSLog_32f,(const Ipp32f* pSrcMean1,
       const Ipp32f* pSrcVar1, const Ipp32f* pSrcMean2, const Ipp32f* pSrcVar2,
       int len, Ipp32f* pResult, Ipp32f sumLog1, Ipp32f sumLog2))

IPPAPI(IppStatus, ippsBhatDistSLog_32f64f,(const Ipp32f* pSrcMean1,
       const Ipp32f* pSrcVar1, const Ipp32f* pSrcMean2, const Ipp32f* pSrcVar2,
       int len, Ipp64f* pResult, Ipp32f sumLog1, Ipp32f sumLog2))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsUpdateMean_*
//  Purpose:           Update the mean vector in the embedded EM
//                     training algorithm.
//  Parameters:
//    pMeanAcc         Pointer to the mean accumulator [len].
//    pMean            Pointer to the mean vector [len].
//    len              The legth of the mean vector [len].
//    meanOcc          The occupation sum of the Gaussian mixture.
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pMean or pMeanAcc
//                     pointer is null.
//    ippStsZeroOcc    Indicates an error when meanOcc is equal to 0
//    ippStsNegOcc     Indicates an error when meanOcc is less than 0
//
*/

IPPAPI(IppStatus, ippsUpdateMean_32f, (const Ipp32f* pMeanAcc, Ipp32f* pMean,
       int len, Ipp32f meanOcc))

IPPAPI(IppStatus, ippsUpdateMean_64f, (const Ipp64f* pMeanAcc, Ipp64f* pMean,
       int len, Ipp64f meanOcc))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsUpdateVar_*
//  Purpose:           Updates the variance vector in the EM training
//                     algorithm.
//  Parameters:
//    pMeanAcc         Pointer to the mean accumulator [len].
//    pVarAcc          Pointer to the variance accumulator [len].
//    pVarFloor        Pointer to the variance floor vector [len].
//    pVar             Pointer to the variance vector [len].
//    len              The legth of the mean and variance vectors [len].
//    meanOcc          The occupation sum of the Gaussian mixture.
//    varOcc           The square occupation sum of the variance mixture.
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the or pMeanAcc or pVarAcc or pVar
//                     or pVarFloor pointer is null.
//    ippStsZeroOcc    Indicates an error when meanOcc or varOcc is equal to 0
//    ippStsNegOcc     Indicates an error when meanOcc and varOcc are less than 0
//    ippStsResFloor   Indicates a warning when all variances are floored.
//
*/

IPPAPI(IppStatus, ippsUpdateVar_32f, (const Ipp32f* pMeanAcc,
       const Ipp32f* pVarAcc, const Ipp32f* pVarFloor, Ipp32f* pVar, int len,
       Ipp32f meanOcc, Ipp32f varOcc))
IPPAPI(IppStatus, ippsUpdateVar_64f, (const Ipp64f* pMeanAcc,
       const Ipp64f* pVarAcc, const Ipp64f* pVarFloor, Ipp64f* pVar, int len,
       Ipp64f meanOcc, Ipp64f varOcc))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsUpdateWeight_*
//  Purpose:           Updates the weight values of Gaussian mixtures
//                     in the EM training algorithm.
//  Parameters:
//    pWgtAccm         Pointer to the weight accumulator [len].
//    pWgt             Pointer to the weight vector [len].
//    len              Number of mixtures in the HMM state.
//    pWgtSum          Pointer to the output sum of weight values.
//    wgtOcc           The nominator of the weight update equation.
//    wgtThresh        The threshold for the weight values.
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the or pWgtAcc or pWgt or pWgtSum
//                     pointer is null.
//    ippStsSizeErr    Indicates an error when len is less than or equal to 0
//    ippStsZeroOcc    Indicates an error when wgtOcc is equal to 0
//    ippStsNegOcc     Indicates an error when wgtOcc is less than 0
//    ippStsResFloor   Indicates a warning when all weights are floored.
//
*/

IPPAPI(IppStatus, ippsUpdateWeight_32f, (const Ipp32f* pWgtAcc, Ipp32f* pWgt,
       int len, Ipp32f* pWgtSum, Ipp32f wgtOcc, Ipp32f wgtThresh))

IPPAPI(IppStatus, ippsUpdateWeight_64f, (const Ipp64f* pWgtAcc, Ipp64f* pWgt,
       int len, Ipp64f* pWgtSum, Ipp64f wgtOcc, Ipp64f wgtThresh))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsUpdateGConst_*
//  Purpose:           Updates the fixed constant in the Gaussian output
//                     probability density function.
//  Parameters:
//    pVar             Pointer to the variance vector [len].
//    len              Dimension of the variance vector.
//    pDet             Pointer to the result value.
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the or pVar or pDet pointer
//                     is null.
//    ippStsSizeErr    Indicates an error when len is less than or equal to 0
//    ippStsLnZeroArg  Indicates a warning for zero-valued input vector elements.
//                     Operation execution is not aborted. The result value is
//                     set to -Inf if there are no negative elements in the vector.
//    ippStsLnNegArg   Indicates a warning for negative input vector elements.
//                     Operation execution is not aborted. The result value is NaN.
//
*/

IPPAPI(IppStatus, ippsUpdateGConst_32f, (const Ipp32f* pVar, int len, Ipp32f* pDet))

IPPAPI(IppStatus, ippsUpdateGConst_64f, (const Ipp64f* pVar, int len, Ipp64f* pDet))

IPPAPI(IppStatus, ippsUpdateGConst_DirectVar_32f, (const Ipp32f* pVar, int len,
       Ipp32f* pDet))

IPPAPI(IppStatus, ippsUpdateGConst_DirectVar_64f, (const Ipp64f* pVar, int len,
       Ipp64f* pDet))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsOutProbPreCalc_*
//  Purpose:           Pre-calculates the part of Gaussian mixture output
//                     probability that is irrelevant to observation vectors.
//  Parameters:
//    pWeight          Pointer to the Gaussian mixture weight vector [len].
//    pGConst          Pointer to the constant vector calculated from
//                     ippsUpdateGConst [len].
//    pVal             Pointer to the resulting vector [len].
//    len              Number of mixtures in the HMM state.
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the or pWeight or pGConst or pVal
//                     pointer is null.
//    ippStsSizeErr    Indicates an error when len is less than or equal to 0
//
*/

IPPAPI(IppStatus, ippsOutProbPreCalc_32f, (const Ipp32f* pWeight,
       const Ipp32f* pGConst, Ipp32f* pVal, int len))

IPPAPI(IppStatus, ippsOutProbPreCalc_64f, (const Ipp64f* pWeight,
       const Ipp64f* pGConst, Ipp64f* pVal, int len))

IPPAPI(IppStatus, ippsOutProbPreCalc_32f_I, (const Ipp32f* pWeight,
       Ipp32f* pGConst, int len))

IPPAPI(IppStatus, ippsOutProbPreCalc_64f_I, (const Ipp64f* pWeight,
       Ipp64f* pGConst, int len))

/*///////////////////////////////////////////////////////////////////////////////
//  Name:              ippsDcsClustLAccumulate_*
//  Purpose:           Update the accumulators for calculating state-cluster
//                     likelihood in the desition-tree clustering algorithm.
//  Parameters:
//    pMean            Pointer to the mean vector of the HMM state in the
//                     cluster [len]
//    pVar             Pointer to the variance vector of the HMM state in the
//                     cluster [len]
//    pDstSum          Pointer to the sum part of the accumulator [len]
//    pDstSqr          Pointer to the sqr part of the accumulator [len]
//    len              Length of the mean and variance vectors.
//    occ              Occupation count of the HMM state.
//  Return:
//    ippStsNoErr      Idicates no error
//    ippStsNullPtrErr Idicates an error when the pMean, pVar, pDstSum or
//                     pDstSqr pointer is null
//    ippStsSizeErr    Idicates an error when len is less than or equal to 0
//
*/
IPPAPI(IppStatus, ippsDcsClustLAccumulate_32f, (const Ipp32f* pMean,
       const Ipp32f* pVar, Ipp32f* pDstSum, Ipp32f* pDstSqr, int len, Ipp32f occ))

IPPAPI(IppStatus, ippsDcsClustLAccumulate_64f, (const Ipp64f* pMean,
       const Ipp64f* pVar, Ipp64f* pDstSum, Ipp64f* pDstSqr, int len, Ipp64f occ))

IPPAPI(IppStatus, ippsDcsClustLAccumulate_DirectVar_32f, (const Ipp32f* pMean,
       const Ipp32f* pVar, Ipp32f* pDstSum, Ipp32f* pDstSqr, int len, Ipp32f occ))

IPPAPI(IppStatus, ippsDcsClustLAccumulate_DirectVar_64f, (const Ipp64f* pMean,
       const Ipp64f* pVar, Ipp64f* pDstSum, Ipp64f* pDstSqr, int len, Ipp64f occ))

/*///////////////////////////////////////////////////////////////////////////////
//  Name:              ippsDcsClustLCompute_*
//  Purpose:           Calculate the likelihood of an HMM state cluster in the
//                     decision-tree state-clustering algorithm.
//  Parameters:
//    pSrcSum          Pointer to the sum part of the accumulator [len]
//    pSrcSqr          Pointer to the sqr part of the accumulator [len]
//    len              Length of the mean and variance vectors.
//    pDst             Pointer to the resulting likelihood value
//    occ              Ocupation sum of the HMM state cluster
//
//  Return:
//    ippStsNoErr      Idicates no error
//    ippStsNullPtrErr Idicates  an error when the pSrcSum, pSrcSqr,
//                     pDst pointer is null.
//    ippStsSizeErr    Indicates an error when len is less than or equal to 0 or
//                     occ is less than or equal to 0.
//    ippStsZeroOcc    Indicates an error when occ is equal to 0
//    ippStsNegOcc     Indicates an error when occ is less than 0
//    ippStsLnZeroArg  Indicates a warning for zero-valued input vector elements.
//                     Operation execution is not aborted. The result value is
//                     set to -Inf if there are no negative elements in the
//                     vector.
//    ippStsLnNegArg   Indicates a warning for negative input vector elements.
//                     Operation execution is not aborted. The result value
//                     is set to NaN.
//
*/

IPPAPI(IppStatus, ippsDcsClustLCompute_32f64f, (const Ipp32f* pSrcSum,
       const Ipp32f* pSrcSqr, int len, Ipp64f* pDst, Ipp32f occ))

IPPAPI(IppStatus, ippsDcsClustLCompute_64f, (const Ipp64f* pSrcSum,
       const Ipp64f* pSrcSqr, int len, Ipp64f* pDst, Ipp64f occ))


/* /////////////////////////////////////////////////////////////////////////////
//  Model Adaptation
///////////////////////////////////////////////////////////////////////////// */
/*/////////////////////////////////////////////////////////////////////////////
//  Name:              ippsAddMulColumn_64f_D2L
//  Purpose:           Adds a weighted matrix column to another column.
//
//  Parameters:
//    mSrcDst          Pointer to the source and destination
//                     matrix [height][width].
//    width            The number of columns in the matrix mSrcDst.
//    height           The number of rows in the matrix mSrcDst.
//    col1             The first number of the column.
//    col2             The second number of the column.
//    row1             The first number of the row.
//    val              The multiplier factor.
//
//  Returns:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the mSrcDst pointer is null.
//    ippStsSizeErr    Indicates an error when when height, width
//                     is less than or equal to 0;
//                     or col1 or col2 is greater than or equal to width;
//                     or row1 is greater than or equal to  height;
//                     or col1 or col2 or row1 is less than 0.
//
*/
IPPAPI(IppStatus, ippsAddMulColumn_64f_D2L, (Ipp64f** mSrcDst, int width,
       int height, int col1, int col2, int row1, const Ipp64f val))

// The functions use for compatibility
IPPAPI(IppStatus, ippsAddMulCol_64f_D2L, (Ipp64f** mSrcDst, int width,
       int height, int col1, int col2, int row1, const Ipp64f val))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsAddMulRow_64f
//  Purpose:           Multiplies sourceh vector elements by a value
//                     and places them in the destination vector.
//
//  Parameters:
//    pSrc             Pointer to the source vector [len]
//    pDst             Pointer to the result vector [len]
//    len              Length  of source vector
//    val              The multiplying coefficient
//
//  Returns:
//    ippStsNoErr      Indicates no error.
//    ippStsNoErr      Indicates an error when the pSrc or pDst is null
//    ippStsSizeErr    Indicates an error when the len is less or equal 0
//
*/
IPPAPI(IppStatus, ippsAddMulRow_64f, (const Ipp64f *pSrc, Ipp64f *pDst,
       int len, const Ipp64f val))

/*/////////////////////////////////////////////////////////////////////////////
//  Name:              ippsQRTransColumn_64f_D2L
//  Purpose:           Calculates QR transformation.
//
//  Parameters:
//    mSrcDst          Pointer to the source and destination
//                     matrix [height][width].
//    width            The number of columns in the matrix mSrcDst.
//    height           The number of rows in the matrix mSrcDst.
//    col1             The first number of the column.
//    col2             The second number of the column.
//    val1             The first multiplier factor.
//    val2             The second multiplier factor.
//  Returns:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the mSrcDst pointer is null.
//    ippStsSizeErr    Indicates an error when height, width
//                     is less than or equal to 0;
//                     or col1 or col2 is greater than or equal to width.
//                     or col1 or col2 is less than 0.
//
*/
IPPAPI(IppStatus, ippsQRTransColumn_64f_D2L, (Ipp64f** mSrcDst, int width,
       int height, int col1, int col2, const Ipp64f val1, const Ipp64f val2))

// The functions use for compatibility
IPPAPI(IppStatus, ippsQRTransCol_64f_D2L, (Ipp64f** mSrcDst, int width,
       int height, int col1, int col2, const Ipp64f val1, const Ipp64f val2))

/*/////////////////////////////////////////////////////////////////////////////
//  Name:              ippsDotProdColumn_64f_D2L
//  Purpose:           Calculates the dot product of two matrix columns.
//
//  Parameters:
//    mSrc             Pointer to the source matrix [height][width].
//    width            The number of columns in the matrix mSrc.
//    height           The number of rows in the matrix mSrc.
//    pSum             Pointer to the value of the computed sum.
//    col1             The first number of the column.
//    col2             The second number of the column.
//    row1             The first number of the row.
//
//  Returns:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the mSrcor pSum pointer is null.
//    ippStsSizeErr    Indicates an error when height, width
//                     is less than or equal to 0;
//                     or row1 is greater than or equal to  height;
//                     or col1 is  greater than or equal to width;
//                     or row1 or col1 is less than 0.
//
*/
IPPAPI(IppStatus, ippsDotProdColumn_64f_D2L, (const Ipp64f** mSrc, int width,
       int height, Ipp64f* pSum, int col1, int col2, int row1))

// The functions use for compatibility
IPPAPI(IppStatus, ippsDotProdCol_64f_D2L, (const Ipp64f** mSrc, int width,
       int height, Ipp64f* pSum, int col1, int col2, int row1))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsMulColumn_64f_D2L
//  Purpose:           Multiplies a matrix column by a value.
//
//  Parameters:
//    mSrcDst          Pointer to the source and destination
//                     matrix [height][width].
//    width            The number of columns in the matrix mSrcDst.
//    height           The number of rows in the matrix mSrcDst.
//    col1             The first number of the column.
//    row1             The first number of the row.
//    val              The multiplier factor.
//
//  Returns:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the mSrcDst pointer is null.
//    ippStsSizeErr    Indicates an error when height, width
//                     is less than or equal to 0;
//                     or row1 is greater than or equal to height;
//                     or col1 is greater than or equal to width;
//                     or row1 or col1 is less than 0.
//
*/
IPPAPI(IppStatus, ippsMulColumn_64f_D2L, (Ipp64f** mSrcDst, int width,
       int height, int col1, int row1, const Ipp64f val))

// The functions use for compatibility
IPPAPI(IppStatus, ippsMulCol_64f_D2L, (Ipp64f** mSrcDst, int width,
       int height, int col1, int row1, const Ipp64f val))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsSumColumnAbs_64f_D2L
//  Purpose:           Sums absolute values of column elements.
//
//  Parameters:
//    mSrc             Pointer to the source matrix [height][width].
//    width            The number of columns in the matrix mSrc.
//    height           The number of rows in the matrix mSrc.
//    pSum             Pointer to the value of the computed sum.
//    col1             The first number of the column.
//    row1             The first number of the row.
//
//  Returns:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the mSrc or pSum pointer is null.
//    ippStsSizeErr    Indicates an error when width, height
//                     is less than or equal to 0;
//                     or row1 is greater than or equal to height;
//                     or col1 is greater than or equal to width;
//                     or row1 or col1 is less than 0.
//
*/
IPPAPI(IppStatus, ippsSumColumnAbs_64f_D2L, (const Ipp64f** mSrc, int width,
       int height, Ipp64f* pSum, int col1, int row1))

// The functions use for compatibility
IPPAPI(IppStatus, ippsSumColAbs_64f_D2L, (const Ipp64f** mSrc, int width,
       int height, Ipp64f* pSum, int col1, int row1))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsSumColumnSqr_64f_D2L
//  Purpose:           Multiplies matrix column elements by a value and
//                     sums their squares.
//
//  Parameters:
//    mSrcDst          Pointer to the source matrix [height][width].
//    width            The number of columns in the matrix mSrcDst.
//    height           The number of rows in the matrix mSrcDst.
//    pSum             Pointer to the value of the computed sum.
//    col1             The first number of the column.
//
//  Returns:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the mSrcDst or pSum
//                     pointer is null.
//    ippStsSizeErr    Indicates an error when width, height
//                     is less than or equal to 0;
//                     or row1 is greater than or equal to height;
//                     or col1 is greater than or equal to width.
//                     or row1 or col1 is less than 0.
//
*/
IPPAPI(IppStatus, ippsSumColumnSqr_64f_D2L, (Ipp64f** mSrcDst, int width,
       int height, Ipp64f* pSum, int col1, int row1, const Ipp64f val))

// The functions use for compatibility
IPPAPI(IppStatus, ippsSumColSqr_64f_D2L, (Ipp64f** mSrcDst, int width,
       int height, Ipp64f* pSum, int col1, int row1, const Ipp64f val))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsSumRowAbs_64f
//  Purpose:           Sums absolute values of vector elements.
//
//  Parameters:
//    pSrc             Pointer to the source vector [len].
//    pSum             Pointer to the value of the computed sum.
//    len              The number of elements in the source vector pSrc.
//
//  Returns:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrc or pSum pointer is null.
//    ippStsSizeErr    Indicates an error when len is less than or equal to 0.
//
*/
IPPAPI(IppStatus, ippsSumRowAbs_64f, (const Ipp64f *pSrc, int len, Ipp64f *pSum))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsSumRowSqr_64f
//  Purpose:           Multiplies vector elements by a value and sums
//                     their squares.
//
//  Parameters:
//    pSrcDst          Pointer to the source vector [len].
//    len              The number of elements in the source vector pSrcDst.
//    pSum             Pointer to the value of the computed sum.
//    val              The multiplier factor.
//
//  Returns:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrcDst or pSum
//                     pointer is null.
//    ippStsSizeErr    Indicates an error when lenis less than or equal to 0.
//
*/
IPPAPI(IppStatus, ippsSumRowSqr_64f, (Ipp64f *pSrcDst,
       int len, Ipp64f *pSum, const Ipp64f val))

/*///////////////////////////////////////////////////////////////////////////////
//  Name:              ippsSVD__*
//  Purpose:           Performs Single Value Decomposition on a matrix.
//
//  Parameters:
//    pSrcA            Pointer to the input vector A [height*step].
//    pDstU            Ppointer to the output vector U [height*step].
//    pSrcDstA         Pointer to the input matrix A and output
//                     matrix U [height*step].
//    pDstV            Pointer to the output vector V [width*step].
//    mSrcA            Pointer to the input matrix A [height][width].
//    mDstU            Pointer to the output matrix U [height][width].
//    mSrcDstA         Pointer to the input matrix A and output
//                     matrix U [height][width].
//    pDstW            Pointer to the output vector W [width].
//    mDstV            Pointer to the output matrix V [width][width].
//    height           Number of rows in the input matrix.
//    width            Number of columns in the input matrix.
//    step             Row step in pSrcA, pSrcDstA, and pDstV.
//    nIter            Number of iteration for diagonalization.
//
//  Returns:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrcA, pSrcDstA, pDstV, mSrcA,
//                     mDstU, mSrcDstA, pDstW or mDstV pointer is null.
//    ippStsSizeErr    Indicates an error when heigh, width, step or nIter is less
//                     than or equal to 0 or width is greater than step;
//    ippStsSVDCnvg    Indicates an error when SVD algorithm was not converged for
//                     nIter iterations.
//
*/

IPPAPI(IppStatus, ippsSVD_64f_D2,(const Ipp64f* pSrcA, Ipp64f* pDstU, int height,
       Ipp64f* pDstW, Ipp64f* pDstV, int width, int step, int nIter))

IPPAPI(IppStatus, ippsSVD_64f_D2_I,(Ipp64f* pSrcDstA, int height, Ipp64f* pDstW,
       Ipp64f* pDstV, int width, int step, int nIter))

IPPAPI(IppStatus, ippsSVD_64f_D2L,(const Ipp64f** mSrcA, Ipp64f** mDstU, int height,
       Ipp64f* pDstW, Ipp64f** mDstV, int width, int nIter))

IPPAPI(IppStatus, ippsSVD_64f_D2L_I,(Ipp64f** mSrcDstA, int height, Ipp64f* pDstW,
       Ipp64f** mDstV, int width, int nIter))

/*///////////////////////////////////////////////////////////////////////////////
//  Name:              ippsWeightedSum_*
//  Purpose:           Calculates the weighted sums of two input vector elements.

//  Parameters:
//    pSrc1            Pointer to the first input vector [len].
//    pSrc2            Pointer to the second input vector [len].
//    pDst             Pointer to the output vector [len]
//    len              The length of the input an output vectors.
//    weight1          The first weight value.
//    weight2          The second weight value.
//
//  Returns:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrc1, pSrc2 or pDst
//                     pointer is null.
//    ippStsSizeErr    Indicates an error when len is less than or equal to 0
//    ippStsDivByZero  Indicates a warning for zero-valued divisor vector
//                     element. Operation execution is not aborted. The value of
//                     the destination vector element in the floating-point operations:
//                     NaN    For zero-valued dividend vector element.
//                     +Inf    For positive dividend vector element.
//                     -Inf    For negative dividend vector element.
//
*/
IPPAPI(IppStatus, ippsWeightedSum_16s, (const Ipp16s* pSrc1,
       const Ipp16s* pSrc2, Ipp16s* pDst, int len, Ipp32f weight1,
       Ipp32f weight2))

IPPAPI(IppStatus, ippsWeightedSum_32f, (const Ipp32f* pSrc1,
       const Ipp32f* pSrc2, Ipp32f* pDst, int len, Ipp32f weight1,
       Ipp32f weight2))

IPPAPI(IppStatus, ippsWeightedSum_64f, (const Ipp64f* pSrc1,
       const Ipp64f* pSrc2, Ipp64f* pDst, int len, Ipp64f weight1,
       Ipp64f weight2))

IPPAPI(IppStatus, ippsWeightedSumHalf_32f, (const Ipp32f* pSrc1,
       const Ipp32f* pSrc2, Ipp32f* pDst, int len, Ipp32f weight1,
       Ipp32f weight2))

IPPAPI(IppStatus, ippsWeightedSumHalf_64f, (const Ipp64f* pSrc1,
       const Ipp64f* pSrc2, Ipp64f* pDst, int len, Ipp64f weight1,
       Ipp64f weight2))


IPPAPI(IppStatus, ippsWeightedSumHalf_16s, (const Ipp16s* pSrc1,
       const Ipp16s* pSrc2, Ipp16s* pDst, int len, Ipp32f weight1,
       Ipp32f weight2))


/* /////////////////////////////////////////////////////////////////////////////
//  Vector Quantization
///////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsFormVector_*
//  Purpose:           Composes a vector from four element chunks.

//  Parameters:
//    pInd             Pointer to the input vector of codebook indexes [nStream].
//    mSrc             Pointer to the vector of pointers to source lookup
//                     tables [nStream].
//    pHeights         Pointer to the vector of codebook lengths [nStream].
//    pWidths          Pointer to the vector of codebook entry lengths [nStream].
//    pSteps           Pointer to the vector of codebook row pSteps [nStream].
//    nStream          The number of codebooks.
//    pDst             Pointer to the output vector [len].
//    len              The length of the output vector.

//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the the pInd, mSrc, pHeights,
//                     pWidths, pSteps, pDst or mSrc[k].
//    ippStsSizeErr    Indicates an error when len , nStream, pHeights[k],
//                     pWidths[k] or pSteps[k] is less than or equal to 0 .
*/
IPPAPI(IppStatus, ippsFormVector_4i_8u16s, (const Ipp8u* pInd,
       const Ipp16s** mSrc, const Ipp32s* pHeights, Ipp16s* pDst, int len))

IPPAPI(IppStatus, ippsFormVector_4i_16s16s, (const Ipp16s* pInd,
       const Ipp16s** mSrc, const Ipp32s* pHeights, Ipp16s* pDst, int len))

IPPAPI(IppStatus, ippsFormVector_4i_8u32f, (const Ipp8u* pInd,
       const Ipp32f** mSrc, const Ipp32s* pHeights, Ipp32f* pDst, int len))

IPPAPI(IppStatus, ippsFormVector_4i_16s32f, (const Ipp16s* pInd,
       const Ipp32f** mSrc, const Ipp32s* pHeights, Ipp32f* pDst, int len))


IPPAPI(IppStatus, ippsFormVector_2i_8u16s, (const Ipp8u* pInd,
       const Ipp16s** mSrc, const Ipp32s* pHeights, Ipp16s* pDst, int len))

IPPAPI(IppStatus, ippsFormVector_2i_16s16s, (const Ipp16s* pInd,
       const Ipp16s** mSrc, const Ipp32s* pHeights, Ipp16s* pDst, int len))

IPPAPI(IppStatus, ippsFormVector_2i_8u32f, (const Ipp8u* pInd,
       const Ipp32f** mSrc, const Ipp32s* pHeights, Ipp32f* pDst, int len))

IPPAPI(IppStatus, ippsFormVector_2i_16s32f, (const Ipp16s* pInd,
       const Ipp32f** mSrc, const Ipp32s* pHeights, Ipp32f* pDst, int len))


IPPAPI(IppStatus, ippsFormVector_8u16s, (const Ipp8u* pInd,
       const Ipp16s** mSrc, const Ipp32s* pHeights, const Ipp32s* pWidths,
       const Ipp32s* pSteps, int nStream, Ipp16s* pDst))

IPPAPI(IppStatus, ippsFormVector_16s16s, (const Ipp16s* pInd,
       const Ipp16s** mSrc, const Ipp32s* pHeights, const Ipp32s* pWidths,
       const Ipp32s* pSteps, int nStream, Ipp16s* pDst))

IPPAPI(IppStatus, ippsFormVector_8u32f, (const Ipp8u* pInd,
       const Ipp32f** mSrc, const Ipp32s* pHeights, const Ipp32s* pWidths,
       const Ipp32s* pSteps, int nStream, Ipp32f * pDst))

IPPAPI(IppStatus, ippsFormVector_16s32f, (const Ipp16s* pInd,
       const Ipp32f** mSrc, const Ipp32s* pHeights, const Ipp32s* pWidths,
       const Ipp32s* pSteps, int nStream, Ipp32f * pDst))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsCdbkInitAlloc_L2_*
//  Purpose:           Initializes the codebook structure.
//
//  Parameters:
//    pCdbk            Pointer to the codebook structure to be created.
//    pSrc             Pointer to the source vector [height*step].
//    width            Length of input vectors.
//    step             Row step in pSrc.
//    height           Number of rows in pSrc.
//    cdbkSize         Required number of codevectors.
//    hint             One of the following values:
//                     IPP_CDBK_FULL    The source data are treated as a codebook,
//                                      height should be greater or equal to
//                                      nCluster. The nearest codebook entry is
//                                      found by a full search.
//                     IPP_CDBK_KMEANS_LONG LBG algorithm with splitting of the
//                                      most extensional cluster is used for
//                                      the codebook building. The nearest
//                                      codebook entry is located through
//                                      a logarithmical search.
//                     IPP_CDBK_KMEANS_NUM LBG algorithm with splitting of
//                                      the most numerous clusters is used for
//                                      the codebook building. The nearest
//                                      codebook entry is located through
//                                      a logarithmical search.
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrc pointer is null.
//    ippStsSizeErr    Indicates an error when width, step, or cdbkSize
//                     is less than or equal to 0;
//                     or cdbkSizeis greater than height;
//                     or width is greater than step;
//                     or cdbkSize is greater than 16383;
//                     or hintis equal to IPP_CDBK_FULL and cdbkSizeis not equal
//                     to height.
//    ippStsCdbkFlagErr
//                      Indicates an error when the hint value is incorrect.
//    ippStsMemAllocErr Indicates an error when no memory allocated.
//
*/

IPPAPI(IppStatus, ippsCdbkInitAlloc_L2_16s,(IppsCdbkState_16s** pCdbk,
       const Ipp16s* pSrc, int width, int step, int height, int nCluster,
       Ipp_Cdbk_Hint hint))

IPPAPI(IppStatus, ippsCdbkInitAlloc_L2_32f,(IppsCdbkState_32f** pCdbk,
       const Ipp32f* pSrc, int width, int step, int height, int nCluster,
       Ipp_Cdbk_Hint hint))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:           ippsCdbkInitAlloc_WgtL2_*
//  Purpose:        Initializes the structure that contains the codebook
//					and additional information to be used for fast search.
//

//  Parameters:
//    pCdbk		       Pointer to the codebook structure to be created.
//    pSrc		       Pointer to the source vector [height*step].
//    pWgt             Pointer to the weights vector [width].
//    width		       Length of input vectors.
//    step		       Row step in pSrc.
//    height		   Number of rows in pSrc.
//    cdbkSize		   Required number of codevectors.
//    hint			   One of the following values:
//    IPP_CDBK_FULL	   The source data are treated as a codebook, height should
//						be greater or equal to nCluster. The nearest codebook
//						entry is found by a full search.
//
//	  IPP_CDBK_LBG_LONG
//					   LBG algorithm with splitting of the most extensious
//					   cluster is used for the codebook building. The nearest
//					   codebook entry is found by a logarithmical search.
//
//	  IPP_CDBK_LBG_NUM LBG algorithm with splitting of the most numerous
//					   clusters is used for the codebook building. The nearest
//					   codebook entry is found by a logarithmical search

//  Return:
//    ippStsNoErr	   Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrc pointer is null.
//    ippStsSizeErr    Indicates an error when width, step, height or cdbkSize
//						is less than or equal to 0 or width is greater than step
//						or cdbkSize is greater than 16383;
//    ippStsCdbkFlagErr
//                      Indicates an error when the hint value is incorrect.
//    ippStsMemAllocErr Indicates an error when no memory allocated.
//  Notes:
*/

IPPAPI(IppStatus, ippsCdbkInitAlloc_WgtL2_32f,(IppsCdbkState_32f** pCdbk, const Ipp32f* pSrc,
	   const Ipp32f* pWgt, int width, int step, int height, int cdbkSize, Ipp_Cdbk_Hint hint))

IPPAPI(IppStatus, ippsCdbkInitAlloc_WgtL2_16s,(IppsCdbkState_16s** pCdbk, const Ipp16s* pSrc,
	   const Ipp16s* pWgt, int width, int step, int height, int cdbkSize, Ipp_Cdbk_Hint hint))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsCdbkFree_*
//  Purpose:           Destroys the codebook structure a
//
//  Parameters:
//      pCdbk          Pointer to the codebook structure.
//  Return:
//    ippStsNoErr     Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pCdbk pointer is null.
//
*/

IPPAPI(IppStatus, ippsCdbkFree_16s,(IppsCdbkState_16s* pCdbk))

IPPAPI(IppStatus, ippsCdbkFree_32f,(IppsCdbkState_32f* pCdbk))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsGetCdbkSize_*
//  Purpose:           Retrieves the number of codevectors in the codebook.
//
//  Parameters:
//    pCdbk            Pointer to the codebook structure.
//    pNum             Pointer to the result number of codevectors.
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pCdbk or pNum pointer is null.
//
*/

IPPAPI(IppStatus, ippsGetCdbkSize_16s,(const IppsCdbkState_16s* pCdbk, int* pNum))

IPPAPI(IppStatus, ippsGetCdbkSize_32f,(const IppsCdbkState_32f* pCdbk, int* pNum))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsGetCodebook_*
//  Purpose:           Retrieves the number of codevectors in the codebook pCdbk.
//
//  Parameters:
//    pCdbk            Pointer to the codebook structure.
//    pDst             Pointer to the destination vector for codevectors
//                     [pNum[0]* step].
//    step             Row step in the destination vector pDst.
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pDst or pNum pointer is null.
//
*/

IPPAPI(IppStatus, ippsGetCodebook_16s,(const IppsCdbkState_16s* pCdbk,
       Ipp16s* pDst, int step))

IPPAPI(IppStatus, ippsGetCodebook_32f,(const IppsCdbkState_32f* pCdbk,
       Ipp32f* pDst, int step))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsVQ_*
//  Purpose:           Quantizes the input vectors given a codebook.
//
//  Parameters:
//    pCdbk            Pointer to the codebook structure.
//    pSrc             Pointer to the source vector [height*step].
//    step             Row step in pSrc.
//    height           Number of rows in pSrc.
//    pIndx            Pointer to the destination vector of closiest codevector
//                     numbers [height].
//    pDist            Pointer to the destination vector of distance to for
//                     closiest codevector [height].
//    scaleFactor
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pCdbk, pSrc, pIndx  or pDist
//                     pointer is null.
//    ippStsSizeErr    Indicates an error when step is less than or equal to 0 or
//                     is step is less than width.
//    ippStsSizeErr    Indicates an error when width, step, height is less than
//                     or equal to 0 or width is greater than step;
//
*/

IPPAPI(IppStatus, ippsVQ_16s,(const Ipp16s* pSrc, int step, Ipp32s* pIndx,
       int height, IppsCdbkState_16s* pCdbk))

IPPAPI(IppStatus, ippsVQ_32f,(const Ipp32f* pSrc, int step, Ipp32s* pIndx,
       int height, IppsCdbkState_32f* pCdbk))

IPPAPI(IppStatus, ippsVQDist_16s32s_Sfs,(const Ipp16s* pSrc, int step,
       Ipp32s* pIndx, Ipp32s* pDist, int height, IppsCdbkState_16s* pCdbk,
       int scaleFactor))

IPPAPI(IppStatus, ippsVQDist_32f,(const Ipp32f* pSrc, int step, Ipp32s* pIndx,
       Ipp32f* pDist, int height, IppsCdbkState_32f* pCdbk))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsSplitVQ_*
//  Purpose:           Quantizes a multiple-stream vector given the codebooks.
//

//  Parameters:
//    pCdbks           Pointer to the vector of pointers to codebook
//                     structure [nStream].
//    pSrc             Pointer to the source vector [height*srcStep].
//    pDst             Pointer to the destination vector [height*dstStep].
//    srcStep          Row step in pSrc.
//    dstStep          Row step in pDst.
//    dstBitStep       Row step in pDst in bits
//    height           Number of rows in pSrc.
//    nStream          Number of chunks in input vectors.
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pCdbk, pCdbk[k], pSrc or pDst
//                     pointer is null.
//    ippStsSizeErr    Indicates an error when srcStep, dstStep, height or
//                     nStream is less than or equal to 0 or chunk length sum
//                     is greater than srcStep or  nStream is greater than
//                     dstStep for functions with 16s or 8u output or number of
//                     bits to represent output indexes sequence is greater than
//                     dstStep for functions with 1u output or codebook size is
//                     greater than 256 for functions with 8u output.
//
*/

IPPAPI(IppStatus, ippsSplitVQ_16s16s,(const Ipp16s* pSrc, int srcStep, Ipp16s* pDst,
       int dstStep, int height,const IppsCdbkState_16s** pCdbks, int nStream))

IPPAPI(IppStatus, ippsSplitVQ_16s8u,(const Ipp16s* pSrc, int srcStep, Ipp8u* pDst,
       int dstStep, int height,const IppsCdbkState_16s** pCdbks, int nStream))

IPPAPI(IppStatus, ippsSplitVQ_16s1u,(const Ipp16s* pSrc, int srcStep, Ipp8u* pDst,
       int dstBitStep, int height,const IppsCdbkState_16s** pCdbks, int nStream))

IPPAPI(IppStatus, ippsSplitVQ_32f16s,(const Ipp32f* pSrc, int srcStep, Ipp16s* pDst,
       int dstStep, int height,const IppsCdbkState_32f** pCdbks, int nStream))

IPPAPI(IppStatus, ippsSplitVQ_32f8u,(const Ipp32f* pSrc, int srcStep, Ipp8u* pDst,
       int dstStep, int height,const IppsCdbkState_32f** pCdbks, int nStream))

IPPAPI(IppStatus, ippsSplitVQ_32f1u,(const Ipp32f* pSrc, int srcStep, Ipp8u* pDst,
       int dstBitStep, int height,const IppsCdbkState_32f** pCdbks, int nStream))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsFormVectorVQ_*
//  Purpose:           Constructs multiple-stream vectors from codebooks,
//                     given indexes.
//

//  Parameters:
//    pCdbks           Pointer to the vector of pointers to codebook
//                     structure [nStream].
//    pSrc             Pointer to the source vector [height*srcStep].
//    pDst             Pointer to the destination vector [height*dstStep].
//    srcStep          Row step in pSrc.
//    dstStep          Row step in pDst.
//    srcBitStep       Row step in pSrc in bits
//    height           Number of rows in pSrc.
//    nStream          Number of chunks in input vectors.
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pCdbk, pCdbk[k], pSrc or pDst
//                     pointer is null.
//    ippStsSizeErr    Indicates an error when srcStep, dstStep, height or
//                     nStream is less than or equal to 0 or codevector length
//                     sum is greater than dstStep or  nStream is greater than
//                     srcStep for functions with 16s or 8u output or number of bits
//                     to represent output indexes sequence is greater than srcStep
//                     for functions with 1u output.
//  Notes:
*/
IPPAPI(IppStatus, ippsFormVectorVQ_16s16s,(const Ipp16s* pSrc, int srcStep, Ipp16s* pDst,
       int dstStep, int height, const IppsCdbkState_16s** pCdbks, int nStream))

IPPAPI(IppStatus, ippsFormVectorVQ_8u16s,(const Ipp8u* pSrc, int srcStep, Ipp16s* pDst,
       int dstStep, int height, const IppsCdbkState_16s** pCdbks, int nStream))

IPPAPI(IppStatus, ippsFormVectorVQ_1u16s,(const Ipp8u* pSrc, int srcBitStep, Ipp16s* pDst,
       int dstStep, int height, const IppsCdbkState_16s** pCdbks, int nStream))

IPPAPI(IppStatus, ippsFormVectorVQ_16s32f,(const Ipp16s* pSrc, int srcStep, Ipp32f* pDst,
       int dstStep, int height, const IppsCdbkState_32f** pCdbks, int nStream))

IPPAPI(IppStatus, ippsFormVectorVQ_8u32f,(const Ipp8u* pSrc, int srcStep, Ipp32f* pDst,
       int dstStep, int height, const IppsCdbkState_32f** pCdbks, int nStream))

IPPAPI(IppStatus, ippsFormVectorVQ_1u32f,(const Ipp8u* pSrc, int srcBitStep, Ipp32f* pDst,
       int dstStep, int height, const IppsCdbkState_32f** pCdbks, int nStream))

/* /////////////////////////////////////////////////////////////////////////////
//  TTS Arithmetic
///////////////////////////////////////////////////////////////////////////// */
/*/////////////////////////////////////////////////////////////////////////////
//  Name:              ippsReflectionToAbsTilt_* / ippsReflectionToTilt_*
//  Purpose:           Calculates tilt for rise/fall/connection parameters.
//
//  Parameters:
//    pSrc1        Pointer to the first input vector [len].
//    pSrc2        Pointer to the second input vector [len].
//    pDst         Pointer to the destination vector [len].
//    len          Length of the input and output vectors.
//
//  Returns:
//    ippStsNoErr       Indicates no error.
//    ippStsNullPtrErr  Indicates an error when the pSrc1, pSrc2 or pDst
//                      pointer is null.
//    ippStsSizeErr     Indicates an error when len is less than or equal to 0.
//    ippStsDivByZero   Indicates a warning for zero-valued divisor vector
//                      element. Operation execution is not aborted. The value of
//                      the destination vector element in the floating-point
//                      operations:
//                         NaN For zero-valued dividend vector element.
//                         +Inf For positive dividend vector element.
//                         -Inf For negative dividend vector
//                      The value of the destination vector element in the
//                      integer operations:
//                         IPP_MAX_16S For positive dividend vector element.
//                         IPP_MIN_16S For negative dividend vector
//  Notes:
//             The function ippsReflectionToAbsTilt converts rise and fall
//             coefficients to absolute tilt.
//             The function ippsReflectionToTilt converts rise and fall
//             coefficients to tilt.
*/
IPPAPI(IppStatus, ippsReflectionToAbsTilt_16s_Sfs, (const Ipp16s* pSrc1,
       const Ipp16s* pSrc2, Ipp16s* pDst, int len, int scaleFactor))

IPPAPI(IppStatus, ippsReflectionToAbsTilt_32f, (const Ipp32f* pSrc1,
       const Ipp32f* pSrc2, Ipp32f* pDst, int len))

IPPAPI(IppStatus, ippsReflectionToTilt_16s_Sfs, (const Ipp16s* pSrc1,
       const Ipp16s* pSrc2, Ipp16s* pDst, int len, int scaleFactor))

IPPAPI(IppStatus, ippsReflectionToTilt_32f, (const Ipp32f* pSrc1,
       const Ipp32f* pSrc2, Ipp32f* pDst, int len))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsLogGaussSingle_*
//  Purpose:           Calculates the observation probability for a
//                     single Gaussian with an observation vector.
//
//  Parameters:
//    pSrc             Pointer to the input vector [len].
//    pMean            Pointer to the mean vector [len].
//    pVar             Pointer to the variance vector [len].
//    pBlockVar        Pointer to the block diagonal variance matrix.
//    len              Number of elements in the input, mean, and variance
//                     vectors.
//    pResult          Pointer to the result value.
//    val              Gaussian constant.
//    scaleFactor
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrc, pMean, pVar, or
//                     pResult or pBlockVar pointer is null.
//    ippStsSizeErr    Indicates an error when len is less than or equal to 0.
//
*/
/*  ADD  */
//Case 1: Operation for the inverse diagonal covariance matrix
IPPAPI(IppStatus, ippsLogGaussSingle_Low_16s32s_Sfs,(const Ipp16s* pSrc,
       const Ipp16s* pMean, const Ipp16s* pVar, int len, Ipp32s* pResult,
       Ipp32s val, int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussSingle_LowScaled_16s32f,(const Ipp16s* pSrc, const Ipp16s* pMean,
       const Ipp16s* pVar, int len, Ipp32f* pResult, Ipp32f val, int scaleFactor))

//Case 3: Operation for the identity covariance matrix
IPPAPI(IppStatus, ippsLogGaussSingle_IdVarLow_16s32s_Sfs,(const Ipp16s* pSrc,
       const Ipp16s* pMean, int len, Ipp32s* pResult, Ipp32s val, int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussSingle_IdVarLowScaled_16s32f,(const Ipp16s* pSrc,
       const Ipp16s* pMean, int len, Ipp32f* pResult, Ipp32f val, int scaleFactor))

// The functions use for compatibility
IPPAPI(IppStatus, ippsLogGaussSingle_Low_16s32f, (const Ipp16s* src,
       const Ipp16s* mean, const Ipp16s* var, int dim, Ipp32f* dst, Ipp32f det))

IPPAPI(IppStatus, ippsLogGaussSingle_IdVarLow_16s32f, (const Ipp16s* src,
       const Ipp16s* mean, int dim, Ipp32f* dst, Ipp32f det))

IPPAPI(IppStatus, ippsLogGauss_Low_16s32f_D2, (const Ipp16s* srcVector,
       int stride, const Ipp16s* mean, const Ipp16s* var, int dim, Ipp32f* dst,
       int length, Ipp32f  det))

IPPAPI(IppStatus, ippsLogGauss_Low_16s32f_D2L, (const Ipp16s** srcMatrix,
       const Ipp16s* mean, const Ipp16s*  var, int dim, Ipp32f*  dst,
       int length, Ipp32f  det))

IPPAPI(IppStatus, ippsLogGauss_IdVarLow_16s32f_D2, (const Ipp16s* srcVector,
       int stride, const Ipp16s* mean, int dim, Ipp32f* dst, int length,
       Ipp32f  det))

IPPAPI(IppStatus, ippsLogGauss_IdVarLow_16s32f_D2L, (const Ipp16s** srcMatrix,
       const Ipp16s* mean, int dim, Ipp32f*  dst, int length, Ipp32f  det))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsLogGauss_*
//  Purpose:           Calculates the observation probability for a single
//                     Gaussian with multiple observation vectors.
//  Parameters:
//    pSrc             Pointer to the input vector [height*step].
//    mSrc             Pointer to the input matrix [height][ width].
//    step             The row step in pSrc.
//    pMean            Pointer to the mean vector [width].
//    pVar             Pointer to the variance vector [width].
//    width            Length of the mean and variance vectors.
//    pDst             Pointer to the result value [height].
//    pSrcDst          Pointer to the input and output vector [height].
//    height           The number of rows in the input matrix and the length of
//                     the result vector pDst.
//    val              Gaussian constant.
//    scaleFactor
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrc, pMean, pVar,
//                     pDst,or mSrc pointer is null.
//    ippStsSizeErr    Indicates an error when height or width is less than or
//                     equal to 0.
//    ippStsStrideErr  Indicates an error when width > step.
//
*/
/*  ADD  */
//Case 1: Operation for the inverse diagonal covariance matrix
IPPAPI(IppStatus, ippsLogGauss_Low_16s32s_D2Sfs, (const Ipp16s* pSrc, int step,
       const Ipp16s* pMean, const Ipp16s* pVar, int width, Ipp32s* pDst,
       int height, Ipp32s val, int scaleFactor))

IPPAPI(IppStatus, ippsLogGauss_Low_16s32s_D2LSfs, (const Ipp16s** mSrc,
	   const Ipp16s* pMean, const Ipp16s* pVar, int width, Ipp32s* pDst,
	   int height, Ipp32s val, int scaleFactor))

IPPAPI(IppStatus, ippsLogGauss_LowScaled_16s32f_D2, (const Ipp16s* pSrc, int step,
       const Ipp16s* pMean, const Ipp16s* pVar, int width, Ipp32f* pDst,
       int height, Ipp32f val, int scaleFactor))

IPPAPI(IppStatus, ippsLogGauss_LowScaled_16s32f_D2L, (const Ipp16s** mSrc,
	   const Ipp16s* pMean, const Ipp16s* pVar, int width, Ipp32f* pDst,
	   int height, Ipp32f val, int scaleFactor))

//Case 2: Operation for the identity covariance matrix

IPPAPI(IppStatus, ippsLogGauss_IdVarLow_16s32s_D2Sfs,(const Ipp16s* pSrc,
	   int step, const Ipp16s* pMean, int width, Ipp32s* pDst, int height,
	   Ipp32s val,int scaleFactor))

IPPAPI(IppStatus, ippsLogGauss_IdVarLowScaled_16s32f_D2,(const Ipp16s* pSrc,
	   int step, const Ipp16s* pMean, int width, Ipp32f* pDst, int height,
	   Ipp32f val,int scaleFactor))

IPPAPI(IppStatus, ippsLogGauss_IdVarLow_16s32s_D2LSfs,(const Ipp16s** mSrc,
	   const Ipp16s* pMean, int width, Ipp32s* pDst, int height, Ipp32s val,
	   int scaleFactor))

IPPAPI(IppStatus, ippsLogGauss_IdVarLowScaled_16s32f_D2L,(const Ipp16s** mSrc,
	   const Ipp16s* pMean, int width, Ipp32f* pDst, int height, Ipp32f val,
	   int scaleFactor))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsLogGaussMultiMix_*
//  Purpose:           Calculates the observation probability for
//                     multiple Gaussian mixture components.
//
//  Parameters:
//    pMean            Pointer to the variance vector [height*step].
//    mMean            Pointer to the mean matrix [height][width].
//    mVar             Pointer to the variance matrix [height][width].
//    pSrcDst          Pointer to the input additive values and
//                     the result vector [height].
//    step             The row step in pMean.
//    pSrc             Pointer to the input vector [width].
//    height           The number of rows in input matrices and the length of
//                     the result vector pSrcDst.
//    width            The length of the input matrices row and the vector pSrc.
//    scaleFactor
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrc, pMean, pVar,
//                     pSrcDst, mMean, or mVar pointer is null.
//    ippStsSizeErr    Indicates an error when heightor width is less than or
//                     equal to 0.
//    ippStsStrideErr  Indicates an error when width > step.
//
*/
/*  ADD  */
IPPAPI(IppStatus, ippsLogGaussMultiMix_Low_16s32s_D2Sfs, (const Ipp16s* pMean,
	   const Ipp16s* pVar, int step, const Ipp16s* pSrc, int width,
	   Ipp32s* pSrcDst, int height, int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussMultiMix_Low_16s32s_D2LSfs, (const Ipp16s** mMean,
	   const Ipp16s** mVar, const Ipp16s* pSrc, int width, Ipp32s* pSrcDst,
	   int height, int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussMultiMix_LowScaled_16s32f_D2, (const Ipp16s* pMean,
	   const Ipp16s* pVar, int step, const Ipp16s* pSrc, int width,
	   Ipp32f* pSrcDst, int height, int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussMultiMix_LowScaled_16s32f_D2L, (const Ipp16s** mMean,
	   const Ipp16s** mVar, const Ipp16s* pSrc, int width, Ipp32f* pSrcDst,
	   int height, int scaleFactor))

// The functions use for compatibility
IPPAPI(IppStatus, ippsLogGaussMultiMix_Low_16s32f_D2,(const Ipp16s* pMean,
       const Ipp16s* pVar, int step, const Ipp16s* pSrc, int width,
       Ipp32f* pSrcDst, int height))

IPPAPI(IppStatus, ippsLogGaussMultiMix_Low_16s32f_D2L, (const Ipp16s** mMean,
       const Ipp16s** mVar, const Ipp16s* pSrc, int width, Ipp32f* pSrcDst,
       int height))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsLogGaussMax_*_D2
//  Purpose:           Computes maximum  value of a vector dst and
//                     logarithms of the Gaussian probability distribution function.
//  Parameters:
//    pSrc             Pointer to the input vector [height*step].
//    step             The row step in pSrc.
//    pMean            Pointer to the mean vector [width].
//    pVar             Pointer to the variance vector [width].
//    width            The length of the input matrix row, mean,
//                     and variance vectors.
//    pSrcDst          Pointer to the input and output vector [height].
//    height           The number of rows in the input matrix and the length of
//                     the result vector pDst.
//    val              The value to add to each distance.
//    scaleFactor
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrc, pMean, pVar,
//                     pSrcDst pointer is null.
//    ippStsSizeErr    Indicates an error when height or width is less than or
//                     equal to 0.
//    ippStsStrideErr  Indicates an error when width > step.
//
*/
/*  ADD  */
//Case 1: Operation for the inverse diagonal covariance matrix
IPPAPI(IppStatus, ippsLogGaussMax_Low_16s32s_D2Sfs, (const Ipp16s* pSrc,
       int step, const Ipp16s* pMean, const Ipp16s* pVar, int width,
       Ipp32s* pSrcDst, int height, Ipp32s val, int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussMax_Low_16s32s_D2LSfs, (const Ipp16s** mSrc,
	   const Ipp16s* pMean, const Ipp16s*  pVar, int width, Ipp32s* pDst,
                  int height, Ipp32s  val, int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussMax_LowScaled_16s32f_D2, (const Ipp16s* pSrc, int step,
       const Ipp16s* pMean, const Ipp16s* pVar, int width,
       Ipp32f* pSrcDst, int height, Ipp32f val, int scaleFacto))

IPPAPI(IppStatus, ippsLogGaussMax_LowScaled_16s32f_D2L, (const Ipp16s** mSrc,
	   const Ipp16s* pMean, const Ipp16s*  pVar, int width, Ipp32f* pDst,
      int height, Ipp32f  val, int scaleFacto))

//Case 2: Operation for the identity covariance matrix
IPPAPI(IppStatus, ippsLogGaussMax_IdVarLow_16s32s_D2Sfs, (const Ipp16s* pSrc,
	   int step, const Ipp16s* pMean, int width, Ipp32s* pSrcDst,
	   int height, Ipp32s val, int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussMax_IdVarLow_16s32s_D2LSfs, (const Ipp16s** mSrc,
	   const Ipp16s* pMean, int width, Ipp32s* pSrcDst, int height,
	   Ipp32s val, int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussMax_IdVarLowScaled_16s32f_D2, (const Ipp16s* pSrc,
	   int step, const Ipp16s* pMean, int width, Ipp32f* pSrcDst,
	   int height, Ipp32f val, int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussMax_IdVarLowScaled_16s32f_D2L, (const Ipp16s** mSrc,
	   const Ipp16s* pMean, int width, Ipp32f* pSrcDst, int height,
	   Ipp32f val, int scaleFactor))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsLogGaussMaxMultiMix_*_*
//  Purpose:           Computes the maximum of the Gaussian probability
//                     distribution function.
//  Parameters:
//    pMean            Pointer to the mean vector of length [height*step].
//    pVar             Pointer to the variance vector of length [height*step].
//    mMean            Pointer to the mean matrix of size [height][width].
//    mVar             Pointer to the mean matrix of size [height][width].
//    pVal             Pointer to the input vector of Maxitive values [height].
//    pSrcDst          Pointer to the input and output vector of length [height].
//    step             Row step in pMean and pVar.
//    pSrc             Pointer to theinput vector of length[width].
//    height           Number of rows in input matrices and the length of
//                     the result vector pSrcDst.
//    width            Length of the input matrices row and the vector pSrc.
//    scaleFactor
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrc, pMean, pVar,
//                     pSrcDst or mMean or mVar or pVal pointer is null.
//    ippStsSizeErr    Indicates an error when height or width is less than or
//                     equal to 0.
//    ippStsStrideErr  Indicates an error when width > step.
//
*/
/*  ADD  */
IPPAPI(IppStatus, ippsLogGaussMaxMultiMix_LowScaled_16s32f_D2, (const Ipp16s* pMean,
	   const Ipp16s* pVar, int step, const Ipp16s* pSrc,int width,
	   const Ipp32f* pVal, Ipp32f* pSrcDst,int height, int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussMaxMultiMix_LowScaled_16s32f_D2L, (const Ipp16s** mMean,
	   const Ipp16s** mVar, const Ipp16s* pSrc, int width, const Ipp32f* pVal,
	   Ipp32f* pSrcDst,int height, int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussMaxMultiMix_Low_16s32s_D2Sfs, (const Ipp16s* pMean,
	   const Ipp16s* pVar, int step, const Ipp16s* pSrc, int width,
	   const Ipp32s* pVal, Ipp32s* pSrcDst,int height, int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussMaxMultiMix_Low_16s32s_D2LSfs, (const Ipp16s** mMean,
	   const Ipp16s** mVar, const Ipp16s* pSrc, int width, const Ipp32s* pVal,
	   Ipp32s* pSrcDst,int height, int scaleFactor))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsLogGaussAdd_32f_D2
//  Purpose:           Calculates the likelihood probability for multiple
//                     observation vectors.
//
//  Parameters:
//    pSrc             Pointer to the first input vector of length [width*height]
//    step             Row step in pSrc.
//    pMean            Pointer to the mean vector of length [width]
//    pVar             Pointer to the variance vector of length [width]
//    width            Length of the mean, and variance vectors.
//    pSrcDst          Pointer to input vector and output vector [height]
//    height           Length of  the input and output vector pSrcDst
//    val              Value to add to each distance.
//
//  Returns:
//    ippStsNoErr      Indicates no error
//    ippStsNullPtrErr Indicates an error when the pSrc, pMean,pVar,
//                     pSrcDst pointer is null.
//    ippStsSizeErr    Indicates an error when width or height
//                     is less than or equal to 0.
//    ippStsStrideErr  Indicates an error when width > step.
*/
/*  ADD  */
//Case 1: Operation for the inverse diagonal covariance matrix
IPPAPI(IppStatus, ippsLogGaussAdd_LowScaled_16s32f_D2,(const Ipp16s* pSrc, int step,
       const Ipp16s* pMean, const Ipp16s* pVar, int width,
       Ipp32f* pSrcDst, int height, Ipp32f val, int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussAdd_LowScaled_16s32f_D2L, (const Ipp16s** mSrc,
	   const Ipp16s* pMean, const Ipp16s* pVar, int width, Ipp32f* pSrcDst,
	   int height, Ipp32f val, int scaleFactor))

//Case 2: Operation for the identity covariance matrix
IPPAPI(IppStatus, ippsLogGaussAdd_IdVarLowScaled_16s32f_D2,(const Ipp16s* pSrc,
	   int step, const Ipp16s* pMean, int width, Ipp32f* pSrcDst,
	   int height, Ipp32f val, int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussAdd_IdVarLowScaled_16s32f_D2L,(const Ipp16s** mSrc,
	   const Ipp16s* pMean, int width, Ipp32f* pSrcDst, int height, Ipp32f val,
	   int scaleFactor))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsLogGaussAddMultiMix_*_*
//  Purpose:           Calculates the likelihood probability for multiple
//                     Gaussian mixture components.
//
//  Parameters:
//    pMean            Pointer to the variance vector [height*step].
//    mMean            Pointer to the mean matrix [height][width].
//    pVal		       Pointer to the input vector of additive values [height].
//    mVar             Pointer to the variance matrix [height][width].
//    pSrcDst          Pointer to the input and output vector of length [height].
//    step             The row step in pMean.
//    pSrc             Pointer to the input vector [width].
//    height           The number of rows in input matrices and the length of
//                     the result vector pSrcDst.
//    width            The length of the input matrices row and the vector pSrc.
//    scaleFactor
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrc, pMean, pVar,
//                     pSrcDst, mMean, or mVar pointer is null.
//    ippStsSizeErr    Indicates an error when heightor width is less than or
//                     equal to 0.
//    ippStsStrideErr  Indicates an error when width > step.
//
*/
/*  ADD  */
IPPAPI(IppStatus, ippsLogGaussAddMultiMix_LowScaled_16s32f_D2, (const Ipp16s* pMean,
	   const Ipp16s* pVar, int step, const Ipp16s* pSrc, int width,
	    const Ipp32f* pVal, Ipp32f* pSrcDst, int height, int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussAddMultiMix_LowScaled_16s32f_D2L, (const Ipp16s** mMean,
	   const Ipp16s** mVar, const Ipp16s* pSrc, int width, const Ipp32f* pVal,
       Ipp32f* pSrcDst, int height, int scaleFactor))


/* /////////////////////////////////////////////////////////////////////////////
//  Name:              LogGaussMixture_*
//  Purpose:           Calculates the likelihood probability for the Gaussian mixture
//
//  Parameters:
//    pMean            Pointer to the variance vector [height*step].
//    mMean            Pointer to the mean matrix [height][width].
//    pVar             Pointer to the variance vector [height*step].
//    mVar             Pointer to the variance matrix [height][width].
//    pVal             Pointer to the weight constant vector [height]..
//    pSrc             Pointer to the input vector [width].
//    pResult          Pointer to the output mixture value.
//    step             The row step in pMean and pVar.
//    height           Number of Gaussian mixture components.
//    width            Length of the mean and variance matrices rows and pSrc vector.
//    scaleFactor
//
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the mMean, mVar, pMean, pVar, pVal or
//                     pResult pointer is null.
//    ippStsSizeErr    Indicates an error when height, step or width is less than or
//                     equal to 0.
//    ippStsStrideErr  Indicates an error when width > step.
//
*/
//Case 1: Operation for the inverse diagonal covariance matrix
IPPAPI(IppStatus, ippsLogGaussMixture_Scaled_16s32f_D2,(const Ipp16s* pSrc, const Ipp16s* pMean,
       const Ipp16s* pVar, int height, int step, int width, const Ipp32f* pVal,
       Ipp32f* pResult, int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussMixture_Scaled_16s32f_D2L,(const Ipp16s* pSrc, const Ipp16s** mMean,
       const Ipp16s** mVar, int height, int width, const Ipp32f* pVal, Ipp32f* pResult,
       int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussMixture_LowScaled_16s32f_D2,(const Ipp16s* pSrc,
       const Ipp16s* pMean, const Ipp16s* pVar, int height, int step, int width,
       const Ipp32f* pVal, Ipp32f* pResult, int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussMixture_LowScaled_16s32f_D2L,(const Ipp16s* pSrc,
       const Ipp16s** mMean, const Ipp16s** mVar, int height, int width,
       const Ipp32f* pVal, Ipp32f* pResult, int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussMixture_32f_D2,(const Ipp32f* pSrc, const Ipp32f* pMean,
       const Ipp32f* pVar, int height, int step, int width, const Ipp32f* pVal,
       Ipp32f* pResult))

IPPAPI(IppStatus, ippsLogGaussMixture_32f_D2L,(const Ipp32f* pSrc, const Ipp32f** mMean,
       const Ipp32f** mVar, int height, int width, const Ipp32f* pVal, Ipp32f* pResult))

IPPAPI(IppStatus, ippsLogGaussMixture_64f_D2,(const Ipp64f* pSrc, const Ipp64f* pMean,
       const Ipp64f* pVar, int height, int step, int width, const Ipp64f* pVal,
       Ipp64f* pResult))

IPPAPI(IppStatus, ippsLogGaussMixture_64f_D2L,(const Ipp64f* pSrc, const Ipp64f** mMean,
       const Ipp64f** mVar, int height, int width, const Ipp64f* pVal, Ipp64f* pResult))

//Case 2: Operation for the identity covariance matrix
IPPAPI(IppStatus, ippsLogGaussMixture_IdVarScaled_16s32f_D2,(const Ipp16s* pSrc,
       const Ipp16s* pMean, int height, int step, int width, const Ipp32f* pVal,
       Ipp32f* pResult, int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussMixture_IdVarScaled_16s32f_D2L,(const Ipp16s* pSrc,
       const Ipp16s** mMean, int height, int width, const Ipp32f* pVal,
       Ipp32f* pResult, int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussMixture_IdVarLowScaled_16s32f_D2,(const Ipp16s* pSrc,
       const Ipp16s* pMean, int height, int step, int width, const Ipp32f* pVal,
       Ipp32f* pResult, int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussMixture_IdVarLowScaled_16s32f_D2L,(const Ipp16s* pSrc,
       const Ipp16s** mMean, int height, int width, const Ipp32f* pVal,
       Ipp32f* pResult, int scaleFactor))

IPPAPI(IppStatus, ippsLogGaussMixture_IdVar_32f_D2,(const Ipp32f* pSrc,
       const Ipp32f* pMean, int height, int step, int width, const Ipp32f* pVal,
       Ipp32f* pResult))

IPPAPI(IppStatus, ippsLogGaussMixture_IdVar_32f_D2L,(const Ipp32f* pSrc,
       const Ipp32f** mMean, int height, int width, const Ipp32f* pVal,
       Ipp32f* pResult))

IPPAPI(IppStatus, ippsLogGaussMixture_IdVar_64f_D2,(const Ipp64f* pSrc,
       const Ipp64f* pMean, int height, int step, int width, const Ipp64f* pVal,
       Ipp64f* pResult))

IPPAPI(IppStatus, ippsLogGaussMixture_IdVar_64f_D2L,(const Ipp64f* pSrc,
       const Ipp64f** mMean, int height, int width, const Ipp64f* pVal,
       Ipp64f* pResult))

/* /////////////////////////////////////////////////////////////////////////////
//  Name:              ippsLogSum_*
//  Purpose:           Logarithmically sums vector elements.
//  Parameters:
//    pSrc             The first input vector [len].
//    pResult          Pointer to the result value.
//    len              The number of elements in the input and output vectors.
//    hint             Recommends to use a specific code for the
                       Logarithmically Sums.
//  Return:
//    ippStsNoErr      Indicates no error.
//    ippStsNullPtrErr Indicates an error when the pSrc or pResult pointer is null.
//    ippStsSizeErr    Indicates an error when len is less than or equal to 0.
//
*/
IPPAPI(IppStatus,ippsLogSum_64f,(const Ipp64f* pSrc, Ipp64f* pResult, int len,
                                 IppHintAlgorithm hint))

IPPAPI(IppStatus,ippsLogSum_32f,(const Ipp32f* pSrc, Ipp32f* pResult, int len,
                                 IppHintAlgorithm hint))


/*F*
  Name:           ippsWeightedMeanColumn_*_*
  Purpose:        Computes the weighted mean values for the column elements.
  Returns:
                  ippStsNoErr		Indicates no error.
                  ippStsNullPtrErr	Indicates an error when pSrc, mSrc, pWgt, or pDstMean pointer is null.
                  ippStsSizeErr		Indicates an error when height or width is less than or equal to 0.
                  IppStsStrideErr		Indicates an error when step is less than width.
  Parameters:
      pSrc		  Pointer to the input vector [height*step].
      mSrc		  Pointer to the input matrix [height][width].
      pWgt		  Pointer to the weights vector [height].
      height	  Number of rows in the input matrix.
      step		  Row step in the input vector (measured in pSrc elements).
      pDstMean	  Pointer to the output mean vector [width].
      width	      Number of columns in the input matrix, and also the length of the output mean vector pDstMean.
  Notes:
*F*/


IPPAPI(IppStatus, ippsWeightedMeanColumn_32f_D2,(const Ipp32f* pSrc, int step,
       const Ipp32f* pWgt, int height, Ipp32f* pDstMean, int width))
IPPAPI(IppStatus, ippsWeightedMeanColumn_32f_D2L,(const Ipp32f** mSrc,
       const Ipp32f* pWgt, int height, Ipp32f* pDstMean, int width))
IPPAPI(IppStatus, ippsWeightedMeanColumn_64f_D2,(const Ipp64f* pSrc, int step,
       const Ipp64f* pWgt, int height, Ipp64f* pDstMean, int width))
IPPAPI(IppStatus, ippsWeightedMeanColumn_64f_D2L,(const Ipp64f** mSrc,
       const Ipp64f* pWgt, int height, Ipp64f* pDstMean, int width))


/*F*
  Name:           ippsWeightedVarColumn_*_*
  Purpose:        Computes the weighted variances values for the column elements.
  Returns:
      ippStsNoErr		Indicates no error.
      ippStsNullPtrErr	Indicates an error when pSrc, mSrc, pWgt, pSrcMean,
                            or pDstVar pointer is null.
      ippStsSizeErr		Indicates an error when height or width is less than
                            or equal to 0.
      ippStsStrideErr	Indicates an error when step is less than width.
  Parameters:
      pSrc		  Pointer to the input vector [height*step].
      mSrc		  Pointer to the input matrix [height][width].
      pWgt		  Pointer to the weights vector [height].
      height	  Number of rows in the input matrix.
      step		  Row step in the input vector (measured in pSrc elements).
      pSrcMean	  Pointer to the input mean vector [width].
      pDstVar	  Pointer to the output variance vector [width].
      width	      Number of columns in the input matrix, and also the length of the input mean vector pSrcMean and the output variance vector pDstVar.
  Notes:
*F*/


IPPAPI(IppStatus, ippsWeightedVarColumn_32f_D2,(const Ipp32f* pSrc, int step,
             const Ipp32f* pWgt, int height, const Ipp32f* pSrcMean,
             Ipp32f* pDstVar, int width))
IPPAPI(IppStatus, ippsWeightedVarColumn_32f_D2L,(const Ipp32f** mSrc,
             const Ipp32f* pWgt, int height, const Ipp32f* pSrcMean,
             Ipp32f* pDstVar, int width))
IPPAPI(IppStatus, ippsWeightedVarColumn_64f_D2,(const Ipp64f* pSrc, int step,
             const Ipp64f* pWgt, int height, const Ipp64f* pSrcMean,
             Ipp64f* pDstVar, int width))
IPPAPI(IppStatus, ippsWeightedVarColumn_64f_D2L,(const Ipp64f** mSrc,
              const Ipp64f* pWgt, int height, const Ipp64f* pSrcMean,
              Ipp64f* pDstVar,int width))



/*F*
  Name:           ippsWeightedMeanVarColumn_*_*
  Purpose:        Computes the weighted mean  variances values for the column elements.
  Returns:
      ippStsNoErr		Indicates no error.
      ippStsNullPtrErr	Indicates an error when pSrc, mSrc, pWgt, pDstMean,
                        or pDstVar pointer is null.
      ippStsSizeErr		Indicates an error when height or width is less than
                        or equal to 0.
      ippStsStrideErr	Indicates an error when step is less than width.
  Parameters:
      pSrc		  Pointer to the input vector [height*step].
      mSrc		  Pointer to the input matrix [height][width].
      pWgt		  Pointer to the weights vector [height].
      height	  Number of rows in the input matrix.
      step		  Row step in the input vector (measured in pSrc elements).
      pDstMean	  Pointer to the output mean vector [width].
      pDstVar	  Pointer to the output variance vector [width].
      width	      Number of columns in the input matrix, and also the length of the output mean vector pSrcMean and the output variance vector pDstVar.
 Notes:
*F*/


IPPAPI(IppStatus, ippsWeightedMeanVarColumn_32f_D2,(const Ipp32f* pSrc, int step,
       const Ipp32f* pWgt, int height, Ipp32f* pDstMean, Ipp32f* pDstVar, int width))
IPPAPI(IppStatus, ippsWeightedMeanVarColumn_32f_D2L,(const Ipp32f** mSrc,
       const Ipp32f* pWgt, int height, Ipp32f* pDstMean, Ipp32f* pDstVar, int width))
IPPAPI(IppStatus, ippsWeightedMeanVarColumn_64f_D2,(const Ipp64f* pSrc, int step,
       const Ipp64f* pWgt, int height, Ipp64f* pDstMean, Ipp64f* pDstVar, int width))
IPPAPI(IppStatus, ippsWeightedMeanVarColumn_64f_D2L,(const Ipp64f** mSrc,
       const Ipp64f* pWgt, int height, Ipp64f* pDstMean, Ipp64f* pDstVar, int width))



/*F*
  Name:           ippsCrossCorrCoeffDecim
  Purpose:        Calculate vector of cross correlation coefficients with decimation.
  Returns:
      ippStsNoErr		Indicates no error.
      ippStsNullPtrErr	Indicates an error when the pSrc1, pSrc2, or pDst pointer is null.
      ippStsSizeErr		Indicates an error when len is less than or equal to 0.
      ippStsBadArgErr	Indicates an error when val is less than 0.
  Parameters:
      pSrc1		  Pointer to the first input vector [maxLen].
      pSrc2		  Pointer to the second input vector [maxLen].
      pDst		  Pointer to the output vector [(maxLen-minLen+dec-1)/dec].
      maxLen	  Maximal length of cross correlation.
      minLen	  Minimal length of cross correlation.
      dec		  Decimation step.
  Notes:
*F*/
IPPAPI(IppStatus, ippsCrossCorrCoeffDecim_16s32f,(const Ipp16s* pSrc1,
            const Ipp16s* pSrc2, int maxLen, int minLen, Ipp32f* pDst, int dec))

/*F*
  Name:           ippsCrossCorrCoeff
  Purpose:        Calculate cross correlation coefficient.
  Context:
  Returns:
      ippStsNoErr		Indicates no error.
      ippStsNullPtrErr	Indicates an error when the pSrc1, pSrc2, or pResult pointer is null.
      ippStsSizeErr		Indicates an error when len is less than or equal to 0.
      ippStsBadArgErr	Indicates an error when val is less than 0.
  Parameters:
      pSrc1		  Pointer to the first input vector [len].
      pSrc2		  Pointer to the second input vector [len].
      len		  Length of the input vectors.
      pResult	  Pointer to the result cross correlation coefficient value.
      val		  First vector length value.
  Notes:
*F*/

IPPAPI(IppStatus, ippsCrossCorrCoeff_16s32f,(const Ipp16s* pSrc1,
                  const Ipp16s* pSrc2, int len, Ipp32f* pResult))
IPPAPI(IppStatus, ippsCrossCorrCoeffPartial_16s32f,(const Ipp16s* pSrc1,
                   const Ipp16s* pSrc2, int len, Ipp32f val, Ipp32f* pResult))

/*F*
  Name:           ippsCrossCorrCoeffInterpolation
  Purpose:        Calculate cross correlation coefficient.
  Context:
  Returns:
      ippStsNoErr		Indicates no error.
      ippStsNullPtrErr	Indicates an error when the pSrc1, pSrc2, pBeta or pResult pointer is null.
      ippStsSizeErr		Indicates an error when len is less than or equal to 0.
      ippStsStrideErr	Indicates an error when srcStep or dstStep is less than width.
 Parameters:
      pSrc1		  Pointer to the first input vector [len].
      pSrc2		  Pointer to the second input vector [len+1].
      len		  Length of the input vectors.
      pResult	  Pointer to the result cross correlation coefficient value.
      pBeta		  Pointer to the result value of fractional part of the pitch period.
  Notes:
*F*/

IPPAPI(IppStatus, ippsCrossCorrCoeffInterpolation_16s32f,(const Ipp16s* pSrc1,
                  const Ipp16s* pSrc2, int len, Ipp32f* pBeta, Ipp32f* pResult))


/*======== End of declaration of functions ===================================*/

#ifdef __cplusplus
}
#endif

#endif /* __IPPSR_H__ */
/* ////////////////////////// End of file "ippsr.h" ///////////////////////// */
