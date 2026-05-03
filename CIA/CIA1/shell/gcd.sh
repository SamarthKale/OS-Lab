#!/bin/bash
# Find GCD (Greatest Common Divisor) of Two Numbers
# Usage: ./gcd.sh <num1> <num2>
# Example: ./gcd.sh 48 18

a=$1
b=$2

while [ $b -ne 0 ]
do
    temp=$b
    b=$((a%b))
    a=$temp
done

echo "GCD = $a"
