#include <stdio.h>
#include <stdlib.h>

NO *criar_no(int chave){
	NO *n = (NO *)malloc(sizeof(NO));
	
	n->item = chave;
	n->prox = NULL;
	
	return n;
}

LISTA *criar_lista(){
	
	LISTA *l = (LISTA *)malloc(sizeof(LISTA));
	
	if(l != NULL){
		l->inicio = NULL;
		l->fim = NULL;		
		l->tam = 0;
	}
	
	return l;
}

void inserir_fim(LISTA *l, NO *n){
	if(n != NULL){
		if(vazia(l)){
			l->inicio = n;
			l->fim = n;
		}else{
			l->fim->prox = n;
		}
		l->tam++;
	}
}
void inserir_inicio(LISTA *l, NO *n){
	if(n != NULL){
		if(vazia(l)){
			l->inicio = n;
		}else{
			n->prox = l->inicio;
			l->inicio = n;
		}
		l->tam++;
	}
}

int busca_item(LISTA *l, int chave){
	NO *aux = l->inicio;
	int count = 0;
	while(aux != NULL){
		count++;
		if(aux->item == chave) return count;
		aux = aux->prox;
	}
	
	return 0;
}

int vazia(LISTA *l){
	return(l->inicio == NULL);
}

int remover_item(LISTA * l, int chave){
	NO *p = l->inicio;
	NO *aux = NULL;

	while(p != NULL && p->item != chave){
		aux = p;
		p = p->prox;
	}
	
	if(p != NULL){
		if(p == l->inicio){
			l->inicio = p->prox;
		}else{
			aux->prox = p->prox;
		}
		
		if(p == l->fim) l->fim = aux;
		
		l->tam--;
		free(p);
		return 0;
	}


	return 1;
}

void imprimir_lista(LISTA *l){
	if(!vazia(l)){
		NO *p = l->inicio;
		while(p != NULL){
			printf(" %d", p->item);

			p = p->prox;
			if(p != NULL) printf(",");
		}	
	}
}