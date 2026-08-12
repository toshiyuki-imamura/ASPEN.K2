SHELL=/bin/bash

#
# Makefile for ASPEN.K2
#
CC      = g++ --std=c++17
FC      = gfortran
CP      = cp
AR      = ar
RANLIB  = ranlib
LN      = ln
INSTALL = $(CP)
NVCC    = $(CUDA_PATH)/bin/nvcc -std=c++17
NVAS    = $(CUDA_PATH)/bin/ptxas

INCLUDEPATH = \
		-I$(CUDA_PATH)/include -I$(CUDA_PATH)/src -I../include -I. \
		-I../half/include/
LDFLAG      = \
		-Wl,-rpath,$(CUDA_PATH)/lib64 \
		-L$(CUDA_PATH)/lib64 -Wl,--no-as-needed -lcudart \
		-Wl,-rpath,$(CUDA_PATH)/targets/sbsa-linux/lib/stubs \
		-L$(CUDA_PATH)/targets/sbsa-linux/lib/stubs -Wl,--no-as-needed -lnvidia-ml
ASPENLIBDIR = \
		../lib

FPIC        = \
		-fPIC

# if cuda-memchemck is needed to run, specify MEMCHECK
#MEMCHECK    = -Xcompiler -rdynamic -lineinfo
MEMCHECK    = -Xcompiler -rdynamic
MEMCHECK    =

REGMAX=255
#		-g -G
#		-O3
NVCOPTION_BASE  = -O3 \
		$(MEMCHECK) \
		--default-stream per-thread \
		--split-compile-extended 0 \
		--compiler-options -fno-strict-aliasing \
		--compiler-options -fopenmp \
		--compiler-options $(FPIC) \
		--compiler-options -Wall \
		-DUNIX \
		--ptxas-options='--allow-expensive-optimizations true' \
		--ptxas-options='--register-usage-level 0' \
		--ptxas-options=-v \
		-maxrregcount=$(REGMAX) \
		-extra-device-vectorization \
		--default-stream per-thread \
		--dopt=on \
		--fmad=true
NVCOPTION_AT    =


LIB_ASPEN   =  libaspen.a libaspen.so
CURRENT_GPU =  ../tuning/CURRENT_GPU
CXXOBJS     =  aspen.o aspen_fortran.o
SYMV_NAME   = \
		wsymv dsymv ssymv hsymv \
		i16symv i32symv i64symv i128symv \
		uhemv zhemv chemv khemv
UTIL_NAME   = \
		zero \
		axpy axpby scal swap copy 
SYMV_OBJS   = \
        $(addsuffix _upper.cu_o, $(SYMV_NAME)) \
        $(addsuffix _lower.cu_o, $(SYMV_NAME))
SYMV_SMALL_OBJS   = \
	$(addsuffix _upper_small.cu_o, $(SYMV_NAME)) \
	$(addsuffix _lower_small.cu_o, $(SYMV_NAME))
ASPEN_OBJS = \
        $(addsuffix .cu_o, $(SYMV_NAME)) \
	$(SYMV_OBJS) \
        $(addsuffix .cu_o, $(UTIL_NAME)) 


# default target
all:: $(CURRENT_GPU)
all:: $(LIB_ASPEN)

# short cut name
hesymv: $(SYMV_OBJS)
symv_u: $(filter %symv_upper.cu_o, $(SYMV_OBJS))
symv_l: $(filter %symv_lower.cu_o, $(SYMV_OBJS))
hemv_u: $(filter %hemv_upper.cu_o, $(SYMV_OBJS))
hemv_l: $(filter %hemv_lower.cu_o, $(SYMV_OBJS))
symv: symv_u symv_l
hemv: hemv_u hemv_l
hesymv_u: hemv_u symv_u
hesymv_l: hemv_l symv_l
$(foreach f, $(SYMV_NAME), $(f)_u) : % : %pper.cu_o
$(foreach f, $(SYMV_NAME), $(f)_l) : % : %ower.cu_o


