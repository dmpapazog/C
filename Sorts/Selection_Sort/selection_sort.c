#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000
    
typedef int element;

void selection_sort(element* pinakas, int n);
void swap(int* a, int* b);
void init_array(element* pinakas, int n, int a, int b);
void print_array(element* pinakas, int n);

int main()
{
    element pinakas[SIZE];

    int megethos = 15;

    init_array(pinakas, megethos, 1, 100);

    printf("Arxikos pinakas\n\n");
    print_array(pinakas, megethos);

    selection_sort(pinakas, megethos);

    printf("\nTa3inomhmenos pinakas me xrhsh tou\n");
    printf("algori8mou ta3inomhshs me epilogh:\n\n");
    print_array(pinakas, megethos);

    system("pause");

    return 1;
}

void selection_sort(element* pinakas, int n)
{
    int i, j;
    int pos;

    for (i = 0; i < n; i++) {
        pos = i;

        for (j = i; j < n; j++) {
            if (pinakas[j] < pinakas[pos])
                swap(&pinakas[pos], &pinakas[j]);
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

void init_array(element* pinakas, int n, int a, int b)
{
    int i;
    srand(time(NULL));

    for (i = 0; i < n; i++) {
        pinakas[i] = rand() % (b - a + 1) + a;
    }
}

void print_array(element* pinakas, int n)
{
    int i;

    int typos_pinaka;
    typos_pinaka = sizeof(element);

    switch(typos_pinaka) {
        case sizeof(int):
            printf("[");
            for (i = 0; i < n - 1; i++)
                printf(" %2d,", pinakas[i]);
            printf(" %2d ]\n", pinakas[n - 1]);
            break;
        case sizeof(double):
            printf("[");
            for (i = 0; i < n - 1; i++)
                printf(" %2.3f,", pinakas[i]);
            printf(" %2.3f ]\n", pinakas[n - 1]);
            break;
        default:
            printf("Den anagnwristhke o typos toy pinaka!!!");
            exit(1);
    }
}