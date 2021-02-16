#! /bin/bash

if ! [[ $1 || $2 ]]
then
    echo 'Insufficient args!'
    exit

fi

cat $1 >> $2

echo 'File Copy Complete!'
