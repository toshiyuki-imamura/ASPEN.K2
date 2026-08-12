#ifndef I64SYMVL_AUTO2_H_INCLUDED
#define I64SYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I64SYMVL
 Tue Nov 18 05:24:18  2025
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
#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_5	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 20 ) {
	BLK = 0;
} else
if ( n >= 20 && n < 21 ) {
	BLK = 2;
} else
if ( n >= 21 && n < 22 ) {
	BLK = 1;
} else
if ( n >= 22 && n < 4187 ) {
	BLK = 0;
} else
if ( n >= 4187 && n < 7301 ) {
	BLK = 3;
} else
if ( n >= 7301 && n < 11775 ) {
	BLK = 2;
} else
if ( n >= 11775 && n < 12638 ) {
	BLK = 3;
} else
if ( n >= 12638 && n < 12727 ) {
	BLK = 2;
} else
if ( n >= 12727 && n < 12837 ) {
	BLK = 5;
} else
if ( n >= 12837 && n < 2147483647 ) {
	BLK = 3;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 3;
} 

#endif
