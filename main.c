#include <stdio.h>
#include <stdlib.h>
#include "funcoes_auxiliares.h"
#include "menuVeiculos.h"
#include "encomendas.h"

int main()
{
    tipoVeiculos veiculos[MAX_VEICULOS];
    tipoEncomendas encomendas[MAX_ENCOMENDAS];
    int numVeiculos=0;
    int numEncomendas=0;
    int opcao=0;
    do{
        printf("\n\t\tQuantidade de Veiculos - %d",numVeiculos);
        printf("\n\t\tQuantidade de Encomendas - %d",numEncomendas);
        printf("\n\t\tPercentagem de Encomendas Entregues");
        printf("\n\t\tQuantidade de Encomendas devolvidas");
        printf("\n\t-------------------------------------------------");
        printf("\n\t\t\t  Distribuicao de Encomendas");
        printf("\n\t\t1 - Veiculos");
        printf("\n\t\t2 - Encomendas");
        printf("\n\t\t3 - Sair");
        printf("\n\n\tOpcao: ");
        scanf("%d",&opcao);
        limpaBuffer();

        switch(opcao){
            case 1:
                numVeiculos = menuVeiculo(veiculos,numVeiculos);
                break;
            case 2:
                numEncomendas = menuEncomendas(encomendas,numEncomendas,veiculos,numVeiculos);
                break;
        }
    }while(opcao!=3);
    return 0;
}