$(CURRENT_GPU): get_dev_info
	@export LD_LIBRARY_PATH=$(CUDA_PATH)/lib64:$(LD_LIBRARY_PATH); \
	./get_dev_info $(ASPEN_GPU_ID) | \
		awk '/CG=/{ print "#define CURRENT_GPU "int($$2); done=1; }END{ if(!done)print "#define CURRENT_GPU 0";}' > $(CURRENT_GPU)__
	@if [ `awk '{print $$3}' $(CURRENT_GPU)__` -ne 0 ]; then \
		\mv $(CURRENT_GPU)__ $(CURRENT_GPU); \
		cat $(CURRENT_GPU); \
	else \
		\touch $(CURRENT_GPU); \rm $(CURRENT_GPU) 1; \
	fi

HEADERS = \
	$(foreach f,$(SYMV_NAME), \
		param-$(f)u.h param-$(f)l.h \
		$(f)-upper-auto.h  $(f)-lower-auto.h  \
		$(f)-upper-auto2.h $(f)-lower-auto2.h )


HEADERS_for = $(addprefix ../tuning/,$(HEADERS))
HEADERS_DIR = tuning/tuning-old/default/default

$(HEADERS_for): %: $(%:tuning=$(HEADERS_DIR))
	#cp $(subst ../tuning,../$(HEADERS_DIR),$@) $@
	awk '/x, y/{ gsub( /x, y/, "x, incx, y, incy" ) }{ print }' \
		$(subst ../tuning,../$(HEADERS_DIR),$@) > $@


aspen.o: aspen.cpp get_tuned_gpuid.h
	$(CC) $(FPIC) -g $(INCLUDEPATH) -o $@ -c $< -DCHECK_TUNED_GPUID=1
aspen_startup.o: aspen.cpp
	$(CC) -g $(INCLUDEPATH) -o $@ -c $< 
aspen_fortran.o: aspen_fortran.cpp
	$(CC) $(FPIC) -g $(INCLUDEPATH) -o $@ -c $< 
get_tuned_gpuid.o: get_tuned_gpuid.c
	$(CC) -g $(INCLUDEPATH) -o $@ -c $< 
get_tuned_gpuid.h:
	@touch $@; \rm $@; touch $@
	echo  'int API(get_tuned_gpuid)(void)' >> $@
	echo  '{ return ('$(ASPEN_GPU_ID)'+0);' } >> $@
get_dev_info: get_dev_info.o aspen_startup.o
	$(CC) -g -O3 -o $@ get_dev_info.o aspen_startup.o $(LDFLAG)
get_dev_info.o: get_dev_info.c
	$(CC) -g $(INCLUDEPATH) -o $@ -c $<
get_mult48: get_mult48.o
	$(CC) -g -O3 -o $@ $<
get_mult32 get_mult: get_mult48
	if [ -f $@ ]; then \
		\rm $@; \
	fi
	$(LN) $< $@
get_mult48.o: get_mult48.c	
	$(CC) -g -O3 $(INCLUDEPATH) -o $@ -c $<


GET_NVOPTIONS_BASE=`awk '{ sm=$$3/10; print "--gpu-architecture=sm_"sm" --generate-code arch=compute_"sm",code=compute_"sm" --generate-code arch=compute_"sm",code=sm_"sm; }' $(CURRENT_GPU)` --define-macro CURRENT_GPU=`awk '{ print $$3}' $(CURRENT_GPU)`
GET_NVOPTIONS_ALLS=\
	--gpu-architecture=sm_`awk '{ print $$3/10; }' $(CURRENT_GPU)` \
	--generate-code arch=compute_80,code=compute_80 \
	--generate-code arch=compute_80,code=sm_80 \
	--generate-code arch=compute_86,code=compute_86 \
	--generate-code arch=compute_86,code=sm_86 \
	--generate-code arch=compute_89,code=compute_89 \
	--generate-code arch=compute_89,code=sm_89 \
	--generate-code arch=compute_90,code=compute_90 \
	--generate-code arch=compute_90,code=sm_90 \
	--generate-code arch=compute_100,code=compute_100 \
	--generate-code arch=compute_100,code=sm_100 \
	--generate-code arch=compute_120,code=compute_120 \
	--generate-code arch=compute_120,code=sm_120 \
	--define-macro CURRENT_GPU=`awk '{ print $$3; }' $(CURRENT_GPU)`
