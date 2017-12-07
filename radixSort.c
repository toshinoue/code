#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void setVector(int **vec, int n);

void radixsort(int *vec, int n, int bitm);

void printVector(int *vec, int n);

int main(int argc, char const *argv[]){
	int n;

	scanf("%d", &n);
	getchar();

	int *vec = (int *)malloc(sizeof(int) * n);

	setVector(&vec, n);

	radixsort(vec, n, 2);

	printVector(vec, n);

	free(vec);

	return 0;
}

void setVector(int **vec, int n){
	int i;
	int num;
	for(i = 0; i < n; i++){
		scanf("%d", &num);
		(*vec)[i] = num;
	}
}

void radixsort(int *v, int n, int bitm) {
	
	int i, j, shift;

	long int base = (long int)pow(2.0, (double)bitm);

	int * count = (int *) calloc(base, sizeof(int));
	int * pos  = (int *) malloc(base*sizeof(int));
	int * copy = (int *) malloc(n*sizeof(int));

	for (shift = 0; shift < 32; shift += bitm) {

		for (j = 0; j < n; j++) {
			int keyp = (v[j] >> shift) & (base-1);
			count[keyp]++;		
			copy[j] = v[j];
		}
	
		pos[0] = 0;
		for (i = 1; i < base; i++) {
			pos[i] = pos[i-1] + count[i-1];
			count[i-1] = 0;
		}
		count[base-1] = 0;

		for (j = 0; j < n; j++) {
			int keyp = (copy[j] >> shift) & (base-1);
			v[pos[keyp]] = copy[j];

			pos[keyp]++;
		}
	}
	free(copy);
	free(count);
	free(pos);
}

void printVector(int *vec, int n){
	int i;
	for(i = 0; i < n; i++){
		printf("%d ", vec[i]);
	}	
}