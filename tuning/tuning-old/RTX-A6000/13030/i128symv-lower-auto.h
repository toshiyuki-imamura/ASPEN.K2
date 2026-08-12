#ifndef I128SYMVL_AUTO_H_INCLUDED
#define I128SYMVL_AUTO_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I128SYMVL
 Mon Jul 27 02:12:57  2026
 Host on pascal.r-ccs27.riken.jp
 Device is RTX-A6000
****************************************/-->
// device name
DEVICE= RTX-A6000
// the number of multi-processors
MP= 84
// compute-compatibility generation
CG= 860
// capacity of the global memory or host memory
MAXmem= 50892406784
// capacity of the work area reserved on the GPU
WORK= 4421120
// for double or cuFloatComplex or int64
MAXDIM= 75771
// for float or cuHalfComplex or int32
MAXDIM2= 107156
// for cuDoubleComplex or DD or int128
MAXDIM3= 53578
// for DD-Complex
MAXDIM4= 37885
// for half or int16
MAXDIM5= 151542
// cuda version
CUDA= 13030
// ASPEN.K2 version
ASPEN_K2= 1.12 Shimada
<--
#define CURRENT_GPU 860
-->
#endif
#ifndef	ASPEN_I128SYMV_LOWER_AUTO
//
//======  'i128symv-lower-auto.h'  =====//
//
{
    //==========
    if ( blk == -1 ) {
        #include "i128symv-lower-auto2.h"
    }
    //==========

#if 0
    struct HESYMV_auto_tuning_param_t {
        int	BLOCK_SIZE, GY, VX, UX, MULTI, MX;
    } PARAM[21+1] = {
        {  96,   2,  1,  16,  2, 50 },
        { 128,   2,  2,  16,  2, 70 },
        { 160,   3,  1,  12,  2,  0 },
        {  64,   3,  4,  32,  2, 50 },
        { 128,   3,  1,  18,  2, 70 },
        { 160,   1,  1,  11,  2,  0 },
        { 192,   3,  1,  13,  2,  0 },
        { 192,   2,  1,  14,  2,  0 },
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
        i128symv_lower_small ( n, alpha, a, lda, x, incx, beta, y, incy );
        break;
    #endif
    #if KERNEL_1
    case     1:
        API_private(HESYMVl_ATOMIC__host)
            < GPU_ARCH, scalar_t,  96,   2,  1,  16,  2,  50 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_2
    case     2:
        API_private(HESYMVl_ATOMIC__host)
            < GPU_ARCH, scalar_t, 128,   2,  2,  16,  2,  70 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_3
    case     3:
        API_private(HESYMVl_ATOMIC__host)
            < GPU_ARCH, scalar_t, 160,   3,  1,  12,  2,   0 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_4
    case     4:
        API_private(HESYMVl_ATOMIC__host)
            < GPU_ARCH, scalar_t,  64,   3,  4,  32,  2,  50 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_5
    case     5:
        API_private(HESYMVl_ATOMIC__host)
            < GPU_ARCH, scalar_t, 128,   3,  1,  18,  2,  70 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_6
    case     6:
        API_private(HESYMVl_ATOMIC__host)
            < GPU_ARCH, scalar_t, 160,   1,  1,  11,  2,   0 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_7
    case     7:
        API_private(HESYMVl_ATOMIC__host)
            < GPU_ARCH, scalar_t, 192,   3,  1,  13,  2,   0 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_8
    case     8:
        API_private(HESYMVl_ATOMIC__host)
            < GPU_ARCH, scalar_t, 192,   2,  1,  14,  2,   0 >
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
//======  'i128symv-lower-auto.h'  =====//
//
#define	ASPEN_I128SYMV_LOWER_AUTO	1
#endif

#endif
