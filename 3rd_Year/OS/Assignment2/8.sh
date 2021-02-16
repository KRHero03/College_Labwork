#!/bin/bash

if ! [[ $1 || $2 || $3 ]]
then
    echo 'Insufficient args'
    exit
fi

num1=$1
num2=$2

if [[ $3 = '+' ]]
then
    sum=$((num1 + num2))
    echo $sum
elif [[ $3 = '-' ]]
then
    diff=$((num1 - num2))
    echo $diff
elif [[ $3 = 'x' ]]
then
    mul=$((num1 * num2))
    echo $mul
elif [[ $3 = '/' ]]
then
    if [[ $num2 -eq 0 ]]
    then
        echo 'Division by 0 not possible!'
    else 
        div=$((num1/num2))
        echo $div
    fi
else
    echo 'Invalid operator!'
fi

    
