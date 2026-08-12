#! /usr/bin/env python

import sys
import os
import subprocess
import re
import math


def index( n, m ) :
    index = '{},{}'.format( n, m )
    return index

if __name__ == '__main__' :

    args = sys.argv
    argc = len( args )

    outfile = open( args[1], mode = 'w' )

    outfile.write( '// ----- begin comment -----\n' )
    outfile.write( '#if 0\n' )

    Nmin = +1000
    Nmax = -Nmin

    s = {}
    for m in range( 0, 20 + 1 ) :
        N = -1
        filename = 'mat.{}'.format( m )
        if os.path.isfile( filename ) :
            with open( filename, mode = 'r' ) as file :
                while True :
                    line = file.readline()
                    if not line :
                        break
                    S = line.split()
                    N = int( S[0] )
                    f = float( S[1] )
                    s[index( N, m )] = f
                    if Nmin > N :
                        Nmin = N
                    if Nmax < N :
                        Nmax = N
        if m == 0 :
            sm = ( 1 if N == -1 else 0 )

    if Nmin == 0 :
        Nmin = 1

    point = {}
    for m in range( sm, 20 + 1 ) :
        point[m] = 0

    smax = {}
    order = {}

    for n in range( Nmin, Nmax + 1 ) :

        order = {}
        for m in range( sm, 20 + 1 ) :
            order[m] = m

        for m in range( sm, 20 + 1 ) :
          if not index( n, order[m] ) in s :
              s[index( n, order[m] )] = 0

        for m in range( sm, 20 + 1 ) :
            for j in range( m + 1, 20 + 1 ) :
                if s[index( n, order[m] )] < s[index( n, order[j] )] :
                    order[m], order[j] = order[j], order[m]

        mk = order[sm]
        smax[n] = s[index( n, mk )]

        out_data = '{:d} {:g} /'.format( n, smax[n] )
        for j in range( sm, 20 + 1 ) :
            mk = order[j]
            sk = s[index( n, mk )]
            fx = sk - smax[n]
            d = ( j - sm + 1 )
            c = - 100 * fx * fx * d * d
            dp = 0.
            if c > -100 :
                dp = math.exp( c )
            point[mk] += dp
            out_data += ' {:2d}'.format( mk )

        outfile.write( out_data+'\n' )

    order = {}
    for m in range( sm, 20 + 1 ) :
        order[m] = m

    for m in range( sm, 20 + 1 ) :
        for j in range( m + 1, 20 + 1 ) :
            if point[order[m]] < point[order[j]] :
                order[m], order[j] = order[j], order[m]

    outfile.write( '%% stats\n' )
    for m in range( sm, 20 + 1 ) :
        outfile.write( '%% {:2d} {:8d}\n'.\
            format( order[m], int( point[order[m]] ) ) )

    used = {}
    for m in range( sm, 20 + 1 ) :
        used[m] = 0

    qp = {}
    for n in range( Nmin, Nmax + 1 ) :
        SMAX = smax[n]
        if SMAX <= 0 :
            r = -1e+10
            j = 0
            for m in range( sm, 20 + 1 ) :
                k = order[m]
                if r < s[index( n, k )] :
                    r = s[index( n, k )]
                    j = k
        else :
            r = 1e+10
            j=0
            for m in range( sm, 20 + 1 ) :
                k = order[m]
                c = (SMAX - s[index( n, k )])/SMAX
                if c < 0.05 :
                    r0 = c + 0.10 * ( ( m - sm + 1) / ( 20 - sm + 1 ) )
                    if r0 < r :
                        r = r0
                        j = k
        qp[n] = j
        outfile.write( '%% {:d} {:d} {:g} / {:g} {}\n'.\
            format( n, j, s[index( n, j )], SMAX, ( " " if s[index( n, j )]==SMAX else  "*" ) ) )
        used[j] = 1

    outfile.write( '#endif\n' )
    outfile.write( '// ----- end comment -----\n' )

    for m in range( sm, 20 + 1 ) :
        outfile.write( '#define\tKERNEL_{}\t{}\n'.format( m, used[m] ) )
    outfile.write( '\n' )

    fmt=\
'''if ( n >= {_from_} && n <{eq} {_to_} ) {{
\tBLK = {id};
'}} {_else_}
'''
    n0 = Nmin
    for n in range( Nmin + 1, Nmax + 1 ) :
        if qp[n] != qp[n0] :
             outfile.write( fmt.format( _from_=n0, _to_=n, eq='', id=qp[n0], _else_='else' ) )
             n0 = n
    outfile.write( fmt.format( _from_=n0, _to_=0x7fffffff, eq='=', id=qp[n0], _else_='' ) )

    outfile.close()

    in_file = open( args[1], mode = 'r' )
    outfile = open( args[2], mode = 'w' )

    flag = False
    while True :
        buff = in_file.readline()
        if not buff :
            break
        if flag :
            outfile.write( buff )
        if 'end comment' in buff :
            flag = True

    in_file.close()
    outfile.close()

    exit( 0 )

