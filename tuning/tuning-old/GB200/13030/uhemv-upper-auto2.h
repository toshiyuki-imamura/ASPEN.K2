#ifndef UHEMVU_AUTO2_H_INCLUDED
#define UHEMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for UHEMVU
 Wed Sep 30 21:18:56  2026
 Host on c181
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
#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1
#define	KERNEL_4	1
#define	KERNEL_5	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 2 ) {
	BLK = 3;
} else
if ( n >= 2 && n < 3 ) {
	BLK = 1;
} else
if ( n >= 3 && n < 4 ) {
	BLK = 0;
} else
if ( n >= 4 && n < 7 ) {
	BLK = 2;
} else
if ( n >= 7 && n < 8 ) {
	BLK = 4;
} else
if ( n >= 8 && n < 9 ) {
	BLK = 1;
} else
if ( n >= 9 && n < 16 ) {
	BLK = 2;
} else
if ( n >= 16 && n < 17 ) {
	BLK = 3;
} else
if ( n >= 17 && n < 22 ) {
	BLK = 1;
} else
if ( n >= 22 && n < 125 ) {
	BLK = 0;
} else
if ( n >= 125 && n < 140 ) {
	BLK = 5;
} else
if ( n >= 140 && n < 141 ) {
	BLK = 0;
} else
if ( n >= 141 && n < 142 ) {
	BLK = 2;
} else
if ( n >= 142 && n < 162 ) {
	BLK = 5;
} else
if ( n >= 162 && n < 195 ) {
	BLK = 0;
} else
if ( n >= 195 && n < 196 ) {
	BLK = 4;
} else
if ( n >= 196 && n < 210 ) {
	BLK = 5;
} else
if ( n >= 210 && n < 378 ) {
	BLK = 0;
} else
if ( n >= 378 && n < 386 ) {
	BLK = 5;
} else
if ( n >= 386 && n < 387 ) {
	BLK = 4;
} else
if ( n >= 387 && n < 492 ) {
	BLK = 0;
} else
if ( n >= 492 && n < 684 ) {
	BLK = 4;
} else
if ( n >= 684 && n < 688 ) {
	BLK = 2;
} else
if ( n >= 688 && n < 697 ) {
	BLK = 0;
} else
if ( n >= 697 && n < 715 ) {
	BLK = 2;
} else
if ( n >= 715 && n < 784 ) {
	BLK = 4;
} else
if ( n >= 784 && n < 785 ) {
	BLK = 3;
} else
if ( n >= 785 && n < 800 ) {
	BLK = 2;
} else
if ( n >= 800 && n < 825 ) {
	BLK = 4;
} else
if ( n >= 825 && n < 865 ) {
	BLK = 2;
} else
if ( n >= 865 && n < 866 ) {
	BLK = 4;
} else
if ( n >= 866 && n < 867 ) {
	BLK = 3;
} else
if ( n >= 867 && n < 870 ) {
	BLK = 2;
} else
if ( n >= 870 && n < 876 ) {
	BLK = 4;
} else
if ( n >= 876 && n < 914 ) {
	BLK = 3;
} else
if ( n >= 914 && n < 978 ) {
	BLK = 2;
} else
if ( n >= 978 && n < 984 ) {
	BLK = 3;
} else
if ( n >= 984 && n < 985 ) {
	BLK = 4;
} else
if ( n >= 985 && n < 988 ) {
	BLK = 2;
} else
if ( n >= 988 && n < 1069 ) {
	BLK = 4;
} else
if ( n >= 1069 && n < 1070 ) {
	BLK = 2;
} else
if ( n >= 1070 && n < 1071 ) {
	BLK = 3;
} else
if ( n >= 1071 && n < 1080 ) {
	BLK = 4;
} else
if ( n >= 1080 && n < 1103 ) {
	BLK = 2;
} else
if ( n >= 1103 && n < 1104 ) {
	BLK = 0;
} else
if ( n >= 1104 && n < 1106 ) {
	BLK = 4;
} else
if ( n >= 1106 && n < 1114 ) {
	BLK = 2;
} else
if ( n >= 1114 && n < 1128 ) {
	BLK = 4;
} else
if ( n >= 1128 && n < 1138 ) {
	BLK = 3;
} else
if ( n >= 1138 && n < 1326 ) {
	BLK = 2;
} else
if ( n >= 1326 && n < 1327 ) {
	BLK = 3;
} else
if ( n >= 1327 && n < 1330 ) {
	BLK = 4;
} else
if ( n >= 1330 && n < 1463 ) {
	BLK = 3;
} else
if ( n >= 1463 && n < 1464 ) {
	BLK = 4;
} else
if ( n >= 1464 && n < 2730 ) {
	BLK = 2;
} else
if ( n >= 2730 && n < 2732 ) {
	BLK = 3;
} else
if ( n >= 2732 && n < 2744 ) {
	BLK = 5;
} else
if ( n >= 2744 && n < 2751 ) {
	BLK = 3;
} else
if ( n >= 2751 && n < 2752 ) {
	BLK = 2;
} else
if ( n >= 2752 && n < 2755 ) {
	BLK = 5;
} else
if ( n >= 2755 && n < 4594 ) {
	BLK = 2;
} else
if ( n >= 4594 && n < 2147483647 ) {
	BLK = 0;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 0;
} 

#endif
