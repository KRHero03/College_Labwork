#!/bin/bash

#!/bin/bash

if ! [[ $1 || $2 || $3 ]]
then
    echo 'Insufficient args'
    exit
fi

num1=$1
num2=$2


case "$3" in

'+')
    sum=$((num1 + num2))
    echo $sum
    ;;
'-')
    diff=$((num1 - num2))
    echo $diff
    ;;
'x')
    mul=$((num1 * num2))
    echo $mul
    ;;
'/')
    if [[ $num2 -eq 0 ]]
    then
        echo 'Division by 0 not possible!'
    else 
        div=$((num1/num2))
        echo $div
    fi
    ;;
*)
    echo 'Invalid operator!'
    ;;
esac

    
