#include "list.h"
#include <stdio.h>
#include <stdlib.h>

// simplelest data type
typedef struct {
    int value;
} TestData;

List testList;

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
    ListElmt* element;

    // init the list
    list_init(&testList, test_destroy);

    // add element
    for (int i = 0; i < 16; i++) {
        td = malloc(sizeof(TestData));
        if (td == NULL) {
            printf("malloc TestData fail\n");
            continue;
        }

        td->value = i;

        //// add in head
        list_add_head(&testList, td); // equivalent to list_ins_next(&testList, NULL, td);

        //// add in tail
        //list_add_tail(&testList, td); // equivalent to list_ins_next(&testList, testList.tail, td);
    }
    printf("total insert (%d) elements\n\n", list_size(&testList));

    count = 0;
    // traverse get every element
    for (element = testList.head; element != NULL; element = list_next(element)) {
        td = (TestData*)element->data;
        printf("count = %04d, TestData.val = [%d]\n", count, td->value);
        count++;
    }

    // destroy the list
    list_destroy(&testList);

    return 0;
}
