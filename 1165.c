#include <stdio.h>
int main()
{
int e,s,X,N,K=0,l;
scanf("%d", &N);
for(e=0;e<N;e++){
    scanf("%d",&X);
    if(X==1 || X==2)printf("%d eh primo\n", X);
    else if(X>2) {
            for(s=2;s<X;s++) {
                if(X%s==0){
                    K=2;
                    break;
                }
                else K=1;
            }
            if(K==2)
                printf("%d nao eh primo\n",X);
            else if (K==1) printf("%d eh primo\n", X);
    }
}
return 0;
}

