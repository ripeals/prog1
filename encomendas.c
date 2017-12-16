#include <stdio.h>
#include <stdlib.h>
#include "funcoes_auxiliares.h"
#include "estruturas.h"
#include "constantes.h"
#include "encomendas.h"

void menuEncomendas()
{
    tipoEncomendas encomendas[MAX_ENCOMENDAS];
    int numEncomendas=0;
    int opcao=0;
    do{
        printf("\n\t\t\t\tMenu das Encomendas");
        printf("\n\t1 - Inserir encomendas");
        printf("\n\t2 - Consultar encomendas");
        printf("\n\t3 - Listar encomendas");
        printf("\n\t4 - Sair");
        printf("\n\tOpcao: ");
        scanf("%d", &opcao);
        switch(opcao)
        {
        case 1:
            printf("\n\t\t\tInserir Encomendas");
            inserirEncomendas(encomendas, &numEncomendas);
            break;
        case 2:
            printf("\n\t\t\tConsultar Encomendas");
            break;
        case 3:
            printf("\n\t\t\tListar Encomendas");
            listarEncomendas (encomendas, numEncomendas);
            break;
        case 4:
            break;
        }
    }while(opcao != 4);

}


void inserirEncomendas (tipoEncomendas encomendas[MAX_ENCOMENDAS], int *numEncomendas){
    if(*numEncomendas == MAX_ENCOMENDAS){
         printf("\n\tERRO: Nao e possivel inserir uma nova encomenda. Foi atingido o maximo das encomendas.");
    }
    else{
        encomendas[*numEncomendas].numRegisto = lerInteiro("\n\tNumero de Registo ",1,MAX_NUM_ENCOMENDA);
        printf("\tData de Registo: ");
        encomendas[*numEncomendas].dataRegisto = lerData();
        encomendas[*numEncomendas].peso = lerFloat("\tPeso: ",1.00,MAX_PESO);
        lerString("\tDestino: ", encomendas[*numEncomendas].destino, MAX_STRING);
        encomendas[*numEncomendas].estado=1;
        lerString("\tObservacoes: ", encomendas[*numEncomendas].obs, MAX_STRING );
        (*numEncomendas)++;
    }
}

void listarEncomendas (tipoEncomendas encomendas[], int numEncomendas){
    int i;
    if(numEncomendas == 0){
        printf("\n\tNao existem encomendas");
    }
    else{
        for(i=0;i<numEncomendas;i++){
            apresentaDadosEncomendas(encomendas[i]);
        }
    }
}
void apresentaDadosEncomendas(tipoEncomendas encomenda){
    printf("\n\tNumero de Registo: %d",encomenda.numRegisto);
    printf("\n\tData de Registo: %d/%d/%d", encomenda.dataRegisto.dia, encomenda.dataRegisto.mes, encomenda.dataRegisto.ano);
    printf("\n\tPeso: %.2f",encomenda.peso);
    printf("\n\tDestino: %s", encomenda.destino);
    printf("\n\tObservacoes: %s",encomenda.obs);
}

//}
