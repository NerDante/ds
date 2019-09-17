#include "dlist.h"
#include <stdio.h>
#include <stdlib.h>

// simplelest data type
typedef struct {
    int value;
} TestData;

DList testList;

void test_destroy(void* data)
{
    TestData* td = (TestData*)data;
    printf("destroy data val = [%d]\n", td->value);
    free(data);
}

int main(int argc, char* argv[])
{
    int count;
    TestData* td;
    DListElmt* element;

    // init the list
    dlist_init(&testList, test_destroy);

    // add element
    for (int i = 0; i < 16; i++) {
        td = malloc(sizeof(TestData));
        if (td == NULL) {
            printf("malloc TestData fail\n");
            continue;
        }

        td->value = i;

        // add in head
        /*dlist_ins_prev(&testList, testList.head, td);*/

        // add in tail
        dlist_ins_next(&testList, testList.tail, td);
    }
    printf("total insert (%d) elements\n\n", dlist_size(&testList));

    count = 0;
#if 0  // forward traverse get every element
    for (element = testList.head; element != NULL; element = dlist_next(element)) {
        td = (TestData*)element->data;
        printf("count = %04d, TestData.val = [%d]\n", count, td->value);
        count++;
    }
#else // backward traverse
    for (element = testList.tail; element != NULL; element = dlist_prev(element)) {
        td = (TestData*)element->data;
        printf("count = %04d, TestData.val = [%d]\n", count, td->value);
        count++;
    }

#endif

    // destroy the list
    dlist_destroy(&testList);

    return 0;
}
