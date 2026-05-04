#!/bin/bash
# Check if String is Palindrome
# Usage: ./palindrome.sh <string>
# Example: ./palindrome.sh madam

str=$1
rev=$(echo $str | rev)

if [ "$str" = "$rev" ]
then
    echo "$str is a Palindrome"
else
    echo "$str is NOT a Palindrome"
fi
