#include <stdio.h>
#include <stdlib.h>

struct lista{
	int info;
	struct lista *prox; //declara o tipo de valor para o qual o ponteiro aponta
};

typedef struct lista Lista;

Lista *insere(Lista *l,int i){
	Lista *novo;
	novo=(Lista*) malloc(sizeof(Lista));
	novo->info=i;
	novo->prox=l;
	return novo;
} 

void imprime(Lista *l){
	Lista *p=l;
	while(p!=NULL){
		printf("%d - ",p->info);
		p=p->prox;
		
	}
}

Lista *retira(Lista *l, int v){
	Lista *ant = NULL;
	Lista *p = l;
	
	while(p != NULL && p->info != v){
		ant = p;
		p = p -> prox;
	}
	if(p == NULL){
		return l;
	}
	if(ant == NULL){
		l = p -> prox;
	}else{
		ant->prox = p->prox;
	}
	
	free(p);
	return l;
}

main(){
	Lista *l;
	l=NULL;
	l=insere(l,43);
	l=insere(l,75);
	l=insere(l,30);
	l=insere(l,12);
	imprime(l);
	l=retira(l,75);
	printf("\n");
	imprime(l);
	getch();
}
