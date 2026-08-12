#ifndef I32SYMVL_AUTO2_H_INCLUDED
#define I32SYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I32SYMVL
 Fri Aug 07 17:30:54  2026
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

#define	KERNEL_0	1
#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_4	1
#define	KERNEL_5	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 254 ) {
	BLK = 0;
} else
if ( n >= 254 && n < 256 ) {
	BLK = 2;
} else
if ( n >= 256 && n < 271 ) {
	BLK = 4;
} else
if ( n >= 271 && n < 272 ) {
	BLK = 2;
} else
if ( n >= 272 && n < 278 ) {
	BLK = 0;
} else
if ( n >= 278 && n < 286 ) {
	BLK = 4;
} else
if ( n >= 286 && n < 287 ) {
	BLK = 0;
} else
if ( n >= 287 && n < 288 ) {
	BLK = 2;
} else
if ( n >= 288 && n < 291 ) {
	BLK = 1;
} else
if ( n >= 291 && n < 299 ) {
	BLK = 0;
} else
if ( n >= 299 && n < 303 ) {
	BLK = 1;
} else
if ( n >= 303 && n < 305 ) {
	BLK = 2;
} else
if ( n >= 305 && n < 328 ) {
	BLK = 0;
} else
if ( n >= 328 && n < 329 ) {
	BLK = 4;
} else
if ( n >= 329 && n < 332 ) {
	BLK = 2;
} else
if ( n >= 332 && n < 346 ) {
	BLK = 0;
} else
if ( n >= 346 && n < 348 ) {
	BLK = 4;
} else
if ( n >= 348 && n < 349 ) {
	BLK = 1;
} else
if ( n >= 349 && n < 366 ) {
	BLK = 0;
} else
if ( n >= 366 && n < 369 ) {
	BLK = 4;
} else
if ( n >= 369 && n < 371 ) {
	BLK = 1;
} else
if ( n >= 371 && n < 1158 ) {
	BLK = 0;
} else
if ( n >= 1158 && n < 1217 ) {
	BLK = 3;
} else
if ( n >= 1217 && n < 1219 ) {
	BLK = 0;
} else
if ( n >= 1219 && n < 1221 ) {
	BLK = 1;
} else
if ( n >= 1221 && n < 1405 ) {
	BLK = 3;
} else
if ( n >= 1405 && n < 1481 ) {
	BLK = 0;
} else
if ( n >= 1481 && n < 1559 ) {
	BLK = 3;
} else
if ( n >= 1559 && n < 1560 ) {
	BLK = 5;
} else
if ( n >= 1560 && n < 1561 ) {
	BLK = 1;
} else
if ( n >= 1561 && n < 1623 ) {
	BLK = 3;
} else
if ( n >= 1623 && n < 1624 ) {
	BLK = 2;
} else
if ( n >= 1624 && n < 1660 ) {
	BLK = 1;
} else
if ( n >= 1660 && n < 1661 ) {
	BLK = 0;
} else
if ( n >= 1661 && n < 1672 ) {
	BLK = 3;
} else
if ( n >= 1672 && n < 1713 ) {
	BLK = 1;
} else
if ( n >= 1713 && n < 1714 ) {
	BLK = 3;
} else
if ( n >= 1714 && n < 1715 ) {
	BLK = 0;
} else
if ( n >= 1715 && n < 1724 ) {
	BLK = 1;
} else
if ( n >= 1724 && n < 1741 ) {
	BLK = 3;
} else
if ( n >= 1741 && n < 1742 ) {
	BLK = 5;
} else
if ( n >= 1742 && n < 1746 ) {
	BLK = 1;
} else
if ( n >= 1746 && n < 1770 ) {
	BLK = 3;
} else
if ( n >= 1770 && n < 1771 ) {
	BLK = 1;
} else
if ( n >= 1771 && n < 1773 ) {
	BLK = 2;
} else
if ( n >= 1773 && n < 1792 ) {
	BLK = 3;
} else
if ( n >= 1792 && n < 1793 ) {
	BLK = 5;
} else
if ( n >= 1793 && n < 1794 ) {
	BLK = 1;
} else
if ( n >= 1794 && n < 1815 ) {
	BLK = 3;
} else
if ( n >= 1815 && n < 1816 ) {
	BLK = 1;
} else
if ( n >= 1816 && n < 1817 ) {
	BLK = 0;
} else
if ( n >= 1817 && n < 1923 ) {
	BLK = 3;
} else
if ( n >= 1923 && n < 1924 ) {
	BLK = 1;
} else
if ( n >= 1924 && n < 1925 ) {
	BLK = 2;
} else
if ( n >= 1925 && n < 1955 ) {
	BLK = 3;
} else
if ( n >= 1955 && n < 1956 ) {
	BLK = 2;
} else
if ( n >= 1956 && n < 2022 ) {
	BLK = 1;
} else
if ( n >= 2022 && n < 2023 ) {
	BLK = 2;
} else
if ( n >= 2023 && n < 2083 ) {
	BLK = 3;
} else
if ( n >= 2083 && n < 2084 ) {
	BLK = 5;
} else
if ( n >= 2084 && n < 2085 ) {
	BLK = 2;
} else
if ( n >= 2085 && n < 2187 ) {
	BLK = 3;
} else
if ( n >= 2187 && n < 2206 ) {
	BLK = 1;
} else
if ( n >= 2206 && n < 2207 ) {
	BLK = 5;
} else
if ( n >= 2207 && n < 2237 ) {
	BLK = 3;
} else
if ( n >= 2237 && n < 2245 ) {
	BLK = 2;
} else
if ( n >= 2245 && n < 2246 ) {
	BLK = 5;
} else
if ( n >= 2246 && n < 2264 ) {
	BLK = 3;
} else
if ( n >= 2264 && n < 2271 ) {
	BLK = 2;
} else
if ( n >= 2271 && n < 2275 ) {
	BLK = 3;
} else
if ( n >= 2275 && n < 2276 ) {
	BLK = 5;
} else
if ( n >= 2276 && n < 2277 ) {
	BLK = 1;
} else
if ( n >= 2277 && n < 2282 ) {
	BLK = 3;
} else
if ( n >= 2282 && n < 2283 ) {
	BLK = 2;
} else
if ( n >= 2283 && n < 2284 ) {
	BLK = 1;
} else
if ( n >= 2284 && n < 2292 ) {
	BLK = 3;
} else
if ( n >= 2292 && n < 2293 ) {
	BLK = 2;
} else
if ( n >= 2293 && n < 2294 ) {
	BLK = 1;
} else
if ( n >= 2294 && n < 2312 ) {
	BLK = 3;
} else
if ( n >= 2312 && n < 2313 ) {
	BLK = 1;
} else
if ( n >= 2313 && n < 2314 ) {
	BLK = 2;
} else
if ( n >= 2314 && n < 2326 ) {
	BLK = 3;
} else
if ( n >= 2326 && n < 2327 ) {
	BLK = 1;
} else
if ( n >= 2327 && n < 2331 ) {
	BLK = 2;
} else
if ( n >= 2331 && n < 2335 ) {
	BLK = 3;
} else
if ( n >= 2335 && n < 2337 ) {
	BLK = 1;
} else
if ( n >= 2337 && n < 2341 ) {
	BLK = 2;
} else
if ( n >= 2341 && n < 2366 ) {
	BLK = 3;
} else
if ( n >= 2366 && n < 2367 ) {
	BLK = 1;
} else
if ( n >= 2367 && n < 2369 ) {
	BLK = 5;
} else
if ( n >= 2369 && n < 2370 ) {
	BLK = 3;
} else
if ( n >= 2370 && n < 2371 ) {
	BLK = 1;
} else
if ( n >= 2371 && n < 2374 ) {
	BLK = 5;
} else
if ( n >= 2374 && n < 2376 ) {
	BLK = 2;
} else
if ( n >= 2376 && n < 2381 ) {
	BLK = 3;
} else
if ( n >= 2381 && n < 2382 ) {
	BLK = 5;
} else
if ( n >= 2382 && n < 2392 ) {
	BLK = 2;
} else
if ( n >= 2392 && n < 2396 ) {
	BLK = 3;
} else
if ( n >= 2396 && n < 2398 ) {
	BLK = 2;
} else
if ( n >= 2398 && n < 2399 ) {
	BLK = 5;
} else
if ( n >= 2399 && n < 2402 ) {
	BLK = 1;
} else
if ( n >= 2402 && n < 2411 ) {
	BLK = 2;
} else
if ( n >= 2411 && n < 2420 ) {
	BLK = 3;
} else
if ( n >= 2420 && n < 2421 ) {
	BLK = 5;
} else
if ( n >= 2421 && n < 2425 ) {
	BLK = 2;
} else
if ( n >= 2425 && n < 2428 ) {
	BLK = 1;
} else
if ( n >= 2428 && n < 2433 ) {
	BLK = 3;
} else
if ( n >= 2433 && n < 2446 ) {
	BLK = 1;
} else
if ( n >= 2446 && n < 2449 ) {
	BLK = 2;
} else
if ( n >= 2449 && n < 2452 ) {
	BLK = 3;
} else
if ( n >= 2452 && n < 2459 ) {
	BLK = 2;
} else
if ( n >= 2459 && n < 2467 ) {
	BLK = 3;
} else
if ( n >= 2467 && n < 2474 ) {
	BLK = 1;
} else
if ( n >= 2474 && n < 2475 ) {
	BLK = 3;
} else
if ( n >= 2475 && n < 2478 ) {
	BLK = 2;
} else
if ( n >= 2478 && n < 2480 ) {
	BLK = 1;
} else
if ( n >= 2480 && n < 2481 ) {
	BLK = 3;
} else
if ( n >= 2481 && n < 2482 ) {
	BLK = 2;
} else
if ( n >= 2482 && n < 2483 ) {
	BLK = 1;
} else
if ( n >= 2483 && n < 2484 ) {
	BLK = 3;
} else
if ( n >= 2484 && n < 2485 ) {
	BLK = 2;
} else
if ( n >= 2485 && n < 2491 ) {
	BLK = 1;
} else
if ( n >= 2491 && n < 2503 ) {
	BLK = 2;
} else
if ( n >= 2503 && n < 2504 ) {
	BLK = 1;
} else
if ( n >= 2504 && n < 2505 ) {
	BLK = 5;
} else
if ( n >= 2505 && n < 2506 ) {
	BLK = 3;
} else
if ( n >= 2506 && n < 2522 ) {
	BLK = 2;
} else
if ( n >= 2522 && n < 2523 ) {
	BLK = 3;
} else
if ( n >= 2523 && n < 2524 ) {
	BLK = 1;
} else
if ( n >= 2524 && n < 2525 ) {
	BLK = 2;
} else
if ( n >= 2525 && n < 2526 ) {
	BLK = 3;
} else
if ( n >= 2526 && n < 2528 ) {
	BLK = 5;
} else
if ( n >= 2528 && n < 2548 ) {
	BLK = 2;
} else
if ( n >= 2548 && n < 2549 ) {
	BLK = 1;
} else
if ( n >= 2549 && n < 2552 ) {
	BLK = 3;
} else
if ( n >= 2552 && n < 2556 ) {
	BLK = 1;
} else
if ( n >= 2556 && n < 2557 ) {
	BLK = 3;
} else
if ( n >= 2557 && n < 2558 ) {
	BLK = 2;
} else
if ( n >= 2558 && n < 2569 ) {
	BLK = 1;
} else
if ( n >= 2569 && n < 2570 ) {
	BLK = 3;
} else
if ( n >= 2570 && n < 2604 ) {
	BLK = 2;
} else
if ( n >= 2604 && n < 2608 ) {
	BLK = 3;
} else
if ( n >= 2608 && n < 2625 ) {
	BLK = 1;
} else
if ( n >= 2625 && n < 2626 ) {
	BLK = 2;
} else
if ( n >= 2626 && n < 2627 ) {
	BLK = 3;
} else
if ( n >= 2627 && n < 2650 ) {
	BLK = 1;
} else
if ( n >= 2650 && n < 2653 ) {
	BLK = 2;
} else
if ( n >= 2653 && n < 2672 ) {
	BLK = 1;
} else
if ( n >= 2672 && n < 2675 ) {
	BLK = 3;
} else
if ( n >= 2675 && n < 2721 ) {
	BLK = 1;
} else
if ( n >= 2721 && n < 2722 ) {
	BLK = 3;
} else
if ( n >= 2722 && n < 2747 ) {
	BLK = 2;
} else
if ( n >= 2747 && n < 2756 ) {
	BLK = 1;
} else
if ( n >= 2756 && n < 2762 ) {
	BLK = 2;
} else
if ( n >= 2762 && n < 2768 ) {
	BLK = 3;
} else
if ( n >= 2768 && n < 2773 ) {
	BLK = 1;
} else
if ( n >= 2773 && n < 2774 ) {
	BLK = 5;
} else
if ( n >= 2774 && n < 2776 ) {
	BLK = 2;
} else
if ( n >= 2776 && n < 2788 ) {
	BLK = 1;
} else
if ( n >= 2788 && n < 2791 ) {
	BLK = 2;
} else
if ( n >= 2791 && n < 2792 ) {
	BLK = 3;
} else
if ( n >= 2792 && n < 2807 ) {
	BLK = 1;
} else
if ( n >= 2807 && n < 2808 ) {
	BLK = 2;
} else
if ( n >= 2808 && n < 2809 ) {
	BLK = 5;
} else
if ( n >= 2809 && n < 2814 ) {
	BLK = 1;
} else
if ( n >= 2814 && n < 2815 ) {
	BLK = 3;
} else
if ( n >= 2815 && n < 2816 ) {
	BLK = 2;
} else
if ( n >= 2816 && n < 2817 ) {
	BLK = 1;
} else
if ( n >= 2817 && n < 2821 ) {
	BLK = 5;
} else
if ( n >= 2821 && n < 2853 ) {
	BLK = 1;
} else
if ( n >= 2853 && n < 2868 ) {
	BLK = 5;
} else
if ( n >= 2868 && n < 2893 ) {
	BLK = 1;
} else
if ( n >= 2893 && n < 2894 ) {
	BLK = 5;
} else
if ( n >= 2894 && n < 2910 ) {
	BLK = 2;
} else
if ( n >= 2910 && n < 2911 ) {
	BLK = 5;
} else
if ( n >= 2911 && n < 2941 ) {
	BLK = 1;
} else
if ( n >= 2941 && n < 2942 ) {
	BLK = 2;
} else
if ( n >= 2942 && n < 2944 ) {
	BLK = 3;
} else
if ( n >= 2944 && n < 3524 ) {
	BLK = 1;
} else
if ( n >= 3524 && n < 3525 ) {
	BLK = 3;
} else
if ( n >= 3525 && n < 3526 ) {
	BLK = 5;
} else
if ( n >= 3526 && n < 3546 ) {
	BLK = 1;
} else
if ( n >= 3546 && n < 3547 ) {
	BLK = 5;
} else
if ( n >= 3547 && n < 3557 ) {
	BLK = 3;
} else
if ( n >= 3557 && n < 3684 ) {
	BLK = 1;
} else
if ( n >= 3684 && n < 3686 ) {
	BLK = 3;
} else
if ( n >= 3686 && n < 3690 ) {
	BLK = 2;
} else
if ( n >= 3690 && n < 3702 ) {
	BLK = 1;
} else
if ( n >= 3702 && n < 3703 ) {
	BLK = 5;
} else
if ( n >= 3703 && n < 3704 ) {
	BLK = 3;
} else
if ( n >= 3704 && n < 3709 ) {
	BLK = 1;
} else
if ( n >= 3709 && n < 3710 ) {
	BLK = 5;
} else
if ( n >= 3710 && n < 3711 ) {
	BLK = 3;
} else
if ( n >= 3711 && n < 3730 ) {
	BLK = 1;
} else
if ( n >= 3730 && n < 3731 ) {
	BLK = 2;
} else
if ( n >= 3731 && n < 3732 ) {
	BLK = 5;
} else
if ( n >= 3732 && n < 3740 ) {
	BLK = 1;
} else
if ( n >= 3740 && n < 3741 ) {
	BLK = 2;
} else
if ( n >= 3741 && n < 3744 ) {
	BLK = 5;
} else
if ( n >= 3744 && n < 3826 ) {
	BLK = 1;
} else
if ( n >= 3826 && n < 3827 ) {
	BLK = 2;
} else
if ( n >= 3827 && n < 3829 ) {
	BLK = 5;
} else
if ( n >= 3829 && n < 3835 ) {
	BLK = 1;
} else
if ( n >= 3835 && n < 3836 ) {
	BLK = 5;
} else
if ( n >= 3836 && n < 3838 ) {
	BLK = 2;
} else
if ( n >= 3838 && n < 3853 ) {
	BLK = 1;
} else
if ( n >= 3853 && n < 3854 ) {
	BLK = 3;
} else
if ( n >= 3854 && n < 3855 ) {
	BLK = 2;
} else
if ( n >= 3855 && n < 3908 ) {
	BLK = 1;
} else
if ( n >= 3908 && n < 3909 ) {
	BLK = 2;
} else
if ( n >= 3909 && n < 3918 ) {
	BLK = 5;
} else
if ( n >= 3918 && n < 3948 ) {
	BLK = 2;
} else
if ( n >= 3948 && n < 3988 ) {
	BLK = 1;
} else
if ( n >= 3988 && n < 3991 ) {
	BLK = 5;
} else
if ( n >= 3991 && n < 4012 ) {
	BLK = 1;
} else
if ( n >= 4012 && n < 4015 ) {
	BLK = 2;
} else
if ( n >= 4015 && n < 4016 ) {
	BLK = 5;
} else
if ( n >= 4016 && n < 4059 ) {
	BLK = 1;
} else
if ( n >= 4059 && n < 4060 ) {
	BLK = 5;
} else
if ( n >= 4060 && n < 4095 ) {
	BLK = 2;
} else
if ( n >= 4095 && n < 4139 ) {
	BLK = 1;
} else
if ( n >= 4139 && n < 4142 ) {
	BLK = 2;
} else
if ( n >= 4142 && n < 4144 ) {
	BLK = 3;
} else
if ( n >= 4144 && n < 4146 ) {
	BLK = 5;
} else
if ( n >= 4146 && n < 4151 ) {
	BLK = 2;
} else
if ( n >= 4151 && n < 4176 ) {
	BLK = 1;
} else
if ( n >= 4176 && n < 4177 ) {
	BLK = 5;
} else
if ( n >= 4177 && n < 4190 ) {
	BLK = 2;
} else
if ( n >= 4190 && n < 4199 ) {
	BLK = 1;
} else
if ( n >= 4199 && n < 4201 ) {
	BLK = 2;
} else
if ( n >= 4201 && n < 4206 ) {
	BLK = 5;
} else
if ( n >= 4206 && n < 4357 ) {
	BLK = 1;
} else
if ( n >= 4357 && n < 4360 ) {
	BLK = 2;
} else
if ( n >= 4360 && n < 4458 ) {
	BLK = 5;
} else
if ( n >= 4458 && n < 4544 ) {
	BLK = 1;
} else
if ( n >= 4544 && n < 4545 ) {
	BLK = 5;
} else
if ( n >= 4545 && n < 4550 ) {
	BLK = 2;
} else
if ( n >= 4550 && n < 4913 ) {
	BLK = 1;
} else
if ( n >= 4913 && n < 4914 ) {
	BLK = 2;
} else
if ( n >= 4914 && n < 4921 ) {
	BLK = 5;
} else
if ( n >= 4921 && n < 6064 ) {
	BLK = 1;
} else
if ( n >= 6064 && n < 8533 ) {
	BLK = 2;
} else
if ( n >= 8533 && n < 9107 ) {
	BLK = 1;
} else
if ( n >= 9107 && n < 15576 ) {
	BLK = 3;
} else
if ( n >= 15576 && n < 2147483647 ) {
	BLK = 4;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 4;
} 

#endif
