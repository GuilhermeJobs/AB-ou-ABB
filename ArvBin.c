#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "ArvBin.h"

#define FALHA 0
#define SUCESSO 1
#define STOP -1

struct NO{
   int info;
   struct NO *pai;
   struct NO *esq;
   struct NO *dir;
};

ArvBin *cria_ArvBin(){
	ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
	if(raiz != NULL) 
		*raiz = NULL;
	return raiz;
}

void libera_NO(struct NO* no){
	if(no == NULL)
		return;
	libera_NO(no->esq);
	libera_NO(no->dir);
	free(no);
	no = NULL;
}

void libera_ArvBin(ArvBin* raiz){
	if(raiz == NULL)
		return;
	libera_NO(*raiz);//libera NO
	free(raiz); //libera raiz
}

int estaVazia_ArvBin(ArvBin *raiz){
	if (raiz == NULL)
		return 1;
	if (*raiz == NULL)
 		return 1;
	return 0;
}

int insNoAleatorioArvBin(ArvBin *raiz, int valor){
	srand(time(NULL));					//modifica o 'ale'
    
	if(raiz == NULL) return FALHA;		//se ab não existir
    
    struct NO* novo;					
    novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo == NULL) return FALHA;		//se a operação falhar
    
    novo->info = valor;					// Passando
    novo->dir = NULL;					// 	   as
    novo->esq = NULL;					// informações

    if(*raiz == NULL)	// se tiver vazia 
        *raiz = novo;	// entao adiciona a raiz
        
    else{				// se não tiver vazia procura onde insirir
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
		struct NO* pai = NULL;
        int ale;
        while(atual != NULL){
            pai = ant = atual;
            ale = (rand() % 10); 		// sorteia um numero aleatorio
			if(ale % 2 == 0)			//se for par
				atual = atual->dir;		//então vai para direita
			else						//se não for par(impar)
				atual = atual->esq;		//então vai esquerda
        }
        
    	if(ale % 2 == 0 ){				//se o ultimo 'ale' for par
    		ant->dir = novo;			//então o NO vai para direita
    		ant->dir->pai = pai;
    	}else{							//se não for par(impar)
    		ant->esq = novo;			//então o NO vai esquerda
    		ant->esq->pai = pai;
		}
	}
	return SUCESSO;
}


void pre_ordem_ArvBin(ArvBin *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
       printf("[%d] ", (*raiz)->info);
       pre_ordem_ArvBin(&(*raiz)->esq);
       pre_ordem_ArvBin(&(*raiz)->dir);
    }
}

void em_ordem_ArvBin(ArvBin *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        em_ordem_ArvBin(&(*raiz)->esq);
        printf("[%d] ", (*raiz)->info);
        em_ordem_ArvBin(&(*raiz)->dir);
    }
}

void pos_ordem_ArvBin(ArvBin *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        pos_ordem_ArvBin(&(*raiz)->esq);
        pos_ordem_ArvBin(&(*raiz)->dir);
        printf("[%d] ", (*raiz)->info);
    }
}
//verifica se a arvore é uma ab ou abb
int ABouABB(ArvBin *raiz){
	if(raiz == NULL)
        return FALHA;
    
    if(*raiz != NULL){
    	
		if((*raiz)->esq != NULL && (*raiz)->dir != NULL){		//se tem dois filhos
			if((*raiz)->esq->info <= (*raiz)->esq->pai->info &&	//se o 'filho' da esquerda é menor que 'pai'
				(*raiz)->dir->info >= (*raiz)->dir->pai->info){ //se o 'filho' da direita é maior que 'pai'
					//ok continua								//se sim então continua
			}else return FALHA;									//se não então returna falha (0)
		}
		
		if((*raiz)->esq != NULL && (*raiz)->dir == NULL){		//se tem apenas o 'filho' da esquerda
			if((*raiz)->esq->info >= (*raiz)->esq->pai->info){	//se o 'filho' da esquerda é menor que 'pai'
					//ok continua								//se sim então continua
			}else return FALHA;									//se não então returna falha (0)
		}
	
		if((*raiz)->esq == NULL && (*raiz)->dir != NULL){		//se tem apenas o 'filho' da direita
			if((*raiz)->dir->info >= (*raiz)->dir->pai->info){	//se o 'filho' da direita é maior que 'pai'
					//ok continua								//se sim então continua
			}else return FALHA;									//se não então returna falha (0)
		}
		
		ABouABB(&(*raiz)->esq);
		ABouABB(&(*raiz)->dir);
    }
    return SUCESSO; //retorna 1
}

int insere_ArvBin(ArvBin *raiz, int valor){
	if(raiz == NULL)
		return FALHA;
	struct NO* novo;
	novo = (struct NO*)malloc(sizeof(struct NO));
	if(novo == NULL)
		return FALHA;
	novo->info = valor;
	novo->esq = NULL;
	novo->dir = NULL;
	
    if(*raiz == NULL){
        *raiz = novo;
    }else{
		struct NO* atual = *raiz;
		struct NO* ant = NULL;
		struct NO* pai = NULL;
			
		while(atual != NULL){
			pai = ant = atual;
			if(valor == atual->info){
				free(novo);
				return FALHA;
			}
			if(valor > atual->info)
				atual = atual->dir;
			else
				atual = atual->esq;
		}
		if(valor > ant->info){
			ant->dir = novo;
    		ant->dir->pai = pai;
    		printf("pai: %d \n", ant->dir->pai->info);
		}
		else{
			ant->esq = novo;
			ant->esq->pai = pai;
    		printf("pai: %d \n", ant->esq->pai->info);
		}
	}
	return SUCESSO;
}
