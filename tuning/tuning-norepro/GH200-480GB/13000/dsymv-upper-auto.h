#ifndef DSYMVU_AUTO_H_INCLUDED
#define DSYMVU_AUTO_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for DSYMVU
 Tue Feb 03 12:15:05  2026
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
MAXmem= 101999210496
// capacity of the work area reserved on the GPU
WORK= 6259200
// for double or cuFloatComplex or int64
MAXDIM= 107269
// for float or cuHalfComplex or int32
MAXDIM2= 151702
// for cuDoubleComplex or DD or int128
MAXDIM3= 75851
// for DD-Complex
MAXDIM4= 53634
// for half or int16
MAXDIM5= 214539
// cuda version
CUDA= 13010
// ASPEN.K2 version
ASPEN_K2= 1.11 Fujieda
<--
#define CURRENT_GPU 900
-->
#endif
#ifndef	ASPEN_DSYMV_UPPER_AUTO
//
//======  'dsymv-upper-auto.h'  =====//
//
{
    //==========
    if ( blk == -1 ) {
        #include "dsymv-upper-auto2.h"
    }
    //==========

#if 0
    struct HESYMV_auto_tuning_param_t {
        int	BLOCK_SIZE, GY, VX, UX, MULTI, MX;
    } PARAM[21+1] = {
        {  64,   8,  1,   8, 11, 60 },
        {  64,  11,  1,  16,  5,  0 },
        {  32,   9,  1,   8, 12, 10 },
        {  32,   9,  1,   5, 12, 60 },
        { 128,  10,  1,   8,  5, 60 },
        {  64,  11,  2,  20,  5, 80 },
        {  64,  10,  2,  24,  3,  0 },
        {  32,   8,  2,   8, 17, 10 },
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
        dsymv_upper_small ( n, alpha, a, lda, x, incx, beta, y, incy );
        break;
    #endif
    #if KERNEL_1
    case     1:
        API_private(HESYMVu_ATOMIC__host)
            < GPU_ARCH, scalar_t,  64,   8,  1,   8, 11,  60 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_2
    case     2:
        API_private(HESYMVu_ATOMIC__host)
            < GPU_ARCH, scalar_t,  64,  11,  1,  16,  5,   0 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_3
    case     3:
        API_private(HESYMVu_ATOMIC__host)
            < GPU_ARCH, scalar_t,  32,   9,  1,   8, 12,  10 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_4
    case     4:
        API_private(HESYMVu_ATOMIC__host)
            < GPU_ARCH, scalar_t,  32,   9,  1,   5, 12,  60 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_5
    case     5:
        API_private(HESYMVu_ATOMIC__host)
            < GPU_ARCH, scalar_t, 128,  10,  1,   8,  5,  60 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_6
    case     6:
        API_private(HESYMVu_ATOMIC__host)
            < GPU_ARCH, scalar_t,  64,  11,  2,  20,  5,  80 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_7
    case     7:
        API_private(HESYMVu_ATOMIC__host)
            < GPU_ARCH, scalar_t,  64,  10,  2,  24,  3,   0 >
            ( n, a, lda, x, incx, y, incy, alpha, beta ); break;
    #endif
    #if KERNEL_8
    case     8:
        API_private(HESYMVu_ATOMIC__host)
            < GPU_ARCH, scalar_t,  32,   8,  2,   8, 17,  10 >
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
//======  'dsymv-upper-auto.h'  =====//
//
#define	ASPEN_DSYMV_UPPER_AUTO	1
#endif

#endif
