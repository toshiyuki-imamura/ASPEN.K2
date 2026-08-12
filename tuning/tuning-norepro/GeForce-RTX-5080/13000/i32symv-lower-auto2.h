#ifndef I32SYMVL_AUTO2_H_INCLUDED
#define I32SYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I32SYMVL
 Sat Nov 09 02:02:46  2024
 Host on newton.r-ccs27.riken.jp
 Device is GeForce-GTX-1080
****************************************/-->
// device name
DEVICE= GeForce-GTX-1080
// the number of multi-processors
MP= 20
// compute-compatibility generation
CG= 610
// capacity of the global memory or host memory
MAXmem= 8497229824
// capacity of the work area reserved on the GPU
WORK= 360960
// for double or cuFloatComplex or int64
MAXDIM= 30961
// for float or cuHalfComplex or int32
MAXDIM2= 43785
// for cuDoubleComplex or DD or int128
MAXDIM3= 21892
// for DD-Complex
MAXDIM4= 15480
// for half or int16
MAXDIM5= 61922
// cuda version
CUDA= 12060
// ASPEN.K2 version
ASPEN_K2= 1.11 Fujieda
<--
#define CURRENT_GPU 610
-->
#endif

#define	KERNEL_0	1
#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_5	1
#define	KERNEL_6	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 631 ) {
	BLK = 0;
} else
if ( n >= 631 && n < 1773 ) {
	BLK = 2;
} else
if ( n >= 1773 && n < 1788 ) {
	BLK = 3;
} else
if ( n >= 1788 && n < 3495 ) {
	BLK = 1;
} else
if ( n >= 3495 && n < 4006 ) {
	BLK = 3;
} else
if ( n >= 4006 && n < 5649 ) {
	BLK = 1;
} else
if ( n >= 5649 && n < 6318 ) {
	BLK = 3;
} else
if ( n >= 6318 && n < 6652 ) {
	BLK = 1;
} else
if ( n >= 6652 && n < 9956 ) {
	BLK = 3;
} else
if ( n >= 9956 && n < 10232 ) {
	BLK = 5;
} else
if ( n >= 10232 && n < 11054 ) {
	BLK = 3;
} else
if ( n >= 11054 && n < 11330 ) {
	BLK = 6;
} else
if ( n >= 11330 && n < 12338 ) {
	BLK = 3;
} else
if ( n >= 12338 && n < 13154 ) {
	BLK = 6;
} else
if ( n >= 13154 && n < 13433 ) {
	BLK = 3;
} else
if ( n >= 13433 && n < 15978 ) {
	BLK = 5;
} else
if ( n >= 15978 && n < 17122 ) {
	BLK = 6;
} else
if ( n >= 17122 && n < 20221 ) {
	BLK = 5;
} else
if ( n >= 20221 && n < 21040 ) {
	BLK = 6;
} else
if ( n >= 21040 && n < 2147483647 ) {
	BLK = 5;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 5;
} 

#endif
