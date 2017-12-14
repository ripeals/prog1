#include <stdio.h>
#include "veiculo.h"
#include "estruturas.h"
#include "constantes.h"

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
            veiculos[numVeiculos] = inserirVeiculo();
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
tipoVeiculos inserirVeiculo(){
    int tamanho,i;
    //veiculo.dataFrabrico=lerData();
    tipoVeiculos veiculo;
    //lerString("\n\tMatricula: ",veiculo.matricula,8);
    //toupper(veiculo.matricula);

    veiculo.cargaMaxima = lerInteiro("\n\tCarga maxima: ",MIN_CARGA,MAX_CARGA);
    veiculo.estado=1;
}
