#!/bin/bash

GLOBAL_ITR=$1
#GLOBAL_ITR_END=1
GLOBAL_ITR_END=2

#####
GLOBAL_ITR_END=0
#####

export ASPEN_REGUSE_CALC=1
export LD_LIBRARY_PATH=../../lib:$LD_LIBRARY_PATH

Init()
{

	../../src/get_dev_info $ASPEN_GPU_ID > DEV_INFO

	DEVICE=`awk '/DEVICE=/{ print $2 }' DEV_INFO`
	MP=`awk '/MP=/{ print $2 }' DEV_INFO`
	CG=`awk '/CG=/{ print $2 }' DEV_INFO`
	MAXDIM=`awk '/MAXDIM3=/{ print $2 }' DEV_INFO`
	CUDA=`awk '/CUDA=/{ print $2 }' DEV_INFO`

	if [ -e ../CURRENT_GPU ]; then
	CG_=`awk '{print $3*1}' ../CURRENT_GPU`
	if [ $CG -ne $CG_ ]; then
		\rm ../CURRENT_GPU
		echo '#define CURRENT_GPU '$CG > ../CURRENT_GPU
	fi
	else
		\rm ../CURRENT_GPU
		echo '#define CURRENT_GPU '$CG > ../CURRENT_GPU
	fi

	if [ -f IN-exe-a ]; then
		\rm IN-exe-a
	fi
	cat << EOS_DO_A >> IN-exe-a
	1
	0
EOS_DO_A
		echo $MAXDIM >> IN-exe-a 
	N=96
	N_STEP=64
	while [ $N -lt $MAXDIM ]
	do
		echo $N >> IN-exe-a
		D_STEP=`expr $N_STEP "*" 33`
		D_STEP=`expr $D_STEP "/" 100`
		N_STEP=`expr $N_STEP "+" $D_STEP`
		N=`expr $N "+" $N_STEP`
	done
	echo -1 >> IN-exe-a

	if [ -f IN-exe-b ]; then
		\rm IN-exe-b
	fi
	touch IN-exe-b
	echo 1 >> IN-exe-b
	echo 0 >> IN-exe-b
	echo $MAXDIM >> IN-exe-b 
	N=51
	N_STEP=16
	while [ $N -lt 1001 ]
	do
		echo $N >> IN-exe-b
		N=`expr $N "+" $N_STEP`
	done
	N=1001
	N_STEP=32
	while [ $N -lt 4001 ]
	do
		echo $N >> IN-exe-b
		N=`expr $N "+" $N_STEP`
	done
	N_step=`expr $N_STEP "*" 100`
	if [ $MAXDIM -gt 10000 ]; then
	while [ $N -lt 10000 ]
	do
		echo $N >> IN-exe-b
		N_STEP=`expr $N_step "/" 100`
		N=`expr $N "+" $N_STEP`
		N_step=`expr $N_step "*" 105`
		N_step=`expr $N_step "/" 100`
	done
	fi
	N_step=`expr $N_STEP "*" 100`
	if [ $MAXDIM -gt 20000 ]; then
	while [ $N -lt 20000 ]
	do
		echo $N >> IN-exe-b
		N_STEP=`expr $N_step "/" 100`
		N=`expr $N "+" $N_STEP`
		N_step=`expr $N_step "*" 115`
		N_step=`expr $N_step "/" 100`
	done
	fi
	while [ $N -lt $MAXDIM ]
	do
		echo $N >> IN-exe-b
		N_STEP=`expr $N_step "/" 100`
		N=`expr $N "+" $N_STEP`
		N_step=`expr $N_step "*" 144`
		N_step=`expr $N_step "/" 100`
	done
	echo -1 >> IN-exe-b

	if [ -f IN-exe-c ]; then
		\rm IN-exe-c
	fi
	touch IN-exe-c
	echo 1 >> IN-exe-c
	echo 0 >> IN-exe-c
	echo $MAXDIM >> IN-exe-c 
	N=1
	N_STEP=1
	while [ $N -lt 4001 ]
	do
		echo $N >> IN-exe-c
		N=`expr $N "+" $N_STEP`
	done
	N=4001
	N_STEP=2
	N_step=`expr $N_STEP "*" 100`
	if [ $MAXDIM -gt 10000 ]; then
	while [ $N -lt 10000 ]
	do
		echo $N >> IN-exe-c
		N_STEP=`expr $N_step "/" 100`
		N=`expr $N "+" $N_STEP`
		N_step=`expr $N_step "*" 101`
		N_step=`expr $N_step "/" 100`
	done
	fi
	N_step=`expr $N_STEP "*" 100`
	if [ $MAXDIM -gt 20000 ]; then
	while [ $N -lt 20000 ]
	do
		echo $N >> IN-exe-c
		N_STEP=`expr $N_step "/" 100`
		N=`expr $N "+" $N_STEP`
		N_step=`expr $N_step "*" 102`
		N_step=`expr $N_step "/" 100`
	done
	fi
	N_step=`expr $N_STEP "*" 100`
	while [ $N -lt $MAXDIM ]
	do
		echo $N >> IN-exe-c
		N_STEP=`expr $N_step "/" 100`
		N=`expr $N "+" $N_STEP`
		N_step=`expr $N_step "*" 105`
		N_step=`expr $N_step "/" 100`
	done
	echo -1 >> IN-exe-c

	UX_PATTERN=""
	M=1; while [ $M -lt 193 ]
	do
		UX_PATTERN=$UX_PATTERN" "$M
		M=`expr $M "+" 1`
	done

	if [ $CG -lt 300 ]; then
		MM_PATTERN=" 8 7 6 5 4 3 2 1"
		MM_MAX=8
	else
	if [ $CG -lt 500 ]; then
		MM_PATTERN=" 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1"
		MM_MAX=16
	else

		MM_PATTERN=" 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1"
		MM_MAX=32

	if [ $CG -eq 750 ] || [ $CG -eq 860 ]; then
		MM_PATTERN=" 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1"
		MM_MAX=16
	fi

	if [ $CG -eq 890 ]; then
		MM_PATTERN="24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1"
		MM_MAX=24
	fi

	fi
	fi

	Gmin=16
	#Gmax=512
	Gmax=1024

  if [ x$ASPEN_TUNING_LEVEL = xROUGH ]; then
	Gmin=50
	Gmax=512
  fi
  if [ x$ASPEN_TUNING_LEVEL = xFULL ]; then
	Gmin=0
	Gmax=1024
  fi

}

