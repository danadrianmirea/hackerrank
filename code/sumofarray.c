#include "sumofarray.h"

#include <stdio.h>
#include <stdlib.h>

void SumOfArray()
{
    int n;
    int sum = 0;

    char input[] = "4\n8 2 1 9";

    sscanf(input, "%d\n", &n);
    int *arr = (int*)malloc(n*sizeof(int));
    
    for(int i=0; i<n; i++)
    {
        sscanf(input+i, "%d ", &arr[i]);
        sum += arr[i];
    }
    
    printf("%d\n", sum);
    
    free(arr);    
}