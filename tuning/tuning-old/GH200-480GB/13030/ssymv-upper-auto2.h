#ifndef SSYMVU_AUTO2_H_INCLUDED
#define SSYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for SSYMVU
 Tue Sep 29 15:27:40  2026
 Host on qc-gh200-02.cloud.r-ccs.riken.jp
 Device is GH200-480GB
****************************************/-->
// device name
DEVICE= GH200-480GB
// the number of multi-processors
MP= 132
// compute-compatibility generation
CG= 900
// capacity of the global memory or host memory
MAXmem= 102123945984
// capacity of the work area reserved on the GPU
WORK= 8140288
// for double or cuFloatComplex or int64
MAXDIM= 107335
// for float or cuHalfComplex or int32
MAXDIM2= 151794
// for cuDoubleComplex or DD or int128
MAXDIM3= 75897
// for DD-Complex
MAXDIM4= 53667
// for half or int16
MAXDIM5= 214670
// cuda version
CUDA= 13040
// ASPEN.K2 version
ASPEN_K2= 1.13 Kanaya
<--
#define CURRENT_GPU 900
-->
#endif

#define	KERNEL_0	1
#define	KERNEL_1	1
#define	KERNEL_3	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 5684 ) {
	BLK = 0;
} else
if ( n >= 5684 && n < 6369 ) {
	BLK = 1;
} else
if ( n >= 6369 && n < 11750 ) {
	BLK = 3;
} else
if ( n >= 11750 && n < 14321 ) {
	BLK = 1;
} else
if ( n >= 14321 && n < 15001 ) {
	BLK = 3;
} else
if ( n >= 15001 && n < 17551 ) {
	BLK = 1;
} else
if ( n >= 17551 && n < 17838 ) {
	BLK = 3;
} else
if ( n >= 17838 && n < 137508 ) {
	BLK = 1;
} else
if ( n >= 137508 && n < 139867 ) {
	BLK = 3;
} else
if ( n >= 139867 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
