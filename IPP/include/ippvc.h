/* ////////////////////////////////// "ippvc.h" ////////////////////////////////
//
//                  INTEL CORPORATION PROPRIETARY INFORMATION
//     This software is supplied under the terms of a license agreement or
//     nondisclosure agreement with Intel Corporation and may not be copied
//     or disclosed except in accordance with the terms of that agreement.
//          Copyright(c) 2001-2003 Intel Corporation. All Rights Reserved.
//
//             	Intel(R) Integrated Performance Primitives
//                  Video Coding (ippvc)
//
*/

#if !defined( __IPPVC_H__ ) || defined( _OWN_BLDPCS )
#define __IPPVC_H__

#ifndef __IPPDEFS_H__
#include "ippdefs.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////Structures and definitions///////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

#if !defined( _OWN_BLDPCS )
/* flags for motion compensation */

#define IPPVC_VLC_FORBIDDEN			  0xf0f1
#define IPPVC_ESCAPE				  0x00ff
#define IPPVC_ENDOFBLOCK			  0x00fe
#define IPPVC_FRAME_PICTURE			  0x0003

typedef enum _IPPVC_ESCAPE_FLAG
{
	 IPPVC_EF_NONE				= 	0x0,
	 IPPVC_EF_REVERSIBLE_VLC	= 	0x1,
	 IPPVC_EF_SHORT_HEADER		=	0x2,

} IPPVC_ESCAPE_FLAG;



typedef enum _IPPVC_MC_APX
{
	 IPPVC_MC_APX_FF = 	0x0,
	 IPPVC_MC_APX_FH =	0x4,
	 IPPVC_MC_APX_HF =	0x8,
	 IPPVC_MC_APX_HH =	0x0c

}IPPVC_MC_APX;



typedef enum _IPPVC_MV_TYPE
{
	 IPPVC_MV_FIELD	=	0x0,
	 IPPVC_MV_FRAME	=	0x1

} IPPVC_MV_TYPE;


typedef struct _IppVCHuffmanSpec_32u // VL code longer than 8 bits
{
	Ipp32u code; // right justified
	Ipp32u len;
} IppVCHuffmanSpec_32u;

typedef long IppVCHuffmanSpec_32s ;

#endif

/* ///////////////////////////////////////////////////////////////////////////////////////
//  Name:       ippvcGetLibVersion
//  Purpose:    getting of the library version
//  Returns:    the structure of information about  version of ippvc library
//  Parameters:
//
//  Notes:      not necessary to release the returned structure
*/
IPPAPI( const IppLibraryVersion*, ippvcGetLibVersion, (void) )

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////Huffman functions/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* Huffman decode table */


IPPAPI(IppStatus, ippiVCHuffmanInitAlloc_32s,	(const Ipp32s* pSrcTable, IppVCHuffmanSpec_32s** pDstSpec))

IPPAPI(IppStatus, ippiVCHuffmanDecodeOne_1u32s,	(Ipp32u** pBitStream, int* pOffset,Ipp32s* pDst,const IppVCHuffmanSpec_32s *pDecodeTable))

IPPAPI(IppStatus, ippiVCHuffmanInitAllocRL_32s,	(const Ipp32s* pSrcTable, IppVCHuffmanSpec_32s** pDstSpec))

IPPAPI(IppStatus, ippiReconstructDCTBlockIntra_MPEG1_32s,	(Ipp32u						**pBitStream,
																 int						*pOffset,
																 const long					*pDCSizeTable,
																 const long					*pACTable,
																 int*						scanMatrix,
																 short						quant,
																 Ipp16s						*pQuantMatrix,
																 short						*dct_dc_past,
																 Ipp16s						*pDstBlock,
																 int						*pDstSize
																 ))
IPPAPI(IppStatus, ippiReconstructDCTBlock_MPEG1_32s,	(Ipp32u						**pBitStream,
															 int						*pOffset,
															 const long					*pDCSizeTable,
															 const long					*pACTable,
															 int*						scanMatrix,
															 short						quant,
															 Ipp16s						*pQuantMatrix,
															 Ipp16s						*pDstBlock,
															 int						*pDstSize))


