#!/bin/bash
# Multiplication Table
# Usage: ./multtable.sh <number>
# Example: ./multtable.sh 7

n=$1
echo "Multiplication Table of $n:"
for ((i=1; i<=10; i++))
do
    echo "$n x $i = $((n*i))"
done
