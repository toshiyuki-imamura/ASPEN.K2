PYTHON = python
ifneq (x$(shell which $(PYTHON) |& grep which),x)
	PYTHON   = python3
endif
ifneq (x$(shell which $(PYTHON) |& grep which),x)
	PYTHON   = python2
endif
ifneq (x$(shell which $(PYTHON) |& grep which),x)
	$(error  python command '[' $(PYTHON) ']' is not found)
endif

all:
	/bin/sh ./Make_shells-sh
	\mv *.cu ../
	@$(PYTHON) make_fort_cpp.py | \
	cpp -P -traditional-cpp | \
	sed -e s/@@//g | \
	cat -s | sed '1{/^$$/d}' | sed -e 's/\/\/@//' > aspen_fortran.cpp
	\mv aspen_fortran.cpp ..
clean:
	\rm *.cu

