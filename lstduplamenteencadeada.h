#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct numeros Numeros;

struct numeros{
	char* nome;
	char* endereco;
	int mat;
};

typedef struct cel Cel;

struct cel{
	Numeros* info;
	struct cel* ant;
	struct cel* prox;
};

typedef struct lstnum LstNum;

struct lstnum{
	Cel* prim;
	Cel* ult;
};

LstNum* inicializaLstNum(){
	LstNum* l = (LstNum*)malloc(sizeof(LstNum));
	l->prim = NULL;
	l->ult = NULL;
}

LstNum* insere(LstNum* lista, Numeros* elem){
	Cel* novo = (Cel*)malloc(sizeof(Cel));
	//Se a lista estiver vazia
	if(lista->prim == NULL){
		novo->info = elem;
		novo->prox = NULL;
		novo->ant = NULL;
		//Acerta o encadeamento
		lista->prim = novo;
		lista->ult = novo;
	}
	else{//Se nao estiver vazia
		novo->info = elem;
		novo->ant = lista->ult;
		novo->prox = NULL;
		//Acerta o encadeamento
		lista->ult->prox = novo;
		lista->ult = novo;
	}
	return(lista);
}

Numeros* retira(LstNum* lista, int v){
	Cel* p = lista->prim;
	while(p != NULL && p->info->mat != v){
		p = p->prox;
	}
	if(p == NULL){
		return(NULL);
	}
	if(p == lista->prim && p == lista->ult){
		lista->prim = NULL;
		lista->ult = NULL;
		return(p->info);
		free(p);
	}
	if(p == lista->prim){
		lista->prim = p->prox;
		lista->prim->ant = NULL;
		return(p->info);
		free(p);
	}
	if(p == lista->ult){
		lista->ult->ant->prox = NULL;
		return(p->info);
		free(p);
	}
	else{
		p->ant->prox = p->prox;
		p->prox->ant = p->ant;
		return(p->info);
	}
	free(p);
}

void imprime(LstNum* lista){
	Cel* p = lista->prim;
	while(p != NULL){
		printf("Nome: %s, Endereco: %s, Matricula: %d\n", p->info->nome, p->info->endereco, p->info->mat);
		p = p->prox;
	}
}

void libera(LstNum* lista){
	Cel* p = lista->prim;
	while(p != NULL){
		Cel* t = p->prox;
		free(p->info->nome);
		free(p->info->endereco);
		free(p->info);
		free(p);
		p = t;
	}
	free(lista);
}

Numeros* inicializatiponum(char* nome,char* end, int v){
	Numeros* novo = (Numeros*)malloc(sizeof(Numeros));
	novo->nome = malloc( (strlen(nome)+1)*sizeof(char) );
	strcpy(novo->nome, nome);
	novo->endereco = malloc( (strlen(end)+1)*sizeof(char) );
	strcpy(novo->endereco, end);
	novo->mat = v;
	return(novo);
}