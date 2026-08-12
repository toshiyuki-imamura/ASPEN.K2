#ifndef I16SYMVL_AUTO2_H_INCLUDED
#define I16SYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I16SYMVL
 Thu Aug 06 08:40:33  2026
 Host on qc-gh200-01.cloud.r-ccs.riken.jp
 Device is GH200-480GB
****************************************/-->
// device name
DEVICE= GH200-480GB
// the number of multi-processors
MP= 132
// compute-compatibility generation
CG= 900
// capacity of the global memory or host memory
MAXmem= 101997334528
// capacity of the work area reserved on the GPU
WORK= 8136960
// for double or cuFloatComplex or int64
MAXDIM= 107268
// for float or cuHalfComplex or int32
MAXDIM2= 151700
// for cuDoubleComplex or DD or int128
MAXDIM3= 75850
// for DD-Complex
MAXDIM4= 53634
// for half or int16
MAXDIM5= 214537
// cuda version
CUDA= 13020
// ASPEN.K2 version
ASPEN_K2= 1.12 Shimada
<--
#define CURRENT_GPU 900
-->
#endif

#define	KERNEL_0	1
#define	KERNEL_1	1
#define	KERNEL_3	1
#define	KERNEL_4	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 5268 ) {
	BLK = 0;
} else
if ( n >= 5268 && n < 13052 ) {
	BLK = 1;
} else
if ( n >= 13052 && n < 121342 ) {
	BLK = 3;
} else
if ( n >= 121342 && n < 123708 ) {
	BLK = 4;
} else
if ( n >= 123708 && n < 136221 ) {
	BLK = 3;
} else
if ( n >= 136221 && n < 140246 ) {
	BLK = 4;
} else
if ( n >= 140246 && n < 183507 ) {
	BLK = 3;
} else
if ( n >= 183507 && n < 194122 ) {
	BLK = 4;
} else
if ( n >= 194122 && n < 2147483647 ) {
	BLK = 3;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 3;
} 

#endif
