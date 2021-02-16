#! /bin/bash

for arg in "$@"
do
    if ! [ -d $arg ]
    then
        echo 'Help: Please enter valid Params : Path to directory'
        exit
    fi
done

for arg in "$@"
do
    echo 'Inside '$arg
    array=()

    mapfile -t array< <(find $arg -maxdepth 1 -type d )

    for path in ${array[@]}
    do
        echo -ne $path' '
        find "$path" -maxdepth 1 -executable -type f | wc -l
    done
done