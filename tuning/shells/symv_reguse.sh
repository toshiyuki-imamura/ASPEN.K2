#!/bin/bash


CUDA_PATH_65=/usr/local/cuda-6.5
CUDA_PATH_70=/usr/local/cuda-7.0
CUDA_PATH_75=/usr/local/cuda-7.5
CUDA_PATH_80=/usr/local/cuda-8.0
CUDA_PATH_90=/usr/local/cuda-9.0
CUDA_PATH_91=/usr/local/cuda-9.1
CUDA_PATH_92=/usr/local/cuda-9.2
CUDA_PATH_100=/usr/local/cuda-10.0
CUDA_PATH_101=/usr/local/cuda-10.1
CUDA_PATH_102=/usr/local/cuda-10.2
CUDA_PATH_default=/usr/local/cuda


Init()
{
	\rm ../CURRENT_GPU
	echo '#define CURRENT_GPU '$CG > ../CURRENT_GPU

	UX_PATTERN=""
	M=1; while [ $M -lt 193 ]
	do
		UX_PATTERN=$UX_PATTERN" "$M
		M=`expr $M "+" 1`
	done

	if [ $CG -lt 300 ]; then
		MM_PATTERN=" 8 7 6 5 4 3 2 1 "
		MM_MAX=8
	else
	if [ $CG -lt 500 ]; then
		MM_PATTERN=" 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 "
		MM_MAX=16
	else
		MM_PATTERN=" 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 "
		MM_MAX=32
	fi
	fi

	Gmin=32
	Gmax=768
}

Setup()
{
	if [ -f $HEADER ]; then
		\rm $HEADER
	fi
	awk ' \
		BEGIN{ \
			print "switch (BLK) {"; \
			for ( i=1; i <= 100*'$MM_MAX'; i+=10 ) { \
				print "#if __KERNEL"i; \
				print "case "i":"; \
				print "\tAPI_private('$FUNC$FORMAT'_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, "int((i-1)/100)+1", "(i-1)%100" >"; \
				print "\t( n, a, lda, x, incx, y, incy, alpha, beta ); break;"; \
				print "#endif" \
			} \
			print "default:"; \
			print "\tfprintf( stderr, \"Not proper Parameter %d \", BLK );"; \
			print "\tbreak;"; \
			print "}"; \
			exit; \
		} { exit; } END { exit; }' > $HEADER
	cp $HEADER ../
}


Make0()
{
	if [ -f $PARAM ]; then
		\rm $PARAM
	fi
	touch $PARAM

cat << EOF_1 >> $PARAM
#define BLOCK_SIZE      $BLOCK_SIZE
#define VX              $VX
#define UX              $UX

// $MMM_PATTERN
EOF_1

        for MULTI in \
                $MMM_PATTERN
        do
        for MX in \
                0 10 20 30 40 50
        do
                ID=`expr $MULTI "-" 1`
                ID=`expr $ID "*" 100`
                ID=`expr $ID "+" $MX`
                ID=`expr $ID "+" 1`
                echo "#define   __KERNEL"$ID" 1" >> $PARAM
        done
        done
	if [ -f ../$PARAM ]; then
		\rm ../$PARAM
	fi
        cp $PARAM ../
}

