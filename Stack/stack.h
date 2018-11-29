#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

#define STACK_SIZE 100
#define TRUE 1
#define FALSE 0

typedef int element;

struct stoiva {
    element array[STACK_SIZE];
    int top;
};

typedef struct stoiva stoiva;

void ST_init(stoiva *s);
int ST_empty(stoiva s);
int ST_full(stoiva s);
int ST_push(stoiva *s, element elem);
int ST_pop(stoiva *s, element *elem);

#endif