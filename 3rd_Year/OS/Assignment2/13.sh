#!/bin/bash

if ! [ $1 ]
then
    echo 'Insufficient args'
    exit
fi

num=$1

ans=1
i=1
while [ $i -le $num ]
do
    ans=$((ans*i))
    i=$((i+1))
done
echo $ans;   