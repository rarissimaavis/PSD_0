#include <stdio.h>
#include "btree.h"
#include "item.h"
#include "stack.h"

/*
1. contare i figli unici di un albero
2. dati due stack inserire il secondo stack al centro del primo (il secondo stack deve rimanere invariato)
3. contare i figli sinistri di un albero
4. date due code, eliminare dalla coda 1 gli elementi che non sono presenti nella coda 2
5. Fogliek(Btree T, int k) La funzione conta il numero di foglie (se presenti) al livello k, restituendolo
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
	
//  BTree h,a,c,d,l,p,s,o,q;
    BTree a,b,c,d,e,f,g,h,i;

	
	//e=buildTree(NULL,NULL,"1");
	f=buildTree(NULL,NULL,"6");
	g=buildTree(NULL,NULL,"2");
	h=buildTree(NULL,NULL,"11");
	i=buildTree(NULL,NULL,"14");
	d=buildTree(h,i,"+");
	c=buildTree(f,g,"*");
	b=buildTree(d,NULL,"-");
	a=buildTree(b,c,"/");

/*	d=buildTree(NULL,NULL,"d");
	o=buildTree(NULL,NULL,"o");
	q=buildTree(NULL,NULL,"q");
	p=buildTree(NULL,NULL,"p");
	s=buildTree(NULL,NULL,"s");
	l=buildTree(o,q,"l");
	a=buildTree(d,l,"a");
	c=buildTree(p,s,"c");
	h=buildTree(a,c,"h");
	printf("PREORDER: ");
*/

	n = figliun(a);

	printf("Figli unici: %d\n", n);

	/*
	nodes = numNodes(h, nodes);
	depth = depthTree(h, depth);
	x = count(h, elem);
	y = elemSum(h);
	printf("Number of nodes: %d\nTree depth: %d\nIstances of %s: %d\nSum of elements: %d\n" ,nodes, depth, elem, x, y);
	*/
	
	return 0;
}