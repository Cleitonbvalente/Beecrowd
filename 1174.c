#include <stdio.h>
#include <stdlib.h>

int main()
{
    double x[100];
    int i;
    for(i=0;i<=99;i++){
        scanf("%lf",&x[i]);
    }
    for(i=0;i<=99;i++){
        if(x[i]<=10.0){
            printf("A[%d] = %.1lf\n",i,x[i]);
        }
    }
    return 0;
}
