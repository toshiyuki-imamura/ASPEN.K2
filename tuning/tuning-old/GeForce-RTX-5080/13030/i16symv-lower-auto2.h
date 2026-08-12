#ifndef I16SYMVL_AUTO2_H_INCLUDED
#define I16SYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for I16SYMVL
 Fri Aug 07 20:17:42  2026
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
#define	KERNEL_3	1
#define	KERNEL_4	1
#define	KERNEL_5	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 515 ) {
	BLK = 0;
} else
if ( n >= 515 && n < 539 ) {
	BLK = 2;
} else
if ( n >= 539 && n < 542 ) {
	BLK = 1;
} else
if ( n >= 542 && n < 563 ) {
	BLK = 2;
} else
if ( n >= 563 && n < 567 ) {
	BLK = 0;
} else
if ( n >= 567 && n < 568 ) {
	BLK = 1;
} else
if ( n >= 568 && n < 639 ) {
	BLK = 2;
} else
if ( n >= 639 && n < 640 ) {
	BLK = 1;
} else
if ( n >= 640 && n < 652 ) {
	BLK = 0;
} else
if ( n >= 652 && n < 653 ) {
	BLK = 1;
} else
if ( n >= 653 && n < 1025 ) {
	BLK = 2;
} else
if ( n >= 1025 && n < 1026 ) {
	BLK = 5;
} else
if ( n >= 1026 && n < 1027 ) {
	BLK = 0;
} else
if ( n >= 1027 && n < 1045 ) {
	BLK = 2;
} else
if ( n >= 1045 && n < 1046 ) {
	BLK = 0;
} else
if ( n >= 1046 && n < 1056 ) {
	BLK = 1;
} else
if ( n >= 1056 && n < 1072 ) {
	BLK = 2;
} else
if ( n >= 1072 && n < 1073 ) {
	BLK = 1;
} else
if ( n >= 1073 && n < 1076 ) {
	BLK = 0;
} else
if ( n >= 1076 && n < 1186 ) {
	BLK = 2;
} else
if ( n >= 1186 && n < 1192 ) {
	BLK = 0;
} else
if ( n >= 1192 && n < 1200 ) {
	BLK = 1;
} else
if ( n >= 1200 && n < 1205 ) {
	BLK = 0;
} else
if ( n >= 1205 && n < 1215 ) {
	BLK = 2;
} else
if ( n >= 1215 && n < 1216 ) {
	BLK = 1;
} else
if ( n >= 1216 && n < 1226 ) {
	BLK = 0;
} else
if ( n >= 1226 && n < 1640 ) {
	BLK = 2;
} else
if ( n >= 1640 && n < 1641 ) {
	BLK = 1;
} else
if ( n >= 1641 && n < 1642 ) {
	BLK = 0;
} else
if ( n >= 1642 && n < 1644 ) {
	BLK = 2;
} else
if ( n >= 1644 && n < 1652 ) {
	BLK = 1;
} else
if ( n >= 1652 && n < 1660 ) {
	BLK = 0;
} else
if ( n >= 1660 && n < 1661 ) {
	BLK = 1;
} else
if ( n >= 1661 && n < 1662 ) {
	BLK = 2;
} else
if ( n >= 1662 && n < 1675 ) {
	BLK = 0;
} else
if ( n >= 1675 && n < 1678 ) {
	BLK = 2;
} else
if ( n >= 1678 && n < 1680 ) {
	BLK = 1;
} else
if ( n >= 1680 && n < 1738 ) {
	BLK = 0;
} else
if ( n >= 1738 && n < 1759 ) {
	BLK = 1;
} else
if ( n >= 1759 && n < 1760 ) {
	BLK = 2;
} else
if ( n >= 1760 && n < 1777 ) {
	BLK = 0;
} else
if ( n >= 1777 && n < 1942 ) {
	BLK = 1;
} else
if ( n >= 1942 && n < 1943 ) {
	BLK = 0;
} else
if ( n >= 1943 && n < 2302 ) {
	BLK = 2;
} else
if ( n >= 2302 && n < 4145 ) {
	BLK = 1;
} else
if ( n >= 4145 && n < 4147 ) {
	BLK = 4;
} else
if ( n >= 4147 && n < 4149 ) {
	BLK = 3;
} else
if ( n >= 4149 && n < 4273 ) {
	BLK = 1;
} else
if ( n >= 4273 && n < 4274 ) {
	BLK = 3;
} else
if ( n >= 4274 && n < 4277 ) {
	BLK = 4;
} else
if ( n >= 4277 && n < 4361 ) {
	BLK = 1;
} else
if ( n >= 4361 && n < 4372 ) {
	BLK = 3;
} else
if ( n >= 4372 && n < 4375 ) {
	BLK = 4;
} else
if ( n >= 4375 && n < 5656 ) {
	BLK = 1;
} else
if ( n >= 5656 && n < 8345 ) {
	BLK = 3;
} else
if ( n >= 8345 && n < 11750 ) {
	BLK = 4;
} else
if ( n >= 11750 && n < 14581 ) {
	BLK = 1;
} else
if ( n >= 14581 && n < 16615 ) {
	BLK = 2;
} else
if ( n >= 16615 && n < 27984 ) {
	BLK = 5;
} else
if ( n >= 27984 && n < 28414 ) {
	BLK = 2;
} else
if ( n >= 28414 && n < 29525 ) {
	BLK = 5;
} else
if ( n >= 29525 && n < 33810 ) {
	BLK = 2;
} else
if ( n >= 33810 && n < 34491 ) {
	BLK = 5;
} else
if ( n >= 34491 && n < 2147483647 ) {
	BLK = 2;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 2;
} 

#endif
