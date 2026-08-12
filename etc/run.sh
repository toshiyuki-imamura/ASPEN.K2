#!/bin/bash
#SBATCH --job-name=ASPEN
#SBATCH --time=24:00:00
#SBATCH --partition=a100

module avail

module load system/x86_64
module load gnu9
module load cuda
module load openblas

export __LMOD_REF_COUNT_CUDA_HOME=/usr/local/cuda-11.7:1
export CUDA_PATH=/usr/local/cuda-11.7
export CUDA_TOP=/usr/local/cuda-11.7
export __LMOD_REF_COUNT_CUDA_PATH=/usr/local/cuda-11.7:1
export CUDA_HOME=/usr/local/cuda-11.7
export __LMOD_REF_COUNT_CUDA_TOP=/usr/local/cuda-11.7:1
export PATH=/usr/local/cuda-11.7/bin:$PATH
export LD_LIBRARY_PATH=/usr/local/cuda-11.7/lib64:$LD_LIBRARY_PATH

module list


TARGET=$1
if [ x$TARGET = x ]; then
        make clobber
        make
        cd bench
        make -j
        /bin/sh ./exe.sh
        exit 0
fi

nvidia-smi

make ${TARGET}
cd tuning
cp *.h ./tuning-old/A100-SXM-80GB/12000/
