#include <stdlib.h>
#include <stdio.h>
#include "ficheiros.h"

/*void guardarFicheiroBinarioVeiculos (tipoVeiculos veiculos[], int numVeiculos)
{
    FILE *ficheiro;
    int numEscritos;
    if(numVeiculos==0)
    {
        printf("\nNao existem veiculos para guardar.");
    }
    else
    {
        ficheiro = fopen("informacoes.dat", "wb");
        if(ficheiro == NULL)
        {
            printf("\nERRO: O ficheiro nao existe");
        }
        else
        {
            numEscritos = fwrite(&numVeiculos, sizeof(int), 1, ficheiro); //escreve 1 int contido em p, para ficheiro aberto por ficheiro
            if(numEscritos!=1);
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


void guardarFicheiroBinarioEncomendas(tipoEncomendas encomendas, int numEncomendas)
{
    FILE *ficheiro;
    int numEscritos;
    if(numEncomendas==0)
    {
        printf("\nNao existem veiculos para guardar.");
    }
    else
    {
        ficheiro = fopen("informacoes.dat", "wb");
        if(ficheiro == NULL)
        {
            printf("\nERRO: O ficheiro nao existe");
        }
        else
        {
            numEscritos = fwrite(&numEncomendas, sizeof(int), 1, ficheiro);
            if(numEscritos!=1);
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



}*/
