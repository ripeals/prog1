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
<<<<<<< HEAD
tipoVeiculos inserirVeiculo(){
    int tamanho,i;
    //veiculo.dataFrabrico=lerData();
    tipoVeiculos veiculo;
    //lerString("\n\tMatricula: ",veiculo.matricula,8);
    //toupper(veiculo.matricula);

    veiculo.cargaMaxima = lerInteiro("\n\tCarga maxima: ",MIN_CARGA,MAX_CARGA);
    veiculo.estado=1;
=======


void inserirVeiculo(tipoVeiculos veiculos[],int *numVeiculos/*, char matricula[MAX_MATRICULA]*/){

    printf("\n\tData de Fabrico: ");
    veiculos[*numVeiculos].dataFabrico=lerData();
    //lerString("\nMatricula: ", matricula, MAX_MATRICULA);




    veiculos[*numVeiculos].cargaMaxima = lerInteiro("\n\tCarga maxima: ",MIN_CARGA,MAX_CARGA);
    veiculos[*numVeiculos].estado=1;
>>>>>>> d2dedc5fc11337dacf6af15c23e94fd18b179c40
}
