#include <stdio.h>
#include <stdlib.h>

struct lista{
	int numero;
	struct lista *p;
};

typedef struct lista lista;

lista * inserir(lista *cabeca,int valor){
	lista *ponteiro;
	ponteiro=(lista *) malloc(sizeof(lista));
	ponteiro->numero=valor;
	ponteiro->p=cabeca;
	return ponteiro;  //novo "cabeca" conter� a posi��o da mem�ria do �ltimo elemento criado
}

lista * retirar (lista *cabeca,int valor){
	lista *ponteiro=cabeca; //ponteiro tambem est� apontando para o primeiro elemento da lista
	lista *auxiliar;
	
	while(ponteiro->numero!=valor && ponteiro!=NULL){
		auxiliar=ponteiro;
		ponteiro=ponteiro->p; //p cont�m a posi��o de mem�ria do pr�ximo elemento
	}
	
	if(ponteiro==cabeca){
		cabeca=cabeca->p;
		free(ponteiro); 
	}else if(ponteiro==NULL){
		printf("Valor nao encontrado \n");
	}else{
		auxiliar->p=ponteiro->p;
		free(ponteiro);
	}
	
	return cabeca;
}

void imprimir(lista *primeiro){
	while(primeiro!=NULL){
		printf(" %d ",primeiro->numero);
		primeiro=primeiro->p;
	}
}

main(){
	int i,x;
	lista *cabeca;
	cabeca=NULL;
	
	for(i=9;i>=0;i--){
		cabeca=inserir(cabeca,i);
	}	
	
	imprimir(cabeca);
	
	printf("Insira o elemento a ser retirado: ");
	scanf("%d",&x);
	cabeca=retirar(cabeca,x);
	
	imprimir(cabeca);
}
