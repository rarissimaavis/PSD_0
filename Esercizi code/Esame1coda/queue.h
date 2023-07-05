#include "item.h"

typedef struct queue *Queue;

Queue newQueue();
int isEmptyQueue(Queue);
int enqueue(Queue, Item);
Item dequeue(Queue);
void printQueue(Queue);
int presenteQ(Queue, Item el);
Queue xorQ(Queue, Queue);
Queue andDaEl(Queue, Queue, Item el);
void cancFinoItem(Queue, Item el);
void cancDaItem(Queue, Item el);