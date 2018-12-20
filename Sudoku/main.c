#include <stdio.h>
#include <stdlib.h>
#include "Sudoku.h"

int main(int argc, char const* argv[])
{

    cellDBL_PTR grid;
    SU_init(&grid, SIZE);

    SU_fillGrid(&grid, SIZE);

    SU_printGrid(grid);

    printf("\n\n");
    system("pause");

    return 0;
}