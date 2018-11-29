#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

void insertion_sort(int* pinakas, int n);
void swap(int* a, int* b);
void init_array(int* pinakas, int n, int a, int b);
void print_array(int* pinakas, int n);

int main()
{
    int pinakas[SIZE];

    int megethos = 15;

    init_array(pinakas, megethos, 1, 100);

    printf("Arxikos pinakas\n\n");
    print_array(pinakas, megethos);

    insertion_sort(pinakas, megethos);

    printf("\nTa3inomhmenos pinakas me xrhsh tou\n");
    printf("algori8mou ta3inomhshs me eisagwgh:\n\n");
    print_array(pinakas, megethos);

    return 1;
}

void insertion_sort(int* pinakas, int n)
{
    int i, j;

    for (i = 1; i < n; i++) {
        for (j = i; j >= 1; j--) {
            if (pinakas[j] <= pinakas[j - 1])
                swap(&pinakas[j], &pinakas[j - 1]);
            else
                break;
        }
    }
}

void swap(int* a, int* b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void init_array(int* pinakas, int n, int a, int b)
{
    int i;
    srand(time(NULL));

    for (i = 0; i < n; i++) {
        pinakas[i] = rand() % (b - a + 1) + a;
    }
}

void print_array(int* pinakas, int n)
{
    int i;

    printf("[");
    for (i = 0; i < n - 1; i++)
        printf(" %2d,", pinakas[i]);
    printf(" %2d ]\n", pinakas[n - 1]);
}