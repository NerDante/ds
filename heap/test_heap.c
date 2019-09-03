#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "heap.h"

Heap g_heap;

// simplelest data type
typedef struct {
    int value;
} TestData;

void data_destroy(void* data)
{
    TestData* td = (TestData*)data;
    printf("destroy data val = [%d]\n", td->value);
    free(data);
}

int data_compare(const void *key1, const void *key2)
{
    TestData *td1, *td2;

    td1 = (TestData *) key1;
    td2 = (TestData *) key2;

    if(td1->value > td2->value)
        return 1;
    else if(td1->value < td2->value)
        return -1;
    else
        return 0;
}

int main(int argc, char const* argv[])
{
    int i;
    int id[8] = {1,9,6,4,2,3,88,100};
    int ret;
    TestData *td;

    heap_init(&g_heap, data_compare, data_destroy);

    for(i = 0; i < 8; i++)
    {
        heap_insert(&g_heap, (void *)&id[i]);
    }

    while((ret = heap_extract(&g_heap, (void **)&td)) == 0)
    {
        printf("%d ", td->value);
    }
    
    return 0;
}
