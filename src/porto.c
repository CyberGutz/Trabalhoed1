#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "porto.h"

void criaNavio(navio *ship, fila queue){
    int rp1, rp2, rp3, rp4, i, j, containerid;
    //Cria as pilhas do navio
    Pilha(&ship->pc1);
    Pilha(&ship->pc2);
    Pilha(&ship->pc3);
    Pilha(&ship->pc4);

    //Cria o id do navio (baseado na quantidade da fila de atracamento)
    ship->id = queue.qtd;

    //Define o ut do navio em 0 (já que ele ainda não passou nenhum tempo na fila)
    ship->ut = 0;

    //Define a quantidade de containeres como 0
    ship->qtdc = 0;

    //Variáveis que identificam quantos containers vão ser empilhados em cada pilha (de 1 a 4)
    rp1 = rand() % (4 - 1) +1;
    rp2 = rand() % (4 - 1) +1;
    rp3 = rand() % (4 - 1) +1;
    rp4 = rand() % (4 - 1) +1;

    //Empilha os containers
    for(int i=0; i<4; i++){
        for(j=0; j<rp1; j++){
            containerid = rand() % 10000;
            empilha(&ship->pc1, containerid);
            ship->qtdc++;
        }

        for(j=0; j<rp2; j++){
            containerid = rand() % 10000;
            empilha(&ship->pc2, containerid);
            ship->qtdc++;
        }

        for(j=0; j<rp3; j++){
            containerid = rand() % 10000;
            empilha(&ship->pc3, containerid);
            ship->qtdc++;
        }

        for(j=0; j<rp4; j++){
            containerid = rand() % 10000;
            empilha(&ship->pc4, containerid);
            ship->qtdc++;
        }
    }
}

void imprimeNavio(navio ship){
    printf("\n///////////////////////////////////////////////\n");
    printf("\n\tDADOS DO NAVIO\n");
    printf("\n\tID: %d",ship.id);
    
    if(ship.ut == 0)
        printf("\n\tO navio ainda nao foi descarregado\n");
    else
        printf("\n\tTempo gasto ao descarregar: %d",ship.ut);

    if(pvazia(ship.pc1) && pvazia(ship.pc2) && pvazia(ship.pc3) && pvazia(ship.pc4))
        printf("navio descarregado!");
    
    else{
        printf("\n\tPILHAS DE CONTAINER\n");
        printf("\n--> PILHA 1: \n");
        imprimeP(ship.pc1.topo);
        printf("\n--> PILHA 2: \n");
        imprimeP(ship.pc2.topo);
        printf("\n--> PILHA 3: \n");
        imprimeP(ship.pc3.topo);
        printf("\n--> PILHA 4: \n");
        imprimeP(ship.pc4.topo);
    }

    printf("\n///////////////////////////////////////////////\n");
}

void atracar(fila *queue){
    int i, qtd;
    navio *ship;

    qtd = rand()%(3 - 0) + 0;

    printf("\n\nChegaram %d navios na fila de atracamento\n\n",qtd);
    sleep(3);

    for(i = 0; i< qtd; i++){
        criaNavio(ship, *queue);
        enfileira(queue, ship);
        printf("Entrou na fila o %d navio",ship->id);
        imprimeNavio(*ship);
        sleep(5);
    }
}

void criaTravessa(travessa *t){
    Pilha(&t->t1);
    Pilha(&t->t2);
    Pilha(&t->t3);
    Pilha(&t->t4);
    Pilha(&t->t5);
}

void imprimeTravessa(travessa t){
    printf("\n\tDADOS DA TRAVESSA\n\n");
    printf("\n--> PILHA 1: \n");
    imprimeP(t.t1.topo);
    sleep(2);
    printf("\n--> PILHA 2: \n");
    imprimeP(t.t2.topo);
    sleep(2);
    printf("\n--> PILHA 3: \n");
    imprimeP(t.t3.topo);
    sleep(2);
    printf("\n--> PILHA 4: \n");
    imprimeP(t.t4.topo);
    sleep(2);
    printf("\n--> PILHA 5: \n");
    imprimeP(t.t5.topo);
    sleep(2);
    printf("\n///////////////////////////////////////////////\n");
}

