#! /bin/bash


if [ $1 ]
then
    i=2
    ans=$1
    while [ $i -le $ans ]
    do
        if [[ $(($ans % $i)) -eq 0 ]]
        then
            echo -ne $i' '

            while [ $(($ans % $i)) -eq 0 ]
            do
                ans=$(( $ans / $i ))
            done
        fi
        i=$(( $i + 1 ))
    done

    if [ $ans -gt 1 ]
    then
        echo -ne $i
    fi
    echo ''
else
    echo 'Help : Enter 1 param whose prime factors need to be found'
    exit
fi

