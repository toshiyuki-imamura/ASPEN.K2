#ifndef WSYMVU_AUTO2_H_INCLUDED
#define WSYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for WSYMVU
 Fri Sep 25 17:38:45  2026
 Host on fermat.r-ccs27.riken.jp
 Device is RTX-A5000
****************************************/-->
// device name
DEVICE= RTX-A5000
// the number of multi-processors
MP= 64
// compute-compatibility generation
CG= 860
// capacity of the global memory or host memory
MAXmem= 25327001600
// capacity of the work area reserved on the GPU
WORK= 3118080
// for double or cuFloatComplex or int64
MAXDIM= 53452
// for float or cuHalfComplex or int32
MAXDIM2= 75593
// for cuDoubleComplex or DD or int128
MAXDIM3= 37796
// for DD-Complex
MAXDIM4= 26726
// for half or int16
MAXDIM5= 106905
// cuda version
CUDA= 13040
// ASPEN.K2 version
ASPEN_K2= 1.13 Kanaya
<--
#define CURRENT_GPU 860
-->
#endif

#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_4	1
#define	KERNEL_5	1


// default kernel is
BLK = 1;

if ( n >= 1 && n < 30 ) {
	BLK = 3;
} else
if ( n >= 30 && n < 319 ) {
	BLK = 5;
} else
if ( n >= 319 && n < 516 ) {
	BLK = 4;
} else
if ( n >= 516 && n < 537 ) {
	BLK = 2;
} else
if ( n >= 537 && n < 785 ) {
	BLK = 4;
} else
if ( n >= 785 && n < 786 ) {
	BLK = 5;
} else
if ( n >= 786 && n < 795 ) {
	BLK = 2;
} else
if ( n >= 795 && n < 796 ) {
	BLK = 5;
} else
if ( n >= 796 && n < 802 ) {
	BLK = 4;
} else
if ( n >= 802 && n < 807 ) {
	BLK = 5;
} else
if ( n >= 807 && n < 861 ) {
	BLK = 4;
} else
if ( n >= 861 && n < 877 ) {
	BLK = 2;
} else
if ( n >= 877 && n < 1584 ) {
	BLK = 4;
} else
if ( n >= 1584 && n < 2640 ) {
	BLK = 2;
} else
if ( n >= 2640 && n < 7349 ) {
	BLK = 1;
} else
if ( n >= 7349 && n < 8122 ) {
	BLK = 3;
} else
if ( n >= 8122 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
