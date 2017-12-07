#include <stdio.h>
#include <stdlib.h>

#define FILHO_ESQ 0
#define FILHO_DIR 1

typedef struct no{
	int item;
	struct no *filhoesq, *filhodir;
}NO;

NO *criar_arvore();

NO *inserir_filho(int filho, NO *no, int item);

int inserir_abb(NO *raiz, int item);

void preordem(NO *raiz);

void imprimir_item(int item);

int remover_abb(NO *raiz, NO *rem, NO *ant, int item);

void troca_max_esq(NO *raiz, NO *rem, NO *ant);

NO *busca_abb(NO *raiz, int item);

int main(int argc, char const *argv[]){
	int n;
	scanf("%d", &n);
	getchar();

	NO *raiz = criar_arvore();

	int i, aux;
	int *inserir = (int *)malloc(sizeof(int) * n);
	for(i = 0; i < n; i++){
		scanf("%d", &aux);
		inserir[i] = aux;
	}

	raiz->item = inserir[0];
	for(i = 1; i < n; i++){
		inserir_abb(raiz, inserir[i]);
	}

/*
	scanf("%d", &n);
	getchar();
	int *remover = (int *)malloc(sizeof(int) * n);
	for(i = 0; i < n; i++){
		scanf("%d", &aux);
		remover[i] = aux;
	}

	for(i = 0; i < n; i++){
		remover_abb(raiz, raiz, NULL, remover[i]);
	}

	free(remover);
*/

	scanf("%d", &n);
	busca_abb(raiz, n);

	//preordem(raiz);

	free(raiz);
	free(inserir);

	return 0;
}

NO *criar_arvore(){
	NO *raiz = (NO*)malloc(sizeof(NO));
	if (raiz != NULL){
		raiz->filhoesq = NULL;
		raiz->filhodir = NULL;
		raiz->item = -1;
	}
	return (raiz);
}

NO *inserir_filho(int filho, NO *no, int item){
	NO *pnovo = (NO *)malloc(sizeof(NO));

	if(pnovo != NULL){
		pnovo->filhodir = NULL;
		pnovo->filhoesq = NULL;
		pnovo->item = item;

		if(filho == FILHO_ESQ){
			no->filhoesq = pnovo;
		}else{
			no->filhodir = pnovo;
		}
	}

	return pnovo;
}

int inserir_abb(NO *raiz, int item){
	NO *aux;
	if(raiz->item > item){
		if(raiz->filhoesq != NULL) {
			return inserir_abb(raiz->filhoesq, item);
		}else{
			aux = inserir_filho(FILHO_ESQ, raiz, item);
			if(aux != NULL) return 1;
		}
	}else{
		if(raiz->item <= item){
			if(raiz->filhodir != NULL){
				return inserir_abb(raiz->filhodir, item);
			}else{
				aux = inserir_filho(FILHO_DIR, raiz, item);
				if(aux != NULL) return 1;
			}
		}
	}

	return 0;
}

void preordem(NO *raiz){
	if(raiz != NULL){
		imprimir_item(raiz->item);
		preordem(raiz->filhoesq);
		preordem(raiz->filhodir);
	}
}

void imprimir_item(int item){
	printf("%d ", item);
}

int remover_abb(NO *raiz, NO *rem, NO *ant, int item){
	NO *prox;
	if(rem == NULL) 
		return 0;
	if(rem->item > item) 
		return remover_abb(raiz, rem->filhoesq, rem, item);
	else{
		if(rem->item < item) 
			return remover_abb(raiz, rem->filhodir, rem, item);
		else{
			if(rem->filhoesq == NULL || rem->filhodir == NULL){
				if(rem->filhoesq == NULL) 
					prox = rem->filhodir;
				else 
					prox = rem->filhoesq;
				if(ant == NULL) {
					raiz->filhodir = prox->filhodir;
					raiz->filhoesq = prox->filhoesq;
					raiz->item = prox->item;
				}else{
					if(rem == ant->filhoesq) 
						ant->filhoesq = prox;
					else 
						ant->filhodir = prox;
				}
				free(rem);
				rem = NULL;
			}else troca_max_esq(rem->filhoesq, rem, rem);
		}
	}

	return 1;
}

void troca_max_esq(NO *raiz, NO *rem, NO *ant){
	if(raiz->filhodir != NULL)
		return troca_max_esq(raiz->filhodir, rem, raiz);

	if(rem == ant){
		ant->filhoesq = raiz->filhoesq;
	}else{
		ant->filhodir = raiz->filhoesq;
	}

	rem->item = raiz->item;
	free(raiz);
	raiz = NULL;
}

NO *busca_abb(NO *raiz, int item){
	if(raiz == NULL){
		printf("elemento nao encontrado\n");
		return NULL;
	}
	else{
		if(raiz->item == item){
			printf("elemento encontrado\n");
			return raiz;
		}
		else{
			if(raiz->item > item){
				return busca_abb(raiz->filhoesq, item);
			}else{
				return busca_abb(raiz->filhodir, item);
			}
		}
	}
	
	return NULL;
}