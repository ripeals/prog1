#include <stdio.h>
#include "veiculo.h"
#include "estruturas.h"
#include "constantes.h"
#include "funcoes_auxiliares.h"

void menuVeiculo(){
    int numVeiculos,opcao=0;
    tipoVeiculos veiculos[MAX_VEICULOS];
    //char matricula[MAX_MATRICULA];
    numVeiculos=0;
    opcao=0;

    printf("\t\t\t\tMenu dos Veiculos");
    printf("\n\t1 - Inserir Veiculo");
    printf("\n\t2 - Consultar Veciulo");
    printf("\n\t3 - Listar Veiculo");
    printf("\n\tOpcao: ");
    scanf("%d",&opcao);

    switch(opcao){
        case 1:
            inserirVeiculo(veiculos,&numVeiculos/*,matricula*/);
            numVeiculos++;
            break;
        case 2:
            //consultarVeiculo(veiculos,&numVeiculos);
            break;
        case 3:
            listarVeiculos(veiculos,&numVeiculos);
            break;
        default:
            printf("Introduza uma opcao valida");
            break;
    }
}

void inserirVeiculo(tipoVeiculos veiculos[],int *numVeiculos/*, char matricula[MAX_MATRICULA]*/){

    printf("\n\tData de Fabrico: ");
    veiculos[*numVeiculos].dataFabrico=lerData();
    //lerString("\nMatricula: ", matricula, MAX_MATRICULA);
    veiculos[*numVeiculos].cargaMaxima = lerFloat("\n\tCarga maxima: ",MIN_CARGA,MAX_CARGA);
    veiculos[*numVeiculos].estado=1;
}
void listarVeiculos(tipoVeiculos veiculos[],int *numVeiculos){
    int i;
    for(i=0;i<numVeiculos;i++){
        printf("\nData de Fabrico: %d/%d/%d",veiculos[*numVeiculos].dataFabrico.dia, veiculos[*numVeiculos].dataFabrico.mes, veiculos[*numVeiculos].dataFabrico.dia);
        printf("\nCarga maxima: %.2f\n",veiculos[*numVeiculos].cargaMaxima);

    }
}
