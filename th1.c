#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define N 100

/*
	andiamo a creare una tavola hash contenente al max 100 elementi
*/

//funzione Hash tipologia 1 
int h(int k){ // k chiave, N dimensione della tavola

	return k % N;
}

int tester(int valore,int k){
	if(valore == 1){
		return h(k);
	}else{
		printf("valore non valido\n");
		return -1;
	}
}


int main(){

	int scanMenu;
	int variabileMenu = TRUE;

	while(variabileMenu == TRUE){
		printf("Benvenuto nel menu:\n");
		printf("0)exit\n");
		printf("1)inserisci un elemento nella tavola hash\n");
		printf("2)Visualizza la mappatura della tavola\n");
		printf("3)Ricerca di un elemento\n");
		printf("4)test delle funzioni hash (valore)\n");

		scanf("%d", &scanMenu);
		if(scanMenu == 0){
			exit(0);
		}else if(scanMenu == 1){
			printf("1\n");
		}else if(scanMenu == 2){
			printf("2\n");
		}else if(scanMenu == 3){
			printf("3\n");
		}else if(scanMenu == 4){
			printf("4\n");
			int valore,k;
			printf("inserisci il valore della chiave\n");
			scanf("%d", &k);
			printf("Inserisci un numero da 1 a X per scegliere quale funzione testare\n");
			printf("Non possiamo dare informazioni su quale funzione stai scegliendo\n");
			scanf("%d", &valore);
			int res = tester(valore,k);
			printf("valore: %d\n", res);

		}else{
			printf("Scelta non valida\n");
		}

	}


}