#include "item.h"
#include "queue.h"
#include <stdio.h>


void presQ(Queue q, int el);
void cancellaFinoEl(Queue q, int el);

int main(void)
{
	Queue q = newQueue();
	Queue w = newQueue();
	
	int i;
	int el=3;

	printf("\nInserire 5 elementi nella prima coda: ");

	for(i=0;i<5;i++){
		enqueue(q, inputItem());
	}
	
	printf("\nInserire 5 elementi nella seconda coda: ");
	
	for(i=0;i<5;i++){
		enqueue(w, inputItem());
	}
	
	printf("\nQueue1: ");
	printQueue(q);
	
	printf("\nQueue2: ");
	printQueue(w);/*

	presQ(q, el);
	
	printf("\nXOR Q1Q2: ");
	Queue p = xorQ(q,w);
	printQueue(p);

	cancellaFinoEl(q, el);*/

	printf("\nAND da %d di Q1Q2", el);
	Queue x = andDaEl(q,w,&el);
	printQueue(x);
	printf("\n");

	return 0;
}


void cancellaFinoEl(Queue q, int el){

	cancFinoItem(q, &el);

	printf("\nQueue da %d in poi: ", el);
	printQueue(q);

}


void presQ(Queue q, int el){

	if(presenteQ(q, &el)) printf("\n%d è presente nella coda\n", el);
	
	else printf("\n%d non è presente nella coda\n", el);

}