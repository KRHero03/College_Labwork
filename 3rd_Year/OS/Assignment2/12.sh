#!/bin/bash

if ! [ $1 ]
then
    echo 'Insufficient args'
    exit
fi

num=$1

ans=0

while [ $num -gt 0 ]
do
    rem=$((num%10))
    ans=$((ans + rem))
    num=$((num/10))
done
echo $ans;   