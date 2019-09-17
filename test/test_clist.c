#include "clist.h"
#include <stdio.h>
#include <stdlib.h>

// simplelest data type
typedef struct {
    int value;
} TestData;

CList testList;

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
    CListElmt* element;

    // init the list
    clist_init(&testList, test_destroy);

    // add element
    for (int i = 0; i < 16; i++) {
        td = malloc(sizeof(TestData));
        if (td == NULL) {
            printf("malloc TestData fail\n");
            continue;
        }

        td->value = i;

        // add in head
        clist_ins_next(&testList, testList.head, td);
    }
    printf("total insert (%d) elements\n\n", clist_size(&testList));

    count = 0;
    // traverse get every element
    for (element = testList.head; element->next != testList.head; element = clist_next(element)) {
        td = (TestData*)element->data;
        printf("count = %04d, TestData.val = [%d]\n", count, td->value);
        count++;
    }

    // destroy the list
    clist_destroy(&testList);

    return 0;
}
