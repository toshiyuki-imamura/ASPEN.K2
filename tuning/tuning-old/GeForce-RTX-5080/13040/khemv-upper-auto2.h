#ifndef KHEMVU_AUTO2_H_INCLUDED
#define KHEMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for KHEMVU
 Sun Sep 27 15:05:36  2026
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

if ( n >= 1 && n < 244 ) {
	BLK = 0;
} else
if ( n >= 244 && n < 262 ) {
	BLK = 4;
} else
if ( n >= 262 && n < 275 ) {
	BLK = 0;
} else
if ( n >= 275 && n < 276 ) {
	BLK = 5;
} else
if ( n >= 276 && n < 281 ) {
	BLK = 4;
} else
if ( n >= 281 && n < 298 ) {
	BLK = 0;
} else
if ( n >= 298 && n < 307 ) {
	BLK = 4;
} else
if ( n >= 307 && n < 347 ) {
	BLK = 0;
} else
if ( n >= 347 && n < 348 ) {
	BLK = 5;
} else
if ( n >= 348 && n < 358 ) {
	BLK = 4;
} else
if ( n >= 358 && n < 359 ) {
	BLK = 5;
} else
if ( n >= 359 && n < 365 ) {
	BLK = 0;
} else
if ( n >= 365 && n < 366 ) {
	BLK = 4;
} else
if ( n >= 366 && n < 368 ) {
	BLK = 5;
} else
if ( n >= 368 && n < 377 ) {
	BLK = 0;
} else
if ( n >= 377 && n < 381 ) {
	BLK = 4;
} else
if ( n >= 381 && n < 382 ) {
	BLK = 5;
} else
if ( n >= 382 && n < 1783 ) {
	BLK = 0;
} else
if ( n >= 1783 && n < 1792 ) {
	BLK = 2;
} else
if ( n >= 1792 && n < 1794 ) {
	BLK = 3;
} else
if ( n >= 1794 && n < 1795 ) {
	BLK = 1;
} else
if ( n >= 1795 && n < 1811 ) {
	BLK = 2;
} else
if ( n >= 1811 && n < 1812 ) {
	BLK = 3;
} else
if ( n >= 1812 && n < 1815 ) {
	BLK = 1;
} else
if ( n >= 1815 && n < 1818 ) {
	BLK = 0;
} else
if ( n >= 1818 && n < 1831 ) {
	BLK = 2;
} else
if ( n >= 1831 && n < 1832 ) {
	BLK = 1;
} else
if ( n >= 1832 && n < 1833 ) {
	BLK = 3;
} else
if ( n >= 1833 && n < 1871 ) {
	BLK = 2;
} else
if ( n >= 1871 && n < 1876 ) {
	BLK = 0;
} else
if ( n >= 1876 && n < 1877 ) {
	BLK = 1;
} else
if ( n >= 1877 && n < 1924 ) {
	BLK = 2;
} else
if ( n >= 1924 && n < 1965 ) {
	BLK = 0;
} else
if ( n >= 1965 && n < 1966 ) {
	BLK = 2;
} else
if ( n >= 1966 && n < 2001 ) {
	BLK = 1;
} else
if ( n >= 2001 && n < 2038 ) {
	BLK = 0;
} else
if ( n >= 2038 && n < 2039 ) {
	BLK = 2;
} else
if ( n >= 2039 && n < 2040 ) {
	BLK = 1;
} else
if ( n >= 2040 && n < 2043 ) {
	BLK = 0;
} else
if ( n >= 2043 && n < 2099 ) {
	BLK = 2;
} else
if ( n >= 2099 && n < 2109 ) {
	BLK = 0;
} else
if ( n >= 2109 && n < 2127 ) {
	BLK = 2;
} else
if ( n >= 2127 && n < 2130 ) {
	BLK = 0;
} else
if ( n >= 2130 && n < 2134 ) {
	BLK = 2;
} else
if ( n >= 2134 && n < 2135 ) {
	BLK = 1;
} else
if ( n >= 2135 && n < 2146 ) {
	BLK = 0;
} else
if ( n >= 2146 && n < 2156 ) {
	BLK = 2;
} else
if ( n >= 2156 && n < 2157 ) {
	BLK = 0;
} else
if ( n >= 2157 && n < 2158 ) {
	BLK = 1;
} else
if ( n >= 2158 && n < 2165 ) {
	BLK = 2;
} else
if ( n >= 2165 && n < 2263 ) {
	BLK = 0;
} else
if ( n >= 2263 && n < 2265 ) {
	BLK = 1;
} else
if ( n >= 2265 && n < 2268 ) {
	BLK = 3;
} else
if ( n >= 2268 && n < 2270 ) {
	BLK = 0;
} else
if ( n >= 2270 && n < 2272 ) {
	BLK = 1;
} else
if ( n >= 2272 && n < 2275 ) {
	BLK = 3;
} else
if ( n >= 2275 && n < 2292 ) {
	BLK = 0;
} else
if ( n >= 2292 && n < 2294 ) {
	BLK = 1;
} else
if ( n >= 2294 && n < 2297 ) {
	BLK = 3;
} else
if ( n >= 2297 && n < 2341 ) {
	BLK = 0;
} else
if ( n >= 2341 && n < 2342 ) {
	BLK = 3;
} else
if ( n >= 2342 && n < 2345 ) {
	BLK = 1;
} else
if ( n >= 2345 && n < 2347 ) {
	BLK = 0;
} else
if ( n >= 2347 && n < 2348 ) {
	BLK = 3;
} else
if ( n >= 2348 && n < 2352 ) {
	BLK = 1;
} else
if ( n >= 2352 && n < 3091 ) {
	BLK = 0;
} else
if ( n >= 3091 && n < 3092 ) {
	BLK = 3;
} else
if ( n >= 3092 && n < 3105 ) {
	BLK = 1;
} else
if ( n >= 3105 && n < 3106 ) {
	BLK = 0;
} else
if ( n >= 3106 && n < 3108 ) {
	BLK = 3;
} else
if ( n >= 3108 && n < 3109 ) {
	BLK = 1;
} else
if ( n >= 3109 && n < 3168 ) {
	BLK = 0;
} else
if ( n >= 3168 && n < 3170 ) {
	BLK = 3;
} else
if ( n >= 3170 && n < 3171 ) {
	BLK = 1;
} else
if ( n >= 3171 && n < 3173 ) {
	BLK = 0;
} else
if ( n >= 3173 && n < 3174 ) {
	BLK = 3;
} else
if ( n >= 3174 && n < 3192 ) {
	BLK = 1;
} else
if ( n >= 3192 && n < 3306 ) {
	BLK = 0;
} else
if ( n >= 3306 && n < 3329 ) {
	BLK = 1;
} else
if ( n >= 3329 && n < 3330 ) {
	BLK = 0;
} else
if ( n >= 3330 && n < 3331 ) {
	BLK = 3;
} else
if ( n >= 3331 && n < 3332 ) {
	BLK = 1;
} else
if ( n >= 3332 && n < 3338 ) {
	BLK = 0;
} else
if ( n >= 3338 && n < 3339 ) {
	BLK = 1;
} else
if ( n >= 3339 && n < 3340 ) {
	BLK = 3;
} else
if ( n >= 3340 && n < 3341 ) {
	BLK = 0;
} else
if ( n >= 3341 && n < 3354 ) {
	BLK = 1;
} else
if ( n >= 3354 && n < 3364 ) {
	BLK = 0;
} else
if ( n >= 3364 && n < 3367 ) {
	BLK = 3;
} else
if ( n >= 3367 && n < 3391 ) {
	BLK = 1;
} else
if ( n >= 3391 && n < 3465 ) {
	BLK = 0;
} else
if ( n >= 3465 && n < 5776 ) {
	BLK = 3;
} else
if ( n >= 5776 && n < 5795 ) {
	BLK = 0;
} else
if ( n >= 5795 && n < 7968 ) {
	BLK = 1;
} else
if ( n >= 7968 && n < 9170 ) {
	BLK = 3;
} else
if ( n >= 9170 && n < 11285 ) {
	BLK = 4;
} else
if ( n >= 11285 && n < 18923 ) {
	BLK = 2;
} else
if ( n >= 18923 && n < 19594 ) {
	BLK = 5;
} else
if ( n >= 19594 && n < 20100 ) {
	BLK = 2;
} else
if ( n >= 20100 && n < 20535 ) {
	BLK = 5;
} else
if ( n >= 20535 && n < 20889 ) {
	BLK = 2;
} else
if ( n >= 20889 && n < 25180 ) {
	BLK = 5;
} else
if ( n >= 25180 && n < 26101 ) {
	BLK = 2;
} else
if ( n >= 26101 && n < 41484 ) {
	BLK = 5;
} else
if ( n >= 41484 && n < 42790 ) {
	BLK = 2;
} else
if ( n >= 42790 && n < 2147483647 ) {
	BLK = 5;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 5;
} 

#endif
