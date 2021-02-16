#!/bin/bash

if ! [ $1 ]
then
    echo 'Insufficient args!'
    exit
fi

file=$1

if ! [ $file ]
then
    echo 'File not found!'
    exit
fi


echo -ne 'Number of characters: '
wc -c $file
echo -ne 'Number of words: '
wc -w $file
echo -ne 'Number of lines: '
wc -l $file