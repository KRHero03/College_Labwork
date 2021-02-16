#! /bin/bash


if [[ $1 && $2 && $1 -gt 0 ]]
then
    i=0
    while [ $i -lt $1 ]
    do
        echo $2
        i=$(($i+1))
    done
else
    echo 'Help: Enter 1st Param as postive Integer and 2nd Param as a string!'
fi