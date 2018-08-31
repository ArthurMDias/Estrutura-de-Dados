#include <stdio.h>
#include <stdlib.h>

struct lista{
	int valor;
	struct lista *dedo;
	struct lista *ant;
};

typedef struct lista Lista;

int contadora(Lista *cabeca){
	int x=0;
	while(cabeca!=NULL){
		x++;
		cabeca=cabeca->dedo;
	}
	
	return x;
}

Lista *inserirFinal(Lista *cabeca,int x){
	Lista *pont=(Lista *) malloc(sizeof(Lista));
	Lista *auxiliar=cabeca;
	if(cabeca==NULL){
		pont->valor=x;
		pont->dedo=cabeca;
		return pont;
	}else{
		while(cabeca->dedo!=NULL){
			cabeca=cabeca->dedo;
		}
		pont->valor=x;
		pont->dedo=NULL;
		cabeca->dedo=pont;
		return auxiliar;
	}
}

void imprimir(Lista *chute){
	while(chute!=NULL){
		printf(" %d ",chute->valor);
		chute=chute->dedo;
	}
}

Lista * inserirPosicao(Lista *cabeca,int info,int pos){
	int i,retorno;
	retorno=contadora(cabeca);
	Lista *auxiliar=cabeca;
	Lista *ponteiro=(Lista *) malloc (sizeof(Lista));
	
	
	if(pos==0){
		ponteiro->valor=info;
		ponteiro->dedo=cabeca;
		auxiliar=ponteiro;
	}else{
		for(i=0;i!=pos-1;i++){
			cabeca=cabeca->dedo;
		}
		
		ponteiro->valor=info;
		ponteiro->dedo=cabeca->dedo;
		cabeca->dedo=ponteiro;
	}
	
	return auxiliar;
}

int conferir(Lista *chute){
	while(chute->dedo!=NULL){
		if(chute->valor>chute->dedo->valor) return 1;
		chute=chute->dedo;
	}
	
	return 0;
}

void ordenarCrescente(Lista *cabeca){
	Lista *ponteiro;
	int retorno,auxValor;
	
	retorno=conferir(cabeca);
	while(retorno==1){
		ponteiro=cabeca;
		while(ponteiro->dedo!=NULL){
			if(ponteiro->valor>ponteiro->dedo->valor){
				auxValor=ponteiro->valor;
				ponteiro->valor=ponteiro->dedo->valor;
				ponteiro->dedo->valor=auxValor;
			}
			ponteiro=ponteiro->dedo;
		}
		retorno=conferir(cabeca);
	}
	
	
}

Lista * inserirfinalDupla(Lista *cabeca,int x){
	Lista *auxiliar,*ponteiro=(Lista *) malloc (sizeof(Lista));
	
	if(cabeca==NULL){
		ponteiro->valor=x;
		ponteiro->dedo=NULL;
		ponteiro->ant=NULL;
		cabeca=ponteiro;
	}else{
		for(auxiliar=cabeca;auxiliar->dedo!=NULL;auxiliar=auxiliar->dedo);
		auxiliar->dedo=ponteiro;
		ponteiro->valor=x;
		ponteiro->dedo=NULL;
		ponteiro->ant=auxiliar;
	}
	
	return cabeca;
}

Lista *buscarValor(Lista *cabeca,int info){
	while(cabeca!=NULL){
		if(cabeca->valor==info){
			return cabeca;
		}
		cabeca=cabeca->dedo;
	}
	printf("Valor não encontrado!");
	return cabeca;
}















