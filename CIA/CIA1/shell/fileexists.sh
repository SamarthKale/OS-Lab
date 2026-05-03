#!/bin/bash
# Check if a File Exists
# Usage: ./fileexists.sh <filename>
# Example: ./fileexists.sh /etc/hosts

if [ -f "$1" ]
then
    echo "File Exists: $1"
else
    echo "File Does NOT Exist: $1"
fi
