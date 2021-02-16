#! /bin/bash

now=$(date '+%s')
midnight=$(date -d 'today 00:00:00' '+%s')
sec=$(($now - $midnight))

if [[ $sec -gt 72000 || $sec -le 23400 ]] # 8 PM to 6:30 AM
then
    echo 'Good Night!'
elif [[ $sec -gt 23400 && $sec -le 43200 ]] # 6:30 AM to 12 PM
then
    echo 'Good Morning!'
elif [[ $sec -gt 43200 && $sec -le 61200  ]] # 12 PM to 5 PM
then
    echo 'Good Afternoon!'
elif [[ $sec -gt 61200 && $sec -le 72000 ]] # 5 PM to 8 PM 
then
    echo 'Good Evening!'
fi
