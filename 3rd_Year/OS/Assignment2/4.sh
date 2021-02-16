#!/bin/bash


if [ -z $1 ]
then
    echo 'No input!'
    exit
elif [ -n $1 ]
then
    ans=$1
fi

if [ -d $ans ] 
then
    ls $ans -1 | wc -l 
else
    echo 'No such directory'
fi