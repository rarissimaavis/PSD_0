#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "stack.h"

int main(void)
{
    printf("Reverse stack ricorsivo\n");
    
    stack s = newStack();
    printf("\nInserisci i dati nello stack (-1 per terminare)\n");
    s = input_stack(s);

    printf("\nstack di partenza\n");
    output_stack(copia_stack(s));

    printf("stack invertito\n");
    rec_rev(s);
    output_stack(s);
}