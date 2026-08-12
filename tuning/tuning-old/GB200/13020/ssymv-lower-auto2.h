#ifndef SSYMVL_AUTO2_H_INCLUDED
#define SSYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for SSYMVL
 Fri Jun 19 18:19:17  2026
 Host on ar13n17-m.ai.r-ccs.riken.jp
 Device is GB200
****************************************/-->
// device name
DEVICE= GB200
// the number of multi-processors
MP= 152
// compute-compatibility generation
CG= 1000
// capacity of the global memory or host memory
MAXmem= 197555425280
// capacity of the work area reserved on the GPU
WORK= 13067520
// for double or cuFloatComplex or int64
MAXDIM= 149287
// for float or cuHalfComplex or int32
MAXDIM2= 211124
// for cuDoubleComplex or DD or int128
MAXDIM3= 105562
// for DD-Complex
MAXDIM4= 74643
// for half or int16
MAXDIM5= 298574
// cuda version
CUDA= 13020
// ASPEN.K2 version
ASPEN_K2= 1.12 Shimada
<--
#define CURRENT_GPU 1000
-->
#endif

#define	KERNEL_0	1
#define	KERNEL_1	1
#define	KERNEL_2	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 2 ) {
	BLK = 2;
} else
if ( n >= 2 && n < 22 ) {
	BLK = 1;
} else
if ( n >= 22 && n < 1462 ) {
	BLK = 0;
} else
if ( n >= 1462 && n < 1463 ) {
	BLK = 2;
} else
if ( n >= 1463 && n < 1501 ) {
	BLK = 1;
} else
if ( n >= 1501 && n < 1502 ) {
	BLK = 2;
} else
if ( n >= 1502 && n < 2063 ) {
	BLK = 0;
} else
if ( n >= 2063 && n < 2064 ) {
	BLK = 1;
} else
if ( n >= 2064 && n < 2065 ) {
	BLK = 2;
} else
if ( n >= 2065 && n < 7532 ) {
	BLK = 0;
} else
if ( n >= 7532 && n < 8741 ) {
	BLK = 2;
} else
if ( n >= 8741 && n < 10756 ) {
	BLK = 0;
} else
if ( n >= 10756 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
