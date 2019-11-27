#include <stdio.h>
#include "sort.h"

int unsortedData[10] = {9,0,3,2,5,6,8,1,4,7};

static int compare(const void *key1, const void *key2)
{
    int *data1;
    int *data2;

    data1 = (int *)key1;
    data2 = (int *)key2;

    if(*data1 > *data2)
    {
        return 1;
    }
    else if(*data1 == *data2)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

static void print_data(char *descp)
{
    printf("********     %s    **********\n", descp);
    for(int i = 0; i < 10; i++)
    {
        printf("%d ", unsortedData[i]);
    }
    printf("\n\n");
}

int main(int argc, char const* argv[])
{
    int ret;

    print_data("original data");

    // insert sort
    // ret = insert_sort(unsortedData, 10, sizeof(int), compare);

    // quick sort
    ret = quick_sort(unsortedData, sizeof(int), 0, 9,compare);
    if(ret < 0)
    {
        printf("insert sort failed!!\n");
        return -1;
    }
    print_data("after insert sort");
    
    return 0;
}
