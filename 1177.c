#include <stdio.h>
#include <stdlib.h>

int main()
{
int n,i,x[1000],aux;
scanf("%d",&n);
aux=0;
for(i=0;i<1000;i++){
    x[i]=aux;
    aux++;if(aux==n){
    aux =0;
}
}
for(i=0;i<1000;i++){
    printf("N[%d] = %d\n",i,x[i]);
}
    return 0;
}
