#!/bin/bash

if ! [ $1 ]
then
    echo 'Help: Please enter 1st param as a File Path'
    exit
fi
cnt=0
while read -r line; do
    n=${#line} 
    if [ $n -eq 0 ]
    then
        cnt=$(($cnt+1))
    fi
done < $1
echo $cnt

# Shortcut method : grep -cvP '\S' $1