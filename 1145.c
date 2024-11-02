#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y, a, b;
    x=0;
    y=0;
    a=1;
    b=0;
    scanf("%d %d", &x, &y);
    for(a=1;a<=y;a++){
            if(a%x == 0){

                    printf("%d\n", a);
            } else{
                    printf("%d ", a);
            }
        }
    return 0;
}

