#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "porto.h"

int main(){
    //Variáveis estruturadas
    tempo time;
    fila *queue;
    travessa *t;

    //Variável de escolha
    int op;

    //Inicialização da fila e travessas.
    Fila(queue);
    criaTravessa(t);

    //Começa a simulação
    printf("****************** SIMULADOR DE PORTO ******************\n\n");
    printf("Digite quantas simulações você deseja fazer: ");
    scanf("%d*c",&op);                                                      //O usuário escole quantas simulações do porto ele vai ver.
    do{
        atracar(queue);                                                     //Cria e enfileira os navios pra atracamento
        desembarcar(queue, t);                                              //Desembarca os containers nas travessas e desenfileira os navios
        sleep(2);
        imprimeTravessa(*t);                                                //Mostra o conteúdo das travessas
        armazenar(t);                                                       //Gruas armazenam os conteúdos das travessas

        relatorio(*queue, *t, time);                                        //Faz o relatório do dia

        if(fvazia(*queue)){                                                 //Se a fila estiver vazia no final do dia, ela reseta (relevante para os id's dos navios)
            Fila(queue);
        }

        time.dia++;                                                         //Finaliza o dia
    } while (time.dia != op);

    relatorio(*queue, *t, time);
    
    exit(0);
}
