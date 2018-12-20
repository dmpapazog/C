#include <stdio.h>
#include <stdlib.h>

struct block {
    int i;
};

typedef struct block block;
typedef struct block* blockPTR;

void init_block(blockPTR* b, int size);
void print_blocks(blockPTR b, int size);

int main()
{
    block* my_block;
    int size = 10;

    init_block(&my_block, size);
    print_blocks(my_block, size);

    system("pause");

    return 0;
}

void init_block(blockPTR* b, int size)
{
    blockPTR newBlock;
    newBlock = (blockPTR)malloc(sizeof(block) * size);
    if (!newBlock) {
        printf("Can't allocate memory.\n");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        (&newBlock[i])->i = i;
    }
    *b = newBlock;
}

void print_blocks(blockPTR b, int size)
{
    printf("\n");
    printf("| ");
    for (int i = 0; i < size; i++) {
        printf("%2d| ", b[i].i);
    }
    printf("\n");
}
