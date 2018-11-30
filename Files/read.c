#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const* argv[])
{
    FILE* file;
    file = fopen("list.txt", "r");
    if (file == NULL) {
        printf("Error in opening file.\n");
        exit(1);
    }

    char myString[10];
    float f;

    while (1) {
        fgets(myString, 10, file);
        if (feof(file))
            break;
            
        f = atof(myString);
        printf("%.3f\n", f);
    }

    fclose(file);

    system("pause");

    return 0;
}
