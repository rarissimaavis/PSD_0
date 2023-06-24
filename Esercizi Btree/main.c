#include <stdio.h>
#include "btree.h"
#include "item.h"
#include "stack.h"

/*
Dato un albero binario in cui è memorizzata un’espressione aritmetica in forma infissa, scrivere una
funzione che risalga all’espressione originale.
Un albero memorizza la forma infissa di un’espressione nel modo seguente, gli operandi sono
inseriti in ordine di apparizione nelle foglie, gli operatori nelle radici.
Spiegare nei commenti il funzionamento dell’algoritmo applicato
*/

int main( void ){

	int nodes = 0, depth = 0, x = 0, y = 0, n = 0;
	Item elem = "a";
/*
	Stack s=newStack();

	for(int i=0;i<5;i++){
		push(s,inputItem(i));
	}

	printStack(s);
	n = RevRecStack(s, 0);
	
	printf("\n");
	printStack(s);
	printf(" %d", n);
*/
	
//	BTree h,a,c,d,l,p,s,o,q;
	BTree a,b,c,d,e,f,g,h,i;
	
	a=buildTree(b,c,"/");
	b=buildTree(d,e,"-");
	c=buildTree(f,g,"*");
	d=buildTree(h,i,"+");
	e=buildTree(NULL,NULL,"1");
	f=buildTree(NULL,NULL,"6");
	g=buildTree(NULL,NULL,"2");
	h=buildTree(NULL,NULL,"11");
	i=buildTree(NULL,NULL,"14");



/*	d=buildTree(NULL,NULL,"d");
	o=buildTree(NULL,NULL,"o");
	q=buildTree(NULL,NULL,"q");
	p=buildTree(NULL,NULL,"p");
	s=buildTree(NULL,NULL,"s");
	l=buildTree(o,q,"l");
	a=buildTree(d,l,"a");
	c=buildTree(p,s,"c");
	h=buildTree(a,c,"h");
	printf("PREORDER: ");*/

	inOrder(a);

	/*
	nodes = numNodes(h, nodes);
	depth = depthTree(h, depth);
	x = count(h, elem);
	y = elemSum(h);
	printf("Number of nodes: %d\nTree depth: %d\nIstances of %s: %d\nSum of elements: %d\n" ,nodes, depth, elem, x, y);
	*/
	
	return 0;
}