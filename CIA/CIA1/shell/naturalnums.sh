#!/bin/bash
# Print First N Natural Numbers and Their Sum
# Usage: ./naturalnums.sh <n>
# Example: ./naturalnums.sh 10

n=$1
sum=0

echo "Natural Numbers from 1 to $n:"
for ((i=1; i<=n; i++))
do
    echo $i
    sum=$((sum+i))
done

echo "Sum of first $n natural numbers = $sum"
