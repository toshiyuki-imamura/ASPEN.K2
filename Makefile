SHELL=/bin/bash

# CHECK whether significant commads available
# 

# check nvcc
ifeq (x$(wildcard $(CUDA_PATH)/bin/nvcc),x)
    $(error  '[' $(CUDA_PATH)/bin/nvcc ']' is not found)
endif

PYTHON    = python
ifneq (x$(shell which $(PYTHON) |& grep which),x)
    PYTHON   = python3
endif
ifneq (x$(shell which $(PYTHON) |& grep which),x)
    PYTHON   = python2
endif
ifneq (x$(shell which $(PYTHON) |& grep which),x)
    $(error  python command '[' $(PYTHON) ']' is not found)
endif

OCTAVE    = octave
# check octave
#ifneq (x$(shell which $(OCTAVE) | grep not),x)
#    $(error  octave command is not found)
#endif

GNUPLOT   = gnuplot
# check gnuplot
#ifneq (x$(shell which $(GNUPLOT) | grep not),x)
#    $(error  gnuplot command is not found)
#endif


all:: .headers
lib:
	if [ ! -e lib ]; then \
		mkdir lib; \
	fi
.headers:
	make .half
	cd src; make get_dev_info
	cd tuning; which $(PYTHON); $(PYTHON) ./touch_header.py
	make lib
	cd src; make -j4; touch ../lib/libaspen.a
	touch .headers

all:: lib/libaspen.a
lib/libaspen.a: tuned
	cd src; make

benchmark: lib/libaspen.a
	cd bench; make

TYPES1        = w d s h i128 i64 i32 i16
TYPES2        = u z c k
SYMV_KERNEL   = symv
HEMV_KERNEL   = hemv
SYMV_OPTIONS  = _u _l
HEMV_OPTIONS  = _u _l
SYMV_KERNELS  = $(foreach f,$(SYMV_OPTIONS),$(addsuffix $f,$(SYMV_KERNEL)))
HEMV_KERNELS  = $(foreach f,$(HEMV_OPTIONS),$(addsuffix $f,$(HEMV_KERNEL)))
ASPEN_KERNELS = $(ASPEN_KERNELS1) $(ASPEN_KERNELS2)
ASPEN_KERNELS1 = $(SYMV_KERNELS)
ASPEN_KERNELS2 = $(HEMV_KERNELS)


tuned-new::
	make -j1 \
		$(addprefix tuned-new-,$(ASPEN_KERNELS1)) \
		$(addprefix tuned-new-,$(ASPEN_KERNELS2))
tuned::
	make -j1 \
		$(addprefix tuned-,$(ASPEN_KERNELS1)) \
		$(addprefix tuned-,$(ASPEN_KERNELS2))


#tuned-xxx:
#	make tuned-dxxx tuned-sxxx
$(addprefix tuned-,$(ASPEN_KERNELS1)):
	make -j1 $(foreach f,$(TYPES1),$(subst tuned-,tuned-$f,$@))
#	make tuned-zxxx tuned-cxxx
$(addprefix tuned-,$(ASPEN_KERNELS2)):
	make -j1 $(foreach f,$(TYPES2),$(subst tuned-,tuned-$f,$@))
#tuned-symv:
$(addprefix tuned-,$(SYMV_KERNEL)):
	make -j1 $(addprefix tuned-,$(SYMV_KERNELS))
#tuned-hemv:
$(addprefix tuned-,$(HEMV_KERNEL)):
	make -j1 $(addprefix tuned-,$(HEMV_KERNELS))
#tuned-[ds]symv:
$(addsuffix $(SYMV_KERNEL),$(addprefix tuned-,$(TYPES1))):
	make -j1 $(addprefix $@,$(SYMV_OPTIONS))
#tuned-[zc]hemv:
$(addsuffix $(HEMV_KERNEL),$(addprefix tuned-,$(TYPES2))):
	make -j1 $(addprefix $@,$(HEMV_OPTIONS))

