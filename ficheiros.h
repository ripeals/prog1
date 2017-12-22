#ifndef FICHEIROS_H_INCLUDED
#define FICHEIROS_H_INCLUDED
#include "veiculo.h"
#include "encomendas.h"

void guardarFicheiroBinarioVeiculos (tipoVeiculos veiculos[], int numVeiculos);
void guardarFicheiroBinarioEncomendas(tipoEncomendas encomendas[], int numEncomendas);
void lerFicheiroBinarioVeiculos(tipoVeiculos veiculos[MAX_VEICULOS], int *numVeiculos);
void lerFicheiroBinarioEncomendas(tipoEncomendas encomendas[], int *numEncomendas);
void FicheiroTextoEncomendaDevolvida (tipoEncomendas encomendas[], int numEncomendas);

#endif // FICHEIROS_H_INCLUDED
