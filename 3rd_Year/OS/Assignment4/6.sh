#! /bin/bash

if ! [ -d $1 ]
then
    echo 'Help: Please enter 1 Param : Directory Path'
    exit
fi

find $1 -type f -mtime -1