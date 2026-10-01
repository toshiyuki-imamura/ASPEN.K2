SHELL=/bin/bash


GCC = gcc -g -fopenmp
GXX = g++ -g -fopenmp -std=gnu++11

CCFLAGS = -O3
ifneq (x$(wildcard $(MKLROOT)),x)

CBLASDIR = $(MKLROOT)
CBLASLDFLAG = \
	-Wl,-rpath,'$(MKLROOT)/lib/intel64' \
	-L$(MKLROOT)/lib/intel64 \
	-Wl,--no-as-needed \
	-lmkl_gf_lp64 -lmkl_gnu_thread -lmkl_core \
	-lgomp -lpthread -lm -ldl \
	-Wl,--as-needed
CCFLAGS := $(CCFLAGS) -DUSE_MKL

else
ifneq (x$(wildcard $(OPENBLAS_DIR)),x)

CBLASDIR = $(OPENBLAS_DIR)
CBLASLDFLAG = \
	-Wl,-rpath,'$(OPENBLAS_DIR)/lib' \
	-L$(OPENBLAS_DIR)/lib \
	-Wl,--no-as-needed \
	-lopenblas -lm \
	-Wl,--as-needed
CCFLAGS := $(CCFLAGS) -I$(OPENBLAS_DIR)/include

else

CBLASDIR = /usr/lib64/atlas
ifneq (x$(shell find $(CBLASDIR) -name "libtatlas.*" -print),x)
CBLASLDFLAG = -ltatlas
endif
ifneq (x$(shell find $(CBLASDIR) -name "libcblas.*" -print),x)
CBLASLDFLAG = -lcblas
endif

endif
endif

CCFLAGS := $(CCFLAGS) -DCURRENT_GPU=`awk '{print $$3}' ../tuning/CURRENT_GPU`


ASPENDIR = ..
ifeq (x$(CUDA_PATH),x)
CUDADIR  = /usr/local/cuda
else
CUDADIR = $(CUDA_PATH)
endif
#MAGMADIR = /opt/tmp/magma-1.6.0
#MAGMADIR = /opt/tmp/magma-1.6.1
#MAGMADIR = /opt/tmp/magma-1.7.0
#MAGMADIR = /opt/tmp/magma-2.0.1
#MAGMADIR = /opt/tmp/magma-2.1.0
#MAGMADIR = /opt/tmp/magma-2.2.0
#MAGMADIR = /opt/tmp/magma-2.3.0
#MAGMADIR = /opt/tmp/magma-2.4.0
ifeq (x$(MAGMADIR),x)
#MAGMADIR = /opt/tmp/magma-2.5.4
#MAGMADIR = /opt/tmp/magma-2.6.2
MAGMADIR = /opt/tmp/magma-2.9.0
endif
#KBLASDIR = /opt/tmp/kblas-1.2
KBLASDIR = /opt/tmp/kblas-1.3-beta
KBLASDIR = /opt/tmp/kblas-3.0
KBLASDIR = /opt/tmp/kblas-4.0


INCPATH  = -I$(CUDADIR)/include -I$(CBLASDIR)/include \
	-I$(CUDADIR)/../math_libs/include \
	-I../include -I../half/include


ASPEN_LDFLAG = \
	-Wl,-rpath,'$(ASPENDIR)/lib' \
	-L$(ASPENDIR)/lib \
	-Wl,--no-as-needed \
	-laspen \
	-Wl,--as-needed \
	-Wl,-rpath,'$(CBLASDIR)' \
	-L$(CBLASDIR) \
	 $(CBLASLDFLAG)
CUDA_LDFLAG  = \
	-Wl,-rpath,'$(CUDADIR)/lib64' \
	-L$(CUDADIR)/lib64 \
	-Wl,--no-as-needed \
	-lcudart \
	-Wl,--as-needed \
	-Wl,-rpath,'$(CUDADIR)/../math_libs/lib64' \
	-L$(CUDADIR)/../math_libs/lib64 \
	-Wl,--no-as-needed \
	-lcublas -lcublasLt -lcusparse -lcusolver \
	-lnvidia-ml \
	-Wl,--as-needed \
	-L$(CUDADIR)/lib64/stubs \
	-lnvidia-ml
