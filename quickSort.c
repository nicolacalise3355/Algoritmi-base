#include<stdio.h>
#include<stdlib.h>

#define N 5

void swap(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int *a, int p, int r){
	int x = a[r];
	int i = p - 1;
	for(int  j = p; j < r; j++){
		if(a[j] <= x){
			i++;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1],&a[r]);
	return i+1;
}

void qs(int *a, int p, int r){

	if(p<r){
		int q = partition(a,p,r);
		qs(a,p,q-1);
		qs(a,q+1,r);
	}

}


//nel main viene testato l'algoritmo su 5 elementi inseriti da input
int main(){

int input;
int *array = malloc(sizeof(int)*N);

for(int i = 0; i < N; i++){

	scanf("%d", &input);
	array[i] = input;
}

qs(array,0,N-1);

for(int y = 0; y < N; y++){
	printf("%d\n", array[y]);
}



}