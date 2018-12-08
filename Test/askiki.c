#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 4
#define SIZE 30

enum typosSunalaghs {
    kata8esh = 1,
    analhpsh = 2,
};

struct sunalages {

    unsigned short int poso;
    enum typosSunalaghs typos;

    char* onomatepwnumo;
};

typedef struct sunalages sunalages;

int timhKataxwrhshs();
void onomaKataxwrhsh(sunalages* s);

int main(int argc, char const* argv[])
{
    sunalages mySunalages[ARRAY_SIZE];
    unsigned short int temp = 0;

    char i = 0;
    char lathosKataxwrhsh;
    int choice;
    while (1) {
        system("cls");
        printf("---------------------------------\n");
        printf("Epile3te ton typo ths sunalaghs:\n");
        printf("1 -> Kata8esh\n");
        printf("2 -> Analhpsh\n");
        printf("3 -> E3odos.\n");
        printf("Epilogh: ");
        fflush(stdin);
        scanf("%d", &choice);
        printf("---------------------------------\n");

        switch (choice) {
        case 1:
            if (i >= ARRAY_SIZE) {
                printf("O pinakas einai gematos\n");
                break;
            }
            mySunalages[i].poso = timhKataxwrhshs();

            onomaKataxwrhsh(&mySunalages[i]);

            mySunalages[i].typos = 1;




            printf("Kataxwrh8hke %s tou posou %d sto onoma %s\n",
                "kata8esh",
                mySunalages[i].poso, mySunalages[i].onomatepwnumo);
            i++;
            break;
        case 2:
            if (i >= ARRAY_SIZE) {
                printf("O pinakas einai gematos\n");
                break;
            }
            mySunalages[i].poso = timhKataxwrhshs();

            onomaKataxwrhsh(&mySunalages[i]);

            mySunalages[i].typos = 2;

            printf("Kataxwrh8hke %s tou posou %d sto onoma %s\n",
                "analhpsh",
                mySunalages[i].poso, mySunalages[i].onomatepwnumo);
            i++;
            break;
        case 3:
            printf("E3odos apo to programma.\n");
            for (int j = 0; j < ARRAY_SIZE; j++)
                free(mySunalages[j].onomatepwnumo);
            exit(0);
        default:
            printf("Lathos kataxwrhsh.\n\n");
        }
        putchar(' ');
        system("pause");
    }

    return 0;
}

int timhKataxwrhshs()
{
    unsigned short int temp = 0;
    int lathosKataxwrhsh = 0;
    do {
        if (lathosKataxwrhsh > 0) {
            printf("To kataxwrh8en poso einai ektos twn epitreptwn oriwn.\n");
            printf("Eisagete neo poso: ");
        } else
            printf("Eisagete to poso: ");
        fflush(stdin);
        scanf("%d", &temp);
        lathosKataxwrhsh++;
    } while (temp < 0 || temp > 32767);

    return temp;
}

void onomaKataxwrhsh(sunalages* s)
{
    printf("Eisagete to onomatepwnumo: ");
    s->onomatepwnumo = (char*)malloc(sizeof(char) * SIZE);
    if (s->onomatepwnumo == NULL) {
        printf("Provlhma deumeushs mnhmhs.");
        exit(1);
    }
    fflush(stdin);
    gets(s->onomatepwnumo);
}