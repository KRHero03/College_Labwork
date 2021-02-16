#! /bin/bash

if ! [ $1 ]
then
    echo 'Help: Please enter 1st Param as Path of Directory to be scanned!'
    exit
fi

path=$1

res=$(find $path -type f -exec du -cha -t 1000 {} + | sort -r -h)
lines=$(($(echo "$res" | wc -l) - 1))
echo "$res"
echo 'Total Files: '$lines