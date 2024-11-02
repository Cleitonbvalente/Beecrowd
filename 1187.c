#include <stdio.h>
#include <stdlib.h>

int main()
{
    double r=0.0, M[12][12];
    char T[2];
    int D,x,y,z,b=10,e=1;
    scanf("%s", &T);
    for(x=0;x<=11;x++)
    {
        for(y=0; y<=11; y++)
            scanf("%lf", &M[x][y]);
    }
    for(z=0; z<=4;z++)
    {
        for(D=e; D<=b;D++) r+=M[z][D];
            b--;
            e++;
    }
    if(T[0]=='S')
        printf("%.1lf\n",r);
    else if(T[0]=='M')
    {
        r=r/30.0;
        printf("%.1lf\n",r);
    }
    return 0;
}
