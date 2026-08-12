#ifndef I128SYMVL_AUTO2_H_INCLUDED
#define I128SYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I128SYMVL
 Fri Nov 08 13:53:44  2024
 Host on newton.r-ccs27.riken.jp
 Device is GeForce-GTX-1080
****************************************/-->
// device name
DEVICE= GeForce-GTX-1080
// the number of multi-processors
MP= 20
// compute-compatibility generation
CG= 610
// capacity of the global memory or host memory
MAXmem= 8497229824
// capacity of the work area reserved on the GPU
WORK= 360960
// for double or cuFloatComplex or int64
MAXDIM= 30961
// for float or cuHalfComplex or int32
MAXDIM2= 43785
// for cuDoubleComplex or DD or int128
MAXDIM3= 21892
// for DD-Complex
MAXDIM4= 15480
// for half or int16
MAXDIM5= 61922
// cuda version
CUDA= 12060
// ASPEN.K2 version
ASPEN_K2= 1.11 Fujieda
<--
#define CURRENT_GPU 610
-->
#endif

#define	KERNEL_0	1
#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_4	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 1042 ) {
	BLK = 0;
} else
if ( n >= 1042 && n < 1063 ) {
	BLK = 3;
} else
if ( n >= 1063 && n < 2133 ) {
	BLK = 4;
} else
if ( n >= 2133 && n < 2788 ) {
	BLK = 2;
} else
if ( n >= 2788 && n < 2801 ) {
	BLK = 4;
} else
if ( n >= 2801 && n < 4501 ) {
	BLK = 1;
} else
if ( n >= 4501 && n < 14856 ) {
	BLK = 2;
} else
if ( n >= 14856 && n < 15259 ) {
	BLK = 1;
} else
if ( n >= 15259 && n < 18648 ) {
	BLK = 2;
} else
if ( n >= 18648 && n < 19424 ) {
	BLK = 1;
} else
if ( n >= 19424 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