IPPAPI(IppStatus, ippiReconstructDCTBlock_MPEG2_32s,		(Ipp32u						**pBitStream,
															 int						*pOffset,
															 const IppVCHuffmanSpec_32s	*pDCTable,
															 const IppVCHuffmanSpec_32s	*pACTable,
															 int						*scanMatrix,
															 short						quant,
															 short						*pQuantMatrix,
															 short						*pDstBlock,
															 int						*pDstSize
															 ))
IPPAPI(IppStatus, ippiReconstructDCTBlockIntra_MPEG2_32s,	(Ipp32u						**pBitStream,
															 int						*pOffset,
															 const IppVCHuffmanSpec_32s *pDCSizeTable,
															 const IppVCHuffmanSpec_32s *pACTable,
															 int						*scanMatrix,
															 short						quant,
															 short						*pQuantMatrix,
															 short						*dct_dc_past,
															 int						intra_dc_shift,
															 short						*pDstBlock,
															 int						*pDstSize
															 ))


IPPAPI(IppStatus, ippiVCHuffmanFree_32s, (IppVCHuffmanSpec_32s **pDecodeTable))

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////Dequantization for block/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

IPPAPI(IppStatus, ippiQuantInvIntra_MPEG2_16s_C1I	,(Ipp16s *pDctCoeff, int quant, Ipp16s *pQuantMatrix))
IPPAPI(IppStatus, ippiQuantInv_MPEG2_16s_C1I		,(Ipp16s *pDctCoeff, int quant, Ipp16s *pQuantMatrix))

IPPAPI(IppStatus, ippiQuantInvIntra_MPEG4_16s_C1I	,(Ipp16s *pDctCoeff, int quant, Ipp16s *pQuantMatrix))
IPPAPI(IppStatus, ippiQuantInv_MPEG4_16s_C1I		,(Ipp16s *pDctCoeff, int quant, Ipp16s *pQuantMatrix))

IPPAPI(IppStatus, ippiQuantInvIntra_H263_C1I		,(Ipp16s *pDctCoeff, int quant))
IPPAPI(IppStatus, ippiQuantInv_H263_C1I				,(Ipp16s *pDctCoeff, int quant))


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////// Motion compensation for macroblock /////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
IPPAPI(IppStatus, ippiMC16x4B_8u_C1, ( const Ipp8u  *pSrcRefF,
									  Ipp32s        srcStepF,
									  Ipp32s	    mcTypeF,
									  const Ipp8u  *pSrcRefB,
									  Ipp32s        srcStepB,
									  Ipp32s	    mcTypeB,
									  const Ipp16s *pSrcYData,
									  Ipp32s        srcYDataStep,
									  Ipp8u        *pDst,
									  Ipp32s        dstStep,
									  Ipp32s	    roundControl))
IPPAPI(IppStatus, ippiMC16x4_8u_C1,	(const Ipp8u  *pSrcRef,
									 Ipp32s        srcStep,
									 const Ipp16s *pSrcYData,
									 Ipp32s        srcYDataStep,
									 Ipp8u        *pDst,
									 Ipp32s        dstStep,
									 Ipp32s		   mcType,
									 Ipp32s		   roundControl
									))


IPPAPI(IppStatus, ippiMC16x16_8u_C1, (const Ipp8u  *pSrcRef,
									  Ipp32s        srcStep,
									  const Ipp16s *pSrcYData,
									  Ipp32s        srcYDataStep,
									  Ipp8u        *pDst,
									  Ipp32s        dstStep,
									  Ipp32s	    mcType,
									  IppRoundMode  roundControl))


IPPAPI(IppStatus, ippiMC16x16B_8u_C1,(const Ipp8u  *pSrcRefF,
									  Ipp32s        srcStepF,
									  Ipp32s	    mcTypeF,
									  const Ipp8u  *pSrcRefB,
									  Ipp32s        srcStepB,
									  Ipp32s	    mcTypeB,
									  const Ipp16s *pSrcYData,
									  Ipp32s        srcYDataStep,
									  Ipp8u        *pDst,
									  Ipp32s        dstStep,
									  IppRoundMode  roundControl))

IPPAPI(IppStatus, ippiMC16x8_8u_C1,  (const Ipp8u  *pSrcRef,
									  Ipp32s        srcStep,
									  const Ipp16s *pSrcYData,
									  Ipp32s        srcYDataStep,
									  Ipp8u        *pDst,
									  Ipp32s        dstStep,
									  Ipp32s	    mcType,
									  IppRoundMode  roundControl))

