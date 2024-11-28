#include <stdio.h>
#include <stdlib.h>

#include <string.h>

int main()
{
    char s[] = "This is an example string";

    // split into tokens and print them
    char* p = strtok(s, " ");
    while (p)
    {
        printf ("%s\n",p);
        p = strtok (NULL, " ");
    }
    return 0;
}