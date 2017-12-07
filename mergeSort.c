// Kleber Yuji Inoue - 8604297

#include <stdio.h>
#include <stdlib.h>

void setVector(int **vec, int n){
	int i, num;
	for(i = 0; i < n; i++){
		scanf("%d", &num);
		(*vec)[i] = num;
	}
}

void merge(int *vec, int ini, int cen, int fim, int bin){
	int i, j, k = 0;

	i = ini;
	j = cen+1;

	int *aux = (int *)malloc(sizeof(int) * (fim-ini+1));

	if(bin == 0){
		while((i <= cen) && (j <= fim)){
		if(vec[i] <= vec[j]){
			aux[k] = vec[i];
			i++;
		}else {
			aux[k] = vec[j];
			j++;
		}
		k++;
		}

		while(i <= cen){
			aux[k] = vec[i];
			i++; 
			k++;
		}

		while(j <= fim){
			aux[k] = vec[j];
			j++; 
			k++;
		}

		for(i = ini; i <= fim; i++){
			vec[i] = aux[i-ini];
		}
	}else{
		while((i <= cen) && (j <= fim)){
		if(vec[i] >= vec[j]){
			aux[k] = vec[i];
			i++;
		}else {
			aux[k] = vec[j];
			j++;
		}
		k++;
		}

		while(i <= cen){
			aux[k] = vec[i];
			i++; 
			k++;
		}

		while(j <= fim){
			aux[k] = vec[j];
			j++; 
			k++;
		}

		for(i = ini; i <= fim; i++){
			vec[i] = aux[i-ini];
		}
	}
	
	free(aux);
}

void mergeSort(int *vec, int ini, int fim, int bin){
	if(fim - ini >= 1){
		int centro = (int)((fim+ini)/2);
		mergeSort(vec, ini, centro, bin);
		mergeSort(vec, centro+1, fim, bin);
		merge(vec, ini, centro, fim, bin);
	}
}



void printVector(int *vec, int n){
	int i;
	for(i = 0; i < n; i++){
		printf("%d ", vec[i]);
	}
	printf("\n");
}

int main(int argc, char const *argv[]){
	int n, bin;

	scanf("%d", &n);
	getchar();
	scanf("%d", &bin);

	int *vec = (int *)malloc(sizeof(int) * n);

	setVector(&vec, n);

	mergeSort(vec, 0, n-1, bin);

	printVector(vec, n);

	free(vec);

	return 0;
}

