#!/bin/bash
# Check if Given Path is a Directory
# Usage: ./checkdir.sh <path>
# Example: ./checkdir.sh /home/user

if [ -d "$1" ]
then
    echo "$1 is a Directory"
else
    echo "$1 is NOT a Directory"
fi
