#!/bin/sh

#export ASPEN_GPU_ID=0

if [ x"$ASPEN_GPU_ID" = x ]; then
	export ASPEN_GPU_ID=0
fi
if [ x"$CUDA_PATH" = x ] || [ ! -e $CUDA_PATH ]; then
	export CUDA_PATH=/usr/local/cuda
fi

export LD_LIBRARY_PATH=$CUDA_PATH/lib64:$LD_LIBRARY_PATH
export LD_LIBRARY_PATH=`pwd`/../lib:$LD_LIBRARY_PATH

if [ x"$OMP_NUM_THREADS" != x ]; then
	unset OMP_NUM_THREADS
fi

IN=IN-HPC151
IN_FROM=16
IN_TO=40000
IN_STEP=32
IN_RAND=1
if [ $IN_RAND -gt 0 ]; then
awk 'BEGIN{ NN=j=0; \
	for(i='$IN_FROM';i<='$IN_TO';i+='$IN_STEP'){ N[j++]=i; } \
	NN=j; \
	for(k=0;k<NN;k++){ i=k; j=int(rand()*NN); \
		t=N[i]; N[i]=N[j]; N[j]=t; } \
	for(k=0;k<'$IN_RAND';k++){ i=int(rand()*NN); j=int(rand()*NN); \
		t=N[i]; N[i]=N[j]; N[j]=t; } \
	for(k=0;k<NN;k++){ i=k; j=int(rand()*NN); \
		t=N[i]; N[i]=N[j]; N[j]=t; } \
	print 1; \
	for(k=0;k<NN;k++){ print N[k]; } \
	print -1; exit; }' > $IN
else
awk 'BEGIN{ NN=j=0; \
	for(i='$IN_FROM';i<='$IN_TO';i+='$IN_STEP'){ N[j++]=i; } \
	NN=j; \
	for(k=0;k<NN;k++){ print N[k]; } \
	print -1; exit; }' > $IN
fi

#GPU=`../src/get_dev_info | awk '/DEVICE/{ gsub(/^[A-Za-z0-9]*-/,"",$2); gsub(/-/,""); print $2; }'`
GPU=`../src/get_dev_info | awk '/DEVICE/{ gsub(/^[Nn][Vv][Ii][Dd][Ii][Aa]*-/,"",$2); gsub(/^[Gg][Ee][Ff][Oo][Rr][Cc][Ee]*-/,"",$2); gsub(/^[Cc][Uu][Dd][Aa]*-/,"",$2); gsub(/GTX-/,"GTX",$2); gsub(/RTX-/,"RTX",$2); gsub(/-Ti/,"Ti",$2); gsub(/-/,"_"); print $2; }'`
DRIVER=`head -1 /proc/driver/nvidia/version | awk '{ gsub(/.*Module/,""); gsub(/.*x86_64/,""); print $1}'`
CG=`awk '{print $3;exit}' ../tuning/CURRENT_GPU`

EXEC='timeout -s KILL 36000 '
OPTIONAL='-'$DRIVER-`date +%Y:%m:%d-%T`

Tee()
{
if [ $IN_RAND -gt 0 ]; then
	tee $1-temp
	cat $1-temp | \
	awk '{if(flag){print}else{printf("<<<== %d ==>>>%s\n",-10000+i,$0);i++}}/Nmax=/{flag=1;}' | \
	sort -gk2 | \
	awk '{gsub(/<<<== -[0-9]* ==>>>/,""); print}' > $1
	\rm $1-temp
else
	tee $1
fi
}


if [ x$ASPEN_V = x ]; then
ASPEN_V=1.13
fi
if [ x$CUDA_V = x ]; then
CUDA_V=13.4
fi
if [ x$MAGMA_V = x ]; then
MAGMA_V=2.9.0
fi
if [ x$KBLAS_V = x ]; then
KBLAS_V=1.3-beta
fi

# ASPEN path to lib archives
ASPEN_LIB_PATH=$HOME/ASPEN.K2-$ASPEN_V/lib

