#! /usr/bin/env python

import sys
import os
import subprocess
import re
import math


def check_lines( line ) :
    err = False
    for j in line :
        if 'ERR' in line[j] :
            err = True
            break
        if 'cannot' in line[j] :
            err = True
            break
    return err


fmt_data  = '{}{:012d} {:3d} {:3d} {:3d} {:3d} {:3d} {:4d}{}'
fmt_param = '{} {} {} {} {} {}'

def print_out( line ) :
    if check_lines( line ) is True :
        return
    for j in line :
        a = line[j].split()
        # earse irregular print out
        a[2] = re.sub( '[0-9]>', '', a[2] );
        N = int( a[1] )
        T = float( a[2] )
        point = int( float( a[4] ) * 1000 )
        header = 'N= {:6d}  '.format( N )
        print( fmt_data.format( header, point,
            BLOCK_SIZE, VX, UX, MULTI, _M_, GY, '' ) )
        if not N in pmax :
            pmax[N] = point
            tmin[N] = T
            ohed[N] = fmt_data.format( header, point,
               BLOCK_SIZE, VX, UX, MULTI, _M_, GY, '' )
        else :
            if pmax[N] < point :
               pmax[N] = point
               tmin[N] = T
               ohed[N] = fmt_data.format( header, point,
                  BLOCK_SIZE, VX, UX, MULTI, _M_, GY, '' )
        global nmax
        nmax = max( nmax, N )
    print( 'EOR' )


def print_top20( topfile ) :
    itr = len( Point )
    with open( topfile, mode='w' ) as file :
        print( '# point BLOCK_SIZE VX UX MULTI _M_ GY' )
        for j in range( min( itr, 20 ) ) :
            point = Point[j]
            line  = Param[j].split()
            BLOCK_SIZE = int( line[0] )
            VX         = int( line[1] )
            UX         = int( line[2] )
            MULTI      = int( line[3] )
            _M_        = int( line[4] )
            GY         = int( line[5] )
            print( fmt_data.format( '# ', point,
                BLOCK_SIZE, VX, UX, MULTI, _M_, GY, '' ) )
            file.write( fmt_data.format( '', point,
                BLOCK_SIZE, VX, UX, MULTI, _M_, GY, '\n' ) )
    

def calc_point( line ) :
    err = check_lines( line )
    if err is True :
        return
    point = 0
    Point = ''
    param = fmt_param.format( BLOCK_SIZE, VX, UX, MULTI, _M_, GY )
    C_matched = 400000

    for j in line :
        a = line[j].split()
        # earse irregular print out
        a[2] = re.sub( '[0-9]>', '', a[2] );
        N = int( a[1] )
        T = float( a[2] )
        Tmin = tmin[N]
        tx = float(N)/nmax
        if T <= Tmin :
            Point = '{} {}:{}'.format( Point, N, T )
            c = C_matched
            if int(args[2]) > 3 :
                #c = 4000 + int(c*(math.exp(-16*tx*tx)+0.1)/3.)
                c = c - int(c*(math.exp(-16*tx*tx)+0.1)/1.2)
                # c - c * (1+0.1)/1.2 = c * (1.2-1.1)/1.2 = c / 12
        else :
            cx = math.fabs((Tmin-T)/Tmin)
            c = 2.0*cx*cx*cx
            c = c * 1200 * math.sqrt(tx*tx)
            if cx == 0 :
                c = C_matched
            elif c < 700 :
                c = int(600.*math.exp(-c)+1)
            else :
                c = 1
        point = point + c

    kernel[param] = point
    return point


