#ifndef HSYMVL_AUTO2_H_INCLUDED
#define HSYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for HSYMVL
 Wed Sep 30 01:53:25  2026
 Host on c237
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
CUDA= 13030
// ASPEN.K2 version
ASPEN_K2= 1.13 Kanaya
<--
#define CURRENT_GPU 1000
-->
#endif

#define	KERNEL_0	1
#define	KERNEL_1	1
#define	KERNEL_3	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 4 ) {
	BLK = 3;
} else
if ( n >= 4 && n < 22064 ) {
	BLK = 0;
} else
if ( n >= 22064 && n < 22338 ) {
	BLK = 1;
} else
if ( n >= 22338 && n < 22765 ) {
	BLK = 0;
} else
if ( n >= 22765 && n < 256536 ) {
	BLK = 1;
} else
if ( n >= 256536 && n < 260689 ) {
	BLK = 0;
} else
if ( n >= 260689 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
