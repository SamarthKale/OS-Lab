#!/bin/bash
# Count Number of Files in a Directory
# Usage: ./countfiles.sh <directory>
# Example: ./countfiles.sh /home/user

if [ ! -d "$1" ]
then
    echo "Directory not found: $1"
    exit
fi

count=$(ls $1 | wc -l)
echo "Number of files in $1 = $count"
