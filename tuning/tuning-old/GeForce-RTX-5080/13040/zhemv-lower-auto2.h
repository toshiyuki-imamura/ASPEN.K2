#ifndef ZHEMVL_AUTO2_H_INCLUDED
#define ZHEMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for ZHEMVL
 Sun Sep 27 19:35:58  2026
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

if ( n >= 1 && n < 2 ) {
	BLK = 3;
} else
if ( n >= 2 && n < 3 ) {
	BLK = 1;
} else
if ( n >= 3 && n < 4 ) {
	BLK = 5;
} else
if ( n >= 4 && n < 5 ) {
	BLK = 2;
} else
if ( n >= 5 && n < 37 ) {
	BLK = 4;
} else
if ( n >= 37 && n < 840 ) {
	BLK = 3;
} else
if ( n >= 840 && n < 1068 ) {
	BLK = 5;
} else
if ( n >= 1068 && n < 1984 ) {
	BLK = 2;
} else
if ( n >= 1984 && n < 2432 ) {
	BLK = 3;
} else
if ( n >= 2432 && n < 3135 ) {
	BLK = 5;
} else
if ( n >= 3135 && n < 4327 ) {
	BLK = 2;
} else
if ( n >= 4327 && n < 6808 ) {
	BLK = 3;
} else
if ( n >= 6808 && n < 13394 ) {
	BLK = 1;
} else
if ( n >= 13394 && n < 14456 ) {
	BLK = 4;
} else
if ( n >= 14456 && n < 14889 ) {
	BLK = 1;
} else
if ( n >= 14889 && n < 2147483647 ) {
	BLK = 4;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 4;
} 

#endif
