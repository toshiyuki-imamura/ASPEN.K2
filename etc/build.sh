#!/bin/sh

export ASPEN_TUNING_LEVEL=DEFAULT
export ASPEN_REGUSE_CALC=0
export ASPEN_CHECK_ERROR=0

#export ASPEN_GPU_ID=0

if [ x"$ASPEN_GPU_ID" = x ]; then
	export ASPEN_GPU_ID=0
fi

BUILD=`date '+%Y%m%d.%H%M%S'`
WORK=ASPEN.K2-1.12

LD_PATH_OLD=$LD_LIBRARY_PATH

export CUDA_PATH=/usr/local/cuda-13.3
if [ x"$LD_PATH_OLD" = x ]; then
	export LD_LIBRARY_PATH=$CUDA_PATH/lib64
else
	export LD_LIBRARY_PATH=$CUDA_PATH/lib64:$LD_PATH_OLD
fi

if [ ! -e $WORK ]; then
	if [ ! -e $WORK.tgz ]; then
		if [ -e ../$WORK || -e ../$WORK.tgz ]; then
		echo 'ERROR : Do not exec here, Move the upper directory.'
		else
		echo 'ERROR : '$WORK'.tgz does not exist.'
		fi
		exit 1
	else
		tar -zxvf $WORK.tgz
	fi
fi

cd $WORK

CUDA=13030
VERSION=`echo $CUDA | awk '{ v=$1; s=int(v/100); m=int(v-s*100); s=int(s/10); m=int(m/10); print s"."m; }'`

export CUDA_PATH=/usr/local/cuda-$VERSION
if [ x"$LD_PATH_OLD" = x ]; then
	export LD_LIBRARY_PATH=$CUDA_PATH/lib64
else
	export LD_LIBRARY_PATH=$CUDA_PATH/lib64:$LD_PATH_OLD
fi
make cleanclean
make

export CUDAx=`awk '/CURRENT_GPU/{ print $3; }' tuning/CURRENT_GPU`
export GPU=`awk '/DEVICE=/{ print $2; }' tuning/DEV_INFO`

cd ..

export ASPEN_TUNING_LEVEL=DEFAULT

CUDA_list='13030'

for CUDA in \
	$CUDA_list
do

	VERSION=`echo $CUDA | awk '{ v=$1; s=int(v/100); m=int(v-s*100); s=int(s/10); m=int(m/10); print s"."m; }'`

	export CUDA_PATH=/usr/local/cuda-$VERSION
if [ x"$LD_PATH_OLD" = x ]; then
	export LD_LIBRARY_PATH=$CUDA_PATH/lib64
else
	export LD_LIBRARY_PATH=$CUDA_PATH/lib64:$LD_PATH_OLD
fi
	cd $WORK
	make cleanclean
	make
	export GPU=`awk '/DEVICE=/{ print $2; }' tuning/DEV_INFO`

	make keepP2
	/bin/bash etc/keepP2.sh

	make tuned-new-symv tuned-new-hemv |& tee log-newkernel-$GPU-$CUDA

	killall -9 keepP2

	cd tuning
	if [ ! -e tuning-old/$GPU ]; then
		mkdir tuning-old/$GPU
	fi
	if [ ! -e tuning-old/$GPU/$CUDA ]; then
		mkdir tuning-old/$GPU/$CUDA
	fi
	cp *.c *.h tuning-old/$GPU/$CUDA/
	cd ../..

export ASPEN_TUNING_LEVEL=ROUGH

done

export CUDA_PATH=/usr/local/cuda-13.3
if [ x"$LD_PATH_OLD" = x ]; then
	export LD_LIBRARY_PATH=$CUDA_PATH/lib64
else
	export LD_LIBRARY_PATH=$CUDA_PATH/lib64:$LD_PATH_OLD
fi

tar -C $WORK/tuning/tuning-old --xz -cf $WORK-$GPU-$BUILD.txz $GPU
tar --xz -cf $WORK-$BUILD.txz $WORK
mv $WORK $WORK-$BUILD
tar --xz -xf $WORK-$BUILD.txz
cd $WORK
make clobber
\rm log-*

make
cd bench
make
export XGPU=`echo $GPU | awk '/DEVICE/{ gsub(/^[A-Za-z0-9]*-/,"",$2); gsub(/-/,""); print $2; }'`
/bin/sh ./exe.sh

LOG_ARCHIVE=logs-1.12
if [ ! -e $LOG_ARCHIVE ]; then
	mkdir $LOG_ARCHIVE
fi
mv log-*$XGPU-* $LOG_ARCHIVE
cd ..
make clobber

cd ..
tar -zcf $WORK.tgz $WORK

export LD_LIBRARY_PATH=$LD_PATH_OLD

exit
