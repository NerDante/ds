#include <stdio.h>
#include <stdlib.h>
#include "bitree.h"

// 插入若干数据，不同的方式进行遍历，验证结果的正确性，

BiTree g_tree;

// simplelest data type
typedef struct {
    int value;
} TestData;

void test_destroy(void* data)
{
    TestData* td = (TestData*)data;
    printf("destroy data val = [%d]\n", td->value);
    free(data);
}

void data_handerler(void *data)
{
    // just print
    TestData* td = (TestData*)data;
    printf("visit data val = [%d]\n", td->value);
}

// 先序遍历（根 - 左 - 右）
void preorder_traverse(BiTreeNode *node, void(handler)(void *data))
{
    if (NULL != node) {
        handler(node->data);
        preorder_traverse(node->left, handler);
        preorder_traverse(node->right, handler);
    }
}

// 中序遍历 (左 - 根 - 右)
void inorder_traverse(BiTreeNode *node, void(handler)(void *data))
{
    if (NULL != node) {
        inorder_traverse(node->left, handler);
        handler(node->data);
        inorder_traverse(node->right, handler);
    }
}

// 后续遍历 （左 - 右 - 根）
void postorder_traverse(BiTreeNode *node, void(handler)(void *data))
{
    if (NULL != node) {
        postorder_traverse(node->left, handler);
        postorder_traverse(node->right, handler);
        handler(node->data);
    }
}

int main(int argc, char const* argv[])
{
    TestData *td;

    bitree_init(&g_tree, test_destroy);

    // inser test data to tree
    // TODO: 如何在只允许在叶子节点插入的情况下，插入多个数据
    for (int i = 0; i < 4; i++) {
        td = malloc(sizeof(TestData));
        if(td == NULL) {
            return -1;
        }
        td->value = i;

        if(i % 2 == 0) {
            bitree_ins_left(&g_tree, g_tree.root, td);
        }
        else {
            bitree_ins_right(&g_tree, g_tree.root, td);
        }
    }
    printf("after insert, tree size = %d\n", g_tree.size);

    //preorder traverse
    printf("preorder traverse:\n");
    preorder_traverse(g_tree.root, data_handerler);

    //inorder traverse
    printf("inorder traverse:\n");
    inorder_traverse(g_tree.root, data_handerler);

    //postorder traverse
    printf("postorder traverse:\n");
    postorder_traverse(g_tree.root, data_handerler);

    return 0;
}
