#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

    //Define o ut do navio em 0 (já que ele ainda não descarregou na travessa)
    ship->ut = 0;

    //Variáveis que identificam quantos containers vão ser empilhados em cada pilha (de 1 a 4)
    rp1 = rand() % (4 + 1 + 1) +1;
    rp2 = rand() % (4 + 1 + 1) +1;
    rp3 = rand() % (4 + 1 + 1) +1;
    rp4 = rand() % (4 + 1 + 1) +1;

    //Empilha os containers
    for(int i=0; i<4; i++){
        for(j=0; j<rp1; j++){
            containerid = rand() % 10000;
            empilha(&ship->pc1, containerid);
        }

        for(j=0; j<rp2; j++){
            containerid = rand() % 10000;
            empilha(&ship->pc2, containerid);
        }

        for(j=0; j<rp3; j++){
            containerid = rand() % 10000;
            empilha(&ship->pc3, containerid);
        }

        for(j=0; j<rp4; j++){
            containerid = rand() % 10000;
            empilha(&ship->pc4, containerid);
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

    printf("\n\tPILHAS DE CONTAINER\n");
    printf("\n--> PILHA 1: \n");
    imprimeP(ship.pc1);
    printf("\n--> PILHA 2: \n");
    imprimeP(ship.pc1);
    printf("\n--> PILHA 3: \n");
    imprimeP(ship.pc1);
    printf("\n--> PILHA 4: \n");
    imprimeP(ship.pc1);

    printf("\n///////////////////////////////////////////////\n");
}

void atracar(navio *ship, fila *queue, int qtd){
    int i;

    for(i = 0; i< qtd; i++){
        criaNavio(ship, *queue);
        enfileira(queue, ship);
        imprimeNavio(*ship);
    }
}

void criaTravessa(travessa *t){
    Pilha(&t->t1);
    Pilha(&t->t2);
    Pilha(&t->t3);
    Pilha(&t->t4);
    Pilha(&t.t5);
}