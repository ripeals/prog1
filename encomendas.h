#ifndef ENCOMENDAS_H_INCLUDED
#define ENCOMENDAS_H_INCLUDED

int menuEncomendas(tipoEncomendas encomendas[],int numEncomendas,tipoVeiculos veiculos[],int numVeiculos);
void inserirEncomendas (tipoEncomendas encomendas[], int *numEncomendas);
void listarEncomendas (tipoEncomendas encomendas[], int numEncomendas);
void apresentaDadosEncomendas(tipoEncomendas encomenda);
int procuraEncomendas (tipoEncomendas encomendas[], int numEncomendas, int numRegisto);
void consultarEncomendas (tipoEncomendas encomendas [], int numEncomendas);
int eliminarEncomendas (tipoEncomendas encomendas [], int numEncomendas);
void carregamentoEncomendas(tipoEncomendas encomendas[], int numEncomendas,tipoVeiculos veiculos[],int numVeiculos);
float pesoMedioEncomendas(tipoEncomendas encomendas[], int numEncomendas);
void validaNumRegistoUnico(tipoEncomendas encomendas[],int numEncomendas);
int quantidadeEncomendasEntregues(tipoEncomendas encomendas[], int *numEncomendas);
#endif // ENCOMENDAS_H_INCLUDED
