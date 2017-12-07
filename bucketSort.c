#include <stdio.h>
#include <stdlib.h>

// struct no (contendo referencia para proximo elemento)
typedef struct node {
	float elem;
	struct node * next;
} Node;

// tipo a ser usado para criar vetor de buckets (facilitar o uso da fila)
typedef struct bucket {
	Node * begin;
	Node * end;
} Bucket;

void bucketsort(float *v, int n) {

	// 1 - encontrar valores de maximo e minimo das chaves
	int i;
	float max, min;
	max = min = v[0];
	for (i = 1; i < n; i++) {
		if (v[i] > max) max = v[i];
		if (v[i] < min) min = v[i];
	}

	// 2 - criar vetor 'bucket' de listas (filas)
	int d = (max-min)+1;
	Bucket *B = (Bucket *) calloc(d, sizeof(Bucket));
	
	// 3 - percorre o vetor de entrada, inserindo os
	//	elementos nos buckets
	for (i = 0; i < n; i++) {
		float key = v[i];
		int pos = (key-min); // desloca a menor chave para 0
	
		// criando novo no
		Node *newnode = malloc(sizeof(Node));
		newnode->elem = v[i];
		newnode->next = NULL;			

		// insere novo no na fila
		// se lista vazia
		if (B[pos].begin == NULL) {
			B[pos].begin = newnode;
		} else {
		// lista nao vazia
			(B[pos].end)->next = newnode;
		}
		B[pos].end = newnode;		
	}

	// 4 - percorre o vetor de buckets, recopiando
	//	para o vetor original de forma ordenada
	int j;
	i = 0; // indice do vetor original
	for (j = 0; j < d; j++) {
		// para cada bucket (fila), removo todos os elementos
		Node *p; // ponteiro que percorre a fila
		p = B[j].begin;
		while (p != NULL) {
			// copia rasa para o vetor original
			v[i] = p->elem; i++;

			// deleto o elemento e vou para o proximo
			Node *del = p;
			p = p->next; B[j].begin = p; // atualiza elemento
			free(del);
		}
	}
	free(B);
}

void setVector(float **vec, int n){
	int i;
	float num;
	for(i = 0; i < n; i++){
		scanf("%f", &num);
		(*vec)[i] = num;
	}
}

int main (int argc, char * argv[]) {

	int n;
	scanf("%d", &n);
	getchar();

	float *vec = (float *)malloc(sizeof(float) * n);
	setVector(&vec, n);

	bucketsort(vec, n);

	int i;
	for (i = 0; i < n; i++) {
		printf("%.4f ", vec[i]);
	}

	return 0;
}
