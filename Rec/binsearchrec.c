#include <stdio.h>
#include <stdlib.h>


int ricerca(int v [], int size, int k);
int recsearch(int v[], int inf, int sup, int k);
void fillarr(int v[], int i);

int main (void){

    int res, i, k;

    printf("Inserire grandezza vettore e numero da cercare: ");
    scanf("%d %d", &i,&k);

    int v[i];

    fillarr(v, i);

    res = recsearch(v, 0, i-1, k);
    
    if (res) printf("%d è presente nel vettore\n", k);
    else printf("%d non è presente nel vettore\n", k);
    



    return 0;
}


int ricerca(int v [], int size, int k){ 
    
    int inf = 0, sup = size-1;
    while (sup >= inf){ 
        int med = (sup + inf ) / 2;
        if (k==v[med])
        return med;
        else if (k>v[med])
                inf = med+1;
        else sup = med-1;
    }
    return 0;
}

int recsearch(int v[], int inf, int sup, int k){

    if (inf > sup) return 0;

    int med = (inf + sup) / 2;

    if (v[med] == k) return 1;

    else if (v[med] > k) return recsearch(v, inf, med - 1, k);

    else if (v[med] < k) return recsearch(v, med + 1, sup, k);

}

void fillarr(int v[], int i){

    int j;

    for (j = 0; j < i; j++){ 
        
        v[j] = j + 1;
        printf("- %d ", v[j]);

    }
    printf("-\n");

}