#include <stdio.h>
#include <stdlib.h>

#define N 5

//l'algoritmo restituisce 1 se e stato trovato, -1 altrimenti

int bs(int *a,int p, int r, int k){

	if(p>r){return -1;}
	if(p == r){
		if(a[p] == k){
			return 1;
		}else{
			return -1;
		}
	}
	int q = (p+r)/2;
	if(a[q] == k){
		return 1;
	}
	else if(a[q] < k){
		return bs(a,q+1,r,k);
	}else if(a[q] > k){
		return bs(a,p,q-1,k);
	}

}



int main(){

	int input,element;
	int *array = malloc(sizeof(int)*N);

	for(int i = 0; i < N; i++){
		scanf("%d", &input);
		array[i] = input;
	}

	printf("Inserisci l'elemento da cercare\n");

	scanf("%d", &element);

	int res = bs(array, 0, N, element);
	printf("risultato = %d\n", res);

}