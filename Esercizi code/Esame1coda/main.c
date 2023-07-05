#include "item.h"
#include "queue.h"
#include <stdio.h>

void presQ(Queue q, int el);
void xorQueue(Queue q, Queue w);
void andDaElement(Queue q, Queue w, int el);
void cancellaFinoEl(Queue q, int el);
void cancellaDaEl(Queue q, int el);

int main(void)
{
	Queue q = newQueue();
	Queue w = newQueue();
	
	int i;
	int el;

	printf("\nInserire 5 elementi nella prima coda: ");

	for(i=0;i<5;i++){
		enqueue(q, inputItem());
	}
	
	printf("\nInserire 5 elementi nella seconda coda: ");
	
	for(i=0;i<5;i++){
		enqueue(w, inputItem());
	}

	printf("\nInserire elemento: ");
	scanf("%d", &el);
	
	printf("\nQueue1: ");
	printQueue(q);

	
	printf("\nQueue2: ");
	printQueue(w);

	presQ(q, el);

	xorQueue(q, w);
	
	andDaElement(q, w, el);

	/*
	cancellaFinoEl(q, el);     //  <--
                               //     |Si possono usare esclusivamente 
 	cancellaDaEl(q, el);	   //  <--	   
	*/

	printf("\n");

	return 0;
}

void andDaElement(Queue q, Queue w, int el){

	printf("\nAND da %d di Q1Q2: ", el);
	Queue x = andDaEl(q,w,&el);
	printQueue(x);

}


void xorQueue(Queue q, Queue w){

	printf("\nXOR Q1Q2: ");
	Queue p = xorQ(q,w);
	printQueue(p);

}


void cancellaFinoEl(Queue q, int el){

	cancFinoItem(q, &el);

	printf("\nQueue da %d in poi: ", el);
	printQueue(q);

}

void cancellaDaEl(Queue q, int el){

	cancDaItem(q, &el);

	printf("\nQueue prima di %d: ", el);
	printQueue(q);

}

void presQ(Queue q, int el){

	if(presenteQ(q, &el)) printf("\n%d è presente nella coda", el);
	
	else printf("\n%d non è presente nella coda", el);

}