#ifndef __BISTREE_H__
#define __BISTREE_H__

#include "bitree.h"

#define            AVL_LFT_HEAVY         1
#define            AVL_BALANCED          0
#define            AVL_RGT_HEAVY        -1

typedef struct AvlNode_ {
    void *data;
    int  hidden;
    int  factor;
} AvlNode;

typedef BiTree BisTree;

// public interface
#define bistree_size(tree) ((tree)->size)

void bistree_init(BisTree *tree, int (*compare)(const void *key1, const void
   *key2), void (*destroy)(void *data));
void bistree_destroy(BisTree *tree);
int bistree_insert(BisTree *tree, const void *data);
int bistree_remove(BisTree *tree, const void *data);
int bistree_lookup(BisTree *tree, void **data);

#endif // __BISTREE_H__
