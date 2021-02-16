#!/bin/bash

shopt -s extglob globasciiranges

if [ -z $1 ]
then
    echo 'No input!'
    exit
elif [ -n $1 ]
then
    ans=$1
fi

case $ans in
    '1')
        who
        ;;
    '2')
        cal
        ;;
    '3')
        date
        ;;
    *)
        echo 'Invalid Option!'
esac