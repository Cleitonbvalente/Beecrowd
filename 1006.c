#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x, y, z, MEDIA;
    scanf("%f",&x);
    scanf("%f", &y);
    scanf("%f", &z);
    MEDIA = ((x*2) + (y*3) + (z*5) )/ 10;
    printf("MEDIA = %.1f\n", MEDIA);
    return 0;
}
