#ifndef VEICULO_H_INCLUDED
#define VEICULO_H_INCLUDED
#include "estruturas.h"

void inserirVeiculo(tipoVeiculos veiculos[],int *numVeiculos);
int procuraVeiculo(tipoVeiculos veiculos[],int numVeiculos, char matricula[MAX_MATRICULA]);
void consultarVeiculos(tipoVeiculos veiculos[], int numVeiculos, char matricula[MAX_MATRICULA]);
void listarVeiculos(tipoVeiculos veiculos[],int numVeiculos);
void apresentaDadosVeiculos(tipoVeiculos veiculo);
float cargaMediaVeiculos(tipoVeiculos veiculos[],int numVeiculos);
#endif // VEICULO_H_INCLUDED
