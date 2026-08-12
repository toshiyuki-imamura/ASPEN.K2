#!/bin/bash

export LD_LIBRARY_PATH=../../lib:$LD_LIBRARY_PATH

IN=$1.$2
OUT=$1.$3
TOP=$4

Make ()
{
	cd ../../src
	\rm uhemv_upper.cu_o uhemv_upper.cu_lo
	make
	cd ../bench
	\rm test-d.o test2-d.o
	make -j
	cd ../tuning/uhemvu-current
}

Main ()
{
	$PYTHON ../anal_symv.py $IN 4 $TOP > anal_symv-result
	cat -n $TOP
	$PYTHON ../code_gen.py $TOP u uhemv-upper-auto 0
	cp uhemv-upper-auto.h ../
}

Main

\rm uhemv-upper-auto2.h
touch uhemv-upper-auto2.h
awk ' \
	BEGIN{ \
		print "#if defined(PRESERVE_DROP)"; \
		print "#undef  PRESERVE_DROP"; \
		print "#endif"; \
		print "#define PRESERVE_DROP   1"; \
		print ""; \
		for(i=0;i<=20;i++) print "#define\tKERNEL_"i"\t1"; \
		exit; \
	} \
	' > uhemv-upper-auto2.h
cp uhemv-upper-auto2.h ../

Make >& /dev/null

	ID_max=8
if [ x$ASPEN_TUNING_LEVEL = xROUGH ]; then
	ID_max=3
fi
if [ x$ASPEN_TUNING_LEVEL = xFULL ]; then
	ID_max=10
fi
	ID_list=" 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 "

#awk 'BEGIN{i=0}{if($1>1)N[i++]=$1}END{NN=i;for(k=0;k<NN;k++){i=int(rand()*NN);j=int(rand()*NN); t=N[i];N[i]=N[j];N[j]=t;} print 1; print 0; for(i=0;i<NN;i++)print N[i]; print -1}' IN-exe-b > IN-exe-B
awk 'BEGIN{i=0}{if($1>1)N[i++]=$1}END{NN=i;print 1; print 0; for(i=0;i<NN;i++)print N[i]; print -1}' IN-exe-b > IN-exe-B

\rm $OUT
touch $OUT
for ID in \
	$ID_list
do
  if [ $ID -le $ID_max ]; then

  POINT=`awk 'BEGIN{ X=0; }{ if (NR=='$ID' && $1~/[0-9]/) { X=$1; exit; } }END{ gsub(/[0-9]*::/,"",X); print X; }' $TOP`
  if [ $ID -eq 0 -o $POINT -gt 10000 ]; then

	timeout -s KILL 2400 ../../bench/test2-uhemv-u IN-exe-B $ID | tee -a $OUT

  else

	echo '% BLK specified='$ID >> $OUT
	awk '{ if(i==0){i=1;next;} N=$1; if(N>0)print "N= "N" 100 [s] 0 GFLOPS 0 0"; }' IN-exe-B >> $OUT

  fi

  fi
done

