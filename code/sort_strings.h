#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char* a, const char* b) 
{
    int result = 0;
    int len_a = strlen(a);
    int len_b = strlen(b);
    
    for(int i=0; i<len_a; i++)
    {
        if(i<len_b)
        {
            if(a[i] > b[i])
            {
                return 1;
            }
            else if(a[i] < b[i])
            {
                return 0;
            }
        }
    }
    
    return result;
}

int lexicographic_sort_reverse(const char* a, const char* b) 
{
    return !lexicographic_sort(a, b);
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) 
{
    int result = 0;
    
    int d1 = strlen(a);
    for(int i=0; i<strlen(a)-1; i++)
    {
        for(int j=i+1; j<strlen(a); j++)
        {
            if(a[i] == a[j]) d1--;
        }
    }
    
    int d2 = strlen(b);
    for(int i=0; i<strlen(b)-1; i++)
    {
        for(int j=i+1; j<strlen(b); j++)
        {
            if(b[i] == b[j]) d2--;
        }
    }

    if(d1==d2) return lexicographic_sort(a, b);
        
    return d1<d2 ? 1: 0;
}

int sort_by_length(const char* a, const char* b) 
{
    return strlen(a) >= strlen(b) ? 1 : 0;
}

void swapstr(char* a, char* b) 
{
    char* tmp = (char*)malloc(strlen(a)+1);
    
    strcpy(tmp ,a);
    a = (char*)realloc(a, strlen(b)+1);
    strcpy(a, b);
    
    b = (char*)realloc(b, strlen(a)+1);
    strcpy(b, tmp);
    
    free(tmp);
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    for(int i=0; i<len-1; i++)
    {
        for(int j=i+1; j<len; j++)
        {
            if( cmp_func(arr[i], arr[j]) > 0 )
            {
                swapstr(arr[i], arr[j]);
            }
        }
    }
}


void TestSortStrings())
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
    
}