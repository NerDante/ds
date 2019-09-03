#ifndef __PQUEUE_H__
#define __PQUEUE_H__

#include "heap.h"
typedef Heap pQueue;

#define pqueue_init heap_init
#define pqueue_destroy heap_destroy
#define pqueue_insert heap_insert
#define pqueu_extract heap_extract
#define pqueue_size heap_size
#define pqueue_peek(pqueue) ((pqueue)->tree == NULL ? NULL : (pqueue)->tree[0])

#endif /* end of include guard */
