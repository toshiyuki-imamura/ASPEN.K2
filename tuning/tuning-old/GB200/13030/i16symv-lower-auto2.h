#ifndef I16SYMVL_AUTO2_H_INCLUDED
#define I16SYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I16SYMVL
 Wed Sep 30 17:16:28  2026
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
#define	KERNEL_3	1
#define	KERNEL_5	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 15066 ) {
	BLK = 0;
} else
if ( n >= 15066 && n < 250478 ) {
	BLK = 2;
} else
if ( n >= 250478 && n < 262146 ) {
	BLK = 5;
} else
if ( n >= 262146 && n < 263978 ) {
	BLK = 3;
} else
if ( n >= 263978 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
