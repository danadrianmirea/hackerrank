#include "sumofarray.h"

#include <stdio.h>
#include <stdlib.h>

void SumOfArray()
{
    int n;
    int sum = 0;
    
    scanf("%d\n", &n);
    int *arr = (int*)malloc(n*sizeof(int));
    
    for(int i=0; i<n; i++)
    {
        scanf("%d ", &arr[i]);
        sum += arr[i];
    }
    
    printf("%d\n", sum);
    
    free(arr);    
}