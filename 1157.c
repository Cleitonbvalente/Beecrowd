#include <stdio.h>
#include <stdlib.h>

int main()
{
int X, y;
scanf("%d", &X);
for(y=1;y<=X;y++)
{
    if(X%y==0)
        printf("%d\n",y);
}
return 0;
}