Do()
{

Init

Setup

echo "Sampling start"

	GLOBAL_MAX_UX_MX=0

for VX in \
	1 2 3 4 5 6 7 8 9 10
do
for BLOCK_SIZE in \
	32 64 96 128 
do
if [ `expr $BLOCK_SIZE "*" $VX` -ge $Gmin ]; then
if [ `expr $BLOCK_SIZE "*" $VX` -le $Gmax ]; then

  touch log-regs-$BLOCK_SIZE
  \rm log-regs-$BLOCK_SIZE

	MAX_UX_MX=0
	last_MMM=9999

  for UX in \
	$UX_PATTERN
  do

   THREADS=`expr $BLOCK_SIZE "*" $VX`
  if [ $UX -le $THREADS ]; then

  if [ `expr $UX "%" $VX` -eq 0 ]; then
  if [ `expr $UX "/" $VX` -ge 1 ]; then
  if [ `expr $UX "/" $VX` -le 32 ]; then


	MMM_PATTERN="1"
	Make0 >& /dev/null

	BK=1
	if [ $SIZEOF -lt 4 ]; then
		BK=`expr 4 "/" $SIZEOF`
	fi
	M=`expr $UX "-" 1`
	M0=`expr $M "%" $BK`
	M=`expr $UX "+" $BK`
	M=`expr $M "-" 1`
	UXX=`expr $M "-" $M0`
	M=`expr $BLOCK_SIZE "*" $VX`
	M=`expr $M "+" $UXX`
	M1=`expr $M "*" $SIZEOF`
	M2=`expr $UXX "*" $SIZEOF`
	if [ $M2 -lt 20 ]; then
		M2=20
	fi
	SHMEM_MIN=`expr $M1 "+" $M2`

	python ../get_reguse.py $CG main_do ../../src/$TEMPLATE.cu > log-reg-all

	MMM=0
	OOO=0
	CCC=0
	SSS=0
	XXX=0

	SSS_1=""
	SSS_2=""

      for MX in \
	0 10 20 30 40 50
      do

	touch log-regs
	\rm log-regs

	\rm CX
	\rm SX
if [ $BODY = 'symv' ]; then
	cat log-reg-all | awk '{ if($6=='$MX'){ print $1 > "CX"; print $7 > "SX"; close("CX"); close("SX"); exit; } }'
fi
if [ $BODY = 'hemv' ]; then
	cat log-reg-all | awk '{ if($6=='$MX'){ print $1 > "CX"; print $7 > "SX"; close("CX"); close("SX"); exit; } }'
fi
	CX=`cat CX`
	SX=`cat SX`

	M=`expr $BLOCK_SIZE "*" $VX`
if [ $CG -lt 200 ]; then
	../../src/get_mult $M $CX $SHMEM_MIN $CG > multi_use
else
	../../src/get_mult48 $M $CX $SHMEM_MIN $CG > multi_use
fi

	MMM_PATTERN=`cat multi_use | \
		awk '{ gsub(/\([0-9]*\)/," "); print; }'`
	OOO_PATTERN=`cat multi_use | \
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
#	if [ $SX -lt 2 ] && [ $BLOCK_SIZE -ge $UX ]; then
		MAX_UX_MX=$UX_MX
#	fi
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
		tee -a log-regs-$BLOCK_SIZE

      done # for MX

	if [ ! "x$SSS_1" == "x" ]; then
		XXX=`echo $SSS_1 | awk '{print $1}'`
	else
	if [ ! "x$SSS_2" == "x" ]; then
		XXX=`echo $SSS_2 | awk '{print $1}'`
	else
		XXX=0
	fi
	fi

      echo '## '$BLOCK_SIZE' '$VX' '$UX' '$MMM' / '$OOO'% ! '$CCC' > '$SSS '::' $XXX | \
		tee -a log-regs-$BLOCK_SIZE


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

  cp log-regs-$BLOCK_SIZE log-regs-$BLOCK_SIZE-$VX
  echo $MAX_UX_MX > MAX_UX_MX-$BLOCK_SIZE-$VX

fi
fi
done # for BLOCK_SIZE
done # for VX

  echo $GLOBAL_MAX_UX_MX > GLOBAL_MAX_UX_MX
}


cd ../src; make get_mult get_mult32 get_mult48; cd ../tuning

\rm .done-symv-reguse

PRECISION=$1
FORMAT=$2
CUDA=$3
CG=$4

if [ $PRECISION != 'w' ] && [ $PRECISION != 'u' ] && [ $PRECISION != 'd' ] && [ $PRECISION != 's' ] && [ $PRECISION != 'z' ] && [ $PRECISION != 'c' ]; then
	PRECISION='d'
fi
if [ $FORMAT != 'u' ] && [ $FORMAT != 'l' ]; then
	FORMAT='u'
fi
if [ $CUDA -ne 6050 ] && [ $CUDA -ne 7000 ] && [ $CUDA -ne 7050 ] && [ $CUDA -ne 8000 ] && [ $CUDA -ne 9000 ] && [ $CUDA -ne 9010 ] && [ $CUDA -ne 9020 ] && [ $CUDA -ne 10000 ] && [ $CUDA -ne 10010 ] && [ $CUDA -ne 10020 ]; then
	CUDA=10020
fi

#for PRECISION in \
#	d s
#do

if [ $PRECISION = 'w' ]; then
	SIZEOF=16
fi
if [ $PRECISION = 'd' ]; then
	SIZEOF=8
fi
if [ $PRECISION = 's' ]; then
	SIZEOF=4
fi
if [ $PRECISION = 'u' ]; then
	SIZEOF=32
fi
if [ $PRECISION = 'z' ]; then
	SIZEOF=16
fi
if [ $PRECISION = 'c' ]; then
	SIZEOF=8
fi

#for FORMAT in \
#	u l
#do


if [ $PRECISION = 'w' ] || [ $PRECISION = 'd' ] || [ $PRECISION = 's' ]; then 
	BODY=symv
	FUNC=HESYMV
fi
if [ $PRECISION = 'u' ] || [ $PRECISION = 'z' ] || [ $PRECISION = 'c' ]; then 
	BODY=hemv
	FUNC=HESYMV
fi

	WORK_DIR=$PRECISION$BODY$FORMAT'_reguse'

if [ $FORMAT = 'u' ]; then
	HEADER=$PRECISION$BODY'-upper-auto.h'
	TEMPLATE=$PRECISION$BODY'_upper-X_template'
else
	HEADER=$PRECISION$BODY'-lower-auto.h'
	TEMPLATE=$PRECISION$BODY'_lower-X_template'
fi
	PARAM='param-'$PRECISION$BODY$FORMAT'.h'


if [ -e $WORK_DIR ]; then
	\rm -rf $WORK_DIR
fi
mkdir $WORK_DIR

#for CUDA in \
#	6050 7000 7050
#do

	if [ $CUDA = '6050' ]; then
		export CUDA_PATH=$CUDA_PATH_65
#if [ x`nvcc --help | grep sm_52` = x ];  then
#CG_Type=" 200 300 350 500"
#else
#CG_Type=" 200 300 350 500 520"
#fi
	fi
	if [ $CUDA = '7000' ]; then
#CG_Type=" 200 300 350 500 520 530"
		export CUDA_PATH=$CUDA_PATH_70
		module unload cuda
		module load cuda/7.0 gcc intel
	fi
	if [ $CUDA = '7050' ]; then
#CG_Type=" 200 300 350 500 520 530"
		export CUDA_PATH=$CUDA_PATH_75
		module unload cuda
		module load cuda/7.5 gcc intel
	fi
	if [ $CUDA = '8000' ]; then
#CG_Type=" 200 300 350 500 520 530 600 610 620"
		export CUDA_PATH=$CUDA_PATH_80
		module unload cuda
		module load cuda/8.0 gcc intel
	fi
	if [ $CUDA = '9000' ]; then
#CG_Type=" 200 300 350 500 520 530 600 610 620 700"
		export CUDA_PATH=$CUDA_PATH_90
		module unload cuda
		module load cuda/9.0 gcc intel
	fi
	if [ $CUDA = '9010' ]; then
#CG_Type=" 200 300 350 500 520 530 600 610 620 700"
		export CUDA_PATH=$CUDA_PATH_91
		module unload cuda
		module load cuda/9.1 gcc intel
	fi
	if [ $CUDA = '9020' ]; then
#CG_Type=" 200 300 350 500 520 530 600 610 620 700"
		export CUDA_PATH=$CUDA_PATH_92
		module unload cuda
		module load cuda/9.2 gcc intel
	fi
	if [ $CUDA = '10000' ]; then
#CG_Type=" 200 300 350 500 520 530 600 610 620 700"
		export CUDA_PATH=$CUDA_PATH_100
		module unload cuda
		module load cuda/10.0 gcc intel
	fi
	if [ $CUDA = '10010' ]; then
#CG_Type=" 200 300 350 500 520 530 600 610 620 700"
		export CUDA_PATH=$CUDA_PATH_101
		module unload cuda
		module load cuda/10.1 gcc intel
	fi
	if [ $CUDA = '10020' ]; then
#CG_Type=" 200 300 350 500 520 530 600 610 620 700"
		export CUDA_PATH=$CUDA_PATH_102
		module unload cuda
		module load cuda/10.2 gcc intel
	fi

	cd $WORK_DIR
	if [ -e  $CUDA ]; then
		\rm -rf $CUDA
	fi
	mkdir $CUDA
	cd ..

#	for CG in \
#		$CG_Type
#	do
		echo 'CUDA '$CUDA'/ CG '$CG'/ '$PRECISION$BODY$FORMAT
		if [ -e log-$CG ]; then
			\rm -rf log-$CG
		fi
		mkdir log-$CG
		cd log-$CG
		Do | tee log-reguse-all
		cd ..
#	done

#	for CG in \
#		$CG_Type
#	do
		cd log-$CG
		\rm CX SX multi_use log-reg-all *.h
		chmod -w *
		cd ..
		mv log-$CG $WORK_DIR/$CUDA/$CG
#	done

#done

#done
#done

\rm CURRENT_GPU
touch .done-$BODY-reguse

exit 0

