#include <stdio.h>
#include <string.h>
#include "biblioteca.h"



main(){
	Lista *cabeca=NULL;
	int entrada,posicao;
	char resp;
	
	do{
		printf("Valor: ");
		scanf("%d",&entrada);
		
		cabeca=inserirFinal(cabeca,entrada);
		imprimir(cabeca);
		printf("\n %d",cabeca->valor);
		printf("\nInserir mais um elemento? ");
		fflush(stdin);
		scanf("%c",&resp);
		system("cls");
	}while(resp=='s' || resp=='S');
	
	
	do{
		printf("Informe a posicao: ");
		fflush(stdin);
		scanf("%d",&posicao);
		
		printf("Informe o valor: ");
		fflush(stdin);
		scanf("%d",&entrada);
		
		cabeca=inserirPosicao(cabeca,entrada,posicao);
		imprimir(cabeca);	
		
		printf("\nInserir mais um elemento? ");
		fflush(stdin);
		scanf("%c",&resp);
		system("cls");
	}while(resp=='s' || resp=='S');
}
