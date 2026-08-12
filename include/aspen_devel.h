#ifndef ASPEN_DEVEL_H_INCLUDED
#define ASPEN_DEVEL_H_INCLUDED		1

// additional including standard header files
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include <ctype.h>
#include <string.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdint.h>
#include <unistd.h>

#include <iostream>
#include <time.h>

#include <assert.h>


// additional including CUDA header files
#include <cuda_runtime.h>
#include <cuda_runtime_api.h>
#include <cuda.h>
#if CUDA_VERSION<5000
#   include <cutil.h>
#endif
#include <cublas.h>
#include <nvml.h>

#if CUDA_VERSION>=9000
#   include <cooperative_groups.h>
#endif


// definitions for the prefix of API
#define	__1PARAMS__(x,y,...)	x ##_## y
#define	_NAME_1PARAMS_(x,y,...)	__1PARAMS__(x,y)
#define	__API_global_PREFIX__	ASPEN
#define	__API_private_PREFIX__	__Aspen__PrivateFunction__
#define	API_global(x,...)	_NAME_1PARAMS_(__API_global_PREFIX__, x)
#define	API_private(x,...)	_NAME_1PARAMS_(__API_private_PREFIX__, x)
#define	API			API_global

// Matrix type CONST
#define	UPPER		(0x00100)
#define	LOWER		(0x00101)
#define	NOTRANS		(0x00200)
#define	TRANS		(0x00201)
#define	CONJT		(0x00202)


// CUDA architecture CONST
#define	Tesla		(130)
#define	Fermi		(200)
#define	Kepler		(300)
#define	Kepler2		(350)
#define	Kepler3		(370)
#define	Maxwell		(500)
#define	Maxwell2	(520)
#define	Maxwell3	(530)
#define	Pascal		(600)
#define	Pascal1		(610)
#define	Pascal2		(620)
#define	Volta		(700)
#define	Volta2		(720)
#define	Turing		(750)
#define	Ampere		(800)
#define	Ampere2		(860)
#define	Ampere3		(870)
#define	Ada		(890)
#define	Hopper		(900)
#define	Blackwell	(1000)
#define	Blackwell2	(1200)

#define	_ASPEN_GPU_name_macro_(x)	case x:	ret = (char *) #x; break

__forceinline__ __host__ __device__ char *
ASPEN_GPU_Names( int const x ) {
  char * ret = NULL;
  switch ( x ) {
    _ASPEN_GPU_name_macro_( Tesla );
    _ASPEN_GPU_name_macro_( Fermi );
    _ASPEN_GPU_name_macro_( Kepler );
    _ASPEN_GPU_name_macro_( Kepler2 );
    _ASPEN_GPU_name_macro_( Kepler3 );
    _ASPEN_GPU_name_macro_( Maxwell );
    _ASPEN_GPU_name_macro_( Maxwell2 );
    _ASPEN_GPU_name_macro_( Maxwell3 );
    _ASPEN_GPU_name_macro_( Pascal );
    _ASPEN_GPU_name_macro_( Pascal1 );
    _ASPEN_GPU_name_macro_( Pascal2 );
    _ASPEN_GPU_name_macro_( Volta );
    _ASPEN_GPU_name_macro_( Volta2 );
    _ASPEN_GPU_name_macro_( Turing );
    _ASPEN_GPU_name_macro_( Ampere );
    _ASPEN_GPU_name_macro_( Ampere2 );
    _ASPEN_GPU_name_macro_( Ampere3 );
    _ASPEN_GPU_name_macro_( Ada );
    _ASPEN_GPU_name_macro_( Hopper );
    _ASPEN_GPU_name_macro_( Blackwell );
    _ASPEN_GPU_name_macro_( Blackwell2 );

  default: ret = (char *) "unknown"; break;
  }
  return ret;
}

#undef	_ASPEN_GPU_name_macro

//
// The macro __CUDA_ARCH__ is only available on the compilation for devices
// To use __CUDA_ARCH__ sometimes confuses us, so we separately compile
// the source code xxxx_X-template.cu by nvcc with an option such as
// --generate-code arch=compute_XX,code=compute_XX, and GPU_ARCH can be
// used for the distingishment of the GPU kernel.
//

#include "aspen_gpu_conf.h"



// definitions for generic macros
#define _MACRO_WRAP_(...)                       \
  do { { __VA_ARGS__; } break; } while( 0 )
#define _MACRO_BLOCK_		_MACRO_WRAP_

