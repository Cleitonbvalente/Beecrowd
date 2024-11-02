#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A,B,C, maiorAB, maiorXC;
    scanf("%d %d %d", &A, &B, &C);

maiorAB = (A+B+abs(A-B))/2;
maiorXC = (maiorAB+C+abs(maiorAB-C))/2;

printf("%d eh o maior\n", maiorXC);

return 0;
}
