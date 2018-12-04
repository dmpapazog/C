#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

void merge_sort(int* pinakas, int n, int start, int finish);
void swap(int* a, int* b);
void init_array(int* pinakas, int n, int a, int b);
void print_array(int* pinakas, int n);
void merge(int* pinakas, int start, int finish);

int main()
{
    int pinakas[SIZE];

    int megethos = 20;

    init_array(pinakas, megethos, 1, 100);

    printf("\nArxikos pinakas\n\n");
    print_array(pinakas, megethos);

    merge_sort(pinakas, megethos, 0, megethos - 1);

    printf("\nTa3inomhmenos pinakas me xrhsh tou\n");
    printf("algori8mou ta3inomhshs sygxwneyshs:\n\n");
    print_array(pinakas, megethos);

    system("pause");

    return 1;
}

void merge_sort(int* pinakas, int n, int start, int finish)
{
    int middle;

    if (start == finish) // 1 stoixeio
        return;
    else if (start == finish - 1) // 2 stoixeia
    {
        if (pinakas[start] > pinakas[finish])
            swap(&pinakas[start], &pinakas[finish]);
    } else {
        middle = (start + finish) / 2;
        merge_sort(pinakas, n, start, middle);
        merge_sort(pinakas, n, middle + 1, finish);
        merge(pinakas, start, finish);
    }
}

void merge(int* pinakas, int start, int finish)
{
    int i, j, k;
    int C[SIZE];
    int middle, n, m;

    k = 0;

    middle = (start + finish) / 2;

    i = start;
    n = middle;

    j = middle + 1;
    m = finish;

    while (i <= n && j <= m) {
        if (pinakas[i] < pinakas[j]) {
            C[k] = pinakas[i];
            k++;
            i++;
        } else {
            C[k] = pinakas[j];
            k++;
            j++;
        }
    }

    if (i == n + 1) {
        while (j <= m) {
            C[k] = pinakas[j];
            k++;
            j++;
        }
    } else {
        while (i <= n) {
            C[k] = pinakas[i];
            k++;
            i++;
        }
    }

    k = 0;
    i = start;
    while (i <= finish) {
        pinakas[i] = C[k];
        i++;
        k++;
    }
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