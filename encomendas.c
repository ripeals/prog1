#include <stdio.h>
#include <stdlib.h>
#include "funcoes_auxiliares.h"
#include "estruturas.h"
#include "constantes.h"
#include "encomendas.h"
#include "veiculo.h"

void menuEncomendas()
{
    tipoEncomendas encomendas[MAX_ENCOMENDAS];
    tipoVeiculos veiculos[MAX_VEICULOS];
    int numVeiculos=0;
    int numEncomendas=0;
    int opcao=0;
    do
    {
        printf("\n\t\t\t\tMenu das Encomendas");
        printf("\n\t1 - Inserir encomendas");
        printf("\n\t2 - Consultar encomendas");
        printf("\n\t3 - Listar encomendas");
        printf("\n\t4 - Eliminar encomendas");
        printf("\n\t5 - Carregamento de encomendas");
        printf("\n\t6 - Sair");
        printf("\n\tOpcao: ");
        scanf("%d", &opcao);
        switch(opcao)
        {
        case 1:
            printf("\n\t\t\t\tInserir Encomendas");
            inserirEncomendas(encomendas, &numEncomendas);
            break;
        case 2:
            printf("\n\t\t\t\tConsultar Encomendas");
            consultarEncomendas(encomendas, numEncomendas);
            break;
        case 3:
            printf("\n\t\t\t\tListar Encomendas");
            listarEncomendas (encomendas, numEncomendas);
            break;
        case 4:
            printf("\n\t\t\t\tEliminar Encomenda");
            numEncomendas=eliminarEncomendas(encomendas, numEncomendas);
            break;
        case 5:
            printf("\n\t\t\tCarregamento de Encomendas");
            carregamentoEncomendas(encomendas,numEncomendas,veiculos,numVeiculos);
            break;
        default:
            printf("Por favor, introduza uma opcao valida.");
        }
    }
    while(opcao != 6);

}


void inserirEncomendas (tipoEncomendas encomendas[], int *numEncomendas)
{
    if(*numEncomendas == MAX_ENCOMENDAS)
    {
        printf("\n\tERRO: Nao e possivel inserir uma nova encomenda. Foi atingido o maximo das encomendas.");
    }
    else
    {
        encomendas[*numEncomendas].numRegisto = lerInteiro("\n\n\tNumero de Registo ",1,MAX_NUM_ENCOMENDA);
        printf("\tData de Registo: ");
        encomendas[*numEncomendas].dataRegisto = lerData();
        encomendas[*numEncomendas].peso = lerFloat("\tPeso: ",1.00,MAX_PESO);
        lerString("\tDestino: ", encomendas[*numEncomendas].destino, MAX_STRING);
        lerString("\tObservacoes: ", encomendas[*numEncomendas].obs, MAX_STRING );
        encomendas[*numEncomendas].estado=REGISTADA;
        (*numEncomendas)++;
    }
}

void listarEncomendas (tipoEncomendas encomendas[], int numEncomendas)
{
    int i;
    if(numEncomendas == 0)
    {
        printf("\n\tNao existem encomendas");
    }
    else
    {
        for(i=0; i<numEncomendas; i++)
        {
            apresentaDadosEncomendas(encomendas[i]);
        }
    }
}
void apresentaDadosEncomendas(tipoEncomendas encomenda)
{
    printf("\n\n\tNumero de Registo: %d",encomenda.numRegisto);
    printf("\n\tData de Registo: %d/%d/%d", encomenda.dataRegisto.dia, encomenda.dataRegisto.mes, encomenda.dataRegisto.ano);
    printf("\n\tPeso: %.2f",encomenda.peso);
    printf("\n\tDestino: %s", encomenda.destino);
    printf("\tObservacoes: %s",encomenda.obs);
}

int procuraEncomendas (tipoEncomendas encomendas [], int numEncomendas, int numRegisto)
{
    int posicao, i;
    posicao = NAO_EXISTE;
    for(i=0; i<numEncomendas; i++)
    {
        if(encomendas[i].numRegisto == numRegisto)
        {
            posicao = i;
            i=numEncomendas;
        }
    }
    return posicao;
}

