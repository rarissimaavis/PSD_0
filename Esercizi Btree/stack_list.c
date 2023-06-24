#include "stack.h"
#include "list.h"
#include "item.h"
#include <stdlib.h>
#include <stdio.h>

struct stack{
    List l;
};

Stack newStack(){
    Stack s=malloc(sizeof(struct stack));
    s->l=newList();
    return s;
}

int isEmptyStack(Stack s){
    return isEmpty(s->l);
} 

int push(Stack s, Item a){
    addHead(s->l,a);
    return 1;
} 

int pop(Stack s){
    if (removeHead(s->l)==NULL)
        return 0;
    else
        return 1;
} 

Item top(Stack s){
    return getHead(s->l);
} 

void printStack(Stack s){
    printList(s->l);
}

void Insert(Stack s, Item tp){

    if (!isEmptyStack(s)){
        Item a;
        a = top(s);
        pop(s);
        Insert(s, tp);
        push(s, a);
    }
    else push(s, tp);
}

int RevRecStack(Stack s, int n){


    if (!isEmptyStack(s)){
        
        n++;

        Item tp = top(s);
        pop(s);
        n = RevRecStack(s, n);
        Insert(s, tp);

    }

    return n;
}