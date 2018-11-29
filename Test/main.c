#include <stdio.h>

int main()
{
    int a = 2;
    long int b = 5;
    float c = 5.25;
    double d = 5.52;

    printf("The size of a is: %d\n", sizeof(a));
    printf("The value of a is: %d\n", a);
    printf("The size of b is: %d\n", sizeof(b));
    printf("The value of b is: %d\n", b);
    printf("The size of c is: %d\n", sizeof(c));
    printf("The value of c is: %.3E\n", c);
    printf("The size of d is: %d\n", sizeof(d));
    printf("The value of d is: %E\n", d);
    
    return 0;
}
