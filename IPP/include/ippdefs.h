/* ////////////////////////////////// "ippdefs.h" //////////////////////////////
//
//                  INTEL CORPORATION PROPRIETARY INFORMATION
//     This software is supplied under the terms of a license agreement or
//     nondisclosure agreement with Intel Corporation and may not be copied
//     or disclosed except in accordance with the terms of that agreement.
//          Copyright(c) 1999-2003 Intel Corporation. All Rights Reserved.
//
//      		Intel(R) Integrated Performance Primitives Common Types and
//					Macro Definitions.
//
*/

#ifndef __IPPDEFS_H__
#define __IPPDEFS_H__

#ifdef __cplusplus
extern "C" {
#endif


#if defined( _WIN32 ) || defined ( _WIN64 )
  #define __STDCALL  __stdcall
  #define __CDECL    __cdecl
  #define __INT64    __int64
  #define __UINT64    unsigned __int64
#else
  #define __STDCALL
  #define __CDECL
  #define __INT64    long long
  #define __UINT64    unsigned long long
#endif


#if !defined( IPPAPI )

  #if defined( IPP_W32DLL ) && (defined( _WIN32 ) || defined( _WIN64 ))
    #if defined( _MSC_VER ) || defined( __ICL )
      #define IPPAPI( type,name,arg ) \
                     extern __declspec(dllimport) type __STDCALL name arg;
    #else
      #define IPPAPI( type,name,arg )        extern type __STDCALL name arg;
    #endif
  #else
    #define   IPPAPI( type,name,arg )        extern type __STDCALL name arg;
  #endif

#endif


#define IPP_PI    ( 3.14159265358979323846 )  /* ANSI C does not support M_PI */
#define IPP_2PI   ( 6.28318530717958647692 )  /* 2*pi                         */
#define IPP_PI2   ( 1.57079632679489661923 )  /* pi/2                         */
#define IPP_PI4   ( 0.78539816339744830961 )  /* pi/4                         */
#define IPP_PI180 ( 0.01745329251994329577 )  /* pi/180                       */
#define IPP_RPI   ( 0.31830988618379067154 )  /* 1/pi                         */
#define IPP_SQRT2 ( 1.41421356237309504880 )  /* sqrt(2)                      */
#define IPP_SQRT3 ( 1.73205080756887729353 )  /* sqrt(3)                      */
#define IPP_LN2   ( 0.69314718055994530942 )  /* ln(2)                        */
#define IPP_LN3   ( 1.09861228866810969139 )  /* ln(3)                        */
#define IPP_E     ( 2.71828182845904523536 )  /* e                            */
#define IPP_RE    ( 0.36787944117144232159 )  /* 1/e                          */
#define IPP_EPS23 ( 1.19209289e-07f )
#define IPP_EPS52 ( 2.2204460492503131e-016 )

#define IPP_MAX_8U     ( 0xFF )
#define IPP_MAX_16U    ( 0xFFFF )
#define IPP_MAX_32U    ( 0xFFFFFFFF )
#define IPP_MIN_8S     (-128 )
#define IPP_MAX_8S     ( 127 )
#define IPP_MIN_16S    (-32768 )
#define IPP_MAX_16S    ( 32767 )
#define IPP_MIN_32S    (-2147483647 - 1 )
#define IPP_MAX_32S    ( 2147483647 )

#if defined( _WIN32 ) || defined ( _WIN64 )
  #define IPP_MAX_64S  ( 9223372036854775807i64 )
  #define IPP_MIN_64S  (-9223372036854775807i64 - 1 )
#else
  #define IPP_MAX_64S  ( 9223372036854775807LL )
  #define IPP_MIN_64S  (-9223372036854775807LL - 1 )
#endif

#define IPP_MINABS_32F ( 1.175494351e-38f )
#define IPP_MAXABS_32F ( 3.402823466e+38f )
#define IPP_EPS_32F    ( 1.192092890e-07f )
#define IPP_MINABS_64F ( 2.2250738585072014e-308 )
#define IPP_MAXABS_64F ( 1.7976931348623158e+308 )
#define IPP_EPS_64F    ( 2.2204460492503131e-016 )

#define IPP_DEG_TO_RAD( deg ) ( (deg)/180.0 * IPP_PI )
#define IPP_COUNT_OF( obj )  (sizeof(obj)/sizeof(obj[0]))

#define IPP_MAX( a, b ) ( ((a) > (b)) ? (a) : (b) )
#define IPP_MIN( a, b ) ( ((a) < (b)) ? (a) : (b) )


#if !defined( _OWN_BLDPCS )

typedef enum {
 /* Enumeration:         Processor:                          */
    ippCpuUnknown = 0x0,
    ippCpuPP,         /* Pentium(R)                          */
    ippCpuPMX,        /* Pentium(R) with MMX(TM)             */
    ippCpuPPR,        /* Pentium(R) Pro                      */
    ippCpuPII,        /* Pentium(R) II                       */
    ippCpuPIII,       /* Pentium(R) III                      */
    ippCpuP4,         /* Pentium(R) 4                        */
    ippCpuP4HT,       /* Pentium(R) 4 with HT enabled        */
    ippCpuP4HT2,
    ippCpuITP = 0x10, /* Itanium(R)                          */
    ippCpuITP2        /* Itanium(R) 2                        */
} IppCpuType;

typedef struct {
    int    major;                     /* e.g. 1                               */
    int    minor;                     /* e.g. 2                               */
    int    majorBuild;                /* e.g. 3                               */
    int    build;                     /* e.g. 10, always >= majorBuild        */

    char  targetCpu[4];               /* corresponding to Intel(R) processor  */
    const char* Name;                 /* e.g. "ippsm6"                        */
    const char* Version;              /* e.g. "v1.2 Beta"                     */
    const char* BuildDate;            /* e.g. "Jul 20 99"                     */
} IppLibraryVersion;


typedef unsigned char   Ipp8u;
typedef unsigned short  Ipp16u;
typedef unsigned int    Ipp32u;

typedef signed char    Ipp8s;
typedef signed short   Ipp16s;
typedef signed int     Ipp32s;
typedef float   Ipp32f;
typedef __INT64 Ipp64s;
typedef __UINT64 Ipp64u;
typedef double  Ipp64f;

typedef struct {
    Ipp8s  re;
    Ipp8s  im;
} Ipp8sc;

typedef struct {
    Ipp16s  re;
    Ipp16s  im;
} Ipp16sc;

typedef struct {
    Ipp32s  re;
    Ipp32s  im;
} Ipp32sc;

typedef struct {
    Ipp32f  re;
    Ipp32f  im;
} Ipp32fc;

typedef struct {
    Ipp64s  re;
    Ipp64s  im;
} Ipp64sc;

typedef struct {
    Ipp64f  re;
    Ipp64f  im;
} Ipp64fc;

typedef enum {
    ippRndZero,
    ippRndNear
} IppRoundMode;


typedef enum {
    ippAlgHintNone,
    ippAlgHintFast,
    ippAlgHintAccurate
} IppHintAlgorithm;

typedef enum {
    ippCmpLess,
    ippCmpLessEq,
    ippCmpEq,
    ippCmpGreaterEq,
    ippCmpGreater
} IppCmpOp;


enum {
    IPP_FFT_DIV_FWD_BY_N = 1,
    IPP_FFT_DIV_INV_BY_N = 2,
    IPP_FFT_DIV_BY_SQRTN = 4,
    IPP_FFT_NODIV_BY_ANY = 8
};

typedef enum {
   ipp1u,
   ipp8u,  ipp8s,
   ipp16u, ipp16s, ipp16sc,
   ipp32u, ipp32s, ipp32sc,
   ipp32f, ipp32fc,
   ipp64u, ipp64s, ipp64sc,
   ipp64f, ipp64fc
} IppDataType;


typedef struct {
    int x;
    int y;
    int width;
    int height;
} IppiRect;

typedef struct {
    int x;
    int y;
} IppiPoint;

typedef struct {
    int width;
    int height;
} IppiSize;


/* /////////////////////////////////////////////////////////////////////////////
//        The following enumerator defines a status of IPP operations
//                     negative value means error
*/
typedef enum {
     /* errors */
    ippStsNotSupportedModeErr   = -9999,
    ippStsCpuNotSupportedErr    = -9998,

    ippStsUnderRunErr           = -124,
    ippStsPaddingErr            = -123,
    ippStsCFBSizeErr            = -122,
    ippStsPaddingSchemeErr      = -121,
    ippStsInvalidCryptoKeyErr   = -120,

    ippStsLengthErr             = -119,
    ippStsBadModulusErr         = -118,

    ippStsLPCCalcErr            = -117,
    ippStsRCCalcErr             = -116,
    ippStsIncorrectLSPErr       = -115,

    ippStsNoRootFoundErr        = -114,

    ippStsJPEG2KBadPassNumber   = -113,
    ippStsJPEG2KDamagedCodeBlock= -112,

    ippStsH263CBPYCodeErr       = -111,
    ippStsH263MCBPCInterCodeErr = -110,
    ippStsH263MCBPCIntraCodeErr = -109,

    ippStsNotEvenStepErr        = -108,
    ippStsHistoNofLevelsErr     = -107,
    ippStsLUTNofLevelsErr       = -106,

    ippStsMP4BitOffsetErr       = -105,
    ippStsMP4QPErr              = -104,
    ippStsMP4BlockIdxErr        = -103,
    ippStsMP4BlockTypeErr       = -102,
    ippStsMP4MVCodeErr          = -101,
    ippStsMP4VLCCodeErr         = -100,
    ippStsMP4DCCodeErr          = -99,
    ippStsMP4FcodeErr           = -98,
    ippStsMP4AlignErr           = -97,
    ippStsMP4TempDiffErr        = -96,
    ippStsMP4BlockSizeErr       = -95,
    ippStsMP4ZeroBABErr         = -94,
    ippStsMP4PredDirErr         = -93,
    ippStsMP4BitsPerPixelErr    = -92,
    ippStsMP4VideoCompModeErr   = -91,
    ippStsMP4LinearModeErr      = -90,

    ippStsH263PredModeErr       = -83,
    ippStsH263BlockStepErr      = -82,
    ippStsH263MBStepErr         = -81,
    ippStsH263FrameWidthErr     = -80,
    ippStsH263FrameHeightErr    = -79,
    ippStsH263ExpandPelsErr     = -78,
    ippStsH263PlaneStepErr      = -77,
    ippStsH263QuantErr          = -76,
    ippStsH263MVCodeErr         = -75,
    ippStsH263VLCCodeErr        = -74,
    ippStsH263DCCodeErr         = -73,
    ippStsH263ZigzagLenErr      = -72,

    ippStsFBankFreqErr          = -71,
    ippStsFBankFlagErr          = -70,
    ippStsFBankErr              = -69,

    ippStsNegOccErr             = -67,
    ippStsCdbkFlagErr           = -66,
    ippStsSVDCnvgErr            = -65,


    ippStsJPEGHuffTableErr      = -64,
    ippStsJPEGDCTRangeErr       = -63,
    ippStsJPEGOutOfBufErr       = -62,

    ippStsDrawTextErr           = -61,
    ippStsChannelOrderErr       = -60,
    ippStsZeroMaskValuesErr     = -59,
    ippStsQuadErr               = -58,
    ippStsRectErr               = -57,
    ippStsCoeffErr              = -56,
    ippStsNoiseValErr           = -55,
    ippStsDitherLevelsErr       = -54,
    ippStsNumChannelsErr        = -53,
    ippStsCOIErr                = -52,
    ippStsDivisorErr            = -51,
    ippStsAlphaTypeErr          = -50,
    ippStsGammaRangeErr         = -49,
    ippStsGrayCoefSumErr        = -48,
    ippStsChannelErr            = -47,

    ippStsToneMagnErr           = -46,
    ippStsToneFreqErr           = -45,
    ippStsTonePhaseErr          = -44,
    ippStsTrnglMagnErr          = -43,
    ippStsTrnglFreqErr          = -42,
    ippStsTrnglPhaseErr         = -41,
    ippStsTrnglAsymErr          = -40,

    ippStsHugeWinErr            = -39,
    ippStsJaehneErr             = -38,
    ippStsStrideErr             = -37,
    ippStsEpsValErr             = -36,
    ippStsWtOffsetErr           = -35,
    ippStsAnchorErr             = -34,
    ippStsMaskSizeErr           = -33,

    ippStsShiftErr              = -32,
    ippStsSampleFactorErr       = -31,
    ippStsSamplePhaseErr        = -30,

    ippStsFIRMRFactorErr        = -29,
    ippStsFIRMRPhaseErr         = -28,
    ippStsRelFreqErr            = -27,
    ippStsFIRLenErr             = -26,
    ippStsIIROrderErr           = -25,
    ippStsDlyLineIndexErr       = -24,

    ippStsResizeFactorErr       = -23,
    ippStsInterpolationErr      = -22,
    ippStsMirrorFlipErr         = -21,
    ippStsMoment00ZeroErr       = -20,
    ippStsThreshNegLevelErr     = -19,
    ippStsThresholdErr          = -18,

    ippStsContextMatchErr       = -17,
    ippStsFftFlagErr            = -16,
    ippStsFftOrderErr           = -15,

    ippStsStepErr               = -14,
    ippStsScaleRangeErr         = -13,
    ippStsDataTypeErr           = -12,
    ippStsOutOfRangeErr         = -11,
    ippStsDivByZeroErr          = -10,
    ippStsMemAllocErr           = -9,
    ippStsNullPtrErr            = -8,
    ippStsRangeErr              = -7,
    ippStsSizeErr               = -6,


    ippStsBadArgErr             = -5,
    ippStsNoMemErr              = -4,
    ippStsSAReservedErr3        = -3,
    ippStsErr                   = -2,
    ippStsSAReservedErr1        = -1,

     /* no errors */
    ippStsNoErr                             =   0,

     /* warnings */
    ippStsNoOperation       =   1,
    ippStsMisalignedBuf     =   2,
    ippStsSqrtNegArg        =   3,
    ippStsInvZero           =   4,
    ippStsEvenMedianMaskSize=   5,
    ippStsDivByZero         =   6,
    ippStsLnZeroArg         =   7,
    ippStsLnNegArg          =   8,
    ippStsNanArg            =   9,
    ippStsJPEGMarker        =   10,
    ippStsResFloor          =   11,
    ippStsOverflow          =   12,
    ippStsLSFLow            =   13,
    ippStsLSFHigh           =   14,
    ippStsLSFLowAndHigh     =   15,
    ippStsZeroOcc           =   16,
    ippStsUnderflow         =   17,
    ippStsSingularity       =   18,
    ippStsDomain            =   19,
    ippStsNonIntelCpu       =   20,
    ippStsCpuMismatch       =   21,
    ippStsNoIppFunctionFound =  22,
    ippStsDllNotFoundBestUsed = 23,
    ippStsNoOperationInDll  =   24,
    ippStsInsufficientEntropy=  25,
    ippStsOvermuchStrings   =   26,
    ippStsOverlongString    =   27

} IppStatus;

#define ippStsOk ippStsNoErr

#endif /* _OWN_BLDPCS */


#ifdef __cplusplus
}
#endif

#endif /* __IPPDEFS_H__ */
/* ///////////////////////// End of file "ippdefs.h" //////////////////////// */
