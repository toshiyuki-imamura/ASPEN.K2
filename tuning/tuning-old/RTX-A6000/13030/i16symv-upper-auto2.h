#ifndef I16SYMVU_AUTO2_H_INCLUDED
#define I16SYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I16SYMVU
 Fri Jul 24 18:09:22  2026
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

#define	KERNEL_0	1
#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 2266 ) {
	BLK = 0;
} else
if ( n >= 2266 && n < 2267 ) {
	BLK = 3;
} else
if ( n >= 2267 && n < 2268 ) {
	BLK = 2;
} else
if ( n >= 2268 && n < 2288 ) {
	BLK = 0;
} else
if ( n >= 2288 && n < 2290 ) {
	BLK = 2;
} else
if ( n >= 2290 && n < 2310 ) {
	BLK = 3;
} else
if ( n >= 2310 && n < 2313 ) {
	BLK = 0;
} else
if ( n >= 2313 && n < 2314 ) {
	BLK = 3;
} else
if ( n >= 2314 && n < 2315 ) {
	BLK = 2;
} else
if ( n >= 2315 && n < 2343 ) {
	BLK = 0;
} else
if ( n >= 2343 && n < 2344 ) {
	BLK = 2;
} else
if ( n >= 2344 && n < 2360 ) {
	BLK = 3;
} else
if ( n >= 2360 && n < 2366 ) {
	BLK = 0;
} else
if ( n >= 2366 && n < 2385 ) {
	BLK = 3;
} else
if ( n >= 2385 && n < 2386 ) {
	BLK = 0;
} else
if ( n >= 2386 && n < 2387 ) {
	BLK = 2;
} else
if ( n >= 2387 && n < 2409 ) {
	BLK = 3;
} else
if ( n >= 2409 && n < 2410 ) {
	BLK = 0;
} else
if ( n >= 2410 && n < 2411 ) {
	BLK = 2;
} else
if ( n >= 2411 && n < 2416 ) {
	BLK = 3;
} else
if ( n >= 2416 && n < 2417 ) {
	BLK = 1;
} else
if ( n >= 2417 && n < 2428 ) {
	BLK = 0;
} else
if ( n >= 2428 && n < 2429 ) {
	BLK = 1;
} else
if ( n >= 2429 && n < 2441 ) {
	BLK = 2;
} else
if ( n >= 2441 && n < 2442 ) {
	BLK = 1;
} else
if ( n >= 2442 && n < 2461 ) {
	BLK = 3;
} else
if ( n >= 2461 && n < 2462 ) {
	BLK = 0;
} else
if ( n >= 2462 && n < 2463 ) {
	BLK = 2;
} else
if ( n >= 2463 && n < 2473 ) {
	BLK = 3;
} else
if ( n >= 2473 && n < 2484 ) {
	BLK = 2;
} else
if ( n >= 2484 && n < 2485 ) {
	BLK = 1;
} else
if ( n >= 2485 && n < 2491 ) {
	BLK = 0;
} else
if ( n >= 2491 && n < 2496 ) {
	BLK = 2;
} else
if ( n >= 2496 && n < 2507 ) {
	BLK = 3;
} else
if ( n >= 2507 && n < 2508 ) {
	BLK = 2;
} else
if ( n >= 2508 && n < 2509 ) {
	BLK = 0;
} else
if ( n >= 2509 && n < 2529 ) {
	BLK = 3;
} else
if ( n >= 2529 && n < 2530 ) {
	BLK = 1;
} else
if ( n >= 2530 && n < 2551 ) {
	BLK = 2;
} else
if ( n >= 2551 && n < 2555 ) {
	BLK = 3;
} else
if ( n >= 2555 && n < 2556 ) {
	BLK = 1;
} else
if ( n >= 2556 && n < 2569 ) {
	BLK = 2;
} else
if ( n >= 2569 && n < 2584 ) {
	BLK = 3;
} else
if ( n >= 2584 && n < 2585 ) {
	BLK = 1;
} else
if ( n >= 2585 && n < 2636 ) {
	BLK = 2;
} else
if ( n >= 2636 && n < 2637 ) {
	BLK = 1;
} else
if ( n >= 2637 && n < 2682 ) {
	BLK = 3;
} else
if ( n >= 2682 && n < 2683 ) {
	BLK = 1;
} else
if ( n >= 2683 && n < 2685 ) {
	BLK = 2;
} else
if ( n >= 2685 && n < 2705 ) {
	BLK = 3;
} else
if ( n >= 2705 && n < 2709 ) {
	BLK = 2;
} else
if ( n >= 2709 && n < 2723 ) {
	BLK = 3;
} else
if ( n >= 2723 && n < 2736 ) {
	BLK = 2;
} else
if ( n >= 2736 && n < 2738 ) {
	BLK = 3;
} else
if ( n >= 2738 && n < 2739 ) {
	BLK = 1;
} else
if ( n >= 2739 && n < 2740 ) {
	BLK = 2;
} else
if ( n >= 2740 && n < 2748 ) {
	BLK = 3;
} else
if ( n >= 2748 && n < 2749 ) {
	BLK = 1;
} else
if ( n >= 2749 && n < 2754 ) {
	BLK = 2;
} else
if ( n >= 2754 && n < 2757 ) {
	BLK = 1;
} else
if ( n >= 2757 && n < 2782 ) {
	BLK = 3;
} else
if ( n >= 2782 && n < 2783 ) {
	BLK = 1;
} else
if ( n >= 2783 && n < 2803 ) {
	BLK = 2;
} else
if ( n >= 2803 && n < 2832 ) {
	BLK = 3;
} else
if ( n >= 2832 && n < 2833 ) {
	BLK = 1;
} else
if ( n >= 2833 && n < 2838 ) {
	BLK = 2;
} else
if ( n >= 2838 && n < 2968 ) {
	BLK = 3;
} else
if ( n >= 2968 && n < 2969 ) {
	BLK = 2;
} else
if ( n >= 2969 && n < 2970 ) {
	BLK = 1;
} else
if ( n >= 2970 && n < 2975 ) {
	BLK = 3;
} else
if ( n >= 2975 && n < 2976 ) {
	BLK = 1;
} else
if ( n >= 2976 && n < 2982 ) {
	BLK = 2;
} else
if ( n >= 2982 && n < 2997 ) {
	BLK = 3;
} else
if ( n >= 2997 && n < 2998 ) {
	BLK = 1;
} else
if ( n >= 2998 && n < 3007 ) {
	BLK = 2;
} else
if ( n >= 3007 && n < 3030 ) {
	BLK = 3;
} else
if ( n >= 3030 && n < 3031 ) {
	BLK = 2;
} else
if ( n >= 3031 && n < 3032 ) {
	BLK = 1;
} else
if ( n >= 3032 && n < 3090 ) {
	BLK = 3;
} else
if ( n >= 3090 && n < 3091 ) {
	BLK = 1;
} else
if ( n >= 3091 && n < 3147 ) {
	BLK = 2;
} else
if ( n >= 3147 && n < 3148 ) {
	BLK = 1;
} else
if ( n >= 3148 && n < 3210 ) {
	BLK = 3;
} else
if ( n >= 3210 && n < 3211 ) {
	BLK = 1;
} else
if ( n >= 3211 && n < 3226 ) {
	BLK = 2;
} else
if ( n >= 3226 && n < 3229 ) {
	BLK = 3;
} else
if ( n >= 3229 && n < 3230 ) {
	BLK = 1;
} else
if ( n >= 3230 && n < 3249 ) {
	BLK = 2;
} else
if ( n >= 3249 && n < 4093 ) {
	BLK = 3;
} else
if ( n >= 4093 && n < 4094 ) {
	BLK = 2;
} else
if ( n >= 4094 && n < 4096 ) {
	BLK = 1;
} else
if ( n >= 4096 && n < 4870 ) {
	BLK = 3;
} else
if ( n >= 4870 && n < 4873 ) {
	BLK = 2;
} else
if ( n >= 4873 && n < 4973 ) {
	BLK = 1;
} else
if ( n >= 4973 && n < 4994 ) {
	BLK = 2;
} else
if ( n >= 4994 && n < 5077 ) {
	BLK = 1;
} else
if ( n >= 5077 && n < 5079 ) {
	BLK = 2;
} else
if ( n >= 5079 && n < 5187 ) {
	BLK = 3;
} else
if ( n >= 5187 && n < 5197 ) {
	BLK = 2;
} else
if ( n >= 5197 && n < 5199 ) {
	BLK = 1;
} else
if ( n >= 5199 && n < 5342 ) {
	BLK = 3;
} else
if ( n >= 5342 && n < 5354 ) {
	BLK = 2;
} else
if ( n >= 5354 && n < 5355 ) {
	BLK = 1;
} else
if ( n >= 5355 && n < 5374 ) {
	BLK = 3;
} else
if ( n >= 5374 && n < 5393 ) {
	BLK = 2;
} else
if ( n >= 5393 && n < 5397 ) {
	BLK = 1;
} else
if ( n >= 5397 && n < 5511 ) {
	BLK = 3;
} else
if ( n >= 5511 && n < 5518 ) {
	BLK = 2;
} else
if ( n >= 5518 && n < 5534 ) {
	BLK = 1;
} else
if ( n >= 5534 && n < 5631 ) {
	BLK = 3;
} else
if ( n >= 5631 && n < 5650 ) {
	BLK = 2;
} else
if ( n >= 5650 && n < 5655 ) {
	BLK = 1;
} else
if ( n >= 5655 && n < 5739 ) {
	BLK = 3;
} else
if ( n >= 5739 && n < 5751 ) {
	BLK = 2;
} else
if ( n >= 5751 && n < 5764 ) {
	BLK = 1;
} else
if ( n >= 5764 && n < 5895 ) {
	BLK = 3;
} else
if ( n >= 5895 && n < 5909 ) {
	BLK = 2;
} else
if ( n >= 5909 && n < 6014 ) {
	BLK = 1;
} else
if ( n >= 6014 && n < 6072 ) {
	BLK = 3;
} else
if ( n >= 6072 && n < 6290 ) {
	BLK = 2;
} else
if ( n >= 6290 && n < 6326 ) {
	BLK = 1;
} else
if ( n >= 6326 && n < 6343 ) {
	BLK = 3;
} else
if ( n >= 6343 && n < 6440 ) {
	BLK = 2;
} else
if ( n >= 6440 && n < 6518 ) {
	BLK = 3;
} else
if ( n >= 6518 && n < 6548 ) {
	BLK = 1;
} else
if ( n >= 6548 && n < 6602 ) {
	BLK = 2;
} else
if ( n >= 6602 && n < 6622 ) {
	BLK = 1;
} else
if ( n >= 6622 && n < 6638 ) {
	BLK = 3;
} else
if ( n >= 6638 && n < 6659 ) {
	BLK = 2;
} else
if ( n >= 6659 && n < 6696 ) {
	BLK = 1;
} else
if ( n >= 6696 && n < 6727 ) {
	BLK = 3;
} else
if ( n >= 6727 && n < 6800 ) {
	BLK = 2;
} else
if ( n >= 6800 && n < 7127 ) {
	BLK = 1;
} else
if ( n >= 7127 && n < 7130 ) {
	BLK = 2;
} else
if ( n >= 7130 && n < 7144 ) {
	BLK = 3;
} else
if ( n >= 7144 && n < 7834 ) {
	BLK = 1;
} else
if ( n >= 7834 && n < 7883 ) {
	BLK = 3;
} else
if ( n >= 7883 && n < 7894 ) {
	BLK = 2;
} else
if ( n >= 7894 && n < 10535 ) {
	BLK = 1;
} else
if ( n >= 10535 && n < 10651 ) {
	BLK = 2;
} else
if ( n >= 10651 && n < 50597 ) {
	BLK = 1;
} else
if ( n >= 50597 && n < 51782 ) {
	BLK = 3;
} else
if ( n >= 51782 && n < 79843 ) {
	BLK = 1;
} else
if ( n >= 79843 && n < 80730 ) {
	BLK = 3;
} else
if ( n >= 80730 && n < 130550 ) {
	BLK = 1;
} else
if ( n >= 130550 && n < 131745 ) {
	BLK = 3;
} else
if ( n >= 131745 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
