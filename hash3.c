#include <stdlib.h>
#include <stdio.h>
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
	LISTA *lista;
}HASH;

NO *criar_no(char *chave);
LISTA *criar_lista();
void inserir(LISTA *l, NO *n);
int vazia(LISTA *l);
void imprimir_lista(LISTA *l);

/******************************************/

HASH *create_table(int n);
void insert_table(HASH h, char *id);
void print_hash(HASH h);
void free_hash(HASH *h);

/******************************************/

char *setString();
char **file_text(FILE *fp, int *lines);
void free_text(char **text, int lines);
char **set_words(int n);
void search_words(HASH *h, char **words, int lines, int n);

int main(int argc, char const *argv[]){

	printf("Informe o nome do arquivo de entrada:\n");
	char *str = setString();
	FILE *fp = fopen(str, "r");

	int lines = 0;
	char **text = file_text(fp, &lines);

	HASH *h = create_table(lines);

	int i;
	for(i = 0; i < lines; i++){
		insert_table(h[i], text[i]);

		printf("[%d].", i+1);
		print_hash(h[i]);
	}

	int n;
	printf("Informe o numero de palavras a serem buscadas: \n");
	scanf("%d", &n);
	getchar();
	char **words = set_words(n);

	search_words(h, words, lines, n);

	fclose(fp);
	free(str);
	free_hash(h);
	free_text(text, lines);
	free_text(words, n);

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

HASH *create_table(int n){
	
	HASH *h = (HASH *)malloc(sizeof(HASH) * n);
	
	int i;
	if(h != NULL){
		for(i = 0; i < n; i++){
			h[i].lista = criar_lista();
		}
	}
	
	return h;
}

void insert_table(HASH h, char *id){
	NO *aux = criar_no(id);
	
	inserir(h.lista, aux);
}

void print_hash(HASH h){
	if(!(vazia(h.lista))){
		imprimir_lista(h.lista);
		printf("\n");
	}
}

void free_hash(HASH *h){
	free(h->lista);
	free(h);
}

/************************************************/

char *setString(){

	char *str = NULL;
	size_t bytes = 0;
	getline(&str, &bytes, stdin);
	int tam = strlen(str);
	str[tam-1] = '\0';

	return str;
}

char **file_text(FILE *fp, int *lines){
	char **file = NULL;
	int i;
	while(!(feof(fp))){
		file = (char **)realloc(file, sizeof(char *) * (*lines+1));

		char entrada;
		fscanf(fp, "%c", &entrada);
		i = 0;
		while(entrada != '\n' && !(feof(fp))){
			file[(*lines)] = (char *)realloc(file[(*lines)], sizeof(char) * (i+1));
			file[(*lines)][i] = entrada;
			i++;
			fscanf(fp, "%c", &entrada);
		}
		file[(*lines)][i] = '\0';
		(*lines)++;
	}

	return file;
}

void free_text(char **text, int lines){
	int i;
	for(i = 0; i < lines; i++){
		free(text[i]);
	}
	free(text);
}

char **set_words(int n){
	char **words = (char **)malloc(sizeof(char *) * n);

	int i;
	for(i = 0; i < n; i++){
		printf("Digite a palavra a ser buscada:\n");
		words[i] = setString();
	}

	return words;
}

void search_words(HASH *h, char **words, int lines, int n){
	int i, j;
	for(i = 0; i < n; i++){
		printf("%s -> ", words[i]);
		for(j = 0; j < lines; j++){
			if(strstr(h[j].lista->inicio->item, words[i]) != NULL){
				printf("%d ", j+1);
			}
		}
		printf("\n");
	}
}