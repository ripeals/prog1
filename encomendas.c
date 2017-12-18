#include <stdio.h>
#include <stdlib.h>
#include "funcoes_auxiliares.h"
#include "estruturas.h"
#include "constantes.h"
#include "encomendas.h"

void menuEncomendas()
{
    tipoEncomendas encomendas[MAX_ENCOMENDAS];
    int numEncomendas=0;
    int opcao=0;
    do
    {
        printf("\n\t\t\t\tMenu das Encomendas");
        printf("\n\t1 - Inserir encomendas");
        printf("\n\t2 - Consultar encomendas");
        printf("\n\t3 - Listar encomendas");
        printf("\n\t4 - Eliminar encomendas");
        printf("\n\t5 - Sair");
        printf("\n\tOpcao: ");
        scanf("%d", &opcao);
        switch(opcao)
        {
        case 1:
            printf("\n\t\t\tInserir Encomendas");
            inserirEncomendas(encomendas, &numEncomendas);
            break;
        case 2:
            printf("\n\t\t\tConsultar Encomendas");
            consultarEncomendas(encomendas, numEncomendas);
            break;
        case 3:
            printf("\n\t\t\tListar Encomendas");
            listarEncomendas (encomendas, numEncomendas);
            break;
        case 4:
            printf("\n\t\t\tEliminar Encomenda(s)");
            numEncomendas=eliminarEncomendas(encomendas, numEncomendas);
            break;
        case 5:
            break;
        default:
            printf("Por favor, introduza uma opcao valida.");
        }
    }
    while(opcao != 4);

}


void inserirEncomendas (tipoEncomendas encomendas[], int *numEncomendas)
{
    if(*numEncomendas == MAX_ENCOMENDAS)
    {
        printf("\n\tERRO: Nao e possivel inserir uma nova encomenda. Foi atingido o maximo das encomendas.");
    }
    else
    {
        encomendas[*numEncomendas].numRegisto = lerInteiro("\n\tNumero de Registo ",1,MAX_NUM_ENCOMENDA);
        printf("\tData de Registo: ");
        encomendas[*numEncomendas].dataRegisto = lerData();
        encomendas[*numEncomendas].peso = lerFloat("\tPeso: ",1.00,MAX_PESO);
        lerString("\tDestino: ", encomendas[*numEncomendas].destino, MAX_STRING);
        encomendas[*numEncomendas].estado=1;
        lerString("\tObservacoes: ", encomendas[*numEncomendas].obs, MAX_STRING );
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
    printf("\n\tDestino: %s", encomenda.destino);
    printf("\n\tObservacoes: %s",encomenda.obs);
}




<<<<<<< HEAD
int procuraEncomendas (tipoEncomendas encomendas [], int numEncomendas, int numRegisto)
{
    int posicao, i;
    posicao = NAO_EXISTE;
=======
int procuraEncomendas (tipoEncomendas encomendas [MAX_ENCOMENDAS], int numEncomendas, int numRegisto)
{
    int posicao, i;
    posicao = -1;
>>>>>>> 1a4992ea99f5279fc165993584fbef37eaa51030
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
<<<<<<< HEAD
    int posicao,numRegisto;
    if(numEncomendas == 0)
    {
        printf("\n\tATENCAO: nao existem encomendas inseridas!!! Por favor, insira.");
    }
    else
    {
        numRegisto = lerInteiro("\n\t\t\tNumero de registo: ",1,MAX_NUM_ENCOMENDA);
        posicao = procuraEncomendas(encomendas, numEncomendas, numRegisto);
=======
    int posicao;
    if(numEncomendas == 0)
    {
        printf("\n\tATENCAO: nao existem encomendas inseridas!!! Por favor, insira.");
        inserirEncomendas(encomendas, &numEncomendas);
    }
    else
    {
        //posicao = procuraEncomendas(encomendas, numEncomendas, numRegisto);
>>>>>>> 1a4992ea99f5279fc165993584fbef37eaa51030

        if(posicao == NAO_EXISTE) //nao existe no vetor
        {
<<<<<<< HEAD
            printf("A encomenda com o numero de registo %d nao e valida ",numRegisto);
=======
            //printf("A encomenda com o numero de registo %d nao e valida ", numRegisto);
>>>>>>> 1a4992ea99f5279fc165993584fbef37eaa51030
        }
        else
        {
            apresentaDadosEncomendas(encomendas[posicao]);
        }
    }
}

int eliminarEncomendas (tipoEncomendas encomendas[], int numEncomendas)  //nao esta a funcionar
{
    int posicao, numRegisto, i;
    if(numEncomendas == 0)
    {
        printf("\nERRO: Nao existem encomendas. Por favor insira ");
        inserirEncomendas(encomendas, &numEncomendas);
    }
    else
    {
        numRegisto = lerInteiro("\nNumero de Registo: ",1, MAX_NUM_ENCOMENDA);//certo ate aqui
        posicao = procuraEncomendas(encomendas, numEncomendas, numRegisto);
        if(posicao==-1)
        {
            do
            {
                printf("\nPor favor insira um numero de registo valido.");
                numRegisto = lerInteiro("\nNumero de Registo: ",1, MAX_NUM_ENCOMENDA);
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
        }
        return numEncomendas;
    }

}