#tuned-new-xxx:
#	make tuned-new-dxxx tuned-new-sxxx
$(addprefix tuned-new-,$(ASPEN_KERNELS1)):
	make -j1 $(foreach f,$(TYPES1),$(subst tuned-new-,tuned-new-$f,$@))
#	make tuned-new-zxxx tuned-new-cxxx
$(addprefix tuned-new-,$(ASPEN_KERNELS2)):
	make -j1 $(foreach f,$(TYPES2),$(subst tuned-new-,tuned-new-$f,$@))
#tuned-new-symv:
$(addsuffix $(SYMV_KERNEL),tuned-new-):
	make -j1 $(addprefix tuned-new-,$(SYMV_KERNELS))
#tuned-new-hemv:
$(addsuffix $(HEMV_KERNEL),tuned-new-):
	make -j1 $(addprefix tuned-new-,$(HEMV_KERNELS))
#tuned-new-[ds]symv:
$(addsuffix $(SYMV_KERNEL),$(addprefix tuned-new-,$(TYPES1))):
	make -j1 $(addprefix $@,$(SYMV_OPTIONS))
#tuned-new-[zc]hemv:
$(addsuffix $(HEMV_KERNEL),$(addprefix tuned-new-,$(TYPES2))):
	make -j1 $(addprefix $@,$(HEMV_OPTIONS))

#tuned-[ds]xxx:
#	touch tuning/.done-[ds]xxx
#	cd src; make [ds]xxx
$(foreach f,$(TYPES1),$(addprefix tuned-$f,$(ASPEN_KERNELS1))):
	@touch tuning/.done-$(subst tuned-,,$@)
	make .half
	cd src; make -j1 get_dev_info
	cd src; make -j4 $(subst tuned-,,$@)
#tuned-[zc]xxx:
#	touch tuning/.done-[zc]xxx
#	cd src; make [zc]xxx
$(foreach f,$(TYPES2),$(addprefix tuned-$f,$(ASPEN_KERNELS2))):
	@touch tuning/.done-$(subst tuned-,,$@)
	make .half
	cd src; make -j1 get_dev_info
	cd src; make -j4 $(subst tuned-,,$@)

#tuned-new-[ds]xxx:
#	@-\rm tuning/.done-[ds]xxx
#	make tuning/.done-[ds]xxx
#	touch tuning/.done-[ds]xxx
$(foreach f,$(TYPES1),$(addprefix tuned-new-$f,$(ASPEN_KERNELS1))):
	@-\rm tuning/.done-$(subst tuned-new-,,$@)
	make -j1 tuning/.done-$(subst tuned-new-,,$@)
	@touch tuning/.done-$(subst tuned-new-,,$@)
#tuned-new-[zc]xxx:
#	@-\rm tuning/.done-[zc]xxx
#	make tuning/.done-[zc]xxx
#	touch tuning/.done-[zc]xxx
$(foreach f,$(TYPES2),$(addprefix tuned-new-$f,$(ASPEN_KERNELS2))):
	@-\rm tuning/.done-$(subst tuned-new-,,$@)
	make -j1 tuning/.done-$(subst tuned-new-,,$@)
	@touch tuning/.done-$(subst tuned-new-,,$@)


#tuning/.done-[ds]xxx:
#	cd tuning; /bin/sh ./[ds]xxx.sh
$(foreach f,$(TYPES1),$(addprefix tuning/.done-$f,$(ASPEN_KERNELS1))):
	cd tuning; \
	export PYTHON=$(PYTHON); \
	$(PYTHON) AT.py $(subst tuning/.done-,,$@)
#tuning/.done-[zc]xxx:
#	cd tuning; /bin/sh ./[zc]xxx.sh
$(foreach f,$(TYPES2),$(addprefix tuning/.done-$f,$(ASPEN_KERNELS2))):
	cd tuning; \
	export PYTHON=$(PYTHON); \
	$(PYTHON) AT.py $(subst tuning/.done-,,$@)