Setup()
{
	if [ -f i128symv-lower-auto.h ]; then
		\rm i128symv-lower-auto.h
	fi
	awk ' \
		BEGIN{ \
			print "int done = 0;"; \
			print "switch (BLK) {"; \
			for ( i=1; i <= 100*'$MM_MAX'; i+=10 ) { \
				print "#if __KERNEL"i; \
				print "case "i":"; \
				print "done = "; \
				print "\tAPI_private(HESYMVl_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, "int((i-1)/100)+1", "(i-1)%100" >"; \
				print "\t( n, a, lda, x, incx, y, incy, alpha, beta ); break;"; \
				print "#endif" \
			} \
			print "default:"; \
			print "\tfprintf( stderr, \"Not proper Parameter %d \", BLK );"; \
			print "\tbreak;"; \
			print "}"; \
			print "if ( ! done ) {"; \
			print "\tperror( \"Incorrect kernel ID has been specified.\" );"; \
			print "\texit(1);"; \
			print "}"; \
			exit; \
		} { exit; } END { exit; }' > i128symv-lower-auto.h
	cp i128symv-lower-auto.h ../
}

Make0()
{
	if [ -f param-i128symvl.h ]; then
		\rm param-i128symvl.h
	fi
	touch param-i128symvl.h

cat << EOF_1 > param-i128symvl.h
#define	BLOCK_SIZE	$BLOCK_SIZE
#define	VX		$VX
#define	UX		$UX
EOF_1

if [ $GLOBAL_ITR -eq 0 ]; then
if [ $GLOBAL_ITR_END -eq 0 ]; then
	MX_PATTERN='0 10  20 30  40 50  60 70  80 90'
else
	MX_PATTERN='0 10 20'
fi
fi
if [ $GLOBAL_ITR -eq 1 ]; then
	MX_PATTERN='30 40 50'
fi
if [ $GLOBAL_ITR -eq 2 ]; then
	MX_PATTERN='60 70 80 90'
fi

	for MX in \
		$MX_PATTERN
	do
		ID=`expr $MULTI "-" 1`
		ID=`expr $ID "*" 100`
		ID=`expr $ID "+" $MX`
		ID=`expr $ID "+" 1`
		echo "#define	__KERNEL"$ID" 1" >> param-i128symvl.h
	done
	if [ -f ../param-i128symvl.h ]; then
		\rm ../param-i128symvl.h
	fi
	cp param-i128symvl.h ../
}

Make1()
{
	if [ -f param-i128symvl.h ]; then
		\rm param-i128symvl.h
	fi
	touch param-i128symvl.h

cat << EOF_2 > param-i128symvl.h
#define	BLOCK_SIZE	$BLOCK_SIZE
#define	VX		$VX
#define	UX		$UX
EOF_2

	for MULTI in \
		$MMM_PATTERN
	do
	for MX in \
		$MX0
	do
		ID=`expr $MULTI "-" 1`
		ID=`expr $ID "*" 100`
		ID=`expr $ID "+" $MX`
		ID=`expr $ID "+" 1`
		echo "#define	__KERNEL"$ID" 1" >> param-i128symvl.h
	done
	done
	if [ -f ../param-i128symvl.h ]; then
		\rm ../param-i128symvl.h
	fi
	cp param-i128symvl.h ../
}

Make()
{
	cd ../../src
	\rm i128symv_lower.cu_o i128symv_lower.cu_lo
	make
	cd ../bench
	\rm test-i128.o test2-i128.o
	make -j
	cd ../tuning/i128symvl-current
}

Get_Reguse()
{
	MMM=$1

	VX=2
	UX=`expr $MMM "*" $VX`

	if [ -e tmp_$MMM ]; then
		\rm -rf tmp_$MMM
	fi
	mkdir tmp_$MMM
	cd tmp_$MMM

	ln -s ../../../include .
	ln -s ../../../half .

	mkdir tuning
	cd tuning
	Make0 >& /dev/null
	cd ..

	mkdir src
	cd src
	ln -s ../../../../src/i128symv_lower-X_template.cu .

	$PYTHON ../../../get_reguse.py $CG main_do \
		./i128symv_lower-X_template.cu \
		| \
		sort -S 1G -k 6 > reg--$MMM
		cp reg--$MMM ../..

	cd ../..
	\rm -rf tmp_$MMM

	echo -n '.'
}

