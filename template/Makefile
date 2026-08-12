indent:
	@echo 'Source reformatting for :: '
	@for f in *.h *.incl; do \
	if [ ! -L $$f ]; then \
		echo -n $$f; \
		emacs --script ../etc/indent.el $$f; \
		if [ -e $$f~ ]; then \
		if [ -f $$f~ ]; then \
			\rm $$f~; \
		fi; \
		fi; \
	fi; \
	done
