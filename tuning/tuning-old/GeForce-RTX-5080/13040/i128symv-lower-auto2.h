#ifndef I128SYMVL_AUTO2_H_INCLUDED
#define I128SYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I128SYMVL
 Sat Sep 26 22:18:46  2026
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

if ( n >= 1 && n < 3 ) {
	BLK = 5;
} else
if ( n >= 3 && n < 9 ) {
	BLK = 1;
} else
if ( n >= 9 && n < 11 ) {
	BLK = 3;
} else
if ( n >= 11 && n < 14 ) {
	BLK = 5;
} else
if ( n >= 14 && n < 17 ) {
	BLK = 3;
} else
if ( n >= 17 && n < 151 ) {
	BLK = 2;
} else
if ( n >= 151 && n < 156 ) {
	BLK = 1;
} else
if ( n >= 156 && n < 911 ) {
	BLK = 0;
} else
if ( n >= 911 && n < 912 ) {
	BLK = 3;
} else
if ( n >= 912 && n < 922 ) {
	BLK = 1;
} else
if ( n >= 922 && n < 955 ) {
	BLK = 0;
} else
if ( n >= 955 && n < 959 ) {
	BLK = 1;
} else
if ( n >= 959 && n < 962 ) {
	BLK = 3;
} else
if ( n >= 962 && n < 963 ) {
	BLK = 4;
} else
if ( n >= 963 && n < 965 ) {
	BLK = 0;
} else
if ( n >= 965 && n < 969 ) {
	BLK = 3;
} else
if ( n >= 969 && n < 971 ) {
	BLK = 4;
} else
if ( n >= 971 && n < 975 ) {
	BLK = 0;
} else
if ( n >= 975 && n < 1280 ) {
	BLK = 3;
} else
if ( n >= 1280 && n < 1360 ) {
	BLK = 4;
} else
if ( n >= 1360 && n < 1363 ) {
	BLK = 3;
} else
if ( n >= 1363 && n < 1388 ) {
	BLK = 4;
} else
if ( n >= 1388 && n < 1392 ) {
	BLK = 3;
} else
if ( n >= 1392 && n < 1395 ) {
	BLK = 1;
} else
if ( n >= 1395 && n < 1419 ) {
	BLK = 4;
} else
if ( n >= 1419 && n < 1420 ) {
	BLK = 3;
} else
if ( n >= 1420 && n < 1423 ) {
	BLK = 1;
} else
if ( n >= 1423 && n < 1431 ) {
	BLK = 4;
} else
if ( n >= 1431 && n < 1432 ) {
	BLK = 1;
} else
if ( n >= 1432 && n < 1437 ) {
	BLK = 3;
} else
if ( n >= 1437 && n < 1716 ) {
	BLK = 4;
} else
if ( n >= 1716 && n < 1717 ) {
	BLK = 3;
} else
if ( n >= 1717 && n < 1830 ) {
	BLK = 1;
} else
if ( n >= 1830 && n < 1831 ) {
	BLK = 3;
} else
if ( n >= 1831 && n < 1832 ) {
	BLK = 4;
} else
if ( n >= 1832 && n < 1839 ) {
	BLK = 1;
} else
if ( n >= 1839 && n < 1840 ) {
	BLK = 3;
} else
if ( n >= 1840 && n < 1841 ) {
	BLK = 4;
} else
if ( n >= 1841 && n < 2079 ) {
	BLK = 1;
} else
if ( n >= 2079 && n < 2080 ) {
	BLK = 3;
} else
if ( n >= 2080 && n < 2112 ) {
	BLK = 4;
} else
if ( n >= 2112 && n < 2241 ) {
	BLK = 1;
} else
if ( n >= 2241 && n < 2242 ) {
	BLK = 4;
} else
if ( n >= 2242 && n < 2245 ) {
	BLK = 3;
} else
if ( n >= 2245 && n < 2251 ) {
	BLK = 4;
} else
if ( n >= 2251 && n < 2259 ) {
	BLK = 1;
} else
if ( n >= 2259 && n < 2260 ) {
	BLK = 4;
} else
if ( n >= 2260 && n < 2263 ) {
	BLK = 3;
} else
if ( n >= 2263 && n < 2269 ) {
	BLK = 1;
} else
if ( n >= 2269 && n < 2270 ) {
	BLK = 4;
} else
if ( n >= 2270 && n < 2271 ) {
	BLK = 3;
} else
if ( n >= 2271 && n < 2274 ) {
	BLK = 1;
} else
if ( n >= 2274 && n < 2275 ) {
	BLK = 4;
} else
if ( n >= 2275 && n < 2288 ) {
	BLK = 3;
} else
if ( n >= 2288 && n < 2289 ) {
	BLK = 4;
} else
if ( n >= 2289 && n < 2295 ) {
	BLK = 1;
} else
if ( n >= 2295 && n < 2296 ) {
	BLK = 3;
} else
if ( n >= 2296 && n < 2297 ) {
	BLK = 4;
} else
if ( n >= 2297 && n < 2300 ) {
	BLK = 1;
} else
if ( n >= 2300 && n < 2303 ) {
	BLK = 3;
} else
if ( n >= 2303 && n < 2304 ) {
	BLK = 4;
} else
if ( n >= 2304 && n < 2404 ) {
	BLK = 1;
} else
if ( n >= 2404 && n < 2418 ) {
	BLK = 4;
} else
if ( n >= 2418 && n < 2423 ) {
	BLK = 3;
} else
if ( n >= 2423 && n < 2431 ) {
	BLK = 1;
} else
if ( n >= 2431 && n < 2432 ) {
	BLK = 3;
} else
if ( n >= 2432 && n < 2437 ) {
	BLK = 4;
} else
if ( n >= 2437 && n < 2452 ) {
	BLK = 1;
} else
if ( n >= 2452 && n < 2454 ) {
	BLK = 3;
} else
if ( n >= 2454 && n < 2464 ) {
	BLK = 4;
} else
if ( n >= 2464 && n < 2470 ) {
	BLK = 1;
} else
if ( n >= 2470 && n < 2477 ) {
	BLK = 3;
} else
if ( n >= 2477 && n < 2480 ) {
	BLK = 4;
} else
if ( n >= 2480 && n < 2481 ) {
	BLK = 1;
} else
if ( n >= 2481 && n < 2483 ) {
	BLK = 3;
} else
if ( n >= 2483 && n < 2485 ) {
	BLK = 4;
} else
if ( n >= 2485 && n < 2490 ) {
	BLK = 1;
} else
if ( n >= 2490 && n < 2493 ) {
	BLK = 3;
} else
if ( n >= 2493 && n < 2496 ) {
	BLK = 4;
} else
if ( n >= 2496 && n < 2561 ) {
	BLK = 3;
} else
if ( n >= 2561 && n < 2688 ) {
	BLK = 4;
} else
if ( n >= 2688 && n < 2689 ) {
	BLK = 3;
} else
if ( n >= 2689 && n < 4897 ) {
	BLK = 1;
} else
if ( n >= 4897 && n < 8718 ) {
	BLK = 3;
} else
if ( n >= 8718 && n < 20965 ) {
	BLK = 2;
} else
if ( n >= 20965 && n < 21435 ) {
	BLK = 5;
} else
if ( n >= 21435 && n < 25398 ) {
	BLK = 2;
} else
if ( n >= 25398 && n < 25950 ) {
	BLK = 5;
} else
if ( n >= 25950 && n < 26557 ) {
	BLK = 2;
} else
if ( n >= 26557 && n < 27241 ) {
	BLK = 5;
} else
if ( n >= 27241 && n < 27629 ) {
	BLK = 2;
} else
if ( n >= 27629 && n < 28471 ) {
	BLK = 5;
} else
if ( n >= 28471 && n < 28996 ) {
	BLK = 2;
} else
if ( n >= 28996 && n < 2147483647 ) {
	BLK = 5;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 5;
} 

#endif
