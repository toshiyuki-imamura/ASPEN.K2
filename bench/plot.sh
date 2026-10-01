#/bin/sh

for Dev in \
	GB200 GH200_480GB A100_SXM_80GB A100_SXM4_40GB V100_PCIE_32GB TITAN_V P100_SXM2_16GB 5080 4080 3090 2080 1080 750 A5000 A6000
do
for SYMV in \
	DSYMVU DSYMVL SSYMVU SSYMVL ZHEMVU ZHEMVL CHEMVU CHEMVL 
do

	OUTPUT=plot-data-"$Dev"-"$SYMV"

	FILES=`find . -name "log-*$SYMV*$Dev*" -print | head -1` 

	if [ x$FILES != x ]; then

	echo $OUTPUT

	if [ -e AVE ]; then
		\rm AVE
	fi

	for F in \
		log-*$SYMV*$Dev* 
	do
		cat $F | \
		tail -50 | \
		head -10 | \
		awk 'BEGIN{ s=0; c=0; }{ s+=(1*$5); c++; }END{ if(c==0)c=1; print s/c; }' >> AVE
	done
	AVE=`awk 'BEGIN{ s=0; }{ if(s<$1)s=$1; }END{ print s;}' AVE`
	\rm AVE

	ls log-*$SYMV*$Dev* | \
	awk '\
		BEGIN{ \
			D="'$Dev'"; \
			K="'$SYMV'"; \
			if ( D == "580"   ) DEV="GeForce GTX580"; \
			if ( D == "750"   ) DEV="GeForce GTX750Ti"; \
			if ( D == "980"   ) DEV="GeForce GTX980"; \
			if ( D == "1080"  ) DEV="GeForce GTX1080"; \
			if ( D == "TITAN" ) DEV="GeForce TitanBlack"; \
			if ( D == "2080"  ) DEV="GeForce RTX2080Ti"; \
			if ( D == "3090"  ) DEV="GeForce RTX3090"; \
			if ( D == "4080"  ) DEV="GeForce RTX4080"; \
			if ( D == "5080"  ) DEV="GeForce RTX5080"; \
			if ( D == "K20c"  ) DEV="Tesla K20c"; \
			if ( D == "K20Xm" ) DEV="Tesla K20Xm"; \
			if ( D == "P100_SXM2_16GB" ) DEV="Tesla P100 16GB"; \
			if ( D == "TITAN_V" ) DEV="TITAN-V"; \
			if ( D == "V100_PCIE_32GB" ) DEV="Tesla V100 32GB"; \
			if ( D == "A100_SXM4_40GB" ) DEV="A100 40GB"; \
			if ( D == "A100_SXM4_80GB" ) DEV="A100 80GB"; \
			if ( D == "A5000"  ) DEV="RTX A5000"; \
			if ( D == "A6000"  ) DEV="RTX A6000"; \
			if ( D == "GH200_480GB"  ) DEV="GH200 1GPU"; \
			if ( D == "GB200"  ) DEV="GB200 1GPU"; \
			printf( "#"K ); \
			printf( "#"D ); \
			printf( "#"DEV ); \
			printf( "set key bottom\n" ); \
			printf( "set grid\n" ); \
			printf( "set pointsize 0.3\n" ); \
			printf( "set yrange [0:]\n" ); \
			printf( "set title \""K" on a <"DEV">\"\n" ); \
			printf( "set xlabel \"[dimension]\"\n" ); \
			printf( "set ylabel \"[GFLOPS]\"\n" ); \
			PLOT = "plot "; \
			c=" "; \
		} \
		{ \
			PLOT = PLOT c " \"" $1 "\" u 2:($5<2*'$AVE'?$5:-1000) t \"" $1 "\" "; \
			c=","; \
		} \
		END{ \
			printf( "set term post eps color\n" ); \
			printf( "set output \"'$OUTPUT'.eps\"\n" ); \
			print PLOT; \
			printf( "clear\n" ); \
			printf( "set term png\n" ); \
			printf( "set output \"'$OUTPUT'.png\"\n" ); \
			print PLOT; \
			printf( "clear\n" ); \
			printf( "exit\n" ); \
		} \
	' > "$SYMV"-"$Dev".plot
	gnuplot  "$SYMV"-"$Dev".plot >& /dev/null

	fi

done
done


