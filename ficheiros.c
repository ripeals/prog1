#include <stdlib.h>
#include <stdio.h>
#include "ficheiros.h"

void guardarFicheiroBinarioVeiculos (tipoVeiculos veiculos[], int numVeiculos)
{
    FILE *ficheiro;
    int numEscritos;
    if(numVeiculos==0)
    {
        printf("\nNao existem veiculos para guardar.");
    }
    else
    {
        ficheiro = fopen("informacoesVeiculos.dat", "wb");
        if(ficheiro == NULL)
        {
            printf("\nERRO: O ficheiro nao existe");
        }
        else
        {
            numEscritos = fwrite(&numVeiculos, sizeof(int), 1, ficheiro); //escreve 1 int contido em p, para ficheiro aberto por ficheiro
            if(numEscritos!=1)
            {
                printf("ERRO: Ocorreu um erro ao guardar o numero de veiculos");
            }
            else
            {
                numEscritos = fwrite(veiculos, sizeof(tipoVeiculos), numVeiculos, ficheiro); //escreve numVeiculos de tipoVeiculos no vetor veiculos para ficheiro
                if(numEscritos!= numVeiculos)
                {
                    printf("ERRO: Impossivel guardar dados dos veiculos");
                }
            }

            fclose(ficheiro);
        }
    }
}


void guardarFicheiroBinarioEncomendas(tipoEncomendas encomendas[], int numEncomendas)
{
    FILE *ficheiro;
    int numEscritos;

    if(numEncomendas==0)
    {
        printf("\nNao existem veiculos para guardar.");
    }
    else
    {
        ficheiro = fopen("informacoesEncomendas.dat", "wb");
        if(ficheiro == NULL)
        {
            printf("\nERRO: O ficheiro nao existe");
        }
        else
        {
            numEscritos = fwrite(&numEncomendas, sizeof(int), 1, ficheiro);
            if(numEscritos!=1)
            {
                printf("ERRO: Ocorreu um erro ao guardar o numero de veiculos");
            }
            else
            {
                numEscritos = fwrite(encomendas, sizeof(tipoEncomendas), numEncomendas, ficheiro); //escreve numVeiculos de tipoVeiculos no vetor veiculos para ficheiro
                if(numEscritos!= numEncomendas)
                {
                    printf("ERRO: Impossivel guardar dados dos veiculos");
                }
            }
            fclose(ficheiro);
        }
    }
}

void lerFicheiroBinarioVeiculos(tipoVeiculos veiculos[MAX_VEICULOS], int *numVeiculos)
{
    FILE *ficheiro;
    int numLidos;

    ficheiro = fopen("informacoesVeiculos.dat", "rb");
    if(ficheiro==NULL)
    {
        printf("ERRO: O ficheiro nao existe");
        *numVeiculos=0;
    }
    else
    {
        numLidos = fread(&*numVeiculos, sizeof(int),1,ficheiro);
        if(numLidos!=1)
        {
            printf("\nERRO: Ocorreu um erro ao guardar o numero de veiculos");
            *numVeiculos=0;
        }
        else
        {
            numLidos = fread(veiculos,sizeof(tipoVeiculos),*numVeiculos,ficheiro);
            if(numLidos!=*numVeiculos)
            {
                printf("\nERRO: Ocorreu um erro ao guardar os dados dos veiculos");
                *numVeiculos=0;
            }



        }
        fclose(ficheiro);
    }
}

void lerFicheiroBinarioEncomendas(tipoEncomendas encomendas[], int *numEncomendas)
{
    FILE *ficheiro;
    int numLidos;

    ficheiro = fopen("informacoesEncomendas.dat", "rb");
    if(ficheiro==NULL)
    {
        printf("ERRO: O ficheiro nao existe");
        *numEncomendas=0;
    }
    else
    {
        numLidos = fread(&*numEncomendas, sizeof(int),1,ficheiro);
        if(numLidos!=1)
        {
            printf("\nERRO: Ocorreu um erro ao guardar o numero de encomendas");
            *numEncomendas=0;
        }
        else
        {
            numLidos = fread(encomendas,sizeof(tipoEncomendas),*numEncomendas,ficheiro);
            if(numLidos!=*numEncomendas)
            {
                printf("\nERRO: Ocorreu um erro ao guardar os dados das encomendas");
                *numEncomendas=0;
            }



        }
        fclose(ficheiro);
    }
}

void FicheiroTextoEncomendaDevolvida (tipoEncomendas encomendas[], int numEncomendas)
{
    FILE *ficheiro;
    int i;

    if(numEncomendas == 0)
    {
        printf("\nNao existem encomendas para guardar ");
    }
    else
    {
        ficheiro = fopen("informacoesEncomendas.dat", "w");
        if(ficheiro==NULL)
        {
            printf("ERRO: O ficheiro nao existe");
        }
        else
        {
            for(i=0; i<numEncomendas; i++)
            {
                fprintf(ficheiro, "\nNumero de Registo: ");
                printf("%d", encomendas[i].numRegisto);
                fprintf(ficheiro, "\nData de Devolucao: ");
                //printf("%d", );
                fprintf(ficheiro, "\nVeiculo que Transportou: ");
                // printf("%s",);
                fprintf(ficheiro, "\nCausa da Devolucao: ");
                //printf("%s", );
            }
        }
        fclose(ficheiro);
    }

}





