#include "Sudoku.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void SU_init(cellDBL_PTR* grid, double size)
{
    int side = (int)sqrt(size);
    cellDBL_PTR newGrid;
    newGrid = (cellDBL_PTR)malloc(sizeof(cellPTR) * side);
    if (!newGrid) {
        printf("Can't allocate memory.\n");
        exit(1);
    }
    for (int i = 0; i < side; i++) {
        newGrid[i] = (cellPTR)malloc(sizeof(cell) * side);
        if (!newGrid[i]) {
            printf("Can't allocate memory.\n");
            exit(1);
        }
    }

    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            newGrid[i][j].i = i;
            newGrid[i][j].j = j;
            newGrid[i][j].digit = 0;
        }
    }
    *grid = newGrid;
}

void SU_fillGrid(cellDBL_PTR* grid, double size)
{
    srand(time(NULL));

    int side = (int)sqrt(size);
    int arrayMaxIndex = 8;
    int* psifia;
    int counter = 0;

    init_psifia(psifia);

    int sizeOfArray = 9;

    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            while (1) {
                int randomIndex = rand() % (arrayMaxIndex + 1);
                int candidate = psifia[randomIndex];

                if (SU_isInRow(*grid, *grid[i][j])) {
                    deleteElement(psifia, sizeOfArray, candidate);
                    sizeOfArray--;
                    continue;
                }
                if (SU_isInColumn(*grid, *grid[i][j])) {
                    deleteElement(psifia, sizeOfArray, candidate);
                    sizeOfArray--;
                    continue;
                }
                if (SU_isInBlock(*grid, *grid[i][j])) {
                    deleteElement(psifia, sizeOfArray, candidate);
                    sizeOfArray--;
                    continue;
                }

                grid[i][j]->digit = candidate;
                free(psifia);
                init_psifia(psifia);
                break;
            }
        }
    }
}

void deleteElement(int* array, int sizeOfArray, int element)
{
    for (int i = 0; i < 8; i++) {
        if (array[i] = element)
            swap(&array[i], &array[i + 1]);
    }
    realloc(array, sizeof(int) * 8);
    if (!array) {
        printf("Can't reallocate memory.\n");
        exit(1);
    }
}

void swap(int* a, int* b)
{
    int temp;
    temp = *b;
    *b = *a;
    *a = temp;
}

int SU_isInColumn(cellDBL_PTR grid, cell c)
{
    int j = 0;
    while (j < 9) {
        if (j == c.j) {
            j++;
            continue;
        }
        if (grid[c.i][j].digit == c.digit && grid[c.i][j].digit != 0) {
            return TRUE;
        }
        j++;
    }
    return FALSE;
}

int SU_isInRow(cellDBL_PTR grid, cell c)
{
    int i = 0;
    while (i < 9) {
        if (i == c.i) {
            i++;
            continue;
        }
        if (grid[i][c.j].digit == c.digit && grid[i][c.j].digit != 0) {
            return TRUE;
        }
        i++;
    }
    return FALSE;
}

int SU_isInBlock(cellDBL_PTR grid, cell c)
{
    if (c.i < 3) {
        if (c.j < 3) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (i == c.i && j == c.j)
                        continue;
                    if (grid[i][j].digit == c.digit && grid[i][j].digit != 0) {
                        return TRUE;
                    }
                }
            }
        } else if (c.j < 6) {
            for (int i = 0; i < 3; i++) {
                for (int j = 3; j < 6; j++) {
                    if (i == c.i && j == c.j)
                        continue;
                    if (grid[i][j].digit == c.digit && grid[i][j].digit != 0) {
                        return TRUE;
                    }
                }
            }
        } else {
            for (int i = 0; i < 3; i++) {
                for (int j = 6; j < 9; j++) {
                    if (i == c.i && j == c.j)
                        continue;
                    if (grid[i][j].digit == c.digit && grid[i][j].digit != 0) {
                        return TRUE;
                    }
                }
            }
        }
    } else if (c.i < 6) {
        if (c.j < 3) {
            for (int i = 3; i < 6; i++) {
                for (int j = 0; j < 3; j++) {
                    if (i == c.i && j == c.j)
                        continue;
                    if (grid[i][j].digit == c.digit && grid[i][j].digit != 0) {
                        return TRUE;
                    }
                }
            }
        } else if (c.j < 6) {
            for (int i = 3; i < 6; i++) {
                for (int j = 3; j < 6; j++) {
                    if (i == c.i && j == c.j)
                        continue;
                    if (grid[i][j].digit == c.digit && grid[i][j].digit != 0) {
                        return TRUE;
                    }
                }
            }
        } else {
            for (int i = 3; i < 6; i++) {
                for (int j = 6; j < 9; j++) {
                    if (i == c.i && j == c.j)
                        continue;
                    if (grid[i][j].digit == c.digit && grid[i][j].digit != 0) {
                        return TRUE;
                    }
                }
            }
        }
    } else {
        if (c.j < 3) {
            for (int i = 6; i < 9; i++) {
                for (int j = 0; j < 3; j++) {
                    if (i == c.i && j == c.j)
                        continue;
                    if (grid[i][j].digit == c.digit && grid[i][j].digit != 0) {
                        return TRUE;
                    }
                }
            }
        } else if (c.j < 6) {
            for (int i = 6; i < 9; i++) {
                for (int j = 3; j < 6; j++) {
                    if (i == c.i && j == c.j)
                        continue;
                    if (grid[i][j].digit == c.digit && grid[i][j].digit != 0) {
                        return TRUE;
                    }
                }
            }
        } else {
            for (int i = 6; i < 9; i++) {
                for (int j = 6; j < 9; j++) {
                    if (i == c.i && j == c.j)
                        continue;
                    if (grid[i][j].digit == c.digit && grid[i][j].digit != 0) {
                        return TRUE;
                    }
                }
            }
        }
    }
    return FALSE;
}

void SU_printGrid(cellDBL_PTR grid)
{
    printf("\n");
    printf("--------------------\n");
    for (int i = 0; i < 9; i++) {
        printf("| ");
        for (int j = 0; j < 9; j++) {
            printf("%2d |", grid[i][j].digit);
        }
        printf("\n");
    }
}

void init_psifia(int* array)
{
    int* psifia;
    psifia = malloc(sizeof(int) * 9);
    if (!psifia) {
        printf("Can't allocate memory.\n");
        exit(1);
    }

    for (int i = 0; i < 9; i++) {
        psifia[i] = i + 1;
    }
    array = psifia;
}