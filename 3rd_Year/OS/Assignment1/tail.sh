#! /bin/sh

echo 'Last 5 Lines:'
tail -n 5 temp.txt # Displays last 5 lines in temp.txt

echo '\nLine 5 and after:'
tail -n +5 temp.txt # Displays since 5th line in temp.txt