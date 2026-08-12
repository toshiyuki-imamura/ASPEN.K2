#!/bin/bash

export LD_LIBRARY_PATH=../../lib:$LD_LIBRARY_PATH

IN=$1.$2
OUT=$1.$3
TOP=$4

Make ()
{
	cd ../../src
	\rm chemv_upper.cu_o chemv_upper.cu_lo
	make
	cd ../bench
	\rm test-d.o test2-d.o
	make -j
	cd ../tuning/chemvu-current
}

Main ()
{
	$PYTHON ../anal_symv.py $IN 4 $TOP > anal_symv-result
	cat -n $TOP
	$PYTHON ../code_gen.py $TOP u chemv-upper-auto 0
	cp chemv-upper-auto.h ../
}

DO_PYTHON ()
{
	echo "import numpy as np" > cc$ID.py
	echo "from scipy.sparse import lil_matrix, csr_matrix" >> cc$ID.py
	echo "from scipy.sparse.linalg import spsolve as linsolve" >> cc$ID.py

	echo "S=np.array([ 0," >> cc$ID.py
	sort -gk 1 IN-exe-c | awk '{if($1>=0)print}END{print -1}' |
	awk ' \
		BEGIN { \
			line = 0; \
		} \
		{ \
			line++; \
			if ( line <= 2 )next; \
			if ( $1 > 0 ) print $0","; \
		} \
	' >> cc$ID.py
	echo "])" >> cc$ID.py

	echo "y=np.array([ 0," >> cc$ID.py
	awk ' \
		/BLK/{ \
			gsub(/.*% BLK/,"% BLK"); \
			gsub(/=/," "); \
			flag = ($4=='$ID')?1:0; next; \
		} \
		/N=/{ \
			if(flag>0){ \
				if(flag==1) { \
					flag++; next; \
				} \
				print $2" "$5; flag++; \
			} \
		} \
		' $OUT | sort -gk 1 > log-RANK$ID

	awk ' \
		{
			print $2",";
		} \
		' log-RANK$ID >> cc$ID.py
	echo "])" >> cc$ID.py

	cat << EOS_P >> cc$ID.py

M = min(S.shape[0],y.shape[0])
N = S[M-1]-S[0]+1

z  = [0]*N
ii = list(range(0,N))+[S[0]]*N

norm = np.linalg.norm(y)
if norm > 0:

	EtE = lil_matrix( (N,N) )
	for j in range(0,M):
		k = S[j]-S[0]
		EtE[k,k] = +1.
	EtE = EtE.tocsr()

	D = lil_matrix( (N,N) )
	for j in range(1,N-1):
		D[j,j-1] = +1.
		D[j,j  ] = -2.
		D[j,j+1] = +1.
	D = D.tocsr()
	DtD = (D.transpose()).dot(D)
	del D
	DtD = DtD.tocsr()

	alpha = 1./N
	AA = EtE + alpha * DtD
	del EtE, DtD
	AA = AA.tocsr()
	
	yy = [0]*N
	for j in range(0,M):
		s = S[j]-S[0]
		yy[s] = y[j]
	del y, S

	yyN = yy[N-1]
	z = linsolve(AA, yy / yyN) * yyN
	z[0] = 0

for j in range(0,N):
	print(ii[j],z[j] if z[j] > 0 else 0)

EOS_P

	$PYTHON cc$ID.py
}

DO_MATLAB ()
{

echo "S=[ 0" > cc$ID.m

	awk ' \
		BEGIN { \
			line = 0; \
		} \
		{ \
			line++; \
			if ( line <= 2 )next; \
			if ( $1 > 0 ) print; \
		} \
	' IN-exe-c >> cc$ID.m
	cat << EOS_M >> cc$ID.m
];

