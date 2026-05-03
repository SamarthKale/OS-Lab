#!/bin/bash
# Check Even or Odd
# Usage: ./evenodd.sh <number>
# Example: ./evenodd.sh 7

if [ $(($1%2)) -eq 0 ]
then
    echo "$1 is Even"
else
    echo "$1 is Odd"
fi
