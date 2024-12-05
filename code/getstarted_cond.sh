#!/bin/bash

# Prompt the user for a character
read -p "Enter a character (Y/y or N/n): " char

# Check the character and display the corresponding message
if [[ "$char" == "Y" || "$char" == "y" ]]; then
  echo "YES"
elif [[ "$char" == "N" || "$char" == "n" ]]; then
  echo "NO"
fi
