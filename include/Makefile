indent:
	@echo 'Source reformatting for :: '
	@for f in *.h; do \
		echo -n $$f; \
		emacs --script ../etc/indent.el $$f; \
		if [ -e $$f~ ]; then \
		if [ -f $$f~ ]; then \
			\rm $$f~; \
		fi; \
		fi; \
	done
