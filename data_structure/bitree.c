#include <stdlib.h>
#include <string.h>
#include "bitree.h"

void bitree_init(BiTree *tree, void (*destroy)(void *data))
{
    tree->root = NULL;
    tree->destroy = destroy;
    tree->size = 0;
}

void bitree_destroy(BiTree *tree)
{
    bitree_rem_left(tree, NULL);
    memset(tree, 0, sizeof(BiTree));
}

int bitree_ins_left(BiTree *tree, BiTreeNode *node, const void *data)
{
    BiTreeNode *new;
    BiTreeNode **position;

    if (NULL == node) {
        // allow insertion at the root only in an empty tree
        if(tree->size > 0) {
            return -1;
        }
        position = &tree->root;
    }
    else{
        // normally allow insertion only at the end of branch
        if(node->left != NULL) {
            return -1;
        }
        position = &node->left;
    }

    new = malloc(sizeof(BiTreeNode));
    if(new == NULL){
        return -1;
    }

    new->data = (void *)data;
    new->left = NULL;
    new->right = NULL;
    *position = new;

    tree->size++;

    return 0;
}

int bitree_ins_right(BiTree *tree, BiTreeNode *node, const void *data)
{
    BiTreeNode *new;
    BiTreeNode **position;

    if (NULL == node) {
        // allow insertion at the root only in an empty tree
        if(tree->size > 0) {
            return -1;
        }
        position = &tree->root;
    }
    else{
        // normally allow insertion only at the end of branch
        if(node->right != NULL) {
            return -1;
        }
        position = &node->right;
    }

    new = malloc(sizeof(BiTreeNode));
    if(new == NULL){
        return -1;
    }

    new->data = (void *)data;
    new->left = NULL;
    new->right = NULL;
    *position = new;

    tree->size++;

    return 0;

}

void bitree_rem_left(BiTree *tree, BiTreeNode *node)
{
    BiTreeNode **position;

    if (tree->size == 0) {
        return;
    }

    if (node == NULL) {
        position = &tree->root;
    }
    else {
        position = &node->left;
    }

    if (*position != NULL) {
        // 递归删除
        bitree_rem_left(tree, *position);
        bitree_rem_right(tree, *position);
        if (tree->destroy != NULL) {
            tree->destroy((*position)->data);
        }

        free(*position);
        *position = NULL;

        tree->size --;
    }
}

void bitree_rem_right(BiTree *tree, BiTreeNode *node)
{
    BiTreeNode **position;

    if (tree->size == 0) {
        return;
    }

    if (node == NULL) {
        position = &tree->root;
    }
    else {
        position = &node->right;
    }

    if (*position != NULL) {
        // 递归删除
        bitree_rem_left(tree, *position);
        bitree_rem_right(tree, *position);
        if (tree->destroy != NULL) {
            tree->destroy((*position)->data);
        }

        free(*position);
        *position = NULL;

        tree->size --;
    }
}

int bitree_merge(BiTree *merge, BiTree *left, BiTree *right, const void *data)
{
    bitree_init(merge, left->destroy);

    if (bitree_ins_left(merge, NULL, data) != 0) {
        bitree_destroy(merge);
        return -1;
    }

    //merge
    bitree_root(merge)->left = bitree_root(left);
    bitree_root(merge)->right =  bitree_root(right);

    //ajust the size of the new binary tree
    merge->size = merge->size + bitree_size(left) + bitree_size(right);

    //do not let the original trees acces  the merged nodes
    left->root = NULL;
    left->size = 0;
    right->root = NULL;
    right->size = 0;

    return 0;
}
