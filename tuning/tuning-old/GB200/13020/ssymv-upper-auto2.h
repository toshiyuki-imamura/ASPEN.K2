#ifndef SSYMVU_AUTO2_H_INCLUDED
#define SSYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for SSYMVU
 Thu Jun 18 16:31:46  2026
 Host on ar17n10-m.ai.r-ccs.riken.jp
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

if ( n >= 1 && n < 2558 ) {
	BLK = 0;
} else
if ( n >= 2558 && n < 2560 ) {
	BLK = 1;
} else
if ( n >= 2560 && n < 2561 ) {
	BLK = 2;
} else
if ( n >= 2561 && n < 2568 ) {
	BLK = 0;
} else
if ( n >= 2568 && n < 2569 ) {
	BLK = 1;
} else
if ( n >= 2569 && n < 2570 ) {
	BLK = 2;
} else
if ( n >= 2570 && n < 2575 ) {
	BLK = 0;
} else
if ( n >= 2575 && n < 2576 ) {
	BLK = 1;
} else
if ( n >= 2576 && n < 2579 ) {
	BLK = 2;
} else
if ( n >= 2579 && n < 2592 ) {
	BLK = 0;
} else
if ( n >= 2592 && n < 2593 ) {
	BLK = 2;
} else
if ( n >= 2593 && n < 2594 ) {
	BLK = 1;
} else
if ( n >= 2594 && n < 6280 ) {
	BLK = 0;
} else
if ( n >= 6280 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
