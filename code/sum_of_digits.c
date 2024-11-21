#include <stdio.h>
#include "sum_of_digits.h"

void testSumOfDigits(int n)
{
    printf("%d\n", sumOfDigits(n));
}

int sumOfDigits(int n)
{
    int sum = 0;
    
    while (n)
    {
        sum += n%10;
        n = n/10;
    }

    return sum;
}