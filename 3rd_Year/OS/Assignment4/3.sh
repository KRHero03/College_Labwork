#! /bin/bash

if ! [[ $1 && $2 ]]
then
    echo 'Help: Please enter 2 Params: 1st - Search Keyword and 2nd - Path'
    exit
fi

grep -RI $1 $2