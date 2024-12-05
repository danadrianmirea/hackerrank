#!/bin/bash

# Prompt the user for two integers
read -p "Enter the first integer (x): " x
read -p "Enter the second integer (y): " y

if [ "$x" -gt "$y" ]; then
    echo "X is greater than Y"
elif [ "$x" -eq "$y" ]; then 
    echo "X is equal to Y"
else
    echo "X is less than Y"
fi