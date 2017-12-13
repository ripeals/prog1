#include <stdio.h>
#include <stdlib.h>

void menuEncomendas()
{
    int opcaoEncomendas;
    printf("\n\t\t\tMenu das Encomendas");
    printf("\n\t1- Inserir encomendas");
    printf("\n\t2- Consultar encomendas");
    printf("\n\t3- Listar encomendas");
    scanf("%d", &opcaoEncomendas);
    switch(opcaoEncomendas)
    {
    case 1:
        printf("\n\t\t\tInserir Encomendas");
        break;
    case 2:
        printf("\n\t\t\tConsultar Encomendas");
        break;
    case 3:
        printf("\n\t\t\tListar Encomendas");
        break;
    default:
        printf("\nA opcao inserida nao e valida. Introduza uma opcao valida");
        break;
    }

}


void inserirEncomendas (){
    printf("Numero de Registo: ");
    printf("");





}
