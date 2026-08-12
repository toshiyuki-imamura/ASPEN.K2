#!/bin/bash

export LD_LIBRARY_PATH=../../lib:$LD_LIBRARY_PATH

IN=$1.$2
OUT=$1.$3
TOP=$4

Make ()
{
	cd ../../src
	\rm i16symv_upper.cu_o i16symv_upper.cu_lo
	make
	cd ../bench
	\rm test-i16.o test2-i16.o
	make -j
	cd ../tuning/i16symvu-current
}

Main ()
{
	$PYTHON ../anal_symv.py $IN 3 $TOP > anal_symv-result 
	cat -n $TOP
	$PYTHON ../code_gen.py $TOP u i16symv-upper-auto 10
	cp i16symv-upper-auto.h ../
}

Main

touch $OUT
\rm $OUT

	ID_max=10
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

\rm i16symv-upper-auto2.h
touch i16symv-upper-auto2.h
awk ' \
	BEGIN{ \
		for(i=0;i<100;i++) print "#define\tKERNEL_"'$ID'*100+i"\t1"; \
		exit; \
	} \
	' > i16symv-upper-auto2.h
cp i16symv-upper-auto2.h ../

Make >& /dev/null

for M in \
	0 10 20 30 40 50 60 70 80 90
do
	BLOCK_SIZE=`awk '{ i++; if (i=='$ID') { print $2; } }' $TOP`
	VX=`awk '{ i++; if (i=='$ID') { print $3; } }' $TOP`
	UX=`awk '{ i++; if (i=='$ID') { print $4; } }' $TOP`
	MULTIPLICITY=`awk '{ i++; if (i=='$ID') { print $5; } }' $TOP`

	if [ x$VX != x ]; then
		MM='OK'
        else
		MM=''
	fi

	if [ x$MM != x ]; then

	WW=`cat log-regs-$BLOCK_SIZE-$VX | \
                awk '/^[0-9]/{ if ( $3=='$UX' && $4=='$M' ) { if ( $NF >= '$MULTIPLICITY' && $8 > 0 ) print "OK"; exit; } }'`

        if [ x$WW != x ]; then

	KERNEL=`expr $ID "*" 100`
	KERNEL=`expr $KERNEL "+" $M`
	timeout -s KILL 600 ../../bench/test2-i16symv-u IN-exe-a $KERNEL | tee -a $OUT
	echo $BLOCK_SIZE" "$VX" "$UX" "$MULTIPLICITY" "$M >> done_pattern
	DONE_KERNEL=`expr $DONE_KERNEL "+" 1`

	fi

	fi
done
  fi

  fi
done

