#!/bin/bash

LINES=0

if [ $# == 0 ]; then
    for f in *.c ; do
        TEMP=$(wc -l ${f} | awk '{print $1}')
        LINES=$[LINES+TEMP]
        echo "${f} ${TEMP}"
    done
elif [ $# == 1 ] && [ $1 == "-q" ] ; then
    for f in *.c ; do
        TEMP=$(wc -l ${f} | awk '{print $1}')
        LINES=$[LINES+TEMP]
    done
else
    echo "usage: codesizes.sh [-q]"
    exit
fi
echo "Total ${LINES}"