MAGMA_LDFLAG = -L$(MAGMADIR)/lib  -lmagma  -lmkl_rt
KBLAS_LDFLAG = -L$(KBLASDIR)/lib  -lkblas-gpu

COMMON = test-common.o warmup.o
LDFLAGS  = -g -fopenmp -lrt \
		$(COMMON) \
		$(CUDA_LDFLAG)


TEST2_W = test2-wsymv-u test2-wsymv-l
TEST2_D = test2-dsymv-u test2-dsymv-l
TEST2_S = test2-ssymv-u test2-ssymv-l
TEST2_H = test2-hsymv-u test2-hsymv-l
TEST2_I128 = test2-i128symv-u test2-i128symv-l
TEST2_I64 = test2-i64symv-u test2-i64symv-l
TEST2_I32 = test2-i32symv-u test2-i32symv-l
TEST2_I16 = test2-i16symv-u test2-i16symv-l
TEST2_U = test2-uhemv-u test2-uhemv-l
TEST2_Z = test2-zhemv-u test2-zhemv-l
TEST2_C = test2-chemv-u test2-chemv-l
TEST2_K = test2-khemv-u test2-khemv-l
TEST_W = test-wsymv-u test-wsymv-l
TEST_D = test-dsymv-u test-dsymv-l
TEST_S = test-ssymv-u test-ssymv-l
TEST_H = test-hsymv-u test-hsymv-l
TEST_I128 = test-i128symv-u test-i128symv-l
TEST_I64 = test-i64symv-u test-i64symv-l
TEST_I32 = test-i32symv-u test-i32symv-l
TEST_I16 = test-i16symv-u test-i16symv-l
TEST_U = test-uhemv-u test-uhemv-l
TEST_Z = test-zhemv-u test-zhemv-l
TEST_C = test-chemv-u test-chemv-l
TEST_K = test-khemv-u test-khemv-l
CUDA_D = cuda-dgemv-t cuda-dgemv-n cuda-dsymv-u cuda-dsymv-l
CUDA_S = cuda-sgemv-t cuda-sgemv-n cuda-ssymv-u cuda-ssymv-l
CUDA_Z = cuda-zgemv-t cuda-zgemv-n cuda-zhemv-u cuda-zhemv-l
CUDA_C = cuda-cgemv-t cuda-cgemv-n cuda-chemv-u cuda-chemv-l
MAGM_D = magma-dgemv-t magma-dgemv-n magma-dsymv-u magma-dsymv-l
MAGM_S = magma-sgemv-t magma-sgemv-n magma-ssymv-u magma-ssymv-l
MAGM_Z = magma-zgemv-t magma-zgemv-n magma-zhemv-u magma-zhemv-l
MAGM_C = magma-cgemv-t magma-cgemv-n magma-chemv-u magma-chemv-l
MAG2_D = magma2-dgemv-t magma2-dgemv-n magma2-dsymv-u magma2-dsymv-l
MAG2_S = magma2-sgemv-t magma2-sgemv-n magma2-ssymv-u magma2-ssymv-l
MAG2_Z = magma2-zgemv-t magma2-zgemv-n magma2-zhemv-u magma2-zhemv-l
MAG2_C = magma2-cgemv-t magma2-cgemv-n magma2-chemv-u magma2-chemv-l
KBLA_D = kblas-dgemv-t kblas-dgemv-n kblas-dsymv-u kblas-dsymv-l
KBLA_S = kblas-sgemv-t kblas-sgemv-n kblas-ssymv-u kblas-ssymv-l
KBLA_Z = kblas-zgemv-t kblas-zgemv-n kblas-zhemv-u kblas-zhemv-l
KBLA_C = kblas-cgemv-t kblas-cgemv-n kblas-chemv-u kblas-chemv-l



