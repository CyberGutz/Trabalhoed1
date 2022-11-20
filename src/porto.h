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

//Estrutura da travessa
typedef struct travessa{
    pilha t1, t2, t3, t4, t5;
}travessa;

//Estrutura do navio
typedef struct navio{
    int id, ut, qtdc;
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
void imprimeP(ap pointer);
int pvazia(pilha stack);

//Funções Gerais
void criaNavio(navio *ship, fila queue);
void imprimeNavio(navio ship);
void atracar(fila *queue);
void criaTravessa(travessa *t);
void imprimeTravessa(travessa t);
void desembarcar(fila *queue, travessa *t);
void armazenar(pilha *t);
void passaTempo(af pointer);
void relatorio(fila fa1, fila fa2, fila fa3, fila fa4, travessa t1, travessa t2, travessa t3, travessa t4, int mt1, int mt2, int mt3, int mt4);
int calculaMt(af pointer);

//Funções estruturais da fila
void Fila(fila *queue);
void enfileira(fila *queue, navio *ship);
void desenfileira(fila *queue, navio *ship);
void imprimeF(af pointer);
int fvazia(fila queue);

#endif