#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

struct queue {
    int size,
        front,
        rear,
        *contents;
};

struct queue *queue_init(int size);
void queue_destroy(struct queue *q);
bool queue_is_empty(struct queue *q);
bool queue_is_full(struct queue *q);
void queue_enqueue(struct queue *q, int value);
int queue_dequeue(struct queue *q);
int queue_peek_front(struct queue *q);
int queue_peek_rear(struct queue *q);
void queue_print(struct queue *q);

#endif /* QUEUE_H */
