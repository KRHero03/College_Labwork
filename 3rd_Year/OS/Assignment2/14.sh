#!/bin/bash

if ! [ $1 ]
then
    echo 'Insufficient args!'
    exit
fi

num=$1

if [ $num -le 0 ]
then
    exit
elif [ $num -eq 1 ]
then
    echo -ne '0'
elif [ $num -eq 2 ]
then
    echo -ne '0 1'
else
    a=0
    b=1
    i=1
    echo -ne $a ' '
    while [ $i -lt $num ]
    do
        c=$b
        b=$((a+b))
        a=$c
        echo -ne $a ' '
        i=$((i+1))
    done
fi
echo ''