#include <stdio.h>
#include <stdlib.h>
#include "porto.h"

void Fila(fila *queue){
    queue->primeiro = (af)malloc(sizeof(cf));
    queue->ultimo = queue->primeiro;
    queue->qtd = 0;
}

void enfileira(fila *queue, navio *x){
    queue->ultimo->prox = (af)malloc(sizeof(cf));
    queue->ultimo = queue->ultimo->prox;
    queue->ultimo->ship = *x;
    queue->ultimo->prox = NULL;
    queue->qtd++;
}

int fvazia(fila queue){
    return (queue.primeiro == queue.ultimo);
}

void desenfileira(fila *queue, navio *x){
    af q;
    if(fvazia(*queue)){
        printf("\nErro: fila vazia\n");
    }

    q = queue->primeiro;
    queue->primeiro = queue->primeiro->prox;
    *x = queue->primeiro->ship;
    free(q);
}

void imprimeF(af pointer){
    if(pointer->prox != NULL)
        imprimeF(pointer->prox);
    else
        imprimeNavio(pointer->ship);
}