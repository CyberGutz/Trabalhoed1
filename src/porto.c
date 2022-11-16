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

    //Define o ut do navio em 0 (já que ele ainda não descarregou na travessa)
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

    qtd = rand()%(3 - 1) + 1;

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
    int i;
    int *x;
    navio *aux;
    desenfileira(queue, aux);
    
    i=0;
    while(i!=aux->pc1.tamanho){
        if(aux->pc1.topo != aux->pc1.fundo){
            desempilha(&aux->pc1, x);
            empilha(&t->t1, *x);
            aux->ut++;
            i++;
         }

        if(aux->pc1.topo != aux->pc1.fundo){
            desempilha(&aux->pc1, x);
            empilha(&t->t2, *x);
            aux->ut++;
            i++;
        }

        if(aux->pc1.topo != aux->pc1.fundo){
            desempilha(&aux->pc1, x);
            empilha(&t->t3, *x);
            aux->ut++;
            i++;
        }

        if(aux->pc1.topo != aux->pc1.fundo){
            desempilha(&aux->pc1, x);
            empilha(&t->t4, *x);
            aux->ut++;
            i++;
        }

        if(aux->pc1.topo != aux->pc1.fundo){
            desempilha(&aux->pc1, x);
            empilha(&t->t5, *x);
            aux->ut++;
            i++;
        }

        else
            break;
    } 
    
    i=0;
    while(i!=aux->pc2.tamanho){
        if(aux->pc1.topo != aux->pc2.fundo){
            desempilha(&aux->pc2, x);
            empilha(&t->t1, *x);
            aux->ut++;
            i++;
         }

        if(aux->pc1.topo != aux->pc2.fundo){
            desempilha(&aux->pc2, x);
            empilha(&t->t2, *x);
            aux->ut++;
            i++;
        }

        if(aux->pc1.topo != aux->pc2.fundo){
            desempilha(&aux->pc2, x);
            empilha(&t->t3, *x);
            aux->ut++;
            i++;
        }

        if(aux->pc1.topo != aux->pc2.fundo){
            desempilha(&aux->pc2, x);
            empilha(&t->t4, *x);
            aux->ut++;
            i++;
        }

        if(aux->pc1.topo != aux->pc2.fundo){
            desempilha(&aux->pc2, x);
            empilha(&t->t5, *x);
            aux->ut++;
            i++;
        }

        else
            break;
    }
    
    i=0;
    while(i!=aux->pc2.tamanho){
        if(aux->pc1.topo != aux->pc3.fundo){
            desempilha(&aux->pc3, x);
            empilha(&t->t1, *x);
            aux->ut++;
            i++;
         }

        if(aux->pc1.topo != aux->pc3.fundo){
            desempilha(&aux->pc3, x);
            empilha(&t->t2, *x);
            aux->ut++;
            i++;
        }

        if(aux->pc1.topo != aux->pc3.fundo){
            desempilha(&aux->pc3, x);
            empilha(&t->t3, *x);
            aux->ut++;
            i++;
        }

        if(aux->pc1.topo != aux->pc3.fundo){
            desempilha(&aux->pc3, x);
            empilha(&t->t4, *x);
            aux->ut++;
            i++;
        }

        if(aux->pc1.topo != aux->pc3.fundo){
            desempilha(&aux->pc3, x);
            empilha(&t->t5, *x);
            aux->ut++;
            i++;
        }

        else
            break;
    }
    
    i=0;
    while(i!=aux->pc4.tamanho){
        if(aux->pc1.topo != aux->pc4.fundo){
            desempilha(&aux->pc4, x);
            empilha(&t->t1, *x);
            aux->ut++;
            i++;
         }

        if(aux->pc1.topo != aux->pc4.fundo){
            desempilha(&aux->pc4, x);
            empilha(&t->t2, *x);
            aux->ut++;
            i++;
        }

        if(aux->pc1.topo != aux->pc4.fundo){
            desempilha(&aux->pc4, x);
            empilha(&t->t3, *x);
            aux->ut++;
            i++;
        }

        if(aux->pc1.topo != aux->pc4.fundo){
            desempilha(&aux->pc4, x);
            empilha(&t->t4, *x);
            aux->ut++;
            i++;
        }

        if(aux->pc1.topo != aux->pc4.fundo){
            desempilha(&aux->pc4, x);
            empilha(&t->t5, *x);
            aux->ut++;
            i++;
        }

        else
            break;
    }

    imprimeNavio(*aux);
    sleep(3);
}

void armazenar(travessa *t){
    int i, x;

    i = 0;
    while(i!=t->t1.tamanho){
        desempilha(&t->t1, &x);
        printf("Uma grua levou o container %d da pilha 1 da travessa",x);
        sleep(2);
        i++;
    }

    i = 0;
    while(i!=t->t2.tamanho){
        desempilha(&t->t2, &x);
        printf("Uma grua levou o container %d da pilha 2 da travessa",x);
        sleep(2);
        i++;
    }

    i = 0;
    while(i!=t->t3.tamanho){
        desempilha(&t->t3, &x);
        printf("Uma grua levou o container %d da pilha 3 da travessa",x);
        sleep(2);
        i++;
    }

    i = 0;
    while(i!=t->t4.tamanho){
        desempilha(&t->t4, &x);
        printf("Uma grua levou o container %d da pilha 4 da travessa",x);
        sleep(2);
        i++;
    }

    i = 0;
    while(i!=t->t5.tamanho){
        desempilha(&t->t5, &x);
        printf("Uma grua levou o container %d da pilha 1 da travessa",x);
        sleep(2);
        i++;
    }
}

void relatorio(fila queue, travessa t, tempo time){
    printf("\n////////////////////////////////////\n");
    printf("\tRELATORIO\n\n");
    printf("\n\tFILA DE BARCOS: \n\n");
    imprimeF(queue.primeiro);
    sleep(5);
    printf("\n\n\tTRAVESSA:\n\n");
    imprimeTravessa(t);
    sleep(5);
    printf("Até agora se passaram %d dias e foram gastas no total %d unidades de tempo para descarga dos containers\n\n", time.dia, time.ut);
    printf("////////////////////////////////////\n\n");
    sleep(10);
}


