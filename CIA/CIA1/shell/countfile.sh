#!/bin/bash
# Count Lines, Words, and Characters in a File
# Usage: ./countfile.sh <filename>
# Example: ./countfile.sh myfile.txt

if [ ! -f "$1" ]
then
    echo "File not found: $1"
    exit
fi

echo "Lines  Words  Characters  File"
wc $1
