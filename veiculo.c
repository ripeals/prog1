#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "veiculo.h"
#include "estruturas.h"
#include "constantes.h"
#include "funcoes_auxiliares.h"


int procuraVeiculo(tipoVeiculos veiculos[],int numVeiculos, char matricula[MAX_MATRICULA])
{
    int posicao, i;
    posicao = NAO_EXISTE;

    for(i=0; i<numVeiculos; i++)
    {
        if(strcmp(veiculos[i].matricula, matricula) == 0)
        {
            posicao = i;
            i = numVeiculos;
        }
    }
    return posicao;
}

void validaMatriculaUnica(tipoVeiculos veiculos[],int numVeiculos)
{
    int i;

    for(i=0; i<numVeiculos; i++)
    {
        if(strcmp(veiculos[i].matricula,veiculos[numVeiculos].matricula)==0)
        {
            do
            {
                printf("\n\tMatricula ja existe");
                lerString("\n\tInsira a matricula(__-__-__): ",veiculos[i].matricula, MAX_MATRICULA);
            }
            while(strcmp(veiculos[i].matricula,veiculos[numVeiculos].matricula)==0);
        }
    }
}

void inserirVeiculo(tipoVeiculos veiculos[],int *numVeiculos)
{
    if(*numVeiculos == MAX_VEICULOS)
    {
        printf("\n\tERRO: Nao e possivel inserir um novo veiculo. Foi atingido o maximo de veiculos.");
    }
    else
    {
        printf("\n\tData de Fabrico: ");
        veiculos[*numVeiculos].dataFabrico = lerData();
        lerString("\n\tInsira a matricula(__-__-__): ",veiculos[*numVeiculos].matricula, MAX_MATRICULA);
        validaMatriculaUnica(veiculos, *numVeiculos);
        veiculos[*numVeiculos].cargaMaxima = lerFloat("\tCarga maxima: ",MIN_CARGA,MAX_CARGA);
        veiculos[*numVeiculos].estado = 1;
        (*numVeiculos)++;
    }
}

void listarVeiculos(tipoVeiculos veiculos[], int numVeiculos)
{
    int i;
    if(numVeiculos == 0)
    {
        printf("\n\tNao existem veiculos");
    }
    else
    {
        for(i=0; i<numVeiculos; i++)
        {
            apresentaDadosVeiculos(veiculos[i]);
            printf("%s",veiculos[i].matricula);
        }
    }
}
void apresentaDadosVeiculos(tipoVeiculos veiculos)
{
    printf("\n\tMatricula: %s",veiculos.matricula);
    printf("\n\tData de Fabrico: %d/%d/%d",veiculos.dataFabrico.dia, veiculos.dataFabrico.mes, veiculos.dataFabrico.ano);
    printf("\n\tCarga maxima: %.2f",veiculos.cargaMaxima);
    printf("\n\tEstado: ");
    switch (veiculos.estado)
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
void consultarVeiculos(tipoVeiculos veiculos[], int numVeiculos, char matricula[MAX_MATRICULA]) //ainda nao funciona
{
    int posicao;
    if(numVeiculos == 0)
    {
        printf("\n\tATENCAO: nao existem veiculos inseridos");
    }
    else
    {
        lerString("\n\tInsira a matricula(__-__-__): ",matricula, MAX_MATRICULA);
        posicao = procuraVeiculo(veiculos,numVeiculos,matricula);

        if(posicao == NAO_EXISTE) //nao existe no vetor
        {
            printf("\nO veiculo com a %s matricula nao existe.",matricula);
        }
        else
        {
            apresentaDadosVeiculos(veiculos[posicao]);
        }
    }

}
float cargaMediaVeiculos(tipoVeiculos veiculos[MAX_VEICULOS],int numVeiculos)
{
    int i;
    float carga,cargaMedia;
    carga=0;
    cargaMedia=0;
    if(numVeiculos == 0)
    {
        printf("\n\tNao existem veiculos");
    }
    else
    {
        for (i=0; i<numVeiculos; i++)
        {
            if(veiculos[i].estado==A_TRANSPORTAR)
            {
                carga+=veiculos[i].cargaMaxima;
            }
            else
            {
                printf("\n\t\t\tNao e possivel mostrar a carga media dos veiculos em viagem, porque de momento nao existe nenhum veiculo em viagem.");
            }
        }
        cargaMedia=carga/numVeiculos;
        printf("\n\t\t\tA carga media dos veiculos em viagem e de %.2f",cargaMedia);
    }
    return cargaMedia;
}

void inicioViagem(tipoVeiculos veiculos[], int numVeiculos, tipoEncomendas encomendas[], int numEncomendas)
{
    float cargaAtual;
    int i,j;


    if(numVeiculos == 0)
    {
        printf("Nao existem veiculos. Por favor insira. ");
    }
    else
    {
        for(i=0; i<numVeiculos; i++)
        {
            if(veiculos[i].estado == EM_CARGA)
            {
                for(j=0; j<numEncomendas; j++)
                {
                    if(encomendas[j].estado == CARREGADA)
                    {
                        cargaAtual += encomendas[j].peso;
                        veiculos[i].cargaDisponivel = veiculos[i].cargaMaxima - cargaAtual;
                        if((veiculos[i].cargaDisponivel == veiculos[i].cargaMaxima * 0.2) && encomendas[j].peso > veiculos[i].cargaDisponivel)  //se estiver cheio a 80%
                        {
                            printf("O veiculo ja esta pronto para partir");
                            veiculos[numVeiculos].estado = A_TRANSPORTAR;
                            encomendas[numEncomendas].estado = TRANSPORTADA;

                        }
                        else
                        {
                            if((veiculos[numVeiculos].cargaDisponivel == veiculos[numVeiculos].cargaMaxima * 0.2)&& encomendas[numEncomendas].peso <= veiculos[numVeiculos].cargaDisponivel)
                            {
                                do
                                {
                                    printf("fff");
                                }
                                while ((veiculos[numVeiculos].cargaDisponivel=veiculos[numVeiculos].cargaMaxima));
                                printf("O veiculo está pronto para partir -> veiculo a 100%%");
                            }

                        }
                    }
                }
            }


            //veiculo tem de estar cheio 80% (800kg) para ir sozinho;
            //pode ultrapassar esses 80% se couberem lá encomendas;
            //se não estiver carregado 80% manda-lo ir manualmente
        }
    }

}

