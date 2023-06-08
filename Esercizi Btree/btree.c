#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "btree.h"
#include "stack.h"



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


void preOrderit(BTree btree){

	if (isEmptyTree(btree)) return;

	Stack s = newStack();
	push(s, btree);

	while (!isEmptyStack(s)){

		BTree nodo = top(s);

		printf("%s " ,getBTreeRoot(nodo));

		pop(s);

		if(getRight(nodo)) push(s, getRight(nodo));

		if(getLeft(nodo)) push(s, getLeft(nodo));
	}
	printf("\n");
}


int numNodes(BTree btree, int nodes){
	
	int l = 0, r = 0;
	
	
	if (!isEmptyTree(btree)){


		if (!isEmptyTree(getLeft(btree)))
			l = numNodes(getLeft(btree), nodes);

		if (!isEmptyTree(getRight(btree)))
			r = numNodes(getRight(btree), nodes);

		nodes++;
		
		nodes += l + r;

	}


	return nodes;
}

int elemSum(BTree btree){

	int l = 0, r = 0, sum = 0;
	
	
	if (!isEmptyTree(btree)){


		if (!isEmptyTree(getLeft(btree)))
			l = elemSum(getLeft(btree));

		if (!isEmptyTree(getRight(btree)))
			r = elemSum(getRight(btree));

		sum = atoi(getBTreeRoot(btree));
		
		sum += l + r;

	}

	return sum;

}


int depthTree(BTree btree, int depth){

	int l = 0, r = 0;

	if(isEmptyTree(getLeft(btree)) && isEmptyTree(getRight(btree)))
		return 0;

	l = depthTree(getLeft(btree), depth);
	r = depthTree(getRight(btree), depth);

	if (l > r) depth = l + 1; else depth= r + 1;

	return depth; 

}

int count(BTree btree, Item elem){

	int x = 0, tmpl = 0, tmpr = 0;

	if (!isEmptyTree(btree)){

		tmpl = count(getLeft(btree), elem);
		tmpr = count(getRight(btree), elem);

		if (cmpItem(getBTreeRoot(btree), elem) == 0) x++;

		x += tmpl + tmpr;

	}

	return x;
}