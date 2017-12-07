// Kleber Yuji Inoue - 8604297

#include <stdio.h>
#include <stdlib.h>

void setVector(int **vec, int n);

int *countingSort(int *vec, int n);

void printVector(int *vec, int n);

int getMaior(int *vec, int n);

int main(int argc, char const *argv[]){
	int n;

	scanf("%d", &n);
	getchar();

	int *vec = (int *)malloc(sizeof(int) * n);

	setVector(&vec, n);

	vec = countingSort(vec, n);

	printVector(vec, n);

	free(vec);

	return 0;
}

void setVector(int **vec, int n){
	int i, num;
	for(i = 0; i < n; i++){
		scanf("%d", &num);
		(*vec)[i] = num;
	}
}

int *countingSort(int *vec, int n){

	int maior = getMaior(vec, n);
	int *aux = (int *)malloc(sizeof(int) * (maior+1));
	int *vector = (int *)malloc(sizeof(int) * n);

	int i;
	for(i = 0; i <= maior; i++){
		aux[i] = 0;
	}

	for(i = 0; i < n; i++){
		aux[vec[i]]++;
	}

	for(i = 1; i <= maior; i++){
		aux[i] += aux[i-1];
	}

	for(i = n-1; i >= 0; i--){
		vector[aux[vec[i]]-1] = vec[i];
		aux[vec[i]]--;
	}

	free(aux);

	return vector;
}

void printVector(int *vec, int n){
	int i;
	for(i = 0; i < n; i++){
		printf("%d ", vec[i]);
	}
	printf("\n");
}

int getMaior(int *vec, int n){
	int i, maior = 0;

	for(i = 0; i < n; i++){
		if(vec[i] > maior) maior = vec[i];
	}

	return maior;
}