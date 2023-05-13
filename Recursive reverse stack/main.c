#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "stack.h"

/*
Reverse stack ricorsivo

Specifica
specifica sintattica: rec_rev(stack s)
    dati di input: stack s
    dati di output: (stack s')
specifica semantica: 
    precondizione: lo stack s deve esistere
    postcondizione: s' contiene gli elementi di s invertiti

Progettazione: rec_rev
1. se lo stack non è vuoto
    1.1 inserisci in tp l'elemento al top dello stack s
    1.2 eliminalo da s
    1.3 passo ricorsivo: chiama la funzione rec_rev su s
    1.4 chiama la funzione insert su tp e s

Raffinamento: insert
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

int main(void)
{
    printf("Reverse stack ricorsivo!\n");
    stack s = newStack();
    printf("\nInserisci i dati nello stack (-1 per terminare)\n");
    s = input_stack(s);
    printf("\nstack di partenza\n");
    output_stack(copia_stack(s));

    printf("stack invertito\n");
    rec_rev(s);
    output_stack(s);
}