all: aspen cuda # magma kblas

aspen: test-w test-d test-s test-h test-i128 test-i64 test-i32 test-i16 test-u test-z test-c test-k
	@echo true > /dev/null
cuda: cuda-d cuda-s cuda-z cuda-c
	@echo true > /dev/null
magma: magma-d magma-s magma-z magma-c \
	magma2-d magma2-s magma2-z magma2-c
	@echo true > /dev/null
kblas: kblas-d kblas-s kblas-z kblas-c
	@echo true > /dev/null


test-w: $(TEST_W) $(TEST2_W)
	@echo true > /dev/null
test-d: $(TEST_D) $(TEST2_D)
	@echo true > /dev/null
test-s: $(TEST_S) $(TEST2_S)
	@echo true > /dev/null
test-i128: $(TEST_I128) $(TEST2_I128)
	@echo true > /dev/null
test-i64: $(TEST_I64) $(TEST2_I64)
	@echo true > /dev/null
test-i32: $(TEST_I32) $(TEST2_I32)
	@echo true > /dev/null
test-i16: $(TEST_I16) $(TEST2_I16)
	@echo true > /dev/null
test-h: $(TEST_H) $(TEST2_H)
	@echo true > /dev/null
test-u: $(TEST_U) $(TEST2_U)
	@echo true > /dev/null
test-z: $(TEST_Z) $(TEST2_Z)
	@echo true > /dev/null
test-c: $(TEST_C) $(TEST2_C)
	@echo true > /dev/null
test-k: $(TEST_K) $(TEST2_K)
	@echo true > /dev/null
cuda-d: $(CUDA_D)
	@echo true > /dev/null
cuda-s: $(CUDA_S)
	@echo true > /dev/null
cuda-z: $(CUDA_Z)
	@echo true > /dev/null
cuda-c: $(CUDA_C)
	@echo true > /dev/null
magma-d: $(MAGM_D)
	@echo true > /dev/null
magma-s: $(MAGM_S)
	@echo true > /dev/null
magma-z: $(MAGM_Z)
	@echo true > /dev/null
magma-c: $(MAGM_C)
	@echo true > /dev/null
magma2-d: $(MAG2_D)
	@echo true > /dev/null
magma2-s: $(MAG2_S)
	@echo true > /dev/null
magma2-z: $(MAG2_Z)
	@echo true > /dev/null
magma2-c: $(MAG2_C)
	@echo true > /dev/null
kblas-d: $(KBLA_D)
	@echo true > /dev/null
kblas-s: $(KBLA_S)
	@echo true > /dev/null
kblas-z: $(KBLA_Z)
	@echo true > /dev/null
kblas-c: $(KBLA_C)
	@echo true > /dev/null

#$(TEST2_W): test2-w.o $(COMMON) $(ASPENDIR)/lib/libaspen.a 
#	-@touch exe-$@
#	-@\rm exe-$@
#	$(GXX) -o exe-$@ $< $(LDFLAGS) $(ASPEN_LDFLAG); \
#	for f in $(TEST2_W) ; do \
#		touch $$f; \
#		\rm $$f; \
#		ln exe-$@ $$f; \
#	done
#	-@\rm exe-$@
$(TEST2_W): test2-w.o $(COMMON) $(ASPENDIR)/lib/libaspen.a 
	$(GXX) -o $@ $< $(LDFLAGS) $(ASPEN_LDFLAG)
$(TEST2_D): test2-d.o $(COMMON) $(ASPENDIR)/lib/libaspen.a 
	$(GXX) -o $@ $< $(LDFLAGS) $(ASPEN_LDFLAG)
$(TEST2_S): test2-s.o $(COMMON) $(ASPENDIR)/lib/libaspen.a 
	$(GXX) -o $@ $< $(LDFLAGS) $(ASPEN_LDFLAG)
