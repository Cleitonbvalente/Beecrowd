#include <stdio.h>
#include <stdlib.h>

int dg(int x)
{
    int a=x,b=0;
    while(a)
    {
        a/=10;
        b++;
    }
    return b;
}
int main()
{
    int l=0,m=0,N,a,b,c=1,x,y=0,T,d,e=0,f,g,k;
    while(1)
    {
        scanf("%d", &N);
        if(N==0) break;
        else
        {
            int ara[N][N];
            T=N-1;
            for(x=0,c=1,y=0; x<N; x++)
            {
                for(a=y,b=0; a>=0; a--,b++)
                    ara[a][b]=c;
                y++; c*=2;
            }
            for(x=1,y=1; x<N; x++)
            {
                for(a=T,b=y; b<=T; a--,b++)
                    ara[a][b]=c;
                y++; c*=2;
            }
            d=dg(ara[T][T]);
            for(l=0; l<N; l++)
            {
                for(m=0; m<N; m++)
                {
                    if(m==0)
                    {
                        k=ara[l][m];
                        e=dg(k);
                        g=d-e;
                        for(f=1;f<=g; f++)
                            printf(" ");
                        printf("%d",ara[l][m]);
                    }
                    else
                    {
                        k=ara[l][m];
                        e=dg(k);
                        g=d-e;
                        for(f=1;f<=g; f++)
                            printf(" ");
                        printf(" %d",ara[l][m]);
                    }
                }
                printf("\n");
            }
            printf("\n");
        }
    }
    return 0;
}
