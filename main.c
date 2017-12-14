#include <stdio.h>
#include <stdlib.h>
#include "funcoes_auxiliares.h"
#include "constantes.h"
#include "veiculo.h"
#include "encomendas.h"

int main()
{
    int opcao=0;
    do{
        printf("\t\tDistribuição de Encomendas");
        printf("\n\t1 - Veiculos");
        printf("\n\t2 - Encomendas");
        printf("\n\t3 - Sair");
        printf("\n\tOpcao: ");
        scanf("%d",&opcao);
        //limpaBuffer();
        switch(opcao){
            case 1:
                menuVeiculo();
                break;
            case 2:
                menuEncomendas();
                break;
        }
    }while(opcao!=3);
    return 0;
}
