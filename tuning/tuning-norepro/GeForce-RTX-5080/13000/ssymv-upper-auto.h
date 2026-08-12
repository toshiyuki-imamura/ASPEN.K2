#ifndef SSYMVU_AUTO_H_INCLUDED
#define SSYMVU_AUTO_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for SSYMVU
 Wed Nov 06 03:05:54  2024
 Host on newton.r-ccs27.riken.jp
 Device is GeForce-GTX-1080
****************************************/-->
// device name
DEVICE= GeForce-GTX-1080
// the number of multi-processors
MP= 20
// compute-compatibility generation
CG= 610
// capacity of the global memory or host memory
MAXmem= 8497229824
// capacity of the work area reserved on the GPU
WORK= 360960
// for double or cuFloatComplex or int64
MAXDIM= 30961
// for float or cuHalfComplex or int32
MAXDIM2= 43785
// for cuDoubleComplex or DD or int128
MAXDIM3= 21892
// for DD-Complex
MAXDIM4= 15480
// for half or int16
MAXDIM5= 61922
// cuda version
CUDA= 12060
// ASPEN.K2 version
ASPEN_K2= 1.11 Fujieda
<--
#define CURRENT_GPU 610
-->
#endif
#ifndef	ASPEN_SSYMV_UPPER_AUTO
//
//======  'ssymv-upper-auto.h'  =====//
//
{
    //==========
    if ( blk == -1 ) {
        #include "ssymv-upper-auto2.h"
    }
    //==========

#if 0
    struct HESYMV_auto_tuning_param_t {
        int	BLOCK_SIZE, GY, VX, UX, MULTI, MX;
    } PARAM[21+1] = {
        {  64,   1,  3,  33,  4,  0 },
        {  64,   2,  2,  22,  6,  0 },
        {  64,   3,  2,  34,  5,  0 },
        {  64,   2,  2,  28,  5,  0 },
        {  64,   4,  1,  32,  8, 70 },
        {  64,   1,  1,  26,  8,  0 },
        {  64,   3,  1,  25,  8,  0 },
        {  64,   2,  1,  28,  8,  0 },
        {  32,   8,  1,   1,  1,  1 },
        {  32,   9,  1,   1,  1,  1 },
        {  32,  10,  1,   1,  1,  1 },
        {  32,  11,  1,   1,  1,  1 },
        {  32,  12,  1,   1,  1,  1 },
        {  32,  13,  1,   1,  1,  1 },
        {  32,  14,  1,   1,  1,  1 },
        {  32,  15,  1,   1,  1,  1 },
        {  32,  16,  1,   1,  1,  1 },
        {  32,  17,  1,   1,  1,  1 },
        {  32,  18,  1,   1,  1,  1 },
        {  32,  19,  1,   1,  1,  1 },
        {   0,   0,  0,   0,  0,  0 },
    };
#endif

    //==========
    switch ( BLK ) {

    #if KERNEL_0
    case 0:
        ssymv_upper_small ( n, alpha, a, lda, x, incx, beta, y, incy );
        break;
    #endif
    #if KERNEL_1
    case     1:
        API_private(HESYMVu_ATOMIC__host)
            < GPU_ARCH, scalar_t,  64,   1,  3,  33,  4,   0 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_2
    case     2:
        API_private(HESYMVu_ATOMIC__host)
            < GPU_ARCH, scalar_t,  64,   2,  2,  22,  6,   0 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_3
    case     3:
        API_private(HESYMVu_ATOMIC__host)
            < GPU_ARCH, scalar_t,  64,   3,  2,  34,  5,   0 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_4
    case     4:
        API_private(HESYMVu_ATOMIC__host)
            < GPU_ARCH, scalar_t,  64,   2,  2,  28,  5,   0 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_5
    case     5:
        API_private(HESYMVu_ATOMIC__host)
            < GPU_ARCH, scalar_t,  64,   4,  1,  32,  8,  70 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_6
    case     6:
        API_private(HESYMVu_ATOMIC__host)
            < GPU_ARCH, scalar_t,  64,   1,  1,  26,  8,   0 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_7
    case     7:
        API_private(HESYMVu_ATOMIC__host)
            < GPU_ARCH, scalar_t,  64,   3,  1,  25,  8,   0 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_8
    case     8:
        API_private(HESYMVu_ATOMIC__host)
            < GPU_ARCH, scalar_t,  64,   2,  1,  28,  8,   0 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_9
    case     9:
        API_private(HESYMVu_ATOMIC__host)
            < GPU_ARCH, scalar_t,  32,   8,  1,   1,  1,   1 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_10
    case    10:
        API_private(HESYMVu_ATOMIC__host)
            < GPU_ARCH, scalar_t,  32,   9,  1,   1,  1,   1 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_11
    case    11:
        API_private(HESYMVu_ATOMIC__host)
            < GPU_ARCH, scalar_t,  32,  10,  1,   1,  1,   1 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_12
    case    12:
        API_private(HESYMVu_ATOMIC__host)
            < GPU_ARCH, scalar_t,  32,  11,  1,   1,  1,   1 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_13
    case    13:
        API_private(HESYMVu_ATOMIC__host)
            < GPU_ARCH, scalar_t,  32,  12,  1,   1,  1,   1 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_14
    case    14:
        API_private(HESYMVu_ATOMIC__host)
            < GPU_ARCH, scalar_t,  32,  13,  1,   1,  1,   1 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_15
    case    15:
        API_private(HESYMVu_ATOMIC__host)
            < GPU_ARCH, scalar_t,  32,  14,  1,   1,  1,   1 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_16
    case    16:
        API_private(HESYMVu_ATOMIC__host)
            < GPU_ARCH, scalar_t,  32,  15,  1,   1,  1,   1 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_17
    case    17:
        API_private(HESYMVu_ATOMIC__host)
            < GPU_ARCH, scalar_t,  32,  16,  1,   1,  1,   1 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_18
    case    18:
        API_private(HESYMVu_ATOMIC__host)
            < GPU_ARCH, scalar_t,  32,  17,  1,   1,  1,   1 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_19
    case    19:
        API_private(HESYMVu_ATOMIC__host)
            < GPU_ARCH, scalar_t,  32,  18,  1,   1,  1,   1 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_20
    case    20:
        API_private(HESYMVu_ATOMIC__host)
            < GPU_ARCH, scalar_t,  32,  19,  1,   1,  1,   1 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif

    default:
        // nothing to be done here
        break;
    }
    //==========

}
//
//======  'ssymv-upper-auto.h'  =====//
//
#define	ASPEN_SSYMV_UPPER_AUTO	1
#endif

#endif
