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
        printf("\t\t\t  Distribuicao de Encomendas");
        printf("\n\t1 - Veiculos");
        printf("\n\t2 - Encomendas");
        printf("\n\t3 - Sair");
        printf("\n\tOpcao: ");
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
