//chined hash table
#ifndef __CHTBL_H__
#define __CHTBL_H__

#include "../linkLists/list.h"

typedef struct CHTBL_ {
    int buckets;

    int (*h)(const void *key);
    int (*match)(const void *key1, const void *key2);
    void (*destroy)(void *data);

    List *table;
}CHtbl;

#define chtbl_size(htbl) ((htbl)->size)
int chtbl_init(CHTbl *htbl, int buckets, int (*h)(const void *key), int
   (*match)(const void *key1, const void *key2), void (*destroy)(void *data));
void chtbl_destroy(CHTbl *htbl);
int chtbl_insert(CHTbl *htbl, const void *data);
int chtbl_remove(CHTbl *htbl, void **data);
int chtbl_lookup(const CHTbl *htbl, void **data);

#endif //__CHTBL_H__
