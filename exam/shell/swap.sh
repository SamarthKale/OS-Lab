#!/bin/bash
# Swap Two Numbers Without Third Variable
# Usage: ./swap.sh <num1> <num2>
# Example: ./swap.sh 10 20

a=$1
b=$2

echo "Before Swap: a=$a  b=$b"

a=$((a+b))
b=$((a-b))
a=$((a-b))

echo "After Swap:  a=$a  b=$b"
