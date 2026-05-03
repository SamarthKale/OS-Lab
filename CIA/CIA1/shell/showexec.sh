#!/bin/bash
# Show All Executable Files in a Directory
# Usage: ./showexec.sh <directory>
# Example: ./showexec.sh /usr/bin

if [ ! -d "$1" ]
then
    echo "Directory not found: $1"
    exit
fi

echo "Executable files in $1:"
find $1 -type f -executable
