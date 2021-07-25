#! /bin/bash

echo 'I,Bubble Sort,Shell Sort'
for ((i=11;i<=10000;i*=2))
do
    echo -ne $i,
    echo -ne $(./bubble $i),
    echo  -ne $(./shell $i),
    echo ''
done