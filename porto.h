#ifndef PORTO_H
#define PORTO_H

//Estruturas da Fila
typedef struct cf *af;
typedef struct cf{
    navio ship;
    af prox;
}cf;
typedef struct fila{
    af primeiro, ultimo;
}fila;

//Funções estruturais da fila
void Fila(fila *queue);
void enfileira(fila *queue, navio ship);
void desenfileira(fila *queue, navio ship);
void imprimeF(fila queue);


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


//Estruturação do navio
typedef struct navio{
    int id, tempo;
    pilha pc1, pc2, pc3, pc4;
}navio;

navio criaNavio(int qtd);
void atracar(navio ships[3])

#endif