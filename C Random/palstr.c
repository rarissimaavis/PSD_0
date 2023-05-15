#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTR 1000

void palit(char *a);
int palrec(char *a);
int ispalrec(char *a, int i, int n);

int main (void){

    char a[MAXSTR];

    printf("Inserisci una stringa: ");
    scanf("%s", &a[0]);

    palrec(a);

    return 0;
}

void palit (char *a){

    int n, pal = 1;

    n = strlen(a);

    for(int i = 0; i < n/2; i++){

        if (a[i] != a[n-1-i]) pal = 0; 

    }

    if (pal == 1) printf("La stringa %s è palindroma\n", a);
    else if (pal == 0) printf("La stringa %s non è palindroma\n", a);

}

int ispalrec(char *a, int i, int n){

    if (i == n) return 1;

    if (a[i] != a[n]) return 0;

    if (n < i + 1) return ispalrec(a, i+1, n-1);

    return 1;
}



int palrec(char *a){

    int n;

    n = strlen(a);

    if (n == 1) {printf("La stringa %s è palindroma\n", a); return 0;}

    if (ispalrec(a, 0, n-1)) printf("La stringa %s è palindroma\n", a);
    else printf("La stringa %s non è palindroma\n", a);
}
