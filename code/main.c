#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void calculate_the_maximum(int n, int k) {
  int maxAnd = 0;
  int maxOr = 0;
  int maxXor = 0; 
  
  for(int a=1; a<=n-1;a++)
  {
      for(int b=a+1; b<=n; b++)
      {
        int and = a&b;                                                       
        int or = a|b;
        int xor = a^b;
  
        if( ( and  > maxAnd ) && ( and < k ) ) maxAnd = and;
        if( ( or   > maxOr  ) && ( or  < k ) ) maxOr = or;
        if( ( xor  > maxXor ) && ( xor < k ) ) maxXor = xor;
        
      }
  }
  
  printf("%d\n", maxAnd);
  printf("%d\n", maxOr);
  printf("%d\n", maxXor);
}

int main() {
    int n, k;

    n = 3;
    k = 2;

    //scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
