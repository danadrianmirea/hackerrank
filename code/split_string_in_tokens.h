#pragma once

#include <stdio.h>
#include <string.h>

    void splitStringInTokens(char* s)
    {
        // split into tokens and print them
        char* p = strtok(s, " ");
        while (p)
        {
            printf("%s\n", p);
            p = strtok(NULL, " ");
        }
    }
