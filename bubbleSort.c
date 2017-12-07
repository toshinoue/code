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

int *bubblesort(int *vec, int n, int bin){
	int i, j, aux;
	if(bin == 0){
		for(i = 0; i < n; i++){
			for(j = 0; j < n-1; j++){
				if(vec[j] > vec[j+1]){
					aux = vec[j];
					vec[j] = vec[j+1];
					vec[j+1] = aux;
				}
			}
		}
	}else{
		for(i = 0; i < n; i++){
			for(j = 0; j < n-1; j++){
				if(vec[j] < vec[j+1]){
					aux = vec[j];
					vec[j] = vec[j+1];
					vec[j+1] = aux;
				}
			}
		}
	}

	return vec;
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

	vec = bubblesort(vec, n, bin);

	printVector(vec, n);

	free(vec);

	return 0;
}

