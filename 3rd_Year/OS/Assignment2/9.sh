#!/bin/bash

arr=( "$@" )
n=${#arr[@]}

i=0

while [ $i -lt $n ]
do
    j=$i
    while [ $j -lt $n ]
    do
        if [ ${arr[$i]} -lt ${arr[$j]}  ]
        then
            t=${arr[$i]}
            arr[$i]=${arr[$j]}
            arr[$j]=$t
        fi
        j=$((j+1))
    done
    i=$((i+1))
done

printf "%s " "${arr[@]}"
echo ''