$(TEST2_H): test2-h.o $(COMMON) $(ASPENDIR)/lib/libaspen.a 
	$(GXX) -o $@ $< $(LDFLAGS) $(ASPEN_LDFLAG)
$(TEST2_I128): test2-i128.o $(COMMON) $(ASPENDIR)/lib/libaspen.a 
	$(GXX) -o $@ $< $(LDFLAGS) $(ASPEN_LDFLAG)
$(TEST2_I64): test2-i64.o $(COMMON) $(ASPENDIR)/lib/libaspen.a 
	$(GXX) -o $@ $< $(LDFLAGS) $(ASPEN_LDFLAG)
$(TEST2_I32): test2-i32.o $(COMMON) $(ASPENDIR)/lib/libaspen.a 
	$(GXX) -o $@ $< $(LDFLAGS) $(ASPEN_LDFLAG)
$(TEST2_I16): test2-i16.o $(COMMON) $(ASPENDIR)/lib/libaspen.a 
	$(GXX) -o $@ $< $(LDFLAGS) $(ASPEN_LDFLAG)
$(TEST2_U): test2-u.o $(COMMON) $(ASPENDIR)/lib/libaspen.a 
	$(GXX) -o $@ $< $(LDFLAGS) $(ASPEN_LDFLAG)
$(TEST2_Z): test2-z.o $(COMMON) $(ASPENDIR)/lib/libaspen.a 
	$(GXX) -o $@ $< $(LDFLAGS) $(ASPEN_LDFLAG)
$(TEST2_C): test2-c.o $(COMMON) $(ASPENDIR)/lib/libaspen.a 
	$(GXX) -o $@ $< $(LDFLAGS) $(ASPEN_LDFLAG)
$(TEST2_K): test2-k.o $(COMMON) $(ASPENDIR)/lib/libaspen.a 
	$(GXX) -o $@ $< $(LDFLAGS) $(ASPEN_LDFLAG)

$(TEST_W): test-w.o $(COMMON) $(ASPENDIR)/lib/libaspen.a 
	$(GXX) -o $@ $< $(LDFLAGS) $(ASPEN_LDFLAG)
$(TEST_D): test-d.o $(COMMON) $(ASPENDIR)/lib/libaspen.a 
	$(GXX) -o $@ $< $(LDFLAGS) $(ASPEN_LDFLAG)
$(TEST_S): test-s.o $(COMMON) $(ASPENDIR)/lib/libaspen.a 
	$(GXX) -o $@ $< $(LDFLAGS) $(ASPEN_LDFLAG)
$(TEST_H): test-h.o $(COMMON) $(ASPENDIR)/lib/libaspen.a 
	$(GXX) -o $@ $< $(LDFLAGS) $(ASPEN_LDFLAG)
$(TEST_I128): test-i128.o $(COMMON) $(ASPENDIR)/lib/libaspen.a 
	$(GXX) -o $@ $< $(LDFLAGS) $(ASPEN_LDFLAG)
$(TEST_I64): test-i64.o $(COMMON) $(ASPENDIR)/lib/libaspen.a 
	$(GXX) -o $@ $< $(LDFLAGS) $(ASPEN_LDFLAG)
$(TEST_I32): test-i32.o $(COMMON) $(ASPENDIR)/lib/libaspen.a 
	$(GXX) -o $@ $< $(LDFLAGS) $(ASPEN_LDFLAG)
$(TEST_I16): test-i16.o $(COMMON) $(ASPENDIR)/lib/libaspen.a 
	$(GXX) -o $@ $< $(LDFLAGS) $(ASPEN_LDFLAG)
$(TEST_U): test-u.o $(COMMON) $(ASPENDIR)/lib/libaspen.a 
	$(GXX) -o $@ $< $(LDFLAGS) $(ASPEN_LDFLAG)
$(TEST_Z): test-z.o $(COMMON) $(ASPENDIR)/lib/libaspen.a 
	$(GXX) -o $@ $< $(LDFLAGS) $(ASPEN_LDFLAG)
