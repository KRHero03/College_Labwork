#! /bin/bash

if ! [ $1 ]
then
    echo 'Help: Please enter 1 Param : Path'
    exit
fi

array=()
mapfile -t array< <(find "$1" -type d)

for path in "${array[@]}"
do
    echo -ne 'Executables in '$path': '
    find "$path" -executable | wc -l
done