IPPAPI(IppStatus, ippiMC16x8B_8u_C1, (const Ipp8u  *pSrcRefF,
									  Ipp32s        srcStepF,
									  Ipp32s	    mcTypeF,
									  const Ipp8u  *pSrcRefB,
									  Ipp32s        srcStepB,
									  Ipp32s	    mcTypeB,
									  const Ipp16s *pSrcYData,
									  Ipp32s        srcYDataStep,
									  Ipp8u        *pDst,
									  Ipp32s        dstStep,
									  IppRoundMode  roundControl))
IPPAPI(IppStatus, ippiMC16x8UV_8u_C1,(const Ipp8u  *pSrcRef,
									  Ipp32s        srcStep,
									  const Ipp16s *pSrcYData,
									  Ipp32s        srcYDataStep,
									  Ipp8u        *pDst,
									  Ipp32s        dstStep,
									  Ipp32s	    mcType,
									  IppRoundMode  roundControl))

IPPAPI(IppStatus, ippiMC16x8BUV_8u_C1,(const Ipp8u  *pSrcRefF,
									  Ipp32s        srcStepF,
									  Ipp32s	    mcTypeF,
									  const Ipp8u  *pSrcRefB,
									  Ipp32s        srcStepB,
									  Ipp32s	    mcTypeB,
									  const Ipp16s *pSrcYData,
									  Ipp32s        srcYDataStep,
									  Ipp8u        *pDst,
									  Ipp32s        dstStep,
									  IppRoundMode  roundControl))

IPPAPI(IppStatus, ippiMC8x16_8u_C1,  (const Ipp8u  *pSrcRef,
									  Ipp32s        srcStep,
									  const Ipp16s *pSrcYData,
									  Ipp32s        srcYDataStep,
									  Ipp8u        *pDst,
									  Ipp32s        dstStep,
									  Ipp32s	    mcType,
									  IppRoundMode  roundControl))

IPPAPI(IppStatus, ippiMC8x16B_8u_C1, (const Ipp8u  *pSrcRefF,
									  Ipp32s        srcStepF,
									  Ipp32s	    mcTypeF,
									  const Ipp8u  *pSrcRefB,
									  Ipp32s        srcStepB,
									  Ipp32s	    mcTypeB,
									  const Ipp16s *pSrcYData,
									  Ipp32s        srcYDataStep,
									  Ipp8u        *pDst,
									  Ipp32s        dstStep,
									  IppRoundMode  roundControl))

IPPAPI(IppStatus, ippiMC8x8_8u_C1, (const Ipp8u  *pSrcRef,
									Ipp32s        srcStep,
									const Ipp16s *pSrcYData,
									Ipp32s        srcYDataStep,
									Ipp8u        *pDst,
									Ipp32s        dstStep,
									Ipp32s        mcType,
									IppRoundMode  roundControl))

IPPAPI(IppStatus, ippiMC8x8B_8u_C1,(const Ipp8u  *pSrcRefF,
									Ipp32s        srcStepF,
									Ipp32s		  mcType,
									const Ipp8u  *pSrcRefB,
									Ipp32s        srcStepB,
									Ipp32s		  mcTypeB,
									const Ipp16s *pSrcYData,
									Ipp32s        srcYDataStep,
									Ipp8u        *pDst,
									Ipp32s        dstStep,
									IppRoundMode  roundControl))

IPPAPI(IppStatus, ippiMC8x4_8u_C1, (const Ipp8u  *pSrcRef,
									Ipp32s        srcStep,
									const Ipp16s *pSrcYData,
									Ipp32s        srcYDataStep,
									Ipp8u        *pDst,
									Ipp32s        dstStep,
									Ipp32s        mcType,
									IppRoundMode  roundControl))

IPPAPI(IppStatus, ippiMC8x4B_8u_C1,(const Ipp8u  *pSrcRefF,
									Ipp32s        srcStepF,
									Ipp32s		  mcType,
									const Ipp8u  *pSrcRefB,
									Ipp32s        srcStepB,
									Ipp32s		  mcTypeB,
									const Ipp16s *pSrcYData,
									Ipp32s        srcYDataStep,
									Ipp8u        *pDst,
									Ipp32s        dstStep,
									IppRoundMode  roundControl))

