#ifndef I16SYMVU_AUTO2_H_INCLUDED
#define I16SYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I16SYMVU
 Thu Aug 06 01:33:13  2026
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
#define	KERNEL_5	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 2377 ) {
	BLK = 0;
} else
if ( n >= 2377 && n < 2380 ) {
	BLK = 1;
} else
if ( n >= 2380 && n < 2463 ) {
	BLK = 0;
} else
if ( n >= 2463 && n < 2480 ) {
	BLK = 1;
} else
if ( n >= 2480 && n < 2494 ) {
	BLK = 0;
} else
if ( n >= 2494 && n < 2558 ) {
	BLK = 2;
} else
if ( n >= 2558 && n < 2559 ) {
	BLK = 4;
} else
if ( n >= 2559 && n < 2605 ) {
	BLK = 1;
} else
if ( n >= 2605 && n < 2606 ) {
	BLK = 2;
} else
if ( n >= 2606 && n < 2607 ) {
	BLK = 0;
} else
if ( n >= 2607 && n < 2646 ) {
	BLK = 1;
} else
if ( n >= 2646 && n < 2654 ) {
	BLK = 2;
} else
if ( n >= 2654 && n < 2679 ) {
	BLK = 1;
} else
if ( n >= 2679 && n < 2685 ) {
	BLK = 2;
} else
if ( n >= 2685 && n < 2697 ) {
	BLK = 0;
} else
if ( n >= 2697 && n < 2704 ) {
	BLK = 1;
} else
if ( n >= 2704 && n < 2719 ) {
	BLK = 0;
} else
if ( n >= 2719 && n < 2728 ) {
	BLK = 1;
} else
if ( n >= 2728 && n < 2799 ) {
	BLK = 0;
} else
if ( n >= 2799 && n < 2800 ) {
	BLK = 1;
} else
if ( n >= 2800 && n < 2807 ) {
	BLK = 2;
} else
if ( n >= 2807 && n < 2809 ) {
	BLK = 0;
} else
if ( n >= 2809 && n < 2810 ) {
	BLK = 1;
} else
if ( n >= 2810 && n < 2813 ) {
	BLK = 2;
} else
if ( n >= 2813 && n < 2842 ) {
	BLK = 0;
} else
if ( n >= 2842 && n < 2861 ) {
	BLK = 2;
} else
if ( n >= 2861 && n < 2869 ) {
	BLK = 1;
} else
if ( n >= 2869 && n < 2876 ) {
	BLK = 0;
} else
if ( n >= 2876 && n < 2879 ) {
	BLK = 2;
} else
if ( n >= 2879 && n < 2893 ) {
	BLK = 1;
} else
if ( n >= 2893 && n < 2909 ) {
	BLK = 0;
} else
if ( n >= 2909 && n < 2911 ) {
	BLK = 2;
} else
if ( n >= 2911 && n < 2934 ) {
	BLK = 1;
} else
if ( n >= 2934 && n < 3007 ) {
	BLK = 0;
} else
if ( n >= 3007 && n < 3024 ) {
	BLK = 1;
} else
if ( n >= 3024 && n < 3025 ) {
	BLK = 2;
} else
if ( n >= 3025 && n < 3035 ) {
	BLK = 0;
} else
if ( n >= 3035 && n < 3036 ) {
	BLK = 1;
} else
if ( n >= 3036 && n < 3062 ) {
	BLK = 2;
} else
if ( n >= 3062 && n < 3063 ) {
	BLK = 0;
} else
if ( n >= 3063 && n < 3066 ) {
	BLK = 1;
} else
if ( n >= 3066 && n < 3067 ) {
	BLK = 2;
} else
if ( n >= 3067 && n < 3068 ) {
	BLK = 0;
} else
if ( n >= 3068 && n < 3148 ) {
	BLK = 1;
} else
if ( n >= 3148 && n < 3179 ) {
	BLK = 2;
} else
if ( n >= 3179 && n < 3182 ) {
	BLK = 1;
} else
if ( n >= 3182 && n < 3184 ) {
	BLK = 0;
} else
if ( n >= 3184 && n < 3188 ) {
	BLK = 2;
} else
if ( n >= 3188 && n < 3189 ) {
	BLK = 1;
} else
if ( n >= 3189 && n < 3199 ) {
	BLK = 0;
} else
if ( n >= 3199 && n < 3211 ) {
	BLK = 1;
} else
if ( n >= 3211 && n < 3212 ) {
	BLK = 2;
} else
if ( n >= 3212 && n < 3263 ) {
	BLK = 0;
} else
if ( n >= 3263 && n < 3264 ) {
	BLK = 2;
} else
if ( n >= 3264 && n < 3312 ) {
	BLK = 1;
} else
if ( n >= 3312 && n < 3578 ) {
	BLK = 0;
} else
if ( n >= 3578 && n < 3597 ) {
	BLK = 2;
} else
if ( n >= 3597 && n < 3605 ) {
	BLK = 0;
} else
if ( n >= 3605 && n < 3608 ) {
	BLK = 2;
} else
if ( n >= 3608 && n < 3609 ) {
	BLK = 1;
} else
if ( n >= 3609 && n < 3639 ) {
	BLK = 0;
} else
if ( n >= 3639 && n < 3641 ) {
	BLK = 1;
} else
if ( n >= 3641 && n < 3652 ) {
	BLK = 2;
} else
if ( n >= 3652 && n < 3940 ) {
	BLK = 1;
} else
if ( n >= 3940 && n < 4094 ) {
	BLK = 0;
} else
if ( n >= 4094 && n < 4095 ) {
	BLK = 2;
} else
if ( n >= 4095 && n < 4194 ) {
	BLK = 1;
} else
if ( n >= 4194 && n < 4214 ) {
	BLK = 0;
} else
if ( n >= 4214 && n < 4221 ) {
	BLK = 2;
} else
if ( n >= 4221 && n < 4301 ) {
	BLK = 1;
} else
if ( n >= 4301 && n < 4366 ) {
	BLK = 0;
} else
if ( n >= 4366 && n < 4369 ) {
	BLK = 1;
} else
if ( n >= 4369 && n < 4377 ) {
	BLK = 2;
} else
if ( n >= 4377 && n < 4409 ) {
	BLK = 0;
} else
if ( n >= 4409 && n < 4528 ) {
	BLK = 1;
} else
if ( n >= 4528 && n < 4532 ) {
	BLK = 0;
} else
if ( n >= 4532 && n < 4790 ) {
	BLK = 2;
} else
if ( n >= 4790 && n < 6123 ) {
	BLK = 1;
} else
if ( n >= 6123 && n < 13568 ) {
	BLK = 4;
} else
if ( n >= 13568 && n < 104249 ) {
	BLK = 3;
} else
if ( n >= 104249 && n < 108986 ) {
	BLK = 5;
} else
if ( n >= 108986 && n < 155317 ) {
	BLK = 3;
} else
if ( n >= 155317 && n < 159875 ) {
	BLK = 5;
} else
if ( n >= 159875 && n < 181336 ) {
	BLK = 3;
} else
if ( n >= 181336 && n < 196145 ) {
	BLK = 5;
} else
if ( n >= 196145 && n < 2147483647 ) {
	BLK = 3;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 3;
} 

#endif
