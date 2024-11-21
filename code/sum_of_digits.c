#include "sum_of_digits.h"

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