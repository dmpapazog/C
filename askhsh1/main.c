#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

int isBetween20and100(int input);

int main(int argc, char const* argv[])
{
    int input, i = 0;
    int array[SIZE];

    srand(time(NULL));

    do {
        if (i > 0)
            printf("Your number %d is not between 20 and 100.\n", input);
        printf("Insert a number between 20 and 100: ");
        scanf("%d", &input);
        printf("\n");
        i++;
    } while (!isBetween20and100(input));

    for (i = 0; i < input; i++) {
        array[i] = rand();
    }

    for (i = 0; i < input; i++) {
        printf("%dst element: %d\n", i + 1, array[i]);
    }

    system("pause");
    return 0;
}

int isBetween20and100(int input)
{
    return (input >= 20 && input <= SIZE);
}