# MAGMA path to lib archives
#MAGMA_LIB_PATH=/opt/tmp/magma-$MAGMA_V/lib
# MAGMA github clone
MAGMA_LIB_PATH=/opt/tmp/magma/magma/lib

# KBLAS path to lib arachives, though it is not tested
KBLAS_LIB_PATH=/opt/tmp/kblas-$KBLAS_V/lib

export LD_LIBRARY_PATH=$ASPEN_LIB_PATH:$MAGMA_LIB_PATH:$KBLAS_LIB_PATH:$LD_LIBRARY_PATH


if [ x$EXEC_ASPEN = x ]; then
EXEC_ASPEN=1
fi
if [ x$EXEC_CUDA = x ]; then
EXEC_CUDA=1
fi
# MAGMA and KBLAS are optional
# You need to prepare lib archives in advance.
if [ x$EXEC_MAGMA = x ]; then
EXEC_MAGMA=0
fi
if [ x$EXEC_KBLAS = x ]; then
EXEC_KBLAS=0
fi


if [ $EXEC_ASPEN -ne 0 ]; then
make
if [ $CG -ge 600 ]; then
$EXEC ./test2-hsymv-u $IN | Tee log-ASPEN.K2-$ASPEN_V-HSYMVU-$GPU$OPTIONAL
$EXEC ./test2-hsymv-l $IN | Tee log-ASPEN.K2-$ASPEN_V-HSYMVL-$GPU$OPTIONAL
else
\rm log-ASPEN.K2-$ASPEN_V-HSYMVU-$GPU$OPTIONAL
touch log-ASPEN.K2-$ASPEN_V-HSYMVU-$GPU$OPTIONAL
\rm log-ASPEN.K2-$ASPEN_V-HSYMVL-$GPU$OPTIONAL
touch log-ASPEN.K2-$ASPEN_V-HSYMVL-$GPU$OPTIONAL
fi
$EXEC ./test2-ssymv-u $IN | Tee log-ASPEN.K2-$ASPEN_V-SSYMVU-$GPU$OPTIONAL
$EXEC ./test2-ssymv-l $IN | Tee log-ASPEN.K2-$ASPEN_V-SSYMVL-$GPU$OPTIONAL
$EXEC ./test2-dsymv-u $IN | Tee log-ASPEN.K2-$ASPEN_V-DSYMVU-$GPU$OPTIONAL
$EXEC ./test2-dsymv-l $IN | Tee log-ASPEN.K2-$ASPEN_V-DSYMVL-$GPU$OPTIONAL
$EXEC ./test2-wsymv-u $IN | Tee log-ASPEN.K2-$ASPEN_V-WSYMVU-$GPU$OPTIONAL
$EXEC ./test2-wsymv-l $IN | Tee log-ASPEN.K2-$ASPEN_V-WSYMVL-$GPU$OPTIONAL
if [ $CG -ge 600 ]; then
$EXEC ./test2-khemv-u $IN | Tee log-ASPEN.K2-$ASPEN_V-KHEMVU-$GPU$OPTIONAL
$EXEC ./test2-khemv-l $IN | Tee log-ASPEN.K2-$ASPEN_V-KHEMVL-$GPU$OPTIONAL
else
\rm log-ASPEN.K2-$ASPEN_V-KHEMVU-$GPU$OPTIONAL
touch log-ASPEN.K2-$ASPEN_V-KHEMVU-$GPU$OPTIONAL
\rm log-ASPEN.K2-$ASPEN_V-KHEMVL-$GPU$OPTIONAL
touch log-ASPEN.K2-$ASPEN_V-KHEMVL-$GPU$OPTIONAL
fi
$EXEC ./test2-chemv-u $IN | Tee log-ASPEN.K2-$ASPEN_V-CHEMVU-$GPU$OPTIONAL
$EXEC ./test2-chemv-l $IN | Tee log-ASPEN.K2-$ASPEN_V-CHEMVL-$GPU$OPTIONAL
$EXEC ./test2-zhemv-u $IN | Tee log-ASPEN.K2-$ASPEN_V-ZHEMVU-$GPU$OPTIONAL
$EXEC ./test2-zhemv-l $IN | Tee log-ASPEN.K2-$ASPEN_V-ZHEMVL-$GPU$OPTIONAL
$EXEC ./test2-uhemv-u $IN | Tee log-ASPEN.K2-$ASPEN_V-UHEMVU-$GPU$OPTIONAL
$EXEC ./test2-uhemv-l $IN | Tee log-ASPEN.K2-$ASPEN_V-UHEMVL-$GPU$OPTIONAL
$EXEC ./test2-i16symv-u $IN | Tee log-ASPEN.K2-$ASPEN_V-I16SYMVU-$GPU$OPTIONAL
$EXEC ./test2-i16symv-u $IN | Tee log-ASPEN.K2-$ASPEN_V-I16SYMVL-$GPU$OPTIONAL
$EXEC ./test2-i32symv-u $IN | Tee log-ASPEN.K2-$ASPEN_V-I32SYMVU-$GPU$OPTIONAL
$EXEC ./test2-i32symv-u $IN | Tee log-ASPEN.K2-$ASPEN_V-I32SYMVL-$GPU$OPTIONAL
$EXEC ./test2-i64symv-u $IN | Tee log-ASPEN.K2-$ASPEN_V-I64SYMVU-$GPU$OPTIONAL
$EXEC ./test2-i64symv-u $IN | Tee log-ASPEN.K2-$ASPEN_V-I64SYMVL-$GPU$OPTIONAL
$EXEC ./test2-i128symv-u $IN | Tee log-ASPEN.K2-$ASPEN_V-I128SYMVU-$GPU$OPTIONAL
$EXEC ./test2-i128symv-u $IN | Tee log-ASPEN.K2-$ASPEN_V-I128SYMVL-$GPU$OPTIONAL
fi

