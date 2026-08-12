all:
	@python3 make_ld_st_h.py | \
	cpp -P -traditional-cpp | \
	sed -e s/@@//g | \
	cat -s | sed '1{/^$$/d}' | sed -e 's/\/\/@//' > aspen_ld_st.h
	@mv aspen_ld_st.h ..
	@python3 make_main_h.py | \
	cpp -P -traditional-cpp | \
	sed -e s/@@//g | \
	cat -s | sed '1{/^$$/d}' | sed -e 's/\/\/@//' > aspen.h
	@mv aspen.h ..
	@python3 make_fort_h.py | \
	cpp -P -traditional-cpp | \
	sed -e s/@@//g | \
	cat -s | sed '1{/^$$/d}' | sed -e 's/\/\/@//' > aspen_fortran.h
	@mv aspen_fortran.h ..

