#pragma once

#include <stdio.h>
#include <string.h>

void splitStringInTokens(const char* s)
{
    char* str = malloc(strlen(s) + 1);
    strcpy(str, s);

    // split into tokens and print them
    char* p = strtok(str, " ");
    while (p)
    {
        printf("%s\n", p);
        p = strtok(NULL, " ");
    }

    free(str);
}
