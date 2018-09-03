#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"


main(){
	char resp;
	int valor;
	Lista *cabeca=NULL,*cabeca2=NULL,*cabeca3;
	
	do{
		printf("Insira um valor (Lista1): ");
		fflush(stdin);
		scanf("%d",&valor);
		
		cabeca=inserirFinal(cabeca,valor);
		
		printf("Deseja continuar? ");
		fflush(stdin);
		scanf("%c",&resp);
		system("cls");
	}while(resp=='s' || resp=='S');
	
	do{
		printf("Insira um valor (Lista2): ");
		fflush(stdin);
		scanf("%d",&valor);
		
		cabeca2=inserirFinal(cabeca2,valor);
		
		printf("Deseja continuar? ");
		fflush(stdin);
		scanf("%c",&resp);
		system("cls");
	}while(resp=='s' || resp=='S');
	
	
	
	cabeca3=combinarListas(cabeca,cabeca2);
	imprimir(cabeca3);
}
