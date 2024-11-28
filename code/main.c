#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[1024] = "a11472o5t6";
    //scanf("%s\n", s);
    
    int freqMap[10] = {0};
    for(int i=0; i<strlen(s); i++)
    {
        if('0' <= s[i] && s[i] <= '9')
        {
            freqMap[s[i]-'0']++;
        }
    }
    
    for(int i=0; i<10; i++)
    {
        printf("%d ", freqMap[i]);
    }

    return 0;
}