if [ $EXEC_CUDA  -ne 0 ]; then
make
$EXEC ./cuda-ssymv-u $IN 1 | Tee log-CUDA-$CUDA_V-SSYMVU-$GPU$OPTIONAL
$EXEC ./cuda-ssymv-l $IN 1 | Tee log-CUDA-$CUDA_V-SSYMVL-$GPU$OPTIONAL
$EXEC ./cuda-ssymv-u $IN 0 | Tee log-CUDA-$CUDA_V-SSYMVUnoAtomic-$GPU$OPTIONAL
$EXEC ./cuda-ssymv-l $IN 0 | Tee log-CUDA-$CUDA_V-SSYMVLnoAtomic-$GPU$OPTIONAL
$EXEC ./cuda-dsymv-u $IN 1 | Tee log-CUDA-$CUDA_V-DSYMVU-$GPU$OPTIONAL
$EXEC ./cuda-dsymv-l $IN 1 | Tee log-CUDA-$CUDA_V-DSYMVL-$GPU$OPTIONAL
$EXEC ./cuda-dsymv-u $IN 0 | Tee log-CUDA-$CUDA_V-DSYMVUnoAtomic-$GPU$OPTIONAL
$EXEC ./cuda-dsymv-l $IN 0 | Tee log-CUDA-$CUDA_V-DSYMVLnoAtomic-$GPU$OPTIONAL
$EXEC ./cuda-chemv-u $IN 1 | Tee log-CUDA-$CUDA_V-CHEMVU-$GPU$OPTIONAL
$EXEC ./cuda-chemv-l $IN 1 | Tee log-CUDA-$CUDA_V-CHEMVL-$GPU$OPTIONAL
$EXEC ./cuda-chemv-u $IN 0 | Tee log-CUDA-$CUDA_V-CHEMVUnoAtomic-$GPU$OPTIONAL
$EXEC ./cuda-chemv-l $IN 0 | Tee log-CUDA-$CUDA_V-CHEMVLnoAtomic-$GPU$OPTIONAL
$EXEC ./cuda-zhemv-u $IN 1 | Tee log-CUDA-$CUDA_V-ZHEMVU-$GPU$OPTIONAL
$EXEC ./cuda-zhemv-l $IN 1 | Tee log-CUDA-$CUDA_V-ZHEMVL-$GPU$OPTIONAL
$EXEC ./cuda-zhemv-u $IN 0 | Tee log-CUDA-$CUDA_V-ZHEMVUnoAtomic-$GPU$OPTIONAL
$EXEC ./cuda-zhemv-l $IN 0 | Tee log-CUDA-$CUDA_V-ZHEMVLnoAtomic-$GPU$OPTIONAL
fi

