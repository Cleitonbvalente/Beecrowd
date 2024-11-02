#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y,z,i,j,k;
    while(1)
    {
        scanf("%d", &x);
        if(x==0) break;
        else
        {
            scanf("%d%d", &y,&z);
            i=x*y;
            k=(i*100)/z;
            k=pow(k,.5);
            printf("%d\n",k);
        }
    }
    return 0;
}
