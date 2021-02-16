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

case "$ans" in
    *([0-9])) echo 'It is a number!'
    ;;
    *([aeiouAEIOU])) echo 'It is a vowel!'
    ;;
    *([a-z])) echo 'It is a lowercase alphabet!'
    ;;
    *([A-Z])) echo 'It is an uppercase alphabet!'
    ;;
    *) echo 'It is a special character!'
    ;;
esac
