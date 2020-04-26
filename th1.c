#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define N 100

/*
	andiamo a creare una tavola hash contenente al max 100 elementi

	inseriremo piu tipologie di funzioni hash 


*/
//ricorda che non puoi inizializzare nelle struct
struct dato{

	int key;
	char *name; //rappresenta il nome di una persona , inteso come nome utente generico

};

//funzione Hash tipologia 1 
int h(int k){ // k chiave, N dimensione della tavola

	return k % N;
}

//funzione Hash tipologia 2
int hh(int k,int val){
	int i = val; //dovra essere un numero casuale tra 1 e N ma per ora assumiamo sia 0, sistemero la funzione dopo 
	int intermedio = h(k);
	int result = (intermedio + i) % N;
	return result;
}


int tester(int valore,int k){
	if(valore == 1){
		return h(k);
	}else{
		printf("valore non valido\n");
		return -1;
	}
}

void stampaMappatura(struct dato *a){
	for(int i = 0; i < N; i++){
		printf("Posizione. %d:\n", i);
		printf("key: %d. ", a[i].key);
		printf("username: %s\n", a[i].name);
	}
}

//funzione di inserimento nella tavola hash
int hashInsert(struct dato *a, int k, char *string){
	printf("--arriviamo nella funzione di insert--\n");
	int i = 0;
	do{
		int j = hh(k,i);
		printf("dopo la funzione hash\n");
		if(a[j].key == -1){
			printf("nell if\n");
			a[j].key = k;
			printf("errore nella copia...\n");
			printf("%s\n", string);
			strcpy(a[j].name,string);
			printf("siamo dopo la copia\n");
			return j;
		}else{
			i = i + 1;
		}
	}while(i == N);
	printf("Posizione non trovata");
	return -1; 

}




int main(){

	struct dato *array = malloc(sizeof(struct dato)*N);
	//inizializziamo tutto a null
	for(int i = 0; i < N; i++){
		array[i].key = -1;
		array[i].name = malloc(sizeof(char)*30);
	}

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
			char *name = malloc(sizeof(char)*30);
			int k;
			printf("1 inserisci chiave e successivamente nome utente\n");
			scanf("%d", &k);
			scanf(" %s", name);
			int pos = hashInsert(array,k,name);
			printf("Inserimento nella posizione %d\n", pos);
		}else if(scanMenu == 2){
			printf("2\n");
			stampaMappatura(array);
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