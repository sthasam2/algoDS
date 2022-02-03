#include <stdio.h>
#include <stdlib.h>
#include "array_queue.h"


struct queue *queue_init(int size)
{
    struct queue *q = malloc(sizeof(struct queue));
    if (q == NULL)
        return NULL;
    q->contents = malloc(sizeof(int) * size);
    if (q->contents == NULL)
        return NULL;
    q->size = size;
    q->front = -1;
    q->rear = -1;
    return q;
} /* end function queue_init */

void queue_destroy(struct queue *q)
{
    free(q->contents);
    free(q);
} /* end function queue_destroy */

bool queue_is_empty(struct queue *q)
{
    return q->front == q->rear;
} /* end function queue_is_empty */

bool queue_is_full(struct queue *q)
{
    return q->rear == q->size - 1;
} /* end function queue_is_full */

void queue_enqueue(struct queue *q, int value)
{
    if (queue_is_full(q)) {
        puts("Queue overflow!");
        return;
    }
    q->contents[++q->rear] = value;
} /* end function queue_enqueue */

int queue_dequeue(struct queue *q)
{
    if (queue_is_empty(q)) {
        puts("Queue underflow!");
        return -1;
    }
    return q->contents[++q->front];
} /* end function queue_dequeue */

int queue_peek_rear(struct queue *q)
{
    if (queue_is_empty(q)) {
        puts("Queue underflow!");
        return -1;
    }
    return q->contents[q->rear];
} /* end function queue_peek_rear */

int queue_peek_front(struct queue *q)
{
    if (queue_is_empty(q)) {
        puts("Queue underflow!");
        return -1;
    }
    return q->contents[q->front + 1];
} /* end function queue_peek_front */

void queue_print(struct queue *q)
{
    for (int i = 0; i <= q->rear; i++) {
        printf("%d ", q->contents[i]);
    }
    puts("");
} /* end function queue_print */
