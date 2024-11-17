#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int a, b;

    const char* input = "8\n11\n";

    // Use sscanf instead of scanf to parse the input from the string
    sscanf(input, "%d\n%d", &a, &b);

    // Complete the code
    const char* names[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    for (int i = a; i <= b; i++) 
    {
        if (i >= 1 && i <= 9) 
        {
            printf("%s\n", names[i - 1]);
        } 
        else if (i > 9) 
        {
            i % 2 ? printf("odd\n") : printf("even\n");
        }
    }

    return 0;
}
