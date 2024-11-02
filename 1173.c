#include <stdio.h>
#include <stdlib.h>

int main()
{
int vet[10];
scanf("%d",&vet[0]);
for(int i=1;i<10;i++){
    vet[i]=vet[i-1]*2;
}
for(int i=0;i<10;i++){
    printf("N[%d] = %d\n", i,vet[i]);
}
    return 0;
}
