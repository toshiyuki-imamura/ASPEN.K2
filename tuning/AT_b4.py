#! /usr/bin/env python

import sys
import os
import subprocess
import re
import datetime
from pathlib import Path
import shutil


os.environ['LD_LIBRARY_PATH'] = '../../lib:'+str(LD_LIBRARY_PATH.val)
args = sys.argv
argc = len( args )
IN  = '{}.{}'.format(sys.argv[1],sys.argv[2])
OUT = '{}.{}'.format(sys.argv[1],sys.argv[3])
TOP = str(sys.argv[4])


def Make( ) :

    NULL = subprocess.DEVNULL

    os.chdir('../../src')
    Path('zhemv_upper.cu_o').unlink()
    Path('zhemv_upper.cu_lo').unlink()
    run_command( [ 'make' ], stdout=NULL )
    os.chdir('../bench')
    Path('test-d.o').unlink()
    Path('test2-d.o').unlink()
    run_command( [ 'make', '-j' ], stdout=NULL )
    os.chdir('../tuning/zhemvu-current')


def Main () :
    global PYTHON
    global IN
    global TOP

    run_command( [ PYTHON, '../anal_symv.py', IN, '4', TOP ], stdout='anal_symv-result' )
    run_command( [ 'cat', '-n', TOP ] )
    run_command( [ PYTHON, '../code_gen.py', TOP, 'u', 'zhemv-upper-auto', '0' ] )
    outfile='zhemv-upper-auto.h'
    shutil.copy( outfile, '../'+outfile )


def DO_PYTHON ( mat_matfile ) :
    global ID
    global OUT
    global PYTHON

    IN_pattern=[]
    with open( 'IN-exe-c', mode = 'r' ) as file :
        line = file.readline()
        lineno = 0
        while line :
            S = line.split()
            if S[0] >= 0 :
                lineno = lineno+1
                if lineno > 2 : 
                    IN_pattern[] = S[0]
            line = file.readline()
    IN_pattern = sorted(IN_pattern, key=lambda x: x[0])

    DATA_pattern=[]
    with open( OUT, mode = 'r' ) as file :
        line = file.readline()
        flag = 0
        lineno = 0
        while line :
            if 'BLK' in line :
                line = re.sub( '.*% BLK', '% BLK', line )
                line = re.sub( '=', ' ', line )
                S = line.split()
                flag = 1 if int(S[3]) == ID else 0
            elif 'N=' in line and flag > 0 :
                if flag == 1 :
                    flag = flag + 1 
                else :
                    S = line.split()
                    DATA_pattern[lineno] = '{} {}\n'.format(S[1],S[4])
                    lineno = lineno + 1
            line = file.readline()
    DATA_pattern = sorted(DATA_pattern, key=lambda x: x[0])

    logfile='log-RANK{}'.format(ID)
    with open( logfile, mode = 'w' ) as outfile :
        for i in range(len(DATA_pattern)) :
            logfile.write( '{}\n'.format(DATA_pattern[i]) )


    matfile="cc{}.py".format(ID)
    cat_string_to_file(matfile,
'''import numpy as np
from scipy.sparse import lil_matrix, csr_matrix
from scipy.sparse.linalg import spsolve as linsolve
S=np.array([ 0,
'''
    with open( matfile. mode = 'a' ) as outfile :
        outfile.write('y=np.array([ 0,')
        for i in range(len(IN_pattern)) :
            outfile.write('{},\n')
        outfile.write(']\n')

        for i in range(len(DATA_pattern)) :
            S = DATA_pattern[i],split()
            logfile.write( '{}\n'.format(S[1]))

    append_string_to_file(matfile,
'''
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
''' )


    run_command( [ PYTHON, matfile ], stdout=mat_matfile )

Main()

auto2file ='zhemv-upper-auto2.h'
Path(auto2file).unlink()
cat_string_to_file(auto2file,
'''#if defined(PRESERVE_DROP)
#undef  PRESERVE_DROP
#endif
#define PRESERVE_DROP   1

''')
for i in range(20+1) :
  append_string_to_file(auto2file, '#define\tKERNEL_{}\t1'.format(i))

shutil.copy(auto2file,'../'+auto2file)

Make()


ID_max = 6
if "x"+str(ASPEN_TUNING_LEVEL.val) == "xROUGH" :
    ID_max = 3
if "x"+str(ASPEN_TUNING_LEVEL.val) == "xFULL" :
    ID_max = 10

ID_list=range(ID_max+1)


script = 'BEGIN{i=0}{if($1>1)N[i++]=$1}END{NN=i;for(k=0;k<NN;k++){i=int(rand()*NN);j=int(rand()*NN); t=N[i];N[i]=N[j];N[j]=t;} print 1; print 0; for(i=0;i<NN;i++)print N[i]; print -1}'
run_command( [ 'awk', script, 'IN-exe-c' ], stdout='IN-exe-C' ) 


Path(OUT).unlink()
Path(OUT).touch()

script='BEGIN{ X=0; }{ if (NR=={id} && $1~/[0-9]/) { X=$1; exit; } }END{ gsub(/[0-9]*::/,"",X); print X; }'.format(id=ID)
line = run_command_async( [ 'awk', script, TOP ] ).readline()
buf = byte2string( line )
POINT = int( buf )


for ID in ID_list :
    if ID == 0 or POINT > 10000 :
        run_command_async( ['tee', '-a', OUT],
            run_command_async( [ 'timeout', '-s', 'KILL', '3600', '../../bench/test2-zhemv-u', 'IN-exe-C', str(ID) ] ) )
    else:
        run_command( [ 'awk', 'BEGIN{ print "%BLK specified={id}"; }{ if(i==0){i=1;next;} N=$1; if(N>0)print "N= "N" 100 [s] 0 GFLOPS 0 0"; }'.format(id=ID), 'IN-exe-C' ], stdout=OUT )


for ID in ID_list :
    mat_matfile='mat_mat.{}'.format(ID)
    Path(mat_matfile).touch()
    Path(mat_matfile).unlink()

    print('Fitting the Kernel.{}'.format(ID))
    DO_PYTHON( mat_matfile )

    matfile='mat.{}'.format(ID)
    run_command( [ 'awk', '/[0-9]/ { gsub(/[(),]/,""); printf("%6d %f\n", $1, $2);}', mat_matfile], stdout=matfile )

