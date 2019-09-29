#ifndef __QUEUE_H__
#define __QUEUE_H__
#include "list.h"

// implement queues as linked list
typedef List Queue;

// public intefaces
#define queue_init list_init
#define queue_destroy list_destroy
#define queue_size list_size
#define queue_peek(queue) ((queue)->head == NULL ? NULL : (queue)->head->data)

int queue_enqueue(Queue *queue, const void *data);
int queue_dequeue(Queue *queue, void **data);

#endif // __QUEUE_H__
