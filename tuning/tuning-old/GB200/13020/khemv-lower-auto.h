#ifndef KHEMVL_AUTO_H_INCLUDED
#define KHEMVL_AUTO_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for KHEMVL
 Thu Jun 25 11:48:44  2026
 Host on ar09n01-m.ai.r-ccs.riken.jp
 Device is GB200
****************************************/-->
// device name
DEVICE= GB200
// the number of multi-processors
MP= 152
// compute-compatibility generation
CG= 1000
// capacity of the global memory or host memory
MAXmem= 197555425280
// capacity of the work area reserved on the GPU
WORK= 13067520
// for double or cuFloatComplex or int64
MAXDIM= 149287
// for float or cuHalfComplex or int32
MAXDIM2= 211124
// for cuDoubleComplex or DD or int128
MAXDIM3= 105562
// for DD-Complex
MAXDIM4= 74643
// for half or int16
MAXDIM5= 298574
// cuda version
CUDA= 13020
// ASPEN.K2 version
ASPEN_K2= 1.12 Shimada
<--
#define CURRENT_GPU 1000
-->
#endif
#ifndef	ASPEN_KHEMV_LOWER_AUTO
//
//======  'khemv-lower-auto.h'  =====//
//
{
    //==========
    if ( blk == -1 ) {
        #include "khemv-lower-auto2.h"
    }
    //==========

#if 0
    struct HESYMV_auto_tuning_param_t {
        int	BLOCK_SIZE, GY, VX, UX, MULTI, MX;
    } PARAM[21+1] = {
        { 128,   3,  1,  32,  4,  0 },
        { 128,   3,  3,  48,  2, 10 },
        { 128,   4,  2,  32,  3, 60 },
        { 128,   3,  3,  57,  2, 20 },
        { 128,   7,  2,  22,  3, 90 },
        {  64,   4,  6,  96,  2, 30 },
        {  32,   6,  1,   1,  1,  1 },
        {  32,   7,  1,   1,  1,  1 },
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
        khemv_lower_small ( n, alpha, a, lda, x, incx, beta, y, incy );
        break;
    #endif
    #if KERNEL_1
    case     1:
        API_private(HESYMVl_ATOMIC__host)
            < GPU_ARCH, scalar_t, 128,   3,  1,  32,  4,   0 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_2
    case     2:
        API_private(HESYMVl_ATOMIC__host)
            < GPU_ARCH, scalar_t, 128,   3,  3,  48,  2,  10 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_3
    case     3:
        API_private(HESYMVl_ATOMIC__host)
            < GPU_ARCH, scalar_t, 128,   4,  2,  32,  3,  60 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_4
    case     4:
        API_private(HESYMVl_ATOMIC__host)
            < GPU_ARCH, scalar_t, 128,   3,  3,  57,  2,  20 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_5
    case     5:
        API_private(HESYMVl_ATOMIC__host)
            < GPU_ARCH, scalar_t, 128,   7,  2,  22,  3,  90 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_6
    case     6:
        API_private(HESYMVl_ATOMIC__host)
            < GPU_ARCH, scalar_t,  64,   4,  6,  96,  2,  30 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_7
    case     7:
        API_private(HESYMVl_ATOMIC__host)
            < GPU_ARCH, scalar_t,  32,   6,  1,   1,  1,   1 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_8
    case     8:
        API_private(HESYMVl_ATOMIC__host)
            < GPU_ARCH, scalar_t,  32,   7,  1,   1,  1,   1 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_9
    case     9:
        API_private(HESYMVl_ATOMIC__host)
            < GPU_ARCH, scalar_t,  32,   8,  1,   1,  1,   1 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_10
    case    10:
        API_private(HESYMVl_ATOMIC__host)
            < GPU_ARCH, scalar_t,  32,   9,  1,   1,  1,   1 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_11
    case    11:
        API_private(HESYMVl_ATOMIC__host)
            < GPU_ARCH, scalar_t,  32,  10,  1,   1,  1,   1 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_12
    case    12:
        API_private(HESYMVl_ATOMIC__host)
            < GPU_ARCH, scalar_t,  32,  11,  1,   1,  1,   1 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_13
    case    13:
        API_private(HESYMVl_ATOMIC__host)
            < GPU_ARCH, scalar_t,  32,  12,  1,   1,  1,   1 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_14
    case    14:
        API_private(HESYMVl_ATOMIC__host)
            < GPU_ARCH, scalar_t,  32,  13,  1,   1,  1,   1 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_15
    case    15:
        API_private(HESYMVl_ATOMIC__host)
            < GPU_ARCH, scalar_t,  32,  14,  1,   1,  1,   1 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_16
    case    16:
        API_private(HESYMVl_ATOMIC__host)
            < GPU_ARCH, scalar_t,  32,  15,  1,   1,  1,   1 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_17
    case    17:
        API_private(HESYMVl_ATOMIC__host)
            < GPU_ARCH, scalar_t,  32,  16,  1,   1,  1,   1 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_18
    case    18:
        API_private(HESYMVl_ATOMIC__host)
            < GPU_ARCH, scalar_t,  32,  17,  1,   1,  1,   1 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_19
    case    19:
        API_private(HESYMVl_ATOMIC__host)
            < GPU_ARCH, scalar_t,  32,  18,  1,   1,  1,   1 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_20
    case    20:
        API_private(HESYMVl_ATOMIC__host)
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
//======  'khemv-lower-auto.h'  =====//
//
#define	ASPEN_KHEMV_LOWER_AUTO	1
#endif

#endif
