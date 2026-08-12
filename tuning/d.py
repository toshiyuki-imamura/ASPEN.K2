#! /usr/bin/env python

import sys
import os
import subprocess
import re


def Do( UX ) :

    with open( '../../template/hesymv_M_patterns.h', mode = 'r' ) as file :

        pat = {}
        JJ = 0
        flag = 0
        while True :
            line = file.readline()
            if not line :
                break

            line = re.sub( '//', '', line )
            if re.search( 'switch[ ]*\\([ ]*_MM_', line ) :
                flag = 1
                continue

            if '_M_SPLIT' in line :
                JJ = line.split()[2]
                continue

            if 'case' in line :
                line = re.sub( ':', '', line )
                pat0 = ''
                pat1 = ''
                CASE = int( line.split()[1] )

                while True :
                    line = file.readline()
                    if not line :
                        break

                    if 'break' in line :
                        break
                    if 'if' in line :
                        continue

                    line = re.sub( '_L_[ ]*\\([ ]*[0-9]*[ ]*\\)[ ]*;[ ]*', '', line )
                    line = re.sub( '_M_', '', line )
                    line = re.sub( '[\\(\\);]', '', line )

                    c = line.split()
                    p = len( c )
                    for i in range( p ) :
                        if int( c[i] ) < UX :
                            if int( c[i] ) < JJ :
                                pat0 = pat0 + ',' + c[i]
                            if int( c[i] ) >= JJ :
                                pat1 = pat1 + ',' + c[i]
                    pat[CASE] = pat1 + '.' + pat0
                continue

            if 'default:' in line :
                break

    for i in range( 10 ) :
        if i in pat :
            flag = 0
            for j in range( i+1, 10 ) :
                if j in pat :
                    if pat[i] == pat[j] :
                        flag = 1
                        break
            if flag == 0 :
                for j in range( 0, 100, 10 ) :
                    print( '{} {}'.format( UX, i+j ) )


if __name__ == '__main__' :

    for UX in range(2, 128) :
        Do( UX )

