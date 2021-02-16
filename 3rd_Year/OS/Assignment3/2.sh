#! /bin/bash

if [[ $1 &&  $1 -gt 0 ]]
then
    i=1

    while [ $(($i * $i)) -le $1 ]
    do
        if [ $(($1 % $i)) -eq 0 ]
        then
            echo -ne $i' '

            if [ $(($1/$i)) -ne $i ]
            then
                echo -ne $(($1/$i))' '
            fi
        fi
        i=$(($i+1))
    done
    echo ''
else
    echo 'Help : Enter 1 Positive Integer param whose factors need to be found'
fi