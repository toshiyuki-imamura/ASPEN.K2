#ifndef ZHEMVL_AUTO2_H_INCLUDED
#define ZHEMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for ZHEMVL
 Sat Aug 08 16:08:13  2026
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
MAXmem= 16647024640
// capacity of the work area reserved on the GPU
WORK= 2526720
// for double or cuFloatComplex or int64
MAXDIM= 43335
// for float or cuHalfComplex or int32
MAXDIM2= 61286
// for cuDoubleComplex or DD or int128
MAXDIM3= 30643
// for DD-Complex
MAXDIM4= 21667
// for half or int16
MAXDIM5= 86671
// cuda version
CUDA= 13030
// ASPEN.K2 version
ASPEN_K2= 1.12 Shimada
<--
#define CURRENT_GPU 1200
-->
#endif

#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_4	1
#define	KERNEL_5	1


// default kernel is
BLK = 1;

if ( n >= 1 && n < 4 ) {
	BLK = 1;
} else
if ( n >= 4 && n < 8 ) {
	BLK = 3;
} else
if ( n >= 8 && n < 9 ) {
	BLK = 4;
} else
if ( n >= 9 && n < 12 ) {
	BLK = 1;
} else
if ( n >= 12 && n < 16 ) {
	BLK = 2;
} else
if ( n >= 16 && n < 18 ) {
	BLK = 4;
} else
if ( n >= 18 && n < 2016 ) {
	BLK = 3;
} else
if ( n >= 2016 && n < 2048 ) {
	BLK = 2;
} else
if ( n >= 2048 && n < 2207 ) {
	BLK = 5;
} else
if ( n >= 2207 && n < 2208 ) {
	BLK = 2;
} else
if ( n >= 2208 && n < 2239 ) {
	BLK = 3;
} else
if ( n >= 2239 && n < 2269 ) {
	BLK = 1;
} else
if ( n >= 2269 && n < 2415 ) {
	BLK = 5;
} else
if ( n >= 2415 && n < 2683 ) {
	BLK = 2;
} else
if ( n >= 2683 && n < 2688 ) {
	BLK = 3;
} else
if ( n >= 2688 && n < 2720 ) {
	BLK = 1;
} else
if ( n >= 2720 && n < 2784 ) {
	BLK = 2;
} else
if ( n >= 2784 && n < 2812 ) {
	BLK = 3;
} else
if ( n >= 2812 && n < 2813 ) {
	BLK = 1;
} else
if ( n >= 2813 && n < 2814 ) {
	BLK = 2;
} else
if ( n >= 2814 && n < 3136 ) {
	BLK = 3;
} else
if ( n >= 3136 && n < 3144 ) {
	BLK = 4;
} else
if ( n >= 3144 && n < 3145 ) {
	BLK = 2;
} else
if ( n >= 3145 && n < 3146 ) {
	BLK = 1;
} else
if ( n >= 3146 && n < 3329 ) {
	BLK = 4;
} else
if ( n >= 3329 && n < 3330 ) {
	BLK = 2;
} else
if ( n >= 3330 && n < 3340 ) {
	BLK = 3;
} else
if ( n >= 3340 && n < 3353 ) {
	BLK = 2;
} else
if ( n >= 3353 && n < 3354 ) {
	BLK = 3;
} else
if ( n >= 3354 && n < 3456 ) {
	BLK = 4;
} else
if ( n >= 3456 && n < 3496 ) {
	BLK = 3;
} else
if ( n >= 3496 && n < 3503 ) {
	BLK = 5;
} else
if ( n >= 3503 && n < 3504 ) {
	BLK = 3;
} else
if ( n >= 3504 && n < 3509 ) {
	BLK = 2;
} else
if ( n >= 3509 && n < 3521 ) {
	BLK = 5;
} else
if ( n >= 3521 && n < 3522 ) {
	BLK = 1;
} else
if ( n >= 3522 && n < 3529 ) {
	BLK = 3;
} else
if ( n >= 3529 && n < 3530 ) {
	BLK = 1;
} else
if ( n >= 3530 && n < 3531 ) {
	BLK = 4;
} else
if ( n >= 3531 && n < 3534 ) {
	BLK = 3;
} else
if ( n >= 3534 && n < 3535 ) {
	BLK = 2;
} else
if ( n >= 3535 && n < 3538 ) {
	BLK = 1;
} else
if ( n >= 3538 && n < 3541 ) {
	BLK = 5;
} else
if ( n >= 3541 && n < 3542 ) {
	BLK = 4;
} else
if ( n >= 3542 && n < 3543 ) {
	BLK = 3;
} else
if ( n >= 3543 && n < 3587 ) {
	BLK = 5;
} else
if ( n >= 3587 && n < 3595 ) {
	BLK = 1;
} else
if ( n >= 3595 && n < 3598 ) {
	BLK = 2;
} else
if ( n >= 3598 && n < 3599 ) {
	BLK = 5;
} else
if ( n >= 3599 && n < 3603 ) {
	BLK = 1;
} else
if ( n >= 3603 && n < 3604 ) {
	BLK = 5;
} else
if ( n >= 3604 && n < 3605 ) {
	BLK = 2;
} else
if ( n >= 3605 && n < 3609 ) {
	BLK = 1;
} else
if ( n >= 3609 && n < 3610 ) {
	BLK = 5;
} else
if ( n >= 3610 && n < 3611 ) {
	BLK = 2;
} else
if ( n >= 3611 && n < 3619 ) {
	BLK = 1;
} else
if ( n >= 3619 && n < 3624 ) {
	BLK = 3;
} else
if ( n >= 3624 && n < 3625 ) {
	BLK = 5;
} else
if ( n >= 3625 && n < 3629 ) {
	BLK = 2;
} else
if ( n >= 3629 && n < 3655 ) {
	BLK = 5;
} else
if ( n >= 3655 && n < 3657 ) {
	BLK = 3;
} else
if ( n >= 3657 && n < 3658 ) {
	BLK = 1;
} else
if ( n >= 3658 && n < 3807 ) {
	BLK = 5;
} else
if ( n >= 3807 && n < 3808 ) {
	BLK = 3;
} else
if ( n >= 3808 && n < 3809 ) {
	BLK = 1;
} else
if ( n >= 3809 && n < 3811 ) {
	BLK = 2;
} else
if ( n >= 3811 && n < 3812 ) {
	BLK = 3;
} else
if ( n >= 3812 && n < 3816 ) {
	BLK = 1;
} else
if ( n >= 3816 && n < 3817 ) {
	BLK = 4;
} else
if ( n >= 3817 && n < 3819 ) {
	BLK = 2;
} else
if ( n >= 3819 && n < 3977 ) {
	BLK = 1;
} else
if ( n >= 3977 && n < 3978 ) {
	BLK = 3;
} else
if ( n >= 3978 && n < 3979 ) {
	BLK = 2;
} else
if ( n >= 3979 && n < 9233 ) {
	BLK = 1;
} else
if ( n >= 9233 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
