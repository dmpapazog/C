#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define M 8

int main(int argc, const char *argv[])
{
    int array[N][M];

    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            array[i][j] = rand() % 201;
        }
    }

    for (int i = 0; i < N; i++) {
        printf("| ");
        for (int j = 0; j < M; j++) {
            printf("%4d |", array[i][j]);
        }

        printf("\n|");
        for (int k = 0; k < 48; k++)
            printf("-");
        printf("|\n");
    }

    system("pause");
    putchar('\a');

    return 0;
}
