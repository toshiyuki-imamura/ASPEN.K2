#ifndef HSYMVL_AUTO2_H_INCLUDED
#define HSYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for HSYMVL
 Fri Aug 07 06:53:04  2026
 Host on cauchy.r-ccs27.riken.jp
 Device is GeForce-RTX-5080
****************************************/-->
// device name
DEVICE= GeForce-RTX-5080
// the number of multi-processors
MP= 84
// compute-compatibility generation
CG= 1200
// capacity of the global memory or host memory
MAXmem= 16647024640
// capacity of the work area reserved on the GPU
WORK= 2526720
// for double or cuFloatComplex or int64
MAXDIM= 43335
// for float or cuHalfComplex or int32
MAXDIM2= 61286
// for cuDoubleComplex or DD or int128
MAXDIM3= 30643
// for DD-Complex
MAXDIM4= 21667
// for half or int16
MAXDIM5= 86671
// cuda version
CUDA= 13030
// ASPEN.K2 version
ASPEN_K2= 1.12 Shimada
<--
#define CURRENT_GPU 1200
-->
#endif

#define	KERNEL_0	1
#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_4	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 3990 ) {
	BLK = 0;
} else
if ( n >= 3990 && n < 15235 ) {
	BLK = 1;
} else
if ( n >= 15235 && n < 18674 ) {
	BLK = 2;
} else
if ( n >= 18674 && n < 20070 ) {
	BLK = 4;
} else
if ( n >= 20070 && n < 22212 ) {
	BLK = 2;
} else
if ( n >= 22212 && n < 22492 ) {
	BLK = 4;
} else
if ( n >= 22492 && n < 23672 ) {
	BLK = 2;
} else
if ( n >= 23672 && n < 24838 ) {
	BLK = 4;
} else
if ( n >= 24838 && n < 28619 ) {
	BLK = 2;
} else
if ( n >= 28619 && n < 30614 ) {
	BLK = 4;
} else
if ( n >= 30614 && n < 32085 ) {
	BLK = 2;
} else
if ( n >= 32085 && n < 32748 ) {
	BLK = 4;
} else
if ( n >= 32748 && n < 36212 ) {
	BLK = 2;
} else
if ( n >= 36212 && n < 36526 ) {
	BLK = 4;
} else
if ( n >= 36526 && n < 37844 ) {
	BLK = 2;
} else
if ( n >= 37844 && n < 39847 ) {
	BLK = 4;
} else
if ( n >= 39847 && n < 54196 ) {
	BLK = 2;
} else
if ( n >= 54196 && n < 55294 ) {
	BLK = 4;
} else
if ( n >= 55294 && n < 69503 ) {
	BLK = 2;
} else
if ( n >= 69503 && n < 70206 ) {
	BLK = 1;
} else
if ( n >= 70206 && n < 72464 ) {
	BLK = 4;
} else
if ( n >= 72464 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
