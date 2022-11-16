#include <stdio.h>
#include <stdlib.h>
#include "porto.h"

void Pilha(pilha *stack){
    stack->topo = (ap)malloc(sizeof(cp));
    stack->fundo = stack->topo;
    stack->topo->prox = NULL;
    stack->tamanho = 0;
}

int pvazia(pilha stack){
    return (stack.topo == stack.fundo);
}

void empilha(pilha *stack, int x){
    ap aux;
    aux = (ap)malloc(sizeof(cp));
    stack->topo->dado = x;
    aux->prox = stack->topo;
    stack->topo = aux;
    stack->tamanho++;
}

void desempilha(pilha *stack, int *x){
    ap q;
    if(pvazia(*stack)){
        printf("\nErro pilha vazia\n");
        return;
    }

    q = stack->topo;
    stack->topo = q->prox;
    *x = q->prox->dado;
    free(q);
    stack->tamanho--;
}

void imprimeP(ap pointer){
    if(pointer->prox != NULL)
        imprimeP(pointer->prox);
    else
        printf("%d",pointer->dado);
}
