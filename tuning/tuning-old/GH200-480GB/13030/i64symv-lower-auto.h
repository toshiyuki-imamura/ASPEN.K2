#ifndef I64SYMVL_AUTO_H_INCLUDED
#define I64SYMVL_AUTO_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I64SYMVL
 Wed Sep 30 04:35:14  2026
 Host on qc-gh200-02.cloud.r-ccs.riken.jp
 Device is GH200-480GB
****************************************/-->
// device name
DEVICE= GH200-480GB
// the number of multi-processors
MP= 132
// compute-compatibility generation
CG= 900
// capacity of the global memory or host memory
MAXmem= 102123945984
// capacity of the work area reserved on the GPU
WORK= 8140288
// for double or cuFloatComplex or int64
MAXDIM= 107335
// for float or cuHalfComplex or int32
MAXDIM2= 151794
// for cuDoubleComplex or DD or int128
MAXDIM3= 75897
// for DD-Complex
MAXDIM4= 53667
// for half or int16
MAXDIM5= 214670
// cuda version
CUDA= 13040
// ASPEN.K2 version
ASPEN_K2= 1.13 Kanaya
<--
#define CURRENT_GPU 900
-->
#endif
#ifndef	ASPEN_I64SYMV_LOWER_AUTO
//
//======  'i64symv-lower-auto.h'  =====//
//
{
    //==========
    if ( blk == -1 ) {
        #include "i64symv-lower-auto2.h"
    }
    //==========

#if 0
    struct HESYMV_auto_tuning_param_t {
        int	BLOCK_SIZE, GY, VX, UX, MULTI, MX;
    } PARAM[21+1] = {
        { 128,   4,  1,  26,  3,  0 },
        {  96,   4,  4,  36,  2, 60 },
        { 128,   5,  2,  42,  2,  0 },
        {  64,   9,  1,  26,  6,  0 },
        {  96,   6,  4,  28,  2, 10 },
        { 160,   3,  3,  12,  2, 10 },
        { 128,   4,  3,  27,  2,  0 },
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
    int constexpr REPRO = 1;
    switch ( BLK ) {

    #if KERNEL_0
    case 0:
        i64symv_lower_small ( n, alpha, a, lda, x, incx, beta, y, incy );
        break;
    #endif
    #if KERNEL_1
    case     1:
        API_private(HESYMVl_ATOMIC__host)
            < REPRO, scalar_t, 128,   4,  1,  26,  3,   0 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_2
    case     2:
        API_private(HESYMVl_ATOMIC__host)
            < REPRO, scalar_t,  96,   4,  4,  36,  2,  60 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_3
    case     3:
        API_private(HESYMVl_ATOMIC__host)
            < REPRO, scalar_t, 128,   5,  2,  42,  2,   0 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_4
    case     4:
        API_private(HESYMVl_ATOMIC__host)
            < REPRO, scalar_t,  64,   9,  1,  26,  6,   0 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_5
    case     5:
        API_private(HESYMVl_ATOMIC__host)
            < REPRO, scalar_t,  96,   6,  4,  28,  2,  10 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_6
    case     6:
        API_private(HESYMVl_ATOMIC__host)
            < REPRO, scalar_t, 160,   3,  3,  12,  2,  10 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_7
    case     7:
        API_private(HESYMVl_ATOMIC__host)
            < REPRO, scalar_t, 128,   4,  3,  27,  2,   0 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_8
    case     8:
        API_private(HESYMVl_ATOMIC__host)
            < REPRO, scalar_t,  32,   7,  1,   1,  1,   1 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_9
    case     9:
        API_private(HESYMVl_ATOMIC__host)
            < REPRO, scalar_t,  32,   8,  1,   1,  1,   1 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_10
    case    10:
        API_private(HESYMVl_ATOMIC__host)
            < REPRO, scalar_t,  32,   9,  1,   1,  1,   1 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_11
    case    11:
        API_private(HESYMVl_ATOMIC__host)
            < REPRO, scalar_t,  32,  10,  1,   1,  1,   1 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_12
    case    12:
        API_private(HESYMVl_ATOMIC__host)
            < REPRO, scalar_t,  32,  11,  1,   1,  1,   1 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_13
    case    13:
        API_private(HESYMVl_ATOMIC__host)
            < REPRO, scalar_t,  32,  12,  1,   1,  1,   1 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_14
    case    14:
        API_private(HESYMVl_ATOMIC__host)
            < REPRO, scalar_t,  32,  13,  1,   1,  1,   1 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_15
    case    15:
        API_private(HESYMVl_ATOMIC__host)
            < REPRO, scalar_t,  32,  14,  1,   1,  1,   1 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_16
    case    16:
        API_private(HESYMVl_ATOMIC__host)
            < REPRO, scalar_t,  32,  15,  1,   1,  1,   1 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_17
    case    17:
        API_private(HESYMVl_ATOMIC__host)
            < REPRO, scalar_t,  32,  16,  1,   1,  1,   1 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_18
    case    18:
        API_private(HESYMVl_ATOMIC__host)
            < REPRO, scalar_t,  32,  17,  1,   1,  1,   1 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_19
    case    19:
        API_private(HESYMVl_ATOMIC__host)
            < REPRO, scalar_t,  32,  18,  1,   1,  1,   1 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_20
    case    20:
        API_private(HESYMVl_ATOMIC__host)
            < REPRO, scalar_t,  32,  19,  1,   1,  1,   1 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif

    default:
        // nothing to be done here
        break;
    }
    //==========

}
//
//======  'i64symv-lower-auto.h'  =====//
//
#define	ASPEN_I64SYMV_LOWER_AUTO	1
#endif

#endif