IPPAPI(IppStatus, ippiMC_8x8OV,		(const Ipp8u  *pSrcRef,
									 Ipp32s        srcStep,
									 const long	  *pMatrix,
									 Ipp16s       *pDst,
									 Ipp32s        dstStep,
									 Ipp32s		   mcType,
									 Ipp32s		   roundControl))

IPPAPI(IppStatus, ippiMC_8x4OV,		(const Ipp8u  *pSrcRef,
									 Ipp32s        srcStep,
									 const long   *pMatrix,
									 Ipp16s        *pDst,
									 Ipp32s        dstStep,
									 Ipp32s		   mcType,
									 Ipp32s		   roundControl))

IPPAPI(IppStatus, ippiMC_4x8OV,		(const Ipp8u  *pSrcRef,
									 Ipp32s        srcStep,
									 const long   *pMatrix,
									 Ipp16s        *pDst,
									 Ipp32s        dstStep,
									 Ipp32s		   mcType,
									 Ipp32s		   roundControl))

IPPAPI(IppStatus, ippiMC_LumaOV,	(const Ipp16s *pSrcYData,
									 Ipp32s        srcYDataStep,
									 const Ipp16s  *pSrcRefQ,
									 const Ipp16s  *pSrcRefR,
									 const Ipp16s  *pSrcRefS,
									 Ipp32s        srcQRSStep,
									 Ipp8u         *pDst,
									 Ipp32s        dstStep))

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
///////////////////////// Motion Estimation Primitives /////////////////////////
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//  Name:       ippiGetDiff16x16_8u16s_C1
//  Purpose:    Evaluates the difference between current and reference blocks
//				in accordance with specified type of following compensation.
//
//  Returns:    IppStatus value
//  Parameters:
//	Input:		pSrcCur			-   pointer to the current block 16x16
//				srcCurStep		-	current block step (stride1)
//				pSrcRef			-	pointer to reference block 16x16
//				srcRefStep		-	reference block step (stride1)
//				mcType			-   flag specifies following compensation type
//  Output:		pDst			-	pointer to the destination block for storing
//									the differences between current and
//									reference blocks
//				dstStep			-	destination block step (stride1)
//				pDstPredictor	-	pointer to block for storing predictors which
//									will be used in image reconstruction
//				dstPredictorStep -	predictors block step (stride1)
//
//  Notes:      This operation is inverse to that performed by ippiMC16x16_8u16s

IPPAPI(IppStatus, ippiGetDiff16x16_8u16s_C1,(const Ipp8u*  pSrcCur,
												   Ipp32s  srcCurStep,
										     const Ipp8u*  pSrcRef,
												   Ipp32s  srcRefStep,
												   Ipp16s* pDstDiff,
												   Ipp32s  dstDiffStep,
												   Ipp16s* pDstPredictor,
												   Ipp32s  dstPredictorStep,
												   Ipp32s  mcType,
												   Ipp32s  roundControl))

IPPAPI(IppStatus, ippiGetDiff16x8_8u16s_C1, (const Ipp8u*  pSrcCur,
												   Ipp32s  srcCurStep,
										     const Ipp8u*  pSrcRef,
												   Ipp32s  srcRefStep,
												   Ipp16s* pDstDiff,
												   Ipp32s  dstDiffStep,
												   Ipp16s* pDstPredictor,
												   Ipp32s  dstPredictorStep,
												   Ipp32s  mcType,
												   Ipp32s  roundControl))

IPPAPI(IppStatus, ippiGetDiff8x8_8u16s_C1,  (const Ipp8u*  pSrcCur,
												   Ipp32s  srcCurStep,
										     const Ipp8u*  pSrcRef,
												   Ipp32s  srcRefStep,
												   Ipp16s* pDstDiff,
												   Ipp32s  dstDiffStep,
												   Ipp16s* pDstPredictor,
												   Ipp32s  dstPredictorStep,
												   Ipp32s  mcType,
												   Ipp32s  roundControl))

IPPAPI(IppStatus, ippiGetDiff8x16_8u16s_C1, (const Ipp8u*  pSrcCur,
												   Ipp32s  srcCurStep,
										     const Ipp8u*  pSrcRef,
												   Ipp32s  srcRefStep,
												   Ipp16s* pDstDiff,
												   Ipp32s  dstDiffStep,
												   Ipp16s* pDstPredictor,
												   Ipp32s  dstPredictorStep,
												   Ipp32s  mcType,
												   Ipp32s  roundControl))

