#include <stdio.h>
#include <stdlib.h>

struct arvore{
	int info;
	struct arvore *dir;
	struct arvore *esq;
};

typedef struct arvore arv;

arv *inserir(arv *raiz,int x){
	arv *aux,*ponteiro=raiz;
	
	
	if(raiz==NULL){
		raiz=(arv *) malloc (sizeof(arv));
		raiz->info=x;
		raiz->dir=NULL;
		raiz->esq=NULL;
	}else{
		while(ponteiro!=NULL){
			aux=ponteiro;
			if(x <= ponteiro->info){
				ponteiro=ponteiro->esq;
			}else if(x > ponteiro->info){
				ponteiro=ponteiro->dir;
			}
		}
		
		ponteiro=(arv*) malloc(sizeof(arv));
		
		if(x <= aux->info) aux->esq=ponteiro;
		else aux->dir=ponteiro;
		
		ponteiro->info=x;
		ponteiro->dir=NULL;
		ponteiro->esq=NULL;
	}
	
	return raiz;
	
}

void imprimir(arv *raiz, int a){
	int i;
	if(raiz!=NULL){
		printf("\n");
		for(i=0;i<a;i++) printf(" ");
		printf("%d",raiz->info);
		imprimir(raiz->esq,a++);
		imprimir(raiz->dir,a++);
	}
}

main(){
	arv *raiz=NULL;
	int i,x,a=0;
	for(i=0;i<10;i++){
		printf("Insira um elemento: ");
		fflush(stdin);
		scanf("%d",&x);
		
		raiz=inserir(raiz,x);
		system("cls");
	}
	imprimir(raiz,a);
}
