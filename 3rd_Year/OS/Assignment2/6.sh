#!/bin/bash


if [[ $1 && $2 ]]
then
    num1=$1
    num2=$2
    sum=$((num1 + num2))
    echo $sum
else
    echo 'Insufficient args!'
    exit
fi