IPPAPI(IppStatus, ippiGetDiff8x4_8u16s_C1,  (const Ipp8u*  pSrcCur,
												   Ipp32s  srcCurStep,
										     const Ipp8u*  pSrcRef,
												   Ipp32s  srcRefStep,
												   Ipp16s* pDstDiff,
												   Ipp32s  dstDiffStep,
												   Ipp16s* pDstPredictor,
												   Ipp32s  dstPredictorStep,
												   Ipp32s  mcType,
												   Ipp32s  roundControl))

////////////////////////////////////////////////////////////////////////////////
//  Name:       ippiGetDiff16x16B_8u16s_C1
//  Purpose:    Evaluates the difference between current and mean of two
//				reference blocks in accordance with specified type of following
//				compensation.
//
//  Returns:    IppStatus value
//  Parameters:
//	Input:		pSrcCur			-   pointer to the current block 16x16
//				srcCurStep		-	current block step (stride1)
//				pSrcRefF		-	pointer to forward reference block 16x16
//				srcRefStepF		-	forward reference block step (stride1)
//				mcTypeF			-   flag specifies forward compensation type
//				pSrcRefB		-	pointer to backward reference block 16x16
//				srcRefStepB		-	backward reference block step (stride1)
//				mcTypeB			-   flag specifies backward compensation type
//  Output:		pDstDiff		-	pointer to the destination block for storing
//									the differences between current and
//									mean of two reference blocks
//				dstDiffStep		-	destination difference block step (stride1)
//
//  Notes:      This operation is inverse to that performed by ippiMC16x16B_8u16s

IPPAPI(IppStatus, ippiGetDiff16x16B_8u16s_C1,	(const Ipp8u*		pSrcCur,
													   Ipp32s		srcCurStep,
												 const Ipp8u*		pSrcRefF,
													   Ipp32s		srcRefStepF,
													   Ipp32s		mcTypeF,
												 const Ipp8u*		pSrcRefB,
													   Ipp32s		srcRefStepB,
													   Ipp32s		mcTypeB,
													   Ipp16s*		pDstDiff,
													   Ipp32s		dstDiffStep,
													   IppRoundMode roundControl ))

IPPAPI(IppStatus, ippiGetDiff16x8B_8u16s_C1,	(const Ipp8u*		pSrcCur,
													   Ipp32s		srcCurStep,
												 const Ipp8u*		pSrcRefF,
													   Ipp32s		srcRefStepF,
													   Ipp32s		mcTypeF,
												 const Ipp8u*		pSrcRefB,
													   Ipp32s		srcRefStepB,
													   Ipp32s		mcTypeB,
													   Ipp16s*		pDstDiff,
													   Ipp32s		dstDiffStep,
													   IppRoundMode roundControl ))

IPPAPI(IppStatus, ippiGetDiff8x8B_8u16s_C1,     (const Ipp8u*		pSrcCur,
													   Ipp32s		srcCurStep,
												 const Ipp8u*		pSrcRefF,
													   Ipp32s		srcRefStepF,
													   Ipp32s		mcTypeF,
												 const Ipp8u*		pSrcRefB,
													   Ipp32s		srcRefStepB,
													   Ipp32s		mcTypeB,
													   Ipp16s*		pDstDiff,
													   Ipp32s		dstDiffStep,
													   IppRoundMode roundControl ))

IPPAPI(IppStatus, ippiGetDiff8x16B_8u16s_C1,	(const Ipp8u*		pSrcCur,
													   Ipp32s		srcCurStep,
												 const Ipp8u*		pSrcRefF,
													   Ipp32s		srcRefStepF,
													   Ipp32s		mcTypeF,
												 const Ipp8u*		pSrcRefB,
													   Ipp32s		srcRefStepB,
													   Ipp32s		mcTypeB,
													   Ipp16s*		pDstDiff,
													   Ipp32s		dstDiffStep,
													   IppRoundMode roundControl ))

