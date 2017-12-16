#include <stdio.h>
#include "veiculo.h"
#include "estruturas.h"
#include "constantes.h"
#include "funcoes_auxiliares.h"


void procuraVeiculo(tipoVeiculos veiculos[MAX_VEICULOS],int numVeiculos){//nao esta a funcionar
    int posicao, i;
    posicao=-1;

    for(i=0;i<numVeiculos;i++){
        if(veiculos[i].matricula == matricula){
            posicao =i;
            i = numVeiculos;
        }
    }
    return posicao;
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
void consultarVeiculos(tipoVeiculos veiculos[], int numVeiculos){//ainda nao funciona
    int posicao;
    if(numVeiculos == 0){
        printf("\n\tATENCAO: nao existem veiculos inseridos");
    }
    else{
        posicao = procuraVeiculo(veiculos,numVeiculos,matricula);

        if(posicao == -1){//nao existe no vetor
            printf("O veiculos com a %s matricula nao existe.",matricula);
        }
        else{
            apresentaDadosVeiculos(veiculos[posicao],0);
        }
    }

}
int quantidadeVeiculos(numVeiculos)
