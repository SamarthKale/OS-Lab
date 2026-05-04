#!/bin/bash
# Fibonacci Series
# Usage: ./fibonacci.sh <count>
# Example: ./fibonacci.sh 10

n=$1
a=0
b=1

echo "Fibonacci Series (first $n terms):"
for ((i=0; i<n; i++))
do
    echo -n "$a "
    temp=$((a+b))
    a=$b
    b=$temp
done
echo
