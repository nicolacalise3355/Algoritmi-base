#include <stdio.h>
#include <stdlib.h>

#define N 5

/*
OVERVIEW:
Algoritmo base, realizzando senza considerare spreco di memoria
e/o avanzo di codice / codice inutile
*/

//algoritmo di ordinamento: tempo caso pessimo -> theta(n^2)
void insertionSort(int *a){
	
	for(int j = 1; j < N; j++){
		int key = a[j];
		int  i = j - 1;
		while(i > 0 && a[i] > key){
			a[i+1] = a[i];
			i = i - 1;

		}
		a[i+1] = key;
	}
	
}


int main(){

	int input;
	int *array = malloc(sizeof(int)*N);

	for(int i = 0; i < N; i++){
		scanf("%d", &input);
		array[i] = input;
	}

	insertionSort(array);


	for(int j = 0; j < N; j++){
		printf("%d\n", array[j]);
	}

}