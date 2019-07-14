#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "queue.h"

// simplelest data type
typedef struct {
    int value;
} TestData;

Queue testQueue;

void test_destroy(void* data)
{
    TestData* td = (TestData*)data;
    printf("destroy data val = [%d]\n", td->value);
    free(data);
}

int main(int argc, char *argv[])
{
    TestData *td;
    queue_init(&testQueue, test_destroy);

    for(int i = 0; i < 5; i++) {
        td = malloc(sizeof(TestData));
        if(td == NULL) {
            printf("malloc fail\n");
            return -1;
        }

        td->value = i*2;
        queue_enqueue(&testQueue, td);
        printf("push to queue, value = %d\n", td->value);
    }

    printf("------------------------------\n");
    while (queue_size(&testQueue) > 0) {
        td = queue_peek(&testQueue);
        printf("peek data from queue: %d\n", td->value);
        queue_dequeue(&testQueue, (void **)&td);
        if (td != NULL) {
            free(td);
        }
    }

    return 0;
}

