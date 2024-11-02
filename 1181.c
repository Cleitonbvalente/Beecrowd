#include <stdio.h>
#include <stdlib.h>

int main()
{
    double r=0.0, M[12][12];
    char T[2];
    int D,x,y;
    scanf("%d", &D);
    scanf("%s", &T);
    for(x=0;x<=11;x++)
    {
        for(y=0; y<=11; y++)
        {
        scanf("%lf", &M[x][y]);
        if(x==D)
            r+=M[x][y];
        }
    }
    if(T[0]=='S')
        printf("%.1lf\n",r);
    else if(T[0]=='M')
    {
        r=r/12.0;
        printf("%.1lf\n",r);
    }
    return 0;
}