ifneq (x$(BUILD_ALL_SM),x)
GET_NVOPTIONS=$(GET_NVOPTIONS_ALLS)
else
GET_NVOPTIONS=$(GET_NVOPTIONS_BASE)
endif
GET_ASOPTIONS=`awk '{ sm=$$3/10; print "--gpu-name=sm_"sm; }' $(CURRENT_GPU)`


$(ASPEN_OBJS): %.cu_o: %.cu $(CURRENT_GPU)
	@$(RM) $(LIB_ASPEN)
	$(NVCC) $(NVCOPTION_BASE) $(NVCOPTION_AT) $(GET_NVOPTIONS_BASE) $(INCLUDEPATH) --ptx    $<
	$(NVCC) $(NVCOPTION_BASE) $(NVCOPTION_AT) $(GET_NVOPTIONS) $(INCLUDEPATH) -c -o $@ $<


$(LIB_ASPEN): $(ASPEN_OBJS) $(CXXOBJS)
	$(AR) cr libaspen.a $(ASPEN_OBJS) $(CXXOBJS)
	$(RANLIB) libaspen.a 
	$(CC) $(FPIC) -shared -o libaspen.so $(ASPEN_OBJS) $(CXXOBJS) $(LDFLAG) -Wl,--version-script,export.map
	if [ ! -e $(ASPENLIBDIR) ]; then \
		mkdir $(ASPENLIBDIR); \
	fi
	$(INSTALL) $(LIB_ASPEN) $(ASPENLIBDIR)


clean:
	@echo '\rm '$(LIB_ASPEN)' *.cu_* *.o *.ptx *.asm get_dev_info get_mult get_mult32 get_mult48 '$(CURRENT_GPU) get_tuned_gpuid.h st*
	@for f in $(LIB_ASPEN) *.cu_* *.o *.ptx *.asm get_dev_info get_mult get_mult32 get_mult48 $(CURRENT_GPU) get_tuned_gpuid.h st*; do \
		if [ -e $$f ]; then \
		if [ -f $$f ]; then \
			\rm $$f; \
		fi; \
		fi; \
	done



# dependency for all
$(ASPEN_OBJ): \
	../include/aspen.h \
	../include/aspen_devel.h

$(SYMV_OBJS) : %.cu_o : \
	%-X_template.cu \
	../template/hesymv_atomic_template.incl \
	../template/atomic_ticket.h \
	../template/reduce_in_block.h

$(addsuffix _upper.cu_o,$(SYMV_NAME)) : %_upper.cu_o : \
	../tuning/%-upper-auto.h \
	../tuning/%-upper-auto2.h \
	../tuning/param-%u.h

$(addsuffix _lower.cu_o,$(SYMV_NAME)) : %_lower.cu_o : \
	../tuning/%-lower-auto.h \
	../tuning/%-lower-auto2.h \
	../tuning/param-%l.h

$(addsuffix _upper_small.cu_o,$(SYMV_NAME)) : %_upper_small.cu_o : \
	../template/trmv_tn_upper_template.incl \
	../template/trmv_tn_lower_template.incl \

indent:
	@echo 'Source reformatting for :: '
	@for f in *.c *.cpp *.cu; do \
		echo -n $$f; \
		emacs --script ../etc/indent.el $$f; \
		if [ -e $$f~ ]; then \
		if [ -f $$f~ ]; then \
			\rm $$f~; \
		fi; \
		fi; \
	done

