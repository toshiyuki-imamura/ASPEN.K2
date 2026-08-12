#ifndef SSYMVU_AUTO2_H_INCLUDED
#define SSYMVU_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for SSYMVU
 Thu Aug 06 00:41:44  2026
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

if ( n >= 1 && n < 279 ) {
	BLK = 0;
} else
if ( n >= 279 && n < 280 ) {
	BLK = 5;
} else
if ( n >= 280 && n < 282 ) {
	BLK = 3;
} else
if ( n >= 282 && n < 292 ) {
	BLK = 2;
} else
if ( n >= 292 && n < 293 ) {
	BLK = 3;
} else
if ( n >= 293 && n < 298 ) {
	BLK = 0;
} else
if ( n >= 298 && n < 300 ) {
	BLK = 5;
} else
if ( n >= 300 && n < 302 ) {
	BLK = 2;
} else
if ( n >= 302 && n < 321 ) {
	BLK = 0;
} else
if ( n >= 321 && n < 323 ) {
	BLK = 5;
} else
if ( n >= 323 && n < 371 ) {
	BLK = 2;
} else
if ( n >= 371 && n < 375 ) {
	BLK = 3;
} else
if ( n >= 375 && n < 376 ) {
	BLK = 2;
} else
if ( n >= 376 && n < 433 ) {
	BLK = 0;
} else
if ( n >= 433 && n < 437 ) {
	BLK = 2;
} else
if ( n >= 437 && n < 447 ) {
	BLK = 0;
} else
if ( n >= 447 && n < 453 ) {
	BLK = 5;
} else
if ( n >= 453 && n < 454 ) {
	BLK = 2;
} else
if ( n >= 454 && n < 455 ) {
	BLK = 0;
} else
if ( n >= 455 && n < 475 ) {
	BLK = 5;
} else
if ( n >= 475 && n < 550 ) {
	BLK = 2;
} else
if ( n >= 550 && n < 551 ) {
	BLK = 5;
} else
if ( n >= 551 && n < 565 ) {
	BLK = 4;
} else
if ( n >= 565 && n < 788 ) {
	BLK = 2;
} else
if ( n >= 788 && n < 789 ) {
	BLK = 3;
} else
if ( n >= 789 && n < 808 ) {
	BLK = 5;
} else
if ( n >= 808 && n < 812 ) {
	BLK = 2;
} else
if ( n >= 812 && n < 813 ) {
	BLK = 4;
} else
if ( n >= 813 && n < 818 ) {
	BLK = 5;
} else
if ( n >= 818 && n < 819 ) {
	BLK = 1;
} else
if ( n >= 819 && n < 820 ) {
	BLK = 2;
} else
if ( n >= 820 && n < 823 ) {
	BLK = 5;
} else
if ( n >= 823 && n < 824 ) {
	BLK = 3;
} else
if ( n >= 824 && n < 825 ) {
	BLK = 1;
} else
if ( n >= 825 && n < 826 ) {
	BLK = 4;
} else
if ( n >= 826 && n < 827 ) {
	BLK = 5;
} else
if ( n >= 827 && n < 828 ) {
	BLK = 0;
} else
if ( n >= 828 && n < 832 ) {
	BLK = 1;
} else
if ( n >= 832 && n < 833 ) {
	BLK = 3;
} else
if ( n >= 833 && n < 840 ) {
	BLK = 5;
} else
if ( n >= 840 && n < 844 ) {
	BLK = 3;
} else
if ( n >= 844 && n < 845 ) {
	BLK = 1;
} else
if ( n >= 845 && n < 849 ) {
	BLK = 2;
} else
if ( n >= 849 && n < 851 ) {
	BLK = 3;
} else
if ( n >= 851 && n < 854 ) {
	BLK = 1;
} else
if ( n >= 854 && n < 857 ) {
	BLK = 2;
} else
if ( n >= 857 && n < 884 ) {
	BLK = 3;
} else
if ( n >= 884 && n < 885 ) {
	BLK = 2;
} else
if ( n >= 885 && n < 886 ) {
	BLK = 1;
} else
if ( n >= 886 && n < 897 ) {
	BLK = 3;
} else
if ( n >= 897 && n < 898 ) {
	BLK = 0;
} else
if ( n >= 898 && n < 901 ) {
	BLK = 4;
} else
if ( n >= 901 && n < 902 ) {
	BLK = 3;
} else
if ( n >= 902 && n < 909 ) {
	BLK = 2;
} else
if ( n >= 909 && n < 910 ) {
	BLK = 4;
} else
if ( n >= 910 && n < 911 ) {
	BLK = 3;
} else
if ( n >= 911 && n < 920 ) {
	BLK = 2;
} else
if ( n >= 920 && n < 921 ) {
	BLK = 3;
} else
if ( n >= 921 && n < 923 ) {
	BLK = 4;
} else
if ( n >= 923 && n < 926 ) {
	BLK = 2;
} else
if ( n >= 926 && n < 932 ) {
	BLK = 3;
} else
if ( n >= 932 && n < 968 ) {
	BLK = 4;
} else
if ( n >= 968 && n < 988 ) {
	BLK = 2;
} else
if ( n >= 988 && n < 989 ) {
	BLK = 4;
} else
if ( n >= 989 && n < 990 ) {
	BLK = 1;
} else
if ( n >= 990 && n < 996 ) {
	BLK = 3;
} else
if ( n >= 996 && n < 1117 ) {
	BLK = 2;
} else
if ( n >= 1117 && n < 1118 ) {
	BLK = 3;
} else
if ( n >= 1118 && n < 1119 ) {
	BLK = 1;
} else
if ( n >= 1119 && n < 1311 ) {
	BLK = 2;
} else
if ( n >= 1311 && n < 1314 ) {
	BLK = 3;
} else
if ( n >= 1314 && n < 1319 ) {
	BLK = 1;
} else
if ( n >= 1319 && n < 1320 ) {
	BLK = 2;
} else
if ( n >= 1320 && n < 1322 ) {
	BLK = 3;
} else
if ( n >= 1322 && n < 1323 ) {
	BLK = 1;
} else
if ( n >= 1323 && n < 1333 ) {
	BLK = 4;
} else
if ( n >= 1333 && n < 1336 ) {
	BLK = 1;
} else
if ( n >= 1336 && n < 1343 ) {
	BLK = 4;
} else
if ( n >= 1343 && n < 1344 ) {
	BLK = 3;
} else
if ( n >= 1344 && n < 1511 ) {
	BLK = 1;
} else
if ( n >= 1511 && n < 1584 ) {
	BLK = 5;
} else
if ( n >= 1584 && n < 2016 ) {
	BLK = 4;
} else
if ( n >= 2016 && n < 2168 ) {
	BLK = 3;
} else
if ( n >= 2168 && n < 2169 ) {
	BLK = 0;
} else
if ( n >= 2169 && n < 2511 ) {
	BLK = 2;
} else
if ( n >= 2511 && n < 2512 ) {
	BLK = 1;
} else
if ( n >= 2512 && n < 2524 ) {
	BLK = 3;
} else
if ( n >= 2524 && n < 2538 ) {
	BLK = 2;
} else
if ( n >= 2538 && n < 2543 ) {
	BLK = 3;
} else
if ( n >= 2543 && n < 2821 ) {
	BLK = 2;
} else
if ( n >= 2821 && n < 2822 ) {
	BLK = 1;
} else
if ( n >= 2822 && n < 2823 ) {
	BLK = 3;
} else
if ( n >= 2823 && n < 2886 ) {
	BLK = 2;
} else
if ( n >= 2886 && n < 2890 ) {
	BLK = 3;
} else
if ( n >= 2890 && n < 2906 ) {
	BLK = 2;
} else
if ( n >= 2906 && n < 2908 ) {
	BLK = 3;
} else
if ( n >= 2908 && n < 2909 ) {
	BLK = 1;
} else
if ( n >= 2909 && n < 2917 ) {
	BLK = 2;
} else
if ( n >= 2917 && n < 2918 ) {
	BLK = 3;
} else
if ( n >= 2918 && n < 2924 ) {
	BLK = 1;
} else
if ( n >= 2924 && n < 2927 ) {
	BLK = 3;
} else
if ( n >= 2927 && n < 2936 ) {
	BLK = 2;
} else
if ( n >= 2936 && n < 2937 ) {
	BLK = 1;
} else
if ( n >= 2937 && n < 2945 ) {
	BLK = 3;
} else
if ( n >= 2945 && n < 2951 ) {
	BLK = 2;
} else
if ( n >= 2951 && n < 2952 ) {
	BLK = 3;
} else
if ( n >= 2952 && n < 2958 ) {
	BLK = 1;
} else
if ( n >= 2958 && n < 3031 ) {
	BLK = 2;
} else
if ( n >= 3031 && n < 3032 ) {
	BLK = 1;
} else
if ( n >= 3032 && n < 3041 ) {
	BLK = 3;
} else
if ( n >= 3041 && n < 3042 ) {
	BLK = 1;
} else
if ( n >= 3042 && n < 3065 ) {
	BLK = 2;
} else
if ( n >= 3065 && n < 3601 ) {
	BLK = 3;
} else
if ( n >= 3601 && n < 3603 ) {
	BLK = 1;
} else
if ( n >= 3603 && n < 3614 ) {
	BLK = 2;
} else
if ( n >= 3614 && n < 3615 ) {
	BLK = 3;
} else
if ( n >= 3615 && n < 3617 ) {
	BLK = 1;
} else
if ( n >= 3617 && n < 3618 ) {
	BLK = 2;
} else
if ( n >= 3618 && n < 3635 ) {
	BLK = 3;
} else
if ( n >= 3635 && n < 3645 ) {
	BLK = 2;
} else
if ( n >= 3645 && n < 3658 ) {
	BLK = 1;
} else
if ( n >= 3658 && n < 3661 ) {
	BLK = 3;
} else
if ( n >= 3661 && n < 3671 ) {
	BLK = 2;
} else
if ( n >= 3671 && n < 3688 ) {
	BLK = 3;
} else
if ( n >= 3688 && n < 3716 ) {
	BLK = 2;
} else
if ( n >= 3716 && n < 3717 ) {
	BLK = 1;
} else
if ( n >= 3717 && n < 3722 ) {
	BLK = 3;
} else
if ( n >= 3722 && n < 3723 ) {
	BLK = 1;
} else
if ( n >= 3723 && n < 3732 ) {
	BLK = 2;
} else
if ( n >= 3732 && n < 3733 ) {
	BLK = 1;
} else
if ( n >= 3733 && n < 3734 ) {
	BLK = 3;
} else
if ( n >= 3734 && n < 3740 ) {
	BLK = 2;
} else
if ( n >= 3740 && n < 3741 ) {
	BLK = 3;
} else
if ( n >= 3741 && n < 3783 ) {
	BLK = 1;
} else
if ( n >= 3783 && n < 3784 ) {
	BLK = 2;
} else
if ( n >= 3784 && n < 3785 ) {
	BLK = 3;
} else
if ( n >= 3785 && n < 3817 ) {
	BLK = 1;
} else
if ( n >= 3817 && n < 3818 ) {
	BLK = 3;
} else
if ( n >= 3818 && n < 4903 ) {
	BLK = 2;
} else
if ( n >= 4903 && n < 5358 ) {
	BLK = 1;
} else
if ( n >= 5358 && n < 9031 ) {
	BLK = 3;
} else
if ( n >= 9031 && n < 10765 ) {
	BLK = 5;
} else
if ( n >= 10765 && n < 11963 ) {
	BLK = 4;
} else
if ( n >= 11963 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
