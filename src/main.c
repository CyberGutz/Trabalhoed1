#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "porto.h"

int main(){
    printf("oi");
    //Variáveis estruturadas
    fila *fa1, *fa2, *fa3, *fa4;
    travessa *t1, *t2, *t3, *t4;

    //Variável de escolha
    int op;

    //controles
    int ut = 0;
    int mt1 = 0;
    int mt2 = 0;
    int mt3 = 0;
    int mt4 = 0;
    int carro1, carro2, carro3, carro4;

    carro1 = 0;
    carro2 = 0;
    carro3 = 0;
    carro4 = 0;

    //Inicialização da fila e travessas.
    Fila(fa1);
    Fila(fa2);
    Fila(fa3);
    Fila(fa4);
    criaTravessa(t1);
    criaTravessa(t2);
    criaTravessa(t3);
    criaTravessa(t4);

    //Começa a simulação
    printf("****************** SIMULADOR DE PORTO ******************\n\n");
    printf("Digite quantas simulações você deseja fazer: ");
    scanf("%d*c",&op);                                                      //O usuário escole quantas simulações do porto ele vai ver.
    do{
        atracar(fa1);                                                     //Cria e enfileira os navios pra atracamento
        atracar(fa2);
        atracar(fa3);
        atracar(fa4);
        desembarcar(fa1, t1);                                              //Desembarca os containers nas travessas e desenfileira os navios
        desembarcar(fa2, t2);
        desembarcar(fa3, t3);
        desembarcar(fa4, t4);

        //Se o tempo dos carros foi completado, ele é reiniciado para poder armazenar de novo
        if(carro1 == 2)
            carro1 =0;
        if(carro2 == 2)
            carro2 =0;
        if(carro3 == 2)
            carro3 =0;
        if(carro4 == 2)
            carro4 =0;

        //Envelhece os carros, se eles foram armazenar na ultima iteração
        if(carro1 == 1)
            carro1 ++;
        if(carro2 == 1)
            carro2 ++;
        if(carro3 == 1)
            carro3 ++;
        if(carro4 == 1)
            carro4 ++;

        //Verifica se a pilha está cheia e se o carro está disponível
        if(t1->t1.tamanho == 5 && carro1 == 0){
            carro1 = 1;
            armazenar(&t1->t1);
        }
        if(t1->t2.tamanho == 5 && carro1 == 0){
            carro1 = 1;
            armazenar(&t1->t1);
        }
        if(t1->t3.tamanho == 5 && carro1 == 0){
            carro1 = 1;
            armazenar(&t1->t1);
        }
        if(t1->t4.tamanho == 5 && carro1 == 0){
            carro1 = 1;
            armazenar(&t1->t1);
        }
        if(t1->t5.tamanho == 5 && carro1 == 0){
            carro1 = 1;
            armazenar(&t1->t1);
        }


        if(t2->t1.tamanho == 5 && carro1 == 0){
            carro1 = 1;
            armazenar(&t1->t1);
        }
        if(t2->t2.tamanho == 5 && carro1 == 0){
            carro1 = 1;
            armazenar(&t1->t1);
        }
        if(t2->t3.tamanho == 5 && carro1 == 0){
            carro1 = 1;
            armazenar(&t1->t1);
        }
        if(t2->t4.tamanho == 5 && carro1 == 0){
            carro1 = 1;
            armazenar(&t1->t1);
        }
        if(t2->t5.tamanho == 5 && carro1 == 0){
            carro1 = 1;
            armazenar(&t1->t1);
        }


        if(t3->t1.tamanho == 5 && carro1 == 0){
            carro1 = 1;
            armazenar(&t1->t1);
        }
        if(t3->t2.tamanho == 5 && carro1 == 0){
            carro1 = 1;
            armazenar(&t1->t1);
        }
        if(t3->t3.tamanho == 5 && carro1 == 0){
            carro1 = 1;
            armazenar(&t1->t1);
        }
        if(t3->t4.tamanho == 5 && carro1 == 0){
            carro1 = 1;
            armazenar(&t1->t1);
        }
        if(t3->t5.tamanho == 5 && carro1 == 0){
            carro1 = 1;
            armazenar(&t1->t1);
        }


        if(t4->t1.tamanho == 5 && carro1 == 0){
            carro1 = 1;
            armazenar(&t1->t1);
        }
        if(t4->t2.tamanho == 5 && carro1 == 0){
            carro1 = 1;
            armazenar(&t1->t1);
        }
        if(t4->t3.tamanho == 5 && carro1 == 0){
            carro1 = 1;
            armazenar(&t1->t1);
        }
        if(t4->t4.tamanho == 5 && carro1 == 0){
            carro1 = 1;
            armazenar(&t1->t1);
        }
        if(t4->t5.tamanho == 5 && carro1 == 0){
            carro1 = 1;
            armazenar(&t1->t1);
        }
        
        sleep(2);

        imprimeTravessa(*t1);                                                //Mostra o conteúdo das travessas
        imprimeTravessa(*t2);
        imprimeTravessa(*t3);
        imprimeTravessa(*t4);

        passaTempo(fa1->primeiro);                                                    //Incrementa o ut passado na fila dos navios
        passaTempo(fa2->primeiro);
        passaTempo(fa3->primeiro);
        passaTempo(fa4->primeiro);

        mt1 = calculaMt(fa1->primeiro)/ut;                                             //Calcula a média de tempo na fila (soma do ut dos navios / ut total)
        mt2 = calculaMt(fa2->primeiro)/ut;
        mt3 = calculaMt(fa3->primeiro)/ut;
        mt4 = calculaMt(fa4->primeiro)/ut;
        
        relatorio(*fa1, *fa2, *fa3, *fa4, *t1, *t2, *t3, *t4, mt1, mt2, mt3, mt4);                                          //Faz o relatório do dia
        
        if(fvazia(*fa1)){                                                   //Se a fila estiver vazia no final do dia, ela reseta (relevante para os id's dos navios)
            Fila(fa1);
        }

        if(fvazia(*fa2)){
            Fila(fa2);
        }

        if(fvazia(*fa3)){
            Fila(fa3);
        }

        if(fvazia(*fa4)){
            Fila(fa4);
        }

        ut++;                                                               //Conta mais uma iteração
    } while (ut != op);
    
    exit(0);
}