Do()
{
if [ 1 -eq 0 ]; then
cat << EOF_Do
#define	BLOCK_SIZE	$BLOCK_SIZE
#define	VX		$VX
#define	UX		$UX
#define	MULTIPLICITY	$MULTI
#define	_M_		$MX
EOF_Do
fi

	MX1=`expr $MX + 1`
	MX2=`expr $MULTI - 1`
	MX2=`expr $MX2 "*" 100`
	MX3=`expr $MX1 + $MX2`

cat << EOF_INnv0 > IN-nv0
1
0
-1
EOF_INnv0

cat << EOF_INnv > IN-nv
1
1001
6001
9001
EOF_INnv
awk '/MAXDIM3=/{ print $2/2; }' DEV_INFO >> IN-nv
echo '-1' >> IN-nv

  if [ x$ASPEN_CHECK_ERROR = x1 ]; then
	../../bench/test-i128symv-l IN-nv0 $MX3
	timeout -s KILL 240 ../../bench/test-i128symv-l IN-nv $MX3 | \
		awk ' \
			/cannot free/{ \
				system("touch ./.NG"); \
			} \
			/ERR/{ \
				system("touch ./.NG"); \
			} \
			/unavailable/{ \
				system("touch ./.NG"); \
			} \
			{ \
				print;fflush(); \
			} \
		' > /dev/null
  fi

	if [ ! -e ./.NG ]; then

		timeout -s KILL 600 ../../bench/test2-i128symv-l IN-exe-a $MX3 | tee trial-$MX3
		PS=${PIPESTATUS[0]}
		echo $BLOCK_SIZE" "$VX" "$UX" "$MULTI" "$MX >> done_pattern
		echo ''
		echo -n '#-> exit code '$PS
		if [ "$PS" -ne 0 ]; then
			touch ./.NG
			echo ' (unexpected failure)'
		else
			echo ' (successful)'
		fi
		echo ''

	fi

	if [ ! -e ./.NG ]; then

		cat trial-$MX3 \
		| awk '/N=/{ print $2" "$5 }' \
		> data-$MX3

		cat MAXF-$BLOCK_SIZE-$VX-$MULTI data-$MX3 \
		| awk '\
			function fabs(x) { return (x>0?x:-x); } \
			BEGIN{ stable=1; } \
			{ N=$1; P=fabs($2)*1; C=-pp[N]*1; \
				if ( C==0 ) { \
					pp[N] = -P; \
				} else if ( C < P ) { \
					printf( "*** %d %f < %f\n", N, C, P ); \
					pp[N] = -P; \
					if ( N >= 512 ) stable = 0; \
				} \
			} \
			END { \
				for ( N in pp ) { \
					print N" "pp[N]; \
				} \
				if ( stable ) { system( "touch NO_UPDATE" ); } \
			}' \
		| sort -S 1G -gk 1 \
		> MAXF2-$BLOCK_SIZE-$VX-$MULTI

		cat MAXF2-$BLOCK_SIZE-$VX-$MULTI \
			| grep "<" \
			| sort -S 1G -gk 2

		cat MAXF2-$BLOCK_SIZE-$VX-$MULTI \
			| grep -v "<" \
			> MAXF-$BLOCK_SIZE-$VX-$MULTI

		cat MAXF-sub data-$MX3 \
		| awk '\
			function fabs(x) { return (x>0?x:-x); } \
			BEGIN{ out_of_range=1; to_be_update=0; } \
			{ N=$1; P=fabs($2); C=-pp[N]; \
				if ( C < P ) { \
					pp[N] = -P; \
				} \
				if ( (C > 0 && C <= 1e-10) || ( C > 1e-10 && 0.8 * C <= P ) ) { \
					out_of_range=0; \
				} \
				if ( C > 0 ) { \
					if ( (N >= 512) && (P > 0.50 * C) ) to_be_update = 1; \
				} \
			} \
			END { \
				for ( N in pp ) { \
					print N" "pp[N]; \
				} \
				if ( to_be_update == 0 ) { system( "touch NO_UPDATE" ); } \
			}' \
		| sort -S 1G -gk 1 \
		> MAXF2-sub
		cp MAXF2-sub MAXF-sub

		cat MAXF-$BLOCK_SIZE-$VX-$MULTI data-$MX3 \
		| awk '\
			function fabs(x) { return (x>0?x:-x); } \
			BEGIN{ out_of_range=1; to_be_update=0; } \
			{ N=$1; P=fabs($2); C=-pp[N]; \
				if ( C < P ) { \
					pp[N] = -P; \
				} \
				if ( C > 0 ) { \
					if ( (N >= 3072) && (P > 0.75 * C) ) to_be_update = 1; \
				} \
			} \
			END { \
				if ( to_be_update == 0 ) { system( "touch NO_UPDATE" ); } \
			}' \
		> /dev/null
	fi
}



Init

Setup

echo "Sampling start"

	GLOBAL_MAX_UX_MX=0

if [ -L ../i128symvl_reguse ]; then
	\rm ../i128symvl_reguse
fi

#if [ x$ASPEN_REGUSE_CALC != x1 ]; then
if [ 1 -eq 0 ]; then
	if [ -f ../i128symvl_reguse-orig.tgz ]; then
		tar -zxf ../i128symvl_reguse-orig.tgz
		mv ./i128symvl_reguse-orig ..
	fi
	ln -s ./i128symvl_reguse-orig ../i128symvl_reguse
fi

