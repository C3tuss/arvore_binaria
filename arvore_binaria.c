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

void inserir_v3(TArvore **raiz, int num){
    TArvore *aux = *raiz;

    while(aux){
        if(num < aux->valor)
            raiz = &aux->esquerda;
        else
            raiz = &aux->direita;
        aux = *raiz;
    }

    aux = calloc(1, sizeof(TArvore));
    aux->valor = num;
    aux->esquerda = NULL;
    aux->direita = NULL;
    *raiz = aux;
}

void preOrdem(TArvore* raiz){
    if(raiz == NULL){
        return;
    }
    printf("%d ", raiz->valor);
    preOrdem(raiz->esquerda);
    preOrdem(raiz->direita);
}

void ordem(TArvore* raiz){
    if(raiz == NULL){
        return;
    }
    ordem(raiz->esquerda);
    printf("%d ", raiz->valor);
    ordem(raiz->direita);
}

void posOrdem(TArvore* raiz){
    if(raiz == NULL){
        return;
    }
    posOrdem(raiz->esquerda);
    posOrdem(raiz->direita);
    printf("%d ", raiz->valor);
}

int main(){

    TArvore *raiz = NULL;

    int v_raiz;

    printf("Digite o valor da raiz: ");
    scanf("%d", &v_raiz);

    inserir_v3(&raiz, v_raiz);

    while (1)
    {
        int leitura;

        printf("Digite um valor para inserir na árvore: \n");
        scanf("%d", &leitura);

        if(leitura == 0)
            break;

        inserir_v3(&raiz, leitura);
    }
    
    ordem(raiz);

    return 0;
}
