#! /bin/bash

if ! [ $1 ]
then
    echo 'Help: Please enter 1st Param as Path of File!'
    exit
fi

if [ -d "$1" ]
then
    echo $1' is a Directory!'   
fi

if [ -L "$1" ]
then
    echo $1' is a Symbolic Link!'
fi

if [ -f "$1" ]
then
    echo $1' is a File!'
fi

if [ -b "$1" ]
then 
    echo $1' is a Block Special File!'
fi

if [ -c "$1" ]
then
    echo $1' is a Character Special File!'
fi

if [ -p "$1" ]
then
    echo $1' is a Named Pipe!'
fi

if [ -S "$1" ]
then
    echo $1' is a Socket!'
fi