IPPAPI(IppStatus, ippiGetDiff8x4B_8u16s_C1,	    (const Ipp8u*		pSrcCur,
													   Ipp32s		srcCurStep,
												 const Ipp8u*		pSrcRefF,
													   Ipp32s		srcRefStepF,
													   Ipp32s		mcTypeF,
												 const Ipp8u*		pSrcRefB,
													   Ipp32s		srcRefStepB,
													   Ipp32s		mcTypeB,
													   Ipp16s*		pDstDiff,
													   Ipp32s		dstDiffStep,
													   IppRoundMode roundControl ))

////////////////////////////////////////////////////////////////////////////////
//  Name:       ippiSAD16x16_8u32s
//  Purpose:    Evaluates the sum of absolute difference (SAD) between current
//				and reference blocks.
//
//  Returns:    IppStatus value
//  Parameters:
//	Input:		pSrcCur			-   pointer to the current block 16x16
//				srcCurStep		-	current block step (stride1)
//				pSrcRef			-	pointer to reference block 16x16
//				srcRefStep		-	reference block step (stride1)
//				mcType			-
//  Output:		pDst			-	pointer to the destination single integer
//
//  Notes:

IPPAPI(IppStatus, ippiSAD16x16_8u32s,    (const Ipp8u*  pSrcCur,
												Ipp32s  srcCurStep,
										  const Ipp8u*  pSrcRef,
												Ipp32s  srcRefStep,
												Ipp32s* pDst,
												Ipp32s  mcType ))
IPPAPI(IppStatus, ippiVariance16x16_8u32s,( const Ipp8u*  pSrc,
										    int           srcStep,
										    Ipp32s*       Var))
IPPAPI(IppStatus, ippiSqrDiff16x16_8u32s,( const Ipp8u*  pSrc,
										      int            srcStep,
											  const Ipp8u*   pRef,
										      int            refStep,
											  Ipp32s		 mcType,
											  Ipp32s*        pSqrDiff))
IPPAPI(IppStatus, ippiSqrDiff16x16B_8u32s,( const Ipp8u*  pSrc,
										       int            srcStep,
											   const Ipp8u*   pRefF,
										       int            refStepF,
											   Ipp32s		  mcTypeF,
											   const Ipp8u*   pRefB,
										       int            refStepB,
											   Ipp32s		  mcTypeB,
											   Ipp32s*        pSqrDiff))

////////////////////////////////////////////////////////////////////////////////
//////////////////////////// Quantiaztion functions ////////////////////////////
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//  Name:       ippiQuantIntra_MPEG2_16s_C1I
//  Purpose:    Performs quantization on DCT coefficients of intra block inplace with
//				specified quantization matrix. Returns the number of last non-zero coefficient
//				for future considerations. If pointer to inverse quantization matrix is NULL
//				default matrix is used
//
//  Returns:    IppStatus value
//  Parameters:
//	Input:		pDCTCoeff	    -	pointer to block of DCT coefficients
//				quant			-   quantizer
//  			pInvQuantMatrix -   pointer to the matrix of inverted quantization coefficients
//									(floating point)
//  Output:		pDCTCoeff	    -	pointer to block of DCT coefficients

//  Notes:

IPPAPI(IppStatus, ippiQuantIntra_MPEG2_16s_C1I,( Ipp16s       *pDctCoeff,
												 Ipp32s        quant,
												 const Ipp32f *pInvQuantMatrix,
												 Ipp32s       *Count ))


////////////////////////////////////////////////////////////////////////////////
//  Name:       ippiQuant_MPEG2_16s_C1I
//  Purpose:    Performs quantization on DCT coefficients of non-intra block inplace with
//				specified quantization matrix. Returns the number of last non-zero coefficient
//				for future considerations. If pointer to inverse quantization matrix is NULL
//				default matrix is used
//
//  Returns:    IppStatus value
//  Parameters:
//	Input:		pDCTCoeff	    -	pointer to block of DCT coefficients
//				quant			-   quantizer
//  			pInvQuantMatrix -   pointer to the matrix of inverted quantization coefficients
//									(floating point)
//  Output:		pDCTCoeff	    -	pointer to block of DCT coefficients
//  Notes:

IPPAPI(IppStatus, ippiQuant_MPEG2_16s_C1I,	   ( Ipp16s       *pDctCoeff,
												 Ipp32s        quant,
												 const Ipp32f *pInvQuantMatrix,
												 Ipp32s       *Count ))

