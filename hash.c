/*
	Nome: Kleber Yuji Inoue - 8604297
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "hash.h"

struct hash{
	int id;
	LISTA *lista;
};

HASH *create_table(int id){
	
	HASH *h = (HASH *)malloc(sizeof(HASH));
	
	if(h != NULL){
		h->id = id;
		h->lista = criar_lista();
	}
	
	return h;
}

void insert_table(HASH *h, int id){
	NO *aux = criar_no(id);
	
	inserir_fim(h->lista, aux);
}

void print_hash(HASH *h, int i){
	if(!(vazia(h->lista))){
		printf("%d -> ", i);
		imprimir_lista(h->lista);
		printf("\n");
	}
}

void free_hash(HASH *h){
	free(h->lista);
	free(h);
}
