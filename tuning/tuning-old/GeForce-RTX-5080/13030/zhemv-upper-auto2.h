#ifndef ZHEMVU_AUTO2_H_INCLUDED
#define ZHEMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for ZHEMVU
 Sat Aug 08 02:29:18  2026
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

if ( n >= 1 && n < 9 ) {
	BLK = 3;
} else
if ( n >= 9 && n < 10 ) {
	BLK = 2;
} else
if ( n >= 10 && n < 11 ) {
	BLK = 1;
} else
if ( n >= 11 && n < 17 ) {
	BLK = 3;
} else
if ( n >= 17 && n < 456 ) {
	BLK = 5;
} else
if ( n >= 456 && n < 528 ) {
	BLK = 2;
} else
if ( n >= 528 && n < 680 ) {
	BLK = 5;
} else
if ( n >= 680 && n < 706 ) {
	BLK = 1;
} else
if ( n >= 706 && n < 912 ) {
	BLK = 2;
} else
if ( n >= 912 && n < 968 ) {
	BLK = 3;
} else
if ( n >= 968 && n < 1918 ) {
	BLK = 5;
} else
if ( n >= 1918 && n < 2420 ) {
	BLK = 2;
} else
if ( n >= 2420 && n < 2421 ) {
	BLK = 3;
} else
if ( n >= 2421 && n < 2426 ) {
	BLK = 1;
} else
if ( n >= 2426 && n < 2430 ) {
	BLK = 2;
} else
if ( n >= 2430 && n < 2445 ) {
	BLK = 3;
} else
if ( n >= 2445 && n < 2448 ) {
	BLK = 2;
} else
if ( n >= 2448 && n < 2449 ) {
	BLK = 1;
} else
if ( n >= 2449 && n < 2450 ) {
	BLK = 3;
} else
if ( n >= 2450 && n < 2465 ) {
	BLK = 2;
} else
if ( n >= 2465 && n < 2470 ) {
	BLK = 1;
} else
if ( n >= 2470 && n < 2472 ) {
	BLK = 5;
} else
if ( n >= 2472 && n < 2473 ) {
	BLK = 3;
} else
if ( n >= 2473 && n < 2487 ) {
	BLK = 2;
} else
if ( n >= 2487 && n < 2494 ) {
	BLK = 1;
} else
if ( n >= 2494 && n < 2495 ) {
	BLK = 2;
} else
if ( n >= 2495 && n < 2496 ) {
	BLK = 3;
} else
if ( n >= 2496 && n < 2501 ) {
	BLK = 5;
} else
if ( n >= 2501 && n < 2505 ) {
	BLK = 3;
} else
if ( n >= 2505 && n < 2506 ) {
	BLK = 1;
} else
if ( n >= 2506 && n < 2507 ) {
	BLK = 2;
} else
if ( n >= 2507 && n < 2510 ) {
	BLK = 5;
} else
if ( n >= 2510 && n < 2513 ) {
	BLK = 1;
} else
if ( n >= 2513 && n < 2517 ) {
	BLK = 3;
} else
if ( n >= 2517 && n < 2518 ) {
	BLK = 5;
} else
if ( n >= 2518 && n < 2523 ) {
	BLK = 1;
} else
if ( n >= 2523 && n < 2525 ) {
	BLK = 2;
} else
if ( n >= 2525 && n < 2536 ) {
	BLK = 3;
} else
if ( n >= 2536 && n < 2537 ) {
	BLK = 1;
} else
if ( n >= 2537 && n < 2538 ) {
	BLK = 2;
} else
if ( n >= 2538 && n < 2567 ) {
	BLK = 3;
} else
if ( n >= 2567 && n < 2609 ) {
	BLK = 2;
} else
if ( n >= 2609 && n < 2610 ) {
	BLK = 1;
} else
if ( n >= 2610 && n < 2614 ) {
	BLK = 3;
} else
if ( n >= 2614 && n < 2627 ) {
	BLK = 2;
} else
if ( n >= 2627 && n < 2628 ) {
	BLK = 3;
} else
if ( n >= 2628 && n < 2632 ) {
	BLK = 1;
} else
if ( n >= 2632 && n < 2688 ) {
	BLK = 2;
} else
if ( n >= 2688 && n < 2690 ) {
	BLK = 3;
} else
if ( n >= 2690 && n < 2694 ) {
	BLK = 5;
} else
if ( n >= 2694 && n < 2695 ) {
	BLK = 3;
} else
if ( n >= 2695 && n < 2753 ) {
	BLK = 2;
} else
if ( n >= 2753 && n < 2754 ) {
	BLK = 3;
} else
if ( n >= 2754 && n < 2790 ) {
	BLK = 5;
} else
if ( n >= 2790 && n < 3706 ) {
	BLK = 2;
} else
if ( n >= 3706 && n < 3729 ) {
	BLK = 4;
} else
if ( n >= 3729 && n < 3730 ) {
	BLK = 1;
} else
if ( n >= 3730 && n < 3744 ) {
	BLK = 2;
} else
if ( n >= 3744 && n < 3799 ) {
	BLK = 4;
} else
if ( n >= 3799 && n < 3800 ) {
	BLK = 2;
} else
if ( n >= 3800 && n < 3809 ) {
	BLK = 1;
} else
if ( n >= 3809 && n < 3810 ) {
	BLK = 4;
} else
if ( n >= 3810 && n < 3811 ) {
	BLK = 2;
} else
if ( n >= 3811 && n < 3821 ) {
	BLK = 1;
} else
if ( n >= 3821 && n < 3859 ) {
	BLK = 4;
} else
if ( n >= 3859 && n < 3860 ) {
	BLK = 1;
} else
if ( n >= 3860 && n < 3861 ) {
	BLK = 2;
} else
if ( n >= 3861 && n < 3882 ) {
	BLK = 4;
} else
if ( n >= 3882 && n < 3886 ) {
	BLK = 1;
} else
if ( n >= 3886 && n < 3890 ) {
	BLK = 2;
} else
if ( n >= 3890 && n < 3899 ) {
	BLK = 4;
} else
if ( n >= 3899 && n < 3936 ) {
	BLK = 2;
} else
if ( n >= 3936 && n < 3961 ) {
	BLK = 1;
} else
if ( n >= 3961 && n < 4118 ) {
	BLK = 2;
} else
if ( n >= 4118 && n < 8008 ) {
	BLK = 1;
} else
if ( n >= 8008 && n < 8085 ) {
	BLK = 2;
} else
if ( n >= 8085 && n < 8179 ) {
	BLK = 3;
} else
if ( n >= 8179 && n < 8586 ) {
	BLK = 1;
} else
if ( n >= 8586 && n < 10663 ) {
	BLK = 2;
} else
if ( n >= 10663 && n < 10693 ) {
	BLK = 3;
} else
if ( n >= 10693 && n < 10817 ) {
	BLK = 1;
} else
if ( n >= 10817 && n < 11952 ) {
	BLK = 2;
} else
if ( n >= 11952 && n < 13149 ) {
	BLK = 3;
} else
if ( n >= 13149 && n < 13416 ) {
	BLK = 2;
} else
if ( n >= 13416 && n < 20489 ) {
	BLK = 3;
} else
if ( n >= 20489 && n < 20755 ) {
	BLK = 2;
} else
if ( n >= 20755 && n < 2147483647 ) {
	BLK = 3;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 3;
} 

#endif