////////////////////////////////////////////////////////////////////////////////
//  Name:       ippiQuantIntra_MPEG4_16s_C1I
//  Purpose:    Performs quantization on DCT coefficients of intra block inplace with
//				specified quantization matrix. Returns the number of last non-zero coefficient
//				for future considerations. If pointer to inverse quantization matrix is NULL
//				default matrix is used
//
//  Returns:    IppStatus value
//  Parameters:
//	Input:		pDCTCoeff	    -	pointer to block of DCT coefficients
//				quant			-   quantizer
//  			pInvQuantMatrix -   pointer to the matrix of inverted quantization coefficients
//									(floating point)
//  Output:		pDCTCoeff	    -	pointer to block of DCT coefficients

//  Notes:

IPPAPI(IppStatus, ippiQuantIntra_MPEG4_16s_C1I,( Ipp16s       *pDctCoeff,
												 Ipp32s        quant,
												 const Ipp32f *pInvQuantMatrix,
												 Ipp32s       *Count ))

////////////////////////////////////////////////////////////////////////////////
//  Name:       ippiQuant_MPEG4_16s_C1I
//  Purpose:    Performs quantization on DCT coefficients of non-intra block inplace with
//				specified quantization matrix. Returns the number of last non-zero coefficient
//				for future considerations. If pointer to inverse quantization matrix is NULL
//				default matrix is used
//
//  Returns:    IppStatus value
//  Parameters:
//	Input:		pDCTCoeff	    -	pointer to block of DCT coefficients
//				quant			-   quantizer
//  			pInvQuantMatrix -   pointer to the matrix of inverted quantization coefficients
//									(floating point)
//  Output:		pDCTCoeff	    -	pointer to block of DCT coefficients

//  Notes:

IPPAPI(IppStatus, ippiQuant_MPEG4_16s_C1I,	   ( Ipp16s       *pDctCoeff,
												 Ipp32s        quant,
												 const Ipp32f *pInvQuantMatrix,
												 Ipp32s       *Count ))

////////////////////////////////////////////////////////////////////////////////
//  Name:       ippiQuantIntra_H263_C1I
//  Purpose:    Performs quantization on DCT coefficients of intra block inplace.
//				Returns the number of last non-zero coefficient
//				for future considerations. If pointer to inverse quantization matrix is NULL
//				default matrix is used
//
//  Returns:    IppStatus value
//  Parameters:
//	Input:		pDCTCoeff	    -	pointer to block of DCT coefficients
//				quant			-   quantizer
//
//  Output:		pDCTCoeff	    -	pointer to block of DCT coefficients

//  Notes:

IPPAPI(IppStatus, ippiQuantIntra_H263_C1I,( Ipp16s *pDctCoeff, Ipp32s quant, Ipp32s *Count))

////////////////////////////////////////////////////////////////////////////////
//  Name:       ippiQuant_H263_C1I
//  Purpose:    Performs quantization on DCT coefficients of non-intra block inplace.
//				Returns the number of last non-zero coefficient
//				for future considerations. If pointer to inverse quantization matrix is NULL
//				default matrix is used
//
//  Returns:    IppStatus value
//  Parameters:
//	Input:		pDCTCoeff	    -	pointer to block of DCT coefficients
//				quant			-   quantizer
//
//  Output:		pDCTCoeff	    -	pointer to block of DCT coefficients

//  Notes:

IPPAPI(IppStatus, ippiQuant_H263_C1I,( Ipp16s *pDctCoeff, Ipp32s quant, Ipp32s *Count ))

IPPAPI(IppStatus, ippiCreateRLEncodeTable, (const Ipp32s* pSrcTable, IppVCHuffmanSpec_32s** pDstSpec))
IPPAPI(IppStatus, ippiPutIntraBlock, (Ipp32u **pBitStream,int *pOffset,
										   short* block, int* dc_dct_pred,
										   IppVCHuffmanSpec_32u* DC_Tbl, IppVCHuffmanSpec_32s* AC_Tbl,
										   int* scan, int EOBLen, int EOBCode, int count))

IPPAPI(IppStatus,  ippiPutNonIntraBlock, (Ipp32u **pBitStream,int *pOffset,
										   short* block, IppVCHuffmanSpec_32s* AC_Tbl,
										   int* scan, int EOBLen, int EOBCode, int count))


#if defined __cplusplus
}
#endif

#endif /* __IPPVC_H__ */
/* End of file ippvc.h*/
