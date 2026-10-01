#ifndef CHEMVL_AUTO2_H_INCLUDED
#define CHEMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for CHEMVL
 Wed Sep 30 18:37:31  2026
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
#define	KERNEL_4	1
#define	KERNEL_5	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 3728 ) {
	BLK = 0;
} else
if ( n >= 3728 && n < 7612 ) {
	BLK = 1;
} else
if ( n >= 7612 && n < 9103 ) {
	BLK = 5;
} else
if ( n >= 9103 && n < 12708 ) {
	BLK = 4;
} else
if ( n >= 12708 && n < 12924 ) {
	BLK = 5;
} else
if ( n >= 12924 && n < 16984 ) {
	BLK = 4;
} else
if ( n >= 16984 && n < 17115 ) {
	BLK = 5;
} else
if ( n >= 17115 && n < 17803 ) {
	BLK = 3;
} else
if ( n >= 17803 && n < 18695 ) {
	BLK = 4;
} else
if ( n >= 18695 && n < 18991 ) {
	BLK = 3;
} else
if ( n >= 18991 && n < 19992 ) {
	BLK = 4;
} else
if ( n >= 19992 && n < 21001 ) {
	BLK = 3;
} else
if ( n >= 21001 && n < 21986 ) {
	BLK = 4;
} else
if ( n >= 21986 && n < 22334 ) {
	BLK = 3;
} else
if ( n >= 22334 && n < 22704 ) {
	BLK = 4;
} else
if ( n >= 22704 && n < 23342 ) {
	BLK = 3;
} else
if ( n >= 23342 && n < 24235 ) {
	BLK = 4;
} else
if ( n >= 24235 && n < 24775 ) {
	BLK = 3;
} else
if ( n >= 24775 && n < 25647 ) {
	BLK = 4;
} else
if ( n >= 25647 && n < 25904 ) {
	BLK = 3;
} else
if ( n >= 25904 && n < 26424 ) {
	BLK = 4;
} else
if ( n >= 26424 && n < 34453 ) {
	BLK = 3;
} else
if ( n >= 34453 && n < 35473 ) {
	BLK = 4;
} else
if ( n >= 35473 && n < 37331 ) {
	BLK = 3;
} else
if ( n >= 37331 && n < 38181 ) {
	BLK = 4;
} else
if ( n >= 38181 && n < 43452 ) {
	BLK = 3;
} else
if ( n >= 43452 && n < 44365 ) {
	BLK = 4;
} else
if ( n >= 44365 && n < 50130 ) {
	BLK = 3;
} else
if ( n >= 50130 && n < 51917 ) {
	BLK = 4;
} else
if ( n >= 51917 && n < 94140 ) {
	BLK = 3;
} else
if ( n >= 94140 && n < 99633 ) {
	BLK = 4;
} else
if ( n >= 99633 && n < 2147483647 ) {
	BLK = 3;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 3;
} 

#endif
