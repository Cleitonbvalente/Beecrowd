#include <stdio.h>
int main()
{
    int N,s,factorial = 1;

    scanf("%d",&N);

    for(s = N; s >= 1; s--){
        factorial = factorial*s;
    }
    printf("%d\n",factorial);

    return 0;
}