#if [ -e ../i128symvl_reguse/$CUDA/$CG/GLOBAL_MAX_UX_MX ]; then
if [ 1 -eq 0 ]; then

	cp ../i128symvl_reguse/$CUDA/$CG/* .
	cat log-reguse-all
	GLOBAL_MAX_UX_MX=`cat GLOBAL_MAX_UX_MX`

else

    VX_PATTERN="16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1"
  if [ x$ASPEN_TUNING_LEVEL = xFULL ]; then
    VX_PATTERN="24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1"
  fi
  if [ x$ASPEN_TUNING_LEVEL = xROUGH ]; then
    VX_PATTERN="6 5 4 3 2 1"
  fi

  if [ 16 -ge 32 ]; then
    BSIZE_PATTERN="32 64 96 128 160 192 224 256"
  fi
  if [ 16 -eq 16 ]; then
    BSIZE_PATTERN="32 64 96 128 160 192 224 256"
  fi
  if [ 16 -eq 8 ]; then
    BSIZE_PATTERN="32 64 96 128 160 192 224 256"
  fi
  if [ 16 -eq 4 ]; then
    BSIZE_PATTERN="64 96 128 160 192 224 256"
  fi
  if [ 16 -le 2 ]; then
    BSIZE_PATTERN="64 128 192 256 320"
  fi

#%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
CORES=`lscpu -e=core | tail -1 | awk '{ print $1+1}'`
for BLOCK_SIZE in \
      48
do


  for MMM in \
	1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32
  do

	Get_Reguse $MMM &

  done
  wait

  echo ''
done
if [ $GLOBAL_ITR -eq 0 ]; then
for BLOCK_SIZE in \
	$BSIZE_PATTERN
do
	\rm -f log-regs-$BLOCK_SIZE
done
fi
#%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(cd ../../src; make -j >& /dev/null) &

for VX in \
	$VX_PATTERN
do
for BLOCK_SIZE in \
	$BSIZE_PATTERN
do

if [ $GLOBAL_ITR -eq 0 ]; then
if [ -e log-regs-$BLOCK_SIZE-$VX ]; then
	\rm -f log-regs-$BLOCK_SIZE-$VX
fi
fi

THREADS=`expr $BLOCK_SIZE "*" $VX`
if [ $THREADS -ge $Gmin ]; then
if [ $THREADS -le $Gmax ]; then
if [ `expr $THREADS "%" 32` -eq 0 ]; then

	MAX_UX_MX=0
	last_MMM=9999

  for UX in \
	$UX_PATTERN
  do

  THREADS=`expr $BLOCK_SIZE "*" $VX`
  if [ $UX -le $THREADS ]; then

  if [ `expr $UX "%" $VX` -eq 0 ]; then
  if [ 1 -eq 1 ]; then
  if [ `expr $UX "/" $VX` -le 32 ]; then


	MMM_PATTERN="1"
	Make0 >& /dev/null

	M0=`expr $THREADS "+" $UX`

	M=`expr $M0 "*" 16`
	M=`expr $M "-" 1`
	M=`expr $M "/" 16`
	M=`expr $M "+" 1`
	M=`expr $M "*" 16`
	M1=$M

	M2=80 # 8 * sizeof(int) + 6 * sizeof(long) = 32 + 48 = 80

	SHMEM_MIN=`expr $M1 "+" $M2`

	M=`expr $UX "/" $VX`
	if [ -e reg--$M ]; then
		cp reg--$M log-reg-all
	else
		$PYTHON ../get_reguse.py $CG main_do \
			../../src/i128symv_lower-X_template.cu \
			| \
		sort -S 1G -k 6 > log-reg-all
		cp log-reg-all reg--$M
	fi

	MMM=0
	OOO=0
	CCC=0
	SSS=0
	XXX=0

	SSS_1=""
	SSS_2=""

if [ $GLOBAL_ITR -eq 0 ]; then
if [ $GLOBAL_ITR_END -eq 0 ]; then
	MX_PATTERN='0 10  20 30  40 50  60 70 80 90'
else
	MX_PATTERN='0 10 20'
fi
fi
if [ $GLOBAL_ITR -eq 1 ]; then
	MX_PATTERN='30 40 50'
fi
if [ $GLOBAL_ITR -eq 2 ]; then
	MX_PATTERN='60 70 80 90'
fi

      for MX in \
	$MX_PATTERN
      do

	cat log-reg-all | \
		awk '{if($6=='$MX'){print $1;c=1}}END{if(!c)print 0}' > CX-$MX
	CX=`cat CX-$MX`

	cat log-reg-all | \
		awk '{if($6=='$MX'){print $7;c=1}}END{if(!c)print 5}' > SX-$MX
	SX=`cat SX-$MX`

if [ $SX -eq 5 ]; then
	touch multi_use-$MX
else
	M=`expr $BLOCK_SIZE "*" $VX`

#if [ $CG -lt 200 ]; then
	../../src/get_mult $M $CX $SHMEM_MIN $CG &> multi_use-$MX &
#else
#	../../src/get_mult48 $M $CX $SHMEM_MIN $CG &> multi_use-$MX &
#fi
fi

      done
      wait

      for MX in \
	$MX_PATTERN
      do

	cat log-reg-all | \
		awk '{if($6=='$MX'){print $1;c=1}}END{if(!c)print 0}' > CX-$MX
	CX=`cat CX-$MX`

	cat log-reg-all | \
		awk '{if($6=='$MX'){print $7;c=1}}END{if(!c)print 5}' > SX-$MX
	SX=`cat SX-$MX`


	MMM_PATTERN=`cat multi_use-$MX | \
		awk '{ gsub(/\([0-9]*\)/," "); print; }'`
	OOO_PATTERN=`cat multi_use-$MX | \
		awk '{ gsub(/[0-9]*\(/," "); gsub(/\)/,""); print; }'`
	M=`echo $MMM_PATTERN | awk '{ print $(NF); }'`
	O=`echo $OOO_PATTERN | awk '{ print $(NF); }'`
	if [ $M -gt $MMM ]; then
		if [ ! $MMM -eq 0 ]; then
			CCC=1
		fi
		MMM=$M
		OOO=$O
		XXX=$MX

		SSS_1=""
		SSS_2=""
	else
		if [ ! $M -eq $MMM ]; then
			CCC=1
		fi
	fi

	UX_MX=`expr $UX "*" $M`
if [ $UX_MX -gt $MAX_UX_MX ]; then
	if [ $SX -lt 2 ] && [ $BLOCK_SIZE -ge $UX ]; then
		MAX_UX_MX=$UX_MX
	fi
fi

if [ $M -eq $MMM ]; then

	if [ $SX -eq 1 ]; then
		SSS_1=$MX" "$SSS_1
	fi
	if [ $SX -eq 2 ]; then
		SSS_2=$MX" "$SSS_2
	fi

fi

	if [ $SSS -lt $SX ]; then
		SSS=$SX
	fi

	echo $BLOCK_SIZE' '$VX' '$UX' '$MX' Register= '$CX ' / '$SX' :: '$SHMEM_MIN' : '$MMM_PATTERN | \
		tee -a log-regs-$BLOCK_SIZE | tee -a log-regs-$BLOCK_SIZE-$VX

      done # for MX

	if [ ! "x$SSS_1" = "x" ]; then
		XXX=`echo $SSS_1 | awk '{print $1}'`
	else
	if [ ! "x$SSS_2" = "x" ]; then
		XXX=`echo $SSS_2 | awk '{print $1}'`
	else
		XXX=0
	fi
	fi

	echo '## '$BLOCK_SIZE' '$VX' '$UX' '$MMM' / '$OOO'% ! '$CCC' > '$SSS '::' $XXX | \
		tee -a log-regs-$BLOCK_SIZE | tee -a log-regs-$BLOCK_SIZE-$VX


	if [ $MMM -le 1 ]; then
	if [ $last_MMM -le 1 ]; then
		break
	fi
	fi
	if [ $SSS -eq 0 ]; then
		break
	fi
	last_MMM=$MMM

  fi
  fi
  fi

  fi
  done # for UX

M=`expr $MAX_UX_MX "*" $BLOCK_SIZE`
if [ $M -gt $GLOBAL_MAX_UX_MX ]; then
	GLOBAL_MAX_UX_MX=$M
fi

  echo $MAX_UX_MX > MAX_UX_MX-$BLOCK_SIZE-$VX

fi
fi
fi
done # for BLOCK_SIZE
done # for VX

## wait for background make
wait

echo $GLOBAL_MAX_UX_MX > GLOBAL_MAX_UX_MX

fi

cat IN-exe-a | awk '{ print $1" -1e-10" }' > MAXF-all


####
#	GLOBAL_MAX_UX_MX=10000000
####

if [ $GLOBAL_MAX_UX_MX -le 0 ]; then
	M=16384
	M=`expr $M "*" 4`
	M=`expr $M "/" 16`
	M=`expr $M "*" 16`
	M=`expr $M "/" 10`
	GLOBAL_MAX_UX_MX=$M
fi

if [ x$ASPEN_TUNING_LEVEL = xFULL ]; then
	GLOBAL_MAX_UX_MX=10000000
else
# 32*256=8192
	M=16384
	M=`expr $M "*" 4`
	M=`expr $M "/" 16`
	M=`expr $M "*" 16`
	M=`expr $M "/" 10`
if [ $GLOBAL_MAX_UX_MX -gt $M ]; then
	GLOBAL_MAX_UX_MX=$M
fi
fi

####
if [ -e GLOBAL_MAX_UX_MX ]; then
	global_MAX_UX_MX=`cat GLOBAL_MAX_UX_MX`
else
	global_MAX_UX_MX=0
fi
#	GLOBAL_MAX_UX_MX=10000000
####


    VX_PATTERN="16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1"
  if [ x$ASPEN_TUNING_LEVEL = xFULL ]; then
    VX_PATTERN="24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1"
  fi
  if [ x$ASPEN_TUNING_LEVEL = xROUGH ]; then
    VX_PATTERN="6 5 4 3 2 1"
  fi

if [ $GLOBAL_ITR -eq 0 ]; then
	MX_PATTERN='0'
  if [ x$ASPEN_TUNING_LEVEL = xFULL ]; then
	MX_PATTERN='0 10 20'
  fi
  if [ x$ASPEN_TUNING_LEVEL = xROUGH ]; then
	MX_PATTERN='0'
  fi
  ###
if [ $GLOBAL_ITR_END -eq 0 ]; then
	MX_PATTERN='0 10  20 30  40 50  60 70  80 90'
else
	MX_PATTERN='0 10 20'
fi
  ###
fi
if [ $GLOBAL_ITR -eq 1 ]; then
	MX_PATTERN='30'
  if [ x$ASPEN_TUNING_LEVEL = xFULL ]; then
	MX_PATTERN='30 40 50'
  fi
  if [ x$ASPEN_TUNING_LEVEL = xROUGH ]; then
	MX_PATTERN='30'
  fi
  ###
	MX_PATTERN='30 40 50'
  ###
fi
if [ $GLOBAL_ITR -eq 2 ]; then
	MX_PATTERN='80'
  if [ x$ASPEN_TUNING_LEVEL = xFULL ]; then
	MX_PATTERN='60 70 80 90'
  fi
  if [ x$ASPEN_TUNING_LEVEL = xROUGH ]; then
	MX_PATTERN='80'
  fi
  ###
	MX_PATTERN='60 70 80 90'
  ###
fi


\rm DONE-[0-9]*

for VX in \
	$VX_PATTERN
do
for BLOCK_SIZE in \
	$BSIZE_PATTERN
do

TTX=`expr $BLOCK_SIZE "*" $VX`

if [ `expr $TTX "%" 32` -eq 0 ]; then
if [ $TTX -ge $Gmin ]; then
if [ $TTX -le $Gmax ]; then

  if [ -e MAX_UX_MX-$BLOCK_SIZE-$VX ]; then
    MAX_UX_MX=`cat MAX_UX_MX-$BLOCK_SIZE-$VX`
    echo 'MAX UX*MX='$MAX_UX_MX' GLOBAL:MAX_BLK*UX*MX='$GLOBAL_MAX_UX_MX
  else
    MAX_UX_MX=1000000
  fi

  UU_PATTERN_old=""

  for MULTI in \
	$MM_PATTERN
  do

	MM16_PATTERN=" 32 21 16 12 10 9 8 7 6 5 4 3 2 1"
	MM48_PATTERN=" 32 27 24 21 19 17 16 14 13 12 11 10 9 8 7 6 5 4 3 2 1"

	MMxx_PATTERN=$MM48_PATTERN

	M_C=0
	for M in \
		$MMxx_PATTERN
	do
		if [ $M -eq $MULTI ]; then
			M_C=`expr $M_C "+" 1`
		fi
	done # for M

	MMM_PATTERN=$MULTI


	if [ $M_C -eq 0 ]; then
	cat log-regs-$BLOCK_SIZE-$VX | \
		awk '/##/{ if ( $5 == '$MULTI' && $11 ) print $4 }' | \
		sort -S 1G -r -g | \
		head -32 | awk '{printf("%d ",$0) }' > UUU
	else
	cat log-regs-$BLOCK_SIZE-$VX | \
		awk '/##/{ if ( $5 >= '$MULTI' && $11 ) print $4 }' | \
		sort -S 1G -r -g | \
		head -32 | awk '{printf("%d ",$0) }' > UUU
	fi

	NUU=`awk '{ if(NF>0)print $1; else print 0; }END{ if(NR==0)print 0; }' UUU`
	NLL=`awk '{ if(NF>8)print $8; else if(NF>0) print $NF; else print 1000; }END{ if(NR==0)print 1000; }' UUU`

	if [ $CG -le 200 ]; then
		NK=8
	else
		NK=32
	fi

if [ x$ASPEN_TUNING_LEVEL = xFULL ]; then
		NK=256
fi

#######
	cat log-regs-$BLOCK_SIZE-$VX | \
		awk '/##/{ if ( $5 >= 1 && $11 ) print $4 }' | \
		sort -S 1G -r -g | \
		head -$NK | awk '{printf("%d\n",$0) }END{print 0}' > UUU-0
	UU_MIN=`cat UUU-0 | awk '{ v='$VX'; x=2*v; y=int(($1/v+1)/2)*v; if(x<y)x=y; printf("%d\n",x);exit;}'`
	echo '# UU_MIN='$UU_MIN
#######


	if [ $M_C -eq 0 ]; then
	cat log-regs-$BLOCK_SIZE-$VX | \
		awk '/##/{ if ( $5 == '$MULTI' && $11 ) print $4 }' | \
		sort -S 1G -r -g | \
		head -$NK | awk '{printf("%d ",$0) }' > UUU
	cat log-regs-$BLOCK_SIZE-$VX | \
		awk '/##/{ if ( $5 == '$MULTI' && $11 ) print $9 }' | \
		sort -S 1G -r -g | \
		head -1 | awk '{printf("%d ",$0) }' > CCC
	cat log-regs-$BLOCK_SIZE-$VX | \
		awk 'BEGIN{print 1}/##/{ if ( $5 == '$MULTI' && $11 ) print $11 }' | \
		sort -S 1G -r -g | \
		head -1 | awk '{printf("%d ",$0) }' > SSS
	else
	cat log-regs-$BLOCK_SIZE-$VX | \
		awk '/##/{ if ( $5 >= '$MULTI' && $11 ) print $4 }' | \
		sort -S 1G -r -g | \
		head -$NK | awk '{printf("%d ",$0) }' > UUU
	cat log-regs-$BLOCK_SIZE-$VX | \
		awk '/##/{ if ( $5 >= '$MULTI' && $11 ) print $9 }' | \
		sort -S 1G -r -g | \
		head -1 | awk '{printf("%d ",$0) }' > CCC
	cat log-regs-$BLOCK_SIZE-$VX | \
		awk 'BEGIN{print 1}/##/{ if ( $5 >= '$MULTI' && $11 ) print $11 }' | \
		sort -S 1G -r -g | \
		head -1 | awk '{printf("%d ",$0) }' > SSS
	fi


	UU_PATTERN=`cat UUU`
	CCC=`cat CCC`
	SSS=`cat SSS`

	if [ $BLOCK_SIZE -lt $NUU ]; then
	if [ $BLOCK_SIZE -lt $NLL ]; then

		NK=10
if [ x$ASPEN_TUNING_LEVEL = xFULL ]; then
		NK=256
fi
		M1=`expr $BLOCK_SIZE "/" $VX`
		M1=`expr $M1 "*" $VX`
		M2=`expr $M1 "-" $VX`

		echo $UU_PATTERN | \
			awk ' \
			$0 !~ /[\y ]'$M1'[\y ]/{ printf(" %s ",'$M1') } \
			$0 !~ /[\y ]'$M2'[\y ]/{ printf(" %s ",'$M2') } \
		' >> UUU

		UU_PATTERN=`cat UUU`

	fi
	fi

	if [ $SSS -gt 0 ]; then
	if [ $BLOCK_SIZE -lt $NUU ]; then
		CCC=3
	else
		CCC=1
	fi
	fi
if [ x$ASPEN_TUNING_LEVEL = xFULL ]; then
		CCC=256
fi
if [ x$ASPEN_TUNING_LEVEL = xROUGH ]; then
		CCC=1
fi

#################################
		CCC=1
#################################

	CCC=`expr $CCC "*" 3`

###
	CCC=4096
###

	echo $UU_PATTERN | \
	awk '{ for(i=1;i<=NF;i++) print $i; }' | \
		sort -g | \
		uniq | \
		sort -gr | \
	awk '{ printf("%d ",$1); }' > UUU

	UU_PATTERN=`cat UUU`

#	for UX in $UU_PATTERN
#	do
#		if [ `expr $UX "/" $VX` -eq 32 ]; then
#			CCC=4
#		fi
#		break
#	done

	M1=`echo $UU_PATTERN     | awk '{ gsub(/ /,":"); print; }'`

	if [ x${M1} = x ]; then
		echo 'UX[MULTI='$MULTI']:=<none>'
	else
		M=`expr $CCC "+" 1`
		echo 'UX[MULTI='$MULTI']:=<'$UU_PATTERN'> <= '$M
	fi

#####
	if [ $MULTI -eq 1 ]; then
		echo '** Skip'
		continue
	fi
#####

	#M2=`echo $UU_PATTERN_old | awk '{ gsub(/ /,":"); print; }'`
	M2=""

if [ x$ASPEN_TUNING_LEVEL != xFULL ] && [ x${M1} = x${M2} ]; then
	echo '** Skip'
else

if [ 'xi128' = 'xw' ] || [ 'xi128' = 'xu' ] || [ 'xi128' = 'xi128' ]; then
	GTOL=33
	LTOL=50
else
	GTOL=50
	LTOL=66
fi

if [ x$ASPEN_TUNING_LEVEL = xFULL ]; then
	GTOL=0
	LTOL=0
fi

if [ x$ASPEN_TUNING_LEVEL = xROUGH ]; then
	GTOL=80
	LTOL=80
fi

###
	GTOL=0
	LTOL=0
###

	M3=`echo $UU_PATTERN "0" | awk '{print $1}'`
	M4=`expr $MULTI "*" $M3`
	M5=`expr $MAX_UX_MX "*" $LTOL`
	M5=`expr $M5 "/" 100`
	M6=`expr $M4 "*" $BLOCK_SIZE`

	#echo '>>Global:MAX(BLK*MX*UX)=' $GLOBAL_MAX_UX_MX 
	#echo '>>          (BLK*MX*UX)=' $M6 

#if [ $M6 -gt $GLOBAL_MAX_UX_MX ]; then
if [ 1 -eq 0 ]; then
	echo '** Skip, because BLK*MX*UX > Global:MAX(BLK*MX*UX)'
else

	M7=`expr $GLOBAL_MAX_UX_MX "*" $GTOL`
	M7=`expr $M7 "/" 100`

	#echo '>>      GTOL(BLK*MX*UX)=' $M7

if [ $M6 -lt $M7 ]; then
	echo '** Skip, because BLK*MX*UX < 0.'$GTOL'*Global:MAX(BLK*MX*UX)'
else
if [ $M4 -lt $M5 ]; then
	echo '** Skip, because MX*UX < 0.'$LTOL'*Local:MAX(MX*UX)'
else

cat IN-exe-a | awk '{ print $1" -1e-10" }' > MAXF-$BLOCK_SIZE-$VX-$MULTI

cat IN-exe-a | awk '{ print $1" -1e-10" }' > MAXF-UUU

	DONE=0
    for UX in \
	$UU_PATTERN
    do
	if [ -e NO_UPDATE ]; then
		\rm NO_UPDATE
	fi

	if [ -e DONE-$BLOCK_SIZE-$VX-$UX ]; then
		break
	fi

#	if [ $DONE -gt 0 ]; then
#		break
#	fi

    THREADS=`expr $BLOCK_SIZE "*" $VX`
    if [ $UX -le $THREADS ]; then

    if [ `expr $UX "%" $VX` -eq 0 ]; then
#    if [ x$ASPEN_TUNING_LEVEL = xFULL ] || [ `expr $UX "/" $VX` -ge 8 ]; then
    if [ $UX -ge $UU_MIN ]; then
    if [ `expr $UX "/" $VX` -le 32 ]; then
    if [ 1 -eq 1 ]; then

	M8=`expr $MULTI "*" $UX`
	M9=`expr $M8 "*" $BLOCK_SIZE`

	#echo '==Global:MAX(BLK*MX*UX)=' $GLOBAL_MAX_UX_MX 
	#echo '==          (BLK*MX*UX)=' $M9 
	#echo '==      GTOL(BLK*MX*UX)=' $M7

	#if [ $CCC -le 0 ]; then
	#	echo 'CCC count = '$CCC'.'$DONE
	#else
	#	echo 'CCC count = '$CCC
	#fi

#if [ $M9 -gt $GLOBAL_MAX_UX_MX ] || [ $M8 -lt $M5 ] || [ $M9 -lt $M7 ]; then
if [ $M8 -lt $M5 ] || [ $M9 -lt $M7 ]; then

if [ $M9 -lt $M7 ]; then
	echo '** Skip, because BLK*MX*UX < 0.'$GTOL'*Global:MAX(BLK*MX*UX)'
else
if [ $M8 -lt $M5 ]; then
	echo '** Skip, because MX*UX < 0.'$LTOL'*Local:MAX(MX*UX)'
fi
fi

else

	CACHE_SIZE=1000000
	if [ $CG -ge 200 ] && [ $CG -lt 300 ]; then
	CACHE_SIZE=768
	fi
	if [ $CG -ge 300 ] && [ $CG -lt 500 ]; then
	CACHE_SIZE=1536
	fi
	if [ $CG -ge 500 ] && [ $CG -lt 600 ]; then
	CACHE_SIZE=2048
	fi
	if [ $CG -ge 600 ] && [ $CG -lt 700 ]; then
	if [ $CG -eq 600 ]; then
	CACHE_SIZE=4096
	else
	CACHE_SIZE=2048
	fi
	fi
	if [ $CG -ge 700 ] && [ $CG -lt 800 ]; then
	CACHE_SIZE=6144
	fi
	if [ $CG -ge 800 ] && [ $CG -lt 900 ]; then
	if [ $CG -eq 800 ]; then
	CACHE_SIZE=40960
	else
	CACHE_SIZE=6144
	fi
	fi
	if [ $CG -ge 900 ] && [ $CG -lt 1000 ]; then
	CACHE_SIZE=61440
	fi
	if [ $CG -ge 1000 ] && [ $CG -lt 1200 ]; then
	CACHE_SIZE=51200
	fi
	if [ $CG -ge 1200 ]; then
	CACHE_SIZE=65536
	fi

	CH=`expr $CACHE_SIZE "*" 75`
	CH=`expr $CH "/" 100`

	CC=$global_MAX_UX_MX
	CC=`expr $CC "*" 16`
	CC=`expr $CC "*" $MP`
	CC=`expr $CC "/" 1024`
	CC=`expr $CC "/" 2`
	if [ $CC -gt $CH ]; then
		CC=$CH
	fi

	M=`expr $BLOCK_SIZE "*" $UX`
	M=`expr $M "*" $MULTI`
	M=`expr $M "*" 16`
	M=`expr $M "*" $MP`
	MTOTAL=`expr $M "/" 1024`

	M=`expr $BLOCK_SIZE "*" $UX`
	MX1=`expr $MULTI "-" 1`
	M=`expr $M "*" $MX1`
	M=`expr $M "*" 16`
	M=`expr $M "*" $MP`
	MTOTAL2=`expr $M "/" 1024`

#	echo 'Minimum usage of L2 cache       = '$CC'[KB]'
#	echo 'Required mem on L2 for full MXs = '$MTOTAL'[KB]'
#	echo 'Required mem on L2 if lost a MX = '$MTOTAL2'[KB]'

	MOK=0
	if [ $MTOTAL2 -ge $CC ] && [ $MTOTAL2 -le $CACHE_SIZE ]; then
		MOK=2
	fi
	if [ $MTOTAL  -gt $CACHE_SIZE ] && [ $MTOTAL2 -lt $CC ]; then
		MOK=2
	fi
	if [ $MTOTAL  -ge $CC ] && [ $MTOTAL  -lt $CACHE_SIZE ]; then
		MOK=1
	fi
	if [ $MOK -eq 0 ]; then
	CACHE_SIZE2=`expr $CACHE_SIZE "*" 2`
	if [ $MTOTAL2 -ge $CC ] && [ $MTOTAL2 -le $CACHE_SIZE2 ]; then
		MOK=3
	fi
	if [ $MTOTAL  -gt $CACHE_SIZE2 ] && [ $MTOTAL2 -lt $CC ]; then
		MOK=3
	fi
	if [ $MTOTAL  -ge $CC ] && [ $MTOTAL  -lt $CACHE_SIZE2 ]; then
		MOK=2
	fi
	fi
	CCC_STEP=`expr 5 "-" $MOK`

	#######
#
	MOK=1
#
	#######

if [ $MOK -eq 0 ]; then
	echo 'Probably not utilizing L2 Cache effectively'
else

#***********************************************
#***********************************************
	echo $MULTI >  DONE-$BLOCK_SIZE-$VX-$UX
#***********************************************
#***********************************************

	cat log-regs-$BLOCK_SIZE-$VX | \
		awk '/##/{ if ( $3=='$VX' && $4=='$UX') print $13}' | \
		awk '{ MM=$0; M0=MM%10; M1=(MM-M0)/10; print MM" "M0"<"M1; }' > MX0_0

	echo $MX_PATTERN > MX0
	MX0=`cat MX0`

	Make1 >& /dev/null
	Make  >& /dev/null

		if [ -e NG ]; then
			\rm NG
		fi
		if [ -e OK ]; then
			\rm OK
		fi

cat IN-exe-a | awk '{ print $1" -1e-10" }' > MAXF-sub

#      for MX in \
#	0 1 2 3 4 5 6 7 8 9
      for MX in \
	$MX0
      do

#####
	WW=`cat log-regs-$BLOCK_SIZE-$VX | \
		awk '/^[0-9]/{ if ( $3=='$UX' && $4=='$MX' ) { if ( $NF >= '$MULTI' && $8 > 0 ) { print "OK"; exit; } } }'`

if [ x$WW != x ]; then
#####

		if [ -e .NG ]; then
			\rm .NG
		fi
		if [ -e NG2 ]; then
			\rm NG2
		fi
		if [ -e NG3 ]; then
			\rm NG3
		fi

		Do | awk ' \
			/ERROR/ { \
				print; \
				fflush(); \
				exit; \
				next; \
				system("touch NG"); \
			} \
			/!\*!\*/ { \
				NG=1; \
			} \
			{ \
				print; \
				fflush(); \
			} \
			END { \
				fflush(); \
				if(!NG) system("touch OK"); \
			} \
			'

		if [ -e .NG ]; then
			echo 'ERROR in kernel implementation!!'
			\rm .NG
			touch NG
		fi

		if [ -e NG ]; then
			if [ $CCC -gt 0 ]; then
				CCC=0
			fi
			break
		fi

