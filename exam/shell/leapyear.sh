#!/bin/bash
# Check if a Year is a Leap Year
# Usage: ./leapyear.sh <year>
# Example: ./leapyear.sh 2024

year=$1

if [ $((year%4)) -eq 0 ] && { [ $((year%100)) -ne 0 ] || [ $((year%400)) -eq 0 ]; }
then
    echo "$year is a Leap Year"
else
    echo "$year is NOT a Leap Year"
fi
