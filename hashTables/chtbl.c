#include "chtbl.h"
#include <stdlib.h>

int chtbl_init(CHTbl* htbl, 
               int buckets, 
               int (*h)(const void* key), 
               int (*match)(const void* key1, const void* key2), 
               void (*destroy)(void* data))
{
    htbl->table = malloc(sizeof(List) * buckets);
    if (NULL == htbl->table) {
        return -1;
    }

    for (int i = 0; i < buckets; i++) {
        list_init(&table[i], destroy);
    }

    htbl->h = h;
    htbl->match = match;
    htbl->destroy = destroy;
    htbl->size = 0;
    htbl->buckets = buckets;

    return 0;
}

void chtbl_destroy(CHTbl* htbl)
{
    for (int i = 0; i < htbl->buckets; i++) {
        list_destroy(&htbl->table[i]);
    }

    free(htbl->table);
    memset(htbl, 0, sizeof(CHTbl));
}

int chtbl_insert(CHTbl* htbl, const void* data)
{
    int bucket;
    int ret;
    void* temp = data;

    if (chtbl_lookup(htbl, &temp) == 0) {
        return 1; //do nothing
    }

    bucket = htbl->h(data) % htbl->buckets;
    if (bucket < 0) {
        return -1;
    }

    ret = list_ins_next(&htbl->table[bucket], htbl->table[bucket]->head, data);
    if (ret == 0) {
        htbl->size++;
    }

    return ret;
}

int chtbl_remove(CHTbl* htbl, void** data)
{
    ListElmt *member, *prev = NULL;
    int bucket;

    bucket = htbl->h(*data) % htbl->buckets;

    for (member = htbl->table[bucket]->head; member != NULL; member = list_next(member)) {
        if (htbl->match(*data, list_data(member)) == 0) {
            if (list_rem_next(&htbl->table[bucket], prev, member) == 0) {
                htbl->size--;
                return 0;
            } else {
                return -1;
            }
        }

        prev = member;
    }

    return -1;
}

int chtbl_lookup(const CHTbl* htbl, void** data)
{
    ListElmt* member;
    int bucket;

    bucket = htbl->h(*data) % htbl->buckets;

    for (member = list_head(&htbl->table[bucket]); member != NULL; member = list_next(member)) {
        if (htbl->match(*data, list_data(member)) == 0) {
            *data = list_data(member);
            return 0;
        }
    }

    return -1;
}
