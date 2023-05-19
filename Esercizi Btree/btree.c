#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "btree.h"



struct node
{
	Item value;
	struct node *left;
	struct node *right;
};


BTree newTree()
{
	return NULL;
}


int isEmptyTree(BTree btree)
{
	if(btree==NULL)
		return 1;
	else 
		return 0;
}

BTree buildTree(BTree left, BTree right, Item value)
{
	BTree btree=malloc(sizeof(struct node));
	btree->left=left;
	btree->right=right;
	btree->value=value;
	return btree;
}

Item getBTreeRoot(BTree btree)
{
	if(isEmptyTree(btree))
		return NULL;
	else 
		return btree->value;
}

BTree getLeft(BTree btree)
{
	if(isEmptyTree(btree))
		return NULL;
	else 
		return btree->left;
}

BTree getRight(BTree btree)
{
	if(isEmptyTree(btree))
		return NULL;
	else
		return btree->right;
}

void preOrder(BTree btree)
{
	if(!isEmptyTree(btree))
	{
		outputItem(btree->value);
		preOrder(btree->left);
		preOrder(btree->right);
	}
}

void postOrder(BTree btree)
{
	if(!isEmptyTree(btree))
	{
		postOrder(btree->left);
		postOrder(btree->right);
		outputItem(btree->value);
	}
}

void inOrder(BTree btree)
{
	if(!isEmptyTree(btree))
	{
		inOrder(btree->left);
		outputItem(btree->value);
		inOrder(btree->right);
	}
}

int numNodes(BTree btree, int nodes, int depth){
	
	int l = 0, r = 0;
	
	
	if (!isEmptyTree(btree)){

		depth++;

		if (!isEmptyTree(getLeft(btree)))
			l = numNodes(getLeft(btree), nodes, depth);

		if (!isEmptyTree(getRight(btree)))
			r = numNodes(getRight(btree), nodes, depth);

		nodes++;
		
		nodes += l + r;

	}


	return nodes;
}
