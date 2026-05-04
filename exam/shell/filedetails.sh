#!/bin/bash
# Display File Details
# Usage: ./filedetails.sh <filename>
# Example: ./filedetails.sh /etc/hosts

if [ ! -e "$1" ]
then
    echo "File/Directory not found: $1"
    exit
fi

echo "Details of: $1"
ls -l $1