ALL_ASPEN_TARGETS = \
	$(foreach f,$(TYPES1),\
		$(addprefix tuned-$f,$(ASPEN_KERNELS1))       \
		$(addprefix tuned-new-$f,$(ASPEN_KERNELS1))   \
		$(addprefix tuning/.done-$f,$(ASPEN_KERNELS1))) \
	$(foreach f,$(TYPES2),\
		$(addprefix tuned-$f,$(ASPEN_KERNELS2))       \
		$(addprefix tuned-new-$f,$(ASPEN_KERNELS2))   \
		$(addprefix tuning/.done-$f,$(ASPEN_KERNELS2)))
$(ALL_ASPEN_TARGETS): .headers


clobber:
	-cd tuning; \rm \
		$(subst _,,\
		$(foreach f,$(TYPES1),\
			$(foreach g,$(SYMV_KERNELS),\
				$f$g-current)) \
		$(foreach f,$(TYPES2),\
			$(foreach g,$(HEMV_KERNELS),\
				$f$g-current)))
	-cd tuning; \rm -rf logs log-* data
	-cd tuning; \rm -rf \
		$(subst =,_,$(subst _,,\
		$(foreach f,$(TYPES1),\
			$(foreach g,$(SYMV_KERNELS),\
				$f$g=reguse-orig))\
		$(foreach f,$(TYPES2),\
			$(foreach g,$(HEMV_KERNELS),\
				$f$g=reguse-orig))))
	-cd tuning; \rm -rf wsymvl_reguse-orig uhemvl_reguse-orig
	-cd tuning; \rm .done-*
	-make cleanclean
cleanclean:
	-cd tuning; \rm *.h *.c *.o a.out
	-cd tuning; \rm skip_list CURRENT_GPU CX CY OO ttt IN-* *-log *_reguse
	-cd tuning; \rm DEV_INFO
	-if [ -e half ]; then \
		cd half; \rm -rf ./* .done-half; \
	fi
	-if [ -e half ]; then \
		\rm -rf half; \
	fi
	-rm .half
	-rm .headers
	-make clean
	-rm log-*
clean:
	echo $(MAKEFLAGS)
	-cd src; make clean
	-cd bench; make clean
	-rm lib/libaspen.a lib/libaspen.so
release:
	make clobber
	make indent
indent:
	@cd src; make indent
	@cd include; make indent
	@cd template; make indent
	@cd bench; make indent


CUDA_SAMPLES=/opt/cuda-samples/Common
ifneq (x$(wildcard $(CUDA_PATH)/samples/common/inc),x)
CUDA_SAMPLES=$(CUDA_PATH)/samples/common/inc
endif
ifneq (x$(wildcard $(CUDA_PATH)/cuda-samples/Common),x)
CUDA_SAMPLES=$(CUDA_PATH)/cuda-samples/Common
endif
ifneq (x$(wildcard $(CUDA_PATH)/samples/cuda-samples/Common),x)
CUDA_SAMPLES=$(CUDA_PATH)/samples/cuda-samples/Common
endif

half:
	if [ ! -e half ]; then \
		mkdir half; \
	fi
half/.done-half: half
	cd half; \
	wget https://sourceforge.net/projects/half/files/half/2.2.1/half-2.2.1.zip; \
	unzip -o -x half-2.2.1.zip; \
	patch -p0 < ../etc/patch-complex-2.2.1; \
	touch .done-half
.half: half/.done-half
	touch .half



# check ASPEN_GPU_ID
ifeq (x$(ASPEN_GPU_ID),x)
    $(warning  Please set the device ID $$ASPEN_GPU_ID if you want to tune up)
    $(warning  other than GPU_ID 0, anyway, continue as $$ASPEN_GPU_ID=0.)
endif

# check CUDA_PATH
ifeq (x$(CUDA_PATH),x)
    $(error  Please set $$CUDA_PATH.x)
endif
ifeq (x$(wildcard $(CUDA_PATH)),x)
    $(error  Not available directory $$CUDA_PATH=$(CUDA_PATH))
endif

# check cblas.h
#ifeq (x$(wildcard /usr/include/cblas.h),x)
#    $(error  CBLAS is not found)
#endif

# check MKL
#ifeq (x$(wildcard $(MKLROOT)),x)
#    $(error  MKL is not found)
#endif

