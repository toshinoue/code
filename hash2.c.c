/*
	Nome: Kleber Yuji Inoue - 8604297
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
	char *item;
	struct no *prox;
}NO;

typedef struct lista_dinamica{
	NO *inicio;
	int tam;
}LISTA;

typedef struct hash{
	int id;
	LISTA *lista;
}HASH;

NO *criar_no(char *chave);
LISTA *criar_lista();
void inserir(LISTA *l, NO *n);
int vazia(LISTA *l);
void imprimir_lista(LISTA *l);
HASH *create_table(int id);
void insert_table(HASH *h, char *id);
void print_hash(HASH *h, char *txt);
void free_hash(HASH *h);

int main(int argc, char const *argv[]){

	char **text = (char **)malloc(sizeof(char *) * 7);

	text[0] = (char *)malloc(sizeof(char) * 36);
	strcpy(text[0], "Good programming is not learned from");

	text[1] = (char *)malloc(sizeof(char) * 42);
	strcpy(text[1], "generalities but by seeing how significant");

	text[2] = (char *)malloc(sizeof(char) * 34);
	strcpy(text[2], "programs can be made clean easy to");

	text[3] = (char *)malloc(sizeof(char) * 32);
	strcpy(text[3], "read easy to maintain and modify");

	text[4] = (char *)malloc(sizeof(char) * 39);
	strcpy(text[4], "human-engineered efficient and reliable");

	text[5] = (char *)malloc(sizeof(char) * 38);
	strcpy(text[5], "by the application of common sense and");

	text[6] = (char *)malloc(sizeof(char) * 40);
	strcpy(text[6], "by the use of good programming practices");

	char **words = (char **)malloc(sizeof(char *) * 8);
	words[0] = (char *)malloc(sizeof(char) * 3);
	strcpy(words[0], "and");
	words[1] = (char *)malloc(sizeof(char) * 2);
	strcpy(words[1], "by");
	words[2] = (char *)malloc(sizeof(char) * 2);
	strcpy(words[2], "be");
	words[3] = (char *)malloc(sizeof(char) * 4);
	strcpy(words[3], "easy");
	words[4] = (char *)malloc(sizeof(char) * 16);
	strcpy(words[4], "human-engineered");
	words[5] = (char *)malloc(sizeof(char) * 11);
	strcpy(words[5], "programming");
	words[6] = (char *)malloc(sizeof(char) * 8);
	strcpy(words[6], "programs");
	words[7] = (char *)malloc(sizeof(char) * 2);
	strcpy(words[7], "to");



	int i, j;

	HASH **h = (HASH **)malloc(sizeof(HASH *) * 7);
	for(i = 0; i < 7; i++){
		h[i] = create_table(i);
		insert_table(h[i], text[i]);
	}

	print_hash(h[0], "10");

	for(i = 0; i < 8; i++){
		for(j = 0; i < 7; j++){
			//if(strstr(h[j].lista->inicio->item, words[i]) != NULL)
				printf("%d ", j+1);
		}	
	}
	
	


	for(i = 0; i < 7; i++){
		free(text[i]);
	}
	for(i = 0; i < 8; i++){
		free(words[i]);
	}
	
	return 0;
}

NO *criar_no(char *chave){
	NO *n = (NO *)malloc(sizeof(NO));
	
	n->item = (char *)malloc(sizeof(char) * strlen(chave));
	strcpy(n->item, chave);
	n->prox = NULL;
	
	return n;
}

LISTA *criar_lista(){
	
	LISTA *l = (LISTA *)malloc(sizeof(LISTA));
	
	if(l != NULL){
		l->inicio = NULL;
		l->tam = 0;
	}
	
	return l;
}

void inserir(LISTA *l, NO *n){
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

int vazia(LISTA *l){
	return(l->inicio == NULL);
}

void imprimir_lista(LISTA *l){
	if(!vazia(l)){
		NO *p = l->inicio;
		while(p != NULL){
			printf("%s ", p->item);
			p = p->prox;
		}	
	}
}

HASH *create_table(int id){
	
	HASH *h = (HASH *)malloc(sizeof(HASH));
	
	if(h != NULL){
		h->id = id;
		h->lista = criar_lista();
	}
	
	return h;
}

void insert_table(HASH *h, char *id){
	NO *aux = criar_no(id);
	
	inserir(h->lista, aux);
}

void print_hash(HASH *h, char *txt){
	if(!(vazia(h->lista))){
		printf("%s -> ", txt);
		imprimir_lista(h->lista);
		printf("\n");
	}
}

void free_hash(HASH *h){
	free(h->lista);
	free(h);
}