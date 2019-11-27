#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int compare_int(const void* int1, const void* int2)
{
    // compare two integers(used during median-of-three partitoning)
    if (*(const int*)int1 > *(const int*)int2)
        return 1;
    else if (*(const int*)int1 < *(const int*)int2)
        return -1;
    else
        return 0;
}

static int partition(void* data, int esize, int i, int k, int (*compare)(const void* key1, const void* key2))
{
    char* a = data;
    void *pval, *temp;
    int r[3];

    // allocate storage for the patition vallue and swapping.
    if ((pval = malloc(esize)) == NULL)
        return -1;

    if ((temp = malloc(esize)) == NULL) {
        free(pval);
        return -1;
    }

    // use the median-of-three method to find partition value.
    r[0] = (rand() % (k - i + 1)) + i;
    r[1] = (rand() % (k - i + 1)) + i;
    r[2] = (rand() % (k - i + 1)) + i;
    insert_sort(r, 3, sizeof(int), compare_int);
    memcpy(pval, &a[r[1] * esize], esize);

    // create two partitions around the partiton value.
    i--;
    k++;
    while (1) {
        // move left until and element is found in the wrong partiton.
        do {
            k--;
        } while (compare(&a[k * esize], pval) > 0);

        // move left until and element is found in the wrong partiton.
        do {
            i++;
        } while (compare(&a[i * esize], pval) < 0);

        if (i >= k) {
            break;
        } else {
            // swap the elements now under the left and right counters
            memcpy(temp, &a[i * esize], esize);
            memcpy(&a[i * esize], &a[k * esize], esize);
            memcpy(&a[k * esize], temp, esize);
        }
    }

    return k;
}

int quick_sort(void* data, int esize, int start, int end, int (*compare)(const void* key1, const void* key2))
{
    int j;

    while (start < end) {
        // determine where to partiton the elements
        if ((j = partition(data, esize, start, end, compare)) < 0) {
            printf("partition fail\n");
            return -1;
        }

        // recursively sort the left partition
        if (quick_sort(data, esize, start, j, compare) < 0) {
            printf("quick sort fail\n");
            return -1;
        }

        // iterate and sort the right partiton
        start = j + 1;
    }
    return 0;
}
