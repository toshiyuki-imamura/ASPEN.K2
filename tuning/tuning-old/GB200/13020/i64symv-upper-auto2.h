#ifndef I64SYMVU_AUTO2_H_INCLUDED
#define I64SYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I64SYMVU
 Sat Jun 20 21:39:42  2026
 Host on ar11n06-m.ai.r-ccs.riken.jp
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

if ( n >= 1 && n < 397 ) {
	BLK = 0;
} else
if ( n >= 397 && n < 398 ) {
	BLK = 2;
} else
if ( n >= 398 && n < 399 ) {
	BLK = 1;
} else
if ( n >= 399 && n < 758 ) {
	BLK = 0;
} else
if ( n >= 758 && n < 759 ) {
	BLK = 2;
} else
if ( n >= 759 && n < 843 ) {
	BLK = 1;
} else
if ( n >= 843 && n < 1215 ) {
	BLK = 0;
} else
if ( n >= 1215 && n < 1216 ) {
	BLK = 2;
} else
if ( n >= 1216 && n < 1301 ) {
	BLK = 1;
} else
if ( n >= 1301 && n < 3990 ) {
	BLK = 0;
} else
if ( n >= 3990 && n < 3991 ) {
	BLK = 2;
} else
if ( n >= 3991 && n < 3992 ) {
	BLK = 1;
} else
if ( n >= 3992 && n < 4099 ) {
	BLK = 0;
} else
if ( n >= 4099 && n < 4100 ) {
	BLK = 1;
} else
if ( n >= 4100 && n < 4127 ) {
	BLK = 2;
} else
if ( n >= 4127 && n < 4132 ) {
	BLK = 0;
} else
if ( n >= 4132 && n < 4152 ) {
	BLK = 1;
} else
if ( n >= 4152 && n < 4195 ) {
	BLK = 0;
} else
if ( n >= 4195 && n < 4196 ) {
	BLK = 1;
} else
if ( n >= 4196 && n < 4242 ) {
	BLK = 2;
} else
if ( n >= 4242 && n < 4244 ) {
	BLK = 1;
} else
if ( n >= 4244 && n < 4266 ) {
	BLK = 0;
} else
if ( n >= 4266 && n < 4301 ) {
	BLK = 2;
} else
if ( n >= 4301 && n < 4305 ) {
	BLK = 0;
} else
if ( n >= 4305 && n < 4306 ) {
	BLK = 1;
} else
if ( n >= 4306 && n < 4344 ) {
	BLK = 2;
} else
if ( n >= 4344 && n < 4349 ) {
	BLK = 0;
} else
if ( n >= 4349 && n < 4350 ) {
	BLK = 1;
} else
if ( n >= 4350 && n < 4830 ) {
	BLK = 2;
} else
if ( n >= 4830 && n < 4834 ) {
	BLK = 0;
} else
if ( n >= 4834 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