$(TEST_C): test-c.o $(COMMON) $(ASPENDIR)/lib/libaspen.a 
	$(GXX) -o $@ $< $(LDFLAGS) $(ASPEN_LDFLAG)
$(TEST_K): test-k.o $(COMMON) $(ASPENDIR)/lib/libaspen.a 
	$(GXX) -o $@ $< $(LDFLAGS) $(ASPEN_LDFLAG)

$(CUDA_D): cuda-d.o test-common.o
	$(GXX) -o $@ $< $(LDFLAGS)
$(CUDA_S): cuda-s.o test-common.o
	$(GXX) -o $@ $< $(LDFLAGS)
$(CUDA_Z): cuda-z.o test-common.o
	$(GXX) -o $@ $< $(LDFLAGS)
$(CUDA_C): cuda-c.o test-common.o
	$(GXX) -o $@ $< $(LDFLAGS)

$(MAGM_D): magma-d.o test-common.o
	$(GXX) -o $@ $< $(LDFLAGS) $(MAGMA_LDFLAG)
$(MAGM_S): magma-s.o test-common.o
	$(GXX) -o $@ $< $(LDFLAGS) $(MAGMA_LDFLAG)
$(MAGM_Z): magma-z.o test-common.o
	$(GXX) -o $@ $< $(LDFLAGS) $(MAGMA_LDFLAG)
$(MAGM_C): magma-c.o test-common.o
	$(GXX) -o $@ $< $(LDFLAGS) $(MAGMA_LDFLAG)

$(MAG2_D): magma2-d.o test-common.o
	$(GXX) -o $@ $< $(LDFLAGS) $(MAGMA_LDFLAG)
$(MAG2_S): magma2-s.o test-common.o
	$(GXX) -o $@ $< $(LDFLAGS) $(MAGMA_LDFLAG)
$(MAG2_Z): magma2-z.o test-common.o
	$(GXX) -o $@ $< $(LDFLAGS) $(MAGMA_LDFLAG)
$(MAG2_C): magma2-c.o test-common.o
	$(GXX) -o $@ $< $(LDFLAGS) $(MAGMA_LDFLAG)

$(KBLA_D): kblas-d.o test-common.o
	$(GXX) -o $@ $< $(LDFLAGS) $(KBLAS_LDFLAG)
$(KBLA_S): kblas-s.o test-common.o
	$(GXX) -o $@ $< $(LDFLAGS) $(KBLAS_LDFLAG)
$(KBLA_Z): kblas-z.o test-common.o
	$(GXX) -o $@ $< $(LDFLAGS) $(KBLAS_LDFLAG)
$(KBLA_C): kblas-c.o test-common.o
	$(GXX) -o $@ $< $(LDFLAGS) $(KBLAS_LDFLAG)


GET_NVOPTIONS=`awk '{ sm=$$3/10; print "--generate-code arch=compute_"sm",code=compute_"sm" --generate-code arch=compute_"sm",code=sm_"sm" "; }' ../tuning/CURRENT_GPU`

NVCCFLAG = \
	-I$(ASPENDIR)/include -I$(ASPENDIR)/template \
	-O3 \
	--compiler-options -fno-strict-aliasing \
	--compiler-options -fopenmp \
	--compiler-options -Wall \
	-DUNIX \
	--ptxas-options=-v \
	$(GET_NVOPTIONS) \
	--fmad=true

test-common.o: test-common.c test.h warmup.o
	$(GXX) -o $@ -c $< $(CCFLAGS) $(INCPATH)
warmup.o: warmup.cu
	$(CUDA_PATH)/bin/nvcc -g $(NVCCFLAG) -c    warmup.cu
test2-w.o: test2.c test-common.h test.h
	$(GXX) -o $@ -c $< $(CCFLAGS) $(INCPATH) -I$(ASPENDIR)/include \
	-DTYPE_DD=1
