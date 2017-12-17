#ifndef ENCOMENDAS_H_INCLUDED
#define ENCOMENDAS_H_INCLUDED

void menuEncomendas();
void inserirEncomendas (tipoEncomendas encomendas[], int *numEncomendas);
void listarEncomendas (tipoEncomendas encomendas[], int numEncomendas);
void apresentaDadosEncomendas(tipoEncomendas encomenda);
int procuraEncomendas (tipoEncomendas encomendas [MAX_ENCOMENDAS], int *numEncomendas, int numeroRegisto);
void consultarEncomendas (tipoEncomendas encomendas [], int *numEncomendas, int numeroRegisto);
#endif // ENCOMENDAS_H_INCLUDED
