// Selection sort -> O(n^2)
// NON ADATTIVO

#include <stdio.h>
#include <stdlib.h>

#define LEN 10


int ric_bin(int a[], int size, int elem) {
	
	int found = 0;
	
	while(size) {
		if(elem == a[size/=2]) {
			
			found = 1;
			break;	
		}
		else if(elem >= a[size]) a += size;
	}
	
	return (found ? found : -1) ;
}

void inputArray(int a[], int n) {
	int i;
	for(i = 0; i < n; i++) {
		printf(">> ");
		scanf("%d", &a[i]);
	}
}

//T(n) = O(1)
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//T(n) = O(n) = Omega(1)
void insertSortedArray(int a[], int *n, int val) {
	int i;
	for(i = *n; i > 0 && val < a[i - 1]; i--) {
		a[i] = a[i - 1];
	}
	a[i] = val;
	(*n)++;
}

//T(n) = O(n2) = Omega(n)
void insertionSort(int a[], int n) {
	int i = 1;
	while(i < n)
		insertSortedArray(a, &i, a[i]);
}


//T(n) = Theta(n2)
int bubbleSort(int a[], int n) {
	int i, j;
	int count = 0;
	for(i = 1; i < n; i++)
		for(j = 0; j < n - i; j++) {
			count++;
			if(a[j] > a[j + 1])
				swap(&a[j], &a[j + 1]);
		}
	
	return count;
}

//T(n)= O(n2) = Omega(n)
int adaptiveBubbleSort(int a[], int n) {
	int i, j;
	int count = 0;
	int ordered = 0;
	for(i = 1; i < n && !ordered; i++){//O(n) Omega(1)
		ordered = 1;
		for(j = 0; j < n - i; j++) { //Theta(n)
			count++;
			if(a[j] > a[j + 1]) {
				swap(&a[j], &a[j + 1]);
				ordered = 0;
			}
		
		}
	}
	
	return count;
}

//T(n) = O(n) = Omega(n) = Theta(n)
int getMin(int a[], int n) {
	int minIndex = 0;
	
	int i;
	for(i = 1; i < n; i++) {
		if(a[i] < a[minIndex]) {
			minIndex = i;
		}
	}
	
	return minIndex;
}

//T(n) = Theta(n2)
void selectionSort(int a[], int n) {
	int minIndex;
	int i;
	for(i = 0; i < n - 1; i++) {
		minIndex = getMin(a + i, n - i) + i;//Theta(n)
		swap(&a[i], &a[minIndex]);
	}
}

void printArray(int a[], int n) {
	int i;
	for(i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
}

//T(n)= T(n/2) + c = O(log n)
int ricercaBinariaRicorsiva(int a[], int inf, int sup, int k){
	int center;

	if(inf > sup)
		return -1;
	else{
		center=(sup+inf)/2;
		if(k==a[center])
			return center;
		else if(k < a[center])
			return ricercaBinariaRicorsiva(a,inf,center-1, k);
		else 
			return ricercaBinariaRicorsiva(a,center+1, sup, k);
	}
}

int ricBinRic(int a[], int size, int k){

	return ricercaBinariaRicorsiva(a,0, size-1, k);
}

int main(int argc, char argv[]) {
	int numbers[LEN];
	
	int n = 5, k;	
	inputArray(numbers, n);
	printf("Inserisci il numero da cercare: ");
	scanf("%d", &k);

	printf("Il numero si trova in posizione: %d\n", ricBinRic(numbers,n,k));
	
	printArray(numbers, n);
	
	return 0;
}