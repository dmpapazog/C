#include <stdio.h>
#include <stdlib.h>

#include "../Stack/stack.h" //remember to copy the "stack.o" object
#include "que.h"

void QUE_reverse(que* q);

int main()
{

    int choice, element, i;
    que my_que;

    QUE_init(&my_que);

    while (1) {

        system("cls");
        printf("----------------\n");
        printf("Dwste thn epilogh:\n");
        printf("1: Pros8hkh sthn oura\n");
        printf("2: E3agwgh apo thn oura\n");
        printf("3: Ektypwsh ouras\n");
        printf("4: Antistrofh ouras\n");
        printf("5: E3odos\n");
        printf("Epilogh -> ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            fflush(stdin);
            printf("\n\nDwse to stoixeio gia eisagwgh: ");
            scanf("%d", &element);
            if (QUE_enque(&my_que, element)) {
                printf("\n\nEgine h eisagwgh\n");
            } else
                printf("\n\nDen egine h eisagwgh, h stoiva einai gemath!\n");
            break;
        case 2:
            if (QUE_deque(&my_que, &element))
                printf("\n\nEgine h e3agwgh tou %d\n", element);
            else
                printf("\n\nLathos. H oura einai adeia!\n");
            break;
        case 3:
            if (!QUE_print(my_que))
                printf("\n\nDen yparxoun stoixeia sthn oura.\n");
            break;
        case 4:
            if (QUE_empty(my_que))
                printf("\n\nLathos. Adeia oura.\n");
            else {
                QUE_reverse(&my_que);
                printf("\n\nEgine h antistrofh.\n");
            }
            break;
        case 5:
            printf("\n\nBye bye!");
            exit(0);
        default:
            printf("\n\nLathos epilogh.\n");
            break;
        }
        system("pause");
    }
    return 0;
}

void QUE_reverse(que* q)
{
    int x;

    stoiva temp;
    ST_init(&temp);

    while (!QUE_empty(*q)) {
        QUE_deque(q, &x);
        ST_push(&temp, x);
    }

    while (!ST_empty(temp)) {
        ST_pop(&temp, &x);
        QUE_enque(q, x);
    }
}