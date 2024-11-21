#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    int n = 81923;
    int sum = 0;
    
    while (n)
    {
        sum += n%10;
        n = n/10;
    }

    printf("%d", sum);

    return 0;
}
