#include <stdio.h>
#include <stdlib.h>

//TAD LISTA
typedef struct no{
	int item;
	struct no *prox;
}NO;

typedef struct lista_dinamica{
	NO *inicio;
	NO *fim;
	int tam;
}LISTA;

NO *criar_no(int chave);
LISTA *criar_lista();
void inserir_fim(LISTA *l, NO *n);
void inserir_inicio(LISTA *l, NO *n);
int busca_item(LISTA *l, int chave);
int vazia(LISTA *l);
int remover_item(LISTA * l, int chave);
void imprimir_lista(LISTA *l);

//HASH
typedef struct hash{
	int id;
	LISTA *lista;
}HASH;

HASH *create_hash(int n);
void insert_hash(HASH h, int id);
void insert_hash_linear(HASH *h, int id, int index, int n);
void print_hash(HASH h, int i);
void free_hash(HASH *h, int n);
void search_hash(HASH h, int id);
void search_hash_linear(HASH *h, int id, int index, int n);
void remove_hash(HASH h, int id);
void remove_hash_linear(HASH *h, int id, int index, int n);

int main(int argc, char const *argv[]){
	
	int tipo, n, m;
	scanf("%d", &tipo);
	scanf("%d %d", &n, &m);

	HASH *hash = create_hash(n);

	int i, num;
	for(i = 0; i < m; i++){
		scanf("%d", &num);
		int index = num % n;
		if(tipo == 0){
			insert_hash(hash[index], num);
		}else{
			insert_hash_linear(hash, num, index, n);
		}
	}

	int remove;
	scanf("%d", &remove);
	for(i = 0; i < remove; i++){
		scanf("%d", &num);
		int index = num % n;
		if(tipo == 0){
			remove_hash(hash[index], num);
		}else{
			remove_hash_linear(hash, num, index, n);
		}
	}


	for(i = 0; i < n; i++){
		print_hash(hash[i], i);
	}

	free_hash(hash, n);
	return 0;
}

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

HASH *create_hash(int n){
	
	HASH *h = (HASH *)malloc(sizeof(HASH) * n);
	
	int i;
	for(i = 0; i < n; i++){
		h[i].id = i;
		h[i].lista = criar_lista();
	}
	
	return h;
}

void insert_hash(HASH h, int id){
	NO *aux = criar_no(id);
	
	inserir_inicio(h.lista, aux);
}

void insert_hash_linear(HASH *h, int id, int index, int n){
	NO *aux = criar_no(id);
	int flag = 0;
	while(flag == 0){
		if(vazia(h[index].lista)){
			inserir_inicio(h[index].lista, aux);
			flag = 1;
		}
		index++;
		if(index == n) index = 0;
	}
}

void print_hash(HASH h, int i){
	printf("[%d] ->", i);
	imprimir_lista(h.lista);
	printf("\n");
}

void free_hash(HASH *h, int n){

	int i;
	for(i = 0; i < n; i++){
		free(h[i].lista);
	}

	free(h);
}

void search_hash(HASH h, int id){
	int pos = busca_item(h.lista, id);
	printf("%d\n", pos);
}

void search_hash_linear(HASH *h, int id, int index, int n){
	int count = 1;

	while(h[index].lista->inicio->item != id){
		count++;
		index++;
		if(index == n) index = 0;
	}

	printf("%d\n", count);
}

void remove_hash(HASH h, int id){
	remover_item(h.lista, id);
}

void remove_hash_linear(HASH *h, int id, int index, int n){
	int count = 0;

	while(count < n && !(vazia(h[index].lista)) && h[index].lista->inicio->item != id){
		count++;
		index++;
		if(index == n) index = 0;
	}	
	

	remover_item(h[index].lista, id);
}