#!/bin/bash

make keepP2

if [ ! -f ./keepP2 ]; then
	exit
fi

NGPUS=`nvidia-smi -q | awk '/Attached/{print $4;exit}'`

killall -9 keepP2

for i in $(seq 1 $NGPUS); do
	j=`expr $i "-" 1`
	./keepP2 device=$j >& /dev/null &
done

sleep 10