test2-d.o: test2.c test-common.h test.h
	$(GXX) -o $@ -c $< $(CCFLAGS) $(INCPATH) -I$(ASPENDIR)/include \
	-DTYPE_DOUBLE=1
test2-s.o: test2.c test-common.h test.h
	$(GXX) -o $@ -c $< $(CCFLAGS) $(INCPATH) -I$(ASPENDIR)/include \
	-DTYPE_FLOAT=1
test2-h.o: test2.c test-common.h test.h
	$(GXX) -o $@ -c $< $(CCFLAGS) $(INCPATH) -I$(ASPENDIR)/include \
	-DTYPE_HALF=1
test2-i128.o: test2.c test-common.h test.h
	$(GXX) -o $@ -c $< $(CCFLAGS) $(INCPATH) -I$(ASPENDIR)/include \
	-DTYPE_INT128=1
test2-i64.o: test2.c test-common.h test.h
	$(GXX) -o $@ -c $< $(CCFLAGS) $(INCPATH) -I$(ASPENDIR)/include \
	-DTYPE_INT64=1
test2-i32.o: test2.c test-common.h test.h
	$(GXX) -o $@ -c $< $(CCFLAGS) $(INCPATH) -I$(ASPENDIR)/include \
	-DTYPE_INT32=1
test2-i16.o: test2.c test-common.h test.h
	$(GXX) -o $@ -c $< $(CCFLAGS) $(INCPATH) -I$(ASPENDIR)/include \
	-DTYPE_INT16=1
test2-u.o: test2.c test-common.h test.h
	$(GXX) -o $@ -c $< $(CCFLAGS) $(INCPATH) -I$(ASPENDIR)/include \
	-DTYPE_DD_COMPLEX=1
test2-z.o: test2.c test-common.h test.h
	$(GXX) -o $@ -c $< $(CCFLAGS) $(INCPATH) -I$(ASPENDIR)/include \
	-DTYPE_DOUBLE_COMPLEX=1
test2-c.o: test2.c test-common.h test.h
	$(GXX) -o $@ -c $< $(CCFLAGS) $(INCPATH) -I$(ASPENDIR)/include \
	-DTYPE_FLOAT_COMPLEX=1
test2-k.o: test2.c test-common.h test.h
	$(GXX) -o $@ -c $< $(CCFLAGS) $(INCPATH) -I$(ASPENDIR)/include \
	-DTYPE_HALF_COMPLEX=1

test-w.o: test.c test-common.h test.h
	$(GXX) -o $@ -c $< $(CCFLAGS) $(INCPATH) -I$(ASPENDIR)/include \
	-DTYPE_DD=1
test-d.o: test.c test-common.h test.h
	$(GXX) -o $@ -c $< $(CCFLAGS) $(INCPATH) -I$(ASPENDIR)/include \
	-DTYPE_DOUBLE=1
test-s.o: test.c test-common.h test.h
	$(GXX) -o $@ -c $< $(CCFLAGS) $(INCPATH) -I$(ASPENDIR)/include \
	-DTYPE_FLOAT=1
test-h.o: test.c test-common.h test.h
	$(GXX) -o $@ -c $< $(CCFLAGS) $(INCPATH) -I$(ASPENDIR)/include \
	-DTYPE_HALF=1
test-i128.o: test.c test-common.h test.h
	$(GXX) -o $@ -c $< $(CCFLAGS) $(INCPATH) -I$(ASPENDIR)/include \
	-DTYPE_INT128=1
test-i64.o: test.c test-common.h test.h
	$(GXX) -o $@ -c $< $(CCFLAGS) $(INCPATH) -I$(ASPENDIR)/include \
	-DTYPE_INT64=1
test-i32.o: test.c test-common.h test.h
	$(GXX) -o $@ -c $< $(CCFLAGS) $(INCPATH) -I$(ASPENDIR)/include \
	-DTYPE_INT32=1
