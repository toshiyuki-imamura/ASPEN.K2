#ifndef UHEMVL_AUTO2_H_INCLUDED
#define UHEMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for UHEMVL
 Thu Oct 01 06:11:38  2026
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

if ( n >= 1 && n < 3 ) {
	BLK = 3;
} else
if ( n >= 3 && n < 5 ) {
	BLK = 0;
} else
if ( n >= 5 && n < 8 ) {
	BLK = 2;
} else
if ( n >= 8 && n < 19 ) {
	BLK = 1;
} else
if ( n >= 19 && n < 128 ) {
	BLK = 0;
} else
if ( n >= 128 && n < 146 ) {
	BLK = 2;
} else
if ( n >= 146 && n < 147 ) {
	BLK = 5;
} else
if ( n >= 147 && n < 534 ) {
	BLK = 0;
} else
if ( n >= 534 && n < 535 ) {
	BLK = 3;
} else
if ( n >= 535 && n < 536 ) {
	BLK = 4;
} else
if ( n >= 536 && n < 543 ) {
	BLK = 0;
} else
if ( n >= 543 && n < 544 ) {
	BLK = 4;
} else
if ( n >= 544 && n < 545 ) {
	BLK = 3;
} else
if ( n >= 545 && n < 574 ) {
	BLK = 0;
} else
if ( n >= 574 && n < 575 ) {
	BLK = 4;
} else
if ( n >= 575 && n < 576 ) {
	BLK = 3;
} else
if ( n >= 576 && n < 700 ) {
	BLK = 0;
} else
if ( n >= 700 && n < 703 ) {
	BLK = 3;
} else
if ( n >= 703 && n < 704 ) {
	BLK = 4;
} else
if ( n >= 704 && n < 762 ) {
	BLK = 0;
} else
if ( n >= 762 && n < 764 ) {
	BLK = 2;
} else
if ( n >= 764 && n < 765 ) {
	BLK = 3;
} else
if ( n >= 765 && n < 766 ) {
	BLK = 0;
} else
if ( n >= 766 && n < 767 ) {
	BLK = 2;
} else
if ( n >= 767 && n < 769 ) {
	BLK = 3;
} else
if ( n >= 769 && n < 770 ) {
	BLK = 4;
} else
if ( n >= 770 && n < 771 ) {
	BLK = 0;
} else
if ( n >= 771 && n < 780 ) {
	BLK = 3;
} else
if ( n >= 780 && n < 783 ) {
	BLK = 4;
} else
if ( n >= 783 && n < 784 ) {
	BLK = 0;
} else
if ( n >= 784 && n < 787 ) {
	BLK = 3;
} else
if ( n >= 787 && n < 789 ) {
	BLK = 4;
} else
if ( n >= 789 && n < 795 ) {
	BLK = 0;
} else
if ( n >= 795 && n < 796 ) {
	BLK = 4;
} else
if ( n >= 796 && n < 798 ) {
	BLK = 3;
} else
if ( n >= 798 && n < 820 ) {
	BLK = 0;
} else
if ( n >= 820 && n < 826 ) {
	BLK = 4;
} else
if ( n >= 826 && n < 827 ) {
	BLK = 0;
} else
if ( n >= 827 && n < 831 ) {
	BLK = 3;
} else
if ( n >= 831 && n < 832 ) {
	BLK = 4;
} else
if ( n >= 832 && n < 873 ) {
	BLK = 0;
} else
if ( n >= 873 && n < 926 ) {
	BLK = 3;
} else
if ( n >= 926 && n < 927 ) {
	BLK = 1;
} else
if ( n >= 927 && n < 928 ) {
	BLK = 4;
} else
if ( n >= 928 && n < 929 ) {
	BLK = 0;
} else
if ( n >= 929 && n < 938 ) {
	BLK = 3;
} else
if ( n >= 938 && n < 939 ) {
	BLK = 0;
} else
if ( n >= 939 && n < 943 ) {
	BLK = 1;
} else
if ( n >= 943 && n < 944 ) {
	BLK = 3;
} else
if ( n >= 944 && n < 945 ) {
	BLK = 0;
} else
if ( n >= 945 && n < 949 ) {
	BLK = 1;
} else
if ( n >= 949 && n < 1008 ) {
	BLK = 3;
} else
if ( n >= 1008 && n < 1015 ) {
	BLK = 0;
} else
if ( n >= 1015 && n < 1200 ) {
	BLK = 3;
} else
if ( n >= 1200 && n < 1201 ) {
	BLK = 1;
} else
if ( n >= 1201 && n < 1202 ) {
	BLK = 0;
} else
if ( n >= 1202 && n < 1259 ) {
	BLK = 3;
} else
if ( n >= 1259 && n < 1265 ) {
	BLK = 0;
} else
if ( n >= 1265 && n < 1303 ) {
	BLK = 3;
} else
if ( n >= 1303 && n < 1304 ) {
	BLK = 1;
} else
if ( n >= 1304 && n < 1305 ) {
	BLK = 0;
} else
if ( n >= 1305 && n < 1327 ) {
	BLK = 3;
} else
if ( n >= 1327 && n < 1408 ) {
	BLK = 1;
} else
if ( n >= 1408 && n < 1490 ) {
	BLK = 3;
} else
if ( n >= 1490 && n < 1495 ) {
	BLK = 1;
} else
if ( n >= 1495 && n < 1500 ) {
	BLK = 0;
} else
if ( n >= 1500 && n < 1504 ) {
	BLK = 3;
} else
if ( n >= 1504 && n < 1512 ) {
	BLK = 1;
} else
if ( n >= 1512 && n < 1513 ) {
	BLK = 3;
} else
if ( n >= 1513 && n < 1514 ) {
	BLK = 0;
} else
if ( n >= 1514 && n < 1727 ) {
	BLK = 1;
} else
if ( n >= 1727 && n < 1728 ) {
	BLK = 3;
} else
if ( n >= 1728 && n < 1916 ) {
	BLK = 0;
} else
if ( n >= 1916 && n < 1919 ) {
	BLK = 2;
} else
if ( n >= 1919 && n < 1920 ) {
	BLK = 1;
} else
if ( n >= 1920 && n < 2493 ) {
	BLK = 0;
} else
if ( n >= 2493 && n < 2494 ) {
	BLK = 3;
} else
if ( n >= 2494 && n < 2496 ) {
	BLK = 2;
} else
if ( n >= 2496 && n < 2677 ) {
	BLK = 0;
} else
if ( n >= 2677 && n < 2678 ) {
	BLK = 3;
} else
if ( n >= 2678 && n < 2688 ) {
	BLK = 2;
} else
if ( n >= 2688 && n < 2941 ) {
	BLK = 0;
} else
if ( n >= 2941 && n < 2944 ) {
	BLK = 1;
} else
if ( n >= 2944 && n < 2946 ) {
	BLK = 3;
} else
if ( n >= 2946 && n < 2950 ) {
	BLK = 0;
} else
if ( n >= 2950 && n < 2956 ) {
	BLK = 3;
} else
if ( n >= 2956 && n < 3067 ) {
	BLK = 0;
} else
if ( n >= 3067 && n < 3071 ) {
	BLK = 2;
} else
if ( n >= 3071 && n < 3168 ) {
	BLK = 3;
} else
if ( n >= 3168 && n < 57738 ) {
	BLK = 0;
} else
if ( n >= 57738 && n < 60514 ) {
	BLK = 1;
} else
if ( n >= 60514 && n < 2147483647 ) {
	BLK = 0;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 0;
} 

#endif
