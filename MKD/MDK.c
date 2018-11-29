#include <stdio.h>
#include <stdlib.h>

void    Eyclid(int x, int y);
int ComputeMKD(int x, int y);

int main(int argc, char* argv[])
{
    int x, y;
    if (argc == 1) {
        fflush(stdin);
        printf("Enter the two numbers.\n");
        scanf("%i%i", &x, &y);
        Eyclid(x, y);
    } else if (argc != 3) {
        printf("ERROR: Please enter either no arguments or 2 numbers.\n");
        system("pause");
        exit(1);
    } else {
        x = atoi(argv[1]);
        y = atoi(argv[2]);
        Eyclid(x,y);
    }

    system("pause");
    return 0;
}

void Eyclid(int x, int y)
{
    int MKD;
    if (x >= y) {
        MKD = ComputeMKD(x, y);
    } else {
        MKD = ComputeMKD(y, x);
    }

    printf("The maximum common divisor of %i and %i is %i\n\n", x, y, MKD);
}

int ComputeMKD(int x, int y)
{
    int X, Y, remainder;
    X = x;
    Y = y;

    while (Y != 0) {
        remainder = X % Y;
        X         = Y;
        Y         = remainder;
    }
    return X;
}
