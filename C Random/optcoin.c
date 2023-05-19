#include <stdio.h>

int min(int a, int b);
void printmatrix(int m, int V, int M[m][V]);

int main(void){

    int m[4][7];
    int i, v, tmp;
    int coin[4]={0,1,2,4};

    for (i=1; i<=3; i++){
        
        m[i][0] = 0;
    }

    for (v=1; v<=6; v++){
        
        m[1][v] = v;
    }
    
    for (v=0; v<=6; v++){
        
        m[0][v] = 10000;
    }
    
    
    for (i=1; i<=3; i++){
        
        for (v=1; v<=6; v++){
            
            if (v < coin[i]){

                m[i][v] = m[i-1][v];
            }
            else {

                m[i][v] = min( (1+m[i][v - coin[i]]), m[i-1][v]);
            }
        }
    }

    printmatrix(i, v, m);

    printf("min: %d\n", m[i-1][v-1]);

    return 0;
}

int min(int a, int b){

    if (a < b) return a;
    else return b;
}

void printmatrix(int m, int V, int M[m][V]){
	
    for (int i = 0; i < m; i++){

		printf("%d  ", i);
		for (int j = 0; j < V; j++)
		{
			printf("%d ", M[i][j]);
		}
		printf("\n");
	}
}