// Error check and safe invocation of the kernel function
#if 0
#define	ASPEN_KERNEL_INVOKE( kernel_name, ...)				\
  _MACRO_BLOCK_ (							\
                 kernel_name  __VA_ARGS__ ;				\
                 cudaError_t err = cudaGetLastError();			\
                 if ( err != cudaSuccess ) {				\
                   printf ( "ERROR in [%s] : %s \n",                    \
                            #kernel_name, cudaGetErrorString(err) );    \
                   exit ( 1 );                                          \
                   /* return; */					\
                 }							\
                                                                        )
#else
#define	ASPEN_KERNEL_INVOKE( kernel_name, ...)  \
  kernel_name  __VA_ARGS__ 
#endif

// this may be used as a spacer aginast 'const' and other attributes
#if 0
//
// __ is commented out, because __ results in the serious side-effect
// as __4 converted into 4 <= this cannot be avoided in the usage of cpp
//
#define	__				/*  2 */
#endif
#define	___				/*  3 */
#define	____				/*  4 */
#define	_____				/*  5 */
#define	______				/*  6 */
#define	_______				/*  7 */
#define	________			/*  8 */
#define	_________			/*  9 */
#define	__________			/* 10 */
#define	___________			/* 11 */
#define	____________			/* 12 */
#define	_____________			/* 13 */
#define	______________			/* 14 */
#define	_______________			/* 15 */
#define	________________		/* 16 */
#define	_________________		/* 17 */
#define	__________________		/* 18 */
#define	___________________		/* 19 */
#define	____________________		/* 20 */
#define	_____________________		/* 21 */
#define	______________________		/* 22 */
#define	_______________________		/* 23 */
#define	________________________	/* 24 */
#define	_________________________	/* 25 */
#define	__________________________	/* 26 */
#define	___________________________	/* 27 */
#define	____________________________	/* 28 */
#define	_____________________________	/* 29 */
#define	______________________________	/* 30 */

#define __LOOP_DIVIDER__(...)                   \
  asm volatile ( "// <- nop ->;" )

#if CUDA_VERSION >= 9000
#  define __sync_active_threads_in_warp(...)            \
  (cooperative_groups::coalesced_threads()).sync()
#else
#  define __sync_active_threads_in_warp(...)
#endif


#if defined(__CUDA_KERNEL__)
// __global__
#  define	__g_const__		__grid_constant__
#elif defined(__CUDA_ARCH__)
// __device__
#  define	__g_const__		const
#else
// __host__
#  define	__g_const__		const
#endif
#define	_Writable_ptr_(T)	T _____ * __restrict__ __g_const__
#define	_ReadOnly_ptr_(T)	T const * __restrict__ __g_const__


#if GPU_ARCH >= 700
__forceinline__ __device__ void
__FENCE__( void ) { asm volatile ( "fence.sc.cta;" ); }
__forceinline__ __device__ void
__FENCE_GPU__( void ) { asm volatile ( "fence.sc.gpu;" ); }
__forceinline__ __device__ void
__FENCE_SYS__( void ) { asm volatile ( "fence.sc.sys;" ); }
__forceinline__ __device__ void
__FENCE_FULL__( void ) { asm volatile ( "fence.sc.sys;" ); }
__forceinline__ __device__ void
__nanosleep__( void ) { asm volatile ( "nanosleep.u32 1;" ); }
__forceinline__ __device__ void
__nanosleep__( int const nsec ) { asm volatile ( "nanosleep.u32 %0;" :: "r"(nsec) ); }
#else
__forceinline__ __device__ void
__FENCE__( void ) { asm volatile ( "membar.cta;" ); }
__forceinline__ __device__ void
__FENCE_GPU__( void ) { asm volatile ( "membar.gl;" ); }
__forceinline__ __device__ void
__FENCE_SYS__( void ) { asm volatile ( "membar.sys;" ); }
__forceinline__ __device__ void
__FENCE_FULL__( void ) { asm volatile ( "membar.sys;" ); }
__forceinline__ __device__ void
__nanosleep__( void ) { ; }
__forceinline__ __device__ void
__nanosleep__( int const nsec ) { ; }
#endif


#include "aspen_shmem.h"
#include "aspen_types.h"
#include "aspen_texture.h"
#include "aspen_const.h"
#if 0
#include "aspen_atomic.h"
#endif
#include "aspen_ld_st.h"
#include "aspen_istypes.h"

#include "aspen_devel_func.h"

/* Utility functions for C APIs */
extern "C"  int     API(get_device_ID)       ( void );
extern "C"  int     API(get_tuned_gpuid)     ( void );
extern "C"  cudaStream_t API(get_Stream)     ( void );
extern "C"  void    API(set_Stream)          ( cudaStream_t st );
extern "C"  int     API(get_numbers_MP)      ( void );
extern "C"  void    API(get_device_Name)     ( char * name );
extern "C"  int     API(get_device_Major)    ( void );
extern "C"  int     API(get_device_Minor)    ( void );
extern "C"  int     API(get_device_CC)       ( void );
extern "C"  int     API(get_driver_Version)  ( void );
extern "C"  int     API(get_runtime_Version) ( void );
extern "C"  size_t  API(get_device_Memory)   ( void );
extern "C"  size_t  API(get_device_WorkSize) ( void );
extern "C"  void *  API(get_device_WorkArea) ( void );
extern "C"  void    API(get_version_info)    ( int *version, char *, char * );
extern "C"  void *  API(const_ZERO)          ( void );
extern "C"  void    API(max_freq)            ( void );


#include "aspen.h"



__forceinline__ __device__ uint32_t
__get_SMID( void )
{
  uint32_t r;
  asm volatile ( "mov.u32 %0, %smid;" : "=r"(r) );
  return r;
}

__forceinline__ __device__ uint64_t
__global_timer__( void )
{
  uint64_t r;
  asm volatile ( "mov.u64 %0, %globaltimer;" : "=l"(r) );
  return r;
}

__forceinline__ __host__ __device__ void *
__choose__( bool const flag, void const * a, void const * b )
{
  return (void *)(flag ? a : b);
}

#if 0
__forceinline__ __host__ __device__ int
INT_volatile( int const a )
{
  int b = static_cast<int>(a);
  asm volatile ( "// INT volatile" : "+r"(b) );
  return static_cast<int>(b);
}

__forceinline__ __host__ __device__ long
LONG_volatile( long const a )
{
  long b = static_cast<long>(a);
  asm volatile ( "// long volatile" : "+l"(b) );
  return static_cast<long>(b);
}

__forceinline__ __host__ __device__ void *
PTR_volatile( void const * a )
{
  void * b = (void *)(a);
  asm volatile ( "// PTR* volatile" : "+l"(b) );
  return (void *)b;
}
#endif

#define USE_ASM_INT		1
#define USE_ASM_MUL		1
#define USE_ASM_DIV		1

__forceinline__ __device__ int
INT_imin( int const a, int const b )
{
#if defined(min)
  return min(a, b);
#else
  int32_t const x = a, y = b;
  int32_t z;
#if USE_ASM_INT
  asm volatile ( "min.s32\t%0, %1, %2;"
                 : "=r"(z) : "r"(x), "r"(y) );
#else
  z = (x < y ? x : y);
#endif
  return static_cast<int>(z);
#endif
}

__forceinline__ __device__ int
INT_imax( int const a, int const b )
{
#if defined(max)
  return max(a, b);
#else
  int32_t const x = a, y = b;
  int32_t z;
#if USE_ASM_INT
  asm volatile ( "max.s32\t%0, %1, %2;"
                 : "=r"(z) : "r"(x), "r"(y) );
#else
  z = (x > y ? x : y);
#endif
  return static_cast<int>(z);
#endif
}


__forceinline__ __device__ int
INT_imul( int const a, int const b )
{
  int c;
#if USE_ASM_MUL
  asm volatile ( "mul.lo.s32\t%0, %1, %2;"
                 : "=r"(c) : "r"(a), "r"(b) );
#else
  c = a * b;
#endif
  return c;
}

__forceinline__ __device__ long
LONG_imul( int const a, int const b )
{
  long c_;
#if USE_ASM_MUL
  asm volatile ( "mul.wide.s32\t%0, %1, %2;"
                 : "=l"(c_) : "r"(a), "r"(b) );
#else
  long a_ = (long)a;
  long b_ = (long)b;
  c_ = a_ * b_;
#endif
  return c_;
}

__forceinline__ __device__ int
INT_imad( int const a, int const b, int const c )
{
  int d;
#if USE_ASM_MUL
  asm volatile ( "mad.lo.s32\t%0, %1, %2, %3;"
                 : "=r"(d) : "r"(a), "r"(b), "r"(c) );
#else
  d = a * b + c;
#endif
  return d;
}

__forceinline__ __device__ long
LONG_imad( int const a, int const b, int const c )
{
  long d_ = (long)c;
#if USE_ASM_MUL
  asm volatile ( "mad.wide.s32\t%0, %1, %2, %0;"
                 : "+l"(d_) : "r"(a), "r"(b) );
#else
  long a_ = (long)a;
  long b_ = (long)b;
  d_ = (a_ * b_ + d_);
#endif
  return d_;
}

__forceinline__ __device__ long
LONG_imad( int const a, int const b, long const c )
{
  long d_ = (long)c;
#if USE_ASM_MUL
  asm volatile ( "mad.wide.s32\t%0, %1, %2, %0;"
                 : "+l"(d_) : "r"(a), "r"(b) );
#else
  long a_ = (long)a;
  long b_ = (long)b;
  d_ = (a_ * b_ + d_);
#endif
  return d_;
}

__forceinline__ __device__ int
INT_idiv( int const a, int const b )
{
  uint32_t const x = a, y = b;
  uint32_t z;
#if USE_ASM_DIV
  asm volatile ( "div.u32\t%0, %1, %2;"
                 : "=r"(z) : "r"(x), "r"(y) );
#else
  z = x / y;
#endif
  return static_cast<int>(z);
}

__forceinline__ __device__ int
INT_irem( int const a, int const b )
{
  uint32_t const x = a, y = b;
  uint32_t z;
#if USE_ASM_DIV
  asm volatile ( "rem.u32\t%0, %1, %2;"
                 : "=r"(z) : "r"(x), "r"(y) );
#else
  z = x % y;
#endif
  return static_cast<int>(z);
}

__forceinline__ __device__ int
INT_floor( int const a, int const b )
{
  int32_t const z = a - INT_irem( a, b );
  return static_cast<int>(z);
}

__forceinline__ __device__ int
INT_ceil( int const a, int const b )
{
  int32_t const c = a + b - 1;
  int32_t const z = c - INT_irem( c, b );
  return static_cast<int>(z);
}

#endif

