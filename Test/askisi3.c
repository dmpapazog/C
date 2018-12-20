#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>

int main()
{
    char c = '\0';
    int power;
    long long int i = 5;
    float f = 5.25;
    double d = 5.52;

    power = pow(2, 3);
    printf("power = %d\n\n", power);

    unsigned char charArray[4] = {'b', 'y', 'e', '\0'};

    printf("The size of c is: %d\n", sizeof(c));
    printf("The minimum value of char is: %d\n", CHAR_MIN);
    printf("The ASCII value of c is: %d\n", c);
    printf("The value of c is: %c\n\n", c);

    printf("The size of i is: %d\n", sizeof(i));
    printf("The maximum value of \'long long int\' is: %ld\n", LONG_MAX);
    printf("The value of i is: %d\n\n", i);

    // printf("The size of c is: %d\n", sizeof(c));
    // printf("The minimum value of char is: %d\n", CHAR_MIN);
    // printf("The ASCII value of c is: %d\n", c);
    printf("The value of c is: %s\n\n", charArray);
    
    // unsigned short int j = 0;
    // while ( charArray[j] != '\0') {
    //     printf("%dst character of charArray: %c\n", j, charArray[j]);
    //     j++;
    // }
    // putchar('\n');

    printf("The size of f is: %d\n", sizeof(f));
    printf("The maximum value of \'float\' is: %E\n", FLT_MAX);
    printf("The value of f is: %f\n\n", f);

    printf("The size of d is: %d\n", sizeof(d));
    printf("The maximum value of \'double\' is: %.16E\n", DBL_MAX);
    printf("The value of d is: %E\n\n", d);



    // printf("The size of c is: %d\n", sizeof(c));
    // printf("The value of c is: %.3E\n", c);
    // printf("The size of d is: %d\n", sizeof(d));
    // printf("The value of d is: %E\n", d);
    
    return 0;
}
