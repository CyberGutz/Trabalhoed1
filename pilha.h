#ifndef PILHA_H
#define PILHA_H

//Estruturas da Pilha
typedef struct cp *ap;
typedef struct cp{
    int dado;
    ap prox;
}cp;
typedef struct pilha{
    int tamanho;
    ap fundo, topo;
}pilha;

//Funções estruturais da pilha
void Pilha(pilha *stack);
void empilha(pilha *stack, int x);
void desempilha(pilha *stack, int *x);
void imprimeP(pilha stack);

#endif