void consultarEncomendas (tipoEncomendas encomendas [], int numEncomendas)
{
    int posicao,numRegisto;
    if(numEncomendas == 0)
    {
        printf("\n\tATENCAO: Nao existem encomendas. Por favor, insira.");
    }
    else
    {
        numRegisto = lerInteiro("\n\n\tNumero de registo: ",1,MAX_NUM_ENCOMENDA);
        posicao = procuraEncomendas(encomendas, numEncomendas, numRegisto);

        if(posicao == NAO_EXISTE) //nao existe no vetor
        {
            printf("\n\tA encomenda com o numero de registo %d nao e valida ",numRegisto);
        }
        else
        {
            apresentaDadosEncomendas(encomendas[posicao]);
        }
    }
}

int eliminarEncomendas (tipoEncomendas encomendas [], int numEncomendas)
{
    int posicao, numRegisto, i;
    if(numEncomendas == 0)
    {
        printf("\n\tERRO: Nao existem encomendas. Por favor insira ");
    }
    else
    {
        numRegisto = lerInteiro("\n\n\tNumero de Registo: ",1, MAX_NUM_ENCOMENDA);
        posicao = procuraEncomendas(encomendas, numEncomendas, numRegisto);
        if(posicao==NAO_EXISTE)
        {
            do
            {
                printf("\n\tPor favor insira um numero de registo valido.");
                numRegisto = lerInteiro("\n\t\tNumero de Registo: ",1, MAX_NUM_ENCOMENDA);
            }
            while (numRegisto>1 || numRegisto<MAX_NUM_ENCOMENDA);
        }
        else
        {
            for(i=posicao; i<numEncomendas; i++)
            {
                encomendas[i]=encomendas[i+1]; //?
            }
            numEncomendas--;
            printf("\n\t - Encomenda eliminada com sucesso - \n\n");
        }

    }
    return numEncomendas;
}
void carregamentoEncomendas(tipoEncomendas encomendas[], int numEncomendas,tipoVeiculos veiculos[],int numVeiculos){
    int numDeEncomendas,opcao,posicao,i;
    char destino[MAX_STRING],matricula[MAX_MATRICULA];

    numDeEncomendas=0;
    opcao=0;

    printf("\n\t\t1 - Selecao Automatica");
    printf("\n\t\t2 - Selecao Manual");
    scanf("%d",&opcao);
    limpaBuffer();
    switch(opcao){
        case 1:
            break;
        case 2:
            if(numEncomendas == 0){
                printf("\n\t\tERRO: Nao existem encomendas. Por favor insira ");
            }
            else{
                lerString("\n\t\tDestino: ",destino,MAX_STRING);
                lerString("\n\tInsira a matricula(__-__-__): ", matricula, MAX_MATRICULA);
                printf("%s",matricula);
                posicao = procuraVeiculo(veiculos,numVeiculos,matricula);
                printf("%d",posicao);
                if(posicao == NAO_EXISTE){
                    printf("\n\t\tNao existe nenhum veiculo com a matricula que introduziu.");
                }
                else{
                    if(veiculos[posicao].estado == DISPONIVEL){
                        for(i=0;i<numEncomendas;i++){
                            if(encomendas[i].estado == REGISTADA){
                                numDeEncomendas++;
                                encomendas[i].estado == CARREGADA;
                                veiculos[posicao].estado == EM_CARGA;
                                printf("Encomenda %d carregada",encomendas[i].numRegisto);
                            }
                        }
                    }
                    else{
                        printf("\n\t\tEste veiculo nao se encontra disponivel");
                    }
                }
            }
            break;

    }
}

float pesoMedioEncomendas(tipoEncomendas encomendas[], int numEncomendas)
{
    int i;
    float pesoMedio, soma;
    soma=0;
    pesoMedio=0;

    if(numEncomendas==0)
    {
        printf("\nNao existem encomendas. Por favor insira");

    }
    else
    {
        for(i=0; i<numEncomendas; i++)
        {
            soma+= encomendas[i].peso;
        }
        pesoMedio=soma/numEncomendas;
    }

    return pesoMedio;

}
