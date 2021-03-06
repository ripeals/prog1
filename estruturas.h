#ifndef ESTRUTURAS_H_INCLUDED
#define ESTRUTURAS_H_INCLUDED
#include "constantes.h"

typedef struct {
    int ano, mes, dia;
}tipoData;

typedef struct{
    int numRegisto;
    tipoData dataRegisto;
    tipoData dataEntrega;
    float peso;
    char destino[MAX_STRING];
    int estado;
    char obs[MAX_STRING];
    char matricula[MAX_MATRICULA];
}tipoEncomendas;

typedef struct{
    char matricula[MAX_MATRICULA];
    tipoData dataFabrico;
    int estado;
    float cargaMaxima;
    float cargaDisponivel;
    int qtViagens;
    int qtEncomendasT;
    int numEncomendas;
    char destino[MAX_STRING];
}tipoVeiculos;

#endif // ESTRUTURAS_H_INCLUDED
