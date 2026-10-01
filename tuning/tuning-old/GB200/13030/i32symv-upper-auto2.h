#ifndef I32SYMVU_AUTO2_H_INCLUDED
#define I32SYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I32SYMVU
 Wed Sep 30 08:26:39  2026
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
#define	KERNEL_4	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 5963 ) {
	BLK = 0;
} else
if ( n >= 5963 && n < 7237 ) {
	BLK = 1;
} else
if ( n >= 7237 && n < 19054 ) {
	BLK = 4;
} else
if ( n >= 19054 && n < 20651 ) {
	BLK = 3;
} else
if ( n >= 20651 && n < 20933 ) {
	BLK = 4;
} else
if ( n >= 20933 && n < 22237 ) {
	BLK = 3;
} else
if ( n >= 22237 && n < 29809 ) {
	BLK = 4;
} else
if ( n >= 29809 && n < 30475 ) {
	BLK = 3;
} else
if ( n >= 30475 && n < 35598 ) {
	BLK = 4;
} else
if ( n >= 35598 && n < 41122 ) {
	BLK = 3;
} else
if ( n >= 41122 && n < 42867 ) {
	BLK = 4;
} else
if ( n >= 42867 && n < 117050 ) {
	BLK = 3;
} else
if ( n >= 117050 && n < 125251 ) {
	BLK = 4;
} else
if ( n >= 125251 && n < 2147483647 ) {
	BLK = 3;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 3;
} 

#endif
