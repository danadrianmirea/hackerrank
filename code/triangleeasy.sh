#!/bin/bash

# Prompt the user for the three sides of the triangle
read -p "Enter the first side: " side1
read -p "Enter the second side: " side2
read -p "Enter the third side: " side3

# Check if all three sides are equal
if [[ "$side1" -eq "$side2" && "$side2" -eq "$side3" ]]; then
  echo "EQUILATERAL"
# Check if any two sides are equal
elif [[ "$side1" -eq "$side2" || "$side2" -eq "$side3" || "$side1" -eq "$side3" ]]; then
  echo "ISOSCELES"
# If no sides are equal, it is scalene
else
  echo "SCALENE"
fi
