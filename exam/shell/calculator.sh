#!/bin/bash
# Basic Calculator
# Usage: ./calculator.sh <num1> <operator> <num2>
# Example: ./calculator.sh 10 + 5
# Operators: + - * /

a=$1
op=$2
b=$3

case $op in
    +) echo "Result = $((a+b))";;
    -) echo "Result = $((a-b))";;
    \*) echo "Result = $((a*b))";;
    /) echo "Result = $((a/b))";;
    *) echo "Invalid Operator. Use: + - * /";;
esac
