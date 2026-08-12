#ifndef UHEMVL_AUTO2_H_INCLUDED
#define UHEMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for UHEMVL
 Thu Nov 20 21:03:09  2025
 Host on shannon.r-ccs27.riken.jp
 Device is GeForce-RTX-5080
****************************************/-->
// device name
DEVICE= GeForce-RTX-5080
// the number of multi-processors
MP= 84
// compute-compatibility generation
CG= 1200
// capacity of the global memory or host memory
MAXmem= 16585474048
// capacity of the work area reserved on the GPU
WORK= 504832
// for double or cuFloatComplex or int64
MAXDIM= 43255
// for float or cuHalfComplex or int32
MAXDIM2= 61172
// for cuDoubleComplex or DD or int128
MAXDIM3= 30586
// for DD-Complex
MAXDIM4= 21627
// for half or int16
MAXDIM5= 86511
// cuda version
CUDA= 13000
// ASPEN.K2 version
ASPEN_K2= 1.11 Fujieda
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

if ( n >= 1 && n < 3 ) {
	BLK = 5;
} else
if ( n >= 3 && n < 4 ) {
	BLK = 3;
} else
if ( n >= 4 && n < 8 ) {
	BLK = 2;
} else
if ( n >= 8 && n < 16 ) {
	BLK = 4;
} else
if ( n >= 16 && n < 565 ) {
	BLK = 5;
} else
if ( n >= 565 && n < 863 ) {
	BLK = 3;
} else
if ( n >= 863 && n < 2021 ) {
	BLK = 1;
} else
if ( n >= 2021 && n < 2086 ) {
	BLK = 2;
} else
if ( n >= 2086 && n < 2087 ) {
	BLK = 4;
} else
if ( n >= 2087 && n < 2088 ) {
	BLK = 1;
} else
if ( n >= 2088 && n < 2115 ) {
	BLK = 2;
} else
if ( n >= 2115 && n < 2116 ) {
	BLK = 4;
} else
if ( n >= 2116 && n < 2117 ) {
	BLK = 1;
} else
if ( n >= 2117 && n < 2134 ) {
	BLK = 2;
} else
if ( n >= 2134 && n < 2135 ) {
	BLK = 4;
} else
if ( n >= 2135 && n < 2136 ) {
	BLK = 1;
} else
if ( n >= 2136 && n < 2143 ) {
	BLK = 2;
} else
if ( n >= 2143 && n < 2563 ) {
	BLK = 4;
} else
if ( n >= 2563 && n < 2564 ) {
	BLK = 1;
} else
if ( n >= 2564 && n < 2566 ) {
	BLK = 2;
} else
if ( n >= 2566 && n < 2574 ) {
	BLK = 4;
} else
if ( n >= 2574 && n < 2588 ) {
	BLK = 1;
} else
if ( n >= 2588 && n < 2604 ) {
	BLK = 4;
} else
if ( n >= 2604 && n < 2605 ) {
	BLK = 2;
} else
if ( n >= 2605 && n < 2606 ) {
	BLK = 1;
} else
if ( n >= 2606 && n < 2613 ) {
	BLK = 4;
} else
if ( n >= 2613 && n < 2614 ) {
	BLK = 2;
} else
if ( n >= 2614 && n < 2615 ) {
	BLK = 1;
} else
if ( n >= 2615 && n < 2652 ) {
	BLK = 4;
} else
if ( n >= 2652 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