#####
  if [ x$ASPEN_TUNING_LEVEL != xFULL ]; then
	break
  fi
fi
#####

      done # for MX

		if [ -e OK ]; then
		cat MAXF-UUU MAXF-sub \
		| awk '\
			function fabs(x) { return (x>0?x:-x); } \
			BEGIN{ out_of_range=1; } \
			{ N=$1; P=fabs($2); C=-pp[N]; \
				if ( C < P ) { \
					pp[N] = -P; \
				} \
				if ( (C > 0 && C <= 1e-10) || ( C > 1e-10 && 0.8 * C <= P ) ) { \
					out_of_range=0; \
				} \
			} \
			END { \
				for ( N in pp ) { \
					print N" "pp[N]; \
				} \
				if ( out_of_range ) { \
					system( "touch NG2" ); \
				} \
			}' \
		| sort -S 1G -gk 1 \
		> MAXF2-UUU
		cp MAXF2-UUU MAXF-UUU

		cat MAXF-all MAXF-sub \
		| awk '\
			function fabs(x) { return (x>0?x:-x); } \
			BEGIN{ out_of_range=1; j=0; n=0; } \
			{ N=$1; P=fabs($2); C=-pp[N]; n++; \
				if ( C < P ) { \
					pp[N] = -P; \
				} \
				if ( (C > 0 && C <= 1e-10) || ( C > 1e-10 && 0.8 * C <= P ) ) { \
					out_of_range=0; \
				} \
				if ( ( C > 1e-10 && 0.5 * C > P ) ) { \
					j++; \
				} \
			} \
			END { \
				n /= 2; \
				for ( N in pp ) { \
					print N" "pp[N]; \
				} \
				if ( out_of_range || j > n * .67 ) { \
					system( "touch NG3" ); \
				} \
			}' \
		| sort -S 1G -gk 1 \
		> MAXF2-all
		cp MAXF2-all MAXF-all
		fi

		awk '{ if ($1>1)print "%%%% "($1)"  "(-$2) }' MAXF-all 

