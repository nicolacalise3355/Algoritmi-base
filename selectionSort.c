#include <stdio.h>
#include <stdlib.h>

#define N 5



/*
OVERVIEW:
Algoritmo base, realizzando senza considerare spreco di memoria
e/o avanzo di codice / codice inutile
*/

void swap(int array[], int aPos, int bPos){
	int tmp = array[aPos];
	array[aPos] = array[bPos];
	array[bPos] = tmp;
}

//algoritmo di ordinamento: temp caso pessimo -> theta(n^2)
void selectionSort(int *a){

	for(int i = 0; i < N-1; i++){
		int min = i;
		for(int j = i + 1; j < N; j++){
			if(a[j] < a[min]){
				min = j;
			}
		}
		swap(a,i,min);
	}

}

int main(){

	int input;
	int *array = malloc(sizeof(int)*N);

	for(int i = 0; i < N; i++){
		scanf("%d", &input);
		array[i] = input;
	}

	selectionSort(array);


	for(int j = 0; j < N; j++){
		printf("%d\n", array[j]);
	}

}