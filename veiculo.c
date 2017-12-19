#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "veiculo.h"
#include "estruturas.h"
#include "constantes.h"
#include "funcoes_auxiliares.h"


int procuraVeiculo(tipoVeiculos veiculos[],int numVeiculos, char matricula[MAX_MATRICULA]){
    int posicao, i;
    posicao = NAO_EXISTE;

    for(i=0;i<numVeiculos;i++){
        if(strcmp(veiculos[i].matricula, matricula) == 0){
            posicao = i;
            i = numVeiculos;
        }
    }
    return posicao;
}

void inserirVeiculo(tipoVeiculos veiculos[],int *numVeiculos){
    if(*numVeiculos == MAX_VEICULOS){
        printf("\n\tERRO: Nao e possivel inserir um novo veiculo. Foi atingido o maximo de veiculos.");
    }
    else{
        printf("\n\tData de Fabrico: ");
        veiculos[*numVeiculos].dataFabrico = lerData();
        lerString("\n\tInsira a matricula(__-__-__): ",veiculos[*numVeiculos].matricula, MAX_MATRICULA);
        veiculos[*numVeiculos].cargaMaxima = lerFloat("\tCarga maxima: ",MIN_CARGA,MAX_CARGA);
        veiculos[*numVeiculos].estado = 1;
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
    printf("\n\tMatricula: %s",veiculo.matricula);
    printf("\n\tData de Fabrico: %d/%d/%d",veiculo.dataFabrico.dia, veiculo.dataFabrico.mes, veiculo.dataFabrico.ano);
    printf("\n\tCarga maxima: %.2f",veiculo.cargaMaxima);
    printf("\n\tEstado: ");
    switch (veiculo.estado)
    {
        case DISPONIVEL:
            printf("disponivel");
            break;
        case EM_CARGA:
            printf("em carga");
            break;
        case A_TRANSPORTAR:
            printf("a transportar encomendas");
        case DE_REGRESSO:
            printf("esta de volta");
        case AVARIADO:
            printf("esta avariado");
    }
}
void consultarVeiculos(tipoVeiculos veiculos[], int numVeiculos, char matricula[MAX_MATRICULA]){//ainda nao funciona
    int posicao;
    if(numVeiculos == 0){
        printf("\n\tATENCAO: nao existem veiculos inseridos");
    }
    else{
        lerString("\n\tInsira a matricula(__-__-__): ",matricula, MAX_MATRICULA);
        posicao = procuraVeiculo(veiculos,numVeiculos,matricula);

        if(posicao == NAO_EXISTE){//nao existe no vetor
            printf("\nO veiculo com a %s matricula nao existe.",matricula);
        }
        else{
            apresentaDadosVeiculos(veiculos[posicao]);
        }
    }

}
float cargaMediaVeiculos(tipoVeiculos veiculos[MAX_VEICULOS],int numVeiculos){
    int i;
    float carga,cargaMedia;
    carga=0;
    cargaMedia=0;
    if(numVeiculos == 0){
        printf("\n\tNao existem veiculos");
    }
    else{
        for (i=0;i<numVeiculos;i++){
            if(veiculos[i].estado==A_TRANSPORTAR){
                carga+=veiculos[i].cargaMaxima;
            }
            else{
                printf("\n\t\t\tNao e possivel mostrar a carga media dos veiculos em viagem, porque de momento nao existe nenhum veiculo em viagem.");
            }
        }
        cargaMedia=carga/numVeiculos;
        printf("\n\t\t\tA carga media dos veiculos em viagem e de %.2f",cargaMedia);
    }
    return cargaMedia;
}

