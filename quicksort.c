// Kleber Yuji Inoue - 8604297

#include <stdio.h>
#include <stdlib.h>
#include "countryVector.h"
#include "countryTree.h"
void setVector(int **vec, int n){
	int i, num;
	for(i = 0; i < n; i++){
		scanf("%d", &num);
		(*vec)[i] = num;
	}
}

int *quicksort(int *a, int p, int r, int bin){
	int t;
	if(p < r){
		int v = (rand() % (r-p)) + p;
		int pivo = a[v];

		a[v] = a[r];
		a[r] = pivo ;

		int i = p-1;
		int j = r;
		if(bin == 0){
			do{
				do{
					i++;
				}while(a[i] < pivo);
				do{
					j--;
				}while((a[j] > pivo) &&(j > p));
				if(i < j){
					t = a[i];
					a[i] = a[j];
					a[j] = t;
				}
			}while(i < j);
			a[r] = a[i];
			a[i] = pivo;	

			quicksort(a, p, i-1, bin);
			quicksort(a, i+1 , r, bin);	

		}else if(bin == 1){
		do{
			do{
				i++;
			}while(a[i] > pivo);
			do{
				j--;
			}while((a[j] < pivo) && (j > p));
			if(i < j){
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}while(i < j);
		a[r] = a[i];
		a[i] = pivo;

		quicksort(a, p, i-1, bin);
		quicksort(a, i+1 , r, bin);
	}

		
	}

	return a;
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

	vec = quicksort(vec, 0, n-1, bin);

	printVector(vec, n);

	free(vec);

	return 0;
}

