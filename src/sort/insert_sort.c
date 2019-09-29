#include <stdlib.h>
#include <string.h>
#include "sort.h"

int insert_sort(void *data, int size, int esize, int (*compare)(const void *key1, const void *key2))
{
    char *a = data;
    void *value;
    int i, j;

    value = malloc(esize);
    if( value == NULL )
    {
        return -1;
    }

    // Repeatedly insert a key element among the sorted elements
    for(i = 1; i < size; i++)
    {
        memcpy(value, &a[i*esize], esize);
        j = i - 1;

        // ascending order
        while (j >= 0 && compare(&a[j*esize], value) > 0)
        {
            memcpy(&a[(j + 1)*esize], &a[j * esize], esize);
            j--;
        }
        memcpy(&a[(j + 1) * esize], value, esize);
    }

    free(value);
    return 0;
}
