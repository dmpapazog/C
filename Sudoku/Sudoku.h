#ifndef SUDOKU_H
#define SUDOKU_H

#define SIZE 81
#define TRUE 1
#define FALSE 0

struct cell {
    int i;
    int j;
    int digit;
};

typedef struct cell cell;
typedef struct cell *cellPTR;
typedef struct cell **cellDBL_PTR;

void SU_init(cellDBL_PTR *grid, double size);
void SU_fillGrid(cellDBL_PTR newGrid, double size);
void SU_printGrid(cellDBL_PTR grid);
int SU_isInColumn(cellDBL_PTR grid, cell c, int candidate);
int SU_isInRow(cellDBL_PTR grid, cell c, int candidate);
int SU_isInBlock(cellDBL_PTR grid, cell c, int candidate);
void deleteElement(int* array, int *sizeOfArray, int element);
void swap(int* a, int* b);
void init_psifia(int* array);


#endif