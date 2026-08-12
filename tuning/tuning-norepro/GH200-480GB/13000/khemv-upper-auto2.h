#ifndef KHEMVU_AUTO2_H_INCLUDED
#define KHEMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for KHEMVU
 Thu Nov 20 08:37:53  2025
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

#define	KERNEL_0	1
#define	KERNEL_4	1
#define	KERNEL_5	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 6309 ) {
	BLK = 0;
} else
if ( n >= 6309 && n < 9601 ) {
	BLK = 4;
} else
if ( n >= 9601 && n < 19114 ) {
	BLK = 5;
} else
if ( n >= 19114 && n < 20165 ) {
	BLK = 4;
} else
if ( n >= 20165 && n < 20451 ) {
	BLK = 5;
} else
if ( n >= 20451 && n < 20727 ) {
	BLK = 4;
} else
if ( n >= 20727 && n < 23187 ) {
	BLK = 5;
} else
if ( n >= 23187 && n < 24514 ) {
	BLK = 4;
} else
if ( n >= 24514 && n < 25060 ) {
	BLK = 5;
} else
if ( n >= 25060 && n < 25332 ) {
	BLK = 4;
} else
if ( n >= 25332 && n < 30299 ) {
	BLK = 5;
} else
if ( n >= 30299 && n < 31126 ) {
	BLK = 4;
} else
if ( n >= 31126 && n < 36530 ) {
	BLK = 5;
} else
if ( n >= 36530 && n < 37941 ) {
	BLK = 4;
} else
if ( n >= 37941 && n < 2147483647 ) {
	BLK = 5;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 5;
} 

#endif
