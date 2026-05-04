#!/bin/bash
# Display File Content in Reverse (last line first)
# Usage: ./reversefile.sh <filename>
# Example: ./reversefile.sh myfile.txt

if [ ! -f "$1" ]
then
    echo "File not found: $1"
    exit
fi

echo "File content in reverse:"
tac $1