void desembarcar(fila *queue, travessa *t){
    int i, verificador, desempilhou;
    int *x; 
    navio aux = queue->primeiro->ship;

    verificador = 0;                                                        //variável que verifica em qual pilha da travessa o navio deve desempilhar.
    desempilhou = 0;                                                        //variável que verifica qual pilha do navio deve ser desempilhada.

    if(t->t1.tamanho != 5 && verificador != 1){                             //verifica se a pilha da travessa está cheia, se estiver, e nenhuma outra travessa foi usada, ela continua o procedimento.
        verificador = 1;
        if(aux.pc1.topo != aux.pc1.fundo && desempilhou != 1){              //verifica se a pilha não está vazia e se nenhuma outra pilha já foi desempilhada (o desmpilhou no primeiro if é mais pra questão de estética).
            desempilha(&aux.pc1, x);
            desempilhou = 1;
        }
        if(aux.pc2.topo != aux.pc2.fundo && desempilhou != 1){
            desempilha(&aux.pc2, x);
            desempilhou = 1;
        }
        if(aux.pc3.topo != aux.pc3.fundo && desempilhou != 1){
            desempilha(&aux.pc3, x);
            desempilhou = 1;
        }
        if(aux.pc4.topo != aux.pc4.fundo && desempilhou != 1){
            desempilha(&aux.pc4, x);
            desempilhou = 1;
        }
    }

    if(t->t2.tamanho != 5 && verificador != 1){
        verificador = 1;
        if(aux.pc1.topo != aux.pc1.fundo && desempilhou != 1){          
            desempilha(&aux.pc1, x);
            desempilhou = 1;
        }
        if(aux.pc2.topo != aux.pc2.fundo && desempilhou != 1){
            desempilha(&aux.pc2, x);
            desempilhou = 1;
        }
        if(aux.pc3.topo != aux.pc3.fundo && desempilhou != 1){
            desempilha(&aux.pc3, x);
            desempilhou = 1;
        }
        if(aux.pc4.topo != aux.pc4.fundo && desempilhou != 1){
            desempilha(&aux.pc4, x);
            desempilhou = 1;
        }
    }

    if(t->t3.tamanho != 5 && verificador != 1){
        verificador = 1;
        if(aux.pc1.topo != aux.pc1.fundo && desempilhou != 1){          //verifica se a pilha não está vazia e se nenhuma outra pilha já foi desempilhada (o desmpilhou no primeiro if é mais pra questão de estética).
            desempilha(&aux.pc1, x);
            desempilhou = 1;
        }
        if(aux.pc2.topo != aux.pc2.fundo && desempilhou != 1){
            desempilha(&aux.pc2, x);
            desempilhou = 1;
        }
        if(aux.pc3.topo != aux.pc3.fundo && desempilhou != 1){
            desempilha(&aux.pc3, x);
            desempilhou = 1;
        }
        if(aux.pc4.topo != aux.pc4.fundo && desempilhou != 1){
            desempilha(&aux.pc4, x);
            desempilhou = 1;
        }
    }

    if(t->t4.tamanho != 5 && verificador != 1){
        verificador = 1;
        if(aux.pc1.topo != aux.pc1.fundo && desempilhou != 1){          //verifica se a pilha não está vazia e se nenhuma outra pilha já foi desempilhada (o desmpilhou no primeiro if é mais pra questão de estética).
            desempilha(&aux.pc1, x);
            desempilhou = 1;
        }
        if(aux.pc2.topo != aux.pc2.fundo && desempilhou != 1){
            desempilha(&aux.pc2, x);
            desempilhou = 1;
        }
        if(aux.pc3.topo != aux.pc3.fundo && desempilhou != 1){
            desempilha(&aux.pc3, x);
            desempilhou = 1;
        }
        if(aux.pc4.topo != aux.pc4.fundo && desempilhou != 1){
            desempilha(&aux.pc4, x);
            desempilhou = 1;
        }
    }

    if(t->t5.tamanho != 5 && verificador != 1){
        verificador = 1;
        if(aux.pc1.topo != aux.pc1.fundo && desempilhou != 1){          //verifica se a pilha não está vazia e se nenhuma outra pilha já foi desempilhada (o desmpilhou no primeiro if é mais pra questão de estética).
            desempilha(&aux.pc1, x);
            desempilhou = 1;
        }
        if(aux.pc2.topo != aux.pc2.fundo && desempilhou != 1){
            desempilha(&aux.pc2, x);
            desempilhou = 1;
        }
        if(aux.pc3.topo != aux.pc3.fundo && desempilhou != 1){
            desempilha(&aux.pc3, x);
            desempilhou = 1;
        }
        if(aux.pc4.topo != aux.pc4.fundo && desempilhou != 1){
            desempilha(&aux.pc4, x);
            desempilhou = 1;
        }
    }
    imprimeNavio(aux);
    queue->primeiro->ship = aux;
    if(aux.pc1.topo == aux.pc1.fundo && aux.pc2.topo == aux.pc2.fundo && aux.pc3.topo == aux.pc3.fundo && aux.pc4.topo == aux.pc4.fundo)
        desenfileira(queue, &aux);
    sleep(3);
}

