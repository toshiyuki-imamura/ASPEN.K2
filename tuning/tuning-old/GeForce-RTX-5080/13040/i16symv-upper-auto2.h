#ifndef I16SYMVU_AUTO2_H_INCLUDED
#define I16SYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I16SYMVU
 Sat Sep 26 10:35:03  2026
 Host on cauchy.r-ccs27.riken.jp
 Device is GeForce-RTX-5080
****************************************/-->
// device name
DEVICE= GeForce-RTX-5080
// the number of multi-processors
MP= 84
// compute-compatibility generation
CG= 1200
// capacity of the global memory or host memory
MAXmem= 16702066688
// capacity of the work area reserved on the GPU
WORK= 2531840
// for double or cuFloatComplex or int64
MAXDIM= 43407
// for float or cuHalfComplex or int32
MAXDIM2= 61387
// for cuDoubleComplex or DD or int128
MAXDIM3= 30693
// for DD-Complex
MAXDIM4= 21703
// for half or int16
MAXDIM5= 86814
// cuda version
CUDA= 13040
// ASPEN.K2 version
ASPEN_K2= 1.13 Kanaya
<--
#define CURRENT_GPU 1200
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

if ( n >= 1 && n < 415 ) {
	BLK = 0;
} else
if ( n >= 415 && n < 417 ) {
	BLK = 4;
} else
if ( n >= 417 && n < 509 ) {
	BLK = 1;
} else
if ( n >= 509 && n < 510 ) {
	BLK = 4;
} else
if ( n >= 510 && n < 2095 ) {
	BLK = 0;
} else
if ( n >= 2095 && n < 2096 ) {
	BLK = 2;
} else
if ( n >= 2096 && n < 2097 ) {
	BLK = 5;
} else
if ( n >= 2097 && n < 2106 ) {
	BLK = 0;
} else
if ( n >= 2106 && n < 2107 ) {
	BLK = 1;
} else
if ( n >= 2107 && n < 2114 ) {
	BLK = 2;
} else
if ( n >= 2114 && n < 2409 ) {
	BLK = 0;
} else
if ( n >= 2409 && n < 2412 ) {
	BLK = 2;
} else
if ( n >= 2412 && n < 2421 ) {
	BLK = 5;
} else
if ( n >= 2421 && n < 2422 ) {
	BLK = 1;
} else
if ( n >= 2422 && n < 2423 ) {
	BLK = 0;
} else
if ( n >= 2423 && n < 2424 ) {
	BLK = 2;
} else
if ( n >= 2424 && n < 2444 ) {
	BLK = 5;
} else
if ( n >= 2444 && n < 2450 ) {
	BLK = 2;
} else
if ( n >= 2450 && n < 2455 ) {
	BLK = 5;
} else
if ( n >= 2455 && n < 2456 ) {
	BLK = 1;
} else
if ( n >= 2456 && n < 2459 ) {
	BLK = 0;
} else
if ( n >= 2459 && n < 2460 ) {
	BLK = 5;
} else
if ( n >= 2460 && n < 2461 ) {
	BLK = 1;
} else
if ( n >= 2461 && n < 2480 ) {
	BLK = 2;
} else
if ( n >= 2480 && n < 2481 ) {
	BLK = 1;
} else
if ( n >= 2481 && n < 2495 ) {
	BLK = 0;
} else
if ( n >= 2495 && n < 2503 ) {
	BLK = 2;
} else
if ( n >= 2503 && n < 2511 ) {
	BLK = 0;
} else
if ( n >= 2511 && n < 2517 ) {
	BLK = 5;
} else
if ( n >= 2517 && n < 2518 ) {
	BLK = 2;
} else
if ( n >= 2518 && n < 2522 ) {
	BLK = 0;
} else
if ( n >= 2522 && n < 2523 ) {
	BLK = 5;
} else
if ( n >= 2523 && n < 2530 ) {
	BLK = 2;
} else
if ( n >= 2530 && n < 2541 ) {
	BLK = 0;
} else
if ( n >= 2541 && n < 2558 ) {
	BLK = 2;
} else
if ( n >= 2558 && n < 2559 ) {
	BLK = 1;
} else
if ( n >= 2559 && n < 2585 ) {
	BLK = 5;
} else
if ( n >= 2585 && n < 2588 ) {
	BLK = 2;
} else
if ( n >= 2588 && n < 2593 ) {
	BLK = 1;
} else
if ( n >= 2593 && n < 2603 ) {
	BLK = 5;
} else
if ( n >= 2603 && n < 2604 ) {
	BLK = 1;
} else
if ( n >= 2604 && n < 2608 ) {
	BLK = 2;
} else
if ( n >= 2608 && n < 2641 ) {
	BLK = 5;
} else
if ( n >= 2641 && n < 2642 ) {
	BLK = 2;
} else
if ( n >= 2642 && n < 2649 ) {
	BLK = 0;
} else
if ( n >= 2649 && n < 2650 ) {
	BLK = 2;
} else
if ( n >= 2650 && n < 2692 ) {
	BLK = 5;
} else
if ( n >= 2692 && n < 2693 ) {
	BLK = 2;
} else
if ( n >= 2693 && n < 2698 ) {
	BLK = 0;
} else
if ( n >= 2698 && n < 2706 ) {
	BLK = 5;
} else
if ( n >= 2706 && n < 2707 ) {
	BLK = 2;
} else
if ( n >= 2707 && n < 2724 ) {
	BLK = 0;
} else
if ( n >= 2724 && n < 2786 ) {
	BLK = 5;
} else
if ( n >= 2786 && n < 2791 ) {
	BLK = 0;
} else
if ( n >= 2791 && n < 2792 ) {
	BLK = 5;
} else
if ( n >= 2792 && n < 2796 ) {
	BLK = 1;
} else
if ( n >= 2796 && n < 2814 ) {
	BLK = 5;
} else
if ( n >= 2814 && n < 2815 ) {
	BLK = 0;
} else
if ( n >= 2815 && n < 2816 ) {
	BLK = 2;
} else
if ( n >= 2816 && n < 2901 ) {
	BLK = 5;
} else
if ( n >= 2901 && n < 2904 ) {
	BLK = 0;
} else
if ( n >= 2904 && n < 2906 ) {
	BLK = 1;
} else
if ( n >= 2906 && n < 2907 ) {
	BLK = 5;
} else
if ( n >= 2907 && n < 2914 ) {
	BLK = 0;
} else
if ( n >= 2914 && n < 2915 ) {
	BLK = 5;
} else
if ( n >= 2915 && n < 2916 ) {
	BLK = 2;
} else
if ( n >= 2916 && n < 2918 ) {
	BLK = 1;
} else
if ( n >= 2918 && n < 2928 ) {
	BLK = 0;
} else
if ( n >= 2928 && n < 2957 ) {
	BLK = 5;
} else
if ( n >= 2957 && n < 2958 ) {
	BLK = 2;
} else
if ( n >= 2958 && n < 2959 ) {
	BLK = 0;
} else
if ( n >= 2959 && n < 2965 ) {
	BLK = 5;
} else
if ( n >= 2965 && n < 2966 ) {
	BLK = 2;
} else
if ( n >= 2966 && n < 2967 ) {
	BLK = 0;
} else
if ( n >= 2967 && n < 2973 ) {
	BLK = 5;
} else
if ( n >= 2973 && n < 2974 ) {
	BLK = 1;
} else
if ( n >= 2974 && n < 2976 ) {
	BLK = 2;
} else
if ( n >= 2976 && n < 2979 ) {
	BLK = 5;
} else
if ( n >= 2979 && n < 2980 ) {
	BLK = 2;
} else
if ( n >= 2980 && n < 2981 ) {
	BLK = 1;
} else
if ( n >= 2981 && n < 2999 ) {
	BLK = 5;
} else
if ( n >= 2999 && n < 3000 ) {
	BLK = 1;
} else
if ( n >= 3000 && n < 3001 ) {
	BLK = 2;
} else
if ( n >= 3001 && n < 3702 ) {
	BLK = 5;
} else
if ( n >= 3702 && n < 3703 ) {
	BLK = 2;
} else
if ( n >= 3703 && n < 3704 ) {
	BLK = 1;
} else
if ( n >= 3704 && n < 3731 ) {
	BLK = 5;
} else
if ( n >= 3731 && n < 3740 ) {
	BLK = 2;
} else
if ( n >= 3740 && n < 3741 ) {
	BLK = 1;
} else
if ( n >= 3741 && n < 3784 ) {
	BLK = 5;
} else
if ( n >= 3784 && n < 3906 ) {
	BLK = 2;
} else
if ( n >= 3906 && n < 3907 ) {
	BLK = 1;
} else
if ( n >= 3907 && n < 3929 ) {
	BLK = 5;
} else
if ( n >= 3929 && n < 3930 ) {
	BLK = 1;
} else
if ( n >= 3930 && n < 6511 ) {
	BLK = 2;
} else
if ( n >= 6511 && n < 12136 ) {
	BLK = 3;
} else
if ( n >= 12136 && n < 14881 ) {
	BLK = 5;
} else
if ( n >= 14881 && n < 21761 ) {
	BLK = 2;
} else
if ( n >= 21761 && n < 22206 ) {
	BLK = 4;
} else
if ( n >= 22206 && n < 22737 ) {
	BLK = 2;
} else
if ( n >= 22737 && n < 24375 ) {
	BLK = 4;
} else
if ( n >= 24375 && n < 25022 ) {
	BLK = 5;
} else
if ( n >= 25022 && n < 36644 ) {
	BLK = 4;
} else
if ( n >= 36644 && n < 37796 ) {
	BLK = 5;
} else
if ( n >= 37796 && n < 41866 ) {
	BLK = 4;
} else
if ( n >= 41866 && n < 42207 ) {
	BLK = 5;
} else
if ( n >= 42207 && n < 48453 ) {
	BLK = 4;
} else
if ( n >= 48453 && n < 50281 ) {
	BLK = 5;
} else
if ( n >= 50281 && n < 53423 ) {
	BLK = 4;
} else
if ( n >= 53423 && n < 56350 ) {
	BLK = 5;
} else
if ( n >= 56350 && n < 67720 ) {
	BLK = 4;
} else
if ( n >= 67720 && n < 71436 ) {
	BLK = 5;
} else
if ( n >= 71436 && n < 2147483647 ) {
	BLK = 4;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 4;
} 

#endif
