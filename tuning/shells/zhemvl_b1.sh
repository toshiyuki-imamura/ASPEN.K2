#!/bin/bash

export LD_LIBRARY_PATH=../../lib:$LD_LIBRARY_PATH

IN=$1.$2
OUT=$1.$3
TOP=$4

Make ()
{
	cd ../../src
	\rm zhemv_lower.cu_o zhemv_lower.cu_lo
	make
	cd ../bench
	\rm test-z.o test2-z.o
	make -j
	cd ../tuning/zhemvl-current
}

Main ()
{
	$PYTHON ../anal_symv.py $IN 3 $TOP > anal_symv-result
	cat -n $TOP
	$PYTHON ../code_gen.py $TOP l zhemv-lower-auto 10
	cp zhemv-lower-auto.h ../
}

Main

touch $OUT
\rm $OUT

	ID_max=20
if [ x$ASPEN_TUNING_LEVEL = xROUGH ]; then
	ID_max=10
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

	M00=`awk '{ i++; if (i=='$ID') { print $6; } }' $TOP`
	M00=`expr $M00 "/" 10`
	M00=`expr $M00 "*" 10`

\rm zhemv-lower-auto2.h
touch zhemv-lower-auto2.h
awk ' \
	BEGIN{ \
		for(i=0;i<100;i++) print "#define\tKERNEL_"'$ID'*100+i"\t" \
			((i-(i%10)) == '$M00'); \
		exit; \
	} \
	' > zhemv-lower-auto2.h
cp zhemv-lower-auto2.h ../

Make >& /dev/null

#for M0 in \
#	0 1 2 3 4 5 6 7 8 9
for M0 in \
	0
do
	BLOCK_SIZE=`awk '{ i++; if (i=='$ID') { print $2; } }' $TOP`
	VX=`awk '{ i++; if (i=='$ID') { print $3; } }' $TOP`
	UX=`awk '{ i++; if (i=='$ID') { print $4; } }' $TOP`
	MULTIPLICITY=`awk '{ i++; if (i=='$ID') { print $5; } }' $TOP`
	M00=`awk '{ i++; if (i=='$ID') { print $6; } }' $TOP`
	M00=`expr $M00 "/" 10`
	M00=`expr $M00 "*" 10`
	M11=`expr $M11 "+" 1`
	M=`expr $M0 "+" $M00`

	if [ x$VX != x ]; then
		#MM=`awk '{ if ( $1=='$UX'/'$VX' && $2==('$M'%10) ) { print "OK"; } }' OK-pat-symv`
		MM='OK'
        else
		MM=''
	fi

	if [ x$MM != x ]; then

	WW=`cat log-regs-$BLOCK_SIZE-$VX | \
                awk '/^[0-9]/{ if ( $3=='$UX' && ($4=='$M00' || $4=='$M11') ) { if ( $NF >= '$MULTIPLICITY' && $8 > 0 ) print "OK"; exit; } }'`

        if [ x$WW != x ]; then

	KERNEL=`expr $ID "*" 100`
	KERNEL=`expr $KERNEL "+" $M`
	timeout -s KILL 600 ../../bench/test2-zhemv-l IN-exe-a $KERNEL | tee -a $OUT
	echo $BLOCK_SIZE" "$VX" "$UX" "$MULTIPLICITY" "$M >> done_pattern1
	DONE_KERNEL=`expr $DONE_KERNEL "+" 1`

	fi

	fi
done
  fi

  fi
done

