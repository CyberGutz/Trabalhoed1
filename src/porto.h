#ifndef PORTO_H
#define PORTO_H

/////////////ESTRUTURAS/////////////

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


//Estrutura de tempo
typedef struct tempo{
    int dia;
    int ut;
}tempo;

//Estrutura da travessa
typedef struct travessa{
    pilha t1, t2, t3, t4, t5;
}travessa;

//Estrutura do navio
typedef struct navio{
    int id, ut;
    pilha pc1, pc2, pc3, pc4;
}navio;

//Estruturas da Fila
typedef struct cf *af;
typedef struct cf{
    navio ship;
    af prox;
}cf;
typedef struct fila{
    af primeiro, ultimo;
    int qtd;
}fila;

//Funções estruturais da pilha
void Pilha(pilha *stack);
void empilha(pilha *stack, int x);
void desempilha(pilha *stack, int *x);
void imprimeP(pilha stack);

//Funções Gerais
void criaNavio(navio *ship, fila queue);
void imprimeNavio(navio ship);
void atracar(navio *fleet, fila *queue, int qtd);
void desembarcar(navio ship);
void armazenar(travessa t);
void relatorio(fila stack, travessa t, tempo time);

//Funções estruturais da fila
void Fila(fila *queue);
void enfileira(fila *queue, navio *ship);
void desenfileira(fila *queue, navio *ship);
void imprimeF(fila queue);

#endif