test-i16.o: test.c test-common.h test.h
	$(GXX) -o $@ -c $< $(CCFLAGS) $(INCPATH) -I$(ASPENDIR)/include \
	-DTYPE_INT16=1
test-u.o: test.c test-common.h test.h
	$(GXX) -o $@ -c $< $(CCFLAGS) $(INCPATH) -I$(ASPENDIR)/include \
	-DTYPE_DD_COMPLEX=1
test-z.o: test.c test-common.h test.h
	$(GXX) -o $@ -c $< $(CCFLAGS) $(INCPATH) -I$(ASPENDIR)/include \
	-DTYPE_DOUBLE_COMPLEX=1
test-c.o: test.c test-common.h test.h
	$(GXX) -o $@ -c $< $(CCFLAGS) $(INCPATH) -I$(ASPENDIR)/include \
	-DTYPE_FLOAT_COMPLEX=1
test-k.o: test.c test-common.h test.h
	$(GXX) -o $@ -c $< $(CCFLAGS) $(INCPATH) -I$(ASPENDIR)/include \
	-DTYPE_HALF_COMPLEX=1

cuda-d.o: cuda2.c test-common.h cuda.h
	$(GXX) -o $@ -c $< $(CCFLAGS) $(INCPATH) \
	-DTYPE_DOUBLE=1
cuda-s.o: cuda2.c test-common.h cuda.h
	$(GXX) -o $@ -c $< $(CCFLAGS) $(INCPATH) \
	-DTYPE_FLOAT=1
cuda-z.o: cuda2.c test-common.h cuda.h
	$(GXX) -o $@ -c $< $(CCFLAGS) $(INCPATH) \
	-DTYPE_DOUBLE_COMPLEX=1
cuda-c.o: cuda2.c test-common.h cuda.h
	$(GXX) -o $@ -c $< $(CCFLAGS) $(INCPATH) \
	-DTYPE_FLOAT_COMPLEX=1

magma-d.o: magma.c test-common.h magma.h
	$(GXX) -o $@ -c $< $(CCFLAGS) $(INCPATH) -I$(MAGMADIR)/include \
	-DTYPE_DOUBLE=1
magma-s.o: magma.c test-common.h magma.h
	$(GXX) -o $@ -c $< $(CCFLAGS) $(INCPATH) -I$(MAGMADIR)/include \
	-DTYPE_FLOAT=1
magma-z.o: magma.c test-common.h magma.h
	$(GXX) -o $@ -c $< $(CCFLAGS) $(INCPATH) -I$(MAGMADIR)/include \
	-DTYPE_DOUBLE_COMPLEX=1
magma-c.o: magma.c test-common.h magma.h
	$(GXX) -o $@ -c $< $(CCFLAGS) $(INCPATH) -I$(MAGMADIR)/include \
	-DTYPE_FLOAT_COMPLEX=1

magma2-d.o: magma2.c test-common.h magma.h
	$(GXX) -o $@ -c $< $(CCFLAGS) $(INCPATH) -I$(MAGMADIR)/include \
	-DTYPE_DOUBLE=1
magma2-s.o: magma2.c test-common.h magma.h
	$(GXX) -o $@ -c $< $(CCFLAGS) $(INCPATH) -I$(MAGMADIR)/include \
	-DTYPE_FLOAT=1
magma2-z.o: magma2.c test-common.h magma.h
	$(GXX) -o $@ -c $< $(CCFLAGS) $(INCPATH) -I$(MAGMADIR)/include \
	-DTYPE_DOUBLE_COMPLEX=1
magma2-c.o: magma2.c test-common.h magma.h
	$(GXX) -o $@ -c $< $(CCFLAGS) $(INCPATH) -I$(MAGMADIR)/include \
	-DTYPE_FLOAT_COMPLEX=1

kblas-d.o: kblas.c test-common.h kblas.h
	$(GXX) -o $@ -c $< $(CCFLAGS) $(INCPATH) -I$(KBLASDIR)/include \
	-DTYPE_DOUBLE=1
