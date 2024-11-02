#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    int digits[] = {0, 9, 189, 2889, 38889, 488889, 5888889, 68888889, 788888889};
    scanf("%d", &x);
    int y = floor(log10(x));
    int result = digits[y] + (x - pow(10, y) + 1) * (y + 1);
    printf("%d\n", result);
    return 0;
}

