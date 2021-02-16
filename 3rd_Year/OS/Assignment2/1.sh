#! /bin/bash

echo 'Please enter a character: '
read -n1 ans
echo ''

if [[ $ans =~ [0-9] ]] 
then
    echo 'It is a number!'
elif ! [[ $ans =~ [^(aeiouAEIOU)] ]]
then
    echo 'It is a vowel!'
elif [[ $ans =~ [a-z] ]] 
then
    echo 'It is a lowercase alphabet!'
elif [[ $ans =~ [A-Z] ]] 
then
    echo 'It is an uppercase alphabet!'
else
    echo 'It is a special character!'
fi
echo ''
