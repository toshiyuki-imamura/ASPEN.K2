#ifndef WSYMVU_AUTO2_H_INCLUDED
#define WSYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for WSYMVU
 Fri Sep 25 18:06:32  2026
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

#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_4	1
#define	KERNEL_5	1


// default kernel is
BLK = 1;

if ( n >= 1 && n < 13 ) {
	BLK = 3;
} else
if ( n >= 13 && n < 29 ) {
	BLK = 4;
} else
if ( n >= 29 && n < 328 ) {
	BLK = 1;
} else
if ( n >= 328 && n < 1427 ) {
	BLK = 5;
} else
if ( n >= 1427 && n < 2216 ) {
	BLK = 1;
} else
if ( n >= 2216 && n < 2217 ) {
	BLK = 5;
} else
if ( n >= 2217 && n < 2219 ) {
	BLK = 2;
} else
if ( n >= 2219 && n < 4343 ) {
	BLK = 1;
} else
if ( n >= 4343 && n < 4349 ) {
	BLK = 3;
} else
if ( n >= 4349 && n < 4374 ) {
	BLK = 4;
} else
if ( n >= 4374 && n < 4401 ) {
	BLK = 1;
} else
if ( n >= 4401 && n < 4435 ) {
	BLK = 2;
} else
if ( n >= 4435 && n < 4446 ) {
	BLK = 1;
} else
if ( n >= 4446 && n < 4497 ) {
	BLK = 2;
} else
if ( n >= 4497 && n < 5373 ) {
	BLK = 4;
} else
if ( n >= 5373 && n < 6195 ) {
	BLK = 3;
} else
if ( n >= 6195 && n < 7837 ) {
	BLK = 2;
} else
if ( n >= 7837 && n < 8139 ) {
	BLK = 3;
} else
if ( n >= 8139 && n < 8560 ) {
	BLK = 2;
} else
if ( n >= 8560 && n < 2147483647 ) {
	BLK = 4;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 4;
} 

#endif
