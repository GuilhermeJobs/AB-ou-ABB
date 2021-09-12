#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "ArvBin.h"

#define FALHA 0
#define SUCESSO 1
#define STOP -1

int main(int argc, char *argv[]) {
  	//srand(time(NULL));
  	setlocale(LC_ALL, "Portuguese");
  	
  	int x;
	ArvBin* raiz = cria_ArvBin();
	printf("Exercício 04\n\n .:::::: Árvore Binária ou Árvore Binária de Busca ::::::.\n");
	printf("Entre com um nó desejado ou -1 para encerrar.\n");
	int valor;
	do{
		scanf("%d", &valor);
		if(valor == STOP)
			break;
		else{
			x = insNoAleatorioArvBin(raiz, valor); //insere os NÓS aleatorio a partir do 2° NO (aceita NÓS reptidos)
			//x = insere_ArvBin(raiz, valor);		//insere os NÓS de acordo com os criterios da ABB
			if(x == SUCESSO)
				printf("sucesso ao inserir [%d]\n", valor);
			else
				printf("falha ao inserir [%d]\n", valor);
		}		
	}while(valor != STOP);
	
	/**x = estaVazia_ArvBin(raiz);
	if(x == SUCESSO)
		printf("\nAB vazia!!\n");
	else{		
		printf("=========================================\n");
		printf("Imprimindo em PRE ORDEM\n");
		pre_ordem_ArvBin(raiz);
		printf("\n");
		printf("Imprimindo EM ORDEM\n");
		em_ordem_ArvBin(raiz);
		printf("\n");
		printf("Imprimindo em POS ORDEM\n");
		pos_ordem_ArvBin(raiz);	
		printf("\n=======================================\n\n");
	}**/
	
	ABouABB(raiz);
	libera_ArvBin(raiz);
	
	return 0;
}

