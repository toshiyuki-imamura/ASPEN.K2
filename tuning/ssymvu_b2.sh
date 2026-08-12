#!/bin/bash

export LD_LIBRARY_PATH=../../lib:$LD_LIBRARY_PATH

IN=$1.$2
OUT=$1.$3
TOP=$4

Make ()
{
	cd ../../src
	\rm ssymv_upper.cu_o ssymv_upper.cu_lo
	make
	cd ../bench
	\rm test-s.o test2-s.o
	make -j
	cd ../tuning/ssymvu-current
}

Main ()
{
	$PYTHON ../anal_symv.py $IN 3 $TOP > anal_symv-result
	cat -n $TOP
	$PYTHON ../code_gen.py $TOP u ssymv-upper-auto 1
	cp ssymv-upper-auto.h ../
}

Main

touch $OUT
\rm $OUT

	ID_max=8
if [ x$ASPEN_TUNING_LEVEL = xROUGH ]; then
	ID_max=6
fi
if [ x$ASPEN_TUNING_LEVEL = xFULL ]; then
	ID_max=20
fi
	ID_list=" 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 "

DONE_KERNEL=0
for ID in \
	$ID_list
do
  if [ $ID -le $ID_max ]; then

  POINT=`awk 'BEGIN{ X=0; }{ if (NR=='$ID' && $1~/[0-9]/) { X=$1;exit; } }END{ print X; }' $TOP`
  if [ $POINT -gt 100 ]; then

\rm ssymv-upper-auto2.h
touch ssymv-upper-auto2.h
awk ' \
	BEGIN{ \
		for(i=1;i<20;i++) print "#define\tKERNEL_"'$ID'*100+i"\t1"; \
		exit; \
	} \
	' > ssymv-upper-auto2.h
cp ssymv-upper-auto2.h ../

Make >& /dev/null

for M0 in \
	1 2 3 4 5 6 7 8 9 10 11 12
do
	BLOCK_SIZE=`awk '{ i++; if (i=='$ID') { print $2; } }' $TOP`
	VX=`awk '{ i++; if (i=='$ID') { print $3; } }' $TOP`
	UX=`awk '{ i++; if (i=='$ID') { print $4; } }' $TOP`
	MULTIPLICITY=`awk '{ i++; if (i=='$ID') { print $5; } }' $TOP`
	MX=`awk '{ i++; if (i=='$ID') { print $6; } }' $TOP`

	KERNEL=`expr $ID "*" 100`
	KERNEL=`expr $KERNEL "+" $M0`
	timeout -s KILL 600 ../../bench/test2-ssymv-u IN-exe-a $KERNEL | tee -a $OUT

done

  fi

  fi
done

