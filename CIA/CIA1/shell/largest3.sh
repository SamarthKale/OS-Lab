#!/bin/bash
# Find Largest Among Three Numbers
# Usage: ./largest3.sh <num1> <num2> <num3>
# Example: ./largest3.sh 10 25 8

a=$1
b=$2
c=$3

if [ $a -ge $b ] && [ $a -ge $c ]
then
    echo "$a is the Largest"
elif [ $b -ge $c ]
then
    echo "$b is the Largest"
else
    echo "$c is the Largest"
fi