y=[ 0
EOS_M

	awk ' \
		/BLK/{ \
			gsub(/=/," "); \
			flag = ($4=='$ID')?1:0; next; \
		} \
		/N=/{ \
			if(flag>0){ \
				if(flag==1) { \
					flag++; next; \
				} \
				print $2" "$5; flag++; \
			} \
		} \
		' $OUT > log-RANK$ID

	awk ' \
		{
			print $2;
		} \
		' log-RANK$ID >> cc$ID.m

	cat << EOS_MM >> cc$ID.m
];

[M,c]=size(S);
[MM,c]=size(y);
if MM<M
	M=MM
end
N=S(M)-S(1)+1;

z=zeros(N,1);
ii=zeros(N,1);
for j=1:N
	ii(j) = j+S(1)-1;
end

norm = y'*y;
if norm > 0

	EtE = sparse(N,N);
	for j=1:M
		k=S(j)-S(1)+1;
		EtE(k,k)=1;
	end

	D = sparse(N,N);
	for j=2:N-1
		D(j,j-1)=1; D(j,j)=-2; D(j,j+1)=1;
	end
	DtD=D'*D/N;

	AA=EtE+DtD;

	yy=zeros(N,1);
	for j=1:M
		s = S(j)-S(1)+1;
		yy(s) = y(j);
	end

	yyN=yy(N);
	yy=yy/yyN;
	z=(AA\yy)*yyN;

end

[ii,z]
EOS_MM

	octave cc$ID.m

}

Main

\rm chemv-upper-auto2.h
touch chemv-upper-auto2.h
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
	' > chemv-upper-auto2.h
cp chemv-upper-auto2.h ../

Make >& /dev/null

	ID_max=5
if [ x$ASPEN_TUNING_LEVEL = xROUGH ]; then
	ID_max=1
fi
if [ x$ASPEN_TUNING_LEVEL = xFULL ]; then
	ID_max=10
fi
	ID_list=" 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 "

#awk 'BEGIN{i=0}{if($1>1)N[i++]=$1}END{NN=i;for(k=0;k<NN;k++){i=int(rand()*NN);j=int(rand()*NN); t=N[i];N[i]=N[j];N[j]=t;} print 1; print 0; for(i=0;i<NN;i++)print N[i]; print -1}' IN-exe-c > IN-exe-C
awk 'BEGIN{i=0}{if($1>1)N[i++]=$1}END{NN=i; print 1; print 0; for(i=0;i<NN;i++)print N[i]; print -1}' IN-exe-c > IN-exe-C

\rm $OUT
touch $OUT
for ID in \
	$ID_list
do
  if [ $ID -le $ID_max ]; then

  POINT=`awk 'BEGIN{ X=0; }{ if (NR=='$ID' && $1~/[0-9]/) { X=$1; exit; } }END{ gsub(/[0-9]*::/,"",X); print X; }' $TOP`
  if [ $ID -eq 0 -o $POINT -gt 10000 ]; then

	timeout -s KILL 3600 ../../bench/test2-chemv-u IN-exe-C $ID | tee -a $OUT

  else

	echo '% BLK specified='$ID >> $OUT
	awk '{ if(i==0){i=1;next;} N=$1; if(N>0)print "N= "N" 100 [s] 0 GFLOPS 0 0"; }' IN-exe-C >> $OUT

  fi

  fi
done

for ID in \
	$ID_list
do

	touch mat_mat.$ID
	\rm mat_mat.$ID
	echo 'Fitting the Kernel.'$ID
if [ 1 -eq 1 ]; then
	DO_PYTHON 1> mat_mat.$ID 2> /dev/null
	awk ' \
		/[0-9]/ { \
			gsub(/[\(\),]/,""); printf("%6d %f\n", $1, $2); \
		} \
	' mat_mat.$ID > mat.$ID
else
	DO_MATLAB 1> mat_mat.$ID 2> /dev/null
        awk ' \
		BEGIN { \
			flga=0; \
		} \
		/ans/ { \
			flag=1; next; \
		} \
		/[0-9]/ { \
			if ( flag ) printf("%6d %f\n", $1, $2); \
		} \
	' mat_mat.$ID > mat.$ID
fi

done