#		if [ -e NO_UPDATE ]; then
#			\rm NO_UPDATE
##		if [ `expr $UX "/" $VX` -lt 16 ]; then
#			echo 'No updates then the next parameters.'
#			break
##		fi
#		fi

		if [ -e NG ]; then
			\rm NG
			if [ $CCC -le 0 ]; then
				break
			fi
		else
			if [ $CCC -gt 0 ]; then
				CCC=`expr $CCC "-" $CCC_STEP`
			else
				DONE=`expr $DONE "+" 1`
#####
#		if [ -e NG2 ]; then
#			echo 'Quit for exploring UX [2]. No enough improvement'
#			\rm NG2
#			break
#		fi
#####
			fi
		fi
#####
		if [ -e OK ]; then
#####
		if [ -e NG3 ]; then
			\rm NG3
		fi
#		if [ -e NG3 ]; then
#			echo 'Quit for exploring UX [3]. No enough improvement'
#			\rm NG3
#			break
#		fi
#####
			\rm OK
		fi
#####
fi

fi

    fi
    fi
    fi
    fi

    fi
    done # for UX

fi
fi
fi

fi

    UU_PATTERN_old=$UU_PATTERN

  done # for MULTI

fi
fi
fi

  if [ -e log-regs-$BLOCK_SIZE-$VX ]; then
	mv log-regs-$BLOCK_SIZE-$VX  log-regs-$BLOCK_SIZE-$VX.a$GLOBAL_ITR
  fi

done # for BLOCK_SIZE
done # for VX

if [ $GLOBAL_ITR -eq $GLOBAL_ITR_END ]; then
for VX in \
	$VX_PATTERN
do
for BLOCK_SIZE in \
	$BSIZE_PATTERN
do
	cat log-regs-$BLOCK_SIZE-$VX.* > log-regs-$BLOCK_SIZE-$VX
done
done
fi

#echo "Complete phase a"$GLOBAL_ITR