kblas-s.o: kblas.c test-common.h kblas.h
	$(GXX) -o $@ -c $< $(CCFLAGS) $(INCPATH) -I$(KBLASDIR)/include \
	-DTYPE_FLOAT=1
kblas-z.o: kblas.c test-common.h cuda.h
	$(GXX) -o $@ -c $< $(CCFLAGS) $(INCPATH) -I$(KBLASDIR)/include \
	-DTYPE_DOUBLE_COMPLEX=1
kblas-c.o: kblas.c test-common.h cuda.h
	$(GXX) -o $@ -c $< $(CCFLAGS) $(INCPATH) -I$(KBLASDIR)/include \
	-DTYPE_FLOAT_COMPLEX=1


$(TEST_W) $(TEST_D) $(TEST_S) $(TEST_H) \
$(TEST_I128) $(TEST_I64) $(TEST_I32) $(TEST_I16) \
$(TEST_U) $(TEST_Z) $(TEST_C) $(TEST_K) \
$(TEST2_W) $(TEST2_D) $(TEST2_S) $(TEST2_H) \
$(TEST2_I128) $(TEST2_I64) $(TEST2_I32) $(TEST2_I16) \
$(TEST2_U) $(TEST2_Z) $(TEST2_C) $(TEST2_K): \
	$(ASPENDIR)/lib/libaspen.a



clean:
	@echo '\rm \
		*.o *.ptx \
		$(TEST2_W) $(TEST2_D) $(TEST2_S) $(TEST2_H) \
		$(TEST2_I128) $(TEST2_I64) $(TEST2_I32) $(TEST2_I16) \
		$(TEST2_U) $(TEST2_Z) $(TEST2_C) $(TEST2_K)\
		$(TEST_W) $(TEST_D) $(TEST_S) $(TEST_H) \
		$(TEST_I128) $(TEST_I64) $(TEST_I32) $(TEST_I16) \
		$(TEST_U) $(TEST_Z) $(TEST_C) $(TEST_K)\
		$(CUDA_D) $(CUDA_S) \
		$(CUDA_Z) $(CUDA_C) \
		$(MAGM_D) $(MAGM_S) \
		$(MAGM_Z) $(MAGM_C) \
		$(MAG2_D) $(MAG2_S) \
		$(MAG2_Z) $(MAG2_C) \
		$(KBLA_D) $(KBLA_S) \
		$(KBLA_Z) $(KBLA_C) \
	'
	@for f in \
		*.o *.ptx \
		$(TEST2_W) $(TEST2_D) $(TEST2_S) $(TEST2_H) \
		$(TEST2_I128) $(TEST2_I64) $(TEST2_I32) $(TEST2_I16) \
		$(TEST2_U) $(TEST2_Z) $(TEST2_C) $(TEST2_K)\
		$(TEST_W) $(TEST_D) $(TEST_S) $(TEST_H) \
		$(TEST_I128) $(TEST_I64) $(TEST_I32) $(TEST_I16) \
		$(TEST_U) $(TEST_Z) $(TEST_C) $(TEST_K)\
		$(CUDA_D) $(CUDA_S) \
		$(CUDA_Z) $(CUDA_C) \
		$(MAGM_D) $(MAGM_S) \
		$(MAGM_Z) $(MAGM_C) \
		$(MAG2_D) $(MAG2_S) \
		$(MAG2_Z) $(MAG2_C) \
		$(KBLA_D) $(KBLA_S) \
		$(KBLA_Z) $(KBLA_C) \
	; do \
		if [ -e $$f ]; then \
		if [ -f $$f ]; then \
			\rm $$f; \
		fi; \
		fi; \
	done


indent:
	@echo 'Source reformatting for :: '
	@for f in *.c; do \
		echo -n $$f; \
		emacs --script ../etc/indent.el $$f; \
		if [ -e $$f~ ]; then \
		if [ -f $$f~ ]; then \
			\rm $$f~; \
		fi; \
		fi; \
	done
