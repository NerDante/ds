# 二叉树
二叉树是一种将节点按照层次结构组织起来的数据结构，每个节点最多只有两个与它直接相关联的子节点。
![image](https://github.com/NerDante/ds/blob/master/docs/images/tree-example.jpg)

## 遍历算法
- 先序遍历（preorder traversal）：首先访问根节点，然后是左子节点，最后是右子节点。这是深度优先的方式。
- 中序遍历(inorder traversal)：首先访问左子节点，然后根几点，最后是右子节点。
- 后续遍历(postorder traversal)：首先访问左子节点，然后右子节点，最后是根节点。
- 层级遍历(levle-order traversal)：首先访问树的根，然后依次向下层梳理，按照从左到右的顺序访问每层的节点。运用了广度优先的策略。
![image](https://github.com/NerDante/ds/blob/master/docs/images/tree-traverse.jpg)

## 树的平衡
如果满足树的所有节点都在同一层上，或者所有叶子节点都在最后两层上，且倒数第二层是满的，则这棵树是平衡的。
![image](https://github.com/NerDante/ds/blob/master/docs/images/balance-binary-tree.jpg)


