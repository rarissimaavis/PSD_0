#include "item.h"

typedef struct node *BTree;

BTree newTree();
int isEmptyTree(BTree);
BTree buildTree(BTree, BTree, Item);
Item getBTreeRoot(BTree);
BTree getLeft(BTree);
BTree getRight(BTree);
void preOrder(BTree);
void postOrder(BTree);
void inOrder(BTree);


int numNodes(BTree, int nodes);
int depthTree(BTree, int depth);
void preOrderit(BTree);
void postOrderit(BTree);
void inOrderit(BTree);
void preOrderec(BTree);
void postOrderec(BTree);
void inOrderec(BTree);
void levelOrder(BTree);