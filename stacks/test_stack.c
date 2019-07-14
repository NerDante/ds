#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

// simplelest data type
typedef struct {
    int value;
} TestData;

Stack testStack;

void test_destroy(void* data)
{
    TestData* td = (TestData*)data;
    printf("destroy data val = [%d]\n", td->value);
    free(data);
}

int main(int argc, char *argv[])
{
    TestData *td;
    stack_init(&testStack, test_destroy);

    for(int i = 0; i < 5; i++) {
        td = malloc(sizeof(TestData));
        if(td == NULL) {
            printf("malloc fail\n");
            return -1;
        }

        td->value = i*2;
        stack_push(&testStack, td);
        printf("push to stack, value = %d\n", td->value);
    }

    printf("------------------------------\n");
    while (stack_size(&testStack) > 0) {
        td = stack_peek(&testStack);
        printf("peek data from top: %d\n", td->value);
        stack_pop(&testStack, (void **)&td);
        if (td != NULL) {
            free(td);
        }
    }

    return 0;
}

