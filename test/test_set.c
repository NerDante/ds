#include <stdio.h>
#include <stdlib.h>
#include "set.h"

// simplelest data type
typedef struct {
    int value;
} TestData;

Set g_set1, g_set2, g_set3;

void test_destroy(void* data)
{
    TestData* td = (TestData*)data;
    printf("destroy data val = [%d]\n", td->value);
    free(data);
}

int data_match(const void *a, const void *b)
{
    TestData *tda = (TestData *)a;
    TestData *tdb = (TestData *)b;

    return tda->value == tdb->value;
}

void test_data_generate()
{
    int i;
    int a[3] = {1, 2, 3};
    int b[3] = {3, 8, 9};
    int c[5] = {1, 2, 3, 8, 9};

    set_init(&g_set1, data_match, test_destroy);
    for (i = 0; i < 3; i++)
    {
        TestData *data = malloc(sizeof(TestData));
        data->value = a[i];
        set_insert(&g_set1, data);
    }

    set_init(&g_set2, data_match, test_destroy);
    for (i = 0; i < 3; i++)
    {
        TestData *data = malloc(sizeof(TestData));
        data->value = b[i];
        set_insert(&g_set2, data);
    }

    set_init(&g_set3, data_match, test_destroy);
    for (i = 0; i < 5; i++)
    {
        TestData *data = malloc(sizeof(TestData));
        data->value = c[i];
        set_insert(&g_set3, data);
    }

    return;
}

void test_set_print(Set *s, const char *name)
{
    ListElmt *member;
    TestData *data;
    if(list_size(s) == 0)
    {
        printf("%s is empty\n", name);
    }
    //遍历，打印
    printf("************ member of %s ************\n", name);
    for (member = list_head(s); member != NULL; member = list_next(member))
    {
        data = (TestData *) list_data(member);
        printf("%d ", data->value);
    }
    printf("\n\n");
}

int main(int argc, char *argv[])
{
    Set setUnit, setInc, setDiff;
    test_data_generate();

    test_set_print(&g_set1, "g_set1");
    test_set_print(&g_set2, "g_set2");
    test_set_print(&g_set3, "g_set3");

    set_union(&setUnit, &g_set1, &g_set2);
    set_intersection(&setInc, &g_set1, &g_set2);
    set_difference(&setDiff, &g_set1, &g_set2);

    test_set_print(&setUnit, "setUnit");
    test_set_print(&setInc, "setInc");
    test_set_print(&setDiff, "setDiff");

    printf("g_set1 is subset of g_set3? %d\n", set_is_subset(&g_set1, &g_set3));
    printf("setUint is same to g_set3? %d\n", set_is_equal(&setUnit, &g_set3));
    return 0;
}
