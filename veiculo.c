#include <stdio.h>
#include "veiculo.h"
#include "estruturas.h"
#include "constantes.h"
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
        printf("\n\t2 - Consultar Veciulo");
        printf("\n\t3 - Listar Veiculo");
        printf("\n\t4 - Sair");
        printf("\n\tOpcao: ");
        scanf("%d",&opcao);
        limpaBuffer();

        switch(opcao){
            case 1:
                inserirVeiculo(veiculos,&numVeiculos);
                break;
            case 2:
                //consultarVeiculo(veiculos,&numVeiculos);
                break;
            case 3:
                listarVeiculos(veiculos, numVeiculos);
                break;
            case 4:
                break;
        }
    }while(opcao!=4);
}

void inserirVeiculo(tipoVeiculos veiculos[MAX_VEICULOS],int *numVeiculos){
    if(*numVeiculos == MAX_VEICULOS){
        printf("\n\tERRO: Nao e possivel inserir um novo veiculo. Foi atingido o maximo de veiculos.");
    }
    else{
        printf("\n\tData de Fabrico: ");
        veiculos[*numVeiculos].dataFabrico=lerData();
        //lerString("\nMatricula: ", matricula, MAX_MATRICULA);
        veiculos[*numVeiculos].cargaMaxima = lerFloat("\n\tCarga maxima: ",MIN_CARGA,MAX_CARGA);
        veiculos[*numVeiculos].estado=1;
        (*numVeiculos)++;
    }
}

void listarVeiculos(tipoVeiculos veiculos[], int numVeiculos){
    int i;
    if(numVeiculos == 0){
        printf("\n\tNao existem veiculos");
    }
    else{
        for(i=0;i<numVeiculos;i++){
            apresentaDadosVeiculos(veiculos[i]);
        }
    }
}
void apresentaDadosVeiculos(tipoVeiculos veiculo){
    printf("\n\tData de Fabrico: %d/%d/%d",veiculo.dataFabrico.dia, veiculo.dataFabrico.mes, veiculo.dataFabrico.dia);
    printf("\n\tCarga maxima: %.2f\n",veiculo.cargaMaxima);
}
