#ifndef VEICULO_H_INCLUDED
#define VEICULO_H_INCLUDED
#include "estruturas.h"

void inserirVeiculo(tipoVeiculos veiculos[],int *numVeiculos);
void validaMatriculaUnica(tipoVeiculos veiculos[],int numVeiculos);
int procuraVeiculo(tipoVeiculos veiculos[],int numVeiculos, char matricula[]);
void consultarVeiculos(tipoVeiculos veiculos[], int numVeiculos, char matricula[]);
void listarVeiculos(tipoVeiculos veiculos[],int numVeiculos);
void apresentaDadosVeiculos(tipoVeiculos veiculo);
float cargaMediaVeiculos(tipoVeiculos veiculos[],int numVeiculos);
void inicioViagem(tipoVeiculos veiculos[], int numVeiculos, tipoEncomendas encomendas[], int numEncomendas);
#endif // VEICULO_H_INCLUDED
