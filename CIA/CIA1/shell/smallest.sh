#!/bin/bash
# Find Smallest Among N Numbers
# Usage: ./smallest.sh <num1> <num2> <num3> ...
# Example: ./smallest.sh 5 2 9 1 7

min=$1
shift

for i in "$@"
do
    if [ $i -lt $min ]
    then
        min=$i
    fi
done

echo "Smallest = $min"
