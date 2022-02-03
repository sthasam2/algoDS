#include <stdio.h>
#include "array_queue.h"

int main(void)
{
    struct queue *q = queue_init(5);
    printf("Queue size: %d\n", q->size);

    queue_enqueue(q, 1);
    queue_enqueue(q, 2);
    queue_enqueue(q, 3);
    queue_enqueue(q, 4);
    queue_enqueue(q, 5);
    queue_enqueue(q, 7);

    printf("%s: ", "Queue");
    queue_print(q);

    printf("Front: %d\n", queue_peek_front(q));
    printf("Rear: %d\n", queue_peek_rear(q));

    printf("%d ",queue_dequeue(q));
    printf("%d ",queue_dequeue(q));
    printf("%d ",queue_dequeue(q));
    printf("%d ",queue_dequeue(q));
    printf("%d ",queue_dequeue(q));
    puts("");

    queue_destroy(q);
    return 0;
} /* end function main */
