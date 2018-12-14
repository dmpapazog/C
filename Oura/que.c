#include <stdio.h>
#include "que.h"

void QUE_init(que* q)
{
    q->start  = -1;
    q->finish = -1;
}

int QUE_empty(que q)
{
    return q.finish == -1;
}

int QUE_full(que q)
{
    return q.start == (q.finish + 1) % QUE_SIZE;
}

int QUE_enque(que* q, element e)
{
    if (QUE_full(*q))
        return FALSE;
    else {
        if (QUE_empty(*q)) {
            q->start  = 0;
            q->finish = 0;
        } else {
            q->finish = (q->finish + 1) % QUE_SIZE;
        }

        q->array[q->finish] = e;
        return TRUE;
    }
}

int QUE_deque(que* q, element* e)
{
    if (QUE_empty(*q))
        return FALSE;
    else {
        *e = q->array[q->start];

        if (q->start == q->finish) {
            q->start  = -1;
            q->finish = -1;
        } else
            q->start  = (q->start + 1) % QUE_SIZE;
        return TRUE;
    }
}

int QUE_print(que q)
{
    if (QUE_empty(q))
        return FALSE;
    else {
        int i = q.start;

        printf("\n\n[ ");
        while (i != q.finish) {
            printf("%2d, ", q.array[i]);
            i = (i + 1) % QUE_SIZE;
        }
        printf("%2d ]\n", q.array[i]);
        return TRUE;
    }
}