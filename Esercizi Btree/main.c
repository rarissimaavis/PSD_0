#include <stdio.h>
#include "btree.h"
#include "item.h"



int main( void ){

	int nodes = 0, depth = 0, x = 0;

	BTree h,a,c,d,l,p,s,o,q;
	/*d=buildTree(NULL,NULL,"d");
	o=buildTree(NULL,NULL,"o");
	q=buildTree(NULL,NULL,"q");
	p=buildTree(NULL,NULL,"p");
	s=buildTree(NULL,NULL,"s");
	l=buildTree(o,q,"l");
	a=buildTree(d,l,"a");
	c=buildTree(p,s,"c");
	h=buildTree(a,c,"h");*/
	d=buildTree(NULL,NULL,"1");
	o=buildTree(NULL,NULL,"2");
	q=buildTree(NULL,NULL,"3");
	p=buildTree(NULL,NULL,"4");
	s=buildTree(NULL,NULL,"5");
	l=buildTree(o,q,"6");
	a=buildTree(d,l,"7");
	c=buildTree(p,s,"8");
	h=buildTree(a,c,"9");
	printf("PREORDER: ");
	preOrder(h);
	printf("\nPOSTORDER: ");
	postOrder(h);
	printf("\nINORDER: ");
	inOrder(h);
	printf("\n");

	nodes = numNodes(h, nodes);
	depth = depthTree(h, depth);
	x = count(h, 2);
	printf("Number of nodes: %d\nTree depth: %d\n" ,nodes, depth);
	
	return 0;
}