#! /bin/bash


for arg in "$@"
do 
    if ! [ -d $arg ] 
    then
        echo 'Help: Please enter valid Params which are directory paths!'
        exit
    fi
done

ans=0

for arg in "$@"
do
    array=()
    mapfile -t array< <(find $arg -type f)

    for file in ${array[@]}
    do
        val=$(ls -s $file | awk '{print $1}')
        ans=$((ans+val))
         
    done
done
echo 'Blocks Occupied: '$ans
    