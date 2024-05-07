#include <stdio.h>
#include <stdlib.h>

typedef struct SArvore
{
    int valor;
    struct SArvore *direita, *esquerda;
}TArvore;

TArvore* inserir_v1(TArvore *raiz, int num){
    if(raiz == NULL){
        TArvore *aux = calloc(1, sizeof(TArvore));
        aux->valor = num;
        aux->esquerda = NULL;
        aux->direita =  NULL;
        return aux;
    }else{
        if(num < raiz->valor){
            raiz->esquerda = inserir_v1(raiz->esquerda, num);
        }else{
            raiz->direita = inserir_v1(raiz->direita, num);
        }
    }
    return raiz;
}

void preOrdem(TArvore* raiz){
    if(raiz == NULL){
        return;
    }
    printf("%d\n", raiz->valor);
    preOrdem(raiz->esquerda);
    preOrdem(raiz->direita);
}

void ordem(TArvore* raiz){
    if(raiz == NULL){
        return;
    }
    ordem(raiz->esquerda);
    printf("%d\n", raiz->valor);
    ordem(raiz->direita);
}

void posOrdem(TArvore* raiz){
    if(raiz == NULL){
        return;
    }
    posOrdem(raiz->esquerda);
    posOrdem(raiz->direita);
    printf("%d\n", raiz->valor);
}

int main(){

    TArvore *raiz = NULL;

    raiz = inserir_v1(raiz, 50);

    return 0;
}
