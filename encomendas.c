#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "funcoes_auxiliares.h"
#include "estruturas.h"
#include "constantes.h"
#include "encomendas.h"
#include "veiculo.h"

int menuEncomendas(tipoEncomendas encomendas[],int numEncomendas,tipoVeiculos veiculos[],int numVeiculos)
{
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
    }while(opcao != 6);
return opcao;
}

void validaNumRegistoUnico(tipoEncomendas encomendas[],int numEncomendas)
{
    int i;

    for(i=0; i<numEncomendas; i++)
    {
        if(encomendas[i].numRegisto == encomendas[numEncomendas].numRegisto)
        {
            do
            {
                printf("\n\tO numero de registo que inseriu ja existe");
                encomendas[i].numRegisto = lerInteiro("\n\tNumero de Registo ", 1, MAX_NUM_ENCOMENDA);
            }
            while(encomendas[i].numRegisto == encomendas[numEncomendas].numRegisto);

        }
    }
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
        validaNumRegistoUnico(encomendas, *numEncomendas);
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
    printf("\n\tNumero de Registo: %d",encomenda.numRegisto);
    printf("\n\tData de Registo: %d/%d/%d", encomenda.dataRegisto.dia, encomenda.dataRegisto.mes, encomenda.dataRegisto.ano);
    printf("\n\tPeso: %.2f",encomenda.peso);
    printf("\n\tEstado: ");
    switch (encomenda.estado)
    {
        case REGISTADA:
            printf("registada");
            break;
        case CARREGADA:
            printf("carregada");
            break;
        case ENTREGUE:
            printf("entregue");
        case DEVOLVIDA:
            printf("devolvida");
    }
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
    int opcao,posicao,i,j;
    char destino[MAX_STRING],matricula[MAX_MATRICULA];

    opcao=0;
    strcpy(veiculos[numVeiculos].destino,"");
    veiculos[numVeiculos].qtEncomendasT=0;
    veiculos[numVeiculos].qtViagens=0;

    printf("\n\t\t1 - Selecao Automatica");
    printf("\n\t\t2 - Selecao Manual");
    scanf("%d",&opcao);
    limpaBuffer();
    switch(opcao){
        case 1:
            if(numEncomendas == 0){
                printf("\n\t\tERRO: Nao existem encomendas. Por favor insira ");
            }
            else{
                lerString("\n\t\tDestino: ",destino,MAX_STRING);
                for(i=0;i<numVeiculos;i++){
                    if(veiculos[i].estado == DISPONIVEL){
                        if(strcmp(veiculos[i].destino,"")== 0){
                            strcpy(veiculos[i].destino,destino);
                            strcpy(matricula,veiculos[i].matricula);
                            for(j=0;j<numEncomendas;j++){
                                if(encomendas[j].estado == REGISTADA){
                                    strcpy(encomendas[j].matricula,matricula);
                                    printf("\n%s %s",encomendas[j].matricula,matricula);
                                    veiculos[i].estado = EM_CARGA;
                                    printf("\n%d",veiculos[i].estado);
                                    encomendas[j].estado = CARREGADA;
                                    printf("\n%d",encomendas[j].estado);
                                    printf("Encomenda %d carregada",encomendas[j].numRegisto);
                                    veiculos[i].qtEncomendasT++;
                                    inicioViagem(veiculos,numVeiculos,encomendas,numEncomendas);
                                }
                            }
                        }
                        else{
                            for(i=0;i<numVeiculos;i++){
                                if(strcmp(destino,veiculos[i].destino) == 0){
                                    strcpy(matricula,veiculos[i].matricula);
                                    for(j=0;j<numEncomendas;j++){
                                        if(encomendas[j].estado == REGISTADA){
                                            strcpy(encomendas[j].matricula,matricula);
                                            printf("\n%s %s",encomendas[j].matricula,matricula);
                                            veiculos[i].estado = EM_CARGA;
                                            printf("\n%d",veiculos[i].estado);
                                            encomendas[j].estado = CARREGADA;
                                            printf("\n%d",encomendas[j].estado);
                                            printf("Encomenda %d carregada",encomendas[j].numRegisto);
                                            veiculos[i].qtEncomendasT++;
                                            inicioViagem(veiculos,numVeiculos,encomendas,numEncomendas);
                                        }
                                    }
                                }
                            }

                        }
                    }else{
                        printf("\n\t\tEste veiculo nao se encontra disponivel");
                    }
                }


            }
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
                            strcpy(veiculos[posicao].destino, destino);
                            printf("%s",veiculos[posicao].destino);
                        for(i=0;i<numEncomendas;i++){
                            if(encomendas[i].estado == REGISTADA){
                                strcpy(encomendas[i].matricula,veiculos[posicao].matricula);
                                printf("\n%s %s",encomendas[i].matricula,veiculos[posicao].matricula);
                                veiculos[posicao].numEncomendas++;
                                printf("\n%d",numEncomendas);
                                veiculos[posicao].estado = EM_CARGA;
                                printf("\n%d",veiculos[posicao].estado);
                                encomendas[i].estado = CARREGADA;
                                printf("\n%d",encomendas[i].estado);
                                printf("Encomenda %d carregada",encomendas[i].numRegisto);
                                inicioViagem(veiculos,numVeiculos,encomendas,numEncomendas);
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



