#ifndef WSYMVL_AUTO2_H_INCLUDED
#define WSYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for WSYMVL
 Wed Aug 05 09:48:24  2026
 Host on qc-gh200-01.cloud.r-ccs.riken.jp
 Device is GH200-480GB
****************************************/-->
// device name
DEVICE= GH200-480GB
// the number of multi-processors
MP= 132
// compute-compatibility generation
CG= 900
// capacity of the global memory or host memory
MAXmem= 101997334528
// capacity of the work area reserved on the GPU
WORK= 8136960
// for double or cuFloatComplex or int64
MAXDIM= 107268
// for float or cuHalfComplex or int32
MAXDIM2= 151700
// for cuDoubleComplex or DD or int128
MAXDIM3= 75850
// for DD-Complex
MAXDIM4= 53634
// for half or int16
MAXDIM5= 214537
// cuda version
CUDA= 13020
// ASPEN.K2 version
ASPEN_K2= 1.12 Shimada
<--
#define CURRENT_GPU 900
-->
#endif

#define	KERNEL_0	1
#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_4	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 2537 ) {
	BLK = 0;
} else
if ( n >= 2537 && n < 2538 ) {
	BLK = 2;
} else
if ( n >= 2538 && n < 2547 ) {
	BLK = 4;
} else
if ( n >= 2547 && n < 2548 ) {
	BLK = 0;
} else
if ( n >= 2548 && n < 2557 ) {
	BLK = 2;
} else
if ( n >= 2557 && n < 2688 ) {
	BLK = 4;
} else
if ( n >= 2688 && n < 2690 ) {
	BLK = 2;
} else
if ( n >= 2690 && n < 2702 ) {
	BLK = 0;
} else
if ( n >= 2702 && n < 2706 ) {
	BLK = 2;
} else
if ( n >= 2706 && n < 2833 ) {
	BLK = 4;
} else
if ( n >= 2833 && n < 2849 ) {
	BLK = 2;
} else
if ( n >= 2849 && n < 2879 ) {
	BLK = 4;
} else
if ( n >= 2879 && n < 2937 ) {
	BLK = 2;
} else
if ( n >= 2937 && n < 2943 ) {
	BLK = 1;
} else
if ( n >= 2943 && n < 2944 ) {
	BLK = 2;
} else
if ( n >= 2944 && n < 2954 ) {
	BLK = 4;
} else
if ( n >= 2954 && n < 2955 ) {
	BLK = 1;
} else
if ( n >= 2955 && n < 3103 ) {
	BLK = 2;
} else
if ( n >= 3103 && n < 3104 ) {
	BLK = 4;
} else
if ( n >= 3104 && n < 3116 ) {
	BLK = 1;
} else
if ( n >= 3116 && n < 3123 ) {
	BLK = 2;
} else
if ( n >= 3123 && n < 3124 ) {
	BLK = 4;
} else
if ( n >= 3124 && n < 3155 ) {
	BLK = 1;
} else
if ( n >= 3155 && n < 3171 ) {
	BLK = 2;
} else
if ( n >= 3171 && n < 3191 ) {
	BLK = 4;
} else
if ( n >= 3191 && n < 3200 ) {
	BLK = 1;
} else
if ( n >= 3200 && n < 3219 ) {
	BLK = 4;
} else
if ( n >= 3219 && n < 3220 ) {
	BLK = 2;
} else
if ( n >= 3220 && n < 3221 ) {
	BLK = 1;
} else
if ( n >= 3221 && n < 3264 ) {
	BLK = 4;
} else
if ( n >= 3264 && n < 3277 ) {
	BLK = 1;
} else
if ( n >= 3277 && n < 3333 ) {
	BLK = 2;
} else
if ( n >= 3333 && n < 3342 ) {
	BLK = 1;
} else
if ( n >= 3342 && n < 3413 ) {
	BLK = 4;
} else
if ( n >= 3413 && n < 3444 ) {
	BLK = 1;
} else
if ( n >= 3444 && n < 3447 ) {
	BLK = 2;
} else
if ( n >= 3447 && n < 3448 ) {
	BLK = 1;
} else
if ( n >= 3448 && n < 3472 ) {
	BLK = 4;
} else
if ( n >= 3472 && n < 3499 ) {
	BLK = 2;
} else
if ( n >= 3499 && n < 3509 ) {
	BLK = 4;
} else
if ( n >= 3509 && n < 3514 ) {
	BLK = 2;
} else
if ( n >= 3514 && n < 3515 ) {
	BLK = 4;
} else
if ( n >= 3515 && n < 3516 ) {
	BLK = 1;
} else
if ( n >= 3516 && n < 3543 ) {
	BLK = 2;
} else
if ( n >= 3543 && n < 3547 ) {
	BLK = 4;
} else
if ( n >= 3547 && n < 3549 ) {
	BLK = 2;
} else
if ( n >= 3549 && n < 3550 ) {
	BLK = 1;
} else
if ( n >= 3550 && n < 3565 ) {
	BLK = 4;
} else
if ( n >= 3565 && n < 3573 ) {
	BLK = 2;
} else
if ( n >= 3573 && n < 3589 ) {
	BLK = 1;
} else
if ( n >= 3589 && n < 3648 ) {
	BLK = 4;
} else
if ( n >= 3648 && n < 3657 ) {
	BLK = 1;
} else
if ( n >= 3657 && n < 3658 ) {
	BLK = 4;
} else
if ( n >= 3658 && n < 3664 ) {
	BLK = 2;
} else
if ( n >= 3664 && n < 3670 ) {
	BLK = 4;
} else
if ( n >= 3670 && n < 3713 ) {
	BLK = 2;
} else
if ( n >= 3713 && n < 3714 ) {
	BLK = 1;
} else
if ( n >= 3714 && n < 3716 ) {
	BLK = 4;
} else
if ( n >= 3716 && n < 3720 ) {
	BLK = 2;
} else
if ( n >= 3720 && n < 3721 ) {
	BLK = 1;
} else
if ( n >= 3721 && n < 3740 ) {
	BLK = 4;
} else
if ( n >= 3740 && n < 3741 ) {
	BLK = 1;
} else
if ( n >= 3741 && n < 3754 ) {
	BLK = 2;
} else
if ( n >= 3754 && n < 3767 ) {
	BLK = 4;
} else
if ( n >= 3767 && n < 3768 ) {
	BLK = 2;
} else
if ( n >= 3768 && n < 3769 ) {
	BLK = 1;
} else
if ( n >= 3769 && n < 3777 ) {
	BLK = 4;
} else
if ( n >= 3777 && n < 3778 ) {
	BLK = 1;
} else
if ( n >= 3778 && n < 3894 ) {
	BLK = 2;
} else
if ( n >= 3894 && n < 3896 ) {
	BLK = 1;
} else
if ( n >= 3896 && n < 3897 ) {
	BLK = 4;
} else
if ( n >= 3897 && n < 3925 ) {
	BLK = 2;
} else
if ( n >= 3925 && n < 3960 ) {
	BLK = 1;
} else
if ( n >= 3960 && n < 3970 ) {
	BLK = 2;
} else
if ( n >= 3970 && n < 3971 ) {
	BLK = 4;
} else
if ( n >= 3971 && n < 3972 ) {
	BLK = 1;
} else
if ( n >= 3972 && n < 5277 ) {
	BLK = 2;
} else
if ( n >= 5277 && n < 6134 ) {
	BLK = 1;
} else
if ( n >= 6134 && n < 7105 ) {
	BLK = 2;
} else
if ( n >= 7105 && n < 20454 ) {
	BLK = 1;
} else
if ( n >= 20454 && n < 21074 ) {
	BLK = 3;
} else
if ( n >= 21074 && n < 21410 ) {
	BLK = 1;
} else
if ( n >= 21410 && n < 22055 ) {
	BLK = 3;
} else
if ( n >= 22055 && n < 22384 ) {
	BLK = 1;
} else
if ( n >= 22384 && n < 2147483647 ) {
	BLK = 3;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 3;
} 

#endif
