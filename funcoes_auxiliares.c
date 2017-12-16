#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "funcoes_auxiliares.h"
#include "constantes.h"


// Acrescentada variavel controlo para repetir insercao se ao for inserido numero int
int lerInteiro(char mensagem[MAX_STRING], int minimo, int maximo)
{
    int numero, controlo;
    do
    {
        printf("%s (%d a %d): ", mensagem, minimo, maximo);
        controlo = scanf ("%d", &numero);  // scanf devolve quantidade de valores vàlidos obtidos
        limpaBuffer();     //limpa todos os caracteres do buffer stdin (nomeadamente o \n)

        if (controlo == 0)
        {
            printf("Devera inserir um numero inteiro. \n");
        }
        else
        {

            if(numero<minimo || numero>maximo)
            {
                printf("Numero invalido. Insira novamente:\n");
            }

        }
    }
    while(numero<minimo || numero>maximo || controlo ==0);

    return numero;
}

float lerFloat(char mensagem[MAX_STRING], float minimo, float maximo)
{
    float numero;
    int controlo;
    do
    {
        printf("%s (%.2f a %.2f): ", mensagem, minimo, maximo);
        controlo = scanf ("%f", &numero);  // scanf devolve quantidade de valores vàlidos obtidos
        limpaBuffer();

        if (controlo == 0)
        {
            printf("Devera inserir um numero decimal (float). \n");
        }
        else
        {

            if(numero<minimo || numero>maximo)
            {
                printf("Numero invalido. Insira novamente:\n");
            }

        }
    }
    while(numero<minimo || numero>maximo || controlo ==0);

    return numero;
}

void lerString(char mensagem[MAX_STRING], char vetorCaracteres[MAX_STRING], int maximoCaracteres)
{
    int tamanhoString;

    do 	// Repete leitura caso sejam obtidas strings vazias
    {
        //   puts(mensagem);
        printf("%s", mensagem);
        fgets(vetorCaracteres, maximoCaracteres, stdin);

        tamanhoString = strlen(vetorCaracteres);
        if(tamanhoString <= 1){
            printf("\n\tERRO: Tem de inserir um valor!");
        }
        else{
            if(vetorCaracteres[tamanhoString-1] == '\n'){
                vetorCaracteres[tamanhoString] = '\0';
            }
            else{
                limpaBuffer();
            }
        }
    }while(tamanhoString <= 1);

}

void limpaBuffer(void)
{
    int chr;
    do
    {
        chr = getchar();
    }
    while (chr != '\n' && chr != EOF);
}
tipoData lerData()
{
    tipoData data;
    int maximoDias;
    data.ano = lerInteiro("\n\t Ano ", MIN_ANO, MAX_ANO);
    data.mes = lerInteiro("\t Mes ", MIN_MES, MAX_MES);
    switch(data.mes)
    {
    case 2:
        if (data.ano%4==0 && data.ano%400==0)
        {
            maximoDias=29;
        }
        else
        {
            maximoDias=28;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        maximoDias=30;
        break;
    default:
        maximoDias=31;
        break;
    }
    data.dia = lerInteiro("\t Dia ", 1, maximoDias);

    return data;
}
void lerMatricula(char mensagem[MAX_STRING], char vetorCaracteres[MAX_STRING], int maximoCaracteres)
{
    int tamanhoString;

    do 			// Repete leitura caso sejam obtidas strings vazias
    {
        //   puts(mensagem);
        printf("%s", mensagem);
        fgets(vetorCaracteres, maximoCaracteres, stdin);

        tamanhoString = strlen(vetorCaracteres);
        if(vetorCaracteres[tamanhoString-1] != '\n')  // ficaram caracteres no buffer....
        {
            limpaBuffer();  // apenas faz sentido limpar buffer se a ficarem caracteres
        }
        if (tamanhoString == 1)
        {
            printf("Nao foram introduzidos caracteres!\n\n");
        }

    }
    while (tamanhoString == 1);
}

/*void inserirMatricula(char matricula[MAX_MATRICULA]){
     lerString("\nMatricula: ", matricula[MAX_MATRICULA], MAX_MATRICULA);



}*/
