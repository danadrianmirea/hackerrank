#pragma once

#include <stdio.h>
#include <stdlib.h>

void swap(int*a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void swapArray()
{
    int num, *arr, i;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) 
    {
        scanf("%d", arr + i);
    }

    /* Write the logic to reverse the array. */
    for(i = 0; i < num/2; i++) 
    {
        swap(&arr[i], &arr[num-i-1]);
    }

    for(i = 0; i < num; i++)
    {
        printf("%d ", *(arr + i));
    }    

    free(arr);
}