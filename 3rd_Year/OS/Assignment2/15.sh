#!/bin/bash

if ! [[ $1 || $2 ]]
then
    echo 'Insufficient args!'
    exit
fi

num=$1
num1=$2

if [ $num -gt $num1 ]
then
    t = $num
    num1=$num
    num=$t
fi

while [ $num -le $num1 ]
do
    if (( $num % 2 == 0 ))
    then
        echo -ne $num' '
    fi
    num=$((num+1))
done
echo ''