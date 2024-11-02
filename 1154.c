#include <stdio.h>
int main()
{
int x=0,y;
float total=0,media;
while(1){
    scanf("%d",&y);
    if(y<0)
    {
        break;
    }
    else
    {
        x+=y;
        total++;
    }
}
media=x/total;
printf("%.2f\n",media);
    return 0;
}
