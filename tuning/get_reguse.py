#! /usr/bin/env python

import sys
import os
import subprocess
import re
import cxxfilt


def byte2string( line ) :
    if sys.version_info.major > 2 :
       buf = line.decode()
    else :
       buf = line.rstrip()
    return buf

def choose( cond, yes, no ) :
    ans = yes if cond else no
    return ans

def get_params_from_Name ( Name, KERNEL_KEY ) :
    demangled_Name = cxxfilt.demangle( Name )
    # First, eliminate the function arguments
    Name = re.sub( '\\(.*\\)$', '', demangled_Name )
    Name = re.sub( '.*<', '', Name )
    Name = re.sub( '>.*', '', Name )
    Name = re.sub( ',', ' ', Name )
    a = Name.split()
    Name = '{} {} {} {} {} {}'.format(a[0],a[2],a[3],a[4],a[5],a[6])
    return Name.split()

def listsort_by_index( data ) :
    ctr = len( data )
    index = list( range( ctr ) )
    for i0 in range( ctr ) :
        i = index[i0]
        key_i = data[i][5]
        for j0 in range( i0+1, ctr ) :
            j = index[j0]
            key_j = data[j][5]
            if key_i > key_j :
               index[i0] = j
               index[j0] = i
               i = j
               key_i = key_j
    return index


if __name__ == '__main__' :

    args = sys.argv
    argc = len( args )

    if argc != 4 :
        print( 'Usage: {} CG keyval target_cu_file'.format( os.path.basename( args[0] ) ) )
        quit()

    CG         = args[1]
    KERNEL_KEY = args[2]
    TARGET     = args[3]

    #REGMAX     = args[4]

    if not os.path.exists( TARGET ) :
        sys.stderr.write( 'Error: file "{}" not existing\n'.format( TARGET ) )
        quit()

    CUDA_PATH = os.getenv( 'CUDA_PATH', default = '/usr/local/cuda' )
    if not os.path.exists( CUDA_PATH ) :
        CUDA_PATH = '/usr/local/cuda'
    if not os.path.exists( CUDA_PATH ) :
        sys.stderr.write( 'Error: CUDA_PATH "{}" not existing\n'.format( CUDA_PATH ) )
        quit()


    CG_lists = [
    '130', '200', '300',
    '350', '370',
    '500', '520', '530',
    '600', '610', '620',
    '700', '750',
    '800', '860',
    '890',
    '900',
    '1000', '1200'
    ]

    if CG in CG_lists :
        COMPILER_FLAGS = '-'
    else :
        sys.stderr.write( 'Error: CG "{}" not supported\n'.format( CG ) )
        sys.stderr.write( '       or new-architecture has been specified\n' )
        quit()
    SM = int(CG)//10


    REGMAX = 255
    #SPLMAX = 0
    #SPLMAX = 64
    #SPLMAX = 128
    SPLMAX = 256
    #SPLMAX = 511

    COMPILER = '{cuda_path}/bin/nvcc'.format( cuda_path=CUDA_PATH )
    COMPILER_FLAGS = '-O3 --default-stream per-thread --compiler-options -fno-strict-aliasing --compiler-options -fopenmp --compiler-options -fPIC --compiler-options -Wall -DUNIX --ptxas-options=\'--allow-expensive-optimizations true\' --ptxas-options=\'--register-usage-level 0\' --ptxas-options=-v --maxrregcount={regmax} --extra-device-vectorization --default-stream per-thread --dopt=on --fmad=true -I{cuda_path}/include -I./include -I../include -I../../include -I../../../include -I./half/include -I../half/include -I../../half/include -I../../../half/include -I. --gpu-architecture=sm_{sm} --generate-code arch=compute_{sm},code=compute_{sm} --generate-code arch=compute_{sm},code=sm_{sm} --define-macro CURRENT_GPU={cg}'.format( sm=SM, cg=CG, cuda_path=CUDA_PATH, regmax=REGMAX )

    cmd = '{compiler} {flags} -c {target} -o /dev/null'.format( compiler=COMPILER, flags=COMPILER_FLAGS, target=TARGET )

    proc = subprocess.Popen( cmd, shell = True, stdout = subprocess.PIPE, stderr = subprocess.STDOUT )


    GX = 0
    GY = 0
    VX = 0
    UX = 0
    MX = 0

    data = []
    while True :

        line = proc.stdout.readline()
        if ( not line ) or ( proc.poll() is not None ) :
            break
        buf = byte2string( line )
        #print( buf )

        if not ( ( ' Function ' in buf ) and ( KERNEL_KEY in buf ) ) :
            continue

        Name = buf.split()[6]
        #print(":[NAME]:"+Name)
        P = get_params_from_Name ( Name, KERNEL_KEY )
        #print(P)
        if len(P) >= 5 :
           GX = int( P[1] )
           GY = int( P[2] )
           VX = int( P[3] )
           UX = int( P[4] )
           MX = int( P[5] )

        spilled = 0
        flag = False
        while True :
            line = proc.stdout.readline()
            if ( not line ) or ( proc.poll() is not None ) :
                break
            buf = byte2string( line )
            #print("::"+buf)

            if 'Compiling' in buf :
                if flag :
                    data += [ [ Registers, GX, GY, VX, UX, MX, spilled ] ]
                    flag = False
                break

            if 'spill' in buf :
                Q = buf.split()
                #spilled = int( Q[4] ) + int( Q[8] )
                spilled = int( Q[4] )
                if spilled < int( Q[8] ) :
                    spilled = int( Q[8] )
                Registers = 0
                flag = True
            if 'register' in buf :
                #print("@@"+buf)
                Q = buf.split()
                Registers = int( Q[4] )
                data += [ [ Registers, GX, GY, VX, UX, MX, spilled ] ]
                flag = False
                break

        if flag :
            data += [ [ Registers, GX, GY, VX, UX, MX, spilled ] ]
            flag = False


    index = listsort_by_index( data )
    fmt = '{:4d} {:3d} {:3d} {:3d} {:3d} {:3d} {:3d}'


    DATA = {}
    for i in range( len(index) ) :
        j = index[i]
        DATA[i] = data[j]


    for i in range( 0, len(index) ) :
        if DATA[i][0] > 0 :
            if i+1 < len(index) :
                for j in range( i+1, len(index) ) :
                    P = DATA[i]
                    Q = DATA[j]
                    if P[1] == Q[1] and P[2] == Q[2] and \
                       P[3] == Q[3] and P[4] == Q[4] and P[5] == Q[5] :
                        DATA[i][6] = P[6] + Q[6]
                        DATA[j][0] = 0
            P = DATA[i]
            Registers = P[0]
            GX = P[1]
            GY = P[2]
            VX = P[3]
            UX = P[4]
            MX = P[5]
            s = choose( P[6] > SPLMAX, 0, choose( P[6] > 0, 2, 1 ) )
            print( fmt.format( Registers, GX, GY, VX, UX, MX, s ) )


    proc.wait()
    sys.exit( 0 )

