#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int key;
	struct node *prox;
}NO;

typedef struct filaPrioridade{
	NO *inicio;
	int tam;
}PRIORIDADE;

NO *criar_no(int key);
PRIORIDADE *criar_lista();
void inserir(PRIORIDADE *l, int key);
void remover(PRIORIDADE *l, int key);
int vazia(PRIORIDADE *l);
void imprimir_lista(PRIORIDADE *l);

int main(int argc, char const *argv[]){
	
	PRIORIDADE *l = criar_lista();

	inserir(l, 5);
	inserir(l, 1);
	inserir(l, 4);
	inserir(l, 9);
	inserir(l, 2);
	inserir(l, 6);
	inserir(l, 8);
	inserir(l, 3);
	inserir(l, 7);
	inserir(l, 0);

	remover(l, 3);

	imprimir_lista(l);

	return 0;
}

NO *criar_no(int key){
	NO *n = (NO *)malloc(sizeof(NO));

	if(n != NULL){
		n->key = key;
		n->prox = NULL;
	}

	return n;
}

PRIORIDADE *criar_lista(){

	PRIORIDADE *l = (PRIORIDADE *)malloc(sizeof(PRIORIDADE));

	if(l != NULL){
		l->inicio = NULL;
		l->tam = 0;
	}

	return l;
}

void inserir(PRIORIDADE *l, int key){
	NO *n = criar_no(key);

	if(vazia(l)){
		l->inicio = n;
	}else{
		NO *p = l->inicio;
		NO *ant = NULL;
		while(p != NULL && p->key < key){
			ant = p;
			p = p->prox;
		}
		if(ant == NULL){
			n->prox = l->inicio;
			l->inicio = n;
		}else{
			n->prox = p;
			ant->prox = n;
		}

		
	}

	l->tam++;
}

void remover(PRIORIDADE *l, int key){
	if(!(vazia(l))){
		NO *p = l->inicio;
		NO *ant = NULL;
		while(p != NULL && p->key != key){
			ant = p;
			p = p->prox;
		}

		if(ant == NULL){
			l->inicio = p->prox;
		}else{
			ant->prox = p->prox;
		}
	}
}

int vazia(PRIORIDADE *l){
	return(l->inicio == NULL);
}

void imprimir_lista(PRIORIDADE *l){
	if(!vazia(l)){
		NO *p = l->inicio;
		while(p != NULL){
			printf("%d ", p->key);
			p = p->prox;
		}
	}
	printf("\n");
}
