#include <stdio.h>
#include <stdlib.h>
#include "veiculo.h"
#include "funcoes_auxiliares.h"
#include "menuVeiculos.h"

int menuVeiculo(tipoVeiculos veiculos[],int numVeiculos){
    int opcao;
    char matricula[MAX_MATRICULA];
    //char matricula[MAX_MATRICULA];
    numVeiculos=0;
    opcao=0;
    do{
        printf("\n\t\t\t\tMenu dos Veiculos");
        printf("\n\t1 - Inserir Veiculo");
        printf("\n\t2 - Consultar");
        printf("\n\t3 - Listar Veiculo");
        printf("\n\t4 - Sair");
        printf("\n\tOpcao: ");
        scanf("%d",&opcao);
        limpaBuffer();

        switch(opcao){
            case 1:
                printf("\n\t\t\t\tInserir Veiculos");
                inserirVeiculo(veiculos,&numVeiculos);
                break;
            case 2:
                menuConsultas(veiculos, numVeiculos,matricula);
                break;
            case 3:
                printf("\n\t\t\t\tListar Veiculos");
                listarVeiculos(veiculos, numVeiculos);
                break;
            case 4:

                break;
            default:
                printf("\tIntroduza uma opcao valida\n\n");
                break;
        }
    }while(opcao!=4);
    return opcao;
}

void menuConsultas(tipoVeiculos veiculos[MAX_VEICULOS], int numVeiculos,char matricula[MAX_MATRICULA]){
    int opcao=0;
    //float cargaMedia=0;
    printf("\n\t\t\t1 - Consultar Veiculos");
    printf("\n\t\t\t2 - Consultar quantidade de veiculos");
    printf("\n\t\t\t3 - Carga media dos veiculos em viagem");
    printf("\n\t\t\t4 - Matricula dos veiculos com menos viagens ");
    scanf("%d",&opcao);
    limpaBuffer();

        switch(opcao){
            case 1:
                printf("\n\t\t\tConsultar Veiculos");
                consultarVeiculos(veiculos,numVeiculos,matricula);
                break;
            case 2:
                printf("\n\t\t\tConsultar quantidade de veiculos");
                printf("\n\t\t\tA quantidade de veiculos existentes no momento e de %d",numVeiculos);
                break;
            case 3:
                printf("\n\t\t\tCarga media dos veiculos em viagem");
               // cargaMedia=cargaMediaVeiculos(veiculos,numVeiculos);
                break;
            case 4:
                break;
        }
}
