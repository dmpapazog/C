#include <stdio.h>
#include "stack.h"

void ST_init(stoiva *s) {
    s->top = -1;
}

int ST_empty(stoiva s) {
    return s.top == -1;
}

int ST_full(stoiva s) {
    return s.top == STACK_SIZE - 1;
}

int ST_push(stoiva *s, element elem) {
    if (ST_full(*s))
        return FALSE;
    else {
        s->top++;
        s->array[s->top] = elem;
        return TRUE;
    }
}

int ST_pop(stoiva *s, element *elem) {
    if (ST_empty(*s))
        return FALSE;
    else {
        *elem = s->array[s->top];
        s->top--;
        return TRUE;
    }
}