#include <stdio.h>
#include <stdlib.h>
int main()
{
    int k[5] = { 3, 1, 7, 2, 6 };
    float d = 0;
    int t = 3;
    int i;
    for (i = 0; i < 5; i++) {
        if (k[5] > t)
            d += k[i];
        else
            d++;
    }
    d /= 2;
    printf("%f\n", d);
    system("pause");

    return 0;
}