#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
#include "list.h"
#include "item.h"

struct queue
{
	List l;
};

Queue newQueue()
{
	Queue q = malloc(sizeof(struct queue));
	q->l = newList();
	return q;
}

int isEmptyQueue(Queue q)
{
	return isEmpty(q->l);
}

int enqueue(Queue q, Item item)
{
	return addListTail(q->l, item);
}

Item dequeue(Queue q)
{
	return removeHead(q->l);
}

void printQueue(Queue q)
{
	printList(q->l);
}

int presenteQ(Queue q, Item el){

	Item a[20];

	int flag = 0,index = 0;

	while(!isEmptyQueue(q)){
		a[index] = dequeue(q);
		index++;
	}
	
	for(int i = 0; i < index; i++){
		if(cmpItem(a[i],el)==0) flag = 1;
		enqueue(q,a[i]);
	}

	return flag;
}

Queue xorQ(Queue q, Queue w){

	Item a[20], b[20];

	Queue p = newQueue();
	int flag = 0,index1 = 0, index2 = 0;

	while(!isEmptyQueue(q)){
		a[index1] = dequeue(q);
		index1++;
	}

	while(!isEmptyQueue(w)){
		b[index2] = dequeue(w);
		index2++;
	}


	for(int i = 0; i < index1; i++){
		
		for(int j = 0; j < index2; j++){

			if(cmpItem(a[i],b[j])==0) flag = 1;
		}
		if(flag == 0) enqueue(p, a[i]);
		else flag = 0; 
	}

	for(int i = 0; i < index2; i++){
		
		for(int j = 0; j < index1; j++){

			if(cmpItem(b[i],a[j])==0) flag = 1;
		}
		if(flag == 0) enqueue(p, b[i]);
		else flag = 0; 
	}
	
	for(int i = 0; i < index1; i++) enqueue(q, a[i]);
	for(int j = 0; j < index2; j++) enqueue(w, b[j]);

	return p;
}

void cancFinoItem(Queue q, Item el){

	Item a[20];

	int flag = 0,index = 0;

	while(!isEmptyQueue(q)){
		a[index] = dequeue(q);
		index++;
	}
	
	for(int i = 0; i < index; i++){
		if(cmpItem(a[i],el)==0) flag = 1;
		
		if(flag==1)enqueue(q,a[i]);
	}

}

Queue andDaEl(Queue q, Queue w, Item el){

	Item a[20], b[20];
	int i, j;

	Queue p = newQueue();
	int flag = 0, flagEl = 0, index1 = 0, index2 = 0;

	while(!isEmptyQueue(q)){
		a[index1] = dequeue(q);
		index1++;
	}

	while(!isEmptyQueue(w)){
		b[index2] = dequeue(w);
		index2++;
	}

	for(int i = 0; i < index1; i++) enqueue(q, a[i]);
	for(int j = 0; j < index2; j++) enqueue(w, b[j]);

	for(i = 0; i < index1; i++){
		if(cmpItem(a[i],el) == 0) break;
	}
	for(j = 0; j < index2; j++){
		if(cmpItem(b[j],el) == 0) break;
	}


	for(int ii = i; ii < index1; ii++){
		
		for(int jj = j; jj < index2; jj++){

			if(cmpItem(a[ii],b[jj]) == 0) flag = 1;
		}
		if(flag == 1){
			enqueue(p, a[ii]);
			flag = 0;
		}
	}
	

	return p;
}

void cancDaItem(Queue q, Item el){

	Item a[20];

	int flag = 0,index = 0;

	while(!isEmptyQueue(q)){
		a[index] = dequeue(q);
		index++;
	}
	
	for(int i = 0; i < index; i++){
		if(cmpItem(a[i],el)==0) flag = 1;
		
		if(flag==0)enqueue(q,a[i]);
	}

}

void estraiMaxN(Queue q, int n){

	Item check[20], a[n], b[20], max;
	int index = 0, index1 = 0, index2 = 0;

	while(!isEmptyQueue(q)){
		check[index1] = dequeue(q);
		index1++;
	}

	for(int i = 0; i < index1; i++) enqueue(q, check[i]);

	if(n > index1){printf("\nErrore: n deve essere al massimo la grandezza della coda\n"); return;}

	for(int i=0; i < n; i++){
		a[i] = dequeue(q);
	}

	max = a[0];

	while(!isEmptyQueue(q)){
		b[index2] = dequeue(q);
		index2++;
	}

	for(int i=1; i < n; i++){

		if(cmpItem(a[i],max)>0) {
			max = a[i];
			index = i;
		}
	}

	for(int i=0; i < n; i++) if(i!=index) enqueue(q,a[i]);
	
	for(int j=0; j < index2; j++) enqueue(q, b[j]);
}


void inserMinN(Queue q, int n, Item el){

	Item check[20], a[n], b[20], min;
	int index = 0, index1 = 0, index2 = 0, act;

	while(!isEmptyQueue(q)){
		check[index1] = dequeue(q);
		index1++;
	}

	for(int i = 0; i < index1; i++) enqueue(q, check[i]);

	if(n > index1){printf("\nErrore: n deve essere al massimo la grandezza della coda\n"); return;}

	act = index1 - n;

	for(int i=0; i < act; i++){
		b[i] = dequeue(q);
	}

	while(!isEmptyQueue(q)){
		a[index2] = dequeue(q);
		index2++;
	}
	min = a[0];

	for(int i=1; i < index2; i++){

		if(cmpItem(a[i],min)<0) {
			min = a[i];
			index = i;
		}
	}

    for(int j=0; j < act; j++) enqueue(q, b[j]);

	for(int i=0; i < n; i++){

		if(i==index) enqueue(q,el);
		
		enqueue(q,a[i]);
	}
}