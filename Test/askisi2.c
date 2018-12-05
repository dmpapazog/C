#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

void removeChar(char *String, char ch);
void swap(char *a, char *b);

int main(int argc, char const *argv[])
{
    char *myString;
    myString = malloc(sizeof(char) * (SIZE + 1));
    if (!myString) {
        printf("Adunamia desmeushs mnhmhs.\n");
        exit(1);
    }

    strcpy(myString, "1230567090");


    // int *intString;
    // intString = malloc(sizeof(int) * 11);
    // if (!intString) {
    //     printf("Adunamia desmeushs mnhmhs.\n");
    //     exit(1);
    // }


    // strcpy(myString, "0123456789");
    printf("Arxika h metablhth einai h: %s, me mege8os %d\n\n", myString, strlen(myString));
    removeChar(myString, '0');

    // for (int i = 0; i < 11; i++)
    //     intString[i] = i;

    // for (int i = 0; i < 11; i++)
    //     printf("Arxika o int: %d\n", intString[i]);

    // printf("\n\n");

    // myString = realloc(myString, sizeof(char) * 11 - 5*sizeof(char));
    // if (!myString) {
    //     printf("Adunamia desmeushs mnhmhs.\n");
    //     exit(1);
    // }
    // myString[6] = '0';

    printf("Meta h metablhth einai h: %s, me mege8os %d\n\n", myString, strlen(myString));

    // intString = realloc(intString, sizeof(int) * 11 - 5*sizeof(int));
    // if (!intString) {
    //     printf("Adunamia desmeushs mnhmhs.\n");
    //     exit(1);
    // }

    // for (int i = 0; i < 7; i++)
    //     printf("Meta o int: %d\n", intString[i]);

    // printf("\n\n");
    

    free(myString);
    // free(intString);

    return 0;
}

void removeChar(char *String, char ch) {
    int i = 0;
    int j = 0;
    int end = strlen(String);

    for (i = 0; i < end; i++) {
        if (String[i] == ch) {
            for (j = i; j < end - 1; j++)
                swap(&String[j], &String[j + 1]);
        end--;
        }
    }

    String = realloc(String, sizeof(char) * end);
    if (!String) {
        printf("Adunamia desmeushs mnhmhs.\n");
        exit(1);
    }
    String[end] = '\0';

}

void swap(char *a, char *b) {
    char temp;
    temp = *b;
    *b = *a;
    *a = temp;
}