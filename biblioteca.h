#include <stdio.h>
#include <stdlib.h>

struct lista{
	int valor;
	struct lista *dedo;
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










