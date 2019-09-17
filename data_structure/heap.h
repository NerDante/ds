#ifndef __HEAP_H__
#define __HEAP_H__

typedef struct Heap_{
    int size;
    int (*compare)(const void *key1, const void * key2);
    void (*destroy)(void *data);

    void **tree;
}Heap;

#define heap_size(heap) ((heap)->size)

void heap_init(Heap *heap, int (*compare)(const void * key1, const void* key2), void (*destroy)(void* data));
void heap_destroy(Heap *heap);
int heap_insert(Heap *heap, const void *data);
int heap_extract(Heap *heap, void **data);

#endif //__HEAP_H__
