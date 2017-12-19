#ifndef VEICULO_H_INCLUDED
#define VEICULO_H_INCLUDED
#include "estruturas.h"

void menuVeiculo();
void inserirVeiculo(tipoVeiculos veiculos[],int *numVeiculos);
void procuraVeiculo(tipoVeiculos veiculos[MAX_VEICULOS],int numVeiculos,char matricula[MAX_MATRICULA]);
void consultarVeiculos(tipoVeiculos veiculos[], int numVeiculos);
void listarVeiculos(tipoVeiculos veiculos[],int numVeiculos);
void apresentaDadosVeiculos(tipoVeiculos veiculo);
float cargaMediaVeiculos(tipoVeiculos veiculos[],int numVeiculos);
#endif // VEICULO_H_INCLUDED
