#!/bin/bash
# Print Numbers from 1 to N
# Usage: ./print1ton.sh <n>
# Example: ./print1ton.sh 10

n=$1
echo "Numbers from 1 to $n:"
for ((i=1; i<=n; i++))
do
    echo $i
done
