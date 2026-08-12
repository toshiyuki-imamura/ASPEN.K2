#! /usr/bin/env python

import sys
import os
import subprocess
import re
import datetime
from pathlib import Path
import shutil



def cat_string_to_file( Fname, data ) :
    with open( Fname, mode = 'w' ) as file :
        file.write(data)
        file.flush()
def append_string_to_file( Fname, data ) :
    with open( Fname, mode = 'a' ) as file :
        file.write(data)
        file.flush()
def run_command( Command, output='', stdout=subprocess.STDOUT ) :
    if output=='' :
        if stdout==subprocess.STDOUT :
            subprocess.run( Command )
        else :
            subprocess.run( Command, stdout=stdout )
    else :
        with open( output, mode = 'w' ) as file :
            subprocess.run( Command, stdout=file )
            file.flush()
def run_command_async( Command, in_pipe=subprocess.DEVNULL ) :
    return subprocess.Popen( Command, stdin=in_pipe, stdout=subprocess.PIPE ).stdout
def run_command_sync( Command, in_pipe=subprocess.DEVNULL ) :
    subprocess.run( Command, stdin=in_pipe )



def Make() :

    NULL = subprocess.DEVNULL

    os.chdir('src')
    objfile = '{}_{}.cu_o' .format(kernel_,uplo_)
    if Path(objfile).exists() :
        Path(objfile).unlink()
    objfile = '{}_{}.cu_lo' .format(kernel_,uplo_)
    if Path(objfile).exists() :
        Path(objfile).unlink()
    run_command( ['make'], stdout=NULL )

    os.chdir('../bench')
    objfile = 'test-{}.o'.format(pred_)
    if Path(objfile).exists() :
        Path(objfile).unlink()
    objfile = 'test2-{}.o'.format(pred_)
    if Path(objfile).exists() :
        Path(objfile).unlink()
    run_comnand( ['make', '-j'], stdout=NULL )

    os.chdir('../')


def ReadTop( TOP ) :

    i=0
    lines = {}
    with open( TOP, mode = 'r' ) as file :
        line = file.readline()
        lines[i] = line
        i = i + 1
        while line[i] :
            line = file.readline()
            lines[i] = line
            i = i + 1
    return lines


def CodeAnaysis( IN, TOP ) :

    run_command( [PYTHON, '../anal_symv.py', IN, '3' TOP], 'anal_symv-result' )
    run_command( ['cat', '-n', TOP] )
    outfile = '{}-{}-auto'.format(kernel_,uplo_)
    run_command( [PYTHON, '../code_gen.py', TOP, uplo_[0], outfile, '10'] )
    shutil.copy( outfile, '../'+outfile )
    return ReadTop( TOP )


def WriteHeader( darafile, ID, M ) :

    with open( datafile, mode = 'w' ) as file :
        for i in range(100) :
            id = i+ID*100
            flag = 1 if int(i/10)*10 == M else 0
            file.write( '#define\tKERNEL_{}\t{}\n'.format(id, flag) )
    shutil.copy(datafile,'../'+datafile)


def FindPattern( regfile, UX, MULTIPLICITY ) :

    lines = CodeAnaysis( IN, TOP )

    ID_BLOCK_SIZE = 0
    ID_VX = 1
    ID_UX = 2
    ID_MM = 3
    ID_Regs = 5
    is_SPILL = 7
    ID_Shmem = 9

    flag = False
    with open( regsfile, mode = 'r' ) as file :
        line = file.readline()
        while not line :
            a = line.split()
            ID_MULTI = len(a)-1
            if ( not '#' in line ) and 
                int(a[ID_UX]) == UX and
                int(a[ID_MULTI]) == MULTIPLICITY and
                int(a[is_SPILL]) > 0 :
                flag = True
                break
            line = file.readline()
    return flag


def Sampling_b1( file, line_data ) :

    line = line_data.split()
    POINTS = int(line[0])

    if POINTS <= 100 :
        return

    M = int(line[5])
    M = int(M / 10)
    M = M * 10

    datafile = '{}-{}-auto2.h'.format(kernel_,uplo_)
    WriteHeader( datafile, ID, M )
    Make()
    os.chdir('tuning/{}-current'.format(kernel))

    BLOCK_SIZE   = int(line[1])
    VX           = int(line[2])
    UX           = int(line[3])
    MULTIPLICITY = int(line[4])

    regsfile = 'log-regs-{}-{}'.format(BLOCK_SIZE,VX)
    if not FindPattern( regfile, UX, MULTIPLICITY ) :
        return

    M = int(line[5])
    M = int(M / 10)
    M = M * 10

    KERNEL=ID*100+M
    TEST2='../../bench/test2-{}-{}'.format(kernel_,uplo_[0])
    run_command( ['timeout', '-s', 'KILL', '360', TEST2, 'IN-exe-a', str(KERNEL)], stdout=file )

    append_string_to_file( 'done_pattern1', '{} {} {} {} {}'.format(BLOCK_SIZE, VX, UX, MULTIPLICITY, M ) )


def Phase_b1( IN, TOP, OUT ) :

    lines = CodeAnaysis( IN, TOP )
    ID_range = min(20, len(lines))

    with open( OUT, mode = 'w' ) as file :
        for ID in range(ID_range) :
            Sampling_b1( file, lines[ID] )


if __name__ == '__main__' :

    args = sys.argv
    argc = len( args )

    ARG = args[1]

    IN  = '{}.{}'.format(args[2],args[3])
    OUT = '{}.{}'.format(args[2],args[4])
    TOP = args[4]

    Phase_b1( IN, TOP, OUT )

