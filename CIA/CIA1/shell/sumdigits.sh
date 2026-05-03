#!/bin/bash
# Sum of Digits of a Number
# Usage: ./sumdigits.sh <number>
# Example: ./sumdigits.sh 1234

n=$1
sum=0

while [ $n -gt 0 ]
do
    r=$((n%10))
    sum=$((sum+r))
    n=$((n/10))
done

echo "Sum of Digits = $sum"
