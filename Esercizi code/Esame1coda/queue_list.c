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