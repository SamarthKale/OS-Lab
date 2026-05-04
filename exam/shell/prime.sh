#!/bin/bash
# Check if a Number is Prime
# Usage: ./prime.sh <number>
# Example: ./prime.sh 17

n=$1
flag=0

if [ $n -le 1 ]
then
    echo "$n is Not Prime"
    exit
fi

for ((i=2; i<=n/2; i++))
do
    if [ $((n%i)) -eq 0 ]
    then
        flag=1
        break
    fi
done

if [ $flag -eq 0 ]
then
    echo "$n is Prime"
else
    echo "$n is Not Prime"
fi
