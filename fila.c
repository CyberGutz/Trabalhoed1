#include <stdio.h>
#include <stdlib.h>
#include "porto.h"

void Fila(fila *queue){
    queue->primeiro = (af)malloc(sizeof(cf));
    queue->ultimo = queue->primeiro;
}

void enfileira(fila *queue, int x){
    queue->ultimo->prox = (af)malloc(sizeof(cf));
    queue->ultimo = queue->ultimo->prox;
    queue->ultimo->dado = x;
    queue->ultimo->prox = NULL;
}

int fvazia(fila queue){
    return (queue.primeiro == queue.ultimo);
}

void desenfileira(fila *queue, int *x){
    af q;
    if(fvazia(*queue)){
        printf("\nErro: fila vazia\n");
    }

    q = queue->primeiro;
    queue->primeiro = queue->primeiro->prox;
    *x = queue->primeiro->dado;
    free(q);
}

void imprimef(af pointer){
    if(pointer->prox != NULL)
        imprimef(pointer->prox);
    else
        printf("%d\n",pointer->dado);
}