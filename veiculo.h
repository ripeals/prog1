#ifndef VEICULO_H_INCLUDED
#define VEICULO_H_INCLUDED
#include "estruturas.h"

void menuVeiculo();
void inserirVeiculo(tipoVeiculos veiculos[],int *numVeiculos/*, char matricula[MAX_MATRICULA]*/);
void listarVeiculos(tipoVeiculos veiculos[],int *numVeiculos);
#endif // VEICULO_H_INCLUDED
