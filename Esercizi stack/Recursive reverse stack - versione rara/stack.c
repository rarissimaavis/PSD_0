#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "stack.h"

struct node
{
    item value;
    struct node *next;
};

struct c_stack
{
    struct node *top;
    int numel;
};

stack newStack(void)
{
    stack s;
    s = malloc(sizeof(struct c_stack));
    if (s == NULL)
    {
        return NULL;
    }
    s->numel = 0;
    s->top = NULL;
    return s;
}

int emptyStack(stack s)
{
    return s->numel == 0;
}

int push(item val, stack s)
{
    struct node *nuovo;
    nuovo = malloc(sizeof(struct node));
    if (nuovo == NULL)
    {
        return 0;
    }
    nuovo->value = val;
    nuovo->next = s->top;
    s->top = nuovo;
    (s->numel)++;
    return 1;
}

int pop(stack s)
{
    if (s->numel == 0)
    {
        return 0;
    }
    struct node *temp;
    temp = s->top;
    s->top = s->top->next;
    free(temp);
    (s->numel)--;
    return 1;
}

item top(stack s)
{
    item e;
    if (s->numel > 0)
    {
        e = s->top->value;
    }
    else
    {
        e = NULLITEM;
    }
    return e;
}

stack input_stack(stack s)
{
    int x;
    input_item(&x);
    while (x != -1)
    {
        push(x, s);
        input_item(&x);
    }
    return s;
}

void output_stack(stack s)
{
    while (!emptyStack(s))
    {
        output_item(top(s));
        printf("\n");
        pop(s);
    }
    printf("\n");
}

stack copia_stack(stack s)
{
    stack copia, tmp;
    copia = newStack();
    tmp = newStack();
    while (!emptyStack(s))
    {
        push(top(s), tmp);
        pop(s);
    }
    while(!emptyStack(tmp))
    {
        push(top(tmp), copia);
        push(top(tmp), s);
        pop(tmp);
    }
    free(tmp);
    return copia;
}

/*
Progettazione: rec_rev
1. se lo stack non è vuoto
    1.1 inserisci in tp l'elemento al top dello stack s
    1.2 eliminalo da s
    1.3 passo ricorsivo: chiama la funzione rec_rev su s
    1.4 chiama la funzione insert su tp e s

Progettazione: insert
1. caso base: se lo stack è vuoto inserisci tp
2. altrimenti:
    2.1 inserisci in a l'elemento al top dello stack s
    2.2 eliminalo da s
    2.3 passo ricorsivo: chiama la funzione insert su tp e s
    2.4 inserisci a in s
*/

void insert(item tp, stack s)
{
    if (emptyStack(s))
    {
        push(tp, s);
    }
    else
    {
        item a = top(s);
        pop(s);
        insert(tp, s);
        push(a, s);
    }
}

void rec_rev(stack s)
{
    if (!emptyStack(s))
    {
        item tp = top(s);
        pop(s);
        rec_rev(s);
        insert(tp, s);
    }
}