#!/bin/bash
# Calculate Power (a^b)
# Usage: ./power.sh <base> <exponent>
# Example: ./power.sh 2 8

a=$1
b=$2
result=1

for ((i=1; i<=b; i++))
do
    result=$((result*a))
done

echo "$a ^ $b = $result"
