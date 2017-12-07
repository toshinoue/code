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

void maxHeapify(int *v, int n, int root){
	
	int child = (root*2)+1;

	
	while(child < n){
		if((child + 1 < n) && (v[child+1] > v[child])){
			child = child + 1;
		}

		int parent = (int)((child-1)/2.0);
		if(v[parent] < v[child]){
			int aux = v[child];
			v[child] = v[parent];
			v[parent] = aux;
			child = (child * 2)+1; // proximo filho esq.
		}
		else break;
	}
}	

void buildMaxHeap(int *v, int n){
	int i = (int)((n-1)/2.0);
	while(i >= 0){
		maxHeapify(v, n, i);
		i--;
	}
}

void heapsort(int *v, int n){

	buildMaxHeap(v, n);

	int t;
	for(t = n; t >= 2; t--){
		int aux = v[0];
		v[0] = v[t-1];
		v[t-1] = aux;

		maxHeapify(v, t-1, 0);
	}
}

void printVector(int *vec, int n, int bin){
	int i;
	if(bin == 0){
		for(i = 0; i < n; i++){
			printf("%d ", vec[i]);
		}	
	}else{
		for(i = n-1; i >= 0; i--){
			printf("%d ", vec[i]);
		}
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

	heapsort(vec, n);

	printVector(vec, n, bin);

	free(vec);

	return 0;
}

