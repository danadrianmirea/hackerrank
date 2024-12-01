#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int next_permutation(int n, char **s)
{
    // Step 1: Find the largest index k such that s[k] < s[k + 1]
    int k = -1;
    for (int i = n - 2; i >= 0; i--) {
        if (strcmp(s[i], s[i + 1]) < 0) {
            k = i;
            break;
        }
    }

    // If no such k exists, we've reached the last permutation
    if (k == -1) {
        return 0;
    }

    // Step 2: Find the largest index l such that s[k] < s[l]
    int l = -1;
    for (int i = n - 1; i > k; i--) {
        if (strcmp(s[k], s[i]) < 0) {
            l = i;
            break;
        }
    }

    // Step 3: Swap s[k] and s[l]
    char *temp = s[k];
    s[k] = s[l];
    s[l] = temp;

    // Step 4: Reverse the sequence from k + 1 to the end
    int left = k + 1, right = n - 1;
    while (left < right) {
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }

    return 1;
}

int main()
{
    char **s;
    int n;

    char* input = "2 ab cd";

    sscanf(input+0, "%d", &n);
    int index = 2;
    int count = 0;

    s = calloc(n, sizeof(char *));
    for (int i = 0; i < n; i++)
    {
        s[i] = calloc(11, sizeof(char));
        count = sscanf(input+index, "%s", s[i]);
        if (count > 0) 
        {
            index += strlen(s[i]) + 1;  // Move index forward by the length of the string plus 1 for the space
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", s[i]);
    }

    do
    {
        for (int i = 0; i < n; i++)
            printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
    } while (next_permutation(n, s));

    for (int i = 0; i < n; i++)
    {
        free(s[i]);
    }
    free(s);
    return 0;
}
