#!/bin/bash
# Reverse a Number
# Usage: ./reversenum.sh <number>
# Example: ./reversenum.sh 12345

n=$1
rev=0

while [ $n -gt 0 ]
do
    r=$((n%10))
    rev=$((rev*10+r))
    n=$((n/10))
done

echo "Reverse = $rev"
