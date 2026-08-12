#! /usr/bin/env python

import sys
import os
import subprocess
import re
    
    
if __name__ == '__main__' :
    
    args = sys.argv
    argc = len( args )

    if argc != 3 :
        print( 'Usage: {} infile outfile'.format( os.path.basename( args[0] ) ) )
        exit( 1 )
    
    infile  = args[1]
    outfile = args[2]

    print( 'Shrinking the condition pattern' )

    if not os.path.exists( infile ) :
        sys.stderr.write( 'Error: file {} not exsiting'.format( infile ) )
        exit(1)
    
    with open( infile, mode = 'r' ) as file :

        pat = 0
        From = {}
        To = {}
        Id = {}

        BLK = {}

        line = file.readline()
        while line :
            if 'define' in line :
                S = line.split()
                S[1] = re.sub( 'KERNEL_', '', S[1] )
                i = int( S[1] )
                BLK[i] = 1
            if 'if' in line :
                S = line.split()
                From[pat] = int( S[4] )
                To[pat]   = int( S[8] )
                line = file.readline()
                S = line.split()
                S[2] = re.sub( ';', '', S[2] )
                Id[pat]   = int( S[2] )
                pat += 1
            line = file.readline()
    
    
    with open( outfile, mode='w' ) as file :

        FROM = {}
        TO = {}
        ID = {}
    
        stable = False
        while stable is False :
            stable = True
            for j in range( 1, pat-1 ) :
                if ( From[j] >= 0 ) and ( To[j] - From[j] <= 256 ) :
                    if ( Id[j-1] == Id[j+1] ) :
                        To[j] = To[j+1]
                        for k in range( j-1, 0-1, -1 ) :
                            To[k] = To[j+1]
                            if ( From[k] >= 0 ) :
                                From[j+1] = From[k]
                                From[k] = -1
                                break
                        From[j] = -1
                        Id[j] = Id[j+1]
                        stable = False
    
        i = 0
        for j in range( 0, pat ) :
            if ( From[j] >= 0 ) :
                FROM[i] = From[j]
                TO[i] = To[j]
                ID[i] = Id[j]
                i += 1
    
        for k in BLK :
            BLK[k] = 0
        for j in range( i ) :
            k = ID[j]
            BLK[k] = 1
    
        numK=0
        KK = {}
        for k in BLK :
            if ( BLK[k] ) :
                KK[numK] = k
                numK += 1
    
        for kk in range( numK-1 ) :
            for jj in range( kk+1, numK ) :
                k = KK[kk]
                j = KK[jj]
                if ( k > j ) :
                    t = KK[kk]
                    KK[kk] = KK[jj]
                    KK[jj] = t
    
        file.write( '\n' )
    
        kk=-1
        for k in BLK :
            if BLK[k] == 1 :
                if kk == -1 :
                   kk = k
                file.write( '#define\tKERNEL_{id}\t1\n'.format( id=k ) )
    
        out_data=\
'''

// default kernel is
BLK = {id};

'''
        file.write( out_data.format( id=kk ) )
    

        fmt=\
'''if ( n >= {_from_} && n <{eq} {_to_} ) {{
\tBLK = {id};
}} {_else_}
'''
##
## special coordinate
##
# this was affectd to start from kernel 0
# but it is not seriousely reasonable if kernel 0 is not optimal..
#        ID[0]   = 0

        FROM[i] = TO[i-1]
        TO[i]   = 0x7fffffff
        ID[i]   = ID[i-1]
        for j in range( i ) :
            file.write( fmt.format( _from_=FROM[j], eq='', _to_=TO[j], id=ID[j], _else_='else' ) )
        file.write( fmt.format( _from_=FROM[i], eq='=', _to_=TO[i], id=ID[i], _else_='' ) )

