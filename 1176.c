#include <stdio.h>
#include <stdlib.h>

int main()
{
   long long int n, x = 0, y = 1, prox, z;
   int a,b;
   scanf("%d", &b);
   for(a=1; a<=b; a++, x = 0, y = 1)
   {
       scanf("%lld",&n);
       n=n+1;
       for ( z = 0 ; z < n ; z++ )
       {
          if (z <= 1) prox = z;
          else
          {
             prox = x + y;
             x = y;
             y = prox;
          }
       }
          printf("Fib(%lld) = %lld\n",n-1,prox);
   }
   return 0;
}

