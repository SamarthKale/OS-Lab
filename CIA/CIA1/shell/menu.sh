#!/bin/bash
# Case Statement Menu
# Usage: ./menu.sh <choice>
# Example: ./menu.sh 1
# Choices:
#   1 = Show current date and time
#   2 = Show current directory
#   3 = Show logged in users

choice=$1

case $choice in
    1) echo "Current Date & Time:"; date;;
    2) echo "Current Directory:"; pwd;;
    3) echo "Logged In Users:"; who;;
    *) echo "Invalid Choice! Enter 1, 2, or 3";;
esac
