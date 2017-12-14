#include <stdio.h>
#include "veiculo.h"
#include "estruturas.h"
#include "constantes.h"
#include "funcoes_auxiliares.h"

void menuVeiculo(){
    int numVeiculos,opcao=0;
    tipoVeiculos veiculos[MAX_VEICULOS];

    numVeiculos=0;
    opcao=0;

    printf("\t\tMenu dos Veiculos");
    printf("\n\t1 - Inserir Veiculo");
    printf("\n\t2 - Consultar Veciulo");
    printf("\n\t3 - Listar Veiculo");
    printf("\n\tOpcao: ");
    scanf("%d",&opcao);

    switch(opcao){
        case 1:
            inserirVeiculo(veiculos,&numVeiculos);
            numVeiculos++;
            break;
        case 2:
            //consultarVeiculo();
            break;
        case 3:
            //listarVeiculo();
            break;
        default:
            printf("Introduza uma opcao valida");
            break;
    }
}
void inserirVeiculo(tipoVeiculos veiculos[],int *numVeiculos){
    veiculos[*numVeiculos].dataFabrico=lerData();
    //lerString("\n\tMatricula: ",veiculo.matricula,8);
    //toupper(veiculo.matricula);

    veiculos[*numVeiculos].cargaMaxima = lerInteiro("\n\tCarga maxima: ",MIN_CARGA,MAX_CARGA);
    veiculos[*numVeiculos].estado=1;
}
