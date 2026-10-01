#ifndef SSYMVU_AUTO2_H_INCLUDED
#define SSYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for SSYMVU
 Tue Sep 29 17:17:30  2026
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
#define	KERNEL_2	1
#define	KERNEL_5	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 9208 ) {
	BLK = 0;
} else
if ( n >= 9208 && n < 55182 ) {
	BLK = 2;
} else
if ( n >= 55182 && n < 57483 ) {
	BLK = 5;
} else
if ( n >= 57483 && n < 58707 ) {
	BLK = 2;
} else
if ( n >= 58707 && n < 66085 ) {
	BLK = 5;
} else
if ( n >= 66085 && n < 68350 ) {
	BLK = 2;
} else
if ( n >= 68350 && n < 71114 ) {
	BLK = 5;
} else
if ( n >= 71114 && n < 82566 ) {
	BLK = 2;
} else
if ( n >= 82566 && n < 89273 ) {
	BLK = 5;
} else
if ( n >= 89273 && n < 93817 ) {
	BLK = 2;
} else
if ( n >= 93817 && n < 2147483647 ) {
	BLK = 5;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 5;
} 

#endif
