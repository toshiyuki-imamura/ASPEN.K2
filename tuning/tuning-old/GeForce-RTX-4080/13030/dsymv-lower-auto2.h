#ifndef DSYMVL_AUTO2_H_INCLUDED
#define DSYMVL_AUTO2_H_INCLUDED    1

#if 0
<--/****************************************
 Automatic Performance Tuning for DSYMVL
 Tue Jul 28 18:15:14  2026
 Host on newton.r-ccs27.riken.jp
 Device is GeForce-RTX-4080
****************************************/-->
// device name
DEVICE= GeForce-RTX-4080
// the number of multi-processors
MP= 76
// compute-compatibility generation
CG= 890
// capacity of the global memory or host memory
MAXmem= 16743747584
// capacity of the work area reserved on the GPU
WORK= 2534400
// for double or cuFloatComplex or int64
MAXDIM= 43461
// for float or cuHalfComplex or int32
MAXDIM2= 61463
// for cuDoubleComplex or DD or int128
MAXDIM3= 30731
// for DD-Complex
MAXDIM4= 21730
// for half or int16
MAXDIM5= 86923
// cuda version
CUDA= 13030
// ASPEN.K2 version
ASPEN_K2= 1.12 Shimada
<--
#define CURRENT_GPU 890
-->
#endif

#define	KERNEL_0	1
#define	KERNEL_1	1
#define	KERNEL_2	1
#define	KERNEL_3	1


// default kernel is
BLK = 0;

if ( n >= 1 && n < 497 ) {
	BLK = 0;
} else
if ( n >= 497 && n < 575 ) {
	BLK = 1;
} else
if ( n >= 575 && n < 577 ) {
	BLK = 2;
} else
if ( n >= 577 && n < 592 ) {
	BLK = 3;
} else
if ( n >= 592 && n < 596 ) {
	BLK = 1;
} else
if ( n >= 596 && n < 604 ) {
	BLK = 3;
} else
if ( n >= 604 && n < 605 ) {
	BLK = 2;
} else
if ( n >= 605 && n < 606 ) {
	BLK = 1;
} else
if ( n >= 606 && n < 624 ) {
	BLK = 3;
} else
if ( n >= 624 && n < 638 ) {
	BLK = 0;
} else
if ( n >= 638 && n < 674 ) {
	BLK = 2;
} else
if ( n >= 674 && n < 753 ) {
	BLK = 0;
} else
if ( n >= 753 && n < 767 ) {
	BLK = 2;
} else
if ( n >= 767 && n < 768 ) {
	BLK = 3;
} else
if ( n >= 768 && n < 773 ) {
	BLK = 1;
} else
if ( n >= 773 && n < 776 ) {
	BLK = 2;
} else
if ( n >= 776 && n < 779 ) {
	BLK = 3;
} else
if ( n >= 779 && n < 784 ) {
	BLK = 1;
} else
if ( n >= 784 && n < 785 ) {
	BLK = 3;
} else
if ( n >= 785 && n < 786 ) {
	BLK = 2;
} else
if ( n >= 786 && n < 792 ) {
	BLK = 1;
} else
if ( n >= 792 && n < 793 ) {
	BLK = 3;
} else
if ( n >= 793 && n < 796 ) {
	BLK = 2;
} else
if ( n >= 796 && n < 797 ) {
	BLK = 3;
} else
if ( n >= 797 && n < 798 ) {
	BLK = 1;
} else
if ( n >= 798 && n < 807 ) {
	BLK = 2;
} else
if ( n >= 807 && n < 815 ) {
	BLK = 3;
} else
if ( n >= 815 && n < 816 ) {
	BLK = 1;
} else
if ( n >= 816 && n < 818 ) {
	BLK = 2;
} else
if ( n >= 818 && n < 819 ) {
	BLK = 3;
} else
if ( n >= 819 && n < 820 ) {
	BLK = 1;
} else
if ( n >= 820 && n < 825 ) {
	BLK = 2;
} else
if ( n >= 825 && n < 828 ) {
	BLK = 3;
} else
if ( n >= 828 && n < 829 ) {
	BLK = 1;
} else
if ( n >= 829 && n < 879 ) {
	BLK = 2;
} else
if ( n >= 879 && n < 899 ) {
	BLK = 3;
} else
if ( n >= 899 && n < 928 ) {
	BLK = 2;
} else
if ( n >= 928 && n < 939 ) {
	BLK = 0;
} else
if ( n >= 939 && n < 1216 ) {
	BLK = 1;
} else
if ( n >= 1216 && n < 2010 ) {
	BLK = 0;
} else
if ( n >= 2010 && n < 3581 ) {
	BLK = 3;
} else
if ( n >= 3581 && n < 3583 ) {
	BLK = 1;
} else
if ( n >= 3583 && n < 3584 ) {
	BLK = 2;
} else
if ( n >= 3584 && n < 3592 ) {
	BLK = 3;
} else
if ( n >= 3592 && n < 3593 ) {
	BLK = 2;
} else
if ( n >= 3593 && n < 3606 ) {
	BLK = 1;
} else
if ( n >= 3606 && n < 4946 ) {
	BLK = 2;
} else
if ( n >= 4946 && n < 6666 ) {
	BLK = 3;
} else
if ( n >= 6666 && n < 2147483647 ) {
	BLK = 1;
} else
if ( n >= 2147483647 && n <= 2147483647 ) {
	BLK = 1;
} 

#endif
