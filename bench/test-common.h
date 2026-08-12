#include <cmath>
#include "aspen_ddreal.h"
#include "aspen_ddcomplex.h"
#if TYPE_DOUBLE_COMPLEX || TYPE_FLOAT_COMPLEX
#include "aspen_complex.h"
#endif
#include "aspen_half.h"
#include "aspen_half_complex.h"
#include "aspen_int16.h"
#include "aspen_int32.h"
#include "aspen_int64.h"
#include "aspen_int128.h"
//#include "aspen_bfloat16.h"

#define CUDA_INVOKE( kernel_name, ...)                                  \
  do {                                                                  \
                 kernel_name  __VA_ARGS__ ;                             \
                 cudaError_t err = cudaGetLastError();                  \
                 if ( err != cudaSuccess ) {                            \
                   printf ( "ERROR in [%s] : %s \n",                    \
                            #kernel_name, cudaGetErrorString(err) );    \
                   exit ( 1 );                                          \
                   /* return; */                                        \
                 }                                                      \
   } while ( 1 == 0 )

#define __isDD__			0
#define __isDOUBLE__			0
#define __isFLOAT__			0
#define __isHALF__			0
#define __isDD_COMPLEX__		0
#define __isDOUBLE_COMPLEX__		0
#define __isFLOAT_COMPLEX__		0
#define __isHALF_COMPLEX__		0
#define __isINT16__			0
#define __isINT32__			0
#define __isINT64__			0
#define __isINT128__			0
#define __isBF16__			0

#if TYPE_DD
#   define TYPE			cuddreal
#   define TYPE_		double
#   define CONST(v)		makeCONST<cuddreal>(v)
#   undef __isDD__
#   define __isDD__			1
#   define EPS			(3.1556e-30)
#   define _FUNCS		W_FUNCS
#endif

#if TYPE_DOUBLE
#   define TYPE			double
#   define TYPE_		double
#   define CONST(v)		((double)(v))
#   undef __isDOUBLE__
#   define __isDOUBLE__			1
#   define EPS			(1.7764e-15)
#   define _FUNCS		D_FUNCS
#endif

#if TYPE_FLOAT
#   define TYPE			float
#   define TYPE_		float
#   define CONST(v)		((float)(v))
#   undef __isFLOAT__
#   define __isFLOAT__			1
#   define EPS			(1.1921e-07)
#   define _FUNCS		S_FUNCS
#endif

#if TYPE_HALF
#   define TYPE			half
#   define TYPE_		half
#   define CONST(v)		((half)(v))
#   undef __isHALF__
#   define __isHALF__			1
#   define EPS			(9.7656e-04)
#   define _FUNCS		H_FUNCS
#endif

#if TYPE_DD_COMPLEX
#   define TYPE			cuddcomplex
#   define TYPE_		cuddreal
#   define CONST(v)		makeCONST<cuddcomplex>(v)
#   undef __isDD_COMPLEX__
#   define __isDD_COMPLEX__		1
#   define EPS			(3.1556e-30)
#   define _FUNCS		U_FUNCS
#endif

#if TYPE_DOUBLE_COMPLEX
#   define TYPE			cuDoubleComplex
#   define TYPE_		double
#   define CONST(v)		make_cuDoubleComplex(v,(double)0)
#   undef __isDOUBLE_COMPLEX__
#   define __isDOUBLE_COMPLEX__		1
#   define EPS			(1.7764e-15)
#   define _FUNCS		Z_FUNCS
#endif

#if TYPE_FLOAT_COMPLEX
#   define TYPE			cuFloatComplex
#   define TYPE_		float
#   define CONST(v)		make_cuFloatComplex(v,(float)0)
#   undef __isFLOAT_COMPLEX__
#   define __isFLOAT_COMPLEX__		1
#   define EPS			(1.1921e-07)
#   define _FUNCS		C_FUNCS
#endif

#if TYPE_HALF_COMPLEX
#   define TYPE			cuHalfComplex
#   define TYPE_		half
#   define CONST(v)		makeCONST<cuHalfCOmplex>(v)
#   undef __isHALF_COMPLEX__
#   define __isHALF_COMPLEX__		1
#   define EPS			(9.7656e-04)
#   define _FUNCS		K_FUNCS
#endif

#if TYPE_INT16
#   define TYPE			int16
#   define TYPE_		int16
#   define CONST(v)		((short)(v))
#   undef __isINT16__
#   define __isINT16__		1
#   define EPS			(1)
#   define _FUNCS		I16_FUNCS
#endif

#if TYPE_INT32
#   define TYPE			int32
#   define TYPE_		int32
#   define CONST(v)		((int32)(v))
#   undef __isINT32__
#   define __isINT32__		1
#   define EPS			(1)
#   define _FUNCS		I32_FUNCS
#endif

#if TYPE_INT64
#   define TYPE			int64
#   define TYPE_		int64
#   define CONST(v)		((int64)(v))
#   undef __isINT64__
#   define __isINT64__		1
#   define EPS			(1)
#   define _FUNCS		I64_FUNCS
#endif

#if TYPE_INT128
#   define TYPE			int128
#   define TYPE_		int128
#   define CONST(v)		((int128){ (signed long)(0), (unsigned long)(v) })
#   undef __isINT128__
#   define __isINT128__		1
#   define EPS			(1)
#   define _FUNCS		I128_FUNCS
#endif

#if 0
#if TYPE_BF16
#   define TYPE			bfloat16
#   define TYPE_		float
#   define CONST(v)		makeCONST<bfloat16>(v)
#   undef __isBF16__
#   define __isBF16__		1
#   define EPS			(1e+0/256)
#   define _FUNCS		BF16_FUNCS
#endif
#endif

// macro for the legacy cublas
#define	cublasAlloc( a, b, c )	cudaMalloc ( (c), long((a)*(b)) )
#define	cublasFree( a )		cudaFree ( a )

// to avoid SIGSEGV in large indexing
#define	MAT( addr, row, col, lda )	\
	(*( (addr) + (long)(row) + ((long)(col)) * ((long)(lda)) ))
#define	VEC( addr, row )		\
	(*( (addr) + (long)(row) ))
#define	VEC2( addr, row, inc )		\
	(*( (addr) + ((long)(row)) * ((long)(inc)) ))


#ifdef __cplusplus
extern "C" {
#endif


  int get_gpu_id( void );
  void print_head( char *func_name, int argc, char **argv );
  double get_wtime( void );
  void do_usleep( const int usec );
  size_t get_device_WorkSize( const int dev, const int size );
  void Check_GPU_status( char * message );
  int get_Max_N( size_t sizeof_T );
 
  void
  ASPEN_init( int );

  void
  ASPEN_shutdown( void );

  int
  ASPEN_get_driver_Version( void );

  int
  ASPEN_get_runtime_Version( void );

  size_t
  ASPEN_get_device_Memory( void );

  size_t
  ASPEN_get_device_WorkSize( void );

  void
  ASPEN_HSYMVu(int blk, int N, half *dA, int LDA,
               half *dB, int incx,
               half *dC, int incy,
               half alpha, half beta);

  void
  ASPEN_HSYMVl(int blk, int N, half *dA, int LDA,
               half *dB, int incx,
               half *dC, int incy,
               half alpha, half beta);

  void
  ASPEN_SSYMVu(int blk, int N, float *dA, int LDA,
               float *dB, int incx,
               float *dC, int incy,
               float alpha, float beta);

  void
  ASPEN_SSYMVl(int blk, int N, float *dA, int LDA,
               float *dB, int incx,
               float *dC, int incy,
               float alpha, float beta);

  void
  ASPEN_DSYMVu(int blk, int N, double *dA, int LDA,
               double *dB, int incx,
               double *dC, int incy,
               double alpha, double beta);
  void
  ASPEN_DSYMVl(int blk, int N, double *dA, int LDA,
               double *dB, int incx,
               double *dC, int incy,
               double alpha, double beta);

  void
  ASPEN_WSYMVu(int blk, int N, cuddreal *dA, int LDA,
               cuddreal *dB, int incx,
               cuddreal *dC, int incy,
               cuddreal alpha, cuddreal beta);
  void
  ASPEN_WSYMVl(int blk, int N, cuddreal *dA, int LDA,
               cuddreal *dB, int incx,
               cuddreal *dC, int incy,
               cuddreal alpha, cuddreal beta);

  void
  ASPEN_KHEMVu(int blk, int N, cuHalfComplex *dA, int LDA,
               cuHalfComplex *dB, int incx,
               cuHalfComplex *dC, int incy,
               cuHalfComplex alpha, cuHalfComplex beta);
  void
  ASPEN_KHEMVl(int blk, int N, cuHalfComplex *dA, int LDA,
               cuHalfComplex *dB, int incx,
               cuHalfComplex *dC, int incy,
               cuHalfComplex alpha, cuHalfComplex beta);

  void
  ASPEN_CHEMVu(int blk, int N, cuFloatComplex *dA, int LDA,
               cuFloatComplex *dB, int incx,
               cuFloatComplex *dC, int incy,
               cuFloatComplex alpha, cuFloatComplex beta);
  void
  ASPEN_CHEMVl(int blk, int N, cuFloatComplex *dA, int LDA,
               cuFloatComplex *dB, int incx,
               cuFloatComplex *dC, int incy,
               cuFloatComplex alpha, cuFloatComplex beta);

  void
  ASPEN_ZHEMVu(int blk, int N, cuDoubleComplex *dA, int LDA,
               cuDoubleComplex *dB, int incx,
               cuDoubleComplex *dC, int incy,
               cuDoubleComplex alpha, cuDoubleComplex beta);
  void
  ASPEN_ZHEMVl(int blk, int N, cuDoubleComplex *dA, int LDA,
               cuDoubleComplex *dB, int incx,
               cuDoubleComplex *dC, int incy,
               cuDoubleComplex alpha, cuDoubleComplex beta);

  void
  ASPEN_UHEMVu(int blk, int N, cuddcomplex *dA, int LDA,
               cuddcomplex *dB, int incx,
               cuddcomplex *dC, int incy,
               cuddcomplex alpha, cuddcomplex beta);
  void
  ASPEN_UHEMVl(int blk, int N, cuddcomplex *dA, int LDA,
               cuddcomplex *dB, int incx,
               cuddcomplex *dC, int incy,
               cuddcomplex alpha, cuddcomplex beta);

  void
  ASPEN_I16GEMV_n(int blk, int16 alpha, int16 beta, int16 *dA, int16 *dB,
                int16 *dC,
                int LDA,
                int N1, int N2, int incx, int incy);
  void
  ASPEN_I16GEMV_t(int blk, int16 alpha, int16 beta, int16 *dA, int16 *dB,
                int16 *dC,
                int LDA,
                int N1, int N2, int incx, int incy);
  void
  ASPEN_I16SYMVu(int blk, int N, int16 *dA, int LDA,
               int16 *dB, int incx,
               int16 *dC, int incy,
               int16 alpha, int16 beta);
  void
  ASPEN_I16SYMVl(int blk, int N, int16 *dA, int LDA,
               int16 *dB, int incx,
               int16 *dC, int incy,
               int16 alpha, int16 beta);

  void
  ASPEN_I32GEMV_n(int blk, int32 alpha, int32 beta, int32 *dA, int32 *dB,
                int32 *dC,
                int LDA,
                int N1, int N2, int incx, int incy);
  void
  ASPEN_I32GEMV_t(int blk, int32 alpha, int32 beta, int32 *dA, int32 *dB,
                int32 *dC,
                int LDA,
                int N1, int N2, int incx, int incy);
  void
  ASPEN_I32SYMVu(int blk, int N, int32 *dA, int LDA,
               int32 *dB, int incx,
               int32 *dC, int incy,
               int32 alpha, int32 beta);
  void
  ASPEN_I32SYMVl(int blk, int N, int32 *dA, int LDA,
               int32 *dB, int incx,
               int32 *dC, int incy,
               int32 alpha, int32 beta);

  void
  ASPEN_I64GEMV_n(int blk, int64 alpha, int64 beta, int64 *dA, int64 *dB,
                int64 *dC,
                int LDA,
                int N1, int N2, int incx, int incy);
  void
  ASPEN_I64GEMV_t(int blk, int64 alpha, int64 beta, int64 *dA, int64 *dB,
                int64 *dC,
                int LDA,
                int N1, int N2, int incx, int incy);
  void
  ASPEN_I64SYMVu(int blk, int N, int64 *dA, int LDA,
               int64 *dB, int incx,
               int64 *dC, int incy,
               int64 alpha, int64 beta);
  void
  ASPEN_I64SYMVl(int blk, int N, int64 *dA, int LDA,
               int64 *dB, int incx,
               int64 *dC, int incy,
               int64 alpha, int64 beta);

  void
  ASPEN_I128GEMV_n(int blk, int128 alpha, int128 beta, int128 *dA, int128 *dB,
                int128 *dC,
                int LDA,
                int N1, int N2, int incx, int incy);
  void
  ASPEN_I128GEMV_t(int blk, int128 alpha, int128 beta, int128 *dA, int128 *dB,
                int128 *dC,
                int LDA,
                int N1, int N2, int incx, int incy);
  void
  ASPEN_I128SYMVu(int blk, int N, int128 *dA, int LDA,
               int128 *dB, int incx,
               int128 *dC, int incy,
               int128 alpha, int128 beta);
  void
  ASPEN_I128SYMVl(int blk, int N, int128 *dA, int LDA,
               int128 *dB, int incx,
               int128 *dC, int incy,
               int128 alpha, int128 beta);
#if 0
  void
  ASPEN_BF16SYMVu(int blk, int N, bfloat16 *dA, int LDA,
               bfloat16 *dB, int incx,
               bfloat16 *dC, int incy,
               bfloat16 alpha, bfloat16 beta);
  void
  ASPEN_BF16SYMVl(int blk, int N, bfloat16 *dA, int LDA,
               bfloat16 *dB, int incx,
               bfloat16 *dC, int incy,
               bfloat16 alpha, bfloat16 beta);
#endif

#ifdef __cplusplus
}
#endif

enum H_FUNCS { HGEMV_N, HGEMV_T, HSYMV_U, HSYMV_L };
enum S_FUNCS { SGEMV_N, SGEMV_T, SSYMV_U, SSYMV_L };
enum D_FUNCS { DGEMV_N, DGEMV_T, DSYMV_U, DSYMV_L };
enum W_FUNCS { WGEMV_N, WGEMV_T, WSYMV_U, WSYMV_L };

enum K_FUNCS { KGEMV_N, KGEMV_T, KGEMV_C, KHEMV_U, KHEMV_L };
enum C_FUNCS { CGEMV_N, CGEMV_T, CGEMV_C, CHEMV_U, CHEMV_L };
enum Z_FUNCS { ZGEMV_N, ZGEMV_T, ZGEMV_C, ZHEMV_U, ZHEMV_L };
enum U_FUNCS { UGEMV_N, UGEMV_T, UGEMV_C, UHEMV_U, UHEMV_L };

enum I16_FUNCS { I16GEMV_N, I16GEMV_T, I16SYMV_U, I16SYMV_L };
enum I32_FUNCS { I32GEMV_N, I32GEMV_T, I32SYMV_U, I32SYMV_L };
enum I64_FUNCS { I64GEMV_N, I64GEMV_T, I64SYMV_U, I64SYMV_L };
enum I128_FUNCS { I128GEMV_N, I128GEMV_T, I128SYMV_U, I128SYMV_L };

#if 0
enum BF16_FUNCS { BF16GEMV_N, BF16GEMV_T, BF16SYMV_U, BF16SYMV_L };
#endif
