#include <stdio.h>
#include "estruturas.h"
#include "veiculo.h"
#include "funcoes_auxiliares.h"

void menuVeiculo(){
    int numVeiculos,opcao;
    tipoVeiculos veiculos[MAX_VEICULOS];
    //char matricula[MAX_MATRICULA];
    numVeiculos=0;
    opcao=0;
    do{
        printf("\t\t\t\tMenu dos Veiculos");
        printf("\n\t1 - Inserir Veiculo");
        printf("\n\t2 - Consultar");
        printf("\n\t3 - Listar Veiculo");
        printf("\n\t4 - Sair");
        printf("\n\tOpcao: ");
        scanf("%d",&opcao);
        limpaBuffer();

        switch(opcao){
            case 1:
                printf("\n\t\t\tInserir Veiculos");
                inserirVeiculo(veiculos,&numVeiculos);
                break;
            case 2:
                menuConsultas(veiculos, numVeiculos);
                break;
            case 3:
                printf("\n\t\t\tListar Veiculos");
                listarVeiculos(veiculos, numVeiculos);
                break;
            case 4:
                break;
        }
    }while(opcao!=4);

}
void menuConsultas(tipoVeiculos veiculos[MAX_VEICULOS], int numVeiculos){
    int opcao=0;
    float cargaMedia=0;
    printf("\n\t\t\t1 - Consultar Veiculos");
    printf("\n\t\t\t2 - Consultar quantidade de veiculos");
    printf("\n\t\t\t3 - Carga media dos veiculos em viagem");
    printf("\n\t\t\t4 - Matricula dos veiculos com menos viagens ");
    scanf("%d",&opcao);
    limpaBuffer();

        switch(opcao){
            case 1:
                printf("\n\t\t\tConsultar Veiculos");
                //consultarVeiculos();
                break;
            case 2:
                printf("\n\t\t\tConsultar quantidade de veiculos");
                printf("\n\t\t\tA quantidade de veiculos existentes no momento e de %d",numVeiculos);
                break;
            case 3:
                printf("\n\t\t\tCarga media dos veiculos em viagem");
                cargaMedia=cargaMediaVeiculos(veiculos,numVeiculos);
                break;
            case 4:
                break;
        }
}
