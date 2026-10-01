#ifndef UHEMVU_AUTO2_H_INCLUDED
#define UHEMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for UHEMVU
 Sun Sep 27 07:58:45  2026
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
if ( n >= 2 && n < 5 ) {
	BLK = 1;
} else
if ( n >= 5 && n < 6 ) {
	BLK = 2;
} else
if ( n >= 6 && n < 8 ) {
	BLK = 5;
} else
if ( n >= 8 && n < 19 ) {
	BLK = 3;
} else
if ( n >= 19 && n < 1425 ) {
	BLK = 1;
} else
if ( n >= 1425 && n < 1476 ) {
	BLK = 2;
} else
if ( n >= 1476 && n < 1490 ) {
	BLK = 4;
} else
if ( n >= 1490 && n < 1491 ) {
	BLK = 1;
} else
if ( n >= 1491 && n < 1525 ) {
	BLK = 2;
} else
if ( n >= 1525 && n < 1530 ) {
	BLK = 4;
} else
if ( n >= 1530 && n < 1541 ) {
	BLK = 1;
} else
if ( n >= 1541 && n < 1544 ) {
	BLK = 2;
} else
if ( n >= 1544 && n < 1557 ) {
	BLK = 1;
} else
if ( n >= 1557 && n < 1558 ) {
	BLK = 2;
} else
if ( n >= 1558 && n < 1727 ) {
	BLK = 4;
} else
if ( n >= 1727 && n < 3303 ) {
	BLK = 1;
} else
if ( n >= 3303 && n < 3679 ) {
	BLK = 3;
} else
if ( n >= 3679 && n < 5269 ) {
	BLK = 1;
} else
if ( n >= 5269 && n < 5603 ) {
	BLK = 4;
} else
if ( n >= 5603 && n < 5667 ) {
	BLK = 3;
} else
if ( n >= 5667 && n < 5678 ) {
	BLK = 1;
} else
if ( n >= 5678 && n < 5687 ) {
	BLK = 4;
} else
if ( n >= 5687 && n < 7234 ) {
	BLK = 3;
} else
if ( n >= 7234 && n < 8647 ) {
	BLK = 4;
} else
if ( n >= 8647 && n < 2147483647 ) {
	BLK = 3;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 3;
} 

#endif
