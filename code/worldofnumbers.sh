#!/bin/bash

# Prompt the user for two integers
read -p "Enter the first integer (a): " a
read -p "Enter the second integer (b): " b

# Calculate the sum, difference, product, and quotient
sum=$((a + b))
difference=$((a - b))
product=$((a * b))

# Handle division carefully to avoid division by zero
if [ "$b" -ne 0 ]; then
  quotient=$((a / b))
else
  quotient="undefined (division by zero)"
fi

# Display the results
echo "$sum"
echo "$difference"
echo "$product"
echo "$quotient"
