#include <stdio.h>
#include <stdlib.h>



int main()
{
       int X = 0;
    int fuel=0;
       int alcool=0;
       int gasolina=0;
       int diesel=0;
           while (X != 4) {

            scanf("%d", &X);
                  if (X == 1) {
                alcool+=1;

            }else if (X == 2) {
                gasolina += 1;

            }else if (X == 3) {
                diesel += 1;
            }
        }
        printf("MUITO OBRIGADO\n");
        printf("Alcool: %d\n", alcool);
        printf("Gasolina: %d\n", gasolina);
        printf("Diesel: %d\n", diesel);

    return 0;
}
