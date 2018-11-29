#ifndef QUE_H
#define QUE_H

#define QUE_SIZE 10
#define TRUE 1
#define FALSE 0

typedef int element;

struct que {
    element array[QUE_SIZE];
    int start;
    int finish;
};

typedef struct que que;

void QUE_init(que *q);
int QUE_empty(que q);
int QUE_full(que q);
int QUE_enque(que *q, element e);
int QUE_deque(que *que, element *e);
int QUE_print(que q);

#endif