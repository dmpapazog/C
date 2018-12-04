#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

void merge_sort(int* pinakas, int n, int start, int finish);
void swap(int* a, int* b);
void init_array(int* pinakas, int n, int a, int b);
void print_array(int* pinakas, int n);
void quickSort(int* pinakas, int start, int finish);
int partition(int* pinakas, int srart, int finish);

int main()
{
    int pinakas[SIZE];

    int megethos = 20;

    init_array(pinakas, megethos, 1, 100);

    printf("\nArxikos pinakas\n\n");
    print_array(pinakas, megethos);

    quickSort(pinakas, 0, megethos - 1);

    printf("\nTa3inomhmenos pinakas me xrhsh tou\n");
    printf("algori8mou ta3inomhshs sygxwneyshs:\n\n");
    print_array(pinakas, megethos);

    system("pause");

    return 1;
}

void swap(int* a, int* b)
{
    int temp;

    temp = *a;
    *a   = *b;
    *b   = temp;
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
    printf(" %2d ]\n", pinakas[i]);
}

void quickSort(int* pinakas, int start, int finish)
{
    if (start < finish) {
        int pos;
        pos = partition(pinakas, start, finish);
        quickSort(pinakas, start, pos - 1);
        quickSort(pinakas, pos + 1, finish);
    }
}

int partition(int* pinakas, int start, int finish)
{
    int pivot = pinakas[start];
    int i = start + 1;
    int j = finish;

    while (1) {
        while (pinakas[i] <= pivot && i <= finish)
            i++;
        while (pinakas[j] > pivot && j > start)
            j--;
        if (i < j)
            swap(&pinakas[i], &pinakas[j]);
        else {
            swap(&pinakas[start], &pinakas[j]);
            return j;
        }
    }
}