def data_analysis( itr ) :

    global BLOCK_SIZE, VX, UX, MULTI, _M_, GY

    with open( infile, mode = 'r' ) as file :

        flag = False
        i = 0
        line = {}

        BLOCK_SIZE = 32
        VX         = 1
        UX         = 1
        MULTI      = 2
        _M_        = 0
        GY         = 3

        while True :

            buff = file.readline()
            if not buff :
                break

            if '#define' in buff :

                if flag :
                    if itr == 0 :
                        print_out( line )
                    else :
                        calc_point( line )
                    flag = False
                    i = 0
                if 'N=' in buff :
                    buff = re.sub( 'N= [0-9]* ', '', buff );

                if 'BLOCK_SIZE' in buff :
                    BLOCK_SIZE = int( buff.split()[2] )
                    continue
                if 'VX' in buff :
                    VX = int( buff.split()[2] )
                    continue
                if 'UX' in buff :
                    UX = int( buff.split()[2] )
                    continue
                if 'MULTIPLICITY' in buff :
                    MULTI = int( buff.split()[2] )
                    continue
                if '_M_' in buff :
                    _M_ = int( buff.split()[2] )
                    continue
                if 'GY' in buff :
                    GY = int( buff.split()[2] )
                    continue
                continue

            if 'N= ' in buff :
                if not 'numBlocks' in buff :
                    if '[s]' in buff :
                        i = i + 1
                        line[i] = buff
                        flag = True
                continue

    if flag :
        if itr == 0 :
            print_out( line )
        else :
            calc_point( line )


def get_Tag( a, option ) :
    tag = a[0]
    for j in range( 1, option ) :
        tag = tag + " " + a[j]
    return tag


def sort_top20( option ) :
    done = {}
    nums = 0
    for param in kernel :
        tag = get_Tag( param.split(), len(param.split()) )
        if not tag in done :
            done[tag] = 1
            Point[nums] = kernel[param]
            Param[nums] = param
            print( "tag[{}]={} / poit={}\n".format( tag,Param[nums],Point[nums] ) )
            nums = nums + 1
    for j in range( 0, nums ) :
        for k in range( j, nums ) :
            if Point[j] < Point[k] :
                Point[j], Point[k] = Point[k], Point[j]
                Param[j], Param[k] = Param[k], Param[j]
    for j in range( 0, nums ) :
       print( "tag[{}]={} / poit={}\n".format( j,Param[j],Point[j] ) )
    done = {}
    k = nums
    for j in range( 0, nums ) :
        tag = get_Tag( Param[j].split(), int(option) )
        if not tag in done :
            done[tag] = 1
        else :
            print( "tag[{}] is dropped\n".format( tag ) )
            Point[j] = 1
            Param[j] = fmt_param.format( 32, 1, 1, 1, 1, k )
            k = k + 1
    for j in range( 0, nums ) :
        for k in range( j, nums ) :
            if Point[j] < Point[k] :
                Point[j], Point[k] = Point[k], Point[j]
                Param[j], Param[k] = Param[k], Param[j]
    if ( nums < 60 ) :
        for j in range( nums, 60 ) :
            Point[j] = 1
            Param[j] = fmt_param.format( 32, 1, 1, 1, 1, j )



if __name__ == '__main__' :

    args = sys.argv
    argc = len( args )

    if argc != 4 :
        print( 'Usage: {} infile sort_ops top20'.format( os.path.basename( args[0] ) ) )
        exit( 1 )


    infile   = str(args[1])
    sort_ops = int(args[2])
    topfile  = str(args[3])


    pmax   = {}
    tmin   = {}
    ohed   = {}
    kernel = {}
    nmax   = -10000
    if not os.path.exists( infile ) :
        sys.stderr.write( 'Error: file {} not exsiting.\n'.format( infile ) )
        exit( 1 )
    data_analysis( 0 )
    for N in tmin :
        print( '{}'.format( ohed[N] ) )
    data_analysis( 1 )


    Point = {}
    Param = {}
    sort_top20( sort_ops )


    if os.path.exists( topfile ) :
        sys.stderr.write( 'Warning: file {} already exsited, it will be overwritten.\n'.format( topfile ) )
    print_top20( topfile )