void armazenar(pilha *t){
    Pilha(t);
    printf("Um carro levou a pilha da travessa para a área de armazenamento\n\n");
}

void passaTempo(af pointer){                                           //Função que incrementa o tempo passado na fila de cada navio
    if(pointer->prox != NULL)
        passaTempo(pointer->prox);
    else
        pointer->ship.ut++;
}

int calculaMt(af pointer){                                            //função que calcula a média de tempo;
    int temponavios = 0;
    if(pointer->prox != NULL)
        calculaMt(pointer->prox);
    else
        return temponavios = temponavios + pointer->ship.ut;
}

void relatorio(fila fa1, fila fa2, fila fa3, fila fa4, travessa t1, travessa t2, travessa t3, travessa t4, int mt1, int mt2, int mt3, int mt4){
    printf("\n////////////////////////////////////\n");
    printf("\tRELATORIO\n\n");
    printf("\n\tFILA DE BARCOS 1: \n\n");
    imprimeF(fa1.primeiro);
    printf("O tempo médio de espera na fila 1 é de %d unidades de tempo.\n\n", mt1);
    sleep(5);
    printf("\n\tFILA DE BARCOS 2: \n\n");
    imprimeF(fa2.primeiro);
    printf("O tempo médio de espera na fila 2 é de %d unidades de tempo.\n\n", mt2);
    sleep(5);
    printf("\n\tFILA DE BARCOS 3: \n\n");
    imprimeF(fa3.primeiro);
    printf("O tempo médio de espera na fila 3 é de %d unidades de tempo.\n\n", mt3);
    sleep(5);
    printf("\n\tFILA DE BARCOS 4: \n\n");
    imprimeF(fa4.primeiro);
    printf("O tempo médio de espera na fila 3 é de %d unidades de tempo.\n\n", mt4);
    sleep(5);
    printf("\n\n\tTRAVESSA 1:\n\n");
    imprimeTravessa(t1);
    sleep(5);
    printf("\n\n\tTRAVESSA 2:\n\n");
    imprimeTravessa(t1);
    sleep(5);
    printf("\n\n\tTRAVESSA 3:\n\n");
    imprimeTravessa(t1);
    sleep(5);
    printf("\n\n\tTRAVESSA 4:\n\n");
    imprimeTravessa(t1);
    sleep(5);
    printf("////////////////////////////////////\n\n");
    sleep(10);
}


