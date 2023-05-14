#include "item.h"

typedef struct c_stack *stack;

stack newStack(void);
int emptyStack(stack s);
int push(item val, stack s);
int pop(stack s);
item top(stack s);
stack input_stack(stack s);
void output_stack(stack s);
stack copia_stack(stack s);

/*
Specifica
specifica sintattica: rec_rev(stack s)
    dati di input: stack s
    dati di output: (stack s')
specifica semantica: 
    precondizione: lo stack s deve esistere
    postcondizione: s' contiene gli elementi di s invertiti
*/
void rec_rev(stack s);