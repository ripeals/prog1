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

    int opcaoEncomendas;
    printf("\n\t\t\t\tMenu das Encomendas");
    printf("\n\t1 - Inserir encomendas");
    printf("\n\t2 - Consultar encomendas");
    printf("\n\t3 - Listar encomendas");
    printf("\n\tOpcao: ");
    scanf("%d", &opcaoEncomendas);
    switch(opcaoEncomendas)
    {
    case 1:
        printf("\n\t\t\tInserir Encomendas");
        inserirEncomendas(encomendas, &numEncomendas);
        numEncomendas++;
        break;
    case 2:
        printf("\n\t\t\tConsultar Encomendas");
        break;
    case 3:
        printf("\n\t\t\tListar Encomendas");
        break;
    default:
        printf("\nA opcao inserida nao e valida. Introduza uma opcao valida");
        break;
    }

}


void inserirEncomendas (tipoEncomendas encomendas[], int *numEncomendas){
   // char destino[MAX_STRING];

    encomendas[*numEncomendas].numRegisto = lerInteiro("\n\tNumero de Registo ",1,MAX_NUM_ENCOMENDA);
    printf("\tData de Registo: ");
    encomendas[*numEncomendas].dataRegisto = lerData();
    encomendas[*numEncomendas].peso = lerFloat("\tPeso: ",1.00,MAX_PESO);
    //encomendas[*numEncomendas].destino = lerString("\nDestino: ",
    encomendas[*numEncomendas].estado=1;
    //encomendas[*numEncomendas].obs = lerString("\nObservacoes: ",encomendas[*numEncomendas].obs, MAX_STRING );







}
