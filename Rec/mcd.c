#include <stdio.h>


int mcdrec(int a, int b);
int mcdit(int a, int b);

int main (void){

    int a, b, c;

    printf("Inserisci due interi: ");
    scanf("%d %d", &a, &b);
    
    c = mcdrec(a, b);

    printf("Il massimo comun divisore è: %d\n", c);

    return 0;
}


int mcdrec(int a, int b){

    int r, fin;

    if (b == 0) return a;

    r = a%b;

    if (r == 0) return b;

    else  return fin = mcdrec(b,r);

}

int mcdit(int a, int b) {
  
  int t;

  while (b != 0) {
    t = b;
    b = a % b;
    a = t;
  }

  return a;
}