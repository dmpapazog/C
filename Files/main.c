#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *list;
    list = fopen("list.txt", "w");
    if (list == NULL) {
        printf("Error in opening file.\n");
        exit(1);
    }

    int i;
    float f = 1.1;
    for (i = 0; i<=10; i++ ) {
        fprintf(list, "%.3f\n", f+(float)i);
    }

    fclose(list);

    return 0;
}