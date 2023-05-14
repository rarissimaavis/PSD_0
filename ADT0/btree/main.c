#include <stdio.h>
#include "btree.h"
#include "item.h"



int main( void )
{
	BTree h,a,c,d,l,p,s,o,q;
	d=buildTree(NULL,NULL,"d");
	o=buildTree(NULL,NULL,"o");
	q=buildTree(NULL,NULL,"q");
	p=buildTree(NULL,NULL,"p");
	s=buildTree(NULL,NULL,"s");
	l=buildTree(o,q,"l");
	a=buildTree(d,l,"a");
	c=buildTree(p,s,"c");
	h=buildTree(a,c,"h");
	printf("PREORDER: ");
	preOrder(h);
	printf("\nPOSTORDER: ");
	postOrder(h);
	printf("\nINORDER: ");
	inOrder(h);
	
	return 0;
}