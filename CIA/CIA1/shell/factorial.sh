#!/bin/bash
# Factorial of a Number
# Usage: ./factorial.sh <number>
# Example: ./factorial.sh 5

n=$1
fact=1

for ((i=1; i<=n; i++))
do
    fact=$((fact*i))
done

echo "Factorial of $n = $fact"