if [ $EXEC_MAGMA -ne 0 ]; then
make magma
$EXEC ./magma-ssymv-u  $IN | Tee log-MAGMA-$MAGMA_V-SSYMVU-$GPU$OPTIONAL
$EXEC ./magma-ssymv-l  $IN | Tee log-MAGMA-$MAGMA_V-SSYMVL-$GPU$OPTIONAL
$EXEC ./magma2-ssymv-u $IN | Tee log-MAGMA2-$MAGMA_V-SSYMVU-$GPU$OPTIONAL
$EXEC ./magma2-ssymv-l $IN | Tee log-MAGMA2-$MAGMA_V-SSYMVL-$GPU$OPTIONAL
$EXEC ./magma-dsymv-u  $IN | Tee log-MAGMA-$MAGMA_V-DSYMVU-$GPU$OPTIONAL
$EXEC ./magma-dsymv-l  $IN | Tee log-MAGMA-$MAGMA_V-DSYMVL-$GPU$OPTIONAL
$EXEC ./magma2-dsymv-u $IN | Tee log-MAGMA2-$MAGMA_V-DSYMVU-$GPU$OPTIONAL
$EXEC ./magma2-dsymv-l $IN | Tee log-MAGMA2-$MAGMA_V-DSYMVL-$GPU$OPTIONAL
$EXEC ./magma-chemv-u  $IN | Tee log-MAGMA-$MAGMA_V-CHEMVU-$GPU$OPTIONAL
$EXEC ./magma-chemv-l  $IN | Tee log-MAGMA-$MAGMA_V-CHEMVL-$GPU$OPTIONAL
$EXEC ./magma2-chemv-u $IN | Tee log-MAGMA2-$MAGMA_V-CHEMVU-$GPU$OPTIONAL
$EXEC ./magma2-chemv-l $IN | Tee log-MAGMA2-$MAGMA_V-CHEMVL-$GPU$OPTIONAL
$EXEC ./magma-zhemv-u  $IN | Tee log-MAGMA-$MAGMA_V-ZHEMVU-$GPU$OPTIONAL
$EXEC ./magma-zhemv-l  $IN | Tee log-MAGMA-$MAGMA_V-ZHEMVL-$GPU$OPTIONAL
$EXEC ./magma2-zhemv-u $IN | Tee log-MAGMA2-$MAGMA_V-ZHEMVU-$GPU$OPTIONAL
$EXEC ./magma2-zhemv-l $IN | Tee log-MAGMA2-$MAGMA_V-ZHEMVL-$GPU$OPTIONAL
fi

if [ $EXEC_KBLAS -ne 0 ]; then
make kblas
$EXEC ./kblas-ssymv-u $IN | Tee log-KBLAS-$KBLAS_V-SSYMVU-$GPU$OPTIONAL
$EXEC ./kblas-ssymv-l $IN | Tee log-KBLAS-$KBLAS_V-SSYMVL-$GPU$OPTIONAL
$EXEC ./kblas-dsymv-u $IN | Tee log-KBLAS-$KBLAS_V-DSYMVU-$GPU$OPTIONAL
$EXEC ./kblas-dsymv-l $IN | Tee log-KBLAS-$KBLAS_V-DSYMVL-$GPU$OPTIONAL
fi

exit 0

